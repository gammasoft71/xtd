#include "../../../include/xtd/diagnostics/event_type_filter.h"

using namespace std;
using namespace xtd::diagnostics;

event_type_filter::event_type_filter(source_levels level) : level_(level) {
}

source_levels event_type_filter::event_type() const {
  return level_;
}

void event_type_filter::event_type(source_levels level) {
  level_ = level;
}

bool event_type_filter::should_trace(const trace_event_cache& cache, const string& source, trace_event_type event_type, int32_t id, const string& message, any data1, const vector<any>& data_array) {
  return (static_cast<int>(event_type) & static_cast<int>(level_)) != 0;
}
