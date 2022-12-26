#include "../../../include/xtd/drawing/white_colors.h"

using namespace std;
using namespace xtd::drawing;

color white_colors::alice_blue() {
  return color::from_known_color(known_color::alice_blue);
}

color white_colors::antique_white() {
  return color::from_known_color(known_color::antique_white);
}

color white_colors::azure() {
  return color::from_known_color(known_color::azure);
}

color white_colors::beige() {
  return color::from_known_color(known_color::beige);
}

color white_colors::floral_white() {
  return color::from_known_color(known_color::floral_white);
}

color white_colors::ghost_white() {
  return color::from_known_color(known_color::ghost_white);
}

color white_colors::honeydew() {
  return color::from_known_color(known_color::honeydew);
}

color white_colors::ivory() {
  return color::from_known_color(known_color::ivory);
}

color white_colors::lavender_blush() {
  return color::from_known_color(known_color::lavender_blush);
}

color white_colors::linen() {
  return color::from_known_color(known_color::linen);
}

color white_colors::mint_cream() {
  return color::from_known_color(known_color::mint_cream);
}

color white_colors::misty_rose() {
  return color::from_known_color(known_color::misty_rose);
}

color white_colors::old_lace() {
  return color::from_known_color(known_color::old_lace);
}

color white_colors::sea_shell() {
  return color::from_known_color(known_color::sea_shell);
}

color white_colors::snow() {
  return color::from_known_color(known_color::snow);
}

color white_colors::white() {
  return color::from_known_color(known_color::white);
}

color white_colors::white_smoke() {
  return color::from_known_color(known_color::white_smoke);
}

const vector<color>& white_colors::get_colors() {
  static vector<color> colors {white_colors::misty_rose(), white_colors::antique_white(), white_colors::linen(), white_colors::beige(), white_colors::white_smoke(), white_colors::lavender_blush(), white_colors::old_lace(), white_colors::alice_blue(), white_colors::sea_shell(), white_colors::ghost_white(), white_colors::honeydew(), white_colors::floral_white(), white_colors::azure(), white_colors::mint_cream(), white_colors::snow(), white_colors::ivory(), white_colors::white()};
  return colors;
}
