#pragma once
#include <ostream>
#include <vector>
#include <xtd/event_args.h>
#include <xtd/event_handler.h>
#include <xtd/event.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::layout namespace contains classes for implementing layout behaviors in your form or control.
    namespace layout {
      class sorter_none {
      public:
        template<typename type_t>
        void operator()(type_t first, type_t last) {}
      };
  
      /// @brief Represents a collection of objects.
      /// @remarks The arranged_element_collection class represents a collection of objects arranged on a design surface or inside a parent xtd.forms::container_control.
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
            this->type_t::operator=(value);
            return *this;
          }
          
          item_t& operator=(item_t&& value) {
            if (value.parent) parent = value.parent;
            if (parent != nullptr && !parent->inserting_ && !parent->erasing_) parent->item_updated(pos, static_cast<type_t&>(value));
            this->type_t::operator=(value);
            return *this;
          }

          operator type_t() {return *this;}
          
          friend std::ostream& operator<<(std::ostream& os, const item_t& value) {return os << static_cast<const type_t&>(value);}
          
          size_t pos = -1;
          arranged_element_collection* parent = nullptr;
        };
        
        /// @brief @member types
        /// @{
        using value_type = item_t;
        using allocator_type = std::allocator<item_t>;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = typename std::allocator_traits<allocator_type>::pointer;
        using const_pointer = typename std::allocator_traits<allocator_type>::const_pointer;
        using iterator = typename std::vector<value_type>::iterator;
        using const_iterator = typename std::vector<value_type>::const_iterator;
        using reverse_iterator = typename std::vector<value_type>::reverse_iterator;
        using const_reverse_iterator = typename std::vector<value_type>::const_reverse_iterator;
        /// @}
        
        /// @biref Creats a new object arranged_element_collection
        explicit arranged_element_collection(const allocator_type& allocator = allocator_type()) : collection_(allocator) {}
        
        /// @cond
        arranged_element_collection(const arranged_element_collection& collection) {this->push_back_range(collection);}
        arranged_element_collection& operator=(const arranged_element_collection& collection) {
          this->clear();
          this->push_back_range(collection);
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
        
        allocator_type get_allocator() const {return this->collection_.get_allocator();}
        
        reference at(size_type pos) {
          this->collection_[pos].pos = pos;
          this->collection_[pos].parent = this;
          return this->collection_.at(pos);
        }
        const_reference at(size_type pos) const {return this->collection_.at(pos);}
       
        reference front() {return this->collection_.front();}
        const_reference front() const {return this->collection_.front();}
       
        reference back() {return this->collection_.back();}
        const_reference back() const {return this->collection_.back();}
    
        value_type* data() {return this->collection_.data();}
        const value_type* data() const {return this->collection_.data();}
        
        reference operator[](size_type pos) {
          this->collection_[pos].pos = pos;
          this->collection_[pos].parent = this;
          return this->collection_[pos];
        }
        const_reference operator[](size_type pos) const {return this->collection_[pos];}
        
        iterator begin() {return this->collection_.begin();}
        const_iterator begin() const {return this->collection_.begin();}
        const_iterator cbegin() const {return this->collection_.cbegin();}
        
        iterator end() {return this->collection_.end();}
        const_iterator end() const {return this->collection_.end();}
        const_iterator cend() const {return this->collection_.cend();}
        
        reverse_iterator rbegin() {return this->collection_.rbegin();}
        const_reverse_iterator rbegin() const {return this->collection_.rbegin();}
        const_reverse_iterator crbegin() const {return this->collection_.crbegin();}

        reverse_iterator rend() {return this->collection_.rend();}
        const_reverse_iterator rend() const {return this->collection_.rend();}
        const_reverse_iterator crend() const {return this->collection_.crend();}
        
        bool empty() const {return this->collection_.empty();}
        
        size_type size() const {return this->collection_.size();}
        
        size_type max_size() const {return this->collection_.max_size();}
        
        void reserve(size_type size) {this->collection_.reserve(size);}
        
        size_type capacity() const {return this->collection_.capacity();}
        
        void shrink_to_fit() {this->collection_.shrink_to_fit();}
        
        bool sorted() const {return sorted_;}
        void sorted(bool value) {
          if (sorted_ != value) {
            sorted_ = value;
            if (sorted_) sort();
          }
        }
        
        void clear() {
          iterator it = this->begin();
          while (it != this->end())
            it = this->erase(it);
        }

        iterator insert(iterator pos, const value_type& value) {
          size_t index = pos - this->begin();
          inserting_ = true;
          iterator result = this->collection_.insert(pos, value);
          inserting_ = false;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          this->item_added(index, this->collection_[index]);
          if (sorted_) sort();
          return result;
        }
        
        iterator insert(const_iterator pos, const value_type& value) {
          size_t index = pos - this->begin();
          inserting_ = true;
          iterator result = this->collection_.insert(pos, value);
          inserting_ = false;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          this->item_added(index, this->collection_[index]);
          if (sorted_) sort();
          return result;
        }
        
        iterator insert(const_iterator pos, const value_type&& value) {
          size_t index = pos - this->begin();
          inserting_ = true;
          iterator result = this->collection_.insert(pos, value);
          inserting_ = false;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          this->item_added(index, this->collection_[index]);
          if (sorted_) sort();
          return result;
        }

        void insert_at(size_t index, const value_type& value) {
          if (index > size()) throw std::invalid_argument("index out of range");
          this->insert(this->begin() + index, value);
        }

        iterator erase(iterator pos) {
          this->item_erased(pos - this->begin(), *pos);
          erasing_ = true;
          iterator result = this->collection_.erase(pos);
          erasing_ = false;
          return result;
        }
        
        iterator erase(const_iterator pos) {
          this->item_erased(pos - this->begin(), *pos);
          erasing_ = true;
          iterator result = this->collection_.erase(pos);
          erasing_ = false;
          return result;
        }
        
        iterator erase(iterator first, iterator last) {
          iterator result = this->end();
          for (iterator it = first; it <= last; it++)
            result = this->erase(it);
          return result;
        }
        
        iterator erase(const_iterator first, const_iterator last) {
          iterator result = this->bend();
          for (const_iterator it = first; it <= last; it++)
            result = this->erase(it);
          return result;
        }
        
        void erase_at(size_t index) {
          if (index > size()) throw std::invalid_argument("index out of range");
          this->erase(this->begin() + index);
        }

        void push_back(const value_type& item) {
          this->collection_.push_back(item);
          size_t index = this->collection_.size() - 1;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          this->item_added(index, this->collection_[index]);
          if (sorted_) sort();
        }
        
        void push_back(value_type&& item) {
          this->collection_.push_back(item);
          size_t index = this->collection_.size() - 1;
          (*this)[index].parent = this;
          (*this)[index].pos = index;
          this->item_added(index, this->collection_[index]);
          if (sorted_) sort();
        }
        
        void push_back_range(const arranged_element_collection& collection) {
          for(value_type item : collection)
            this->push_back(item);
        }
        
        void push_back_range(const std::vector<value_type>& collection) {
          for(value_type item : collection)
            this->push_back(item);
        }

        void push_back_range(const std::initializer_list<value_type>& collection) {
          for(value_type item : collection)
            this->push_back(item);
        }
        
        template<typename collection_t>
        void push_back_range(collection_t collection) {
          for(const auto& item : collection)
            this->push_back(value_type(item));
        }

        void sort() {
          //std::sort(begin(), end());
          sorter_t sorter;
          sorter(begin(), end());
        }
      
      private:
        std::vector<value_type, allocator_type> collection_;
        bool inserting_ = false;
        bool erasing_ = false;
        bool sorted_ = false;
      };
    }
  }
}
