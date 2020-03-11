#include "../../../include/xtd/forms/screen.h"
#include <xtd/forms/native/screen.h>

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
  size_t index = native::screen::from_handle(control.handle());
  if (index == -1 && control.parent().has_value()) index = native::screen::from_handle(control.parent().value().get().handle());
  if (index == -1) index  = native::screen::from_point(forms::cursor::position());
  return all_screens()[index];
}

screen screen::from_handle(intptr_t handle) {
  return from_control(control::from_handle(handle).value().get());
}

screen screen::from_point(const point& point) {
  return all_screens()[native::screen::from_point(point)];
}

screen screen::from_rectangle(const rectangle& rect) {
  return from_point(rect.location());
}

 rectangle screen::get_bounds(const control& control) {
  return from_control(control).bounds();
}

rectangle screen::get_bounds(intptr_t handle) {
  return from_handle(handle).bounds();
}

rectangle screen::get_bounds(const point& point) {
  return from_point(point).bounds();
}

rectangle screen::get_bounds(const rectangle& rect) {
  return from_rectangle(rect).bounds();
}

rectangle screen::get_working_area(const control& control) {
  return from_control(control).working_area();
}

rectangle screen::get_working_area(intptr_t handle) {
  return from_handle(handle).working_area();
}

rectangle screen::get_working_area(const point& point) {
  return from_point(point).working_area();
}

rectangle screen::get_working_area(const rectangle& rect) {
  return from_rectangle(rect).working_area();
}
