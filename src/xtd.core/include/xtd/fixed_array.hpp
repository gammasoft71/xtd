/// @file
/// @brief Contains xtd::fixed_array class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "array.hpp"
#include "optional.hpp"
#include "string.hpp"
#include "helpers/throw_helper.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a fixed array class.
  /// @par Header
  /// ```cpp
  /// #include <xtd/fixed_array>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t, xtd::size len>
  class fixed_array : public xtd::object {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the array value type.
    using value_type = type_t;
    /// @brief Represents the array base type.
    using base_type = value_type*;
    /// @brief Represents the const array base type.
    using const_base_type = const value_type*;
    /// @brief Represents the reference of array value type.
    using reference = value_type&;
    /// @brief Represents the const reference of array value type.
    using const_reference = const value_type&;
    /// @brief Represents the iterator of array value type.
    using iterator = value_type*;
    /// @brief Represents the const iterator of array value type.
    using const_iterator = const value_type*;
    /// @brief Represents the pointer of array value type.
    using pointer = value_type*;
    /// @brief Represents the const pointer of array value type.
    using const_pointer = const value_type*;
    /// @brief Represents the array size type (usually xtd::size).
    using size_type = xtd::size;
    /// @brief Represents the array difference type (usually xtd::ptrdiff).
    using difference_type = xtd::ptrdiff;
    /// @brief Represents the reverse iterator of array value type.
    using reverse_iterator = std::reverse_iterator<iterator>;
    /// @brief Represents the const reverse iterator of array value type.
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    fixed_array() = default;
    fixed_array(fixed_array&&) = default;
    fixed_array& operator =(fixed_array&&) = default;
    fixed_array(const fixed_array&) = default;
    fixed_array& operator =(const fixed_array&) = default;
    fixed_array(std::initializer_list<type_t> il) {
      auto index = xtd::size {0};
      for (const auto& item : il)
        items_[index++] = item;
    }
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief Returns a reference to the last element in the container.
    /// @return Reference to the first element.
    /// @remarks Calling front on an empty container causes undefined behavior.
    [[nodiscard]] virtual auto back() -> reference {return at(count() - 1);}
    /// @brief Returns a reference to the last element in the container.
    /// @return Reference to the first element.
    /// @remarks Calling front on an empty container causes undefined behavior.
    [[nodiscard]] virtual auto back() const -> const_reference {return at(count() - 1);}
    
    /// @brief Returns an iterator to the first element of the enumerable.
    /// @return Iterator to the first element.
    [[nodiscard]] auto begin() const noexcept -> const_iterator {return cbegin();}
    /// @brief Returns an iterator to the first element of the enumerable.
    /// @return Iterator to the first element.
    [[nodiscard]] auto begin() noexcept -> iterator {return iterator {data()};}
    
    /// @brief Returns an iterator to the first element of the enumerable.
    /// @return Iterator to the first element.
    [[nodiscard]] auto cbegin() const noexcept -> const_iterator {return const_iterator {data()};}
    
    /// @brief Returns an iterator to the element following the last element of the enumerable.
    /// @return Iterator to the element following the last element.
    [[nodiscard]] auto cend() const noexcept -> const_iterator {return const_iterator {data() + len};}
    
    /// @brief Gets the number of elements contained in the xtd::collections::generic::list <type_t>.
    /// @return The number of elements contained in the xtd::collections::generic::list <type_t>.
    [[nodiscard]] auto count() const noexcept -> size_type {return size();}
    
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::array::data(), xtd::array::data() + xtd::array::size()) is always a valid range, even if the container is empty (xtd::array::data() is not dereferenceable in that case).
    [[nodiscard]] auto data() const noexcept -> const_pointer {return items_;}
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::array::data(), xtd::array::data() + xtd::array::size()) is always a valid range, even if the container is empty (xtd::array::data() is not dereferenceable in that case).
    [[nodiscard]] auto data() noexcept -> pointer {return items_;}
    
    /// @brief Checks if the container has no elements, i.e. whether xtd::array::begin() == xtd::array::end().
    /// @return `true` if the container is empty, `false` otherwise.
    [[nodiscard]] virtual auto empty() const noexcept -> bool {return len == xtd::size {0};}
    
    /// @brief Returns an iterator to the element following the last element of the enumerable.
    /// @return Iterator to the element following the last element.
    [[nodiscard]] auto end() const noexcept -> const_iterator {return cend();}
    /// @brief Returns an iterator to the element following the last element of the enumerable.
    /// @return Iterator to the element following the last element.
    [[nodiscard]] auto end() noexcept -> iterator {return iterator {data() + len};}
    /// @brief Returns a reference to the first element in the container.
    /// @return Reference to the first element.
    /// @remarks Calling front on an empty container causes undefined behavior.
    [[nodiscard]] virtual auto front() -> reference {return at(0);}
    /// @brief Returns a reference to the first element in the container.
    /// @return Reference to the first element.
    /// @remarks Calling front on an empty container causes undefined behavior.
    [[nodiscard]] virtual auto front() const -> const_reference {return at(0);}
    
    /// @brief Returns the underlying base type items.
    /// @return The underlying base type items.
    [[nodiscard]] virtual auto items() const noexcept -> const_base_type {return items_;}
    /// @brief Returns the underlying base type items.
    /// @return The underlying base type items.
    [[nodiscard]] virtual auto items() noexcept -> base_type {return items_;}
    
    /// @brief Gets a size that represents the total number of elements in all the dimensions of the array.
    /// @return A size that represents the total number of elements in all the dimensions of the array; zero if there are no elements in the array.
    /// @remarks Retrieving the value of this property is an O(1) operation.
    [[nodiscard]] virtual auto length() const noexcept -> size_type {return len;}
    
    /// @brief Returns the number of elements in the container, i.e. std::distance(xtd::array::begin(), xtd::array::end()).
    /// @return The number of elements in the container.
    [[nodiscard]] auto size() const noexcept -> size_type {return length();}
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Returns a reference to the element at specified location pos, with bounds checking.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If pos is not within the range of the container.
    [[nodiscard]] virtual auto at(size_type index) const -> const_reference {return operator [](index);}
    /// @brief Returns a reference to the element at specified location pos, with bounds checking.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If pos is not within the range of the container.
    [[nodiscard]] virtual auto at(size_type index) -> reference {return operator [](index);}
    
    /// @brief Clears the contents of this xtd::span <type> object.
    /// @remarks The xtd::span::clear method sets the items in the xtd::span <type_t> object to their default values. It does not remove items from the xtd::span <type_t>.
    auto clear() noexcept -> void {fill(value_type {});}
    
    /// @brief Fills the elements of this span with a specified value.
    /// @param value The value to assign to each element of the span.
    auto fill(const value_type& value) -> void {
      for (auto& item : *this)
        item = value;
    }
    
    /// @brief Copies the elements of the xtd::collections::generic::list <type_t> to a new array.
    /// @return An array containing copies of the elements of the xtd::fixed_array <type_t, xtd::size>.
    [[nodiscard]] virtual auto to_array() const noexcept -> xtd::array<value_type> {return size() ? xtd::array<value_type>(items_, items_ + len) : xtd::array<value_type> {};}
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    [[nodiscard]] auto to_string() const noexcept -> xtd::string override {return xtd::string::format("[{}]", xtd::string::join(", ", *this));}
    /// @}
    
    /// @name Public Operators
    
    /// @{
    
    /// @brief Returns a reference to the element at specified location index.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If `index` is not within the range of the container.
    auto operator [](size_type index) const -> const_reference {
      if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return items_[index == epos ? size() - 1 : index];
    }
    /// @brief Returns a reference to the element at specified location index.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    auto operator [](size_type index) -> reference {
      if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return items_[index == epos ? size() - 1 : index];
    }
    /// @}
    
  private:
    type_t items_[len];
  };

  /// @cond
  // Deduction guides for xtd::fixed_array
  // {
  template<typename type_t, typename... args_t>
  fixed_array(type_t, args_t...) -> fixed_array <type_t, 1 + sizeof...(args_t)>;
  // }
  /// @endcond
}
