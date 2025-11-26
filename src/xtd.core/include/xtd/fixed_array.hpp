/// @file
/// @brief Contains xtd::fixed_array class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
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
  template<class type_t, xtd::size len>
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
    virtual reference back() {return at(count() - 1);}
    /// @brief Returns a reference to the last element in the container.
    /// @return Reference to the first element.
    /// @remarks Calling front on an empty container causes undefined behavior.
    virtual const_reference back() const {return at(count() - 1);}
    
    /// @brief Returns an iterator to the first element of the enumerable.
    /// @return Iterator to the first element.
    const_iterator begin() const noexcept {return cbegin();}
    /// @brief Returns an iterator to the first element of the enumerable.
    /// @return Iterator to the first element.
    iterator begin() noexcept {return iterator {data()};}
    
    /// @brief Returns an iterator to the first element of the enumerable.
    /// @return Iterator to the first element.
    const_iterator cbegin() const noexcept {return const_iterator {data()};}
    
    /// @brief Returns an iterator to the element following the last element of the enumerable.
    /// @return Iterator to the element following the last element.
    const_iterator cend() const noexcept {return const_iterator {data() + len};}
    
    /// @brief Gets the number of elements contained in the xtd::collections::generic::list <type_t>.
    /// @return The number of elements contained in the xtd::collections::generic::list <type_t>.
    size_type count() const noexcept {return size();}
    
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::array::data(), xtd::array::data() + xtd::array::size()) is always a valid range, even if the container is empty (xtd::array::data() is not dereferenceable in that case).
    const_pointer data() const noexcept {return items_;}
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::array::data(), xtd::array::data() + xtd::array::size()) is always a valid range, even if the container is empty (xtd::array::data() is not dereferenceable in that case).
    pointer data() noexcept {return items_;}
    
    /// @brief Checks if the container has no elements, i.e. whether xtd::array::begin() == xtd::array::end().
    /// @return `true` if the container is empty, `false` otherwise.
    virtual bool empty() const noexcept {return len == xtd::size {0};}
    
    /// @brief Returns an iterator to the element following the last element of the enumerable.
    /// @return Iterator to the element following the last element.
    const_iterator end() const noexcept {return cend();}
    /// @brief Returns an iterator to the element following the last element of the enumerable.
    /// @return Iterator to the element following the last element.
    iterator end() noexcept {return iterator {data() + len};}
    /// @brief Returns a reference to the first element in the container.
    /// @return Reference to the first element.
    /// @remarks Calling front on an empty container causes undefined behavior.
    virtual reference front() {return at(0);}
    /// @brief Returns a reference to the first element in the container.
    /// @return Reference to the first element.
    /// @remarks Calling front on an empty container causes undefined behavior.
    virtual const_reference front() const {return at(0);}
    
    /// @brief Returns the underlying base type items.
    /// @return The underlying base type items.
    virtual const_base_type items() const noexcept {return items_;}
    /// @brief Returns the underlying base type items.
    /// @return The underlying base type items.
    virtual base_type items() noexcept {return items_;}
    
    /// @brief Gets a size that represents the total number of elements in all the dimensions of the array.
    /// @return A size that represents the total number of elements in all the dimensions of the array; zero if there are no elements in the array.
    /// @remarks Retrieving the value of this property is an O(1) operation.
    virtual size_type length() const noexcept {return len;}
    
    /// @brief Returns the number of elements in the container, i.e. std::distance(xtd::array::begin(), xtd::array::end()).
    /// @return The number of elements in the container.
    xtd::size size() const noexcept {return length();}
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Returns a reference to the element at specified location pos, with bounds checking.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If pos is not within the range of the container.
    virtual const_reference at(size_type index) const {
      if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return items_[index == epos ? size() - 1 : index];
    }
    /// @brief Returns a reference to the element at specified location pos, with bounds checking.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If pos is not within the range of the container.
    virtual reference at(size_type index) {
      if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return items_[index == epos ? size() - 1 : index];
    }
    
    /// @brief Clears the contents of this xtd::span <type> object.
    /// @remarks The xtd::span::clear method sets the items in the xtd::span <type_t> object to their default values. It does not remove items from the xtd::span <type_t>.
    void clear() noexcept {
      for (auto& item : *this)
        item = value_type {};
    }
    
    /// @brief Fills the elements of this span with a specified value.
    /// @param value The value to assign to each element of the span.
    void fill(const type_t& value) {
      for (auto& item : *this)
        item = value;
    }
    
    /// @brief Copies the elements of the xtd::collections::generic::list <type_t> to a new array.
    /// @return An array containing copies of the elements of the xtd::fixed_array <type_t, xtd::size>.
    virtual xtd::array<value_type> to_array() const noexcept {return size() ? xtd::array<value_type>(items_, items_ + len) : xtd::array<value_type> {};}
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    xtd::string to_string() const noexcept override {return xtd::string::format("[{}]", xtd::string::join(", ", *this));}
    /// @}
    
    /// @name Public Operators
    
    /// @{
    
    /// @brief Returns a reference to the element at specified location index.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If `index` is not within the range of the container.
    const_reference operator [](xtd::size index) const {return at(index);}
    /// @brief Returns a reference to the element at specified location index.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    reference operator [](xtd::size index) {return at(index);}
    /// @}
    
  private:
    type_t items_[len];
  };
  
  template <class type_t, class... args_t>
  fixed_array(type_t, args_t...) -> fixed_array < type_t, 1 + sizeof...(args_t) >;
}
