/// @file
/// @brief Contains xtd::forms::combo_box control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.h"
#include "combo_box_style.h"
#include "list_control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows combo box control.
    /// @par Header
    /// @code #include <xtd/forms/combo_box> @endcode
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
    /// @par Appearance
    /// |       | Windows                                | macOS                                  | Gnome                                  |
    /// | ----- | -------------------------------------- | -------------------------------------- | -------------------------------------- |
    /// | Light |  @image html control_combo_box_w.png   |  @image html control_combo_box_m.png   |  @image html control_combo_box_g.png   |
    /// | Dark  |  @image html control_combo_box_wd.png  |  @image html control_combo_box_md.png  |  @image html control_combo_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of combo box control.
    /// @include combo_box.cpp
    class forms_export_ combo_box : public list_control {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the combo_box class.
      combo_box();
      /// @}
      
      /// @name Porperties
      
      /// @{
      /// @brief Gets a value indicating whether the combo box is displaying its drop-down portion.
      /// @return true if the drop-down portion is displayed; otherwise, false. The default is false.
      bool dropped_down() const noexcept;
      /// @brief Sets a value indicating whether the combo box is displaying its drop-down portion.
      /// @param value true if the drop-down portion is displayed; otherwise, false. The default is false.
      /// @warning This feature is not supported on macOS.
      combo_box& dropped_down(bool value);
      
      /// @brief Gets a value specifying the style of the combo box.
      /// @return One of the combo_box_style values. The default is drop_down.
      /// @remarks The drop_down_style property specifies whether the list is always displayed or whether the list is displayed in a drop-down. The drop_down_style property also specifies whether the text portion can be edited. See combo_box_style for the available settings and their effects. There is no setting to always display the list and disallow entering a new value. To display a list to which no new values can be added, use a list_box control.
      combo_box_style drop_down_style() const noexcept;
      /// @brief Sets a value specifying the style of the combo box.
      /// @param droop_down_style One of the combo_box_style values. The default is drop_down.
      /// @remarks The drop_down_style property specifies whether the list is always displayed or whether the list is displayed in a drop-down. The drop_down_style property also specifies whether the text portion can be edited. See combo_box_style for the available settings and their effects. There is no setting to always display the list and disallow entering a new value. To display a list to which no new values can be added, use a list_box control.
      combo_box& drop_down_style(combo_box_style drop_down_style);
      
      /// @brief Gets an object representing the collection of the items contained in this combo_box. Gets an object representing the collection of the items contained in this combo_box.
      /// @return A combo_box::object_collection representing the items in the combo_box.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the combo_box. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() noexcept;
      /// @brief Gets an object representing the collection of the items contained in this combo_box. Gets an object representing the collection of the items contained in this combo_box.
      /// @return A combo_box::object_collection representing the items in the combo_box.
      const object_collection& items() const noexcept;
      /// @brief Sets an object representing the collection of the items contained in this combo_box. Gets an object representing the collection of the items contained in this combo_box.
      /// @param items A combo_box::object_collection representing the items in the combo_box.
      /// @return This instance of combo_box.
      const combo_box& items(const object_collection& items);
      
      using list_control::selected_index;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current list_control.
      list_control& selected_index(size_t selected_index) override;
      
      /// @brief Gets currently selected item in the combo_box.
      /// @return An object that represents the current selection in the control.
      const item& selected_item() const noexcept;
      /// @brief Sets currently selected item in the combo_box.
      /// @param selected_item An object that represents the current selection in the control.
      /// @return Current combo_box.
      combo_box& selected_item(const item& selected_item);
      
      /// @brief Gets a value indicating whether the items in the combo_box are sorted alphabetically.
      /// @return true if items in the control are sorted; otherwise, false. The default is false.
      /// @remarks Use the sorted property to automatically sort strings alphabetically in a combo_box. As items are added to a sorted combo_box, the items are moved to the appropriate location in the sorted list. When adding items to a list_box, it is more efficient to sort the items first and then add new items.
      virtual bool sorted() const noexcept;
      /// @brief Sets a value indicating whether the items in the combo_box are sorted alphabetically.
      /// @param sorted true if items in the control are sorted; otherwise, false. The default is false.
      /// @return Current combo_box.
      /// @remarks Use the sorted property to automatically sort strings alphabetically in a combo_box. As items are added to a sorted combo_box, the items are moved to the appropriate location in the sorted list. When adding items to a list_box, it is more efficient to sort the items first and then add new items.
      virtual combo_box& sorted(bool sorted);
      
      using list_control::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      control& text(const xtd::ustring& text) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Maintains performance while items are added to the combo_box one at a time by preventing the control from drawing until the EndUpdate() method is called.
      /// @remarks The preferred way to add multiple items to the combo_box is to use the push_back_range method of the combo_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void begin_update();
      
      using control::create;
      /// @brief A factory to create an xtd::forms::combo_box with specified items, selected_index, location ,size, and name.
      /// @param items A choice::object_collection representing the items in the combo_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::combo_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::combo_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::combo_box.
      /// @return New xtd::forms::combo_box created.
      static combo_box create(const object_collection& items, size_t selected_index = object_collection::npos, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::combo_box with specified parent, items, selected_index, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::combo_box.
      /// @param items A choice::object_collection representing the items in the combo_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::combo_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::combo_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::combo_box.
      /// @return New xtd::forms::combo_box created.
      static combo_box create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      
      /// @brief Resumes painting the combo_box control after painting is suspended by the begin_update method.
      /// @remarks The preferred way to add multiple items to the combo_box is to use the push_back_range method of the combo_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void end_update();
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the drop-down portion of a xtd::forms::combo_box is shown.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<combo_box, event_handler> drop_down;
      /// @brief Occurs when the drop-down portion of the xtd::forms::combo_box is no longer visible.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<combo_box, event_handler> drop_down_closed;
      /// @brief Occurs when the drop_down_style property has changed.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<combo_box, event_handler> drop_down_style_changed;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      /// @brief Raises the xtd::forms::combo_box::drop_down event.
      /// @remarks This event is raised each time the drop-down is displayed.
      /// @remarks Raising an event invokes the event handler through a delegate. For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      /// @remarks The xtd::forms::combo_box::on_drop_down method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_drop_down(const event_args& e);
      
      /// @brief Raises the xtd::forms::combo_box::drop_down_closed event.
      /// @remarks Raising an event invokes the event handler through a delegate. For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      /// @remarksThe xtd::forms::combo_box::on_drop_down_closed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_drop_down_closed(const event_args& e);
      
      /// @brief Raises the xtd::forms::combo_box::drop_down_style_changed event.
      /// @remarks This event is raised when you set xtd::forms::combo_box::drop_down_style to a new value.
      /// @remarks Raising an event invokes the event handler through a delegate. For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      /// @remarks The xtd::forms::combo_box::on_drop_down_style_changed method also allows derived classes to handle the event without attaching a delegate. This is the preferred technique for handling the event in a derived class.
      virtual void on_drop_down_style_changed(const event_args& e);
      
      void on_handle_created(const event_args& e) override;
      void on_selected_value_changed(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void wm_command_control(message& message);
      void wm_command_control_selchange(message& message);
      void wm_mouse_double_click(message& message);
      void wm_mouse_down(message& message);
      void wm_mouse_up(message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}
