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
        linked_list_node(const value_type & value) {data_->value = value;}
        linked_list_node(value_type&& value) {data_->value = std::move(value);}
        linked_list_node(linked_list_node&&) = default;
        linked_list_node(const linked_list_node&) = default;
        /// @}
        
        /// @name Public Properties
        xtd::ref<const linked_list<type_t>> list() const noexcept {return data_->list ? ref {*data_->list} : xtd::ref<linked_list<type_t>> {};}

        xtd::optional<linked_list_node> next() const {
          check_stale();
          if (!data_->list || !data_->list->count() || data_->iterator == end()) return xtd::nullopt;
          auto tmp = data_->iterator;
          if (++tmp == end()) return xtd::nullopt;
          return linked_list_node {*data_->list, tmp, data_->version};
        }
        
        xtd::optional<linked_list_node> previous() const {
          check_stale();
          if (!data_->list || !data_->list->count() || data_->iterator == begin()) return xtd::nullopt;
          auto tmp = data_->iterator;
          return linked_list_node {*data_->list, --tmp, data_->version};
        }
        
        const value_type& value() const {
          check_stale();
          return data_->value.has_value() ? data_->value.value() : *data_->iterator;
        }
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
        using iterator = typename base_type::iterator;
        
        linked_list_node(linked_list_type & list, iterator iterator, size_type version) {
          data_->list = &list;
          data_->iterator = iterator;
          data_->version = version;
        }
                
        iterator begin() const {return data_->list->data_->items.begin();}
        void check_stale() const {if (data_->list && data_->list->data_->version != data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; node operation may not execute.");}
        iterator end() const {return data_->list->data_->items.end();}
        
        struct node_data {
          linked_list<type_t>* list = null;
          iterator iterator;
          xtd::optional < value_type > value;
          size_type version;
        };
        
        xtd::ptr < node_data > data_ = xtd::new_ptr < node_data > ();
      };
    }
  }
}
