/// @file
/// @brief Contains xtd::println methods.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "string.hpp"
#include "u8string.hpp"
#include "u16string.hpp"
#include "u32string.hpp"
#include "wstring.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Writes the text representation of the specified arguments list, to basic_string using the specified format information.
  /// @param fmt A composite format basic_string.
  /// @param args arguments list to write using format.
  /// @return basic_string formatted.
  /// @ingroup format_parse
  /// @remarks A format specifier follows this prototype:
  /// @remarks %[flags][width][.precision][length]specifier
  /// | specifier | Output                                                                                                                                                   | Example      |
  /// | --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ |
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
  /// | s         | basic_string of characters                                                                                                                               | sample       |
  /// | p         | Pointer address                                                                                                                                          | b8000000     |
  /// | n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location |              |
  /// | %         | A % followed by another % character will write a single % to the stream.                                                                                 | %            |
  /// @remarks The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:
  /// | flags   | description                                                                                                                                                                                                                                                                                                 |
  /// | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | -       | Left-justify within the given field width; Right justification is the default (see width sub-specifier).                                                                                                                                                                                                    |
  /// | +       | Forces to prefix the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.                                                                                                                                                     |
  /// | (space) | If no sign is going to be written, a blank space is inserted before the value.                                                                                                                                                                                                                              |
  /// | #       | Used with o, x or X specifiers the value is prefixed with 0, 0x or 0X respectively for values different than zero. Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.  |
  /// | 0       | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).                                                                                                                                                                                                 |
  ///
  /// | width    | description                                                                                                                                                                                          |
  /// | -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
  /// | *        | The width is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                  |
  ///
  /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
  /// | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
  /// | .*         | The precision is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
  /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
  /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n               |
  /// | ------ | ------------- | ---------------------- | --------------- | ----- | -------- | ----- | --------------- |
  /// | (none) | int           | unsigned int           | double          | int   | char8*   | void* | int*            |
  /// | hh     | signed char8  | unsigned char8         |                 |       |          |       | unsigned char8* |
  /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*      |
  /// | l      | long int      | unsigned long int      |                 | win_t | wchar*   |       | long int*       |
  /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int*  |
  /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*       |
  /// | z      | size_t        | size_t                 |                 |       |          |       | size_t*         |
  /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*      |
  /// | L      |               |                        | long double     |       |          |       |                 |
  /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char8 value (or a wchar) before formatting it for output.
  /// @remarks you can use std::basic_string or std::wstring with format param %%s.
  template<class ...args_t>
  xtd::string sprintf(const xtd::string& fmt, args_t&& ... args) {return xtd::string::sprintf(fmt, std::forward<args_t>(args)...);}
