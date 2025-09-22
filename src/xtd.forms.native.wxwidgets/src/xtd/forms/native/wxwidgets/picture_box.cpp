#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_picture_box.hpp"
#include <xtd/forms/native/picture_box>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/argument_exception>

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::drawing;
using namespace xtd::forms::native;
using namespace xtd::helpers;

void picture_box::image(intptr control, const drawing::image& image) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().chars().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  wxSize current_size = reinterpret_cast<control_handler*>(control)->control()->GetSize();
  static_cast<wxStaticBitmapBase*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmap(wxBitmap(*reinterpret_cast<wxImage*>(image.handle())));
  if (reinterpret_cast<wx_picture_box*>(control)->auto_size) {
    if (current_size.GetWidth() < reinterpret_cast<control_handler*>(control)->control()->GetSize().GetWidth())
      current_size.SetWidth(reinterpret_cast<control_handler*>(control)->control()->GetSize().GetWidth());
    if (current_size.GetHeight() < reinterpret_cast<control_handler*>(control)->control()->GetSize().GetHeight())
      current_size.SetHeight(reinterpret_cast<control_handler*>(control)->control()->GetSize().GetHeight());
  }
  reinterpret_cast<control_handler*>(control)->control()->SetSize(current_size);
}

void picture_box::reset(intptr control) {
  if (!control || !wxTheApp) throw_helper::throws(exception_case::argument);
  if (!reinterpret_cast<control_handler*>(control)->control()) {
    wxASSERT_MSG_AT(reinterpret_cast<control_handler*>(control)->control() == 0, "Control is null", stack_frame().current().get_file_name().chars().c_str(), stack_frame().current().get_file_line_number(), stack_frame().current().get_method().chars().c_str());
    return;
  }
  static_cast<wxStaticBitmapBase*>(reinterpret_cast<control_handler*>(control)->control())->SetBitmap(wxNullBitmap);
}
