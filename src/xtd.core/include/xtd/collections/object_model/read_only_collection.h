/// @file
/// @brief Contains xtd::collections::object_model::read_only_collection class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../generic/ilist.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Contains classes that can be used as collections in the object model of a reusable library. Use these classes when properties or methods return collections.
    namespace object_model {
      /// @brief Provides the base class for a generic read-only collection.
      /// ```cpp
      /// template<typename type_t>
      /// class read_only_collection : public xtd::object, public xtd::collections::generic::ilist<type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/object_model/read_only_collection
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core object_model_collections
      template<typename type_t>
      class read_only_collection : public xtd::object, public xtd::collections::generic::ienumerable<type_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the list value type.
        using value_type = type_t;
        /// @brief Represents the list base type.
        using base_type = ptr<xtd::collections::generic::ilist<value_type>>;
        /// @brief Represents the list size type (usually xtd::size).
        using size_type = xtd::size;
        /// @brief Represents the list difference type (usually xtd::ptrdiff).
        using difference_type = xtd::ptrdiff;
        /// @brief Represents the reference of list value type.
        using reference = value_type&;
        /// @brief Represents the const reference of list value type.
        using const_reference = const value_type&;
        /// @brief Represents the pointer of list value type.
        using pointer = value_type*;
        /// @brief Represents the const pointer of list value type.
        using const_pointer = const value_type*;
        /// @brief Represents the iterator of list value type.
        using iterator = generic::ienumerable<type_t>::iterator;
        /// @brief Represents the const iterator of list value type.
        using const_iterator = generic::ienumerable<type_t>::const_iterator;
        /// @}

        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::object_model::read_only_collection <type_t> class that is a read-only wrapper around the specified list.
        /// @remarks To prevent any modifications to `list`, expose `list` only through this wrapper.
        /// @remarks A collection that is read-only is simply a collection with a wrapper that prevents modifying the collection; therefore, if changes are made to the underlying collection, the read-only collection reflects those changes.
        /// @remarks This constructor is an O(1) operation.
        explicit read_only_collection(ptr<generic::ilist<value_type>> list) : items_(list) {}
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the number of elements contained in the xtd::collections::object_model::read_only_collection <type_t> instance.
        /// @return The number of elements contained in the xtd::collections::object_model::read_only_collection <type_t> instance.
        /// @remarks Retrieving the value of this property is an O(1) operation.
        xtd::size count() const noexcept {return items_->count();}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        generic::enumerator<type_t> get_enumerator() const noexcept override {return items_->get_enumerator();}
        /// @}

        /// @name Public Operators
        
        /// @{
        /// @brief Returns a reference to the element at specified location pos.
        /// @param index The position of the element to return.
        /// @return Reference to the requested element.
        /// @remarks No bounds checking is performed.
        const_reference operator [](size_type index) const {return (*items_)[index];}
        /// @brief Returns a reference to the element at specified location pos.
        /// @param index The position of the element to return.
        /// @return Reference to the requested element.
        /// @remarks No bounds checking is performed.
        reference operator [](size_type index) {return (*items_)[index];}
        /// @}

      protected:
        /// @name Protected Properties
        
        /// @{
        base_type items() noexcept {return items_;}
        /// @}

      private:
        base_type items_;
      };
    }
  }
}
