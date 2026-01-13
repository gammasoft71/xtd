#include "../../../include/xtd/diagnostics/default_trace_listener.hpp"
#include "../../../include/xtd/io/file.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::diagnostics;

default_trace_listener::default_trace_listener() : default_trace_listener("") {
}

default_trace_listener::default_trace_listener(const string log_file_name) : trace_listener("default"), log_file_name_ {log_file_name} {
}

default_trace_listener::~default_trace_listener() {
  flush();
}

auto default_trace_listener::assert_ui_enabled() const noexcept -> bool {
  return assert_ui_enabled_;
}

auto default_trace_listener::assert_ui_enabled(bool assert_ui_enabled) noexcept -> void {
  assert_ui_enabled_ = assert_ui_enabled;
}

auto default_trace_listener::log_file_name() const noexcept -> string {
  return log_file_name_;
}

auto default_trace_listener::log_file_name(const string log_file_name) noexcept -> void {
  log_file_name_ = log_file_name;
}

auto default_trace_listener::close() -> void {
}

auto default_trace_listener::flush() -> void {
  if (!xtd::string::is_empty(message_line_)) write_line("");
}

auto default_trace_listener::write(const string& message) -> void {
  if (need_indent()) write_indent();
  message_line_ += message;
  if (!xtd::string::is_empty(log_file_name_)) xtd::io::file::append_all_text(string(log_file_name_), message);
}

auto default_trace_listener::write_line(const string& message) -> void {
  write(message + "\n");
  native::debugger::log(0, string::empty_string, message_line_);
  message_line_ = "";
  need_indent(true);
}
