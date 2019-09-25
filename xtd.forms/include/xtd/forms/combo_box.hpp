#pragma once
#include "layout/arranged_element_collection.hpp"
#include "list_control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class combo_box : public list_control {
    public:      
      combo_box();

      virtual drawing::size default_size() const override {return{121, 23};}
      
      item_collection& items() {return this->items_;}

      const item_collection& items() const {return this->items_;}
      
      const combo_box& items(const item_collection& items) {
        this->items_ = items;
        return *this;
      }
      
      using list_control::selected_index;
      list_control& selected_index(size_t selected_index) override;
      
      const item& selected_item() const {return this->selected_item_;}
      
      combo_box& selected_item(const item& selected_item);
      
      virtual bool sorted() const {return this->sorted_;}
      virtual combo_box& sorted(bool sorted);
      
      using list_control::text;
      control& text(const std::string& text) override {return *this;}

      
    protected:
      forms::create_params create_params() const override;

      void on_handle_created(const event_args& e) override;

      void on_selected_value_changed(const event_args& e) override;

      void wnd_proc(message& message) override;
      
      virtual void wm_reflect_command(message& message);
      
      virtual void wm_mouse_double_click(message& message);

      virtual void wm_mouse_down(message& message);
      
      virtual void wm_mouse_up(message& message);
      
      item_collection items_;
      item selected_item_;
      bool sorted_ = false;
    };
  }
}
