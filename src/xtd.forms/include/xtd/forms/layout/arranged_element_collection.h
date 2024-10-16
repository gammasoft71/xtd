/// @file
/// @brief Contains xtd::forms::layout::arranged_element_collection collection.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once

#include "sorter_none.h"
#include <xtd/argument_out_of_range_exception>
#include <xtd/event_args>
#include <xtd/event_handler>
#include <xtd/event>
#include <xtd/object>
#include <xtd/size_object>
#include <ostream>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::layout namespace contains classes for implementing layout behaviors in your form or control.
    namespace layout {
      /// @brief Represents a collection of objects.
      /// @par Header
      /// ```cpp
      /// #include <xtd/forms/layout/arranged_element_collection> 
      /// ```
      /// @par Namespace
      /// xtd::forms::layout
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms collections
      /// @remarks The xtd::forms::layout::arranged_element_collection class represents a collection of objects arranged on a design surface or inside a parent xtd.forms::container_control.
      template<typename type_t, typename sorter_t = sorter_none>
      class arranged_element_collection : public object {
      public:
        /// @brief Represents the value type of the collection.
        class value_type : public type_t {
        public:
          /// @cond
          value_type() = default;
          value_type(const value_type&) = default;
          value_type(value_type&&) = default;
          template <typename ...args_t>
          value_type(args_t&& ...args) : type_t(args...) {}
          value_type& operator =(const value_type& value) {
            if (value.owner) owner = value.owner;
            if (owner != nullptr && !owner->inserting_ && !owner->erasing_) owner->on_item_updated(pos, static_cast<type_t&>(const_cast<value_type&>(value)));
            type_t::operator =(value);
            return *this;
          }
          value_type& operator =(value_type&& value) {
            if (value.owner) owner = value.owner;
            if (owner != nullptr && !owner->inserting_ && !owner->erasing_) owner->on_item_updated(pos, static_cast<type_t&>(value));
            type_t::operator =(value);
            return *this;
          }
          operator type_t() {return *this;}
          friend std::ostream& operator <<(std::ostream& os, const value_type& value) {return os << static_cast<const type_t&>(value);}
          /// @endcond
          
        private:
          friend class arranged_element_collection;
          size_t pos = size_object::max_value;
          arranged_element_collection* owner = nullptr;
        };
        
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the allocator type of the collection.
        using allocator_type = std::allocator<value_type>;
        /// @brief Represents the size type of the collection.
        using size_type = std::size_t;
        /// @brief Represents the pointer difference type of the collection.
        using difference_type = std::ptrdiff_t;
        /// @brief Represents the value type reference of the collection.
        using reference = value_type&;
        /// @brief Represents the value type const reference the collection.
        using const_reference = const value_type&;
        /// @brief Represents the value type pointer of the collection.
        using pointer = typename std::allocator_traits<allocator_type>::pointer;
        /// @brief Represents the value type const pointer of the collection.
        using const_pointer = typename std::allocator_traits<allocator_type>::const_pointer;
        /// @brief Represents the iterator type of the collection.
        using iterator = typename std::vector<value_type>::iterator;
        /// @brief Represents the const iterator type of the collection.
        using const_iterator = typename std::vector<value_type>::const_iterator;
        /// @brief Represents the reverse iterator type of the collection.
        using reverse_iterator = typename std::vector<value_type>::reverse_iterator;
        /// @brief Represents the const reverse iterator type of the collection.
        using const_reverse_iterator = typename std::vector<value_type>::const_reverse_iterator;
        /// @}
        
        /// @name Public Fields
        
        /// @{
        /// @brief This is a special value equal to the maximum value representable by the type size_t.
        inline static constexpr xtd::size npos = xtd::size_object::max_value;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Creates a new object xtd::forms::layout::arranged_element_collection with specified allocator (optional).
        /// @param allocator The allocator associate to the collection (optional).
        /// @remarks If allocator not specified, the std::allocator<value_type> is used.
        explicit arranged_element_collection(const allocator_type& allocator = allocator_type()) : collection_(allocator) {}
        /// @brief Creates a new object xtd::diagnostics::trace_listener_collection with specified initializer list.
        /// @param il The initializer list that contains items to fill the collection.
        arranged_element_collection(const std::initializer_list<type_t>& il) {
          for (auto item : il)
            push_back(item);
        }
        /// @}
        
        /// @cond
        explicit arranged_element_collection(const std::vector<type_t>& collection) {
          for (auto item : collection)
            push_back(item);
        }
        arranged_element_collection(const arranged_element_collection& collection) {push_back_range(collection);}
        arranged_element_collection& operator =(const arranged_element_collection& collection) {
          clear();
          push_back_range(collection);
          return *this;
        }
        arranged_element_collection(arranged_element_collection&&) = default;
        bool operator ==(const arranged_element_collection& value) const {return collection_ == value.collection_;}
        bool operator !=(const arranged_element_collection& value) const {return !operator ==(value);}
        /// @endcond
        
        /// @name Public Methods
        
        /// @{
        /// @brief Returns the associated allocator
        /// @return The associate allocator.
        allocator_type get_allocator() const noexcept {return collection_.get_allocator();}
        
        /// @brief Access specified element with bounds checking.
        /// @param pos The position of the element to return.
        /// @exception std::out_of_range pos is greater than arranged_element_collection::size.
        reference at(size_type pos) {
          collection_[pos].pos = pos;
          collection_[pos].owner = this;
          return collection_.at(pos);
        }
        /// @brief Access specified element with bounds checking.
        /// @param pos The position of the element to return.
        /// @exception std::out_of_range pos is greater than arranged_element_collection::size.
        const_reference at(size_type pos) const {return collection_.at(pos);}
        
        /// @brief Access the first element.
        /// @return The first element.
        reference front() {return collection_.front();}
        /// @brief Access the first element.
        /// @return The first element.
        const_reference front() const {return collection_.front();}
        
        /// @brief Access the last element.
        /// @return The last element.
        reference back() {return collection_.back();}
        /// @brief Access the last element.
        /// @return The last element.
        const_reference back() const {return collection_.back();}
        
        /// @brief Direct access to the underlying array.
        /// @return The underlying array.
        pointer data() {return collection_.data();}
        /// @brief Direct access to the underlying array.
        /// @return The underlying array.
        const_pointer data() const {return collection_.data();}
        
        /// @brief Returns an iterator to the beginning.
        /// @return The iterator to the beginning.
        iterator begin() noexcept {return collection_.begin();}
        /// @brief Returns an iterator to the beginning.
        /// @return The iterator to the beginning.
        const_iterator begin() const noexcept {return collection_.begin();}
        /// @brief Returns an iterator to the beginning.
        /// @return The iterator to the beginning.
        const_iterator cbegin() const noexcept {return collection_.cbegin();}
        
        /// @brief Returns an iterator to the end.
        /// @return The iterator to the end.
        iterator end() noexcept {return collection_.end();}
        /// @brief Returns an iterator to the end.
        /// @return The iterator to the end.
        const_iterator end() const noexcept {return collection_.end();}
        /// @brief Returns an iterator to the end.
        /// @return The iterator to the end.
        const_iterator cend() const noexcept {return collection_.cend();}
        
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        reverse_iterator rbegin() noexcept {return collection_.rbegin();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        const_reverse_iterator rbegin() const noexcept {return collection_.rbegin();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        const_reverse_iterator crbegin() const noexcept {return collection_.crbegin();}
        
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        reverse_iterator rend() noexcept {return collection_.rend();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        const_reverse_iterator rend() const noexcept {return collection_.rend();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        const_reverse_iterator crend() const noexcept {return collection_.crend();}
        
        /// @brief Checks whether the container is empty.
        /// @return true if container is empty; otherwise false.
        bool empty() const noexcept {return collection_.empty();}
        
        /// @brief Returns the number of elements.
        /// @return The number of elements.
        size_type size() const noexcept {return collection_.size();}
        
        /// @brief Returns the maximum possible number of elements.
        /// @return The maximum possible number of elements.
        size_type max_size() const noexcept {return collection_.max_size();}
        
        /// @brief Reserves storage.
        void reserve(size_type size) {collection_.reserve(size);}
        
        /// @brief Returns the number of elements that can be held in currently allocated storage.
        /// @return The number of elements that can be held in currently allocated storage.
        size_type capacity() const noexcept {return collection_.capacity();}
        
        /// @brief Reduces memory usage by freeing unused memory.
        void shrink_to_fit() {collection_.shrink_to_fit();}
        
        /// @brief Checks whether the container is sorted.
        /// @return true if container is sorted; otherwise false.
        virtual bool sorted() const noexcept {return sorted_;}
        /// @brief Sets the container is sorted.
        /// @param value true if container is sorted; otherwise false.
        virtual void sorted(bool value) {
          if (sorted_ != value) {
            sorted_ = value;
            if (sorted_) sort();
          }
        }
        
        /// @brief clears the contents.
        virtual void clear() noexcept {
          iterator it = begin();
          while (it != end())
            it = erase(it);
        }
        
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param value The element to insert.
        virtual iterator insert(const_iterator pos, const value_type& value) {
          size_t index = pos - begin();
          inserting_ = true;
          iterator result = collection_.insert(pos, value);
          inserting_ = false;
          (*this)[index].owner = this;
          (*this)[index].pos = index;
          on_item_added(index, collection_[index]);
          if (sorted_) sort();
          return result;
        }
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param value The element to insert.
        virtual iterator insert(const_iterator pos, value_type&& value) {
          size_t index = pos - begin();
          inserting_ = true;
          iterator result = collection_.insert(pos, value);
          inserting_ = false;
          (*this)[index].owner = this;
          (*this)[index].pos = index;
          on_item_added(index, collection_[index]);
          if (sorted_) sort();
          return result;
        }
        
        /// @brief Inserts specified element at specified index.
        /// @param index The index before which the content will be inserted.
        /// @param value The element to insert.
        virtual void insert_at(size_t index, const value_type& value) {
          if (index > size()) throw argument_out_of_range_exception {};
          insert(begin() + index, value);
        }
        
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param args The arguments to forward to the constructor of the element
        template<typename ...args_t>
        void emplace(const_iterator pos, args_t&& ... args) {
          size_t index = pos - begin();
          inserting_ = true;
          iterator result = collection_.insert(pos, args...);
          inserting_ = false;
          (*this)[index].owner = this;
          (*this)[index].pos = index;
          on_item_added(index, collection_[index]);
          if (sorted_) sort();
          return result;
        }
        
        /// @brief Adds an element to the end.
        /// @param args The arguments to forward to the constructor of the element
        template<typename ...args_t>
        void emplace_back(args_t&& ... args) {
          collection_.push_back(args...);
          size_t index = collection_.size() - 1;
          (*this)[index].owner = this;
          (*this)[index].pos = index;
          on_item_added(index, collection_[index]);
          if (sorted_) sort();
        }
        
        /// @brief Erases element at specified position.
        /// @param pos The iterator which the content will be erased.
        virtual iterator erase(iterator pos) {
          on_item_removed(pos - begin(), *pos);
          erasing_ = true;
          iterator result = collection_.erase(pos);
          erasing_ = false;
          return result;
        }
        /// @brief Erases element at specified position.
        /// @param pos The iterator which the content will be erased.
        virtual iterator erase(const_iterator pos) {
          on_item_removed(pos - begin(), *reinterpret_cast<iterator&>(pos));
          erasing_ = true;
          iterator result = collection_.erase(pos);
          erasing_ = false;
          return result;
        }
        
        /// @brief Erases elements at specified range.
        /// @param first The first iterator range which the content will be erased.
        /// @param first The last iterator range which the content will be erased.
        virtual iterator erase(iterator first, iterator last) {
          iterator result = end();
          for (iterator it = first; it <= last; ++it)
            result = erase(it);
          return result;
        }
        /// @brief Erases elements at specified range.
        /// @param first The first iterator range which the content will be erased.
        /// @param first The last iterator range which the content will be erased.
        virtual iterator erase(const_iterator first, const_iterator last) {
          iterator result = end();
          for (const_iterator it = first; it <= last; ++it)
            result = erase(it);
          return result;
        }
        
        /// @brief Erases element at specified index.
        /// @param pos The index which the content will be erased.
        virtual void erase_at(size_t index) {
          if (index > size()) throw argument_out_of_range_exception {};
          erase(begin() + index);
        }
        
        /// @brief Removes the last element of the container.
        virtual void pop_back() {
          if (size() != 0) erase_at(size() - 1);
        }
        
        /// @brief Adds an element to the end.
        /// @param item The element to add.
        virtual void push_back(const value_type& item) {
          collection_.push_back(item);
          size_t index = collection_.size() - 1;
          (*this)[index].owner = this;
          (*this)[index].pos = index;
          on_item_added(index, collection_[index]);
          if (sorted_) sort();
        }
        /// @brief Adds an element to the end.
        /// @param item The element to add.
        virtual void push_back(value_type&& item) {
          collection_.push_back(item);
          size_t index = collection_.size() - 1;
          (*this)[index].owner = this;
          (*this)[index].pos = index;
          on_item_added(index, collection_[index]);
          if (sorted_) sort();
        }
        
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        virtual void push_back_range(const arranged_element_collection& collection) {
          for (value_type item : collection)
            push_back(item);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        virtual void push_back_range(const std::vector<value_type>& collection) {
          for (value_type item : collection)
            push_back(item);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        virtual void push_back_range(const std::initializer_list<value_type>& collection) {
          for (value_type item : collection)
            push_back(item);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        template<typename collection_t>
        void push_back_range(collection_t&& collection) {
          for (auto& item : collection)
            push_back(value_type(item));
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        template<typename iterator_t>
        void push_back_range(iterator_t begin, iterator_t end) {
          for (auto it = begin; it != end; ++it)
            push_back(value_type(*it));
        }
        
        /// @brief Sorts the content.
        virtual void sort() {
          sorter_t sorter;
          sorter(begin(), end());
        }
        
        /// @brief Gets an array with the elements of the container.
        /// @return The array that contains elements of the container.
        std::vector<type_t> to_array() const noexcept {
          std::vector<type_t> array;
          std::for_each(collection_.begin(), collection_.end(), [&](auto item) {array.push_back(item);});
          return array;
        }
        
        /// @brief Gets an array with the elements of the container.
        /// @return The array that contains elements of the container.
        std::vector<type_t> to_vector() const noexcept {return to_array();}
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Access specified element.
        /// @return The requested element.
        reference operator [](size_type pos) {
          collection_[pos].pos = pos;
          collection_[pos].owner = this;
          return collection_[pos];
        }
        /// @brief Access specified element.
        /// @return The requested element.
        const_reference operator [](size_type pos) const {
          collection_[pos].pos = pos;
          collection_[pos].owner = const_cast<arranged_element_collection*>(this);
          return collection_[pos];
        }
        /// @}
        
        /// @name Public Events
        
        /// @{
        /// @brief Occurs when an item is added to the collection.
        /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
        event<arranged_element_collection, delegate<void(size_t, type_t& item)>> item_added;
        
        /// @brief Occurs when an item is updated in the collection.
        /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
        event<arranged_element_collection, delegate<void(size_t, type_t& item)>> item_updated;
        
        /// @brief Occurs when an item is removed from the collection.
        /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Events/overview).
        event<arranged_element_collection, delegate<void(size_t, type_t& item)>> item_removed;
        /// @}
        
        /// @name Protected Methods
        
        /// @{
        /// @brief Raises the xtd::forms::layout::arranged_element_collection::item_added event.
        /// @param index The index of the item.
        /// @param item The item added.
        virtual void on_item_added(size_t index, type_t& item) {
          item_added(index, item);
        }

        /// @brief Raises the xtd::forms::layout::arranged_element_collection::item_updated event.
        /// @param index The index of the item.
        /// @param item The item updated.
        virtual void on_item_updated(size_t index, type_t& item) {
          item_updated(index, item);
        }

        /// @brief Raises the xtd::forms::layout::arranged_element_collection::item_removed event.
        /// @param index The index of the item.
        /// @param item The item removed.
        virtual void on_item_removed(size_t index, type_t& item) {
          item_removed(index, item);
        }
        /// @}

      private:
        mutable std::vector<value_type, allocator_type> collection_;
        bool inserting_ = false;
        bool erasing_ = false;
        bool sorted_ = false;
      };
    }
  }
}
