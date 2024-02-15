/// @file
/// @brief Contains xtd::forms::domain_up_down control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "up_down_base.h"
#include "application.h"
#include <xtd/iequatable>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows spin box (also known as an up-down control) that displays string values.
    /// @par Header
    /// @code #include <xtd/forms/domain_up_down> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                     | macOS                                       | Gnome                                       |
    /// | ----- | ------------------------------------------- | ------------------------------------------- | ------------------------------------------- |
    /// | Light |  @image html control_domain_up_down_w.png   |  @image html control_domain_up_down_m.png   |  @image html control_domain_up_down_g.png   |
    /// | Dark  |  @image html control_domain_up_down_wd.png  |  @image html control_domain_up_down_md.png  |  @image html control_domain_up_down_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of domain up down control.
    /// @include domain_up_down.cpp
    class forms_export_ domain_up_down : public up_down_base {
      struct data;
      
    public:
      /// @brief Represent an item contained in the domain_up_down::object_collection collection.
      class item : public object, public icomparable<item>, public xtd::iequatable<item> {
      public:
        /// @name Constructors
        
        /// @{
        /// @brief Initializes a new instance of the item class.
        item() = default;
        /// @brief Initializes a new instance of the item class with specified value.
        /// @param value a string that represent the item.
        item(const xtd::ustring& value); // Can't be explicit by design.
        /// @brief Initializes a new instance of the item class with specified value and tag.
        /// @param value a string that represent the item.
        /// @param tag an object that contains data about the item.
        item(const xtd::ustring& value, const std::any& tag);
        /// @}
        
        /// @cond
        item(const char* value); // Can't be explicit by design.
        item(const item& value) = default;
        item& operator =(const item& value) = default;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the value of the item.
        /// @return A xtd::ustring that represent the value of item.
        virtual const xtd::ustring& value() const noexcept;
        
        /// @brief Gets the tag of the item.
        /// @return A std::any that represent the tag of item.
        virtual std::any tag() const noexcept;
        /// @}
        
        /// @name Methods
        
        /// @{
        int32 compare_to(const item& value) const noexcept override;
        bool equals(const item& value) const noexcept override;
        /// @brief Returns a string containing the vague of the item.
        /// @return A string containing the value of the item.
        xtd::ustring to_string() const noexcept override;
        /// @}
        
      private:
        xtd::ustring value_;
        std::any tag_;
      };
      
      /// @name Alias
      
      /// @{
      /// @brief Represents the collection of items in a list_control.
      using object_collection = layout::arranged_element_collection<item>;
      /// @}
      
      /// @name Fields
      
      /// @{
      /// @brief This is a special value equal to the maximum value representable by the type size_t.
      static const size_t npos = std::numeric_limits<size_t>::max();
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the DomainUpDown class.
      domain_up_down();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets an object representing the collection of the items contained in this domain_up_down. Gets an object representing the collection of the items contained in this domain_up_down.
      /// @return A domain_up_down::object_collection representing the items in the domain_up_down.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the domain_up_down. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      object_collection& items() noexcept;
      /// @brief Gets an object representing the collection of the items contained in this domain_up_down. Gets an object representing the collection of the items contained in this domain_up_down.
      /// @return A domain_up_down::object_collection representing the items in the domain_up_down.
      const object_collection& items() const noexcept;
      /// @brief Sets an object representing the collection of the items contained in this domain_up_down. Gets an object representing the collection of the items contained in this domain_up_down.
      /// @param items A domain_up_down::object_collection representing the items in the domain_up_down.
      /// @return Current domain_up_down.
      const domain_up_down& items(const object_collection& items);
      /// @brief Gets the zero-based index of the currently selected item.
      /// @return A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      virtual size_t selected_index() const noexcept;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current domain_up_down.
      virtual domain_up_down& selected_index(size_t selected_index);
      
      /// @brief Gets the selected item based on the index value of the selected item in the collection.
      /// @return The selected item based on the selected_index value. The default value is item::empty.
      const item& selected_item() const noexcept;
      /// @brief Gets the selected item based on the index value of the selected item in the collection.
      /// @param item The selected item based on the selected_index value. The default value is item::empty.
      /// @return Current domain_up_down.
      domain_up_down& selected_item(const item& selected_item);
      
      /// @brief Gets a value indicating whether the collection of items continues to the first or last item if the user continues past the end of the list.
      /// @return true if the list starts again when the user reaches the beginning or end of the collection; otherwise, false. The default value is false.
      virtual bool wrap() const noexcept;
      /// @brief Sets a value indicating whether the collection of items continues to the first or last item if the user continues past the end of the list.
      /// @param value true if the list starts again when the user reaches the beginning or end of the collection; otherwise, false. The default value is false.
      /// @return Current domain_up_down.
      virtual domain_up_down& wrap(bool value);
      /// @}
      
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::domain_up_down with specified items, selected_index, location ,size, and name.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      static domain_up_down create(const object_collection& items, size_t selected_index = object_collection::npos, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, items, selected_index, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      static domain_up_down create(const control& parent, const object_collection& items, size_t selected_index, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @}
      
      /// @name Events
      
      /// @{
      /// @brief Occurs when the selected_item property has been changed.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<domain_up_down, event_handler> selected_item_changed;
      
      /// @brief Occurs when the value property has been changed.
      /// @remarks For more information about handling events, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview">Handling and Raising Events</a>.
      event<domain_up_down, event_handler> value_changed;
      /// @}
      
    protected:
      /// @name Protetced properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      drawing::color default_back_color() const noexcept override;
      drawing::color default_fore_color() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      void on_handle_created(const event_args& e) override;
      
      void on_lost_focus(const event_args& e) override;
      
      /// @brief Raises the domain_up_down::selected_item_changed event.
      /// @param e An event_args that contains the event data.
      virtual void on_selected_item_changed(const event_args& e);
      
      void on_text_changed(const event_args& e) override;
      void wnd_proc(message& message) override;
      /// @}
      
      /// @cond
      void wm_scroll_control(message& message);
      /// @endcond
      
    private:
      void on_items_item_added(size_t pos, const item& item);
      void on_items_item_removed(size_t pos, const item& item);
      void on_items_item_updated(size_t pos, const item& item);
      
      std::shared_ptr<data> data_;
    };
  }
}
