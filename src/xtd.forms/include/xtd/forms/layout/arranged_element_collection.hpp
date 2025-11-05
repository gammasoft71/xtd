/// @file
/// @brief Contains xtd::forms::layout::arranged_element_collection collection.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once

//#include "items_added_event_handler.hpp"
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
#include <xtd/new_ptr>
#include <xtd/size_object>

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
      /// @remarks xtd::forms::layout::arranged_element_collection inherits from xtd::collections::generic::icollection instead of xtd::collections::generic::ilistto allow `operator[]` to return `value_type`, which triggers updates and events on element changes.
      /// @remarks Returning `type_t&` would bypass these updates, while returning `value_type&` would break the xtd::collections::generic::ilist interface.
      /// @remarks This keeps the collection safe and consistent, while most developers can still use xtd::forms::layout::arranged_element_collection::add_range() or xtd::forms::layout::arranged_element_collection::operator[] as expected.
      template<class type_t, class sorter_t = sorter_none>
      class arranged_element_collection : public object, public xtd::collections::generic::icollection<type_t> {
        struct internal_enumerator : public xtd::collections::generic::ienumerator<type_t> {
        public:
          explicit internal_enumerator(const arranged_element_collection& items, xtd::size version) : items_(items), version_(version) {}
          
          const type_t& current() const override {
            if (version_ != items_.items().version()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
            if (index_ < items_.count()) return items_[index_];
            return default_value_;
          }
          
          bool move_next() override {
            if (version_ != items_.items().version()) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation, "Collection was modified; enumeration operation may not execute.");
            return ++index_ < items_.count();
          }
          
          void reset() override {
            version_ = items_.items().version();
            index_ = arranged_element_collection::npos;
          }
          
        protected:
          const arranged_element_collection& items_;
          xtd::size index_ = arranged_element_collection::npos;
          xtd::size version_ = 0;
          type_t default_value_;
        };
        
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
            if (owner != nullptr && !owner->data_->inserting && !owner->data_->erasing) owner->on_item_updated(pos, static_cast<type_t&>(const_cast<value_type&>(value)));
            type_t::operator =(value);
            return self_;
          }
          value_type& operator =(value_type&& value) {
            if (value.owner) owner = value.owner;
            if (owner != nullptr && !owner->data_->inserting && !owner->data_->erasing) owner->on_item_updated(pos, static_cast<type_t&>(value));
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
        /// @brief Represents the read only collection of of list.
        using read_only_collection = xtd::collections::object_model::read_only_collection<value_type>;
        /// @}
        
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
        /// @brief Initializes a new instance of the xtd::forms::layout::arranged_element_collection class that is empty.
        /// @par Examples
        /// The following code example demonstrates the default constructor of the xtd::forms::layout::arranged_element_collection generic class. The default constructor creates a list with the default capacity, as demonstrated by displaying the xtd::forms::layout::arranged_element_collection::capacity property.
        /// @include generic_list2.cpp
        arranged_element_collection() = default;
        /// @brief Constructs the container with specified count default-inserted instances of type_t. No copies are made.
        /// @param capacity The number of elements that the new list can initially store.
        /// @exception xtd::out_of_memory There is not enough memory available on the system.
        /// @par Examples
        /// The following code example demonstrates the default constructor of the xtd::forms::layout::arranged_element_collection generic class. The default constructor creates a list with the default capacity, as demonstrated by displaying the xtd::forms::layout::arranged_element_collection::capacity property.
        /// @include generic_list2.cpp
        explicit arranged_element_collection(size_type capacity) {self_.capacity(capacity);}
        /// @brief Initializes a new instance of the xtd::forms::layout::arranged_element_collection <type_t> class that contains elements copied from the specified collection and has sufficient capacity to accommodate the number of elements copied.
        /// @param collection The collection whose elements are copied to the new list.
        /// @par Examples
        /// The following code example demonstrates the xtd::forms::layout::arranged_element_collection <type_t> constructor and various methods of the xtd::forms::layout::arranged_element_collection <type_t> class that act on ranges. An array of strings is created and passed to the constructor, populating the list with the elements of the array. The xtd::forms::layout::arranged_element_collection::capacity property is then displayed, to show that the initial capacity is exactly what is required to hold the input elements.
        /// @include generic_list3.cpp
        /// @remarks The elements are copied onto the xtd::forms::layout::arranged_element_collection <type_t> in the same order they are read by the enumerator of the collection.
        /// @remarks This constructor is an O(n) operation, where n is the number of elements in collection.
        arranged_element_collection(const xtd::collections::generic::ienumerable<type_t>& collection) {add_range(collection);}
        
        /// @brief Default copy constructor with specified list.
        /// @param collection The xtd::forms::layout::arranged_element_collection which elements will be inserted from.
        arranged_element_collection(const arranged_element_collection& collection) {*data_ = *collection.data_;}
        /// @brief Move constructor with specified list.
        /// @param list The xtd::forms::layout::arranged_element_collection which elements will be moved from.
        arranged_element_collection(arranged_element_collection&& collection) {
          data_ = std::move(collection.data_);
          collection.data_ = new_ptr<data_collection>();
        }
        /// @brief Copy constructor with specified base type list.
        /// @param list The xtd::forms::layout::arranged_element_collection::base_type which elements will be inserted from.
        arranged_element_collection(const base_type& collection) {data_->items = collection;}
        /// @brief Move constructor with specified base type list.
        /// @param list The xtd::forms::layout::arranged_element_collection::base_type which elements will be moved from.
        arranged_element_collection(base_type&& collection) {data_->items = std::move(collection);}
        /// @brief Constructs the container with the contents of the specified initializer list, and allocator.
        /// @param items The initializer list to initialize the elements of the container with.
        arranged_element_collection(std::initializer_list<type_t> items) {add_range(items);}
        /// @brief Constructs the container with the contents of the range [first, last).
        /// @param first The first iterator the range to copy the elements from.
        /// @param last The last iterator the range to copy the elements from.
        /// @param alloc The allocator to use for all memory allocations of this container.
        template <std::input_iterator input_iterator_t>
        arranged_element_collection(input_iterator_t first, input_iterator_t last) {
          for (auto iterator = first; iterator != last; ++iterator)
            add(*iterator);
        }
        /// @}
        
        /// @name Public Properties
        
        /// @{
        /// @brief Gets the total number of elements the internal data structure can hold without resizing.
        /// @return Capacity of the currently allocated storage.
        /// @exception xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
        size_type capacity() const noexcept {return data_->items.capacity();}
        /// @brief Sets the total number of elements the internal data structure can hold without resizing.
        /// @return Capacity of the currently allocated storage.
        /// @exception xtd::out_of_memory There is not enough memory available on the system.
        /// @exception xtd::argument_out_of_range_exception xtd::collections::generic::list::capacity is set to a value that is less than xtd::collections::generic::list::count.
        void capacity(size_type value) {data_->items.capacity(value);}
        
        /// @brief Gets the number of elements contained in the xtd::forms::layout::arranged_element_collection <type_t>.
        /// @return The number of elements contained in the xtd::forms::layout::arranged_element_collection <type_t>.
        size_type count() const noexcept override {return data_->items.count();}
        
        /// @brief Direct access to the underlying array.
        /// @return The underlying array.
        pointer data() {return data_->items.data();}
        /// @brief Direct access to the underlying array.
        /// @return The underlying array.
        const_pointer data() const {return data_->items.data();}
        
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        const auto& items() const {return data_->items.items();}
        /// @brief Returns the underlying base type items.
        /// @return The underlying base type items.
        auto& items() {return data_->items.items();}
        
        /// @brief Checks whether the container is sorted.
        /// @return `true` if container is sorted; otherwise `false`.
        virtual bool sorted() const noexcept {return data_->sorted;}
        /// @brief Sets the container is sorted.
        /// @param value `true` if container is sorted; otherwise `false`.
        virtual arranged_element_collection& sorted(bool value) {
          if (data_->sorted == value) return self_;
          data_->sorted = value;
          if (data_->sorted) sort();
          return self_;
        }
        /// @}
        
        /// @name Public Methods
        
        /// @{
        /// @brief Adds an item to the xtd::forms::layout::arranged_element_collection <type_t>.
        /// @param item The object to add to the xtd::forms::layout::arranged_element_collection <type_t>.
        void add(const type_t& item) override {
          data_->items.add(item);
          size_t index = data_->items.count() - 1;
          static_cast<value_type&>(self_[index]).owner = this;
          static_cast<value_type&>(self_[index]).pos = index;
          on_item_added(index, data_->items[index]);
          if (data_->sorted) sort();
        }
        /// @brief Adds an item to the xtd::forms::layout::arranged_element_collection <type_t>.
        /// @param item The object to add to the xtd::forms::layout::arranged_element_collection <type_t>.
        virtual void add(type_t&& item) {
          data_->items.add(item);
          size_t index = data_->items.count() - 1;
          static_cast<value_type&>(self_[index]).owner = this;
          static_cast<value_type&>(self_[index]).pos = index;
          on_item_added(index, data_->items[index]);
          if (data_->sorted) sort();
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
        
        /// @brief Removes all items from the xtd::forms::layout::arranged_element_collection <type_t>.
        /// @remarks xtd::forms::layout::arranged_element_collection::count must be set to 0, and references to other objects from elements of the collection must be released.
        void clear() override {
          while (count())
            remove_at(0);
        }
        
        /// @brief Determines whether the xtd::forms::layout::arranged_element_collection <type_t> contains a specific value.
        /// @param item The object to locate in the xtd::forms::layout::arranged_element_collection <type_t>.
        /// @return `true` if item is found in the xtd::forms::layout::arranged_element_collection <type_t>; otherwise, `false`.
        bool contains(const type_t& item) const noexcept override {
          return data_->items.contains(item);
        }
        
        /// @brief Copies the elements of the xtd::forms::layout::arranged_element_collection <type_t> to an xtd::array, starting at a particular xtd::array index.
        /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::forms::layout::arranged_element_collection <type_t>. The xtd::array must have zero-based indexing.
        /// @param array_index The zero-based index in `array` at which copying begins.
        /// @exception xtd::argument_exception The number of elements in the source xtd::forms::layout::arranged_element_collection <type_t> is greater than the available space from `array_index` to the end of the destination `array`.
        void copy_to(xtd::array<type_t>& array, xtd::size array_index) const override {
          if (array_index + count() > array.size()) helpers::throw_helper::throws(helpers::exception_case::argument_out_of_range);
          auto i = size_type {0};
          for (const type_t& item : self_) {
            if (i >= count()) return;
            array[array_index + i++] = item;
          }
        }
        
        /// @brief Returns an enumerator that iterates through the xtd::forms::layout::arranged_element_collection <type_t>.
        /// @return A xtd::collections::generic::.enumerator for the xtd::forms::layout::arranged_element_collection <type_t>.
        xtd::collections::generic::enumerator<type_t> get_enumerator() const noexcept override {
          return {new_ptr<internal_enumerator>(self_, items().version())};
        }
        
        /// @brief Inserts specified element at specified index.
        /// @param index The index before which the content will be inserted.
        /// @param value The element to insert.
        virtual void insert(xtd::size index, const type_t& value) {
          if (index > count()) helpers::throw_helper::throws(xtd::helpers::exception_case::argument_out_of_range);
          data_->inserting = true;
          items().insert(items().begin() + index, value);
          data_->inserting = false;
          static_cast<value_type&>(self_[index]).owner = this;
          static_cast<value_type&>(self_[index]).pos = index;
          on_item_added(index, data_->items[index]);
          if (data_->sorted) sort();
        }
        
        /// @brief Sorts the content.
        virtual arranged_element_collection& sort() {
          sorter_t sorter;
          sorter(items().begin(), items().end());
          return self_;
        }
        
        /// @brief Removes the first occurrence of a specific object from the xtd::forms::layout::arranged_element_collection <type_t>.
        /// @param item The object to remove from the xtd::forms::layout::arranged_element_collection <type_t>.
        /// @return `true` if item was successfully removed from the xtd::forms::layout::arranged_element_collection <type_t>; otherwise, `false`. This method also returns `false` if item is not found in the original xtd::forms::layout::arranged_element_collection <type_t>.
        /// @remarks If type `typ_t` implements the xtd::iequatable <type_t> generic interface, the equality comparer is the xtd::iequatable::equals method of that interface; otherwise, the default equality comparer is xtd::object::equals.
        /// @remarks This method performs a linear search; therefore, this method is an O(n) operation, where n is xtd::forms::layout::arranged_element_collection::count.
        bool remove(const type_t& item) override {
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
          on_item_removed(index, const_cast<value_type&>(data_->items[index]));
          data_->erasing = true;
          items().erase(items().begin() + index);
          data_->erasing = false;
        }
        
        /// @brief Gets an array with the elements of the container.
        /// @return The array that contains elements of the container.
        xtd::array<type_t> to_array() const noexcept {
          return data_->items.count() ? xtd::array<type_t>(data_->items.data(), data_->items.count()) : xtd::array<type_t> {};
        }
        /// @}
        
        /// @name Public Operators
        
        /// @{
        /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
        /// @param other Another container to use as data source.
        /// @return This current instance.
        arranged_element_collection& operator =(const arranged_element_collection& other) {
          clear();
          add_range(other);
          return self_;
        }
        /// @brief Move assignment operator. Replaces the contents with those of other using move semantics (i.e. the data in other is moved from other into this container). other is in a valid but unspecified state afterwards.
        /// @param other Another base type container to use as data source.
        /// @return This current instance.
        arranged_element_collection& operator =(arranged_element_collection&& other) noexcept {
          clear();
          add_range(std::move(other.data_->items));
          return self_;
        }
        /// @brief Replaces the contents with those identified by initializer list ilist.
        /// @param items Initializer list to use as data source
        /// @return This current instance.
        arranged_element_collection& operator =(const std::initializer_list<type_t>& items) {
          clear();
          add_range(items);
          return self_;
        }
        
        /// @brief Access specified element.
        /// @param index The position of the element to return.
        /// @return The requested element.
        value_type& operator [](size_type index) {
          if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
          data_->items[index].pos = index > npos / 2 ? count() - (npos - index) : index;
          data_->items[index].owner = this;
          return data_->items[index];
        }
        /// @brief Access specified element.
        /// @param index The position of the element to return.
        /// @return The requested element.
        const value_type& operator [](size_type index) const {
          if ((index >= count() && index <= ~count() - 1) || index == npos) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::index_out_of_range);
          data_->items[index].pos = index > npos / 2 ? count() - (npos - index) : index;
          data_->items[index].owner = const_cast<arranged_element_collection*>(this);
          return data_->items[index];
        }
        
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator const_base_type& () const noexcept {return items();}
        /// @brief Returns a reference to the underlying base type.
        /// @return Reference to the underlying base type.
        operator base_type& () noexcept {return items();}
        
        bool operator ==(const arranged_element_collection& value) const {return data_->items == value.data_->items;}
        bool operator !=(const arranged_element_collection& value) const {return !operator ==(value);}
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
        /// @brief Returns the maximum possible number of elements.
        /// @return The maximum possible number of elements.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::max_size().empty - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().max_size - Will be removed in version 0.4.0.")]]
        size_type max_size() const noexcept {return data_->items.max_size();}
        /// @}
        
        /// @name Public Deprecated Methods
        
        /// @{
        /// @brief Access specified element with bounds checking.
        /// @param pos The position of the element to return.
        /// @exception std::out_of_range pos is greater than arranged_element_collection::size.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::rator [] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [] - Will be removed in version 0.4.0.")]]
        reference at(size_type pos) {
          data_->items[pos].pos = pos;
          data_->items[pos].owner = this;
          return data_->items.at(pos);
        }
        /// @brief Access specified element with bounds checking.
        /// @param pos The position of the element to return.
        /// @exception std::out_of_range pos is greater than arranged_element_collection::size.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::rator [] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [] - Will be removed in version 0.4.0.")]]
        const_reference at(size_type pos) const {return data_->items.at(pos);}
        
        /// @brief Access the last element.
        /// @return The last element.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::operator [~1_z] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [~1_z] - Will be removed in version 0.4.0.")]]
        reference back() {return data_->items.back();}
        /// @brief Access the last element.
        /// @return The last element.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::operator [~1_z] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [~1_z] - Will be removed in version 0.4.0.")]]
        const_reference back() const {return data_->items.back();}
        
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().crbegin - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().crbegin - Will be removed in version 0.4.0.")]]
        const_reverse_iterator crbegin() const noexcept {return data_->items.crbegin();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().crend - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().crend - Will be removed in version 0.4.0.")]]
        const_reverse_iterator crend() const noexcept {return data_->items.crend();}
        
        /// @brief Access the first element.
        /// @return The first element.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::operator [0] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [0] - Will be removed in version 0.4.0.")]]
        reference front() {return data_->items.front();}
        /// @brief Access the first element.
        /// @return The first element.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::operator [0] - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::operator [0] - Will be removed in version 0.4.0.")]]
        const_reference front() const {return data_->items.front();}
        
        /// @brief Returns the associated allocator
        /// @return The associate allocator.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::count - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().get_allocator - Will be removed in version 0.4.0.")]]
        auto get_allocator() const noexcept {return data_->items.get_allocator();}
        
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param args The arguments to forward to the constructor of the element
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.
        template<class ...args_t>
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.")]]
        void emplace(xtd::collections::generic::list<value_type>::const_iterator pos, args_t&& ... args) {
          auto index = pos - items().begin();
          data_->inserting = true;
          auto result = data_->items.insert(pos, args...);
          data_->inserting = false;
          self_[index].owner = this;
          self_[index].pos = index;
          on_item_added(index, data_->items[index]);
          if (data_->sorted) sort();
          return result;
        }
        
        /// @brief Adds an element to the end.
        /// @param args The arguments to forward to the constructor of the element
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::add - Will be removed in version 0.4.0.
        template<class ...args_t>
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::add - Will be removed in version 0.4.0.")]]
        void emplace_back(args_t&& ... args) {
          data_->items.emplace_back(args...);
          size_t index = data_->items.size() - 1;
          self_[index].owner = this;
          self_[index].pos = index;
          on_item_added(index, data_->items[index]);
          if (data_->sorted) sort();
        }
        
        /// @brief Erases element at specified position.
        /// @param pos The iterator which the content will be erased.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.")]]
        auto erase(xtd::collections::generic::list<value_type>::iterator pos) {
          on_item_removed(pos - items().begin(), *pos);
          data_->erasing = true;
          auto result = items().erase(pos);
          data_->erasing = false;
          return result;
        }
        /// @brief Erases element at specified position.
        /// @param pos The iterator which the content will be erased.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.")]]
        auto erase(xtd::collections::generic::list<value_type>::const_iterator pos) {
          on_item_removed(pos - items().begin(), const_cast<value_type&>(*pos));
          data_->erasing = true;
          auto result = items().erase(pos);
          data_->erasing = false;
          return result;
        }
        
        /// @brief Erases elements at specified range.
        /// @param first The first iterator range which the content will be erased.
        /// @param first The last iterator range which the content will be erased.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.")]]
        auto erase(xtd::collections::generic::list<value_type>::iterator first, xtd::collections::generic::list<value_type>::iterator last) {
          auto result = items().end();
          auto index = first - items().begin();
          for (auto it = first; it <= last; ++it)
            remove_at(index++);
          return result;
        }
        /// @brief Erases elements at specified range.
        /// @param first The first iterator range which the content will be erased.
        /// @param first The last iterator range which the content will be erased.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::remove_at - Will be removed in version 0.4.0.")]]
        auto erase(xtd::collections::generic::list<value_type>::const_iterator first, xtd::collections::generic::list<value_type>::const_iterator last) {
          auto result = items().end();
          auto index = first - items().begin();
          for (auto it = first; it <= last; ++it)
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
        auto insert(xtd::collections::generic::list<value_type>::const_iterator pos, const type_t& value) {
          auto index = pos - items().begin();
          data_->inserting = true;
          auto result = items().insert(pos, value);
          data_->inserting = false;
          self_[index].owner = this;
          self_[index].pos = index;
          on_item_added(index, data_->items[index]);
          if (data_->sorted) sort();
          return result;
        }
        /// @brief Inserts specified element at specified position.
        /// @param pos The iterator before which the content will be inserted. pos may be the arranged_element_collection::end iterator.
        /// @param value The element to insert.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::insert - Will be removed in version 0.4.0.")]]
        auto insert(xtd::collections::generic::list<value_type>::const_iterator pos, type_t&& value) {
          auto index = pos - items().begin();
          data_->inserting = true;
          auto result = items().insert(pos, value);
          data_->inserting = false;
          self_[index].owner = this;
          self_[index].pos = index;
          on_item_added(index, data_->items[index]);
          if (data_->sorted) sort();
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
        auto rbegin() noexcept {return data_->items.rbegin();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().rbegin - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().rbegin - Will be removed in version 0.4.0.")]]
        auto rbegin() const noexcept {return data_->items.rbegin();}
        
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().rend - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().rend - Will be removed in version 0.4.0.")]]
        auto rend() noexcept {return data_->items.rend();}
        /// @brief Returns a reverse iterator to the end.
        /// @return The reverse iterator to the end.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().rend - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().rend - Will be removed in version 0.4.0.")]]
        auto rend() const noexcept {return data_->items.rend();}
        
        /// @brief Reserves storage.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().reserve - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().reserve - Will be removed in version 0.4.0.")]]
        void reserve(size_type size) {data_->items.reserve(size);}
        
        /// @brief Reduces memory usage by freeing unused memory.
        /// @deprecated Replaced by xtd::forms::layout::arranged_element_collection::items().shrink_to_fit - Will be removed in version 0.4.0.
        [[deprecated("Replaced by xtd::forms::layout::arranged_element_collection::items().shrink_to_fit - Will be removed in version 0.4.0.")]]
        void shrink_to_fit() {data_->items.shrink_to_fit();}
        /// @}
        
      protected:
        /// @name Protected Methods
        
        /// @{
        /// @brief Raises the xtd::forms::layout::arranged_element_collection::item_added event.
        /// @param index The index of the item.
        /// @param item The item added.
        virtual void on_item_added(size_t index, type_t& item) {item_added(index, item);}
        
        /// @brief Raises the xtd::forms::layout::arranged_element_collection::item_updated event.
        /// @param index The index of the item.
        /// @param item The item updated.
        virtual void on_item_updated(size_t index, type_t& item) {item_updated(index, item);}
        
        /// @brief Raises the xtd::forms::layout::arranged_element_collection::item_removed event.
        /// @param index The index of the item.
        /// @param item The item removed.
        virtual void on_item_removed(size_t index, type_t& item) {item_removed(index, item);}
        /// @}
        
      private:
        bool is_read_only() const noexcept override {return false;}
        bool is_synchronized() const noexcept override {return false;}
        const xtd::object& sync_root() const noexcept override {return data_->sync_root;}
        
        struct data_collection {
          mutable xtd::collections::generic::list < value_type > items;
          bool inserting = false;
          bool erasing = false;
          bool sorted = false;
          xtd::object sync_root;
        };
        ptr < data_collection > data_ = new_ptr < data_collection > ();
      };
    }
  }
}
