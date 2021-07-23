#include "../../../include/xtd/diagnostics/trace_listener.h"

using namespace xtd;
using namespace xtd::diagnostics;

trace_listener::~trace_listener() {
  close();
}

trace_listener::trace_listener(const std::string& name) {
  name_ = name;
}

unsigned int trace_listener::indent_level() const {
  return indent_level_;
}

void trace_listener::indent_level(unsigned int indent_level) {
  indent_level_ = indent_level;
}

unsigned int trace_listener::indent_size() const {
  return indent_size_;
}

void trace_listener::indent_size(unsigned int indent_size) {
  indent_size_ = indent_size;
}

bool trace_listener::is_thread_safe() const {
  return is_thread_safe_;
}

const std::string& trace_listener::name() const {
  return name_;
}

void trace_listener::name(const std::string& name) {
  name_ = name;
}

const trace_options& trace_listener::trace_output_options() const {
  return trace_output_options_;
}

void trace_listener::trace_output_options(const trace_options& trace_output_options) {
  trace_output_options_ = trace_output_options;
}

void trace_listener::close() {
  flush();
}

bool trace_listener::need_indent() const {
  return need_indent_;
}

void trace_listener::need_indent(bool need_indent) {
  need_indent_ = need_indent;
}

void trace_listener::thread_safe(bool thread_safe) {
  is_thread_safe_ = thread_safe;
}

void trace_listener::write_event_cache(const trace_event_cache& event_cache) {
  if (((int)trace_output_options_ & (int)xtd::diagnostics::trace_options::process_id) == (int)xtd::diagnostics::trace_options::process_id)
    write_line(xtd::strings::format("{0}ProcessId={1}", std::string(indent_size_, ' '), event_cache.process_id()));
  if (((int)trace_output_options_ & (int)xtd::diagnostics::trace_options::logical_operation_stack) == (int)xtd::diagnostics::trace_options::logical_operation_stack)
    write_line(xtd::strings::format("{0}LogicalOperationStack={1}", std::string(indent_size_, ' '), xtd::strings::join(", ", event_cache.logical_operation_stack())));
  if (((int)trace_output_options_ & (int)xtd::diagnostics::trace_options::thread_id) == (int)xtd::diagnostics::trace_options::thread_id)
    write_line(xtd::strings::format("{0}ThreadId={1}", std::string(indent_size_, ' '), event_cache.thread_id()));
  if (((int)trace_output_options_ & (int)xtd::diagnostics::trace_options::date_time) == (int)xtd::diagnostics::trace_options::date_time)
    write_line(xtd::strings::format("{0}DateTime={1:D}T{1:T}", std::string(indent_size_, ' '), event_cache.date_time()));
  if (((int)trace_output_options_ & (int)xtd::diagnostics::trace_options::timestamp) == (int)xtd::diagnostics::trace_options::timestamp)
    write_line(xtd::strings::format("{0}Timestamp={1}", std::string(indent_size_, ' '), event_cache.timestamp()));
  if (((int)trace_output_options_ & (int)xtd::diagnostics::trace_options::callstack) == (int)xtd::diagnostics::trace_options::callstack)
    write_line(xtd::strings::format("{0}Callstack={1}", std::string(indent_size_, ' '), event_cache.call_stack()));
}
