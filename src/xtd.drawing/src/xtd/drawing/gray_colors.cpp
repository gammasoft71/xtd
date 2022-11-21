#include "../../../include/xtd/drawing/gray_colors.h"

using namespace std;
using namespace xtd::drawing;

color gray_colors::black() {
  return color::from_known_color(known_color::black);
}

color gray_colors::dark_gray() {
  return color::from_known_color(known_color::dark_gray);
}

color gray_colors::dark_slate_gray() {
  return color::from_known_color(known_color::dark_slate_gray);
}

color gray_colors::dim_gray() {
  return color::from_known_color(known_color::dim_gray);
}

color gray_colors::gainsboro() {
  return color::from_known_color(known_color::gainsboro);
}

color gray_colors::gray() {
  return color::from_known_color(known_color::gray);
}

color gray_colors::light_gray() {
  return color::from_known_color(known_color::light_gray);
}

color gray_colors::light_slate_gray() {
  return color::from_known_color(known_color::light_slate_gray);
}

color gray_colors::silver() {
  return color::from_known_color(known_color::silver);
}

color gray_colors::slate_gray() {
  return color::from_known_color(known_color::slate_gray);
}

vector<color> gray_colors::get_colors() {
  return {gray_colors::black(), gray_colors::dark_slate_gray(), gray_colors::dim_gray(), gray_colors::slate_gray(), gray_colors::gray(), gray_colors::light_slate_gray(), gray_colors::dark_gray(), gray_colors::silver(), gray_colors::light_gray(), gray_colors::gainsboro()};
}
