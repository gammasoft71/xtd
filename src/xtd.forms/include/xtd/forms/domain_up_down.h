/// @file
/// @brief Contains xtd::forms::domain_up_down control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "up_down_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows spin box (also known as an up-down control) that displays string values.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of domain up down control.
    /// @include domain_up_down.cpp
    /// @par Windows
    /// @image html domain_up_down_w.png
    /// <br>
    /// @image html domain_up_down_wd.png
    /// @par macOS
    /// @image html domain_up_down_m.png
    /// <br>
    /// @image html domain_up_down_md.png
    /// @par Gnome
    /// @image html domain_up_down_g.png
    /// <br>
    /// @image html domain_up_down_gd.png
    class forms_export_ domain_up_down : public up_down_base {
    public:
      /// @brief Represent an item contained in the domain_up_down::object_collection collection.
       class item {
       public:
         /// @brief Initializes a new instance of the item class.
         item() = default;
         /// @brief Initializes a new instance of the item class with specified value.
         /// @param value a string that represent the item.
         item(const std::string& value) : value_(value) {}
         /// @brief Initializes a new instance of the item class with specified value and tag.
         /// @param value a string that represent the item.
         /// @param tag an object that contains data about the item.
         item(const std::string& value, const std::any& tag) : value_(value), tag_(tag) {}
         /// @cond
         item(const char* value) : value_(value) {}
         item(const item& value) = default;
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
         /// @return A std::string that represent the value of item.
         virtual const std::string& value() const {return value_;}
         
         /// @brief Gets the tag of the item.
         /// @return A std::any that represent the tag of item.
         virtual std::any tag() const {return tag_;}
         
         /// @brief Returns a string containing the vakue of the item.
         /// @return A string containing the value of the item.
         std::string to_string() const {return value_;}

       private:
         std::string value_;
         std::any tag_;
       };
      
      /// @brief Represents the collection of items in a list_control.
      using object_collection = layout::arranged_element_collection<item>;

      /// @brief Initializes a new instance of the DomainUpDown class.
      domain_up_down();

      /// @brief Gets an object representing the collection of the items contained in this domain_up_down. Gets an object representing the collection of the items contained in this domain_up_down.
      /// @return A domain_up_down::object_collection representing the items in the domain_up_down.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the domain_up_down. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() {return items_;}
      /// @brief Gets an object representing the collection of the items contained in this domain_up_down. Gets an object representing the collection of the items contained in this domain_up_down.
      /// @return A domain_up_down::object_collection representing the items in the domain_up_down.
      const object_collection& items() const {return items_;}
      /// @brief Sets an object representing the collection of the items contained in this domain_up_down. Gets an object representing the collection of the items contained in this domain_up_down.
      /// @param items A domain_up_down::object_collection representing the items in the domain_up_down.
      /// @return Current domain_up_down.
      const domain_up_down& items(const object_collection& items) {
        items_ = items;
        return *this;
      }
      /// @brief Gets the zero-based index of the currently selected item.
      /// @return A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      virtual size_t selected_index() const {return selected_index_;}
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current domain_up_down.
      virtual domain_up_down& selected_index(size_t selected_index);
      
      /// @brief Gets the selected item based on the index value of the selected item in the collection.
      /// @return The selected item based on the selected_index value. The default value is item::empty.
      const item& selected_item() const {return selected_item_;}
      /// @brief Gets the selected item based on the index value of the selected item in the collection.
      /// @param item The selected item based on the selected_index value. The default value is item::empty.
      /// @return Current domain_up_down.
      domain_up_down& selected_item(const item& selected_item);

      /// @brief Gets a value indicating whether the collection of items continues to the first or last item if the user continues past the end of the list.
      /// @return true if the list starts again when the user reaches the beginning or end of the collection; otherwise, false. The default value is false.
      virtual bool wrap() {return wrap_;}
      /// @brief Sets a value indicating whether the collection of items continues to the first or last item if the user continues past the end of the list.
      /// @param value true if the list starts again when the user reaches the beginning or end of the collection; otherwise, false. The default value is false.
      /// @return Current domain_up_down.
      virtual domain_up_down& wrap(bool value);
      
      forms::create_params create_params() const override;
      
      /// @brief Occurs when the selected_item property has been changed.
      /// @ingroup events
      event<domain_up_down, event_handler> selected_item_changed;

      /// @brief Occurs when the value property has been changed.
      /// @ingroup events
      event<domain_up_down, event_handler> value_changed;

      /// @brief This is a special value equal to the maximum value representable by the type size_t.
      static const size_t npos = std::numeric_limits<size_t>::max();

    protected:
      drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().window();}
      
      drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().window_text();}
      
      drawing::size default_size() const override {return {150, 21};}

      void on_handle_created(const event_args& e) override;
      
      /// @brief Raises the domain_up_down::selected_item_changed event.
      /// @param e An event_args that contains the event data.
      virtual void on_selected_item_changed(const event_args& e);

      void on_text_changed(const event_args& e) override;
      
      /// @cond
      object_collection items_;
      size_t selected_index_ = npos;
      item selected_item_;
      bool wrap_ = false;
      /// @endcond
    };
  }
}
