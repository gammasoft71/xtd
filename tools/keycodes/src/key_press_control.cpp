#include "key_press_control.h"
#include <xtd/forms/application>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace keycodes;

key_press_control::key_press_control() {
  height(60);
  
  key_event_label_.auto_size(true);
  key_event_label_.location({10, 10});
  key_event_label_.parent(*this);
  key_event_label_.text("Key press"_t);
  
  key_char_label_.auto_size(true);
  key_char_label_.fore_color(application::style_sheet().system_colors().gray_text());
  key_char_label_.location({30, 30});
  key_char_label_.parent(*this);
  key_char_label_.text("Key char"_t);
  
  key_char_.auto_size(true);
  key_char_.location({110, 30});
  key_char_.parent(*this);
}

key_press_control& key_press_control::key_char(const xtd::ustring& value) {
  key_char_.text(value);
  return *this;
}
