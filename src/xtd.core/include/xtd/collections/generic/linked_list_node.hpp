/// @file
/// @brief Contains xtd::collections::generic::linked_list_node <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "../../null.hpp"
#include "../../object.hpp"

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
      
      /// @brief Represents a doubly linked list.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// using linked_list_node = xtd::collections::generic::linked_list<type_t>::linked_list_node;
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
      template<class type_t>
      class linked_list_node : public xtd::object {
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
        linked_list_node(linked_list_node&&) = default;
        linked_list_node(const linked_list_node&) = default;
        linked_list_node(value_type&& value) {
          data_->value = std::move(value);
        }
        linked_list_node(const value_type & value) {
          data_->value = value;
        }
        
        /// @}
        
        /// @name Public Properties
        bool has_value() const noexcept {return  data_->value.has_value() || (data_->list && data_->iterator != end());}
        
        bool is_valid() const noexcept {return has_value();}
        
        linked_list_node next() const noexcept {
          if (!data_->list) return self_;
          if (!data_->list->count() || data_->iterator == end()) return {*data_->list, end()};
          auto tmp = data_->iterator;
          return {*data_->list, ++tmp};
        }
        
        linked_list_node previous() const noexcept {
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
          if (data_->value.has_value()) return data_->value.value();
          return *data_->iterator;
        }
        
        value_type value_or(const value_type & default_value) const {
          if (!has_value()) return default_value;
          return value();
        }
        /// @}
        
        /// @cond
        linked_list_node& operator =(linked_list_node&&) = default;
        linked_list_node& operator =(const linked_list_node&) = default;
        /// @endcond
        
      private:
        friend class linked_list<type_t>;
        using iterator_type = typename base_type::iterator;
        
        linked_list_node(linked_list_type & list, iterator_type iterator) {
          data_->list = &list;
          data_->iterator = iterator;
        }
        
        iterator_type begin() const {return data_->list->items().begin();}
        iterator_type end() const {return data_->list->items().end();}
        
        struct node_data {
          linked_list<type_t>* list = null;
          iterator_type iterator;
          xtd::optional < value_type > value;
        };
        
        xtd::ptr < node_data > data_ = xtd::new_ptr < node_data > ();
      };
    }
  }
}
