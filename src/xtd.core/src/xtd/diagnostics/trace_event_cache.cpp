#include "../../../include/xtd/diagnostics/trace_event_cache.h"
#include "../../../include/xtd/diagnostics/stack_trace.h"
#include "../../../include/xtd/diagnostics/stopwatch.h"

using namespace xtd;
using namespace xtd::diagnostics;

ustring trace_event_cache::call_stack() const {
  return stack_trace(true).to_string();
}

const date_time& trace_event_cache::date_time() const {
  if (date_time_ == date_time::min_value)
    date_time_ = date_time::now();
  return date_time_;
}

std::vector<ustring> trace_event_cache::logical_operation_stack() const {
  return std::vector<ustring>();
}

int32_t trace_event_cache::process_id() const {
  return -1;
}

ustring trace_event_cache::thread_id() const {
  return ustring::format("{}", std::this_thread::get_id());
}

int64_t trace_event_cache::timestamp() const {
  return stopwatch::get_timestamp();
}
