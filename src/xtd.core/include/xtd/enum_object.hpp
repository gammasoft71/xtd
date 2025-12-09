/// @file
/// @brief Contains xtd::enum_object struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "array.hpp"
#include "enum_attribute.hpp"
#include "enum_collection.hpp"
#include "enum_register.hpp"
#include "enum_set_attribute.hpp"
#include "format_exception.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "iformatable.hpp"
#include "number_styles.hpp"
#include "optional.hpp"
#include "static.hpp"
#include "string_comparison.hpp"
#include "string_split_options.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @name Boxed types
  
  /// @{
  /// @brief Provides the base class for enumerations.
  /// ```cpp
  /// template<class enum_t = std::nullptr_t>
  /// struct enum_object : xtd::object, xtd::icomparable<enum_object<enum_t>>, xtd::iequatable<enum_object<enum_t>>, xtd::iformatable;
  /// ```
  /// @par Inheritance
  /// xtd::object → xtd::enum_object <enum_t>
  /// @par Header
  /// ```cpp
  /// #include <xtd/enum_object>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  /// @remarks For more information about enumeration, see [enum class](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/enum_class) guide.
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  /// The following code show how to use xtd::enum_object class for an enum.
  /// @include enum_class.cpp
  /// The following code show how to use xtd::enum_object class for an enum flags.
  /// @include enum_class_flags.cpp
  template<class enum_t = std::nullptr_t>
  struct enum_object : xtd::object, xtd::icomparable<enum_object<enum_t>>, xtd::iequatable<enum_object<enum_t >>, xtd::iformatable {
    /// @name Public Aliases
    
    /// @{
    /// @brief Represents the enumeration type.
    using enum_type = enum_t;
    /// @brief Represents the enumeration type.
    using value_type = enum_t;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::enum_object class.
    enum_object() noexcept = default;
    /// @brief Initializes a new instance of the xtd::enum_object class with specified value.
    /// @param value Value to set to this instance.
    explicit enum_object(enum_type value) : value(value) {}
    /// @}
    
    /// @cond
    explicit enum_object(xtd::byte value) : value(to_enum(value)) {}
    explicit enum_object(sbyte value) : value(to_enum(value)) {}
    explicit enum_object(int16 value) : value(to_enum(value)) {}
    explicit enum_object(int32 value) : value(to_enum(value)) {}
    explicit enum_object(int64 value) : value(to_enum(value)) {}
    explicit enum_object(uint16 value) : value(to_enum(value)) {}
    explicit enum_object(uint32 value) : value(to_enum(value)) {}
    explicit enum_object(uint64 value) : value(to_enum(value)) {}
    enum_object(enum_object&&) noexcept = default;
    enum_object(const enum_object&) noexcept = default;
    enum_object& operator =(const enum_object&) noexcept = default;
    operator enum_type() const noexcept {return value;}
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @param flag An enumeration value.
    /// @return `true` if the bit field or bit fields that are set in flag are also set in the current instance; otherwise, `false`.
    /// @remarks The has_flag method returns the result of the following bool expression : this_instance And flag = flag
    bool has_flag(enum_type flag) const noexcept {return (to_int(value) & to_int(flag)) == to_int(flag);}
    
    /// @brief Gets or sets the value of the enum.
    /// @param value The value of the enum.
    enum_type value {};
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
    int32 compare_to(const enum_object& value) const noexcept override {
      if (to_int(this->value) == to_int(value.value)) return 0;
      if (to_int(this->value) < to_int(value.value)) return -1;
      return 1;
    }
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const object& obj) const noexcept override {return dynamic_cast<const enum_object*>(&obj) && equals(static_cast<const enum_object&>(obj));}
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const enum_object& value) const noexcept override {return this->value == value.value;}
    /// @brief Indicates whether the current object is equal to another object of the same type.
    /// @param obj An object to compare with this object.
    /// @return `true` if the current object is equal to the other parameter; otherwise, `false`.
    bool equals(enum_type value) const noexcept {return this->value == value;}
    /// @brief Indicates whether the current object is equal to another object with defferent type.
    /// @param obj An object to compare with this object.
    /// @return Always return `false`.
    template<class attribute_t>
    bool equals(attribute_t value) const noexcept {return false;}
    
    /// @brief Serves as a hash function for a particular type.
    /// @return size_t A hash code for the current object.
    xtd::size get_hash_code() const noexcept override {return hash_code::combine(value);}
    
    /// @brief Converts this instance to byte.
    /// @return A new xtd::byte object converted from this instance.
    xtd::byte to_byte() const noexcept {return static_cast<xtd::byte>(value);}
    
    /// @brief Converts this instance to int16.
    /// @return A new to_int16 object converted from this instance.
    int16 to_int16() const noexcept {return static_cast<int16>(value);}
    
    /// @brief Converts this instance to int32.
    /// @return A new to_int32 object converted from this instance.
    int32 to_int32() const noexcept {return static_cast<int32>(value);}
    
    /// @brief Converts this instance to int64.
    /// @return A new to_int64 object converted from this instance.
    int64 to_int64() const noexcept {return static_cast<int64>(value);}
    
    /// @brief Converts this instance to signed byte.
    /// @return A new sbyte object converted from this instance.
    sbyte to_sbyte() const noexcept {return static_cast<sbyte>(value);}
    
    /// @brief Converts this instance to unsigned int16.
    /// @return A new to_uint16 object converted from this instance.
    uint16 to_uint16() const noexcept {return static_cast<uint16>(value);}
    
    /// @brief Converts this instance to unsigned int32.
    /// @return A new to_uint32 object converted from this instance.
    uint32 to_uint32() const noexcept {return static_cast<uint32>(value);}
    
    /// @brief Converts this instance to unsigned int64.
    /// @return A new to_uint64 object converted from this instance.
    uint64 to_uint64() const noexcept {return static_cast<uint64>(value);}
    
    /// @brief Returns a xtd::string that represents the current object.
    /// @return A string that represents the current object.
    xtd::string to_string() const noexcept override {
      init();
      if (attribute() == xtd::enum_attribute::flags) return to_string_flags();
      
      auto iterator = std::find_if(entries().begin(), entries().end(), [&](auto value)->bool {return value.first == this->value;});
      if (iterator == entries().end()) return string::format("{}", to_int(value));
      
      return iterator->second;
    }
    
    /// @brief Converts the value of this instance to its equivalent string representation using the specified format.
    /// @param format A format string.
    /// @return The string representation of the value of this instance as specified by format.
    /// @exception xtd::format_exception format contains an invalid specification.
    /// @remarks The format parameter can be one of the following format strings: "G" or "g", "D" or "d", "X" or "x", and "F" or "f" (the format string is not case-sensitive). If format is null or an empty string (""), the general format specifier ("G") is used. For more information about the enumeration format strings and formatting enumeration values, see [Enumeration Format Strings](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Format%20number%20dates%20other%20types/enumeration_format_strings). For more information about formatting in general, see [Formatting Types](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Format%20number%20dates%20other%20types/overview).
    /// @par Notes to caller
    /// If multiple enumeration members have the same underlying value and you attempt to retrieve the string representation of an enumeration member's name based on its underlying value, your code should not make any assumptions about which name the method will return. For example, the following enumeration defines two members, shade::gray and shade::grey, that have the same underlying value.
    /// ```cpp
    /// enum shade {
    ///   white = 0, gray = 1, grey = 1, black = 2
    /// };
    /// ```
    /// The following method call attempts to retrieve the name of a member of the shade enumeration whose underlying value is 1. The method can return either "gray" or "grey", and your code should not make any assumptions about which string will be returned.
    /// ```cpp
    /// string shade_name = enum_object<shade>(as<shade>(1)).to_string("F");
    /// ```
    xtd::string to_string(const xtd::string& format) const {return to_string(format, std::locale {});}
    
    /// @brief Converts the value of this instance to its equivalent string representation using the specified format, and locale.
    /// @param format A format string.
    /// @param culture An xtd::globalization::culture_info object that contains culture information.
    /// @return The string representation of the value of this instance as specified by format.
    /// @exception xtd::format_exception format contains an invalid specification.
    /// @remarks The format parameter can be one of the following format strings: "G" or "g", "D" or "d", "X" or "x", and "F" or "f" (the format string is not case-sensitive). If format is null or an empty string (""), the general format specifier ("G") is used. For more information about the enumeration format strings and formatting enumeration values, see [Enumeration Format Strings](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Format%20number%20dates%20other%20types/enumeration_format_strings). For more information about formatting in general, see [Formatting Types](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Format%20number%20dates%20other%20types/overview).
    /// @par Notes to caller
    /// If multiple enumeration members have the same underlying value and you attempt to retrieve the string representation of an enumeration member's name based on its underlying value, your code should not make any assumptions about which name the method will return. For example, the following enumeration defines two members, shade::gray and shade::grey, that have the same underlying value.
    /// ```cpp
    /// enum shade {
    ///   white = 0, gray = 1, grey = 1, black = 2
    /// };
    /// ```
    /// The following method call attempts to retrieve the name of a member of the shade enumeration whose underlying value is 1. The method can return either "gray" or "grey", and your code should not make any assumptions about which string will be returned.
    /// ```cpp
    /// string shade_name = enum_object<shade>(as<shade>(1)).to_string("F");
    /// ```
    xtd::string to_string(const xtd::string& format, const globalization::culture_info& culture) const override;
    /// @}
    
    /// @name Public Static Methods
    
    /// @{
    /// @{
    /// @brief Converts the string to its `enum_type` equivalent.
    /// @param value A string containing a `enum_type` to convert.
    /// @return A `enum_type` equivalent to the native value contained in value.
    static enum_type parse(const xtd::string& str) {return parse(str, false);}
    /// @brief Converts the string to its `enum_type` equivalent with a specified boolean to ignore case.
    /// @param value A string containing a `enum_type` to convert.
    /// @param ignore_case 'true` to ingore case; otherwise `false`.
    /// @return A `enum_type` equivalent to the native value contained in value.
    static enum_type parse(const xtd::string& str, bool ignore_case) {
      enum_object<enum_type>().init();
      if (enum_object<enum_type>().attribute() == xtd::enum_attribute::flags) return parse_flags(str, ignore_case);
      
      for (auto item : enum_object<enum_type>().entries()) {
        if (xtd::string::compare(str, item.second, ignore_case) == 0)
          return static_cast<enum_type>(item.first);
      }
      
      return to_enum(xtd::parse<int64>(str));
    }
    /// @}

    
    /// @cond
    friend auto operator << (std::ostream& os, const enum_object& value) -> std::ostream& {return os << value.to_string();}
    /// @endcond

  private:
    friend struct enum_object<std::nullptr_t>;
    
    xtd::string get_name() const noexcept {
      auto iterator = std::find_if(entries().begin(), entries().end(), [&](auto value)->bool {return value.first == this->value;});
      if (iterator == entries().end()) return xtd::string::format("{}", to_int(value));
      return iterator->second;
    }
    
    static enum_type parse_flags(const xtd::string& value, bool ignore_case) {
      xtd::array<xtd::string> values = value.split(',');
      for (xtd::string& str : values)
        str = str.trim(' ');
        
      if (values.length() == 1) {
        for (auto item : enum_object<enum_type>().entries()) {
          if (xtd::string::compare(value, item.second, ignore_case) == 0)
            return to_enum(item.first);
        }
        return to_enum(xtd::parse<int64>(value));
      }
      
      int64 result = 0;
      for (xtd::string str : values) {
        bool found = false;
        for (auto item : enum_object<enum_type>().entries()) {
          if (xtd::string::compare(str, item.second, ignore_case) == 0) {
            found = true;
            result |= to_int(item.first);
            break;
          }
        }
        if (found == false)
          xtd::helpers::throw_helper::throws(xtd::helpers::exception_case::format);
      }
      
      return to_enum(result);
    }
    
    xtd::string to_string_flags() const noexcept {
      auto iterator = std::find_if(entries().begin(), entries().end(), [&](auto value)->bool {return value.first == this->value;});
      if (to_int(value) == 0 && iterator == entries().end()) return "0";
      
      iterator = std::find_if(entries().begin(), entries().end(), [&](auto value)->bool {return value.first == to_enum(0);});
      if (to_int(value) == 0) return iterator == entries().end() ? "0" : iterator->second;
      
      xtd::string str;
      int64 rest = to_int(value);
      enum_collection<enum_type> reversed_entries = entries();
      std::reverse(reversed_entries.begin(), reversed_entries.end());
      
      for (auto item : reversed_entries) {
        if (to_int(item.first) != 0 && (rest & to_int(item.first)) == to_int(item.first)) {
          rest -= to_int(item.first);
          if (!xtd::string::is_empty(str)) str = ", " + str;
          str = item.second + str;
        }
      }
      
      if (xtd::string::is_empty(str) || rest > 0) return  xtd::string::format("{}", to_int(value));
      
      return str;
    }
    
    template<class attribute_t>
    inline static enum_type to_enum(attribute_t value) noexcept {return static_cast<enum_type>(value);}
    static int64 to_int(enum_type value) noexcept {return static_cast<int64>(value);}
    
    static xtd::enum_attribute attribute() noexcept {
      if (attribute_.has_value()) return attribute_.value();
      attribute_ = xtd::enum_attribute(enum_set_attribute<enum_type>());
      return attribute_.value();
    }
    
    static enum_collection<enum_type>& entries() noexcept {
      if (entries_.has_value()) return entries_.value();
      entries_ = enum_collection<enum_type>(enum_register<enum_type>());
      return entries_.value();
    };
    
    static void init() noexcept {
      attribute();
      entries();
    }
    
    inline static std::optional<xtd::enum_attribute> attribute_;
    inline static std::optional<enum_collection<enum_type>> entries_;
  };
  
  /// @brief Provides the base class for enumerations.
  /// @par Header
  /// ```cpp
  /// #include <xtd/enum_object>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system types
  template<>
  struct enum_object < std::nullptr_t > static_ {
    /// @name Public Aliases
    
    /// @{
    /// @}
    
    /// @{
    /// @name Public Static Methods
    
    /// @{
    /// @brief Retrieves an array of the xtd::enum_collection<enum_t> of the constants in a specified enumeration.
    /// @return A xtd::string array of the values and names of the constants in enumType.
    template < class enum_t >
    inline static const xtd::enum_collection < enum_t >& get_entries() noexcept {
      return enum_object < enum_t > ().entries();
    }
    
    /// @brief Retrieves an array of the xtd::enum_collection<xtd::byte> of the constants in a specified enumeration.
    /// @return A xtd::string array of the values and names of the constants in enumType.
    template < class enum_t >
    inline static xtd::enum_collection < xtd::byte > get_entries_as_byte() noexcept {
      xtd::enum_collection < xtd::byte > entries;
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t>().entries().end(), [&](auto entry) {entries.emplace_back(enum_object < enum_t > (entry.first).to_byte(), entry.second);});
      return entries;
    }
    
    /// @brief Retrieves an array of the xtd::enum_collection<int16> of the constants in a specified enumeration.
    /// @return A xtd::string array of the values and names of the constants in enumType.
    template < class enum_t >
    inline static xtd::enum_collection < int16 > get_entries_as_int16() noexcept {
      xtd::enum_collection < int16 > entries;
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t>().entries().end(), [&](auto entry) {entries.emplace_back(enum_object < enum_t > (entry.first).to_int16(), entry.second);});
      return entries;
    }
    
    /// @brief Retrieves an array of the xtd::enum_collection<int32> of the constants in a specified enumeration.
    /// @return A xtd::string array of the values and names of the constants in enumType.
    template < class enum_t >
    inline static xtd::enum_collection < int32 > get_entries_as_int32() noexcept {
      xtd::enum_collection < int32 > entries;
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t>().entries().end(), [&](auto entry) {entries.emplace_back(enum_object < enum_t > (entry.first).to_int32(), entry.second);});
      return entries;
    }
    
    /// @brief Retrieves an array of the xtd::enum_collection<int64> of the constants in a specified enumeration.
    /// @return A xtd::string array of the values and names of the constants in enumType.
    template < class enum_t >
    inline static xtd::enum_collection < int64 > get_entries_as_int64() noexcept {
      xtd::enum_collection < int64 > entries;
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t>().entries().end(), [&](auto entry) {entries.emplace_back(enum_object < enum_t > (entry.first).to_int64(), entry.second);});
      return entries;
    }
    
    /// @brief Retrieves an array of the xtd::enum_collection<sbyte> of the constants in a specified enumeration.
    /// @return A xtd::string array of the values and names of the constants in enumType.
    template < class enum_t >
    inline static xtd::enum_collection < sbyte > get_entries_as_sbyte() noexcept {
      xtd::enum_collection < sbyte > entries;
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t>().entries().end(), [&](auto entry) {entries.emplace_back(enum_object < enum_t > (entry.first).to_sbyte(), entry.second);});
      return entries;
    }
    
    /// @brief Retrieves an array of the xtd::enum_collection<uint16> of the constants in a specified enumeration.
    /// @return A xtd::string array of the values and names of the constants in enumType.
    template < class enum_t >
    inline static xtd::enum_collection < uint16 > get_entries_as_uint16() noexcept {
      xtd::enum_collection < uint16 > entries;
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t>().entries().end(), [&](auto entry) {entries.emplace_back(enum_object < enum_t > (entry.first).to_uint16(), entry.second);});
      return entries;
    }
    
    /// @brief Retrieves an array of the xtd::enum_collection<uint32> of the constants in a specified enumeration.
    /// @return A xtd::string array of the values and names of the constants in enumType.
    template < class enum_t >
    inline static xtd::enum_collection < uint32 > get_entries_as_uint32() noexcept {
      xtd::enum_collection < uint32 > entries;
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t>().entries().end(), [&](auto entry) {entries.emplace_back(enum_object < enum_t > (entry.first).to_uint32(), entry.second);});
      return entries;
    }
    
    /// @brief Retrieves an array of the xtd::enum_collection<uint64> of the constants in a specified enumeration.
    /// @return A xtd::string array of the values and names of the constants in enumType.
    template < class enum_t >
    inline static xtd::enum_collection < uint64 > get_entries_as_uint64() noexcept {
      xtd::enum_collection < uint64 > entries;
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t>().entries().end(), [&](auto entry) {entries.emplace_back(enum_object < enum_t > (entry.first).to_uint64(), entry.second);});
      return entries;
    }
    
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return A xtd::string containing the name of the enumerated constant in enumType whose value is value; or the value int32 to xtd::string if no such constant is found.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::string get_name(enum_t value) noexcept {return enum_object < enum_t > (value).to_string();}
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return xtd::string A xtd::string containing the name of the enumerated constant in enumType whose value is value; or the value int32 to xtd::string if no such constant is found.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::string get_name(enum_object < enum_t > value) noexcept {return enum_object < enum_t > (value).to_string();}
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return xtd::string A xtd::string containing the name of the enumerated constant in enumType whose value is value; or the value int32 to xtd::string if no such constant is found.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::string get_name(int32 value) noexcept {return enum_object < enum_t > (value).to_string();}
    /// @brief Retrieves the name of the constant in the specified enumeration that has the specified value.
    /// @param value The value of a particular enumerated constant in terms of its underlying type.
    /// @return A xtd::string containing the name of the enumerated constant in enumType whose value is value; or the value int32 to xtd::string if no such constant is found.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::string get_name(int64 value) noexcept {return enum_object < enum_t > (value).to_string();}
    
    /// @brief Retrieves an array of the names of the constants in a specified enumeration.
    /// @return A xtd::string array of the names of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < xtd::string > get_names() noexcept {
      auto names = xtd::array < xtd::string > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {names.resize(names.length() + 1, entry.second);});
      return names;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<enum_t> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < enum_t > get_values() noexcept {
      auto values = xtd::array < enum_t > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {values.resize(values.length() + 1, entry.first);});
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<xtd::byte> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < xtd::byte > get_values_as_byte() noexcept {
      auto values = xtd::array < xtd::byte > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {values.resize(values.length() + 1, enum_object < enum_t > (entry.first).to_byte());});
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<int16> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < int16 > get_values_as_int16() noexcept {
      auto values = xtd::array < xtd::int16 > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {values.resize(values.length() + 1, enum_object < enum_t > (entry.first).to_int16());});
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<int32> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < int32 > get_values_as_int32() noexcept {
      auto values = xtd::array < xtd::int32 > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {values.resize(values.length() + 1, enum_object < enum_t > (entry.first).to_int32());});
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<int64> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < int64 > get_values_as_int64() noexcept {
      auto values = xtd::array < xtd::int64 > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {values.resize(values.length() + 1, enum_object < enum_t > (entry.first).to_int64());});
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<sbyte> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < sbyte > get_values_as_sbyte() noexcept {
      auto values = xtd::array < xtd::sbyte > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {values.resize(values.length() + 1, enum_object < enum_t > (entry.first).to_sbyte());});
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<uint16> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < uint16 > get_values_as_uint16() noexcept {
      auto values = xtd::array < xtd::uint16 > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {values.resize(values.length() + 1, enum_object < enum_t > (entry.first).to_uint16());});
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<uint32> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < uint32 > get_values_as_uint32() noexcept {
      auto values = xtd::array < xtd::uint32 > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {values.resize(values.length() + 1, enum_object < enum_t > (entry.first).to_uint32());});
      return values;
    }
    
    /// @brief Retrieves an array of the values of the constants in a specified enumeration.
    /// @return Array<uint64> An array that contains the values of the constants in enumType.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static xtd::array < uint64 > get_values_as_uint64() noexcept {
      auto values = xtd::array < xtd::uint64 > {};
      std::for_each(enum_object < enum_t > ().entries().begin(), enum_object < enum_t > ().entries().end(), [&](auto entry) {values.resize(values.length() + 1, enum_object < enum_t > (entry.first).to_uint64());});
      return values;
    }
    
    /// @brief Returns an indication whether a constant with a specified value exists in a specified enumeration.
    /// @param fromValue An enumeration value.
    /// @return `true` if a constant in enumType has a value equal to value; otherwise, `false`.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static bool is_defined(enum_t value) noexcept {return std::find_if(enum_object < enum_t > ().entries().begin(), enum_object < enum_t>().entries().end(), [&](auto item)->bool {return item.first == value;}) != enum_object < enum_t > ().entries().end();}
    /// @brief Returns an indication whether a constant with a specified value exists in a specified enumeration.
    /// @param fromValue An enumeration value.
    /// @return `true` if a constant in enumType has a value equal to value; otherwise, `false`.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static bool is_defined(enum_object < enum_t > value) noexcept {return std::find_if(enum_object < enum_t>().entries().begin(), enum_object<enum_t>().entries().end(), [&](auto item)->bool {return item.first == value;}) != enum_object < enum_t > ().entries().end();}
    
    /// @brief Converts the xtd::string representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
    /// @param value An A xtd::string containing the name or value to convert.
    /// @return enum_object An enum whose value is represented by value.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static enum_t parse(const xtd::string & value) {return parse < enum_t > (value, false);}
    /// @brief Converts the xtd::string representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object.
    /// @param str An A xtd::string containing the name or value to convert.
    /// @param ignore_case `true` to Ignore case; `false` to regard case.
    /// @return enum_object An enum whose value is represented by value.
    /// @exception xtd::argument_exception The value is ! a value of enumType.
    template < class enum_t >
    inline static enum_t parse(const xtd::string & str, bool ignore_case) {
      return enum_object < enum_t >::parse(str, ignore_case);
    }
    
    /// @brief Converts this instance to byte.
    /// @return A new xtd::byte object converted from this instance.
    /// @param value The value to convert.
    template < class enum_t >
    inline static xtd::byte to_byte(enum_t value) noexcept {return enum_object < enum_t > (value).to_byte();}
    
    /// @brief Converts this instance to int16.
    /// @param value The value to convert.
    /// @return A new to_int16 object converted from this instance.
    template < class enum_t >
    inline static int16 to_int16(enum_t value) noexcept {return enum_object < enum_t > (value).to_int16();}
    
    /// @brief Converts this instance to int32.
    /// @param value The value to convert.
    /// @return A new to_int32 object converted from this instance.
    template < class enum_t >
    inline static int32 to_int32(enum_t value) noexcept {return enum_object < enum_t > (value).to_int32();}
    
    /// @brief Converts this instance to int64.
    /// @param value The value to convert.
    /// @return A new to_int64 object converted from this instance.
    template < class enum_t >
    inline static int64 to_int64(enum_t value) noexcept {return enum_object < enum_t > (value).to_int64();}
    
    /// @brief Converts this instance to signed byte.
    /// @param value The value to convert.
    /// @return A new sbyte object converted from this instance.
    template < class enum_t >
    inline static sbyte to_sbyte(enum_t value) noexcept {return enum_object < enum_t > (value).to_sbyte();}
    
    /// @brief Converts this instance to string.
    /// @param value The value to convert.
    /// @return A new xtd::string converted from this instance.
    template < class enum_t >
    inline static xtd::string to_string(enum_t value) noexcept {return enum_object < enum_t > (value).to_string();}
    
    /// @brief Converts this instance to unsigned int16.
    /// @param value The value to convert.
    /// @return A new to_uint16 object converted from this instance.
    template < class enum_t >
    inline static uint16 to_uint16(enum_t value) noexcept {return enum_object < enum_t > (value).to_uint16();}
    
    /// @brief Converts this instance to unsigned int32.
    /// @param value The value to convert.
    /// @return A new to_uint32 object converted from this instance.
    template < class enum_t >
    inline static uint32 to_uint32(enum_t value) noexcept {return enum_object < enum_t > (value).to_uint32();}
    
    /// @brief Converts this instance to unsigned int64.
    /// @param value The value to convert.
    /// @return A new to_uint64 object converted from this instance.
    template < class enum_t >
    inline static uint64 to_uint64(enum_t value) noexcept {return enum_object < enum_t > (value).to_uint64();}
    
    /// @brief Converts the xtd::string representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. The return value indicates whether the conversion succeeded.
    /// @param vaue The xtd::string representation of the enumeration name or underlying value to convert.
    /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
    /// @return `true` if the value parameter was converted successfully; otherwise, `false`.
    template < class enum_t >
    inline static bool try_parse(const xtd::string & value, enum_t& result) noexcept {return try_parse < enum_t > (value, false, result);}
    
    /// @brief Converts the xtd::string representation of the name or numeric value of one or more enumerated constants to an equivalent enumerated object. A parameter specifies whether the operation is case-sensitive. The return value indicates whether the conversion succeeded.
    /// @param vaue The xtd::string representation of the enumeration name or underlying value to convert.
    /// @param ignore_case `true` to Ignore case; `false` to regard case.
    /// @param reslt When this method returns, result contains an object of type TEnum whose value is represented by value if the parse operation succeeds. If the parse operation fails, result contains the default value of the underlying type of TEnum. Note that this value need ! be a member of the TEnum enumeration. This parameter is passed uninitialized.
    /// @return `true` if the value parameter was converted successfully; otherwise, `false`.
    template < class enum_t >
    inline static bool try_parse(const xtd::string & value, bool ignore_case, enum_t& result) noexcept {
      try {
        result = parse < enum_t > (value, ignore_case);
        return true;
      } catch (...) {
        return false;
      }
    }
    /// @}
  };
  /// @}
}

/// @cond
template < class enum_t >
inline std::string __enum_to_string__(enum_t value) noexcept {
  return xtd::enum_object < >::get_name(value);
}

template < class value_t >
value_t __parse_enum(const std::string& str) {
  return xtd::enum_object < >::parse < value_t > (str);
}
/// @endcond
