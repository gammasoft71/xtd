#include "../../../include/xtd/diagnostics/source_switch.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

source_switch::source_switch(const string& name) : switch_object(name, string::empty_string) {
}

source_switch::source_switch(const string& display_name, const string& default_switch_value) : switch_object(display_name, string::empty_string, default_switch_value) {
}


source_levels source_switch::level() const noexcept {
  return static_cast<source_levels>(switch_setting());
}

void source_switch::level(xtd::diagnostics::source_levels level) {
  switch_setting(static_cast<int32>(level));
}


bool source_switch::should_trace(trace_event_type event_type) noexcept {
  return (switch_setting() & static_cast<int32>(event_type)) != 0;
}

void source_switch::on_value_changed() {
  switch_setting(static_cast<int32>(parse<source_levels>(value())));
}
