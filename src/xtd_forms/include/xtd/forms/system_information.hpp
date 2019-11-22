#pragma once
#include <xtd/drawing/size.hpp>
#include "arrange_direction.hpp"
#include "arrange_starting_position.hpp"
#include "boot_mode.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides information about the current system environment.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The system_information class provides static properties that can be used to get information about the current system environment. The class provides access to information such as Windows display element sizes, operating system settings, network availability, and the capabilities of hardware installed on the system. This class cannot be instantiated.
    /// @remarks For more information about system-wide parameters, see "SystemParametersInfo" in the Platform SDK documentation at http://msdn.microsoft.com.
    class system_information final {
    public:
      /// @cond
      system_information() = delete;
      /// @endcond

      /// @brief Gets the active window tracking delay.
      /// @return The active window tracking delay, in milliseconds.
      static int32_t active_window_tracking_delay();
      
      /// @brief Gets a value that indicates the direction in which the operating system arranges minimized windows.
      /// @return One of the ArrangeDirection values that indicates the direction in which the operating system arranges minimized windows.
      /// @remarks The arrange_direction property indicates the direction in which minimized windows are arranged on the desktop or in a Multiple Document Interface (MDI) container.
      static xtd::forms::arrange_direction arrange_direction();

      /// @brief Gets an ArrangeStartingPosition value that indicates the starting position from which the operating system arranges minimized windows.
      /// @return One of the ArrangeStartingPosition values that indicates the starting position from which the operating system arranges minimized windows.
      /// @remarks The ArrangeStartingPosition property indicates the corner of a screen or window in which the operating system begins to arrange minimized windows.
      static xtd::forms::arrange_starting_position arrange_starting_position();

      /// @brief Gets a BootMode value that indicates the boot mode the system was started in.
      /// @return One of the boot_mode values that indicates the boot mode the system was started in.
      /// @remarks The boot_mode property indicates whether the operating system was started in a normal or safe boot mode.
      static xtd::forms::boot_mode boot_mode();

      /// @brief Gets the thickness, in pixels, of a three-dimensional (3-D) style window or system control border.
      /// @return A Size that indicates the width, in pixels, of a 3-D style vertical border, and the height, in pixels, of a 3-D style horizontal border.
      /// @remarks The Border3DSize property indicates the thickness, in pixels, of a three-dimensional (3-D) style system control border.
      /// @remarks The Width property of the Border3DSize property indicates the width of a vertical 3-D border. The Height property of the Border3DSize property indicates the height of a horizontal 3-D border.
      /// @remarks The BorderSize property indicates the thickness of a window or system control border that is not a 3-D style border.
      static xtd::drawing::size border_3d_size();

      /// @brief Gets the border multiplier factor that is used when determining the thickness of a window's sizing border.
      /// @return The multiplier used to determine the thickness of a window's sizing border.
      static int32_t border_multiplier_factor();

      /// @brief Gets the thickness, in pixels, of a flat-style window or system control border.
      /// @return A Size that indicates the width, in pixels, of a vertical border, and the height, in pixels, of a horizontal border.
      /// @remarks The BorderSize property indicates the thickness of a flat-style system control border in pixels.
      /// @remarks The Width property of the BorderSize property indicates the width of a vertical flat-style border. The Height property of the BorderSize property indicates the height of a horizontal flat-style border.
      /// @remarks The Border3DSize property of the SystemInformation class indicates the thickness of a three-dimensional (3-D) style window or system control border.
      static xtd::drawing::size border_size();

      /// @brief Gets the standard size, in pixels, of a button in a window's title bar.
      /// @return A Size that indicates the standard dimensions, in pixels, of a button in a window's title bar.
      /// @remarks The CaptionButtonSize property indicates the standard dimensions of a button in the title bar of a window.
      /// @remarks The value of this property can be used to ensure that a button is properly sized to fit within the title bar of a window. Window caption buttons should be sized less than or equal to the standard dimensions for window caption buttons to ensure that they can be displayed in view correctly.
      static xtd::drawing::size caption_button_size();

      /// @brief Gets the height, in pixels, of the standard title bar area of a window.
      /// @return The height, in pixels, of the standard title bar area of a window.
      /// @remarks The caption_height property indicates the height of the standard window title bar area, in pixels.
      static int32_t caption_height();

      /// @brief Gets the caret blink time
      /// @return The caret blink time.
      static int32_t caret_blink_time();

      /// @brief Gets the width, in pixels, of the caret in edit controls.
      /// @return The width, in pixels, of the caret in edit controls.
      static int32_t caret_width();

      /// @brief Gets the NetBIOS computer name of the local computer.
      /// @return The name of this computer.
      /// @remarks The ComputerName property retrieves the NetBIOS name of the local computer. This is accomplished with a call into the native System Information function GetComputerName. This name is established at system startup_, when the system reads it from the registry. If the local computer is a node in a cluster, ComputerName returns the name of the cluster virtual server.
      /// @remarks You can use the computer_name method to determine the name of the computer that is displayed to other users on a network.
      static ustring computer_name();

      /// @brief Gets the maximum size, in pixels, that a cursor can occupy.
      /// @return A Size that indicates the maximum dimensions of a cursor in pixels.
      /// @remarks The system cannot create cursors of other sizes.
      static xtd::drawing::size cursor_size();

      /// @brief Gets a value indicating whether the operating system is capable of handling double-byte character set (DBCS) characters.
      /// @return true if the operating system supports DBCS; otherwise, false.
      /// @remarks The dbcs_enabled property indicates whether the current operating system supports DBCS.
      static bool dbcs_enabled();

      /// @brief Gets a value indicating whether the debug version of USER.EXE is installed.
      /// @return true if the debugging version of USER.EXE is installed; otherwise, false.
      static bool debug_os();

      /// @brief Gets the dimensions, in pixels, of the area within which the user must click twice for the operating system to consider the two clicks a double-click.
      /// @return A Size that indicates the dimensions, in pixels, of the area within which the user must click twice for the operating system to consider the two clicks a double-click.
      /// @remarks The double_click_size property indicates the size of a rectangular area centered around the point at which the last click occurred. To cause a double-click, a second click must occur within the area of the rectangle before the double-click time elapses.
      static xtd::drawing::size double_click_size();

      /// @brief Gets the maximum number of milliseconds that can elapse between a first click and a second click for the OS to consider the mouse action a double-click.
      /// @return The maximum amount of time, in milliseconds, that can elapse between a first click and a second click for the OS to consider the mouse action a double-click.
      /// @remarks A double-click is a series of two clicks of the mouse button, the second occurring within a specified length of time after, and within a specified distance from, the first. The double-click time is the maximum number of milliseconds that can elapse between the first and second click of a double-click.
      /// @remarks The double_click_time property indicates the maximum number of milliseconds that can elapse before a second click for the second click to cause a double-click.
      static int32_t double_click_time();

      /// @brief Gets a value indicating whether the user has enabled full window drag.
      /// @return true if the user has enabled full window drag; otherwise, false.
      /// @remarks When this property is true, the content of a window is refreshed during a window move or resize drag, using the current position and size as they are updated.
      static bool drag_full_windows();

      /// @brief Gets the width and height of a rectangle centered on the point the mouse button was pressed, within which a drag operation will not begin.
      /// @return A Size that specifies the area of a rectangle, in pixels, centered on the point the mouse button was pressed, within which a drag operation will not begin.
      /// @remarks The drag_size property indicates the size, in pixels, of a rectangle centered around the point at which the mouse button was pressed. Windows uses the rectangle as a boundary within which it does not start a drag operation.
      /// @remarks A user can hold a mouse button down and move the mouse within this area before a drag operation begins, which enables the user to click and release the mouse button easily without unintentionally starting a drag operation.
      static xtd::drawing::size drag_size();

      /// @brief Gets the thickness, in pixels, of the frame border of a window that has a caption and is not resizable.
      /// @return A Size that specifies the thickness, in pixels, of a fixed sized window border.
      /// @remarks The fixed_frame_border_size property indicates the thickness of the frame, in pixels, around the perimeter of a window that has a caption but is not sizable.
      /// @remarks The Width property of fixed_frame_border_size is the height of the horizontal border and the Height property of fixed_frame_border_size is the width of the vertical border.
      static xtd::drawing::size fixed_frame_border_size();

      /// @brief Gets the font smoothing contrast value used in ClearType smoothing.
      /// @return The ClearType font smoothing contrast value.
      static int32_t font_smoothing_contrast();

      /// @brief Gets the current type of font smoothing.
      /// @return A value that indicates the current type of font smoothing.
      static int32_t font_smoothing_type();
    };
  }
}
