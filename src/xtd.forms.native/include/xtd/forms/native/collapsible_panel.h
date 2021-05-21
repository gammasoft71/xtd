/// @file
/// @brief Contains xtd::forms::native::collapsible_panel API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class collapsible_panel;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains collapsible panel native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ collapsible_panel final static_ {
        friend xtd::forms::collapsible_panel;
      protected:
        /// @brief Gets a value indicating whether the collapsible_panel is in the expanded.
        /// @param control Collapsible panel window handle.
        /// @return true if collapsible_panel is expanded; otherwise false.
        /// @warning Internal use only
        static bool expanded(intptr_t handle);
        /// @brief Sets a value indicating whether the collapsible_panel is in the expanded.
        /// @param control Collapsible panel window handle.
        /// @param expanded true if collapsible_panel is expanded; otherwise false.
        /// @warning Internal use only
        static void expanded(intptr_t handle, bool expanded);
      };
    }
  }
}
