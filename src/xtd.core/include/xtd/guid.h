/// @file
/// @brief Contains xtd::guid class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <vector>
#include "argument_exception.h"
#include "format_exception.h"
#include "core_export.h"
#include "icomparable.h"
#include "iequatable.h"
#include "object.h"
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a globally unique identifier (GUID). A GUID is a 128-bit integer (16 bytes) that can be used across all computers and networks wherever a unique identifier is required. Such an identifier has a very low probability of being duplicated.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following code example demonstrate the use of guid class.
  /// @include guid.cpp
  class core_export_ guid final : public object, public icomparable<guid>, public iequatable<guid> {
  public:
    /// @brief Initializes a new instance of the Guid structure.
    guid() = default;
    
    /// @brief Initializes a new instance of the Guid structure by using the specified array of bytes.
    /// @param bytes A 16-element byte array containing values with which to initialize the GUID.
    /// @exception std::invalid_argument bytes is not 16 bytes long.
    explicit guid(const std::vector<uint8_t>& data) : data_(data) {
      if (data.size() != 16) throw xtd::argument_exception("Vector size must be 16", current_stack_frame_);
    }
    
    /// @brief Initializes a new instance of the Guid structure by using the specified array of bytes.
    /// @param bytes A 16-element byte array containing values with which to initialize the GUID.
    /// @exception std::invalid_argument bytes is not 16 bytes long.
    explicit guid(const std::initializer_list<uint8_t>& data) : data_(data) {
      if (data.size() != 16) throw xtd::argument_exception("Vector size must be 16", current_stack_frame_);
    }

    /// @brief Initializes a new instance of the Guid structure by using the specified integers and byte array.
    /// @param a The first 4 bytes of the GUID.
    /// @param b The next 2 bytes of the GUID.
    /// @param c The next 2 bytes of the GUID.
    /// @param d The remaining 8 bytes of the GUID.
    /// @exception std::invalid_argument bytes is not 8 bytes long.
    explicit guid(int a, int b, int c, const std::vector<uint8_t>& d) {
      if (d.size() != 8) throw xtd::argument_exception("Vector size must be 8", current_stack_frame_);
      
      data_[0] = static_cast<uint8_t>((a & 0xFF000000) >> 24);
      data_[1] = static_cast<uint8_t>((a & 0x00FF0000) >> 16);
      data_[2] = static_cast<uint8_t>((a & 0x0000FF00) >> 8);
      data_[3] = static_cast<uint8_t>((a & 0x000000FF) >> 0);
      data_[4] = static_cast<uint8_t>((b & 0xFF00) >> 8);
      data_[5] = static_cast<uint8_t>((b & 0x00FF) >> 0);
      data_[6] = static_cast<uint8_t>((c & 0xFF00) >> 8);
      data_[7] = static_cast<uint8_t>((c & 0x00FF) >> 0);
      
      for (int index = 0; index < 8; index++)
        data_[8 + index] = d[index];
    }
    
    /// @brief Initializes a new instance of the Guid structure by using the specified integers and bytes.
    /// @param a The first 4 bytes of the GUID.
    /// @param b The next 2 bytes of the GUID.
    /// @param c The next 2 bytes of the GUID.
    /// @param d The next byte of the GUID.
    /// @param e The next byte of the GUID.
    /// @param f The next byte of the GUID.
    /// @param g The next byte of the GUID.
    /// @param h The next byte of the GUID.
    /// @param i The next byte of the GUID.
    /// @param j The next byte of the GUID.
    /// @param k The next byte of the GUID.
    guid(int a, short b, short c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t h, uint8_t i, uint8_t j, uint8_t k) noexcept {
      data_[0] = static_cast<uint8_t>((a & 0xFF000000) >> 24);
      data_[1] = static_cast<uint8_t>((a & 0x00FF0000) >> 16);
      data_[2] = static_cast<uint8_t>((a & 0x0000FF00) >> 8);
      data_[3] = static_cast<uint8_t>((a & 0x000000FF) >> 0);
      data_[4] = static_cast<uint8_t>((b & 0xFF00) >> 8);
      data_[5] = static_cast<uint8_t>((b & 0x00FF) >> 0);
      data_[6] = static_cast<uint8_t>((c & 0xFF00) >> 8);
      data_[7] = static_cast<uint8_t>((c & 0x00FF) >> 0);
      data_[8] = d;
      data_[9] = e;
      data_[10] = f;
      data_[11] = g;
      data_[12] = h;
      data_[13] = i;
      data_[14] = j;
      data_[15] = k;
    }
    
    /// @brief Initializes a new instance of the Guid structure by using the specified uint32_tegers and bytes.
    /// @param a The first 4 bytes of the GUID.
    /// @param b The next 2 bytes of the GUID.
    /// @param c The next 2 bytes of the GUID.
    /// @param d The next byte of the GUID.
    /// @param e The next byte of the GUID.
    /// @param f The next byte of the GUID.
    /// @param g The next byte of the GUID.
    /// @param h The next byte of the GUID.
    /// @param i The next byte of the GUID.
    /// @param j The next byte of the GUID.
    /// @param k The next byte of the GUID.
    guid(uint32_t a, uint16_t b, uint16_t c, uint8_t d, uint8_t e, uint8_t f, uint8_t g, uint8_t h, uint8_t i, uint8_t j, uint8_t k) noexcept {
      data_[0] = static_cast<uint8_t>((a & 0xFF000000) >> 24);
      data_[1] = static_cast<uint8_t>((a & 0x00FF0000) >> 16);
      data_[2] = static_cast<uint8_t>((a & 0x0000FF00) >> 8);
      data_[3] = static_cast<uint8_t>((a & 0x000000FF) >> 0);
      data_[4] = static_cast<uint8_t>((b & 0xFF00) >> 8);
      data_[5] = static_cast<uint8_t>((b & 0x00FF) >> 0);
      data_[6] = static_cast<uint8_t>((c & 0xFF00) >> 8);
      data_[7] = static_cast<uint8_t>((c & 0x00FF) >> 0);
      data_[8] = d;
      data_[9] = e;
      data_[10] = f;
      data_[11] = g;
      data_[12] = h;
      data_[13] = i;
      data_[14] = j;
      data_[15] = k;
    }
    
    /// @brief Initializes a new instance of the guid structure by using the value represented by the specified string.
    /// @param guid A string that contains a GUID in one of the following formats ("d" represents a hexadecimal digit whose case is ignored):
    /// 32 contiguous digits:
    /// dddddddddddddddddddddddddddddddd
    /// -or-
    /// Groups of 8, 4, 4, 4, and 12 digits with hyphens between the groups. The entire GUID can optionally be enclosed in matching braces or parentheses:
    /// dddddddd-dddd-dddd-dddd-dddddddddddd
    /// -or-
    /// {dddddddd-dddd-dddd-dddd-dddddddddddd}
    /// -or-
    /// (dddddddd-dddd-dddd-dddd-dddddddddddd)
    /// -or-
    /// Groups of 8, 4, and 4 digits, and a subset of eight groups of 2 digits, with each group prefixed by "0x" or "0X", and separated by commas. The entire GUID, as well as the subset, is enclosed in matching braces:
    /// {0xdddddddd, 0xdddd, 0xdddd,{0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd,0xdd}}
    /// All braces, commas, and "0x" prefixes are required. All embedded spaces are ignored. All leading zeros in a group are ignored.
    /// The digits shown in a group are the maximum number of meaningful digits that can appear in that group. You can specify from 1 to the number of digits shown for a group. The specified digits are assumed to be the low-order digits of the group.
    /// @exception std::invalid_argument The format of gui is invalid.
    /// @remarks The alphabetic hexadecimal digits in the g parameter can be uppercase or lowercase. For example, the following strings represent the same GUID:
    /// @remarks "ca761232ed4211cebacd00aa0057b223"
    /// @remarks "CA761232-ED42-11CE-BACD-00AA0057B223"
    /// @remarks "{CA761232-ED42-11CE-BACD-00AA0057B223}"
    /// @remarks "(CA761232-ED42-11CE-BACD-00AA0057B223)"
    /// @remarks "{0xCA761232, 0xED42, 0x11CE, {0xBA, 0xCD, 0x00, 0xAA, 0x00, 0x57, 0xB2, 0x23}}"
    guid(const std::string& guid) {
      std::string simple = xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(xtd::strings::replace(guid, "0x", ""), ",", ""), "-", ""), "(", ""), ")", ""), "{", ""), "}", "");
      for (size_t i = 0; i < data_.size(); i ++) {
        data_[i] = xtd::parse<uint8_t>(xtd::strings::substring(simple, 0, 2), xtd::number_styles::hex_number);
        simple = xtd::strings::remove(simple, 0, 2);
      }
    }

    /// @cond
    guid(const guid&) = default;
    guid& operator=(const guid&) = default;
    friend std::ostream& operator <<(std::ostream& os, const guid& guid) noexcept {return os << guid.to_string();}
    /// @endcond
    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    /// | Value             | Condition                          |
    /// |-------------------|------------------------------------|
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    virtual int32_t compare_to(const object& obj) const noexcept override {
      if (!dynamic_cast<const guid*>(&obj)) return 1;
      return compare_to(static_cast<const guid&>(obj));
    }
    
    /// @brief Compares the current instance with another object of the same type.
    /// @param obj An object to compare with this instance.
    /// @return A 32-bit signed integer that indicates the relative order of the objects being compared.
    /// The return value has these meanings:
    /// | Value             | Condition                          |
    /// |-------------------|------------------------------------|
    /// | Less than zero    | This instance is less than obj.    |
    /// | Zero              | This instance is equal to obj.     |
    /// | Greater than zero | This instance is greater than obj. |
    virtual int32_t compare_to(const guid& value) const noexcept override {
      for (size_t i = 0; i < data_.size(); i++)
        if (data_[i] > value.data_[i]) return 1;
        else if (data_[i] < value.data_[i]) return -1;
      return 0;
    }

    bool equals(const object& g) const noexcept override {return dynamic_cast<const guid*>(&g) && equals(static_cast<const guid&>(g));}
    
    bool equals(const guid& g) const noexcept override {
      for (size_t index = 0; index < 16; index++)
        if (data_[index] != g.data_[index]) return false;
      return true;
    }
    
    /// @brief Initializes a new instance of the guid structure.
    /// @return guid A new GUID object.
    /// @remarks This is a convenient static method that you can call to get a new guid.
    /// @remarks The chance that the value of the new guid will be all zeros or equal to any other guid is very low. You can determine whether a GUID consists of all zeros by comparing it to guid::empty().
    static guid new_guid() noexcept;
    
    /// @brief Returns a 16-element byte array that contains the value of this instance.
    /// @return Array<Byte> A 16-element byte array.
    const std::vector<uint8_t>& to_byte_array() const noexcept {return data_;}

    /// @brief Returns a string representation of the value of this instance in registry format.
    /// @return string The value of this Guid, formatted by using the "D" format specifier as follows:
    /// xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
    /// where the value of the GUID is represented as a series of lowercase hexadecimal digits in groups of 8, 4, 4, 4, and 12 digits and separated by hyphens. An example of a return value is "382c74c3-721d-4f34-80e5-57657b6cbc27". To convert the hexadecimal digits from a through f to uppercase, call the string.ToString method on the returned string.
    /// @remarks This method provides a default GUID format that is sufficient for typical use; however, other versions of this method that take a format parameter provide a few common format variations.
    xtd::ustring to_string() const noexcept override {return to_string("D");}
    
    /// @brief Returns a string representation of the value of this Guid instance, according to the provided format specifier.
    /// @param format A single format specifier that indicates how to format the value of this Guid. The format parameter can be "N", "D", "B", "P", or "X". If format is null or an empty string (""), "D" is used.
    /// @return The value of this Guid, represented as a series of lowercase hexadecimal digits in the specified format.
    /// @exception std::invalid_argument The value of format is not null, an empty string (""), "N", "D", "B", "P", or "X".
    /// @remarks The following table shows the accepted format specifiers for the format parameter. "0" represents a digit; hyphens ("-"), braces ("{", "}"), and parentheses ("(", ")") appear as shown.
    /// | Specifier | Format of return value                                                                                                                      |
    /// |-----------|---------------------------------------------------------------------------------------------------------------------------------------------|
    /// | N         | 32 digits:                                                                                                                                  |
    /// |           | 00000000000000000000000000000000                                                                                                            |
    /// | D         | 32 digits separated by hyphens:                                                                                                             |
    /// |           | 00000000-0000-0000-0000-000000000000                                                                                                        |
    /// | B         | 32 digits separated by hyphens, enclosed in braces:                                                                                         |
    /// |           | {00000000-0000-0000-0000-000000000000}                                                                                                      |
    /// | P         | 32 digits separated by hyphens, enclosed in parentheses:                                                                                    |
    /// |           | (00000000-0000-0000-0000-000000000000)                                                                                                      |
    /// | X         | Four hexadecimal values enclosed in braces, where the fourth value is a subset of eight hexadecimal values that is also enclosed in braces: |
    /// |           | {0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}                                                                         |
    std::string to_string(std::string format) const {
      format = format.empty() ? "d" : xtd::strings::to_lower(format);
      
      if (format.size() != 1 || xtd::strings::index_of("ndbpx", format) == std::string::npos)
        throw xtd::format_exception(current_stack_frame_);
      
      bool hyphens = format != "n" && format != "x";
      bool braces = format == "b";
      bool parentheses = format == "p";
      bool hexadecimal = format == "x";
      
      std::string result;
      for (size_t index = 0; index < data_.size(); index++) {
        if (hexadecimal && (index == 4 || index == 6 || (index >= 8 && index <= 15)))
          result += ",";
        if (hexadecimal && (index == 0 || index == 8))
          result += "{";
        if (hexadecimal && (index == 0 || index == 4 || index == 6 || (index >= 8 && index <= 15)))
          result += "0x";
        result += xtd::to_string(data_[index], "x2");
        if (hexadecimal && index == 15)
          result += "}}";
        if (hyphens && (index == 3 || index == 5 || index == 7 || index == 9))
          result += "-";
      }
      
      if (braces)
        result = "{" + result + "}";
      if (parentheses)
        result = "(" + result + ")";
      
      return result;
    }
    
    /// @brief Get A read-only instance of the Guid structure whose value is all zeros.
    /// @return Guid A read-only instance of the Guid structure whose value is all zeros.
    /// @remarks You can compare a GUID with the value of the Guid.Empty field to determine whether a GUID is non-zero. The following example uses the Equality operator to compare two GUID values with Guid.Empty to determine whether they consist exclusively of zeros.
    static const guid empty;

  private:
    std::vector<uint8_t> data_ = std::vector<uint8_t>(16);
  };

  /// @cond
  template<>
  inline std::string to_string(const guid& value, const std::string& fmt, const std::locale& loc) {
    return value.to_string(fmt);
  }
  /// @endcond
}
