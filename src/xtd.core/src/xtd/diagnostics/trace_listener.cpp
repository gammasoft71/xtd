#include "../../../include/xtd/diagnostics/trace_listener.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

trace_listener::~trace_listener() {
  close();
}

trace_listener::trace_listener(const string& name) : name_{name} {
}

auto trace_listener::indent_level() const noexcept -> uint32 {
  return indent_level_;
}

auto trace_listener::indent_level(uint32 indent_level) noexcept -> void {
  indent_level_ = indent_level;
}

auto trace_listener::indent_size() const noexcept -> uint32 {
  return indent_size_;
}

auto trace_listener::indent_size(uint32 indent_size) noexcept -> void {
  indent_size_ = indent_size;
}

auto trace_listener::is_thread_safe() const noexcept -> bool {
  return is_thread_safe_;
}

auto trace_listener::name() const noexcept -> const string& {
  return name_;
}

auto trace_listener::name(const string& name) noexcept -> void {
  name_ = name;
}

auto trace_listener::trace_output_options() const noexcept -> trace_options {
  return trace_output_options_;
}

auto trace_listener::trace_output_options(trace_options trace_output_options) noexcept -> void {
  trace_output_options_ = trace_output_options;
}

auto trace_listener::close() -> void {
  flush();
}

auto trace_listener::need_indent() const noexcept -> bool {
  return need_indent_;
}

auto trace_listener::need_indent(bool need_indent) noexcept -> void {
  need_indent_ = need_indent;
}

auto trace_listener::thread_safe(bool thread_safe) noexcept -> void {
  is_thread_safe_ = thread_safe;
}

auto trace_listener::write_event_cache(const trace_event_cache& event_cache) -> void {
  if (enum_object {trace_output_options_}.has_flag(trace_options::process_id))
    write_line(string::format("{0}process_id={1}", string(' ', indent_size_), event_cache.process_id()));
  if (enum_object {trace_output_options_}.has_flag(trace_options::logical_operation_stack))
    write_line(string::format("{0}logical_operation_stack={1}", string(' ', indent_size_), string::join(", ", event_cache.logical_operation_stack())));
  if (enum_object {trace_output_options_}.has_flag(trace_options::thread_id))
    write_line(string::format("{0}thread_id={1}", string(' ', indent_size_), event_cache.thread_id()));
  if (enum_object {trace_output_options_}.has_flag(trace_options::date_time))
    write_line(string::format("{0}date_time={1:s}", string(' ', indent_size_), event_cache.date_time()));
  if (enum_object {trace_output_options_}.has_flag(trace_options::timestamp))
    write_line(string::format("{0}timestamp={1}", string(' ', indent_size_), event_cache.timestamp()));
  if (enum_object {trace_output_options_}.has_flag(trace_options::callstack))
    write_line(string::format("{0}callstack={1}", string(' ', indent_size_), event_cache.call_stack()));
}
