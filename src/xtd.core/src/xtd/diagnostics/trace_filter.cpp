#include "../../../include/xtd/diagnostics/trace_filter.h"

using namespace xtd;
using namespace xtd::diagnostics;

bool trace_filter::should_trace(const xtd::diagnostics::trace_event_cache& cache, const ustring& source, trace_event_type event_type, int32_t id, const ustring& message) {
  return should_trace(cache, source, event_type, id, message, nullptr, {});
}

bool trace_filter::should_trace(const xtd::diagnostics::trace_event_cache& cache, const ustring& source, trace_event_type event_type, int32_t id, const ustring& message, std::any data1) {
  return should_trace(cache, source, event_type, id, message, data1, {});
}

