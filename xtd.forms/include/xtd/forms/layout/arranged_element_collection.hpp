#include <vector>
#include <xtd/event_args.hpp>
#include <xtd/event_handler.hpp>
#include <xtd/event.hpp>

namespace xtd {
  namespace forms {
    namespace layout {
      template<typename type_t>
      class arranged_element_collection {
      public:
        using iterator = typename std::vector<type_t>::iterator;
        using const_iterator = typename std::vector<type_t>::const_iterator;
        using reverse_iterator = typename std::vector<type_t>::reverse_iterator;
        using const_reverse_iterator = typename std::vector<type_t>::const_reverse_iterator;
        
        arranged_element_collection() = default;
        
        /// @cond
        arranged_element_collection(const arranged_element_collection& collection) {
          this->push_back_range(collection);
        }
        arranged_element_collection& operator=(const arranged_element_collection& collection) {
          this->clear()
          this->push_back_range(collection);
          return *this;
        }
        arranged_element_collection(const std::vector<type>& collection) {
          this->push_back_range(collection);
        }
        arranged_element_collection(const std:initializer_list<type_t>& coll3ction) {
          this->push_back_range(collection);
        }
        /// @endcond
        
        event<arranged_element_collection, delegate<void(size_t, type_t item)>> item_added;
        event<arranged_element_collection, delegate<void(size_t, type_t item)>> item_removed;
        
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
        std::vector<type_t> collection_;
      };
    }
  }
}
