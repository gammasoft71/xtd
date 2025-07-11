/// @file
/// @brief Contains xtd::any_object class.
#pragma once
#include "collections/generic/helpers/comparer.hpp"
#include "boxing.hpp"
#include "enum_object.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "invalid_operation_exception.hpp"
#include "is.hpp"
#include "object.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a polymorphic wrapper capable of holding any type.
  /// @par Header
  /// ```cpp
  /// #include <xtd/any_object>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following code example illustrates the use of xtd::any_object class.
  /// @include any.cpp
  /// @remarks TTo add a class, structure or any other type unknown to xtd, you need to implement the xtd::iequatable and xtd::icompoabale interfaces or overrride the == and < operetors.
  class any_object : public object, public icomparable<any_object>, public iequatable<any_object> {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::any_object class.
    any_object() noexcept = default;
    /// @brief Initializes a new instance of the xtd::any_object class with specified value.
    /// @param value The value to initialize the contained value with.
    template<class type_t> // Can't be explicit by design.
    any_object(type_t&& value) noexcept : value_(boxing_ptr(value)) {}
    /// @brief Initializes a new instance of the xtd::any_object class with specified value.
    /// @param value The value to initialize the contained value with.
    template<class type_t> // Can't be explicit by design.
    any_object(type_t& value) noexcept : value_(boxing_ptr(value)) {}
    /// @brief Initializes a new instance of the xtd::any_object class with specified value.
    /// @param value The value to initialize the contained value with.
    template<class type_t> // Can't be explicit by design.
    any_object(const type_t& value) noexcept : value_(boxing_ptr(value)) {}
    /// @}
    
    /// @cond
    any_object(any_object&&) noexcept = default;
    any_object(any_object&) noexcept = default;
    any_object(const any_object&) noexcept = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets a value indicating whether the current xtd::any_object object has a valid value of its underlying type.
    /// @return `true` if the current xtd::any_object object has a value; `false` if the current xtd::any_object object has no value.
    /// @remarks If the xtd::any_object::has_value property is `true`, the value of the current xtd::any_object object can be accessed with the xtd::any_object::value property. Otherwise, attempting to access its value throws an xtd::invalid_operation_exception exception.
    bool has_value() const noexcept {return value_ != null;}
    
    /// @brief Gets the value of the current xtd::any_object object if it has been assigned a valid underlying value.
    /// @return The value of the current xtd::any_object object if the xtd::any_object::has_value property is `true`. An exception is thrown if the xtd::any_object::has_value property is `false`.
    /// @exception xtd::invalid_operation_exception The xtd::any_object::has_value property is `false`.
    const object& value() const {
      if (value_ == null) xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::invalid_operation);
      return *value_;
    }
    /// @}
    
    /// @name Public Methods
    
    /// @{
    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    ///
    /// | Value             | Condition                          |
    /// | ----------------- | ---------------------------------- |
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    int32 compare_to(const any_object& other) const noexcept override {
      if (!has_value() && other.has_value()) return -1;
      if (has_value() && !other.has_value()) return 1;
      return xtd::collections::generic::helpers::comparer<ptr<object>> {}(value_, other.value_);
    }
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const object& other) const noexcept override {return dynamic_cast<const any_object*>(&other) && equals(static_cast<const any_object&>(other));}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    bool equals(const any_object& other) const noexcept override {
      if (!has_value() && !other.has_value()) return true;
      if (has_value() != other.has_value()) return false;
      return value_->equals(*other.value_);
    }
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    xtd::size get_hash_code() const noexcept override {return has_value() ? value_->get_hash_code() : 0;}
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    string to_string() const noexcept override {return has_value() ? value_->to_string() : "(null)";}
    
    /// @brief Reset the current object. Set the current object to null.
    /// @remarks If xtd::any_object::has_values is `true`, destroys the contained object; otherwise does nothing.
    void reset() noexcept {value_.reset();}
    /// @}
    
    /// @name Public Operators
    
    /// @{
    /// @brief Copy assignment operator. Replaces the contents with a copy of the contents of other.
    /// @param other Another polymorphic wrapper.
    /// @return This current instance.
    any_object& operator =(const any_object& other) = default;
    /// @brief Move assignment operator. Replaces the contents with a copy of the contents of other.
    /// @param other Another polymorphic wrapper.
    /// @return This current instance.
    any_object& operator =(any_object&& other) {
      value_ = std::move(other.value_);
      return *this;
    };
    /// @}
    
  private:
    template<class type_t>
    inline ptr<object> boxing_ptr(const type_t& value) noexcept {return new_ptr<typename __box_enum_or_object__<type_t, typename std::is_enum<type_t>::type>::type>(value);}
    template<class type_t, class ...args_t>
    inline ptr<object> boxing_ptr(args_t&& ...args) noexcept {return new box<type_t>(args...);}
    //inline ptr<object> boxing_ptr(const object& value) noexcept {return new value;}
    inline ptr<object> boxing_ptr(const char* value) noexcept {return new_ptr<string>(value);}
    inline ptr<object> boxing_ptr(const char8* value) noexcept {return  new_ptr<string>(value);}
    inline ptr<object> boxing_ptr(const char16* value) noexcept {return new_ptr<string>(value);}
    inline ptr<object> boxing_ptr(const char32* value) noexcept {return new_ptr<string>(value);}
    inline ptr<object> boxing_ptr(const wchar* value) noexcept {return new_ptr<string>(value);}
    inline ptr<object> boxing_ptr(const char& value) noexcept {return new_ptr<char_object>(value);}
    inline ptr<object> boxing_ptr(const char8& value) noexcept {return new_ptr<char8_object>(value);}
    inline ptr<object> boxing_ptr(const char16& value) noexcept {return new_ptr<char16_object>(value);}
    inline ptr<object> boxing_ptr(const char32& value) noexcept {return new_ptr<char32_object>(value);}
    inline ptr<object> boxing_ptr(const wchar& value) noexcept {return new_ptr<wchar_object>(value);}
    inline ptr<object> boxing_ptr(char& value) noexcept {return new_ptr<char_object>(value);}
    inline ptr<object> boxing_ptr(char8& value) noexcept {return new_ptr<char8_object>(value);}
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
    inline ptr<object> boxing_ptr(std::nullptr_t value) noexcept {return ptr<object> {};}
    
    ptr<object> value_;
  };
  
  /// @cond
  template<class type_t, class bool_t>
  struct __is_enum_any_object__ {};
  
  template<class type_t>
  struct __is_enum_any_object__<type_t, std::true_type> {
    bool operator()(const any_object& o) const {return is<enum_object<type_t>>(o.value());}
  };
  
  template<class type_t>
  struct __is_enum_any_object__<type_t, std::false_type> {
    bool operator()(const any_object& o) const {return false;}
  };
  
  template<class type_t, class bool_t>
  struct __is_polymorphic_any_object__ {};
  
  template<class type_t>
  struct __is_polymorphic_any_object__<type_t, std::true_type> {
    bool operator()(const any_object& o) const {return is<type_t>(o.value());}
  };
  
  template<class type_t>
  struct __is_polymorphic_any_object__<type_t, std::false_type> {
    bool operator()(const any_object& o) const {return __is_enum_any_object__<type_t, typename std::is_enum<type_t>::type> {}(o);}
  };
  
  template<class type_t>
  bool is(any_object& o) {
    if (is<box<type_t>>(o.value())) return true;
    return __is_polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type > {}(o);
  }
  
  template<class type_t>
  bool is(const any_object& o) {
    if (is<box<type_t>>(o.value())) return true;
    return __is_polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type > {}(o);
  }
  
  template<class type_t>
  bool is(any_object* o) {
    if (is<box<type_t>>(o->value())) return true;
    return __is_polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type > {}(*o);
  }
  
  template<class type_t>
  bool is(const any_object* o) {
    if (is<box<type_t>>(o->value())) return true;
    return __is_polymorphic_any_object__<type_t, typename std::is_polymorphic<type_t>::type > {}(*o);
  }
  /// @endcond
}
