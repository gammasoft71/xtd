#include <stdexcept>
#include <xtd/drawing/system_colors.hpp>
#include <xtd/forms/native/application.hpp>
#include <xtd/forms/native/text_box.hpp>
#include "fl_text_box.hpp"

using namespace std;
using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms::native;

ustring text_box::text(intptr_t control) {
  if (control == 0) return {};
  return static_cast<Fl_Input*>(reinterpret_cast<control_handler*>(control)->control())->value();
}

void text_box::text(intptr_t control, const ustring& text) {
  if (control == 0) return;
  static_cast<Fl_Input*>(reinterpret_cast<control_handler*>(control)->control())->value(text.c_str());
}
