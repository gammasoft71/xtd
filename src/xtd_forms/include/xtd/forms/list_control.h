#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a common implementation of members for the list_box and combo_box classes.
    /// @remarks The list_control class provides implementations of common elements for the list_box and combo_box controls.
    /// @remarks The following properties are of primary concern to users of a data-bound list_box or combo_box: data_source, display_member, selected_value, and value_member properties.
    class list_control : public control {
    public:
      class item {
      public:
        class sorter {
        public:
          template<typename type_t>
          void operator()(type_t first, type_t last) {
            std::sort(first, last);
          }
        };

        item() = default;
        item(const std::string& value) : value_(value) {}
        item(const std::string& value, const std::any& tag) : value_(value), tag_(tag) {}
        /// @cond
        item(const char* value) : value_(value) {}
        item(const item& value) = default;
        item(item&& value) = default;
        item& operator=(const item& value) = default;
        item& operator=(item&& value) = default;
        virtual ~item() = default;
        bool operator==(const item& value) const {return this->value_ == value.value_;}
        bool operator!=(const item& value) const {return !this->operator==(value);}
        bool operator<(const item& value) const {return this->value_ < value.value_;}
        bool operator<=(const item& value) const {return this->value_ <= value.value_;}
        bool operator>(const item& value) const {return this->value_ > value.value_;}
        bool operator>=(const item& value) const {return this->value_ >= value.value_;}
        /// @endcond
        
        virtual const std::string& value() const {return this->value_;}
        
        virtual std::any tag() const {return this->tag_;}
        
        std::string to_string() const {return this->value_;}
        friend std::ostream& operator<<(std::ostream& os, const item& value) {return os << value.to_string();}
        
      private:
        std::string value_;
        std::any tag_;
      };
   
      using item_collection = layout::arranged_element_collection<item, item::sorter>;

      /// @brief Gets the zero-based index of the currently selected item.
      /// @return A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      virtual size_t selected_index() const {return this->selected_index_;}
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      virtual list_control& selected_index(size_t selected_index) = 0;

      virtual std::string value_member() const {return this->value_member_;}
      virtual list_control& value_member(const std::string& value_member);
                  
      event<list_control, event_handler<control&>> selected_index_changed;

      event<list_control, event_handler<control&>> selected_value_changed;

      event<list_control, event_handler<control&>> value_member_changed;

    protected:
      list_control();
  
      /// @brief Gets a value indicating whether the list enables selection of list items.
      /// @return true if the list enables list item selection; otherwise, false. The default is true.
      virtual bool allow_selection() {return true;}
      
      virtual drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().window();}
      
      virtual drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().window_text();}
      
      virtual void on_selected_index_changed(const event_args& e) {this->selected_index_changed(*this, e);}

      virtual void on_selected_value_changed(const event_args& e) {this->selected_value_changed(*this, e);}

      virtual void on_value_member_changed(const event_args& e) {this->value_member_changed(*this, e);}

      /// @cond
      size_t selected_index_ = -1;
      std::string value_member_;
      /// @endcond;
    };
  }
}
