/// @file
/// @brief Contains xtd::collections::generic::list <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/equator.hpp"
#include "helpers/lesser.hpp"
#include "comparer.hpp"
#include "ilist.hpp"
#define __XTD_CORE_INTERNAL__
#include "../../internal/__list_definition.hpp"
#include "../../internal/__xtd_raw_array_data.hpp"
#undef  __XTD_CORE_INTERNAL__
#include "../object_model/read_only_collection.hpp"
#include "../../action.hpp"
#include "../../comparison.hpp"
#include "../../converter.hpp"
#include "../../intptr.hpp"
#include "../../is.hpp"
#include "../../object.hpp"
#include "../../optional.hpp"
#include "../../new_ptr.hpp"
#include "../../predicate.hpp"
#include "../../self.hpp"
#include "../../string.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a strongly typed list of objects that can be accessed by index. Provides methods to search, sort, and manipulate lists.
      /// ```cpp
      /// template<class type_t>
      /// class list : public xtd::object, xtd::collections::generic::ilist<type_t>, public xtd::iequatable<xtd::collections::generic::list<type_t>>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/list>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
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
      /// @remarks The xtd::collections::generic::list <type_t> class instanciate as xtd::collections::generic::list::base_type a [std::vector](https://en.cppreference.com/w/cpp/container/vector) with xtd::collections::generic::helpers::allocator instead [std::allocator](https://en.cppreference.com/w/cpp/memory/allocator). Use xtd::collections::generic::list::items property to access the underlying [std::vector](https://en.cppreference.com/w/cpp/container/vector).
      /// @remarks The xtd::collections::generic::list <type_t> class can also be used to manage a dynamic array of `bool` exactly as other types unlike [std::vector](https://en.cppreference.com/w/cpp/container/vector) with xtd::collections::generic::helpers::allocator instead [std::allocator](https://en.cppreference.com/w/cpp/memory/allocator). When the `type_t`is `bool` The underlying [std::vector](https://en.cppreference.com/w/cpp/container/vector) uses xtd::byte.
      /// @remarks The xtd::collections::generic::list <type_t> class is the generic equivalent of the xtd::collections::array_list class. It implements the xtd::collections::generic::ilist <type_t> generic interface by using an array whose size is dynamically increased as required.
      /// @remarks You can add items to a xtd::collections::generic::list <type_t> by using the xtd::collections::generic::list::add or xtd::collections::generic::list::add_range methods.
      /// @remarks The xtd::collections::generic::list <type_t> class uses both an equality comparer and an ordering comparer.
      /// * Methods such as xtd::collections::generic::list::contains, xtd::collections::generic::list::index_of, xtd::collections::generic::list::last_index_of, and xtd::collections::generic::list::remove use an equality comparer for the list elements. The default equality comparer for type `type_t` is determined as follows. If type `type_t` implements the xtd::iequatable <type_t> generic interface, then the equality comparer is the xtd::iequatable::equals method of that interface; otherwise, if the `type_t`inherits of the xtd::object class, the default equality comparer is xtd::object::equals. If the `type_t` does not implement the xtd::iequality <type_t> interface and does not inherit from xtd::object, the `type_t` must implement the euqality operator : `bool operator ==(const type_t& rhs) const noexcept`.
      /// * Methods such as xtd::collections::generic::list::binary_search and xtd::collections::generic::list::sort use an ordering comparer for the list elements. The default comparer for type `type_t` is determined as follows. If type `type_t` implements the xtd::icomparable <type_t> generic interface, then the default comparer is the xtd::icomaprable::compare_to method of that interface. If the `type_t` type does not implement the xtd::icomparable <type_t> interface, the `type_t` type must implement the less than operator : `bool operator <(const type_t& rhs) const noexcept`.
      /// @remarks The xtd::collections::generic::list <type_t> is not guaranteed to be sorted. You must sort the xtd::collections::generic::list <type_t> before performing operations (such as xtd::collections::binary_search) that require the xtd::collections::generic::list <type_t> to be sorted.
      /// @remarks Elements in this collection can be accessed using an integer index. Indexes in this collection are zero-based.
      /// @remarks For an immutable version of the xtd::collections::generic::list <type_t> class, see xtd::collections::immutale::immutable_list <type_t>.
      /// @par Linq extension
      /// * As xtd::collections::generic::list <type_t> inherits the xtd::collections::generic::ienumerable <type_t> interface, it automatically inherits the xtd::collections::generic::extensions::enumerable <type_t> interface and at the same time all the methods of xtd::linq::enumerable.
      /// * Thanks to xtd::linq, xtd::collections::generic::list <type_t> can be manipulated by the classes of xtd::ranges::views and can be combined with [std::ranges](https://en.cppreference.com/w/cpp/ranges.html).
      /// <br>The following example shows the xtd::ranges::views and [std::ranges](https://en.cppreference.com/w/cpp/ranges.html) usage :
      /// @include ranges_views.cpp
      /// @par Performance considerations
      /// As xtd::collections::generic::list <type_t> instantiates and uses only the methods of [std::vector](https://en.cppreference.com/w/cpp/container/vector), the performance of xtd::collections::generic::list <type_t> is practically identical to that of [std::vector](https://en.cppreference.com/w/cpp/container/vector).
      template<class type_t, class allocator_t>
      class list : public xtd::object, public xtd::collections::generic::ilist<type_t>, public xtd::iequatable<xtd::collections::generic::list<type_t, allocator_t >> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the list value type.
        using value_type = typename ilist<type_t>::value_type;
        /// @brief Represents the list base type.
        using base_type = typename __xtd_raw_array_data__<value_type>::base_type;
        /// @brief Represents the list base type.
        using const_base_type = const base_type;
        /// @brief Represents the list size type (usually xtd::size).
        using size_type = xtd::size;
        /// @brief Represents the reference of list value type.
        using reference = value_type&;
        /// @brief Represents the const reference of list value type.
        using const_reference = const value_type&;
        /// @brief Represents the pointer of list value type.
        using pointer = value_type*;
        /// @brief Represents the const pointer of list value type.
        using const_pointer = const value_type*;
        /// @brief Represents the read only collection of of list.
        using read_only_collection = xtd::collections::object_model::read_only_collection<value_type>;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::list class that is empty.
        /// @par Examples
        /// The following code example demonstrates the default constructor of the xtd::collections::generic::list generic class. The default constructor creates a list with the default capacity, as demonstrated by displaying the xtd::collections::generic::list::capacity property.
        /// @include generic_list2.cpp
        /// @remarks The capacity of a xtd::collections::generic::list is the number of elements that the xtd::collections::generic::list can hold. As elements are added to a xtd::collections::generic::list, the capacity is automatically increased as required by reallocating the internal array.
        /// @remarks If the size of the collection can be estimated, using the xtd::collections::generic::list (size_type) constructor and specifying the initial capacity eliminates the need to perform a number of resizing operations while adding elements to the xtd::collections::generic::list.
        /// @remarks The capacity can be decreased by calling the xtd::collections::generic::list::trim_excess method or by setting the xtd::collections::generic::list::capacity property explicitly. Decreasing the capacity reallocates memory and copies all the elements in the xtd::collections::generic::list.
        /// @remarks This constructor is an O(1) operation.
        list() noexcept = default;
        /// @brief Constructs the container with specified count default-inserted instances of type_t. No copies are made.
        /// @param capacity The number of elements that the new list can initially store.
        /// @exception xtd::out_of_memory There is not enough memory available on the system.
        /// @par Examples
        /// The following code example demonstrates the default constructor of the xtd::collections::generic::list generic class. The default constructor creates a list with the default capacity, as demonstrated by displaying the xtd::collections::generic::list::capacity property.
        /// @include generic_list2.cpp
        explicit list(size_type capacity) {self_.capacity(capacity);}
        /// @brief Initializes a new instance of the xtd::collections::generic::list <type_t> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new list.
        /// @par Examples
        /// The following code example demonstrates the xtd::collections::generic::list <type_t> constructor and various methods of the xtd::collections::generic::list <type_t> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The xtd::collections::generic::list::capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
        /// @include generic_list3.cpp
        /// @remarks The elements are copied onto the xtd::collections::generic::list <type_t> in the same order they are read by the enumerator of the collection.
        /// @remarks This constructor is an O(`n`) operation, where `n` is the number of elements in collection.
        list(const xtd::collections::generic::ienumerable<type_t>& collection) {add_range(collection);}
        /// @brief Default copy constructor with specified list.
        /// @param list The xtd::collections::generic::list which elements will be inserted from.
        list(const list& list) {*data_ = *list.data_;}
        /// @brief Move constructor with specified list.
        /// @param list The xtd::collections::generic::list which elements will be moved from.
        list(list&& list) {
          data_ = std::move(list.data_);
          list.data_ = new_ptr<list_data>();
        }
        /// @brief Copy constructor with specified base type list.
        /// @param list The xtd::collections::generic::list::base_type which elements will be inserted from.
        list(const base_type& list) {data_->items = list;}
        /// @brief Move constructor with specified base type list.
        /// @param list The xtd::collections::generic::list::base_type which elements will be moved from.
        list(base_type&& list) {data_->items = std::move(list);}
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        list(std::initializer_list<type_t> items) {add_range(items);}
        /// @brief Constructs the container with the contents of the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        template <std::input_iterator input_iterator_t>
        list(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator)
            add(*iterator);
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the total number of elements the internal data structure can hold without resizing.
        /// @return Capacity of the currently allocated storage.
        /// @exception xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
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
        size_type capacity() const noexcept {return data_->items.capacity();}
        /// @brief Sets the total number of elements the internal data structure can hold without resizing.
        /// @return Capacity of the currently allocated storage.
        /// @exception xtd::out_of_memory There is not enough memory available on the system.
        /// @exception xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
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
        void capacity(size_type value) {
          if (value > data_->items.max_size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::out_of_memory);
          if (value < count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          if (value == capacity()) return;
          if (value < capacity()) data_->items.shrink_to_fit();
          data_->items.reserve(value);
        }
        
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
        size_type count() const noexcept override {return data_->items.size();}
        
        /// @brief Returns pointer to the underlying array serving as element storage.
        /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
        /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::count()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
        pointer data() noexcept {return reinterpret_cast<pointer>(data_->items.data());}
        /// @brief Returns pointer to the underlying array serving as element storage.
        /// @return Pointer to the underlying element storage. For non-empty containers, the returned pointer compares equal to the address of the first element.
        /// @remarks The pointer is such that range [xtd::collections::generic::list::data(), xtd::collections::generic::list::data() + xtd::collections::generic::list::count()) is always a valid range, even if the container is empty (xtd::collections::generic::list::data() is not dereferenceable in that case).
        const_pointer data() const noexcept {return reinterpret_cast<const_pointer>(data_->items.data());}
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        const auto& items() const noexcept {return data_->items;}
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        auto& items() noexcept {return data_->items;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Adds an object to the end of the xtd::collections::generic::list <type_t>.
        /// @param item The object to be added to the end of the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::collections::generic::list <type_t>.
        /// @include generic_list4.cpp
        /// The following example demonstrates several properties and methods of the xtd::collections::generic::list <type_t> generic class, including the xtd::collections::generic::list::add method.
        /// The parameterless constructor is used to create a list of strings with a capacity of 0. The xtd::collections::generic::list::capacity property is displayed, and then the xtd::collections::generic::list::add method is used to add several items. The items are listed, and the xtd::collections::generic::list::capacity property is displayed again, along with the xtd::collections::generic::list::count property, to show that the capacity has been increased as needed.
        ///
        /// Other properties and methods are used to search for, insert, and remove elements from the list, and finally to clear the list.
        /// @include generic_list2.cpp
        /// @remarks xtd::collections::generic::list <type_t>  allows duplicate elements.
        /// @remarks If xtd::collections::generic::list::count already equals xtd::collections::generic::list::capacity, the capacity of the xtd::collections::generic::list <type_t> is increased by automatically reallocating the internal array, and the existing elements are copied to the new array before the new element is added.
        /// @remarks If xtd::collections::generic::list::count is less than xtd::collections::generic::list::capacity, this method is an O(1) operation. If the capacity needs to be increased to accommodate the new element, this method becomes an O(n) operation, where n is xtd::collections::generic::list::count.
        void add(const type_t& item) override {data_->items.push_back(item);}
        /// @brief Adds an object to the end of the xtd::collections::generic::list <type_t>.
        /// @param item The object to be added to the end of the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following example demonstrates how to add, remove, and insert a simple business object in a xtd::collections::generic::list <type_t>.
        /// @include generic_list4.cpp
        /// The following example demonstrates several properties and methods of the xtd::collections::generic::list <type_t> generic class, including the xtd::collections::generic::list::add method.
        /// The parameterless constructor is used to create a list of strings with a capacity of 0. The xtd::collections::generic::list::capacity property is displayed, and then the xtd::collections::generic::list::add method is used to add several items. The items are listed, and the xtd::collections::generic::list::capacity property is displayed again, along with the xtd::collections::generic::list::count property, to show that the capacity has been increased as needed.
        ///
        /// Other properties and methods are used to search for, insert, and remove elements from the list, and finally to clear the list.
        /// @include generic_list2.cpp
        /// @remarks xtd::collections::generic::list <type_t>  allows duplicate elements.
        /// @remarks If xtd::collections::generic::list::count already equals xtd::collections::generic::list::capacity, the capacity of the xtd::collections::generic::list <type_t> is increased by automatically reallocating the internal array, and the existing elements are copied to the new array before the new element is added.
        /// @remarks If xtd::collections::generic::list::count is less than xtd::collections::generic::list::capacity, this method is an O(1) operation. If the capacity needs to be increased to accommodate the new element, this method becomes an O(n) operation, where n is xtd::collections::generic::list::count.
        void add(type_t&& item) {data_->items.push_back(std::move(item));}
        
        /// @brief Adds copy of elements from the specified collection to the end of the xtd::collections::generic::list <type_t>.
        /// @param collection The collection whose elements should be added to the end of the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following code example demonstrates the xtd::collections::generic::list <type_t> constructor and various methods of the xtd::collections::generic::list <type_t> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The xtd::collections::generic::list::capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
        /// @include generic_list3.cpp
        /// @remarks The order of the elements in the collection is preserved in the xtd::collections::generic::list <type_t>.
        /// @remarks If the new xtd::collections::generic::list::count (the current xtd::collections::generic::list::count plus the size of the collection) will be greater than xtd::collections::generic::list::capacity, the capacity of the xtd::collections::generic::list <type_t> is increased by automatically reallocating the internal array to accommodate the new elements, and the existing elements are copied to the new array before the new elements are added.
        /// @remarks If the xtd::collections::generic::list <type_t> can accommodate the new elements without increasing the xtd::collections::generic::list::capacity, this method is an O(`n`) operation, where `n` is the number of elements to be added. If the capacity needs to be increased to accommodate the new elements, this method becomes an O(n + m) operation, where n is the number of elements to be added and m is xtd::collections::generic::list::count.
        void add_range(const xtd::collections::generic::ienumerable<type_t>& enumerable) {insert_range(count(), enumerable);}
        
        /// @brief Adds copy of elements from the specified collection to the end of the xtd::collections::generic::list <type_t>.
        /// @param il The collection whose elements should be added to the end of the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following code example demonstrates the xtd::collections::generic::list <type_t> constructor and various methods of the xtd::collections::generic::list <type_t> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The xtd::collections::generic::list::capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
        /// @include generic_list3.cpp
        /// @remarks The order of the elements in the collection is preserved in the xtd::collections::generic::list <type_t>.
        /// @remarks If the new xtd::collections::generic::list::count (the current xtd::collections::generic::list::count plus the size of the collection) will be greater than xtd::collections::generic::list::capacity, the capacity of the xtd::collections::generic::list <type_t> is increased by automatically reallocating the internal array to accommodate the new elements, and the existing elements are copied to the new array before the new elements are added.
        /// @remarks If the xtd::collections::generic::list <type_t> can accommodate the new elements without increasing the xtd::collections::generic::list::capacity, this method is an O(`n`) operation, where `n` is the number of elements to be added. If the capacity needs to be increased to accommodate the new elements, this method becomes an O(n + m) operation, where n is the number of elements to be added and m is xtd::collections::generic::list::count.
        void add_range(std::initializer_list<type_t> il) {insert_range(count(), il);}
        
        /// @cond
        template<class enumerable_t>
        void add_range(const enumerable_t& enumerable) {insert_range(count(), enumerable);}
        /// @endcond
        
        /// @brief Returns a read-only xtd::collections::object_model::read_only_collection <type_t> wrapper for the current collection.
        /// @return An object that acts as a read-only wrapper around the current xtd::collections::generic::list <type_t>.
        /// @remarks To prevent any modifications to the xtd::collections::generic::list <type_t> object, expose it only through this wrapper. A xtd::collections::object_model::read_only_collection <type_t> object does not expose methods that modify the collection. However, if changes are made to the underlying xtd::collections::generic::list <type_t> object, the read-only collection reflects those changes.
        /// @remarks This method is an O(1) operation.
        read_only_collection as_read_only() const noexcept {return read_only_collection {self_};}
        
        /// @brief Searches the entire sorted xtd::collections::generic::list <type_t> for an element using the default comparer and returns the zero-based index of the element.
        /// @param item The object to locate.
        /// @return The zero-based index of item in the sorted xtd::collections::generic::list <type_t>, if item is found; otherwise, a number greater than xtd::collections::genric::list::count that is the bitwise complement of the index of the next element that is larger than item or, if there is no larger element, the bitwise complement of xtd::collections::genric::list::count.
        /// @exception xtd::invalid_operation_exception The default comparer xtd::collections::generic::comparer::default_comparer cannot find an implementation of the xtd::icomparable <type_t> generic interface.
        /// @par Examples
        /// The xtd::collections::generic::list::binary_search method overload is then used to search for two strings that are not in the list, and the xtd::collections::generic::list::insert method is used to insert them. The return value of the xtd::collections::generic::list::binary_search method is greater than xtd::collections::generic::list::count in each case, because the strings are not in the list. Taking the bitwise complement of this number produces the index of the first element in the list that is larger than the search string, and inserting at this location preserves the sort order. The second search string is larger than any element in the list, so the insertion position is at the end of the list.
        /// @include generic_list_binary_search.cpp
        /// @remarks This method uses the default comparer xtd::collections::generic::comparer::default_comparer for type `type_t` to determine the order of list elements. The xtd::collections::generic::comparer::default_comparer property checks whether type `type_t` implements the xtd::icomparable <type_t> generic interface and uses that implementation, if available. If not, xtd::collections::generic::comparer::default_comparer checks whether type `type_t` implements the xtd::icomparable interface. If type `type_t` does not implement either interface, xtd::collections::generic::comparer::default_comparer throws an xtd::invalid_operation_exception.
        /// @remarks The xtd::collections::generic::list <type_t> must already be sorted according to the comparer implementation; otherwise, the result is incorrect.
        /// @remarks If the xtd::collections::generic::list <type_t> contains more than one element with the same value, the method returns only one of the occurrences, and it might return any one of the occurrences, not necessarily the first one.
        /// @remarks If the xtd::collections::generic::list <type_t> does not contain the specified value, the method returns an integer greater than xtd::collections::generic::list::count. You can apply the bitwise complement operation (~) to this integer to get the index of the first element that is larger than the search value. When inserting the value into the xtd::collections::generic::list <type_t>, this index should be used as the insertion point to maintain the sort order.
        /// @remarks This method is an O(log n) operation, where n is the number of elements in the range.
        /// @remarks The following code example demonstrates the xtd::collections::generic::list::sort() method overload and the xtd::collections::generic::list::binary_search method overload. A xtd::collections::generic::list <type_t> of strings is created and populated with four strings, in no particular order. The list is displayed, sorted, and displayed again.
        xtd::size binary_search(const type_t& item) const noexcept {return binary_search(0, count(), item, xtd::collections::generic::comparer<type_t>::default_comparer);}
        /// @brief Searches the entire sorted xtd::collections::generic::list <type_t> for an element using the specified comparer and returns the zero-based index of the element.
        /// @param item The object to locate.
        /// @param comparer The xtd::collections::generic::icomparer <type_t> implementation to use when comparing elements.
        /// @return The zero-based index of item in the sorted xtd::collections::generic::list <type_t>, if item is found; otherwise, a number greater than xtd::collections::genric::list::count that is the bitwise complement of the index of the next element that is larger than item or, if there is no larger element, the bitwise complement of xtd::collections::genric::list::count.
        /// @exception xtd::invalid_operation_exception The default comparer xtd::collections::generic::comparer::default_comparer cannot find an implementation of the xtd::icomparable <type_t> generic interface.
        /// @remarks The comparer customizes how the elements are compared. For example, you can use a xtd::case_insensitive_comparer instance as the comparer to perform case-insensitive string searches.
        /// @remarks If comparer is provided, the elements of the xtd::collections::generic::list <type_t> are compared to the specified value using the specified xtd::collections::generic::icomparer <type_t> implementation.
        /// @remarks The xtd::collections::generic::list <type_t> must already be sorted according to the comparer implementation; otherwise, the result is incorrect.
        /// @remarks If the xtd::collections::generic::list <type_t> contains more than one element with the same value, the method returns only one of the occurrences, and it might return any one of the occurrences, not necessarily the first one.
        /// @remarks If the xtd::collections::generic::list <type_t> does not contain the specified value, the method returns an integer greater than xtd::collections::generic::list::count. You can apply the bitwise complement operation (~) to this integer to get the index of the first element that is larger than the search value. When inserting the value into the xtd::collections::generic::list <type_t>, this index should be used as the insertion point to maintain the sort order.
        /// @remarks This method is an O(log n) operation, where n is the number of elements in the range.
        xtd::size binary_search(const type_t& item, const xtd::collections::generic::icomparer<type_t>& comparer) const noexcept {return binary_search(0, count(), item, comparer);}
        /// @brief Searches a range of elements in the sorted xtd::collections::generic::list <type_t> for an element using the specified comparer and returns the zero-based index of the element.
        /// @param index The zero-based starting index of the range to search.
        /// @param count The length of the range to search.
        /// @param item The object to locate.
        /// @param comparer The xtd::collections::generic::icomparer <type_t> implementation to use when comparing elements, or null to use the default comparer xtd::collections::generic::comparer<type_t>::default_comparer.
        /// @return The zero-based index of item in the sorted xtd::collections::generic::list <type_t>, if item is found; otherwise, a number greater than xtd::collections::genric::list::count that is the bitwise complement of the index of the next element that is larger than item or, if there is no larger element, the bitwise complement of xtd::collections::genric::list::count.
        /// @exception xtd::argument_out_of_range_exception `index` and `count` do not denote a valid range in the xtd::collections::generic::list <type_t>.
        /// @exception xtd::invalid_operation_exception The default comparer xtd::collections::generic::comparer::default_comparer cannot find an implementation of the xtd::icomparable <type_t> generic interface.
        /// @remarks The comparer customizes how the elements are compared. For example, you can use a xtd::case_insensitive_comparer instance as the comparer to perform case-insensitive string searches.
        /// @remarks If comparer is provided, the elements of the xtd::collections::generic::list <type_t> are compared to the specified value using the specified xtd::collections::generic::icomparer <type_t> implementation.
        /// @remarks The xtd::collections::generic::list <type_t> must already be sorted according to the comparer implementation; otherwise, the result is incorrect.
        /// @remarks If the xtd::collections::generic::list <type_t> contains more than one element with the same value, the method returns only one of the occurrences, and it might return any one of the occurrences, not necessarily the first one.
        /// @remarks If the xtd::collections::generic::list <type_t> does not contain the specified value, the method returns an integer greater than xtd::collections::generic::list::count. You can apply the bitwise complement operation (~) to this integer to get the index of the first element that is larger than the search value. When inserting the value into the xtd::collections::generic::list <type_t>, this index should be used as the insertion point to maintain the sort order.
        /// @remarks This method is an O(log n) operation, where n is the number of elements in the range.
        xtd::size binary_search(xtd::size index, xtd::size count, const type_t& item, const xtd::collections::generic::icomparer<type_t>& comparer) const {
          if (index + count > self_.count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          auto first = data_->items.begin();
          auto last = data_->items.begin();
          std::advance(first, index);
          std::advance(last, index + count);
          auto position = std::lower_bound(first, last, item, helpers::lesser<type_t> {comparer});
          
          if (position != data_->items.end() && !comparer.compare(item, *position))
            return std::distance(data_->items.begin(), position);
          return ~std::distance(data_->items.begin(), position);
        }
        
        /// @brief Removes all elements from the xtd::collections::generic::list <type_t>.
        /// @remarks xtd::collections::generic::list::count is set to 0, and references to other objects from elements of the collection are also released.
        /// @remarks xtd::collections::generic::list::capacity remains unchanged. To reset the capacity of the xtd::collections::generic::list <type_t>, call the xtd::collections::generic::list::trim_excess method or set the xtd::collections::generic::list::capacity property directly. Decreasing the capacity reallocates memory and copies all the elements in the xtd::collections::generic::list <type_t>. Trimming an empty xtd::collections::generic::list <type_t> sets the capacity of the xtd::collections::generic::list <type_t> to the default capacity.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        void clear() override {data_->items.clear();}
        
        /// @brief Determines whether an element is in the xtd::colllections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::colllections::generic::list <type_t>. The value can be null for reference types.
        /// @return `true` if item is found in the xtd::colllections::generic::list <type_t>; otherwise, `false`.
        bool contains(const type_t& value) const noexcept override {
          return index_of(value) != npos;
        }
        
        /// @brief Converts the elements in the current xtd::colllections::generic::list <type_t> to another type, and returns a list containing the converted elements.
        /// @tparam output_t The type of the elements of the target array.
        /// @param converter A xtd::converter <output_t, input_t> delegate that converts each element from one type to another type.
        /// @return A xtd::collections::generic::list <type_t> of the target type containing the converted elements from the current xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following example defines a method named `point_f_to_point` that converts a xtd::drawing::point_f structure to a xtd::drawing::point structure. The example then creates a xtd::collections::generic::list <type_t> of xtd::drawing::point_f structures, creates a xtd::converter <point_f, point> delegate to represent the `point_f_to_point` method, and passes the delegate to the xtd::collections::generic::list::convert_all method. The xtd::collections::generic::list::convert_all method passes each element of the input list to the `point_f_to_point` method and puts the converted elements into a new list of Point structures. Both lists are displayed.
        /// @include generic_list_convert_all.cpp
        template<class output_t, class converter_t>
        list<output_t> convert_all(converter_t converter) const {
          auto result = list<output_t> {};
          auto apply_converter = xtd::converter<output_t, const type_t&> {converter};
          for (const auto& item : self_)
            result.add(apply_converter(item));
          return result;
        }
        
        /// @brief Copies the entire xtd::collections::generic::list <type_t> to a compatible one-dimensional array.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from ICollection. The xtd::array must have zero-based indexing.
        /// @exception ArgumentNullException array is null.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::list <type_t> is greater than the number of elements that the destination array can contain.
        /// @par Examples
        /// The following code example demonstrates all three overloads of the CopyTo method. A xtd::collections::generic::list <type_t> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the copy_to(type_t[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(type_t[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, type_t[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
        /// @include ListCopyTo.cpp
        /// @remarks TThis method uses xtd::array::copy to copy the elements.
        /// @remarks The elements are copied to the xtd::array in the same order in which the enumerator iterates through the xtd::collections::generic::list <type_t>.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        void copy_to(xtd::array<type_t>& array) const {copy_to(0, array, 0, count());}
        /// @brief Copies the entire xtd::colllections::generic::list <type_t> to a compatible one-dimensional array, starting at the specified index of the target array.
        /// @param array The one-dimensional Array that is the destination of the elements copied from xtd::colllections::generic::list <type_t>. The Array must have zero-based indexing.
        /// @param array_index The zero-based index in array at which copying begins.
        /// @exception xtd::argument_out_of_range_exception The number of elements in the source xtd::colllections::generic::list <type_t> is greater than the available space from arrayIndex to the end of the destination array.
        /// @remarks This method uses xtd::array::copy to copy the elements.
        /// @remarks The elements are copied to the xtd::array in the same order in which the enumerator iterates through the xtd::colllections::generic::list <type_t>.
        /// @remarks This method is an O(n) operation, where n is xtd::colllections::generic::list::count.
        void copy_to(xtd::array<type_t>& array, size_type array_index) const override {copy_to(0, array, array_index, count());}
        /// @brief Copies the entire xtd::collections::generic::list <type_t> to a compatible one-dimensional array, starting at the specified index of the target array.
        /// @param index The zero-based index in the source xtd::collections::generic::list <type_t> at which copying begins.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from ICollection. The xtd::array must have zero-based indexing.
        /// @param arrayIndex The zero-based index in array at which copying begins;
        /// @param count The number of elements to copy.
        /// @exception ArgumentNullException array is null.
        /// @exception xtd::argument_out_of_range_exception The arrayIndex or count is less than 0.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::list <type_t> is greater than the number of elements that the destination array can contain.
        /// @par Examples
        /// The following code example demonstrates all three overloads of the CopyTo method. A xtd::collections::generic::list <type_t> of strings is created and populated with 5 strings. An empty string array of 15 elements is created, and the CopyTo(type_t[]) method overload is used to copy all the elements of the list to the array beginning at the first element of the array. The CopyTo(type_t[], Int32) method overload is used to copy all the elements of the list to the array beginning at array index 6 (leaving index 5 empty). Finally, the CopyTo(Int32, type_t[], Int32, Int32) method overload is used to copy 3 elements from the list, beginning with index 2, to the array beginning at array index 12 (leaving index 11 empty). The contents of the array are then displayed.
        /// @include ListCopyTo.cpp
        /// @remarks TThis method uses xtd::array::copy to copy the elements.
        /// @remarks The elements are copied to the xtd::array in the same order in which the enumerator iterates through the xtd::collections::generic::list <type_t>.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        void copy_to(size_type index, xtd::array<type_t>& array, size_type array_index, size_type count) const {
          if (index + count > self_.count() || array_index + count > array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          for (auto i = index; i < (index + count); ++i)
            array[array_index++] = self_[i];
        }
        
        /// @brief Ensures that the capacity of this list is at least the specified `capacity`. If the current capacity is less than `capacity`, it is increased to at least the specified `capacity`.
        /// @param capacity The minimum capacity to ensure.
        /// @return The new capacity of this list.
        /// @exception xtd::out_of_memory There is not enough memory available on the system.
        xtd::size ensure_capacity(xtd::size capacity) {
          data_->items.reserve(capacity);
          return self_.capacity();
        }
        
        /// @brief Determines whether the specified object is equal to the current object.
        /// @param obj The object to compare with the current object.
        /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
        /// @par Examples
        /// The following code example compares the current instance with another object.
        /// @include object_equals.cpp
        bool equals(const object& obj) const noexcept override {return is<list<value_type>>(obj) && equals(static_cast<const list<value_type>& > (obj));}
        /// @brief Indicates whether the current object is equal to another object of the same type.
        /// @param obj An object to compare with this object.
        /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
        bool equals(const list& obj) const noexcept override {
          if (count() != obj.count()) return false;
          for (size_type i = 0; i < count(); i++)
            if (!helpers::equator<type_t> {}(self_[i], obj[i])) return false;
          return true;
        }
        
        /// @brief Determines whether the xtd::collections::generic::list <type_t> contains elements that match the conditions defined by the specified predicate.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return `true` if the xtd::collections::generic::list <type_t> contains one or more elements that match the conditions defined by the specified `predicate`; otherwise, `false`.
        /// @par Examples
        /// The following example demonstrates the xtd::collections::generic::list::exists method and several other methods that use the xtd::predicate <type_t> generic delegate.
        /// <br>A xtd::collections::generic::list <type_t> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The example also defines a search predicate method named `ends_with_saurus`, which accepts a string parameter and returns a boolean value indicating whether the input string ends in "saurus".
        /// <br>The xtd::collections::generic::list::find, xtd::collections::generic::list::find_last, and xtd::collections::generic::list::findA_all methods are used to search the list with the search predicate method, and then the xtd::collections::generic::list::remove_all method is used to remove all entries ending with "saurus".
        /// <br>Finally, the xtd::collections::generic::list::exists method is called. It traverses the list from the beginning, passing each element in turn to the `ends_with_saurus` method. The search stops and the method returns `true` if the `ends_with_saurus` method returns `true` for any element. The xtd::collections::generic::list::exists method returns `false` because all such elements have been removed.
        /// @include generic_list_exists.cpp
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        bool exists(predicate_t match) const {
          return find_index(match) != npos;
        }
        
        /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the first occurrence within the entire xtd::collections::generic::list <type_t>.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return The first element that matches the conditions defined by the specified `predicate`, if found; otherwise, the default value for type `type_t`.
        /// @par Examples
        /// The following example demonstrates the xtd::collections::generic::list::exists method and several other methods that use the xtd::predicate <type_t> generic delegate.
        /// <br>A xtd::collections::generic::list <type_t> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The example also defines a search predicate method named `ends_with_saurus`, which accepts a string parameter and returns a boolean value indicating whether the input string ends in "saurus".
        /// <br>The xtd::collections::generic::list::find, xtd::collections::generic::list::find_last, and xtd::collections::generic::list::findA_all methods are used to search the list with the search predicate method, and then the xtd::collections::generic::list::remove_all method is used to remove all entries ending with "saurus".
        /// <br>Finally, the xtd::collections::generic::list::exists method is called. It traverses the list from the beginning, passing each element in turn to the `ends_with_saurus` method. The search stops and the method returns `true` if the `ends_with_saurus` method returns `true` for any element. The xtd::collections::generic::list::exists method returns `false` because all such elements have been removed.
        /// @include generic_list_exists.cpp
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        optional<type_t> find(predicate_t match) const {
          auto index = find_index(match);
          if (index == npos) return nullopt;
          return self_[index];
        }
        
        /// @brief Retrieves all the elements that match the conditions defined by the specified predicate.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return A xtd::collections::generic::list <type_t> containing all the elements that match the conditions defined by the specified `predicate`, if found; otherwise, an empty xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following example demonstrates the xtd::collections::generic::list::exists method and several other methods that use the xtd::predicate <type_t> generic delegate.
        /// <br>A xtd::collections::generic::list <type_t> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The example also defines a search predicate method named `ends_with_saurus`, which accepts a string parameter and returns a boolean value indicating whether the input string ends in "saurus".
        /// <br>The xtd::collections::generic::list::find, xtd::collections::generic::list::find_last, and xtd::collections::generic::list::findA_all methods are used to search the list with the search predicate method, and then the xtd::collections::generic::list::remove_all method is used to remove all entries ending with "saurus".
        /// <br>Finally, the xtd::collections::generic::list::exists method is called. It traverses the list from the beginning, passing each element in turn to the `ends_with_saurus` method. The search stops and the method returns `true` if the `ends_with_saurus` method returns `true` for any element. The xtd::collections::generic::list::exists method returns `false` because all such elements have been removed.
        /// @include generic_list_exists.cpp
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        list find_all(predicate_t match) const {
          auto predicate = xtd::predicate<const type_t&> {match};
          auto result = list {};
          for (const auto& item : self_)
            if (predicate(item)) result.add(item);
          return result;
        }
        
        /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the first occurrence within the entire xtd::collections::generic::list <type_t>.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return The zero-based index of the first occurrence of an element that matches the conditions defined by match, if found; otherwise, xtd::collections::generic::list::npos.
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        xtd::size find_index(predicate_t match) const {return find_index(0, count(), match);}
        /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the first occurrence within the range of elements in the xtd::collections::generic::list <type_t> that extends from the specified index to the last element.
        /// @param start_index The zero-based starting index of the search.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return The zero-based index of the first occurrence of an element that matches the conditions defined by match, if found; otherwise, xtd::collections::generic::list::npos.
        /// @exception xtd::argument_out_of_range_exception `start_index` is outside the range of valid indexes for the xtd::collections::generic::list <type_t>..
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        xtd::size find_index(xtd::size start_index, predicate_t match) const {return find_index(start_index, count() - start_index, match);}
        /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the first occurrence within the range of elements in the xtd::collections::generic::list <type_t> that starts at the specified index and contains the specified number of elements.
        /// @param start_index The zero-based starting index of the search.
        /// @param count The number of elements in the section to search.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return The zero-based index of the first occurrence of an element that matches the conditions defined by match, if found; otherwise, xtd::collections::generic::list::npos.
        /// @exception xtd::argument_out_of_range_exception `start_index` is outside the range of valid indexes for the xtd::collections::generic::list <type_t>.<br>-or-<br>`start_index` and `count` do not specify a valid section in the xtd::collections::generic::list <type_t>.
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        xtd::size find_index(xtd::size start_index, xtd::size count, predicate_t match) const {
          if (start_index > self_.count() || start_index + count > self_.count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          auto predicate = xtd::predicate<const type_t&> {match};
          for (auto index = start_index; index < start_index + count; ++index)
            if (predicate(self_[index])) return index;
          return npos;
        }
        
        /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the last occurrence within the entire xtd::collections::generic::list <type_t>.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return The last element that matches the conditions defined by the specified predicate, if found; otherwise, the default value for type `type_t`.
        /// @par Examples
        /// The following example demonstrates the xtd::collections::generic::list::exists method and several other methods that use the xtd::predicate <type_t> generic delegate.
        /// <br>A xtd::collections::generic::list <type_t> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The example also defines a search predicate method named `ends_with_saurus`, which accepts a string parameter and returns a boolean value indicating whether the input string ends in "saurus".
        /// <br>The xtd::collections::generic::list::find, xtd::collections::generic::list::find_last, and xtd::collections::generic::list::findA_all methods are used to search the list with the search predicate method, and then the xtd::collections::generic::list::remove_all method is used to remove all entries ending with "saurus".
        /// <br>Finally, the xtd::collections::generic::list::exists method is called. It traverses the list from the beginning, passing each element in turn to the `ends_with_saurus` method. The search stops and the method returns `true` if the `ends_with_saurus` method returns `true` for any element. The xtd::collections::generic::list::exists method returns `false` because all such elements have been removed.
        /// @include generic_list_exists.cpp
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        optional<type_t> find_last(predicate_t match) const {
          auto index = find_last_index(match);
          if (index == npos) return nullopt;
          return self_[index];
        }
        
        /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the last occurrence within the entire xtd::collections::generic::list <type_t>.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return The zero-based index of the last occurrence of an element that matches the conditions defined by match, if found; otherwise, xtd::collections::generic::list::npos.
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        xtd::size find_last_index(predicate_t match) const {return find_last_index(count() - 1, count(), match);}
        /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the last occurrence within the range of elements in the xtd::collections::generic::list <type_t> that extends from the first element to the specified index.
        /// @param start_index The zero-based starting index of the backward search.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return The zero-based index of the last occurrence of an element that matches the conditions defined by match, if found; otherwise, xtd::collections::generic::list::npos.
        /// @exception xtd::argument_out_of_range_exception `start_index` is outside the range of valid indexes for the xtd::collections::generic::list <type_t>.
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        xtd::size find_last_index(xtd::size start_index, predicate_t match) const {return find_last_index(start_index, start_index + 1, match);}
        /// @brief Searches for an element that matches the conditions defined by the specified predicate, and returns the zero-based index of the last occurrence within the range of elements in the xtd::collections::generic::list <type_t> that contains the specified number of elements and ends at the specified index.
        /// @param start_index The zero-based starting index of the backward search.
        /// @param count The number of elements in the section to search.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return The zero-based index of the last occurrence of an element that matches the conditions defined by match, if found; otherwise, xtd::collections::generic::list::npos.
        /// @exception xtd::argument_out_of_range_exception `start_index` is outside the range of valid indexes for the xtd::collections::generic::list <type_t>.<br>-or-<br>`start_index` and `count` do not specify a valid section in the xtd::collections::generic::list <type_t>.
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        xtd::size find_last_index(xtd::size start_index, xtd::size count, predicate_t match) const {
          if (start_index >= self_.count() || count > start_index + 1) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          auto predicate = xtd::predicate<const type_t&> {match};
          auto end_index = start_index + 1 - count;
          for (auto index = start_index; ; --index) {
            if (predicate(self_[index])) return index;
            if (index == end_index) break;
          }
          return npos;
        }
        
        /// @brief Performs the specified action on each element of the xtd::collections::generic::list <type_t>.
        /// @param action The xtd::action <type_t> delegate to perform on each element of the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following example demonstrates the use of the xtd::action <type_t> delegate to print the contents of a xtd::collections::generic::list <type_t> object. In this example the `print` method is used to display the contents of the list to the console.
        /// @include generic_list_for_each.cpp
        /// @remarks The xtd::action <type_t> is a delegate to a method that performs an action on the object passed to it. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::action <type_t> delegate.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        /// @remarks Modifying the underlying collection in the body of the Action<T> delegate is not supported and causes undefined behavior.
        template<class action_t>
        void for_each(action_t action) {
          auto apply_action = xtd::action<const type_t&> {action};
          for (const auto& item : self_)
            apply_action(item);
        }
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::list <type_t>.
        /// @return A xtd::collections::generic::.enumerator for the xtd::collections::generic::list <type_t>.
        enumerator<value_type> get_enumerator() const noexcept override {
          struct list_enumerator : public ienumerator<value_type> {
            explicit list_enumerator(const list& items, xtd::size version) : items_(items), version_(version) {}
            
            const value_type& current() const override {
              if (index_ >= items_.count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
              if (version_ != items_.data_->items.version()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              return items_[index_];
            }
            
            bool move_next() override {
              if (version_ != items_.data_->items.version()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              return ++index_ < items_.count();
            }
            
            void reset() override {
              version_ = items_.data_->items.version();
              index_ = list::npos;
            }
            
          private:
            size_type index_ = list::npos;
            const list& items_;
            size_type version_ = 0;
          };
          
          return {new_ptr<list_enumerator>(self_, data_->items.version())};
        }
        
        /// @brief Creates a shallow copy of a range of elements in the source xtd::collections::generic::list <type_t>.
        /// @param index The zero-based xtd::collections::generic::list <type_t> index at which the range starts.
        /// @param count The number of elements in the range.
        /// @return A shallow copy of a range of elements in the source xtd::collections::generic::list <type_t>.
        /// @exception xtd::argument_out_of_range_exception index and count do ! denote a valid range of elements in the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following code example demonstrates the xtd::collections::generic::list::get_range method and other methods of the xtd::collections::generic::list <type_t> class that act on ranges. At the end of the code example, the xtd::collections::generic::list::get_range method is used to get three items from the list, beginning with index location 2. The xtd::collections::generic::ist::to_array method is called on the resulting xtd::collections::generic::list <type_t>, creating an array of three elements. The elements of the array are displayed.
        /// @include List3.cpp
        /// @remarks A shallow copy of a collection of reference types, or a subset of that collection, contains only the references to the elements of the collection. The objects themselves are ! copied. The references in the new list point to the same objects as the references in the original list.
        /// @remarks A shallow copy of a collection of value types, or a subset of that collection, contains the elements of the collection. However, if the elements of the collection contain references to other objects, those objects are ! copied. The references in the elements of the new collection point to the same objects as the references in the elements of the original collection.
        /// @remarks In contrast, a deep copy of a collection copies the elements and everything directly or indirectly referenced by the elements.
        /// @remarks This method is an O(n) operation, where n is count.
        list get_range(size_type index, size_type count) {
          if (index + count > self_.count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          return list<type_t> {data_->items.begin() + index, data_->items.begin() + index + count};
        }
        
        /// @brief Determines the index of a specific item in the xtd::collections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::collections::generic::list <type_t>.
        /// @return The index of value if found in the list; otherwise, xtd::collections::generic::ilist::npos.
        size_type index_of(const type_t& value) const noexcept override {
          if (count() == 0)  return npos;
          return index_of(value, 0, count());
        }
        /// @brief Determines the index of a specific item in the xtd::collections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::collections::generic::list <type_t>.
        /// @param index The zero-based starting index of the search.
        /// @return The index of value if found in the xtd::collections::generic::list; otherwise, xtd::collections::generic::ilist::npos.
        /// @exception xtd::argument_out_of_range_exception `index` is outside the range of valid indexes for the xtd::collections::generic::list <type_t>.
        size_type index_of(const type_t& value, size_type index) const {return index_of(value, index, count() - index);}
        /// @brief Determines the index of a specific item in the xtd::collections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::collections::generic::list <type_t>.
        /// @param index The zero-based starting index of the search.
        /// @param count The number of elements in the section to search
        /// @return The index of value if found in the xtd::collections::generic::list; otherwise, xtd::collections::generic::ilist::npos.
        /// @exception xtd::argument_out_of_range_exception `index` and `countù  do not specify a valid section in the xtd::collections::generic::list <type_t>.
        size_type index_of(const type_t& value, size_type index, size_type count) const {
          return find_index(index, count, delegate_(auto n) {return helpers::equator<type_t> {}(n, value);});
        }
        
        /// @brief Inserts an element into the xtd::collections::generic::list <type_t> at the specified index.
        /// @param index The zero-based index at which the new element should be inserted.
        /// @param value The element should be inserted into the xtd::collections::generic::list <type_t>.
        /// @exception xtd::argument_out_of_range_exception index is is greater than xtd::collections::generic::list::count.
        /// @remarks xtd::collections::generic::list <type_t> allows duplicate elements.
        void insert(size_type index, const type_t& value) override {
          if (index > count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          data_->items.insert(data_->items.begin() + index, value);
        }
        /// @brief Inserts an element into the xtd::collections::generic::list <type_t> at the specified index.
        /// @param index The zero-based index at which the new element should be inserted.
        /// @param value The element should be inserted into the xtd::collections::generic::list <type_t>.
        /// @exception xtd::argument_out_of_range_exception index is is greater than xtd::collections::generic::list::count.
        /// @remarks xtd::collections::generic::list <type_t> allows duplicate elements.
        void insert(size_type index, type_t&& value) {
          if (index > count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          data_->items.insert(data_->items.begin() + index, std::move(value));
        }
        
        /// @brief Inserts copy of elements from a collection into the xtd::collections::generic::list <type_t> at the specified index.
        /// @param index The zero-based index at which the new elements should be inserted.
        /// @param collection The collection whose elements should be inserted into the xtd::collections::generic::list <type_t>.
        /// @exception xtd::argument_out_of_range_exception index is is greater than xtd::collections::generic::list::count.
        /// @par Examples
        /// The following code example demonstrates the xtd::collections::generic::list <type_t> constructor and various methods of the xtd::collections::generic::list <type_t> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The xtd::collections::generic::list::capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
        /// @include generic_list3.cpp
        /// @remarks xtd::collections::generic::list <type_t> allows duplicate elements.
        /// @remarks The order of the elements in the collection is preserved in the xtd::collections::generic::list <type_t>.
        void insert_range(size_type index, const xtd::collections::generic::ienumerable<type_t>& enumerable) {
          if (index > count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          
          // If the collection is this instance, it must be copied to avoid an infinite loop.
          if (static_cast<const void*>(&enumerable) == static_cast<const void*>(this)) {
            insert_range(index, list(enumerable));
            return;
          }
          
          data_->items.insert(data_->items.begin() + index, enumerable.begin(), enumerable.end());
        }
        /// @brief Inserts copy of elements from a collection into the xtd::collections::generic::list <type_t> at the specified index.
        /// @param index The zero-based index at which the new elements should be inserted.
        /// @param collection The collection whose elements should be inserted into the xtd::collections::generic::list <type_t>.
        /// @exception xtd::argument_out_of_range_exception index is is greater than xtd::collections::generic::list::count.
        /// @par Examples
        /// The following code example demonstrates the xtd::collections::generic::list <type_t> constructor and various methods of the xtd::collections::generic::list <type_t> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The xtd::collections::generic::list::capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
        /// @include generic_list3.cpp
        /// @remarks xtd::collections::generic::list <type_t> allows duplicate elements.
        /// @remarks The order of the elements in the collection is preserved in the xtd::collections::generic::list <type_t>.
        void insert_range(size_type index, const std::initializer_list<type_t>& items) {
          if (index > count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          data_->items.insert(data_->items.begin() + index, items.begin(), items.end());
        }
        
        /// @cond
        template<class collection_t>
        void insert_range(size_type index, const collection_t& items) {
          if (index > count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          
          // If the collection is this instance, it must be copied to avoid an infinite loop.
          if (static_cast<const void*>(&items) == static_cast<const void*>(this)) {
            insert_range(index, list(items));
            return;
          }
          
          data_->items.insert(data_->items.begin() + index, items.begin(), items.end());
        }
        /// @endcond
        
        /// @brief Determines the last index of a specific item in the xtd::collections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::collections::generic::list <type_t>.
        /// @return The last index of value if found in the list; otherwise, xtd::collections::generic::list::npos.
        size_type last_index_of(const type_t& value) const noexcept {
          if (count() == 0) return npos;
          return last_index_of(value, count() - 1, count());
        }
        /// @brief Determines the last index of a specific item in the xtd::collections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::collections::generic::list <type_t>.
        /// @param index The zero-based starting index of the search.
        /// @return The last index of value if found in the list; otherwise, xtd::collections::generic::list::npos.
        /// @exception xd::argument_out_of_range_exception The parameters `indexù  is greater than xtd::collections::generic::list::count().
        size_type last_index_of(const type_t& value, size_type index) const {
          return last_index_of(value, index, index + 1);
        }
        /// @brief Determines the last index of a specific item in the xtd::collections::generic::list <type_t>.
        /// @param value The object to locate in the xtd::collections::generic::list <type_t>.
        /// @param index The zero-based starting index of the search.
        /// @param count The number of elements in the section to search
        /// @return The last index of value if found in the list; otherwise, xtd::collections::generic::list::npos.
        /// @exception xd::argument_out_of_range_exception `index` and `count` do not specify a valid section in the xtd::collections::generic::list <type_t>.
        size_type last_index_of(const type_t& value, size_type index, size_type count) const {
          return find_last_index(index, count, delegate_(auto n) {return helpers::equator<type_t> {}(n, value);});
        }
        
        /// @brief Removes the first occurrence of a specific object from the xtd::collections::generic::list <type_t>.
        /// @param item The object to remove from the xtd::collections::generic::list <type_t>.
        /// @return `true` if item is successfully removed; otherwise, `false`. This method also returns `false` if item was not found in the xtd::collections::generic::list <type_t>.
        /// @remarks If type `typ_t` implements the xtd::iequatable <type_t> generic interface, the equality comparer is the xtd::iequatable::equals method of that interface; otherwise, the default equality comparer is xtd::object::equals.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        bool remove(const type_t& item) noexcept override {
          auto index = index_of(item);
          if (index == npos) return false;
          remove_at(index);
          return true;
        }
        
        /// @brief Removes all the elements that match the conditions defined by the specified predicate.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return The number of elements removed from the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following example demonstrates the xtd::collections::generic::list::exists method and several other methods that use the xtd::predicate <type_t> generic delegate.
        /// <br>A xtd::collections::generic::list <type_t> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The example also defines a search predicate method named `ends_with_saurus`, which accepts a string parameter and returns a boolean value indicating whether the input string ends in "saurus".
        /// <br>The xtd::collections::generic::list::find, xtd::collections::generic::list::find_last, and xtd::collections::generic::list::findA_all methods are used to search the list with the search predicate method, and then the xtd::collections::generic::list::remove_all method is used to remove all entries ending with "saurus".
        /// <br>Finally, the xtd::collections::generic::list::exists method is called. It traverses the list from the beginning, passing each element in turn to the `ends_with_saurus` method. The search stops and the method returns `true` if the `ends_with_saurus` method returns `true` for any element. The xtd::collections::generic::list::exists method returns `false` because all such elements have been removed.
        /// @include generic_list_exists.cpp
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class predicate_t>
        xtd::size remove_all(predicate_t match) {
          auto predicate = xtd::predicate<const type_t&> {match};
          auto count = xtd::size {0};
          auto iterator = data_->items.begin();
          while (iterator != data_->items.end())
            if (!predicate(*iterator)) iterator++;
            else {
              iterator = data_->items.erase(iterator);
              ++count;
            }
          return count;
        }
        
        /// @brief Removes the element at the specified index of the xtd::collections::generic::list <type_t>.
        /// @param index The zero-based index of the item to remove
        /// @exception xtd::argument_out_of_range_exception index is less than 0 or index is greater than xtd::collections::generic::list::count.
        void remove_at(size_type index) override {
          if (index >= count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          data_->items.erase(data_->items.begin() + index);
        }
        
        /// @brief Removes a range of elements from the xtd::collections::generic::list <type_t>.
        /// @param index The zero-based index of the item to remove
        /// @param count The number of elements to remove
        /// @exception xtd::argument_out_of_range_exception index or count is less than 0 or index + count is greater than xtd::collections::generic::list::count.
        /// @par Examples
        /// The following code example demonstrates the xtd::collections::generic::list <type_t> constructor and various methods of the xtd::collections::generic::list <type_t> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The xtd::collections::generic::list::capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
        /// @include generic_list3.cpp
        /// @remarks The items are removed and all the elements following them in the xtd::collections::generic::list <type_t> have their indexes reduced by count.
        void remove_range(size_type index, size_type count) {
          if (index + count > self_.count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          data_->items.erase(data_->items.begin() + index, data_->items.begin() + index + count);
        }
        
        /// @brief Resizes the container to contain `count` elements, does nothing if `count == size().
        /// @param count The new size of the container.
        /// @exception xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
        /// @remarks If the current size is greater than `count`, the container is reduced to its first `count` elements.
        /// @remarks If the current size is less than `count`, additional default-inserted elements are appended.
        virtual void resize(size_type count)  {resize(count, value_type {});}
        /// @brief Resizes the container to contain `count` elements, does nothing if `count == size().
        /// @param count The new size of the container.
        /// @param value The value to initialize the new elements with.
        /// @exception xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
        /// @remarks If the current size is greater than `count`, the container is reduced to its first `count` elements.
        /// @remarks If the current size is less than `count`, additional copies of `value` are appended.
        virtual void resize(size_type count, const value_type& value) {
          if (count > data_->items.max_size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::out_of_memory);;
          if (count == self_.count()) return;
          data_->items.resize(count, value);
        }
        
        /// @brief Reverses the order of the elements in the entire xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following example demonstrates both overloads of the xtd::collections::generic::list::reverse method. The example creates a xtd::collections::generic::list <type_t> of strings and adds six strings. The xtd::collections::generic::list::reverse () method overload is used to reverse the list, and then the xtd::collections::generic::list::reverse (xtd::size, xtd::size) method overload is used to reverse the middle of the list, beginning with element 1 and encompassing four elements.
        /// @include generic_list_reverse.cpp
        /// @remarks This method uses xtd::array::reverse to reverse the order of the elements.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        void reverse() {reverse(0, count());}
        /// @brief Reverses the order of the elements in the specified range.
        /// @param index The zero-based starting index of the range to reverse.
        /// @param count The number of elements in the range to reverse.
        /// @exception xtd::argument_out_of_range_exception `index` and `count` do not denote a valid range of elements in the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following example demonstrates both overloads of the xtd::collections::generic::list::reverse method. The example creates a xtd::collections::generic::list <type_t> of strings and adds six strings. The xtd::collections::generic::list::reverse () method overload is used to reverse the list, and then the xtd::collections::generic::list::reverse (xtd::size, xtd::size) method overload is used to reverse the middle of the list, beginning with element 1 and encompassing four elements.
        /// @include generic_list_reverse.cpp
        /// @remarks This method uses xtd::array::reverse to reverse the order of the elements.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        void reverse(size_type index, size_type count) {
          if (index + count > self_.count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          data_->items.increment_version();
          std::reverse(data_->items.begin() + index, data_->items.begin() + index + count);
        }
        
        /// @brief Creates a shallow copy of a range of elements in the source xtd::collections::generic::list <type_t>.
        /// @param start The zero-based xtd::collections::generic::list <type_t> index at which the range starts.
        /// @param length The length of the range.
        /// @return A shallow copy of a range of elements in the source xtd::collections::generic::list <type_t>.
        /// @exception xt::argument_out_of_range_exception `start` and `length` do not denote a valid range of elements in the xtd::collections::generic::list <type_t>.
        list<type_t> slice(size_type start, size_type length) const {
          if (start + length > count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          return list<type_t> {data_->items.begin() + start, data_->items.begin() + start + length};
        }
        
        /// @brief Sorts the elements in the entire xtd::collections::generic::list <type_t> using the default comparer.
        /// @exception xtd::invalid_operation_exception The default comparer xtd::collections::generic::comparer::default_comparer cannot find an implementation of the xtd::icomparable <type_t> generic interface.
        /// @par Examples
        /// The xtd::collections::generic::list::binary_search method overload is then used to search for two strings that are not in the list, and the xtd::collections::generic::list::insert method is used to insert them. The return value of the xtd::collections::generic::list::binary_search method is gretaer than xtd::collections::generic::list::count in each case, because the strings are not in the list. Taking the bitwise complement of this negative number produces the index of the first element in the list that is larger than the search string, and inserting at this location preserves the sort order. The second search string is larger than any element in the list, so the insertion position is at the end of the list.
        /// @include generic_list_binary_search.cpp
        /// @remarks This method uses the default comparer xtd::collections::generic::comparer::default_comparer for type `type_t` to determine the order of list elements. The xtd::collections::generic::comparer::default_comparer property checks whether type `type_t` implements the xtd::icomparable <type_t> generic interface and uses that implementation, if available. If not, xtd::collections::generic::comparer::default_comparer checks whether type T implements the xtd::icomparable interface. If type `type_t` does not implement either interface, xtd::collections::generic::comparer::default_comparer throws an xtd::invalid_operation_exception.
        /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
        /// @remarks On average, this method is an O(n log n) operation, where n is xtd::collections::generic::list::count; in the worst case it is an O(n ^ 2) operation.
        /// @remarks The following code example demonstrates the xtd::collections::generic::list::sort method overload and the xtd::collections::generic::list::binary_search method overload. A xtd::collections::generic::list <type_t> of strings is created and populated with four strings, in no particular order. The list is displayed, sorted, and displayed again.
        list<type_t>& sort() {return sort(xtd::collections::generic::comparer<type_t>::default_comparer);}
        
        /// @brief Sorts the elements in the entire xtd::collections::generic::list <type_t> using the specified xtd::comparison <type_t>.
        /// @exception xtd::argument_out_of_range_exception The implementation of comparison caused an error during the sort. For example, comparison might not return 0 when comparing an item with itself.
        /// @remarks If comparison is provided, the elements of the xtd::collections::generic::list <type_t> are sorted using the method represented by the delegate.
        /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
        /// @remarks On average, this method is an O(n log n) operation, where n is xtd::collections::generic::list::count; in the worst case it is an O(n ^ 2) operation.
        list<type_t>& sort(xtd::comparison<const type_t&> comparison) {
          struct comparison_comparer {
            comparison_comparer(xtd::comparison<const type_t&> comparison) : comparison_(comparison) {}
            bool operator()(const type_t& e1, const type_t& e2) const {return comparison_(e1, e2) < 0;}
            xtd::comparison<const type_t&> comparison_;
          };
          data_->items.increment_version();
          std::sort(data_->items.begin(), data_->items.end(), comparison_comparer {comparison});
          return self_;
        }
        
        /// @brief Sorts the elements in the entire xtd::collections::generic::list <type_t> using the specified comparer.
        /// @param comparer The xtd::collections::generic::icomparer <type_t> implementation to use when comparing elements, or null to use the default comparer xtd::collections::generic::comparer::default_comparer.
        /// @remarks If comparer is provided, the elements of the xtd::collections::generic::list <type_t> are sorted using the specified xtd::collections::generic::icomparer <type_t> implementation.
        /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
        /// @remarks On average, this method is an O(n log n) operation, where n is xtd::collections::generic::list::count; in the worst case it is an O(n ^ 2) operation.
        list<type_t>& sort(const xtd::collections::generic::icomparer<type_t>& comparer) {
          return sort(0, count(), comparer);
        }
        
        /// @brief Sorts the elements in a range of elements in xtd::collections::generic::list <type_t> using the specified comparer.
        /// @param index The zero-based starting index of the range to sort.
        /// @param count The length of the range to sort.
        /// @param comparer The xtd::collections::generic::icomparer <type_t> implementation to use when comparing elements, or null to use the default comparer xtd::collections::generic::comparer::default_comparer.
        /// @exception xtd::argument_out_of_range_exception The implementation of comparison caused an error during the sort. For example, comparison might not return 0 when comparing an item with itself.
        /// @remarks If comparer is provided, the elements of the xtd::collections::generic::list <type_t> are sorted using the specified xtd::collections::generic::icomparer <type_t> implementation.
        /// @remarks This method uses xtd::array::sort, which uses the QuickSort algorithm. This implementation performs an unstable sort; that is, if two elements are equal, their order might ! be preserved. In contrast, a stable sort preserves the order of elements that are equal.
        /// @remarks On average, this method is an O(n log n) operation, where n is xtd::collections::generic::list::count; in the worst case it is an O(n ^ 2) operation.
        list<type_t>& sort(xtd::size index, xtd::size count, const xtd::collections::generic::icomparer<type_t>& comparer) {
          if (index + count > self_.count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          data_->items.increment_version();
          std::sort(data_->items.begin() + index, data_->items.begin() + index + count, helpers::lesser<type_t> {comparer});
          return self_;
        }
        
        /// @brief Copies the elements of the xtd::collections::generic::list <type_t> to a new array.
        /// @return An array containing copies of the elements of the xtd::collections::generic::list <type_t>.
        /// @par Examples
        /// The following code example demonstrates the xtd::collections::generic::list <type_t> constructor and various methods of the xtd::collections::generic::list <type_t> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The xtd::collections::generic::list::capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
        /// @include generic_list3.cpp
        /// @remarks The elements are copied using xtd::array::copy, which is an O(n) operation, where n is xtd::collections::generic::list::count.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        xtd::array<value_type> to_array() const noexcept {return count() ? xtd::array<value_type>(data(), count()) : xtd::array<value_type> {};}
        
        /// @brief Returns a xtd::string that represents the current object.
        /// @return A string that represents the current object.
        string to_string() const noexcept override {return xtd::string::format("[{}]", xtd::string::join(", ", self_));}
        
        /// @brief Sets the capacity to the actual number of elements in the xtd::collections::generic::list <type_t>, if that number is less than a threshold value.
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
        /// @remarks This method can be used to minimize a collection's memory overhead if no new elements will be added to the collection. The cost of reallocating and copying a large xtd::collections::generic::list <type_t> can be considerable, however, so the xtd::collections::generic::list::trim_excess method does nothing if the list is at more than 90 percent of capacity. This avoids incurring a large reallocation cost for a relatively small gain.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::generic::list::count.
        /// @remarks To reset a xtd::collections::generic::list <type_t> to its initial state, call the xtd::collections::generic::list::clear method before calling the xtd::collections::generic::list::trim_excess method. Trimming an empty xtd::collections::generic::list <type_t> sets the capacity of the xtd::collections::generic::list <type_t> to the default capacity.
        /// @remarks The capacity can also be set using the xtd::collections::generic::list::capacity property.
        void trim_excess() {data_->items.shrink_to_fit();}
        
        /// @brief Determines whether every element in the xtd::collections::generic::list <type_t> matches the conditions defined by the specified predicate.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to search for.
        /// @return `true` if every element in the xtd::collections::generic::list <type_t> matches the conditions defined by the specified `predicate`; otherwise, `false`. If the list has no elements, the return value is `true`.
        /// @par Examples
        /// The following example demonstrates the xtd::collections::generic::list::exists method and several other methods that use the xtd::predicate <type_t> generic delegate.
        /// <br>A xtd::collections::generic::list <type_t> of strings is created, containing 8 dinosaur names, two of which (at positions 1 and 5) end with "saurus". The example also defines a search predicate method named `ends_with_saurus`, which accepts a string parameter and returns a boolean value indicating whether the input string ends in "saurus".
        /// <br>The xtd::collections::generic::list::find, xtd::collections::generic::list::find_last, and xtd::collections::generic::list::findA_all methods are used to search the list with the search predicate method, and then the xtd::collections::generic::list::remove_all method is used to remove all entries ending with "saurus".
        /// <br>Finally, the xtd::collections::generic::list::exists method is called. It traverses the list from the beginning, passing each element in turn to the `ends_with_saurus` method. The search stops and the method returns `true` if the `ends_with_saurus` method returns `true` for any element. The xtd::collections::generic::list::exists method returns `false` because all such elements have been removed.
        /// @include generic_list_exists.cpp
        /// @remarks The xtd::predicate <type_t> is a delegate to a method that returns true if the object passed to it matches the conditions defined in the delegate. The elements of the current xtd::collections::generic::list <type_t> are individually passed to the xtd::predicate <type_t> delegate, and the elements that match the conditions are removed from the xtd::collections::generic::list <type_t>.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::generic::list::count.
        template<class prediacate_t>
        bool true_for_all(prediacate_t match) const {
          auto predicate = xtd::predicate<const type_t&> {match};
          for (const auto& item : self_)
            if (!predicate(item)) return false;
          return true;
        }
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        list& operator =(const list& other) = default;
        /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container). other is in a valid but unspecified state afterwards.
        /// @param other Another base type container to use as data source.
        /// @return This current instance.
        list& operator =(list&& other) noexcept {
          data_->items = std::move(other.data_->items);
          return self_;
        }
        /// @brief Replaces the contents with those identified by initializer list ilist.
        /// @param items Initializer list to use as data source
        /// @return This current instance.
        list& operator =(const std::initializer_list<type_t>& items) {
          data_->items = items;
          return self_;
        }
        
        /// @brief Returns a reference to the element at specified location index.
        /// @param index The position of the element to return.
        /// @return Reference to the requested element.
        /// @exception std::out_of_range If `index` is not within the range of the container.
        const_reference operator [](size_type index) const override {
          if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
          return data_->items[index];
        }
        /// @brief Returns a reference to the element at specified location index.
        /// @param index The position of the element to return.
        /// @return Reference to the requested element.
        /// @exception std::out_of_range If `index` is not within the range of the container.
        reference operator [](size_type index) override {
          if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
          return data_->items[index];
        }
        
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const_base_type& () const noexcept {return data_->items;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator base_type& () noexcept {return data_->items;}
        /// @}
        
      private:
        bool is_fixed_size() const noexcept override {return false;}
        bool is_read_only() const noexcept override {return false;}
        bool is_synchronized() const noexcept override {return false;}
        const xtd::object& sync_root() const noexcept override {return data_->sync_root;}
        
        struct list_data {
          __xtd_raw_array_data__<value_type, allocator_t> items;
          xtd::object sync_root;
        };
        
        xtd::ptr<list_data> data_ = xtd::new_ptr<list_data>();
      };
      
      /// @cond
      // Deduction guides for xtd::collections::generic::list
      // {
      template<class type_t>
      list(std::initializer_list<type_t>) -> list<type_t>;
      
      template<class type_t>
      list(const ienumerable<type_t>&) -> list<type_t>;
      
      template<class type_t>
      list(const ilist<type_t>&) -> list<type_t>;
      
      template<class type_t>
      list(const std::vector<type_t>&) -> list<type_t>;
      
      template<class type_t, class allocator_t = helpers::allocator<type_t>>
      list(const list<type_t, allocator_t>&) -> list<type_t, allocator_t>;
      
      template<class type_t>
      list(std::vector<type_t>&&) -> list<type_t>;
      
      template<class type_t, class allocator_t = helpers::allocator<type_t>>
      list(list<type_t, allocator_t>&&) -> list<type_t, allocator_t>;
      
      template <class input_iterator_t>
      list(input_iterator_t, input_iterator_t) -> list<typename input_iterator_t::value_type>;
      // }
      /// @endcond
    }
  }
}

/// @cond
namespace xtd::collections::generic::extensions {
  template <class enumerable_t, class source_t>
  inline xtd::collections::generic::list<source_t> enumerable<enumerable_t, source_t>::to_list() const noexcept {
    return xtd::linq::enumerable::to_list(self());
  }
}

namespace xtd::linq {
  template <class source_t>
  inline auto enumerable::to_list(const xtd::collections::generic::ienumerable<source_t>& source) noexcept {
    auto result = xtd::collections::generic::list<source_t> {};
    result = xtd::collections::generic::list<source_t> {source};
    return result;
  }
}
/// @endcond
