#include "../../../include/xtd/drawing/yellow_colors"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color yellow_colors::dark_khaki() noexcept {
  return color::from_known_color(known_color::dark_khaki);
}

color yellow_colors::gold() noexcept {
  return color::from_known_color(known_color::gold);
}

color yellow_colors::khaki() noexcept {
  return color::from_known_color(known_color::khaki);
}

color yellow_colors::lemon_chiffon() noexcept {
  return color::from_known_color(known_color::lemon_chiffon);
}

color yellow_colors::light_goldenrod_yellow() noexcept {
  return color::from_known_color(known_color::light_goldenrod_yellow);
}

color yellow_colors::light_yellow() noexcept {
  return color::from_known_color(known_color::light_yellow);
}

color yellow_colors::moccasin() noexcept {
  return color::from_known_color(known_color::moccasin);
}

color yellow_colors::pale_goldenrod() noexcept {
  return color::from_known_color(known_color::pale_goldenrod);
}

color yellow_colors::papaya_whip() noexcept {
  return color::from_known_color(known_color::papaya_whip);
}

color yellow_colors::peach_puff() noexcept {
  return color::from_known_color(known_color::peach_puff);
}

color yellow_colors::yellow() noexcept {
  return color::from_known_color(known_color::yellow);
}

const vector<color>& yellow_colors::get_colors() noexcept {
  static auto colors = vector {yellow_colors::dark_khaki(), yellow_colors::gold(), yellow_colors::khaki(), yellow_colors::peach_puff(), yellow_colors::yellow(), yellow_colors::pale_goldenrod(), yellow_colors::moccasin(), yellow_colors::papaya_whip(), yellow_colors::light_goldenrod_yellow(), yellow_colors::lemon_chiffon(), yellow_colors::light_yellow()};
  return colors;
}

const vector<ustring>& yellow_colors::get_color_names() noexcept {
  static auto color_names = vector {yellow_colors::dark_khaki().name(), yellow_colors::gold().name(), yellow_colors::khaki().name(), yellow_colors::peach_puff().name(), yellow_colors::yellow().name(), yellow_colors::pale_goldenrod().name(), yellow_colors::moccasin().name(), yellow_colors::papaya_whip().name(), yellow_colors::light_goldenrod_yellow().name(), yellow_colors::lemon_chiffon().name(), yellow_colors::light_yellow().name()};
  return color_names;
}
