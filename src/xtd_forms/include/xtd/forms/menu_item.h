#pragma once
#include <string>
#include "menu.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class main_menu;
    class context_menu;
    /// @endcond
    class menu_item : public menu {
    public:      
      menu_item();
      menu_item(const std::string& text);
      menu_item(const std::string& text, const std::initializer_list<menu_item>& items);
      menu_item(const std::string& text, const std::vector<menu_item>& items);

      const std::string& text() const {return text_;}
      
    protected:
      friend main_menu;
      friend context_menu;
      intptr_t create_menu_handle() override;
      void destroy_menu_handle(intptr_t handle) override;

      std::string text_;
    };
  }
}
