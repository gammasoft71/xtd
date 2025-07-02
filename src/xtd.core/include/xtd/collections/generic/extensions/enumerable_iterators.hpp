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
        /// @brief Internal enumerable iterators definition.
        /// @par Definition
        /// ```cpp
        /// template<class type_t, class enumerable_t>
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
        template<class type_t, class enumerable_t>
        class enumerable_iterators {
          /// @cond
          template<class iterator_enumerable_t>
          class enumerable_iterator : public xtd::icomparable<enumerable_iterator<iterator_enumerable_t>>, public xtd::iequatable<enumerable_iterator<iterator_enumerable_t>> {
          public:
            using value_type = type_t;
            using iterator_category = std::forward_iterator_tag;
            using iterator_concept = std::forward_iterator_tag;
            using difference_type = xtd::ptrdiff;
            using pointer = value_type*;
            using reference = value_type&;

            static constexpr xtd::size npos() {return std::numeric_limits<xtd::size>::max();}

            enumerable_iterator() = default;
            enumerable_iterator(iterator_enumerable_t* enumerable, xtd::size pos) : enumerable_ {enumerable}, enumerator_ {enumerable->get_enumerator()}, pos_ {pos} {reset();}
            enumerable_iterator(enumerable_iterator&& value) noexcept = default;
            enumerable_iterator(const enumerable_iterator& value) noexcept : enumerable_(value.enumerable_), enumerator_(value.enumerable_->get_enumerator()), pos_ {value.pos_} {reset();}
            enumerable_iterator& operator =(enumerable_iterator&& value) noexcept = default;
            enumerable_iterator& operator =(const enumerable_iterator& value) noexcept {
              enumerable_ = value.enumerable_;
              enumerator_ = value.enumerable_->get_enumerator();
              pos_ = value.pos_;
              reset();
              return const_cast<enumerable_iterator&>(*this);
            }
            
            int32 compare_to(const enumerable_iterator& rhs) const noexcept override {return pos_ < rhs.pos_ ? -1 : pos_ > rhs.pos_ ? 1 : 0;}
            bool equals(const enumerable_iterator& rhs) const noexcept override {return pos_ == rhs.pos_;}

            reference operator *() const {return const_cast<value_type&>(enumerator_.current());}
            pointer operator ->() const {return &operator*();}
            
            enumerable_iterator& operator ++() noexcept {
              if (pos_ != npos()) pos_ = enumerator_.move_next() ? pos_ + 1 : npos();
              return const_cast<enumerable_iterator&>(*this);
            }
            enumerable_iterator operator ++(int) noexcept {
              auto current = *this;
              operator ++();
              return current;
            }
            
            template<class value_t>
            const enumerable_iterator operator +(value_t value) const noexcept {return enumerable_iterator {enumerable_, pos_ + value};}
            template<class value_t>
            enumerable_iterator operator +(value_t value) noexcept {return enumerable_iterator {enumerable_, pos_ + value};}
            template<class value_t>
            enumerable_iterator& operator +=(value_t value) noexcept {
              *this = *this + value;
              return *this;
            }
            difference_type operator -(enumerable_iterator value) const noexcept {
              if (pos_ == npos()) return npos();
              return static_cast<difference_type>(pos_ - value.pos_);
            }
            
            operator enumerable_iterator<const iterator_enumerable_t>() const noexcept {
              return enumerable_iterator<const iterator_enumerable_t>(enumerable_, pos_);
            }
            
          private:
            void reset() {
              if (pos_ == npos()) return;
              enumerator_.reset();
              for (auto index = xtd::size {}; index <= pos_; ++index)
                if (enumerator_.move_next() == false) {
                  pos_ = npos();
                  break;
                }
            }
            
            iterator_enumerable_t* enumerable_ = nullptr;
            enumerator<type_t> enumerator_;
            xtd::size pos_ = 0;
          };
          /// @endcond
          
        public:
          /// @name Public Aliases
          
          /// @{
          /// @brief Represents the iterator of enumerable value type.
          using iterator = enumerable_iterator<enumerable_t>;
          /// @brief Represents the const iterator of enumerable value type.
          using const_iterator = enumerable_iterator<const enumerable_t>;
          /// @}
          
          /// @name Public Methods
          
          /// @{
          /// @brief Returns an iterator to the first element of the enumerable.
          /// @return Iterator to the first element.
          virtual const_iterator begin() const {return cbegin();}
          /// @brief Returns an iterator to the first element of the enumerable.
          /// @return Iterator to the first element.
          virtual iterator begin() {return iterator {static_cast<enumerable_t*>(this), 0};}
          
          /// @brief Returns an iterator to the first element of the enumerable.
          /// @return Iterator to the first element.
          virtual const_iterator cbegin() const {return const_iterator {static_cast<const enumerable_t*>(this), 0};}
          
          /// @brief Returns an iterator to the element following the last element of the enumerable.
          /// @return Iterator to the element following the last element.
          virtual const_iterator cend() const {return const_iterator {static_cast<const enumerable_t*>(this), const_iterator::npos()};}
          
          /// @brief Returns an iterator to the element following the last element of the enumerable.
          /// @return Iterator to the element following the last element.
          virtual const_iterator end() const {return cend();}
          /// @brief Returns an iterator to the element following the last element of the enumerable.
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
          static typename target_collection_t::const_iterator to_const_iterator(typename source_collection_t::const_iterator& value, const source_collection_t& source_collection, const target_collection_t& target_collection) noexcept {
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
          static typename target_collection_t::const_iterator to_const_iterator(typename source_collection_t::const_iterator& value, source_collection_t& source_collection, target_collection_t& target_collection) noexcept {
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

/// @cond
namespace std {
  template<typename type_t, typename enumerable_t>
  struct iterator_traits<typename xtd::collections::generic::extensions::enumerable_iterators<type_t, enumerable_t>> {
    using value_type = type_t;
    using reference = const type_t&;
    using pointer = const type_t*;
    using difference_type = std::ptrdiff_t;
    using iterator_category = std::input_iterator_tag;
  };
}
/// @endcond
