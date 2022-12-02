/// @file
/// @brief Contains xtd::box class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "convert_string.h"
#include "icomparable.h"
#include "invalid_cast_exception.h"
#include "iequatable.h"
#include "enum.h"
#include "object.h"
#include "ustring.h"
#include "types.h"
#define __XTD_CORE_INTERNAL__
#include "internal/__math.h"
#undef __XTD_CORE_INTERNAL__

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
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
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
    /// @name Constructors
    
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
    
    /// @name Properties
    
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
    
    /// @name Methods
    
    /// @{
    bool equals(const object& value) const noexcept override {return (dynamic_cast<const box<type_t>*>(&value) ? equals(static_cast<const box<type_t>&>(value)) : false);}
    bool equals(const box& value) const noexcept override {return value_ == value.value_;}
    
    int32_t compare_to(const object& value) const noexcept override {return (dynamic_cast<const box<type_t>*>(&value) ? compare_to(static_cast<const box<type_t>&>(value)) : -1);}
    int32_t compare_to(const box& value) const noexcept override {
      if (value_ == value.value_) return 0;
      if (value_ < value.value_) return -1;
      return 1;
    }
    
    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    static type_t parse(const xtd::ustring& value) {return xtd::parse<type_t>(value);}
    
    xtd::ustring to_string() const noexcept override {return xtd::ustring::format("{}", value_);}
    /// @brief Converts the value of this instance to its equivalent string representation, using the specified format.
    /// @param format A value type format string.
    /// @return The string representation of the value of this instance as specified by format.
    xtd::ustring to_string(const xtd::ustring& format) const noexcept {
      return xtd::ustring::format(xtd::ustring::format("{{:{}}}", format), value_);
    }
    
    /// @brief Converts the string to its type_t equivalent. A return value indicates whether the conversion succeeded or failed.
    /// @param value A string containing a type_t to convert.
    /// @param result A type_t equivalent to the number contained in value.
    /// @return true if s was converted successfully; otherwise, false.
    static bool try_parse(const xtd::ustring& value, type_t& result) noexcept {return xtd::try_parse<type_t>(value, result);}
    /// @}
    
  private:
    type_t value_ {};
  };
  
  /// @brief Represent a boxed bool.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following example shows how to create and use xtd::boolean_object.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// bool unboxed_object = true;
  /// boolean_object boxed_object = unboxed_bool;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = true;
  /// @endcode
  using boolean_object = box<bool>;
  
  /// @cond
  template<typename type_t, typename bool_t>
  struct __box_enum_or_object__;
  
  template<typename type_t>
  struct __box_enum_or_object__<type_t, std::true_type> {
    using type = xtd::enum_object<type_t>;
  };
  
  template<typename type_t>
  struct __box_enum_or_object__<type_t, std::false_type> {
    using type = typename std::conditional<std::is_base_of<xtd::object, type_t>::value, type_t, xtd::box<type_t>>::type;
  };
  
  inline const object& boxing(const object& value) {return value;}
  inline ustring boxing(const char* value) {return ustring(value);}
  inline ustring boxing(const char8_t* value) {return ustring(value);}
  inline ustring boxing(const char16_t* value) {return ustring(value);}
  inline ustring boxing(const char32_t* value) {return ustring(value);}
  inline ustring boxing(const wchar_t* value) {return ustring(value);}
  /// @endcond
  
  /// @brief Allows to box an object
  /// @param value Value used to initialize object.
  /// @return Boxed object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t>
  inline auto boxing(const type_t& value) {return typename __box_enum_or_object__<type_t, typename std::is_enum<type_t>::type>::type(value);}
  /// @brief Allows to box an object
  /// @param ...args  Params used to initialize object.
  /// @return Boxed object.
  /// @remarks The boxed object must implement operator == and operator < because a xtd::box implement xtd::icomparable and xtd::iequatable interfaces.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t, typename ...args_t>
  inline box<type_t> boxing(args_t&& ...args) {return box<type_t>(args...);}
  
  /// @brief Allows to unbox an object
  /// @param value Object to box.
  /// @return Unboxed object.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename type_t>
  inline type_t unboxing(const xtd::box<type_t>& value) {return value.value();}
  
  /// @cond
  template<typename type_t>
  inline type_t unboxing(const xtd::enum_object<type_t>& value) {return value.value();}
  
  inline const object& unboxing(const object& value) {return value;}
  inline const char* unboxing(ustring& value) {return value.c_str();}
  
  template<typename char_t>
  inline const char_t* unboxing(ustring& value) {throw invalid_cast_exception("Invalid character type");}
  
  template<>
  inline const char* unboxing<char>(ustring& value) {return value.c_str();}
  
  template<>
  inline const char8_t* unboxing<char8_t>(ustring& value) {
    thread_local static std::u8string result;
    result = convert_string::to_u8string(value);
    return result.c_str();
  }
  
  template<>
  inline const char16_t* unboxing<char16_t>(ustring& value) {
    thread_local static std::u16string result;
    result = convert_string::to_u16string(value);
    return result.c_str();
  }
  
  template<>
  inline const char32_t* unboxing<char32_t>(ustring& value) {
    thread_local static std::u32string result;
    result = convert_string::to_u32string(value);
    return result.c_str();
  }
  
  template<>
  inline const wchar_t* unboxing<wchar_t>(ustring& value) {
    thread_local static std::wstring result;
    result = convert_string::to_wstring(value);
    return result.c_str();
  }
  inline object& unboxing(object& value) {return value;}
  
  template<typename type_t>
  inline std::string to_string(const xtd::box<type_t>& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  /// @endcond
}

#include "box_char.h"
#include "box_floating_point.h"
#include "box_integer.h"

