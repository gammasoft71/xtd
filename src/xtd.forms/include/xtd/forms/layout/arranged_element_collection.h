/// @file
/// @brief Contains xtd::forms::arranged_element_collection collection.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <limits>
#include <ostream>
#include <vector>
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/event_args.h>
#include <xtd/event_handler.h>
#include <xtd/event.h>
#include "sorter_none.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::layout namespace contains classes for implementing layout behaviors in your form or control.
    namespace layout {
      /// @brief Represents a collection of objects.
      /// @par Library
      /// xtd.forms
      /// @ingroup xtd_forms
      /// @remarks The xtd::forms::layout::arranged_element_collection class represents a collection of objects arranged on a design surface or inside a parent xtd.forms::container_control.
      template<typename type_t, typename sorter_t = sorter_none>
      class arranged_element_collection {
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
          value_type& operator=(const value_type& value) {
            if (value.parent) parent = value.parent;
            if (parent != nullptr && !parent->inserting_ && !parent->erasing_) parent->item_updated(pos, static_cast<type_t&>(const_cast<value_type&>(value)));
            type_t::operator=(value);
            return *this;
          }
          value_type& operator=(value_type&& value) {
            if (value.parent) parent = value.parent;
            if (parent != nullptr && !parent->inserting_ && !parent->erasing_) parent->item_updated(pos, static_cast<type_t&>(value));
            type_t::operator=(value);
            return *this;
          }
          operator type_t() {return *this;}
          friend std::ostream& operator<<(std::ostream& os, const value_type& value) {return os << static_cast<const type_t&>(value);}
          /// @endcond
                    
        private:
          friend class arranged_element_collection;
          size_t pos = std::numeric_limits<size_t>::max();
          arranged_element_collection* parent = nullptr;
        };
        
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
        /// @brief Represents the reverse iterrator type of the collection.
        using reverse_iterator = typename std::vector<value_type>::reverse_iterator;
        /// @brief Represents the constt reverse iterator type of the collection.
        using const_reverse_iterator = typename std::vector<value_type>::const_reverse_iterator;
        
        /// @brief Creates a new object xtd::forms::layout::arranged_element_collection with specified allocator (optional).
        /// @param allocator The allocator associate to the collection (optional).
        /// @remarks If allocator not specified, the std::allocator<vallue_type> is used.
        explicit arranged_element_collection(const allocator_type& allocator = allocator_type()) : collection_(allocator) {}        
        /// @brief Creates a new object xtd::diagnostics::trace_listener_collection with specified initializer list.
        /// @param il The initializer list that contains items to fill the collection.
        arranged_element_collection(const std::initializer_list<type_t>& il) {
          for (auto item : il)
            push_back(item);
        }

        /// @cond
        arranged_element_collection(const std::vector<type_t>& collection) {
          for (auto item : collection)
            push_back(item);
        }
        arranged_element_collection(const arranged_element_collection& collection) {push_back_range(collection);}
        arranged_element_collection& operator=(const arranged_element_collection& collection) {
          clear();
          push_back_range(collection);
          return *this;
        }
        arranged_element_collection(arranged_element_collection&&) = default;
        bool operator==(const arranged_element_collection& value) const {return collection_ == value.collection_;}
        bool operator!=(const arranged_element_collection& value) const {return !operator==(value);}
        /// @endcond
        
        /// @brief Occurs when an item is added to the collection.
        event<arranged_element_collection, delegate<void(size_t, type_t& item)>> item_added;

        /// @brief Occurs when an item is updated in the collection.
        event<arranged_element_collection, delegate<void(size_t, type_t& item)>> item_updated;

        /// @brief Occurs when an item is erased from the collection.
        event<arranged_element_collection, delegate<void(size_t, type_t& item)>> item_erased;
        
        /// @brief Returns the associated allocator
        /// @return The associate allocator.
        allocator_type get_allocator() const {return collection_.get_allocator();}
        
        /// @brief Access specified element with bounds checking.
        /// @param pos The position of the element to return.
        /// @exception std::out_of_range pos is greather than arranged_element_collection::size.
        reference at(size_type pos) {
          collection_[pos].pos = pos;
          collection_[pos].parent = this;
          return collection_.at(pos);
        }
        /// @brief Access specified element with bounds checking.
        /// @param pos The position of the element to return.
        /// @exception std::out_of_range pos is greather than arranged_element_collection::size.
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
        
        /// @brief Access specified element.
        /// @return The requested element.
        reference operator[](size_type pos) {
          collection_[pos].pos = pos;
          collection_[pos].parent = this;
          return collection_[pos];
        }
        /// @brief Access specified element.
        /// @return The requested element.
        const_reference operator[](size_type pos) const {return collection_[pos];}
        
        /// @brief Returns an iterator to the beginning.
        /// @return The iterator to the begining.
        iterator begin() {return collection_.begin();}
        /// @brief Returns an iterator to the beginning.
        /// @return The iterator to the begining.
        const_iterator begin() const {return collection_.begin();}
        /// @brief Returns an iterator to the beginning.
        /// @return The iterator to the begining.
        const_iterator cbegin() const {return collection_.cbegin();}
        
        /// @brief Returns an iterator to the end.
        /// @return The iterator to the end.
        iterator end() {return collection_.end();}
        /// @brief Returns an iterator to the end.
        /// @return The iterator to the end.
        const_iterator end() const {return collection_.end();}
        /// @brief Returns an iterator to the end.
        /// @return The iterator to the end.
        const_iterator cend() const {return collection_.cend();}
        
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        reverse_iterator rbegin() {return collection_.rbegin();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        const_reverse_iterator rbegin() const {return collection_.rbegin();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        const_reverse_iterator crbegin() const {return collection_.crbegin();}

        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        reverse_iterator rend() {return collection_.rend();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        const_reverse_iterator rend() const {return collection_.rend();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        const_reverse_iterator crend() const {return collection_.crend();}
        
        /// @brief Checks whether the container is empty.
        /// @return true if container is empty; otherwise false.
        bool empty() const {return collection_.empty();}
        
        /// @brief Returns the number of elements.
        /// @return The number of elements.
        size_type size() const {return collection_.size();}
        
        /// @brief Returns the maximum possible number of elements.
        /// @return The maximum possible number of elements.
        size_type max_size() const {return collection_.max_size();}
        
        /// @brief Reserves storage.
        void reserve(size_type size) {collection_.reserve(size);}
        
        /// @brief Returns the number of elements that can be held in currently allocated storage.
        /// @return The number of elements that can be held in currently allocated storage.
        size_type capacity() const {return collection_.capacity();}
        
        /// @brief Reduces memory usage by freeing unused memory.
        void shrink_to_fit() {collection_.shrink_to_fit();}
        
        /// @brief Checks whether the container is sorted.
        /// @return true if container is sorted; otherwise false.
        bool sorted() const {return sorted_;}
        /// @brief Sets the container is sorted.
        /// @param value true if container is sorted; otherwise false.
        void sorted(bool value) {
          if (sorted_ != value) {
            sorted_ = value;
            if (sorted_) sort();
          }
        }
        
        /// @brief clears the contents.
        void clear() {
          iterator it = begin();
          while (it != end())
            it = erase(it);
        }

        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param value The element to insert.
        iterator insert(iterator pos, const value_type& value) {
          size_t index = pos - begin();
          inserting_ = true;
          iterator result = collection_.insert(pos, value);
          inserting_ = false;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          item_added(index, collection_[index]);
          if (sorted_) sort();
          return result;
        }
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param value The element to insert.
        iterator insert(const_iterator pos, const value_type& value) {
          size_t index = pos - begin();
          inserting_ = true;
          iterator result = collection_.insert(pos, value);
          inserting_ = false;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          item_added(index, collection_[index]);
          if (sorted_) sort();
          return result;
        }
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param value The element to insert.
        iterator insert(const_iterator pos, const value_type&& value) {
          size_t index = pos - begin();
          inserting_ = true;
          iterator result = collection_.insert(pos, value);
          inserting_ = false;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          item_added(index, collection_[index]);
          if (sorted_) sort();
          return result;
        }

        /// @brief Inserts specified element at specified index.
        /// @param pos The index before which the content will be inserted.
        /// @param value The element to insert.
        void insert_at(size_t index, const value_type& value) {
          if (index > size()) throw argument_out_of_range_exception(current_stack_frame_);
          insert(begin() + index, value);
        }

        /// @brief Erases element at specified position.
        /// @param pos The iterator which the content will be erased.
        iterator erase(iterator pos) {
          item_erased(pos - begin(), *pos);
          erasing_ = true;
          iterator result = collection_.erase(pos);
          erasing_ = false;
          return result;
        }
        /// @brief Erases element at specified position.
        /// @param pos The iterator which the content will be erased.
         iterator erase(const_iterator pos) {
          item_erased(pos - begin(), *pos);
          erasing_ = true;
          iterator result = collection_.erase(pos);
          erasing_ = false;
          return result;
        }
        
        /// @brief Erases elements at specified range.
        /// @param first The first iterator range which the content will be erased.
        /// @param first The llast iterator range which the content will be erased.
        iterator erase(iterator first, iterator last) {
          iterator result = end();
          for (iterator it = first; it <= last; it++)
            result = erase(it);
          return result;
        }
        /// @brief Erases elements at specified range.
        /// @param first The first iterator range which the content will be erased.
        /// @param first The llast iterator range which the content will be erased.
        iterator erase(const_iterator first, const_iterator last) {
          iterator result = this->bend();
          for (const_iterator it = first; it <= last; it++)
            result = erase(it);
          return result;
        }
        
        /// @brief Erases element at specified index.
        /// @param pos The index which the content will be erased.
        void erase_at(size_t index) {
          if (index > size()) throw argument_out_of_range_exception(current_stack_frame_);
          erase(begin() + index);
        }

        /// @brief Adds an element to the end.
        /// @param item The element to add.
        void push_back(const value_type& item) {
          collection_.push_back(item);
          size_t index = collection_.size() - 1;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          item_added(index, collection_[index]);
          if (sorted_) sort();
        }
        /// @brief Adds an element to the end.
        /// @param item The element to add.
        void push_back(value_type&& item) {
          collection_.push_back(item);
          size_t index = collection_.size() - 1;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          item_added(index, collection_[index]);
          if (sorted_) sort();
        }
        
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        void push_back_range(const arranged_element_collection& collection) {
          for(value_type item : collection)
            push_back(item);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        void push_back_range(const std::vector<value_type>& collection) {
          for(value_type item : collection)
            push_back(item);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        void push_back_range(const std::initializer_list<value_type>& collection) {
          for(value_type item : collection)
            push_back(item);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        template<typename collection_t>
        void push_back_range(collection_t collection) {
          for(const auto& item : collection)
            push_back(value_type(item));
        }

        /// @brief Sorts the content.
        void sort() {
          sorter_t sorter;
          sorter(begin(), end());
        }

        /// @brief Gets an arrray with the elements of the container.
        /// @return The array that contains elements of the container.
        std::vector<type_t> to_array() const {
          std::vector<type_t> array;
          for (auto item : collection_)
            array.push_back(item);
          return array;
        }
        
        /// @brief Gets an arrray with the elements of the container.
        /// @return The array that contains elements of the container.
        std::vector<type_t> to_vector() const {return to_array();}

        /// @brief This is a special value equal to the maximum value representable by the type size_t.
        static const size_type npos = std::numeric_limits<size_type>::max();

      private:
        std::vector<value_type, allocator_type> collection_;
        bool inserting_ = false;
        bool erasing_ = false;
        bool sorted_ = false;
      };
    }
  }
}
