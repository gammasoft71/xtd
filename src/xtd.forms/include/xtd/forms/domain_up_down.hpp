/// @file
/// @brief Contains xtd::forms::domain_up_down control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once

#include "up_down_base.hpp"
#include "application.hpp"
#include <xtd/iequatable>
#include <xtd/usize_object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows spin box (also known as an up-down control) that displays string values.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/domain_up_down>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                     | macOS                                       | Gnome                                       |
    /// | ----- | ------------------------------------------- | ------------------------------------------- | ------------------------------------------- |
    /// | Light |  @image html control_domain_up_down_w.png   |  @image html control_domain_up_down_m.png   |  @image html control_domain_up_down_g.png   |
    /// | Dark  |  @image html control_domain_up_down_wd.png  |  @image html control_domain_up_down_md.png  |  @image html control_domain_up_down_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of domain up down control.
    /// @include domain_up_down.cpp
    class forms_export_ domain_up_down : public xtd::forms::up_down_base {
      struct data;
      
    public:
      /// @brief Represent an item contained in the domain_up_down::object_collection collection.
      class item : public xtd::object, public xtd::icomparable<item>, public xtd::iequatable<item> {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the item class.
        item() = default;
        /// @brief Initializes a new instance of the item class with specified value.
        /// @param value a string that represent the item.
        item(const xtd::string& value); // Can't be explicit by design.
        /// @brief Initializes a new instance of the item class with specified value and tag.
        /// @param value a string that represent the item.
        /// @param tag an object that contains data about the item.
        item(const xtd::string& value, const xtd::any_object& tag);
        /// @}
        
        /// @cond
        item(const char* value); // Can't be explicit by design.
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the value of the item.
        /// @return A xtd::string that represent the value of item.
        [[nodiscard]] virtual auto value() const noexcept -> const xtd::string&;
        
        /// @brief Gets the tag of the item.
        /// @return A xtd::any_object that represent the tag of item.
        virtual auto tag() const noexcept -> const xtd::any_object&;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Compares the current instance with another object of the same type.
        /// @param obj An object to compare with this instance.
        /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
        /// The return value has these meanings:
        ///
        /// | Value             | Condition                          |
        /// | ----------------- | ---------------------------------- |
        /// | Less than zero    | This instance is less than obj.    |
        /// | Zero              | This instance is equal to obj.     |
        /// | Greater than zero | This instance is greater than obj. |
        [[nodiscard]] auto compare_to(const item& value) const noexcept -> xtd::int32 override;
        
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param other The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        [[nodiscard]] auto equals(const item& other) const noexcept -> bool override;
        
        /// @brief Serves as a hash function for a particular type.
        /// @return A hash code for the current object.
        [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
        
        /// @brief Returns a string containing the vague of the item.
        /// @return A string containing the value of the item.
        [[nodiscard]] auto to_string() const noexcept -> xtd::string override;
        /// @}
        
      private:
        xtd::string value_;
        xtd::any_object tag_;
      };
      
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the collection of items in a list_control.
      using object_collection = xtd::forms::layout::arranged_element_collection<item>;
      /// @}
      
      /// @name Public Fields
      
      /// @{
      /// @brief Represents a value that is not a valid position in a collection.
      /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::usize.
      inline static constexpr xtd::usize npos = object_collection::npos;
      
      /// @brief Represents the index of the first valid element in a collection.
      /// @remarks Unlike xtd::npos (which means "no position"), xtd::bpos points to the first accessible element of a collection. It is equivalent to `0`.
      static inline constexpr xtd::usize bpos = object_collection::bpos;
      
      /// @brief Represents the index of the last valid element in a collection.
      /// @remarks Unlike xtd::npos (which means "no position"), xtd::epos points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
      /// @note This constant is provided for readability and convenience. For example, `items[xtd::epos]` directly accesses the last element without manually subtracting one from the collection count.
      /// @remarks The epos is equivalent to `~1_z`. With bitwise operator the code is more concise.
      static inline constexpr xtd::usize epos = object_collection::epos;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the DomainUpDown class.
      domain_up_down();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets an object representing the collection of the items contained in this domain_up_down. Gets an object representing the collection of the items contained in this domain_up_down.
      /// @return A domain_up_down::object_collection representing the items in the domain_up_down.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the domain_up_down. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      [[nodiscard]] auto items() const noexcept -> const object_collection&;
      /// @brief Gets an object representing the collection of the items contained in this domain_up_down. Gets an object representing the collection of the items contained in this domain_up_down.
      /// @return A domain_up_down::object_collection representing the items in the domain_up_down.
      /// @remarks This property enables you to obtain a reference to the list of items that are currently stored in the domain_up_down. With this reference, you can add items, remove items, and obtain a count of the items in the collection.
      [[nodiscard]] auto items() noexcept -> object_collection&;
      /// @brief Sets an object representing the collection of the items contained in this domain_up_down. Gets an object representing the collection of the items contained in this domain_up_down.
      /// @param value A domain_up_down::object_collection representing the items in the domain_up_down.
      /// @return Current domain_up_down.
      auto items(const object_collection& value) -> domain_up_down&;
      
      /// @brief Gets the zero-based index of the currently selected item.
      /// @return A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      [[nodiscard]] virtual auto selected_index() const noexcept -> xtd::usize;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param value A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current domain_up_down.
      virtual auto selected_index(xtd::usize value) -> domain_up_down&;
      
      /// @brief Gets the selected item based on the index value of the selected item in the collection.
      /// @return The selected item based on the selected_index value. The default value is item::empty.
      [[nodiscard]] auto selected_item() const noexcept -> const item&;
      /// @brief Gets the selected item based on the index value of the selected item in the collection.
      /// @param value The selected item based on the selected_index value. The default value is item::empty.
      /// @return Current domain_up_down.
      auto selected_item(const item& value) -> domain_up_down&;
      
      /// @brief Gets a value indicating whether the collection of items continues to the first or last item if the user continues past the end of the list.
      /// @return `true` if the list starts again when the user reaches the beginning or end of the collection; otherwise, `false`. The default value is `false`.
      [[nodiscard]] virtual auto wrap() const noexcept -> bool;
      /// @brief Sets a value indicating whether the collection of items continues to the first or last item if the user continues past the end of the list.
      /// @param value `true` if the list starts again when the user reaches the beginning or end of the collection; otherwise, `false`. The default value is `false`.
      /// @return Current domain_up_down.
      virtual auto wrap(bool value) -> domain_up_down&;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create() -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @param name The name of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified items.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const object_collection& items) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified items, and location.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const object_collection& items, const xtd::drawing::point& location) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified items, location, and size.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const object_collection& items, const xtd::drawing::point& location, const xtd::drawing::size& size) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified items, location, size, and name.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @param name The name of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const object_collection& items, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified items, and selected_index.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const object_collection& items, xtd::usize selected_index) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified items, selected_index, and location.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const object_collection& items, xtd::usize selected_index, const xtd::drawing::point& location) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified items, selected_index, location, and size.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const object_collection& items, xtd::usize selected_index, const xtd::drawing::point& location, const xtd::drawing::size& size) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified items, selected_index, location, size, and name.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @param name The name of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const object_collection& items, xtd::usize selected_index, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const xtd::drawing::point& location) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @param name The name of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, and items.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const object_collection& items) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, items, and location.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const object_collection& items, const xtd::drawing::point& location) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, items, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const object_collection& items, const xtd::drawing::point& location, const xtd::drawing::size& size) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, items, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @param name The name of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const object_collection& items, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, items, and selected_index.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const object_collection& items, xtd::usize selected_index) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, items, selected_index, and location.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const object_collection& items, xtd::usize selected_index, const xtd::drawing::point& location) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, items, selected_index, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const object_collection& items, xtd::usize selected_index, const xtd::drawing::point& location, const xtd::drawing::size& size) -> domain_up_down;
      /// @brief A factory to create an xtd::forms::domain_up_down with specified parent, items, selected_index, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::domain_up_down.
      /// @param items A choice::object_collection representing the items in the domain_up_down.
      /// @param selected_index A zero-based index of the currently selected item. The xtd::forms::domain_up_down::object_collection::npos is returned if no item is selected.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::domain_up_down.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::domain_up_down.
      /// @param name The name of the xtd::forms::domain_up_down.
      /// @return New xtd::forms::domain_up_down created.
      [[nodiscard]] static auto create(const control& parent, const object_collection& items, xtd::usize selected_index, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> domain_up_down;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the selected_item property has been changed.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<domain_up_down, xtd::event_handler> selected_item_changed;
      
      /// @brief Occurs when the value property has been changed.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<domain_up_down, xtd::event_handler> value_changed;
      /// @}
      
    protected:
      /// @name Protetced properties
      
      /// @{
      xtd::forms::create_params create_params() const noexcept override;
      xtd::drawing::color default_back_color() const noexcept override;
      xtd::drawing::color default_fore_color() const noexcept override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      auto on_handle_created(const xtd::event_args& e) -> void override;
      auto on_lost_focus(const xtd::event_args& e) -> void override;
      
      /// @brief Raises the domain_up_down::selected_item_changed event.
      /// @param e An event_args that contains the event data.
      virtual auto on_selected_item_changed(const xtd::event_args& e) -> void;
      
      auto on_text_changed(const xtd::event_args& e) -> void override;
      auto wnd_proc(xtd::forms::message& message) -> void override;
      /// @}
      
      /// @cond
      auto wm_scroll_control(xtd::forms::message& message) -> void;
      /// @endcond
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
