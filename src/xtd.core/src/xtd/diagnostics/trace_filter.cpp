#include "../../../include/xtd/diagnostics/trace_filter.h"

using namespace xtd;
using namespace xtd::diagnostics;

bool trace_filter::should_trace(const xtd::diagnostics::trace_event_cache& cache, const std::string& source, xtd::diagnostics::trace_event_type event_type, int32_t id, const std::string& message) {
  return should_trace(cache, source, event_type, id, message, nullptr, {});
}

bool trace_filter::should_trace(const xtd::diagnostics::trace_event_cache& cache, const std::string& source, xtd::diagnostics::trace_event_type event_type, int32_t id, const std::string& message, std::any data1) {
  return should_trace(cache, source, event_type, id, message, data1, {});
}

