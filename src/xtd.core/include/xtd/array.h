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
#include "iequatable.h"
#include "new_ptr.h"
#include "object.h"
#include <algorithm>
#include <vector>

#define __XTD_ARRAY_INTERNAL__
#include "array_object.h"
#include "basic_array.h"
#undef __XTD_ARRAY_INTERNAL__

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {  
  /// @brief Provides methods for creating, manipulating, searching, and sorting arrays, thereby serving as the base class for all arrays.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks The array class is not part of the xtd::collections namespaces. However, it is still considered a collection because it is based on the xtd::collections::generic::ilist interface.
  /// @remarks An element is a value in an array. The length of an array is the total number of elements it can contain. The lower bound of an array is the index of its first element. An array can have any lower bound, but it has a lower bound of zero by default. A different lower bound can be defined when creating an instance of the array class using xtd::array::create_instance. A multidimensional array can have different bounds for each dimension. An array can have a maximum of 32 dimensions.
  /// @remarks Unlike the classes in the xtd::collections namespaces, array has a fixed capacity. To increase the capacity, you must create a new array object with the required capacity, copy the elements from the old array object to the new one, and delete the old array.
  /// @remarks The array class implements the System.Collections.Generic.IList<type_t>, System.Collections.Generic.ICollection<type_t>, and System.Collections.Generic.IEnumerable<type_t> generic interfaces. The implementations are provided to arrays at run time, and as a result, the generic interfaces do not appear in the declaration syntax for the array class. In addition, there are no reference topics for interface members that are accessible only by casting an array to the generic interface type (explicit interface implementations). The key thing to be aware of when you cast an array to one of these interfaces is that members which add, insert, or remove elements throw NotSupportedException.
  /// @remarks The array.Copy method copies elements not only between arrays of the same type but also between standard arrays of different types; it handles type casting automatically.
  /// @remarks Some methods, such as xtd::array::create_instance, Copy, CopyTo, GetValue, and SetValue, provide overloads that accept 64-bit integers as parameters to accommodate large capacity arrays. LongLength and GetLongLength return 64-bit integers indicating the length of the array.
  /// @remarks The array is not guaranteed to be sorted. You must sort the array prior to performing operations (such as BinarySearch) that require the array to be sorted.
  /// @par Examples
  /// The following code example demonstrates different methods to create an array.
  /// @include array1.cpp
  /// @par Examples
  /// The following code example creates and initializes an array and displays its properties and its elements.
  /// @include array2.cpp
  template<typename type_t, xtd::size rank_, typename allocator_t>
  class array_ : public basic_array<type_t, allocator_t> {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the array class that is empty.
    /// @remarks The array class is not thread safe.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include ArrayConstructor.cpp
    array_() = default;
    
    /// @brief Initializes a new instance of the array class with lengths for each rank specified.
    /// @param lengths the lengths for each rank.
    /// @remarks The array class is not thread safe.
    /// @par Examples
    /// The following code example demonstrates different methods to create an array.
    /// @include array_constructor.cpp
    array_(const array_<xtd::size, 1>& lengths) : xtd::basic_array<type_t, allocator_t>(lengths) {}
    
    /// @cond
    array_(const array_& array) : xtd::basic_array<type_t, allocator_t>(array) {}
    array_(const array_&& array) : xtd::basic_array<type_t, allocator_t>(std::move(array)) {}
    /// @}

    /// @name Public Operators
    
    /// @{
    array_& operator=(const array_&) = default;
    array_& operator=(array_&&) = default;
    /// @}
  };
}

#define __XTD_ARRAY_INTERNAL__
#include "array_1.h"
#include "array_2.h"
#include "array_3.h"
#include "array.hpp"
#undef __XTD_ARRAY_INTERNAL__
