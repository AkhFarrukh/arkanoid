#include <allegro5/allegro5.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/bitmap.h>
#include <allegro5/color.h>
#include <allegro5/display.h>
#include <allegro5/drawing.h>
#include <allegro5/events.h>
#include <allegro5/keyboard.h>
#include <allegro5/keycodes.h>
#include <allegro5/mouse.h>
#include <allegro5/system.h>
#include <allegro5/timer.h>
#include <allegro5/transformations.h>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>
#include <numbers>
#include <ranges>
#include <string>
#include <vector>

using namespace std;
inline constexpr float PI = std::numbers::pi_v<float>;

const int    windowWidth      = 500;
const int    windowHeight     = 500;
const float  mid_x            = static_cast<float>(windowWidth) / 2.0F;
const float  mid_y            = static_cast<float>(windowHeight) / 2.0F;
const double refreshPerSecond = 60;

const ALLEGRO_COLOR COLOR_RED     = al_map_rgb(255, 0, 0);
const ALLEGRO_COLOR COLOR_GREY    = al_map_rgb(200, 200, 200);
const ALLEGRO_COLOR COLOR_GREEN   = al_map_rgb(0, 255, 0);
const ALLEGRO_COLOR COLOR_YELLOW  = al_map_rgb(255, 255, 0);
const ALLEGRO_COLOR COLOR_BLACK   = al_map_rgb(0, 0, 0);
const ALLEGRO_COLOR COLOR_WHITE   = al_map_rgb(255, 255, 255);
const ALLEGRO_COLOR COLOR_PINK    = al_map_rgb(200, 150, 167);
const ALLEGRO_COLOR COLOR_MAGENTA = al_map_rgb(255, 0, 255);
const ALLEGRO_COLOR COLOR_BLUE    = al_map_rgb(0, 0, 255);

// Global that contains font size and the font itself
const int     FONT_SIZE = 20;
ALLEGRO_FONT *font;

struct Point {
    float x = 0, y = 0;
};

struct PointInt {
    int x = 0, y = 0;
};


/*--------------------------------------------------
Drawable class.
--------------------------------------------------*/
class Drawable {
protected:
    Drawable()                             = default;
    Drawable(const Drawable &)            = default;
    Drawable(Drawable &&)                 = default;
    Drawable &operator=(const Drawable &) = default;
    Drawable &operator=(Drawable &&)      = default;

public:
    virtual bool contains(Point p) const = 0;
    virtual void draw()                 = 0;
    virtual ~Drawable()                 = default;
};

/*--------------------------------------------------
Clickable class.
--------------------------------------------------*/
class Clickable : public virtual Drawable {
protected:
    Clickable()                             = default;
    Clickable(const Clickable &)            = default;
    Clickable(Clickable &&)                 = default;
    Clickable &operator=(const Clickable &) = default;
    Clickable &operator=(Clickable &&)      = default;

public:
    virtual void onClick() {};
    ~Clickable() override  = default;
};

/*--------------------------------------------------
Message Receiver
--------------------------------------------------*/
class MessageReceiver {
protected:
    MessageReceiver()                                   = default;
    MessageReceiver(const MessageReceiver &)            = default;
    MessageReceiver(MessageReceiver &&)                 = default;
    MessageReceiver &operator=(const MessageReceiver &) = default;
    MessageReceiver &operator=(MessageReceiver &&)      = default;

public:
    virtual void receiveMessage(const string &message) = 0;
    virtual ~MessageReceiver()                         = default;
};

/*--------------------------------------------------
Observer
--------------------------------------------------*/
struct Observer {
    virtual void subjectChanged() = 0;
    virtual ~Observer()           = default;

protected:
    Observer()                            = default;
    Observer(const Observer &)            = default;
    Observer(Observer &&)                 = default;
    Observer &operator=(const Observer &) = default;
    Observer &operator=(Observer &&)      = default;
};

/*--------------------------------------------------
Subject
--------------------------------------------------*/
class Subject {
    vector<Observer *> observers;  // Should be weak_ptr s

protected:
    Subject()                           = default;
    Subject(const Subject &)            = default;
    Subject(Subject &&)                 = default;
    Subject &operator=(const Subject &) = default;
    Subject &operator=(Subject &&)      = default;

public:
    void registerObserver(Observer *observer) { observers.push_back(observer); }
    void removeObserver(Observer *observer) { erase(observers, observer); }
    void notifyObservers() const {
      for (const auto &observer : observers) {
        observer->subjectChanged();
      }
    }
    virtual ~Subject() = default;
};

