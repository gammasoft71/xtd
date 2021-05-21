/// @file
/// @brief Contains xtd::forms::native::color_picker API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/color.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class color_picker;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains color picker native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ color_picker final static_ {
        friend xtd::forms::color_picker;
      protected:
        /// @brief Gets picker color.
        /// @param control Control window handle.
        /// @return A xtd::drawing::color from picker.
        /// @warning Internal use only
        static drawing::color color(intptr_t control);
        /// @brief Sets picker color.
        /// @param control Control window handle.
        /// @param color A xtd::drawing::color to picker.
        /// @warning Internal use only
        static void color(intptr_t control, const drawing::color& color);
      };
    }
  }
}
