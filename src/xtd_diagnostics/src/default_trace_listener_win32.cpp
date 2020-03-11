#include "../include/xtd/diagnostics/default_trace_listener.h"

#if defined(_WIN32)
#include <windows.h>

void xtd::diagnostics::default_trace_listener::write_to_output_debug(const std::string& message) {
  OutputDebugStringA(message.c_str());
}

#endif
