/// @file
/// @brief Contains xtd::fixed_array class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "array.hpp"
#include "iequatable.hpp"
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
  template<typename type_t, xtd::usize len>
  class fixed_array : public xtd::object, public xtd::collections::generic::ienumerable<type_t>, public xtd::iequatable<fixed_array<type_t, len>> {
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
    /// @brief Represents the array size type (usually xtd::usize).
    using size_type = xtd::usize;
    /// @brief Represents the array difference type (usually xtd::ptrdiff).
    using difference_type = xtd::ptrdiff;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the fixed_array class that is empty.
    /// @remarks The fixed_array class is not thread safe.
    fixed_array() = default;
    /// @brief Initializes a new instance of the fixed_array class with specified initializer list.
    /// @param items The initializer list to initialize the elements of the container with.
    /// @remarks The fixed_array class is not thread safe.
    fixed_array(std::initializer_list<type_t> items) {
      auto index = xtd::usize {0};
      for (const auto& item : items)
        items_[index++] = item;
    }
    /// @}

    /// @cond
    fixed_array(fixed_array&&) = default;
    fixed_array& operator =(fixed_array&&) = default;
    fixed_array(const fixed_array&) = default;
    fixed_array& operator =(const fixed_array&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the number of elements contained in the xtd::fixed_array <type_t>.
    /// @return The number of elements contained in the xtd::fixed_array <type_t>.
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
    [[nodiscard]] virtual auto empty() const noexcept -> bool {return len == xtd::usize {0};}
    
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
    
    /// @name Public Methods
    
    /// @{
    /// @brief Clears the contents of this xtd::span <type> object.
    /// @remarks The xtd::span::clear method sets the items in the xtd::span <type_t> object to their default values. It does not remove items from the xtd::span <type_t>.
    auto clear() noexcept -> void {fill(value_type {});}
    
    /// @brief Determines whether an element is in the array.
    /// @param value The object to be added to the end of the array.
    [[nodiscard]] auto contains(const value_type& value) const noexcept -> bool {
      for (const auto& item : items_)
        if (xtd::collections::generic::helpers::equator<type_t> {}(reinterpret_cast<const value_type&>(item), value)) return true;
      return false;
    }
    
    /// @brief Copies the entire xtd::array <type_t> to a compatible one-dimensional array.
    /// @param array The one-dimensional xtd::array that is the destination of the elements copied from ICollection. The xtd::array must have zero-based indexing.
    /// @exception xtd::argument_exception  The number of elements in the source xtd::array <type_t> is greater than the number of elements that the destination array can contain.
    auto copy_to(xtd::array<value_type>& array) const -> void {
      copy_to(0, array, 0);
    }
    
    /// @brief Copies the elements of the xtd::array <type_t> to an xtd::array, starting at a particular xtd::array index.
    /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
    /// @param array_index The zero-based index in `array` at which copying begins.
    /// @exception xtd::argument_exception The number of elements in the source xtd::array <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
    auto copy_to(xtd::array<value_type>& array, size_type array_index) const -> void {
      return copy_to(0, array, array_index);
    }
    /// @brief Copies the elements of the xtd::array <type_t> from a specified index to an xtd::array, starting at a particular xtd::array index.
    /// @param index The zero-based index in the source fixed_array at which copying begins.
    /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
    /// @param array_index The zero-based index in `array` at which copying begins.
    /// @exception xtd::argument_exception The number of elements in the source xtd::array <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
    auto copy_to(const size_type index, xtd::array<value_type>& array, size_type array_index) const -> void {
      return copy_to(index, array, array_index, length() - index);
    }
    /// @brief Copies the elements of the xtd::array <type_t> from a specified index to an xtd::array, starting at a particular xtd::array index.
    /// @param index The zero-based index in the source fixed_array at which copying begins.
    /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
    /// @param array_index The zero-based index in `array` at which copying begins.
    /// @param count The number of elements to copy.
    /// @exception xtd::argument_exception The number of elements in the source xtd::array <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
    auto copy_to(const size_type index, xtd::array<value_type>& array, size_type array_index, size_type count) const -> void {
      if (array.rank() != 1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
      if (index + count > self_.length() || array_index + count > array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      for (auto i = index; i < (index + count); ++i)
        array[array_index++] = self_[i];
    }
    
    /// @brief Determines whether this instance and a specified object, which must also be a xtd::fixed_array object, have the same value.
    /// @param obj The fixed_array to compare to this instance.
    /// @return `true` if `obj` is a xtd::fixed_array and its value is the same as this instance; otherwise, `false`.
    [[nodiscard]] auto equals(const object & obj) const noexcept -> bool override {return dynamic_cast<const fixed_array<value_type, len>*>(&obj) && equals(static_cast<const fixed_array<value_type, len>&>(obj));}
    /// @brief Determines whether this instance and another specified xtd::fixed_array object have the same value.
    /// @param value The fixed_array to compare to this instance.
    /// @return `true` if the `value` of the value parameter is the same as the value of this instance; otherwise, `false`.
    /// @remarks This method performs an ordinal (case-sensitive) comparison.
    [[nodiscard]] auto equals(const fixed_array & rhs) const noexcept -> bool override {
      if (count() != rhs.count()) return false;
      for (size_type i = 0; i < count(); i++)
        if (!xtd::collections::generic::helpers::equator<type_t> {}(items_[i], rhs.items_[i])) return false;
      return true;
    }

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
    
    /// @brief Determines the index of a specific item in the xtd::array <type_t>.
    /// @param value The object to locate in the xtd::array.
    /// @return The index of value if found in the array; otherwise, xtd::collections::generic::ilist::npos.
    [[nodiscard]] auto index_of(const value_type& value) const noexcept -> size_type {return index_of(value, 0, length());}
    /// @brief Determines the index of a specific item in the xtd::fixed_array <type_t>.
    /// @param value The object to locate in the xtd::fixed_array <type_t>.
    /// @param index The zero-based starting index of the search.
    /// @return The index of value if found in the xtd::fixed_array; otherwise, xtd::collections::generic::ilist::npos.
    /// @exception xtd::argument_out_of_range_exception `index` is outside the range of valid indexes for the xtd::fixed_array <type_t>.
    [[nodiscard]] auto index_of(const value_type& value, size_type index) const -> size_type {return index_of(value, index, length() - index);}
    /// @brief Determines the index of a specific item in the xtd::fixed_array <type_t>.
    /// @param value The object to locate in the xtd::fixed_array <type_t>.
    /// @param index The zero-based starting index of the search.
    /// @param count The number of elements in the section to search
    /// @return The index of value if found in the xtd::fixed_array; otherwise, xtd::collections::generic::ilist::npos.
    /// @exception xtd::argument_out_of_range_exception `index` and `countù  do not specify a valid section in the xtd::fixed_array <type_t>.
    [[nodiscard]] auto index_of(const value_type& value, size_type index, size_type count) const -> size_type {
      if (index > length() || index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      for (auto increment = index; increment < (index + count); ++increment)
        if (xtd::collections::generic::helpers::equator<type_t> {}(items_[increment], value)) return increment;
      return xtd::npos;
    }
    
    /// @brief Sorts the elements in the entire xtd::fixed_array <type_t> using the default comparer.
    /// @exception xtd::invalid_operation_exception The default comparer xtd::collections::generic::comparer::default_comparer cannot find an implementation of the xtd::icomparable <type_t> generic interface.
    /// @par Examples
    /// The xtd::fixed_array::binary_search method overload is then used to search for two strings that are not in the list, and the xtd::fixed_array::insert method is used to insert them. The return value of the xtd::fixed_array::binary_search method is gretaer than xtd::fixed_array::count in each case, because the strings are not in the list. Taking the bitwise complement of this negative number produces the index of the first element in the list that is larger than the search string, and inserting at this location preserves the sort order. The second search string is larger than any element in the list, so the insertion position is at the end of the list.
    /// @include generic_list_binary_search.cpp
    /// @remarks This method uses the default comparer xtd::collections::generic::comparer::default_comparer for type `type_t` to determine the order of list elements. The xtd::collections::generic::comparer::default_comparer property checks whether type `type_t` implements the xtd::icomparable <type_t> generic interface and uses that implementation, if available. If not, xtd::collections::generic::comparer::default_comparer checks whether type T implements the xtd::icomparable interface. If type `type_t` does not implement either interface, xtd::collections::generic::comparer::default_comparer throws an xtd::invalid_operation_exception.
    /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might not be preserved. In contrast, a stable sort preserves the order of elements that are equal.
    /// @remarks On average, this method is an O(n log n) operation, where n is xtd::fixed_array::count; in the worst case it is an O(n ^ 2) operation.
    /// @remarks The following code example demonstrates the xtd::fixed_array::sort method overload and the xtd::fixed_array::binary_search method overload. A xtd::fixed_array <type_t> of strings is created and populated with four strings, in no particular order. The list is displayed, sorted, and displayed again.
    auto sort() -> fixed_array& {return sort(dynamic_cast<const xtd::collections::generic::icomparer<type_t>&>(xtd::collections::generic::comparer<type_t>::default_comparer));}
    
    /// @brief Sorts the elements in the entire xtd::fixed_array <type_t> using the specified xtd::comparison <type_t>.
    /// @exception xtd::argument_exception The implementation of comparison caused an error during the sort. For example, comparison might not return 0 when comparing an item with itself.
    /// @remarks If comparison is provided, the elements of the xtd::fixed_array <type_t> are sorted using the method represented by the delegate.
    /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might not be preserved. In contrast, a stable sort preserves the order of elements that are equal.
    /// @remarks On average, this method is an O(n log n) operation, where n is xtd::fixed_array::count; in the worst case it is an O(n ^ 2) operation.
    template<typename comparison_t>
    auto sort(comparison_t&& comparison) -> fixed_array& {
      std::sort(items_, items_ + length(), [&](const type_t& x, const type_t& y) {return comparison(x, y) < 0;});
      return self_;
    }
    
    /// @brief Sorts the elements in the entire xtd::fixed_array <type_t> using the specified comparer.
    /// @param comparer The xtd::collections::generic::icomparer <type_t> implementation to use when comparing elements, or null to use the default comparer xtd::collections::generic::comparer::default_comparer.
    /// @exception xtd::argument_exception The implementation of comparison caused an error during the sort. For example, comparison might not return 0 when comparing an item with itself.
    /// @remarks If comparer is provided, the elements of the xtd::fixed_array <type_t> are sorted using the specified xtd::collections::generic::icomparer <type_t> implementation.
    /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might not be preserved. In contrast, a stable sort preserves the order of elements that are equal.
    /// @remarks On average, this method is an O(n log n) operation, where n is xtd::fixed_array::count; in the worst case it is an O(n ^ 2) operation.
    auto sort(const xtd::collections::generic::icomparer<type_t>& comparer) -> fixed_array& {
      return sort(0, count(), comparer);
    }
    
    /// @brief Sorts the elements in a range of elements in xtd::fixed_array <type_t> using the specified comparer.
    /// @param index The zero-based starting index of the range to sort.
    /// @param count The length of the range to sort.
    /// @param comparer The xtd::collections::generic::icomparer <type_t> implementation to use when comparing elements, or null to use the default comparer xtd::collections::generic::comparer::default_comparer.
    /// @exception xtd::argument_exception The implementation of comparison caused an error during the sort. For example, comparison might not return 0 when comparing an item with itself.
    /// @remarks If comparer is provided, the elements of the xtd::fixed_array <type_t> are sorted using the specified xtd::collections::generic::icomparer <type_t> implementation.
    /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might not be preserved. In contrast, a stable sort preserves the order of elements that are equal.
    /// @remarks On average, this method is an O(n log n) operation, where n is xtd::fixed_array::count; in the worst case it is an O(n ^ 2) operation.
    auto sort(xtd::usize index, xtd::usize count, const xtd::collections::generic::icomparer<type_t>& comparer) -> fixed_array& {
      if (index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
      std::sort(items_, items_ + length(), xtd::collections::generic::helpers::lesser<type_t> {comparer});
      return self_;
    }

    /// @brief Copies the elements of the xtd::fixed_array <type_t> to a new array.
    /// @return An array containing copies of the elements of the xtd::fixed_array <type_t, xtd::usize>.
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
