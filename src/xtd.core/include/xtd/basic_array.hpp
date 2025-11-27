/// @file
/// @brief Contains xtd::basic_array class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/array> or <xtd/array.hpp> instead."
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Base object that represent array.
  /// @par Definition
  /// ```cpp
  /// template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  /// class basic_array : public xtd::array_object, public xtd::collections::generic::ilist<type_t>, public xtd::iequatable<basic_array<type_t, allocator_t>>;
  /// ```
  /// @par Header
  /// ```cpp
  /// #include <xtd/array>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  class basic_array : public xtd::array_abstract_object, public xtd::collections::generic::ilist<type_t>, public xtd::iequatable<basic_array<type_t, allocator_t >> {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the array value type.
    using value_type = type_t;
    /// @brief Represents the array allocator type.
    using allocator_type = xtd::collections::generic::helpers::allocator<value_type>;
    /// @brief Represents the array base type.
    using base_type = typename xtd::collections::generic::helpers::raw_array<value_type, allocator_type>::base_type;
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
    using iterator = typename xtd::collections::generic::ienumerable<type_t>::iterator;
    /// @brief Represents the const iterator of array value type.
    using const_iterator = typename xtd::collections::generic::ienumerable<type_t>::const_iterator;
    /// @brief Represents the reverse iterator of array value type.
    using reverse_iterator = typename xtd::collections::generic::helpers::raw_array<value_type>::reverse_iterator;
    /// @brief Represents the const reverse iterator of array value type.
    using const_reverse_iterator = typename xtd::collections::generic::helpers::raw_array<value_type>::const_reverse_iterator;
    /// @}
    
    /// @name Public Fields
    
    /// @cond
    basic_array(basic_array&& array) = default;
    basic_array(const basic_array & array) { if (array.data_) *data_ = *array.data_;}
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    using xtd::collections::generic::extensions::enumerable<xtd::collections::generic::ienumerable<value_type>, value_type>::count;
    /// @brief Gets the number of elements contained in the xtd::array <type_t>.
    /// @return The number of elements contained in the xtd::array <type_t>.
    /// @remarks Retrieving the value of this property is an O(1) operation; setting the property is an O(n) operation, where n is the new capacity.
    size_type count() const noexcept override {return data_->items.size();}
    
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::array::data(), xtd::array::data() + xtd::array::size()) is always a valid range, even if the container is empty (xtd::array::data() is not dereferenceable in that case).
    virtual pointer data() noexcept {return (pointer)data_->items.data();}
    /// @brief Returns pointer to the underlying array serving as element storage.
    /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
    /// @remarks The pointer is such that range [xtd::array::data(), xtd::array::data() + xtd::array::size()) is always a valid range, even if the container is empty (xtd::array::data() is not dereferenceable in that case).
    virtual const_pointer data() const noexcept {return (pointer)data_->items.data();}
    
    /// @brief Gets a value indicating whether the xtd::collections::generic::ilist <type_t> has a fixed size.
    /// @return `true` if the xtd::collections::generic::ilist <type_t> has a fixed size; otherwise, `false`.
    /// @remarks A collection with a fixed size does not allow the addition or removal of elements after the collection is created, but it allows the modification of existing elements.
    bool is_fixed_size() const noexcept override {return true;}
    
    /// @brief Gets a value indicating whether the xtd::collections::generic::icollection <type_t> is read-only.
    /// @return `true` if the xtd::collections::generic::icollection <type_t> is read-only; otherwise, `false`.
    /// @remarks A collection that is read-only does not allow the addition or removal of elements after the collection is created. Note that read-only in this context does not indicate whether individual elements of the collection can be modified, since the xtd::collections::generic::icollection <type_t> interface only supports addition and removal operations. For example, the xtd::collections::generic::icollection::is_read_only property of an array that is cast or converted to an xtd::collections::generic::icollection <type_t> object returns `true`, even though individual array elements can be modified.
    bool is_read_only() const noexcept override {return false;}
    
    /// @brief Gets a value indicating whether access to the xtd::collections::generic::icollection <type_t> is synchronized (thread safe).
    /// @return `true` if access to the xtd::collections::generic::icollection <type_t> is synchronized (thread safe); otherwise, `false`.
    /// @remarks xtd::collections::generic::icollection::sync_root returns an object, which can be used to synchronize access to the xtd::collections::generic::icollection <type_t>.
    /// @remarks Most collection classes in the xtd::collections namespace also implement a `synchronized` method, which provides a synchronized wrapper around the underlying collection.
    /// @remarks Enumerating through a collection is intrinsically not a thread-safe procedure. Even when a collection is synchronized, other threads can still modify the collection, which causes the enumerator to throw an exception. To guarantee thread safety during enumeration, you can either lock the collection during the entire enumeration or catch the exceptions resulting from changes made by other threads.
    /// @remarks The following code example shows how to lock the collection using the xtd::collections::generic::icollection::sync_root property during the entire enumeration.
    /// @code
    /// icollection& my_collection = some_collection;
    /// lock_(my_collection.sync_root()) {
    ///   for (auto item : my_collection) {
    ///     // Insert your code here.
    ///   }
    /// }
    /// @endcode
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
    virtual size_type length() const noexcept {return data_->items.size();}
    /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the array.
    /// @return int64 A 64-bit integer that represents the total number of elements in all the dimensions of the array; zero if there are no elements in the array.
    /// @remarks Retrieving the value of this property is an O(1) operation.
    virtual xtd::int64 long_length() {return static_cast<xtd::int64>(length());}
    
    /// @brief Returns the maximum number of elements the container is able to hold due to system or library implementation limitations, i.e. std::distance(xtd::array::begin(), xtd::array::end()) for the largest container.
    /// @return Maximum number of elements.
    virtual size_type max_length() const noexcept {return data_->items.max_size();}
    
    /// @brief Gets the rank (number of dimensions) of the array.
    /// @return The rank (number of dimensions) of the array.
    /// @par Examples
    /// The following code example demonstrates methods to get the rank of an array.
    /// @include array_get_length.cpp
    virtual size_type rank() const noexcept {return 1;}
    
    /// @brief Gets an object that can be used to synchronize access to the the xtd::collections::generic::icollection <type_t>.
    /// @return An object that can be used to synchronize access to the the xtd::collections::generic::icollection <type_t>.
    /// @remarks For collections whose underlying store is not publicly available, the expected implementation is to return the current instance. Note that the pointer to the current instance might not be sufficient for collections that wrap other collections; those should return the underlying collection's `sync_root` property.
    /// @remarks Most collection classes in the xts::.collections namespace also implement a `synchronized` method, which provides a synchronized wrapper around the underlying collection. However, derived classes can provide their own synchronized version of the collection using the xtd::collections::generic::icollection::sync_root property. The synchronizing code must perform operations on the xtd::collections::generic::icollection::sync_root property of the collection, not directly on the collection. This ensures proper operation of collections that are derived from other objects. Specifically, it maintains proper synchronization with other threads that might be simultaneously modifying the collection instance.
    /// @remarks In the absence of a `synchronized` method on a collection, the expected usage for the xtd::collections::generic::icollection::sync_root looks as follows:
    /// @code
    /// icollection& my_collection = some_collection;
    /// lock_(my_collection.sync_root()) {
    ///   // Some operation on the collection, which is now thread safe.
    /// }
    /// @encode
    /// @remarks Enumerating through a collection is intrinsically not a thread-safe procedure. Even when a collection is synchronized, other threads can still modify the collection, which causes the enumerator to throw an exception. To guarantee thread safety during enumeration, you can either lock the collection during the entire enumeration or catch the exceptions resulting from changes made by other threads.
    /// @remarks The following code example shows how to lock the collection using the xtd::collections::generic::icollection::sync_root property during the entire enumeration.
    /// @code
    /// icollection& my_collection = some_collection;
    /// lock_(my_collection.sync_root()) {
    ///   for (auto item : my_collection) {
    ///     // Insert your code here.
    ///   }
    /// }
    /// @endcode
    const xtd::object& sync_root() const noexcept override {return data_->sync_root;}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Determines whether an element is in the array.
    /// @param value The object to be added to the end of the array.
    bool contains(const type_t& value) const noexcept override {
      for (const auto& item : data_->items)
        if (xtd::collections::generic::helpers::equator<type_t> {}(reinterpret_cast<const type_t&>(item), value)) return true;
      return false;
    }
    
    void copy_to(xtd::array<type_t>& array) const {
      copy_to(0, array, 0);
    }
    
    /// @brief Copies the elements of the xtd::array <type_t> to an xtd::array, starting at a particular xtd::array index.
    /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
    /// @param array_index The zero-based index in `array` at which copying begins.
    /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::icollection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
    void copy_to(xtd::array<type_t>& array, size_type array_index) const override {
      return copy_to(0, array, array_index);
    }
    
    void copy_to(const xtd::array<size_type>& indexes, xtd::array<type_t>& array, size_type array_index) const {
      return copy_to(compute_index(self_, indexes), array, array_index);
    }
    
    void copy_to(const xtd::array<size_type>& indexes, xtd::array<type_t>& array, size_type array_index, size_type count) const {
      return copy_to(compute_index(self_, indexes), array, array_index, count);
    }
    
    void copy_to(const size_type index, xtd::array<type_t>& array, size_type array_index) const {
      return copy_to(index, array, array_index, length() - index);
    }
    
    void copy_to(const size_type index, xtd::array<type_t>& array, size_type array_index, size_type count) const {
      if (array.rank() != 1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
      if (index + count > self_.length() || array_index + count > array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      for (auto i = index; i < (index + count); ++i)
        array[array_index++] = self_[i];
    }
    
    bool equals(const object & obj) const noexcept override {return dynamic_cast<const basic_array<value_type>*>(&obj) && equals(static_cast<const basic_array<value_type>&>(obj));}
    bool equals(const basic_array & rhs) const noexcept override {
      if (count() != rhs.count()) return false;
      for (size_type i = 0; i < count(); i++)
        if (!xtd::collections::generic::helpers::equator<type_t> {}(data_->items.at(i), rhs.data_->items.at(i))) return false;
      return data_->lower_bound == rhs.data_->lower_bound && data_->upper_bound == rhs.data_->upper_bound;
    }
    
    /// @brief Assigns the value to all elements in the container.
    /// @param value The value to assign to the elements.
    virtual void fill(const value_type & value) noexcept {
      for (auto& item : data_->items)
        item = value;
    }
    
    xtd::collections::generic::enumerator<value_type> get_enumerator() const noexcept override {
      struct basic_array_enumerator : public xtd::collections::generic::ienumerator < value_type > {
        explicit basic_array_enumerator(const basic_array & items, size_type version) : items_(items), version_(version) {}
        
        const value_type& current() const override {
          if (index_ >= items_.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
          if (version_ != items_.data_->items.version()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
          return items_[index_];
        }
        
        bool move_next() override {
          if (version_ != items_.data_->items.version()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
          return ++index_ < items_.count();
        }
        
        void reset() override {
          version_ = items_.data_->items.version();
          index_ = basic_array::npos;
        }
        
      private:
        size_type index_ = basic_array::npos;
        const basic_array& items_;
        size_type version_ = 0;
      };
      return {new_ptr < basic_array_enumerator > (*this, data_->items.version())};
    }
    
    /// @brief Gets the total number of elements in all the dimensions of the array.
    /// @param dimension A zero-based dimension of the array whose length needs to be determined.
    /// @return The total number of elements in all the dimensions of the array; zero if there are no elements in the array.
    /// @exception xtd::argument_out_of_range_exception `dimension` is equal to or greater than xtd::basic_array::rank.
    /// @par Examples
    /// The following code example demonstrates methods to get the length of an array.
    /// @include array_get_length.cpp
    constexpr size_type get_length(size_type dimension) const {return get_upper_bound(dimension) - get_lower_bound(dimension) + 1;}
    
    /// @brief Gets an array of the number of elements of all the dimensions of the array.
    /// @return The array of the number of elements of all the dimensions of the array;
    xtd::array<size_type, 1> get_lengths() const;
    
    /// @brief Gets a 64-bit integer that represents the total number of elements in all the dimensions of the array.
    /// @param dimension A zero-based dimension of the array whose length needs to be determined.
    /// @return A 64-bit integer that represents the total number of elements in all the dimensions of the array; zero if there are no elements in the array.
    /// @exception xtd::argument_out_of_range_exception `dimension` is equal to or greater than xtd::basic_array::rank.
    /// @par Examples
    /// The following code example demonstrates methods to get the length of an array.
    /// @include array_get_length.cpp
    constexpr xtd::int64 get_long_length(size_type dimension) const {return static_cast < xtd::int64 > (get_upper_bound(dimension) + 1);}
    
    /// @brief Gets the lower bound of the specified dimension in the array.
    /// @param dimension A zero-based dimension of the array whose lower bound needs to be determined.
    /// @return The lower bound of the specified dimension in the array.
    /// @exception xtd::argument_out_of_range_exception `dimension` is equal to or greater than xtd::basic_array::rank.
    /// @par Examples
    /// The following code example uses xtd::array::get_lower_bound and xtd::array::get_upper_bound to initialize a one-dimensional array and a multidimensional array.
    /// @include array_get_lower_bound.cpp
    constexpr size_type get_lower_bound(size_type dimension) const {
      if (dimension >= rank()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
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
      if (dimension >= rank()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      return data_->upper_bound[dimension];
    }
    
    /// @brief Gets the value at the specified position in the multidimensional array. The indexes are specified as 32-bit integers array.
    /// @param indexes An array that represents the position of the element to get.
    /// @return The value at the specified position in the multidimensional array.
    /// @exception xtd::index_out_of_range_exception If `indexes` is outside the range of valid indexes for the corresponding dimension of the current array.
    const value_type& get_value(const xtd::array < size_type >& indexes) const;
    
    /// @brief Determines the index of a specific item in the xtd::array <type_t>.
    /// @param value The object to locate in the xtd::array.
    /// @return The index of value if found in the array; otherwise, xtd::collections::generic::ilist::npos.
    size_type index_of(const type_t& value) const noexcept override  {return index_of(value, 0, length());}
    size_type index_of(const type_t& value, size_type index) const {return index_of(value, index, length() - index);}
    size_type index_of(const type_t& value, size_type index, size_type count) const {
      if (index > length() || index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      for (auto increment = index; increment < (index + count); ++increment)
        if (xtd::collections::generic::helpers::equator<type_t> {}(data_->items[increment], value)) return increment;
      return xtd::npos;
    }
    
    /// @brief Resizes the container to contain `count` elements, does nothing if `count == length().
    /// @param new_size The new size of the container.
    /// @exception xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
    /// @remarks If the current size is greater than `count`, the container is reduced to its first `count` elements.
    /// @remarks If the current size is less than `count`, additional default-inserted elements are appended.
    void resize(size_type new_size) {resize(new_size, value_type {});}
    
    /// @brief Resizes the container to contain `count` elements, does nothing if `count == length().
    /// @param new_size The new size of the container.
    /// @param value The value to initialize the new elements with.
    /// @exception xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
    /// @remarks If the current size is greater than `count`, the container is reduced to its first `count` elements.
    /// @remarks If the current size is less than `count`, additional default-inserted elements are appended.
    void resize(size_type new_size, value_type value) {
      if (new_size == length()) return;
      if (rank() != 1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
      if (new_size > max_length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::out_of_memory);
      data_->items.resize(new_size, value);
      data_->upper_bound[0] = new_size - 1;
    }
    
    /// @brief Sets a value to the element at the specified position in the multidimensional array.
    /// @param value The new value for the specified element.
    /// @param indexes An array that represents the position of the element to set.
    /// @exception xtd::index_out_of_range_exception Either `indexes` is outside the range of valid indexes for the current array.
    void set_value(const type_t& value, const xtd::array < size_type >& indexes) {operator()(indexes) = value;}
    
    /// @brief Sorts the elements in the entire xtd::collections::generic::list <type_t> using the default comparer.
    /// @exception xtd::invalid_operation_exception The default comparer xtd::collections::generic::comparer::default_comparer cannot find an implementation of the xtd::icomparable <type_t> generic interface.
    /// @par Examples
    /// The xtd::collections::generic::list::binary_search method overload is then used to search for two strings that are not in the list, and the xtd::collections::generic::list::insert method is used to insert them. The return value of the xtd::collections::generic::list::binary_search method is gretaer than xtd::collections::generic::list::count in each case, because the strings are not in the list. Taking the bitwise complement of this negative number produces the index of the first element in the list that is larger than the search string, and inserting at this location preserves the sort order. The second search string is larger than any element in the list, so the insertion position is at the end of the list.
    /// @include generic_list_binary_search.cpp
    /// @remarks This method uses the default comparer xtd::collections::generic::comparer::default_comparer for type `type_t` to determine the order of list elements. The xtd::collections::generic::comparer::default_comparer property checks whether type `type_t` implements the xtd::icomparable <type_t> generic interface and uses that implementation, if available. If not, xtd::collections::generic::comparer::default_comparer checks whether type T implements the xtd::icomparable interface. If type `type_t` does not implement either interface, xtd::collections::generic::comparer::default_comparer throws an xtd::invalid_operation_exception.
    /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
    /// @remarks On average, this method is an O(n log n) operation, where n is xtd::collections::generic::list::count; in the worst case it is an O(n ^ 2) operation.
    /// @remarks The following code example demonstrates the xtd::collections::generic::list::sort method overload and the xtd::collections::generic::list::binary_search method overload. A xtd::collections::generic::list <type_t> of strings is created and populated with four strings, in no particular order. The list is displayed, sorted, and displayed again.
    basic_array < type_t >& sort() {return sort(dynamic_cast<const xtd::collections::generic::icomparer<type_t>&>(xtd::collections::generic::comparer < type_t >::default_comparer));}
    
    /// @brief Sorts the elements in the entire xtd::collections::generic::list <type_t> using the specified xtd::comparison <type_t>.
    /// @exception xtd::argument_exception The implementation of comparison caused an error during the sort. For example, comparison might not return 0 when comparing an item with itself.
    /// @remarks If comparison is provided, the elements of the xtd::collections::generic::list <type_t> are sorted using the method represented by the delegate.
    /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
    /// @remarks On average, this method is an O(n log n) operation, where n is xtd::collections::generic::list::count; in the worst case it is an O(n ^ 2) operation.
    template<class comparison_t>
    basic_array < type_t >& sort(comparison_t&& comparison) {
      data_->items.increment_version();
      std::sort(data_->items.begin(), data_->items.end(), [&](const type_t& x, const type_t& y) {return comparison(x, y) < 0;});
      return self_;
    }
    
    /// @brief Sorts the elements in the entire xtd::collections::generic::list <type_t> using the specified comparer.
    /// @param comparer The xtd::collections::generic::icomparer <type_t> implementation to use when comparing elements, or null to use the default comparer xtd::collections::generic::comparer::default_comparer.
    /// @exception xtd::argument_exception The implementation of comparison caused an error during the sort. For example, comparison might not return 0 when comparing an item with itself.
    /// @remarks If comparer is provided, the elements of the xtd::collections::generic::list <type_t> are sorted using the specified xtd::collections::generic::icomparer <type_t> implementation.
    /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
    /// @remarks On average, this method is an O(n log n) operation, where n is xtd::collections::generic::list::count; in the worst case it is an O(n ^ 2) operation.
    basic_array < type_t >& sort(const xtd::collections::generic::icomparer < type_t >& comparer) {
      return sort(0, count(), comparer);
    }
    
    /// @brief Sorts the elements in a range of elements in xtd::collections::generic::list <type_t> using the specified comparer.
    /// @param index The zero-based starting index of the range to sort.
    /// @param count The length of the range to sort.
    /// @param comparer The xtd::collections::generic::icomparer <type_t> implementation to use when comparing elements, or null to use the default comparer xtd::collections::generic::comparer::default_comparer.
    /// @exception xtd::argument_exception The implementation of comparison caused an error during the sort. For example, comparison might not return 0 when comparing an item with itself.
    /// @remarks If comparer is provided, the elements of the xtd::collections::generic::list <type_t> are sorted using the specified xtd::collections::generic::icomparer <type_t> implementation.
    /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
    /// @remarks On average, this method is an O(n log n) operation, where n is xtd::collections::generic::list::count; in the worst case it is an O(n ^ 2) operation.
    basic_array < type_t >& sort(xtd::size index, xtd::size count, const xtd::collections::generic::icomparer < type_t >& comparer) {
      if (index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
      data_->items.increment_version();
      std::sort(data_->items.begin(), data_->items.end(), xtd::collections::generic::helpers::lesser<type_t> {comparer});
      return self_;
    }
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    xtd::string to_string() const noexcept override;
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
    /// @param other Another container to use as data source.
    /// @return This current instance.
    basic_array& operator =(const basic_array & other) {
      *data_ = *other.data_;
      return *this;
    }
    /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container). other is in a valid but unspecified state afterwards.
    /// @param other Another base type container to use as data source.
    /// @return This current instance.
    basic_array& operator =(basic_array&& other) noexcept = default;
    /// @brief Replaces the contents with those identified by initializer list ilist.
    /// @param items Initializer list to use as data source
    /// @return This current instance.
    basic_array& operator =(std::initializer_list < type_t >& items) {
      data_->items = items;
      data_->upper_bound[0] = data_->items.size() - 1;
      return *this;
    }
    
    /// @brief Returns a reference to the element at specified location index.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception xtd::index_out_of_range_exception If pos is not within the range of the container.
    const_reference operator [](size_type index) const override {
      if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return data_->items.at(index);
    }
    /// @brief Returns a reference to the element at specified location index.
    /// @param index The position of the element to return.
    /// @return Reference to the requested element.
    /// @exception xtd::index_out_of_range_exception If `index` is not within the range of the container.
    reference operator [](size_type index) override {
      if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      return data_->items.at(index);
    }
    
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    operator const base_type& () const noexcept {return data_->items;}
    /// @brief Returns a reference to the underlying base type.
    /// @return Reference to the underlying base type.
    operator base_type& () noexcept {return data_->items;}
    
    /// @brief Gets the value at the specified position in the multidimensional array. The indexes are specified as a 32-bit integer array.
    /// @param indexes An array that represents the multidimension index of the array element to get.
    /// @return The value at the specified position in the multidimensional array.
    /// @exception xtd::index_out_of_range_exception Either each index is outside the range of valid indexes for the corresponding dimension of the current array.
    /// @par Examples
    /// The following code example shows how to use operator [] to list the elements of an array.
    /// @include array_array_operator_functor.cpp
    type_t& operator()(const xtd::array < size_type >& indexes);
    
    /// @brief Gets the value at the specified position in the multidimensional array. The indexes are specified as a 32-bit integer array.
    /// @param indexes An array that represents the multidimension index of the array element to get.
    /// @return The value at the specified position in the multidimensional array.
    /// @exception xtd::index_out_of_range_exception Either each index is outside the range of valid indexes for the corresponding dimension of the current array.
    /// @par Examples
    /// The following code example shows how to use operator [] to list the elements of an array.
    /// @include array_array_operator_functor.cpp
    const type_t& operator()(const xtd::array < size_type >& indexes) const;
    /// @}
    
  private:
    template < class type_array_t, size_type rank_array_t, class allocator_array_t >
    friend class array;
    
    basic_array() = default;
    explicit basic_array(const array < size_type, 1 >& lengths);
    basic_array(const array < size_type, 1 >& lengths, const value_type & value);
    explicit basic_array(const xtd::collections::generic::ienumerable < type_t >& enumerable) {
      for (const auto& value : enumerable)
        data_->items.push_back(value);
      data_->upper_bound[0] = data_->items.size() - 1;
    }
    explicit basic_array(const xtd::collections::generic::ilist < type_t >& items) {
      data_->items.reserve(items.count());
      for (const auto& value : items)
        data_->items.push_back(value);
      data_->upper_bound[0] = data_->items.size() - 1;
    }
    
    template < class input_iterator_t >
    basic_array(input_iterator_t first, input_iterator_t last) {
      data_->items.assign(first, last);
      data_->upper_bound.push_back(data_->items.size() - 1);
    }
    
    basic_array(const std::vector < type_t >& items) {
      data_->items.assign(items.begin(), items.end());
      data_->upper_bound[0] = data_->items.size() - 1;
    }
    
    basic_array(const std::vector < std::vector < type_t>>& items)  {
      for (const std::vector < type_t >& items1 : items)
        data_->items.insert(data_->items.end(), items1.begin(), items1.end());
      data_->upper_bound[0] = items.size() - 1;
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back((*items.begin()).size() - 1);
    }
    
    basic_array(const std::vector < std::vector < std::vector<type_t>>>& items)  {
      for (const std::vector < std::vector < type_t>>& items1 : items)
        for (const std::vector < type_t >& items2 : items1)
          data_->items.insert(data_->items.end(), items2.begin(), items2.end());
      data_->upper_bound[0] = items.size() - 1;
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back((*items.begin()).size() - 1);
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back((*(*items.begin()).begin()).size() - 1);
    }
    
    basic_array(std::initializer_list < type_t > il) {
      data_->items.assign(il.begin(), il.end());
      data_->upper_bound[0] = data_->items.size() - 1;
    }
    
    basic_array(std::initializer_list < std::initializer_list < type_t>> il)  {
      for (const std::initializer_list < type_t >& il1 : il)
        data_->items.insert(data_->items.end(), il1.begin(), il1.end());
      data_->upper_bound[0] = il.size() - 1;
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back((*il.begin()).size() - 1);
    }
    
    basic_array(std::initializer_list < std::initializer_list < std::initializer_list<type_t>>> il)  {
      for (const std::initializer_list < std::initializer_list < type_t>>& il1 : il)
        for (const std::initializer_list < type_t >& il2 : il1)
          data_->items.insert(data_->items.end(), il2.begin(), il2.end());
      data_->upper_bound[0] = il.size() - 1;
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back((*il.begin()).size() - 1);
      data_->lower_bound.push_back(0);
      data_->upper_bound.push_back((*(*il.begin()).begin()).size() - 1);
    }
    
    void add(const type_t& item) override {}
    
    void clear() override {fill(value_type {});}
    
    template<class value_t>
    static xtd::size compute_index(const xtd::basic_array<value_t>& items, const xtd::array<size_type>& indexes);
    template<class value_t>
    static xtd::size compute_index(const xtd::basic_array<value_t>& items, xtd::size rank, xtd::size index);
    
    void insert(size_type index, const type_t& value) override {}
    
    bool remove(const type_t& item) override {return false;}
    
    void remove_at(size_type index) override {}
    
    void reverse(size_type index, size_type count) {
      if (index > length() || index + count > length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if (count == 0) return;
      data_->items.increment_version();
      std::reverse(data_->items.begin() + index, data_->items.begin() + index + count);
    }
    
    template<class value_t>
    static xtd::string to_string(const xtd::basic_array<value_t>& items, xtd::size rank, xtd::size base_index);
    
    struct array_data {
      xtd::collections::generic::helpers::raw_array < value_type > items;
      std::vector < size_type > lower_bound {0};
      std::vector < size_type > upper_bound {std::numeric_limits < size_type >::max()};
      object sync_root;
    };
    
    xtd::ptr < array_data > data_ = xtd::new_ptr < array_data > ();
  };
}
