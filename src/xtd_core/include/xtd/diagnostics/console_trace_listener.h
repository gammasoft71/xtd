/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <iostream>
#include "ostream_trace_listener.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    class console_trace_listener : public ostream_trace_listener {
    public:
      console_trace_listener() : console_trace_listener(false) {}
      console_trace_listener(bool use_error_stream) : ostream_trace_listener(use_error_stream ? std::cerr : std::cout) {}
      
    private:
      using ostream_trace_listener::ostream;
    };
  }
}
