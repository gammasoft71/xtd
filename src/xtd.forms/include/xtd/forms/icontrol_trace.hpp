/// @file
/// @brief Contains xtd::forms::icontrol_trace interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/interface>
#include <xtd/string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Allow a control to be called by control_trace_listener for writing debug or trace message.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/ibutton_trace>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms interfaces
    class icontrol_trace interface_ {
    public:
      /// @name Public Methods
      
      /// @{
      /// @brief Write debug or trace message on this instance control.
      /// @param message A string that tcontains the debug or trace message.
      virtual void write(const xtd::string& message) = 0;
      
      /// @brief Write debug or trace message on this instance control followed by line terminator.
      /// @param message A string that tcontains the debug or trace message.
      virtual void write_line(const xtd::string& message) = 0;
      
      /// @brief Flushes the output buffer and causes buffered data to write to the control.
      virtual void flush() = 0;
      /// @}
    };
  }
}
