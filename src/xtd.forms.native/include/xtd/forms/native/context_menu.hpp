/// @file
/// @brief Contains xtd::forms::native::context_menu API.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_FORMS_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "create_params.hpp"
#include <xtd/static>
#include <xtd/forms_native_export.hpp>

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
      /// @par Namespace
      /// xtd::forms::native
      /// @par Library
      /// xtd.forms.native
      /// @ingroup xtd_forms_native native
      /// @warning Internal use only
      class forms_native_export_ context_menu final static_ {
        friend xtd::forms::context_menu;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Creates context menu.
        /// @return The created context menu window handle.
        /// @warning Internal use only
        [[nodiscard]] static auto create() -> xtd::intptr;
        /// @brief Destroys context menu.
        /// @param context_menu Context menu window handle to destroy.
        /// @warning Internal use only
        static auto destroy(xtd::intptr context_menu) -> void;
        /// @brief Insert specified item to specisified position.
        /// @param context_menu Context menu handle.
        /// @param pos Position to insert menu item.
        /// @param menu_item Menu item to insert.
        /// @warning Internal use only
        static auto insert_item(xtd::intptr context_menu, xtd::usize pos,  xtd::intptr menu_item) -> void;
        /// @brief Insert specified menu item to specisified position.
        /// @param context_menu Context menu handle.
        /// @param pos Position to insert menu item.
        /// @param menu_item Menu item to insert.
        /// @param text The text associated with this menu.
        /// @warning Internal use only
        static auto insert_menu(xtd::intptr context_menu, xtd::usize pos,  xtd::intptr menu_item, const xtd::string& text) -> void;
        /// @brief Gets native menu handle.
        /// @param context_menu Context menu handle.
        /// @return The native menu handle.
        /// @warning Internal use only
        [[nodiscard]] static auto native_handle(xtd::intptr context_menu) -> xtd::intptr;
        /// @brief Remove menu item from specisified position.
        /// @param context_menu Context menu handle.
        /// @param pos Position to insert menu item.
        /// @warning Internal use only
        static auto remove_item(xtd::intptr context_menu, xtd::usize pos) -> void;
        /// @brief Sets text menu.
        /// @param context_menu Context menu handle.
        /// @param text The text associated with this menu.
        /// @warning Internal use only
        static auto text(xtd::intptr context_menu, const xtd::string& text) -> void;
        /// @}
      };
    }
  }
}
