#define __XTD_DRAWING_NATIVE_LIBRARY__
#include <xtd/drawing/native/hdc_wrapper>
#define __XTD_DRAWING_NATIVE_LIBRARY__
#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include <xtd/forms/native/application>
#include <xtd/forms/native/screen>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/convert_string>
#include <xtd/ustring>
#include <wx/dcscreen.h>
#include <wx/display.h>

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

intptr screen::create_graphics() {
  application::initialize();
  xtd::drawing::native::hdc_wrapper* hdc_wrapper = new xtd::drawing::native::hdc_wrapper;
  hdc_wrapper->create<wxScreenDC>();
  return reinterpret_cast<intptr>(hdc_wrapper);
}

size_t screen::count() {
  application::initialize();
  return wxDisplay::GetCount();
}

int32 screen::bits_per_pixel(size_t index) {
  application::initialize();
  return wxDisplay(static_cast<int32>(index)).GetCurrentMode().GetDepth();
}

rectangle screen::bounds(size_t index) {
  application::initialize();
  wxRect bounds = wxDisplay(static_cast<int32>(index)).GetGeometry();
  return {bounds.GetX(), bounds.GetY(), bounds.GetWidth(), bounds.GetHeight()};
}

std::string screen::device_name(size_t index) {
  application::initialize();
  std::string device_name = xtd::convert_string::to_string(wxDisplay(static_cast<int32>(index)).GetName().c_str().AsWChar());
  return device_name.empty() ? ustring::format("\\\\.\\DISPLAY{}", index + 1) : device_name;
}

int32 screen::pixels_per_inch(size_t index) {
  application::initialize();
  return wxDisplay(static_cast<int32>(index)).GetPPI().GetHeight();
}

bool screen::primary(size_t index) {
  application::initialize();
  return wxDisplay(static_cast<int32>(index)).IsPrimary();
}

double screen::scale_factor(size_t index) {
  application::initialize();
  return wxDisplay(static_cast<int32>(index)).GetScaleFactor();
}

int32 screen::standard_pixels_per_inch() {
  application::initialize();
  return wxDisplay::GetStdPPIValue();
}

rectangle screen::working_area(size_t index) {
  application::initialize();
  wxRect working_area = wxDisplay(static_cast<int32>(index)).GetClientArea();
  return {working_area.GetX(), working_area.GetY(), working_area.GetWidth(), working_area.GetHeight()};
}

size_t screen::from_handle(intptr handle) {
  application::initialize();
  return wxDisplay::GetFromWindow(reinterpret_cast<control_handler*>(handle)->control());
}

size_t screen::from_point(const point& point) {
  application::initialize();
  return wxDisplay::GetFromPoint(wxPoint(point.x(), point.y()));
}
