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
        if (!this->str().empty()) {
          xtd::diagnostics::debug::write_line(strings::trim_end(this->str(), '\n'));
          this->str("");
        }
#endif
        return 0;
      }
    };
  }
}
