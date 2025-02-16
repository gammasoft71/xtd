/// @file
/// @brief Contains xtd::collections::object_model::read_only_collection class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../generic/ilist.hpp"
#include "../../helpers/throw_helper.hpp"
#include "../../size.hpp"
#include <limits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Contains classes that can be used as collections in the object model of a reusable library. Use these classes when properties or methods return collections.
    namespace object_model {
      /// @brief Provides the base class for a generic read-only collection.
      /// ```cpp
      /// template<class type_t>
      /// class read_only_collection : public xtd::object, public xtd::collections::generic::ilist<type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/object_model/read_only_collection>
      /// ```
      /// @par Namespace
      /// xtd::collections::object_model
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core object_model_collections
      /// @par Examples
      /// The following code example demonstrates several members of the xtd::collections::object_model::read_only_collection <type_t> class. The code example creates a xtd::collections::generic::list <type_t> of strings and adds four dinosaur names to it. The code example then wraps the list in a xtd::collections::object_model::read_only_collection <type_t>.
      ///
      /// After demonstrating the xtd::collections::object_model::read_only_collection::count, xtd::collections::object_model::read_only_collection::contains, xtd::collections::object_model::read_only_collection:: opertor [], and xtd::collections::generic::ilist::index_of members, the code example shows that the xtd::collections::object_model::read_only_collection <type_t> is just a wrapper for the original xtd::collections::generic::list <type_t> by adding a new item to the xtd::collections::generic::list <type_t> and displaying the contents of the xtd::collections::object_model::read_only_collection <type_t>.
      ///
      /// Finally, the code example creates an array larger than the collection and uses the xtd::collections::object_model::read_only_collection::copy_to method to insert the elements of the collection into the middle of the array.
      /// @include read_only_collection.cpp
      template<class type_t>
      class read_only_collection : public xtd::object, public xtd::collections::generic::ilist<type_t> {
        template<class list_type_t>
        class empty_list : public generic::ilist<list_type_t> {
        public:
          using iterator = typename generic::ilist<list_type_t>::iterator;
          using const_iterator = typename generic::ilist<list_type_t>::const_iterator;
          
          inline static constexpr xtd::size npos = std::numeric_limits<xtd::size>::max();
          
          bool contains(const list_type_t& item) const noexcept override {return false;}
          void copy_to(xtd::array<list_type_t>& array, xtd::size array_index) const override {}
          generic::enumerator<list_type_t> get_enumerator() const noexcept {
            class empty_enumerator : public generic::ienumerator<list_type_t> {
            public:
              const list_type_t& current() const override {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);}
              bool move_next() override {return false;}
              void reset() override {}
            private:
            };
            return {new_ptr<empty_enumerator>()};
          }
          xtd::size index_of(const list_type_t& item) const noexcept override {return npos;}
          
          const list_type_t& operator [](xtd::size index) const override {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);}
          list_type_t& operator [](xtd::size index) override {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);}

        private:
          bool is_fixed_size() const noexcept override {return false;}
          bool is_synchronized() const noexcept override {return false;}
          void add(const list_type_t& item) override {}
          void clear() override  {}
          void insert(xtd::size index, const list_type_t& item) override {}
          bool remove(const list_type_t& item) override {return false;}
          void remove_at(xtd::size index) override {}
        };
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the list value type.
        using value_type = type_t;
        /// @brief Represents the list base type.
        using base_type = ptr<xtd::collections::generic::ilist<value_type>>;
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
        using iterator = typename generic::icollection<type_t>::iterator;
        /// @brief Represents the const iterator of list value type.
        using const_iterator = typename generic::icollection<type_t>::const_iterator;
        /// @}
        
        /// @name Public Fields
        
        /// @{
        /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
        inline static constexpr xtd::size npos = std::numeric_limits<xtd::size>::max();
        /// @}

        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::object_model::read_only_collection <type_t> class that is a read-only wrapper around the specified list.
        /// @par Examples
        /// The following code example demonstrates several members of the xtd::collections::object_model::read_only_collection <type_t> class. The code example creates a xtd::collections::generic::list <type_t> of strings and adds four dinosaur names to it. The code example then wraps the list in a xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// After demonstrating the xtd::collections::object_model::read_only_collection::count, xtd::collections::object_model::read_only_collection::contains, xtd::collections::object_model::read_only_collection:: opertor [], and xtd::collections::generic::ilist::index_of members, the code example shows that the xtd::collections::object_model::read_only_collection <type_t> is just a wrapper for the original xtd::collections::generic::list <type_t> by adding a new item to the xtd::collections::generic::list <type_t> and displaying the contents of the xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// Finally, the code example creates an array larger than the collection and uses the xtd::collections::object_model::read_only_collection::copy_to method to insert the elements of the collection into the middle of the array.
        /// @include read_only_collection.cpp
        /// @remarks To prevent any modifications to `list`, expose `list` only through this wrapper.
        /// @remarks A collection that is read-only is simply a collection with a wrapper that prevents modifying the collection; therefore, if changes are made to the underlying collection, the read-only collection reflects those changes.
        /// @remarks This constructor is an O(1) operation.
        explicit read_only_collection(ptr<generic::ilist<value_type>> list) : items_(list) {}
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the number of elements contained in the xtd::collections::object_model::read_only_collection <type_t> instance.
        /// @return The number of elements contained in the xtd::collections::object_model::read_only_collection <type_t> instance.
        /// @par Examples
        /// The following code example demonstrates several members of the xtd::collections::object_model::read_only_collection <type_t> class. The code example creates a xtd::collections::generic::list <type_t> of strings and adds four dinosaur names to it. The code example then wraps the list in a xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// After demonstrating the xtd::collections::object_model::read_only_collection::count, xtd::collections::object_model::read_only_collection::contains, xtd::collections::object_model::read_only_collection:: opertor [], and xtd::collections::generic::ilist::index_of members, the code example shows that the xtd::collections::object_model::read_only_collection <type_t> is just a wrapper for the original xtd::collections::generic::list <type_t> by adding a new item to the xtd::collections::generic::list <type_t> and displaying the contents of the xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// Finally, the code example creates an array larger than the collection and uses the xtd::collections::object_model::read_only_collection::copy_to method to insert the elements of the collection into the middle of the array.
        /// @include read_only_collection.cpp
        /// @remarks Retrieving the value of this property is an O(1) operation.
        xtd::size count() const noexcept override {return items_->count();}
        
        /// @brief Gets an empty xtd::collections::object_model::read_only_collection <type_t>.
        /// @return An empty xtd::collections::object_model::read_only_collection <type_t>.
        /// @remarks The returned instance is immutable and will always be empty.
        static const read_only_collection<value_type>& empty() {
          auto result = read_only_collection<value_type> {new_ptr<empty_list<value_type>>()};
          return result;
        }
        
        const xtd::object& sync_root() const noexcept override {return items_->sync_root();}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether an element is in the xtd::collections::object_model::read_only_collection <type_t>.
        /// @param item The object to locate in the xtd::collections::object_model::read_only_collection <type_t>. The value can be null for reference types.
        /// @return `true` if value is found in the xtd::collections::object_model::read_only_collection <type_t>; otherwise, `false`.
        /// @par Examples
        /// The following code example demonstrates several members of the xtd::collections::object_model::read_only_collection <type_t> class. The code example creates a xtd::collections::generic::list <type_t> of strings and adds four dinosaur names to it. The code example then wraps the list in a xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// After demonstrating the xtd::collections::object_model::read_only_collection::count, xtd::collections::object_model::read_only_collection::contains, xtd::collections::object_model::read_only_collection:: opertor [], and xtd::collections::generic::ilist::index_of members, the code example shows that the xtd::collections::object_model::read_only_collection <type_t> is just a wrapper for the original xtd::collections::generic::list <type_t> by adding a new item to the xtd::collections::generic::list <type_t> and displaying the contents of the xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// Finally, the code example creates an array larger than the collection and uses the xtd::collections::object_model::read_only_collection::copy_to method to insert the elements of the collection into the middle of the array.
        /// @include read_only_collection.cpp
        /// @remarks This method determines equality using the default equality comparer xtd::collections::generic::equality_comparer::default_comparer.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::object_model::read_only_collection::count.
        bool contains(const type_t& item) const noexcept override {return items_->contains(item);}
        
        /// @brief Copies the entire xtd::collections::object_model::read_only_collection <type_t> to a compatible one-dimensional Array, starting at the specified index of the target array.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::object_model::read_only_collection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in array at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::object_model::read_only_collection <type_t> is greater than the available space from index to the end of the destination array.
        /// @par Examples
        /// The following code example demonstrates several members of the xtd::collections::object_model::read_only_collection <type_t> class. The code example creates a xtd::collections::generic::list <type_t> of strings and adds four dinosaur names to it. The code example then wraps the list in a xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// After demonstrating the xtd::collections::object_model::read_only_collection::count, xtd::collections::object_model::read_only_collection::contains, xtd::collections::object_model::read_only_collection:: opertor [], and xtd::collections::generic::ilist::index_of members, the code example shows that the xtd::collections::object_model::read_only_collection <type_t> is just a wrapper for the original xtd::collections::generic::list <type_t> by adding a new item to the xtd::collections::generic::list <type_t> and displaying the contents of the xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// Finally, the code example creates an array larger than the collection and uses the xtd::collections::object_model::read_only_collection::copy_to method to insert the elements of the collection into the middle of the array.
        /// @include read_only_collection.cpp
        /// @remarks This method uses xtd::array::copy to copy the elements.
        /// @remarks The elements are copied to the xtd::array in the same order that the enumerator iterates through the xtd::collections::object_model::read_only_collection <type_t>.
        /// @remarks This method is an O(n) operation, where n is xtd::collections::object_model::read_only_collection::count.
        void copy_to(xtd::array<type_t>& array, xtd::size array_index) const override {return items_->copy_to(array, array_index);}
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::object_model::read_only_collection <type_t>.
        /// @return An xtd::collections::generic::enumerator<T> for the xtd::collections::object_model::read_only_collection <type_t>.
        /// @par Examples
        /// The following code example demonstrates several members of the xtd::collections::object_model::read_only_collection <type_t> class. The code example creates a xtd::collections::generic::list <type_t> of strings and adds four dinosaur names to it. The code example then wraps the list in a xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// After demonstrating the xtd::collections::object_model::read_only_collection::count, xtd::collections::object_model::read_only_collection::contains, xtd::collections::object_model::read_only_collection:: opertor [], and xtd::collections::generic::ilist::index_of members, the code example shows that the xtd::collections::object_model::read_only_collection <type_t> is just a wrapper for the original xtd::collections::generic::list <type_t> by adding a new item to the xtd::collections::generic::list <type_t> and displaying the contents of the xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// Finally, the code example creates an array larger than the collection and uses the xtd::collections::object_model::read_only_collection::copy_to method to insert the elements of the collection into the middle of the array.
        /// @include read_only_collection.cpp
        /// @remarks The for each statement of the C++ language hides the complexity of the enumerators. Therefore, using `for each` is recommended, instead of directly manipulating the enumerator.
        /// @remarks Enumerators can be used to read the data in the collection, but they cannot be used to modify the underlying collection.
        /// @remarks Initially, the enumerator is positioned before the first element in the collection. At this position, xtd::collections::generic::enumerator::current is undefined. Therefore, you must call xtd::collections::generic::enumerator::move_next to advance the enumerator to the first element of the collection before reading the value of xtd::collections::generic::enumerator::current.
        /// @remarks xtd::collections::generic::enumerator::current returns the same object until xtd::collections::generic::enumerator::move_next is called. xtd::collections::generic::enumerator::move_next sets xtd::collections::generic::enumerator::current to the next element.
        /// @remarks If xtd::collections::generic::enumerator::move_next passes the end of the collection, the enumerator is positioned after the last element in the collection and xtd::collections::generic::enumerator::move_next returns `false`. When the enumerator is at this position, subsequent calls to MoveNext also return `false`. If the last call to MoveNext returned `false`, Current is undefined. You cannot set xtd::collections::generic::enumerator::current to the first element of the collection again; you must create a new enumerator instance instead.
        /// @remarks An enumerator remains valid as long as the collection remains unchanged. If changes are made to the collection, such as adding, modifying, or deleting elements, the enumerator is irrecoverably invalidated and its behavior is undefined.
        /// @remarks The enumerator does not have exclusive access to the collection; therefore, enumerating through a collection is intrinsically not a thread-safe procedure. To guarantee thread safety during enumeration, you can lock the collection during the entire enumeration. To allow the collection to be accessed by multiple threads for reading and writing, you must implement your own synchronization.
        /// @remarks Default implementations of collections in xtd::collections::generic are not synchronized.
        /// @remarks This method is an O(1) operation
        generic::enumerator<type_t> get_enumerator() const noexcept override {return items_->get_enumerator();}
        
        /// @brief Searches for the specified object and returns the zero-based index of the first occurrence within the entire xtd::collections::object_model::read_only_collection <type_t>.
        /// @param item The object to locate in the xtd::collections::object_model::read_only_collection <type_t>.
        /// @return The zero-based index of the first occurrence of item within the entire xtd::collections::object_model::read_only_collection <type_t>, if found; otherwise, xtd::collections::object_model::read_only_collection::npos.
        /// @par Examples
        /// The following code example demonstrates several members of the xtd::collections::object_model::read_only_collection <type_t> class. The code example creates a xtd::collections::generic::list <type_t> of strings and adds four dinosaur names to it. The code example then wraps the list in a xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// After demonstrating the xtd::collections::object_model::read_only_collection::count, xtd::collections::object_model::read_only_collection::contains, xtd::collections::object_model::read_only_collection:: opertor [], and xtd::collections::generic::ilist::index_of members, the code example shows that the xtd::collections::object_model::read_only_collection <type_t> is just a wrapper for the original xtd::collections::generic::list <type_t> by adding a new item to the xtd::collections::generic::list <type_t> and displaying the contents of the xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// Finally, the code example creates an array larger than the collection and uses the xtd::collections::object_model::read_only_collection::copy_to method to insert the elements of the collection into the middle of the array.
        /// @include read_only_collection.cpp
        /// @remarks The xtd::collections::object_model::read_only_collection <type_t> is searched forward starting at the first element and ending at the last element.
        /// @remarks This method determines equality using the default comparer xtd::collections::generic::equality_comparer::default_comparer.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::collections::object_model::read_only_collection::count.
        xtd::size index_of(const type_t& item) const noexcept override {return items_->index_of(item);}
        /// @}

        /// @name Public Operators
        
        /// @{
        /// @brief Returns a reference to the element at specified location pos.
        /// @param index The position of the element to return.
        /// @return Reference to the requested element.
        /// @par Examples
        /// The following code example demonstrates several members of the xtd::collections::object_model::read_only_collection <type_t> class. The code example creates a xtd::collections::generic::list <type_t> of strings and adds four dinosaur names to it. The code example then wraps the list in a xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// After demonstrating the xtd::collections::object_model::read_only_collection::count, xtd::collections::object_model::read_only_collection::contains, xtd::collections::object_model::read_only_collection:: opertor [], and xtd::collections::generic::ilist::index_of members, the code example shows that the xtd::collections::object_model::read_only_collection <type_t> is just a wrapper for the original xtd::collections::generic::list <type_t> by adding a new item to the xtd::collections::generic::list <type_t> and displaying the contents of the xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// Finally, the code example creates an array larger than the collection and uses the xtd::collections::object_model::read_only_collection::copy_to method to insert the elements of the collection into the middle of the array.
        /// @include read_only_collection.cpp
        /// @remarks Retrieving the value of this property is an O(1) operation.
        /// @remarks This property provides the ability to access a specific element in the collection by using the following C++ syntax: `my_collection[index]`.
        /// @remarks Retrieving the value of this property is an O(1) operation.
        const_reference operator [](size_type index) const override {return (*items_)[index];}
        /// @}

      protected:
        /// @name Protected Properties
        
        /// @{
        /// @brief Returns the xtd::collections::generic::ilist <type_t> that the xtd::collections::object_model::read_only_collection <type_t> wraps.
        /// @return The xtd::collections::generic::ilist <type_t> that the xtd::collections::object_model::read_only_collection <type_t> wraps.
        /// @par Examples
        /// The following code example demonstrates several members of the xtd::collections::object_model::read_only_collection <type_t> class. The code example creates a xtd::collections::generic::list <type_t> of strings and adds four dinosaur names to it. The code example then wraps the list in a xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// After demonstrating the xtd::collections::object_model::read_only_collection::count, xtd::collections::object_model::read_only_collection::contains, xtd::collections::object_model::read_only_collection:: opertor [], and xtd::collections::generic::ilist::index_of members, the code example shows that the xtd::collections::object_model::read_only_collection <type_t> is just a wrapper for the original xtd::collections::generic::list <type_t> by adding a new item to the xtd::collections::generic::list <type_t> and displaying the contents of the xtd::collections::object_model::read_only_collection <type_t>.
        ///
        /// Finally, the code example creates an array larger than the collection and uses the xtd::collections::object_model::read_only_collection::copy_to method to insert the elements of the collection into the middle of the array.
        /// @include read_only_collection.cpp
        /// @remarks Retrieving the value of this property is an O(1) operation.
        base_type items() noexcept {return items_;}
        /// @}

      private:
        reference operator [](size_type index) override {xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);}
        bool is_fixed_size() const noexcept override {return false;}
        bool is_read_only() const noexcept override {return false;}
        bool is_synchronized() const noexcept override {return false;}
        void add(const value_type& item) override {}
        void clear() override {}
        void insert(xtd::size index, const value_type& item) override {}
        bool remove(const value_type& item) override {return false;}
        void remove_at(xtd::size index) override {}
        base_type items_;
      };
    }
  }
}
