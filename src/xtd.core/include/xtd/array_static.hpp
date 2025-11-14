/// @file
/// @brief Contains xtd::array <> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.

#if !defined(__XTD_ARRAY_INTERNAL__)
#error "Do not include this file: Internal use only. Include <xtd/array> or <xtd/array.hpp> instead."
#endif

#include "collections/generic/comparer.hpp"
#include "helpers/throw_helper.hpp"

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
    /// @param array The one-dimensional, zero-based array to wrap in a read-only xtd::collections::object_model::read_only_collection<type_t> wrapper.
    /// @return A read-only xtd::collections::object_model::read_only_collection<type_t> wrapper for the specified array.
    /// @remarks To prevent any modifications to the array, expose the array only through this wrapper.
    /// @remarks A collection that is read-only is simply a collection with a wrapper that prevents modifying the collection; therefore, if changes are made to the underlying collection, the read-only collection reflects those changes.
    /// @remarks This method is an O(n) operation.
    /// @par Examples
    /// The following example wraps an array in a read-only xtd::collections::object_model::read_only_collection<type_t>.
    /// @include array_as_read_only.cpp
    template<class type_t, class allocator_t>
    inline static xtd::collections::object_model::read_only_collection<type_t> as_read_only(const xtd::array<type_t, 1, allocator_t>& array); // defined in array_.hpp file
    
    /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the xtd::icomparable interface implemented by each element of the array and by the specified value.
    /// @param array The sorted one-dimensional array to search.
    /// @param index The starting index of the range to search.
    /// @param length The length of the range to search.
    /// @param value The object to search for.
    /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
    /// @exception xtd::rank_exception array is multidimensional.
    /// @exception xtd::argument_out_of_range_exception index is less than the lower bound of array. <br>-or-<bre>  length is less than zero.
    /// @exception xtd::argument_exception index and length do not specify a valid range in array. <br>-or-<bre>  value is of a type that is not compatible with the elements of array.
    /// @exception xtd::invalid_operation_exception value does not implement the xtd::icomparable interface, and the search encounters an element that does not implement the xtd::icomparable interface.
    /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
    /// @remarks If the array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
    /// @remarks Either value or every element of array must implement the xtd::icomparable interface, which is used for comparisons. The elements of array must already be sorted in increasing value according to the sort order defined by the xtd::icomparable implementation; otherwise, the result might be incorrect.
    /// @note If value does not implement the xtd::icomparable interface, the elements of array are not tested for xtd::icomparable before the search begins. An exception is thrown if the search encounters an element that does not implement xtd::icomparable.
    /// @remarks Duplicate elements are allowed. If the array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
    /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception.
    /// @note For every element tested, value is passed to the appropriate xtd::icomparable implementation, even if value is null. That is, the xtd::icomparable implementation determines how a given element compares to null.
    /// @remarks This method is an O(log n) operation, where n is length.
    template<class type_t, class allocator_t>
    inline static int32 binary_search(const array<type_t, 1, allocator_t>& array, int32 index, int32 length, const type_t& value) {return binary_search(array, index, length, value, xtd::collections::generic::comparer<type_t>::default_comparer);}
    /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the specified xtd::icomparer interface.
    /// @param array The sorted one-dimensional array to search.
    /// @param index The starting index of the range to search.
    /// @param length The length of the range to search.
    /// @param value The object to search for.
    /// @param comparer The xtd::icomparer implementation to use when comparing elements. <br>-or-<bre>  null to use the xtd::icomparable implementation of each element.
    /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
    /// @exception xtd::rank_exception array is multidimensional.
    /// @exception xtd::argument_out_of_range_exception index is less than the lower bound of array. <br>-or-<bre>  length is less than zero.
    /// @exception xtd::argument_exception index and length do not specify a valid range in array. <br>-or-<bre>  value is of a type that is not compatible with the elements of array.
    /// @exception xtd::invalid_operation_exception value does not implement the xtd::icomparable interface, and the search encounters an element that does not implement the xtd::icomparable interface.
    /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
    /// @remarks If the array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
    /// @remarks The comparer customizes how the elements are compared. For example, you can use a xtd::collections::case_insensitive_comparer as the comparer to perform case-insensitive string searches.
    /// @remarks If comparer is not null, the elements of array are compared to the specified value using the specified xtd::icomparer implementation. The elements of array must already be sorted in increasing value according to the sort order defined by comparer; otherwise, the result might be incorrect.
    /// @remarks If comparer is null, the comparison is done using the xtd::icomparable implementation provided by the element itself or by the specified value. The elements of array must already be sorted in increasing value according to the sort order defined by the xtd::icomparable implementation; otherwise, the result might be incorrect.
    /// @note If comparer is null and value does not implement the xtd::icomparable interface, the elements of array are not tested for xtd::icomparable before the search begins. An exception is thrown if the search encounters an element that does not implement xtd::icomparable.
    /// @remarks Duplicate elements are allowed. If the array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
    /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception when using xtd::icomparable.
    /// @note For every element tested, value is passed to the appropriate xtd::icomparable implementation, even if value is null. That is, the xtd::icomparable implementation determines how a given element compares to null.
    /// @remarks This method is an O(log n) operation, where n is length.
    template<class type_t, class allocator_t>
    inline static xtd::size binary_search(const array<type_t, 1, allocator_t>& array, xtd::size index, xtd::size count, const type_t& value, const xtd::collections::generic::icomparer<type_t>& comparer) {
      if (index + count > array->Length) helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      typename std::vector<type_t>::const_iterator first = array.array.begin();
      typename std::vector<type_t>::const_iterator last = array.array.begin();
      std::advance(first, index);
      std::advance(last, index + count);
      typename std::vector<type_t>::const_iterator position = std::lower_bound(first, last, value, xtd::array<type_t>::comparer(&comparer));
      
      if (position != array.array.end() && !comparer->Compare(value, *position))
        return (int32)std::distance(array.array.begin(), position);
      return (int32)~std::distance(array.array.begin(), position);
    }
    /// @brief Searches an entire one-dimensional sorted array for a specific element, using the xtd::icomparable interface implemented by each element of the array and by the specified object.
    /// @param array The sorted one-dimensional array to search.
    /// @param value The object to search for.
    /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
    /// @exception xtd::rank_exception array is multidimensional.
    /// @exception xtd::argument_exception value is of a type that is not compatible with the elements of array.
    /// @exception xtd::invalid_operation_exception value does not implement the xtd::icomparable interface, and the search encounters an element that does not implement the xtd::icomparable interface.
    /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
    /// @remarks If the array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
    /// @remarks Either value or every element of array must implement the xtd::icomparable interface, which is used for comparisons. The elements of array must already be sorted in increasing value according to the sort order defined by the xtd::icomparable implementation; otherwise, the result might be incorrect.
    /// @note Ifvalue does not implement the xtd::icomparable interface, the elements of array are not tested for xtd::icomparable before the search begins. An exception is thrown if the search encounters an element that does not implement xtd::icomparable.
    /// @remarks Duplicate elements are allowed. If the array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
    /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception.
    /// @note For every element tested, value is passed to the appropriate xtd::icomparable implementation, even if value is null. That is, the xtd::icomparable implementation determines how a given element compares to null.
    /// @remarks This method is an O(log n) operation, where n is the Length of array.
    template<class type_t, class allocator_t>
    inline static xtd::size binary_search(const array<type_t, 1, allocator_t>& array, const type_t& value) {return binary_search(array, 0, array.Length, value, xtd::collections::generic::comparer<type_t>::default_comparer.release());}
    /// @brief Searches a range of elements in a one-dimensional sorted array for a value, using the specified xtd::icomparer interface.
    /// @param array The sorted one-dimensional array to search.
    /// @param value The object to search for.
    /// @param comparer The xtd::icomparer implementation to use when comparing elements. <br>-or-<bre>  null to use the xtd::icomparable implementation of each element.
    /// @return int32 The index of the specified value in the specified array, if value is found; otherwise, a negative number. If value is not found and value is less than one or more elements in array, the negative number returned is the bitwise complement of the index of the first element that is larger than value. If value is not found and value is greater than all elements in array, the negative number returned is the bitwise complement of (the index of the last element plus 1). If this method is called with a non-sorted array, the return value can be incorrect and a negative number could be returned, even if value is present in array.
    /// @exception xtd::rank_exception array is multidimensional.
    /// @exception xtd::argument_out_of_range_exception index is less than the lower bound of array. <br>-or-<bre>  length is less than zero.
    /// @exception xtd::argument_exception index and length do not specify a valid range in array. <br>-or-<bre>  value is of a type that is not compatible with the elements of array.
    /// @exception xtd::invalid_operation_exception value does not implement the xtd::icomparable interface, and the search encounters an element that does not implement the xtd::icomparable interface.
    /// @remarks This method does not support searching arrays that contain negative indexes. array must be sorted before calling this method.
    /// @remarks If the array does not contain the specified value, the method returns a negative integer. You can apply the bitwise complement operator ~ to the negative result to produce an index. If this index is one greater than the upper bound of the array, there are no elements larger than value in the array. Otherwise, it is the index of the first element that is larger than value.
    /// @remarks The comparer customizes how the elements are compared. For example, you can use a xtd::collections::case_insensitive_comparer as the comparer to perform case-insensitive string searches.
    /// @remarks If comparer is not null, the elements of array are compared to the specified value using the specified xtd::icomparer implementation. The elements of array must already be sorted in increasing value according to the sort order defined by comparer; otherwise, the result might be incorrect.
    /// @remarks If comparer is null, the comparison is done using the xtd::icomparable implementation provided by the element itself or by the specified value. The elements of array must already be sorted in increasing value according to the sort order defined by the xtd::icomparable implementation; otherwise, the result might be incorrect.
    /// @note If comparer is null and value does not implement the xtd::icomparable interface, the elements of array are not tested for xtd::icomparable before the search begins. An exception is thrown if the search encounters an element that does not implement xtd::icomparable.
    /// @remarks Duplicate elements are allowed. If the array contains more than one element equal to value, the method returns the index of only one of the occurrences, and not necessarily the first one.
    /// @remarks null can always be compared with any other reference type; therefore, comparisons with null do not generate an exception when using xtd::icomparable.
    /// @note For every element tested, value is passed to the appropriate xtd::icomparable implementation, even if value is null. That is, the xtd::icomparable implementation determines how a given element compares to null.
    /// @remarks This method is an O(log n) operation, where n is length.
    template<class type_t, class allocator_t>
    inline static xtd::size binary_search(const array<type_t, 1, allocator_t>& array, const type_t& value, const xtd::collections::generic::icomparer<type_t>& comparer) {return binary_search(array, 0, array.Length, value, comparer);}
    
    /// @brief Clears the contents of an array.
    /// @param array The array to clear.
    template<class type_t, xtd::size rank, class allocator_t>
    inline static void clear(const array<type_t, rank, allocator_t>& array) {clear(array, 0, array.data_->items.size());}
    /// @brief Sets a range of elements in an array to the default value of each element type.
    /// @param array The array whose elements need to be cleared.
    /// @param index The starting index of the range of elements to clear.
    /// @param length The number of elements to clear.
    /// @exception xtd::index_out_of_range_exception The sum of `index` and `length` is greater than the size of array.
    /// @par Examples
    /// The following example uses the xtd::array::clear method to reset integer values in a one-dimensional, two-dimensional, and three-dimensional array.
    /// @include array_clear.cpp
    template<class type_t, xtd::size rank, class allocator_t>
    inline static void clear(const array<type_t, rank, allocator_t>& array, xtd::size index, xtd::size length) {
      if (index + length > array.data_->items.size()) helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
      for (auto i = xtd::size {}; i < length; ++i)
        array.data_->items[index + i] = type_t {};
    }
    
    /// @brief Copies a range of elements from an xtd::array starting at the specified source index and pastes them to another xtd::array starting at the specified destination index. Guarantees that all changes are undone if the copy does not succeed completely.
    /// @param source_array The xtd::array that contains the data to copy.
    /// @param source_indexes An array of xtd::size that represents the index in `source_array` at which copying begins.
    /// @param destination_array The xtd::array that receives the data.
    /// @param destination_indexes An array of xtd::size that represents the index in `destination_array` at which storing begins.
    /// @param length An xtd::size that represents the number of elements to copy.
    /// @exception xtd::rank_exception `source_array` and `destination_array` have different ranks.
    /// @exception xtd::argument_out_of_range_excpetion `source_index` is less than the lower bound of the first dimension of `source_array`. <br>-or-<br> `destination_index` is less than the lower bound of the first dimension of `destination_array`.
    /// @exception xtd::argument_exception `length` is greater than the number of elements from `source_index` to the end of `source_array`. <br>-or-<br> `length` is greater than the number of elements from `destination_index` to the end of `destination_array`.
    template<class source_type_t, xtd::size source_rank, class source_allocator_t, class destination_type_t, xtd::size destination_rank, class destination_allocator_t>
    static void constrained_copy(const array<source_type_t, source_rank, source_allocator_t>& source_array, const xtd::array<xtd::size>& source_indexes, array<destination_type_t, destination_rank, destination_allocator_t>& destination_array, const xtd::array<xtd::size>& destination_indexes, xtd::size length) {constrained_copy(source_array, xtd::basic_array<source_type_t, source_allocator_t>::compute_index(source_indexes), destination_array, xtd::basic_array<destination_type_t, destination_allocator_t>::compute_index(destination_indexes), length);}
    /// @brief Copies a range of elements from an xtd::array starting at the specified source index and pastes them to another xtd::array starting at the specified destination index. Guarantees that all changes are undone if the copy does not succeed completely.
    /// @param source_array The xtd::array that contains the data to copy.
    /// @param source_index An xtd::size that represents the index in `source_array` at which copying begins.
    /// @param destination_array The xtd::array that receives the data.
    /// @param destination_index An xtd::size that represents the index in `destination_array` at which storing begins.
    /// @param length An xtd::size that represents the number of elements to copy.
    /// @exception xtd::rank_exception `source_array` and `destination_array` have different ranks.
    /// @exception xtd::argument_out_of_range_excpetion `source_index` is less than the lower bound of the first dimension of `source_array`. <br>-or-<br> `destination_index` is less than the lower bound of the first dimension of `destination_array`.
    /// @exception xtd::argument_exception `length` is greater than the number of elements from `source_index` to the end of `source_array`. <br>-or-<br> `length` is greater than the number of elements from `destination_index` to the end of `destination_array`.
    template<class source_type_t, xtd::size source_rank, class source_allocator_t, class destination_type_t, xtd::size destination_rank, class destination_allocator_t>
    static void constrained_copy(const array<source_type_t, source_rank, source_allocator_t>& source_array, xtd::size source_index, array<destination_type_t, destination_rank, destination_allocator_t>& destination_array, xtd::size destination_index, xtd::size length) {
      if (source_array.rank() != destination_array.rank()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::rank);
      for (auto r = xtd::size{0}; r < source_array.rank(); ++r)
        if (source_array.get_length(r) != destination_array.get_length(r)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
      if (source_index < source_array.get_lower_bound(0) || destination_index < destination_array.get_lower_bound(0)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
      if (source_index + length > source_array.length() || destination_index + length > destination_array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
      
      auto tmp_array = destination_array;
      for (auto i = source_index; i < (source_index + length); ++i)
        tmp_array.data_->items[destination_index++] = source_array.data_->items[i];
      destination_array.data_->items.swap(tmp_array.data_->items);
    }
    
    /// @brief Converts an array of one type to an array of another type.
    /// @param array The zero-based xtd::array <type_t> to convert to a target type.
    /// @param converter A xtd::converter <output_t, input_t> that converts each element from one type to another type.
    /// @return An array of the target type containing the converted elements from the source array.
    /// @remarks The xtd::converter <output_t, input_t> is a delegate to a method that converts an object to the target type. The elements of array are individually passed to the xtd::converter <output_t, input_t>, and the converted elements are saved in the new array.
    /// @remarks The source array remains unchanged.
    /// @remarks This method is an O(n) operation, where n is the xtd::basic_array::length of array.
    template<class output_t, class input_t, xtd::size rank, class allocator_t, class converter_t>
    static xtd::array<output_t, rank> convert_all(const xtd::array<input_t, rank, allocator_t>& array, converter_t converter) {
      auto result = create_instance<output_t, rank>(array.get_lengths());
      for (auto i = xtd::size {0}; i < array.length(); ++i)
        result[i] = converter(array[i]);
      return result;
    }
    
    /// @brief Copies a range of elements from an xtd::array starting at the first element and pastes them into another xtd::array starting at the first element. The length is specified as an xtd::size.
    /// @param source_array The xtd::array that contains the data to copy.
    /// @param destination_array The xtd::rray that receives the data.
    /// @param length An xtd::size that represents the number of elements to copy.
    /// @exception xtd::argument_out_of_range_exception The `length` is greater than `source_array` size.<ber>-or-<br>The `length` is greater than `destination_array` size.
    template<class source_type_t, xtd::size source_rank, class source_allocator_t, class destination_type_t, xtd::size destination_rank, class destination_allocator_t>
    inline static void copy(const array<source_type_t, source_rank, source_allocator_t>& source_array, const array<destination_type_t, destination_rank, destination_allocator_t>& destination_array) {copy(source_array, 0, destination_array, 0, destination_array.length());}
    /// @brief Copies a range of elements from an xtd::array starting at the first element and pastes them into another xtd::array starting at the first element. The length is specified as an xtd::size.
    /// @param source_array The xtd::array that contains the data to copy.
    /// @param destination_array The xtd::rray that receives the data.
    /// @param length An xtd::size that represents the number of elements to copy.
    /// @exception xtd::argument_out_of_range_exception The `length` is greater than `source_array` size.<ber>-or-<br>The `length` is greater than `destination_array` size.
    template<class source_type_t, xtd::size source_rank, class source_allocator_t, class destination_type_t, xtd::size destination_rank, class destination_allocator_t>
    inline static void copy(const array<source_type_t, source_rank, source_allocator_t>& source_array, const array<destination_type_t, destination_rank, destination_allocator_t>& destination_array, xtd::size length) {copy(source_array, 0, destination_array, 0, length);}
    /// @brief Copies a range of elements from an xtd::array starting at the specified source index and pastes them to another xtd::array starting at the specified destination index. The length and the indexes are specified as 64-bit integers.
    /// @param source_array The xtd::rray that contains the data to copy.
    /// @param source_index An xtd::size that represents the index in `source_array` at which copying begins.
    /// @param destination_array The xtd::array that receives the data.
    /// @param destination_index An xtd::size that represents the index in `destination_array` at which storing begins.
    /// @param length An xtd::size that represents the number of elements to copy.
    /// @exception xtd::argument_out_of_range_exception The sum of the `source_index` and `length` is greater than `source_array` size.<ber>-or-<br>The sum of the `destination_index` and `length` is greater than `destination_array` size.
    template<class source_type_t, xtd::size source_rank, class source_allocator_t, class destination_type_t, xtd::size destination_rank, class destination_allocator_t>
    inline static void copy(const array<source_type_t, source_rank, source_allocator_t>& source_array, const xtd::array<xtd::size>& source_indexes, const array<destination_type_t, destination_rank, destination_allocator_t>& destination_array, const xtd::array<xtd::size>& destination_indexes, xtd::size length) {
      copy(source_array, source_array.compute_index(source_array, source_indexes), destination_array, destination_array.compute_index(destination_array, destination_indexes), length);
    }
    /// @brief Copies a range of elements from an xtd::array starting at the specified source index and pastes them to another xtd::array starting at the specified destination index. The length and the indexes are specified as 64-bit integers.
    /// @param source_array The xtd::rray that contains the data to copy.
    /// @param source_index An xtd::size that represents the index in `source_array` at which copying begins.
    /// @param destination_array The xtd::array that receives the data.
    /// @param destination_index An xtd::size that represents the index in `destination_array` at which storing begins.
    /// @param length An xtd::size that represents the number of elements to copy.
    /// @exception xtd::argument_out_of_range_exception The sum of the `source_index` and `length` is greater than `source_array` size.<ber>-or-<br>The sum of the `destination_index` and `length` is greater than `destination_array` size.
    template<class source_type_t, xtd::size source_rank, class source_allocator_t, class destination_type_t, xtd::size destination_rank, class destination_allocator_t>
    inline static void copy(const array<source_type_t, source_rank, source_allocator_t>& source_array, xtd::size source_index, const array<destination_type_t, destination_rank, destination_allocator_t>& destination_array, xtd::size destination_index, xtd::size length); // defined in as.hpp file
    
    /// @brief Creates a one-dimensional xtd::array <type_t> of the specified Type and length, with zero-based indexing.
    /// @param length The size of the xtd::array <type_t> to create.
    /// @return A new one-dimensional xtd::array <type_t> of the specified Type with the specified length, using zero-based indexing.
    /// @exception xtd::argument_exception elementType is not a valid Type.
    /// @exception xtd::not_supported_exception elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
    /// @exception xtd::argument_out_of_range_exception length is less than zero.
    /// @remarks Unlike most classes, xtd::array <type_t> provides the create_instance method, instead of public constructors, to allow for late bound access.
    /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
    /// @remarks This method is an O(n) operation, where n is length.
    /// @param EXamples
    /// The following code example shows how to create and initialize a one-dimensional xtd::array <type_t>.
    /// @include array_create_instance1.cpp
    template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
    static xtd::array<type_t, 1, allocator_t> create_instance(xtd::size length) {return xtd::array<type_t, 1, allocator_t>(length);}
    /// @brief Creates a two-dimensional xtd::array <type_t> of the specified Type and dimension lengths, with zero-based indexing.
    /// @param length1 The size of the first dimension of the xtd::array <type_t> to create.
    /// @param length2 The size of the second dimension of the xtd::array <type_t> to create.
    /// @return A new two-dimensional xtd::array <type_t> of the specified Type with the specified length for each dimension, using zero-based indexing.
    /// @exception xtd::argument_exception elementType is not a valid Type.
    /// @exception xtd::not_supported_exception elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
    /// @exception xtd::argument_out_of_range_exception length1 is less than zero.  -or-  xtd::argument_out_of_range_exception length2 is less than zero.
    /// @remarks Unlike most classes, xtd::array <type_t> provides the create_instance method, instead of public constructors, to allow for late bound access.
    /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
    /// @remarks This method is an O(n) operation, where n is length.
    /// @param EXamples
    /// The following code example shows how to create and initialize a two-dimensional xtd::array <type_t>.
    /// @include array_create_instance2.cpp
    template<class type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
    static xtd::array<type_t, 2, allocator_t> create_instance(xtd::size length1, xtd::size length2) {return xtd::array<type_t, 2, allocator_t>(length1, length2);}
    /// @brief Creates a three-dimensional xtd::array <type_t> of the specified Type and dimension lengths, with zero-based indexing.
    /// @param length1 The size of the first dimension of the xtd::array <type_t> to create.
    /// @param length2 The size of the second dimension of the xtd::array <type_t> to create.
    /// @param length3 The size of the third dimension of the xtd::array <type_t> to create.
    /// @return A new three-dimensional xtd::array <type_t> of the specified Type with the specified length for each dimension, using zero-based indexing.
    /// @exception xtd::argument_exception elementType is not a valid Type.
    /// @exception xtd::not_supported_exception elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
    /// @exception xtd::argument_out_of_range_exception length1 is less than zero.  -or-  xtd::argument_out_of_range_exception length2 is less than zero.  -or-  xtd::argument_out_of_range_exception length3 is less than zero.
    /// @remarks Unlike most classes, xtd::array <type_t> provides the create_instance method, instead of public constructors, to allow for late bound access.
    /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
    /// @remarks This method is an O(n) operation, where n is length.
    /// @param EXamples
    /// The following code example shows how to create and initialize a three-dimensional xtd::array <type_t>.
    /// @include array_create_instance3.cpp
    template<typename type_t, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
    static xtd::array<type_t, 3, allocator_t> create_instance(xtd::size length1, xtd::size length2, xtd::size length3) {return xtd::array<type_t, 3, allocator_t>(length1, length2, length3);}
    /// @brief Creates a multidimensional xtd::array <type_t> of the specified Type and dimension lengths, with zero-based indexing. The dimension lengths are specified in an array of 32-bit integers.
    /// @param An array of 32-bit integers that represent the size of each dimension of the xtd::array <type_t> to create.
    /// @return A new multidimensional xtd::array <type_t> of the specified Type with the specified length for each dimension, using zero-based indexing.
    /// @exception xtd::argument_exception elementType is not a valid Type.
    /// @exception xtd::not_supported_exception elementType is not supported. For example, Void is not supported.  -or-  elementType is an open generic type.
    /// @exception xtd::argument_out_of_range_exception length1 is less than zero.  -or-  xtd::argument_out_of_range_exception length2 is less than zero.  -or-  xtd::argument_out_of_range_exception length3 is less than zero.
    /// @remarks Unlike most classes, xtd::array <type_t> provides the create_instance method, instead of public constructors, to allow for late bound access.
    /// @remarks The number of elements in the lengths array must equal the number of dimensions in the new xtd::array <type_t>. Each element of the lengths array must specify the length of the corresponding dimension in the new xtd::array <type_t>.
    /// @remarks Pointer-type elements are initialized to null. Value-type elements are initialized to zero.
    /// @remarks This method is an O(n) operation, where n is length.
    template<typename type_t, xtd::size rank, class allocator_t = xtd::collections::generic::helpers::allocator<type_t>>
    static xtd::array<type_t, rank, allocator_t> create_instance(const xtd::array<xtd::size>& lengths) {return xtd::array<type_t, rank, allocator_t>(lengths, type_t {});}
    /// @}
  };
}
