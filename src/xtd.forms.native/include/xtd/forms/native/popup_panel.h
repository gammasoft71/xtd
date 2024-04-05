/// @file
/// @brief Contains xtd::forms::native::popup_panel API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.#pragma once
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.h"
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class popup_panel;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains popup panel native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ popup_panel final static_ {
        friend xtd::forms::popup_panel;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Sets ignore mouse messages
        /// @param control Control popup panel handle.
        /// @param value If true, the popup panel does not close automatically when the user clicks outside the popup panel; otherwise the popup panel will close automatically.
        /// @warning Internal use only
        static void ignore_mouse_messages(intptr control, bool value);
        
        /// @brief Sets the shape of the popup panel to that depicted by region.
        /// @param control Control popup panel handle.
        /// @param region The region to set shape;
        /// @warning Internal use only
        static void set_region(intptr control, intptr region);
        
        /// @brief Sets virtual size
        /// @param control Control popup panel handle.
        /// @param size A virtual xtd::drawing::size.
        /// @warning Internal use only
        static void virtual_size(intptr control, const drawing::size& size);
        /// @}
      };
    }
  }
}
