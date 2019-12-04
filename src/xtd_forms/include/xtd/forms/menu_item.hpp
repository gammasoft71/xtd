#pragma once
#include <xtd/ustring.hpp>
#include "menu.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class menu_item : public menu {
    public:      
      menu_item() : menu(menu::menu_item_collection {}) {};
      menu_item(const ustring& text) : menu(menu::menu_item_collection {}), text_(text) {}

    protected:
      intptr_t create_menu_handle() override;
      void destroy_menu_handle(intptr_t handle) override;

      ustring text_;
    };
  }
}
