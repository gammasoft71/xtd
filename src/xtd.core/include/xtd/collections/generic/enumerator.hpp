/// @file
/// @brief Contains xtd::collections::generic::enumerator <type_t> interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "ienumerator.hpp"
#include "../../ptr.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Supports a simple iteration over a generic collection.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// class enumerator interface_
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/enumerator
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::enumerator <type_t> class is used to encapsulate an xtd::collections::generic::ienumerator <type_t>.
      template<typename type_t>
      class enumerator : public ienumerator<type_t> {
      public:
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::enumerator <type_t> class.
        enumerator() = default;
        /// @brief Initializes a new instance of the xtd::collections::generic::enumerator <type_t> class with specified enumerator.
        /// @param enumerator The xtd::collections::generic::ienumerator <type_t> enumerator to encapsulate.
        enumerator(ptr<ienumerator<type_t>> enumerator) : enumerator_ {enumerator} {} // Can't be explicit by design.
        /// @}
        
        /// @cond
        enumerator(enumerator&& enumerator) = default;
        enumerator(const enumerator& enumerator) = default;
        enumerator& operator =(const enumerator& enumerator) = default;
        /// @endcond
        
        /// @{
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the element in the collection at the current position of the enumerator.
        /// @return The element in the collection at the current position of the enumerator.
        const type_t& current() const override {return enumerator_->current();}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Advances the enumerator to the next element of the collection.
        /// @return true if the enumerator was successfully advanced to the next element; false if the enumerator has passed the end of the collection.
        /// @exception xtd::invalid_operation_exception The collection was modified after the enumerator was created.
        bool move_next() override {return enumerator_->move_next();}
        
        /// @brief Sets the enumerator to its initial position, which is before the first element in the collection.
        /// @exception xtd::invalid_operation_exception The collection was modified after the enumerator was created.
        /// @exception xtd::not_supported_exception The enumerator does not support being reset.
        void reset() override {enumerator_->reset();}
        /// @}
      
      private:
        ptr<ienumerator<type_t>> enumerator_;
      };
    }
  }
}
