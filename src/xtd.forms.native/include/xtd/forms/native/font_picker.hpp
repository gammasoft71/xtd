/// @file
/// @brief Contains xtd::forms::native::font_picker API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.hpp"
#include <xtd/static>
#include <xtd/drawing/color>
#include <xtd/drawing/font>
#include <xtd/forms_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class font_picker;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains font picker native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ font_picker final static_ {
        friend xtd::forms::font_picker;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Gets the color selected by the user.
        /// @param control Control window handle.
        /// @return The color selected by the user. If a color is not selected, the default value is black.
        /// @warning Internal use only
        static drawing::color color(intptr control);
        /// @brief Sets the color selected by the user.
        /// @param control Control window handle.
        /// @param color The color selected by the user. If a color is not selected, the default value is black.
        /// @warning Internal use only
        static void color(intptr control, const drawing::color& color);
        /// @brief Gets the selected font.
        /// @param control Control window handle.
        /// @return The selected font.
        /// @warning Internal use only
        static drawing::font font(intptr control);
        /// @brief Sets the selected font.
        /// @param control Control window handle.
        /// @param font The selected font.
        /// @warning Internal use only
        static void font(intptr control, const drawing::font& font);
        /// @}
      };
    }
  }
}
