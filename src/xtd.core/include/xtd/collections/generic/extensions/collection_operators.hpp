/// @file
/// @brief Contains xtd::extensions::collection_operators class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::extensions namespace contains interface extensions.
      namespace extensions {
        /// @brief Internal collection operators definition.
        /// @par Definition
        /// ```cpp
        /// template<class type_t, class collection_t>
        /// class collection_operator;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/extensions/collection_operators
        /// ```
        /// @par Namespace
        /// xtd
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core extensions
        /// @warning Internal use only for xtd::iequatable interfece.
        template<class type_t, class collection_t>
        class collection_operators {
        public:
          /// @name Public Operators
          
          /// @{
          /// @brief The shift left operator adds an item to the xtd::collections::generic::icollection <type_t>.
          /// @param item The object to add to the xtd::collections::generic::icollection <type_t>.
          /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
          virtual collection_t& operator <<(const type_t& item) {
            auto& self = static_cast<collection_t&>(*this);
            self.add(item);
            return self;
          }

          /// @brief The shift right operator removes tthe first occurrence of a specific object from the xtd::collections::generic::icollection <type_t>.
          /// @param item The object to remove from the xtd::collections::generic::icollection <type_t>.
          /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
          /// @remarks Implementations can vary in how they determine equality of objects; for example, xtd::collections::generic::list <type_t> uses xtd::collections::generic::compoarer <type_t>::default_comparer, whereas, xtd::collections::generic::dictionary <key_t, value_t> allows the user to specify the xtd::collections::generic::icompoarer <type_t> implementation to use for comparing keys.
          /// @remarks In collections of contiguous elements, such as lists, the elements that follow the removed element move up to occupy the vacated spot. If the collection is indexed, the indexes of the elements that are moved are also updated. This behavior does not apply to collections where elements are conceptually grouped into buckets, such as a hash table.
          virtual collection_t& operator >>(const type_t& item) {
            auto& self = static_cast<collection_t&>(*this);
            self.remove(item);
            return self;
          }
          /// @}
        
        private:
          friend collection_t;
          collection_operators() = default;
        };
      }
    }
  }
}