#if defined(__xtd__cpp_lib_char8_t)
  /// @brief Writes the text representation of the specified arguments list, to basic_string using the specified format information.
  /// @param fmt A composite format basic_string.
  /// @param args arguments list to write using format.
  /// @return basic_string formatted.
  /// @ingroup format_parse
  /// @remarks A format specifier follows this prototype:
  /// @remarks %[flags][width][.precision][length]specifier
  /// | specifier | Output                                                                                                                                                   | Example      |
  /// | --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ |
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
  /// | s         | basic_string of characters                                                                                                                               | sample       |
  /// | p         | Pointer address                                                                                                                                          | b8000000     |
  /// | n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location |              |
  /// | %         | A % followed by another % character will write a single % to the stream.                                                                                 | %            |
  /// @remarks The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:
  /// | flags   | description                                                                                                                                                                                                                                                                                                 |
  /// | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | -       | Left-justify within the given field width; Right justification is the default (see width sub-specifier).                                                                                                                                                                                                    |
  /// | +       | Forces to prefix the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.                                                                                                                                                     |
  /// | (space) | If no sign is going to be written, a blank space is inserted before the value.                                                                                                                                                                                                                              |
  /// | #       | Used with o, x or X specifiers the value is prefixed with 0, 0x or 0X respectively for values different than zero. Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.  |
  /// | 0       | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).                                                                                                                                                                                                 |
  ///
  /// | width    | description                                                                                                                                                                                          |
  /// | -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
  /// | *        | The width is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                  |
  ///
  /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
  /// | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
  /// | .*         | The precision is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
  /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
  /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n               |
  /// | ------ | ------------- | ---------------------- | --------------- | ----- | -------- | ----- | --------------- |
  /// | (none) | int           | unsigned int           | double          | int   | char8*   | void* | int*            |
  /// | hh     | signed char8  | unsigned char8         |                 |       |          |       | unsigned char8* |
  /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*      |
  /// | l      | long int      | unsigned long int      |                 | win_t | wchar*   |       | long int*       |
  /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int*  |
  /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*       |
  /// | z      | size_t        | size_t                 |                 |       |          |       | size_t*         |
  /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*      |
  /// | L      |               |                        | long double     |       |          |       |                 |
  /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char8 value (or a wchar) before formatting it for output.
  /// @remarks you can use std::basic_string or std::wstring with format param %%s.
  template<class ...args_t>
  xtd::u8string sprintf(const xtd::u8string& fmt, args_t&& ... args) {return xtd::string::sprintf(fmt.to_string(), std::forward<args_t>(args)...);}
