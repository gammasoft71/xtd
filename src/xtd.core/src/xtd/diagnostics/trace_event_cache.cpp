#include "../../../include/xtd/diagnostics/trace_event_cache.hpp"
#include "../../../include/xtd/diagnostics/stack_trace.hpp"
#include "../../../include/xtd/diagnostics/stopwatch.hpp"
#include "../../../include/xtd/threading/thread.hpp"

using namespace xtd;
using namespace xtd::diagnostics;

auto trace_event_cache::call_stack() const noexcept -> string {
  return stack_trace(true).to_string();
}

auto trace_event_cache::date_time() const noexcept -> const class date_time& {
  if (date_time_ == date_time::min_value)
    date_time_ = date_time::utc_now();
  return date_time_;
}

auto trace_event_cache::logical_operation_stack() const noexcept -> array<string> {
  return array<string>();
}

auto trace_event_cache::process_id() const noexcept -> int32 {
  return -1;
}

auto trace_event_cache::thread_id() const noexcept -> string {
  return string::format("{}", threading::thread::current_thread().managed_thread_id());
}

auto trace_event_cache::timestamp() const noexcept -> std::chrono::nanoseconds {
  return stopwatch::get_timestamp();
}

auto trace_event_cache::timestamp_milliseconds() const noexcept -> int64 {
  return stopwatch::get_timestamp_milliseconds();
}

auto trace_event_cache::timestamp_nanoseconds() const noexcept -> int64 {
  return stopwatch::get_timestamp_nanoseconds();
}

auto trace_event_cache::timestamp_ticks() const noexcept -> int64 {
  return stopwatch::get_timestamp_ticks();
}
