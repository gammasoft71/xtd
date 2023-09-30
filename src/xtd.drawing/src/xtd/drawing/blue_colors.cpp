#include "../../../include/xtd/drawing/blue_colors.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color blue_colors::blue() noexcept {
  return color::from_known_color(known_color::blue);
}

color blue_colors::cornflower_blue() noexcept {
  return color::from_known_color(known_color::cornflower_blue);
}

color blue_colors::dark_blue() noexcept {
  return color::from_known_color(known_color::dark_blue);
}

color blue_colors::deep_sky_blue() noexcept {
  return color::from_known_color(known_color::deep_sky_blue);
}

color blue_colors::dodger_blue() noexcept {
  return color::from_known_color(known_color::dodger_blue);
}

color blue_colors::light_blue() noexcept {
  return color::from_known_color(known_color::light_blue);
}

color blue_colors::light_sky_blue() noexcept {
  return color::from_known_color(known_color::light_sky_blue);
}

color blue_colors::light_steel_blue() noexcept {
  return color::from_known_color(known_color::light_steel_blue);
}

color blue_colors::medium_blue() noexcept {
  return color::from_known_color(known_color::medium_blue);
}

color blue_colors::midnight_blue() noexcept {
  return color::from_known_color(known_color::midnight_blue);
}

color blue_colors::navy() noexcept {
  return color::from_known_color(known_color::navy);
}

color blue_colors::powder_blue() noexcept {
  return color::from_known_color(known_color::powder_blue);
}

color blue_colors::royal_blue() noexcept {
  return color::from_known_color(known_color::royal_blue);
}

color blue_colors::sky_blue() noexcept {
  return color::from_known_color(known_color::sky_blue);
}

color blue_colors::steel_blue() noexcept {
  return color::from_known_color(known_color::steel_blue);
}

const vector<color>& blue_colors::get_colors() noexcept {
  static auto colors = vector {blue_colors::midnight_blue(), blue_colors::navy(), blue_colors::dark_blue(), blue_colors::medium_blue(), blue_colors::blue(), blue_colors::royal_blue(), blue_colors::steel_blue(), blue_colors::dodger_blue(), blue_colors::deep_sky_blue(), blue_colors::cornflower_blue(), blue_colors::sky_blue(), blue_colors::light_sky_blue(), blue_colors::light_steel_blue(), blue_colors::light_blue(), blue_colors::powder_blue()};
  return colors;
}

const vector<ustring>& blue_colors::get_color_names() noexcept {
  static auto color_names = vector {blue_colors::midnight_blue().name(), blue_colors::navy().name(), blue_colors::dark_blue().name(), blue_colors::medium_blue().name(), blue_colors::blue().name(), blue_colors::royal_blue().name(), blue_colors::steel_blue().name(), blue_colors::dodger_blue().name(), blue_colors::deep_sky_blue().name(), blue_colors::cornflower_blue().name(), blue_colors::sky_blue().name(), blue_colors::light_sky_blue().name(), blue_colors::light_steel_blue().name(), blue_colors::light_blue().name(), blue_colors::powder_blue().name()};
  return color_names;
}
