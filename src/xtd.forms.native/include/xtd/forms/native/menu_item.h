/// @file
/// @brief Contains xtd::forms::native::menu_item API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "../create_params.h"
#include <xtd/static.h>
#include <xtd/drawing/image.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Menu item native API.
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ menu_item final static_ {
      public:
        /// @brief Creates menu item.
        /// @param text The text associated with this menu_item.
        /// @param image A xtd::drawing::image associated with this menu_item.
        /// @param kind A menu item kind.
        /// @param checked true if menu item is checked; otherwise false.
        /// @param shortcut A bittwise virtual key and virtual key modifiers shortcut associate with this menu_item.
        /// @return The created menu handle.
        /// @warning Internal use only
        static intptr_t create(const std::string& text, const xtd::drawing::image& image, int32_t kind, bool checked, size_t shortcut);
        /// @brief Destroy menu_item.
        /// @param menu_item Menu item handle.
        /// @warning Internal use only
        static void destroy(intptr_t menu_item);
        /// @brief Gets menu id.
        /// @param menu_item Menu item handle.
        /// @return Id corresponding to menu_item handle.
        static int32_t menu_id(intptr_t menu_item);
      };
    }
  }
}
