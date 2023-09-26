#include "../../../include/xtd/drawing/red_colors"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color red_colors::crimson() noexcept {
  return color::from_known_color(known_color::crimson);
}

color red_colors::dark_red() noexcept {
  return color::from_known_color(known_color::dark_red);
}

color red_colors::dark_salmon() noexcept {
  return color::from_known_color(known_color::dark_salmon);
}

color red_colors::firebrick() noexcept {
  return color::from_known_color(known_color::firebrick);
}

color red_colors::indian_red() noexcept {
  return color::from_known_color(known_color::indian_red);
}

color red_colors::light_coral() noexcept {
  return color::from_known_color(known_color::light_coral);
}

color red_colors::light_salmon() noexcept {
  return color::from_known_color(known_color::light_salmon);
}

color red_colors::red() noexcept {
  return color::from_known_color(known_color::red);
}

color red_colors::salmon() noexcept {
  return color::from_known_color(known_color::salmon);
}

const vector<color>& red_colors::get_colors() noexcept {
  static auto colors = vector {red_colors::dark_red(), red_colors::red(), red_colors::firebrick(), red_colors::crimson(), red_colors::indian_red(), red_colors::light_coral(), red_colors::salmon(), red_colors::dark_salmon(), red_colors::light_salmon()};
  return colors;
}

const vector<ustring>& red_colors::get_color_names() noexcept {
  static auto color_names = vector {red_colors::dark_red().name(), red_colors::red().name(), red_colors::firebrick().name(), red_colors::crimson().name(), red_colors::indian_red().name(), red_colors::light_coral().name(), red_colors::salmon().name(), red_colors::dark_salmon().name(), red_colors::light_salmon().name()};
  return color_names;
}
