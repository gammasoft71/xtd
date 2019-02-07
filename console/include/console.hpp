/// @file
/// @brief Contains console class.
#pragma once
#include "console_color.hpp"
#include "console_key_info.hpp"
#include "console_special_key.hpp"

#include <iostream>
#include <map>
#include <string>

/// @cond
extern std::streambuf* __cerr_rdbuf;
extern std::streambuf* __cin_rdbuf;
extern std::streambuf* __cout_rdbuf;
/// @endcond

/// @brief The gammasoft namespace contains all fundamental classes to access console.
namespace gammasoft {
  /// @brief Represents the standard input, output, and error streams for console applications.
  /// @remarks This class cannot be inherited.
  /// @par Examples
  /// The following example demonstrates how to read data from, and write data to, the standard input and output streams. Note that these streams can be redirected by using the SetIn and SetOut methods.
  /// @include Console.cpp
  /// @include ConsoleOut.cpp
  //template<class Char>
  class console final {
  public:
    static std::istream in;
    
    static std::ostream error;
    
    static std::ostream out;

    /// @cond
    console() = delete;
    /// @endcond

    /// @brief Gets the background color of the console.
    /// @return the background console_color.
    /// @include
    /// A get operation for a Windows-based application, in which a console does not exist, returns ConsoleColor.Black.
    /// @par Example
    /// The following example saves the values of the ConsoleColor enumeration to an array and stores the current values of the BackgroundColor and ForegroundColor properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the ConsoleColor enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the ResetColor method to restore the original console colors.
    /// @include ConsoleColor4.cpp
    static console_color background_color() noexcept;
    
    /// @brief Sets the background color of the console.
    /// @param A ConsoleColor that specifies the background color of the console; that is, the color that appears behind each character.
    /// @return false if the color specified in a set operation is not a valid member of console_color or I/O error occurred; otherise true.
    /// @remarks A change to the background_color method affects only output that is written to individual character cells after the background color is changed. To change the background color of the console window as a whole, set the BackgroundColor property and call the Clear method. The following example provides an illustration.
    /// @include
    /// A get operation for a Windows-based application, in which a console does not exist, returns ConsoleColor.Black.
    /// @par Example
    /// The following example saves the values of the ConsoleColor enumeration to an array and stores the current values of the BackgroundColor and ForegroundColor properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the ConsoleColor enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the ResetColor method to restore the original console colors.
    /// @include ConsoleColor4.cpp
    static bool background_color(console_color color) noexcept;
    
    static void beep() noexcept;
    
    static bool beep(unsigned int frequency, unsigned int duration) noexcept;
    
    static int buffer_height() noexcept;

    static int buffer_width() noexcept;
    
    static bool caps_lock() noexcept;
    
    static bool clrscr() noexcept;

    static int cursor_left() noexcept;

    static bool cursor_left(int left) noexcept;

    static int cursor_size() noexcept;
    
    static void cursor_size(int size) noexcept;
    
    static int cursor_top() noexcept;
    
    static bool cursor_top(int top) noexcept;
    
    static bool cursor_visible() noexcept;
    
    static void cursor_visible(bool visible) noexcept;
    
    static console_color foreground_color() noexcept;
    
    static bool foreground_color(console_color color) noexcept;
    
    template<typename ... Args>
    static std::string format(const std::string& format, Args&& ... args) noexcept {
      std::string formated_string(snprintf(nullptr, 0, format.c_str(), std::forward<Args>(args) ...), 0);
      snprintf(&formated_string[0], formated_string.size() + 1, format.c_str(), std::forward<Args>(args) ...);
      return formated_string;
    }

    static int input_code_page() noexcept;

    static bool input_code_page(int codePage) noexcept;
    
    static bool is_error_redireted() noexcept;
    
    static bool is_in_redireted() noexcept;
    
    static bool is_out_redireted() noexcept;
    
    static std::ostream open_standard_error() noexcept;
    
    static std::istream open_standard_input() noexcept;
    
    static std::ostream open_standard_output() noexcept;

    static int output_code_page() noexcept;

    static bool output_code_page(int codePage) noexcept;

    static bool reset_color() noexcept;

    static std::string read_line() noexcept;

    static bool set_cursor_position(int left, int top) noexcept;

    static void set_error(const std::ostream& error) noexcept;
    
    static void set_in(const std::istream& in) noexcept;
    
    static void set_out(const std::ostream& out) noexcept;
    
    static std::map<int, console_special_key> signal_keys() noexcept;

    static int window_height() noexcept;
    
    static int window_left() noexcept;
    
    static int window_top() noexcept;
    
    static int window_width() noexcept;
    
    template<typename Arg>
    static void write(Arg&& arg) noexcept {
      out << arg;
    }
    
    static void write_line() noexcept;

    template<typename Arg>
    static void write_line(Arg&& arg) noexcept {
      out << arg << std::endl;
    }
    
    template<typename ... Args>
    static void write(const std::string& fmt, Args&& ... args) noexcept {
      out << format(format, std::forward<Args>(args) ...);
    }
    
    template<typename ... Args>
    static void write_line(const std::string& fmt, Args&& ... args) noexcept {
      out << format(format, std::forward<Args>(args) ...) << std::endl;
    }
  };
  
  //using console = basic_console<char>;
  //using wconsole = basic_console<wchar_t>;
}

#include "background_color.hpp"
#include "beep.hpp"
#include "foreground_color.hpp"
#include "format.hpp"
#include "reset_color.hpp"
