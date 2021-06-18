#include "../../../include/xtd/diagnostics/source_filter.h"
#include <call_stack.h>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

source_filter::source_filter(const string& source) : source_(source) {
}

const string& source_filter::source() const {
  return source_;
}

void source_filter::source(const string& source) {
  source_ = source;
}

bool source_filter::should_trace(const trace_event_cache& cache, const string& source, trace_event_type event_type, int32_t id, const string& message, any data1, const vector<any>& data_array) {
  return source == source_;
}