/*--------------------------------------------------
Send messages when clicked
--------------------------------------------------*/
class OnClickMessageSender : public virtual Clickable  {
    string                      message;
    shared_ptr<MessageReceiver> receiver;

protected:
    OnClickMessageSender(const OnClickMessageSender &)            = default;
    OnClickMessageSender(OnClickMessageSender &&)                 = default;
    OnClickMessageSender &operator=(const OnClickMessageSender &) = default;
    OnClickMessageSender &operator=(OnClickMessageSender &&)      = default;

public:
    OnClickMessageSender(string message, shared_ptr<MessageReceiver> receiver)
            : message{std::move(message)}, receiver{std::move(receiver)} {}
    void onClick() override { receiver->receiveMessage(message); }
    ~OnClickMessageSender() override = default;
};

/*--------------------------------------------------
Text class.

Use to display text on the screen. For example:

Text("Hello!", {250, 250}).draw();

will create a text temporary instance with the
string "Hello!" centered at 250, 250 and will
call draw on the temporary.

It should have all the features you need and you
should not need to edit it.
--------------------------------------------------*/

class Text: public virtual Drawable {
    string        s_;
    Point         center_;
    ALLEGRO_COLOR color_;

public:
    // Constructor
    Text(string text, Point center, ALLEGRO_COLOR color = COLOR_BLACK)
            : s_{text}, center_{center}, color_{color} {}

    // Draw
    void draw() override;

    // Setters and getters
    string getString() { return s_; }
    void   setString(const string &newString) { s_ = newString; }
    Point  getCenter() { return center_; }
    void   setCenter(Point newCenter) { center_ = newCenter; }
    bool   contains(Point p) const override;
};

void Text::draw() {
  auto verticalCenterAdjustment =
          static_cast<float>(al_get_font_line_height(font) / 2.0);
  al_draw_text(font, color_, center_.x, center_.y - verticalCenterAdjustment,
               ALLEGRO_ALIGN_CENTRE, s_.c_str());
}

bool Text::contains(Point p) const {
  auto w=al_get_font_line_height(font);
  auto h=al_get_text_width(font,s_.c_str());
  auto verticalCenterAdjustment =
          static_cast<float>(al_get_font_line_height(font) / 2.0);
  return abs(p.x-center_.x)<=w && abs(p.y-(center_.y - verticalCenterAdjustment))<=h;

}

/*--------------------------------------------------
Rectangle class.

Use to display a filled-in rectangle on the screen
with different colors for the fill and the border
--------------------------------------------------*/
/*--------------------------------------------------
Rectangle class.

Use to display a filled-in rectangle on the screen
with different colors for the fill and the border

It should have all the features you need and you
should not need to edit it.
--------------------------------------------------*/

class Rectangle : public virtual Drawable {
    Point center_;
    float         w_, h_;
    ALLEGRO_COLOR frameColor_, fillColor_;

public:
    Rectangle(Point center, float w, float h,
              ALLEGRO_COLOR frameColor = COLOR_BLACK,
              ALLEGRO_COLOR fillColor  = COLOR_WHITE) noexcept;
    void                draw() override;
    void                setFillColor(ALLEGRO_COLOR newFillColor);
    void                setFrameColor(ALLEGRO_COLOR newFrameColor);
    [[nodiscard]] bool  contains(Point point) const override;
    [[nodiscard]] Point getCenter() const;
};

Rectangle::Rectangle(Point center, float w, float h, ALLEGRO_COLOR frameColor,
                     ALLEGRO_COLOR fillColor) noexcept
        : Drawable {},
          center_{center},
          w_{w},
          h_{h},
          frameColor_{frameColor},
          fillColor_{fillColor} {}

void Rectangle::draw() {
  const float x1 = center_.x - w_ / 2;
  const float x2 = center_.x + w_ / 2;
  const float y1 = center_.y - h_ / 2;
  const float y2 = center_.y + h_ / 2;
  al_draw_filled_rectangle(x1, y1, x2, y2, fillColor_);
  al_draw_rectangle(x1, y1, x2, y2, frameColor_, 1);
}

void Rectangle::setFillColor(ALLEGRO_COLOR fillColor) {
  fillColor_ = fillColor;
}

