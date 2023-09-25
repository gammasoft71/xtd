#include "../../../include/xtd/diagnostics/event_type_filter"

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

event_type_filter::event_type_filter(source_levels level) : level_(level) {
}

source_levels event_type_filter::event_type() const noexcept {
  return level_;
}

void event_type_filter::event_type(source_levels level) noexcept {
  level_ = level;
}

bool event_type_filter::should_trace(const trace_event_cache& cache, const ustring& source, trace_event_type event_type, int32 id, const ustring& message, any data1, const vector<any>& data_array) noexcept {
  return (static_cast<int32>(event_type) & static_cast<int32>(level_)) != 0;
}
