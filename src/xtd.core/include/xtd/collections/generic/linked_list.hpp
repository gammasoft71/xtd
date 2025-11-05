/// @file
/// @brief Contains xtd::collections::generic::linked_list <value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/comparer.hpp"
#include "icollection.hpp"
#include "../../object.hpp"
#include "../../size.hpp"
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
      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
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
        /// @brief Represents the pointer of list value type.
        using pointer = value_type*;
        /// @brief Represents the const pointer of list value type.
        using const_pointer = const value_type*;
        /// @brief Represents the read only collection of of list.
        using read_only_collection = xtd::collections::object_model::read_only_collection<value_type>;
        /// @}
        
        class node : public xtd::object {
        public:
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the list value type.
          using value_type = type_t;
          /// @brief Represents the list base type.
          using linked_list_type = linked_list<value_type>;
          /// @brief Represents the list base type.
          using base_type = typename linked_list_type::base_type;
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          node(node&&) = default;
          node(const node&) = default;
          node(value_type&& value) {
            data_->value = std::move(value);
          }
          node(const value_type& value) {
            data_->value = value;
          }

          /// @}
          
          /// @name Public Properties
          bool has_value() const noexcept {return  data_->value.has_value() || (data_->list && data_->iterator != end());}
          
          bool is_valid() const noexcept {return has_value();}
          
          node next() const noexcept {
            if (!data_->list) return self_;
            if (!data_->list->count() || data_->iterator == end()) return {*data_->list, end()};
            auto tmp = data_->iterator;
            return {*data_->list, ++tmp};
          }
          
          node previous() const noexcept {
            if (!data_->list) return self_;
            if (!data_->list->count() || data_->iterator == begin()) return {*data_->list, end()};
            auto tmp = data_->iterator;
            return {*data_->list, --tmp};
          }
          
          const value_type& value() const {
            if (!has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
            return *data_->iterator;
          }
          value_type& value() {
            if (!has_value()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
            if (data_->value.has_value()) return data_->value;
            return *data_->iterator;
          }

          value_type value_or(const value_type& default_value) const {
            if (!has_value()) return default_value;
            return value();
          }
          /// @}
          
          /// @cond
          node& operator =(node&&) = default;
          node& operator =(const node&) = default;
          /// @endcond
          
        private:
          friend class linked_list;
          using iterator_type = typename base_type::iterator;

          node(linked_list_type& list, iterator_type iterator) {
            data_->list = &list;
            data_->iterator = iterator;
          }
          
          iterator_type begin() const {return data_->list->items().begin();}
          iterator_type end() const {return data_->list->items().end();}

          struct node_data {
            linked_list* list = null;
            iterator_type iterator;
            xtd::optional<value_type> value;
          };
          
          xtd::ptr<node_data> data_ = xtd::new_ptr<node_data>();
        };

        /// @name Public Constructors
        
        /// @{
        linked_list() = default;
        linked_list(linked_list&&) = default;
        linked_list(const linked_list& list) {*data_ = *list.data_;}
        linked_list(std::list<type_t>&& list) {data_->items = std::move(list);}
        linked_list(const std::list<type_t>& list) {data_->items = list;}
        linked_list(const xtd::collections::generic::ienumerable<type_t>& collection) {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        linked_list(std::initializer_list<type_t> items) {
          for (const auto& item : items)
            add(item);
        }
        /// @brief Constructs the container with the contents of the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        template <std::input_iterator input_iterator_t>
        linked_list(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator)
            add(*iterator);
        }
        /// @}
        
        /// @name Public Properties
        size_type count() const noexcept override {return data_->items.size();}
        
        node first() {
          if (!count()) return node {self_, data_->items.end()};
          return node {self_, data_->items.begin()};
        }
        
        const base_type& items() const noexcept {return data_->items;}
        base_type& items() noexcept {return data_->items;}

        node last() {
          if (!count()) return node {self_, data_->items.end()};
          auto tmp = data_->items.end();
          return node {self_, --tmp};
        }
        /// @}
        
        /// @name Public Methods
        node add_after(const node& node, const type_t& value) {
          if (node.data_->list != this) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          auto iterator = node.data_->iterator;
          if (iterator != data_->items.end()) ++iterator;
          auto result = data_->items.insert(iterator, value);
          ++data_->version;
          return {self_, result};
        }
        
        node add_before(const node& node, const type_t& value) {
          if (node.data_->list != this) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          auto iterator = node.data_->iterator;
          auto result = data_->items.insert(iterator, value);
          ++data_->version;
          return {self_, result};
        }
        
        void add_first(const type_t& value) {
          data_->items.push_front(value);
          ++data_->version;
        }
        
        void add_last(const type_t& value) {
          data_->items.push_back(value);
          ++data_->version;
        }
        
        /// @brief Removes all elements from the xtd::collections::generic::list <type_t>.
        /// @remarks xtd::collections::generic::list::count is set to 0, and references to other objects from elements of the collection are also released.
        /// @remarks xtd::collections::generic::list::capacity remains unchanged. To reset the capacity of the xtd::collections::generic::list <type_t>, call the xtd::collections::generic::list::trim_excess method or set the xtd::collections::generic::list::capacity property directly. Decreasing the capacity reallocates memory and copies all the elements in the xtd::collections::generic::list <type_t>. Trimming an empty xtd::collections::generic::list <type_t> sets the capacity of the xtd::collections::generic::list <type_t> to the default capacity.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        void clear() override {
          data_->items.clear();
          ++data_->version;
        }
        
        /// @brief Determines whether an element is in the xtd::colllections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::colllections::generic::list <type_t>. The value can be null for reference types.
        /// @return `true` if item is found in the xtd::colllections::generic::list <type_t>; otherwise, `false`.
        bool contains(const type_t& value) const noexcept override {
          for (auto item : data_->items)
            if (item == value) return true;
          return false;
        }

        /// @brief Copies the entire xtd::colllections::generic::list <type_t> to a compatible one-dimensional array, starting at the specified index of the target array.
        /// @param array The one-dimensional Array that is the destination of the elements copied from xtd::colllections::generic::list <type_t>. The Array must have zero-based indexing.
        /// @param array_index The zero-based index in array at which copying begins.
        /// @exception xtd::argument_out_of_range_exception The number of elements in the source xtd::colllections::generic::list <type_t> is greater than the available space from arrayIndex to the end of the destination array.
        /// @remarks This method uses xtd::array::copy to copy the elements.
        /// @remarks The elements are copied to the xtd::array in the same order in which the enumerator iterates through the xtd::colllections::generic::list <type_t>.
        /// @remarks This method is an O(n) operation, where n is xtd::colllections::generic::list::count.
        void copy_to(xtd::array<type_t>& array, size_type array_index) const override {
          if (array_index + count() > array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          auto index = array_index;
          for (auto item : data_->items)
            array[index++] = item;
        }

        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::list <type_t>.
        /// @return A xtd::collections::generic::.enumerator for the xtd::collections::generic::list <type_t>.
        enumerator<value_type> get_enumerator() const noexcept override {
          return {new_ptr<internal_enumerator>(self_, data_->version)};
        }
        
        /// @brief Removes the first occurrence of a specific object from the xtd::collections::generic::list <type_t>.
        /// @param item The object to remove from the xtd::collections::generic::list <type_t>.
        /// @return `true` if item is successfully removed; otherwise, `false`. This method also returns `false` if item was not found in the xtd::collections::generic::list <type_t>.
        /// @remarks If type `typ_t` implements the xtd::iequatable <type_t> generic interface, the equality comparer is the xtd::iequatable::equals method of that interface; otherwise, the default equality comparer is xtd::object::equals.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        bool remove(const type_t& item) noexcept override {
          for (auto iterator = data_->items.begin(); iterator != data_->items.end(); ++iterator)
            if (*iterator == item) {
              data_->items.erase(iterator);
              return true;
            }
          return false;
        }
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        string to_string() const noexcept override {return xtd::string::format("[{}]", xtd::string::join(", ", self_));}
        /// @}

      private:
        void add(const type_t& item) override {add_last(item);}
        bool is_read_only() const noexcept override {return false;}
        bool is_synchronized() const noexcept override {return false;}
        const xtd::object& sync_root() const noexcept override {return data_->sync_root;}

        struct internal_enumerator : public ienumerator<type_t> {
        public:
          explicit internal_enumerator(const linked_list& items, xtd::size version) : items_(items), version_(version) {}
          
          const type_t& current() const override {
            if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
            if (iterator_ != items_.data_->items.end()) return *iterator_;
            return default_value_;
          }
          
          bool move_next() override {
            if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
            if (first_iteration) {
              first_iteration = false;
              return iterator_ != items_.data_->items.end();
            }
            return ++iterator_ != items_.data_->items.end();
          }
          
          void reset() override {
            version_ = items_.data_->version;
            iterator_ = items_.data_->items.begin();
          }
          
        protected:
          const linked_list& items_;
          bool first_iteration = true;
          typename base_type::iterator iterator_ = items_.data_->items.begin();
          xtd::size version_ = 0;
          type_t default_value_;
        };
        
        struct linked_list_data {
          base_type items;
          xtd::object sync_root;
          xtd::size version = 0;
        };
        
        xtd::ptr<linked_list_data> data_ = xtd::new_ptr<linked_list_data>();
      };
      
      /// @cond
      // C++17 deduction guides for xtd::collections::generic::list
      // {
      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      linked_list(linked_list<type_t, allocator_t>&&) -> linked_list<type_t, allocator_t>;

      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      linked_list(const list<type_t, allocator_t>&) -> linked_list<type_t, allocator_t>;
      
      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      linked_list(const std::list<type_t>&) -> linked_list<type_t, allocator_t>;
      
      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      linked_list(std::list<type_t>&&) -> linked_list<type_t, allocator_t>;
      
      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      linked_list(const ienumerable<type_t>&) -> linked_list<type_t, allocator_t>;

      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      linked_list(std::initializer_list<type_t>) -> linked_list<type_t, allocator_t>;
      // }
      /// @endcond
    }
  }
}
