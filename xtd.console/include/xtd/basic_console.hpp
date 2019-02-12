/// @file
/// @brief Contains xtd::basic_console class.
#pragma once
#include "__get_err_rdbuf.hpp"
#include "__get_in_rdbuf.hpp"
#include "__get_out_rdbuf.hpp"
#include "__opaque_console.hpp"
#include <xtd/strings>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Represents the standard input, output, and error streams for console applications.
  /// @remarks This class cannot be inherited.
  /// @par Examples
  /// The following example demonstrates how to read data from, and write data to, the standard input and output streams. Note that these streams can be redirected by using the set_in and set_out methods.
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
    /// @par Example
    /// The following example demonstrates the beep method. The example accepts a number from 1 through 9 as a command line argument, and plays the beep that number of times.
    /// @include console_beep.cpp
    static void beep() noexcept {beep(800, 200);}
    
    /// @brief Plays the sound of a beep of a specified frequency and duration through the console speaker.
    /// @param frequency The frequency of the beep, ranging from 37 to 32767 hertz
    /// @param duration The duration of the beep measured in milliseconds
    /// @return false if ranging out of range; otherwise true.
    /// @par Example
    /// This example demonstrates the beep method by playing the first few notes of a song through the console speaker.
    /// @include console_song.cpp
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
    
    /// @brief Gets the code page the console uses to read input.
    /// @return The code page used to read console input.
    static int input_code_page() noexcept {return __opaque_console::input_code_page();}
    
    /// @brief Sets the code page the console uses to read input.
    /// @param code_page The code page used to read console input.
    /// @return true if the code page changed; otherwise false.
    static bool input_code_page(int code_page) noexcept {return __opaque_console::input_code_page(code_page);}
    
    /// @brief Gets a value that indicates whether the error output stream has been redirected from the standard error stream.
    /// @param true if error output is redirected; otherwise, false.
    static bool is_error_redireted() noexcept {return error.rdbuf() != __get_err_rdbuf<Char>();}
    
    /// @brief  Gets a value that indicates whether the input stream has been redirected from the standard input stream.
    /// @param true if input is redirected; otherwise, false.
    static bool is_in_redireted() noexcept {return in.rdbuf() != __get_in_rdbuf<Char>();}
    
    /// @brief  Gets a value that indicates whether the output stream has been redirected from the standard output stream.
    /// @param true if output is redirected; otherwise, false.
    static bool is_out_redireted() noexcept {return out.rdbuf() != __get_out_rdbuf<Char>();}
    
    /// @brief Acquires the standard error stream.
    /// @return The standard error stream.
    /// @remarks This method can be used to reacquire the standard error stream after it has been changed by the set_error method.
    static std::basic_ostream<Char> open_standard_error() noexcept {return std::basic_ostream<Char>(__get_err_rdbuf<Char>());}
    
    /// @brief Acquires the standard input stream.
    /// @return The standard input stream.
    /// @remarks This method can be used to reacquire the standard input stream after it has been changed by the set_int method.
    static std::basic_istream<Char> open_standard_input() noexcept {return std::basic_istream<Char>(__get_in_rdbuf<Char>());}
    
    /// @brief Acquires the standard output stream.
    /// @return The standard output stream.
    /// @remarks This method can be used to reacquire the standard output stream after it has been changed by the set_output method.
    static std::basic_ostream<Char> open_standard_output() noexcept {return std::basic_ostream<Char>(__get_out_rdbuf<Char>());}
    
    /// @brief Gets the code page the console uses to write output.
    /// @return The code page used to write console output.
    static int output_code_page() noexcept {return __opaque_console::output_code_page();}
    
    /// @brief Sets the code page the console uses to write output.
    /// @param code_page The code page used to write console output.
    /// @return true if the code page changed; otherwise false.
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
    static void write(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {out << strings::format(fmt, std::forward<Args>(args)...);}

    static void write_line() noexcept {out << std::endl;}
    
    template<typename Arg>
    static void write_line(Arg&& arg) noexcept {out << arg << std::endl;}
    
    template<typename ... Args>
    static void write_line(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {out << strings::format(fmt, std::forward<Args>(args)...) << std::endl;}
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
