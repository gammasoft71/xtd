/// @file
/// @brief Contains xtd::cdebug object.
#pragma once
#include <iostream>
#include "debug.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    class debugstreambuf : public std::stringbuf {
    public:
      int sync() override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
        if (!str().empty()) {
          if (str() == "\n") xtd::diagnostics::debug::write_line();
          else if (strings::ends_with(str(), '\n')) xtd::diagnostics::debug::write_line(strings::trim_end(str(), '\n'));
          else xtd::diagnostics::debug::write(str());
          str("");
        }
#endif
        return 0;
      }
    };
  }
}
