/// @file
/// @brief Contains xtd::collections::generic::extensions::enumerable_iterators <type_t, enumerable_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../enumerator.hpp"
#include "../../../icomparable.hpp"
#include "../../../iequatable.hpp"
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
        /// template<class type_t, class enumerable_t, class iterator_tag_t =  std::bidirectional_iterator_tag>
        /// class enumerable_iterators;
        /// ```
        /// @par Header
        /// ```cpp
        /// #include <xtd/collections/generic/extensions/enumerable_iterators>
        /// ```
        /// @par Namespace
        /// xtd::collections::generic
        /// @par Library
        /// xtd.core
        /// @ingroup xtd_core extensions_generic_collections
        /// @remarks The xtd::collections::generic::extensions::enumerable_iterators <type_t> class is use to hide the complexity of c++ [std::iterator](https://en.cppreference.com/w/cpp/iterator/iterator).
        /// @remarks The objective is for any collection inheriting from the xtd::collections::generic::ienumerable <type_t> interface to provide the iterator and const_iterator types and `begin` and `end` methods needed to be able to iterate the collection as for example :
        /// ```cpp
        /// auto parts = part_collection {};
        /// parts.add(part {"item one", guid::new_guid()});
        /// // ...
        /// parts.add(part {"item n", guid::new_guid()}});
        ///
        /// for (auto part : parts)
        ///   console::write_line(part);
        /// ```
        /// @warning Internal use only for xtd::collections::generic::ienumerable interfece.
        template<class type_t, class enumerable_t, class iterator_tag_t =  std::bidirectional_iterator_tag>
        class enumerable_iterators {
        public:
          /// @name Public Classes
          
          /// @{
          /// @brief Represents the iterator of enumarable value type.
          class iterator : public xtd::icomparable<iterator>, public xtd::iequatable<iterator> {
          public:
            /// @name Public Aliases
            
            /// @{
            /// @brief Represents the value type.
            using value_type = type_t;
            /// @brief Represents the iterator category type.
            using iterator_category = iterator_tag_t;
            /// @brief Represents the iterator concept type.
            using iterator_concept  = iterator_tag_t;
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
            
            
            /// @name Public Fields
            
            /// @{
            /// @brief This is a special value equal to the maximum value representable by the type xtd::size.
            static constexpr xtd::size npos() {return std::numeric_limits<xtd::size>::max();}
            /// @}
            
            /// @name Public Constructors
            
            /// @{
            /// @brief Initializes a new instance of the xtd::collections::generic::iterator class.
            iterator() = default;
            
            /// @brief Create an xtd::collections::generic::iterator with specified enumerator and position.
            /// @param enumerator The enumerator to iterate with.
            /// @param pos The position to iterate with.
            /// @return The xtd::collections::generic::iterator.
            /// @remarks Set pos to std::numeric_limits<xtd::size>::max() for end iterator.
            iterator(const enumerable_t* enumerable, xtd::size pos) : enumerable_ {enumerable}, enumerator_ {enumerable->get_enumerator()}, pos_ {pos} {reset();}
            /// @}
            
            /// @cond
            iterator(const iterator& value) noexcept : enumerable_(value.enumerable_), enumerator_(value.enumerable_->get_enumerator()), pos_ {value.pos_} {reset();}
            iterator& operator =(const iterator& value) noexcept {
              enumerable_ = value.enumerable_;
              enumerator_ = value.enumerable_->get_enumerator();
              pos_ = value.pos_;
              reset();
              return const_cast<iterator&>(*this);
            }
            iterator(iterator&& value) noexcept = default;
            iterator& operator =(iterator&& value) noexcept = default;
            /// @endcond
            
            /// @name Public Methods
            
            /// @{
            int32 compare_to(const iterator& rhs) const noexcept override {return pos_ < rhs.pos_ ? -1 : pos_ > rhs.pos_ ? 1 : 0;}
            bool equals(const iterator& rhs) const noexcept override {return pos_ == rhs.pos_;}
            /// @}
            
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
            iterator& operator ++() const noexcept {
              if (pos_ != std::numeric_limits<xtd::size>::max()) pos_ = enumerator_.move_next() ? pos_ + 1 : std::numeric_limits<xtd::size>::max();
              return const_cast<iterator&>(*this);
            }
            /// @brief Post increments the underlying iterator.
            /// @return The underlying iterator.
            iterator operator ++(int) const noexcept {
              auto current = *this;
              operator ++();
              return current;
            }
            
            /// @brief Pre decrements the underlying iterator.
            /// @return The underlying iterator.
            iterator& operator --() const noexcept {
              if (pos_ != 0) pos_ = enumerator_.move_next() ? pos_ - 1 : std::numeric_limits<xtd::size>::max();
              return const_cast<iterator&>(*this);
            }
            /// @brief Post decrements the underlying iterator.
            /// @return The underlying iterator.
            iterator operator --(int) const noexcept {
              auto current = *this;
              operator --();
              return current;
            }
            
            /// @brief Add operator with specified value.
            /// @param value The number to add to the underlying iterator.
            /// @return The underlying iterator.
            template<class value_t>
            iterator operator +(value_t value) const noexcept {return iterator {enumerable_, pos_ + value};}
            /// @brief Add equal operator with specified value.
            /// @param value The number to add to the underlying iterator.
            /// @return The underlying iterator.
            template<class value_t>
            iterator& operator +=(value_t value) noexcept {
              *this = *this + value;
              return *this;
            }
            /// @brief Subtract The specified iterator from the current iterator.
            /// @param value The iterator to subtract from the current iterator.
            /// @return The difference between current iterator and the specified iterator.
            difference_type operator -(iterator value) const noexcept {
              if (pos_ == std::numeric_limits<xtd::size>::max()) return std::numeric_limits<xtd::size>::max();
              return static_cast<difference_type>(pos_ - value.pos_);
            }
            /// @}
            
          private:
            void reset() const {
              enumerator_.reset();
              if (pos_ == std::numeric_limits<xtd::size>::max()) return;
              for (auto index = xtd::size {}; index <= pos_; ++index)
                if (enumerator_.move_next() == false) {
                  pos_ = std::numeric_limits<xtd::size>::max();
                  break;
                }
            }
            
            mutable const enumerable_t* enumerable_ = nullptr;
            mutable enumerator<type_t> enumerator_;
            mutable xtd::size pos_ = 0;
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
          virtual const_iterator begin() const {return cbegin();}
          /// @brief Returns an iterator to the first element of the enumarable.
          /// @return Iterator to the first element.
          virtual iterator begin() {return iterator {static_cast<enumerable_t*>(this), 0};}
          
          /// @brief Returns an iterator to the first element of the enumarable.
          /// @return Iterator to the first element.
          virtual const_iterator cbegin() const {return const_iterator {static_cast<const enumerable_t*>(this), 0};}
          
          /// @brief Returns an iterator to the element following the last element of the enumarable.
          /// @return Iterator to the element following the last element.
          virtual const_iterator cend() const {return const_iterator {static_cast<const enumerable_t*>(this), const_iterator::npos()};}
          
          /// @brief Returns an iterator to the element following the last element of the enumarable.
          /// @return Iterator to the element following the last element.
          virtual const_iterator end() const {return cend();}
          /// @brief Returns an iterator to the element following the last element of the enumarable.
          /// @return Iterator to the element following the last element.
          virtual iterator end() {return iterator {static_cast<enumerable_t*>(this), iterator::npos()};}
          /// @}

          /// @name Public Static Methods
          
          /// @{
          /// @brief Converts source iterator to target iterator.
          /// @param value The source iterator to convert.
          /// @param source The source collection from which the source iterator originates.
          /// @param target_collection The target collection from which the target iterator originates.
          /// @return The converted target iterator.
          /// @remarks This converter is used only to convert a source iterator position into a target iterator position.
          /// @note This converter does not check the validity and consistency of the data in the various collections; it is up to the user to ensure this.
          /// @remarks The distance to move the target iterator is calculated with `std::distance(source_collection.begin(), value);`. Then simply move the target iterator from `target_collection.begin();`.
          template<class source_collection_t, class target_collection_t>
          static typename target_collection_t::const_iterator to_iterator(typename source_collection_t::const_iterator& value, const source_collection_t& source_collection, const target_collection_t& target_collection) noexcept {
            if (value == source_collection.cbegin()) return target_collection.cbegin();
            if (value == source_collection.cend()) return target_collection.cend();
            
            auto result = target_collection.cbegin();
            for (auto index = ptrdiff {}; index < std::distance(source_collection.cbegin(), value); ++index, ++result);
            return result;
          }
          
          /// @brief Converts source iterator to target iterator.
          /// @param value The source iterator to convert.
          /// @param source The source collection from which the source iterator originates.
          /// @param target_collection The target collection from which the target iterator originates.
          /// @return The converted target iterator.
          /// @remarks This converter is used only to convert a source iterator position into a target iterator position.
          /// @note This converter does not check the validity and consistency of the data in the various collections; it is up to the user to ensure this.
          /// @remarks The distance to move the target iterator is calculated with `std::distance(source_collection.begin(), value);`. Then simply move the target iterator from `target_collection.begin();`.
          template<class source_collection_t, class target_collection_t>
          static typename target_collection_t::iterator to_iterator(typename source_collection_t::iterator& value, const source_collection_t& source_collection, const target_collection_t& target_collection) noexcept {
            if (value == source_collection.begin()) return target_collection.begin();
            if (value == source_collection.end()) return target_collection.end();
            
            auto result = target_collection.begin();
            for (auto index = ptrdiff {}; index < std::distance(source_collection.begin(), value); ++index, ++result);
            return result;
          }
          
          /// @brief Converts source iterator to target iterator.
          /// @param value The source iterator to convert.
          /// @param source The source collection from which the source iterator originates.
          /// @param target_collection The target collection from which the target iterator originates.
          /// @return The converted target iterator.
          /// @remarks This converter is used only to convert a source iterator position into a target iterator position.
          /// @note This converter does not check the validity and consistency of the data in the various collections; it is up to the user to ensure this.
          /// @remarks The distance to move the target iterator is calculated with `std::distance(source_collection.begin(), value);`. Then simply move the target iterator from `target_collection.begin();`.
          template<class source_collection_t, class target_collection_t>
          static typename target_collection_t::const_iterator to_iterator(typename source_collection_t::const_iterator& value, source_collection_t& source_collection, target_collection_t& target_collection) noexcept {
            if (value == source_collection.cbegin()) return target_collection.cbegin();
            if (value == source_collection.cend()) return target_collection.cend();
            
            auto result = target_collection.cbegin();
            for (auto index = ptrdiff {}; index < std::distance(source_collection.cbegin(), value); ++index, ++result);
            return result;
          }
          
          /// @brief Converts source iterator to target iterator.
          /// @param value The source iterator to convert.
          /// @param source The source collection from which the source iterator originates.
          /// @param target_collection The target collection from which the target iterator originates.
          /// @return The converted target iterator.
          /// @remarks This converter is used only to convert a source iterator position into a target iterator position.
          /// @note This converter does not check the validity and consistency of the data in the various collections; it is up to the user to ensure this.
          /// @remarks The distance to move the target iterator is calculated with `std::distance(source_collection.begin(), value);`. Then simply move the target iterator from `target_collection.begin();`.
          template<class source_collection_t, class target_collection_t>
          static typename target_collection_t::iterator to_iterator(typename source_collection_t::iterator& value, source_collection_t& source_collection, target_collection_t& target_collection) noexcept {
            if (value == source_collection.begin()) return target_collection.begin();
            if (value == source_collection.end()) return target_collection.end();
            
            auto result = target_collection.begin();
            for (auto index = ptrdiff {}; index < std::distance(source_collection.begin(), value); ++index, ++result);
            return result;
          }
          /// @}
        };
      }
    }
  }
}
