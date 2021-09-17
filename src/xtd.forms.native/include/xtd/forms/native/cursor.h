/// @file
/// @brief Contains xtd::forms::native::cursor API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/drawing/image.h>
#include <xtd/drawing/point.h>
#include <xtd/drawing/size.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class cursor;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains cursor native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ cursor final static_ {
        friend xtd::forms::cursor;
      protected:
        /// @brief Creates cursor.
        /// @return The created cursor handle.
        /// @warning Internal use only
        static intptr_t create();
        /// @brief Creates cursor with specifiiedd image and hot spot.
        /// @param image A xtd::drawing::image image will be use by cursor.
        /// @param hot_spot A xtd::drawing::point hot spot location.
        /// @return The created cursor handle.
        /// @warning Internal use only
        static intptr_t create(const xtd::drawing::image& image, const drawing::point& hot_spot);
        /// @brief Copies the cursor handle.
        /// @param cursor Cursor handle.
        /// @return An intptr_t that represents the cursor's handle.
        /// @warning Internal use only
        static intptr_t copy(intptr_t cursor);
        /// @brief Sets a cursor object that represents the mouse cursor.
        /// @param cursor Cursor handle.
        /// @warning Internal use only
        static void current(intptr_t cursor);
        /// @brief Destroy cursor.
        /// @param cursor Cursor handle.
        /// @warning Internal use only
        static void destroy(intptr_t cursor);
        /// @brief Hides cursor.
        /// @param cursor Cursor handle.
        /// @warning Internal use only
        static void hide();
        /// @brief Gets the cursor hot spot.
        /// @param cursor Cursor handle.
        /// @return A point representing the cursor hot spot.
        /// @warning Internal use only
        static drawing::point hot_spot(intptr_t cursor);
        /// @brief Gets the cursor's position.
        /// @param cursor Cursor handle.
        /// @return A point that represents the cursor's position in screen coordinates.
        /// @warning Internal use only
        static drawing::point position();
        /// @brief Sets the cursor's position.
        /// @param cursor Cursor handle.
        /// @param position A point that represents the cursor's position in screen coordinates.
        /// @warning Internal use only
        static void position(const drawing::point& position);
        /// @brief Gets the size of the cursor object.
        /// @param cursor Cursor handle.
        /// @return A size that represents the width and height of the cursor.
        /// @warning Internal use only
        static drawing::size size(intptr_t cursor);
        /// @brief Shows cursor.
        /// @param cursor Cursor handle.
        /// @warning Internal use only
        static void show();
      };
    }
  }
}
