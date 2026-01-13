#include "../../../include/xtd/diagnostics/source_filter.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

source_filter::source_filter(const string& source) : source_(source) {
}

auto source_filter::source() const noexcept -> const string& {
  return source_;
}

auto source_filter::source(const string& source) noexcept -> void {
  source_ = source;
}

auto source_filter::should_trace(const trace_event_cache& cache, const string& source, trace_event_type event_type, int32 id, const string& message, any_object data1, const list<any_object>& data_array) noexcept -> bool {
  return source == source_;
}
