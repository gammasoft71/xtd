/// @file
/// @brief Contains xtd::box_char class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "box.hpp"
#include "char32.hpp"
#include "character.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents a boxed char object.
  /// ```cpp
  /// class box_char : public xtd::box<type_t>
  /// ```
  /// @par Inheritance
  /// xtd::object → xtd::box <type_t> → xtd::box <type_t> → xtd::box_char <type_t>
  /// @par Header
  /// ```cpp
  /// #include <xtd/box_char>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks You can use xtd::box to represent a class or structure that does not inherit from xtd::object. Typically used for integral types.
  /// @remarks Use xtd::boxing to box an object.
  /// @remarks Use xtd::unboxing to unbox an object.
  /// @remarks For more information about types, see [Native types, boxing and unboxing](https://gammasoft71.github.io/xtd/docs/documentation/guides/xtd.core/Types%20overview/types).
  /// @par Examples
  /// The following example shows how to create and use xtd::box_char<char8>.
  /// ```cpp
  /// auto stringer = [](const object& value) {return value.to_string();};
  /// char8 unboxed_object = u8'a';
  /// box_char<char8> boxed_object = unboxed_object;
  /// auto result = stringer(boxed_object);
  /// console::write_line("result = {}", result); // Display: result = a;
  /// ```
  template<typename type_t>
  requires xtd::character<type_t>
  class box_char : public xtd::box<type_t> {
  public:
    /// @cond
    box_char() = default;
    box_char(const type_t& value) : box<type_t>(value) {}
    box_char(const box_char&) = default;
    box_char(box_char&&) = default;
    box_char& operator =(const box_char&) = default;
    /// @endcond
    
    /// @name Public Fields
    
    /// @{
    /// @brief Represents the largest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::max().
    static constexpr type_t max_value = std::numeric_limits<type_t>::max();
    /// @brief Represents the smallest possible value of type_t. This field is constant.
    /// @remarks The value of this field is std::numeric_limits<type_t>::lowest().
    static constexpr type_t min_value = std::numeric_limits<type_t>::lowest();
    /// @}

    /// @name Public Static Methods
    
    /// @{
    /// @brief Returns `true` if c is an ASCII character ([ U+0000..U+007F ]).
    /// @param c The character to analyze.
    /// @return `true` if c is an ASCII character; `false` otherwise.
    [[nodiscard]] static auto is_ascii(type_t c) noexcept -> bool {return c > 0 && c <= 0x7F;}
    /// @brief Indicates whether the character at the specified position in a specified string is an ASCII character ([ U+0000..U+007F ]).
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is n ASCII character; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_ascii(const string& s, xtd::usize index) -> bool {return is_ascii(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a control character.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is a control character; otherwise, `false`.
    [[nodiscard]] static auto is_control(type_t c) noexcept -> bool {return std::iscntrl(static_cast<int>(c)) != 0;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a control character.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is a control character; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_control(const string& s, xtd::usize index) -> bool {return is_control(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a decimal digit.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is a decimal digit; otherwise, `false`.
    /// @remarks This method determines whether a type_tis a radix-10 digit. This contrasts with is_number, which determines whether a Char is of any numeric Unicode category. Numbers include characters such as fractions, subscripts, superscripts, Roman numerals, currency numerators, encircled numbers, and script-specific digits.
    [[nodiscard]] static auto is_digit(type_t c) noexcept -> bool {return std::isdigit(static_cast<int>(c)) != 0;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a decimal digit.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is decimal digit; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_digit(const string& s, xtd::usize index) -> bool {return is_digit(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a Unicode letter.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is a letter; otherwise, `false`.
    [[nodiscard]] static auto is_letter(type_t c) noexcept -> bool {return std::isalpha(static_cast<int>(c)) != 0;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a Unicode letter.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is a letter; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_letter(const string& s, xtd::usize index) -> bool {return is_letter(s[index]);}
    
    /// @brief Indicates whether a Unicode character is categorized as a letter or a decimal digit.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is a letter or a decimal digit; otherwise, `false`.
    [[nodiscard]] static auto is_letter_or_digit(type_t c) noexcept -> bool {return std::isalnum(static_cast<int>(c)) != 0;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a letter or a decimal digit.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is a letter or a decimal digit; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_letter_or_digit(const string& s, xtd::usize index) -> bool {return is_letter_or_digit(s[index]);}
    
    /// @brief ndicates whether the specified Unicode character is categorized as a lowercase letter.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is a lowercase letter; otherwise, `false`.
    [[nodiscard]] static auto is_lower(type_t c) noexcept -> bool {return std::islower(static_cast<int>(c)) != 0;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a lowercase letter.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is a lowercase letter; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_lower(const string& s, xtd::usize index) -> bool {return is_lower(s[index]);}
    
    /// @brief Indicates whether a Unicode character is categorized as a number.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is a number; otherwise, `false`.
    [[nodiscard]] static auto is_number(type_t c) noexcept -> bool {return std::isdigit(static_cast<int>(c)) != 0;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a number.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is a number; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_number(const string& s, xtd::usize index) -> bool {return is_number(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a punctuation mark.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is a punctuation mark; otherwise, `false`.
    [[nodiscard]] static auto is_punctuation(type_t c) noexcept -> bool {return std::ispunct(static_cast<int>(c)) != 0;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a punctuation mark.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is categorized as a punctuation mark.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_punctuation(const string& s, xtd::usize index) -> bool {return is_punctuation(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a separator character.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is a separator character; otherwise, `false`.
    [[nodiscard]] static auto is_separator(type_t c) noexcept -> bool {return std::isspace(static_cast<int>(c)) != 0 || c == '\n';}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a separator character.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is categorized as a separator character.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_separator(const string& s, xtd::usize index) -> bool {return is_separator(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as a symbol character.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is a symbol character; otherwise, `false`.
    [[nodiscard]] static auto is_symbol(type_t c) noexcept -> bool {return std::isgraph(static_cast<int>(c)) != 0 || c == 0x9C;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as a symbol character.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is a symbol character; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_symbol(const string& s, xtd::usize index) -> bool {return is_symbol(s[index]);}
    
    /// @brief Indicates whether the specified Unicode character is categorized as an uppercase letter.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is an uppercase letter; otherwise, `false`.
    [[nodiscard]] static auto is_upper(type_t c) noexcept -> bool {return std::isupper(static_cast<int>(c)) != 0;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as an uppercase letter.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is an uppercase letter; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_upper(const string& s, xtd::usize index) -> bool {return is_upper(s[index]);}
    
    /// @brief Determines whether the specified value can be safely converted to type_t without overflow.
    /// @param value The floating point value to validate.
    /// @return true if value is greater than or equal to min_value and less than or equal to max_value; otherwise, false.
    /// @remarks If the value is outside the valid range defined by min_value and max_value, the method returns false.
    [[nodiscard]] static auto is_valid(type_t value) noexcept -> bool {return value >= static_cast<xtd::char32>(min_value) && value <= static_cast<xtd::char32>(max_value);}

    /// @brief Indicates whether the specified Unicode character is categorized as white space.
    /// @param c The Unicode character to evaluate.
    /// @return `true` if c is white space; otherwise, `false`.
    [[nodiscard]] static auto is_white_space(type_t c) noexcept -> bool {return std::isspace(static_cast<int>(c)) != 0;}
    /// @brief Indicates whether the character at the specified position in a specified string is categorized as white space.
    /// @param s A string.
    /// @param index The position of the character to evaluate in s.
    /// @return `true` if the character at position index in s is white space; otherwise, `false`.
    /// @exception xtd::argument_out_of_range_exception index is greater than the last position in s.
    [[nodiscard]] static auto is_white_space(const string& s, xtd::usize index) -> bool {return is_white_space(s[index]);}
    
    using box<type_t>::parse;
    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    static type_t parse(const xtd::string& value, xtd::number_styles styles) {return xtd::parse<type_t>(value, styles);}

    /// @brief Converts the value of a Unicode character to its lowercase equivalent.
    /// @param c The Unicode character to convert.
    /// @return The lowercase equivalent of c, or the unchanged value of c, if c is already lowercase or not alphabetic.
    [[nodiscard]] static auto to_lower(type_t c) noexcept -> type_t {return static_cast<type_t>(std::tolower(static_cast<int>(c)));}
    
    /// @brief Converts the value of a Unicode character to its uppercase equivalent.
    /// @param c The Unicode character to convert.
    /// @return The uppercase equivalent of c, or the unchanged value of c if c is already uppercase, has no uppercase equivalent, or is not alphabetic.
    [[nodiscard]] static auto to_upper(type_t c) noexcept -> type_t {return static_cast<type_t>(std::toupper(static_cast<int>(c)));}
    
    using box<type_t>::try_parse;
    /// @brief Converts the string to its type_t equivalent.
    /// @param value A string containing a type_t to convert.
    /// @return A type_t equivalent to the number contained in value.
    static bool try_parse(const xtd::string& value, type_t& result, xtd::number_styles styles) {return xtd::try_parse<type_t>(value, result, styles);}
    /// @}
  };
}
