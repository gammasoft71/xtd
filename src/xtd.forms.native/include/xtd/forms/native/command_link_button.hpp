/// @file
/// @brief Contains xtd::forms::native::command_link_button API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.hpp"
#include <xtd/static>
#include <xtd/drawing/image>
#include <xtd/forms_native_export.h>
#include <tuple>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class command_link_button;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains command link button native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ command_link_button final static_ {
        friend xtd::forms::command_link_button;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Sets image.
        /// @param control Command link button window handle.
        /// @param image A xtd::drawing::image to set.
        /// @warning Internal use only
        static void image(intptr control, const drawing::image& image);
        /// @brief Sets image align.
        /// @param control Command link button window handle.
        /// @param align A bitwise combination of the content alignment flags.
        /// @warning Internal use only
        static void image_align(intptr control, uint32 align);
        /// @brief Sets text and supplementary text.
        /// @param control Command link button window handle.
        /// @param texts A tuple of two strings that represent control text and supplementary text.
        /// @warning Internal use only
        static void texts(intptr control, const std::tuple<string, string>& texts);
        /// @}
      };
    }
  }
}
