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
    };
  }
}
