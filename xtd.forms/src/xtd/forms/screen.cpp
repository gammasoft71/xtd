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
    screens.push_back({native::screen::bits_per_pixel(index), native::screen::bounds(index), native::screen::device_name(index), native::screen::primary(index), native::screen::working_area(index)});
  return screens;
}

graphics screen::create_graphics() {
  return graphics(native::screen::create_graphics());
}

screen screen::from_control(const control& control) {
  return all_screens()[native::screen::from_handle(control.data_->handle_)];
}

screen screen::from_handle(intptr_t handle) {
  return from_control(control::from_handle(handle));
}

screen screen::from_point(const point& point) {
  return all_screens()[native::screen::from_point(point)];
}

screen screen::from_rectangle(const rectangle& rect) {
  return from_point(rect.location());
}

 rectangle screen::get_bounds(const control& control) {
  return all_screens()[native::screen::from_handle(control.data_->handle_)].bounds();
}

rectangle screen::get_bounds(intptr_t handle) {
  return get_bounds(control::from_handle(handle));
}

rectangle screen::get_bounds(const point& point) {
  return all_screens()[native::screen::from_point(point)].bounds();
}

rectangle screen::get_bounds(const rectangle& rect) {
  return get_bounds(rect.location());
}

rectangle screen::get_working_area(const control& control) {
  return all_screens()[native::screen::from_handle(control.data_->handle_)].working_area();
}

rectangle screen::get_working_area(intptr_t handle) {
  return get_working_area(control::from_handle(handle));
}

rectangle screen::get_working_area(const point& point) {
  return all_screens()[native::screen::from_point(point)].working_area();
}

rectangle screen::get_working_area(const rectangle& rect) {
  return get_working_area(rect.location());
}
