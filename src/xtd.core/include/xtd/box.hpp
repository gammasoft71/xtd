/// @file
/// @brief Contains xtd::box class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "collections/generic/helpers/comparer.hpp"
#include "collections/generic/helpers/equator.hpp"
#include "convert_string.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "invalid_cast_exception.hpp"
#include "iequatable.hpp"
#include "iformatable.hpp"
#include "is.hpp"
#include "enum.hpp"
#include "object.hpp"
#include "string.hpp"
#include "types.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a boxed object.
  /// ```cpp
  /// class box : public xtd::icomparable<box<type_t>>, public xtd::iequatable<box<type_t>>, public xtd::object
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
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types).
  /// @par Examples
  /// The following example shows how to create and use xtd::box<bool>.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// bool unboxed_object = true;
  /// box<bool> boxed_object = unboxed_bool;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = true;
  /// ```
  template<typename type_t>
  class box : public xtd::object, public xtd::icomparable<box<type_t>>, public xtd::iequatable<box<type_t>>, public xtd::iformatable {
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
    int32 compare_to(const box& value) const noexcept override {return equals(value) ? 0 : xtd::collections::generic::helpers::comparer<type_t> {}(value_, value.value_) ? -1 : 1;}
    bool equals(const object& obj) const noexcept override {return is<box<type_t>>(obj) && equals(static_cast<const box<type_t>&>(obj));}
    bool equals(const box& value) const noexcept override {return xtd::collections::generic::helpers::equator<type_t> {}(value_, value.value_);}
    xtd::string to_string() const noexcept override {return std::is_integral<type_t>::value || std::is_floating_point<type_t>::value || std::is_enum<type>::value || std::is_pointer<type>::value || std::is_base_of<xtd::object, type_t>::value ? xtd::string::format("{}", value_) : typeof_<type_t>().full_name();}
    /// @brief Converts the value of this instance to its equivalent string representation, using the specified format.
    /// @param format A value type format string.
    /// @return The string representation of the value of this instance as specified by format.
    xtd::string to_string(const xtd::string& format) const {return to_string(format, std::locale {});}
    /// @brief Converts the value of this instance to its equivalent string representation, using the specified format, and locale.
    /// @param format A value type format string.
    /// @param loc An std::locale object that contains locale information (see [std::locale](https://en.cppreference.com/w/cpp/locale/locale)).
    /// @return The string representation of the value of this instance as specified by format.
    xtd::string to_string(const xtd::string& format, const std::locale& loc) const override {return xtd::string::format(xtd::string::format("{{:{}}}", format), value_);}
    /// @}

    /// @name Public Static Methods
    
    /// @{
    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    static type_t parse(const xtd::string& value) {return xtd::parse<type_t>(value);}

    /// @brief Converts the string to its type_t equivalent. A return value indicates whether the conversion succeeded or failed.
    /// @param value A string containing a type_t to convert.
    /// @param result A type_t equivalent to the number contained in value.
    /// @return true if s was converted successfully; otherwise, false.
    static bool try_parse(const xtd::string& value, type_t& result) noexcept {return xtd::try_parse<type_t>(value.chars(), result);}
    /// @}
    
  private:
    type_t value_ {};
  };
}
