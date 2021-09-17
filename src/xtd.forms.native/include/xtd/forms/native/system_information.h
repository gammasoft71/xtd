/// @file
/// @brief Contains xtd::forms::native::system_information API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/environment.h>
#include <xtd/drawing/size.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class system_information;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains settings native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ system_information final static_ {
        friend xtd::forms::system_information;
      protected:
        /// @brief Gets the active window tracking delay.
        /// @return The active window tracking delay, in milliseconds.
        /// @warning Internal use only
        static int32_t active_window_tracking_delay();
        /// @brief Gets a value that indicates the direction in which the operating system arranges minimized windows.
        /// @return One of the ArrangeDirection values that indicates the direction in which the operating system arranges minimized windows.
        /// @warning Internal use only
        static int32_t arrange_direction();
        /// @brief Gets an ArrangeStartingPosition value that indicates the starting position from which the operating system arranges minimized windows.
        /// @return One of the ArrangeStartingPosition values that indicates the starting position from which the operating system arranges minimized windows.
        /// @warning Internal use only
        static int32_t arrange_starting_position();
        /// @brief Gets a BootMode value that indicates the boot mode the system was started in.
        /// @return One of the boot_mode values that indicates the boot mode the system was started in.
        /// @warning Internal use only
        static int32_t boot_mode();
        /// @brief Gets the thickness, in pixels, of a three-dimensional (3-D) style window or system control border.
        /// @return A size that indicates the width, in pixels, of a 3-D style vertical border, and the height, in pixels, of a 3-D style horizontal border.
        /// @warning Internal use only
        static xtd::drawing::size border_3d_size();
        /// @brief Gets the border multiplier factor that is used when determining the thickness of a window's sizing border.
        /// @return The multiplier used to determine the thickness of a window's sizing border.
        /// @warning Internal use only
        static int32_t border_multiplier_factor();
        /// @brief Gets the thickness, in pixels, of a flat-style window or system control border.
        /// @return A size that indicates the width, in pixels, of a vertical border, and the height, in pixels, of a horizontal border.
        /// @warning Internal use only
        static xtd::drawing::size border_size();
        /// @brief Gets the standard size, in pixels, of a button in a window's title bar.
        /// @return A size that indicates the standard dimensions, in pixels, of a button in a window's title bar.
        /// @warning Internal use only
        static xtd::drawing::size caption_button_size();
        /// @brief Gets the height, in pixels, of the standard title bar area of a window.
        /// @return The height, in pixels, of the standard title bar area of a window.
        /// @warning Internal use only
        static int32_t caption_height();
        /// @brief Gets the caret blink time
        /// @return The caret blink time.
        /// @warning Internal use only
        static int32_t caret_blink_time();
        /// @brief Gets the width, in pixels, of the caret in edit controls.
        /// @return The width, in pixels, of the caret in edit controls.
        /// @warning Internal use only
        static int32_t caret_width();
        /// @brief Gets the NetBIOS computer name of the local computer.
        /// @return The name of this computer.
        /// @warning Internal use only
        static xtd::ustring computer_name();
        /// @brief Gets the maximum size, in pixels, that a cursor can occupy.
        /// @return A size that indicates the maximum dimensions of a cursor in pixels.
        /// @warning Internal use only
        static xtd::drawing::size cursor_size();
        /// @brief Gets a value indicating whether the operating system is capable of handling double-byte character set (DBCS) characters.
        /// @return true if the operating system supports DBCS; otherwise, false.
        static bool dbcs_enabled();
        /// @brief Gets a value indicating whether the debug version of USER.EXE is installed.
        /// @return true if the debugging version of USER.EXE is installed; otherwise, false.
        /// @warning Internal use only
        static bool debug_os();
        /// @brief Gets the dimensions, in pixels, of the area within which the user must click twice for the operating system to consider the two clicks a double-click.
        /// @return A size that indicates the dimensions, in pixels, of the area within which the user must click twice for the operating system to consider the two clicks a double-click.
        /// @warning Internal use only
        static xtd::drawing::size double_click_size();
        /// @brief Gets the maximum number of milliseconds that can elapse between a first click and a second click for the OS to consider the mouse action a double-click.
        /// @return The maximum amount of time, in milliseconds, that can elapse between a first click and a second click for the OS to consider the mouse action a double-click.
        /// @warning Internal use only
        static int32_t double_click_time();
        /// @brief Gets a value indicating whether the user has enabled full window drag.
        /// @return true if the user has enabled full window drag; otherwise, false.
        /// @warning Internal use only
        static bool drag_full_windows();
        /// @brief Gets the width and height of a rectangle centered on the point the mouse button was pressed, within which a drag operation will not begin.
        /// @return A size that specifies the area of a rectangle, in pixels, centered on the point the mouse button was pressed, within which a drag operation will not begin.
        /// @warning Internal use only
        static xtd::drawing::size drag_size();
        /// @brief Gets the thickness, in pixels, of the frame border of a window that has a caption and is not resizable.
        /// @return A size that specifies the thickness, in pixels, of a fixed sized window border.
        /// @warning Internal use only
        static xtd::drawing::size fixed_frame_border_size();
        /// @brief Gets the font smoothing contrast value used in ClearType smoothing.
        /// @return The ClearType font smoothing contrast value.
        /// @warning Internal use only
        static int32_t font_smoothing_contrast();
        /// @brief Gets the current type of font smoothing.
        /// @return A value that indicates the current type of font smoothing.
        /// @warning Internal use only
        static int32_t font_smoothing_type();
      };
    }
  }
}
