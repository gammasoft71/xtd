/// @file
/// @brief Contains xtd::collections::generic::enumerable_iterators <type_t, enumerator_t> class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "enumerator.h"
#include "../../ptrdiff.h"
#include "../../size.h"
#include "../../size_object.h"

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
      /// @ingroup xtd_core generic_collections
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
          /// @brief Represents the value type.
          using difference_type = xtd::ptrdiff;
          /// @brief Represents the pointer of the value type.
          using pointer = value_type*;
          /// @brief Represents the reference of the value type.
          using reference = value_type&;
          /// @}

          /// @brief Create begin xtd::collections::generic::iterator with specified enumerator.
          /// @param enumerator The enumerator to iterate with.
          /// @return The begin xtd::collections::generic::iterator.
          static iterator begin(enumerator<type_t> enumerator) {
            auto begin = iterator {};
            begin.enumerator_ = enumerator;
            begin.pos_ = 0;
            begin.initial_pos_ = 0;
            begin.reset();
            return begin;
          }
          
          /// @brief Create end xtd::collections::generic::iterator with specified enumerator.
          /// @param enumerator The enumerator to iterate with.
          /// @return The end xtd::collections::generic::iterator.
          static iterator end(enumerator<type_t> enumerator) {
            auto end = iterator {};
            end.enumerator_ = enumerator;
            end.pos_ = xtd::size_object::max_value;
            end.initial_pos_ = xtd::size_object::max_value;
            end.reset();
            return end;
          }
          
          /// @name Public Constructors
          
          /// @{
          /// @brief Initializes a new instance of the xtd::collections::generic::iterator class.
          iterator() = default;
          /// @brief Initializes a new instance of the xtd::collections::generic::iterator class with specified iterator.
          /// @param value The enumerator to iterate with.
          iterator(const iterator& value) noexcept : enumerator_(value.enumerator_), pos_ {value.initial_pos_}, initial_pos_(value.initial_pos_) {
            reset();
          }
          /// @}
          
          /// @cond
          iterator& operator =(const iterator& value) noexcept {
            enumerator_ = value.enumerator_;
            pos_ = value.initial_pos_;
            initial_pos_ = value.initial_pos_;
            reset();
            return *this;
          }
          /// @endcond

          /// @name Public Operators
          
          /// @{
          /// @brief Returns reference to the current element, or a proxy holding it.
          /// @return The reference to the current element.
          reference operator *() const {return const_cast<reference>(enumerator_.current());}
          /// @brief Returns pointer to the current element, or a proxy holding it.
          /// @return The pointer to the current element.
          pointer operator ->() {return &operator*();}
          
          /// @brief Pre increments the underlying iterator.
          /// @return The underlying iterator.
          iterator& operator ++() {
            if (pos_ != xtd::size_object::max_value) pos_ = enumerator_.move_next() ? pos_ + 1 : xtd::size_object::max_value;
            return *this;
          }
          /// @brief Post increments the underlying iterator.
          /// @return The underlying iterator.
          iterator operator ++(int) {
            auto current = *this;
            current.pos_ = pos_;
            current.initial_pos_ = pos_;
            ++(*this);
            return current;
          }
          
          /// @brief Add operator with specified value.
          /// @param value The number to add to the underlying iterator.
          /// @return The underlying iterator.
          template<typename value_t>
          iterator operator +(value_t value) const noexcept {return iterator {*this, value};}
          
          /// @brief Subtract The specified iterator from the current iterator.
          /// @param value The iterator to subtract from the current iterator.
          /// @return The difference between current iterator and the specified iterator.
          difference_type operator -(iterator value) const noexcept {
            if (pos_ == xtd::size_object::max_value) return xtd::size_object::max_value;
            return static_cast<difference_type>(pos_ - value.pos_);
          }
          
          /// @biref The equality operator of specified underlyig itertators.
          /// @return true if underlying iterators are equels; otherwise false.
          friend bool operator ==(const iterator& a, const iterator& b) noexcept {return a.pos_ == b.pos_;}
          /// @biref The inequality operator of specified underlyig itertators.
          /// @return true if underlying iterators are not equels; otherwise false.
          friend bool operator !=(const iterator& a, const iterator& b) noexcept {return !operator==(a, b);}
          /// @}

        private:
          template<typename value_t>
          iterator(const iterator& base, value_t value) noexcept : enumerator_(base.enumerator_), pos_ {base.initial_pos_ + value}, initial_pos_(base.initial_pos_ + value) {
            reset();
          }

          void reset() {
            enumerator_.reset();
            if (pos_ == xtd::size_object::max_value) return;
            
            // Must be executed at least once
            auto index = 0_z;
            do {
              if (enumerator_.move_next() == true) continue;
              pos_ = xtd::size_object::max_value;
              break;
            } while (++index <= pos_);
          }
          enumerator<type_t> enumerator_;
          xtd::size pos_ = 0;
          xtd::size initial_pos_ = 0;
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
        virtual const_iterator begin() const noexcept {return iterator::begin(enumerator_->get_enumerator());}
        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        virtual iterator begin() noexcept {return iterator::begin(enumerator_->get_enumerator());}

        /// @brief Returns an iterator to the first element of the enumarable.
        /// @return Iterator to the first element.
        virtual const_iterator cbegin() const noexcept {return iterator::begin(enumerator_->get_enumerator());}

        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        virtual const_iterator cend() const noexcept {return iterator::end(enumerator_->get_enumerator());}

        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        virtual const_iterator end() const noexcept {return iterator::end(enumerator_->get_enumerator());}
        /// @brief Returns an iterator to the element following the last element of the enumarable.
        /// @return Iterator to the element following the last element.
        virtual iterator end() noexcept {return iterator::end(enumerator_->get_enumerator());}
        /// @}
        
      private:
        friend enumerator_t;
        explicit enumerable_iterators(enumerator_t* enumerator) : enumerator_(enumerator) {}
        enumerator_t* enumerator_ = nullptr;
      };
    }
  }
}
