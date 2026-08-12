/// @file
/// @brief Contains xtd::collections::generic::extensions::list_common class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "../../../internal/__span_definitions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../../../self.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class index;
  class range;
  /// @endcond
  
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::extensions namespace contains interface extensions.
      namespace extensions {
        /// @brief Internal list common definition.
        /// @par Definition
        /// ```cpp
        /// template<typename type_t, typename list_t>
        /// class list_common;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/extensions/list_common
        /// ```
        /// @par Namespace
        /// xtd
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core extensions_generic_collections
        /// @warning Internal use only for xtd::icollection interfece.
        template<typename type_t, typename list_t>
        class list_common {
        public:
          /// @name Public Operators
          
          /// @{
          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] virtual auto operator ()(xtd::usize index) const -> const type_t& {
            return self().operator [](index);
          }
          /// @brief Sets the element at the specified index.
          /// @param index The zero-based index of the element to set.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] virtual auto operator ()(xtd::usize index) -> type_t& {
            return self().operator [](index);
          }

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] auto operator [](const xtd::index& index) const -> const type_t&;
          /// @brief Sets the element at the specified index.
          /// @param index The zero-based index of the element to set.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] auto operator [](const xtd::index& index) -> type_t&;

          /// @brief Gets the element at the specified index.
          /// @param index The zero-based index of the element to get.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] auto operator ()(const xtd::index& index) const -> const type_t&;
          /// @brief Sets the element at the specified index.
          /// @param index The zero-based index of the element to set.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] auto operator ()(const xtd::index& index) -> type_t&;

          /// @brief Gets the elements at the specified range.
          /// @param range The range of the elements to get.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] auto operator [](const xtd::range& range) const -> xtd::read_only_span<type_t>;
          /// @brief Sets the elements at the specified range.
          /// @param range The range of the elements to set.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] auto operator [](const xtd::range& range) -> xtd::span<type_t>;

          /// @brief Gets the elements at the specified range.
          /// @param range The range of the elements to get.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] auto operator ()(const xtd::range& range) const -> xtd::read_only_span<type_t>;
          /// @brief Sets the elements at the specified range.
          /// @param range The range of the elements to set.
          /// @remarks This operator provides the ability to access a specific element in the collection by using the following syntax: `my_collection[index]`.
          [[nodiscard]] auto operator ()(const xtd::range& range) -> xtd::span<type_t>;
          /// @}
          
        private:
          auto self() const noexcept -> const list_t& {return static_cast<const list_t&>(self_);}
          auto self() noexcept -> list_t& {return static_cast<list_t&>(self_);}
          
          friend list_t;
          list_common() = default;
        };
      }
    }
  }
}
