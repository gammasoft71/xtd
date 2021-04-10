/// @file
/// @brief Contains xtd::forms::native::check_box API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      /// @brief Contains check box native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ check_box final static_ {
      public:
        /// @brief set check state.
        /// @param control Chreck box window handle to set check state.
        /// @param check_state The check state value : BST_UNCHECKED or BST_CHECKED or BST_INDETERMINATE.
        /// @warning Internal use only
        static void check_state(intptr_t control, int check_state);
      };
    }
  }
}
