#include <vector>
#include <xtd/event_args.hpp>
#include <xtd/event_handler.hpp>
#include <xtd/event.hpp>

namespace xtd {
  namespace forms {
    namespace layout {
      template<typename type_t, typename allocator_t = std::allocator<type_t>>
      class arranged_element_collection {
      public:
        using value_type = type_t;
        using allocator_type = allocator_t;
        using size_type = size_t;
        using difference_type = ptrdiff_t;
        using reference = type_t&;
        using const_reference = const type_t&;
        using pointer = typename std::allocator_traits<allocator_t>::pointer;
        using const_pointer = typename std::allocator_traits<allocator_t>::const_pointer;
        using iterator = typename std::vector<type_t>::iterator;
        using const_iterator = typename std::vector<type_t>::const_iterator;
        using reverse_iterator = typename std::vector<type_t>::reverse_iterator;
        using const_reverse_iterator = typename std::vector<type_t>::const_reverse_iterator;
        
        explicit arranged_element_collection(const allocator_t& allocator = allocator_t()) : collection_(allocator) {}
        
        /// @cond
        arranged_element_collection(const arranged_element_collection& collection) {this->push_back_range(collection);}
        arranged_element_collection& operator=(const arranged_element_collection& collection) {
          this->clear()
          this->push_back_range(collection);
          return *this;
        }
        /// @endcond
        
        event<arranged_element_collection, delegate<void(size_t, type_t item)>> item_added;
        event<arranged_element_collection, delegate<void(size_t, type_t item)>> item_removed;
        
        allocator_t get_allocator() const {return this->collection_.get_allocator();}
        
        reference at(size_type pos) {return this->collection_.at(pos);}
        const_reference at(size_type pos) const {return this->collection_.at(pos);}
       
        reference front() {return this->collection_.front();}
        const_reference front() const {return this->collection_.front();}
       
        reference back() {return this->collection_.back();}
        const_reference back() const {return this->collection_.back();}
    
        type_t* data() {return this->collection_.data();}
        const type_t* data() const {return this->collection_.data();}
        
        reference operator[](size_type pos) {return this->collection[pos];}
        const_reference operator[](size_type pos) const {return this->collection[pos];}
       
        void push_back(size_t item) {
          this->collection_.pudh_back(item);
          this->item_added(this->collection_.size() - 1, item);
        }
        
        void push_back_range(const arranged_element_collection& collection) {
          for(type_t item : collection)
            this->push_back(item);
        }
        
        void push_back_range(const std::vector<type_t>& collection) {
          for(type_t item : collection)
            this->push_back(item);
        }

        void push_back_range(const std::initializer_list<type_t>& collection) {
          for(type_t item : collection)
            this->push_back(item);
        }
      
      private:
        std::vector<type_t, allocator_t> collection_;
      };
    }
  }
}
