/// @file
/// @brief Contains xtd::forms::combo_box control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.h"
#include "combo_box_style.h"
#include "list_control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows combo box control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks A combo_box displays a text box combined with a list_box, which enables the user to select items from the list or enter a new value.
    /// @remarks The drop_down_style property specifies whether the list is always displayed or whether the list is displayed in a drop-down. The drop_down_style property also specifies whether the text portion can be edited. See combo_box_style for the available settings and their effects. There is no setting to always display the list and disallow entering a new value. To display a list to which no new values can be added, use a list_box control.
    /// @remarks To add or remove objects in the list at run time, use methods of the combo_box.object_collection class (through the items property of the combo_box). You can assign an array of object with the push_range method. The list then displays the default string value for each object. You can add individual objects with the push method. You can delete items with the erase method or clear the entire list with the clear method.
    /// @remarks In addition to display and selection functionality, the combo_box also provides features that enable you to efficiently add items to the combo_box and to find text within the items of the list. With the begin_update and end_update methods, you can add a large number of items to the combo_box without the control being repainted each time an item is added to the list. The find_string and find_string_exact methods enable you to search for an item in the list that contains a specific search string.
    /// @remarks You can use these properties to manage the currently selected item in the list, the text property to specify the string displayed in the editing field, the selected_index property to get or set the current item, and the selected_item property to get or set a reference to the object.
    /// @par Examples
    /// The following code example demonstrate the use of combo box control.
    /// @include combo_box.cpp
    class forms_export_ combo_box : public list_control {
    public:
      /// @brief Initializes a new instance of the combo_box class.
      combo_box();

      virtual drawing::size default_size() const override {return {121, 23};}
      
      /// @brief Gets a value specifying the style of the combo box.
      /// @return One of the combo_box_style values. The default is drop_down.
      /// @remarks The drop_down_style property specifies whether the list is always displayed or whether the list is displayed in a drop-down. The drop_down_style property also specifies whether the text portion can be edited. See combo_box_style for the available settings and their effects. There is no setting to always display the list and disallow entering a new value. To display a list to which no new values can be added, use a list_box control.
      combo_box_style drop_down_style() const {return drop_down_style_;}
      /// @brief Sets a value specifying the style of the combo box.
      /// @param droop_down_style One of the combo_box_style values. The default is drop_down.
      /// @remarks The drop_down_style property specifies whether the list is always displayed or whether the list is displayed in a drop-down. The drop_down_style property also specifies whether the text portion can be edited. See combo_box_style for the available settings and their effects. There is no setting to always display the list and disallow entering a new value. To display a list to which no new values can be added, use a list_box control.
      combo_box& drop_down_style(combo_box_style drop_down_style);
      
      /// @brief Gets an object representing the collection of the items contained in this combo_box. Gets an object representing the collection of the items contained in this combo_box.
      /// @return A combo_box::object_collection representing the items in the combo_box.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the combo_box. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() {return items_;}
      /// @brief Gets an object representing the collection of the items contained in this combo_box. Gets an object representing the collection of the items contained in this combo_box.
      /// @return A combo_box::object_collection representing the items in the combo_box.
      const object_collection& items() const {return items_;}
      /// @brief Sets an object representing the collection of the items contained in this combo_box. Gets an object representing the collection of the items contained in this combo_box.
      /// @param items A combo_box::object_collection representing the items in the combo_box.
      /// @return This instance of combo_box.
      const combo_box& items(const object_collection& items) {
        items_ = items;
        return *this;
      }
      
      using list_control::selected_index;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current list_control.
      list_control& selected_index(size_t selected_index) override;
      
      /// @brief Gets currently selected item in the combo_box.
      /// @return An object that represents the current selection in the control.
      const item& selected_item() const {return selected_item_;}
      /// @brief Sets currently selected item in the combo_box.
      /// @param selected_item An object that represents the current selection in the control.
      /// @return Current combo_box.
      combo_box& selected_item(const item& selected_item);
      
      /// @brief Gets a value indicating whether the items in the combo_box are sorted alphabetically.
      /// @return true if items in the control are sorted; otherwise, false. The default is false.
      /// @remarks Use the sorted property to automatically sort strings alphabetically in a combo_box. As items are added to a sorted combo_box, the items are moved to the appropriate location in the sorted list. When adding items to a list_box, it is more efficient to sort the items first and then add new items.
      virtual bool sorted() const {return sorted_;}
      /// @brief Sets a value indicating whether the items in the combo_box are sorted alphabetically.
      /// @param sorted true if items in the control are sorted; otherwise, false. The default is false.
      /// @return Current combo_box.
      /// @remarks Use the sorted property to automatically sort strings alphabetically in a combo_box. As items are added to a sorted combo_box, the items are moved to the appropriate location in the sorted list. When adding items to a list_box, it is more efficient to sort the items first and then add new items.
      virtual combo_box& sorted(bool sorted);
      
      using list_control::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      control& text(const xtd::ustring& text) override {return *this;}
      
      /// @brief Maintains performance while items are added to the combo_box one at a time by preventing the control from drawing until the EndUpdate() method is called.
      /// @remarks The preferred way to add multiple items to the combo_box is to use the push_back_range method of the combo_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void begin_update();
      /// @brief Resumes painting the combo_box control after painting is suspended by the begin_update method.
      /// @remarks The preferred way to add multiple items to the combo_box is to use the push_back_range method of the combo_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void end_update();

      /// @brief Occurs when the drop_down_style property has changed.
      /// @ingroup events
      event<combo_box, event_handler> drop_down_style_changed;
      
    protected:
      forms::create_params create_params() const override;

      /// @brief Raises the combo_box::drop_down_style_changed event.
      virtual void on_drop_down_style_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;

      void on_selected_value_changed(const event_args& e) override;

      void set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) override;

      void set_client_size_core(int32_t width, int32_t height) override;
      
      void wnd_proc(message& message) override;
      
      /// @brief Processes the command message the list_box control receives from the top-level window.
      /// @param message The message the top-level window sent to the list_box control.
      virtual void wm_reflect_command(message& message);
      
      /// @brief Processes the mouse double-click message the list_box control receives from the top-level window.
      /// @param message The message the top-level window sent to the list_box control.
      virtual void wm_mouse_double_click(message& message);

      /// @brief Processes the mouse down message the list_box control receives from the top-level window.
      /// @param message The message the top-level window sent to the list_box control.
      virtual void wm_mouse_down(message& message);
      
      /// @brief Processes the mouse up message the list_box control receives from the top-level window.
      /// @param message The message the top-level window sent to the list_box control.
      virtual void wm_mouse_up(message& message);
      
      /// @cond
      int32_t drop_down_height_ = 0;
      combo_box_style drop_down_style_ = combo_box_style::drop_down;
      int32_t drop_down_width_ = 0;
      object_collection items_;
      item selected_item_;
      bool sorted_ = false;
      bool user_set_size_ = false;
      /// @endcond
    };
  }
}
