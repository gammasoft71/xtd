/// @file
/// @brief Contains xtd::box_char class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "box_integer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a boxed char object.
  /// @code
  /// class box_char : public xtd::box_integer<type_t>
  /// @endcode
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t> → xtd::box_integer <type_t> → xtd::box_char <type_t>
  /// @par Header
  /// @code #include <xtd/box_char> @endcode
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  /// @remarks For more information about types, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Types%20overview/types">Native types, boxing and unboxing</a>.
  /// @par Examples
  /// The following example shows how to create and use xtd::box_char<char8>.
  /// @code
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// char8 unboxed_object = u8'a';
  /// box_char<char8> boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// @endcode
  template<typename type_t>
  class box_char : public xtd::box_integer<type_t> {
  public:
    /// @cond
    box_char() = default;
    box_char(const type_t& value) : box_integer<type_t>(value) {}
    box_char(const box_char&) = default;
    box_char(box_char&&) = default;
    box_char& operator =(const box_char&) = default;
    /// @endcond
    
    /// @name static methods
    
    /// @{
    /// @brief Returns true if c is an ASCII character ([ U+0000..U+007F ]).
    /// @param c The character to analyze.
    /// @return true if c is an ASCII character; false otherwise.
    static bool is_ascii(type_t c) noexcept {return c > 0 && c <= 0x7F;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is an ASCII character ([ U+0000..U+007F ]).
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is n ASCII character; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_ascii(const ustring& s, size_t index) {return is_ascii(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a control character.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is a control character; otherwise, false.
    static bool is_control(type_t c) noexcept {return std::iscntrl(c) != 0;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a control character.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is a control character; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_control(const ustring& s, size_t index) {return is_control(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a decimal digit.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is a decimal digit; otherwise, false.
    /// @remarks This method determines whether a type_tis a radix-10 digit. This contrasts with is_number, which determines whether a Char is of any numeric Unicode category. Numbers include characters such as fractions, subscripts, superscripts, Roman numerals, currency numerators, encircled numbers, and script-specific digits.
    static bool is_digit(type_t c) noexcept {return std::isdigit(c) != 0;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a decimal digit.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is decimal digit; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_digit(const ustring& s, size_t index) {return is_digit(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a Unicode letter.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is a letter; otherwise, false.
    static bool is_letter(type_t c) noexcept {return std::isalpha(c) != 0;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a Unicode letter.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is a letter; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_letter(const ustring& s, size_t index) {return is_letter(s[index]);}
    
    /// @brief Indicates whether a Unicode character is categorized as a letter or a decimal digit.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is a letter or a decimal digit; otherwise, false.
    static bool is_letter_or_digit(type_t c) noexcept {return std::isalnum(c) != 0;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a letter or a decimal digit.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is a letter or a decimal digit; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_letter_or_digit(const ustring& s, size_t index) {return is_letter_or_digit(s[index]);}
    
    /// @brief ndicates whether the specified Unicode character is categorized as a lowercase letter.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is a lowercase letter; otherwise, false.
    static bool is_lower(type_t c) noexcept {return std::islower(c) != 0;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a lowercase letter.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is a lowercase letter; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_lower(const ustring& s, size_t index) {return is_lower(s[index]);}
    
    /// @brief Indicates whether a Unicode character is categorized as a number.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is a number; otherwise, false.
    static bool is_number(type_t c) noexcept {return std::isdigit(c) != 0;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a number.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is a number; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_number(const ustring& s, size_t index) {return is_number(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a punctuation mark.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is a punctuation mark; otherwise, false.
    static bool is_punctuation(type_t c) noexcept {return std::ispunct(c) != 0;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a punctuation mark.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is categorized as a punctuation mark.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_punctuation(const ustring& s, size_t index) {return is_punctuation(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a separator character.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is a separator character; otherwise, false.
    static bool is_separator(type_t c) noexcept {return std::isspace(c) != 0 || c == '\n';}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a separator character.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is categorized as a separator character.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_separator(const ustring& s, size_t index) {return is_separator(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a symbol character.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is a symbol character; otherwise, false.
    static bool is_symbol(type_t c) noexcept {return std::isgraph(c) != 0 || c == 0x9C;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a symbol character.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is a symbol character; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_symbol(const ustring& s, size_t index) {return is_symbol(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as an uppercase letter.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is an uppercase letter; otherwise, false.
    static bool is_upper(type_t c) noexcept {return std::isupper(c) != 0;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as an uppercase letter.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is an uppercase letter; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_upper(const ustring& s, size_t index) {return is_upper(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as white space.
    /// @param c The Unicode character to evaluate.
    /// @return true if c is white space; otherwise, false.
    static bool is_white_space(type_t c) noexcept {return std::isspace(c) != 0;}
    
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as white space.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return true if the character at position index in s is white space; otherwise, false.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    static bool is_white_space(const ustring& s, size_t index) {return is_white_space(s[index]);}
    
    /// @brief Converts the value of a Unicode character to its lowercase equivalent.
    /// @param c The Unicode character to convert.
    /// @return The lowercase equivalent of c, or the unchanged value of c, if c is already lowercase or not alphabetic.
    static char to_lower(type_t c) noexcept {return static_cast<type_t>(std::tolower(c));}
    
    /// @brief Converts the value of a Unicode character to its uppercase equivalent.
    /// @param c The Unicode character to convert.
    /// @return The uppercase equivalent of c, or the unchanged value of c if c is already uppercase, has no uppercase equivalent, or is not alphabetic.
    static char to_upper(type_t c) noexcept {return static_cast<type_t>(std::toupper(c));}
    /// @}
  };
}
