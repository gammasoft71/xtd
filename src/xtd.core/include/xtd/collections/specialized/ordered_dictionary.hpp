/// @file
/// @brief Contains xtd::collections::specialized::ordered_dictionary <key_t, value_t> class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../generic/dictionary.hpp"
#include "../generic/list.hpp"
#include "../generic/key_not_found_exception.hpp"
#include "../generic/helpers/iterator.hpp"
#include "../../threading/lock.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief The xtd::collections::specialized namespace contains specialized and strongly-typed collections; for example, a linked list dictionary, a bit vector, and collections that contain only strings.
    namespace specialized {
      /// @brief Represents a collection of keys and values.
      /// @par Definition
      /// ```cpp
      /// template<class key_t, class value_t, class allocator_t = xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t>>>
      /// class ordered_dictionary : public xtd::object, public xtd::collections::generic::iordered_dictionary<key_t, value_t>;
      /// ```
      /// @par Header
      /// ```cpp
      /// #include <xtd/collections/specialized/ordered_dictionary>
      /// ```
      /// @par Namespace
      /// xtd::collections::specialized
      /// @par Library
      /// xtd.core
      /// @ingroup xtd_core specialized_collections
      template<class key_t, class value_t, class allocator_t = xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t>>>
      class ordered_dictionary : public xtd::object, public xtd::collections::generic::idictionary<key_t, value_t> {
      public:
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the dictionary key type.
        using key_type = typename xtd::collections::generic::idictionary<key_t, value_t>::key_type;
        /// @brief Represents the dictionary mapped type.
        using mapped_type = typename xtd::collections::generic::idictionary<key_t, value_t>::mapped_type;
        /// @brief Represents the dictionary value type.
        using value_type = typename xtd::collections::generic::idictionary<key_type, mapped_type>::value_type;
        /// @brief Represents the dictionary size type.
        using size_type = xtd::size;
        /// @brief Represents the dictionary base value type.
        using base_value_type = xtd::collections::generic::key_value_pair<key_type, mapped_type>;
        /// @brief Represents the dictionary base type.
        using base_type = xtd::collections::generic::list<xtd::collections::generic::key_value_pair<key_type, mapped_type>>;
        /// @brief Represents the dictionary base type.
        using dictionary_type = xtd::collections::generic::dictionary<key_type, mapped_type*>;
        /// @brief Represents the idictionary key collection type.
        using key_collection = typename xtd::collections::generic::idictionary<key_type, mapped_type>::key_collection;
        /// @brief Represents the idictionary value collection type.
        using value_collection = typename xtd::collections::generic::idictionary<key_type, mapped_type>::value_collection;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        ordered_dictionary() noexcept = default;
        ordered_dictionary(const xtd::collections::generic::idictionary<key_t, value_t>& dictionary) {
          data_->list_items.capacity(dictionary.count());
          data_->dictionary_items.ensure_capacity(dictionary.count());
          for (const auto& item : dictionary)
            add(item);
        }
        ordered_dictionary(const xtd::collections::generic::ienumerable < value_type > & collection) {
          for (const auto& item : collection)
            add(item);
        }
        ordered_dictionary(size_t capacity) {
          data_->list_items.capacity(capacity);
          data_->dictionary_items.ensure_capacity(capacity);
        }
        template < class input_iterator_t >
        explicit ordered_dictionary(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator) {
            const auto& [key, value] = *iterator;
            add(key, value);
          }
        }
        ordered_dictionary(const ordered_dictionary & other) noexcept : data_(xtd::new_ptr<dictionary_data>(other.data_->list_items, other.data_->version)) {}
        ordered_dictionary(ordered_dictionary&& other) noexcept = default;
        ordered_dictionary(std::initializer_list<base_value_type> init) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
            self_[key] = value;
          }
        }
        template < class init_key_t, class init_value_t >
        explicit ordered_dictionary(std::initializer_list<key_value_pair<init_key_t, init_value_t>> init) {
          for (const auto& [key, value] : init) {
            if (contains_key(key)) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
            add(key, value);
          }
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return the number of key/value pairs contained in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity of a xtd::collections::generic::dictionary <key_t, value_t> is the number of elements that the xtd::collections::generic::dictionary <key_t, value_t> can store. The xtd::collections::generic::dictionary::count property is the number of elements that are actually in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The capacity is always greater than or equal to xtd::collections::generic::dictionary::count. If xtd::collections::generic::dictionary::count exceeds the capacity while adding elements, the capacity is increased by automatically reallocating the internal array before copying the old elements and adding the new elements.
        /// @remarks Getting the value of this property is an O(1) operation.
        size_type count() const noexcept override {return data_->list_items.count();}
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual const base_type & items() const noexcept {return data_->list_items;}
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        virtual base_type & items() noexcept {return data_->list_items;}
        
        key_collection keys() const noexcept override {
          auto keys = key_collection {};
          for (const auto& [key, value] : data_->list_items)
            keys.add(key);
          return keys;
        }
        value_collection values() const noexcept override {
          auto values = value_collection {};
          for (const auto& [key, value] : data_->list_items)
            values.add(value);
          return values;
        }
        /// @}
        
        /// @name Public Methods
        
        /// @{
        void add(const key_t & key, const value_t value) override {
          insert(count(), key, value);
        }
        
        /// @brief Adds an item to the xtd::collections::generic::icollection <type_t>.
        /// @param item The object to add to the xtd::collections::generic::icollection <type_t>.
        /// @exception xtd::not_supported_exception The xtd::collections::generic::icollection <type_t> is read-only.
        void add(const value_type & item) override {
          insert(count(), item.key(), item.value());
        }
        
        /// @brief Removes all keys and values from the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @remarks The xtd::collections::generic::dictionary::count property is set to 0, and references to other objects from elements of the collection are also released. The capacity remains unchanged.
        void clear() noexcept override {
          lock_(data_->sync_op) {
            data_->list_items.clear();
            data_->dictionary_items.clear();
          }
          ++data_->version;
        }
        
        /// @brief Determines whether an element is in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @param item The object to be added to the end of the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified `item` ; otherwise, `false`.
        bool contains(const value_type & item) const noexcept override {
          return data_->list_items.contains(item);
        }
        
        /// @brief Determines whether the xtd::collections::generic::dictionary <key_t, value_t> contains the specified key.
        /// @param The key to locate in the xtd::collections::generic::dictionary <key_t, value_t>.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified `key` ; otherwise, `false`.
        /// @remarks This method approaches an O(1) operation.
        bool contains_key(const key_t & key) const noexcept override {
          return data_->dictionary_items.contains_key(key);
        }
        
        bool contains_value(const value_t& value) const noexcept {
          for (const auto& [item_key, item_value] : self_)
            if (item_value == value) return true;
          return false;
        }
        
        /// @brief Copies the elements of the xtd::collections::generic::icollection <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::generic::icollection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::collections::generic::icollection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        void copy_to(xtd::array<value_type>& array, xtd::size array_index) const override {
          if (array_index + count() > array.size()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
          auto index = size_type {0};
          for (const auto& item : self_)
            array[array_index + index++] = item;
        }
        
        xtd::collections::generic::enumerator<value_type> get_enumerator() const noexcept override {
          return data_->list_items.get_enumerator();
        }
        
        void insert(xtd::size index, const key_t & key) {
          insert(index, key, value_t {});
        }
        
        void insert(xtd::size index, const key_t & key, const value_t value) {
          if (contains_key(key)) return xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument);
          lock_(data_->sync_op) {
            data_->list_items.insert(index, std::forward<base_value_type>({key, value}));
            data_->dictionary_items.add(key, &data_->list_items[index].second);
          }
          ++data_->version;
        }
        
        bool remove(const key_t & key) noexcept override {
          if (!contains_key(key)) return false;
          lock_(data_->sync_op) {
            remove_at(get_index(key));
            data_->dictionary_items.remove(key);
          }
          ++data_->version;
          return true;
        }
        
        bool remove(const value_type & item) noexcept override {
          lock_(data_->sync_op) {
            auto result = data_->list_items.remove(item);
            if (!result) return false;
            data_->dictionary_items.remove(item.first);
          }
          ++data_->version;
          return true;
        }
        
        void remove_at(xtd::size index) {
          const auto& key = data_->list_items[index].first;
          lock_(data_->sync_op) {
            data_->list_items.remove_at(index);
            data_->dictionary_items.remove(key);
          }
          ++data_->version;
        }
        
        /// @brief Gets a string that represents the current object.
        /// @return A string that represents the current object.
        xtd::string to_string() const noexcept override {return xtd::string::format("{{{}}}", xtd::string::join(", ", self_));}
        
        /// @brief Gets the value associated with the specified key.
        /// @param key The key of the value to get.
        /// @param value When this method returns, contains the value associated with the specified key, if the key is found; otherwise, the default value for the type of the value parameter.
        /// @return `true` if the xtd::collections::generic::dictionary <key_t, value_t> contains an element with the specified key; otherwise, `false`.
        bool try_get_value(const key_t & key, value_t& value) const override {
          auto ptr = &value;
          auto result = data_->dictionary_items.try_get_value(key, ptr);
          if (result) value = *ptr;
          return result;
        }
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Move assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        ordered_dictionary& operator =(ordered_dictionary&& other) noexcept {
          data_->list_items = std::move(other.data_->list_items);
          data_->dictionary_items = std::move(other.data_->dictionary_items);
          data_->version = std::move(other.data_->version);
          return self_;
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        ordered_dictionary& operator =(const ordered_dictionary & other) noexcept = default;
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        ordered_dictionary& operator =(std::initializer_list<base_value_type> ilist) {
          clear();
          for (const auto& [key, value] : ilist)
            add(key, value);
          return self_;
        }
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of `other`.
        /// @param ilist The initializer list to use as data source.
        /// @return This current instance.
        template < class init_key_t, class init_value_t >
        ordered_dictionary& operator =(std::initializer_list<key_value_pair<init_key_t, init_value_t>> ilist) {
          clear();
          for (const auto& [key, value] : ilist)
            add(key, value);
          return self_;
        }
        
        const value_t& operator [](const key_t & key) const override {
          return *data_->dictionary_items[key];
        }
        
        value_t& operator [](const key_t & key) override {
          if (!data_->dictionary_items.contains_key(key))
            add(key, value_t {});
          return *data_->dictionary_items[key];
        }
        
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const base_type &() const noexcept {return data_->list_items;}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator base_type &() noexcept {return data_->list_items;}
        /// @}
        
      private:
        xtd::size get_index(const key_t & key) const noexcept {
          auto index = xtd::size {0};
          for (const auto& [item_key, item_value] : self_) {
            if (item_key == key) return index;
            ++index;
          }
          return xtd::npos;
        }
        
        xtd::size get_index(const value_type & value) const noexcept {
          auto index = xtd::size {0};
          for (const auto& item : self_) {
            if (item == value) return index;
            ++index;
          }
          return xtd::npos;
        }
        
        bool is_read_only() const noexcept override {return false;}
        bool is_synchronized() const noexcept override {return false;}
        const xtd::object & sync_root() const noexcept override {return data_->sync_root;}
        
        struct dictionary_data {
          dictionary_data() noexcept = default;
          dictionary_data(const base_type & items, size_type version) noexcept : list_items {size_type {}}, version {version} {
            for (const auto& item : items) {
              this->list_items.add(item);
              this->dictionary_items.add(this->list_items[this->list_items.count() - 1].first, &this->list_items[this->list_items.count() - 1].second);
            }
          }
          dictionary_data(base_type&& items, size_type version) noexcept : list_items {size_type {}}, version {version} {
            for (auto&& item : items) {
              this->list_items.add(item);
              this->dictionary_items.add(this->list_items[this->list_items.count() - 1].first, &this->list_items[this->list_items.count() - 1].second);
            }
          }
          
          base_type list_items;
          dictionary_type dictionary_items;
          size_type version = 0;
          xtd::object sync_root;
          xtd::object sync_op;
        };
        xtd::ptr<dictionary_data> data_ = xtd::new_ptr<dictionary_data>();
      };
      
      /// @cond
      // C++17 deduction guides for xtd::collections::specialized::ordered_dictionary
      // {
      template < class key_t, class value_t >
      ordered_dictionary(xtd::collections::generic::idictionary<key_t, value_t >) -> ordered_dictionary<key_t, value_t, xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t>>>;
      
      template < class key_t, class value_t >
      ordered_dictionary(xtd::collections::generic::ienumerable<key_value_pair<key_t, value_t>>) -> ordered_dictionary<key_t, value_t, xtd::collections::generic::helpers::allocator<std::pair<const key_t, value_t >>>;
      
      template < class key_t, class value_t >
      ordered_dictionary(std::initializer_list<key_value_pair<key_t, value_t>>) -> ordered_dictionary<key_t, value_t>;
      
      template < class key_t, class value_t >
      ordered_dictionary(std::initializer_list<std::pair<key_t, value_t>>) -> ordered_dictionary <key_t, value_t>;
      
      template < class input_iterator_t >
      ordered_dictionary(input_iterator_t, input_iterator_t) -> ordered_dictionary < xtd::collections::generic::helpers::iterator_key_t < input_iterator_t>, xtd::collections::generic::helpers::iterator_mapped_t<input_iterator_t >>;
      // }
      /// @endcond
    }
  }
}
