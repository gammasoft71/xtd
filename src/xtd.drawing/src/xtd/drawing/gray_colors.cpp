#include "../../../include/xtd/drawing/gray_colors"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color gray_colors::black() noexcept {
  return color::from_known_color(known_color::black);
}

color gray_colors::dark_gray() noexcept {
  return color::from_known_color(known_color::dark_gray);
}

color gray_colors::dark_slate_gray() noexcept {
  return color::from_known_color(known_color::dark_slate_gray);
}

color gray_colors::dim_gray() noexcept {
  return color::from_known_color(known_color::dim_gray);
}

color gray_colors::gainsboro() noexcept {
  return color::from_known_color(known_color::gainsboro);
}

color gray_colors::gray() noexcept {
  return color::from_known_color(known_color::gray);
}

color gray_colors::light_gray() noexcept {
  return color::from_known_color(known_color::light_gray);
}

color gray_colors::light_slate_gray() noexcept {
  return color::from_known_color(known_color::light_slate_gray);
}

color gray_colors::silver() noexcept {
  return color::from_known_color(known_color::silver);
}

color gray_colors::slate_gray() noexcept {
  return color::from_known_color(known_color::slate_gray);
}

const vector<color>& gray_colors::get_colors() noexcept {
  static auto colors = vector {gray_colors::black(), gray_colors::dark_slate_gray(), gray_colors::dim_gray(), gray_colors::slate_gray(), gray_colors::gray(), gray_colors::light_slate_gray(), gray_colors::dark_gray(), gray_colors::silver(), gray_colors::light_gray(), gray_colors::gainsboro()};
  return colors;
}

const vector<ustring>& gray_colors::get_color_names() noexcept {
  static auto color_names = vector {gray_colors::black().name(), gray_colors::dark_slate_gray().name(), gray_colors::dim_gray().name(), gray_colors::slate_gray().name(), gray_colors::gray().name(), gray_colors::light_slate_gray().name(), gray_colors::dark_gray().name(), gray_colors::silver().name(), gray_colors::light_gray().name(), gray_colors::gainsboro().name()};
  return color_names;
}
