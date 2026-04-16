/// @file
/// @brief Contains xtd::fixed_array class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "array.hpp"
#include "optional.hpp"
#include "npos.hpp"
#include "string.hpp"
#include "collections/generic/ienumerable.hpp"
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
  class fixed_array : public xtd::object, public xtd::collections::generic::ienumerable<type_t> {
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
    /// @brief Represents the pointer of array value type.
    using pointer = value_type*;
    /// @brief Represents the const pointer of array value type.
    using const_pointer = const value_type*;
    /// @brief Represents the array size type (usually xtd::size).
    using size_type = xtd::size;
    /// @brief Represents the array difference type (usually xtd::ptrdiff).
    using difference_type = xtd::ptrdiff;
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
    
    /// @brief Returns an enumerator that iterates through a collection.
    /// @return An xtd::collections::generic::enumerator object that can be used to iterate through the collection.
    [[nodiscard]] auto get_enumerator() const -> xtd::collections::generic::enumerator<value_type> override {
      struct fixed_array_enumerator : public xtd::collections::generic::ienumerator < value_type > {
        explicit fixed_array_enumerator(const fixed_array & items) : items_(items) {}
        
        [[nodiscard]] const value_type& current() const override {
          if (index_ >= items_.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          return items_[index_];
        }
        
        bool move_next() override {return ++index_ < items_.count();}
        
        void reset() override {index_ = xtd::npos;}
        
      private:
        size_type index_ = xtd::npos;
        const fixed_array& items_;
      };
      return {new_ptr<fixed_array_enumerator>(*this)};
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
