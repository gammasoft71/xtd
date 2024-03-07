/// @file
/// @brief Contains xtd::forms::checked_list_box control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "item_check_event_handler.h"
#include "list_box.h"
#include <xtd/iequatable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Displays a xtd::forms::list_box in which a check box is displayed to the left of each item.
    /// @par Header
    /// @code #include <xtd/forms/checked_list_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks This control presents a list of items that the user can navigate by using the keyboard or the scrollbar on the right side of the control. The user can place a check mark by one or more items and the checked items can be navigated with the checked_list_box::checked_item_collection and checked_list_box::checked_index_collection.
    /// @remarks To add objects to the list at run time, assign an array of object with the push_range method. The list then displays the default string value for each object. You can add individual items to the list with the push method.
    /// @remarks The checked_list_box object supports three states through the check_state enumeration: checked, indeterminate, and unchecked. You must set the state of indeterminate in the code because the user interface for a checked_list_box does not provide a mechanism to do so.
    /// @remarks If use_tab_stops is true, the checked_list_box will recognize and expand tab characters in an item's text, creating columns. These tab stops are preset and cannot be changed. To use custom tab stops, set use_tab_stops to false, set use_custom_tab_offsets to true, and add the custom values to the custom_tab_offsets collection.
    /// @note If the use_compatible_text_rendering property is false, the custom_tab_offsets property will be ignored and replaced with standard tab offsets.
    /// @par Appearance
    /// |       | Windows                                       | macOS                                         | Gnome                                         |
    /// | ----- | --------------------------------------------- | --------------------------------------------- | --------------------------------------------- |
    /// | Light |  @image html control_checked_list_box_w.png   |  @image html control_checked_list_box_m.png   |  @image html control_checked_list_box_g.png   |
    /// | Dark  |  @image html control_checked_list_box_wd.png  |  @image html control_checked_list_box_md.png  |  @image html control_checked_list_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of checked_list_box control.
    /// @include checked_list_box.cpp
    class forms_export_ checked_list_box : public list_box {
      struct data;
      
    public:
      /// @brief Represent an item contained in the checked_list_box::object_collection collection.
      class item : public list_box::item, public xtd::icomparable<item>, public xtd::iequatable<item> {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the item class.
        item() = default;
        /// @brief Initializes a new instance of the item class with specified value.
        /// @param value a string that represent the item.
        item(const xtd::ustring& value); // Can't be explicit by design.
        /// @brief Initializes a new instance of the item class with specified value and check state.
        /// @param value a string that represent the item.
        /// @param checked a bool that represent check state.
        item(const xtd::ustring& value, bool checked);
        /// @brief Initializes a new instance of the item class with specified value and checked state.
        /// @param value a string that represent the item.
        /// @param check_state a bool that represent check state.
        item(const xtd::ustring& value, forms::check_state check_state);
        /// @brief Initializes a new instance of the item class with specified value and tag.
        /// @param value a string that represent the item.
        /// @param tag an object that contains data about the item.
        item(const xtd::ustring& value, const std::any& tag);
        /// @brief Initializes a new instance of the item class with specified value, check state and tag.
        /// @param value a string that represent the item.
        /// @param checked a bool that represent check state.
        /// @param tag an object that contains data about the item.
        item(const xtd::ustring& value, bool checked, const std::any& tag);
        /// @brief Initializes a new instance of the item class with specified value, check state and tag.
        /// @param value a string that represent the item.
        /// @param checked a bool that represent check state.
        /// @param tag an object that contains data about the item.
        item(const xtd::ustring& value, forms::check_state check_state, const std::any& tag);
        /// @}
        
        /// @cond
        item(const char* value); // Can't be explicit by design.
        item(const item& value) = default;
        item& operator =(const item& value) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets a value indicating whether the item is in the checked state.
        /// @return true if the item is in the checked state; otherwise, false. The default value is false. If the three_state property is set to true, the checked property will return true for either a checked or indeterminate check_state.
        virtual bool checked() const;
        
        /// @brief Gets the state of the item.
        /// @return One of the check_state enumeration values. The default value is unchecked.
        /// @remarks If the three_state property is set to false, the check_state property value can only be set to check_state::indeterminate in code and not by u ser interaction.
        virtual forms::check_state check_state() const;
        /// @}
        
        /// @name Methods
        
        /// @{
        using list_box::item::compare_to;
        int32 compare_to(const item& value) const noexcept override;
        using list_box::item::equals;
        bool equals(const item& value) const noexcept override;
        /// @}
        
      private:
        forms::check_state check_state_ = forms::check_state::unchecked;
      };
      
      /// @name Aliases
      
      /// @{
      /// @brief Represents the collection of items in a checked_list_box.
      using object_collection = layout::arranged_element_collection<item>;
      
      /// @brief Encapsulates the collection of indexes of checked items (including items in an indeterminate state)
      using checked_index_collection = std::vector<size_t>;
      
      /// @brief Encapsulates the collection of checked items, including items in an indeterminate state, in a checked_list_box control.
      using checked_item_collection = std::vector<item>;
      
      /// @brief Represents the collection of selected items in the list_box.
      using selected_object_collection = std::vector<item>;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the checked_list_box class.
      /// @remarks By default, checked_list_box uses set_style and the resize_redraw value of control_styles to specify that the control is redrawn when resized.
      checked_list_box();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Collection of checked indexes in this checked_list_box.
      /// @return The checked_list_box::checked_index_collection collection for the checked_list_box.
      /// @remarks The collection of checked indexes is a subset of the indexes into the collection of all items in the checked_list_box control. These indexes specify items in a checked or indeterminate state.
      checked_index_collection checked_indices() const noexcept;
      
      /// @brief Collection of checked items in this checked_list_box.
      /// @return The checked_list_box::checked_item_collection collection for the checked_list_box.
      /// @remarks The collection is a subset of the objects in the items collection, representing only those items whose xtd::forms::check_state is checked or indeterminate. The indexes in this collection are in ascending order.
      checked_item_collection checked_items() const noexcept;
      
      /// @brief Gets the collection of items in this checked_list_box.
      /// @return The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @remarks The items property enables you to obtain a reference to the list of items that are currently stored in a checked_list_box control. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() noexcept;
      /// @brief Gets the collection of items in this checked_list_box.
      /// @return The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @remarks The items property enables you to obtain a reference to the list of items that are currently stored in a checked_list_box control. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      const object_collection& items() const noexcept;
      /// @brief Sets the collection of items in this checked_list_box.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      const list_box& items(const object_collection& items);
      
      using list_box::selected_index;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::checked_list_box::object_collection::npos is returned if no item is selected.
      /// @return Current list_control.
      list_control& selected_index(size_t selected_index) override;
      
      std::vector<size_t> selected_indices() const noexcept override;
      
      /// @brief Gets the currently selected item in the checked_list_box.
      /// @return An object that represents the current selection in the control.
      /// @remarks For a standard list_box, you can use this property to determine which item is selected in the list_box. If the selection_mode property of the list_box is set to either selection_mode::multi_simple or selection_mode::multi_extended (which indicates a multiple-selection list_box) and multiple items are selected in the list, this property can return any selected item.
      /// @remarks To retrieve a collection containing all selected items in a multiple-selection list_box, use the selected_items property. If you want to obtain the index position of the currently selected item in the list_box, use the selected_index property. In addition, you can use the selected_indices property to obtain all the selected indexes in a multiple-selection list_box.
      const item& selected_item() const noexcept;
      /// @brief Sets the currently selected item in the list_box.
      /// @param selected_item An object that represents the current selection in the control.
      /// @remarks For a standard list_box, you can use this property to determine which item is selected in the list_box. If the selection_mode property of the list_box is set to either selection_mode::multi_simple or selection_mode::multi_extended (which indicates a multiple-selection list_box) and multiple items are selected in the list, this property can return any selected item.
      /// @remarks To retrieve a collection containing all selected items in a multiple-selection list_box, use the selected_items property. If you want to obtain the index position of the currently selected item in the list_box, use the selected_index property. In addition, you can use the selected_indices property to obtain all the selected indexes in a multiple-selection list_box.
      checked_list_box& selected_item(const item& selected_item);
      
      /// @brief Gets a collection containing the currently selected items in the list_box.
      /// @return A list_box::selected_object_collection containing the currently selected items in the control.
      /// @remarks For a multiple-selection list_box, this property returns a collection containing all items that are selected in the list_box. For a single-selection list_box, this property returns a collection containing a single element containing the only selected item in the list_box. For more information about how to manipulate the items of the collection, see list_box::selected_object_collection.
      /// @remarks The list_box class provides a number of ways to reference selected items. Instead of using the selected_items property to obtain the currently selected item in a single-selection list_box, you can use the selected_item property. If you want to obtain the index position of an item that is currently selected in the list_box, instead of the item itself, use the selected_index property. In addition, you can use the selected_indices property if you want to obtain the index positions of all selected items in a multiple-selection list_box.
      selected_object_collection selected_items() const noexcept;
      
      using list_box::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      control& text(const xtd::ustring& text) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Maintains performance while items are added to the checked_list_box one at a time by preventing the control from drawing until the end_update() method is called.
      /// @remarks The preferred way to add multiple items to the list_box is to use the push_back_range method of the list_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void begin_update();

      /// @brief Resumes painting the checked_list_box control after painting is suspended by the begin_update method.
      /// @remarks The preferred way to add multiple items to the list_box is to use the push_back_range method of the list_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void end_update();
      
      /// @brief Returns a value indicating whether the specified item is checked.
      /// @param index The index of the item.
      /// @return true if the item is checked; otherwise, false.
      /// @remarks get_item_checked returns true if the value of CheckState is checked or indeterminate for the item. To determine the specific state the item is in, use the get_item_check_state method.
      bool get_item_checked(size_t index) const;
      
      /// @brief Returns a value indicating the check state of the current item.
      /// @param index The index of the item.
      /// @return One of the check_state values.
      /// @remarks The get_item_check_state method provides the ability to get the check_state value of an item, given the index. If you never set the check state of an item to indeterminate, then use the getItem_checked method.
      forms::check_state get_item_check_state(size_t index) const;
      
      /// @brief Returns the text value of the current item.
      /// @param index The index of the item.
      /// @return A string that represent the text value of the current item.
      const xtd::ustring& get_item_text(size_t index) const;
      
      /// @brief Sets check_state for the item at the specified index to checked.
      /// @param index The index of the item to set the check state for.
      /// @param checked true to set the item as checked; otherwise, false.
      /// @remarks When a value of true is passed, this method sets the check_state value to checked. A value of false sets check_state to unchecked.
      void set_item_checked(size_t index, bool checked);
      
      /// @brief Sets the check state of the item at the specified index.
      /// @param index The index of the item to set the check state for.
      /// @param check_state One of the check_state values.
      /// @remarks The set_item_check_state method raises the item_check event.
      /// @remarks Items whose check_state is set to indeterminate appear with a check mark in the check box, but the box is grayed to indicate the indeterminate status of the checked item.
      void set_item_check_state(size_t index, forms::check_state check_state);
      
      /// @brief Sets the text value of the item at the specified index.
      /// @param index The index of the item to set the check state for.
      /// @param text A string that represent the text value.
      void set_item_text(size_t index, const xtd::ustring& text);
      /// @}
      
      /// @name Static methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create();
      /// @brief A factory to create an xtd::forms::checked_list_box with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @param name The name of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified items.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const object_collection& items);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified items, and location.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const object_collection& items, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified items, location, and size.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const object_collection& items, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified items, location, size, and name.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @param name The name of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified items, and selected_index.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::checked_list_box::object_collection::npos is returned if no item is selected.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const object_collection& items, size_t selected_index);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified items, selected_index, and location.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::checked_list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const object_collection& items, size_t selected_index, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified items, selected_index, location, and size.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::checked_list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified items, selected_index, location, size, and name.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::checked_list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @param name The name of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @param name The name of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, and items.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const object_collection& items);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, items, and location.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const object_collection& items, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, items, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, items, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @param name The name of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, items, and selected_index.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::checked_list_box::object_collection::npos is returned if no item is selected.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const object_collection& items, size_t selected_index);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, items, selected_index, and location.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::checked_list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, items, selected_index, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::checked_list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::checked_list_box with specified parent, items, selected_index, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::checked_list_box.
      /// @param items The checked_list_box::object_collection collection representing the items in the checked_list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::checked_list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::checked_list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::checked_list_box.
      /// @param name The name of the xtd::forms::checked_list_box.
      /// @return New xtd::forms::checked_list_box created.
      static checked_list_box create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the checked state of an item changes.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<checked_list_box, item_check_event_handler> item_check;
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      bool allow_selection() const noexcept override;
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      void on_handle_created(const event_args& e) override;
      
      /// @brief Raises the checked_list_box::item_check event.
      /// @param e An item_check_event_args that contains the event data.
      virtual void on_item_check(item_check_event_args& e);
      
      void on_selected_value_changed(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
    private:
      void on_items_item_added(size_t pos, const item& item);
      void on_items_item_removed(size_t pos, const item& item);
      void on_items_item_updated(size_t pos, const item& item);
      void wm_command_control(message& message);
      void wm_mouse_double_click(message& message);
      void wm_mouse_down(message& message);
      void wm_mouse_up(message& message);
      
      std::shared_ptr<data> data_;
    };
  }
}
