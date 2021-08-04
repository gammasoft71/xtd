/// @file
/// @brief Contains xtd::diagnostics::trace_level enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specifies what messages to output for the debug, trace and trace_switch classes.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    enum class trace_level {
      /// @brief Output no tracing and debugging messages.
      off = 0,
      /// @brief Output error-handling messages.
      error = 1,
      /// @brief Output warnings and error-handling messages.
      warning = 2,
      /// @brief Output informational messages, warnings, and error-handling messages.
      info = 3,
      /// @brief Output all debugging and tracing messages.
      verbose = 4,
    };

    inline std::ostream& operator<<(std::ostream& os, xtd::diagnostics::trace_level value) {return os << to_string(value, {{diagnostics::trace_level::off, "off"}, {diagnostics::trace_level::error, "error"}, {diagnostics::trace_level::warning, "warning"}, {diagnostics::trace_level::info, "info"}, {diagnostics::trace_level::verbose, "verbose"}});}
    inline std::wostream& operator<<(std::wostream& os, xtd::diagnostics::trace_level value) {return os << to_string(value, {{diagnostics::trace_level::off, L"off"}, {diagnostics::trace_level::error, L"error"}, {diagnostics::trace_level::warning, L"warning"}, {diagnostics::trace_level::info, L"info"}, {diagnostics::trace_level::verbose, L"verbose"}});}
  }
}
