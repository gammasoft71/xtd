/// @file
/// @brief Contains xtd::forms::native::menu API.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_FORMS_NATIVE_LIBRARY__
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
    class menu;
    class menu_item;
    /// @endcond
    
    /// @brief The xtd::forms::native namespace contains internal native API definitions to access underlying toolkits used by xtd.forms library.
    /// @warning Internal use only
    namespace native {
      /// @brief Menu native API.
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ menu final static_ {
        friend xtd::forms::menu;
        friend xtd::forms::menu_item;
      protected:
        /// @name Protected methods
        
        /// @{
        /// @brief Creates menu.
        /// @return The created menu handle.
        /// @warning Internal use only
        static intptr_t create();
        /// @brief Destroys menu.
        /// @param menu Menu handle.
        /// @warning Internal use only
        static void destroy(intptr_t menu);
        /// @brief Insert specified item to specisified position.
        /// @param menu Menu handle.
        /// @param pos Position to insert menu item.
        /// @param menu_item Menu item to insert.
        /// @warning Internal use only
        static void insert_item(intptr_t menu, size_t pos,  intptr_t menu_item);
        /// @brief Insert specified menu item to specisified position.
        /// @param menu Menu handle.
        /// @param pos Position to insert menu item.
        /// @param menu_item Menu item to insert.
        /// @param text The text associated with this menu.
        /// @warning Internal use only
        static void insert_menu(intptr_t menu, size_t pos,  intptr_t menu_item, const xtd::ustring& text);
        /// @brief Gets native menu handle.
        /// @param menu Menu handle.
        /// @return The native menu handle.
        /// @warning Internal use only
        static intptr_t native_handle(intptr_t menu);
        /// @brief Remove menu item from specisified position.
        /// @param menu Menu handle.
        /// @param pos Position to insert menu item.
        /// @warning Internal use only
        static void remove_item(intptr_t menu, size_t pos);
        /// @brief Sets text menu.
        /// @param menu Menu handle.
        /// @param text The text associated with this menu.
        /// @warning Internal use only
        static void text(intptr_t menu, const xtd::ustring& text);
        /// @}
      };
    }
  }
}
