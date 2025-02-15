#include "../../../include/xtd/diagnostics/boolean_switch.hpp"
#include "../../../include/xtd/format_exception.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::helpers;

boolean_switch::boolean_switch(const string& display_name, const string& description) : switch_base(display_name, description) {
}

boolean_switch::boolean_switch(const string& display_name, const string& description, const string& default_switch_value) : switch_base(display_name, description, default_switch_value) {
}

bool boolean_switch::enabled() const {
  if (!enabled_.has_value() && !this->value().empty() == true) {
    auto bool_value = false;
    auto int_value = 0;
    if (string::try_parse(this->value(), bool_value) == true)
      enabled_ = bool_value;
    else if (string::try_parse(this->value(), int_value) == true) enabled_ = int_value != 0;
    else throw_helper::throws(exception_case::format, "Input xtd::string was not in a correct format."_t);
  }
  return enabled_.value();
}

void boolean_switch::enabled(bool enabled) {
  if (enabled_ == enabled) return;
  enabled_ = enabled;
  on_value_changed();
}

void boolean_switch::on_value_changed() {
  switch_base::on_value_changed();
  switch_setting(as<int32>(enabled_.value()));
}
