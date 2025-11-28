#include "../../../include/xtd/diagnostics/trace_listener.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

trace_listener::~trace_listener() {
  close();
}

trace_listener::trace_listener(const string& name) : name_{name} {
}

uint32 trace_listener::indent_level() const noexcept {
  return indent_level_;
}

void trace_listener::indent_level(uint32 indent_level) noexcept {
  indent_level_ = indent_level;
}

uint32 trace_listener::indent_size() const noexcept {
  return indent_size_;
}

void trace_listener::indent_size(uint32 indent_size) noexcept {
  indent_size_ = indent_size;
}

bool trace_listener::is_thread_safe() const noexcept {
  return is_thread_safe_;
}

const string& trace_listener::name() const noexcept {
  return name_;
}

void trace_listener::name(const string& name) noexcept {
  name_ = name;
}

trace_options trace_listener::trace_output_options() const noexcept {
  return trace_output_options_;
}

void trace_listener::trace_output_options(trace_options trace_output_options) noexcept {
  trace_output_options_ = trace_output_options;
}

void trace_listener::close() {
  flush();
}

bool trace_listener::need_indent() const noexcept {
  return need_indent_;
}

void trace_listener::need_indent(bool need_indent) noexcept {
  need_indent_ = need_indent;
}

void trace_listener::thread_safe(bool thread_safe) noexcept {
  is_thread_safe_ = thread_safe;
}

void trace_listener::write_event_cache(const trace_event_cache& event_cache) {
  if (((int32)trace_output_options_ & (int32)xtd::diagnostics::trace_options::process_id) == (int32)xtd::diagnostics::trace_options::process_id)
    write_line(string::format("{0}process_id={1}", string(' ', indent_size_), event_cache.process_id()));
  if (((int32)trace_output_options_ & (int32)xtd::diagnostics::trace_options::logical_operation_stack) == (int32)xtd::diagnostics::trace_options::logical_operation_stack)
    write_line(string::format("{0}logical_operation_stack={1}", string(' ', indent_size_), string::join(", ", event_cache.logical_operation_stack())));
  if (((int32)trace_output_options_ & (int32)xtd::diagnostics::trace_options::thread_id) == (int32)xtd::diagnostics::trace_options::thread_id)
    write_line(string::format("{0}thread_id={1}", string(' ', indent_size_), event_cache.thread_id()));
  if (((int32)trace_output_options_ & (int32)xtd::diagnostics::trace_options::date_time) == (int32)xtd::diagnostics::trace_options::date_time)
    write_line(string::format("{0}date_time={1:s}", string(' ', indent_size_), event_cache.date_time()));
  if (((int32)trace_output_options_ & (int32)xtd::diagnostics::trace_options::timestamp) == (int32)xtd::diagnostics::trace_options::timestamp)
    write_line(string::format("{0}timestamp={1}", string(' ', indent_size_), event_cache.timestamp()));
  if (((int32)trace_output_options_ & (int32)xtd::diagnostics::trace_options::callstack) == (int32)xtd::diagnostics::trace_options::callstack)
    write_line(string::format("{0}callstack={1}", string(' ', indent_size_), event_cache.call_stack()));
}
