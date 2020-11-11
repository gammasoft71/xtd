/// @file
/// @brief Contains xtd::diagnostics::debug class.
#pragma once
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specifies the levels of trace messages filtered by the source switch and event type filter. This enumeration has a flags attribute that allows a bitwise combination of its member values.
    /// @remarks The source levels identify the trace_event_type events that are to be traced. The source_switch class uses the source_levels enumeration to define the event level of the trace message to use for filtering messages to send to the trace listener.
    enum class source_levels {
      /// @brief Allows all events through.
      all = 0b1111111111111111,
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
    };
    
    /// @cond
    inline source_levels& operator +=(source_levels& lhs, source_levels rhs) {lhs = static_cast<source_levels>(static_cast<long long>(lhs) + static_cast<long long>(rhs)); return lhs;}
    inline source_levels& operator -=(source_levels& lhs, source_levels rhs) {lhs = static_cast<source_levels>(static_cast<long long>(lhs) - static_cast<long long>(rhs)); return lhs;}
    inline source_levels& operator &=(source_levels& lhs, source_levels rhs) {lhs = static_cast<source_levels>(static_cast<long long>(lhs) & static_cast<long long>(rhs)); return lhs;}
    inline source_levels& operator |=(source_levels& lhs, source_levels rhs) {lhs = static_cast<source_levels>(static_cast<long long>(lhs) | static_cast<long long>(rhs)); return lhs;}
    inline source_levels& operator ^=(source_levels& lhs, source_levels rhs) {lhs = static_cast<source_levels>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs)); return lhs;}
    inline source_levels operator +(source_levels lhs, source_levels rhs) {return static_cast<source_levels>(static_cast<long long>(lhs) + static_cast<long long>(rhs));}
    inline source_levels operator -(source_levels lhs, source_levels rhs) {return static_cast<source_levels>(static_cast<long long>(lhs) - static_cast<long long>(rhs));}
    inline source_levels operator ~(source_levels rhs) {return static_cast<source_levels>(~static_cast<long long>(rhs));}
    inline source_levels operator &(source_levels lhs, source_levels rhs) {return static_cast<source_levels>(static_cast<long long>(lhs) & static_cast<long long>(rhs));}
    inline source_levels operator |(source_levels lhs, source_levels rhs) {return static_cast<source_levels>(static_cast<long long>(lhs) | static_cast<long long>(rhs));}
    inline source_levels operator ^(source_levels lhs, source_levels rhs) {return static_cast<source_levels>(static_cast<long long>(lhs) ^ static_cast<long long>(rhs));}
    inline std::ostream& operator<<(std::ostream& os, xtd::diagnostics::source_levels value) {return os << to_string(value, {{diagnostics::source_levels::all, "all"}, {diagnostics::source_levels::off, "off"}, {diagnostics::source_levels::critical, "critical"}, {diagnostics::source_levels::error, "error"}, {diagnostics::source_levels::warning, "warning"}, {diagnostics::source_levels::information, "information"}, {diagnostics::source_levels::verbose, "verbose"}, {diagnostics::source_levels::activity_tracing, "activity_tracing"}});}
    inline std::wostream& operator<<(std::wostream& os, xtd::diagnostics::source_levels value) {return os << to_string(value, {{diagnostics::source_levels::all, L"all"}, {diagnostics::source_levels::off, L"off"}, {diagnostics::source_levels::critical, L"critical"}, {diagnostics::source_levels::error, L"error"}, {diagnostics::source_levels::warning, L"warning"}, {diagnostics::source_levels::information, L"information"}, {diagnostics::source_levels::verbose, L"verbose"}, {diagnostics::source_levels::activity_tracing, L"activity_tracing"}});}
    /// @endcond
  }
}
