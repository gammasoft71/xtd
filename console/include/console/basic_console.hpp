/// @file
/// @brief Contains xtd::basic_console class.
#pragma once
#include "__format.hpp"
#include "__get_err_rdbuf.hpp"
#include "__get_in_rdbuf.hpp"
#include "__get_out_rdbuf.hpp"
#include "__opaque_console.hpp"

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Represents the standard input, output, and error streams for console applications.
  /// @remarks This class cannot be inherited.
  /// @par Examples
  /// The following example demonstrates how to read data from, and write data to, the standard input and output streams. Note that these streams can be redirected by using the SetIn and SetOut methods.
  /// @include console1.cpp
  /// @include console_out.cpp
  template<class Char>
  class basic_console final {
  public:    
    /// @brief Gets the error output stream. A std::basic_ostream<Char> that represents the error output stream.
    static std::basic_ostream<Char> error;

    /// @brief Gets the standard input stream. A std::basic_istream<Char> that represents the standard input stream.
    /// @par Example
    /// The following sample illustrates the use of the in property.
    /// @include console_in_out.cpp
    static std::basic_istream<Char> in;
    
    /// @brief Gets the standard output stream. A std::basic_ostream<Char> that represents the standard output stream.
    /// @par Example
    /// The following sample illustrates the use of the out property.
    /// @include console_in_out.cpp
    static std::basic_ostream<Char> out;
    
    /// @cond
    basic_console() = delete;
    /// @endcond
    
    /// @brief Gets the background color of the console.
    /// @return the background console_color.
    /// @remarks A get operation for a Windows-based application, in which a console does not exist, returns console_color.Black.
    /// @par Example
    /// The following example saves the values of the console_color enumeration to an array and stores the current values of the background_color and foreground_color properties to variables. It then changes the foreground color to each color in the console_color enumeration except to the color that matches the current background, and it changes the background color to each color in the console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the reset_color method to restore the original console colors.
    /// @include console_color4.cpp
    static console_color background_color() noexcept {return  __opaque_console::background_color();}
    
    /// @brief Sets the background color of the console.
    /// @param color Aconsole_color that specifies the background color of the console; that is, the color that appears behind each character.
    /// @return false if the color specified in a set operation is not a valid member of console_color or I/O error occurred; otherise true.
    /// @remarks A change to the background_color method affects only output that is written to individual character cells after the background color is changed. To change the background color of the console window as a whole, set the BackgroundColor property and call the Clear method. The following example provides an illustration.
    /// @par Example
    /// The following example saves the values of the console_color enumeration to an array and stores the current values of the background_color and foreground_color properties to variables. It then changes the foreground color to each color in the console_color enumeration except to the color that matches the current background, and it changes the background color to each color in the console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the reset_color method to restore the original console colors.
    /// @include console_color4.cpp
    static bool background_color(console_color color) noexcept {return __opaque_console::background_color(color);}
    
    /// @brief Plays the sound of a beep through the console speaker.
    /// @remarks By default, the beep plays at a frequency of 800 hertz for a duration of 200 milliseconds
    static void beep() noexcept {beep(800, 200);}
    
    /// @brief Plays the sound of a beep of a specified frequency and duration through the console speaker.
    /// @param frequency The frequency of the beep, ranging from 37 to 32767 hertz
    /// @param duration The duration of the beep measured in milliseconds
    /// @return false if ranging out of range; otherwise true.
    static bool beep(unsigned int frequency, unsigned int duration) noexcept {return __opaque_console::beep(frequency, duration);}
    
    /// @brief Gets the height of the buffer area.
    /// @return The current height, in rows, of the buffer area.
    /// @par Example
    /// This example demonstrates the buffer_height and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static int buffer_height() noexcept {return __opaque_console::buffer_height();}
    
    /// @brief Gets or sets the height of the buffer area.
    /// @param height The current height, in rows, of the buffer area.
    /// @return true if buffer heigh changed; otherwise false.
    /// @par Example
    /// This example demonstrates the buffer_height and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static bool buffer_height(int height) noexcept {return __opaque_console::buffer_height(height);}
    
    /// @brief Gets the width of the buffer area.
    /// @return The current width, in columns, of the buffer area.
    /// @par Example
    /// This example demonstrates the BufferHeight and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static int buffer_width() noexcept {return __opaque_console::buffer_width();}
    
    /// @brief Sets the width of the buffer area.
    /// @param width The current width, in columns, of the buffer area.
    /// @par Example
    /// This example demonstrates the BufferHeight and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static bool buffer_width(int width) noexcept {return __opaque_console::buffer_width(width);}
    
    /// @brief Gets a value indicating whether the CAPS LOCK keyboard toggle is turned on or turned off.
    /// @return true if CAPS LOCK is turned on; false if CAPS LOCK is turned off.
    static bool caps_lock() noexcept {return __opaque_console::caps_lock();}
    
    /// @brief Clears the console buffer and corresponding console window of display information.
    /// @remarks Using the clear method is equivalent invoking the MS-DOS cls command in the command prompt window.
    /// @remarks When the Clear method is called, the cursor automatically scrolls to the top-left corner of the window and the contents of the screen buffer are set to blanks using the current foreground background colors.
    /// @par Example
    /// The following example uses the cear method to clear the console before it executes a loop, prompts the user to select a foreground and background color and to enter a string to display. If the user chooses not to exit the program, the console's original foreground and background colors are restored and the Clear method is called again before re-executing the loop.
    /// @include console_clear.cpp
    /// The example relies on a get_key_press method to validate the user's selection of a foreground and background color.
    /// @par Example
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static bool clear() noexcept {return __opaque_console::clear();}
    
    /// @brief Gets the column position of the cursor within the buffer area.
    /// @return The current position, in columns, of the cursor.
    /// @par Example
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static int cursor_left() noexcept {return __opaque_console::cursor_left();}
    
    /// @brief Sets the column position of the cursor within the buffer area.
    /// @param left The current position, in columns, of the cursor.
    /// @return true if cursor left changed; otherwise false.
    /// @par Example
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static bool cursor_left(int left) noexcept {return set_cursor_position(left, cursor_top());}
    
    /// @brief Gets or sets the height of the cursor within a character cell.
    /// @return The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
    /// @par Example
    /// This example demonstrates the cursor_size property. The example increases the size of the cursor each time any console key is pressed, then restores the cursor to its original size before terminating.
    /// @include console_cursor_size.cpp
    static int cursor_size() noexcept {return __opaque_console::cursor_size();}
    
    /// @brief Sets the height of the cursor within a character cell.
    /// @param size The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
    /// @return true if cursor size changed; otherwise false.
    /// @par Example
    /// This example demonstrates the cursor_size property. The example increases the size of the cursor each time any console key is pressed, then restores the cursor to its original size before terminating.
    /// @include console_cursor_size.cpp
    static void cursor_size(int size) noexcept {__opaque_console::cursor_size(size);}
    
    /// @brief Gets the row position of the cursor within the buffer area.
    /// @return The current position, in rows, of the cursor.
    /// @par Example
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static int cursor_top() noexcept {return __opaque_console::cursor_top();}
    
    /// @brief Sets the row position of the cursor within the buffer area.
    /// @param top The current position, in rows, of the cursor.
    /// @return true if cursor top changed; otherwise false.
    /// @par Example
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static bool cursor_top(int top) noexcept {return set_cursor_position(cursor_left(), top);}
    
    /// @brief Gets a value indicating whether the cursor is visible.
    /// @return  true if the cursor is visible; otherwise, false.
    /// @par Example
    /// This example demonstrates the cursor_visible property. The example makes the cursor visible if the first column of input is a '+' character or invisible if the input is a '-' character.
    /// @include console_cursor_visible.cpp
    static bool cursor_visible() noexcept {return __opaque_console::cursor_visible();}
    
    /// @brief Sets a value indicating whether the cursor is visible.
    /// @param visible true if the cursor is visible; otherwise, false.
    /// @par Example
    /// This example demonstrates the cursor_visible property. The example makes the cursor visible if the first column of input is a '+' character or invisible if the input is a '-' character.
    /// @include console_cursor_visible.cpp
    static void cursor_visible(bool visible) noexcept {__opaque_console::cursor_visible(visible);}
    
    /// @brief Gets the foreground color of the console.
    /// @return A console_color that specifies the foreground color of the console; that is, the color of each character that is displayed.
    /// @par Example
    /// The following example saves the values of the console_color enumeration to an array and stores the current values of the background_color and foreground_color properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the reset_color method to restore the original console colors.
    /// @include console_color4.cpp
    static console_color foreground_color() noexcept {return __opaque_console::foreground_color();}
    
    /// @brief Sets the foreground color of the console.
    /// @param color A console_color that specifies the foreground color of the console; that is, the color of each character that is displayed.
    /// @par Example
    /// The following example saves the values of the console_color enumeration to an array and stores the current values of the background_color and foreground_color properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the reset_color method to restore the original console colors.
    /// @include console_color4.cpp
    static bool foreground_color(console_color color) noexcept {return __opaque_console::foreground_color(color);}
    
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
    /// |        | specifiers                                                                                           |
    /// |--------|------------------------------------------------------------------------------------------------------|
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
    /// @remarks you can use std::string or std::wstring with format param %s.
    template<typename ... Args>
    static std::basic_string<Char> format(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {return __format(fmt.c_str(), convert_param(std::forward<Args>(args)) ...);}
    
    static int input_code_page() noexcept {return __opaque_console::input_code_page();}
    
    static bool input_code_page(int code_page) noexcept {return __opaque_console::input_code_page(code_page);}
    
    static bool is_error_redireted() noexcept {return error.rdbuf() != __get_err_rdbuf<Char>();}
    
    static bool is_in_redireted() noexcept {return in.rdbuf() != __get_in_rdbuf<Char>();}
    
    static bool is_out_redireted() noexcept {return out.rdbuf() != __get_out_rdbuf<Char>();}
    
    static std::basic_ostream<Char> open_standard_error() noexcept {return std::basic_ostream<Char>(__get_err_rdbuf<Char>());}
    
    static std::basic_istream<Char> open_standard_input() noexcept {return std::basic_istream<Char>(__get_in_rdbuf<Char>());}
    
    static std::basic_ostream<Char> open_standard_output() noexcept {return std::basic_ostream<Char>(__get_out_rdbuf<Char>());}
    
    static int output_code_page() noexcept {return __opaque_console::output_code_page();}
    
    static bool output_code_page(int code_page) noexcept {return __opaque_console::output_code_page(code_page);}
    
    static std::basic_string<Char> read_line() noexcept {
      std::basic_string<Char> result;
      in >> result;
      return result;
    }
    
    static bool reset_color() noexcept {return __opaque_console::reset_color();}
    
    static bool set_cursor_position(int left, int top) noexcept {return __opaque_console::set_cursor_position(left, top);}
    
    static void set_error(const std::ostream& os) noexcept {error.rdbuf(os.rdbuf());}
    
    static void set_in(const std::istream& is) noexcept  {in.rdbuf(is.rdbuf());}
    
    static void set_out(const std::ostream& os) noexcept  {out.rdbuf(os.rdbuf());}
    
    static std::map<int, console_special_key> signal_keys() noexcept {return __opaque_console::signal_keys();}
    
    static int window_height() noexcept {return __opaque_console::window_height();}
    
    static int window_left() noexcept {return __opaque_console::window_left();}
    
    static int window_top() noexcept {return __opaque_console::window_top();}
    
    static int window_width() noexcept {return __opaque_console::window_width();}
    
    template<typename Arg>
    static void write(Arg&& arg) noexcept {out << arg;}
    
    template<typename ... Args>
    static void write(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {out << format(fmt, args...);}

    static void write_line() noexcept {out << std::endl;}
    
    template<typename Arg>
    static void write_line(Arg&& arg) noexcept {out << arg << std::endl;}
    
    template<typename ... Args>
    static void write_line(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {out << format(fmt, args...) << std::endl;}
    
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
  
  /// @cond
  template<class Char>
  std::basic_ostream<Char> basic_console<Char>::error {__get_err_rdbuf<Char>()};
  template<class Char>
  std::basic_istream<Char> basic_console<Char>::in {__get_in_rdbuf<Char>()};
  template<class Char>
  std::basic_ostream<Char> basic_console<Char>::out {__get_out_rdbuf<Char>()};
  /// @endcond
}
