#include "../../../include/xtd/drawing/apple_colors.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color apple_colors::black() noexcept {
  return color::from_known_color(known_color::apple_black);
}

color apple_colors::blue() noexcept {
  return color::from_known_color(known_color::apple_blue);
}

color apple_colors::brown() noexcept {
  return color::from_known_color(known_color::apple_brown);
}

color apple_colors::cyan() noexcept {
  return color::from_known_color(known_color::apple_cyan);
}

color apple_colors::green() noexcept {
  return color::from_known_color(known_color::apple_green);
}

color apple_colors::magenta() noexcept {
  return color::from_known_color(known_color::apple_magenta);
}

color apple_colors::orange() noexcept {
  return color::from_known_color(known_color::apple_orange);
}

color apple_colors::purple() noexcept {
  return color::from_known_color(known_color::apple_purple);
}

color apple_colors::red() noexcept {
  return color::from_known_color(known_color::apple_red);
}

color apple_colors::yellow() noexcept {
  return color::from_known_color(known_color::apple_yellow);
}

color apple_colors::white() noexcept {
  return color::from_known_color(known_color::apple_white);
}

const vector<color>& apple_colors::get_colors() noexcept {
  static auto colors = vector {apple_colors::black(), apple_colors::blue(), apple_colors::brown(), apple_colors::cyan(), apple_colors::green(), apple_colors::magenta(), apple_colors::orange(), apple_colors::purple(), apple_colors::red(), apple_colors::yellow(), apple_colors::white()};
  return colors;
}

const vector<ustring>& apple_colors::get_color_names() noexcept {
  static auto color_names = vector {apple_colors::black().name(), apple_colors::blue().name(), apple_colors::brown().name(), apple_colors::cyan().name(), apple_colors::green().name(), apple_colors::magenta().name(), apple_colors::orange().name(), apple_colors::purple().name(), apple_colors::red().name(), apple_colors::yellow().name(), apple_colors::white().name()};
  return color_names;
}
