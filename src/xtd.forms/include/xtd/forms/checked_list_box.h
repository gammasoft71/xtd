/// @file
/// @brief Contains xtd::forms::checked_list_box control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "item_check_event_handler.h"
#include "list_box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a list_box in which a check box is displayed to the left of each item.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks This control presents a list of items that the user can navigate by using the keyboard or the scrollbar on the right side of the control. The user can place a check mark by one or more items and the checked items can be navigated with the checked_list_box::checked_item_collection and checked_list_box::checked_index_collection.
    /// @remarks To add objects to the list at run time, assign an array of object with the push_range method. The list then displays the default string value for each object. You can add individual items to the list with the push method.
    /// @remarks The checked_list_box object supports three states through the check_state enumeration: checked, indeterminate, and unchecked. You must set the state of indeterminate in the code because the user interface for a checked_list_box does not provide a mechanism to do so.
    /// @remarks If use_tab_stops is true, the checked_list_box will recognize and expand tab characters in an item's text, creating columns. These tab stops are preset and cannot be changed. To use custom tab stops, set use_tab_stops to false, set use_custom_tab_offsets to true, and add the custom values to the custom_tab_offsets collection.
    /// @note If the use_compatible_text_rendering property is false, the custom_tab_offsets property will be ignored and replaced with standard tab offsets.
    /// @par Examples
    /// The following code example demonstrate the use of checked_list_box control.
    /// @include checked_list_box.cpp
    /// @par Windows
    /// @image html checked_list_box_w.png
    /// <br>
    /// @image html checked_list_box_wd.png
    /// @par macOS
    /// @image html checked_list_box_m.png
    /// <br>
    /// @image html checked_list_box_md.png
    /// @par Gnome
    /// @image html checked_list_box_g.png
    /// <br>
    /// @image html checked_list_box_gd.png
    class forms_export_ checked_list_box : public list_box {
    public:
      /// @brief Represent an item contained in the checked_list_box::object_collection.
      class item : public list_box::item {
      public:
        /// @brief Initializes a new instance of the item class.
        item() = default;
        /// @brief Initializes a new instance of the item class with specified value.
        /// @param value a string that represent the item.
        item(const std::string& value) : list_box::item(value) {}
        /// @brief Initializes a new instance of the item class with specified value and check state.
        /// @param value a string that represent the item.
        /// @param checked a bool that represent check state.
        item(const std::string& value, bool checked) : list_box::item(value), check_state_(checked ? forms::check_state::checked : forms::check_state::unchecked) {}
        /// @brief Initializes a new instance of the item class with specified value and checked state.
        /// @param value a string that represent the item.
        /// @param check_state a bool that represent check state.
        item(const std::string& value, forms::check_state check_state) : list_box::item(value), check_state_(check_state) {}
        /// @brief Initializes a new instance of the item class with specified value and tag.
        /// @param value a string that represent the item.
        /// @param tag an object that contains data about the item.
        item(const std::string& value, const std::any& tag) : list_box::item(value, tag) {}
        /// @brief Initializes a new instance of the item class with specified value, check state and tag.
        /// @param value a string that represent the item.
        /// @param checked a bool that represent check state.
        /// @param tag an object that contains data about the item.
        item(const std::string& value, bool checked, const std::any& tag) : list_box::item(value, tag), check_state_(checked ? forms::check_state::checked : forms::check_state::unchecked) {}
        /// @brief Initializes a new instance of the item class with specified value, check state and tag.
        /// @param value a string that represent the item.
        /// @param checked a bool that represent check state.
        /// @param tag an object that contains data about the item.
        item(const std::string& value, forms::check_state check_state, const std::any& tag) : list_box::item(value, tag), check_state_(check_state) {}
        /// @cond
        item(const char* value) : list_box::item(value) {}
        item(const item& value) = default;
        bool operator==(const item& value) const {return list_box::item::operator==(value);}
        bool operator!=(const item& value) const {return list_box::item::operator!=(value);}
        bool operator<(const item& value) const {return list_box::item::operator<(value);}
        bool operator<=(const item& value) const {return list_box::item::operator<=(value);}
        bool operator>(const item& value) const {return list_box::item::operator>(value);}
        bool operator>=(const item& value) const {return list_box::item::operator>=(value);}
        friend std::ostream& operator<<(std::ostream& os, const item& value) {return os << value.to_string();}
        /// @endcond

        /// @brief Gets a value indicating whether the item is in the checked state.
        /// @return true if the item is in the checked state; otherwise, false. The default value is false. If the three_state property is set to true, the checked property will return true for either a checked or indeterminate check_state.
        virtual bool checked() const {return check_state_ != forms::check_state::unchecked;}
        
        /// @brief Gets the state of the item.
        /// @return One of the check_state enumeration values. The default value is unchecked.
        /// @remarks If the three_state property is set to false, the check_state property value can only be set to check_state::indeterminate in code and not by u ser interaction.
        virtual forms::check_state check_state() const {return check_state_;}
        
      private:
        forms::check_state check_state_ = forms::check_state::unchecked;
      };
      
      /// @brief Represents the collection of items in a checked_list_box.
      using object_collection = layout::arranged_element_collection<item>;

      /// @brief Encapsulates the collection of indexes of checked items (including items in an indeterminate state)
      using checked_index_collection = std::vector<size_t>;

      /// @brief Encapsulates the collection of checked items, including items in an indeterminate state, in a checked_list_box control.
      using checked_item_collection = std::vector<item>;

      /// @brief Initializes a new instance of the checked_list_box class.
      /// @remarks By default, checked_list_box uses set_style and the resize_redraw value of control_styles to specify that the control is redrawn when resized.
      checked_list_box();
    
      /// @brief Collection of checked indexes in this checked_list_box.
      /// @return The checked_list_box::checked_index_collection collection for the checked_list_box.
      /// @remarks The collection of checked indexes is a subset of the indexes into the collection of all items in the checked_list_box control. These indexes specify items in a checked or indeterminate state.
      checked_index_collection checked_indices() const;
      
      /// @brief Collection of checked items in this checked_list_box.
      /// @return The checked_list_box::checked_item_collection collection for the checked_list_box.
      /// @remarks The collection is a subset of the objects in the items collection, representing only those items whose xtd::forms::check_state is checked or indeterminate. The indexes in this collection are in ascending order.
      checked_item_collection checked_items() const;
      
      object_collection& items() {return items_;}

      const object_collection& items() const {return items_;}
      
      const list_box& items(const object_collection& items) {
        items_ = items;
        return *this;
      }
      
      using list_box::selected_index;
      list_control& selected_index(size_t selected_index) override;
      
      std::vector<size_t> selected_indices() const override;
      
      const item& selected_item() const {return selected_item_;}
      
      list_box& selected_item(const item& selected_item);
      
      std::vector<item> selected_items() const;
      
      using list_box::text;
      control& text(const std::string& text) override {
        selected_item_ = {text};
        return *this;
      }
  
      void begin_update();
      void end_update();

      bool get_item_checked(size_t index) const;
      
      forms::check_state get_item_check_state(size_t index) const;

      const std::string& get_item_text(size_t index) const;

      void set_item_checked(size_t index, bool checked);

      void set_item_check_state(size_t index, forms::check_state check_state);

      void set_item_text(size_t index, const std::string& text);
      
      event<checked_list_box, item_check_event_handler<control&>> item_check;

    protected:
      bool allow_selection() override {return selection_mode_ != forms::selection_mode::none;}

      forms::create_params create_params() const override;

      void on_handle_created(const event_args& e) override;
      
      virtual void on_item_check(item_check_event_args& e) {item_check(*this, e);}
      
      void on_selected_value_changed(const event_args& e) override;

      void wnd_proc(message& message) override;
      
      void wm_reflect_command(message& message) override;
      
      void wm_mouse_double_click(message& message) override;

      void wm_mouse_down(message& message) override;
      
      void wm_mouse_up(message& message) override;
      
      object_collection items_;
      item selected_item_;
    };
  }
}
