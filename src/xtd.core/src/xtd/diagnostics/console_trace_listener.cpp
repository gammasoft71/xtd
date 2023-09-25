#include "../../../include/xtd/diagnostics/console_trace_listener"
#include "../../../include/xtd/io/file"

using namespace std;
using namespace xtd::diagnostics;

console_trace_listener::console_trace_listener() : console_trace_listener(false) {
  name("console");
}

console_trace_listener::console_trace_listener::console_trace_listener(bool use_error_stream) : ostream_trace_listener(use_error_stream ? std::cerr : std::cout) {
  name("console");
}
