/// @file
/// @brief Contains xtd::diagnostics::process_window_style enum class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../enum"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::diagnostics namespace provides classes that allow you to interact with system processes, event logs, and performance counters.
  namespace diagnostics {
    /// @brief Specified how a new window should appear when the system starts a process.
    /// @code
    /// enum class process_window_style
    /// @endcode
    /// @par Header
    /// @code #include <xtd/diagnostics/process_window_style> @endcode
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::diagnostics::process_window_style> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::diagnostics::process_window_style> {{xtd::diagnostics::process_window_style::normal, "normal"}, {xtd::diagnostics::process_window_style::hidden, "hidden"}, {xtd::diagnostics::process_window_style::minimized, "minimized"}, {xtd::diagnostics::process_window_style::maximized, "maximized"}};}
};
/// @endcond
