#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_color_picker.hpp"
#include <xtd/forms/native/color_picker>
#include <xtd/forms/native/content_alignment>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;

color color_picker::color(intptr control) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return {};
  }
  wxColour colour = static_cast<wxColourPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetColour();
  return color::from_argb(colour.Alpha(), colour.Red(), colour.Green(), colour.Blue());
}

void color_picker::color(intptr control, const drawing::color& color) {
  if (!control || !wxTheApp) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().c_str());
    return;
  }
  static_cast<wxColourPickerCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetColour(wxColour(color.r(), color.g(), color.b(), color.a()));
}
