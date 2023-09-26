#include "../../../include/xtd/drawing/purple_colors"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color purple_colors::blue_violet() noexcept {
  return color::from_known_color(known_color::blue_violet);
}

color purple_colors::dark_magenta() noexcept {
  return color::from_known_color(known_color::dark_magenta);
}

color purple_colors::dark_orchid() noexcept {
  return color::from_known_color(known_color::dark_orchid);
}

color purple_colors::dark_slate_blue() noexcept {
  return color::from_known_color(known_color::dark_slate_blue);
}

color purple_colors::dark_violet() noexcept {
  return color::from_known_color(known_color::dark_violet);
}

color purple_colors::fuchsia() noexcept {
  return color::from_known_color(known_color::fuchsia);
}

color purple_colors::indigo() noexcept {
  return color::from_known_color(known_color::indigo);
}

color purple_colors::lavender() noexcept {
  return color::from_known_color(known_color::lavender);
}

color purple_colors::magenta() noexcept {
  return color::from_known_color(known_color::magenta);
}

color purple_colors::medium_orchid() noexcept {
  return color::from_known_color(known_color::medium_orchid);
}

color purple_colors::medium_purple() noexcept {
  return color::from_known_color(known_color::medium_purple);
}

color purple_colors::medium_slate_blue() noexcept {
  return color::from_known_color(known_color::medium_slate_blue);
}

color purple_colors::orchid() noexcept {
  return color::from_known_color(known_color::orchid);
}

color purple_colors::plum() noexcept {
  return color::from_known_color(known_color::plum);
}

color purple_colors::purple() noexcept {
  return color::from_known_color(known_color::purple);
}

color purple_colors::rebecca_purple() noexcept {
  return color::from_known_color(known_color::rebecca_purple);
}

color purple_colors::slate_blue() noexcept {
  return color::from_known_color(known_color::slate_blue);
}

color purple_colors::thistle() noexcept {
  return color::from_known_color(known_color::thistle);
}

color purple_colors::violet() noexcept {
  return color::from_known_color(known_color::violet);
}

const vector<color>& purple_colors::get_colors() noexcept {
  static auto colors = vector {purple_colors::indigo(), purple_colors::rebecca_purple(), purple_colors::purple(), purple_colors::dark_magenta(), purple_colors::dark_violet(), purple_colors::dark_slate_blue(), purple_colors::blue_violet(), purple_colors::dark_orchid(), purple_colors::fuchsia(), purple_colors::magenta(), purple_colors::slate_blue(), purple_colors::medium_slate_blue(), purple_colors::medium_orchid(), purple_colors::medium_purple(), purple_colors::orchid(), purple_colors::violet(), purple_colors::plum(), purple_colors::thistle(), purple_colors::lavender()};
  return colors;
}

const vector<ustring>& purple_colors::get_color_names() noexcept {
  static auto color_names = vector {purple_colors::indigo().name(), purple_colors::rebecca_purple().name(), purple_colors::purple().name(), purple_colors::dark_magenta().name(), purple_colors::dark_violet().name(), purple_colors::dark_slate_blue().name(), purple_colors::blue_violet().name(), purple_colors::dark_orchid().name(), purple_colors::fuchsia().name(), purple_colors::magenta().name(), purple_colors::slate_blue().name(), purple_colors::medium_slate_blue().name(), purple_colors::medium_orchid().name(), purple_colors::medium_purple().name(), purple_colors::orchid().name(), purple_colors::violet().name(), purple_colors::plum().name(), purple_colors::thistle().name(), purple_colors::lavender().name()};
  return color_names;
}
