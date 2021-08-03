#include <stdexcept>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/text_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_text_box.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

size_t text_box::selection_length(intptr_t control) {
  long from = 0, to = 0;
  if (control == 0) return 0;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection(&from, &to);
  return static_cast<size_t>(to - from);
}

size_t text_box::selection_start(intptr_t control) {
  long from = 0, to = 0;
  if (control == 0) return 0;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection(&from, &to);
  return static_cast<size_t>(from);
}

void text_box::append(intptr_t control, const std::string& text) {
  if (control == 0) return;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->AppendText(wxString(convert_string::to_wstring(text)));
}

void text_box::select(intptr_t control, size_t start, size_t length) {
  if (control == 0) return;
  return static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(start, start + length);
}
std::string text_box::text(intptr_t control) {
  if (control == 0) return {};
  return xtd::convert_string::to_string(static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue().ToStdWstring());
}

void text_box::text(intptr_t control, const std::string& text) {
  if (control == 0) return;
  switch (reinterpret_cast<wx_text_box*>(control)->character_casing_) {
    case wx_text_box::character_casing::normal: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(wxString(convert_string::to_wstring(text))); break;
    case wx_text_box::character_casing::upper: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(convert_string::to_wstring(xtd::strings::to_upper(text))); break;
    case wx_text_box::character_casing::lower: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue(convert_string::to_wstring(xtd::strings::to_lower(text))); break;
  }
}
