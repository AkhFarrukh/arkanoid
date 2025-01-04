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

#include <cstdlib>
#include <ctime>
#include <iostream>


#include "constants.hpp"
#include "canvas.hpp"
#include "view.hpp"
#include "modelInteractions.hpp"

using namespace std;

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

  ALLEGRO_FONT *font = al_load_ttf_font("SourceCodePro-Regular.ttf", FONT_SIZE, 0);
  must_init(font, "font");

  must_init(al_init_primitives_addon(), "primitives");

  al_register_event_source(queue, al_get_keyboard_event_source());
  al_register_event_source(queue, al_get_display_event_source(disp));
  al_register_event_source(queue, al_get_mouse_event_source());
  al_register_event_source(queue, al_get_timer_event_source(timer));

  bool          done = false;
  bool          draw = false;
  bool keyPressed[ALLEGRO_KEY_MAX] = {false};
  bool anyKeyPressed = {false};
  ALLEGRO_EVENT event;

  Canvas        canvas;
  View view{canvas, font};

  al_start_timer(timer);
  while (!done) {
    al_wait_for_event(queue, nullptr);
    while (al_get_next_event(queue, &event)) {
      switch (event.type) {
        case ALLEGRO_EVENT_KEY_DOWN:
          //https://www.allegro.cc/forums/thread/612907
          if (!keyPressed[event.keyboard.keycode]) {
            keyPressed[event.keyboard.keycode] = true;
            anyKeyPressed = true;
          }
          break;
        case ALLEGRO_EVENT_KEY_UP:
          keyPressed[event.keyboard.keycode] = false; // Mark the key as released
          anyKeyPressed = false;
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
      if (keyPressed[ALLEGRO_KEY_Q] or keyPressed[ALLEGRO_KEY_A]) {
        canvas.keyPressed(MODEL_LEFT);
      }
      if (keyPressed[ALLEGRO_KEY_D] or keyPressed[ALLEGRO_KEY_P]) {
        canvas.keyPressed(MODEL_RIGHT);
      }
      if((canvas.isGameWon() and anyKeyPressed) or (canvas.isGameOver() and keyPressed[ALLEGRO_KEY_R])){
        canvas = Canvas();
        view = View{canvas, font};
      }
      al_start_timer(timer);
      al_clear_to_color(al_map_rgb(255, 255, 255));
      view.draw();
      al_flip_display();
    }
  }

  al_destroy_font(font);
  al_destroy_display(disp);
  al_destroy_timer(timer);
  al_destroy_event_queue(queue);

  return 0;
}