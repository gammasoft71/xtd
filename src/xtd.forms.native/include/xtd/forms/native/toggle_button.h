/// @file
/// @brief Contains xtd::forms::native::toggle_button API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.#pragma once
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
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains toggle button native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ toggle_button final static_ {
      public:
        /// @brief Sets check state.
        /// @param control Toggle button window handle.
        /// @param check_state The check state value : BST_UNCHECKED or BST_CHECKED or BST_INDETERMINATE.
        /// @warning Internal use only
        static void check_state(intptr_t control, int check_state);
      };
    }
  }
}
