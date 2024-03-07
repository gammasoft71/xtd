/// @file
/// @brief Contains xtd::box class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "convert_string.h"
#include "icomparable.h"
#include "iequatable.h"
#include "invalid_cast_exception.h"
#include "iequatable.h"
#include "enum.h"
#include "object.h"
#include "ustring.h"
#include "types.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a boxed object.
  /// @code
  /// class box : public xtd::icomparable<box<type_t>>, public xtd::iequatable<box<type_t>>, public xtd::object
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t>
  /// @par Implements
  /// xtd::icomparable <>, xtd::iequatable <>
  /// @par Header
  /// @code #include <xtd/box> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  /// @par Examples
  /// The following example shows how to create and use xtd::box<bool>.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// bool unboxed_object = true;
  /// box<bool> boxed_object = unboxed_bool;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = true;
  /// @endcode
  template<typename type_t>
  class box : public xtd::icomparable<box<type_t>>, public xtd::iequatable<box<type_t>>, public xtd::object {
  public:
    using underlying_type = type_t;
    /// @name Public Constructors
    
    /// @{
    /// @brief Initialize a new xtd::box object.
    box() = default;
    /// @brief Initialize a new xtd::box object with specified value.
    /// @param value Value used to initialize object.
    box(const type_t& value) : value_(value) {}
    /// @brief Initialize a new xtd::box object with specified value.
    /// @param ...args_t Params used to initialize object.
    template<typename ...args_t>
    box(args_t&& ...args) : value_(args...) {}
    /// @}
    
    /// @cond
    box(const box&) = default;
    box(box&&) = default;
    box& operator =(const box&) = default;
    box& operator =(const type_t& value) {
      value_ = value;
      return *this;
    };
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets the underlying value.
    /// @return Return the underlying value.
    const type_t& value() const noexcept {return value_;}
    /// @brief Gets the underlying value.
    /// @return Return the underlying value.
    type_t& value() noexcept {return value_;}
    /// @brief Sets de underlying value.
    /// @param value The value to set to the underlying value.
    box& value(const type_t& value) {
      value_ = value;
      return *this;
    }
    /// @}
    
    /// @name Opertors
    
    /// @{
    operator type_t() const noexcept {return value_;}
    /// @}
    
    /// @name Public Methods
    
    /// @{
    bool equals(const box& value) const noexcept override {return value_ == value.value_;}
    
    int32 compare_to(const box& value) const noexcept override {
      if (value_ == value.value_) return 0;
      if (value_ < value.value_) return -1;
      return 1;
    }
    
    xtd::ustring to_string() const noexcept override {return xtd::ustring::format("{}", value_);}
    /// @brief Converts the value of this instance to its equivalent string representation, using the specified format.
    /// @param format A value type format string.
    /// @return The string representation of the value of this instance as specified by format.
    xtd::ustring to_string(const xtd::ustring& format) const noexcept {
      return xtd::ustring::format(xtd::ustring::format("{{:{}}}", format), value_);
    }
    /// @}

    /// @name Public Static Methods
    
    /// @{
    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    static type_t parse(const xtd::ustring& value) {return xtd::parse<type_t>(value);}

    /// @brief Converts the string to its type_t equivalent. A return value indicates whether the conversion succeeded or failed.
    /// @param value A string containing a type_t to convert.
    /// @param result A type_t equivalent to the number contained in value.
    /// @return true if s was converted successfully; otherwise, false.
    static bool try_parse(const xtd::ustring& value, type_t& result) noexcept {return xtd::try_parse<type_t>(value, result);}
    /// @}
    
  private:
    type_t value_ {};
  };
}
