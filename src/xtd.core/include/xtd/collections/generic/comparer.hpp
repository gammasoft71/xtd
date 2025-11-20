/// @file
/// @brief Contains xtd::collections::generic::comparer <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/comparer.hpp"
#include "icomparer.hpp"
//#include "../../comparison.hpp"
#include "../../object.hpp"
#include "../../ptr.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Provides a base class for implementations of the xtd::collections::generic::icomparer <type_t> generic interface.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// class comparer : public xtd::object, public xtd::collections::generic::icomparer<type_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/comparer>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      template<class type_t>
      class comparer : public object, public icomparer<type_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the first argument type.
        using first_argument_type = type_t;
        /// @brief Represents the second argument type.
        using second_argument_type = type_t;
        /// @brief Represents the result type.
        using result_type = int32;
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Returns a default sort order comparer for the type specified by the generic argument
        static const comparer<type_t> default_comparer;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Compares two entities and returns a value indicating whether one is less than, equal to, or greater than the other.
        /// @param x The first entity to compare.
        /// @param y The second entity to compare.
        /// @return A 32-bit signed integer that indicates the relative order of the entities being compared. The return value has these meanings:
        ///
        /// | Value             | Condition            |
        /// |-------------------|----------------------|
        /// | Less than zero    | x is less than y.    |
        /// | Zero              | x equals y.          |
        /// | Greater than zero | x is greater than y. |
        auto compare(const first_argument_type& x, const second_argument_type& y) const noexcept -> result_type override {return helpers::comparer<type_t> {}(x, y);}
        
        //static ptr<comparer<type_t>> create (xtd::comparison<type_t> comparison) {
        //  return {};
        //}
        /// @}
        
      protected:
        /// @name Protected Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::comparer <type_t> class.
        comparer() = default;
        /// @}
      };
      
      /// @cond
      template<class type_t>
      inline const comparer<type_t> comparer<type_t>::default_comparer;
      /// @endcond
    }
  }
}
