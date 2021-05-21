/// @file
/// @brief Contains xtd::forms::native::context_menu API.
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
    class context_menu;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains context menu native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ context_menu final static_ {
        friend xtd::forms::context_menu;
      protected:
        /// @brief Creates context menu.
        /// @return The created context menu window handle.
        /// @warning Internal use only
        static intptr_t create();
        /// @brief Destroys context menu.
        /// @param context_menu Context menu window handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr_t context_menu);
      };
    }
  }
}
