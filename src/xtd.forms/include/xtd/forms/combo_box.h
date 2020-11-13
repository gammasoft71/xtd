#pragma once
#include "layout/arranged_element_collection.h"
#include "combo_box_style.h"
#include "list_control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows combo box control.
    /// @remarks A combo_box displays a text box combined with a list_box, which enables the user to select items from the list or enter a new value.
    /// @remarks The drop_down_style property specifies whether the list is always displayed or whether the list is displayed in a drop-down. The drop_down_style property also specifies whether the text portion can be edited. See combo_box_style for the available settings and their effects. There is no setting to always display the list and disallow entering a new value. To display a list to which no new values can be added, use a list_box control.
    /// @remarks To add or remove objects in the list at run time, use methods of the combo_box.object_collection class (through the items property of the combo_box). You can assign an array of object with the push_range method. The list then displays the default string value for each object. You can add individual objects with thepush method. You can delete items with the erase method or clear the entire list with the clear method.
    /// @remarks In addition to display and selection functionality, the combo_box also provides features that enable you to efficiently add items to the combo_box and to find text within the items of the list. With the begin_update and end_update methods, you can add a large number of items to the combo_box without the control being repainted each time an item is added to the list. The find_string and find_string_exact methods enable you to search for an item in the list that contains a specific search string.
    /// @remarks You can use these properties to manage the currently selected item in the list, the text property to specify the string displayed in the editing field, the selected_index property to get or set the current item, and the selected_item property to get or set a reference to the object.
    class combo_box : public list_control {
    public:
      /// @brief Initializes a new instance of the combo_box class.
      combo_box();

      virtual drawing::size default_size() const override {return {121, 23};}
      
      combo_box_style drop_down_style() const {return this->drop_down_style_;}
      combo_box& drop_down_style(combo_box_style drop_down_style);
      
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
      
      void begin_update();
      void end_update();

      event<combo_box, event_handler<control&>> drop_down_style_changed;
      
    protected:
      /// @remarks Gets the required creation parameters when the control handle is created.
      /// @return A create_params that contains the required creation parameters when the handle to the control is created.
      forms::create_params create_params() const override;
      
      virtual void on_drop_down_style_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;

      void on_selected_value_changed(const event_args& e) override;

      void set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) override;

      void set_client_size_core(int32_t width, int32_t height) override;
      
      void wnd_proc(message& message) override;
      
      virtual void wm_reflect_command(message& message);
      
      virtual void wm_mouse_double_click(message& message);

      virtual void wm_mouse_down(message& message);
      
      virtual void wm_mouse_up(message& message);
      
      int32_t drop_down_height_ = 0;
      combo_box_style drop_down_style_ = combo_box_style::drop_down;
      int32_t drop_down_width_ = 0;
      item_collection items_;
      item selected_item_;
      bool sorted_ = false;
      bool user_set_size_ = false;
    };
  }
}
