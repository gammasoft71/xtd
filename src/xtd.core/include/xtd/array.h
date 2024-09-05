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
    /// @brief Represents the list value type.
    using value_type = type_t;
    /// @brief Represents the list allocator type.
    using allocator_type = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, value_type>::value, xtd::byte, value_type>::type>;
    /// @brief Represents the list base type.
    using base_type = std::vector<typename std::conditional<std::is_same<bool, value_type>::value, xtd::byte, value_type>::type, allocator_type>;
    /// @brief Represents the list size type (usually xtd::size).
    using size_type = xtd::size;
    /// @brief Represents the list difference type (usually xtd::ptrdiff).
    using difference_type = xtd::ptrdiff;
    /// @brief Represents the reference of list value type.
    using reference = value_type&;
    /// @brief Represents the const reference of list value type.
    using const_reference = const value_type&;
    /// @brief Represents the pointer of list value type.
    using pointer = value_type*;
    /// @brief Represents the const pointer of list value type.
    using const_pointer = const value_type*;
    /// @brief Represents the iterator of list value type.
    using iterator = xtd::collections::generic::ilist<type_t>::iterator;
    /// @brief Represents the const iterator of list value type.
    using const_iterator = xtd::collections::generic::ilist<type_t>::const_iterator;
    /// @brief Represents the reverse iterator of list value type.
    using reverse_iterator = typename base_type::reverse_iterator;
    /// @brief Represents the const reverse iterator of list value type.
    using const_reverse_iterator = typename base_type::const_reverse_iterator;
    /// @}
    
    /// @name Public Fields
    
    /// @{
    /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
    inline static constexpr size_type npos = xtd::collections::generic::ilist<type_t>::npos;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
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
    
    /// @brief Gets the number of elements contained in the xtd::collections::generic::list <type_t>.
    /// @return The number of elements contained in the xtd::collections::generic::list <type_t>.
    /// @par Examples
    /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::collections::generic::list <type_t>.
    /// @include generic_list.cpp
    /// The following example demonstrates several properties and methods of the xtd::collections::generic::list <type_t> generic class of type string. (For an example of a xtd::collections::generic::list <type_t> of complex types, see the xtd::collections::generic::list::contains method.)
    ///
    /// The parameterless constructor is used to create a list of strings with the default capacity. The xtd::collections::generic::list::capacity property is displayed and then the xtd::collections::generic::list::add method is used to add several items. The items are listed, and the xtd::collections::generic::list::capacity property is displayed again, along with the xtd::collections::generic::list::count property, to show that the capacity has been increased as needed.
    ///
    /// The xtd::collections::generic::list::contains method is used to test for the presence of an item in the list, the Insert method is used to insert a new item in the middle of the list, and the contents of the list are displayed again.
    ///
    /// The default xtd::collections::generic::list::operator [] is used to retrieve an item, the xtd::collections::generic::list::remove method is used to remove the first instance of the duplicate item added earlier, and the contents are displayed again. The xtd::collections::generic::list::remove method always removes the first instance it encounters.
    ///
    /// The xtd::collections::generic::list::trim_excess method is used to reduce the capacity to match the count, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed. If the unused capacity had been less than 10 percent of total capacity, the list would not have been resized.
    ///
    /// Finally, the xtd::collections::generic::list::clear method is used to remove all items from the list, and the xtd::collections::generic::list::capacity and xtd::collections::generic::list::count properties are displayed.
    /// @include generic_list2.cpp
    /// @remarks xtd::collections::generic::list::capacity is the number of elements that the xtd::collections::generic::list <type_t> can store before resizing is required, whereas xtd::collections::generic::list::count is the number of elements that are actually in the xtd::collections::generic::list <type_t>.
    /// @remarks xtd::collections::generic::list::capacity is always greater than or equal to xtd::collections::generic::list::count. If xtd::collections::generic::list::count exceeds xtd::collections::generic::list::capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
    /// @remarks If the capacity is significantly larger than the count and you want to reduce the memory used by the xtd::collections::generic::list <type_t>, you can decrease capacity by calling the xtd::collections::generic::list::trim_excess method or by setting the xtd::collections::generic::list::capacity property explicitly to a lower value. When the value of xtd::collections::generic::list::capacity is set explicitly, the internal array is also reallocated to accommodate the specified capacity, and all the elements are copied.
    /// @remarks Retrieving the value of this property is an O(1) operation; setting the property is an O(n) operation, where n is the new capacity.
    size_type count() const noexcept override {return size();}

    /// @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to xtd::collections::generic::list::rend().
    /// @return Reverse iterator to the first element.
    /// @remarks If the vector is empty, the returned iterator will be equal to xtd::collections::generic::list::rend().
    virtual const_reverse_iterator crbegin() const noexcept {return data_->items.crbegin();}
    
    /// @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as a placeholder, attempting to access it results in undefined behavior.
    /// @return Reverse iterator to the element following the last element.
    /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
    virtual const_reverse_iterator crend() const noexcept {return data_->items.crend();}
    
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::size()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
    virtual pointer data() noexcept {return (pointer)data_->items.data();}
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::size()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
    virtual const_pointer data() const noexcept {return (pointer)data_->items.data();}
    
    /// @brief Checks if the container has no elements, i.e. whether xtd::collections::generic::list::begin() == xtd::collections::generic::list::end().
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
    
    /// @brief Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(xtd::collections::generic::list::begin(), xtd::collections::generic::list::end()) for the largest container.
    /// @return Maximum number of elements.
    virtual size_type max_size() const noexcept {return data_->items.max_size();}

    /// @brief Gets the rank (number of dimensions) of the array.
    /// @return int32 The rank (number of dimensions) of the array.
    /// @par Examples
    /// The following code example demonstrates methods to get the rank of an array.
    /// @include ArrayGetLength.cpp
    virtual xtd::size rank() const noexcept {return 1;}

    /// @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to xtd::collections::generic::list::rend().
    /// @return Reverse iterator to the first element.
    /// @remarks If the vector is empty, the returned iterator will be equal to xtd::collections::generic::list::rend().
    virtual reverse_iterator rbegin() noexcept {return data_->items.rbegin();}
    /// @brief Returns a reverse iterator to the first element of the reversed vector. It corresponds to the last element of the non-reversed vector. If the vector is empty, the returned iterator is equal to xtd::collections::generic::list::rend().
    /// @return Reverse iterator to the first element.
    /// @remarks If the vector is empty, the returned iterator will be equal to xtd::collections::generic::list::rend().
    virtual const_reverse_iterator rbegin() const noexcept {return data_->items.rbegin();}
    
    /// @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as a placeholder, attempting to access it results in undefined behavior.
    /// @return Reverse iterator to the element following the last element.
    /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
    virtual reverse_iterator rend() noexcept {return data_->items.rend();}
    /// @brief Returns a reverse iterator to the element following the last element of the reversed vector. It corresponds to the element preceding the first element of the non-reversed vector. This element acts as a placeholder, attempting to access it results in undefined behavior.
    /// @return Reverse iterator to the element following the last element.
    /// @remarks This element acts as a placeholder; attempting to access it results in undefined behavior.
    virtual const_reverse_iterator rend() const noexcept {return data_->items.rend();}

    /// @brief Returns the number of elements in the container, i.e. std::distance(xtd::collections::generic::list::begin(), xtd::collections::generic::list::end()).
    /// @return The number of elements in the container.
    virtual size_type size() const noexcept {return data_->items.size();}
    
    const xtd::object& sync_root() const noexcept override {return data_->sync_root;}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Returns a reference to the element at specified location pos, with bounds checking.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If pos is not within the range of the container.
    virtual reference at(size_type index) {
      if (index >= count()) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      return (reference)data_->items.at(index);
    }
    /// @brief Returns a reference to the element at specified location pos, with bounds checking.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception std::out_of_range If pos is not within the range of the container.
    virtual const_reference at(size_type index) const {
      if (index >= count()) __throw_index_out_of_range_exception(__FILE__, __LINE__, __func__);
      return (reference)data_->items.at(index);
    }
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
    /// @param other Another container to use as data source.
    /// @return This current instance.
    basic_array& operator =(const basic_array& other) = default;
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container). other is in a valid but unspecified state afterwards.
    /// @param other Another base type container to use as data source.
    /// @return This current instance.
    basic_array& operator =(basic_array&& other) noexcept {
      data_->version = std::move(other.data_->version);
      data_->items = std::move(other.data_->items);
      data_->lower_bound = std::move(other.data_->lower_bound);
      data_->upper_bound = std::move(other.data_->upper_bound);
      return *this;
    }
    /// @brief Replaces the contents with those identified by initializer list ilist.
    /// @param items Initializer list to use as data source
    /// @return This current instance.
    basic_array& operator =(std::initializer_list<type_t>& items) {
      data_->version = 0;
      data_->items = items;
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
    /// @}

  private:
    template<typename type_array_t, xtd::size rank_array_t, typename allocator_array_t>
    friend class array_;
    
    basic_array() = default;
    basic_array(const array_<size_type, 1>& lengths);
    
    basic_array(const_pointer array, xtd::size length) {
      if (array == null) __throw_argument_null_exception(__FILE__, __LINE__, __func__);
      data_->items = base_type {array, length};
      data_->upper_bound[0] = length - 1;
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
