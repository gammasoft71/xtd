/// @file
/// @brief Contains xtd::collections::generic::helpers::wrap_pointer_iterator class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../../ptrdiff.hpp"
#include "../../../size.hpp"
#include <iterator>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::helpers namespace contains helpers for generic collections, sush as comparer, equator an hasher structs.
      namespace helpers {
        /// @brief Represents a wrap pointer iterator.
        /// @par Definition
        /// ```cpp
        /// template<class value_t>
        /// class wrap_pointer_iterator;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/genric/helpers/wrap_pointer_iterator
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template<class value_t>
        class wrap_pointer_iterator {
        public:
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the value type.
          using value_type = value_t;
          /// @brief Represents the iterator category type.
          using iterator_category = std::forward_iterator_tag;
          /// @brief Represents the value type.
          using difference_type = xtd::ptrdiff;
          /// @brief Represents the pointer of the value type.
          using pointer = value_type*;
          /// @brief Represents the const pointer of the value type.
          using const_pointer = const value_type*;
          /// @brief Represents the reference of the value type.
          using reference = value_type&;
          /// @brief Represents the const reference of the value type.
          using const_reference = const value_type&;
          /// @}
          
          /// @name Public Constructors
          
          /// @{
          /// @brief Initializes a new instance of the xtd::collections::generic::helpers::wrap_pointer_iterator class with specified pointer value.
          /// @param pointer The pointer value.
          wrap_pointer_iterator(value_t pointer) noexcept : data_ {pointer} {}
          /// @}

          /// @name Public Operators
          
          /// @{
          /// @brief Returns reference to the current element, or a proxy holding it.
          /// @return The reference to the current element.
          const std::remove_pointer_t<value_t> operator *() const noexcept {return *data_;}
          /// @brief Returns reference to the current element, or a proxy holding it.
          /// @return The reference to the current element.
          std::remove_pointer_t<value_t> operator *() noexcept {return *data_;}
          /// @brief Returns pointer to the current element, or a proxy holding it.
          /// @return The pointer to the current element.
          const value_t operator ->() const noexcept {return data_;}
          /// @brief Returns pointer to the current element, or a proxy holding it.
          /// @return The pointer to the current element.
          value_t operator ->() noexcept {return data_;}
          
          /// @brief Pre increments the underlying iterator.
          /// @return The underlying iterator.
          wrap_pointer_iterator& operator ++() const noexcept {++data_; return *const_cast<wrap_pointer_iterator*>(this);}
          /// @brief Post increments the underlying iterator.
          /// @return The underlying iterator.
          wrap_pointer_iterator operator ++(int) const noexcept {auto current = *this; operator ++(); return current;}
          
          /// @brief Add operator with specified value.
          /// @param value The number to add to the underlying iterator.
          /// @return The underlying iterator.
          wrap_pointer_iterator operator +(xtd::size value) const noexcept {return wrap_pointer_iterator {data_ + value};}
          /// @brief Subtract The specified iterator from the current iterator.
          /// @param value The iterator to subtract from the current iterator.
          /// @return The difference between current iterator and the specified iterator.
          xtd::ptrdiff operator -(wrap_pointer_iterator value) const noexcept {return data_ - value.data_;}
          
          /// @biref The equality operator of specified underlyig itertators.
          /// @return true if underlying iterators are equels; otherwise false.
          bool operator ==(const wrap_pointer_iterator& rhs) const noexcept {return data_ == rhs.data_;}
          /// @biref The inequality operator of specified underlyig itertators.
          /// @return true if underlying iterators are not equels; otherwise false.
          bool operator !=(const wrap_pointer_iterator& rhs) const  noexcept {return !operator==(rhs);}
          /// @}

        private:
          mutable value_t data_ = nullptr;
        };
      }
    }
  }
}
