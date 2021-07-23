#include "../../../include/xtd/diagnostics/trace_event_cache.h"
#include "../../../include/xtd/diagnostics/stack_trace.h"

using namespace xtd;
using namespace xtd::diagnostics;

std::string trace_event_cache::call_stack() const {
  return stack_trace(true).to_string();
}

trace_event_cache::clock::time_point trace_event_cache::date_time() const {
  if (date_time_ == clock::time_point::min())
    date_time_ = clock::now();
  return date_time_;
}

std::vector<std::string> trace_event_cache::logical_operation_stack() const {
  return std::vector<std::string>();
}

int trace_event_cache::process_id() const {
  return -1;
}

std::string trace_event_cache::thread_id() const {
  return xtd::strings::format("{}", std::this_thread::get_id());
}

long long trace_event_cache::timestamp() const {
  return  0; //stopwatch::get_timestamp();
}
