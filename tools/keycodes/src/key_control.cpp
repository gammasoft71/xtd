#include "key_control.h"
#include <xtd/forms/application>

using namespace xtd;
using namespace xtd::drawing;
using namespace xtd::forms;
using namespace keycodes;

key_control::key_control() {
  height(120);
  
  key_event_.auto_size(true);
  key_event_.location({10, 10});
  key_event_.parent(*this);
  
  key_code_label_.auto_size(true);
  key_code_label_.fore_color(application::style_sheet().system_colors().gray_text());
  key_code_label_.location({30, 30});
  key_code_label_.parent(*this);
  key_code_label_.text("Key code"_t);
  
  key_code_.auto_size(true);
  key_code_.location({110, 30});
  key_code_.parent(*this);
  
  key_data_label_.auto_size(true);
  key_data_label_.fore_color(application::style_sheet().system_colors().gray_text());
  key_data_label_.location({30, 50});
  key_data_label_.parent(*this);
  key_data_label_.text("Key data"_t);
  
  key_data_.auto_size(true);
  key_data_.location({110, 50});
  key_data_.parent(*this);
  
  key_value_label_.auto_size(true);
  key_value_label_.fore_color(application::style_sheet().system_colors().gray_text());
  key_value_label_.location({30, 70});
  key_value_label_.parent(*this);
  key_value_label_.text("Value"_t);
  
  key_value_.auto_size(true);
  key_value_.location({110, 70});
  key_value_.parent(*this);
  
  key_modfiers_label_.auto_size(true);
  key_modfiers_label_.fore_color(application::style_sheet().system_colors().gray_text());
  key_modfiers_label_.parent(*this);
  key_modfiers_label_.location({30, 90});
  key_modfiers_label_.text("Modifiers"_t);
  
  key_modfiers_.auto_size(true);
  key_modfiers_.location({110, 90});
  key_modfiers_.parent(*this);
  
  line_.dock(dock_style::top);
  line_.back_color(application::style_sheet().system_colors().gray_text());
  line_.height(2);
  line_.parent(*this);
  line_.visible(false);
}

key_control& key_control::key_event(const ustring& value) {
  key_event_.text(value);
  return *this;
}

key_control& key_control::key_code(const xtd::ustring& value) {
  key_code_.text(value);
  return *this;
}

key_control& key_control::key_data(const xtd::ustring& value) {
  key_data_.text(value);
  return *this;
}

key_control& key_control::key_value(const xtd::ustring& value) {
  key_value_.text(value);
  return *this;
}

key_control& key_control::key_modfiers(const xtd::ustring& value) {
  key_modfiers_.text(value);
  return *this;
}

key_control& key_control::line_visible(bool value) {
  line_.visible(value);
  return *this;
}
