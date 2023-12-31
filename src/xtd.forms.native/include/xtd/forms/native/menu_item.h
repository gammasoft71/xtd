/// @file
/// @brief Contains xtd::forms::native::menu_item API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.h"
#include <xtd/static.h>
#include <xtd/ustring.h>
#include <xtd/drawing/image.h>
#include <xtd/forms_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class context_menu;
    class menu_item;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Menu item native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ menu_item final static_ {
        friend xtd::forms::context_menu;
        friend xtd::forms::menu_item;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Checked menu item.
        /// @param menu_item Menu item handle.
        /// @param checked true if menu item is checked; otherwise false.
        /// @warning Internal use only
        static void checked(intptr menu_item, bool checked);
        /// @brief Creates menu item with specified menu.
        /// @param menu Menu handle.
        /// @param text The text associated with this menu_item.
        /// @param image A xtd::drawing::image associated with this menu_item.
        /// @param kind A menu item kind.
        /// @param shortcut A bitwise virtual key and virtual key modifiers shortcut associate with this menu_item.
        /// @return The created menu handle.
        /// @warning Internal use only
        static intptr create(intptr menu, const xtd::ustring& text, const xtd::drawing::image& image, int32 kind, size_t shortcut);
        /// @brief Destroys menu_item.
        /// @param menu_item Menu item handle.
        /// @warning Internal use only
        static void destroy(intptr menu_item);
        /// @brief Enabled menu item.
        /// @param menu_item Menu item handle.
        /// @param enabled true if menu item is enabled; otherwise false.
        /// @warning Internal use only
        static void enabled(intptr menu_item, bool enabled);
        /// @brief Gets menu id.
        /// @param menu_item Menu item handle.
        /// @return Id corresponding to menu_item handle.
        /// @warning Internal use only
        static intptr menu_id(intptr menu_item);
        /// @brief Sets text menu item.
        /// @param menu_item Menu item handle.
        /// @param text The text associated with this menu_item.
        /// @param shortcut A bitwise virtual key and virtual key modifiers shortcut associate with this menu_item.
        /// @warning Internal use only
        static void text(intptr menu_item, const xtd::ustring& text, size_t shortcut);
        /// @}
      };
    }
  }
}