#endif
  /// @brief Writes the text representation of the specified arguments list, to basic_string using the specified format information.
  /// @param fmt A composite format basic_string.
  /// @param args arguments list to write using format.
  /// @return basic_string formatted.
  /// @ingroup format_parse
  /// @remarks A format specifier follows this prototype:
  /// @remarks %[flags][width][.precision][length]specifier
  /// | specifier | Output                                                                                                                                                   | Example      |
  /// | --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ |
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
  /// | s         | basic_string of characters                                                                                                                               | sample       |
  /// | p         | Pointer address                                                                                                                                          | b8000000     |
  /// | n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location |              |
  /// | %         | A % followed by another % character will write a single % to the stream.                                                                                 | %            |
  /// @remarks The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:
  /// | flags   | description                                                                                                                                                                                                                                                                                                 |
  /// | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | -       | Left-justify within the given field width; Right justification is the default (see width sub-specifier).                                                                                                                                                                                                    |
  /// | +       | Forces to prefix the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.                                                                                                                                                     |
  /// | (space) | If no sign is going to be written, a blank space is inserted before the value.                                                                                                                                                                                                                              |
  /// | #       | Used with o, x or X specifiers the value is prefixed with 0, 0x or 0X respectively for values different than zero. Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.  |
  /// | 0       | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).                                                                                                                                                                                                 |
  ///
  /// | width    | description                                                                                                                                                                                          |
  /// | -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
  /// | *        | The width is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                  |
  ///
  /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
  /// | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
  /// | .*         | The precision is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
  /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
  /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n               |
  /// | ------ | ------------- | ---------------------- | --------------- | ----- | -------- | ----- | --------------- |
  /// | (none) | int           | unsigned int           | double          | int   | char8*   | void* | int*            |
  /// | hh     | signed char8  | unsigned char8         |                 |       |          |       | unsigned char8* |
  /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*      |
  /// | l      | long int      | unsigned long int      |                 | win_t | wchar*   |       | long int*       |
  /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int*  |
  /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*       |
  /// | z      | size_t        | size_t                 |                 |       |          |       | size_t*         |
  /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*      |
  /// | L      |               |                        | long double     |       |          |       |                 |
  /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char8 value (or a wchar) before formatting it for output.
  /// @remarks you can use std::basic_string or std::wstring with format param %%s.
  template<class ...args_t>
  xtd::u16string sprintf(const xtd::u16string& fmt, args_t&& ... args) {return xtd::string::sprintf(fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to basic_string using the specified format information.
  /// @param fmt A composite format basic_string.
  /// @param args arguments list to write using format.
  /// @return basic_string formatted.
  /// @ingroup format_parse
  /// @remarks A format specifier follows this prototype:
  /// @remarks %[flags][width][.precision][length]specifier
  /// | specifier | Output                                                                                                                                                   | Example      |
  /// | --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ |
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
  /// | s         | basic_string of characters                                                                                                                               | sample       |
  /// | p         | Pointer address                                                                                                                                          | b8000000     |
  /// | n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location |              |
  /// | %         | A % followed by another % character will write a single % to the stream.                                                                                 | %            |
  /// @remarks The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:
  /// | flags   | description                                                                                                                                                                                                                                                                                                 |
  /// | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | -       | Left-justify within the given field width; Right justification is the default (see width sub-specifier).                                                                                                                                                                                                    |
  /// | +       | Forces to prefix the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.                                                                                                                                                     |
  /// | (space) | If no sign is going to be written, a blank space is inserted before the value.                                                                                                                                                                                                                              |
  /// | #       | Used with o, x or X specifiers the value is prefixed with 0, 0x or 0X respectively for values different than zero. Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.  |
  /// | 0       | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).                                                                                                                                                                                                 |
  ///
  /// | width    | description                                                                                                                                                                                          |
  /// | -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
  /// | *        | The width is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                  |
  ///
  /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
  /// | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
  /// | .*         | The precision is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
  /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
  /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n               |
  /// | ------ | ------------- | ---------------------- | --------------- | ----- | -------- | ----- | --------------- |
  /// | (none) | int           | unsigned int           | double          | int   | char8*   | void* | int*            |
  /// | hh     | signed char8  | unsigned char8         |                 |       |          |       | unsigned char8* |
  /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*      |
  /// | l      | long int      | unsigned long int      |                 | win_t | wchar*   |       | long int*       |
  /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int*  |
  /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*       |
  /// | z      | size_t        | size_t                 |                 |       |          |       | size_t*         |
  /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*      |
  /// | L      |               |                        | long double     |       |          |       |                 |
  /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char8 value (or a wchar) before formatting it for output.
  /// @remarks you can use std::basic_string or std::wstring with format param %%s.
  template<class ...args_t>
  xtd::u32string sprintf(const xtd::u32string& fmt, args_t&& ... args) {return xtd::string::sprintf(fmt.to_string(), std::forward<args_t>(args)...);}
  /// @brief Writes the text representation of the specified arguments list, to basic_string using the specified format information.
  /// @param fmt A composite format basic_string.
  /// @param args arguments list to write using format.
  /// @return basic_string formatted.
  /// @ingroup format_parse
  /// @remarks A format specifier follows this prototype:
  /// @remarks %[flags][width][.precision][length]specifier
  /// | specifier | Output                                                                                                                                                   | Example      |
  /// | --------- | -------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------ |
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
  /// | s         | basic_string of characters                                                                                                                               | sample       |
  /// | p         | Pointer address                                                                                                                                          | b8000000     |
  /// | n         | Nothing printed. The corresponding argument must be a pointer to a signed int. The number of characters written so far is stored in the pointed location |              |
  /// | %         | A % followed by another % character will write a single % to the stream.                                                                                 | %            |
  /// @remarks The format specifier can also contain sub-specifiers: flags, width, .precision and modifiers (in that order), which are optional and follow these specifications:
  /// | flags   | description                                                                                                                                                                                                                                                                                                 |
  /// | ------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | -       | Left-justify within the given field width; Right justification is the default (see width sub-specifier).                                                                                                                                                                                                    |
  /// | +       | Forces to prefix the result with a plus or minus sign (+ or -) even for positive numbers. By default, only negative numbers are preceded with a - sign.                                                                                                                                                     |
  /// | (space) | If no sign is going to be written, a blank space is inserted before the value.                                                                                                                                                                                                                              |
  /// | #       | Used with o, x or X specifiers the value is prefixed with 0, 0x or 0X respectively for values different than zero. Used with a, A, e, E, f, F, g or G it forces the written output to contain a decimal point even if no more digits follow. By default, if no digits follow, no decimal point is written.  |
  /// | 0       | Left-pads the number with zeroes (0) instead of spaces when padding is specified (see width sub-specifier).                                                                                                                                                                                                 |
  ///
  /// | width    | description                                                                                                                                                                                          |
  /// | -------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | (number) | Minimum number of characters to be printed. If the value to be printed is shorter than this number, the result is padded with blank spaces. The value is not truncated even if the result is larger. |
  /// | *        | The width is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                  |
  ///
  /// | .precision | description                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              |
  /// | ---------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
  /// | .number    | For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written. If the value to be written is shorter than this number, the result is padded with leading zeros. The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0. For a, A, e, E, f and F specifiers: this is the number of digits to be printed after the decimal point (by default, this is 6). For g and G specifiers: This is the maximum number of significant digits to be printed. For s: this is the maximum number of characters to be printed. By default all characters are printed until the ending null character is encountered. If the period is specified without an explicit value for precision, 0 is assumed. |
  /// | .*         | The precision is not specified in the format basic_string, but as an additional integer value argument preceding the argument that has to be formatted.                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  |
  /// @remarks The length sub-specifier modifies the length of the data type. This is a chart showing the types used to interpret the corresponding arguments with and without length specifier (if a different type is used, the proper type promotion or conversion is performed, if allowed):
  /// | length | d i           | u o x X                | f F e E g G a A | c     | s        | p     | n               |
  /// | ------ | ------------- | ---------------------- | --------------- | ----- | -------- | ----- | --------------- |
  /// | (none) | int           | unsigned int           | double          | int   | char8*   | void* | int*            |
  /// | hh     | signed char8  | unsigned char8         |                 |       |          |       | unsigned char8* |
  /// | h      | short int     | unsigned short int     |                 |       |          |       | short int*      |
  /// | l      | long int      | unsigned long int      |                 | win_t | wchar*   |       | long int*       |
  /// | ll     | long long int | unsigned long long int |                 |       |          |       | long long int*  |
  /// | j      | intmax_t      | uintmax_t              |                 |       |          |       | intmax_t*       |
  /// | z      | size_t        | size_t                 |                 |       |          |       | size_t*         |
  /// | t      | ptrdiff_t     | ptrdiff_t              |                 |       |          |       | ptrdiff_t*      |
  /// | L      |               |                        | long double     |       |          |       |                 |
  /// @remarks Note regarding the c specifier: it takes an int (or wint_t) as argument, but performs the proper conversion to a char8 value (or a wchar) before formatting it for output.
  /// @remarks you can use std::basic_string or std::wstring with format param %%s.
  template<class ...args_t>
  xtd::wstring sprintf(const xtd::wstring& fmt, args_t&& ... args) {return xtd::string::sprintf(fmt.to_string(), std::forward<args_t>(args)...);}

  /// @cond
  template<class ...args_t>
  xtd::string sprintf(const char* fmt, args_t&& ... args) {return xtd::string::sprintf(std::string {fmt}, std::forward<args_t>(args)...);}
#if defined(__xtd__cpp_lib_char8_t)
  template<class ...args_t>
  xtd::u8string sprintf(const char8_t* fmt, args_t&& ... args) {return xtd::string::sprintf(std::u8string {fmt}, std::forward<args_t>(args)...);}
#endif
  template<class ...args_t>
  xtd::u16string sprintf(const char16_t* fmt, args_t&& ... args) {return xtd::string::sprintf(std::u16string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::u32string sprintf(const char32_t* fmt, args_t&& ... args) {return xtd::string::sprintf(std::u32string {fmt}, std::forward<args_t>(args)...);}
  template<class ...args_t>
  xtd::wstring sprintf(const wchar_t* fmt, args_t&& ... args) {return xtd::string::sprintf(std::wstring {fmt}, std::forward<args_t>(args)...);}
  /// @endcond
}
