#include <xtd/forms/native/screen.hpp>
#include <xtd/xtd.strings>
#include "control_handler.hpp"
#include <wx/display.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

size_t screen::count() {
  return wxDisplay::GetCount();
}

int32_t screen::bits_per_pixel(size_t index) {
  return wxDisplay(index).GetCurrentMode().GetDepth();
}

rectangle screen::bounds(size_t index) {
  wxRect bounds = wxDisplay(index).GetGeometry();
  return {bounds.GetX(), bounds.GetY(), bounds.GetWidth(), bounds.GetHeight()};
}

string screen::device_name(size_t index) {
  string device_name = wxDisplay(index).GetName().ToStdString();
  return device_name.empty() ? strings::format("\\\\.\\DISPLAY{}", index + 1) : device_name;
}

bool screen::primary(size_t index) {
  return wxDisplay(index).IsPrimary();
}

rectangle screen::working_area(size_t index) {
  wxRect working_area = wxDisplay(index).GetClientArea();
  return {working_area.GetX(), working_area.GetY(), working_area.GetWidth(), working_area.GetHeight()};
}

size_t screen::from_handle(intptr_t handle) {
  return wxDisplay::GetFromWindow(reinterpret_cast<control_handler*>(handle)->control());
}

size_t screen::from_point(const point& point) {
  return wxDisplay::GetFromPoint(wxPoint(point.x(), point.y()));
}
