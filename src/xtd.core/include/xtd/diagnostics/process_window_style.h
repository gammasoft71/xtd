/// @file
/// @brief Contains xtd::diagnostics::process_window_style enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specified how a new window should appear when the system starts a process.
    /// @par Namespace
    /// xtd::diagnostics
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    enum class process_window_style {
      /// @brief The normal, visible window style. The system displays a window with Normal style on the screen, in a default location. If a window is visible, the user can supply input to the window and view the window's output. Frequently, an application may initialize a new window to the Hidden style while it customizes the window's appearance, and then make the window style Normal.
      normal = 0,
      /// @brief The hidden window style. A window can be either visible or hidden. The system displays a hidden window by not drawing it. If a window is hidden, it is effectively disabled. A hidden window can process messages from the system or from other windows, but it cannot process input from the user or display output. Frequently, an application may keep a new window hidden while it customizes the window's appearance, and then make the window style Normal. To use process_window_style.Hidden, the ProcessStartInfo.UseShellExecute property must be false.
      hidden = 1,
      /// @brief The minimized window style. By default, the system reduces a minimized window to the size of its taskbar button and moves the minimized window to the taskbar.
      minimized = 2,
      /// @brief The maximized window style. By default, the system enlarges a maximized window so that it fills the screen or, in the case of a child window, the parent window's client area. If the window has a title bar, the system automatically moves it to the top of the screen or to the top of the parent window's client area. Also, the system disables the window's sizing border and the window-positioning capability of the title bar so that the user cannot move the window by dragging the title bar.
      maximized = 3,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, xtd::diagnostics::process_window_style value) {return os << to_string(value, {{diagnostics::process_window_style::normal, "normal"}, {diagnostics::process_window_style::hidden, "hidden"}, {diagnostics::process_window_style::minimized, "minimized"}, {diagnostics::process_window_style::maximized, "maximized"}});}
    inline std::wostream& operator<<(std::wostream& os, xtd::diagnostics::process_window_style value) {return os << to_string(value, {{diagnostics::process_window_style::normal, L"normal"}, {diagnostics::process_window_style::hidden, L"hidden"}, {diagnostics::process_window_style::minimized, L"minimized"}, {diagnostics::process_window_style::maximized, L"maximized"}});}
    /// @endcond
  }
}
