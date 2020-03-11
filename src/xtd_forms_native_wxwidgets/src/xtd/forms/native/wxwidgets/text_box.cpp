#include <stdexcept>
#include <xtd/drawing/system_colors.h>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/text_box.hpp>
#include "../../../../../include/xtd/forms/native/wxwidgets/wx_text_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

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
  static_cast<wxTextCtrl*>(reinterpret_cast<control_handler*>(control)->control())->SetValue({text.c_str(), wxMBConvUTF8()});
}
