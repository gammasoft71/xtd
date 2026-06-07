/// @file
/// @brief Contains xtd::forms::list_control control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once

#include "application.hpp"
#include "control.hpp"
#include <xtd/iequatable>
#include <xtd/usize_object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a common implementation of members for the list_box, choice and combo_box classes.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/list_control>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The list_control class provides implementations of common elements for the list_box and combo_box controls.
    /// @remarks The following properties are of primary concern to users of a data-bound list_box, choice or combo_box: data_source, display_member, selected_value, and value_member properties.
    class forms_export_ list_control : public xtd::forms::control {
      struct data;
      
    public:
      /// @brief Represent an item contained in the list_control::object_collection collection.
      class item : public xtd::object, public xtd::icomparable<item>, public xtd::iequatable<item> {
      public:
        /// @brief Represent the sorter struct used by list_control::object_collection collection.
        struct sorter {
          /// @name Operators
          
          /// @{
          /// @brief sorter functor.
          /// @param first the fist iterator to sort.
          /// @param last the last iterator to sort.
          /// @remarks same as std::sort.
          template<typename type_t>
          auto operator()(type_t first, type_t last) -> void {std::sort(first, last);}
          /// @}
        };
        
        /// @name Public Fields
        
        /// @{
        /// @brief Represents an empty item that value is equal to xtd::string::empty_string and tag has no vlaue.
        static const item empty;
        /// @}
        
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
        virtual ~item() = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the value of the item.
        /// @return A xtd::string that represent the value of item.
        [[nodiscard]] virtual auto value() const noexcept -> const xtd::string&;
        
        /// @brief Gets the tag of the item.
        /// @return A xtd::any_object that represent the tag of item.
        [[nodiscard]] virtual auto tag() const noexcept -> const xtd::any_object&;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Compares the current instance with another object of the same type.
        /// @param value An object to compare with this instance.
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
        
        /// @brief Returns a string containing the value of the item.
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
      using object_collection = xtd::forms::layout::arranged_element_collection<item, item::sorter>;
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
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the zero-based index of the currently selected item.
      /// @return A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      [[nodiscard]] virtual auto selected_index() const noexcept -> xtd::usize;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param value A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current list_control.
      virtual auto selected_index(xtd::usize value) -> list_control& = 0;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the selected_index property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<list_control, xtd::event_handler> selected_index_changed;
      
      /// @brief Occurs when the selected_value property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
      xtd::event<list_control, xtd::event_handler> selected_value_changed;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the list_control class.
      list_control();
      /// @}
      
      /// @name Protetced properties
      
      /// @{
      [[nodiscard]] auto default_back_color() const noexcept -> xtd::drawing::color override;
      [[nodiscard]] auto default_fore_color() const noexcept -> xtd::drawing::color override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Gets a value indicating whether the list enables selection of list items.
      /// @return `true` if the list enables list item selection; otherwise, `false`. The default is `true`.
      [[nodiscard]] virtual auto allow_selection() const noexcept -> bool;
      
      /// @briefautoRaises the list_control::selected_index_changed event.
      virtual auto on_selected_index_changed(const event_args& e) -> void;
      
      /// @brief Raises the list_control::selected_value_changed event.
      virtual auto on_selected_value_changed(const event_args& e) -> void;
      
      /// @brief Sets the currently selected item.
      /// @param value A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      auto set_selected_index(xtd::usize value) -> void;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
