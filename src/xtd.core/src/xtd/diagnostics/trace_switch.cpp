#include "../../../include/xtd/diagnostics/trace_switch.h"

using namespace xtd;
using namespace xtd::diagnostics;

trace_switch::trace_switch(const std::string& display_name, const std::string& description) : switch_base(display_name, description) {
}

trace_switch::trace_switch(const std::string& display_name, const std::string& description, const std::string& default_switch_value) : switch_base(display_name, description, default_switch_value) {
}

xtd::diagnostics::trace_level trace_switch::level() const {
  return static_cast<xtd::diagnostics::trace_level>(switch_setting());
}

void trace_switch::level(xtd::diagnostics::trace_level level) {
  switch_setting(static_cast<int32_t>(level));
}

bool trace_switch::trace_switch::trace_error() const {
  return static_cast<int32_t>(level()) >= static_cast<int32_t>(xtd::diagnostics::trace_level::error);
}

bool trace_switch::trace_info() const {
  return static_cast<int32_t>(level()) >= static_cast<int32_t>(xtd::diagnostics::trace_level::info);
}

bool trace_switch::trace_verbose() const {
  return static_cast<int32_t>(level()) == static_cast<int32_t>(xtd::diagnostics::trace_level::verbose);
}

bool trace_switch::trace_warning() const {
  return static_cast<int32_t>(level()) >= static_cast<int32_t>(xtd::diagnostics::trace_level::warning);
}

void trace_switch::on_switch_setting_changed() {
  switch_base::on_switch_setting_changed();
  int32_t level = switch_setting();
  if (level < static_cast<int32_t>(xtd::diagnostics::trace_level::off)) {
    //xtd::diagnostics::debug::write_line<std::string>(std::string("trace_switch level too low"), display_name());
    switch_setting(static_cast<int32_t>(xtd::diagnostics::trace_level::off));
  } else if (level > static_cast<int32_t>(xtd::diagnostics::trace_level::verbose)) {
    //xtd::diagnostics::debug::write_line<std::string>(std::string("trace_switch level too high"), display_name());
    switch_setting(static_cast<int32_t>(xtd::diagnostics::trace_level::verbose));
  }
}

void trace_switch::on_value_changed() {
  switch_base::on_value_changed();
  switch_setting(static_cast<int32_t>(xtd::parse<xtd::diagnostics::trace_level>(value())));
}
