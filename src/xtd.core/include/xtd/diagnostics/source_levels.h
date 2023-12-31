/// @file
/// @brief Contains xtd::diagnostics::source_levels enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specifies the levels of trace messages filtered by the source switch and event type filter. This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @code
    /// enum class source_levels
    /// @endcode
    /// @par Header
    /// @code #include <xtd/diagnostics/source_levels> @endcode
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks The source levels identify the trace_event_type events that are to be traced. The source_switch class uses the source_levels enumeration to define the event level of the trace message to use for filtering messages to send to the trace listener.
    enum class source_levels {
      /// @brief Does not allow any events through.
      off = 0,
      /// @brief Allows only Critical events through.
      critical = 0b1,
      /// @brief Allows critical and error events through.
      error = 0b11,
      /// @brief Allows critical, error, and warning events through.
      warning = 0b111,
      /// @brief Allows Critical, error, warning, and information events through.
      information = 0b1111,
      /// @brief Allows critical, error, warning, information, and verbose events through.
      verbose = 0b11111,
      /// @brief Allows the stop, start, suspend, transfer, and resume events through.
      activity_tracing = 0b1111111100000000,
      /// @brief Allows all events through.
      all = 0b1111111111111111,
    };
  }
}

/// @cond
flags_attribute_(xtd::diagnostics, source_levels);

template<> struct xtd::enum_register<xtd::diagnostics::source_levels> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::diagnostics::source_levels> {{xtd::diagnostics::source_levels::off, "off"}, {xtd::diagnostics::source_levels::critical, "critical"}, {xtd::diagnostics::source_levels::error, "error"}, {xtd::diagnostics::source_levels::warning, "warning"}, {xtd::diagnostics::source_levels::information, "information"}, {xtd::diagnostics::source_levels::verbose, "verbose"}, {xtd::diagnostics::source_levels::activity_tracing, "activity_tracing"}, {xtd::diagnostics::source_levels::all, "all"}};}
};
/// @endcond
