/// @file
/// @brief Contains xtd::guid class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "core_export.hpp"
#include "icomparable.hpp"
#include "iequatable.hpp"
#include "iformatable.hpp"
#include "object.hpp"
#include "string.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a globally unique identifier (GUID). A GUID is a 128-bit integer (16 bytes) that can be used across all computers and networks wherever a unique identifier is required. Such an identifier has a very low probability of being duplicated.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @par Examples
  /// The following code example demonstrates the use of xtd::guid class.
  /// @include guid.cpp
  class core_export_ guid final : public object, public icomparable<guid>, public xtd::iequatable<guid>, public xtd::iformatable {
  public:
    /// @name Public Fields
    
    /// @{
    /// @brief Gets A read-only instance of the xtd::guid structure whose value is all zeros.
    /// @return xtd::guid A read-only instance of the xtd::guid structure whose value is all zeros.
    /// @remarks You can compare a GUID with the value of the xtd::guid.Empty field to determine whether a GUID is non-zero. The following example uses the Equality operator to compare two GUID values with xtd::guid.Empty to determine whether they consist exclusively of zeros.
    static const guid empty;
    /// @}
    
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::guid structure.
    guid() = default;
    /// @brief Initializes a new instance of the xtd::guid structure by using the specified array of bytes.
    /// @param bytes A 16-element byte array containing values with which to initialize the GUID.
    /// @exception xtd::argument_exception bytes is not 16 bytes long.
    explicit guid(const xtd::array<xtd::byte>& data);
    /// @brief Initializes a new instance of the xtd::guid structure by using the specified array of bytes.
    /// @param bytes A 16-element byte array containing values with which to initialize the GUID.
    /// @exception xtd::argument_exception bytes is not 16 bytes long.
    explicit guid(const std::initializer_list<xtd::byte>& data);
    /// @brief Initializes a new instance of the xtd::guid structure by using the specified integers and byte array.
    /// @param a The first 4 bytes of the GUID.
    /// @param b The next 2 bytes of the GUID.
    /// @param c The next 2 bytes of the GUID.
    /// @param d The remaining 8 bytes of the GUID.
    /// @exception xtd::argument_exception bytes is not 8 bytes long.
    /// @brief Initializes a new instance of the xtd::guid structure by using the specified integers and byte array.
    /// @param a The first 4 bytes of the GUID.
    /// @param b The next 2 bytes of the GUID.
    /// @param c The next 2 bytes of the GUID.
    /// @param d The remaining 8 bytes of the GUID.
    /// @exception xtd::argument_exception bytes is not 8 bytes long.
    explicit guid(int32 a, int16 b, int16 c, const xtd::array<xtd::byte>& d);
    /// @brief Initializes a new instance of the xtd::guid structure by using the specified  unsigned integers and byte array.
    /// @param a The first 4 bytes of the GUID.
    /// @param b The next 2 bytes of the GUID.
    /// @param c The next 2 bytes of the GUID.
    /// @param d The remaining 8 bytes of the GUID.
    /// @exception xtd::argument_exception bytes is not 8 bytes long.
    /// @brief Initializes a new instance of the xtd::guid structure by using the specified integers and byte array.
    /// @param a The first 4 bytes of the GUID.
    /// @param b The next 2 bytes of the GUID.
    /// @param c The next 2 bytes of the GUID.
    /// @param d The remaining 8 bytes of the GUID.
    /// @exception xtd::argument_exception bytes is not 8 bytes long.
    explicit guid(uint32 a, uint16 b, uint16 c, const xtd::array<xtd::byte>& d);
    /// @brief Initializes a new instance of the xtd::guid structure by using the specified integers and bytes.
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
    guid(int32 a, int16 b, int16 c, xtd::byte d, xtd::byte e, xtd::byte f, xtd::byte g, xtd::byte h, xtd::byte i, xtd::byte j, xtd::byte k) noexcept;
    /// @brief Initializes a new instance of the xtd::guid structure by using the specified unsigned integers and bytes.
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
    guid(uint32 a, uint16 b, uint16 c, xtd::byte d, xtd::byte e, xtd::byte f, xtd::byte g, xtd::byte h, xtd::byte i, xtd::byte j, xtd::byte k) noexcept;
    /// @brief Initializes a new instance of the xtd::guid structure by using the value represented by the specified string.
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
    /// @exception xtd::format_exception The format of gui is invalid.
    /// @remarks The alphabetic hexadecimal digits in the g parameter can be uppercase or lowercase. For example, the following strings represent the same GUID:
    /// @remarks "ca761232ed4211cebacd00aa0057b223"
    /// @remarks "CA761232-ED42-11CE-BACD-00AA0057B223"
    /// @remarks "{CA761232-ED42-11CE-BACD-00AA0057B223}"
    /// @remarks "(CA761232-ED42-11CE-BACD-00AA0057B223)"
    /// @remarks "{0xCA761232, 0xED42, 0x11CE, {0xBA, 0xCD, 0x00, 0xAA, 0x00, 0x57, 0xB2, 0x23}}"
    explicit guid(const string& guid);
    /// @}
    
    /// @cond
    guid(const guid&) = default;
    guid& operator =(const guid&) = default;
    /// @endcond
    
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
    int32 compare_to(const guid& value) const noexcept override;
    
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param obj The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const object& obj) const noexcept override;
    /// @brief Determines whether the specified object is equal to the current object.
    /// @param g The object to compare with the current object.
    /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
    bool equals(const guid& g) const noexcept override;
    
    /// @brief Serves as a hash function for a particular type.
    /// @return A hash code for the current object.
    xtd::size get_hash_code() const noexcept override;
    
    /// @brief Returns a 16-element byte array that contains the value of this instance.
    /// @return A 16-element byte array.
    const xtd::array<xtd::byte>& to_byte_array() const noexcept;
    
    /// @brief Returns a string representation of the value of this instance in registry format.
    /// @return The value of this xtd::guid, formatted by using the "D" format specifier as follows:
    /// xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
    /// where the value of the GUID is represented as a series of lowercase hexadecimal digits in groups of 8, 4, 4, 4, and 12 digits and separated by hyphens. An example of a return value is "382c74c3-721d-4f34-80e5-57657b6cbc27". To convert the hexadecimal digits from a through f to uppercase, call the string::to_string method on the returned string.
    /// @remarks This method provides a default GUID format that is sufficient for typical use; however, other versions of this method that take a format parameter provide a few common format variations.
    xtd::string to_string() const noexcept override;
    /// @brief Returns a string representation of the value of this xtd::guid instance, according to the provided format specifier.
    /// @param format A single format specifier that indicates how to format the value of this xtd::guid. The format parameter can be "N", "D", "B", "P", or "X". If format is null or an empty string (""), "D" is used.
    /// @return The value of this xtd::guid, represented as a series of lowercase hexadecimal digits in the specified format.
    /// @exception xtd::format_exception The value of format is not null, an empty string (""), "N", "D", "B", "P", or "X".
    /// @remarks The following table shows the accepted format specifiers for the format parameter. "0" represents a digit; hyphens ("-"), braces ("{", "}"), and parentheses ("(", ")") appear as shown.
    /// | Specifier | Format of return value                                                                                                                      |
    /// | --------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
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
    string to_string(const string& format) const;
    /// @brief Returns a string representation of the value of this xtd::guid instance, according to the provided format specifier, and locale.
    /// @param format A single format specifier that indicates how to format the value of this xtd::guid. The format parameter can be "N", "D", "B", "P", or "X". If format is null or an empty string (""), "D" is used.
    /// @param loc An std::locale object that contains locale information (see [std::locale](https://en.cppreference.com/w/cpp/locale/locale)).
    /// @return The value of this xtd::guid, represented as a series of lowercase hexadecimal digits in the specified format.
    /// @exception xtd::format_exception The value of format is not null, an empty string (""), "N", "D", "B", "P", or "X".
    /// @remarks The following table shows the accepted format specifiers for the format parameter. "0" represents a digit; hyphens ("-"), braces ("{", "}"), and parentheses ("(", ")") appear as shown.
    /// | Specifier | Format of return value                                                                                                                      |
    /// | --------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
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
    string to_string(const string& format, const std::locale& loc) const override;
    /// @}

    /// @name Public Static Methods
    
    /// @{
    /// @brief Initializes a new instance of the xtd::guid structure.
    /// @return A new GUID object.
    /// @remarks This is a convenient static method that you can call to get a new guid.
    /// @remarks The chance that the value of the new guid will be all zeros or equal to any other guid is very low. You can determine whether a GUID consists of all zeros by comparing it to guid::empty().
    static guid new_guid() noexcept;
    /// @}
    
  private:
    xtd::array<xtd::byte> data_ = xtd::array<xtd::byte>(16);
  };
}
