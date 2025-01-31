/// @file
/// @brief Contains Switch::System::Collections::bit_array class.
#pragma once

#include "generic/list.hpp"
#include "../iclonable.hpp"
#include "../iequatable.hpp"
#include "../array.hpp"
#include "../boolean.hpp"
#include "../byte.hpp"
#include "../int32.hpp"
#include "../object.hpp"
#include "../size.hpp"
#include "../types.hpp"
#include <bitset>
#include <initializer_list>
#include <limits>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::collections namespace contains interfaces and classes that define various collections of objects, such as lists, queues, bit arrays, hash tables and dictionaries.
  namespace collections {
    /// @brief Manages a compact array of bit values, which are represented as booleans, where `true` indicates that the bit is on (1) and `false` indicates the bit is off (0).
    /// ```cpp
    /// class core_export_ bit_array : public xtd::object, public xtd::iequatable<bit_array>, public xtd::collections::generic::icollection<bool>, public xtd::iclonable;
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/collections/bit_array>
    /// ```
    /// @par Namespace
    /// xtd::collections
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    /// @par Examples
    /// The following code example shows how to create and initialize a xtd::collections::bit_array and how to print out its values.
    /// @include bit_array.cpp
    class core_export_ bit_array : public xtd::object, public xtd::iequatable<bit_array>, public xtd::collections::generic::icollection<bool>, public xtd::iclonable {
    private:
      struct boolean_ref {
        boolean_ref() noexcept = default;
        bool& get_boolean_ref(bool value, xtd::size index) noexcept;
        const bool& get_boolean_ref(bool value, xtd::size index) const noexcept;
        void from_boolean(bit_array& parent) noexcept;
        
        static constexpr xtd::size npos = std::numeric_limits<xtd::size>::max();
        mutable xtd::size index = npos;
        mutable bool value = false;
      };

    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents the list value type.
      using value_type = bool;
      /// @brief Represents the list allocator type.
      using allocator_type = typename xtd::collections::generic::list<int32>::allocator_type;
      /// @brief Represents the list base type.
      using base_type =  typename xtd::collections::generic::list<int32>;
      /// @brief Represents the list size type (usually xtd::size).
      using size_type = xtd::size;
      /// @brief Represents the list difference type (usually xtd::ptrdiff).
      using difference_type = xtd::ptrdiff;
      /// @brief Represents the reference of list value type.
      using reference = value_type&;
      /// @brief Represents the const reference of list value type.
      using const_reference = const value_type&;
      /// @brief Represents the pointer of list value type.
      using pointer = value_type*;
      /// @brief Represents the const pointer of list value type.
      using const_pointer = const value_type*;
      /// @brief Represents the iterator of list value type.
      using iterator = typename xtd::collections::generic::ienumerable<bool>::iterator;
      /// @brief Represents the const iterator of list value type.
      using const_iterator = typename xtd::collections::generic::ienumerable<bool>::const_iterator;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::collections::bit_array class that can hold the specified number of bit values, which are initially set to `false`.
      /// @param length_ The number of bit values in the new xtd::collections::bit_array.
      /// @exception xtd::argument_out_of_range_exception length_ is less than 0.
      /// @remarks This constructor is an O(n) operation, where n is length_.
      explicit bit_array(xtd::size length);
      
      /// @brief Initializes a new instance of the xtd::collections::bit_array class that can hold the specified number of bit values, which are initially set to the specified value.
      /// @param length_ The number of bit values in the new xtd::collections::bit_array.
      /// @param defaultValueThe bool value to assign to each bit.
      /// @exception xtd::argument_out_of_range_exception length_ is less than 0.
      /// @remarks This constructor is an O(n) operation, where n is length_.
      bit_array(xtd::size length, bool defaultValue);

      /// @brief Initializes a new instance of the xtd::collections::bit_array class that contains bit values copied from the specified initializer list of booleans.
      /// @param values An array of booleans to copy.
      /// @remarks This constructor is an O(n) operation, where n is the number of elements in values.
      bit_array(std::initializer_list<bool> il);

      /// @brief Initializes a new instance of the xtd::collections::bit_array class that contains bit values copied from the specified array of booleans.
      /// @param values An initializer list of booleans to copy.
      /// @remarks This constructor is an O(n) operation, where n is the number of elements in values.
      bit_array(const xtd::array<bool>& values);
      
      /// @brief Initializes a new instance of the xtd::collections::bit_array class that contains bit values copied from the specified array of bytes.
      /// @param values An array of bytes containing the values to copy, where each byte represents eight consecutive bits.
      /// @remarks The first byte in the array represents bits 0 through 7, the second byte represents bits 8 through 15, and so on. The Least Significant Bit of each byte represents the lowest index value: " bytes [0] & 1" represents bit 0, " bytes [0] & 2" represents bit 1, " bytes [0] & 4" represents bit 2, and so on.
      /// @remarks This constructor is an O(n) operation, where n is the number of elements in values.
      bit_array(const xtd::array<xtd::byte>& values);

      /// @brief Initializes a new instance of the xtd::collections::bit_array class that contains bit values copied from the specified array of 32-bit integers.
      /// @param values An array of integers containing the values to copy, where each integer represents 32 consecutive bits.
      /// @remarks The number in the first values array element represents bits 0 through 31, the second number in the array represents bits 32 through 63, and so on. The Least Significant Bit of each integer represents the lowest index value: " values [0] & 1" represents bit 0, " values [0] & 2" represents bit 1, " values [0] & 4" represents bit 2, and so on.
      /// @remarks This constructor is an O(n) operation, where n is the number of elements in values.
      bit_array(const xtd::array<int32>& values);
      /// @}

      /// @cond
      bit_array(bit_array&& bits) = default;
      bit_array& operator=(bit_array&&) = default;
      bit_array(const bit_array& bits) = default;
      bit_array& operator=(const bit_array&) = default;
      template<xtd::size length>
      bit_array(const std::bitset<length>& bit_set) {
        length_ = length;
        while (bit_array_.count() < get_list_length(length_))
          bit_array_.add(0);
        for (auto index = xtd::size {0}; index < length; index++)
          set(index, bit_set.test(index));
      }
      /// @endcond

      /// @name Public Properties

      /// @{
      
      /// @brief Returns an iterator to the first element of the enumarable.
      /// @return Iterator to the first element.
      const_iterator begin() const noexcept override {return xtd::collections::generic::ienumerable<value_type>::begin();}
      /// @brief Returns an iterator to the first element of the enumarable.
      /// @return Iterator to the first element.
      iterator begin() noexcept override {return xtd::collections::generic::ienumerable<value_type>::begin();}
      
      /// @brief Returns an iterator to the first element of the enumarable.
      /// @return Iterator to the first element.
      const_iterator cbegin() const noexcept override {return xtd::collections::generic::ienumerable<value_type>::cbegin();}
      
      /// @brief Returns an iterator to the element following the last element of the enumarable.
      /// @return Iterator to the element following the last element.
      const_iterator cend() const noexcept override {return xtd::collections::generic::ienumerable<value_type>::cend();}
      
      /// @brief Gets the number of elements contained in the xtd::collections::bit_array.
      /// @return The number of elements contained in the xtd::collections::bit_array.
      /// @remarks Retrieving the value of this property is an O(1) operation; setting the property is an O(n) operation, where n is the new capacity.
      xtd::size count() const noexcept override;
      
      /// @brief Checks if the container has no elements, i.e. whether xtd::collections::bit_array::begin() == xtd::collections::bit_array::end().
      /// @return `true` if the container is empty, `false` otherwise.
      virtual bool empty() const noexcept {return !length();}
      
      /// @brief Returns an iterator to the element following the last element of the enumarable.
      /// @return Iterator to the element following the last element.
      const_iterator end() const noexcept override {return xtd::collections::generic::ienumerable<value_type>::end();}
      /// @brief Returns an iterator to the element following the last element of the enumarable.
      /// @return Iterator to the element following the last element.
      iterator end() noexcept override {return xtd::collections::generic::ienumerable<value_type>::end();}

      /// @brief Gets the number of elements contained in the xtd::collections::bit_array.
      /// @return The number of elements contained in the xtd::collections::bit_array.
      /// @remarks xtd::collections::bit_array::length and xtd::collections::bit_array::count return the same value. xtd::collections::bit_array::length can be set to a specific value.
      xtd::size length() const noexcept;
      /// @brief Sets the number of elements contained in the xtd::collections::bit_array.
      /// @param value The number of elements contained in the xtd::collections::bit_array.
      /// @remarks xtd::collections::bit_array::length and xtd::collections::bit_array::count return the same value. xtd::collections::bit_array::length can be set to a specific value.
      void length(xtd::size value);

      bool is_read_only() const noexcept override;

      bool is_synchronized() const noexcept override;

      const object& sync_root() const noexcept override;
      /// @}

      /// @name Public Methods
      
      /// @{
      /// @brief Performs the bitwise AND operation on the elements in the current xtd::collections::bit_array against the corresponding elements in the specified xtd::collections::bit_array.
      /// @param value The xtd::collections::bit_array with which to perform the bitwise AND operation.
      /// @return The current instance containing the result of the bitwise AND operation on the elements in the current xtd::collections::bit_array against the corresponding elements in the specified xtd::collections::bit_array.
      /// @exception xtd::argument_exception value and the current xtd::collections::bit_array do not have the same number of elements.
      /// @remarks The bitwise AND operation returns `true` if both operands are true, and returns `false` if one or both operands are `false`.
      /// @remarks This method is an O(n) operation, where n is count.
      const bit_array& and_(const bit_array& value);

      /// @brief Gets the value of the bit at a specific position in the xtd::collections::bit_array.
      /// @param index The zero-based index of the value to get.
      /// @return The value of the bit at position index.
      /// @exception xtd::argument_out_of_range_exception index is less than zero. -or- index is greater than or equal to the number of elements in the xtd::collections::bit_array.
      /// @remarks This method is an O(1) operation.
      bool at(xtd::size index) const;
      
      /// @brief Gets the value of the bit at a specific position in the xtd::collections::bit_array.
      /// @param index The zero-based index of the value to get.
      /// @return The value of the bit at position index.
      /// @exception xtd::argument_out_of_range_exception index is less than zero. -or- index is greater than or equal to the number of elements in the xtd::collections::bit_array.
      /// @remarks This method is an O(1) operation.
      bool& at(xtd::size index);

      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      xtd::uptr<xtd::object> clone() const override;
 
      /// @brief Copies the elements of the xtd::collections::bit_array to an xtd::array, starting at a particular xtd::array index.
      /// @param array The one-dimensional xtd::array that is the destination of the elements copied from xtd::collections::bit_array. The xtd::array must have zero-based indexing.
      /// @param index The zero-based index in array at which copying begins;
      /// @return Number of elements copied.
      void copy_to(xtd::array<bool>& array, xtd::size index) const override;

      /// @brief Determines whether this instance of xtd::collections::bit_array and a specified object, which must also be a xtd::collections::bit_array object, have the same value.
      /// @param value The xtd::collections::bit_array to compare with the current object.
      /// @return `true` if the specified value is equal to the current object. otherwise, `false`.
      bool equals(const bit_array& value) const noexcept override;

      /// @brief Determines whether this instance of xtd::collections::bit_array and a specified object, which must also be a xtd::collections::bit_array object, have the same value.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      bool equals(const object& obj) const noexcept override;

      /// @brief Gets the value of the bit at a specific position in the xtd::collections::bit_array.
      /// @param index The zero-based index of the value to get.
      /// @return The value of the bit at position index.
      /// @exception xtd::argument_out_of_range_exception index is less than zero. -or- index is greater than or equal to the number of elements in the xtd::collections::bit_array.
      /// @remarks This method is an O(1) operation.
      bool get(xtd::size index) const;

      /// @brief Gets the value of the bit at a specific position in the xtd::collections::bit_array.
      /// @param index The zero-based index of the value to get.
      /// @return The value of the bit at position index.
      /// @exception xtd::argument_out_of_range_exception index is less than zero. -or- index is greater than or equal to the number of elements in the xtd::collections::bit_array.
      /// @remarks This method is an O(1) operation.
      bool& get(xtd::size index);

      /// @brief Returns an enumerator that iterates through a collection.
      /// @return An xtd::collection::generic::ienumerator object that can be used to iterate through the collection.
      xtd::collections::generic::enumerator<bool> get_enumerator() const override;

      /// @brief Inverts all the bit values in the current xtd::collections::bit_array, so that elements set to `true` are changed to `false`, and elements set to `false` are changed to true.
      /// @return The current instance with inverted bit values.
      /// @remarks This method is an O(n) operation, where n is count.
      const bit_array& not_();

      /// @brief Performs the bitwise OR operation on the elements in the current xtd::collections::bit_array against the corresponding elements in the specified xtd::collections::bit_array.
      /// @param value The xtd::collections::bit_array with which to perform the bitwise OR operation.
      /// @return The current instance containing the result of the bitwise OR operation on the elements in the current xtd::collections::bit_array against the corresponding elements in the specified xtd::collections::bit_array.
      /// @exception xtd::argument_exception value and the current xtd::collections::bit_array do not have the same number of elements.
      /// @remarks The bitwise OR operation returns `true` if one or both operands are `true`, and returns `false` if both operands are `false`.
      /// @remarks This method is an O(n) operation, where n is count.
      const bit_array& or_(const bit_array& value);

      /// @brief Sets the value of the bit at a specific position in the xtd::collections::bit_array.
      /// @param index The zero-based index of the value to get.
      /// @param value The bool value to assign to the bit.
      /// @exception xtd::argument_out_of_range_exception index is less than zero. -or- index is greater than or equal to the number of elements in the xtd::collections::bit_array.
      /// @remarks This method is an O(1) operation.
      void set(xtd::size index, bool value);

      /// @brief Sets all bits in the xtd::collections::bit_array to the specified value.
      /// @param value The bool value to assign to all bits.
      /// @remarks This method is an O(n) operation, where n is count.
      void set_all(bool value);
      
      xtd::string to_string() const noexcept override;

      /// @brief Performs the bitwise exclusive OR operation on the elements in the current xtd::collections::bit_array against the corresponding elements in the specified xtd::collections::bit_array.
      /// @param value The xtd::collections::bit_array with which to perform the bitwise exclusive OR operation.
      /// @return The current instance containing the result of the bitwise exclusive OR operation on the elements in the current xtd::collections::bit_array against the corresponding elements in the specified xtd::collections::bit_array.
      /// @exception xtd::argument_exception value and the current xtd::collections::bit_array do not have the same number of elements.
      /// @remarks The bitwise exclusive OR operation returns `true` if exactly one operand is `true`, and returns `false` if both operands have the same bool value.
      /// @remarks This method is an O(n) operation, where n is count.
      const bit_array& xor_(const bit_array& value);
      /// @}

      /// @name Public Operators
      
      /// @{
      /// @brief Gets the element at the specified index.
      /// @param index The zero-based index of the element to get.
      /// @return The element at the specified index.
      /// @exception xtd::argument_out_of_range_exception index is less than 0 or index is equal to or greater than count.
      const bool& operator[](xtd::size index) const;

      /// @brief Gets or Sets the element at the specified index.
      /// @param index The zero-based index of the element to get.
      /// @return The element at the specified index.
      /// @exception xtd::argument_out_of_range_exception index is less than 0 or index is equal to or greater than count.
      bool& operator[](xtd::size index);
      /// @}

    private:
      void add(const bool&) override;
      void clear() override;
      bool contains(const bool&) const noexcept override;
      bool remove(const bool&) override;


      inline xtd::size get_list_length(xtd::size length_) const noexcept;
      inline xtd::size get_list_position(xtd::size index) const noexcept;
      inline xtd::size get_bit_position(xtd::size index) const noexcept;
      bool get_bit_value(xtd::size index) const noexcept;
      void set_bit_value(xtd::size index, bool value) noexcept;

      static constexpr xtd::size bits_per_byte   = 8;
      static constexpr xtd::size bits_per_int32  = 32;
      static constexpr xtd::size bytes_per_int32 = 4;
      boolean_ref value_ref_;
      xtd::collections::generic::list<int32> bit_array_;
      xtd::size length_ = 0;
    };
  }
}
