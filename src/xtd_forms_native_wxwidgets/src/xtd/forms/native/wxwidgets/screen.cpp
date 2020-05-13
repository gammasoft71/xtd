#include <xtd/drawing/native/hdc_wrapper.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/screen.h>
#include <xtd/xtd.strings>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include <wx/dcscreen.h>
#include <wx/display.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr_t screen::create_graphics() {
  application::initialize();
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  hdc_wrapper->create<wxScreenDC>();
  return reinterpret_cast<intptr_t>(hdc_wrapper);
}

size_t screen::count() {
  application::initialize();
  return wxDisplay::GetCount();
}

int32_t screen::bits_per_pixel(size_t index) {
  application::initialize();
  return wxDisplay(index).GetCurrentMode().GetDepth();
}

rectangle screen::bounds(size_t index) {
  application::initialize();
  wxRect bounds = wxDisplay(index).GetGeometry();
  return {bounds.GetX(), bounds.GetY(), bounds.GetWidth(), bounds.GetHeight()};
}

std::string screen::device_name(size_t index) {
  application::initialize();
  std::string device_name = wxDisplay(index).GetName().utf8_str().data();
  return device_name.empty() ? strings::format("\\\\.\\DISPLAY{}", index + 1) : device_name;
}

bool screen::primary(size_t index) {
  application::initialize();
  return wxDisplay(index).IsPrimary();
}

rectangle screen::working_area(size_t index) {
  application::initialize();
  wxRect working_area = wxDisplay(index).GetClientArea();
  return {working_area.GetX(), working_area.GetY(), working_area.GetWidth(), working_area.GetHeight()};
}

size_t screen::from_handle(intptr_t handle) {
  application::initialize();
  return wxDisplay::GetFromWindow(reinterpret_cast<control_handler*>(handle)->control());
}

size_t screen::from_point(const point& point) {
  application::initialize();
  return wxDisplay::GetFromPoint(wxPoint(point.x(), point.y()));
}
