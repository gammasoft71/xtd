#include "../../../include/xtd/diagnostics/trace_switch.hpp"
#include "../../../include/xtd/as.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

trace_switch::trace_switch(const string& display_name, const string& description) : switch_object(display_name, description) {
  value(value());
}

trace_switch::trace_switch(const string& display_name, const string& description, const string& default_switch_value) : switch_object(display_name, description) {
  value(default_switch_value);
}

trace_level trace_switch::level() const noexcept {
  return as<trace_level>(switch_setting());
}

void trace_switch::level(xtd::diagnostics::trace_level level) noexcept {
  if (self_.level() == level) return;
  value(enum_object<>::to_string(level));
}

bool trace_switch::trace_switch::trace_error() const noexcept {
  return static_cast<int32>(level()) >= static_cast<int32>(xtd::diagnostics::trace_level::error);
}

bool trace_switch::trace_info() const noexcept {
  return static_cast<int32>(level()) >= static_cast<int32>(xtd::diagnostics::trace_level::info);
}

bool trace_switch::trace_verbose() const noexcept {
  return static_cast<int32>(level()) == static_cast<int32>(xtd::diagnostics::trace_level::verbose);
}

bool trace_switch::trace_warning() const noexcept {
  return static_cast<int32>(level()) >= static_cast<int32>(xtd::diagnostics::trace_level::warning);
}

void trace_switch::on_switch_setting_changed() {
  switch_object::on_switch_setting_changed();
  auto level = switch_setting();
  if (level < as<int32>(xtd::diagnostics::trace_level::off)) {
    //xtd::diagnostics::debug::write_line<string>(xtd::string("trace_switch level too low"), display_name());
    switch_setting(as<int32>(xtd::diagnostics::trace_level::off));
  } else if (level > as<int32>(xtd::diagnostics::trace_level::verbose)) {
    //xtd::diagnostics::debug::write_line<string>(xtd::string("trace_switch level too high"), display_name());
    switch_setting(as<int32>(xtd::diagnostics::trace_level::verbose));
  }
}

void trace_switch::on_value_changed() {
  auto level_value = trace_level {};
  if (string::try_parse(value(), level_value)) switch_setting(as<int32>(level_value));
  else switch_object::on_value_changed();
}
