/// @file
/// @brief Contains std::any type and xtd::any_object class.
#pragma once
#include "as.h"
#include "boxing.h"
#include "is.h"
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a type-safe container for single values of any copy constructible type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/any_object>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class any_object : public object, iequatable<any_object> {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @breif Constructs a new any object.
    any_object() noexcept = default;
    any_object(any_object&&) = default;
    explicit any_object(const any_object&) noexcept = default;
    /// @brief Constructs a new any object.
    /// @param value
    template<typename type_t>
    explicit any_object(type_t&& value) : value_(boxing_ptr(value)) {}
    template<typename type_t>
    explicit any_object(const type_t& value) : value_(boxing_ptr(value)) {}
    /// @}
    
    /// @name Public Properties
    
    /// @{
    /// @brief checks if object holds a value
    /// @return true if this current instance conatains a value; otherwhise false.
    bool has_value() const noexcept {return value_ != null;}
    
    const object& value() const {
      if (value_ == null) throw argument_exception {csf_};
      return *value_;
    }
    /// @}
    
    /// @name Public Methods
    
    /// @{
    bool equals(const object& other) const noexcept override {return is<any_object>(other) && equals(as<any_object>(other));}
    bool equals(const any_object& other) const noexcept override {return *value_ == *other.value_;}
    ustring to_string() const noexcept override {return has_value() ? value_->to_string() : "(null)";}
    
    /// @brief If not empty, destroys the contained object.
    void reset() noexcept {value_.reset();}
    /// @}
    
    /// @name Public Operators
    
    /// @{
    any_object& operator =(const any_object&) = default;
    any_object& operator =(any_object&& o) {
      value_ = std::move(o.value_);
      return *this;
    };
    template<typename type_t>
    any_object& operator =(const type_t& value) {
      value_ = boxing_ptr(value);
      return *this;
    };
    /// @}
    
  private:
    template<typename type_t>
    inline ptr<object> boxing_ptr(const type_t& value) noexcept {return new_ptr<typename __box_enum_or_object__<type_t, typename std::is_enum<type_t>::type>::type>(value);}
    template<typename type_t, typename ...args_t>
    inline ptr<object> boxing_ptr(args_t&& ...args) noexcept {return new box<type_t>(args...);}
    //inline ptr<object> boxing_ptr(const object& value) noexcept {return new value;}
    inline ptr<object> boxing_ptr(const char* value) noexcept {return new_ptr<ustring>(value);}
#if defined(__xtd__cpp_lib_char8_t)
    inline ptr<object> boxing_ptr(const char8* value) noexcept {return  new_ptr<ustring>(value);}
#endif
    inline ptr<object> boxing_ptr(const char16* value) noexcept {return new_ptr<ustring>(value);}
    inline ptr<object> boxing_ptr(const char32* value) noexcept {return new_ptr<ustring>(value);}
    inline ptr<object> boxing_ptr(const wchar* value) noexcept {return new_ptr<ustring>(value);}
    inline ptr<object> boxing_ptr(const char& value) noexcept {return new_ptr<char_object>(value);}
#if defined(__xtd__cpp_lib_char8_t)
    inline ptr<object> boxing_ptr(const char8& value) noexcept {return new_ptr<char8_object>(value);}
#endif
    inline ptr<object> boxing_ptr(const char16& value) noexcept {return new_ptr<char16_object>(value);}
    inline ptr<object> boxing_ptr(const char32& value) noexcept {return new_ptr<char32_object>(value);}
    inline ptr<object> boxing_ptr(const wchar& value) noexcept {return new_ptr<wchar_object>(value);}
    inline ptr<object> boxing_ptr(char& value) noexcept {return new_ptr<char_object>(value);}
#if defined(__xtd__cpp_lib_char8_t)
    inline ptr<object> boxing_ptr(char8& value) noexcept {return new_ptr<char8_object>(value);}
#endif
    inline ptr<object> boxing_ptr(char16& value) noexcept {return new_ptr<char16_object>(value);}
    inline ptr<object> boxing_ptr(char32& value) noexcept {return new_ptr<char32_object>(value);}
    inline ptr<object> boxing_ptr(wchar& value) noexcept {return new_ptr<wchar_object>(value);}
    inline ptr<object> boxing_ptr(const xtd::byte& value) noexcept {return new_ptr<byte_object>(value);}
    inline ptr<object> boxing_ptr(const int16& value) noexcept {return new_ptr<int16_object>(value);}
    inline ptr<object> boxing_ptr(const int32& value) noexcept {return new_ptr<int32_object>(value);}
    inline ptr<object> boxing_ptr(const int64& value) noexcept {return new_ptr<int64_object>(value);}
    inline ptr<object> boxing_ptr(const slong& value) noexcept {return new_ptr<slong_object>(value);}
    inline ptr<object> boxing_ptr(const sbyte& value) noexcept {return new_ptr<sbyte_object>(value);}
    inline ptr<object> boxing_ptr(const uint16& value) noexcept {return new_ptr<uint16_object>(value);}
    inline ptr<object> boxing_ptr(const uint32& value) noexcept {return new_ptr<uint32_object>(value);}
    inline ptr<object> boxing_ptr(const uint64& value) noexcept {return new_ptr<uint64_object>(value);}
    inline ptr<object> boxing_ptr(const xtd::ulong& value) noexcept {return new_ptr<ulong_object>(value);}
    inline ptr<object> boxing_ptr(xtd::byte& value) noexcept {return new_ptr<byte_object>(value);}
    inline ptr<object> boxing_ptr(int16& value) noexcept {return new_ptr<int16_object>(value);}
    inline ptr<object> boxing_ptr(int32& value) noexcept {return new_ptr<int32_object>(value);}
    inline ptr<object> boxing_ptr(int64& value) noexcept {return new_ptr<int64_object>(value);}
    inline ptr<object> boxing_ptr(slong& value) noexcept {return new_ptr<slong_object>(value);}
    inline ptr<object> boxing_ptr(sbyte& value) noexcept {return new_ptr<sbyte_object>(value);}
    inline ptr<object> boxing_ptr(uint16& value) noexcept {return new_ptr<uint16_object>(value);}
    inline ptr<object> boxing_ptr(uint32& value) noexcept {return new_ptr<uint32_object>(value);}
    inline ptr<object> boxing_ptr(uint64& value) noexcept {return new_ptr<uint64_object>(value);}
    inline ptr<object> boxing_ptr(xtd::ulong& value) noexcept {return new_ptr<ulong_object>(value);}
    inline ptr<object> boxing_ptr(const float& value) noexcept {return new_ptr<single_object>(value);}
    inline ptr<object> boxing_ptr(const double& value) noexcept {return new_ptr<double_object>(value);}
    inline ptr<object> boxing_ptr(const decimal& value) noexcept {return new_ptr<decimal_object>(value);}
    inline ptr<object> boxing_ptr(float& value) noexcept {return new_ptr<single_object>(value);}
    inline ptr<object> boxing_ptr(double& value) noexcept {return new_ptr<double_object>(value);}
    inline ptr<object> boxing_ptr(decimal& value) noexcept {return new_ptr<decimal_object>(value);}
    inline ptr<object> boxing_ptr(nullptr_t value) noexcept {return ptr<object> {};}
    
    ptr<object> value_;
  };
}
