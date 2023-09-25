#include "../../../include/xtd/diagnostics/trace_switch"

using namespace xtd;
using namespace xtd::diagnostics;

trace_switch::trace_switch(const ustring& display_name, const ustring& description) : switch_base(display_name, description) {
}

trace_switch::trace_switch(const ustring& display_name, const ustring& description, const ustring& default_switch_value) : switch_base(display_name, description, default_switch_value) {
}

xtd::diagnostics::trace_level trace_switch::level() const noexcept {
  return static_cast<xtd::diagnostics::trace_level>(switch_setting());
}

void trace_switch::level(xtd::diagnostics::trace_level level) noexcept {
  switch_setting(static_cast<int32>(level));
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
  switch_base::on_switch_setting_changed();
  auto level = switch_setting();
  if (level < static_cast<int32>(xtd::diagnostics::trace_level::off)) {
    //xtd::diagnostics::debug::write_line<ustring>(xtd::ustring("trace_switch level too low"), display_name());
    switch_setting(static_cast<int32>(xtd::diagnostics::trace_level::off));
  } else if (level > static_cast<int32>(xtd::diagnostics::trace_level::verbose)) {
    //xtd::diagnostics::debug::write_line<ustring>(xtd::ustring("trace_switch level too high"), display_name());
    switch_setting(static_cast<int32>(xtd::diagnostics::trace_level::verbose));
  }
}

void trace_switch::on_value_changed() {
  switch_base::on_value_changed();
  switch_setting(static_cast<int32>(xtd::parse<xtd::diagnostics::trace_level>(value())));
}
