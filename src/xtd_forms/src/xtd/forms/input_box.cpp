#include <xtd/forms/native/input_box.h>
#include "../../../include/xtd/forms/input_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

void input_box::reset() {
  caption_ = "";
  multiline_ = false;
  text_ = "";
  use_system_password_char_ = false;
  value_ = "";
}

bool input_box::run_dialog(intptr_t owner) {
  return native::input_box::run_dialog(owner, text_, caption_, value_, multiline_, use_system_password_char_);
}
