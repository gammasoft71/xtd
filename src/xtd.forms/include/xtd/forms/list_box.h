/// @file
/// @brief Contains xtd::forms::list_box control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.h"
#include "border_sides.h"
#include "border_style.h"
#include "list_control.h"
#include "selection_mode.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a standard Windows list box.
    /// @par Header
    /// @code #include <xtd/forms/list_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                               | macOS                                 | Gnome                                 |
    /// | ----- | ------------------------------------- | ------------------------------------- | ------------------------------------- |
    /// | Light |  @image html control_list_box_w.png   |  @image html control_list_box_m.png   |  @image html control_list_box_g.png   |
    /// | Dark  |  @image html control_list_box_wd.png  |  @image html control_list_box_md.png  |  @image html control_list_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of list_box control.
    /// @include list_box.cpp
    class forms_export_ list_box : public list_control {
      struct data;
      
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the collection containing the indexes to the selected items in a list_box.
      using selected_index_collection = std::vector<size_t>;
      
      /// @brief Represents the collection of selected items in the list_box.
      using selected_object_collection = std::vector<item>;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the list_box class.
      list_box();
      /// @}
      
      /// @cond
      list_box(list_box&& rhs);
      /// @endcond

      /// @name Public Properties
      
      /// @{
      /// @brief Gets the border sides for the control.
      /// @return A bitwise combination of the A bitwise combination values. The default is border_style::all.
      virtual forms::border_sides border_sides() const noexcept;
      /// @brief Sets the border sides for the control.
      /// @param border_style A bitwise combination of the border_sides values. The default is border_style::all.
      virtual list_box& border_sides(forms::border_sides border_sides);
      
      /// @brief Gets the type of border that is drawn around the list_box.
      /// @return One of the xtd::forms::border_styleforms::border_style values. The default is fixed_single.
      virtual forms::border_style border_style() const noexcept;
      /// @brief Sets the type of border that is drawn around the list_box.
      /// @param border_style One of the xtd::forms::border_styleforms::border_style values. The default is fixed_single.
      /// @return Current list_box.
      virtual list_box& border_style(forms::border_style border_style);
      /// @brief Resets the border style for the control.
      /// @param border_style nullptr.
      /// @return Current label instance.
      /// @remarks You can use this property to add a border to the control. This property is typically used to differentiate a label that labels another control from a label that displays the status of a process in an application.
      virtual list_box& border_style(std::nullptr_t);
      
      /// @brief Gets the items of the list_box.
      /// @return An list_box::object_collection representing the items in the list_box.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the list_box. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() noexcept;
      /// @brief Gets the items of the list_box.
      /// @return An list_box::object_collection representing the items in the list_box.
      const object_collection& items() const noexcept;
      /// @brief Sets the items of the list_box.
      /// @param items An list_box::object_collection representing the items in the list_box.
      /// @return Current list_box.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the list_box. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      const list_box& items(const object_collection& items);
      
      using list_control::selected_index;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current list_control.
      list_control& selected_index(size_t selected_index) override;
      
      /// @brief Gets a collection that contains the zero-based indexes of all currently selected items in the list_box.
      /// @brief A list_box.selected_index_collection containing the indexes of the currently selected items in the control. If no items are currently selected, an empty ListBox.SelectedIndexCollection is returned.
      /// @remarks For a multiple-selection list_box, this property returns a collection containing the indexes to all items that are selected in the list_box. For a single-selection ListBox, this property returns a collection containing a single element containing the index of the only selected item in the list_box. For more information about how to manipulate the items of the collection, see list_box::selected_index_collection.
      /// @remarks The list_box class provides a number of ways to reference selected items. Instead of using the selected_indices property to obtain the index position of the currently selected item in a single-selection list_box, you can use the selected_index property. If you want to obtain the item that is currently selected in the list_box, instead of the index position of the item, use the selected_item property. In addition, you can use the selected_items property if you want to obtain all the selected items in a multiple-selection list_box.
      virtual selected_index_collection selected_indices() const noexcept;
      
      /// @brief Gets the currently selected item in the list_box.
      /// @return An object that represents the current selection in the control.
      /// @remarks For a standard list_box, you can use this property to determine which item is selected in the list_box. If the selection_mode property of the list_box is set to either selection_mode::multi_simple or selection_mode::multi_extended (which indicates a multiple-selection list_box) and multiple items are selected in the list, this property can return any selected item.
      /// @remarks To retrieve a collection containing all selected items in a multiple-selection list_box, use the selected_items property. If you want to obtain the index position of the currently selected item in the list_box, use the selected_index property. In addition, you can use the selected_indices property to obtain all the selected indexes in a multiple-selection list_box.
      const item& selected_item() const noexcept;
      /// @brief Sets the currently selected item in the list_box.
      /// @param selected_item An object that represents the current selection in the control.
      /// @return Current list_box.
      /// @remarks For a standard list_box, you can use this property to determine which item is selected in the list_box. If the selection_mode property of the list_box is set to either selection_mode::multi_simple or selection_mode::multi_extended (which indicates a multiple-selection list_box) and multiple items are selected in the list, this property can return any selected item.
      /// @remarks To retrieve a collection containing all selected items in a multiple-selection list_box, use the selected_items property. If you want to obtain the index position of the currently selected item in the list_box, use the selected_index property. In addition, you can use the selected_indices property to obtain all the selected indexes in a multiple-selection list_box.
      list_box& selected_item(const item& selected_item);
      
      /// @brief Gets a collection containing the currently selected items in the list_box.
      /// @return A list_box::selected_object_collection containing the currently selected items in the control.
      /// @remarks For a multiple-selection list_box, this property returns a collection containing all items that are selected in the list_box. For a single-selection list_box, this property returns a collection containing a single element containing the only selected item in the list_box. For more information about how to manipulate the items of the collection, see list_box::selected_object_collection.
      /// @remarks The list_box class provides a number of ways to reference selected items. Instead of using the selected_items property to obtain the currently selected item in a single-selection list_box, you can use the selected_item property. If you want to obtain the index position of an item that is currently selected in the list_box, instead of the item itself, use the selected_index property. In addition, you can use the selected_indices property if you want to obtain the index positions of all selected items in a multiple-selection list_box.
      selected_object_collection selected_items() const noexcept;
      
      /// @brief Gets the method in which items are selected in the list_box.
      /// @return One of the selection_mode values. The default is selection_mode::one.
      /// @remarks The selection_mode property enables you to determine how many items in the list_box a user can select at one time and how the user can make multiple-selections. When the selection_mode property is set to selection_mode::multi_extended, pressing SHIFT and clicking the mouse or pressing SHIFT and one of the arrow keys (UP ARROW, DOWN ARROW, LEFT ARROW, and RIGHT ARROW) extends the selection from the previously selected item to the current item. Pressing CTRL and clicking the mouse selects or deselects an item in the list. When the property is set to selection_mode::multi_simple, a mouse click or pressing the SPACEBAR selects or deselects an item in the list.
      virtual forms::selection_mode selection_mode() const noexcept;
      /// @brief Sets the method in which items are selected in the list_box.
      /// @param selection_mode One of the selection_mode values. The default is selection_mode::one.
      /// @return Current list_box.
      /// @remarks The selection_mode property enables you to determine how many items in the list_box a user can select at one time and how the user can make multiple-selections. When the selection_mode property is set to selection_mode::multi_extended, pressing SHIFT and clicking the mouse or pressing SHIFT and one of the arrow keys (UP ARROW, DOWN ARROW, LEFT ARROW, and RIGHT ARROW) extends the selection from the previously selected item to the current item. Pressing CTRL and clicking the mouse selects or deselects an item in the list. When the property is set to selection_mode::multi_simple, a mouse click or pressing the SPACEBAR selects or deselects an item in the list.
      virtual list_box& selection_mode(forms::selection_mode selection_mode);
      
      /// @brief Gets a value indicating whether the items in the list_box are sorted alphabetically.
      /// @return true if items in the control are sorted; otherwise, false. The default is false.
      /// @remarks Use the sorted property to automatically sort strings alphabetically in a list_box. As items are added to a sorted list_box, the items are moved to the appropriate location in the sorted list. When adding items to a list_box, it is more efficient to sort the items first and then add new items.
      virtual bool sorted() const noexcept;
      /// @brief Sets a value indicating whether the items in the list_box are sorted alphabetically.
      /// @param sorted true if items in the control are sorted; otherwise, false. The default is false.
      /// @return Current list_box.
      /// @remarks Use the sorted property to automatically sort strings alphabetically in a list_box. As items are added to a sorted list_box, the items are moved to the appropriate location in the sorted list. When adding items to a list_box, it is more efficient to sort the items first and then add new items.
      virtual list_box& sorted(bool sorted);
      
      using list_control::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      control& text(const xtd::ustring& text) override;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Maintains performance while items are added to the list_box one at a time by preventing the control from drawing until the EndUpdate() method is called.
      /// @remarks The preferred way to add multiple items to the list_box is to use the push_back_range method of the list_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void begin_update();

      /// @brief Resumes painting the list_box control after painting is suspended by the begin_update method.
      /// @remarks The preferred way to add multiple items to the list_box is to use the push_back_range method of the list_box::object_collection class (through the items property of the list_box). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the list_box::object_collection class, you can use the begin_update method to prevent the control from repainting the list_box each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the list_box to repaint. This way of adding items can prevent flickered drawing of the list_box when a large number of items are being added to the list.
      void end_update();
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create();
      /// @brief A factory to create an xtd::forms::list_box with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::list_box with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::list_box with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @param name The name of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::list_box with specified items.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const object_collection& items);
      /// @brief A factory to create an xtd::forms::list_box with specified items, and location.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const object_collection& items, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::list_box with specified items, location, and size.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const object_collection& items, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::list_box with specified items, location, size, and name.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @param name The name of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::list_box with specified items, and selected_index.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::list_box::object_collection::npos is returned if no item is selected.
      /// @return New xtd::forms::list_box created.
      static list_box create(const object_collection& items, size_t selected_index);
      /// @brief A factory to create an xtd::forms::list_box with specified items, selected_index, and location.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const object_collection& items, size_t selected_index, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::list_box with specified items, selected_index, location, and size.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::list_box with specified items, selected_index, location, size, and name.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @param name The name of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::list_box with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @param name The name of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, and items.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const object_collection& items);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, items, and location.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const object_collection& items, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, items, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, items, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @param name The name of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, items, and selected_index.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::list_box::object_collection::npos is returned if no item is selected.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const object_collection& items, size_t selected_index);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, items, selected_index, and location.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, items, selected_index, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::list_box with specified parent, items, selected_index, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::list_box.
      /// @param items A choice::object_collection representing the items in the list_box.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::list_box::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::list_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::list_box.
      /// @param name The name of the xtd::forms::list_box.
      /// @return New xtd::forms::list_box created.
      static list_box create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protetced properties
      
      /// @{
      bool allow_selection() const noexcept override;
      forms::create_params create_params() const noexcept override;
      drawing::color default_back_color() const noexcept override;
      drawing::color default_fore_color() const noexcept override;
      /// @}
      ///
      /// @name Protetced methods
      
      /// @{
      void on_handle_created(const event_args& e) override;
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
