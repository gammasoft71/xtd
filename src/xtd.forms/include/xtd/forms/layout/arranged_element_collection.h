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
        class item_t : public type_t {
        public:
          item_t() = default;
          item_t(const item_t&) = default;
          item_t(item_t&&) = default;
          template <typename ...args_t>
          item_t(args_t&& ...args) : type_t(args...) {}

          item_t& operator=(const item_t& value) {
            if (value.parent) parent = value.parent;
            if (parent != nullptr && !parent->inserting_ && !parent->erasing_) parent->item_updated(pos, static_cast<type_t&>(const_cast<item_t&>(value)));
            type_t::operator=(value);
            return *this;
          }
          
          item_t& operator=(item_t&& value) {
            if (value.parent) parent = value.parent;
            if (parent != nullptr && !parent->inserting_ && !parent->erasing_) parent->item_updated(pos, static_cast<type_t&>(value));
            type_t::operator=(value);
            return *this;
          }

          operator type_t() {return *this;}
          
          friend std::ostream& operator<<(std::ostream& os, const item_t& value) {return os << static_cast<const type_t&>(value);}
          
        private:
          friend class arranged_element_collection;
          size_t pos = std::numeric_limits<size_t>::max();
          arranged_element_collection* parent = nullptr;
        };
        
        /// @brief Represents the value type of the collection.
        using value_type = item_t;
        /// @brief Represents the allocator type of the collection.
        using allocator_type = std::allocator<value_type>;
        /// @brief Represents the size type of the collection.
        using size_type = size_t;
        /// @brief Represents the pointer difference type of the collection.
        using difference_type = ptrdiff_t;
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
        
        allocator_type get_allocator() const {return collection_.get_allocator();}
        
        reference at(size_type pos) {
          collection_[pos].pos = pos;
          collection_[pos].parent = this;
          return collection_.at(pos);
        }
        const_reference at(size_type pos) const {return collection_.at(pos);}
       
        reference front() {return collection_.front();}
        const_reference front() const {return collection_.front();}
       
        reference back() {return collection_.back();}
        const_reference back() const {return collection_.back();}
    
        value_type* data() {return collection_.data();}
        const value_type* data() const {return collection_.data();}
        
        reference operator[](size_type pos) {
          collection_[pos].pos = pos;
          collection_[pos].parent = this;
          return collection_[pos];
        }
        const_reference operator[](size_type pos) const {return collection_[pos];}
        
        iterator begin() {return collection_.begin();}
        const_iterator begin() const {return collection_.begin();}
        const_iterator cbegin() const {return collection_.cbegin();}
        
        iterator end() {return collection_.end();}
        const_iterator end() const {return collection_.end();}
        const_iterator cend() const {return collection_.cend();}
        
        reverse_iterator rbegin() {return collection_.rbegin();}
        const_reverse_iterator rbegin() const {return collection_.rbegin();}
        const_reverse_iterator crbegin() const {return collection_.crbegin();}

        reverse_iterator rend() {return collection_.rend();}
        const_reverse_iterator rend() const {return collection_.rend();}
        const_reverse_iterator crend() const {return collection_.crend();}
        
        bool empty() const {return collection_.empty();}
        
        size_type size() const {return collection_.size();}
        
        size_type max_size() const {return collection_.max_size();}
        
        void reserve(size_type size) {collection_.reserve(size);}
        
        size_type capacity() const {return collection_.capacity();}
        
        void shrink_to_fit() {collection_.shrink_to_fit();}
        
        bool sorted() const {return sorted_;}
        void sorted(bool value) {
          if (sorted_ != value) {
            sorted_ = value;
            if (sorted_) sort();
          }
        }
        
        void clear() {
          iterator it = begin();
          while (it != end())
            it = erase(it);
        }

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

        void insert_at(size_t index, const value_type& value) {
          if (index > size()) throw argument_out_of_range_exception(current_stack_frame_);
          insert(begin() + index, value);
        }

        iterator erase(iterator pos) {
          item_erased(pos - begin(), *pos);
          erasing_ = true;
          iterator result = collection_.erase(pos);
          erasing_ = false;
          return result;
        }
        
        iterator erase(const_iterator pos) {
          item_erased(pos - begin(), *pos);
          erasing_ = true;
          iterator result = collection_.erase(pos);
          erasing_ = false;
          return result;
        }
        
        iterator erase(iterator first, iterator last) {
          iterator result = end();
          for (iterator it = first; it <= last; it++)
            result = erase(it);
          return result;
        }
        
        iterator erase(const_iterator first, const_iterator last) {
          iterator result = this->bend();
          for (const_iterator it = first; it <= last; it++)
            result = erase(it);
          return result;
        }
        
        void erase_at(size_t index) {
          if (index > size()) throw argument_out_of_range_exception(current_stack_frame_);
          erase(begin() + index);
        }

        void push_back(const value_type& item) {
          collection_.push_back(item);
          size_t index = collection_.size() - 1;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          item_added(index, collection_[index]);
          if (sorted_) sort();
        }
        
        void push_back(value_type&& item) {
          collection_.push_back(item);
          size_t index = collection_.size() - 1;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          item_added(index, collection_[index]);
          if (sorted_) sort();
        }
        
        void push_back_range(const arranged_element_collection& collection) {
          for(value_type item : collection)
            push_back(item);
        }
        
        void push_back_range(const std::vector<value_type>& collection) {
          for(value_type item : collection)
            push_back(item);
        }

        void push_back_range(const std::initializer_list<value_type>& collection) {
          for(value_type item : collection)
            push_back(item);
        }
        
        template<typename collection_t>
        void push_back_range(collection_t collection) {
          for(const auto& item : collection)
            push_back(value_type(item));
        }

        void sort() {
          //std::sort(begin(), end());
          sorter_t sorter;
          sorter(begin(), end());
        }

        std::vector<type_t> to_array() const {
          std::vector<type_t> array;
          for (auto item : collection_)
            array.push_back(item);
          return array;
        }
        
        std::vector<type_t> to_vector() const {return to_array();}

        /// @brief This is a special value equal to the maximum value representable by the type size_t.
        static const size_t npos = std::numeric_limits<size_t>::max();

      private:
        std::vector<value_type, allocator_type> collection_;
        bool inserting_ = false;
        bool erasing_ = false;
        bool sorted_ = false;
      };
    }
  }
}
