#include "../../../include/xtd/diagnostics/source_filter.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

source_filter::source_filter(const string& source) : source_(source) {
}

const string& source_filter::source() const noexcept {
  return source_;
}

void source_filter::source(const string& source) noexcept {
  source_ = source;
}

bool source_filter::should_trace(const trace_event_cache& cache, const string& source, trace_event_type event_type, int32 id, const string& message, std::any data1, const list<xtd::any_object>& data_array) noexcept {
  return source == source_;
}