void Rectangle::setFrameColor(ALLEGRO_COLOR frameColor) {
  frameColor_ = frameColor;
}

bool Rectangle::contains(Point point) const {
  return point.x >= center_.x - w_ / 2 && point.x < center_.x + w_ / 2 &&
         point.y >= center_.y - h_ / 2 && point.y < center_.y + h_ / 2;
}

Point Rectangle::getCenter() const { return center_; }


/*--------------------------------------------------
Circle class.

Use to display a filled-in circle on the screen
with different colors for the fill and the border

It should have all the features you need and you
should not need to edit it.
--------------------------------------------------*/
class Circle : public virtual Drawable {
protected:
    Point         center_;
    float         r_;
    ALLEGRO_COLOR frameColor_, fillColor_;

public:
    Circle(Point center, float r, ALLEGRO_COLOR frameColor = COLOR_BLACK,
           ALLEGRO_COLOR fillColor = COLOR_WHITE) noexcept;
    void                draw() override;
    void                setFillColor(ALLEGRO_COLOR newFillColor);
    void                setFrameColor(ALLEGRO_COLOR newFrameColor);
    [[nodiscard]] bool  contains(Point point) const override;
    [[nodiscard]] Point getCenter() const;
    void                setCenter(Point newCenter);

};

Circle::Circle(Point center, float r, ALLEGRO_COLOR frameColor,
               ALLEGRO_COLOR fillColor) noexcept
        : center_{center}, r_{r}, frameColor_{frameColor}, fillColor_{fillColor} {}

void Circle::draw() {
  al_draw_filled_circle(center_.x, center_.y, r_, fillColor_);
  al_draw_circle(center_.x, center_.y, r_, frameColor_, 1);
}

void Circle::setFillColor(ALLEGRO_COLOR fillColor) { fillColor_ = fillColor; }

void Circle::setFrameColor(ALLEGRO_COLOR frameColor) {
  frameColor_ = frameColor;
}

Point Circle::getCenter() const { return center_; }

bool Circle::contains(Point p) const {
  return ((p.x - center_.x) * (p.x - center_.x) +
          (p.y - center_.y) * (p.y - center_.y) <=
          r_ * r_);
}

void Circle::setCenter(Point newCenter) { center_ = newCenter; }




/*--------------------------------------------------------------
 *
 --------------------------------------------------------------*/
class BouncyBall : public virtual Circle{
    /*
     * https://www.youtube.com/watch?v=lpvH6MStSis&list=PLgLT8uqXESN84XNkhn7MT-HIi-BYzFWqZ&index=44
     */
private:
    float horizontalSpeed = 4.5F;
    float verticalSpeed = 4.0F;

public:
    BouncyBall(Point center, float r, ALLEGRO_COLOR frameColor,
            ALLEGRO_COLOR fillColor) noexcept;

    void draw() override;
};

BouncyBall::BouncyBall(Point center, float r, ALLEGRO_COLOR frameColor,
                       ALLEGRO_COLOR fillColor) noexcept :
                       Circle{center, r, frameColor, fillColor} {}

void BouncyBall::draw() {
  Point center = getCenter();


  center.x = center.x + horizontalSpeed;
  center.y = center.y + verticalSpeed;



  /*
   *
  if (center.x + r_ > windowWidth or center.x - r_ < 0){
    horizontalSpeed = -horizontalSpeed;
  }
  if (center.y + r_> windowHeight or center.y - r_ < 0){
    verticalSpeed = -verticalSpeed;
  }
   */

  if (Circle::contains(Point{0, center.y})or Circle::contains(Point{windowWidth, center.y})){
    horizontalSpeed = -horizontalSpeed;
  }
  if (Circle::contains(Point{center.x, 0})or Circle::contains(Point{center.x, windowHeight})){
    verticalSpeed = -verticalSpeed;
  }


  setCenter(center);
  Circle::draw();
}


/*--------------------------------------------------
TextRectangle
--------------------------------------------------*/
class TextRectangle : public Text, public Rectangle {
protected:
    TextRectangle(const TextRectangle &)            = default;
    TextRectangle(TextRectangle &&)                 = default;
    TextRectangle &operator=(const TextRectangle &) = default;
    TextRectangle &operator=(TextRectangle &&)      = default;

public:
    TextRectangle(Point center, float w, float h, string text)
            : Text{std::move(text), center}, Rectangle{center, w, h} {}
    void draw() override {
      Rectangle::draw();
      Text::draw();
    }
    bool contains(Point p) const override { return Rectangle::contains(p); }
    ~TextRectangle() override = default;
};

