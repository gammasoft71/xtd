#include "../../../include/xtd/drawing/white_colors.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color white_colors::alice_blue() noexcept {
  return color::from_known_color(known_color::alice_blue);
}

color white_colors::antique_white() noexcept {
  return color::from_known_color(known_color::antique_white);
}

color white_colors::azure() noexcept {
  return color::from_known_color(known_color::azure);
}

color white_colors::beige() noexcept {
  return color::from_known_color(known_color::beige);
}

color white_colors::floral_white() noexcept {
  return color::from_known_color(known_color::floral_white);
}

color white_colors::ghost_white() noexcept {
  return color::from_known_color(known_color::ghost_white);
}

color white_colors::honeydew() noexcept {
  return color::from_known_color(known_color::honeydew);
}

color white_colors::ivory() noexcept {
  return color::from_known_color(known_color::ivory);
}

color white_colors::lavender_blush() noexcept {
  return color::from_known_color(known_color::lavender_blush);
}

color white_colors::linen() noexcept {
  return color::from_known_color(known_color::linen);
}

color white_colors::mint_cream() noexcept {
  return color::from_known_color(known_color::mint_cream);
}

color white_colors::misty_rose() noexcept {
  return color::from_known_color(known_color::misty_rose);
}

color white_colors::old_lace() noexcept {
  return color::from_known_color(known_color::old_lace);
}

color white_colors::sea_shell() noexcept {
  return color::from_known_color(known_color::sea_shell);
}

color white_colors::snow() noexcept {
  return color::from_known_color(known_color::snow);
}

color white_colors::white() noexcept {
  return color::from_known_color(known_color::white);
}

color white_colors::white_smoke() noexcept {
  return color::from_known_color(known_color::white_smoke);
}

const vector<color>& white_colors::get_colors() noexcept {
  static auto colors = vector {white_colors::misty_rose(), white_colors::antique_white(), white_colors::linen(), white_colors::beige(), white_colors::white_smoke(), white_colors::lavender_blush(), white_colors::old_lace(), white_colors::alice_blue(), white_colors::sea_shell(), white_colors::ghost_white(), white_colors::honeydew(), white_colors::floral_white(), white_colors::azure(), white_colors::mint_cream(), white_colors::snow(), white_colors::ivory(), white_colors::white()};
  return colors;
}

const vector<ustring>& white_colors::get_color_names() noexcept {
  static auto color_names = vector {white_colors::misty_rose().name(), white_colors::antique_white().name(), white_colors::linen().name(), white_colors::beige().name(), white_colors::white_smoke().name(), white_colors::lavender_blush().name(), white_colors::old_lace().name(), white_colors::alice_blue().name(), white_colors::sea_shell().name(), white_colors::ghost_white().name(), white_colors::honeydew().name(), white_colors::floral_white().name(), white_colors::azure().name(), white_colors::mint_cream().name(), white_colors::snow().name(), white_colors::ivory().name(), white_colors::white().name()};
  return color_names;
}
