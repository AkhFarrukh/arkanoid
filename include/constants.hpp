//
// Created by farrukh on 31/12/24.
//

#ifndef ARKANOID_CONSTANTS_HPP
#define ARKANOID_CONSTANTS_HPP

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


#include <numbers>

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
inline ALLEGRO_FONT *font; //todo


#endif //ARKANOID_CONSTANTS_HPP