/*--------------------------------------------------
IntRectangle
--------------------------------------------------*/
class IntRectangle : public TextRectangle, public Subject {
    int  theInteger = 0;
    void update() {
      setString(to_string(theInteger));
      notifyObservers();
    }

protected:
    IntRectangle(const IntRectangle &)            = default;
    IntRectangle(IntRectangle &&)                 = default;
    IntRectangle &operator=(const IntRectangle &) = default;
    IntRectangle &operator=(IntRectangle &&)      = default;

public:
    IntRectangle(Point center, float w, float h, int theInteger)
            : TextRectangle{center, w, h, ""}, theInteger{theInteger} {
      update();
    }
    operator int() const { return theInteger; }
    int  getInteger() const { return theInteger; }
    void setInteger(int newInteger) {
      theInteger = newInteger;
      update();
    }
    ~IntRectangle() override = default;
};

/*--------------------------------------------------
CounterRectangle
--------------------------------------------------*/
class CounterRectangle : public IntRectangle, public MessageReceiver {
protected:
    CounterRectangle(const CounterRectangle &)            = default;
    CounterRectangle(CounterRectangle &&)                 = default;
    CounterRectangle &operator=(const CounterRectangle &) = default;
    CounterRectangle &operator=(CounterRectangle &&)      = default;

public:
    CounterRectangle(Point center, float w, float h)
            : IntRectangle{center, w, h, 0} {}
    void receiveMessage(const string &message) override {
      if (message == "increment") {
        setInteger(*this + 1);
      } else if (message == "decrement") {
        setInteger(*this - 1);
      } else {
        // It is far better to throw an exception than to exit(1), even
        // when you known the exception will never be handled.
        throw invalid_argument("CounterRectangle: Unknown message received: " +
                               message);
      }
    }
    ~CounterRectangle() override = default;
};

/*--------------------------------------------------
SumRectangle
--------------------------------------------------*/

class SumRectangle : public IntRectangle, public Observer {
    vector<shared_ptr<IntRectangle>> toSum;

protected:
    SumRectangle(const SumRectangle &)            = default;
    SumRectangle(SumRectangle &&)                 = default;
    SumRectangle &operator=(const SumRectangle &) = default;
    SumRectangle &operator=(SumRectangle &&)      = default;

public:
    SumRectangle(Point center, float w, float h,
                 const vector<shared_ptr<IntRectangle>> &toSum)
            : IntRectangle{center, w, h, 0}, toSum{toSum} {
      for (const auto &iRect : toSum) {
        iRect->registerObserver(this);
      }
      subjectChanged();
    }
    void subjectChanged() final {
      int sum = 0;
      for (const auto &iRect : toSum) {
        sum += *iRect;
      }
      setInteger(sum);
    }
    ~SumRectangle() override = default;
};

/*--------------------------------------------------
MultRectangle
--------------------------------------------------*/

class MultRectangle : public IntRectangle, public Observer {
    vector<shared_ptr<IntRectangle>> toMult;

protected:
    MultRectangle(const MultRectangle &)            = default;
    MultRectangle(MultRectangle &&)                 = default;
    MultRectangle &operator=(const MultRectangle &) = default;
    MultRectangle &operator=(MultRectangle &&)      = default;

public:
    MultRectangle(Point center, float w, float h,
                  const vector<shared_ptr<IntRectangle>> &toMult)
            : IntRectangle{center, w, h, 0}, toMult{toMult} {
      for (const auto &iRect : toMult) {
        iRect->registerObserver(this);
      }
      subjectChanged();
    }
    void subjectChanged() final {
      int product = 1;
      for (const auto &iRect : toMult) {
        product *= *iRect;
      }
      setInteger(product);
    }
    ~MultRectangle() override = default;
};

/*--------------------------------------------------
ClickableCircle class.
--------------------------------------------------*/

