#include "../../../include/xtd/diagnostics/boolean_switch.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::helpers;

boolean_switch::boolean_switch(const string& display_name, const string& description) : switch_object(display_name, description) {
  value(value());
}

boolean_switch::boolean_switch(const string& display_name, const string& description, const string& default_switch_value) : switch_object(display_name, description) {
  value(default_switch_value);
}

bool boolean_switch::enabled() const {
  return switch_setting();
}

void boolean_switch::enabled(bool enabled) {
  if (self_.enabled() == enabled) return;
  value(as<string>(enabled));
}

void boolean_switch::on_value_changed() {
  auto bool_value = false;
  if (string::try_parse(value(), bool_value)) switch_setting(as<int32>(bool_value));
  else switch_object::on_value_changed();
}
