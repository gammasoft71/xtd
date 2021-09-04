/// @file
/// @brief Contains xtd::forms::list_box control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.h"
#include "border_style.h"
#include "list_control.h"
#include "selection_mode.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows list box.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrate the use of list_box control.
    /// @include list_box.cpp
    class forms_export_ list_box : public list_control {
    public:
      /// @brief Represents the collection containing the indexes to the selected items in a list_box.
      using selected_index_collection = std::vector<size_t>;
      
      /// @brief Represents the collection of selected items in the list_box.
      using selected_object_collection = std::vector<item>;
      
      /// @brief Initializes a new instance of the list_box class.
      list_box();

      /// @brief Gets the type of border that is drawn around the list_box.
      /// @return One of the xtd::forms::border_styleforms::border_style values. The default is fixed_single.
      virtual forms::border_style border_style() const {return border_style_;}
      /// @brief Sets the type of border that is drawn around the list_box.
      /// @param border_style One of the xtd::forms::border_styleforms::border_style values. The default is fixed_single.
      /// @return Current list_box.
      virtual list_box& border_style(forms::border_style border_style);
      
      drawing::color default_back_color() const override {return xtd::forms::theme_colors::current_theme().window();}
      
      drawing::color default_fore_color() const override {return xtd::forms::theme_colors::current_theme().window_text();}
      
      drawing::size default_size() const override {return {120, 96};}
      
      /// @brief Gets the items of the list_box.
      /// @return An list_boxlist_box::object_collection representing the items in the list_box.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the list_box. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() {return items_;}
      /// @brief Gets the items of the list_box.
      /// @return An list_boxlist_box::object_collection representing the items in the list_box.
      const object_collection& items() const {return items_;}
      /// @brief Sets the items of the list_box.
      /// @param items An list_boxlist_box::object_collection representing the items in the list_box.
      /// @return Current list_box.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the list_box. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      const list_box& items(const object_collection& items) {
        items_ = items;
        return *this;
      }
      
      using list_control::selected_index;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current list_control.
      list_control& selected_index(size_t selected_index) override;
      
      /// @brief Gets a collection that contains the zero-based indexes of all currently selected items in the list_box.
      /// @brief A list_box.selected_index_collection containing the indexes of the currently selected items in the control. If no items are currently selected, an empty ListBox.SelectedIndexCollection is returned.
      /// @remarks For a multiple-selection list_box, this property returns a collection containing the indexes to all items that are selected in the list_box. For a single-selection ListBox, this property returns a collection containing a single element containing the index of the only selected item in the list_box. For more information about how to manipulate the items of the collection, see list_box::selected_index_collection.
      /// @remarks The list_box class provides a number of ways to reference selected items. Instead of using the selected_indices property to obtain the index position of the currently selected item in a single-selection list_box, you can use the selected_index property. If you want to obtain the item that is currently selected in the list_box, instead of the index position of the item, use the delected_item property. In addition, you can use the selected_items property if you want to obtain all the selected items in a multiple-selection list_box.
      virtual selected_index_collection selected_indices() const;

      /// @brief Gets the currently selected item in the list_box.
      /// @return An object that represents the current selection in the control.
      /// @remarks For a standard list_box, you can use this property to determine which item is selected in the list_box. If the selection_mode property of the list_boxlist_box is set to either selection_mode::multi_simple or selection_mode::multi_extended (which indicates a multiple-selection list_box) and multiple items are selected in the list, this property can return any selected item.
      /// @remarks To retrieve a collection containing all selected items in a multiple-selection list_box, use the selected_items property. If you want to obtain the index position of the currently selected item in the list_box, use the selected_index property. In addition, you can use the selected_indices property to obtain all the selected indexes in a multiple-selection list_box.
      const item& selected_item() const {return selected_item_;}
      /// @brief Sets the currently selected item in the list_box.
      /// @param selected_item An object that represents the current selection in the control.
      /// @return Current list_box.
      /// @remarks For a standard list_box, you can use this property to determine which item is selected in the list_box. If the selection_mode property of the list_boxlist_box is set to either selection_mode::multi_simple or selection_mode::multi_extended (which indicates a multiple-selection list_box) and multiple items are selected in the list, this property can return any selected item.
      /// @remarks To retrieve a collection containing all selected items in a multiple-selection list_box, use the selected_items property. If you want to obtain the index position of the currently selected item in the list_box, use the selected_index property. In addition, you can use the selected_indices property to obtain all the selected indexes in a multiple-selection list_box.
      list_box& selected_item(const item& selected_item);
      
      /// @brief Gets a collection containing the currently selected items in the list_box.
      /// @return A list_box::selected_object_collection containing the currently selected items in the control.
      /// @remarks For a multiple-selection list_box, this property returns a collection containing all items that are selected in the list_box. For a single-selection list_box, this property returns a collection containing a single element containing the only selected item in the list_box. For more information about how to manipulate the items of the collection, see list_box::selected_object_collection.
      /// @remarks The list_box class provides a number of ways to reference selected items. Instead of using the selected_items property to obtain the currently selected item in a single-selection list_box, you can use the selected_item property. If you want to obtain the index position of an item that is currently selected in the list_box, instead of the item itself, use the selected_index property. In addition, you can use the selected_indices property if you want to obtain the index positions of all selected items in a multiple-selection list_box.
      selected_object_collection selected_items() const;
      
      /// @brief Gets the method in which items are selected in the list_box.
      /// @return One of the selection_mode values. The default is selection_mode::one.
      /// @remarks The selection_mode property enables you to determine how many items in the list_box a user can select at one time and how the user can make multiple-selections. When the selection_mode property is set to selection_mode::multi_extended, pressing SHIFT and clicking the mouse or pressing SHIFT and one of the arrow keys (UP ARROW, DOWN ARROW, LEFT ARROW, and RIGHT ARROW) extends the selection from the previously selected item to the current item. Pressing CTRL and clicking the mouse selects or deselects an item in the list. When the property is set to selection_mode::multi_simple, a mouse click or pressing the SPACEBAR selects or deselects an item in the list.
      virtual forms::selection_mode selection_mode() const {return selection_mode_;}
      /// @brief Sets the method in which items are selected in the list_box.
      /// @param selection_mode One of the selection_mode values. The default is selection_mode::one.
      /// @return Current list_box.
      /// @remarks The selection_mode property enables you to determine how many items in the list_box a user can select at one time and how the user can make multiple-selections. When the selection_mode property is set to selection_mode::multi_extended, pressing SHIFT and clicking the mouse or pressing SHIFT and one of the arrow keys (UP ARROW, DOWN ARROW, LEFT ARROW, and RIGHT ARROW) extends the selection from the previously selected item to the current item. Pressing CTRL and clicking the mouse selects or deselects an item in the list. When the property is set to selection_mode::multi_simple, a mouse click or pressing the SPACEBAR selects or deselects an item in the list.
      virtual list_box& selection_mode(forms::selection_mode selection_mode);

      /// @brief Gets a value indicating whether the items in the list_box are sorted alphabetically.
      /// @return true if items in the control are sorted; otherwise, false. The default is false.
      /// @remarks Use the sorted property to automatically sort strings alphabetically in a list_box. As items are added to a sorted list_box, the items are moved to the appropriate location in the sorted list. When adding items to a list_box, it is more efficient to sort the items first and then add new items.
      virtual bool sorted() const {return sorted_;}
      /// @brief Sets a value indicating whether the items in the list_box are sorted alphabetically.
      /// @param sorted true if items in the control are sorted; otherwise, false. The default is false.
      /// @return Current list_box.
      /// @remarks Use the sorted property to automatically sort strings alphabetically in a list_box. As items are added to a sorted list_box, the items are moved to the appropriate location in the sorted list. When adding items to a list_box, it is more efficient to sort the items first and then add new items.
      virtual list_box& sorted(bool sorted);
      
      using list_control::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      control& text(const xtd::ustring& text) override {return *this;}

      /// @brief Maintains performance while items are added to the list_box one at a time by preventing the control from drawing until the EndUpdate() method is called.
      /// @remarks The preferred way to add multiple items to the list_box is to use the push_back_range method of the list_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void begin_update();
      /// @brief Resumes painting the list_box control after painting is suspended by the begin_update method.
      /// @remarks The preferred way to add multiple items to the list_box is to use the push_back_range method of the list_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void end_update();
      
    protected:
      bool allow_selection() override {return selection_mode_ != forms::selection_mode::none;}

      forms::create_params create_params() const override;

      void on_handle_created(const event_args& e) override;
      
      void on_selected_value_changed(const event_args& e) override;

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
      forms::border_style border_style_ = forms::border_style::fixed_single;
      object_collection items_;
      item selected_item_;
      forms::selection_mode selection_mode_ = forms::selection_mode::one;
      bool sorted_ = false;
      /// @endcond
    };
  }
}
