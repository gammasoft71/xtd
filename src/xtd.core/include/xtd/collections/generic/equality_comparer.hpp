/// @file
/// @brief Contains xtd::collections::generic::equality_comparer <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "iequality_comparer.hpp"
#include "helpers/equator.hpp"
#include "helpers/hasher.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Provides a base class for implementations of the xtd::collections::generic::iequality_comparer <type_t> generic interface.
      /// @par Definition
      /// ```cpp
      /// template<class type_t>
      /// class equality_comparer : public xtd::collections::generic::iequality_comparer<type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/equality_comparer
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections interfaces
      /// @remarks This interface allows the implementation of customized equality comparison for collections. That is, you can create your own definition of equality for type `type_t`, and specify that this definition be used with a collection type that accepts the xtd::collections::generic::iequality_comparer <type_t> generic interface. In the xtd framework, constructors of the xtd::collections::generic::dictionary <key_t, value_t> generic collection type accept this interface.
      /// @remarks A default implementation of this interface is provided by the xtd::collections::generic::equality_comparer::default_equality_comparer property of the xtd::collections::generic::equality_comparer <type_t> generic class. The xtd::string_comparer class implements xtd::collections::generic::iequality_comparer <type_t> of type xtd::string.
      /// @remarks This interface supports only equality comparisons. Customization of comparisons for sorting and ordering is provided by the xtd::collections::generic::icomparer <type_t> generic interface.
      /// @remarks We recommend that you derive from the xtd::collections::generic::equality_comparer <type_t> class instead of implementing the xtd::collections::generic::iequality_comparer <type_t> interface, because the xtd::collections::generic::equality_comparer <type_t> class tests for equality using the xtd::iequatable::equals method instead of the xtd::object::equals method. This is consistent with the `contains`, `index_of`, `last_index_of`, and `remove` methods of the xtd::collections::generic::dictionary <key_t, value_t> class and other generic collections.
      template<class type_t>
      class equality_comparer : public xtd::collections::generic::iequality_comparer<type_t> {
      public:
        /// @name Public Static Properties
        
        /// @{
        /// @brief Gets the default equality comparer for the type specified by the generic argument.
        /// @return The default instance of the xtd::collections::generic::equality_comparer <type_t> class.
        static equality_comparer default_equality_comparer() {return equality_comparer {};}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Determines whether the specified objects are equal.
        /// @param x The first object of type `type_t` to compare.
        /// @param y The seco,d object of type `type_t` to compare.
        /// @return `true` if the specified objects are equal; otherwise, `false`.
        /// @remarks Implement this method to provide a customized equality comparison for type `type_t`.
        /// @par Notes to Implementers
        /// Implementations are required to ensure that if the xtd::collections::generic::iequality_comparer::equals method returns `true` for two objects `x` and `y`, then the value returned by the xtd::collections::generic::iequality_comparer::get_hash_code method for `x` must equal the value returned for `y`.
        /// The xtd::collections::generic::iequality_comparer::equals method is reflexive, symmetric, and transitive. That is, it returns `true` if used to compare an object with itself; `true` for two objects `x` and `y` if it is `true` for `y` and `x;` and `true` for two objects `x` and `z` if it is `true` for `x` and `y` and also `true` for `y` and `z`.
        bool equals(const type_t& x, const type_t& y) const noexcept override {return xtd::collections::generic::helpers::equator<type_t> {}(x, y);}
        
        /// @brief Returns a hash code for the specified object.
        /// @param obj The xtd::object for which a hash code is to be returned.
        /// @return A hash code for the specified object.
        /// @remarks Implement this method to provide a customized hash code for type `type_t`, corresponding to the customized equality comparison provided by the xtd::collections::generic::iequality_comparer::equals method.
        /// @par Notes to Implementers
        /// Implementations are required to ensure that if the xtd::collections::generic::iequality_comparer::equals method returns `true` for two objects `x` and `y`, then the value returned by the xtd::collections::generic::iequality_comparer::get_hash_code method for `x` must equal the value returned for `y`.
        xtd::size get_hash_code(const type_t& obj) const noexcept override {return xtd::collections::generic::helpers::hasher<type_t> {}(obj);}
        /// @}
      
      private:
        equality_comparer() = default;
      };
    }
  }
}
