/// @file
/// @brief Contains xtd::collections::generic::enumerator <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "ienumerator.hpp"
#define __XTD_CORE_INTERNAL__
#include "../../internal/__external_exceptions.hpp"
#undef __XTD_CORE_INTERNAL__
#include "../../ptr.hpp"
#include "../../static.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @cond
      template <typename type_t = std::nullptr_t>
      struct enumerator;
      /// @endcond
      
      /// @brief Supports a simple iteration over a generic collection.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t>
      /// struct enumerator : ienumerator<type_t>;
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
      struct enumerator : ienumerator<type_t> {
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
        enumerator& operator =(enumerator&& enumerator) = default;
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
      template <>
      struct enumerator<> static_ {
        /// @name Public Static Methods
        
        /// @{
        /// @brief Create an enumerator from specified collection and version.
        /// @tparam collection_t The collection type.
        /// @tparam vertion_t The collection version type.
        /// @param items The collection to create an enumerator on.
        /// @param current_version A pointer on the collection current version.
        /// @return The enumerator created.
        /// @par Examples
        /// The following code shows how to use enumerator<>::create method to create a simple enumerator on any std or xtd collections.
        /// @include generic_ienumerable3.cpp
        template <typename collection_t, typename vertion_t = std::nullptr_t>
        static auto create(const collection_t& items, const vertion_t* current_version = nullptr) noexcept {
          using value_type = typename collection_t::value_type;
          using const_iterator = typename collection_t::const_iterator;
          struct internal_enumerator : public ienumerator<value_type> {
          public:
            explicit internal_enumerator(const collection_t& items, const vertion_t* current_version) : items_(items), version_(current_version ? *current_version : 0), current_version_(current_version) {}
            
            const value_type& current() const override {
              if (current_version_ && version_ != *current_version_) __throw_invalid_operation_exception("Collection was modified; enumeration operation may not execute.", __FILE__, __LINE__, __func__);
              if (iterator_ != items_.cend()) return *iterator_;
              static auto default_value_type = value_type {};
              return default_value_type;
            }
            
            bool move_next() override {
              if (current_version_ && version_ != *current_version_) __throw_invalid_operation_exception("Collection was modified; enumeration operation may not execute.", __FILE__, __LINE__, __func__);
              if (!reset_) return ++iterator_ != items_.cend();
              reset_ = false;
              iterator_ = items_.cbegin();
              return iterator_ != items_.cend();
            }
            
            void reset() override {
              reset_ = true;
              version_ = current_version_ ? *current_version_ : vertion_t {};
              iterator_ = items_.cend();
            }
            
          protected:
            bool reset_ = true;
            const collection_t& items_;
            const_iterator iterator_ = items_.cend();
            vertion_t version_ = vertion_t {};
            const vertion_t* current_version_ = nullptr;
          };
          return enumerator<value_type> {new_ptr<internal_enumerator>(items, current_version)};
        }
        /// @}
      };
    }
  }
}
