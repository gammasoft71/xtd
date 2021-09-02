/// @file
/// @brief Contains xtd::forms::native::tab_page API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.#pragma once
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class tab_control;
    class tab_page;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains tab page native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ tab_page final static_ {
        friend xtd::forms::tab_control;
        friend xtd::forms::tab_page;
      protected:
        /// @brief Sets image index associate to the tab page.
        /// @param control Tab page window handle.
        /// @param image_index The image index.
        /// @warning Internal use only
        static void image_index(intptr_t control, size_t image_index);
        /// @brief Sets text associate to the tab page.
        /// @param control Tab page window handle.
        /// @param text The text string.
        /// @warning Internal use only
        static void text(intptr_t control, const xtd::ustring& text);
      };
    }
  }
}
