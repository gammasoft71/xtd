#include "../../../include/xtd/drawing/orange_colors.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color orange_colors::coral() noexcept {
  return color::from_known_color(known_color::coral);
}

color orange_colors::dark_orange() noexcept {
  return color::from_known_color(known_color::dark_orange);
}

color orange_colors::orange_red() noexcept {
  return color::from_known_color(known_color::orange_red);
}

color orange_colors::tomato() noexcept {
  return color::from_known_color(known_color::tomato);
}

color orange_colors::orange() noexcept {
  return color::from_known_color(known_color::orange);
}

const vector<color>& orange_colors::get_colors() noexcept {
  static auto colors = vector {orange_colors::orange_red(), orange_colors::tomato(), orange_colors::dark_orange(), orange_colors::coral(), orange_colors::orange()};
  return colors;
}

const vector<ustring>& orange_colors::get_color_names() noexcept {
  static auto color_names = vector {orange_colors::orange_red().name(), orange_colors::tomato().name(), orange_colors::dark_orange().name(), orange_colors::coral().name(), orange_colors::orange().name()};
  return color_names;
}
