#include <stdexcept>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/application.h>
#include <xtd/forms/native/text_box.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_text_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

size_t text_box::selection_length(intptr_t control) {
  long from = 0, to = 0;
  if (control == 0) return;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection(&from, &to);
  return static_cast<size_t>(to - from);
}

size_t text_box::selection_start(intptr_t control) {
  long from = 0, to = 0;
  if (control == 0) return;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetSelection(&from, &to);
  return static_cast<size_t>(from);
}

void text_box::append(intptr_t control, const std::string& text) {
  if (control == 0) return;
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->AppendText({text.c_str(), wxMBConvUTF8()});
}

void text_box::select(intptr_t control, size_t start, size_t length) {
  if (control == 0) return;
  return static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetSelection(start, start + length);
}
std::string text_box::text(intptr_t control) {
  if (control == 0) return {};
  return static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->GetValue().utf8_str().data();
}

void text_box::text(intptr_t control, const std::string& text) {
  if (control == 0) return;
  switch (reinterpret_cast<wx_text_box*>(control)->character_casing_) {
    case wx_text_box::character_casing::normal: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue({text.c_str(), wxMBConvUTF8()}); break;
    case wx_text_box::character_casing::upper: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue({xtd::strings::to_upper(text).c_str(), wxMBConvUTF8()}); break;
    case wx_text_box::character_casing::lower: static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue({xtd::strings::to_lower(text).c_str(), wxMBConvUTF8()}); break;
  }
}
