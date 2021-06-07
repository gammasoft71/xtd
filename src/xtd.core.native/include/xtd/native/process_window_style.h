
/// @file
/// @brief Contains process window style constants.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>

/// @brief The normal, visible window style. The system displays a window with Normal style on the screen, in a default location. If a window is visible, the user can supply input to the window and view the window's output. Frequently, an application may initialize a new window to the Hidden style while it customizes the window's appearance, and then make the window style Normal.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pws
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROCESS_WINDOW_STYLE_NORMAL = 0;

/// @brief The hidden window style. A window can be either visible or hidden. The system displays a hidden window by not drawing it. If a window is hidden, it is effectively disabled. A hidden window can process messages from the system or from other windows, but it cannot process input from the user or display output. Frequently, an application may keep a new window hidden while it customizes the window's appearance, and then make the window style Normal. To use process_window_style.Hidden, the ProcessStartInfo.UseShellExecute property must be false.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pws
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROCESS_WINDOW_STYLE_HIDDEN = 1;

/// @brief The minimized window style. By default, the system reduces a minimized window to the size of its taskbar button and moves the minimized window to the taskbar.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pws
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROCESS_WINDOW_STYLE_MINIMIZED = 2;

/// @brief The maximized window style. By default, the system enlarges a maximized window so that it fills the screen or, in the case of a child window, the parent window's client area. If the window has a title bar, the system automatically moves it to the top of the screen or to the top of the parent window's client area. Also, the system disables the window's sizing border and the window-positioning capability of the title bar so that the user cannot move the window by dragging the title bar.
/// @par Library
/// xtd.core.native
/// @ingroup xtd_core_native pws
/// @remarks Added specifically for xtd.
/// @warning Internal use only
constexpr int32_t PROCESS_WINDOW_STYLE_MAXIMIZED = 3;
