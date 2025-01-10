/// @file
/// @brief Contains xtd::array <type_t, 3> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/array> or <xtd/array.h> instead."
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
  /// @par Definition
  /// ```cpp
  /// template<class type_t, xtd::size rank_, class allocator_t>
  /// class array : public xtd::basic_array<type_t, allocator_t>;
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
  /// @remarks The xtd::array class is not part of the xtd::collections namespaces. However, it is still considered a collection because it is based on the xtd::collections::generic::ilist interface.
  /// @remarks An element is a value in an xtd::array. The length of an xtd::array is the total number of elements it can contain. The lower bound of an v is the index of its first element. An xtd::array can have any lower bound, but it has a lower bound of zero by default. A different lower bound can be defined when creating an instance of the xtd::array class using xtd::array::create_instance. A multidimensional xtd::array can have different bounds for each dimension. An array can have a maximum of 32 dimensions.
  /// @remarks Unlike the classes in the xtd::collections namespaces, xtd::array has a fixed capacity. To increase the capacity, you must create a new xtd::array object with the required capacity, copy the elements from the old xtd::array object to the new one, and delete the old xtd::array.
  /// @remarks The xtd::array class implements the xtd::collections::generic::ilist, xtd::collections::generic::icollection, and xtd::collections::generic::ienumerable generic interfaces. The implementations are provided to arrays at run time, and as a result, the generic interfaces do not appear in the declaration syntax for the xtd::array class. In addition, there are no reference topics for interface members that are accessible only by casting an array to the generic interface type (explicit interface implementations). The key thing to be aware of when you cast an array to one of these interfaces is that members which add, insert, or remove elements throw xtd::not_supported_exception.
  /// @remarks The xtd::array::copy method copies elements not only between arrays of the same type but also between standard arrays of different types; it handles type casting automatically.
  /// @remarks Some methods, such as xtd::array::create_instance, xtd::array::copy, xtd::array::copy_to, xtd::array::get_value, and xtd::array::set_value, provide overloads that accept 64-bit integers as parameters to accommodate large capacity arrays. xtd::array::long_length and xtd::array::get_long_length return 64-bit integers indicating the length of the array.
  /// @remarks The xtd::array is not guaranteed to be sorted. You must sort the xtd::array prior to performing operations (such as xtd::array::binary_search) that require the xtd::array to be sorted.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include array1.cpp
  /// @par Examples
  /// The following code example creates and initializes an Array and displays its properties and its elements.
  /// @include array2.cpp
  template<class type_t, class allocator_t>
  class array<type_t, 3, allocator_t> : public xtd::basic_array<type_t, allocator_t> {
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
    array() = default;
    /// @brief Copy constructor with specified array.
    /// @param array The xtd::array which elements will be inserted from.
    array(const array& array) : basic_array<type_t, allocator_t>(array) {}
    /// @brief Move constructor with specified array.
    /// @param array The xtd::array which elements will be inserted from.
    array(const array&& array) : basic_array<type_t, allocator_t>(std::move(array)) {}
    /// @brief Copy constructor with specified base type array.
    /// @param array The xtd::array::base_type which elements will be inserted from.
    array(const base_type& array) : basic_array<type_t, allocator_t>(array) {}
    /// @brief Move constructor with specified base type array.
    /// @param array The xtd::array::base_type which elements will be moved from.
    array(base_type&& array) : basic_array<type_t, allocator_t>(array) {}
    /// @brief Initializes a new instance of the array class with lengths for each rank specified.
    /// @param length1 the length for the first rank.
    /// @param length2 the length for the second rank.
    /// @param length3 the length for the third rank.
    /// @remarks The array class is not thread safe.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include array_constructor.cpp
    array(size_type length1, size_type length2, size_type length3) : basic_array<type_t, allocator_t>(array<xtd::size> {length1, length2, length3}) {}
    /// @brief Constructs the container with the contents of the specified initializer list.
    /// @param items The initializer list to initialize the elements of the container with.
    array(std::initializer_list<std::initializer_list<std::initializer_list<type_t>>> items) : basic_array<type_t, allocator_t>(items) {}
    /// @}

    /// @cond
    ~array() {}
    /// @endcond

    /// @name Public Properties
    
    /// @{
    xtd::size rank() const noexcept override {return 3;}
    /// @}
  };
}
