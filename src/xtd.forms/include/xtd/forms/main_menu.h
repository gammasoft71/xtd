/// @file
/// @brief Contains xtd::forms::main_menu menu.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "menu_item.h"
#include "message.h"
#include <xtd/drawing/size>
#include <memory>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class form;
    /// @endcond
    
    /// @brief Represents the menu structure of a form.
    /// @par Header
    /// @code #include <xtd/forms/main_menu> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    /// @par Appearance
    /// |       | Windows                                           | macOS                                             | Gnome                                             |
    /// | ----- | ------------------------------------------------- | ------------------------------------------------- | ------------------------------------------------- |
    /// | Light |  @image html menus_and_toolbars_main_menu_w.png   |  @image html menus_and_toolbars_main_menu_m.png   |  @image html menus_and_toolbars_main_menu_g.png   |
    /// | Dark  |  @image html menus_and_toolbars_main_menu_wd.png  |  @image html menus_and_toolbars_main_menu_md.png  |  @image html menus_and_toolbars_main_menu_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of main_menu control.
    /// @include main_menu.cpp
    /// @par Examples
    /// The following code example demonstrates the use of main_menu::create_standard_items factory.
    /// @include main_menu_create_standard_items.cpp
    class forms_export_ main_menu : public menu {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of main_menu class.
      main_menu();
      /// @brief Initialize a new instance of main_menu class.
      /// @param menu_items An array of menu_item objects that will be added to the main_menu.
      explicit main_menu(const std::vector<menu_item_ref>& menu_items);
      /// @}
      
      /// @cond
      explicit main_menu(const std::initializer_list<const_menu_item_ref>& menu_items);
      /// @endcond
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create a main menu with specified on click event handler.
      /// @param menu_items an array xtd::forms::menu_item which will contain the created menu items.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      /// @remarks The following table shows the items contained in the menu_items array and sub menu_items array :
      /// | menu_index | sub_menu_index | menu_item | sub_menu_item |
      /// | ---------- | -------------- | --------- | ------------- |
      /// | 0          |                | file      |               |
      /// | 0          | 0              | file      | new           |
      /// | 0          | 1              | file      | open          |
      /// | 0          | 2              | file      | separator1    |
      /// | 0          | 3              | file      | save          |
      /// | 0          | 4              | file      | save_as       |
      /// | 0          | 5              | file      | separator2    |
      /// | 0          | 6              | file      | print         |
      /// | 0          | 7              | file      | print_preview |
      /// | 0          | 8              | file      | separator3    |
      /// | 0          | 9              | file      | exit          |
      /// | 1          |                | edit      |               |
      /// | 1          | 0              | edit      | undo          |
      /// | 1          | 1              | edit      | redo          |
      /// | 1          | 2              | edit      | separator1    |
      /// | 1          | 3              | edit      | cut           |
      /// | 1          | 4              | edit      | copy          |
      /// | 1          | 6              | edit      | paste         |
      /// | 1          | 6              | edit      | separator2    |
      /// | 1          | 7              | edit      | select_all    |
      /// | 2          |                | tools     |               |
      /// | 2          | 0              | tools     | customize     |
      /// | 2          | 1              | tools     | options       |
      /// | 3          |                | help      |               |
      /// | 3          | 0              | help      | contents      |
      /// | 3          | 1              | help      | index         |
      /// | 3          | 2              | help      | search        |
      /// | 3          | 3              | help      | separator1    |
      /// | 3          | 4              | help      | about         |
      ///
      /// @par Examples
      /// The following example shows how to access to edit menu item.
      /// @code
      /// auto main_menu = create_standard_items(on_click_menu_items);
      /// auto& edit_menu = main_menu.menu_items()[1].get();
      /// @endcode
      /// The following example shows how to access to search help menu item.
      /// @code
      /// auto main_menu = create_standard_items(on_click_menu_items);
      /// auto& search_help_menu = main_menu.menu_items()[3].get()[2].get();
      /// @endcode
      static xtd::forms::main_menu create_standard_items(const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified image size and on click event handler.
      /// @param menu_items an array xtd::forms::menu_item which will contain the created menu items.
      /// @param image_size A xtd::drawing::size that represent the menu item image size.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      /// @remarks The following table shows the items contained in the menu_items array and sub menu_items array :
      /// | menu_index | sub_menu_index | menu_item | sub_menu_item |
      /// | ---------- | -------------- | --------- | ------------- |
      /// | 0          |                | file      |               |
      /// | 0          | 0              | file      | new           |
      /// | 0          | 1              | file      | open          |
      /// | 0          | 2              | file      | separator1    |
      /// | 0          | 3              | file      | save          |
      /// | 0          | 4              | file      | save_as       |
      /// | 0          | 5              | file      | separator2    |
      /// | 0          | 6              | file      | print         |
      /// | 0          | 7              | file      | print_preview |
      /// | 0          | 8              | file      | separator3    |
      /// | 0          | 9              | file      | exit          |
      /// | 1          |                | edit      |               |
      /// | 1          | 0              | edit      | undo          |
      /// | 1          | 1              | edit      | redo          |
      /// | 1          | 2              | edit      | separator1    |
      /// | 1          | 3              | edit      | cut           |
      /// | 1          | 4              | edit      | copy          |
      /// | 1          | 6              | edit      | paste         |
      /// | 1          | 6              | edit      | separator2    |
      /// | 1          | 7              | edit      | select_all    |
      /// | 2          |                | tools     |               |
      /// | 2          | 0              | tools     | customize     |
      /// | 2          | 1              | tools     | options       |
      /// | 3          |                | help      |               |
      /// | 3          | 0              | help      | contents      |
      /// | 3          | 1              | help      | index         |
      /// | 3          | 2              | help      | search        |
      /// | 3          | 3              | help      | separator1    |
      /// | 3          | 4              | help      | about         |
      ///
      /// @par Examples
      /// The following example shows how to access to edit menu item.
      /// @code
      /// auto main_menu = create_standard_items(on_click_menu_items);
      /// auto& edit_menu = main_menu.menu_items()[1].get();
      /// @endcode
      /// The following example shows how to access to search help menu item.
      /// @code
      /// auto main_menu = create_standard_items(on_click_menu_items);
      /// auto& search_help_menu = main_menu.menu_items()[3].get()[2].get();
      /// @endcode
      static xtd::forms::main_menu create_standard_items(const xtd::drawing::size& image_size, const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified theme and on click event handler.
      /// @param menu_items an array xtd::forms::menu_item which will contain the created menu items.
      /// @param theme The theme of menu item image.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      /// @remarks The following table shows the items contained in the menu_items array and sub menu_items array :
      /// | menu_index | sub_menu_index | menu_item | sub_menu_item |
      /// | ---------- | -------------- | --------- | ------------- |
      /// | 0          |                | file      |               |
      /// | 0          | 0              | file      | new           |
      /// | 0          | 1              | file      | open          |
      /// | 0          | 2              | file      | separator1    |
      /// | 0          | 3              | file      | save          |
      /// | 0          | 4              | file      | save_as       |
      /// | 0          | 5              | file      | separator2    |
      /// | 0          | 6              | file      | print         |
      /// | 0          | 7              | file      | print_preview |
      /// | 0          | 8              | file      | separator3    |
      /// | 0          | 9              | file      | exit          |
      /// | 1          |                | edit      |               |
      /// | 1          | 0              | edit      | undo          |
      /// | 1          | 1              | edit      | redo          |
      /// | 1          | 2              | edit      | separator1    |
      /// | 1          | 3              | edit      | cut           |
      /// | 1          | 4              | edit      | copy          |
      /// | 1          | 6              | edit      | paste         |
      /// | 1          | 6              | edit      | separator2    |
      /// | 1          | 7              | edit      | select_all    |
      /// | 2          |                | tools     |               |
      /// | 2          | 0              | tools     | customize     |
      /// | 2          | 1              | tools     | options       |
      /// | 3          |                | help      |               |
      /// | 3          | 0              | help      | contents      |
      /// | 3          | 1              | help      | index         |
      /// | 3          | 2              | help      | search        |
      /// | 3          | 3              | help      | separator1    |
      /// | 3          | 4              | help      | about         |
      ///
      /// @par Examples
      /// The following example shows how to access to edit menu item.
      /// @code
      /// auto main_menu = create_standard_items(on_click_menu_items);
      /// auto& edit_menu = main_menu.menu_items()[1].get();
      /// @endcode
      /// The following example shows how to access to search help menu item.
      /// @code
      /// auto main_menu = create_standard_items(on_click_menu_items);
      /// auto& search_help_menu = main_menu.menu_items()[3].get()[2].get();
      /// @endcode
      static xtd::forms::main_menu create_standard_items(const xtd::ustring& theme, const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified theme, image size and on click event handler.
      /// @param menu_items an array xtd::forms::menu_item which will contain the created menu items.
      /// @param theme The theme of menu item image.
      /// @param image_size A xtd::drawing::size that represent the menu item image size.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      /// @remarks The following table shows the items contained in the menu_items array and sub menu_items array :
      /// | menu_index | sub_menu_index | menu_item | sub_menu_item |
      /// | ---------- | -------------- | --------- | ------------- |
      /// | 0          |                | file      |               |
      /// | 0          | 0              | file      | new           |
      /// | 0          | 1              | file      | open          |
      /// | 0          | 2              | file      | separator1    |
      /// | 0          | 3              | file      | save          |
      /// | 0          | 4              | file      | save_as       |
      /// | 0          | 5              | file      | separator2    |
      /// | 0          | 6              | file      | print         |
      /// | 0          | 7              | file      | print_preview |
      /// | 0          | 8              | file      | separator3    |
      /// | 0          | 9              | file      | exit          |
      /// | 1          |                | edit      |               |
      /// | 1          | 0              | edit      | undo          |
      /// | 1          | 1              | edit      | redo          |
      /// | 1          | 2              | edit      | separator1    |
      /// | 1          | 3              | edit      | cut           |
      /// | 1          | 4              | edit      | copy          |
      /// | 1          | 6              | edit      | paste         |
      /// | 1          | 6              | edit      | separator2    |
      /// | 1          | 7              | edit      | select_all    |
      /// | 2          |                | tools     |               |
      /// | 2          | 0              | tools     | customize     |
      /// | 2          | 1              | tools     | options       |
      /// | 3          |                | help      |               |
      /// | 3          | 0              | help      | contents      |
      /// | 3          | 1              | help      | index         |
      /// | 3          | 2              | help      | search        |
      /// | 3          | 3              | help      | separator1    |
      /// | 3          | 4              | help      | about         |
      ///
      /// @par Examples
      /// The following example shows how to access to edit menu item.
      /// @code
      /// auto main_menu = create_standard_items(on_click_menu_items);
      /// auto& edit_menu = main_menu.menu_items()[1].get();
      /// @endcode
      /// The following example shows how to access to search help menu item.
      /// @code
      /// auto main_menu = create_standard_items(on_click_menu_items);
      /// auto& search_help_menu = main_menu.menu_items()[3].get()[2].get();
      /// @endcode
      static xtd::forms::main_menu create_standard_items(const xtd::ustring& theme, const xtd::drawing::size& size, const xtd::event_handler& on_click);
      /// @}
      
      /// @cond
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(on_click_type on_click) {return create_standard_items(xtd::event_handler(on_click));}
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const xtd::drawing::size& size, on_click_type on_click) {return create_standard_items(size, xtd::event_handler(on_click));}
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const xtd::ustring& theme, on_click_type on_click) {return create_standard_items(theme, xtd::event_handler(on_click));}
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const xtd::ustring& theme, const xtd::drawing::size& size, on_click_type on_click) {return create_standard_items(theme, size, xtd::event_handler(on_click));}
      /// @endcond
      
    protected:
      /// @name Protected methods
      
      /// @{
      intptr create_menu_handle() override;
      void destroy_menu_handle(intptr handle) override;
      void on_item_added(size_t pos, menu_item_ref item) override;
      void on_item_removed(size_t pos, menu_item_ref item) override;
      /// @}
      
    private:
      friend class form;
      void wm_click(message& message);
      std::vector<std::unique_ptr<menu_item>> standard_menu_items_;
    };
  }
}

