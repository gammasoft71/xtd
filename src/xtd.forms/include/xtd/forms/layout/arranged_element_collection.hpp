/// @file
/// @brief Contains xtd::forms::layout::arranged_element_collection collection.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

#include "sorter_none.hpp"
#include <xtd/collections/generic/helpers/equator>
#include <xtd/collections/generic/list>
#include <xtd/helpers/throw_helper.hpp>
#include <xtd/array>
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
      template<class type_t, class sorter_t = sorter_none>
      class arranged_element_collection : public object {
      public:
        /// @brief Represents the value type of the collection.
        class value_type : public type_t {
        public:
          /// @cond
          value_type() = default;
          value_type(const value_type&) = default;
          value_type(value_type&&) = default;
          template<class ...args_t>
          value_type(args_t&& ...args) : type_t(args...) {}
          value_type& operator =(const value_type& value) {
            if (value.owner) owner = value.owner;
            if (owner != nullptr && !owner->inserting_ && !owner->erasing_) owner->on_item_updated(pos, static_cast<type_t&>(const_cast<value_type&>(value)));
            type_t::operator =(value);
            return self_;
          }
          value_type& operator =(value_type&& value) {
            if (value.owner) owner = value.owner;
            if (owner != nullptr && !owner->inserting_ && !owner->erasing_) owner->on_item_updated(pos, static_cast<type_t&>(value));
            type_t::operator =(value);
            return self_;
          }
          operator type_t() {return self_;}
          friend std::ostream& operator <<(std::ostream& os, const value_type& value) {return os << static_cast<const type_t&>(value);}
          /// @endcond
          
        private:
          friend class arranged_element_collection;
          size_t pos = size_object::max_value;
          arranged_element_collection* owner = nullptr;
        };
        
        /// @name Public Aliases
        
        /// @{
        /// @brief Represents the list base type.
        using base_type = typename xtd::collections::generic::list<value_type>::base_type;
        /// @brief Represents the list base type.
        using const_base_type = const base_type;
        /// @brief Represents the list size type (usually xtd::size).
        using size_type = xtd::size;
        /// @brief Represents the reference of list value type.
        using reference = type_t&;
        /// @brief Represents the const reference of list value type.
        using const_reference = const type_t&;
        /// @brief Represents the pointer of list value type.
        using pointer = value_type*;
        /// @brief Represents the const pointer of list value type.
        using const_pointer = const value_type*;
        
        /// @brief Represents the iterator type of the collection.
        using iterator = typename xtd::collections::generic::list<value_type>::iterator;
        /// @brief Represents the const iterator type of the collection.
        using const_iterator = typename xtd::collections::generic::list<value_type>::const_iterator;
        
        /// @name Public Fields
        
        /// @{
        /// @brief Represents a value that is not a valid position in a collection.
        /// @remarks This constant is typically used to indicate the absence of an index or a failed search operation. It is equivalent to the maximum value of xtd::size.
        /// @par Examples
        /// ```cpp
        /// auto controls = control_collection {label1, button1, choice1};
        /// if (items.index_of(label1) == items.npos)
        ///   console::write_line("Value not found");
        /// ```
        inline static constexpr xtd::size npos = xtd::npos;
        
        /// @brief Represents the index of the first valid element in a collection.
        /// @remarks Unlike xtd::npos (which means "no position"), xtd::bpos points to the first accessible element of a collection. It is equivalent to `0`.
        /// @par Examples
        /// ```cpp
        /// auto controls = control_collection {label1, button1, choice1};
        /// controls[bpos].width(240); // change the with of label1 to 240
        /// controls[bpos + 1].width(120); // change the with of button1 to 120
        /// ```
        static inline constexpr xtd::size bpos = 0;
        
        /// @brief Represents the index of the last valid element in a collection.
        /// @remarks Unlike xtd::npos (which means "no position"), xtd::epos points to the last accessible element of a collection. It is equivalent to `items.count() - 1`.
        /// @note This constant is provided for readability and convenience. For example, `items[xtd::epos]` directly accesses the last element without manually subtracting one from the collection count.
        /// @remarks The epos is equivalent to `~1_z`. With bitwise operator the code is more concise.
        /// @par Examples
        /// ```cpp
        /// auto controls = control_collection {label1, button1, choice1};
        /// controls[epos].width(240); // change the with of choice1 to 240
        /// controls[epos - 1].width(120); // change the with of button1 to 120
        /// ```
        /// The wollowing exemple shows the same example with bitwise operator as index.
        /// ```cpp
        /// auto controls = control_collection {label1, button1, choice1};
        /// controls[~1_z].width(240); // change the with of choice1 to 240
        /// controls[~2_z].width(120); // change the with of button1 to 120
        /// ```
        static inline constexpr xtd::size epos = npos - 1;
        /// @}
        
        /// @name Public Constructors
        
        /// @{
        /// @brief Creates a new object xtd::forms::layout::arranged_element_collection with specified allocator (optional).
        arranged_element_collection() = default;
        /// @brief Creates a new object xtd::diagnostics::trace_listener_collection with specified initializer list.
        arranged_element_collection(const std::initializer_list<type_t>& il) {
          for (auto item : il)
            add(item);
        }
        /// @}
        
        /// @cond
        explicit arranged_element_collection(const std::vector<type_t>& collection) {
          for (auto item : collection)
            add(item);
        }
        arranged_element_collection(const arranged_element_collection& collection) {add_range(collection);}
        arranged_element_collection& operator =(const arranged_element_collection& collection) {
          clear();
          add_range(collection);
          return self_;
        }
        arranged_element_collection(arranged_element_collection&&) = default;
        bool operator ==(const arranged_element_collection& value) const {return items_ == value.items_;}
        bool operator !=(const arranged_element_collection& value) const {return !operator ==(value);}
        /// @endcond
        
        /// @name Public Properties
        
        /// @{
        /// @brief Returns the number of elements.
        /// @return The number of elements.
        size_type count() const noexcept {return items_.count();}
        
        /// @brief Direct access to the underlying array.
        /// @return The underlying array.
        pointer data() {return items_.data();}
        /// @brief Direct access to the underlying array.
        /// @return The underlying array.
        const_pointer data() const {return items_.data();}
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        const auto& items() const {return items_.items();}
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        auto& items() {return items_.items();}
        
        /// @brief Checks whether the container is sorted.
        /// @return `true` if container is sorted; otherwise `false`.
        virtual bool sorted() const noexcept {return sorted_;}
        /// @brief Sets the container is sorted.
        /// @param value `true` if container is sorted; otherwise `false`.
        virtual arranged_element_collection& sorted(bool value) {
          if (sorted_ == value) return self_;
          sorted_ = value;
          if (sorted_) sort();
          return self_;
        }
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Returns an iterator to the beginning.
        /// @return The iterator to the beginning.
        iterator begin() noexcept {return items_.begin();}
        /// @brief Returns an iterator to the beginning.
        /// @return The iterator to the beginning.
        const_iterator begin() const noexcept {return items_.begin();}
        /// @brief Returns an iterator to the beginning.
        /// @return The iterator to the beginning.
        const_iterator cbegin() const noexcept {return items_.cbegin();}
        
        /// @brief Returns an iterator to the end.
        /// @return The iterator to the end.
        iterator end() noexcept {return items_.end();}
        /// @brief Returns an iterator to the end.
        /// @return The iterator to the end.
        const_iterator end() const noexcept {return items_.end();}
        /// @brief Returns an iterator to the end.
        /// @return The iterator to the end.
        const_iterator cend() const noexcept {return items_.cend();}
        
        /// @brief Adds an element to the end.
        /// @param item The element to add.
        virtual void add(const type_t& item) {
          items_.add(item);
          size_t index = items_.count() - 1;
          static_cast<value_type&>(self_[index]).owner = this;
          static_cast<value_type&>(self_[index]).pos = index;
          on_item_added(index, items_[index]);
          if (sorted_) sort();
        }
        /// @brief Adds an element to the end.
        /// @param item The element to add.
        virtual void add(type_t&& item) {
          items_.add(item);
          size_t index = items_.count() - 1;
          static_cast<value_type&>(self_[index]).owner = this;
          static_cast<value_type&>(self_[index]).pos = index;
          on_item_added(index, items_[index]);
          if (sorted_) sort();
        }
        
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        virtual void add_range(const arranged_element_collection& collection) {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        virtual void add_range(const std::vector<type_t>& collection) {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        virtual void add_range(const std::initializer_list<type_t>& collection) {
          for (const auto& item : collection)
            add(item);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        template<class collection_t>
        void add_range(collection_t&& collection) {
          for (auto& item : collection)
            add(value_type(item));
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        template<class collection_t>
        void add_range(const collection_t& collection) {
          for (const auto& item : collection)
            add(item);
        }
        
        /// @brief clears the contents.
        virtual void clear() noexcept {
          while (count())
            remove_at(0);
        }
        
        /// @brief Inserts specified element at specified index.
        /// @param index The index before which the content will be inserted.
        /// @param value The element to insert.
        virtual void insert(xtd::size index, const type_t& value) {
          if (index > count()) helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          inserting_ = true;
          items().insert(items().begin() + index, value);
          inserting_ = false;
          static_cast<value_type&>(self_[index]).owner = this;
          static_cast<value_type&>(self_[index]).pos = index;
          on_item_added(index, items_[index]);
          if (sorted_) sort();
        }
        
        /// @brief Sorts the content.
        virtual arranged_element_collection& sort() {
          sorter_t sorter;
          sorter(items().begin(), items().end());
          return self_;
        }
        
        /// @brief Removes an element.
        /// @param item The element to remove.
        virtual bool remove(const type_t& item) {
          if (count() == 0)  return false;
          for (auto index = size_type {0}; index < count(); ++index) {
            if (!xtd::collections::generic::helpers::equator<type_t> {}(self_[index], item)) continue;
            remove_at(index);
            return true;
          }
          return false;
        }
        
        /// @brief Erases element at specified index.
        /// @param pos The index which the content will be erased.
        virtual void remove_at(size_t index) {
          if (index > count()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          on_item_removed(index, const_cast<value_type&>(items_[index]));
          erasing_ = true;
          items().erase(items().begin() + index);
          erasing_ = false;
        }
        
        /// @brief Gets an array with the elements of the container.
        /// @return The array that contains elements of the container.
        xtd::array<type_t> to_array() const noexcept {
          return items_.count() ? xtd::array<type_t>(items_.data(), items_.count()) : xtd::array<type_t> {};
        }
        /// @}
        
        /// @name Public Deprecatd Aliases
        
        /// @{
        /// @brief Represents the reverse iterator type of the collection.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items::reverse_iterator - Will be removed in version 0.4.0.
        using reverse_iterator [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items::reverse_iterator - Will be removed in version 0.4.0.")]] = typename xtd::collections::generic::list<value_type>::base_type::reverse_iterator;
        /// @brief Represents the const reverse iterator type of the collection.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items::reverse_iterator - Will be removed in version 0.4.0.
        using const_reverse_iterator [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items::const_reverse_iterator - Will be removed in version 0.4.0.")]] = typename xtd::collections::generic::list<value_type>::base_type::const_reverse_iterator;
        /// @}
        
        /// @name Public Deprecatd Properties
        
        /// @{
        /// @brief Returns the number of elements that can be held in currently allocated storage.
        /// @return The number of elements that can be held in currently allocated storage.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().capacity - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().capacity - Will be removed in version 0.4.0.")]]
        size_type capacity() const noexcept {return items_.capacity();}
        
        /// @brief Checks whether the container is empty.
        /// @return `true` if container is empty; otherwise `false`.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().empty - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().empty - Will be removed in version 0.4.0.")]]
        bool empty() const noexcept {return items_.empty();}
        
        /// @brief Returns the maximum possible number of elements.
        /// @return The maximum possible number of elements.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::max_size().empty - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().max_size - Will be removed in version 0.4.0.")]]
        size_type max_size() const noexcept {return items_.max_size();}
        
        /// @brief Returns the number of elements.
        /// @return The number of elements.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::count - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::count - Will be removed in version 0.4.0.")]]
        size_type size() const noexcept {return count();}
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Access specified element.
        /// @param index The position of the element to return.
        /// @return The requested element.
        value_type& operator [](size_type index) {
          if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
          items_[index].pos = index > npos / 2 ? count() - (npos - index) : index;
          items_[index].owner = this;
          return items_[index];
        }
        /// @brief Access specified element.
        /// @param index The position of the element to return.
        /// @return The requested element.
        const value_type& operator [](size_type index) const {
          if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
          items_[index].pos = index > npos / 2 ? count() - (npos - index) : index;
          items_[index].owner = const_cast<arranged_element_collection*>(this);
          return items_[index];
        }
        /// @}
        
        /// @name Public Events
        
        /// @{
        /// @brief Occurs when an item is added to the collection.
        /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
        event<arranged_element_collection, delegate<void(size_t, type_t& item)>> item_added;
        
        /// @brief Occurs when an item is updated in the collection.
        /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
        event<arranged_element_collection, delegate<void(size_t, type_t& item)>> item_updated;
        
        /// @brief Occurs when an item is removed from the collection.
        /// @remarks For more information about handling events, see [Handling and Raising Events](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Events/overview).
        event<arranged_element_collection, delegate<void(size_t, type_t& item)>> item_removed;
        /// @}
        
        /// @name Public Deprecated Methods
        
        /// @{
        /// @brief Access specified element with bounds checking.
        /// @param pos The position of the element to return.
        /// @exception std::out_of_range pos is greater than arranged_element_collection::size.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::rator [] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [] - Will be removed in version 0.4.0.")]]
        reference at(size_type pos) {
          items_[pos].pos = pos;
          items_[pos].owner = this;
          return items_.at(pos);
        }
        /// @brief Access specified element with bounds checking.
        /// @param pos The position of the element to return.
        /// @exception std::out_of_range pos is greater than arranged_element_collection::size.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::rator [] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [] - Will be removed in version 0.4.0.")]]
        const_reference at(size_type pos) const {return items_.at(pos);}
        
        /// @brief Access the last element.
        /// @return The last element.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::operator [~1_z] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [~1_z] - Will be removed in version 0.4.0.")]]
        reference back() {return items_.back();}
        /// @brief Access the last element.
        /// @return The last element.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::operator [~1_z] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [~1_z] - Will be removed in version 0.4.0.")]]
        const_reference back() const {return items_.back();}
        
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().crbegin - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().crbegin - Will be removed in version 0.4.0.")]]
        const_reverse_iterator crbegin() const noexcept {return items_.crbegin();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().crend - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().crend - Will be removed in version 0.4.0.")]]
        const_reverse_iterator crend() const noexcept {return items_.crend();}
        
        /// @brief Access the first element.
        /// @return The first element.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::operator [0] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [0] - Will be removed in version 0.4.0.")]]
        reference front() {return items_.front();}
        /// @brief Access the first element.
        /// @return The first element.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::operator [0] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [0] - Will be removed in version 0.4.0.")]]
        const_reference front() const {return items_.front();}
        
        /// @brief Returns the associated allocator
        /// @return The associate allocator.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::count - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().get_allocator - Will be removed in version 0.4.0.")]]
        auto get_allocator() const noexcept {return items_.get_allocator();}
        
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param args The arguments to forward to the constructor of the element
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.
        template<class ...args_t>
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.")]]
        void emplace(const_iterator pos, args_t&& ... args) {
          auto index = pos - begin();
          inserting_ = true;
          auto result = items_.insert(pos, args...);
          inserting_ = false;
          self_[index].owner = this;
          self_[index].pos = index;
          on_item_added(index, items_[index]);
          if (sorted_) sort();
          return result;
        }
        
        /// @brief Adds an element to the end.
        /// @param args The arguments to forward to the constructor of the element
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::add - Will be removed in version 0.4.0.
        template<class ...args_t>
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::add - Will be removed in version 0.4.0.")]]
        void emplace_back(args_t&& ... args) {
          items_.emplace_back(args...);
          size_t index = items_.size() - 1;
          self_[index].owner = this;
          self_[index].pos = index;
          on_item_added(index, items_[index]);
          if (sorted_) sort();
        }
        
        /// @brief Erases element at specified position.
        /// @param pos The iterator which the content will be erased.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.")]]
        auto erase(iterator pos) {
          on_item_removed(pos - begin(), *pos);
          erasing_ = true;
          auto result = items().erase(pos);
          erasing_ = false;
          return result;
        }
        /// @brief Erases element at specified position.
        /// @param pos The iterator which the content will be erased.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.")]]
        auto erase(const_iterator pos) {
          on_item_removed(pos - begin(), const_cast<value_type&>(*pos));
          erasing_ = true;
          auto result = items().erase(pos);
          erasing_ = false;
          return result;
        }
        
        /// @brief Erases elements at specified range.
        /// @param first The first iterator range which the content will be erased.
        /// @param first The last iterator range which the content will be erased.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.")]]
        auto erase(iterator first, iterator last) {
          iterator result = end();
          auto index = first - begin();
          for (iterator it = first; it <= last; ++it)
            remove_at(index++);
          return result;
        }
        /// @brief Erases elements at specified range.
        /// @param first The first iterator range which the content will be erased.
        /// @param first The last iterator range which the content will be erased.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.")]]
        auto erase(const_iterator first, const_iterator last) {
          auto result = end();
          auto index = first - begin();
          for (const_iterator it = first; it <= last; ++it)
            remove_at(index++);
          return result;
        }
        
        /// @brief Erases element at specified index.
        /// @param pos The index which the content will be erased.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.")]]
        void erase_at(size_t index) {
          remove_at(index);
        }
        
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param value The element to insert.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.")]]
        auto insert(const_iterator pos, const type_t& value) {
          auto index = pos - begin();
          inserting_ = true;
          auto result = items().insert(pos, value);
          inserting_ = false;
          self_[index].owner = this;
          self_[index].pos = index;
          on_item_added(index, items_[index]);
          if (sorted_) sort();
          return result;
        }
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param value The element to insert.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.")]]
        auto insert(const_iterator pos, type_t&& value) {
          auto index = pos - begin();
          inserting_ = true;
          auto result = items().insert(pos, value);
          inserting_ = false;
          self_[index].owner = this;
          self_[index].pos = index;
          on_item_added(index, items_[index]);
          if (sorted_) sort();
          return result;
        }
        
        /// @brief Inserts specified element at specified index.
        /// @param index The index before which the content will be inserted.
        /// @param value The element to insert.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.")]]
        void insert_at(size_t index, const type_t& value) {
          insert(index, value);
        }
        
        /// @brief Removes the last element of the container.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove(count() - 1) - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove(count() - 1) - Will be removed in version 0.4.0.")]]
        void pop_back() {
          if (count() != 0) remove_at(count() - 1);
        }
        
        /// @brief Adds an element to the end.
        /// @param item The element to add.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::add - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::add - Will be removed in version 0.4.0.")]]
        void push_back(const type_t& item) {
          add(item);
        }
        /// @brief Adds an element to the end.
        /// @param item The element to add.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::add - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::add - Will be removed in version 0.4.0.")]]
        void push_back(type_t&& item) {
          add(std::move(item));
        }
        
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.")]]
        void push_back_range(const arranged_element_collection& collection) {
          add_range(collection);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.")]]
        void push_back_range(const std::vector<type_t>& collection) {
          add_range(collection);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.")]]
        void push_back_range(const std::initializer_list<type_t>& collection) {
          add_range(collection);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.
        template<class collection_t>
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.")]]
        void push_back_range(collection_t&& collection) {
          add_range(collection);
        }
        /// @brief Adds elements to the end.
        /// @param collection The elements to add.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.
        template<class iterator_t>
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::add_range - Will be removed in version 0.4.0.")]]
        void push_back_range(iterator_t begin, iterator_t end) {
          add_range(begin, end);
        }
        
        /// @brief Gets an array with the elements of the container.
        /// @return The array that contains elements of the container.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::to_array - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::to_array - Will be removed in version 0.4.0.")]]
        std::vector<type_t> to_vector() const noexcept {return to_array();}
        
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().rbegin - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().rbegin - Will be removed in version 0.4.0.")]]
        auto rbegin() noexcept {return items_.rbegin();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().rbegin - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().rbegin - Will be removed in version 0.4.0.")]]
        auto rbegin() const noexcept {return items_.rbegin();}
        
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().rend - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().rend - Will be removed in version 0.4.0.")]]
        auto rend() noexcept {return items_.rend();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().rend - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().rend - Will be removed in version 0.4.0.")]]
        auto rend() const noexcept {return items_.rend();}
        
        /// @brief Reserves storage.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().reserve - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().reserve - Will be removed in version 0.4.0.")]]
        void reserve(size_type size) {items_.reserve(size);}
        
        /// @brief Reduces memory usage by freeing unused memory.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().shrink_to_fit - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().shrink_to_fit - Will be removed in version 0.4.0.")]]
        void shrink_to_fit() {items_.shrink_to_fit();}
        /// @}
        
      protected:
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
        mutable xtd::collections::generic::list<value_type> items_;
        bool inserting_ = false;
        bool erasing_ = false;
        bool sorted_ = false;
      };
    }
  }
}
