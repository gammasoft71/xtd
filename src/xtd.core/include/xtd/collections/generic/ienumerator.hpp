/// @file
/// @brief Contains xtd::collections::generic::ienumerator <type_t> interface.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../../interface.hpp"
#include <iterator>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Supports a simple iteration over a generic collection.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// class ienumerator interface_
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/ienumerator>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections interfaces
      /// @par Examples
      /// The following example shows an implementation of the xtd::collections::generic::ienumerator <type_t> interface for a collection class of custom objects. The custom object is an instance of the type Box, and the collection class is BoxCollection. This code example is part of a larger example provided for the ICollection<T> interface.
      /// @code
      /// // Defines the enumerator for the boxes collection.
      /// // (Some prefer this class nested in the collection class.)
      /// class box_enumerator : public ienumerator<box> {
      /// public:
      ///   explicit box_enumerator(const box_collection& boxes) : boxes {boxes} {}
      ///
      ///   const box& current() const override {return boxes[cur_index];}
      ///   bool move_next() override {return ++cur_index < boxes.count() ? true : false;}
      ///   void reset() override {cur_index = box_integer<size>::max_value;}
      ///
      /// private:
      ///   const box_collection& boxes;
      ///   size cur_index = box_integer<size>::max_value;
      /// };
      /// @endcode
      /// @remarks xtd::collections::generic::ienumerator <type_t> is the base interface for all generic enumerators.
      /// @remarks The for each statement of the C++ language hides the complexity of the enumerators. Therefore, using `for` is recommended, instead of directly manipulating the enumerator.
      /// @remarks Enumerators can be used to read the data in the collection, but they cannot be used to modify the underlying collection.
      /// @remarks Initially, the enumerator is positioned before the first element in the collection. At this position, xtd::collections::generic::ienumerator::current is undefined. Therefore, you must call xtd::collections::generic::ienumerator::move_next to advance the enumerator to the first element of the collection before reading the value of xtd::collections::generic::ienumerator::current.
      /// @remarks xtd::collections::generic::ienumerator::current returns the same object until xtd::collections::generic::ienumerator::move_next is called. xtd::collections::generic::ienumerator::move_next sets xtd::collections::generic::ienumerator::current to the next element.
      /// @remarks If xtd::collections::generic::ienumerator::move_next passes the end of the collection, the enumerator is positioned after the last element in the collection and xtd::collections::generic::ienumerator::move_next returns `false`. When the enumerator is at this position, subsequent calls to xtd::collections::generic::ienumerator::move_next also return `false`. If the last call to xtd::collections::generic::ienumerator::move_next returned `false`, xtd::collections::generic::ienumerator::current is undefined. You cannot set xtd::collections::generic::ienumerator::current to the first element of the collection again; you must create a new enumerator instance instead.
      /// @remarks The xtd::collections::generic::ienumerator::reset method is provided for COM interoperability. It does not necessarily need to be implemented; instead, the implementer can simply throw a xtd::not_supported_exception. However, if you choose to do this, you should make sure no callers are relying on the xtd::collections::generic::ienumerator::reset functionality.
      /// @remarks If changes are made to the collection, such as adding, modifying, or deleting elements, the behavior of the enumerator is undefined.
      /// @remarks The enumerator does not have exclusive access to the collection; therefore, enumerating through a collection is intrinsically not a thread-safe procedure. To guarantee thread safety during enumeration, you can lock the collection during the entire enumeration. To allow the collection to be accessed by multiple threads for reading and writing, you must implement your own synchronization.
      /// @remarks Default implementations of collections in the xtd::collections::generic namespace are not synchronized.
      template<class type_t>
      class ienumerator interface_ {
      public:
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the element in the collection at the current position of the enumerator.
        /// @return The element in the collection at the current position of the enumerator.
        /// @par Examples
        /// The following code example demonstrates the implementation of the IEnumerator interfaces for a custom collection. In this example, xtd::collections::generic::ienumerator::move_next is not explicitly called, but it is implemented to support the use of foreach (for each in Visual Basic). This code example is part of a larger example for the IEnumerator interface.
        /// @code
        /// // When you implement ienumerable, you must also implement ienumerator.
        /// class people_enum : public ienumerator<person> {
        /// private:
        ///   // Enumerators are positioned before the first element
        ///   // until the first move_next() call.
        ///   size position_ = box_integer<size>::max_value;
        ///
        /// public:
        ///   const list<person>& people;
        ///
        ///   explicit people_enum(const list<person>& people) : people {people} {}
        ///
        ///   bool move_next() override {
        ///     ++position_;
        ///     return position < people.count();
        ///   }
        ///
        ///   void reset() override {position_ = box_integer<size>::max_value;}
        ///
        ///   const person& current() const override {
        ///     try {
        ///       return people[position_];
        ///     } catch (const index_out_of_range_exception& e) {
        ///       throw invalid_operation_exception {};
        ///     }
        ///   }
        /// };
        /// @endcode
        /// @remarks xtd::collections::generic::ienumerator::current is undefined under any of the following conditions:
        /// * The enumerator is positioned before the first element in the collection, immediately after the enumerator is created. xtd::collections::generic::ienumerator::move_next must be called to advance the enumerator to the first element of the collection before reading the value of xtd::collections::generic::ienumerator::current.
        /// * The last call to xtd::collections::generic::ienumerator::move_next returned `false`, which indicates the end of the collection.
        /// * The enumerator is invalidated due to changes made in the collection, such as adding, modifying, or deleting elements.
        /// @remarks xtd::collections::generic::ienumerator::current returns the same object until xtd::collections::generic::ienumerator::move_next is called. xtd::collections::generic::ienumerator::move_next sets xtd::collections::generic::ienumerator::current to the next element.
        /// @par Notes to Implementers
        /// Implementing this interface requires implementing the nongeneric IEnumerator interface. The xtd::collections::generic::ienumerator::current property appears on both interfaces, and has different return types. Implement the nongeneric xtd::collections::generic::ienumerator::current property as an explicit interface implementation. This allows any consumer of the nongeneric interface to consume the generic interface.
        virtual auto current() const -> const type_t& = 0;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Advances the enumerator to the next element of the collection.
        /// @return `true` if the enumerator was successfully advanced to the next element; `false` if the enumerator has passed the end of the collection.
        /// @exception xtd::invalid_operation_exception The collection was modified after the enumerator was created.
        /// @par Examples
        /// The following code example demonstrates the implementation of the IEnumerator interfaces for a custom collection. In this example, xtd::collections::generic::ienumerator::move_next is not explicitly called, but it is implemented to support the use of foreach (for each in Visual Basic). This code example is part of a larger example for the IEnumerator interface.
        /// @code
        /// // When you implement IEnumerable, you must also implement IEnumerator.
        /// class people_enum : public ienumerator<person> {
        /// private:
        ///   // Enumerators are positioned before the first element
        ///   // until the first move_next() call.
        ///   size position_ = box_integer<size>::max_value;
        ///
        /// public:
        ///   const list<person>& people;
        ///
        ///   explicit people_enum(const list<person>& people) : people {people} {}
        ///
        ///   bool move_next() override {
        ///     ++position_;
        ///     return position < people.count();
        ///   }
        ///
        ///   void reset() override {position_ = box_integer<size>::max_value;}
        ///
        ///   const person& current() const override {
        ///     try {
        ///       return people[position_];
        ///     } catch (const index_out_of_range_exception& e) {
        ///       throw invalid_operation_exception {};
        ///     }
        ///   }
        /// };
        /// @endcode
        /// @remarks After an enumerator is created or after the xtd::collections::generic::ienumerator::reset method is called, an enumerator is positioned before the first element of the collection, and the first call to the xtd::collections::generic::ienumerator::move_next method moves the enumerator over the first element of the collection.
        /// @remarks If xtd::collections::generic::ienumerator::move_next passes the end of the collection, the enumerator is positioned after the last element in the collection and xtd::collections::generic::ienumerator::move_next returns `false`. When the enumerator is at this position, subsequent calls to xtd::collections::generic::ienumerator::move_next also return `false` until xtd::collections::generic::ienumerator::reset is called.
        /// @remarks If changes are made to the collection, such as adding, modifying, or deleting elements, the behavior of xtd::collections::generic::ienumerator::move_next is undefined.
        virtual auto move_next() -> bool = 0;
        
        /// @brief Sets the enumerator to its initial position, which is before the first element in the collection.
        /// @exception xtd::invalid_operation_exception The collection was modified after the enumerator was created.
        /// @exception xtd::not_supported_exception The enumerator does not support being reset.
        /// @par Examples
        /// The following code example demonstrates the implementation of the IEnumerator interfaces for a custom collection. In this example, xtd::collections::generic::ienumerator::move_next is not explicitly called, but it is implemented to support the use of foreach (for each in Visual Basic). This code example is part of a larger example for the IEnumerator interface.
        /// @code
        /// // When you implement IEnumerable, you must also implement IEnumerator.
        /// class people_enum : public ienumerator<person> {
        /// private:
        ///   // Enumerators are positioned before the first element
        ///   // until the first move_next() call.
        ///   size position_ = box_integer<size>::max_value;
        ///
        /// public:
        ///   const list<person>& people;
        ///
        ///   explicit people_enum(const list<person>& people) : people {people} {}
        ///
        ///   bool move_next() override {
        ///     ++position_;
        ///     return position < people.count();
        ///   }
        ///
        ///   void reset() override {position_ = box_integer<size>::max_value;}
        ///
        ///   const person& current() const override {
        ///     try {
        ///       return people[position_];
        ///     } catch (const index_out_of_range_exception& e) {
        ///       throw invalid_operation_exception {};
        ///     }
        ///   }
        /// };
        /// @endcode
        /// @remarks If changes are made to the collection, such as adding, modifying, or deleting elements, the behavior of xtd::collections::generic::ienumerator::reset is undefined.
        /// @remarks The xtd::collections::generic::ienumerator::reset method is provided for COM interoperability. It does not necessarily need to be implemented; instead, the implementer can simply throw a xtd::not_supported_exception.
        /// @par Notes to Implementers
        /// All calls to xtd::collections::generic::ienumerator::reset() must result in the same state for the enumerator. The preferred implementation is to move the enumerator to the beginning of the collection, before the first element. This invalidates the enumerator if the collection has been modified since the enumerator was created, which is consistent with xtd::collections::generic::ienumerator::move_next() and xtd::collections::generic::ienumerator::current.
        virtual auto reset() -> void = 0;
        /// @}
      };
    }
  }
}
