/// @file
/// @brief Contains xtd::array <type_t, 1> class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <array> or <array.h> instead."
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The Array class is not part of the xtd::collections namespaces. However, it is still considered a collection because it is based on the xtd::collections::generic::ilist interface.
  /// @remarks An element is a value in an Array. The length of an Array is the total number of elements it can contain. The lower bound of an Array is the index of its first element. An Array can have any lower bound, but it has a lower bound of zero by default. A different lower bound can be defined when creating an instance of the Array class using xtd::array::create_instance. A multidimensional Array can have different bounds for each dimension. An array can have a maximum of 32 dimensions.
  /// @remarks Unlike the classes in the xtd::collections namespaces, Array has a fixed capacity. To increase the capacity, you must create a new Array object with the required capacity, copy the elements from the old Array object to the new one, and delete the old Array.
  /// @remarks The Array class implements the System.Collections.Generic.IList<T>, System.Collections.Generic.ICollection<T>, and System.Collections.Generic.IEnumerable<T> generic interfaces. The implementations are provided to arrays at run time, and as a result, the generic interfaces do not appear in the declaration syntax for the Array class. In addition, there are no reference topics for interface members that are accessible only by casting an array to the generic interface type (explicit interface implementations). The key thing to be aware of when you cast an array to one of these interfaces is that members which add, insert, or remove elements throw NotSupportedException.
  /// @remarks The Array.Copy method copies elements not only between arrays of the same type but also between standard arrays of different types; it handles type casting automatically.
  /// @remarks Some methods, such as xtd::array::create_instance, Copy, CopyTo, GetValue, and SetValue, provide overloads that accept 64-bit integers as parameters to accommodate large capacity arrays. LongLength and GetLongLength return 64-bit integers indicating the length of the array.
  /// @remarks The Array is not guaranteed to be sorted. You must sort the Array prior to performing operations (such as BinarySearch) that require the Array to be sorted.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include Array1.cpp
  /// @par Examples
  /// The following code example creates and initializes an Array and displays its properties and its elements.
  /// @include Array2.cpp
  template<typename type_t, typename allocator_t>
  class array_<type_t, 1, allocator_t> : public xtd::basic_array<type_t, allocator_t> {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the array value type.
    using value_type = type_t;
    /// @brief Represents the array allocator type.
    using allocator_type = typename xtd::basic_array<type_t, allocator_t>::allocator_type;
    /// @brief Represents the array base type.
    using base_type = typename xtd::basic_array<type_t, allocator_t>::base_type;
    /// @brief Represents the array size type (usually xtd::size).
    using size_type = typename xtd::basic_array<type_t, allocator_t>::size_type;
    /// @brief Represents the array difference type (usually xtd::ptrdiff).
    using difference_type = typename xtd::basic_array<type_t, allocator_t>::difference_type;
    /// @brief Represents the reference of array value type.
    using reference = typename xtd::basic_array<type_t, allocator_t>::reference;
    /// @brief Represents the const reference of array value type.
    using const_reference = typename xtd::basic_array<type_t, allocator_t>::const_reference;
    /// @brief Represents the pointer of array value type.
    using pointer = typename xtd::basic_array<type_t, allocator_t>::pointer;
    /// @brief Represents the const pointer of array value type.
    using const_pointer = typename xtd::basic_array<type_t, allocator_t>::const_pointer;
    /// @brief Represents the iterator of array value type.
    using iterator = typename xtd::basic_array<type_t, allocator_t>::iterator;
    /// @brief Represents the const iterator of array value type.
    using const_iterator = typename xtd::basic_array<type_t, allocator_t>::const_iterator;
    /// @brief Represents the reverse iterator of array value type.
    using reverse_iterator = typename xtd::basic_array<type_t, allocator_t>::reverse_iterator;
    /// @brief Represents the const reverse iterator of array value type.
    using const_reverse_iterator = typename xtd::basic_array<type_t, allocator_t>::const_reverse_iterator;
    /// @}

    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the Array class that is empty.
    /// @remarks The Array class is not thread safe.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include array_constructor.cpp
    array_() = default;
    /// @brief Copy constructor with specified array.
    /// @param array The xtd::array which elements will be inserted from.
    array_(const array_& array) : basic_array<type_t, allocator_t>(array) {}
    /// @brief Move constructor with specified array.
    /// @param array The xtd::array which elements will be inserted from.
    array_(const array_&& array) : basic_array<type_t, allocator_t>(std::move(array)) {}
    /// @brief Copy constructor with specified base type array.
    /// @param array The xtd::array::base_type which elements will be inserted from.
    array_(const base_type& array) : basic_array<type_t, allocator_t>(array) {}
    /// @brief Move constructor with specified base type array.
    /// @param array The xtd::array::base_type which elements will be moved from.
    array_(base_type&& array) : basic_array<type_t, allocator_t>(array) {}
    /// @brief Initializes a new instance of the array class with lengths for each rank specified.
    /// @param length the length for the first rank.
    /// @remarks The array class is not thread safe.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include array_constructor.cpp
    array_(size_type length) : basic_array<type_t, allocator_t>(array_<xtd::size> {length}) {}
    /// @brief Constructs the container with the contents of the specified initializer list.
    /// @param items The initializer list to initialize the elements of the container with.
    array_(std::initializer_list<type_t> items) : basic_array<type_t, allocator_t>(items) {}
    /// @brief Initializes a new instance of the array and copy array[] type_t.
    /// @param array the array to copy.
    /// @remarks The array class is not thread safe.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include array_constructor.cpp
    template<xtd::size length>
    array_(const type_t(&array)[length]) : basic_array<type_t, allocator_t>(array, length) {}
    /// @brief Initializes a new instance of the array and copy array[] type_t with length specified.
    /// @param array the array to copy.
    /// @param length length of the array.
    /// @remarks The array class is not thread safe.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include array_constructor.cpp
    array_(const type_t* array, size_type length) : basic_array<type_t, allocator_t>(array, length) {}
    /// @brief Initializes a new instance of the array and copy array array specified.
    /// @param array the array to copy.
    /// @remarks The array class is not thread safe.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include array_constructor.cpp
    array_(const xtd::collections::generic::ienumerable<type_t>& enumerable) : basic_array<type_t, allocator_t>(enumerable) {}
    /// @brief Initializes a new instance of the array and copy array array specified.
    /// @param array the array to copy.
    /// @remarks The array class is not thread safe.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include array_constructor.cpp
    array_(const xtd::collections::generic::ilist<type_t>& list) : basic_array<type_t, allocator_t>(list) {}
    /// @brief Constructs the container with the contents of the range [first, last).
    /// @param first The first iterator the range to copy the elements from.
    /// @param last The last iterator the range to copy the elements from.
    template<typename iterator_t>
    array_(iterator_t first, iterator_t last) : basic_array<type_t, allocator_t>(first, last) {}
    /// @}

    /// @name Public Properties
    
    /// @{
    xtd::size rank() const noexcept override {return 1;}
    /// @}

    /// @name Public Properties
    
    /// @{
    using xtd::basic_array<type_t, allocator_t>::get_value;
    /// @brief Gets the value at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
    /// @param index The position of the Array element to get.
    /// @return The value at the specified position in the one-dimensional Array.
    /// @exception ArgumentException The current Array does ! have exactly one dimension.
    /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
    const value_type& get_value(size_type index) const {return operator()(index);}
    
    using xtd::basic_array<type_t, allocator_t>::set_value;
    /// @brief Sets a value to the element at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
    /// @param value The new value for the specified element.
    /// @param index The position of the Array element to set.
    /// @exception ArgumentException The current Array does ! have exactly one dimension.
    /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
    void set_value(const value_type& value, size_type index) {operator()(index) = value;}
    /// @}


    /// @name Public Operators
    
    /// @{
    array_& operator=(const array_&) = default;
    array_& operator=(array_&&) = default;
    
    using xtd::basic_array<type_t, allocator_t>::operator();
    /// @brief Sets a value to the element at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
    /// @param value The new value for the specified element.
    /// @param index A 32-bit integer that represents the position of the Array element to set.
    /// @exception ArgumentException The current Array does ! have exactly one dimension.
    /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
    /// @par Examples
    /// The following code example shows how to use operator () to list the elements of an array.
    /// @include ArrayArrayOperatorFunctor.cpp
    value_type& operator()(size_type index) {return xtd::basic_array<type_t, allocator_t>::operator[](index);}
    
    /// @brief Gets the value at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
    /// @param index A 32-bit integer that represents the position of the Array element to get.
    /// @return The value at the specified position in the one-dimensional Array.
    /// @exception ArgumentException The current Array does ! have exactly one dimension.
    /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
    /// @par Examples
    /// The following code example shows how to use operator () to list the elements of an array.
    /// @include ArrayArrayOperatorFunctor.cpp
    const value_type& operator()(size_type index) const {return xtd::basic_array<type_t, allocator_t>::operator[](index);}
    
    /// @brief Sets a value to the element at the specified position in the one-dimensional Array. The index is specified as a 32-bit integer.
    /// @param value The new value for the specified element.
    /// @param index A 32-bit integer that represents the position of the Array element to set.
    /// @exception ArgumentException The current Array does ! have exactly one dimension.
    /// @exception IndexOutOfRangeException index is outside the range of valid indexes for the current Array.
    /// @par Examples
    /// The following code example shows how to use operator [] to list the elements of an array.
    /// @include ArrayArrayOperator.cpp
    value_type& operator[](size_type index) override {return xtd::basic_array<type_t, allocator_t>::operator[](index);}
    
    /// @brief Gets the element at the specified index.
    /// @param index The zero-based index of the element to get.
    /// @return The value at the specified position in the one-dimensional Array.
    /// @exception ArgumentException The current Array does ! have exactly one dimension.
    /// @exception IndexOutOfRangeException index is less than 0 or index is equal to or greater than Count.
    /// @par Examples
    /// The following code example shows how to use operator [] to list the elements of an array.
    /// @include ArrayArrayOperator.cpp
    const value_type& operator[](size_type index) const override {return xtd::basic_array<type_t, allocator_t>::operator[](index);}
    /// @}
  };
}
