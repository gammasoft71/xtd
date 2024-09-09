/// @file
/// @brief Contains xtd::array class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#define __XTD_CORE_INTERNAL__
#include "internal/__array_definition.h"
#include "internal/__external_exceptions.h"
#undef __XTD_CORE_INTERNAL__
#include "collections/generic/enumerator.h"
#include "collections/generic/icomparer.h"
#include "collections/generic/ilist.h"
#include "core_export.h"
#include "int64.h"
#include "new_ptr.h"
#include "object.h"
#include <algorithm>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  class array_object : public xtd::object {
    template<typename type_t, typename allocator_t>
    friend class basic_array;
    
  public:
    array_object() = default;
  };

  template<typename type_t, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
  class basic_array : public xtd::array_object, public xtd::collections::generic::ilist<type_t> {
    class comparer {
    public:
      comparer(const xtd::collections::generic::icomparer<type_t>* comparer) : comparer_(comparer) { }
      comparer(const comparer&) = default;
      comparer(comparer&&) = default;
      comparer& operator=(const comparer& comparer) = default;
      comparer& operator=(comparer&&) = default;
      
      bool operator()(const type_t& e1, const type_t& e2) const noexcept {return comparer_ && comparer_->compare(e1, e2) < 0;}
      
    private:
      const xtd::collections::generic::icomparer<type_t>* comparer_;
    };
    
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the array value type.
    using value_type = type_t;
    /// @brief Represents the array allocator type.
    using allocator_type = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, value_type>::value, xtd::byte, value_type>::type>;
    /// @brief Represents the array base type.
    using base_type = std::vector<typename std::conditional<std::is_same<bool, value_type>::value, xtd::byte, value_type>::type, allocator_type>;
    /// @brief Represents the array size type (usually xtd::size).
    using size_type = xtd::size;
    /// @brief Represents the array difference type (usually xtd::ptrdiff).
    using difference_type = xtd::ptrdiff;
    /// @brief Represents the reference of array value type.
    using reference = value_type&;
    /// @brief Represents the const reference of array value type.
    using const_reference = const value_type&;
    /// @brief Represents the pointer of array value type.
    using pointer = value_type*;
    /// @brief Represents the const pointer of array value type.
    using const_pointer = const value_type*;
    /// @brief Represents the iterator of array value type.
    using iterator = xtd::collections::generic::ilist<type_t>::iterator;
    /// @brief Represents the const iterator of array value type.
    using const_iterator = xtd::collections::generic::ilist<type_t>::const_iterator;
    /// @brief Represents the reverse iterator of array value type.
    using reverse_iterator = typename base_type::reverse_iterator;
    /// @brief Represents the const reverse iterator of array value type.
    using const_reverse_iterator = typename base_type::const_reverse_iterator;
    /// @}
    
    /// @name Public Fields
    
    /// @{
    /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
    inline static constexpr size_type npos = xtd::collections::generic::ilist<type_t>::npos;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    basic_array(const basic_array& array) {*data_ = *array.data_;}
    basic_array(basic_array&& array) = default;
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
    
    /// @brief Returns an iterator to the first element of the enumarable.
    /// @return Iterator to the first element.
    const_iterator begin() const noexcept override {return xtd::collections::generic::ienumerable<value_type>::begin();}
    /// @brief Returns an iterator to the first element of the enumarable.
    /// @return Iterator to the first element.
    iterator begin() noexcept override {return xtd::collections::generic::ienumerable<value_type>::begin();}
    
    /// @brief Returns an iterator to the first element of the enumarable.
    /// @return Iterator to the first element.
    const_iterator cbegin() const noexcept override {return xtd::collections::generic::ienumerable<value_type>::cbegin();}
    
    /// @brief Returns an iterator to the element following the last element of the enumarable.
    /// @return Iterator to the element following the last element.
    const_iterator cend() const noexcept override {return xtd::collections::generic::ienumerable<value_type>::cend();}
    
    /// @brief Gets the number of elements contained in the xtd::array <type_t>.
    /// @return The number of elements contained in the xtd::array <type_t>.
    /// @par Examples
    /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::array <type_t>.
    /// @include generic_list.cpp
    /// The following example demonstrates several properties and methods of the xtd::array <type_t> generic class of type string. (For an example of a xtd::array <type_t> of complex types, see the xtd::array::contains method.)
    ///
    /// The parameterless constructor is used to create a array of strings with the default capacity. The xtd::array::capacity property is displayed and then the xtd::array::add method is used to add several items. The items are listed, and the xtd::array::capacity property is displayed again, along with the xtd::array::count property, to show that the capacity has been increased as needed.
    ///
    /// The xtd::array::contains method is used to test for the presence of an item in the array, the Insert method is used to insert a new item in the middle of the array, and the contents of the array are displayed again.
    ///
    /// The default xtd::array::operator [] is used to retrieve an item, the xtd::array::remove method is used to remove the first instance of the duplicate item added earlier, and the contents are displayed again. The xtd::array::remove method always removes the first instance it encounters.
    ///
    /// The xtd::array::trim_excess method is used to reduce the capacity to match the count, and the xtd::array::capacity and xtd::array::count properties are displayed. If the unused capacity had been less than 10 percent of total capacity, the array would not have been resized.
    ///
    /// Finally, the xtd::array::clear method is used to remove all items from the array, and the xtd::array::capacity and xtd::array::count properties are displayed.
    /// @include generic_list2.cpp
    /// @remarks xtd::array::capacity is the number of elements that the xtd::array <type_t> can store before resizing is required, whereas xtd::array::count is the number of elements that are actually in the xtd::array <type_t>.
    /// @remarks xtd::array::capacity is always greater than or equal to xtd::array::count. If xtd::array::count exceeds xtd::array::capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
    /// @remarks If the capacity is significantly larger than the count and you want to reduce the memory used by the xtd::array <type_t>, you can decrease capacity by calling the xtd::array::trim_excess method or by setting the xtd::array::capacity property explicitly to a lower value. When the value of xtd::array::capacity is set explicitly, the internal array is also reallocated to accommodate the specified capacity, and all the elements are copied.
    /// @remarks Retrieving the value of this property is an O(1) operation; setting the property is an O(n) operation, where n is the new capacity.
    size_type count() const noexcept override {return size();}

    /// @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to xtd::array::rend().
    /// @return Reverse iterator to the first element.
    /// @remarks If the vector is empty, the returned iterator will be equal to xtd::array::rend().
    virtual const_reverse_iterator crbegin() const noexcept {return data_->items.crbegin();}
    
    /// @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as a placeholder, attempting to access it results in undefined behavior.
    /// @return Reverse iterator to the element following the last element.
    /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
    virtual const_reverse_iterator crend() const noexcept {return data_->items.crend();}
    
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::array::data(), xtd::array::data() + xtd::array::size()) is always a valid range, even if the container is empty (xtd::array::data() is not dereferenceable in that case).
    virtual pointer data() noexcept {return (pointer)data_->items.data();}
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::array::data(), xtd::array::data() + xtd::array::size()) is always a valid range, even if the container is empty (xtd::array::data() is not dereferenceable in that case).
    virtual const_pointer data() const noexcept {return (pointer)data_->items.data();}
    
    /// @brief Checks if the container has no elements, i.e. whether xtd::array::begin() == xtd::array::end().
    /// @return true if the container is empty, false otherwise.
    virtual bool empty() const noexcept {return data_->items.empty();}

    /// @brief Returns an iterator to the element following the last element of the enumarable.
    /// @return Iterator to the element following the last element.
    const_iterator end() const noexcept override {return xtd::collections::generic::ienumerable<value_type>::end();}
    /// @brief Returns an iterator to the element following the last element of the enumarable.
    /// @return Iterator to the element following the last element.
    iterator end() noexcept override {return xtd::collections::generic::ienumerable<value_type>::end();}
    
    /// @brief Returns a reference to the first element in the container.
    /// @return Reference to the first element.
    /// @remarks Calling front on an empty container causes undefined behavior.
    virtual reference front() {return at(0);}
    /// @brief Returns a reference to the first element in the container.
    /// @return Reference to the first element.
    /// @remarks Calling front on an empty container causes undefined behavior.
    virtual const_reference front() const {return at(0);}
    
    bool is_fixed_size() const noexcept override {return false;}
    bool is_read_only() const noexcept override {return false;}
    bool is_synchronized() const noexcept override {return false;}
    
    /// @brief Returns the underlying base type items.
    /// @return The underlying base type items.
    virtual const base_type& items() const noexcept {return data_->items;}
    /// @brief Returns the underlying base type items.
    /// @return The underlying base type items.
    virtual base_type& items() noexcept {return data_->items;}

    /// @brief Gets a size that represents the total number of elements in all the dimensions of the array.
    /// @return A size that represents the total number of elements in all the dimensions of the array; zero if there are no elements in the array.
    /// @remarks Retrieving the value of this property is an O(1) operation.
    /// @par Examples
    /// The following code example demonstrates methods to get the length of an array.
    /// @include array_length.cpp
    virtual size_type length() const noexcept {return size();}
    /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the array.
    /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the array; zero if there are no elements in the array.
    /// @remarks Retrieving the value of this property is an O(1) operation.
    virtual xtd::int64 long_length() {return static_cast<xtd::int64>(size());}
    
    /// @brief Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(xtd::array::begin(), xtd::array::end()) for the largest container.
    /// @return Maximum number of elements.
    virtual size_type max_size() const noexcept {return data_->items.max_size();}

    /// @brief Gets the rank (number of dimensions) of the array.
    /// @return int32 The rank (number of dimensions) of the array.
    /// @par Examples
    /// The following code example demonstrates methods to get the rank of an array.
    /// @include arrayGetLength.cpp
    virtual xtd::size rank() const noexcept {return 1;}

    /// @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to xtd::array::rend().
    /// @return Reverse iterator to the first element.
    /// @remarks If the vector is empty, the returned iterator will be equal to xtd::array::rend().
    virtual reverse_iterator rbegin() noexcept {return data_->items.rbegin();}
    /// @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to xtd::array::rend().
    /// @return Reverse iterator to the first element.
    /// @remarks If the vector is empty, the returned iterator will be equal to xtd::array::rend().
    virtual const_reverse_iterator rbegin() const noexcept {return data_->items.rbegin();}
    
    /// @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as a placeholder, attempting to access it results in undefined behavior.
    /// @return Reverse iterator to the element following the last element.
    /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
    virtual reverse_iterator rend() noexcept {return data_->items.rend();}
    /// @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as a placeholder, attempting to access it results in undefined behavior.
    /// @return Reverse iterator to the element following the last element.
    /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
    virtual const_reverse_iterator rend() const noexcept {return data_->items.rend();}

    /// @brief Returns the number of elements in the container, i.e. std::distance(xtd::array::begin(), xtd::array::end()).
    /// @return The number of elements in the container.
    virtual size_type size() const noexcept {return data_->items.size();}
    
    const xtd::object& sync_root() const noexcept override {return data_->sync_root;}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Adds an object to the end of the xtd::array <type_t>.
    /// @param item The object to be added to the end of the xtd::array <type_t>.
    /// @)ar Examples
    /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::array <type_t>.
    /// @include generic_list4.cpp
    /// The following example demonstrates several properties and methods of the xtd::array <type_t> generic class, including the xtd::array::add method.
    /// The parameterless constructor is used to create a array of strings with a capacity of 0. The xtd::array::capacity property is displayed, and then the xtd::array::add method is used to add several items. The items are listed, and the xtd::array::capacity property is displayed again, along with the xtd::array::count property, to show that the capacity has been increased as needed.
    ///
    /// Other properties and methods are used to search for, insert, and remove elements from the array, and finally to clear the array.
    /// @include generic_list2.cpp
    /// @remarks xtd::array <type_t>  allows duplicate elements.
    /// @remarks If xtd::array::count already equals xtd::array::capacity, the capacity of the xtd::array <type_t> is increased by automatically reallocating the internal array, and the existing elements are copied to the new array before the new element is added.
    /// @remarks If xtd::array::count is less than xtd::array::capacity, this method is an O(1) operation. If the capacity needs to be increased to accommodate the new element, this method becomes an O(n) operation, where n is xtd::array::count.
    void add(const type_t& item) override {
      ++data_->version;
      data_->items.push_back(item);
    }

    /// @brief Returns a reference to the element at specified location pos, with bounds checking.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If `pos` is not within the range of the container.
    virtual reference at(size_type index) {
      if (index >= count()) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      return (reference)data_->items.at(index);
    }
    /// @brief Returns a reference to the element at specified location pos, with bounds checking.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If `pos` is not within the range of the container.
    virtual const_reference at(size_type index) const {
      if (index >= count()) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      return (reference)data_->items.at(index);
    }

    void clear() override {
      ++data_->version;
      data_->items.clear();
    }
    
    /// @brief Determines whether an element is in the array.
    /// @param value The object to be added to the end of the array.
    constexpr bool contains(const type_t& value) const noexcept override {
      for (const type_t& item : data_->items)
        if (item == value) return true;
      return false;
    }

    void copy_to(xtd::array<type_t>& array, size_type array_index) const override {
      if (array_index + length() > array.length()) __throw_argument_exception(__FILE__, __LINE__, __func__);
      
      for (auto increment = size_type {0}; increment < length(); ++increment)
        array[array_index + increment] = at(increment);
    }
    
    bool equals(const object& obj) const noexcept override {return is<basic_array<value_type>>(obj) && equals(static_cast<const basic_array<value_type>&>(obj));}
    bool equals(const basic_array& rhs) const noexcept override {return data_->items == rhs.data_->items && data_->version == rhs.data_->version && data_->lowerbound == rhs.data_->lowerbound && data_->upperbound == rhs.data_->upperbound;}

    /// @brief Assigns the value to all elements in the container.
    /// @param value The value to assign to the elements.
    virtual void fill(const value_type& value) noexcept {
      std::fill(begin(), end(), value);
    }

    xtd::collections::generic::enumerator<value_type> get_enumerator() const noexcept override {
      class basic_array_enumerator : public xtd::collections::generic::ienumerator<value_type> {
      public:
        explicit basic_array_enumerator(const basic_array& items, size_type version) : items_(items), version_(version) {}
        
        const value_type& current() const override {
          if (version_ != items_.data_->version) __throw_invalid_operation_exception("Collection was modified; enumeration operation may not execute.", __FILE__, __LINE__, __func__);
          return items_.at(index_);
        }
        
        bool move_next() override {
          if (version_ != items_.data_->version) __throw_invalid_operation_exception("Collection was modified; enumeration operation may not execute.", __FILE__, __LINE__, __func__);
          return ++index_ < items_.count();
        }
        
        void reset() override {
          version_ = items_.data_->version;
          index_ = basic_array::npos;
        }
        
      protected:
        const basic_array& items_;
        size_type index_ = basic_array::npos;
        size_type version_ = 0;
      };
      return {new_ptr<basic_array_enumerator>(*this, data_->version)};
    }
    
    /// @brief Gets the total number of elements in all the dimensions of the array.
    /// @param dimension A zero-based dimension of the array whose length needs to be determined.
    /// @return The total number of elements in all the dimensions of the array; zero if there are no elements in the array.
    /// @exception xtd::argument_out_of_range_exception `dimension` is equal to or greater than xtd::basic_array::rank.
    /// @par Examples
    /// The following code example demonstrates methods to get the length of an array.
    /// @include array_get_length.cpp
    constexpr size_type get_length(size_type dimension) const {return get_upper_bound(dimension) + 1;}
    
    /// @brief Gets the lower bound of the specified dimension in the array.
    /// @param dimension A zero-based dimension of the array whose lower bound needs to be determined.
    /// @return The lower bound of the specified dimension in the array.
    /// @exception xtd::argument_out_of_range_exception `dimension` is equal to or greater than xtd::basic_array::rank.
    /// @par Examples
    /// The following code example uses xtd::array::get_lower_bound and xtd::array::get_upper_bound to initialize a one-dimensional array and a multidimensional array.
    /// @include array_get_lower_bound.cpp
    constexpr size_type get_lower_bound(size_type dimension) const {
      if (dimension >= rank()) throw_argument_out_of_range_exception(__FILE__, __LINE__, __func__);
      return data_->lower_bound[dimension];
    }
    
    /// @brief Gets the upper bound of the specified dimension in the array.
    /// @param dimension A zero-based dimension of the array whose upper bound needs to be determined.
    /// @return The upper bound of the specified dimension in the array.
    /// @exception xtd::argument_out_of_range_exception `dimension` is equal to or greater than xtd::basic_array::rank.
    /// @par Examples
    /// The following code example uses xtd::array::get_lower_bound and xtd::array::get_upper_bound to initialize a one-dimensional array and a multidimensional array.
    /// @include array_get_lower_bound.cpp
    constexpr size_type get_upper_bound(size_type dimension) const {
      if (dimension >= rank()) throw_argument_out_of_range_exception(__FILE__, __LINE__, __func__);
      return data_->upper_bound[dimension];
    }

    /// @brief Gets the value at the specified position in the multidimensional array. The indexes are specified as 32-bit integers array.
    /// @param indexes An array that represents the position of the element to get.
    /// @return The value at the specified position in the multidimensional array.
    /// @exception xtd::index_out_of_range_exception Either `indexes` is outside the range of valid indexes for the corresponding dimension of the current array.
    const value_type& get_value(const xtd::array<xtd::size>& indexes) const;
    
    /// @brief Determines the index of a specific item in the List.xtd::array <type_t>.
    /// @param value The object to locate in the List.
    /// @return The index of value if found in the array; otherwise, xtd::collections::generic::ilist::npos.
    size_type index_of(const type_t& value) const noexcept override {
      if (count() == 0)  return npos;
      return index_of(*this, value, 0, count());
    }
    
    /// @brief Inserts an element into the xtd::array <type_t> at the specified index.
    /// @param index The zero-based index at which the new element should be inserted.
    /// @param value The element should be inserted into the xtd::array <type_t>.
    /// @exception xtd::argument_out_of_range_exception `index` is is greater than xtd::array::count.
    /// @remarks xtd::array <type_t> allows duplicate elements.
    void insert(size_type index, const type_t& value) override {
      if (index > count()) __throw_argument_out_of_range_exception(__FILE__, __LINE__, __func__);
      data_->items.insert(to_base_type_iterator(begin()) + index, value);
    }
    
    bool remove(const type_t& item) override {
      if (count() == 0)  return false;
      for (auto index = size_type {0}; index < count(); ++index) {
        if (at(index) != item) continue;
        remove_at(index);
        return true;
      }
      return false;
    }
    
    /// @brief Removes the element at the specified index of the xtd::array <type_t>.
    /// @param index The zero-based index of the item to remove
    /// @exception xtd::argument_out_of_range_exception `index` is greater than xtd::array::count.
    void remove_at(size_type index) override {
      if (index >= count()) __throw_argument_out_of_range_exception(__FILE__, __LINE__, __func__);
      
      if (index == count() - 1) data_->items.pop_back();
      else data_->items.erase(to_base_type_iterator(begin()) + index);
    }

    /// @brief Sets a value to the element at the specified position in the multidimensional array.
    /// @param value The new value for the specified element.
    /// @param indexes An array that represents the position of the element to set.
    /// @exception IndexOutOfRangeException Either `indexes` is outside the range of valid indexes for the current array.
    void set_value(const type_t& value, const array<xtd::size>& indexes) {operator()(indexes) = value;}

    /// @brief Exchanges the contents and capacity of the container with those of other. Does not invoke any move, copy, or swap operations on individual elements.
    /// @remarks All iterators and references remain valid. The xtd::array::end() iterator is invalidated.
    virtual void swap(basic_array& other) noexcept {
      ++data_->version;
      data_->items.swap(other.data_->items);
    }

    string to_string() const noexcept override {return xtd::string::format("[{}]", xtd::string::join(", ", *this));}    
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Determines the index of a specific item in the array specified.
    /// @param array The object to locate in the array.
    /// @param value The object to locate in the array.
    /// @return int32 The index of value if found in the array; otherwise, -1.
    /// @par Examples
    /// The following code example shows how to determine the index of the first occurrence of a specified element.
    /// @include array_index_of.cpp
    static size_type index_of(const basic_array& array, const value_type& value) {return index_of(array, value, 0, array.Length);}
    
    /// @brief Determines the index of a specific item in the array specified.
    /// @param array The object to locate in the array.
    /// @param value The object to locate in the array.
    /// @param index The zero-based starting index of the search.
    /// @return int32 The index of value if found in the array; otherwise, -1.
    /// @exception xtd::argument_out_of_range_exception The parameters `index` is less than 0.
    /// @par Examples
    /// The following code example shows how to determine the index of the first occurrence of a specified element.
    /// @include array_index_of.cpp
    static size_type index_of(const basic_array& array, const value_type& value, size_type index) {return index_of(array, value, index, array.Length - index);}
    
    /// @brief Determines the index of a specific item in the array specified.
    /// @param array The object to locate in the array.
    /// @param value The object to locate in the array.
    /// @param index The zero-based starting index of the search.
    /// @param count The number of elements in the section to search
    /// @return int32 The index of value if found in the array; otherwise, -1.
    /// @exception xtd::argument_out_of_range_exception The parameters `index` and `count` do not specify a valid section in the 'array'.
    /// @par Examples
    /// The following code example shows how to determine the index of the first occurrence of a specified element.
    /// @include array_index_of.cpp
    static size_type index_of(const basic_array& array, const value_type& value, size_type index, size_type count) {
      if (index > array.length() || index + count > array.length()) __throw_argument_exception(__FILE__, __LINE__, __func__);
      
      for (auto increment = size_type {0}; increment < count; ++increment) {
        if (array[index + increment] == value)
          return index + increment;
      }
      return npos;
    }
    /// @}

    /// @name Public Operators
    
    /// @{
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
    /// @param other Another container to use as data source.
    /// @return This current instance.
    basic_array& operator =(const basic_array& other) {*data_ = *other.data_;}
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container). other is in a valid but unspecified state afterwards.
    /// @param other Another base type container to use as data source.
    /// @return This current instance.
    basic_array& operator =(basic_array&& other) noexcept = default;
    /// @brief Replaces the contents with those identified by initializer list ilist.
    /// @param items Initializer list to use as data source
    /// @return This current instance.
    basic_array& operator =(std::initializer_list<type_t>& items) {
      data_->version = 0;
      data_->items = items;
      data_->upper_bound[0] = data_->items.size() - 1;
      return *this;
    }
    
    /// @brief Returns a reference to the element at specified location index.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If pos is not within the range of the container.
    const_reference operator [](size_type index) const override {return at(index);}
    /// @brief Returns a reference to the element at specified location index.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If `index` is not within the range of the container.
    reference operator [](size_type index) override {return at(index);}
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    virtual operator const base_type&() const noexcept {return data_->items;}
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    virtual operator base_type&() noexcept {return data_->items;}

    /// @brief Gets the value at the specified position in the multidimensional array. The indexes are specified as a 32-bit integer array.
    /// @param indexes A 32-bit integer array that represents the multidimension index of the array element to get.
    /// @return The value at the specified position in the multidimensional array.
    /// @exception IndexOutOfRangeException Either each index is outside the range of valid indexes for the corresponding dimension of the current array.
    /// @par Examples
    /// The following code example shows how to use operator [] to list the elements of an array.
    /// @include arrayarrayOperatorFunctor.cpp
    type_t& operator()(const array<xtd::size>& indexes);
    
    /// @brief Gets the value at the specified position in the multidimensional array. The indexes are specified as a 32-bit integer array.
    /// @param indexes A 32-bit integer array that represents the multidimension index of the array element to get.
    /// @return The value at the specified position in the multidimensional array.
    /// @exception IndexOutOfRangeException Either each index is outside the range of valid indexes for the corresponding dimension of the current array.
    /// @par Examples
    /// The following code example shows how to use operator [] to list the elements of an array.
    /// @include arrayarrayOperatorFunctor.cpp
    const type_t& operator()(const array<xtd::size>& indexes) const;
    /// @}

  private:
    template<typename type_array_t, xtd::size rank_array_t, typename allocator_array_t>
    friend class array_;
    
    basic_array() = default;
    basic_array(const array_<size_type, 1>& lengths);
    
    basic_array(const_pointer array, xtd::size length) {
      if (array == null) __throw_argument_null_exception(__FILE__, __LINE__, __func__);
      data_->items = base_type {array, length};
      data_->upper_bound[0] = data_->items.size() - 1;
    }
    
    basic_array(const xtd::collections::generic::ienumerable<type_t>& enumerable) {
      for (const auto& value : enumerable)
        data_->items.push_back(value);
      data_->lower_bound.push_back(0);
      data_->upper_bound[0] = data_->items.size() - 1;
    }
    
    basic_array(const std::vector<type_t>& array) {
      data_->items = array;
      data_->upper_bound[0] = data_->items.size() - 1;
    }
    
    basic_array(std::vector<type_t>&& array) {
      data_->items = std::move(array);
      data_->upper_bound[0] = data_->items.size() - 1;
    }
    
    
    basic_array(std::initializer_list<type_t> il) {
      data_->items.append(il);
      data_->upper_bound[0] = data_->items.size() - 1;
    }
    
    basic_array(std::initializer_list<std::initializer_list<type_t>> il)  {
      for (const std::initializer_list<type_t>& il1 : il)
        data_->items.append(il1);
      data_->upper_bound[0] = il.size() - 1;
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back((*il.begin()).size() - 1);
    }
    
    basic_array(std::initializer_list<std::initializer_list<std::initializer_list<type_t>>> il)  {
      for (const std::initializer_list<std::initializer_list<type_t>>& il1 : il)
        for (const std::initializer_list<type_t>& il2 : il1)
          data_->items.append(il2);
      data_->upper_bound[0] = il.size() - 1;
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back((*il.begin()).size() - 1);
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back((*(*il.begin()).begin()).size() - 1);
    }
    
    template<typename iterator_t>
    basic_array(iterator_t first, iterator_t last) {
      data_->items.append(first, last);
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back(data_->items.size() - 1);
    }

    typename base_type::iterator to_base_type_iterator(iterator value) noexcept {
      if (value == begin()) return data_->items.begin();
      if (value == end()) return data_->items.end();
      return data_->items.begin() + (value - begin());
    }
    
    iterator to_iterator(typename base_type::iterator value) noexcept {
      if (value == data_->items.begin()) return begin();
      if (value == data_->items.end()) return end();
      return begin() + (value - data_->items.begin());
    }
    
    struct data {
      size_type version = 0;
      base_type items;
      std::vector<size_type> lower_bound {0};
      std::vector<size_type> upper_bound {std::numeric_limits<xtd::size>::max()};
      object sync_root;
    };
    
    xtd::ptr<struct data> data_ = xtd::new_ptr<struct data>();
  };
}

#define __XTD_ARRAY_INTERNAL__
#include "array.hpp"
#undef __XTD_ARRAY_INTERNAL__
