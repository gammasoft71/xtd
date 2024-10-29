/// @file
/// @brief Contains array definitions.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_INTERNAL__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond
#include "../collections/generic/helpers/allocator.h"
#include "../size.h"
#include <vector> // @todo remove line

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t, xtd::size rank_, typename allocator_t>
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
  template<typename type_t = std::nullptr_t, xtd::size rank_size = 1, typename allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
  class array;
  
  /// @brief Base object that represent array.
  /// @par Definition
  /// ```cpp
  /// template<typename type_t, typename allocator_t = xtd::collections::generic::helpers::allocator<typename std::conditional<std::is_same<bool, type_t>::value, char, type_t>::type>>
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
  template<typename type_t, typename allocator_t>
  class basic_array;
  
  /// @brief Abstract object that represent array.
  /// @par Definition
  /// ```cpp
  /// class array_abstract_object abstract_;
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
  class array_abstract_object;
}
