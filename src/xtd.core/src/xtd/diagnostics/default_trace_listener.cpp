#include "../../../include/xtd/diagnostics/default_trace_listener.hpp"
#include "../../../include/xtd/io/file.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::diagnostics;

default_trace_listener::default_trace_listener() : default_trace_listener("") {
}

default_trace_listener::default_trace_listener(const xtd::string log_file_name) : trace_listener("default"), log_file_name_ {log_file_name} {
}

default_trace_listener::~default_trace_listener() {
  flush();
}

bool default_trace_listener::assert_ui_enabled() const noexcept {
  return assert_ui_enabled_;
}

void default_trace_listener::assert_ui_enabled(bool assert_ui_enabled) noexcept {
  assert_ui_enabled_ = assert_ui_enabled;
}

string default_trace_listener::log_file_name() const noexcept {
  return log_file_name_;
}

void default_trace_listener::log_file_name(const string log_file_name) noexcept {
  log_file_name_ = log_file_name;
}

void default_trace_listener::close() {
}

void default_trace_listener::flush() {
  if (!xtd::string::is_empty(message_line_)) write_line("");
}

void default_trace_listener::write(const string& message) {
  if (need_indent()) write_indent();
  message_line_ += message;
  if (!xtd::string::is_empty(log_file_name_)) xtd::io::file::append_all_text(string(log_file_name_), message);
}

void default_trace_listener::write_line(const string& message) {
  write(message + "\n");
  native::debugger::log(0, string::empty_string, message_line_);
  message_line_ = "";
  need_indent(true);
}
