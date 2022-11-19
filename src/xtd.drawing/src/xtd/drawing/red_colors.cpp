#include "../../../include/xtd/drawing/red_colors.h"

using namespace std;
using namespace xtd::drawing;

color red_colors::crimson() {
  return color::from_known_color(known_color::crimson);
}

color red_colors::dark_red() {
  return color::from_known_color(known_color::dark_red);
}

color red_colors::dark_salmon() {
  return color::from_known_color(known_color::dark_salmon);
}

color red_colors::firebrick() {
  return color::from_known_color(known_color::firebrick);
}

color red_colors::indian_red() {
  return color::from_known_color(known_color::indian_red);
}

color red_colors::light_coral() {
  return color::from_known_color(known_color::light_coral);
}

color red_colors::light_salmon() {
  return color::from_known_color(known_color::light_salmon);
}

color red_colors::red() {
  return color::from_known_color(known_color::red);
}

color red_colors::salmon() {
  return color::from_known_color(known_color::salmon);
}

vector<color> red_colors::get_colors() {
  return {red_colors::dark_red(), red_colors::red(), red_colors::firebrick(), red_colors::crimson(), red_colors::indian_red(), red_colors::light_coral(), red_colors::salmon(), red_colors::dark_salmon(), red_colors::light_salmon()};
}
