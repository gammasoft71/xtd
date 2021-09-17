#include "../../../include/xtd/diagnostics/source_filter.h"
#include <call_stack.h>

using namespace std;
using namespace xtd;
using namespace xtd::diagnostics;

source_filter::source_filter(const ustring& source) : source_(source) {
}

const ustring& source_filter::source() const {
  return source_;
}

void source_filter::source(const ustring& source) {
  source_ = source;
}

bool source_filter::should_trace(const trace_event_cache& cache, const ustring& source, trace_event_type event_type, int32_t id, const ustring& message, any data1, const vector<any>& data_array) {
  return source == source_;
}
