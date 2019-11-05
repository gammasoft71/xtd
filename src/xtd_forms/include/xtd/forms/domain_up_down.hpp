#pragma once
#include "up_down_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class domain_up_down : public up_down_base {
    public:      
       class item {
       public:
         item() = default;
         item(const ustring& value) : value_(value) {}
         item(const ustring& value, const std::any& tag) : value_(value), tag_(tag) {}
         /// @cond
         item(const char* value) : value_(value) {}
         item(const item& value) = default;
         virtual ~item() = default;
         bool operator==(const item& value) const {return this->value_ == value.value_;}
         bool operator!=(const item& value) const {return !this->operator==(value);}
         bool operator<(const item& value) const {return this->value_ < value.value_;}
         bool operator<=(const item& value) const {return this->value_ <= value.value_;}
         bool operator>(const item& value) const {return this->value_ > value.value_;}
         bool operator>=(const item& value) const {return this->value_ >= value.value_;}
         /// @endcond
         
         virtual const ustring& value() const {return this->value_;}
         
         virtual std::any tag() const {return this->tag_;}
         
         ustring to_string() const {return this->value_;}
         friend std::ostream& operator<<(std::ostream& os, const item& value) {return os << value.to_string();}
         
       private:
         ustring value_;
         std::any tag_;
       };
      
      using item_collection = layout::arranged_element_collection<item>;

      domain_up_down();

      item_collection& items() {return this->items_;}

      const item_collection& items() const {return this->items_;}
      
      const domain_up_down& items(const item_collection& items) {
        this->items_ = items;
        return *this;
      }
      /// @brief Gets the zero-based index of the currently selected item.
      /// @return A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      virtual size_t selected_index() const {return this->selected_index_;}
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      virtual domain_up_down& selected_index(size_t selected_index);
      
      const item& selected_item() const {return selected_item_;}
      
      domain_up_down& selected_item(const item& selected_item);

      forms::create_params create_params() const override;
      
      event<domain_up_down, event_handler<control&>> selected_index_changed;

      event<domain_up_down, event_handler<control&>> selected_value_changed;

      event<domain_up_down, event_handler<control&>> value_changed;
      
    protected:
      drawing::color default_back_color() const override {return drawing::system_colors::window();}
      
      drawing::color default_fore_color() const override {return drawing::system_colors::window_text();}
      
      drawing::size default_size() const override {return {120, 21};}

      /// @brief Overrides control::on_handle_created(const event_args&)
      /// @param e A EventArgs that contains the event data.
      void on_handle_created(const event_args& e) override;
      
      virtual void on_selected_index_changed(const event_args& e) {this->selected_index_changed(*this, e);}

      void on_text_changed(const event_args& e) override;
      
      virtual void on_value_changed(const event_args& e);
      
      item_collection items_;
      size_t selected_index_ = -1;
      item selected_item_;
    };
  }
}
