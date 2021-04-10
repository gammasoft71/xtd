/// @file
/// @brief Contains xtd::forms::native::button API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/image.h>
#include <xtd/forms_native_export.h>

namespace xtd {
  namespace forms {
    namespace native {
      /// @brief Contains button native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native
      /// @warning Internal use only
      class forms_native_export_ button final static_ {
      public:
        /// @brief Mark button as default.
        /// @param control Button window handle.
        /// @warning Internal use only
        static void set_default_button(intptr_t control);
      };
    }
  }
}
