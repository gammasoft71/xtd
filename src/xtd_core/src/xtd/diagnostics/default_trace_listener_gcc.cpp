#include "../include/xtd/diagnostics/default_trace_listener.h"

#if defined(__linux__) || defined(__APPLE__)

#include <iostream>
#include <syslog.h>

void xtd::diagnostics::default_trace_listener::write_to_output_debug(const std::string& message) {
  syslog(LOG_EMERG | LOG_USER, "%s", message.c_str());
#if !defined(__APPLE__)
  std::cerr << message << std::flush;
#endif
}

#endif
