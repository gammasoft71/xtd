/// @file
/// @brief Contains xtd::collections::generic::enumerable_iterators <type_t, enumerator_t> class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enumerator.h"
#include "../../size.h"
#include <limits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Internal enumarable iterators definition.
      /// @par Definition
      /// ```cpp
      /// template<typename type_t, typename enumerator_t>
      /// class enumerable_iterators
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/enumerable_iterators
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core
      /// @warning Internal use only for xtd::collections::generic::ienumerable interfece.
      template<typename type_t, typename enumerator_t>
      class enumerable_iterators {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the iterator of enumarable value type.
        class iterator {
        public:
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the iterator category type.
          using iterator_category = std::forward_iterator_tag;
          /// @brief Represents the value type.
          using value_type = type_t;
          /// @brief Represents the pointer of the value type.
          using pointer_type = value_type*;
          /// @brief Represents the reference of the value type.
          using reference_type = value_type&;
          /// @}

          /// @name Public Constructors
          
          /// @{
          /// @brief Initializes a new instance of the xtd::collections::generic::iterator class with specified enumerator.
          /// @param enumerator The enumerator to iterate with.
          iterator(enumerator<type_t> enumerator) : iterator(enumerator, false) {}
          /// @brief Initializes a new instance of the xtd::collections::generic::iterator class with specified enumerator and end.
          /// @param enumerator The enumerator to iterate with.
          /// @parem end true to specify the end iterotator; otherwise false.
          iterator(enumerator<type_t> enumerator, bool end) : enumerator_(enumerator) {
            enumerator_.reset();
            pos_ = enumerator_.move_next() == false || end == true ? std::numeric_limits<xtd::size>::max() : 0;
          }
          /// @}

          /// @name Public Operators
          
          /// @{
          /// @brief Returns reference to the current element, or a proxy holding it.
          /// @return The reference to the current element.
          reference_type operator *() const {return const_cast<reference_type>(enumerator_.current());}
          /// @brief Returns pointer to the current element, or a proxy holding it.
          /// @return The pointer to the current element.
          pointer_type operator ->() {return &operator*();}
          
          /// @brief Pre increments the underlying iterator.
          /// @return The underlying iterator.
          iterator& operator ++() {
            if (pos_ != std::numeric_limits<xtd::size>::max()) pos_ = enumerator_.move_next() ? pos_ + 1 : std::numeric_limits<xtd::size>::max();
            return *this;
          }
          /// @brief Post increments the underlying iterator.
          /// @return The underlying iterator.
          iterator operator ++(int) {
            auto current = *this;
            ++(*this);
            return current;
          }
          
          template<typename value_t>
          iterator& operator +(value_t value) {
            for (auto index = xtd::size {}; index < value && pos_ != std::numeric_limits<xtd::size>::max(); ++index)
              if (pos_ != std::numeric_limits<xtd::size>::max()) pos_ = enumerator_.move_next() ? pos_ + 1 : std::numeric_limits<xtd::size>::max();
            return *this;
          }
          
          /// @biref The equality operator of specified underlyig itertators.
          /// @return true if underlying iterators are equels; otherwise false.
          friend bool operator ==(const iterator& a, const iterator& b) noexcept { return a.pos_ == b.pos_; }
          /// @biref The inequality operator of specified underlyig itertators.
          /// @return true if underlying iterators are not equels; otherwise false.
          friend bool operator !=(const iterator& a, const iterator& b) noexcept { return !operator==(a, b); }
          /// @}

        private:
          enumerator<type_t> enumerator_;
          xtd::size pos_ = std::numeric_limits<xtd::size>::max();
        };
        /// @}

        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the const iterator of enumarable value type.
        using const_iterator = const iterator;
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        const_iterator cbegin() const noexcept {return iterator(enumerator_->get_enumerator());}
        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        const_iterator cend() const noexcept {return iterator(enumerator_->get_enumerator(), true);}
        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        const_iterator begin() const noexcept {return iterator(enumerator_->get_enumerator());}
        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        iterator begin() noexcept {return iterator(enumerator_->get_enumerator());}
        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        const_iterator end() const noexcept {return iterator(enumerator_->get_enumerator(), true);}
        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        iterator end() noexcept {return iterator(enumerator_->get_enumerator(), true);}
        /// @}
        
      private:
        friend enumerator_t;
        explicit enumerable_iterators(enumerator_t* enumerator) : enumerator_(enumerator) {}
        enumerator_t* enumerator_ = nullptr;
      };
    }
  }
}
