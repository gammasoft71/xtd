/// @file
/// @brief Contains xtd::forms::choice control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.h"
#include "list_control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a choice control.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks A choice displays a text box combined with a list, which enables the user to select items from the list or enter a new value.
    /// @remarks To add or remove objects in the list at run time, use methods of the choice.object_collection class (through the items property of the choice). You can assign an array of object with the push_range method. The list then displays the default string value for each object. You can add individual objects with thepush method. You can delete items with the erase method or clear the entire list with the clear method.
    /// @remarks In addition to display and selection functionality, the choice also provides features that enable you to efficiently add items to the choice and to find text within the items of the list. With the begin_update and end_update methods, you can add a large number of items to the choice without the control being repainted each time an item is added to the list. The find_string and find_string_exact methods enable you to search for an item in the list that contains a specific search string.
    /// @remarks You can use these properties to manage the currently selected item in the list, the text property to specify the string displayed in the editing field, the selected_index property to get or set the current item, and the selected_item property to get or set a reference to the object.
    /// @par Examples
    /// The following code example demonstrate the use of choice control.
    /// @include choice.cpp
    /// @par Windows
    /// @image html choice_w.png
    /// <br>
    /// @image html choice_wd.png
    /// @par macOS
    /// @image html choice_m.png
    /// <br>
    /// @image html choice_md.png
    /// @par Gnome
    /// @image html choice_g.png
    /// <br>
    /// @image html choice_gd.png
    class forms_export_ choice : public list_control {
    public:
      /// @brief Initializes a new instance of the choice class.
      choice();

      virtual drawing::size default_size() const override {return {121, 23};}
      
      /// @brief Gets an object representing the collection of the items contained in this choice.
      /// @return A choice::object_collection representing the items in the choice.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the choice. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() {return items_;}
      /// @brief Gets an object representing the collection of the items contained in this choice.
      /// @return A choice::object_collection representing the items in the choice.
      const object_collection& items() const {return items_;}
      /// @brief Sets an object representing the collection of the items contained in this choice.
      /// @param items A choice::object_collection representing the items in the choice.
      const choice& items(const object_collection& items) {
        items_ = items;
        return *this;
      }
      
      using list_control::selected_index;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      list_control& selected_index(size_t selected_index) override;
      
      /// @brief Gets currently selected item in the choice.
      /// @return The object that is the currently selected item.
      const item& selected_item() const {return selected_item_;}
      /// @brief Sets currently selected item in the choice.
      /// @param selected_item The object that is the currently selected item.
      choice& selected_item(const item& selected_item);
      
      /// @brief Gets a value indicating whether the items in the choice are sorted.
      /// @return true if the choice is sorted; otherwise, false. The default is false.
      /// @remarks This property specifies whether the choice sorts existing entries and add new entries to the appropriate sorted position in the list. You can use this property to automatically sort items in a choice. As items are added to a sorted choice, the items are moved to the appropriate location in the sorted list. When you set the property to false, new items are added to the end of the existing list. The sort is case-insensitive and in alphabetically ascending order.
      virtual bool sorted() const {return sorted_;}
      /// @brief Sets a value indicating whether the items in the choice are sorted.
      /// @param sorted true if the choice is sorted; otherwise, false. The default is false.
      /// @remarks This property specifies whether the choice sorts existing entries and add new entries to the appropriate sorted position in the list. You can use this property to automatically sort items in a choice. As items are added to a sorted choice, the items are moved to the appropriate location in the sorted list. When you set the property to false, new items are added to the end of the existing list. The sort is case-insensitive and in alphabetically ascending order.
      virtual choice& sorted(bool sorted);
      
      using list_control::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      control& text(const xtd::ustring& text) override {return *this;}
      
      /// @brief Maintains performance while items are added to the choice one at a time by preventing the control from drawing until the EndUpdate() method is called.
      /// @remarks The preferred way to add multiple items to the choice is to use the push_back_range method of the choice::object_collection class (through the items property of the choice). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the choice::object_collection class, you can use the begin_update method to prevent the control from repainting the choice each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the choice to repaint. This way of adding items can prevent flickered drawing of the choice when a large number of items are being added to the list.
      void begin_update();
      /// @brief Resumes painting the choice control after painting is suspended by the begin_update method.
      /// @remarks The preferred way to add multiple items to the choice is to use the push_back_range method of the choice::object_collection class (through the items property of the choice). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the choice::object_collection class, you can use the begin_update method to prevent the control from repainting the choice each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the choice to repaint. This way of adding items can prevent flickered drawing of the choice when a large number of items are being added to the list.
      void end_update();

    protected:
      forms::create_params create_params() const override;
      
      void on_handle_created(const event_args& e) override;

      void on_selected_value_changed(const event_args& e) override;

      void set_bounds_core(int32_t x, int32_t y, int32_t width, int32_t height, bounds_specified specified) override;

      void set_client_size_core(int32_t width, int32_t height) override;
      
      void wnd_proc(message& message) override;
      
      /// @brief Processes the command message the choice control receives from the top-level window.
      /// @param message The message the top-level window sent to the choice control.
      virtual void wm_reflect_command(message& message);
      
      /// @brief Processes the mouse double-click message the choice control receives from the top-level window.
      /// @param message The message the top-level window sent to the choice control.
      virtual void wm_mouse_double_click(message& message);

      /// @brief Processes the mouse down message the choice control receives from the top-level window.
      /// @param message The message the top-level window sent to the choice control.
      virtual void wm_mouse_down(message& message);
      
      /// @brief Processes the mouse up message the choice control receives from the top-level window.
      /// @param message The message the top-level window sent to the choice control.
      virtual void wm_mouse_up(message& message);

      /// @cond
      object_collection items_;
      item selected_item_;
      bool sorted_ = false;
      bool user_set_size_ = false;
      /// @endcond
    };
  }
}
