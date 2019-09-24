#pragma once
#include "layout/arranged_element_collection.hpp"
#include "border_style.hpp"
#include "list_control.hpp"
#include "selection_mode.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class list_box : public list_control {
    public:
      class list_box_item {
      public:
        list_box_item() = default;
        list_box_item(const char* value) : value_(value) {}
        list_box_item(const std::string& value) : value_(value) {}
        list_box_item(const std::string& value, const std::any& tag) : value_(value), tag_(tag) {}
        list_box_item(const list_box_item& value) : value_(value.value_), tag_(value.tag_) {}
        
        std::string value() const {return this->value_;}
        void value(const std::string& value) {this->value_ = value;}
        
        std::any tag() const {return this->tag_;}
        void tag(const std::any& tag) {this->tag_ = tag;}

        bool operator==(const list_box_item& value) const {return this->value_ == value.value_;}
        bool operator!=(const list_box_item& value) const {return !this->operator==(value);}
        bool operator<(const list_box_item& value) const {return this->value_ < value.value_;}
        bool operator<=(const list_box_item& value) const {return this->value_ <= value.value_;}
        bool operator>(const list_box_item& value) const {return this->value_ > value.value_;}
        bool operator>=(const list_box_item& value) const {return this->value_ >= value.value_;}

      private:
        std::string value_;
        std::any tag_;
      };
      
      using list_box_item_collection = layout::arranged_element_collection<list_box_item>;
      
      list_box();

      forms::border_style border_style() const {return this->border_style_;}
      list_box& border_style(forms::border_style border_style);
      
      drawing::color default_back_color() const override {return drawing::system_colors::window();}
      
      drawing::color default_fore_color() const override {return drawing::system_colors::window_text();}
      
      drawing::size default_size() const override {return{120, 96};}
      
      list_box_item_collection& items() {return this->items_;}

      const list_box_item_collection& items() const {return this->items_;}
      
      const list_box& items(const list_box_item_collection& items) {
        this->items_ = items;
        return *this;
      }
      
      virtual size_t selected_index() const {return this->selected_index_;}
      
      virtual list_box& selected_index(size_t selected_index);
      
      virtual std::vector<size_t> selected_indices() const;
      
      virtual const list_box_item& selected_item() const {return this->selected_item_;}
      
      virtual list_box& selected_item(const list_box_item& selected_item);
      
      virtual std::vector<list_box_item> selected_items() const;
      
      virtual forms::selection_mode selection_mode() const {return this->selection_mode_;}

      virtual list_box& selection_mode(forms::selection_mode selection_mode);

      virtual bool sorted() const {return this->sorted_;}
      virtual list_box& sorted(bool sorted);
      
      using list_control::text;
      control& text(const std::string& text) override {
        this->selected_item_.value(text);
        return *this;
      }

      event<list_box, event_handler<control>> selected_index_changed;
      
    protected:
      forms::create_params create_params() const override;

      void on_handle_created(const event_args& e) override;

      virtual void on_selected_index_changed(const event_args& e) {this->selected_index_changed(*this, e);}

      virtual void on_selected_value_changed(const event_args& e) {this->list_control::text(this->selected_item_.value());}

      void wnd_proc(message& message) override;
      
      virtual void wm_reflect_command(message& message);
      
      void wm_mouse_double_click(message& message);

      void wm_mouse_down(message& message);
      
      void wm_mouse_up(message& message);
      
      forms::border_style border_style_ = forms::border_style::fixed_3d;
      list_box_item_collection items_;
      size_t selected_index_ = -1;
      list_box_item selected_item_;
      forms::selection_mode selection_mode_ = forms::selection_mode::one;
      bool sorted_ = false;
    };
  }
}
