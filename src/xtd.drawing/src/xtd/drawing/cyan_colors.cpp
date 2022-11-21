#include "../../../include/xtd/drawing/cyan_colors.h"

using namespace std;
using namespace xtd::drawing;

color cyan_colors::aqua() {
  return color::from_known_color(known_color::aqua);
}

color cyan_colors::aquamarine() {
  return color::from_known_color(known_color::aquamarine);
}

color cyan_colors::cadet_blue() {
  return color::from_known_color(known_color::cadet_blue);
}

color cyan_colors::cyan() {
  return color::from_known_color(known_color::cyan);
}

color cyan_colors::dark_cyan() {
  return color::from_known_color(known_color::dark_cyan);
}

color cyan_colors::dark_turquoise() {
  return color::from_known_color(known_color::dark_turquoise);
}

color cyan_colors::light_cyan() {
  return color::from_known_color(known_color::light_cyan);
}

color cyan_colors::light_sea_green() {
  return color::from_known_color(known_color::light_sea_green);
}

color cyan_colors::medium_turquoise() {
  return color::from_known_color(known_color::medium_turquoise);
}

color cyan_colors::pale_turquoise() {
  return color::from_known_color(known_color::pale_turquoise);
}

color cyan_colors::teal() {
  return color::from_known_color(known_color::teal);
}

color cyan_colors::turquoise() {
  return color::from_known_color(known_color::turquoise);
}

vector<color> cyan_colors::get_colors() {
  return {cyan_colors::teal(), cyan_colors::dark_cyan(), cyan_colors::light_sea_green(), cyan_colors::cadet_blue(), cyan_colors::dark_turquoise(), cyan_colors::medium_turquoise(), cyan_colors::turquoise(), cyan_colors::aqua(), cyan_colors::cyan(), cyan_colors::aquamarine(), cyan_colors::pale_turquoise(), cyan_colors::light_cyan()};
}
