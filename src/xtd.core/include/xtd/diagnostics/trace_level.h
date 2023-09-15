/// @file
/// @brief Contains xtd::diagnostics::trace_level enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specifies what messages to output for the debug, trace and trace_switch classes.
    /// @code
    /// enum class trace_level
    /// @endcode
    /// @par Header
    /// @code #include <xtd/diagnostics/trace_level> @endcode
    /// @par Namespace
    /// xtd::diagnostics
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::diagnostics::trace_level> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::diagnostics::trace_level> {{xtd::diagnostics::trace_level::off, "off"}, {xtd::diagnostics::trace_level::error, "error"}, {xtd::diagnostics::trace_level::warning, "warning"}, {xtd::diagnostics::trace_level::info, "info"}, {xtd::diagnostics::trace_level::verbose, "verbose"}};}
};
/// @endcond
