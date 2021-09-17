/// @file
/// @brief Contains xtd::forms::icontrol_trace interface.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/interface.h>
#include <xtd/ustring.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Allow a control to be called by control_trace_listener for wrtiting debug or trace message.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms interfaces
    class icontrol_trace interface_ {
    public:
      /// @brief Write debug or trace message on this instance control.
      /// @param message A string that tcontains the debug oor trace message.
      virtual void write(const xtd::ustring& message) = 0;

      /// @brief Write debug or trace message on this instance control followed by line terminator.
      /// @param message A string that tcontains the debug oor trace message.
      virtual void write_line(const xtd::ustring& message) = 0;

      /// @brief Flushes the output buffer and causes buffered data to write to the contrtol.
      virtual void flush() = 0;
    };
  }
}
