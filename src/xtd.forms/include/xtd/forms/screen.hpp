/// @file
/// @brief Contains xtd::forms::screen component.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"
#include <xtd/drawing/rectangle>
#include <xtd/object>
#include <cstdint>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a display device or multiple display devices on a single system.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/screen>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    /// @remarks The constructor for this object is not public, so you cannot explicitly create a screen object. The object is created when you call its public methods.
    /// @par Examples
    /// The following code example demonstrates the use of screen class.
    /// @include screen.cpp
    /// @par Examples
    /// The following code example shows how to get screen informations of screen component.
    /// @include screen_informations.cpp
    class forms_export_ screen : public object {
    public:
      /// @cond
      screen(const screen&) = default;
      screen& operator =(const screen&) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the number of bits of memory, associated with one pixel of data.
      /// @return The number of bits of memory, associated with one pixel of data.
      /// @remarks Typically, the number of bits per pixel for a screen is useful when working with bitmaps.
      int32 bits_per_pixel() const noexcept;
      
      /// @brief Gets the bounds of the display.
      /// @return A xtd::drawing::rectangle, representing the bounds of the display.
      const drawing::rectangle& bounds() const noexcept;
      
      /// @brief Gets the device name associated with a display.
      /// @return The device name associated with a display.
      /// @remarks This string may contain non-printable characters.
      const xtd::string& device_name() const;
      
      /// @brief Gets a value indicating whether a particular display is high resolution.
      /// @return true if this display is high resolution; otherwise, false.
      bool high_resolution() const noexcept;
      
      /// @brief Gets the number of pixels per inch of the display.
      /// @return The number of pixels per inch of the display.
      /// @remarks See get_standard_pixels_per_inch() for more informations.
      int32 pixels_per_inch() const noexcept;
      
      /// @brief Gets a value indicating whether a particular display is the primary device.
      /// @return true if this display is primary; otherwise, false.
      bool primary() const noexcept;
      
      /// @brief Gets the scale factor of the display.
      /// @return The scale factor of the display.
      /// @remarks This value is computed from pixels_per_inch() for the display divided by get_standard_pixels_per_inch().
      /// @remarks If scale factor is equal to 1.0 is a standard display; greater than 1.0 is a high DPI display.
      /// @remarks See get_standard_pixels_per_inch() for more informations.
      double scale_factor() const noexcept;
            
      /// @brief Gets the working area of the display. The working area is the desktop area of the display, excluding taskbars, docked windows, and docked tool bars.
      /// @return A xtd::drawing::rectangle, representing the working area of the display.
      /// @remarks The working area is the desktop area of the display, excluding taskbars, docked windows, and docked tool bars.
      /// @remarks working_area will return the entire area of the screen if the Windows Taskbar is set to Auto-Hide, no matter whether the Taskbar is currently displayed or not.
      const drawing::rectangle& working_area() const noexcept;
      /// @}
      
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets an array of all displays on the system.
      /// @return An array of type screen, containing all displays on the system.
      static std::vector<screen> all_screens();
      
      /// @brief Gets the primary display.
      /// @return The primary display.
      /// @remarks For a single display system, the primary display is the only display.
      static screen primary_screen();
      /// @}

      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates the xtd::drawing::graphics for the screen.
      /// @return A xtd::drawing::graphics for the screen.
      static drawing::graphics create_graphics();
      
      /// @brief Retrieves a screen for the display that contains the largest portion of the specified control.
      /// @param control A xtd::forms::control for which to retrieve a Screen.
      /// @return A screen for the display that contains the largest region of the specified control. In multiple display environments where no display contains the control, the display closest to the specified control is returned.
      static screen from_control(const control& control);
      
      /// @brief Retrieves a screen for the display that contains the largest portion of the object referred to by the specified handle.
      /// @param handle The window handle for which to retrieve the screen.
      /// @return A screen for the display that contains the largest region of the object. In multiple display environments where no display contains any portion of the specified handle, the display closest to the object is returned.
      static screen from_handle(intptr handle);
      
      /// @brief Retrieves a screen for the display that contains the specified point.
      /// @param point A xtd::drawing::point that specifies the location for which to retrieve a screen.
      /// @return A screen for the display that contains the point. In multiple display environments where no display contains the point, the display closest to the specified point is returned.
      static screen from_point(const drawing::point& point);
      
      /// @brief Retrieves a screen for the display that contains the largest portion of the rectangle.
      /// @param A xtd::drawing::rectangle that specifies the area for which to retrieve the display.
      /// @return A screen for the display that contains the largest region of the specified rectangle. In multiple display environments where no display contains the rectangle, the display closest to the rectangle is returned.
      static screen from_rectangle(const drawing::rectangle& rect);
      
      /// @brief Retrieves the bounds of the display that contains the largest portion of the specified control.
      /// @param control The control for which to retrieve the display bounds.
      /// @return A xtd::drawing::rectangle that specifies the bounds of the display that contains the specified control. In multiple display environments where no display contains the specified control, the display closest to the control is returned.
      static drawing::rectangle get_bounds(const control& control);
      
      /// @brief Retrieves the bounds of the display that contains the largest portion of the specified handle.
      /// @param handle The window handle for which to retrieve the display bounds.
      /// @return A xtd::drawing::rectangle that specifies the bounds of the display that contains the specified handle. In multiple display environments where no display contains the specified handle, the display closest to the object is returned.
      static drawing::rectangle get_bounds(intptr handle);
      
      /// @brief Retrieves the bounds of the display that contains the specified point.
      /// @param point A xtd::drawing::point that specifies the coordinates for which to retrieve the display bounds.
      /// @return A xtd::drawing::rectangle that specifies the bounds of the display that contains the specified point. In multiple display environments where no display contains the specified point, the display closest to the point is returned.
      static drawing::rectangle get_bounds(const drawing::point& point);
      
      /// @brief Retrieves the bounds of the display that contains the largest portion of the specified rectangle.
      /// @param rect A xtd::drawing::rectangle that specifies the area for which to retrieve the display bounds.
      /// @return A xtd::drawing::rectangle that specifies the bounds of the display that contains the specified rectangle. In multiple display environments where no monitor contains the specified rectangle, the monitor closest to the rectangle is returned.
      static drawing::rectangle get_bounds(const drawing::rectangle& rect);
      
      /// @brief Gets the the standard number of pixels per inch of the display.
      /// @return The standard number of pixels per inch of the display.
      /// @remarks In printing, DPI (dots per inch) refers to the output resolution of a printer, scanner or image setter, and PPI (pixels per inch) refers to the input resolution of a photograph, image or screen.
      /// @remarks The following table shows the standard values by operating system :
      /// |  Values and conversion            | Windows | macOS | linux |
      /// | --------------------------------- | ------- | ----- | ----- |
      /// | Pixels per inch (PPI)             |      96 |    72 |    96 |
      /// | Pixels per centimeters (pixel/cm) |      38 |    28 |    38 |
      /// | Pitch (µm)                        |     265 |   353 |   265 |
      static int32 get_standard_pixels_per_inch();
      
      /// @brief Retrieves the working area for the display that contains the largest region of the specified control. The working area is the desktop area of the display, excluding taskbars, docked windows, and docked tool bars.
      /// @param control The control for which to retrieve the working area.
      /// @return A xtd::drawing::rectangle that specifies the working area. In multiple display environments where no display contains the specified control, the display closest to the control is returned.
      static drawing::rectangle get_working_area(const control& control);
      
      /// @brief Retrieves the working area for the display that contains the largest region of the specified handle. The working area is the desktop area of the display, excluding taskbars, docked windows, and docked tool bars.
      /// @param handle The window handle for which to retrieve the working area.
      /// @return A xtd::drawing::rectangle that specifies the working area. In multiple display environments where no display contains the specified handle, the display closest to the object is returned.
      static drawing::rectangle get_working_area(intptr handle);
      
      /// @brief Retrieves the working area closest to the specified point. The working area is the desktop area of the display, excluding taskbars, docked windows, and docked tool bars.
      /// @param point A xtd::drawing::point that specifies the coordinates for which to retrieve the working area.
      /// @return A xtd::drawing::rectangle that specifies the working area. In multiple display environments where no display contains the specified point, the display closest to the point is returned.
      static drawing::rectangle get_working_area(const drawing::point& point);
      
      /// @brief Retrieves the working area for the display that contains the largest portion of the specified rectangle. The working area is the desktop area of the display, excluding taskbars, docked windows, and docked tool bars.
      /// @param rect The xtd::drawing::rectangle that specifies the area for which to retrieve the working area.
      /// @return A xtd::drawing::rectangle that specifies the working area. In multiple display environments where no display contains the specified rectangle, the display closest to the rectangle is returned.
      static drawing::rectangle get_working_area(const drawing::rectangle& rect);
      /// @}
      
    private:
      screen() = default;
      screen(int32 bits_per_pixel, const drawing::rectangle& bounds, const xtd::string& device_name, int32 pixels_per_inch, bool primary, double scale_factor, const drawing::rectangle& working_area);
      
      int32 bits_per_pixel_ = 0;
      drawing::rectangle bounds_;
      xtd::string device_name_;
      int32 pixels_per_inch_ = 96;
      bool primary_ = false;
      double scale_factor_ = 1.;
      drawing::rectangle working_area_;
    };
  }
}
