#include "../../../include/xtd/drawing/blue_colors.h"

using namespace std;
using namespace xtd::drawing;

color blue_colors::blue() {
  return color::from_known_color(known_color::blue);
}

color blue_colors::cornflower_blue() {
  return color::from_known_color(known_color::cornflower_blue);
}

color blue_colors::dark_blue() {
  return color::from_known_color(known_color::dark_blue);
}

color blue_colors::deep_sky_blue() {
  return color::from_known_color(known_color::deep_sky_blue);
}

color blue_colors::dodger_blue() {
  return color::from_known_color(known_color::dodger_blue);
}

color blue_colors::light_blue() {
  return color::from_known_color(known_color::light_blue);
}

color blue_colors::light_sky_blue() {
  return color::from_known_color(known_color::light_sky_blue);
}

color blue_colors::light_steel_blue() {
  return color::from_known_color(known_color::light_steel_blue);
}

color blue_colors::medium_blue() {
  return color::from_known_color(known_color::medium_blue);
}

color blue_colors::midnight_blue() {
  return color::from_known_color(known_color::midnight_blue);
}

color blue_colors::navy() {
  return color::from_known_color(known_color::navy);
}

color blue_colors::powder_blue() {
  return color::from_known_color(known_color::powder_blue);
}

color blue_colors::royal_blue() {
  return color::from_known_color(known_color::royal_blue);
}

color blue_colors::sky_blue() {
  return color::from_known_color(known_color::sky_blue);
}

color blue_colors::steel_blue() {
  return color::from_known_color(known_color::steel_blue);
}

vector<color> blue_colors::get_colors() {
  return {blue_colors::midnight_blue(), blue_colors::navy(), blue_colors::dark_blue(), blue_colors::medium_blue(), blue_colors::blue(), blue_colors::royal_blue(), blue_colors::steel_blue(), blue_colors::dodger_blue(), blue_colors::deep_sky_blue(), blue_colors::cornflower_blue(), blue_colors::sky_blue(), blue_colors::light_sky_blue(), blue_colors::light_steel_blue(), blue_colors::light_blue(), blue_colors::powder_blue()};
}
