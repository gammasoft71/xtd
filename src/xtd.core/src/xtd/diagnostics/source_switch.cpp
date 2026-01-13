#include "../../../include/xtd/diagnostics/source_switch.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

source_switch::source_switch(const string& name) : switch_object(name, string::empty_string) {
  value(value());
}

source_switch::source_switch(const string& display_name, const string& default_switch_value) : switch_object(display_name, string::empty_string) {
  value(default_switch_value);
}

auto source_switch::level() const noexcept -> source_levels {
  return as<source_levels>(switch_setting());
}

auto source_switch::level(xtd::diagnostics::source_levels level) -> void {
  if (self_.level() == level) return;
  value(enum_object<>::to_string(level));
}

auto source_switch::should_trace(trace_event_type event_type) noexcept -> bool {
  return (switch_setting() & static_cast<int32>(event_type)) != 0;
}

auto source_switch::on_value_changed() -> void {
  auto level_value = source_levels {};
  if (string::try_parse(value(), level_value)) switch_setting(as<int32>(level_value));
  else switch_object::on_value_changed();
}
