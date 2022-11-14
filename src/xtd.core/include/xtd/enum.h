/// @file
/// @brief Contains xtd::enum_object.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include "format_exception.h"
#include "icomparable.h"
#include "static.h"
#include "enum_type.h"
#include "ustring.h"
#include <mutex>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename enum_t>
  using enum_collection = std::vector<std::pair<enum_t, xtd::ustring>>;
  
  /// @cond
  template<typename enum_t>
  struct enum_register {
    void operator()(xtd::enum_collection<enum_t>& values, xtd::enum_type& type) {}
  };
  /// @endcond
  
  /// @brief Provides the base class for enumerations.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<typename enum_t = std::nullptr_t>
  class enum_object : public xtd::object, public icomparable<enum_object<enum_t>> {
  public:
    /// @name Alias
    
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::enum_object class.
    enum_object() noexcept = default;
    /// @brief Initializes a new instance of the xtd::enum_object class with specified value.
    /// @param value Value to set to this instance.
    enum_object(enum_t value) : value_(value) {}
    /// @}

    /// @cond
    enum_object(byte_t value) : value_(to_enum(value)) {}
    enum_object(sbyte_t value) : value_(to_enum(value)) {}
    enum_object(int16_t value) : value_(to_enum(value)) {}
    enum_object(int32_t value) : value_(to_enum(value)) {}
    enum_object(int64_t value) : value_(to_enum(value)) {}
    enum_object(uint16_t value) : value_(to_enum(value)) {}
    enum_object(uint32_t value) : value_(to_enum(value)) {}
    enum_object(uint64_t value) : value_(to_enum(value)) {}
    enum_object(enum_object&&) noexcept = default;
    enum_object(const enum_object&) noexcept = default;
    enum_object& operator=(const enum_object&) noexcept = default;
    operator enum_t() const noexcept {return value_;}
    /// @endcond
        
    /// @name Public properties
    
    /// @{
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @param flag An enumeration value.
    /// @return true if the bit field or bit fields that are set in flag are also set in the current instance; otherwise, false.
    /// @remarks The has_flag method returns the result of the following bool expression : this_instance And flag = flag
    bool has_flag(enum_t flag) const {return (to_int(value_) & to_int(flag)) == to_int(flag);}
    
    /// @brief Gets the value of the enum.
    /// @return The value of the enum.
    enum_t value() const noexcept {return value_;}
    /// @brief Sets the value of the enum.
    /// @param value The value of the enum.
    enum_object& value(enum_t value) {value_ = value;}
    /// @}

    /// @name Public methods
    
    /// @{
    int32_t compare_to(const enum_object& value) const noexcept override {
      if (to_int(value_) == to_int(value.value_)) return 0;
      if (to_int(value_) < to_int(value.value_)) return -1;
      return 1;
    }
    
    int32_t compare_to(const xtd::object& value) const noexcept override {return is<enum_object<enum_t>>(value) && compare_to(static_cast<const enum_object<enum_t>&>(value));}
    
    bool equals(const xtd::object& value) const noexcept override {return is<enum_object<enum_t>>(value) && equals(static_cast<const enum_object<enum_t>&>(value));}

    /// @brief Converts this instance to byte.
    /// @return A new byte_t object converted from this instance.
    byte_t to_byte() const noexcept {return static_cast<byte_t>(value_);}

    /// @brief Converts this instance to signed byte.
    /// @return A new sbyte_t object converted from this instance.
    sbyte_t to_sbyte() const noexcept {return static_cast<sbyte_t>(value_);}

    /// @brief Converts this instance to int16.
    /// @return A new to_int16 object converted from this instance.
    int16_t to_int16() const noexcept {return static_cast<int16_t>(value_);}

    /// @brief Converts this instance to int32.
    /// @return A new to_int32 object converted from this instance.
    int32_t to_int32() const noexcept {return static_cast<int32_t>(value_);}

    /// @brief Converts this instance to int64.
    /// @return A new to_int64 object converted from this instance.
    int64_t to_int64() const noexcept {return static_cast<int64_t>(value_);}

    /// @brief Converts this instance to unsigned int16.
    /// @return A new to_uint16 object converted from this instance.
    uint16_t to_uint16() const noexcept {return static_cast<uint16_t>(value_);}

    /// @brief Converts this instance to unsigned int32.
    /// @return A new to_uint32 object converted from this instance.
    uint32_t to_uint32() const noexcept {return static_cast<uint32_t>(value_);}

    /// @brief Converts this instance to unsigned int64.
    /// @return A new to_uint64 object converted from this instance.
    uint64_t to_uint64() const noexcept {return static_cast<uint64_t>(value_);}

    xtd::ustring to_string() const noexcept override {
      values();
      if (type_ == xtd::enum_type::flags) return to_string_flags();
      
      auto iterator = std::find_if(values().begin(), values().end(), [&](auto value)->bool {return value.first == value_;});
      if (iterator == values().end()) return ustring::format("{}", to_int(value_));
      
      return iterator->second;
    }
    /// @}

    /// @cond
    bool equals(const enum_object& value) const noexcept {return value_ == value.value_;}
    bool equals(enum_t value) const noexcept {return value_ == value;}
    template<typename type_t>
    bool equals(type_t value) const {return false;}

    static enum_t parse(const xtd::ustring& str) {return parse(str, false);}
    static enum_t parse(const xtd::ustring& str, bool ignore_case) {
      enum_object<enum_t>().values();
      if (enum_object<enum_t>().flags) return parse_flags(str, ignore_case);
      
      for (auto item : enum_object<enum_t>().values()) {
        if (xtd::ustring::compare(str, item.second, ignore_case) == 0)
          return (enum_t)item.first;
      }
      
      return to_enum(xtd::parse<int64_t>(str));
    }
    
    static enum_t parse_flags(const xtd::ustring& value, bool ignore_case) {
      std::vector<xtd::ustring> values = value.split({','});
      for (xtd::ustring& str : values)
        str = str.trim_start(' ').trim_end(' ');
      
      if (values.size() == 1) {
        for (auto item : enum_object<enum_t>().values()) {
          if (xtd::ustring::compare(value, item.seconf, ignore_case) == 0)
            return to_enm(item.first);
        }
        return to_enum(xtd::parse<int64_t>(value));
      }
      
      int64_t result = 0;
      for (xtd::ustring str : values) {
        bool found = false;
        for (auto item : enum_object<enum_t>().values()) {
          if (xtd::ustring::compare(str, item.second, ignore_case) == 0) {
            found = true;
            result |= to_int(item.first);
            break;
          }
        }
        if (found == false)
          throw xtd::format_exception(csf_);
      }
      
      return to_enum(result);
    }
    
    /// @endcond

  private:
    friend class enum_object<std::nullptr_t>;

    xtd::ustring get_name() const {
      auto iterator = std::find_if(values().begin(), values().end(), [&](auto value)->bool {return value.first == value_;});
      if (iterator == values().end()) return xtd::ustring::format("{}", to_int(value_));
        return iterator->second;
    }
    
    xtd::ustring to_string_flags() const {
      auto iterator = std::find_if(values().begin(), values().end(), [&](auto value)->bool {return value.first == value_;});
      if (to_int(value_) == 0 && iterator == values().end()) return "0";
      
      iterator = std::find_if(values().begin(), values().end(), [&](auto value)->bool {return value.first == to_enum(0);});
      if (to_int(value_) == 0) return iterator == values().end() ? "0" : iterator->second;
      
      xtd::ustring str;
      int64_t rest = to_int(value_);
      enum_collection<enum_t> reversed = values();
      std::reverse(reversed.begin(), reversed.end());
      
      for (auto item : reversed) {
        if (to_int(item.first) != 0 && (rest & to_int(item.first)) == to_int(item.first)) {
          rest -= to_int(item.first);
          if (!xtd::ustring::is_empty(str)) str = ", " + str;
          str = item.second + str;
        }
      }
      
      if (str.empty() || rest > 0) return  xtd::ustring::format("{}", to_int(value_));
      
      return str;
    }

    template<typename type_t>
    static enum_t to_enum(type_t value) {return (enum_t)value;}
    static int64_t to_int(enum_t value) {return static_cast<int64_t>(value);}

    static enum_collection<enum_t>& values() {
      std::mutex enum_mutex;
      std::lock_guard<std::mutex> lock(enum_mutex);
      if (values_.size() == 0) enum_register<enum_t>()(values_, type_);
      return values_;
    };
    
    enum_t value_ {};
    inline static enum_collection<enum_t> values_;
    inline static xtd::enum_type type_ = xtd::enum_type::standard;
  };
 
  /// @brief Provides the base class for enumerations.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  template<>
  class enum_object<std::nullptr_t> static_ {
  public:
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return String A String containing the name of the enumerated constant in enumType whose value is value; or the value int32 to String if no such constant is found.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static xtd::ustring get_name(enum_t value) {return enum_object<enum_t>(value).to_string();}
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return String A String containing the name of the enumerated constant in enumType whose value is value; or the value int32 to String if no such constant is found.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static xtd::ustring get_name(enum_object<enum_t> value) {return enum_object<enum_t>(value).to_string();}
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return String A String containing the name of the enumerated constant in enumType whose value is value; or the value int32 to String if no such constant is found.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static xtd::ustring get_name(int32_t value) {return enum_object<enum_t>(value).to_string();}
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return String A String containing the name of the enumerated constant in enumType whose value is value; or the value int32 to String if no such constant is found.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static xtd::ustring get_name(int64_t value) {return enum_object<enum_t>(value).to_string();}
    
    /// @brief Retrieves an array of the names of the constants in a specified enumeration.
    /// @return Array<String> A String array of the names of the constants in enumType.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<xtd::ustring> get_names() {
      std::vector<xtd::ustring> names;
      for (auto item : enum_object<enum_t>().values())
        names.push_back(item.first);
      return names;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<enum_t> An array that contains the values of the constants in enumType.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static std::vector<enum_t> get_values() {
      std::vector<enum_t> values;
      for (auto item : enum_object<enum_t>().values())
        values.push_back(item.second);
      return values;
    }
    
    /// @brief Returns an indication whether a constant with a specified value exists in a specified enumeration.
    /// @param fromValue An enumeration value.
    /// @return Boolean true if a constant in enumType has a value equal to value; otherwise, false.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static bool is_defined(enum_t value) {return std::find_if(enum_object<enum_t>().values().begin(), enum_object<enum_t>().values().end(), [&](auto item)->bool {return item.first == value;}) != enum_object<enum_t>().values().end();}
    /// @brief Returns an indication whether a constant with a specified value exists in a specified enumeration.
    /// @param fromValue An enumeration value.
    /// @return Boolean true if a constant in enumType has a value equal to value; otherwise, false.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static bool is_defined(enum_object<enum_t> value) {return std::find_if(enum_object<enum_t>().values().begin(), enum_object<enum_t>().values().end(), [&](auto item)->bool {return item.first == value;}) != enum_object<enum_t>().values().end();}

    /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
    /// @param value An A String containing the name or value to convert.
    /// @return enum_object An enum whose value is represented by value.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static enum_t parse(const xtd::ustring& value) {return parse<enum_t>(value, false);}
    /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
    /// @param str An A String containing the name or value to convert.
    /// @param ignore_case true to Ignore case; false to regard case.
    /// @return enum_object An enum whose value is represented by value.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static enum_t parse(const xtd::ustring& str, bool ignore_case) {
      return enum_object<enum_t>::parse(str, ignore_case);
    }
    
    /// @brief Converts this instance to byte.
    /// @return A new byte_t object converted from this instance.
    /// @param value The value to convert.
    template<typename enum_t>
    static byte_t to_byte(enum_t value) noexcept {return enum_object<enum_t>(value).to_byte();}
    
    /// @brief Converts this instance to signed byte.
    /// @param value The value to convert.
    /// @return A new sbyte_t object converted from this instance.
    template<typename enum_t>
    static sbyte_t to_sbyte(enum_t value) noexcept {return enum_object<enum_t>(value).to_sbyte();}
    
    /// @brief Converts this instance to int16.
    /// @param value The value to convert.
    /// @return A new to_int16 object converted from this instance.
    template<typename enum_t>
    static int16_t to_int16(enum_t value) noexcept {return enum_object<enum_t>(value).to_int16();}
    
    /// @brief Converts this instance to int32.
    /// @param value The value to convert.
    /// @return A new to_int32 object converted from this instance.
    template<typename enum_t>
    static int32_t to_int32(enum_t value) noexcept {return enum_object<enum_t>(value).to_int32();}
    
    /// @brief Converts this instance to int64.
    /// @param value The value to convert.
    /// @return A new to_int64 object converted from this instance.
    template<typename enum_t>
    static int64_t to_int64(enum_t value) noexcept {return enum_object<enum_t>(value).to_int64();}
    
    /// @brief Converts this instance to unsigned int16.
    /// @param value The value to convert.
    /// @return A new to_uint16 object converted from this instance.
    template<typename enum_t>
    static uint16_t to_uint16(enum_t value) noexcept {return enum_object<enum_t>(value).to_uint16();}
    
    /// @brief Converts this instance to unsigned int32.
    /// @param value The value to convert.
    /// @return A new to_uint32 object converted from this instance.
    template<typename enum_t>
      static uint32_t to_uint32(enum_t value) noexcept {return enum_object<enum_t>(value).to_uint32();}
    
    /// @brief Converts this instance to unsigned int64.
    /// @param value The value to convert.
    /// @return A new to_uint64 object converted from this instance.
    template<typename enum_t>
      static uint64_t to_uint64(enum_t value) noexcept {return enum_object<enum_t>(value).to_uint64();}

    /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. The return value indicates whether the conversion succeeded.
    /// @param vaue The String representation of the enumeration name or underlying value to convert.
    /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
    /// @return true if the value parameter was converted successfully; otherwise, false.
    template<typename enum_t>
    static bool try_parse(const xtd::ustring& value, enum_t& result) {return try_parse<enum_t>(value, false, result);}
    
    /// @brief Converts the String representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. A parameter specifies whether the operation is case-sensitive. The return value indicates whether the conversion succeeded.
    /// @param vaue The String representation of the enumeration name or underlying value to convert.
    /// @param ignore_case true to Ignore case; false to regard case.
    /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
    /// @return true if the value parameter was converted successfully; otherwise, false.
    template<typename enum_t>
    static bool try_parse(const xtd::ustring& value, bool ignore_case, enum_t& result) {
      try {
        result = parse<enum_t>(value, ignore_case);
        return true;
      } catch (...) {
        return false;
      }
    }
  };
}

