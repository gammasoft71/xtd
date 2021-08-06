/// @file
/// @brief Contains xtd::forms::list_control control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a common implementation of members for the list_box, choice and combo_box classes.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The list_control class provides implementations of common elements for the list_box and combo_box controls.
    /// @remarks The following properties are of primary concern to users of a data-bound list_box, choioce or combo_box: data_source, display_member, selected_value, and value_member properties.
    class forms_export_ list_control : public control {
    public:
      /// @brief Represent an item contained in the list_control::object_collection collection.
      class item {
      public:
        /// @brief Represent the sorter cllass used by list_control::object_collection collection.
        class sorter {
        public:
          /// @brief sorter functor.
          /// @param first the fist iterator to sort.
          /// @param last the last iterator to sort.
          /// @remarks same as std::sort.
          template<typename type_t>
          void operator()(type_t first, type_t last) {
            std::sort(first, last);
          }
        };

        /// @brief Initializes a new instance of the item class.
        item() = default;
        /// @brief Initializes a new instance of the item class with specified value.
        /// @param value a string that represent the item.
        item(const xtd::ustring& value) : value_(value) {}
        /// @brief Initializes a new instance of the item class with specified value and tag.
        /// @param value a string that represent the item.
        /// @param tag an object that contains data about the item.
        item(const xtd::ustring& value, const std::any& tag) : value_(value), tag_(tag) {}
        /// @cond
        item(const char* value) : value_(value) {}
        item(const item& value) = default;
        item(item&& value) = default;
        item& operator=(const item& value) = default;
        item& operator=(item&& value) = default;
        virtual ~item() = default;
        bool operator==(const item& value) const {return value_ == value.value_;}
        bool operator!=(const item& value) const {return !operator==(value);}
        bool operator<(const item& value) const {return value_ < value.value_;}
        bool operator<=(const item& value) const {return value_ <= value.value_;}
        bool operator>(const item& value) const {return value_ > value.value_;}
        bool operator>=(const item& value) const {return value_ >= value.value_;}
        friend std::ostream& operator<<(std::ostream& os, const item& value) {return os << value.to_string();}
        /// @endcond
        
        /// @brief Gets the value of the item.
        /// @return A xtd::ustring that represent the value of item.
        virtual const xtd::ustring& value() const {return value_;}
        
        /// @brief Gets the tag of the item.
        /// @return A std::any that represent the tag of item.
        virtual std::any tag() const {return tag_;}
        
        /// @brief Returns a string containing the vakue of the item.
        /// @return A string containing the value of the item.
        xtd::ustring to_string() const {return value_;}
        
      private:
        xtd::ustring value_;
        std::any tag_;
      };
   
      /// @brief Represents the collection of items in a list_control.
      using object_collection = layout::arranged_element_collection<item, item::sorter>;

      /// @brief Gets the zero-based index of the currently selected item.
      /// @return A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      virtual size_t selected_index() const {return selected_index_;}
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current list_control.
      virtual list_control& selected_index(size_t selected_index) = 0;
                  
      /// @brief Occurs when the selected_index property changes.
      /// @ingroup events
      event<list_control, event_handler> selected_index_changed;

      /// @brief Occurs when the selected_value property changes.
      /// @ingroup events
      event<list_control, event_handler> selected_value_changed;

      /// @brief This is a special value equal to the maximum value representable by the type size_t.
      static const size_t npos = std::numeric_limits<size_t>::max();
      
    protected:
      /// @brief Initializes a new instance of the listt_conrol class.
      list_control();
  
      /// @brief Gets a value indicating whether the list enables selection of list items.
      /// @return true if the list enables list item selection; otherwise, false. The default is true.
      virtual bool allow_selection() {return true;}
      
      virtual drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().window();}
      
      virtual drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().window_text();}
      
      /// @brief Raises the list_control::selected_index_changed event.
      virtual void on_selected_index_changed(const event_args& e) {selected_index_changed(*this, e);}

      /// @brief Raises the list_control::selected_value_changed event.
      virtual void on_selected_value_changed(const event_args& e) {selected_value_changed(*this, e);}

      /// @cond
      size_t selected_index_ = npos;
      /// @endcond;
    };
  }
}
