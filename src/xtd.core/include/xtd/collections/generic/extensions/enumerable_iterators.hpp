/// @file
/// @brief Contains xtd::collections::generic::enumerable_iterators <type_t, enumerable_t> class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../enumerator.hpp"
#include "../../../ptrdiff.hpp"
#include "../../../size.hpp"
#include <limits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief The xtd::collections::generic::extensions namespace contains collection and interface extensions.
      namespace extensions {
        /// @brief Internal enumarable iterators definition.
        /// @par Definition
        /// ```cpp
        /// template<typename type_t, typename enumerable_t>
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
        /// @ingroup xtd_core extensions_generic_collections
        /// @remarks The xtd::collections::generic::enumerable_iterators <type_t> class is use to hide the complexity of c++ [std::iterator](https://en.cppreference.com/w/cpp/iterator/iterator).
        /// @remarks The objective is for any collection inheriting from the xtd::collections::generic::ienumerable <type_t> interface to provide the iterator and const_iterator types and `begin` and `end` methods needed to be able to iterate the collection as for example :
        /// ```cpp
        /// auto parts = part_collection {};
        /// Items.add(part {"item one", guid::new_guid()});
        /// /*...*/
        /// Items.add(part {"item n", guid::new_guid()}});
        ///
        /// for (auto part : parts)
        ///   console::write_line(part);
        /// ```
        /// @warning Internal use only for xtd::collections::generic::ienumerable interfece.
        template<typename type_t, typename enumerable_t>
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
            /// @brief Represents the const pointer of the value type.
            using const_pointer = const value_type*;
            /// @brief Represents the reference of the value type.
            using reference = value_type&;
            /// @brief Represents the const reference of the value type.
            using const_reference = const value_type&;
            /// @}
            
            /// @brief Create begin xtd::collections::generic::iterator with specified enumerator.
            /// @param enumerator The enumerator to iterate with.
            /// @return The begin xtd::collections::generic::iterator.
            static iterator begin(const enumerable_t* enumerable) {
              auto begin = iterator {};
              begin.enumerable_ = enumerable;
              begin.enumerator_ = begin.enumerable_->get_enumerator();
              begin.pos_ = 0;
              begin.reset();
              return begin;
            }
            
            /// @brief Create end xtd::collections::generic::iterator with specified enumerator.
            /// @param enumerator The enumerator to iterate with.
            /// @return The end xtd::collections::generic::iterator.
            static iterator end(const enumerable_t* enumerable) {
              auto end = iterator {};
              end.enumerable_ = enumerable;
              end.enumerator_ = end.enumerable_->get_enumerator();
              end.pos_ = std::numeric_limits<xtd::size>::max();
              end.reset();
              return end;
            }
            
            /// @name Public Constructors
            
            /// @{
            /// @brief Initializes a new instance of the xtd::collections::generic::iterator class.
            iterator() = default;
            /// @}
            
            /// @cond
            iterator(const iterator& value) noexcept : enumerable_(value.enumerable_), enumerator_(value.enumerable_->get_enumerator()), pos_ {value.pos_} {reset();}
            iterator(iterator&& value) = default;
            iterator& operator =(const iterator& value) noexcept {
              enumerable_ = value.enumerable_;
              enumerator_ = value.enumerable_->get_enumerator();
              pos_ = value.pos_;
              reset();
              return *this;
            }
            /// @endcond
            
            /// @name Public Operators
            
            /// @{
            /// @brief Returns reference to the current element, or a proxy holding it.
            /// @return The reference to the current element.
            const_reference operator *() const {return enumerator_.current();}
            /// @brief Returns reference to the current element, or a proxy holding it.
            /// @return The reference to the current element.
            reference operator *() {return const_cast<reference>(enumerator_.current());}
            /// @brief Returns pointer to the current element, or a proxy holding it.
            /// @return The pointer to the current element.
            const_pointer operator ->() const {return &operator*();}
            /// @brief Returns pointer to the current element, or a proxy holding it.
            /// @return The pointer to the current element.
            pointer operator ->() {return &operator*();}
            
            /// @brief Pre increments the underlying iterator.
            /// @return The underlying iterator.
            iterator& operator ++() noexcept {
              if (pos_ != std::numeric_limits<xtd::size>::max()) pos_ = enumerator_.move_next() ? pos_ + 1 : std::numeric_limits<xtd::size>::max();
              return *this;
            }
            /// @brief Post increments the underlying iterator.
            /// @return The underlying iterator.
            iterator operator ++(int) noexcept {
              auto current = *this;
              operator ++();
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
              if (pos_ == std::numeric_limits<xtd::size>::max()) return std::numeric_limits<xtd::size>::max();
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
            iterator(const iterator& base, value_t value) noexcept : enumerable_(base.enumerable_),  enumerator_(base.enumerable_->get_enumerator()), pos_ {base.pos_ + value} {reset();}
            
            void reset() {
              enumerator_.reset();
              if (pos_ == std::numeric_limits<xtd::size>::max()) return;
              for (auto index = xtd::size {}; index <= pos_; ++index)
                if (enumerator_.move_next() == false) {
                  pos_ = std::numeric_limits<xtd::size>::max();
                  break;
                }
            }
            
            const enumerable_t* enumerable_ = nullptr;
            enumerator<type_t> enumerator_;
            xtd::size pos_ = 0;
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
          virtual const_iterator begin() const {return const_iterator::begin(static_cast<const enumerable_t*>(this));}
          /// @brief Returns an iterator to the first element of the enumarable.
          /// @return Iterator to the first element.
          virtual iterator begin() {return iterator::begin(static_cast<enumerable_t*>(this));}
          
          /// @brief Returns an iterator to the first element of the enumarable.
          /// @return Iterator to the first element.
          virtual const_iterator cbegin() const {return const_iterator::begin(static_cast<const enumerable_t*>(this));}
          
          /// @brief Returns an iterator to the element following the last element of the enumarable.
          /// @return Iterator to the element following the last element.
          virtual const_iterator cend() const {return const_iterator::end(static_cast<const enumerable_t*>(this));}
          
          /// @brief Returns an iterator to the element following the last element of the enumarable.
          /// @return Iterator to the element following the last element.
          virtual const_iterator end() const {return const_iterator::end(static_cast<const enumerable_t*>(this));}
          /// @brief Returns an iterator to the element following the last element of the enumarable.
          /// @return Iterator to the element following the last element.
          virtual iterator end() {return iterator::end(static_cast<enumerable_t*>(this));}
          /// @}
        };
      }
    }
  }
}
