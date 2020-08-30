#pragma once
#include "layout/arranged_element_collection.h"
#include "border_style.h"
#include "list_control.h"
#include "selection_mode.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class list_box : public list_control {
    public:      
      list_box();

      virtual forms::border_style border_style() const {return this->border_style_;}
      virtual list_box& border_style(forms::border_style border_style);
      
      drawing::color default_back_color() const override {return xtd::forms::theme_color::current_theme().window();}
      
      drawing::color default_fore_color() const override {return xtd::forms::theme_color::current_theme().window_text();}
      
      drawing::size default_size() const override {return {120, 96};}
      
      item_collection& items() {return this->items_;}

      const item_collection& items() const {return this->items_;}
      
      const list_box& items(const item_collection& items) {
        this->items_ = items;
        return *this;
      }
      
      using list_control::selected_index;
      list_control& selected_index(size_t selected_index) override;
      
      virtual std::vector<size_t> selected_indices() const;

      const item& selected_item() const {return this->selected_item_;}
      
      list_box& selected_item(const item& selected_item);
      
      std::vector<item> selected_items() const;
      
      virtual forms::selection_mode selection_mode() const {return this->selection_mode_;}

      virtual list_box& selection_mode(forms::selection_mode selection_mode);

      virtual bool sorted() const {return this->sorted_;}
      virtual list_box& sorted(bool sorted);
      
      using list_control::text;
      control& text(const std::string& text) override {return *this;}

      void begin_update();
      void end_update();
      
    protected:
      bool allow_selection() override {return this->selection_mode_ != forms::selection_mode::none;}

      forms::create_params create_params() const override;

      void on_handle_created(const event_args& e) override;

      void on_selected_value_changed(const event_args& e) override;

      void wnd_proc(message& message) override;
      
      virtual void wm_reflect_command(message& message);
      
      virtual void wm_mouse_double_click(message& message);

      virtual void wm_mouse_down(message& message);
      
      virtual void wm_mouse_up(message& message);
      
      forms::border_style border_style_ = forms::border_style::fixed_single;
      item_collection items_;
      item selected_item_;
      forms::selection_mode selection_mode_ = forms::selection_mode::one;
      bool sorted_ = false;
    };
  }
}
