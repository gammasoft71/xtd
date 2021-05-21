/// @file
/// @brief Contains xtd::forms::native::command_link_button API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/image.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains command link button native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ command_link_button final static_ {
      public:
        /// @brief Sets image.
        /// @param control Command link button window handle.
        /// @param image A xtd::drawing::image to set.
        /// @warning Internal use only
        static void image(intptr_t control, const drawing::image& image);
        /// @brief Sets image align.
        /// @param control Command link button window handle.
        /// @param align A bitwise combination of the content alignment flags.
        /// @warning Internal use only
        static void image_align(intptr_t control, uint32_t align);
      };
    }
  }
}
