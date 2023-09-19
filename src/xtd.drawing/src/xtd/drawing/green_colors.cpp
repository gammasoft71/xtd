#include "../../../include/xtd/drawing/green_colors.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;

color green_colors::chartreuse() noexcept {
  return color::from_known_color(known_color::chartreuse);
}

color green_colors::dark_green() noexcept {
  return color::from_known_color(known_color::dark_green);
}

color green_colors::dark_olive_green() noexcept {
  return color::from_known_color(known_color::dark_olive_green);
}

color green_colors::dark_sea_green() noexcept {
  return color::from_known_color(known_color::dark_sea_green);
}

color green_colors::green() noexcept {
  return color::from_known_color(known_color::green);
}

color green_colors::green_yellow() noexcept {
  return color::from_known_color(known_color::green_yellow);
}

color green_colors::forest_green() noexcept {
  return color::from_known_color(known_color::forest_green);
}

color green_colors::lawn_green() noexcept {
  return color::from_known_color(known_color::lawn_green);
}

color green_colors::light_green() noexcept {
  return color::from_known_color(known_color::light_green);
}

color green_colors::lime() noexcept {
  return color::from_known_color(known_color::lime);
}

color green_colors::lime_green() noexcept {
  return color::from_known_color(known_color::lime_green);
}

color green_colors::medium_aquamarine() noexcept {
  return color::from_known_color(known_color::medium_aquamarine);
}

color green_colors::medium_sea_green() noexcept {
  return color::from_known_color(known_color::medium_sea_green);
}

color green_colors::medium_spring_green() noexcept {
  return color::from_known_color(known_color::medium_spring_green);
}

color green_colors::olive() noexcept {
  return color::from_known_color(known_color::olive);
}

color green_colors::olive_drab() noexcept {
  return color::from_known_color(known_color::olive_drab);
}

color green_colors::pale_green() noexcept {
  return color::from_known_color(known_color::pale_green);
}

color green_colors::sea_green() noexcept {
  return color::from_known_color(known_color::sea_green);
}

color green_colors::spring_green() noexcept {
  return color::from_known_color(known_color::spring_green);
}

color green_colors::yellow_green() noexcept {
  return color::from_known_color(known_color::yellow_green);
}

const vector<color>& green_colors::get_colors() noexcept {
  static auto colors = vector {green_colors::dark_green(), green_colors::green(), green_colors::dark_olive_green(), green_colors::forest_green(), green_colors::sea_green(), green_colors::olive(), green_colors::olive_drab(), green_colors::medium_sea_green(), green_colors::lime_green(), green_colors::lime(), green_colors::spring_green(), green_colors::medium_spring_green(), green_colors::dark_sea_green(), green_colors::medium_aquamarine(), green_colors::yellow_green(), green_colors::lawn_green(), green_colors::chartreuse(), green_colors::light_green(), green_colors::green_yellow(), green_colors::pale_green()};
  return colors;
}

const vector<ustring>& green_colors::get_color_names() noexcept {
  static auto color_names = vector {green_colors::dark_green().name(), green_colors::green().name(), green_colors::dark_olive_green().name(), green_colors::forest_green().name(), green_colors::sea_green().name(), green_colors::olive().name(), green_colors::olive_drab().name(), green_colors::medium_sea_green().name(), green_colors::lime_green().name(), green_colors::lime().name(), green_colors::spring_green().name(), green_colors::medium_spring_green().name(), green_colors::dark_sea_green().name(), green_colors::medium_aquamarine().name(), green_colors::yellow_green().name(), green_colors::lawn_green().name(), green_colors::chartreuse().name(), green_colors::light_green().name(), green_colors::green_yellow().name(), green_colors::pale_green().name()};
  return color_names;
}
