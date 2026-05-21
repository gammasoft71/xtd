/// @file
/// @brief Contains xtd::forms::native::button API.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.hpp"
#include <xtd/static>
#include <xtd/drawing/image>
#include <xtd/forms_native_export.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class button;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains button native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ button final static_ {
        friend xtd::forms::button;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Sets image.
        /// @param control Button window handle.
        /// @param image A xtd::drawing::image to set.
        /// @warning Internal use only
        static auto image(xtd::intptr control, const drawing::image& image) -> void;
        /// @brief Sets image align.
        /// @param control Button window handle.
        /// @param align A bitwise combination of the content alignment flags.
        /// @warning Internal use only
        static auto image_align(xtd::intptr control, xtd::uint32 align) -> void;
        /// @brief Mark button as default.
        /// @param control Button window handle.
        /// @warning Internal use only
        static auto set_default_button(xtd::intptr control) -> void;
        /// @}
      };
    }
  }
}
