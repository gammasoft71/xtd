/// @file
/// @brief Contains xtd::collections::generic::linked_list <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/comparer.hpp"
#include "../object_model/read_only_collection.hpp"
#include "icollection.hpp"
#include "linked_list_node.hpp"
#include "../../size.hpp"
#include "../../string.hpp"
#include <list>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a doubly linked list.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// using linked_list = std::list<type_t, xtd::collections::generic::helpers::allocator<type_t>>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/linked_list>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      template<class type_t, class allocator_t>
      class linked_list : public xtd::object, public xtd::collections::generic::icollection<type_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the list value type.
        using value_type = typename icollection<type_t>::value_type;
        /// @brief Represents the list base type.
        using base_type = std::list<value_type>;
        /// @brief Represents the list base type.
        using const_base_type = const base_type;
        /// @brief Represents the list size type (usually xtd::size).
        using size_type = xtd::size;
        /// @brief Represents the reference of list value type.
        using reference = value_type&;
        /// @brief Represents the const reference of list value type.
        using const_reference = const value_type&;
        /// @brief Represents the read only collection of of list.
        using read_only_collection = xtd::collections::object_model::read_only_collection<value_type>;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        linked_list() = default;
        linked_list(linked_list&&) = default;
        linked_list(const linked_list & list) {*data_ = *list.data_;}
        linked_list(std::list < type_t > && list) {data_->items = std::move(list);}
        linked_list(const std::list < type_t >& list) {data_->items = list;}
        linked_list(const xtd::collections::generic::ienumerable < type_t >& collection) {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        linked_list(std::initializer_list < type_t > items) {
          for (const auto& item : items)
            add(item);
        }
        /// @brief Constructs the container with the contents of the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        template < std::input_iterator input_iterator_t >
        linked_list(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator)
            add(*iterator);
        }
        /// @}
        
        /// @name Public Properties
        size_type count() const noexcept override {return data_->items.size();}
        
        xtd::optional<linked_list_node<type_t>> first() const {
          if (!count()) return xtd::nullopt;
          return linked_list_node<type_t> {const_cast<linked_list&>(self_), data_->items.begin(), data_->version};
        }
        
        xtd::optional<linked_list_node<type_t>> first() {
          if (!count()) return xtd::nullopt;
          return linked_list_node<type_t> {self_, data_->items.begin(), data_->version};
        }
        
        const base_type& items() const noexcept {
          return data_->items;
        }
        
        base_type& items() noexcept {
          return data_->items;
        }

        xtd::optional<linked_list_node<type_t>> last() const {
          if (!count()) return xtd::nullopt;
          auto tmp = data_->items.end();
          return linked_list_node<type_t> {const_cast<linked_list&>(self_), --tmp, data_->version};
        }

        xtd::optional<linked_list_node<type_t>> last() {
          if (!count()) return xtd::nullopt;
          auto tmp = data_->items.end();
          return linked_list_node<type_t> {self_, --tmp, data_->version};
        }
        /// @}
        
        /// @name Public Methods
        linked_list_node<type_t> add_after(const linked_list_node<type_t>& node, const type_t& value) {
          if (node.data_->list != this) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          auto iterator = node.data_->iterator;
          if (iterator != data_->items.end()) ++iterator;
          auto result = data_->items.insert(iterator, value);
          ++data_->version;
          return {self_, result};
        }
        
        void add_after(const linked_list_node<type_t>& node, linked_list_node<type_t>& new_node) {
          if (node.data_->list != this) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          if (new_node.data_->list || !new_node.data_->value.has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          auto iterator = node.data_->iterator;
          if (iterator != data_->items.end()) ++iterator;
          auto result = data_->items.insert(iterator, new_node.data_->value.value());
          new_node = {self_, result};
          ++data_->version;
        }
        
        linked_list_node<type_t> add_before(const linked_list_node<type_t>& node, const type_t& value) {
          if (node.data_->list != this) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          auto iterator = node.data_->iterator;
          auto result = data_->items.insert(iterator, value);
          ++data_->version;
          return {self_, result};
        }
        
        linked_list_node<type_t> add_before(const linked_list_node<type_t>& node, linked_list_node<type_t>& new_node) {
          if (node.data_->list != this) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          if (new_node.data_->list || !new_node.data_->value.has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          auto iterator = node.data_->iterator;
          auto result = data_->items.insert(iterator, new_node.data_->value.value());
          ++data_->version;
          new_node = {self_, result};
        }
        
        void add_first(const type_t& value) {
          data_->items.push_front(value);
          ++data_->version;
        }
        
        void add_first(linked_list_node<type_t>& node) {
          if (node.data_->list || !node.data_->value.has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          data_->items.push_front(node.data_->value.value());
          ++data_->version;
          node = {self_, data_->items.begin()};
        }
        
        void add_last(const type_t& value) {
          data_->items.push_back(value);
          ++data_->version;
        }
        
        void add_last(linked_list_node<type_t>& node) {
          if (node.data_->list || !node.data_->value.has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          data_->items.push_back(node.data_->value.value());
          ++data_->version;
          auto tmp = data_->items.end();
          node = {self_, --tmp};
        }
        
        /// @brief Removes all elements from the xtd::collections::generic::linked_list <type_t>.
        /// @remarks xtd::collections::generic::linked_list::count is set to 0, and references to other objects from elements of the collection are also released.
        /// @remarks xtd::collections::generic::linked_list::capacity remains unchanged. To reset the capacity of the xtd::collections::generic::linked_list <type_t>, call the xtd::collections::generic::linked_list::trim_excess method or set the xtd::collections::generic::linked_list::capacity property directly. Decreasing the capacity reallocates memory and copies all the elements in the xtd::collections::generic::linked_list <type_t>. Trimming an empty xtd::collections::generic::linked_list <type_t> sets the capacity of the xtd::collections::generic::linked_list <type_t> to the default capacity.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::linked_list::count.
        void clear() override {
          data_->items.clear();
          ++data_->version;
        }
        
        /// @brief Determines whether an element is in the xtd::colllections::generic::linked_list <type_t>.
        /// @param value The object to locate in the xtd::colllections::generic::linked_list <type_t>. The value can be null for reference types.
        /// @return `true` if item is found in the xtd::colllections::generic::linked_list <type_t>; otherwise, `false`.
        bool contains(const type_t& value) const noexcept override {
          for (auto item : data_->items)
            if (item == value) return true;
          return false;
        }
        
        /// @brief Copies the entire xtd::colllections::generic::linked_list <type_t> to a compatible one-dimensional array, starting at the specified index of the target array.
        /// @param array The one-dimensional Array that is the destination of the elements copied from xtd::colllections::generic::linked_list <type_t>. The Array must have zero-based indexing.
        /// @param array_index The zero-based index in array at which copying begins.
        /// @exception xtd::argument_out_of_range_exception The number of elements in the source xtd::colllections::generic::linked_list <type_t> is greater than the available space from arrayIndex to the end of the destination array.
        /// @remarks This method uses xtd::array::copy to copy the elements.
        /// @remarks The elements are copied to the xtd::array in the same order in which the enumerator iterates through the xtd::colllections::generic::linked_list <type_t>.
        /// @remarks This method is an O(n) operation, where n is xtd::colllections::generic::linked_list::count.
        void copy_to(xtd::array < type_t >& array, size_type array_index) const override {
          if (array_index + count() > array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          auto index = array_index;
          for (auto item : data_->items)
            array[index++] = item;
        }
        
        xtd::optional<linked_list_node<type_t>> find(const type_t value) const noexcept {
          for (auto node = first(); node; node = node->next())
            if (node->value() == value) return node;
          return xtd::nullopt;
        }
        
        xtd::optional<linked_list_node<type_t>> find_last(const type_t value) const noexcept {
          for (auto node = last(); node; node = node->previous())
            if (node->value() == value) return node;
          return xtd::nullopt;
        }
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::linked_list <type_t>.
        /// @return A xtd::collections::generic::.enumerator for the xtd::collections::generic::linked_list <type_t>.
        enumerator < value_type > get_enumerator() const noexcept override {
          struct linked_list_enumerator : public ienumerator < value_type > {
            explicit linked_list_enumerator(const linked_list & items, xtd::size version) : items_(items), version_(version) {}
            
            const value_type& current() const override {
              if (iterator_ == items_.data_->items.cend()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              return *iterator_;
            }
            
            bool move_next() override {
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              if (index_++ && iterator_ != items_.data_->items.cend()) ++iterator_;
              else iterator_ = items_.data_->items.cbegin();
              return iterator_ != items_.data_->items.cend();
            }
            
            void reset() override {
              index_ = 0;
              version_ = items_.data_->version;
              iterator_ = items_.data_->items.cend();
            }
            
          private:
            size_type index_ = 0;
            const linked_list& items_;
            typename base_type::const_iterator iterator_ = items_.data_->items.cend();
            size_type version_ = 0;
          };
          return {new_ptr < linked_list_enumerator > (self_, data_->version)};
        }
        
        /// @brief Removes the first occurrence of a specific object from the xtd::collections::generic::linked_list <type_t>.
        /// @param item The object to remove from the xtd::collections::generic::linked_list <type_t>.
        /// @return `true` if item is successfully removed; otherwise, `false`. This method also returns `false` if item was not found in the xtd::collections::generic::linked_list <type_t>.
        /// @remarks If type `typ_t` implements the xtd::iequatable <type_t> generic interface, the equality comparer is the xtd::iequatable::equals method of that interface; otherwise, the default equality comparer is xtd::object::equals.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::linked_list::count.
        bool remove(const type_t& item) noexcept override {
          for (auto iterator = data_->items.begin(); iterator != data_->items.end(); ++iterator)
            if (*iterator == item) {
              data_->items.erase(iterator);
              return true;
            }
          return false;
        }
        
        void remove(linked_list_node<type_t>& node) {
          if (!count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          if (node.data_->list != this) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          node.data_->value = *node.data_->iterator;
          data_->items.erase(node.data_->iterator);
          ++data_->version;
          node.data_->list = null;
        }
        
        void remove_first() {
          if (!count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          data_->items.erase(data_->items.begin());
          ++data_->version;
        }
        
        void remove_last() {
          if (!count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          data_->items.erase(--data_->items.end());
          ++data_->version;
        }
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        string to_string() const noexcept override {return xtd::string::format("[{}]", xtd::string::join(", ", self_));}
        /// @}
        /// @name Public Operators
        
        /// @{
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        linked_list& operator =(const linked_list & other) = default;
        /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container). other is in a valid but unspecified state afterwards.
        /// @param other Another base type container to use as data source.
        /// @return This current instance.
        linked_list& operator =(linked_list&& other) noexcept {
          data_->items = std::move(other.data_->items);
          return self_;
        }
        /// @brief Replaces the contents with those identified by initializer list ilist.
        /// @param items Initializer list to use as data source
        /// @return This current instance.
        linked_list& operator =(const std::initializer_list < type_t >& items) {
          data_->items = items;
          return self_;
        }
        
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const_base_type& () const noexcept {return data_->items;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator base_type& () noexcept {return data_->items;}
        /// @}
        
      private:
        friend class linked_list_node<type_t>;
        void add(const type_t& item) override {add_last(item);}
        bool is_read_only() const noexcept override {return false;}
        bool is_synchronized() const noexcept override {return false;}
        const xtd::object& sync_root() const noexcept override {return data_->sync_root;}
        
        struct linked_list_data {
          base_type items;
          xtd::object sync_root;
          xtd::size version = 0;
        };
        
        xtd::ptr < linked_list_data > data_ = xtd::new_ptr < linked_list_data > ();
      };
      
      /// @cond
      // C++17 deduction guides for xtd::collections::generic::linked_list
      // {
      template < class type_t, class allocator_t = xtd::collections::generic::helpers::allocator < type_t>>
      linked_list(linked_list < type_t, allocator_t >&&) -> linked_list < type_t, allocator_t >;
      
      template < class type_t, class allocator_t = xtd::collections::generic::helpers::allocator < type_t>>
      linked_list(const list < type_t, allocator_t >&) -> linked_list < type_t, allocator_t >;
      
      template < class type_t, class allocator_t = xtd::collections::generic::helpers::allocator < type_t>>
      linked_list(const std::list < type_t >&) -> linked_list < type_t, allocator_t >;
      
      template < class type_t, class allocator_t = xtd::collections::generic::helpers::allocator < type_t>>
      linked_list(std::list < type_t >&&) -> linked_list < type_t, allocator_t >;
      
      template < class type_t, class allocator_t = xtd::collections::generic::helpers::allocator < type_t>>
      linked_list(const ienumerable < type_t >&) -> linked_list < type_t, allocator_t >;
      
      template < class type_t, class allocator_t = xtd::collections::generic::helpers::allocator < type_t>>
      linked_list(std::initializer_list < type_t >) -> linked_list < type_t, allocator_t >;
      // }
      /// @endcond
    }
  }
}