class ClickableCircle : public Circle, public OnClickMessageSender {
protected:
    ClickableCircle(const ClickableCircle &)            = default;
    ClickableCircle(ClickableCircle &&)                 = default;
    ClickableCircle &operator=(const ClickableCircle &) = default;
    ClickableCircle &operator=(ClickableCircle &&)      = default;

public:
    ClickableCircle(Point center, float r, ALLEGRO_COLOR frameColor, ALLEGRO_COLOR fillColor,
                    string message, shared_ptr<MessageReceiver> receiver) noexcept
            : Circle{center, r, frameColor, fillColor},
              OnClickMessageSender{std::move(message), std::move(receiver)} {}
    ~ClickableCircle() override = default;
};

/*--------------------------------------------------
Canvas class.

One instance of the canvas class is made by the
MainWindow class.

The fltk system via MainWindow calls:

draw 60 times a second
mouseClick whenever the mouse is clicked
keyPressed whenever a key is pressed

Any drawing code should be called ONLY in draw
or methods called by draw. If you try to draw
elsewhere it will probably crash.
--------------------------------------------------*/

class Canvas {
    BouncyBall bouncyBall_ = BouncyBall(Point{mid_x,mid_y}, 25.0F, COLOR_BLACK, COLOR_RED);

public:
    Canvas() = default;
    void draw();
    void mouseClick(Point mouseLoc);
    void mouseMove(Point mouseMove){}
    bool keyPressed(int keyCode);  // return True if the event was handled
};

//Canvas::Canvas() = default;

void Canvas::draw() {
  bouncyBall_.draw();
}

void Canvas::mouseClick(Point mouseLoc) {
}

bool Canvas::keyPressed(int /* keyCode */) { return false; }
// *****************DONT EDIT BELOW HERE************************

void must_init(bool test, const char *description) {
  if (test) {
    return;
  }

  std::cerr << "couldn't initialize " << description << '\n';
  exit(1);
}

void must_init(void *test, const char *description) {
  must_init(test != nullptr, description);
}

int main(int /* argc */, char ** /* argv */) {
  srand(static_cast<unsigned>(time(nullptr)));

  must_init(al_init(), "allegro");
  must_init(al_install_keyboard(), "keyboard");
  must_init(al_install_mouse(), "mouse");

  ALLEGRO_TIMER *timer = al_create_timer(1.0 / refreshPerSecond);
  must_init(timer, "timer");

  ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
  must_init(queue, "queue");

  al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
  al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
  al_set_new_bitmap_flags(ALLEGRO_MIN_LINEAR | ALLEGRO_MAG_LINEAR);

  ALLEGRO_DISPLAY *disp = al_create_display(windowWidth, windowHeight);
  must_init(disp, "display");

  must_init(al_init_ttf_addon(), "TTF addon");
  // font = al_create_builtin_font();
  font = al_load_ttf_font("SourceCodePro-Regular.ttf", FONT_SIZE, 0);
  must_init(font, "font");

  must_init(al_init_primitives_addon(), "primitives");

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(disp));
  al_register_event_source(queue, al_get_mouse_event_source());
  al_register_event_source(queue, al_get_timer_event_source(timer));

  bool          done = false;
  bool          draw = false;
  ALLEGRO_EVENT event;
  Canvas        canvas;

  al_start_timer(timer);
  while (!done) {
    al_wait_for_event(queue, nullptr);
    while (al_get_next_event(queue, &event)) {
      switch (event.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
          canvas.keyPressed(event.keyboard.keycode);
          break;
        case ALLEGRO_EVENT_MOUSE_AXES:
          // We try to never leave implicit casts in the code. By making the
          // cast explicit, we show that this is indeed our will, and that we
          // are aware of the loss of precision that occurs at this moment.
          canvas.mouseMove({static_cast<float>(event.mouse.x),
                            static_cast<float>(event.mouse.y)});
          // Another approach would be to create a constructor for the Point
          // structure that accepts integers and does the explicit casting at
          // that time. This would make the code easier to read. We didn't do
          // this to keep the part of the code you need to understand and modify
          // simpler.
          break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
          canvas.mouseClick({static_cast<float>(event.mouse.x),
                             static_cast<float>(event.mouse.y)});
          break;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
          done = true;
          break;
        case ALLEGRO_EVENT_TIMER:
          draw = true;
          al_stop_timer(timer);
          break;
        default: { /* Nothing, normal */
        }
      }
    }
    if (draw) {
      draw = false;
      al_start_timer(timer);
      al_clear_to_color(al_map_rgb(255, 255, 255));
      canvas.draw();
      al_flip_display();
    }
  }

  al_destroy_font(font);
  al_destroy_display(disp);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);

  return 0;
}