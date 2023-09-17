#include "../../../include/xtd/drawing/brown_colors.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color brown_colors::bisque() noexcept {
  return color::from_known_color(known_color::bisque);
}

color brown_colors::blanched_almond() noexcept {
  return color::from_known_color(known_color::blanched_almond);
}

color brown_colors::brown() noexcept {
  return color::from_known_color(known_color::brown);
}

color brown_colors::burly_wood() noexcept {
  return color::from_known_color(known_color::burly_wood);
}

color brown_colors::chocolate() noexcept {
  return color::from_known_color(known_color::chocolate);
}

color brown_colors::cornsilk() noexcept {
  return color::from_known_color(known_color::cornsilk);
}

color brown_colors::dark_goldenrod() noexcept {
  return color::from_known_color(known_color::dark_goldenrod);
}

color brown_colors::goldenrod() noexcept {
  return color::from_known_color(known_color::goldenrod);
}

color brown_colors::maroon() noexcept {
  return color::from_known_color(known_color::maroon);
}

color brown_colors::navajo_white() noexcept {
  return color::from_known_color(known_color::navajo_white);
}

color brown_colors::peru() noexcept {
  return color::from_known_color(known_color::peru);
}

color brown_colors::rosy_brown() noexcept {
  return color::from_known_color(known_color::rosy_brown);
}

color brown_colors::saddle_brown() noexcept {
  return color::from_known_color(known_color::saddle_brown);
}

color brown_colors::sandy_brown() noexcept {
  return color::from_known_color(known_color::sandy_brown);
}

color brown_colors::sienna() noexcept {
  return color::from_known_color(known_color::sienna);
}

color brown_colors::tan() noexcept {
  return color::from_known_color(known_color::tan);
}

color brown_colors::wheat() noexcept {
  return color::from_known_color(known_color::wheat);
}

const vector<color>& brown_colors::get_colors() noexcept {
  static auto colors = vector {brown_colors::maroon(), brown_colors::brown(), brown_colors::saddle_brown(), brown_colors::sienna(), brown_colors::chocolate(), brown_colors::dark_goldenrod(), brown_colors::peru(), brown_colors::rosy_brown(), brown_colors::goldenrod(), brown_colors::sandy_brown(), brown_colors::tan(), brown_colors::burly_wood(), brown_colors::wheat(), brown_colors::navajo_white(), brown_colors::bisque(), brown_colors::blanched_almond(), brown_colors::cornsilk()};
  return colors;
}

const vector<ustring>& brown_colors::get_color_names() noexcept {
  static auto color_names = vector {brown_colors::maroon().name(), brown_colors::brown().name(), brown_colors::saddle_brown().name(), brown_colors::sienna().name(), brown_colors::chocolate().name(), brown_colors::dark_goldenrod().name(), brown_colors::peru().name(), brown_colors::rosy_brown().name(), brown_colors::goldenrod().name(), brown_colors::sandy_brown().name(), brown_colors::tan().name(), brown_colors::burly_wood().name(), brown_colors::wheat().name(), brown_colors::navajo_white().name(), brown_colors::bisque().name(), brown_colors::blanched_almond().name(), brown_colors::cornsilk().name()};
  return color_names;
}
