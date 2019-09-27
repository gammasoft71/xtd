#pragma once
#include <ostream>
#include <vector>
#include <xtd/event_args.hpp>
#include <xtd/event_handler.hpp>
#include <xtd/event.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief The xtd::forms::layout namespace contains classes for implementing layout behaviors in your form or control.
    namespace layout {
      /// @brief Represents a collection of objects.
      /// @remarks The arranged_element_collection class represents a collection of objects arranged on a design surface or inside a parent xtd.forms::container_control.
      template<typename type_t, typename allocator_t = std::allocator<type_t>>
      class arranged_element_collection {
      public:
        class item_t :public type_t {
        public:
          item_t() = default;
          template <typename ...args_t>
          item_t(args_t&& ...args) : type_t(args...) {}

          item_t& operator=(const item_t& value) {
            this->type_t::operator=(value);
            if (parent != nullptr) {
              parent->item_updated(pos, static_cast<const type_t&>(*this));
              //parent = nullptr;
            }
            return *this;
          }
          
          operator type_t() {return *this;}
          
          friend std::ostream& operator<<(std::ostream& os, const item_t& value) {return os << value.to_string();}
          
          size_t pos;
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
        explicit arranged_element_collection(const allocator_t& allocator = allocator_t()) : collection_(allocator) {}
        
        /// @cond
        arranged_element_collection(const arranged_element_collection& collection) {this->push_back_range(collection);}
        arranged_element_collection& operator=(const arranged_element_collection& collection) {
          this->clear();
          this->push_back_range(collection);
          return *this;
        }
        /// @endcond
        
        /// @brief Occurs when an item is added to the collection.
        event<arranged_element_collection, delegate<void(size_t, const type_t& item)>> item_added;

        /// @brief Occurs when an item is updated in the collection.
        event<arranged_element_collection, delegate<void(size_t, const type_t& item)>> item_updated;

        /// @brief Occurs when an item is erased from the collection.
        event<arranged_element_collection, delegate<void(size_t, const type_t& item)>> item_erased;
        
        allocator_t get_allocator() const {return this->collection_.get_allocator();}
        
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
        
        void clear() {
          iterator it = this->begin();
          while (it != this->end())
            it = this->erase(it);
        }
        
        iterator insert(iterator pos, const value_type& value) {
          iterator result = this->collection_.insert(pos, value);
          this->item_added(pos - this->begin(), value);
          return result;
        }
        
        iterator insert(const_iterator pos, const value_type& value) {
          iterator result = this->collection_.insert(pos, value);
          this->item_added(pos - this->begin(), value);
          return result;
        }
        
        iterator insert(const_iterator pos, const value_type&& value) {
          iterator result = this->collection_.insert(pos, value);
          this->item_added(pos - this->begin(), value);
          return result;
        }

        void insert_at(size_t index, const value_type& value) {this->insert(this->begin() + index, value);}

        iterator erase(iterator pos) {
          size_t index = pos - this->begin();
          value_type item = *pos;
          iterator result = this->collection_.erase(pos);
          this->item_erased(index, item);
          return result;
        }
        
        iterator erase(const_iterator pos) {
          size_t index = pos - this->cbegin();
          value_type item = *pos;
          iterator result = this->collection_.erase(pos);
          this->item_erased(index, item);
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
        
        void erase_at(size_t index) {this->erase(this->begin() + index);}

        void push_back(const value_type& item) {
          this->collection_.push_back(item);
          this->item_added(this->collection_.size() - 1, item);
        }
        
        void push_back(value_type&& item) {
          this->collection_.push_back(item);
          this->item_added(this->collection_.size() - 1, item);
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
      
      private:
        std::vector<value_type, allocator_type> collection_;
      };
    }
  }
}
