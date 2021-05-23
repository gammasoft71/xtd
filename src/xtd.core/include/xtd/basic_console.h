/// @file
/// @brief Contains xtd::basic_console class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "__generic_stream_output.h"
#include <xtd/strings.h>
#include "__get_err_rdbuf.h"
#include "__get_in_rdbuf.h"
#include "__get_out_rdbuf.h"
#include "__opaque_console.h"
#include "console_cancel_event_handler.h"
#include <xtd/event.h>
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the standard input, output, and error streams for console applications.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core system
  /// @remarks This class cannot be inherited.
  /// @par Examples
  /// The following example demonstrates how to read data from, and write data to, the standard input and output streams. Note that these streams can be redirected by using the set_in and set_out methods.
  /// @include console1.cpp
  /// @include console_out.cpp
  template<class char_t>
  class basic_console final static_ {
  public:    
    /// @brief Gets the error output stream. A std::basic_ostream<char_t> that represents the error output stream.
    static std::basic_ostream<char_t> error;
    /// @brief Gets the standard input stream. A std::basic_istream<char_t> that represents the standard input stream.
    /// @par Examples
    /// The following sample illustrates the use of the in property.
    /// @include console_in_out.cpp
    static std::basic_istream<char_t> in;
    /// @brief Gets the standard output stream. A std::basic_ostream<char_t> that represents the standard output stream.
    /// @par Examples
    /// The following sample illustrates the use of the out property.
    /// @include console_in_out.cpp
    static std::basic_ostream<char_t> out;
    
    /// @brief Occurs when the Control modifier key (Ctrl) and either the ConsoleKey.C console key (C) or the Break key are pressed simultaneously (Ctrl+C or Ctrl+Break).
    /// @remarks This event is used in conjunction with xtd::console_cancel_event_handler and xtd::console_cancel_event_args. The cancel_key_press event enables a console application to intercept the Ctrl+C signal so the event handler can decide whether to continue executing or terminate. For more information about handling events, see Handling and Raising Events.
    /// @remarks When the user presses either Ctrl+C or Ctrl+Break, the cancel_key_press event is fired and the application's console_cancel_event_handler event handler is executed. The event handler is passed a console_cancel_event_args object that has two useful properties:
    /// * special_key, which allows you to determine whether the handler was invoked as a result of the user pressing Ctrl+C (the property value is console_special_key::control_c) or Ctrl+Break (the property value is console_special_key.control_break).
    /// * Cancel, which allows you to determine how to your application should respond to the user pressing Ctrl+C or Ctrl+Break. By default, the cancel property is false, which causes program execution to terminate when the event handler exits. Changing its property to true specifies that the application should continue to execute.
    /// @note If your application has simple requirements, you can use the treat_control_c_as_input property instead of this event. By setting this property to false, you can ensure that your application always exits if the user presses Ctrl+C. By setting it to true, you can ensure that pressing Ctrl+C will not terminate the application.
    static event<basic_console<char_t>, console_cancel_event_handler> cancel_key_press;

    /// @brief Gets the background color of the console.
    /// @return the background console_color.
    /// @remarks A get operation for a Windows-based application, in which a console does not exist, returns console_color::black.
    /// @par Examples
    /// The following example saves the values of the console_color enumeration to an array and stores the current values of the background_color and foreground_color properties to variables. It then changes the foreground color to each color in the console_color enumeration except to the color that matches the current background, and it changes the background color to each color in the console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the reset_color method to restore the original console colors.
    /// @include console_color4.cpp
    static console_color background_color() {return  __opaque_console::background_color();}
    /// @brief Sets the background color of the console.
    /// @param color Aconsole_color that specifies the background color of the console; that is, the color that appears behind each character.
    /// @remarks A change to the background_color method affects only output that is written to individual character cells after the background color is changed. To change the background color of the console window as a whole, set the BackgroundColor property and call the Clear method. The following example provides an illustration.
    /// @par Examples
    /// The following example saves the values of the console_color enumeration to an array and stores the current values of the background_color and foreground_color properties to variables. It then changes the foreground color to each color in the console_color enumeration except to the color that matches the current background, and it changes the background color to each color in the console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the reset_color method to restore the original console colors.
    /// @include console_color4.cpp
    static void background_color(console_color color) {__opaque_console::background_color(color);}
    
    /// @brief Plays the sound of a beep through the console speaker.
    /// @remarks By default, the beep plays at a frequency of 800 hertz for a duration of 200 milliseconds
    /// @par Examples
    /// The following example demonstrates the beep method. The example accepts a number from 1 through 9 as a command line argument, and plays the beep that number of times.
    /// @include console_beep.cpp
    static void beep() {beep(800, 200);}
    /// @brief Plays the sound of a beep of a specified frequency and duration through the console speaker.
    /// @param frequency The frequency of the beep, ranging from 37 to 32767 hertz
    /// @param duration The duration of the beep measured in milliseconds
    /// @par Examples
    /// This example demonstrates the beep method by playing the first few notes of a song through the console speaker.
    /// @include console_song.cpp
    static void beep(unsigned int frequency, unsigned int duration) {__opaque_console::beep(frequency, duration);}
    
    /// @brief Gets the height of the buffer area.
    /// @return The current height, in rows, of the buffer area.
    /// @par Examples
    /// This example demonstrates the buffer_height and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static int buffer_height() {return __opaque_console::buffer_height();}
    /// @brief Sets or sets the height of the buffer area.
    /// @param height The current height, in rows, of the buffer area.
    /// @par Examples
    /// This example demonstrates the buffer_height and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static void buffer_height(int height) {__opaque_console::buffer_height(height);}
    
    /// @brief Gets the width of the buffer area.
    /// @return The current width, in columns, of the buffer area.
    /// @par Examples
    /// This example demonstrates the BufferHeight and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static int buffer_width() {return __opaque_console::buffer_width();}
    /// @brief Sets the width of the buffer area.
    /// @param width The current width, in columns, of the buffer area.
    /// @par Examples
    /// This example demonstrates the BufferHeight and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static void buffer_width(int width) {__opaque_console::buffer_width(width);}
    
    /// @brief Gets a value indicating whether the CAPS LOCK keyboard toggle is turned on or turned off.
    /// @return true if CAPS LOCK is turned on; false if CAPS LOCK is turned off.
    static bool caps_lock() {return __opaque_console::caps_lock();}
    
    /// @brief Clears the console buffer and corresponding console window of display information.
    /// @remarks Using the clear method is equivalent invoking the MS-DOS cls command in the command prompt window.
    /// @remarks When the Clear method is called, the cursor automatically scrolls to the top-left corner of the window and the contents of the screen buffer are set to blanks using the current foreground background colors.
    /// @par Examples
    /// The following example uses the cear method to clear the console before it executes a loop, prompts the user to select a foreground and background color and to enter a string to display. If the user chooses not to exit the program, the console's original foreground and background colors are restored and the Clear method is called again before re-executing the loop.
    /// @include console_clear.cpp
    /// The example relies on a get_key_press method to validate the user's selection of a foreground and background color.
    /// @par Examples
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static void clear() {__opaque_console::clear();}
    
    /// @brief Gets the column position of the cursor within the buffer area.
    /// @return The current position, in columns, of the cursor.
    /// @par Examples
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static int cursor_left() {return __opaque_console::cursor_left();}
    /// @brief Sets the column position of the cursor within the buffer area.
    /// @param left The current position, in columns, of the cursor.
    /// @return true if cursor left changed; otherwise false.
    /// @par Examples
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static void cursor_left(int left) {set_cursor_position(left, cursor_top());}
    
    /// @brief Gets or sets the height of the cursor within a character cell.
    /// @return The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
    /// @par Examples
    /// This example demonstrates the cursor_size property. The example increases the size of the cursor each time any console key is pressed, then restores the cursor to its original size before terminating.
    /// @include console_cursor_size.cpp
    static int cursor_size() {return __opaque_console::cursor_size();}
    /// @brief Sets the height of the cursor within a character cell.
    /// @param size The size of the cursor expressed as a percentage of the height of a character cell. The property value ranges from 1 to 100.
    /// @par Examples
    /// This example demonstrates the cursor_size property. The example increases the size of the cursor each time any console key is pressed, then restores the cursor to its original size before terminating.
    /// @include console_cursor_size.cpp
    static void cursor_size(int size) {__opaque_console::cursor_size(size);}
    
    /// @brief Gets the row position of the cursor within the buffer area.
    /// @return The current position, in rows, of the cursor.
    /// @par Examples
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static int cursor_top() {return __opaque_console::cursor_top();}
    /// @brief Sets the row position of the cursor within the buffer area.
    /// @param top The current position, in rows, of the cursor.
    /// @return true if cursor top changed; otherwise false.
    /// @par Examples
    /// This example demonstrates the cursor_left and cursor_top properties, and the set_cursor_position and clear methods. The example positions the cursor, which determines where the next write will occur, to draw a 5 character by 5 character rectangle using a combination of "+", "|", and "-" strings. Note that the rectangle could be drawn with fewer steps using a combination of other strings.
    /// @include console_cursor.cpp
    static void cursor_top(int top) {set_cursor_position(cursor_left(), top);}
    
    /// @brief Gets a value indicating whether the cursor is visible.
    /// @return true if the cursor is visible; otherwise, false.
    /// @par Examples
    /// This example demonstrates the cursor_visible property. The example makes the cursor visible if the first column of input is a '+' character or invisible if the input is a '-' character.
    /// @include console_cursor_visible.cpp
    static bool cursor_visible() {return __opaque_console::cursor_visible();}
    /// @brief Sets a value indicating whether the cursor is visible.
    /// @param visible true if the cursor is visible; otherwise, false.
    /// @par Examples
    /// This example demonstrates the cursor_visible property. The example makes the cursor visible if the first column of input is a '+' character or invisible if the input is a '-' character.
    /// @include console_cursor_visible.cpp
    static void cursor_visible(bool visible) {__opaque_console::cursor_visible(visible);}
    
    /// @brief Gets the foreground color of the console.
    /// @return A console_color that specifies the foreground color of the console; that is, the color of each character that is displayed.
    /// @par Examples
    /// The following example saves the values of the console_color enumeration to an array and stores the current values of the background_color and foreground_color properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the reset_color method to restore the original console colors.
    /// @include console_color4.cpp
    static console_color foreground_color() {return __opaque_console::foreground_color();}
    /// @brief Sets the foreground color of the console.
    /// @param color A console_color that specifies the foreground color of the console; that is, the color of each character that is displayed.
    /// @par Examples
    /// The following example saves the values of the console_color enumeration to an array and stores the current values of the background_color and foreground_color properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the reset_color method to restore the original console colors.
    /// @include console_color4.cpp
    static bool foreground_color(console_color color) {return __opaque_console::foreground_color(color);}
    
    /// @brief Gets the code page the console uses to read input.
    /// @return The code page used to read console input.
    static int input_code_page() {return __opaque_console::input_code_page();}
    /// @brief Sets the code page the console uses to read input.
    /// @param code_page The code page used to read console input.
    /// @return true if the code page changed; otherwise false.
    static bool input_code_page(int code_page) {return __opaque_console::input_code_page(code_page);}
    
    /// @brief Gets a value that indicates whether the error output stream has been redirected from the standard error stream.
    /// @param true if error output is redirected; otherwise, false.
    static bool is_error_redireted() {return error.rdbuf() != __get_err_rdbuf<char_t>();}
    /// @brief  Gets a value that indicates whether the input stream has been redirected from the standard input stream.
    /// @param true if input is redirected; otherwise, false.
    static bool is_in_redireted() {return in.rdbuf() != __get_in_rdbuf<char_t>();}
    /// @brief  Gets a value that indicates whether the output stream has been redirected from the standard output stream.
    /// @param true if output is redirected; otherwise, false.
    static bool is_out_redireted() {return out.rdbuf() != __get_out_rdbuf<char_t>();}
    
    /// @brief Gets a value indicating whether a key press is available in the input stream.
    /// @param true if a key press is available; otherwise, false
    /// @remarks The key_available method is returned immediately; that is, the key_available method does not block input until a key press is available.
    /// @remarks Use the key_available method in conjunction with only the read_key method, not the read or read_line methods
    static bool key_available() {return __opaque_console::key_available();}

    /// @brief Gets the largest possible number of console window rows, based on the current font and screen resolution.
    /// @param The height of the largest possible console window measured in rows.
    static int largest_window_height() {return __opaque_console::largest_window_height();}
    /// @brief Gets the largest possible number of console window columns, based on the current font and screen resolution.
    /// @param The width of the largest possible console window measured in colomns.
    static int largest_window_width() {return __opaque_console::largest_window_width();}
    
    /// @brief Gets a value indicating whether the NUM LOCK keyboard toggle is turned on or turned off.
    /// @param true if NUM LOCK is turned on; false if NUM LOCK is turned off.
    static bool number_lock() {return __opaque_console::number_lock();}

    /// @brief Acquires the standard error stream.
    /// @return The standard error stream.
    /// @remarks This method can be used to reacquire the standard error stream after it has been changed by the set_error method.
    static std::basic_ostream<char_t> open_standard_error() {return std::basic_ostream<char_t>(__get_err_rdbuf<char_t>());}
    /// @brief Acquires the standard input stream.
    /// @return The standard input stream.
    /// @remarks This method can be used to reacquire the standard input stream after it has been changed by the set_int method.
    static std::basic_istream<char_t> open_standard_input() {return std::basic_istream<char_t>(__get_in_rdbuf<char_t>());}
    /// @brief Acquires the standard output stream.
    /// @return The standard output stream.
    /// @remarks This method can be used to reacquire the standard output stream after it has been changed by the set_output method.
    static std::basic_ostream<char_t> open_standard_output() {return std::basic_ostream<char_t>(__get_out_rdbuf<char_t>());}
    
    /// @brief Gets the code page the console uses to write output.
    /// @return The code page used to write console output.
    static int output_code_page() {return __opaque_console::output_code_page();}
    /// @brief Sets the code page the console uses to write output.
    /// @param code_page The code page used to write console output.
    /// @return true if the code page changed; otherwise false.
    static bool output_code_page(int code_page) {return __opaque_console::output_code_page(code_page);}
    
    /// @brief Reads the next line of characters from the standard input stream.
    /// @return The next line of characters from the input stream, or "" if no more lines are available.
    static std::basic_string<char_t> read_line() {
      std::basic_string<char_t> result;
      in >> result;
      return result;
    }
    /// @brief Obtains the next character or function key pressed by the user. The pressed key is displayed in the console window.
    /// @return ConsoleKeyInfo A ConsoleKeyInfo object that describes the ConsoleKey constant and Unicode character, if any, that correspond to the pressed console key.
    /// The ConsoleKeyInfo object also describes, in a bitwise combination of ConsoleModifiers values, whether one or more SHIFT, ALT, or CTRL modifier keys was pressed simultaneously with the console key.
    static console_key_info read_key() {return read_key(false);}
    /// @brief Obtains the next character or function key pressed by the user. The pressed key is optionally displayed in the console window.
    /// @param intercept Determines whether to display the pressed key in the console window. true to not display the pressed key; otherwise, false
    /// @return ConsoleKeyInfo A ConsoleKeyInfo object that describes the ConsoleKey constant and Unicode character, if any, that correspond to the pressed console key.
    /// The ConsoleKeyInfo object also describes, in a bitwise combination of ConsoleModifiers values, whether one or more SHIFT, ALT, or CTRL modifier keys was pressed simultaneously with the console key.
    static console_key_info read_key(bool intercept) {
      int key_char = 0;
      int key_code = 0;
      bool alt = false;
      bool shift = false;
      bool ctrl = false;
      
      out.flush();
      __opaque_console::read_key(key_char, key_code, alt, shift, ctrl);
      console_key_info key_info = console_key_info(key_char, static_cast<console_key>(key_code), shift, alt, ctrl);
      
      if (intercept == false)
        write(char_t(key_info.key_char()));
      return key_info;
    }

    /// @brief Sets the foreground and background console colors to their defaults.
    /// @remarks The foreground and background colors are restored to the colors that existed when the current process began. For more information, see the foreground_color and background_color properties.
    static bool reset_color() {return __opaque_console::reset_color();}
    
    /// @brief Sets the position of the cursor.
    /// @param left The column position of the cursor. Columns are numbered from left to right starting at 0.
    /// @param top The row position of the cursor. Rows are numbered from top to bottom starting at 0.
    /// @remarks Use the set_cursor_position method to specify where the next write operation in the console window is to begin. If the specified cursor position is outside the area that is currently visible in the console window, the window origin changes automatically to make the cursor visible.
    /// @remarks The cursor automatically moves to the next character position each time a character is written to the console window. If the cursor is at the bottom right character position of the console window, the next write operation causes the console window to scroll so the cursor remains visible. If you want to write a character to the bottom right character position without causing the console window to scroll, use the move_buffer_area method to move a character to that position.
    static void set_cursor_position(int left, int top) {__opaque_console::set_cursor_position(left, top);}
    
    /// @brief Sets the error property to the specified std::ostream object.
    /// @param os A stream that is the new standard error output.
    /// @remarks By default, the error property is set to the standard error output stream.
    /// @remarks A std::ostream that encapsulates a std::ofstream can be used to send error messages to a file.
    static void set_error(const std::basic_ostream<char_t>& os) {error.rdbuf(os.rdbuf());}
    /// @brief Sets the int property to the specified std::istream object.
    /// @param os A stream that is the new standard input.
    /// @remarks By default, the in property is set to the standard input stream.
    /// @remarks A std::istream that encapsulates a std::ifstream can be used to receivr input from a file.
    static void set_in(const std::basic_istream<char_t>& is)  {in.rdbuf(is.rdbuf());}
    /// @brief Sets the out property to the specified std::ostream object.
    /// @param os A stream that is the new standard output.
    /// @remarks By default, the out property is set to the standard output stream.
    /// @remarks A std::ostream that encapsulates a std::ofstream can be used to send output to a file.
    static void set_out(const std::basic_ostream<char_t>& os)  {out.rdbuf(os.rdbuf());}
    
    /// @brief Gets the title to display in the console title bar.
    /// @return The string to be displayed in the title bar of the console. The maximum length of the title string is 24500 characters.
    static std::string title() {return __opaque_console::title();}
    /// @brief Sets the title to display in the console title bar.
    /// @param title The string to be displayed in the title bar of the console. The maximum length of the title string is 24500 characters.
    static void title(const std::string& title) {__opaque_console::title(title);}

    /// @brief Gets a value indicating whether the combination of the Control modifier key and C console key (Ctrl+C) is treated as ordinary input or as an interruption that is handled by the operating system.
    /// @return true if Ctrl+C is treated as ordinary input; otherwise, false.
    /// @remarks If the value of the treat_control_c_as_input property is false and Ctrl+C is pressed, the pressed keys are not stored in the input buffer and the operating system terminates the currently executing process. This is the default value.
    /// @warning Use this property judiciously because setting it to true has such a dramatic effect. Most users expect Ctrl+C to terminate a console application. If you disable the effect of Ctrl+C, the user must remember to use Ctrl+Break to terminate the application, which is a less familiar key combination.
    static bool treat_control_c_as_input() {return __opaque_console::treat_control_c_as_input();}
    /// @brief Sets a value indicating whether the combination of the Control modifier key and C console key (Ctrl+C) is treated as ordinary input or as an interruption that is handled by the operating system.
    /// @param treat_control_c_as_input true if Ctrl+C is treated as ordinary input; otherwise, false.
    /// @remarks If the value of the treat_control_c_as_input property is false and Ctrl+C is pressed, the pressed keys are not stored in the input buffer and the operating system terminates the currently executing process. This is the default value.
    /// @warning Use this property judiciously because setting it to true has such a dramatic effect. Most users expect Ctrl+C to terminate a console application. If you disable the effect of Ctrl+C, the user must remember to use Ctrl+Break to terminate the application, which is a less familiar key combination.
    static void treat_control_c_as_input(bool treat_control_c_as_input) {return __opaque_console::treat_control_c_as_input(treat_control_c_as_input);}

    /// @brief Gets the height of the console window area.
    /// @return The height of the console window measured in rows.
    static int window_height() {return __opaque_console::window_height();}
    /// @brief Sets the height of the console window area.
    /// @param height The height of the console window measured in rows.
    static void window_height(int height) {__opaque_console::window_height(height);}

    /// @brief Gets the left of the console window area.
    /// @return The left of the console window measured in columns.
    static int window_left() {return __opaque_console::window_left();}
    /// @brief Sets the left of the console window area.
    /// @param left The left of the console window measured in columns.
    static void window_left(int left) {__opaque_console::window_left(left);}

    /// @brief Gets the top of the console window area.
    /// @return The top of the console window measured in rows.
    static int window_top() {return __opaque_console::window_top();}
    /// @brief Sets the top of the console window area.
    /// @param top The top of the console window measured in rows.
    static void window_top(int top) {__opaque_console::window_top(top);}

    /// @brief Gets the width of the console window area.
    /// @return The width of the console window measured in columns.
    static int window_width() {return __opaque_console::window_width();}
    /// @brief Sets the width of the console window area.
    /// @param width The width of the console window measured in columns.
    static void window_width(int width) {__opaque_console::window_width(width);}

    /// @brief Writes the text representation of the specified value to the standard output stream.
    /// @tparam arg_t The type of the value to write.
    /// @param value The value to write,
    template<typename arg_t>
    static void write(arg_t&& value) {out << strings::format(std::basic_string<char_t> {'{', '}'},  value);}
    
    /// @cond
    template<typename type_t>
    static void write(std::initializer_list<type_t>&& il) {out << strings::format(std::basic_string<char_t> {'{', '}'}, il);}
    /// @endcond
    
    /// @brief Writes the text representation of the specified listt of values to the standard output stream using the specified format information.
    /// @tparam ...args_t Types of the values to write.
    /// @param values Values to write,
    template<typename ... args_t>
    static void write(const std::basic_string<char_t>& fmt, args_t&& ... values) {out << strings::format(fmt, std::forward<args_t>(values)...);}

    /// @brief Writes the current line terminator to the standard output stream using the specified format information.
    static void write_line() {out << std::endl << std::flush;}
    
    /// @brief Writes the text representation of the specified value, followed by the current line terminator, to the standard output stream.
    /// @tparam arg_t The type of the value to write.
    /// @param value The value to write,
    template<typename arg_t>
    static void write_line(arg_t&& value) {out << strings::format(std::basic_string<char_t> {'{', '}'}, value) << std::endl << std::flush;}

    /// @cond
    template<typename type_t>
    static void write_line(const std::initializer_list<type_t>& il) {out << strings::format(std::basic_string<char_t> {'{', '}'}, il) << std::endl << std::flush;}
    /// @endcond

    /// @brief Writes the text representation of the specified listt of values, followed by the current line terminator, to the standard output stream using the specified format information.
    /// @tparam ...args_t Types of the values to write.
    /// @param values Values to write,
    template<typename ... args_t>
    static void write_line(const std::basic_string<char_t>& fmt, args_t&& ... values) {out << strings::format(fmt, std::forward<args_t>(values)...) << std::endl << std::flush;}
    
    /// @cond
    static void __internal_cancel_key_press__(xtd::console_cancel_event_args& e) {cancel_key_press(e);}
    /// @endcond
  };
  
  /// @cond
  template<class char_t>
  std::basic_ostream<char_t> basic_console<char_t>::error {__get_err_rdbuf<char_t>()};
  template<class char_t>
  std::basic_istream<char_t> basic_console<char_t>::in {__get_in_rdbuf<char_t>()};
  template<class char_t>
  std::basic_ostream<char_t> basic_console<char_t>::out {__get_out_rdbuf<char_t>()};
  template<class char_t>
  event<basic_console<char_t>, xtd::console_cancel_event_handler> basic_console<char_t>::cancel_key_press;
  /// @endcond
}
