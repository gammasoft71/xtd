/// @file
/// @brief Contains xtd::strings class.
#pragma once

#include "__format.hpp"

#include <algorithm>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Specifies whether applicable strings::Split method overloads include or omit empty substrings from the return value.
  /// @see xtd::strings
  enum class string_split_options {
    /// @brief The return value includes array elements that contain an empty string.
    none,
    /// @brief The return value does not include array elements that contain an empty string.
    remove_empty_entries
  };

  /// @brief The strings Cainteins string operation methods.
  class strings {
  public:
    /// @cond
    strings() = delete;
    /// @endcond
    
    /// @brief Writes the text representation of the specified arguments list, to string using the specified format information.
    /// @param fmt A composite format string.
    /// @param args anarguments list to write using format.
    /// @return string formated.
    /// @remarks A format specifier follows this prototype:
    /// @remarks %[flags][width][.precision][length]specifier
    /// | specifier | Output                                                                                                                                                   | Example      |
    /// |-----------|----------------------------------------------------------------------------------------------------------------------------------------------------------|--------------|
    /// | d or i    | Signed decimal integer                                                                                                                                   | 392          |
    /// | u         | Unsigned decimal integer                                                                                                                                 | 7235         |
    /// | o         | Unsigned octal                                                                                                                                           | 610          |
    /// | x         | Unsigned hexadecimal integer                                                                                                                             | 7fa          |
    /// | X         | Unsigned hexadecimal integer (uppercase)                                                                                                                 | 7FA          |
    /// | f         | Decimal floating point, lowercase                                                                                                                        | 392.65       |
    /// | F         | Decimal floating point, lowercase (uppercase)                                                                                                            | 392.65       |
    /// | e         | Scientific notation (mantissa/exponent), lowercase                                                                                                       | 3.9265e+2    |
    /// | E         | Scientific notation (mantissa/exponent), uppercase                                                                                                       | 3.9265E+2    |
    /// | g         | Use the shortest representation: %e or %f                                                                                                                | 392.65       |
    /// | G         | Use the shortest representation: %E or %F                                                                                                                | 392.65       |
    /// | a         | Hexadecimal floating point, lowercase                                                                                                                    | -0xc.90fep-2 |
    /// | A         | Hexadecimal floating point, uppercase                                                                                                                    | -0XC.90FEP-2 |
    /// | c         | Character                                                                                                                                                | a            |
    /// | s         | String of characters                                                                                                                                     | sample       |
    /// | p         | Pointer address                                                                                                                                          | b8000000     |
    /// | n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location |              |
    /// | %         | A % followed by another % character will write a single % to the stream.                                                                                 | %            |
    /// @remarks The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:
    /// | flags   | description                                                                                                                                                                                                                                                                                                 |
    /// |---------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    /// | -       | Left-justify within the given field width; Right justification is the default (see width sub-specifier).                                                                                                                                                                                                    |
    /// | +       | Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.                                                                                                                                                    |
    /// | (space) | If no sign is going to be written, a blank space is inserted before the value.                                                                                                                                                                                                                              |
    /// | #       | Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero. Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written. |
    /// | 0       | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).                                                                                                                                                                                                 |
    ///
    /// | width    | description                                                                                                                                                                                          |
    /// |----------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    /// | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
    /// | *        | The width is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                                        |
    ///
    /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
    /// |------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
    /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
    /// | .*         | The precision is not specified in the format string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        |
    /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
    /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n              |
    /// |--------|---------------|------------------------|-----------------|-------|----------|-------|----------------|
    /// | (none) | int           | unsigned int           | double          | int   | char*    | void* | int*           |
    /// | hh     | signed char   | unsigned char          |                 |       |          |       | unsigned char* |
    /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*     |
    /// | l      | long int      | unsigned long int      |                 | win_t | wchar_t* |       | long int*      |
    /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int* |
    /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*      |
    /// | z      | size_t        | size_t                 |                 |       |          |       | size_t*        |
    /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*     |
    /// | L      |               |                        | long double     |       |          |       |                |
    /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char value (or a wchar_t) before formatting it for output.
    /// @remarks you can use std::string or std::wstring with format param %%s.
    template<typename Char, typename ... Args>
    static std::basic_string<Char> format(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {return __format(fmt.c_str(), convert_param(std::forward<Args>(args)) ...);}

    /// @cond
    template<typename Char, typename ... Args>
    static std::basic_string<Char> format(const Char* fmt, Args&& ... args) noexcept {return __format(fmt, convert_param(std::forward<Args>(args)) ...);}
    /// @endcond
    
    /// @brief Splits a specified string into a maximum number of substrings based on the characters in an array.
    /// @param str string to split.
    /// @param separators A character array that delimits the substrings in this string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @param options xtd::string_split_options::remove_empty_entries to omit empty array elements from the array returned; or None to include empty array elements in the array returned.
    /// @return An array whose elements contain the substrings in this string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If this instance does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains this instance.
    /// @remarks If the count parameter is zero, or the options parameter is remove_empty_entries and the length of this instance is zero, an empty array is returned.
    /// @remarks Each element of separator defines a separate delimiter character. If the options parameter is None, and two delimiters are adjacent or a delimiter is found at the beginning or end of this instance, the corresponding array element contains an empty string.
    /// @remarks If there are more than count substrings in this instance, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in this instance are returned in the last element of the return value.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
   template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str, const std::vector<Char>& separators, size_t count, string_split_options options) noexcept {
      if (count == 0) return {};
      if (count == 1) return {str};
      
      std::vector<std::basic_string<Char>> list;
      std::basic_string<Char> subString;
      std::vector<Char> split_char_separators = separators.size() == 0 ? std::vector<Char> {9, 10, 11, 12, 13, 32} : separators;
      for (std::string::const_iterator it = str.begin(); it != str.end(); it++) {
        bool is_separator =  std::find(split_char_separators.begin(), split_char_separators.end(), *it) != split_char_separators.end();
        if (!is_separator) subString.append(std::string(1, *it));
        if ((it - str.begin() == str.length() - 1 || is_separator) && (subString.length() > 0 || (subString.length() == 0 && options != string_split_options::remove_empty_entries))) {
          if (list.size() == count - 1) {
            list.push_back(subString + std::string(str.c_str(), it - str.begin() + (is_separator ? 1 : 0), str.length() - (it - str.begin()) + (is_separator ? 1 : 0)));
            return list;
          }
          list.push_back(subString);
          subString.clear();
        }
      }
      
      return list;
    }

    /// @brief Splits a specified string into substrings that are based on the default white-space characters. White-space characters are defined by the c++ standard and return true if they are passed to the std::isspace() or std::iswspace() method.
    /// @param str string to split.
    /// @return An array whose elements contain the substrings in this string that are delimited by one or more characters in white-space separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If this instance does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains this instance.
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str) noexcept {return split(str, std::vector<Char> {9, 10, 11, 12, 13, 32}, std::numeric_limits<size_t>::max(), string_split_options::none);}
    
    /// @brief Splits a specified string into substrings that are based on the characters in an array.
    /// @param str string to split.
    /// @param separators A character array that delimits the substrings in this string, an empty array that contains no delimiters.
    /// @return An array whose elements contain the substrings in this string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If this instance does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains this instance.
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str, const std::vector<Char>& separators) noexcept {return split(str, separators, std::numeric_limits<size_t>::max(), string_split_options::none);}
    
    /// @brief Splits a specified string into substrings based on the characters in an array. You can specify whether the substrings include empty array elements.
    /// @param str string to split.
    /// @param separators A character array that delimits the substrings in this string, an empty array that contains no delimiters.
    /// @param options xtd::string_split_options::remove_empty_entries to omit empty array elements from the array returned; or None to include empty array elements in the array returned.
    /// @return An array whose elements contain the substrings in this string that are delimited by one or more characters in separators. For more information, see the Remarks section.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If this instance does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains this instance.
    /// @remarks If this instance does not contain any of the characters in separator, the returned array consists of a single element that contains this instance.
    /// @remarks If the options parameter is remove_empty_entries and the length of this instance is zero, the method returns an empty array.
    /// @remarks Each element of separator defines a separate delimiter that consists of a single character. If the options argument is none, and two delimiters are adjacent or a delimiter is found at the beginning or end of this instance, the corresponding array element contains empty string. For example, if separator includes two elements, "-" and "_", the value of the string instance is "-_aa-_", and the value of the options argument is None, the method returns a string array with the following five elements:
    ///   1. empty string, which represents the empty string that precedes the "-" character at index 0.
    ///   2. empty string, which represents the empty string between the "-" character at index 0 and the "_" character at index 1.
    ///   3. "aa",
    ///   4. empty string, which represents the empty string that follows the "_" character at index 4.
    ///   5. empty string, which represents the empty string that follows the "-" character at index 5.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the c++ standard and return true if they are passed to the std::isspace() or std::iswspace() method.
    /// @remarks If count is greater than the number of substrings, the available substrings are returned.
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str, const std::vector<Char>& separators, string_split_options options) noexcept {return split(str, separators, std::numeric_limits<size_t>::max(), options);}
    
    /// Splits a specified string into a maximum number of substrings based on the characters in an array. You also specify the maximum number of substrings to return.
    /// @param str string to split.
    /// @param separators A character array that delimits the substrings in this string, an empty array that contains no delimiters.
    /// @param count The maximum number of substrings to return.
    /// @remarks Delimiter characters are not included in the elements of the returned array.
    /// @remarks If this instance does not contain any of the characters in separator, or the count parameter is 1, the returned array consists of a single element that contains this instance.
    /// @remarks If the separator parameter contains no characters, white-space characters are assumed to be the delimiters. White-space characters are defined by the Unicode standard and return true if they are passed to the Char.IsWhiteSpace method.
    /// @remarks Each element of separator defines a separate delimiter character. If two delimiters are adjacent, or a delimiter is found at the beginning or end of this instance, the corresponding array element contains empty string.
    /// @remarks If there are more than count substrings in this instance, the first count minus 1 substrings are returned in the first count minus 1 elements of the return value, and the remaining characters in this instance are returned in the last element of the return value.
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const std::basic_string<Char>& str, const std::vector<Char>& separators, size_t count) noexcept {return split(str, separators, count, string_split_options::none);}

    /// @cond
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str, const std::vector<Char>& separators, size_t count, string_split_options options) noexcept {return split(std::basic_string<Char>(str), separators, count, options);}
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str) noexcept {return split(str, std::vector<Char> {9, 10, 11, 12, 13, 32}, std::numeric_limits<size_t>::max(), string_split_options::none);}
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str, const std::vector<Char>& separators) noexcept {return split(str, separators, std::numeric_limits<size_t>::max(), string_split_options::none);}
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str, const std::vector<Char>& separators, string_split_options options) noexcept {return split(str, separators, std::numeric_limits<size_t>::max(), options);}
    template<typename Char>
    static std::vector<std::basic_string<Char>> split(const Char* str, const std::vector<Char>& separators, size_t count) noexcept {return split(str, separators, count, string_split_options::none);}
    /// @endcond
    
  private:
    template<typename Arg>
    static auto convert_param(Arg&& arg) {
      if constexpr (std::is_same<std::remove_cv_t<std::remove_reference_t<Arg>>, std::string>::value) {
        return std::forward<Arg>(arg).c_str();
      } else if constexpr (std::is_same<std::remove_cv_t<std::remove_reference_t<Arg>>, std::wstring>::value) {
        return std::forward<Arg>(arg).c_str();
      }
      else {
        return std::forward<Arg>(arg);
      }
    }
  };
}
