#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debugger.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/io/file.h>

using namespace std;
using namespace xtd::diagnostics;

default_trace_listener::default_trace_listener() : trace_listener("default") {
}

default_trace_listener::~default_trace_listener() {
  flush();
}

bool default_trace_listener::assert_ui_enabled() {
  return assert_ui_enabled_;
}

void default_trace_listener::assert_ui_enabled(bool assert_ui_enabled) {
  assert_ui_enabled_ = assert_ui_enabled;
}

std::string default_trace_listener::log_file_name() const {
  return log_file_name_;
}

void default_trace_listener::log_file_name(const std::string log_file_name) {
  log_file_name_ = log_file_name;
}

void default_trace_listener::close() {
}

void default_trace_listener::flush() {
  if (!message_line_.empty()) write_line("");
}

void default_trace_listener::write(const std::string& message) {
  if (need_indent()) write_indent();
  message_line_ += message;
  if (!log_file_name_.empty()) xtd::io::file::append_all_text(log_file_name_, message);
}

void default_trace_listener::write_line(const std::string& message) {
  write(message + "\n");
  native::debugger::log(0, "", message_line_);
  message_line_ = "";
  need_indent(true);
}
