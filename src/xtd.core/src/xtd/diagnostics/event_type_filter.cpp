#include "../../../include/xtd/diagnostics/event_type_filter.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;

event_type_filter::event_type_filter(source_levels level) : level_(level) {
}

source_levels event_type_filter::event_type() const noexcept {
  return level_;
}

void event_type_filter::event_type(source_levels level) noexcept {
  level_ = level;
}

bool event_type_filter::should_trace(const trace_event_cache& cache, const string& source, trace_event_type event_type, int32 id, const string& message, std::any data1, const list<xtd::any_object>& data_array) noexcept {
  return (static_cast<int32>(event_type) & static_cast<int32>(level_)) != 0;
}
