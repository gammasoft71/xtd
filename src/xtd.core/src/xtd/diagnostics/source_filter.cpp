#include "../../../include/xtd/diagnostics/source_filter.h"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

source_filter::source_filter(const ustring& source) : source_(source) {
}

const ustring& source_filter::source() const noexcept {
  return source_;
}

void source_filter::source(const ustring& source) noexcept {
  source_ = source;
}

bool source_filter::should_trace(const trace_event_cache& cache, const ustring& source, trace_event_type event_type, int32 id, const ustring& message, std::any data1, const list<xtd::any_object>& data_array) noexcept {
  return source == source_;
}
