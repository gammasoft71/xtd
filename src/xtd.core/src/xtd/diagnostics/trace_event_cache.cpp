#include "../../../include/xtd/diagnostics/trace_event_cache.h"
#include "../../../include/xtd/diagnostics/stack_trace.h"
#include "../../../include/xtd/diagnostics/stopwatch.h"
#include "../../../include/xtd/threading/thread.h"

using namespace xtd;
using namespace xtd::diagnostics;

ustring trace_event_cache::call_stack() const noexcept {
  return stack_trace(true).to_string();
}

const date_time& trace_event_cache::date_time() const noexcept {
  if (date_time_ == date_time::min_value)
    date_time_ = date_time::now();
  return date_time_;
}

std::vector<ustring> trace_event_cache::logical_operation_stack() const noexcept {
  return std::vector<ustring>();
}

int32 trace_event_cache::process_id() const noexcept {
  return -1;
}

ustring trace_event_cache::thread_id() const noexcept {
  return ustring::format("{}", threading::thread::current_thread().managed_thread_id());
}

std::chrono::nanoseconds trace_event_cache::timestamp() const noexcept {
  return stopwatch::get_timestamp();
}

int64 trace_event_cache::timestamp_milliseconds() const noexcept {
  return stopwatch::get_timestamp_milliseconds();
}

int64 trace_event_cache::timestamp_nanoseconds() const noexcept {
  return stopwatch::get_timestamp_nanoseconds();
}

int64 trace_event_cache::timestamp_ticks() const noexcept {
  return stopwatch::get_timestamp_ticks();
}
