/// @file
/// @brief Contains xtd::collections::generic::helpers::wrap_pointer_iterator class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../../icomparable.hpp"
#include "../../../iequatable.hpp"
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
        /// template<class value_t, class iterator_tag_t = std::bidirectional_iterator_tag>
        /// class wrap_pointer_iterator : public xtd::icomparable<wrap_pointer_iterator<value_t, iterator_tag_t>>, public xtd::iequatable<wrap_pointer_iterator<value_t, iterator_tag_t>>;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/genric/helpers/wrap_pointer_iterator>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic::helpers
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core helpers_generic_collections
        template<class value_t, class iterator_tag_t = std::bidirectional_iterator_tag>
        class wrap_pointer_iterator : public xtd::icomparable<wrap_pointer_iterator<value_t, iterator_tag_t>>, public xtd::iequatable<wrap_pointer_iterator<value_t, iterator_tag_t >> {
        public:
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the value type.
          using value_type = value_t;
          /// @brief Represents the iterator category type.
          using iterator_category = iterator_tag_t;
          /// @brief Represents the iterator concept type.
          using iterator_concept  = iterator_tag_t;
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
          /// @brief Initializes a new instance of the xtd::collections::generic::helpers::wrap_pointer_iterator class.
          wrap_pointer_iterator() = default;
          /// @brief Initializes a new instance of the xtd::collections::generic::helpers::wrap_pointer_iterator class with specified pointer value.
          /// @param pointer The pointer value.
          explicit wrap_pointer_iterator(value_t pointer) noexcept : data_ {pointer} {}
          /// @}
          
          /// @cond
          wrap_pointer_iterator(const wrap_pointer_iterator& value) noexcept = default;
          wrap_pointer_iterator& operator =(const wrap_pointer_iterator& value) noexcept = default;
          wrap_pointer_iterator(wrap_pointer_iterator&& value) noexcept = default;
          wrap_pointer_iterator& operator =(wrap_pointer_iterator&& value) noexcept = default;
          /// @endcond
          
          /// @name Public Properties
          
          /// @{
          /// @brief Gets iterator data.
          /// @return The iterator data.
          auto data() const noexcept -> const value_t& {return data_;}
          /// @brief Gets iterator data.
          /// @return The iterator data.
          auto data() noexcept -> value_t& {return data_;}
          /// @}
          
          /// @name Public methods
          
          /// @{
          auto compare_to(const wrap_pointer_iterator& rhs) const noexcept -> int32 override {return data_ < rhs.data_ ? -1 : data_ > rhs.data_ ? 1 : 0;}
          auto equals(const wrap_pointer_iterator& rhs) const noexcept -> bool override {return data_ == rhs.data_;}
          /// @}
          
          /// @name Public Operators
          
          /// @{
          /// @brief Returns reference to the current element, or a proxy holding it.
          /// @return The reference to the current element.
          auto operator *() const noexcept -> const std::remove_pointer_t<value_t>& {return *data_;}
          /// @brief Returns reference to the current element, or a proxy holding it.
          /// @return The reference to the current element.
          auto operator *() noexcept -> std::remove_pointer_t<value_t>& {return *data_;}
          /// @brief Returns pointer to the current element, or a proxy holding it.
          /// @return The pointer to the current element.
          auto operator ->() const noexcept -> const value_t& {return data_;}
          /// @brief Returns pointer to the current element, or a proxy holding it.
          /// @return The pointer to the current element.
          auto operator ->() noexcept -> value_t& {return data_;}
          
          /// @brief Pre increments the underlying iterator.
          /// @return The underlying iterator.
          auto operator ++() const noexcept -> wrap_pointer_iterator& {++data_; return *const_cast<wrap_pointer_iterator*>(this);}
          /// @brief Post increments the underlying iterator.
          /// @return The underlying iterator.
          auto operator ++(int) const noexcept -> wrap_pointer_iterator {auto current = *this; operator ++(); return current;}
          
          /// @brief Pre decrements the underlying iterator.
          /// @return The underlying iterator.
          auto operator --() const noexcept -> wrap_pointer_iterator& {--data_; return *const_cast<wrap_pointer_iterator*>(this);}
          /// @brief Post decrements the underlying iterator.
          /// @return The underlying iterator.
          auto operator --(int) const noexcept -> wrap_pointer_iterator {auto current = *this; operator --(); return current;}
          
          /// @brief Add operator with specified value.
          /// @param value The number to add to the underlying iterator.
          /// @return The underlying iterator.
          auto operator +(xtd::size value) const noexcept -> wrap_pointer_iterator {return wrap_pointer_iterator {data_ + value};}
          /// @brief Add equal operator with specified value.
          /// @param value The number to add to the underlying iterator.
          /// @return The underlying iterator.
          auto operator +=(xtd::size value) noexcept -> wrap_pointer_iterator& {*this = *this + value; return *this;}
          /// @brief Subtract The specified iterator from the current iterator.
          /// @param value The iterator to subtract from the current iterator.
          /// @return The difference between current iterator and the specified iterator.
          auto operator -(wrap_pointer_iterator value) const noexcept -> xtd::ptrdiff {return data_ - value.data_;}
          /// @}
          
        private:
          mutable value_t data_ = nullptr;
        };
      }
    }
  }
}
