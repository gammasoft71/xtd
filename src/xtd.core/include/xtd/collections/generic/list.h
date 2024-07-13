/// @file
/// @brief Contains xtd::collections::generic::list struct.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a strongly typed list of objects that can be accessed by index. Provides methods to search, sort, and manipulate lists.
      /// ```cpp
      /// template<typename type_t>
      /// class list : public std::vector<type_t, helpers::allocator<type_t>>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/list
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::list class is same as [std::vector](https://en.cppreference.com/w/cpp/container/vector) with xtd::collections::generic::helpers::allocator instead [std::allocator](https://en.cppreference.com/w/cpp/memory/allocator).
      template<typename type_t>
      class list : public std::vector<type_t, helpers::allocator<type_t>> {
      public:
        /// @name Public Alias
        
        /// @{
        /// @brief Represents the allocator type of list.
        using allocator_type = helpers::allocator<type_t>;
        /// @brief Represents the base type of list.
        using base_type = std::vector<type_t, allocator_type>;
        /// @brief Represents the size type of list.
        using size_type = std::vector<type_t, allocator_type>::size_type;
        /// @}

        /// @name Constructors
        
        /// @{
        list() noexcept = default;
        explicit list(const allocator_type& alloc) noexcept : base_type(alloc) {}
        list(size_type count, const type_t& value, const allocator_type& alloc = allocator_type()) : base_type(count, value, alloc) {}
        explicit list(size_type count, const allocator_type& alloc = allocator_type()) : base_type(count, alloc) {}
        template<typename input_iterator_t>
        list(input_iterator_t first, input_iterator_t last, const allocator_type& alloc = allocator_type()) : base_type(first, last, alloc) {}
        list(const list& other) : base_type(other) {}
        list(const base_type& other) : base_type(other) {}
        list(const list& other, const allocator_type& alloc) : base_type(other, alloc) {}
        list(const base_type& other, const allocator_type& alloc) : base_type(other, alloc) {}
        list(list&& other) : base_type(other) {}
        list(base_type&& other) : base_type(other) {}
        list(list&& other, const allocator_type& alloc) : base_type(other, alloc) {}
        list(base_type&& other, const allocator_type& alloc) : base_type(other, alloc) {}
        list(std::initializer_list<type_t> init, const allocator_type& alloc = allocator_type()) : base_type(init, alloc) {}
        list& operator =(const list& other) = default;
       /// @}
      };
    }
  }
}
