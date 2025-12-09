/// @file
/// @brief Contains xtd::box struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/helpers/comparer.hpp"
#include "collections/generic/helpers/equator.hpp"
#include "convert_string.hpp"
#include "hash_code.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "invalid_cast_exception.hpp"
#include "iequatable.hpp"
#include "iformatable.hpp"
#include "istringable.hpp"
#include "is.hpp"
#include "object.hpp"
#include "string.hpp"
#include "types.hpp"
#include "typeof.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a boxed object.
  /// ```cpp
  /// template<class type_t>
  /// struct box : xtd::object, xtd::icomparable<box<type_t>>, xtd::iequatable<box<type_t>>, xtd::iformatable;
  /// ```
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t>
  /// @par Implements
  /// xtd::icomparable <>, xtd::iequatable <>
  /// @par Header
  /// ```cpp
  /// #include <xtd/box>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  /// @par Examples
  /// The following example shows how to create and use xtd::box<bool>.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// bool unboxed_object = true;
  /// box<bool> boxed_object = unboxed_bool;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = true;
  /// ```
  template<class type_t>
  struct box : xtd::object, xtd::icomparable<box<type_t>>, xtd::iequatable<box<type_t >>, xtd::iformatable {
    /// @name Public Aliases
    
    /// @{
    /// Represents the value type.
    using value_type = type_t;
    
    /// Represents the reference type.
    using reference = type_t&;
    
    /// Represents the cont reference type.
    using const_reference = const type_t&;
    
    /// Represents the reference type.
    using pointer = type_t*;
    
    /// Represents the cont reference type.
    using const_pointer = const type_t*;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialize a new xtd::box object.
    box() = default;
    /// @brief Initialize a new xtd::box object with specified value.
    /// @param value Value used to initialize object.
    box(const_reference value) : value(value) {}
    /// @brief Initialize a new xtd::box object with specified value.
    /// @param ...args_t Params used to initialize object.
    template<class ...args_t>
    box(args_t&& ...args) : value(args...) {}
    /// @}
    
    /// @cond
    box(box&&) = default;
    box(const box&) = default;
    box& operator =(box&&) = default;
    box& operator =(const box&) = default;
    box& operator =(const_reference value) {
      this->value = value;
      return *this;
    };
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets or sets the underlying value.
    /// @param value The value to set to the underlying value.
    value_type value {};
    /// @}
    
    /// @name Public Opertors
    
    /// @{
    /// @brief Cast operator to the value type.
    /// @return The xtd::box current instnce to `value_type`.
    operator value_type() const noexcept {return value;}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Compares the current instance with another object of the same type.
    /// @param value An object to compare with this instance.
    /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    ///
    /// | Value             | Condition                          |
    /// | ----------------- | ---------------------------------- |
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    int32 compare_to(const box& value) const noexcept override {return xtd::collections::generic::helpers::comparer<value_type> {}(this->value, value.value);}
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const object& obj) const noexcept override {return is<box<value_type>>(obj) && equals(static_cast<const box<value_type>& > (obj));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    bool equals(const box& value) const noexcept override {return xtd::collections::generic::helpers::equator<value_type> {}(this->value, value.value);}
    
    /// @brief Serves as a hash function for a particular type.
    /// @return size_t A hash code for the current object.
    xtd::size get_hash_code() const noexcept override {return hash_code::combine(value);}
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    xtd::string to_string() const noexcept override;
    /// @brief Converts the value of this instance to its equivalent string representation, using the specified format.
    /// @param format A value type format string.
    /// @return The string representation of the value of this instance as specified by format.
    xtd::string to_string(const xtd::string& format) const;
    /// @brief Converts the value of this instance to its equivalent string representation, using the specified format, and locale.
    /// @param format A value type format string.
    /// @param culture An xtd::globalization::culture_info object that contains culture information.
    /// @return The string representation of the value of this instance as specified by format.
    xtd::string to_string(const xtd::string& format, const globalization::culture_info& culture) const override;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @brief Converts the string to its `value_type` equivalent.
    /// @param value A string containing a `value_type` to convert.
    /// @return A `value_type` equivalent to the native value contained in value.
    static value_type parse(const xtd::string& value) {return xtd::parse<value_type>(value);}
    
    /// @brief Converts the string to its `value_type` equivalent. A return value indicates whether the conversion succeeded or failed.
    /// @param value A string containing a `value_type` to convert.
    /// @param result A `value_type` equivalent to the native value contained in value.
    /// @return `true` if s was converted successfully; otherwise, `false`.
    static bool try_parse(const xtd::string& value, reference result) noexcept {return xtd::try_parse<value_type>(value.chars(), result);}
    /// @}
  };
}
