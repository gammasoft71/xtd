#include "../../../include/xtd/drawing/cyan_colors"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color cyan_colors::aqua() noexcept {
  return color::from_known_color(known_color::aqua);
}

color cyan_colors::aquamarine() noexcept {
  return color::from_known_color(known_color::aquamarine);
}

color cyan_colors::cadet_blue() noexcept {
  return color::from_known_color(known_color::cadet_blue);
}

color cyan_colors::cyan() noexcept {
  return color::from_known_color(known_color::cyan);
}

color cyan_colors::dark_cyan() noexcept {
  return color::from_known_color(known_color::dark_cyan);
}

color cyan_colors::dark_turquoise() noexcept {
  return color::from_known_color(known_color::dark_turquoise);
}

color cyan_colors::light_cyan() noexcept {
  return color::from_known_color(known_color::light_cyan);
}

color cyan_colors::light_sea_green() noexcept {
  return color::from_known_color(known_color::light_sea_green);
}

color cyan_colors::medium_turquoise() noexcept {
  return color::from_known_color(known_color::medium_turquoise);
}

color cyan_colors::pale_turquoise() noexcept {
  return color::from_known_color(known_color::pale_turquoise);
}

color cyan_colors::teal() noexcept {
  return color::from_known_color(known_color::teal);
}

color cyan_colors::turquoise() noexcept {
  return color::from_known_color(known_color::turquoise);
}

const vector<color>& cyan_colors::get_colors() noexcept {
  static auto colors = vector {cyan_colors::teal(), cyan_colors::dark_cyan(), cyan_colors::light_sea_green(), cyan_colors::cadet_blue(), cyan_colors::dark_turquoise(), cyan_colors::medium_turquoise(), cyan_colors::turquoise(), cyan_colors::aqua(), cyan_colors::cyan(), cyan_colors::aquamarine(), cyan_colors::pale_turquoise(), cyan_colors::light_cyan()};
  return colors;
}

const vector<ustring>& cyan_colors::get_color_names() noexcept {
  static auto color_names = vector {cyan_colors::teal().name(), cyan_colors::dark_cyan().name(), cyan_colors::light_sea_green().name(), cyan_colors::cadet_blue().name(), cyan_colors::dark_turquoise().name(), cyan_colors::medium_turquoise().name(), cyan_colors::turquoise().name(), cyan_colors::aqua().name(), cyan_colors::cyan().name(), cyan_colors::aquamarine().name(), cyan_colors::pale_turquoise().name(), cyan_colors::light_cyan().name()};
  return color_names;
}
