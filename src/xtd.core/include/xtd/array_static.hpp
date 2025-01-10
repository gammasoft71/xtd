/// @file
/// @brief Contains xtd::array <> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/array> or <xtd/array.h> instead."
#endif

#include "collections/generic/comparer.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace collections::object_model {
    template<class type_t>
    class read_only_collection;
  }
  /// @endcond
  
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
  /// The following code example creates and initializes an array and displays its properties and its elements.
  /// @include array2.cpp
  template<>
  class array<> static_ {
  public:
    /// @name Public Aliases
    
    /// @{
    /// @}

    /// @name Public Static Methods
    
    /// @{
    /// @brief Returns a read-only wrapper for the specified array.
    /// @param array The one-dimensional, zero-based array to wrap in a read-only ReadOnlyCollection<type_t> wrapper.
    /// @return A read-only ReadOnlyCollection<type_t> wrapper for the specified array.
    /// @remarks To prevent any modifications to the array, expose the array only through this wrapper.
    /// @remarks A collection that is read-only is simply a collection with a wrapper that prevents modifying the collection; therefore, if changes are made to the underlying collection, the read-only collection reflects those changes.
    /// @remarks This method is an O(n) operation.
    /// @par Examples
    /// The following example wraps an array in a read-only ReadOnlyCollection<type_t>.
    /// @include ArrayAsReadOnly.cpp
    template<typename type_t, typename allocator_t>
    static xtd::collections::object_model::read_only_collection<type_t> as_read_only(const xtd::array<type_t, 1, allocator_t>& array);

    /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the IComparable interface implemented by each element of the array and by the specified value.
    /// @param array The sorted one-dimensional array to search.
    /// @param index The starting index of the range to search.
    /// @param length The length of the range to search.
    /// @param value The object to search for.
    /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
    /// @exception RankException array is multidimensional.
    /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
    /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
    /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
    /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
    /// @remarks If the array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
    /// @remarks Either value or every element of array must implement the IComparable interface, which is used for comparisons. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
    /// @note If value does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
    /// @remarks Duplicate elements are allowed. If the array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
    /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception.
    /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
    /// @remarks This method is an O(log n) operation, where n is length.
    //template<typename type_t, typename allocator_t>
    //static int32 binary_search(const array<type_t, 1, allocator_t>& array, int32 index, int32 length, const type_t& value) {return binary_search(array, index, length, value, xtd::collections::generic::comparer<type_t>::default_comparer);}
    
    /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the specified IComparer interface.
    /// @param array The sorted one-dimensional array to search.
    /// @param index The starting index of the range to search.
    /// @param length The length of the range to search.
    /// @param value The object to search for.
    /// @param comparer The IComparer implementation to use when comparing elements.  -or-  null to use the IComparable implementation of each element.
    /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
    /// @exception RankException array is multidimensional.
    /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
    /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
    /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
    /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
    /// @remarks If the array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
    /// @remarks The comparer customizes how the elements are compared. For example, you can use a System.Collections.CaseInsensitiveComparer as the comparer to perform case-insensitive string searches.
    /// @remarks If comparer is not null, the elements of array are compared to the specified value using the specified IComparer implementation. The elements of array must already be sorted in increasing value according to the sort order defined by comparer; otherwise, the result might be incorrect.
    /// @remarks If comparer is null, the comparison is done using the IComparable implementation provided by the element itself or by the specified value. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
    /// @note If comparer is null and value does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
    /// @remarks Duplicate elements are allowed. If the array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
    /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception when using IComparable.
    /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
    /// @remarks This method is an O(log n) operation, where n is length.
    /*
    template<typename type_t, typename allocator_t>
    static xtd::size binary_search(const array<type_t, 1, allocator_t>& array, xtd::size index, xtd::size count, const type_t& value, const xtd::collections::generic::icomparer<type_t>& comparer) {
      if (index + count > array->Length) throw ArgumentException(caller_);
      
      typename std::vector<type_t>::const_iterator first = array.array.begin();
      typename std::vector<type_t>::const_iterator last = array.array.begin();
      std::advance(first, index);
      std::advance(last, index + count);
      typename std::vector<type_t>::const_iterator position = std::lower_bound(first, last, value, array<type_t>::Comparer(&comparer));
      
      if (position != array.array.end() && !comparer->Compare(value, *position))
        return (int32)std::distance(array.array.begin(), position);
      return (int32)~std::distance(array.array.begin(), position);
    }*/
    
    /// @brief Searches an entire one-dimensional sorted array for a specific element, using the IComparable interface implemented by each element of the array and by the specified object.
    /// @param array The sorted one-dimensional array to search.
    /// @param value The object to search for.
    /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
    /// @exception RankException array is multidimensional.
    /// @exception ArgumentException value is of a type that is not compatible with the elements of array.
    /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
    /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
    /// @remarks If the array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
    /// @remarks Either value or every element of array must implement the IComparable interface, which is used for comparisons. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
    /// @note Ifvalue does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
    /// @remarks Duplicate elements are allowed. If the array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
    /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception.
    /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
    /// @remarks This method is an O(log n) operation, where n is the Length of array.
    //template<typename type_t, typename allocator_t>
    //static xtd::size binary_search(const array<type_t, 1, allocator_t>& array, const type_t& value) {return binary_search(array, 0, array.Length, value, xtd::collections::generic::comparer<type_t>::default_comparer.release());}
    
    /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the specified IComparer interface.
    /// @param array The sorted one-dimensional array to search.
    /// @param value The object to search for.
    /// @param comparer The IComparer implementation to use when comparing elements.  -or-  null to use the IComparable implementation of each element.
    /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
    /// @exception RankException array is multidimensional.
    /// @exception ArgumentOutOfRangeException index is less than the lower bound of array.  -or-  length is less than zero.
    /// @exception ArgumentException index and length do not specify a valid range in array.  -or-  value is of a type that is not compatible with the elements of array.
    /// @exception InvalidOperationException value does not implement the IComparable interface, and the search encounters an element that does not implement the IComparable interface.
    /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
    /// @remarks If the array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
    /// @remarks The comparer customizes how the elements are compared. For example, you can use a System.Collections.CaseInsensitiveComparer as the comparer to perform case-insensitive string searches.
    /// @remarks If comparer is not null, the elements of array are compared to the specified value using the specified IComparer implementation. The elements of array must already be sorted in increasing value according to the sort order defined by comparer; otherwise, the result might be incorrect.
    /// @remarks If comparer is null, the comparison is done using the IComparable implementation provided by the element itself or by the specified value. The elements of array must already be sorted in increasing value according to the sort order defined by the IComparable implementation; otherwise, the result might be incorrect.
    /// @note If comparer is null and value does not implement the IComparable interface, the elements of array are not tested for IComparable before the search begins. An exception is thrown if the search encounters an element that does not implement IComparable.
    /// @remarks Duplicate elements are allowed. If the array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
    /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception when using IComparable.
    /// @note For every element tested, value is passed to the appropriate IComparable implementation, even if value is null. That is, the IComparable implementation determines how a given element compares to null.
    /// @remarks This method is an O(log n) operation, where n is length.
    //template<typename type_t, typename allocator_t>
    //static xtd::size binary_search(const array<type_t, 1, allocator_t>& array, const type_t& value, const xtd::collections::generic::icomparer<type_t>& comparer) {return binary_search(array, 0, array.Length, value, comparer);}
    /// @}
  };
}
