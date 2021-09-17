#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/convert_string.h>
#include <xtd/drawing/native/hdc_wrapper.h>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/screen.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/ustring.h>
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
  return wxDisplay(static_cast<int32_t>(index)).GetCurrentMode().GetDepth();
}

rectangle screen::bounds(size_t index) {
  application::initialize();
  wxRect bounds = wxDisplay(static_cast<int32_t>(index)).GetGeometry();
  return {bounds.GetX(), bounds.GetY(), bounds.GetWidth(), bounds.GetHeight()};
}

std::string screen::device_name(size_t index) {
  application::initialize();
  std::string device_name = xtd::convert_string::to_string(wxDisplay(static_cast<int32_t>(index)).GetName().c_str().AsWChar());
  return device_name.empty() ? ustring::format("\\\\.\\DISPLAY{}", index + 1) : device_name;
}

int32_t screen::pixels_per_inch(size_t index) {
  application::initialize();
  return wxDisplay(static_cast<int32_t>(index)).GetPPI().GetHeight();
}

bool screen::primary(size_t index) {
  application::initialize();
  return wxDisplay(static_cast<int32_t>(index)).IsPrimary();
}

double screen::scale_factor(size_t index) {
  application::initialize();
  return wxDisplay(static_cast<int32_t>(index)).GetScaleFactor();
}

int32_t screen::standard_pixels_per_inch() {
  application::initialize();
  return wxDisplay::GetStdPPIValue();
}

rectangle screen::working_area(size_t index) {
  application::initialize();
  wxRect working_area = wxDisplay(static_cast<int32_t>(index)).GetClientArea();
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
