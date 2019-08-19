#pragma once
#include "layout/arranged_element_collection.hpp"
#include "border_style.hpp"
#include "control.hpp"
#include "selection_mode.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class list_box : public control {
    public:
      using string_collection = layout::arranged_element_collection<std::string>;
      
      list_box();

      forms::border_style border_style() const {return this->border_style_;}
      list_box& border_style(forms::border_style border_style);
      
      drawing::color default_back_color() const override;
      
      drawing::color default_fore_color() const override;
      
      drawing::size default_size() const override {return{120, 96};}
      
      string_collection& items() {return this->items_;}

      const string_collection& items() const {return this->items_;}
      
      const list_box& items(const string_collection& items) {
        this->items_ = items;
        return *this;
      }
      
      virtual size_t selected_index() const {return this->selected_index_;}
      
      virtual list_box& selected_index(size_t selected_index);
      
      virtual std::vector<size_t> selected_indices() const;
      
      virtual const std::string& selected_item() const {return this->selected_item_;}
      
      virtual list_box& selected_item(const std::string& selected_item);
      
      virtual std::vector<std::string> selected_items() const;
      
      virtual forms::selection_mode selection_mode() const {return this->selection_mode_;}

      virtual list_box& selection_mode(forms::selection_mode selection_mode);

      virtual bool sorted() const {return this->sorted_;}
      virtual list_box& sorted(bool sorted);
      
      using control::text;
      control& text(const std::string& text) override {return this->selected_item(text);}

      event<list_box, event_handler<control>> selected_index_changed;
      
    protected:
      forms::create_params create_params() const override;

      void on_handle_created(const event_args& e) override;

      virtual void on_selected_index_changed(const event_args& e) {this->selected_index_changed(*this, e);}

      virtual void on_selected_value_changed(const event_args& e) {this->control::text(this->selected_item_);}

      void wnd_proc(message& message) override;
      
      virtual void wm_reflect_command(message& message);
      
      void wm_mouse_double_click(message& message);

      void wm_mouse_down(message& message);
      
    private:
      forms::border_style border_style_ = forms::border_style::fixed_3d;
      string_collection items_;
      size_t selected_index_ = -1;
      std::string selected_item_;
      forms::selection_mode selection_mode_ = forms::selection_mode::one;
      bool sorted_ = false;
    };
  }
}
