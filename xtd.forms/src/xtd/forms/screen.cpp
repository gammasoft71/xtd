#include "../../../include/xtd/forms/screen.hpp"
#include <xtd/forms/native/screen.hpp>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

vector<screen> screen::all_screens() {
  vector<screen> screens;
  size_t count = native::screen::count();
  for (size_t index = 0; index < count; index++)
    sscreens.push_back({native::screen::bits_per_pixel(index), native::screen::bounds(index), native::screen::device_name(index), native::screen::primary(index), native::screen::working_area(index)});
  return screens;
}

const screen& screen::from_control(const control& control) {
  return all_screens()[natives::screen::from_handle(control.__get_handle__())];
}

const screen& screen::from_handle(intptr_t handle) {
  return from_control(control::from_handle(handle));
}

const screen& screen::from_point(const point& point) {
  return all_screens()[natives::screen::from_point(point)];
}

const screen& screen::from_rectangle(const rectangle& rect) {
  return from_point(rect.location());
}

const rectangle& screen::get_bounds(const control& control) {
  return all_screens()[natives::screen::from_handle(control.__get_handle__())].bounds();
}

const rectangle& screen::get_bounds(intptr_t handle) {
  return get_bounds(control::from_handle(handle));
}

const rectangle& screen::get_bounds(const point& point) {
  return all_screens()[natives::screen::from_point(point)].bounds();
}

const rectangle& screen::get_bounds(const rectangle& rect) {
  return get_bounds(rect.location());
}
