#include "../../../include/xtd/diagnostics/trace_filter.h"

using namespace xtd;
using namespace xtd::diagnostics;

bool trace_filter::should_trace(const xtd::diagnostics::trace_event_cache& cache, const string& source, trace_event_type event_type, int32 id, const string& message) noexcept {
  return should_trace(cache, source, event_type, id, message, nullptr, {});
}

bool trace_filter::should_trace(const xtd::diagnostics::trace_event_cache& cache, const string& source, trace_event_type event_type, int32 id, const string& message, std::any data1) noexcept {
  return should_trace(cache, source, event_type, id, message, data1, {});
}

