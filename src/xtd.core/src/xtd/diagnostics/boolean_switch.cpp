#include "../../../include/xtd/diagnostics/boolean_switch"
#include "../../../include/xtd/format_exception"
#include "../../../include/xtd/as"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

boolean_switch::boolean_switch(const ustring& display_name, const ustring& description) : switch_base(display_name, description) {
}

boolean_switch::boolean_switch(const ustring& display_name, const ustring& description, const ustring& default_switch_value) : switch_base(display_name, description, default_switch_value) {
}

bool boolean_switch::enabled() const {
  if (!enabled_.has_value() && !this->value().empty() == true) {
    auto bool_value = false;
    auto int_value = 0;
    if (try_parse(this->value(), bool_value) == true)
      enabled_ = bool_value;
    else if (try_parse(this->value(), int_value) == true) enabled_ = int_value != 0;
    else throw format_exception {"Input xtd::ustring was not in a correct format."_t, csf_};
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
