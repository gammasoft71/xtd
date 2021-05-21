/// @file
/// @brief Contains xtd::forms::native::screen API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdio>
#include <string>
#include <xtd/static.h>
#include <xtd/drawing/point.h>
#include <xtd/drawing/rectangle.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class screen;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains screen native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
     class forms_native_export_ screen final static_ {
       friend xtd::forms::screen;
     protected:
       /// @brief Gets number of screens.
       /// @return Number of screens.
       /// @warning Internal use only
        static size_t count();
       /// @brief Creates a graphics for the screen.
       /// @return A graphics handle for the screen.
       /// @warning Internal use only
        static intptr_t create_graphics();
       /// @brief Gets the number of bits of memory, associated with one pixel of data.
       /// @param index The screen index.
       /// @return The number of bits of memory, associated with one pixel of data.
       /// @warning Internal use only
        static int32_t bits_per_pixel(size_t index);
       /// @brief Gets the bounds of the display.
       /// @param index The screen index.
       /// @return A xtd::drawing::rectangle, representing the bounds of the display.
       /// @warning Internal use only
        static drawing::rectangle bounds(size_t index);
       /// @brief Gets the device name associated with a display.
       /// @param index The screen index.
       /// @return The device name associated with a display.
       /// @warning Internal use only
        static std::string device_name(size_t index);
       /// @brief Gets a value indicating whether a particular display is the primary device.
       /// @param index The screen index.
       /// @return true if index display is primary; otherwise, false.
       /// @warning Internal use only
        static bool primary(size_t index);
       /// @brief Gets the working area of the display. The working area is the desktop area of the display, excluding taskbars, docked windows, and docked tool bars.
       /// @param index The screen index.
       /// @return A xtd::drawing::rectangle, representing the working area of the display.
       /// @warning Internal use only
        static drawing::rectangle working_area(size_t index);
       /// @brief Retrieves a screen for the display that contains the largest portion of the object referred to by the specified handle.
       /// @param handle The window handle for which to retrieve the screen.
       /// @return A screen index for the display that contains the largest region of the object. In multiple display environments where no display contains any portion of the specified handle, the display closest to the object is returned.
       /// @warning Internal use only
        static size_t from_handle(intptr_t handle);
       /// @brief Retrieves a screen for the display that contains the specified point.
       /// @param point A xtd::drawing::oint that specifies the location for which to retrieve a screen.
       /// @return A screen index for the display that contains the point. In multiple display environments where no display contains the point, the display closest to the specified point is returned.
       /// @warning Internal use only
        static size_t from_point(const drawing::point& point);
      };
    }
  }
}
