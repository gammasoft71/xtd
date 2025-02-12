#include "../../../include/xtd/forms/screen.hpp"
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/screen>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <limits>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;

int32 screen::bits_per_pixel() const noexcept {
  return bits_per_pixel_;
}

const drawing::rectangle& screen::bounds() const noexcept {
  return bounds_;
}

const xtd::string& screen::device_name() const {
  return device_name_;
}

bool screen::high_resolution() const noexcept {
  return scale_factor_ > 1.;
}

int32 screen::pixels_per_inch() const noexcept {
  return pixels_per_inch_;
}

bool screen::primary() const noexcept {
  return primary_;
}

double screen::scale_factor() const noexcept {
  return scale_factor_;
}

const drawing::rectangle& screen::working_area() const noexcept {
  return working_area_;
}

std::vector<screen> screen::all_screens() {
  auto screens = std::vector<screen> {};
  auto count = native::screen::count();
  for (auto index = 0_z; index < count; index++)
    screens.push_back({native::screen::bits_per_pixel(index), native::screen::bounds(index), native::screen::device_name(index), native::screen::pixels_per_inch(index), native::screen::primary(index), native::screen::scale_factor(index), native::screen::working_area(index)});
  return screens;
}

screen screen::primary_screen() {
  auto screens = all_screens();
  for (auto& screen : screens)
    if (screen.primary()) return screen;
  return screens[0];
}

bool screen::equals(const object& obj) const noexcept {
  return is<screen>(obj) && equals(static_cast<const screen&>(obj));
}

bool screen::equals(const screen& other) const noexcept {
  return device_name_ == other.device_name_;
}

xtd::size screen::get_hash_code() const noexcept {
  return hash_code::combine(device_name_);
}

graphics screen::create_graphics() {
  return graphics(native::screen::create_graphics());
}

screen screen::from_control(const control& control) {
  if (control.handle() == 0) return primary_screen();
  auto index = native::screen::from_handle(control.handle());
  if (index == std::numeric_limits<size_t>::max() && control.parent().has_value()) index = native::screen::from_handle(control.parent().value().get().handle());
  if (index == std::numeric_limits<size_t>::max()) index = native::screen::from_point(forms::cursor::position());
  if (index == std::numeric_limits<size_t>::max()) index = 0;
  return all_screens()[index];
}

screen screen::from_handle(intptr handle) {
  if (handle == 0) return primary_screen();
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

rectangle screen::get_bounds(intptr handle) {
  return from_handle(handle).bounds();
}

rectangle screen::get_bounds(const point& point) {
  return from_point(point).bounds();
}

rectangle screen::get_bounds(const rectangle& rect) {
  return from_rectangle(rect).bounds();
}

int32 screen::get_standard_pixels_per_inch() {
  return native::screen::standard_pixels_per_inch();
}

rectangle screen::get_working_area(const control& control) {
  return from_control(control).working_area();
}

rectangle screen::get_working_area(intptr handle) {
  return from_handle(handle).working_area();
}

rectangle screen::get_working_area(const point& point) {
  return from_point(point).working_area();
}

rectangle screen::get_working_area(const rectangle& rect) {
  return from_rectangle(rect).working_area();
}

screen::screen(int32 bits_per_pixel, const drawing::rectangle& bounds, const xtd::string& device_name, int32 pixels_per_inch, bool primary, double scale_factor, const drawing::rectangle& working_area) : bits_per_pixel_(bits_per_pixel), bounds_(bounds), device_name_(device_name), pixels_per_inch_(pixels_per_inch), primary_(primary), scale_factor_(scale_factor), working_area_(working_area) {
}
