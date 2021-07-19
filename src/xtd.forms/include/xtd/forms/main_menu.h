/// @file
/// @brief Contains xtd::forms::main_menu menu.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "menu_item.h"
#include "message.h"
#include "theme_images.h"
#include <xtd/drawing/size.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
  /// @cond
  class form;
  /// @endcond
  
    /// @brief Represents the menu structure of a form.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms menus_and_toolbars
    /// @par Examples
    /// The following code example demonstrate the use of main_menu control.
    /// @include main_menu.cpp
    /// @par Windows
    /// @image html main_menu_w.png
    /// <br>
    /// @image html main_menu_wd.png
    /// @par macOS
    /// @image html main_menu_m.png
    /// <br>
    /// @image html main_menu_md.png
    /// @par Gnome
    /// @image html main_menu_g.png
    /// <br>
    /// @image html main_menu_gd.png
    /// @par Examples
    /// The following code example demonstrate the use of main_menu::create_standard_items factroy.
    /// @include main_menu_create_standard_items.cpp
    /// @par Windows
    /// @image html main_menu_create_standard_items_w.png
    /// <br>
    /// @image html main_menu_create_standard_itemsmain_menu_create_standard_items_wd.png
    /// @par macOS
    /// @image html main_menu_create_standard_items_m.png
    /// <br>
    /// @image html main_menu_create_standard_items_md.png
    /// @par Gnome
    /// @image html main_menu_create_standard_items_g.png
    /// <br>
    /// @image html main_menu_create_standard_items_gd.png
    class forms_export_ main_menu : public menu {
    public:
      /// @brief Initialize a new instance of main_menu class.
      main_menu();
      /// @brief Initialize a new instance of main_menu class.
      /// @param menu_items An array of menu_item objects that will be added to the main_menu.
      main_menu(const std::vector<menu_item>& menu_items);
      /// @cond
      main_menu(const std::initializer_list<menu_item>& menu_items);
      ~main_menu();
      /// @endcond

      /// @brief A factory to create a main menu with specified on click event handler.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      static xtd::forms::main_menu create_standard_items(const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified image size and on click event handler.
      /// @param image_size A xttd::drawing::size that represent the menu item image size.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      static xtd::forms::main_menu create_standard_items(const xtd::drawing::size& image_size, const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified theme and on click event handler.
      /// @param theme The theme of menu item image.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      static xtd::forms::main_menu create_standard_items(const std::string& theme, const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified theme, image size and on click event handler.
      /// @param theme The theme of menu item image.
      /// @param image_size A xttd::drawing::size that represent the menu item image size.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      static xtd::forms::main_menu create_standard_items(const std::string& theme, const xtd::drawing::size& size, const xtd::event_handler& on_click);
      /// @brief A factory to create a main menu with specified theme, image size and on click event handler.
      /// @param theme The theme of menu item image.
      /// @param image_size A xttd::drawing::size that represent the menu item image size.
      /// @param on_click an event handler to respond on lick event.
      /// @return new main menu instance.
      static xtd::forms::main_menu create_standard_items(const xtd::forms::theme_images& theme, const xtd::drawing::size& size, const xtd::event_handler& on_click);

      /// @cond
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(on_click_type on_click) {return create_standard_items(xtd::event_handler(on_click));}
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const xtd::drawing::size& size, on_click_type on_click) {return create_standard_items(size, xtd::event_handler(on_click));}
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const std::string& theme, on_click_type on_click) {return create_standard_items(theme, xtd::event_handler(on_click));}
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const std::string& theme, const xtd::drawing::size& size, on_click_type on_click) {return create_standard_items(theme, size, xtd::event_handler(on_click));}
      template<typename on_click_type>
      static xtd::forms::main_menu create_standard_items(const xtd::forms::theme_images& theme, const xtd::drawing::size& size, on_click_type on_click) {return create_standard_items(theme, size, xtd::event_handler(on_click));}
      /// @endcond
 
    protected:
      intptr_t create_menu_handle() override;
      
      void destroy_menu_handle(intptr_t handle) override;

    private:
      friend class form;
      void wm_click(message& message);
    };
  }
}
