#include "../../../include/xtd/drawing/brown_colors.h"

using namespace std;
using namespace xtd::drawing;

color brown_colors::bisque() {
  return color::from_known_color(known_color::bisque);
}

color brown_colors::blanched_almond() {
  return color::from_known_color(known_color::blanched_almond);
}

color brown_colors::brown() {
  return color::from_known_color(known_color::brown);
}

color brown_colors::burly_wood() {
  return color::from_known_color(known_color::burly_wood);
}

color brown_colors::chocolate() {
  return color::from_known_color(known_color::chocolate);
}

color brown_colors::cornsilk() {
  return color::from_known_color(known_color::cornsilk);
}

color brown_colors::dark_goldenrod() {
  return color::from_known_color(known_color::dark_goldenrod);
}

color brown_colors::goldenrod() {
  return color::from_known_color(known_color::goldenrod);
}

color brown_colors::maroon() {
  return color::from_known_color(known_color::maroon);
}

color brown_colors::navajo_white() {
  return color::from_known_color(known_color::navajo_white);
}

color brown_colors::peru() {
  return color::from_known_color(known_color::peru);
}

color brown_colors::rosy_brown() {
  return color::from_known_color(known_color::rosy_brown);
}

color brown_colors::saddle_brown() {
  return color::from_known_color(known_color::saddle_brown);
}

color brown_colors::sandy_brown() {
  return color::from_known_color(known_color::sandy_brown);
}

color brown_colors::sienna() {
  return color::from_known_color(known_color::sienna);
}

color brown_colors::tan() {
  return color::from_known_color(known_color::tan);
}

color brown_colors::wheat() {
  return color::from_known_color(known_color::wheat);
}

vector<color> brown_colors::get_colors() {
  return {brown_colors::maroon(), brown_colors::brown(), brown_colors::saddle_brown(), brown_colors::sienna(), brown_colors::chocolate(), brown_colors::dark_goldenrod(), brown_colors::peru(), brown_colors::rosy_brown(), brown_colors::goldenrod(), brown_colors::sandy_brown(), brown_colors::tan(), brown_colors::burly_wood(), brown_colors::wheat(), brown_colors::navajo_white(), brown_colors::bisque(), brown_colors::blanched_almond(), brown_colors::cornsilk()};
}
