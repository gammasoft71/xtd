#include <xtd/drawing/native/fl_dc.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/screen.hpp>
#include <xtd/xtd.strings>
#include "control_handler.hpp"
#include <FL/Fl.H>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t screen::create_graphics() {
  application::initialize();
  return reinterpret_cast<intptr_t>(new drawing::native::fl_screen_dc());
}

size_t screen::count() {
  application::initialize();
  return Fl::screen_count();
}

int32_t screen::bits_per_pixel(size_t index) {
  application::initialize();
  float h = 0, v = 0;
  Fl::screen_dpi(h, v, index);
  return h;
}

rectangle screen::bounds(size_t index) {
  application::initialize();
  int x = 0, y = 0, w = 0, h = 0;
  Fl::screen_xywh(x, y, w, h, index);
  return {x, y, w, h};
}

ustring screen::device_name(size_t index) {
  application::initialize();
  return strings::format("\\\\.\\DISPLAY{}", index + 1);
}

bool screen::primary(size_t index) {
  application::initialize();
  return index == 0;
}

rectangle screen::working_area(size_t index) {
  application::initialize();
  int x = 0, y = 0, w = 0, h = 0;
  Fl::screen_work_area(x, y, w, h, index);
  return {x, y, w, h};
}

size_t screen::from_handle(intptr_t handle) {
  application::initialize();
  int x = 0, y = 0;
  Fl_Widget* widget = reinterpret_cast<Fl_Widget*>(handle);
  while (widget) {
    x += widget->x();
    y += widget->y();
    
    widget = widget->parent();
  }
  
  return Fl::screen_num(x, y, reinterpret_cast<Fl_Widget*>(handle)->w(), reinterpret_cast<Fl_Widget*>(handle)->h());
}

size_t screen::from_point(const point& point) {
  application::initialize();
  return Fl::screen_num(point.x(), point.y());
}
