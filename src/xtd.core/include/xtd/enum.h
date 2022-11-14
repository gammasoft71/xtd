/// @file
/// @brief Contains xtd::enum_object.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once

#include "format_exception.h"
#include "icomparable.h"
#include "ustring.h"
#include <mutex>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  template<typename enum_t>
  using enum_collection = std::vector<std::pair<enum_t, xtd::ustring>>;
  
  /// @cond
  template<typename enum_t>
  struct enum_register {
    void operator()(enum_collection<enum_t>& values, bool& flags) {}
  };
  
  template <typename enum_t, bool = std::is_enum<enum_t>::value>
  class add_flag_operators;
  
  template <typename enum_t>
  class add_flag_operators<enum_t, true> : public std::false_type { };
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t & operator+=(enum_t& lhs, enum_t rhs) {
    lhs = static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) + static_cast<typename std::underlying_type<enum_t>::type>(rhs));
    return lhs;
  }
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t & operator-=(enum_t& lhs, enum_t rhs) {
    lhs = static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) - static_cast<typename std::underlying_type<enum_t>::type>(rhs));
    return lhs;
  }
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t & operator &=(enum_t& lhs, enum_t rhs) {
    lhs = static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) & static_cast<typename std::underlying_type<enum_t>::type>(rhs));
    return lhs;
  }
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t & operator |=(enum_t& lhs, enum_t rhs) {
    lhs = static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) | static_cast<typename std::underlying_type<enum_t>::type>(rhs));
    return lhs;
  }
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t & operator ^=(enum_t& lhs, enum_t rhs) {
    lhs = static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) ^ static_cast<typename std::underlying_type<enum_t>::type>(rhs));
    return lhs;
  }
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t operator+(enum_t lhs, enum_t rhs) {return static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) + static_cast<typename std::underlying_type<enum_t>::type>(rhs));}
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t operator-(enum_t lhs, enum_t rhs) {return static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) - static_cast<typename std::underlying_type<enum_t>::type>(rhs));}
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t operator &(enum_t lhs, enum_t rhs) {return static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) & static_cast<typename std::underlying_type<enum_t>::type>(rhs));}
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t operator |(enum_t lhs, enum_t rhs) {return static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) | static_cast<typename std::underlying_type<enum_t>::type>(rhs));}
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t operator ^(enum_t lhs, enum_t rhs) {return static_cast<enum_t>(static_cast<typename std::underlying_type<enum_t>::type>(lhs) ^ static_cast<typename std::underlying_type<enum_t>::type>(rhs));}
  
  template <typename enum_t, typename std::enable_if<add_flag_operators<enum_t>::value>::type* = nullptr>
  inline enum_t operator ~(enum_t rhs) {return static_cast<enum_t>(~static_cast<typename std::underlying_type<enum_t>::type>(rhs));}
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
    
    /// @{
    /// @brief The enum type.
    using enum_type = enum_t;
    /// @}
    
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::enum_object class.
    enum_object() noexcept = default;
    /// @brief Initializes a new instance of the xtd::enum_object class with specified value.
    /// @param value Value to set to this instance.
    enum_object(enum_t value) : value_(value) {}
    /// @}

    /// @cond
    enum_object(enum_object&&) noexcept = default;
    enum_object(const enum_object&) noexcept = default;
    enum_object& operator=(const enum_object&) noexcept = default;
    operator enum_type() const noexcept {return value_;}
    /// @endcond
        
    /// @name Public properties
    
    /// @{
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @param flag An enumeration value.
    /// @return true if the bit field or bit fields that are set in flag are also set in the current instance; otherwise, false.
    /// @remarks The has_flag method returns the result of the following bool expression : this_instance And flag = flag
    bool has_flag(enum_type flag) const {return (to_int(value_) & to_int(flag)) == to_int(flag);}
    
    /// @brief Gets the value of the enum.
    /// @return The value of the enum.
    enum_type value() const noexcept {return value_;}
    /// @brief Sets the value of the enum.
    /// @param value The value of the enum.
    enum_object& value(enum_type value) {value_ = value;}
    /// @}

    /// @name Public methods
    
    /// @{
    int32_t compare_to(const enum_object& value) const noexcept override {
      if (to_int(value_) == to_int(value.value_)) return 0;
      if (to_int(value_) < to_int(value.value_)) return -1;
      return 1;
    }
    
    int32_t compare_to(const xtd::object& value) const noexcept override {return is<enum_object<enum_type>>(value) && compare_to(static_cast<const enum_object<enum_type>&>(value));}
    
    bool equals(const xtd::object& value) const noexcept override {return is<enum_object<enum_type>>(value) && equals(static_cast<const enum_object<enum_type>&>(value));}

    xtd::ustring to_string() const noexcept override {
      values();
      if (flags_) return to_string_flags();
      
      auto iterator = std::find_if(values().begin(), values().end(), [&](auto value)->bool {return value.first == value_;});
      if (iterator == values().end()) return ustring::format("{}", to_int(value_));
      
      return iterator->second;
    }
    /// @}

    /// @cond
    bool equals(const enum_object& value) const noexcept {return value_ == value.value_;}
    bool equals(enum_type value) const noexcept {return value_ == value;}
    template<typename type_t>
    bool equals(type_t value) const {return false;}

    static enum_type parse(const xtd::ustring& str) {return parse(str, false);}
    static enum_type parse(const xtd::ustring& str, bool ignore_case) {
      enum_object<enum_type>().values();
      if (enum_object<enum_type>().flags) return parse_flags(str, ignore_case);
      
      for (auto item : enum_object<enum_type>().values()) {
        if (xtd::ustring::compare(str, item.second, ignore_case) == 0)
          return (enum_type)item.first;
      }
      
      return to_enum(xtd::parse<int64_t>(str));
    }
    
    static enum_type parse_flags(const xtd::ustring& value, bool ignore_case) {
      std::vector<xtd::ustring> values = value.split({','});
      for (xtd::ustring& str : values)
        str = str.trim_start(' ').trim_end(' ');
      
      if (values.size() == 1) {
        for (auto item : enum_object<enum_type>().values()) {
          if (xtd::ustring::compare(value, item.seconf, ignore_case) == 0)
            return to_enm(item.first);
        }
        return to_enum(xtd::parse<int64_t>(value));
      }
      
      int64_t result = 0;
      for (xtd::ustring str : values) {
        bool found = false;
        for (auto item : enum_object<enum_type>().values()) {
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
      enum_collection<enum_type> reversed = values();
      std::reverse(reversed.begin(), reversed.end());
      
      for (auto item : reversed) {
        if (to_int(item.first) != 0 && (rest & to_int(item.first)) == to_int(item.first)) {
          rest -= to_int(item.first);
          if (!str.empty()) str = ", " + str;
          str = item.second + str;
        }
      }
      
      if (str.empty() || rest > 0) return  xtd::ustring::format("{}", value_);
      
      return str;
    }

    static enum_type to_enum(int64_t value) {return static_cast<enum_type>(value);}
    static int64_t to_int(enum_type value) {return static_cast<int64_t>(value);}

    static enum_collection<enum_type>& values() {
      std::mutex enum_mutex;
      std::lock_guard<std::mutex> lock(enum_mutex);
      if (values_.size() == 0) enum_register<enum_type>()(values_, flags_);
      return values_;
    };
    
    enum_type value_ {};
    inline static enum_collection<enum_type> values_;
    inline static bool flags_ = false;
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
    static xtd::ustring get_name(int32_t value) {return enum_object<enum_t>(static_cast<enum_t>(value)).to_string();}
    
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return String A String containing the name of the enumerated constant in enumType whose value is value; or the value int32 to String if no such constant is found.
    /// @exception ArgumentException The value is ! a value of enumType.
    template<typename enum_t>
    static xtd::ustring get_name(int64_t value) {return enum_object<enum_t>(static_cast<enum_t>(value)).to_string();}
    
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

