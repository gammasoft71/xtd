/// @file
/// @brief Contains xtd::collections::generic::linked_list_node <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "../../null.hpp"
#include "../../nullopt.hpp"
#include "../../object.hpp"
#include "../../optional.hpp"
#include "../../ref.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @cond
      template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
      class linked_list;
      /// @endcond
      
      /// @brief Represents a node in a LinkedList<T>. This class cannot be inherited.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// class linked_list_node final : public xtd::object;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/linked_list_node>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @par Examples
      /// The following code example creates a xtd::collections::generic::linked_list_node <type_t>, adds it to a xtd::collections::generic::linked_list <type_t>, and tracks the values of its properties as the xtd::collections::generic::linked_list <type_t> changes.
      /// @include generic_linked_list_node.cpp
      /// @remarks Each element of the xtd::collections::generic::linked_list <type_t> collection has a virtual xtd::collections::generic::linked_list_node <type_t>. The xtd::collections::generic::linked_list_node <type_t> contains a value, a reference to the xtd::collections::generic::linked_list <type_t> that it belongs to, a reference to the next node, and a reference to the previous node.
      template<class type_t>
      class linked_list_node final : public xtd::object {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the linked list node value type.
        using value_type = type_t;
        /// @brief Represents the linked list type.
        using linked_list_type = linked_list<value_type>;
        /// @brief Represents the linked list base type.
        using base_type = typename linked_list_type::base_type;
        /// @brief Represents the size type.
        using size_type = typename linked_list_type::size_type;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::linked_list_node <type_t> class, containing the specified value.
        /// @param The value to contain in the xtd::collections::generic::linked_list_node <type_t>.
        /// @par Examples
        /// The following code example creates a xtd::collections::generic::linked_list_node <type_t>, adds it to a xtd::collections::generic::linked_list <type_t>, and tracks the values of its properties as the xtd::collections::generic::linked_list <type_t> changes.
        /// @include generic_linked_list_node.cpp
        /// @remarks The xtd::collections::generic::linked_list_node::list, xtd::collections::generic::linked_list_node::next, and xtd::collections::generic::linked_list_node::previous properties are set to xtd::nullopt.
        linked_list_node(const value_type & value) {data_->value = value;}
        /// @}
        
        /// @cond
        linked_list_node(value_type&& value) {data_->value = std::move(value);}
        linked_list_node(linked_list_node&&) = default;
        linked_list_node(const linked_list_node&) = default;
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the xtd::collections::generic::linked_list <type_t> that the xtd::collections::generic::linked_list_node <type_t> belongs to.
        /// @return A reference to the xtd::collections::generic::linked_list <ype_t> that the xtd::collections::generic::linked_list_node <type_t> belongs to, or null if the xtd::collections::generic::linked_list_node <type_t> is not linked.
        /// @par Examples
        /// The following code example creates a xtd::collections::generic::linked_list_node <type_t>, adds it to a xtd::collections::generic::linked_list <type_t>, and tracks the values of its properties as the xtd::collections::generic::linked_list <type_t> changes.
        /// @include generic_linked_list_node.cpp
        xtd::ref<const linked_list<type_t>> list() const noexcept {return data_->list ? ref {*data_->list} : xtd::ref<linked_list<type_t>> {};}
        
        /// @brief Gets the next node in the LinkedList<T>.
        /// @return A reference to the next node in the xtd::collections::generic::linked_list <type_t>, or null if the current node is the last element (Last) of the xtd::collections::generic::linked_list <type_t>.
        /// @par Examples
        /// The following code example creates a xtd::collections::generic::linked_list_node <type_t>, adds it to a xtd::collections::generic::linked_list <type_t>, and tracks the values of its properties as the xtd::collections::generic::linked_list <type_t> changes.
        /// @include generic_linked_list_node.cpp
        xtd::optional<linked_list_node> next() const {
          check_stale();
          if (!data_->list || !data_->list->count() || data_->iterator == end()) return xtd::nullopt;
          auto tmp = data_->iterator;
          if (++tmp == end()) return xtd::nullopt;
          return linked_list_node {*data_->list, tmp, data_->version};
        }
        
        /// @brief Gets the previous node in the LinkedList<T>.
        /// @return A reference to the previous node in the xtd::collections::generic::linked_list <type_t>, or null if the current node is the first element (Last) of the xtd::collections::generic::linked_list <type_t>.
        /// @par Examples
        /// The following code example creates a xtd::collections::generic::linked_list_node <type_t>, adds it to a xtd::collections::generic::linked_list <type_t>, and tracks the values of its properties as the xtd::collections::generic::linked_list <type_t> changes.
        /// @include generic_linked_list_node.cpp
        xtd::optional<linked_list_node> previous() const {
          check_stale();
          if (!data_->list || !data_->list->count() || data_->iterator == begin()) return xtd::nullopt;
          auto tmp = data_->iterator;
          return linked_list_node {*data_->list, --tmp, data_->version};
        }
        
        /// @brief Gets the value contained in the node.
        /// @return The value contained in the node.
        /// @par Examples
        /// The following code example creates a xtd::collections::generic::linked_list_node <type_t>, adds it to a xtd::collections::generic::linked_list <type_t>, and tracks the values of its properties as the xtd::collections::generic::linked_list <type_t> changes.
        /// @include generic_linked_list_node.cpp
        /// @remarks This property is set in the xtd::collections::generic::linked_list_node <type_t>.
        const value_type& value() const {
          check_stale();
          return data_->value.has_value() ? data_->value.value() : *data_->iterator;
        }
        /// @brief Gets the value contained in the node.
        /// @return The value contained in the node.
        /// @par Examples
        /// The following code example creates a xtd::collections::generic::linked_list_node <type_t>, adds it to a xtd::collections::generic::linked_list <type_t>, and tracks the values of its properties as the xtd::collections::generic::linked_list <type_t> changes.
        /// @include generic_linked_list_node.cpp
        /// @remarks This property is set in the xtd::collections::generic::linked_list_node <type_t>.
        value_type& value() {
          check_stale();
          return data_->value.has_value() ? data_->value.value() : *data_->iterator;
        }
        /// @}
        
        /// @cond
        linked_list_node& operator =(linked_list_node&&) = default;
        linked_list_node& operator =(const linked_list_node&) = default;
        /// @endcond
        
      private:
        friend class linked_list<type_t>;
        using iterator_type = typename base_type::iterator;
        
        linked_list_node(linked_list_type & list, iterator_type iterator, size_type version) {
          data_->list = &list;
          data_->iterator = iterator;
          data_->version = version;
        }
        
        iterator_type begin() const {return data_->list->data_->items.begin();}
        void check_stale() const {if (data_->list && data_->list->data_->version != data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; node operation may not execute.");}
        iterator_type end() const {return data_->list->data_->items.end();}
        
        struct node_data {
          linked_list<type_t>* list = null;
          iterator_type iterator;
          xtd::optional < value_type > value;
          size_type version;
        };
        
        xtd::ptr < node_data > data_ = xtd::new_ptr < node_data > ();
      };
    }
  }
}
