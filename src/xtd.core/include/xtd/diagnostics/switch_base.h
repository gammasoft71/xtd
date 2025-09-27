/// @file
/// @brief Contains xtd::diagnostics::switch_base class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/diagnostics/switch_object.hpp> - Will be removed in version 0.4.0.")
#else
#  warning "Deprecated : Replaced by #include <xtd/diagnostics/switch_object.hpp> - Will be removed in version 0.4.0."
#endif
#include "switch_object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Provides an abstract base class to create new debugging and tracing switches.
    /// ```cpp
    /// class core_export_ switch_base : public xtd::object
    /// ```
    /// @par Inheritance
    /// xtd::object → xtd::diagnostics::switch_base
    /// @par Header
    /// ```cpp
    /// #include <xtd/diagnostics/switch_base>
    /// ```
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks A switch provides an efficient mechanism for controlling tracing and debugging output at run time using external settings. The switch_base class implements default behavior for switches, allowing you to change the switch level at run time.
    /// @remarks This class is the base class for the boolean_switch, source_switch and the trace_switch classes. These switches meet most debugging and tracing needs.
    /// @par Notes to implementers
    /// If you need trace levels, or mechanisms for setting switch levels different from those provided by boolean_switch, source_switch and trace_switch, you can inherit from switch_base. When inheriting from this class, you must implement the switch_setting method.
    /// @deprecated Replaced by xtd::diagnostics::switch_object - Will be removed in version 0.4.0.
    using switch_base [[deprecated("Replaced by xtd::diagnostics::switch_object - Will be removed in version 0.4.0.")]] = switch_object;
  }
}
