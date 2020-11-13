#pragma once
#include "item_check_event_handler.h"
#include "list_box.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a list_box in which a check box is displayed to the left of each item.
    /// @remarks This control presents a list of items that the user can navigate by using the keyboard or the scrollbar on the right side of the control. The user can place a check mark by one or more items and the checked items can be navigated with the checked_list_box::checked_item_collection and checked_list_box::checked_index_collection.
    /// @remarks To add objects to the list at run time, assign an array of object with the push_range method. The list then displays the default string value for each object. You can add individual items to the list with the push method.
    /// @remarks The checked_list_box object supports three states through the check_state enumeration: checked, indeterminate, and unchecked. You must set the state of indeterminate in the code because the user interface for a checked_list_box does not provide a mechanism to do so.
    /// @remarks If use_tab_stops is true, the checked_list_box will recognize and expand tab characters in an item's text, creating columns. These tab stops are preset and cannot be changed. To use custom tab stops, set use_tab_stops to false, set use_custom_tab_offsets to true, and add the custom values to the custom_tab_offsets collection.
    /// @note If the use_compatible_text_rendering property is false, the custom_tab_offsets property will be ignored and replaced with standard tab offsets.
    class checked_list_box : public list_box {
    public:
      class item : public list_box::item {
      public:
        item() = default;
        item(const std::string& value) : list_box::item(value) {}
        item(const std::string& value, bool checked) : list_box::item(value), check_state_(checked ? forms::check_state::checked : forms::check_state::unchecked) {}
        item(const std::string& value, forms::check_state check_state) : list_box::item(value), check_state_(check_state) {}
        item(const std::string& value, const std::any& tag) : list_box::item(value, tag) {}
        item(const std::string& value, bool checked, const std::any& tag) : list_box::item(value, tag), check_state_(checked ? forms::check_state::checked : forms::check_state::unchecked) {}
        item(const std::string& value, forms::check_state check_state, const std::any& tag) : list_box::item(value, tag), check_state_(check_state) {}
        /// @cond
        item(const char* value) : list_box::item(value) {}
        item(const item& value) = default;
        bool operator==(const item& value) const {return this->list_box::item::operator==(value);}
        bool operator!=(const item& value) const {return this->list_box::item::operator!=(value);}
        bool operator<(const item& value) const {return this->list_box::item::operator<(value);}
        bool operator<=(const item& value) const {return this->list_box::item::operator<=(value);}
        bool operator>(const item& value) const {return this->list_box::item::operator>(value);}
        bool operator>=(const item& value) const {return this->list_box::item::operator>=(value);}
        /// @endcond

        virtual bool checked() const {return this->check_state_ != forms::check_state::unchecked;}
        
        virtual forms::check_state check_state() const {return this->check_state_;}
        
        friend std::ostream& operator<<(std::ostream& os, const item& value) {return os << value.to_string();}

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
      
      checked_item_collection checked_items() const;
      
      object_collection& items() {return this->items_;}

      const object_collection& items() const {return this->items_;}
      
      const list_box& items(const object_collection& items) {
        this->items_ = items;
        return *this;
      }
      
      using list_box::selected_index;
      list_control& selected_index(size_t selected_index) override;
      
      std::vector<size_t> selected_indices() const override;
      
      const item& selected_item() const {return this->selected_item_;}
      
      list_box& selected_item(const item& selected_item);
      
      std::vector<item> selected_items() const;
      
      using list_box::text;
      control& text(const std::string& text) override {
        this->selected_item_ = {text};
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
      bool allow_selection() override {return this->selection_mode_ != forms::selection_mode::none;}

      forms::create_params create_params() const override;

      void on_handle_created(const event_args& e) override;
      
      virtual void on_item_check(item_check_event_args& e) {this->item_check(*this, e);}
      
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
