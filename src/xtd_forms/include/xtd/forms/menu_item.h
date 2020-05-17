#pragma once
#include <string>
#include <xtd/drawing/image.h>
#include "menu.h"
#include "shortcut.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class main_menu;
    class context_menu;
    /// @endcond
    
    enum class menu_item_kind {
      normal = 0,
      check = 1,
      radio = 2,
      drop_down = 3,
      separator = 4,
    };
  
    class menu_item : public xtd::forms::menu {
    public:      
      menu_item();
      menu_item(const std::string& text);
      menu_item(const std::string& text, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::drawing::image& image);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, xtd::forms::menu_item_kind kind);
      menu_item(const std::string& text, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, xtd::forms::menu_item_kind kind, bool checked);
      menu_item(const std::string& text, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked);
      menu_item(const std::string& text, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);

      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind, bool checked);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked);
      menu_item(const std::string& text, const xtd::event_handler<xtd::forms::component&>& on_click, const xtd::drawing::image& image, xtd::forms::menu_item_kind kind, bool checked, xtd::forms::shortcut shortcut);

      menu_item(const std::string& text, const std::vector<menu_item>& items);

      const std::string& text() const {return text_;}
      
    protected:
      friend main_menu;
      friend context_menu;
      intptr_t create_menu_handle() override;
      void destroy_menu_handle(intptr_t handle) override;

      std::string text_;
      xtd::drawing::image image_ = xtd::drawing::image::empty;
      xtd::forms::menu_item_kind kind_ = xtd::forms::menu_item_kind::normal;
      bool checked_ = false;
      xtd::forms::shortcut shortcut_ = static_cast<xtd::forms::shortcut>(0);
    };
  }
}
