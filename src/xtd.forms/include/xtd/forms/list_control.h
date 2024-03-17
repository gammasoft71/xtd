/// @file
/// @brief Contains xtd::forms::list_control control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

#include "application.h"
#include "control.h"
#include <xtd/iequatable>
#include <xtd/size_object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a common implementation of members for the list_box, choice and combo_box classes.
    /// @par Header
    /// @code #include <xtd/forms/list_control> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    /// @remarks The list_control class provides implementations of common elements for the list_box and combo_box controls.
    /// @remarks The following properties are of primary concern to users of a data-bound list_box, choice or combo_box: data_source, display_member, selected_value, and value_member properties.
    class forms_export_ list_control : public control {
      struct data;
      
    public:
      /// @brief Represent an item contained in the list_control::object_collection collection.
      class item : public object, public icomparable<item>, public xtd::iequatable<item> {
      public:
        /// @brief Represent the sorter class used by list_control::object_collection collection.
        class sorter {
        public:
          /// @name Operators
          
          /// @{
          /// @brief sorter functor.
          /// @param first the fist iterator to sort.
          /// @param last the last iterator to sort.
          /// @remarks same as std::sort.
          template<typename type_t>
          void operator()(type_t first, type_t last) {
            std::sort(first, last);
          }
          /// @}
        };
        
        /// @name Public Fields
        
        /// @{
        /// @brief Represents an empty item that value is equal to xtd::ustring::empty_string and tag has no vlaue.
        static const item empty;
        /// @}

        /// @name Public Constructors
        
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
        item(item&& value) = default;
        item& operator =(const item& value) = default;
        item& operator =(item&& value) = default;
        virtual ~item() = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the value of the item.
        /// @return A xtd::ustring that represent the value of item.
        virtual const xtd::ustring& value() const noexcept;
        
        /// @brief Gets the tag of the item.
        /// @return A std::any that represent the tag of item.
        virtual std::any tag() const noexcept;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        int32 compare_to(const item& value) const noexcept override;
        
        bool equals(const item& value) const noexcept override;
        
        /// @brief Returns a string containing the value of the item.
        /// @return A string containing the value of the item.
        xtd::ustring to_string() const noexcept override;
        /// @}
        
      private:
        xtd::ustring value_;
        std::any tag_;
      };
      
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the collection of items in a list_control.
      using object_collection = layout::arranged_element_collection<item, item::sorter>;
      /// @}
      
      /// @name Public Fields
      
      /// @{
      /// @brief This is a special value equal to the maximum value representable by the type size_t.
      static const size_t npos = size_object::max_value;
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the zero-based index of the currently selected item.
      /// @return A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      virtual size_t selected_index() const noexcept;
      /// @brief When overridden in a derived class, Sets the zero-based index of the currently selected item.
      /// @param selected_index A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      /// @return Current list_control.
      virtual list_control& selected_index(size_t selected_index) = 0;
      /// @}
      
      /// @name Public Events
      
      /// @{
      /// @brief Occurs when the selected_index property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<list_control, event_handler> selected_index_changed;
      
      /// @brief Occurs when the selected_value property changes.
      /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
      event<list_control, event_handler> selected_value_changed;
      /// @}
      
    protected:
      /// @name Protected constructors
      
      /// @{
      /// @brief Initializes a new instance of the list_control class.
      list_control();
      /// @}
      
      /// @name Protetced properties
      
      /// @{
      drawing::color default_back_color() const noexcept override;
      drawing::color default_fore_color() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      /// @brief Gets a value indicating whether the list enables selection of list items.
      /// @return true if the list enables list item selection; otherwise, false. The default is true.
      virtual bool allow_selection() const noexcept;
      
      /// @brief Raises the list_control::selected_index_changed event.
      virtual void on_selected_index_changed(const event_args& e);
      
      /// @brief Raises the list_control::selected_value_changed event.
      virtual void on_selected_value_changed(const event_args& e);
      
      /// @brief Sets the currently selected item.
      /// @param value A zero-based index of the currently selected item. A value of negative one (-1) is returned if no item is selected.
      void set_selected_index(size_t value);
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
