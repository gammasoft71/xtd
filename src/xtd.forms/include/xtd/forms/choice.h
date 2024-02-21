/// @file
/// @brief Contains xtd::forms::choice control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "layout/arranged_element_collection.h"
#include "list_control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a choice control.
    /// @par Header
    /// @code #include <xtd/forms/choice> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @remarks A choice displays a text box combined with a list, which enables the user to select items from the list or enter a new value.
    /// @remarks To add or remove objects in the list at run time, use methods of the choice.object_collection class (through the items property of the choice). You can assign an array of object with the push_range method. The list then displays the default string value for each object. You can add individual objects with the push method. You can delete items with the erase method or clear the entire list with the clear method.
    /// @remarks In addition to display and selection functionality, the choice also provides features that enable you to efficiently add items to the choice and to find text within the items of the list. With the begin_update and end_update methods, you can add a large number of items to the choice without the control being repainted each time an item is added to the list. The find_string and find_string_exact methods enable you to search for an item in the list that contains a specific search string.
    /// @remarks You can use these properties to manage the currently selected item in the list, the text property to specify the string displayed in the editing field, the selected_index property to get or set the current item, and the selected_item property to get or set a reference to the object.
    /// @par Appearance
    /// |       | Windows                             | macOS                               | Gnome                               |
    /// | ----- | ----------------------------------- | ----------------------------------- | ----------------------------------- |
    /// | Light |  @image html control_choice_w.png   |  @image html control_choice_m.png   |  @image html control_choice_g.png   |
    /// | Dark  |  @image html control_choice_wd.png  |  @image html control_choice_md.png  |  @image html control_choice_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of checked_list_box control.
    /// @include checked_list_box.cpp
    /// @par Examples
    /// The following code example demonstrates the use of choice control.
    /// @include choice.cpp
    class forms_export_ choice : public list_control {
      struct data;
      
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the choice class.
      choice();
      //// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets an object representing the collection of the items contained in this choice.
      /// @return A choice::object_collection representing the items in the choice.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the choice. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() noexcept;
      /// @brief Gets an object representing the collection of the items contained in this choice.
      /// @return A choice::object_collection representing the items in the choice.
      const object_collection& items() const noexcept;
      /// @brief Sets an object representing the collection of the items contained in this choice.
      /// @param items A choice::object_collection representing the items in the choice.
      const choice& items(const object_collection& items);
      
      using list_control::selected_index;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      list_control& selected_index(size_t selected_index) override;
      
      /// @brief Gets currently selected item in the choice.
      /// @return The object that is the currently selected item.
      const item& selected_item() const noexcept;
      /// @brief Sets currently selected item in the choice.
      /// @param selected_item The object that is the currently selected item.
      choice& selected_item(const item& selected_item);
      
      /// @brief Gets a value indicating whether the items in the choice are sorted.
      /// @return true if the choice is sorted; otherwise, false. The default is false.
      /// @remarks This property specifies whether the choice sorts existing entries and add new entries to the appropriate sorted position in the list. You can use this property to automatically sort items in a choice. As items are added to a sorted choice, the items are moved to the appropriate location in the sorted list. When you set the property to false, new items are added to the end of the existing list. The sort is case-insensitive and in alphabetically ascending order.
      virtual bool sorted() const noexcept;
      /// @brief Sets a value indicating whether the items in the choice are sorted.
      /// @param sorted true if the choice is sorted; otherwise, false. The default is false.
      /// @remarks This property specifies whether the choice sorts existing entries and add new entries to the appropriate sorted position in the list. You can use this property to automatically sort items in a choice. As items are added to a sorted choice, the items are moved to the appropriate location in the sorted list. When you set the property to false, new items are added to the end of the existing list. The sort is case-insensitive and in alphabetically ascending order.
      virtual choice& sorted(bool sorted);
      
      using list_control::text;
      /// @brief Sets the text associated with this control.
      /// @param text The text associated with this control.
      control& text(const xtd::ustring& text) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Maintains performance while items are added to the choice one at a time by preventing the control from drawing until the EndUpdate() method is called.
      /// @remarks The preferred way to add multiple items to the choice is to use the push_back_range method of the choice::object_collection class (through the items property of the choice). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the choice::object_collection class, you can use the begin_update method to prevent the control from repainting the choice each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the choice to repaint. This way of adding items can prevent flickered drawing of the choice when a large number of items are being added to the list.
      void begin_update();
      
      /// @brief A factory to create an xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create();
      /// @brief A factory to create an xtd::forms::choice with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::choice with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::choice with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @param name The name of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::choice with specified items.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @return New xtd::forms::choice created.
      static choice create(const object_collection& items);
      /// @brief A factory to create an xtd::forms::choice with specified items, and location.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const object_collection& items, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::choice with specified items, location, and size.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const object_collection& items, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::choice with specified items, location, size, and name.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @param name The name of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::choice with specified items, and selected_index.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::choice::object_collection::npos is returned if no item is selected.
      /// @return New xtd::forms::choice created.
      static choice create(const object_collection& items, size_t selected_index);
      /// @brief A factory to create an xtd::forms::choice with specified items, selected_index, and location.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::choice::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const object_collection& items, size_t selected_index, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::choice with specified items, selected_index, location, and size.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::choice::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::choice with specified items, selected_index, location, size, and name.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::choice::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @param name The name of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::choice with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent);
      /// @brief A factory to create an xtd::forms::choice with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::choice with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::choice with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @param name The name of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::choice with specified parent, and items.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const object_collection& items);
      /// @brief A factory to create an xtd::forms::choice with specified parent, items, and location.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const object_collection& items, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::choice with specified parent, items, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::choice with specified parent, items, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @param name The name of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const object_collection& items, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::choice with specified parent, items, and selected_index.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::choice::object_collection::npos is returned if no item is selected.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const object_collection& items, size_t selected_index);
      /// @brief A factory to create an xtd::forms::choice with specified parent, items, selected_index, and location.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::choice::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::choice with specified parent, items, selected_index, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::choice::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::choice with specified parent, items, selected_index, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::choice.
      /// @param items A choice::object_collection representing the items in the choice.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::choice::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::choice.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::choice.
      /// @param name The name of the xtd::forms::choice.
      /// @return New xtd::forms::choice created.
      static choice create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Resumes painting the choice control after painting is suspended by the begin_update method.
      /// @remarks The preferred way to add multiple items to the choice is to use the push_back_range method of the choice::object_collection class (through the items property of the choice). This enables you to add an array of items to the list in a single operation. However, if you want to add items one at a time using the Add method of the choice::object_collection class, you can use the begin_update method to prevent the control from repainting the choice each time an item is added to the list. Once you have completed the task of adding items to the list, call the end_update method to enable the choice to repaint. This way of adding items can prevent flickered drawing of the choice when a large number of items are being added to the list.
      void end_update();
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      void on_handle_created(const event_args& e) override;
      void on_selected_value_changed(const event_args& e) override;
      void set_bounds_core(int32 x, int32 y, int32 width, int32 height, bounds_specified specified) override;
      void set_client_size_core(int32 width, int32 height) override;
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
