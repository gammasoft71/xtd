#include "../../../include/xtd/diagnostics/default_trace_listener.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/debug.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd::diagnostics;

void default_trace_listener::write_to_output_debug(const string& message) {
  native::debug::write_to_output(message);
}
