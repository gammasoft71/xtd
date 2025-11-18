/// @file
/// @brief Contains xtd::collections::generic::hash_set <type_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "helpers/allocator.hpp"
#include "helpers/equator.hpp"
#include "helpers/hasher.hpp"
#include "iset.hpp"
#include <unordered_set>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::generic namespace contains interfaces and classes that define generic collections, which allow users to create strongly typed collections that provide better type safety and performance than non-generic strongly typed collections.
    namespace generic {
      /// @brief Represents a set of values.
      /// @par Definition
      /// ```cpp
      /// template<class type_t, class hasher_t = xtd::collections::generic::helpers::hasher<type_t>, class equator_t = xtd::collections::generic::helpers::equator<type_t>, class allocator_t = xtd::collections::generic::helpers::allocator<type_t >>
      /// class hash_set : public xtd::object, public xtd::collections::generic::iset<type_t>
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/generic/hash_set>
      /// ```
      /// @par Namespace
      /// xtd::collections::generic
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core generic_collections
      /// @remarks The xtd::collections::generic::hash_set class is same as [std::unordered_set](https://en.cppreference.com/w/cpp/container/unordered_set).
      /// @par Examples
      /// The following example demonstrates how to merge two disparate sets. This example creates two xtd::collections::generic::hash_set <type_t> objects and populates them with even and odd numbers, respectively. A third xtd::collections::generic::hash_set <type_t> object is created from the set that contains the even numbers. The example then calls the xtd::collections::generic::hash_set::union_with method, which adds the odd number set to the third set.
      /// @include generic_hash_set.cpp
      template<class type_t, class hasher_t = xtd::collections::generic::helpers::hasher<type_t>, class equator_t = xtd::collections::generic::helpers::equator<type_t>, class allocator_t = xtd::collections::generic::helpers::allocator<type_t >>
      class hash_set : public xtd::object, public xtd::collections::generic::iset<type_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the hash set key type.
        using key_type = typename xtd::collections::generic::iset<type_t>::key_type;
        /// @brief Represents the hash set value type.
        using value_type = typename xtd::collections::generic::iset <type_t>::value_type;
        /// @brief Represents the hash set size type.
        using size_type = xtd::size;
        /// @brief Represents the hash set base type.
        using base_type = std::unordered_set<key_type, hasher_t, equator_t, allocator_t>;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Initializes a new instance of the xtd::collections::generic::hash_set <type_t> class that is empty and uses the default equality comparer for the set type.
        /// @par Examples
        /// The following example demonstrates how to create and populate two xtd::collections::generic::hash_set <type_t> objects. This example is part of a larger example provided for the xtd::collections::generic::hash_set::union_with method.
        /// ```cpp
        /// auto even_numbers = hash_set<int> {};
        /// auto odd_numbers = hash_set<int> {};
        ///
        /// for (auto i = 0; i < 5; ++i) {
        ///   // Populate even_numbers with just even numbers.
        ///   even_numbers.add(i * 2);
        ///
        ///   // Populate odd_numbers with just odd numbers.
        ///   odd_numbers.add((i * 2) + 1);
        /// }
        /// ```
        /// @remarks The capacity of a xtd::collections::generic::hash_set <type_t> object is the number of elements that the object can hold. A xtd::collections::generic::hash_set <type_t> object's capacity automatically increases as elements are added to the object.
        /// @remarks This constructor is an O(1) operation.
        hash_set() noexcept = default;
        /// @brief Initializes a new instance of the xtd::collections::generic::hash_set <type_t> class that is empty and uses the specified equality comparer for the set type.
        /// @param comparer The xtd::collections::generic::iequality_comparer <type_t> implementation to use when comparing values in the set.
        /// @remarks The capacity of a xtd::collections::generic::hash_set <type_t> object is the number of elements that the object can hold. A xtd::collections::generic::hash_set <type_t> object's capacity automatically increases as elements are added to the object.
        /// @remarks This constructor is an O(1) operation.
        hash_set(const xtd::collections::generic::iequality_comparer<key_type>& comparer) noexcept : data_(xtd::new_ptr<hash_set_data>(comparer)) {}
        /// @brief Initializes a new instance of the xtd::collections::generic::hash_set <type_t> class that uses the default equality comparer for the set type, contains elements copied from the specified collection, and has sufficient capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new set.
        /// @par Examples
        /// The following example shows how to create a xtd::collections::generic::hash_set <type_t> collection from an existing set. In this example, two sets are created with even and odd integers, respectively. A third xtd::collections::generic::hash_set <type_t> object is then created from the even integer set.
        /// @include generic_hash_set.cpp
        /// @remarks The capacity of a xtd::collections::generic::hash_set <type_t> object is the number of elements that the object can hold. A xtd::collections::generic::hash_set <type_t> object's capacity automatically increases as elements are added to the object.
        /// @remarks If `collection` contains duplicates, the set will contain one of each unique element. No exception will be thrown. Therefore, the size of the resulting set is not identical to the size of `collection`.
        /// @remarks This constructor is an O(`n`) operation, where `n` is the number of elements in the `collection` parameter.
        hash_set(const ienumerable<value_type>& collection) noexcept {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::hash_set <type_t> class that uses the specified equality comparer for the set type, contains elements copied from the specified collection, and has sufficient capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new set.
        /// @param comparer The xtd::collections::generic::iequality_comparer <type_t> implementation to use when comparing values in the set.
        /// @par Examples
        /// The following example uses a supplied xtd::collections::generic::iequality_comparer <type_t> to allow case-insensitive comparisons on the elements of a xtd::collections::generic::hash_set <type_t> collection of vehicle types.
        /// @include generic_hash_set2.cpp
        hash_set(const ienumerable < value_type >& collection, const xtd::collections::generic::iequality_comparer<key_type>& comparer) noexcept : data_(xtd::new_ptr<hash_set_data>(comparer)) {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Initializes a new instance of the xtd::collections::generic::hash_set <type_t> class that is empty, but has reserved space for capacity items and uses the default equality comparer for the set type.
        /// @param capacity The initial size of the xtd::collections::generic::hash_set <type_t>.
        /// @remarks Since resizes are relatively expensive (require rehashing), this attempts to minimize the need to resize by setting the initial capacity based on the value of the capacity.
        hash_set(size_type capacity) noexcept {
          ensure_capacity(capacity);
        }
        hash_set(hash_set&& other) noexcept = default;
        hash_set(const hash_set& other) noexcept : data_(xtd::new_ptr<hash_set_data>(other.data_->comparer, other.data_->items, other.data_->version)) {}
        hash_set(std::unordered_set<key_type>&& other) noexcept : data_(xtd::new_ptr<hash_set_data>(std::move(other))) {}
        hash_set(const std::unordered_set<key_type>& other) noexcept {
          for (auto iterator = other.begin(); iterator != other.end(); ++iterator)
            add(*iterator);
        }
        hash_set(std::initializer_list <value_type> init) {
          ensure_capacity(init.size());
          for (const auto& value : init)
            add(value);
        }
        template <class input_iterator_t>
        explicit hash_set(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator)
            add(*iterator);
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the total numbers of elements the internal data structure can hold without resizing.
        /// @return The total numbers of elements the internal data structure can hold without resizing.
        size_type capacity() const noexcept {return items().bucket_count();}
        
        /// @brief Gets the xtd::collections::generic::iequality_comparer <type_t> that is used to determine equality of keys for the set.
        /// @return The xtd::collections::generic::iequality_comparer <type_t> generic interface implementation that is used to determine equality of keys for the current xtd::collections::generic::hash_set <type_t> and to provide hash values for the keys.
        /// @remarks xtd::collections::generic::hash_set <type_t> requires an equality implementation to determine whether keys are equal. You can specify an implementation of the xtd::collections::generic::iequality_comparer <type_t> generic interface by using a constructor that accepts a comparer parameter; if you do not specify one, the default generic equality comparer td::collections::generic::equality_comparer::default_equality_comparer is used.
        const iequality_comparer<key_type>& comparer() const noexcept {
          if (!data_->comparer) return equality_comparer <key_type>::default_equality_comparer();
          return *data_->comparer;
        }
        
        /// @brief Gets the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that the xtd::collections::generic::dictionary <key_t, value_t> can store. The xtd::collections::generic::dictionary::count property is the number of elements that are actually in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity is always greater than or equal to xtd::collections::generic::dictionary::count. If xtd::collections::generic::dictionary::count exceeds the capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks Getting the value of this property is an O(1) operation.
        size_type count() const noexcept override {return items().size();}
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual const base_type& items() const noexcept {return data_->items;}
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual base_type& items() noexcept {return data_->items;}
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Adds an item to the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to add to the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        bool add(const key_type& item) noexcept override {
          if (contains(item)) return false;
          items().insert(item);
          ++data_->version;
          return true;
        }
        
        /// @brief Removes all keys and values from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The xtd::collections::generic::dictionary::count property is set to 0, and references to other objects from elements of the collection are also released. The capacity remains unchanged.
        void clear() noexcept override {
          items().clear();
          ++data_->version;
        }
        
        /// @brief Determines whether an element is in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param item The object to be added to the end of the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified `item` ; otherwise, `false`.
        bool contains(const value_type & item) const noexcept override {
          return items().find(item) != items().end();
        }
        
        /// @brief Copies the complete hash_set <type_t> to a compatible one-dimensional array, starting at the beginning of the target array.
        /// @param array A one-dimensional array that is the destination of the elements copied from the hash_set <type_t>.
        /// @exception ArgumentException The number of elements in the source hash_set <type_t> exceeds the number of elements that the destination array can contain.
        /// @exception ArgumentNullException array is null.
        void copy_to(xtd::array<type_t>& array) const {
          copy_to(0, array, 0, count());
        }
        
        /// @brief Copies the complete hash_set <type_t> to a compatible one-dimensional array, starting at the specified array index.
        /// @param array A one-dimensional array that is the destination of the elements copied from the hash_set <type_t>. The array must have zero-based indexing.
        /// @param index The zero-based index in array at which copying begins.
        /// @exception ArgumentException The number of elements in the source array is greater than the available space from index to the end of the destination array.
        /// @exception ArgumentNullException array is null.
        /// @exception ArgumentOutOfRangeException index is less than zero.
        void copy_to(xtd::array<type_t>& array, size_type index) const override {
          copy_to(0, array, index, count());
        }
        
        /// @brief Copies a specified number of elements from hash_set <type_t> to a compatible one-dimensional array, starting at the specified array index
        /// @param array A one-dimensional array that is the destination of the elements copied from the hash_set <type_t>. The array must have zero-based indexing.
        /// @param index The zero-based index in array at which copying begins.
        /// @param count The number of elements to copy.
        /// @exception ArgumentException The number of elements in the source (count) array is greater than the available space from index to the end of the destination array.
        /// @exception ArgumentNullException array is null.
        /// @exception ArgumentOutOfRangeException index is less than zero or count is less than zero.
        void copy_to(size_type index, xtd::array<type_t>& array, size_type array_index, size_type count) const {
          if (index + count > self_.count() || array_index + count > array.length()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
          auto increment = size_type {};
          for (const auto& item : self_) {
            if (increment >= index + count) return;
            if (increment++ >= index) array[array_index++] = item;
          }
        }
        
        /// @brief Ensures that the dictionary can hold up to a specified number of entries without any further expansion of its backing storage.
        /// @param capacity The number of entries.
        /// @return The current capacity of the xtd::collections::generic::dictionary <key_t, value_t>.
        xtd::size ensure_capacity(xtd::size capacity) noexcept {
          data_->items.reserve(capacity);
          return self_.capacity();
        }
        
        /// @brief Removes all elements in the specified collection from the current set.
        /// @param other The collection of items to remove from the set.
        /// @remarks This method is an O(`n`) operation, where `n` is the number of elements in the other parameter.
        void except_with(const xtd::collections::generic::ienumerable<type_t>& other) noexcept override {
          if (&other == this) {
            clear();
            return;
          }
          for (const type_t& item : other)
            remove(item);
        }
        
        /// @brief Returns an enumerator that iterates through the xtd::collections::generic::hash_set <type_t>.
        /// @return A xtd::collections::enumerator structure for the xtd::collections::generic::hash_set <type_t>.
        enumerator<value_type> get_enumerator() const noexcept override {
          struct hash_set_enumerator : public ienumerator < value_type > {
            explicit hash_set_enumerator(const hash_set & items, size_type version) : items_(items), version_(version) {}
            
            const value_type& current() const override {
              if (iterator_ == items_.items().cend()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              value_ = value_type {*iterator_};
              return value_;
            }
            
            bool move_next() override {
              if (version_ != items_.data_->version) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
              if (index_++ && iterator_ != items_.data_->items.cend()) ++iterator_;
              else iterator_ = items_.items().cbegin();
              return  iterator_ != items_.data_->items.cend();
            }
            
            void reset() override {
              index_ = 0;
              version_ = items_.data_->version;
              iterator_ = items_.items().cend();
            }
            
          private:
            size_type index_ = 0;
            const hash_set& items_;
            typename hash_set::base_type::const_iterator iterator_ = items_.data_->items.cend();
            mutable value_type value_;
            size_type version_ = 0;
          };
          return {new_ptr < hash_set_enumerator > (self_, data_->version)};
        }
        
        /// @brief Modifies the current set so that it contains only elements that are also in a specified collection.
        /// @param other The collection to compare to the current set.
        /// @remarks This method ignores any duplicate elements in `other`.
        void intersect_with(const xtd::collections::generic::ienumerable<type_t>& other) noexcept override {
          auto to_keep = hash_set {other};
          auto to_remove = hash_set {};
          for (const type_t& item : self_)
            if (!to_keep.contains(item))
              to_remove.add(item);
          except_with(to_remove);
        }
        
        /// @brief Determines whether the current set is a proper (strict) superset of a specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is a proper superset of `other`; otherwise, `false`.
        bool is_proper_subset_of(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept override {
          auto set = hash_set {other};
          if (count() == 0) return set.count() > 0;
          if (count() >= set.count()) return false;
          return sub_set(set);
        }
        
        /// @brief Determines whether the current set is a proper (strict) superset of a specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is a proper superset of `other`; otherwise, `false`.
        bool is_proper_superset_of(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept override {
          auto set = hash_set {other};
          if (set.count() == 0) return count() > 0;
          if (set.count() >= count()) return false;
          return super_set(set);
        }
        
        /// @brief Determines whether a set is a subset of a specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is a subset of `other`; otherwise, `false`.
        bool is_subset_of(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept override {
          return sub_set(hash_set {other});
        }
        
        /// @brief Determines whether a set is a superset of a specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is a superset of `other`; otherwise, `false`.
        bool is_superset_of(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept override {
          return super_set(hash_set {other});
        }
        
        /// @brief Determines whether the current set overlaps with the specified collection.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set and `other` share at least one common element; otherwise, `false`.
        bool overlaps(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept override {
          if (count() == 0) return false;
          for (const auto& item : other)
            if (contains(item)) return true;
          return false;
        }
        
        /// @brief Removes a specified item from the hash_set <type_t>.
        /// @param item The element to remove.
        /// @return true if the element was removed, false otherwise.
        bool remove(const type_t& item) noexcept override {
          auto result = items().erase(item) == 1;
          ++data_->version;
          return result;
        }
        
        /// @brief Removes all elements that match the conditions defined by the specified predicate from a hash_set <type_t> collection.
        /// @param match The xtd::predicate <type_t> delegate that defines the conditions of the elements to remove.
        /// @return The number of elements that were removed from the hash_set <type_t> collection.
        template<class predicate_t>
        size_type remove_where(predicate_t match) noexcept {
          auto to_remove = hash_set {};
          for (const auto& item : self_)
            if (match(item)) to_remove.add(item);
          for (const auto& item : to_remove)
            remove(item);
          return to_remove.count();
        }
        
        /// @brief Determines whether the current set and the specified collection contain the same elements.
        /// @param other The collection to compare to the current set.
        /// @return `true` if the current set is equal to `other`; otherwise, `false`.
        bool set_equals(const xtd::collections::generic::ienumerable<type_t>& other) const noexcept override {
          auto set = hash_set {other};
          if (count() != set.count()) return false;
          for (const auto& item : other)
            if (!contains(item)) return false;
          return true;
        }
        
        /// @brief Modifies the current set so that it contains only elements that are present either in the current set or in the specified collection, but not both.
        /// @param other The collection to compare to the current set.
        /// @remarks Any duplicate elements in `other` are ignored.
        void symetric_excep_with(const xtd::collections::generic::ienumerable<type_t>& other) noexcept override {
          for (const auto& item : other)
            if (contains(item)) remove(item);
            else add(item);
        }
        
        /// @brief Gets a string that represents the current object.
        /// @return A string that represents the current object.
        xtd::string to_string() const noexcept override {return xtd::string::format("{{{}}}", xtd::string::join(", ", self_));}
        
        /// @brief Modifies the current set so that it contains all elements that are present in the current set, in the specified collection, or in both.
        /// @param other The collection to compare to the current set.
        /// @remarks Any duplicate elements in `other` are ignored.
        void union_with(const xtd::collections::generic::ienumerable<type_t>& other) noexcept override {
          for (const auto& item : other)
            if (!contains(item)) add(item);
        }
        
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @}
        
      private:
        bool is_read_only() const noexcept override {return false;}
        bool is_synchronized() const noexcept override {return false;}
        const xtd::object& sync_root() const noexcept override {return data_->sync_root;}
        bool sub_set(const hash_set& set) const noexcept {
          if (count() == 0) return true;
          if (count() > set.count()) return false;
          for (const auto& item : self_)
            if (!set.contains(item)) return false;
          return true;
        }
        
        bool super_set(const hash_set& set) const noexcept {
          if (set.count() == 0) return true;
          if (set.count() > count()) return false;
          for (const auto& item : set)
            if (!contains(item)) return false;
          return true;
        }
        
        struct hash_set_data {
          hash_set_data() = default;
          hash_set_data(const xtd::collections::generic::iequality_comparer<key_type>& comparer) : comparer {&comparer}, items  {size_type {}, hasher_t {*comparer}, equator_t {*comparer}, allocator_t {}} {}
          hash_set_data(const xtd::collections::generic::iequality_comparer<key_type>& comparer, const base_type& items, size_type version) noexcept : comparer {&comparer}, items {size_type {}, hasher_t {*comparer}, equator_t {*comparer}, allocator_t {}}, version {version} {
            for (const auto& item : items)
              self_.items.insert(item);
          }
          hash_set_data(base_type&& items, size_type version) noexcept : version {version} {
            for (auto&& item : items)
              self_.items.insert(item);
          }
          
          const xtd::collections::generic::iequality_comparer<key_type>* comparer = null;
          base_type items;
          size_type version = 0;
          xtd::object sync_root;
        };
        xtd::ptr <hash_set_data> data_ = xtd::new_ptr<hash_set_data>();
      };
      
      /// @cond
      // Deduction guides for xtd::collections::generic::hash_set
      // {
      template<class type_t>
      hash_set(iset<type_t>) -> hash_set<type_t>;
      
      template<class type_t>
      hash_set(ienumerable<type_t>) -> hash_set<type_t>;
      
      template <class type_t>
      hash_set(std::initializer_list<type_t>) -> hash_set<type_t>;
      
      template <class input_iterator_t >
      hash_set(input_iterator_t, input_iterator_t) -> hash_set<typename input_iterator_t::value_type>;
      // }
      /// @endcond
    }
  }
}
