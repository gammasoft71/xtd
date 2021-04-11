/// @file
/// @brief Contains xtd::forms::native::cursor API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
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
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains cursor native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ cursor final static_ {
      public:
        /// @brief Creates cursor.
        /// @return The created control window handle.
        /// @warning Internal use only
        static intptr_t create();
        /// @brief Creates cursor with specifiiedd image and hot spot.
        /// @param image A xtd::drawing::image image will be use by cursor.
        /// @param hot_spot A xtd::drawing::point hot spot location.
        /// @return The created control window handle.
        /// @warning Internal use only
        static intptr_t create(const xtd::drawing::image& image, const drawing::point& hot_spot);
        static intptr_t copy(intptr_t cursor);
        static void current(intptr_t cursor);
        static void destroy(intptr_t cursor);
        static void hide();
        static drawing::point hot_spot(intptr_t cursor);
        static drawing::point position();
        static void position(const drawing::point& position);
        static drawing::size size(intptr_t cursor);
        static void show();
      };
    }
  }
}