/// @cond
template<typename enum_t>
inline std::string __enum_to_string(enum_t value) {
  return xtd::enum_object<>::get_name(value);
}

/*
template<> struct xtd::enum_register<xtd::enum_type> {
  void operator()(xtd::enum_collection<xtd::enum_type>& values, xtd::enum_type& type) {
    values = {{enum_type::standard, L"standard"}, {enum_type::flags, L"flags"}};
    type = xtd::enum_type::flags;
  }
};
 */
/// @endcond

#define add_enum_flag_operators_(enum_name) \
  inline enum_name& operator^=(enum_name& lhs, enum_name rhs) {lhs = static_cast<enum_name>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;} \
  inline enum_name& operator&=(enum_name& lhs, enum_name rhs) {lhs = static_cast<enum_name>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;} \
  inline enum_name& operator|=(enum_name& lhs, enum_name rhs) {lhs = static_cast<enum_name>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;} \
  inline enum_name& operator+=(enum_name& lhs, enum_name rhs) {lhs = static_cast<enum_name>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;} \
  inline enum_name& operator-=(enum_name& lhs, enum_name rhs) {lhs = static_cast<enum_name>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;} \
  inline enum_name operator^(enum_name lhs, enum_name rhs) {return static_cast<enum_name>(static_cast<int>(lhs) ^ static_cast<int>(rhs));} \
  inline enum_name operator&(enum_name lhs, enum_name rhs) {return static_cast<enum_name>(static_cast<int>(lhs) & static_cast<int>(rhs));} \
  inline enum_name operator|(enum_name lhs, enum_name rhs) {return static_cast<enum_name>(static_cast<int>(lhs) | static_cast<int>(rhs));} \
  inline enum_name operator+(enum_name lhs, enum_name rhs) {return static_cast<enum_name>(static_cast<int>(lhs) + static_cast<int>(rhs));} \
  inline enum_name operator-(enum_name lhs, enum_name rhs) {return static_cast<enum_name>(static_cast<int>(lhs) - static_cast<int>(rhs));} \
  inline enum_name operator~(enum_name lhs) {return static_cast<enum_name>(~static_cast<int>(lhs));}
