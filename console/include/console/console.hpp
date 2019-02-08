/// @file
/// @brief Contains console class.
#pragma once
#include "console_color.hpp"
#include "console_key_info.hpp"
#include "console_special_key.hpp"

#include <cstdarg>
#include <iostream>
#include <map>
#include <string>

/// @cond
template<class Char>
inline std::basic_streambuf<Char>* __get_err_rdbuf() {return nullptr;};

template<>
inline std::basic_streambuf<char>* __get_err_rdbuf<char>() {
  static std::basic_streambuf<char>* rdbuf = std::cerr.rdbuf();
  return rdbuf;
};

template<>
inline std::basic_streambuf<wchar_t>* __get_err_rdbuf<wchar_t>() {
  static std::basic_streambuf<wchar_t>* rdbuf = std::wcerr.rdbuf();
  return rdbuf;
};

template<class Char>
inline std::basic_streambuf<Char>* __get_in_rdbuf() {return nullptr;};

template<>
inline std::basic_streambuf<char>* __get_in_rdbuf<char>() {
  static std::basic_streambuf<char>* rdbuf = std::cin.rdbuf();
  return rdbuf;
};

template<>
inline std::basic_streambuf<wchar_t>* __get_in_rdbuf<wchar_t>() {
  static std::basic_streambuf<wchar_t>* rdbuf = std::wcin.rdbuf();
  return rdbuf;
};

template<class Char>
inline std::basic_streambuf<Char>* __get_out_rdbuf() {return nullptr;};

template<>
inline std::basic_streambuf<char>* __get_out_rdbuf<char>() {
  static std::basic_streambuf<char>* rdbuf = std::cout.rdbuf();
  return rdbuf;
};

template<>
inline std::basic_streambuf<wchar_t>* __get_out_rdbuf<wchar_t>() {
  static std::basic_streambuf<wchar_t>* rdbuf = std::wcout.rdbuf();
  return rdbuf;
};

template <class Char>
inline std::basic_string<Char> __format(const Char* fmt, ...) {return std::basic_string<Char>();}

template <>
inline std::basic_string<char> __format<char>(const char* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  std::basic_string<char> formated_string(vsnprintf(nullptr, 0, fmt, args), 0);
  va_end(args);
  va_start(args, fmt);
  vsnprintf(&formated_string[0], formated_string.size() + 1, fmt, args);
  va_end(args);
  return formated_string;
}

template <>
inline std::basic_string<wchar_t> __format<wchar_t>(const wchar_t* fmt, ...) {
  va_list args;
  va_start(args, fmt);
  std::basic_string<wchar_t> formated_string(vswprintf(nullptr, 0, fmt, args), 0);
  va_end(args);
  va_start(args, fmt);
  vswprintf(&formated_string[0], formated_string.size() + 1, fmt, args);
  va_end(args);
  return formated_string;
}

xtd::console_color __os_background_color() noexcept;
bool __os_background_color(xtd::console_color color) noexcept;
bool __os_beep(unsigned int frequency, unsigned int duration) noexcept;
int __os_buffer_height() noexcept;
int __os_buffer_width() noexcept;
bool __os_caps_lock() noexcept;
bool __os_clrscr() noexcept;
int __os_cursor_left() noexcept;
int __os_cursor_size() noexcept;
void __os_cursor_size(int size) noexcept;
int __os_cursor_top() noexcept;
bool __os_cursor_visible() noexcept;
void __os_cursor_visible(bool visible) noexcept;
xtd::console_color __os_foreground_color() noexcept;
bool __os_foreground_color(xtd::console_color color) noexcept;
int __os_input_code_page() noexcept;
bool __os_input_code_page(int codePage) noexcept;
int __os_output_code_page() noexcept;
bool __os_output_code_page(int codePage) noexcept;
bool __os_reset_color() noexcept;
bool __os_set_cursor_position(int left, int top) noexcept;
std::map<int, xtd::console_special_key> __os_signal_keys() noexcept;
int __os_window_left() noexcept;
int __os_window_height() noexcept;
int __os_window_top() noexcept;
int __os_window_width() noexcept;
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief Represents the standard input, output, and error streams for console applications.
  /// @remarks This class cannot be inherited.
  /// @par Examples
  /// The following example demonstrates how to read data from, and write data to, the standard input and output streams. Note that these streams can be redirected by using the SetIn and SetOut methods.
  /// @include Console.cpp
  /// @include ConsoleOut.cpp
  template<class Char>
  class basic_console final {
  public:
    static std::basic_istream<Char> in;
    
    static std::basic_ostream<Char> error;
    
    static std::basic_ostream<Char> out;
    
    /// @cond
    basic_console() = delete;
    /// @endcond
    
    /// @brief Gets the background color of the console.
    /// @return the background console_color.
    /// @include
    /// A get operation for a Windows-based application, in which a console does not exist, returns ConsoleColor.Black.
    /// @par Example
    /// The following example saves the values of the ConsoleColor enumeration to an array and stores the current values of the BackgroundColor and ForegroundColor properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the ConsoleColor enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the ResetColor method to restore the original console colors.
    /// @include ConsoleColor4.cpp
    static console_color background_color() noexcept {return __os_background_color();}
    
    /// @brief Sets the background color of the console.
    /// @param A ConsoleColor that specifies the background color of the console; that is, the color that appears behind each character.
    /// @return false if the color specified in a set operation is not a valid member of console_color or I/O error occurred; otherise true.
    /// @remarks A change to the background_color method affects only output that is written to individual character cells after the background color is changed. To change the background color of the console window as a whole, set the BackgroundColor property and call the Clear method. The following example provides an illustration.
    /// @include
    /// A get operation for a Windows-based application, in which a console does not exist, returns ConsoleColor.Black.
    /// @par Example
    /// The following example saves the values of the ConsoleColor enumeration to an array and stores the current values of the BackgroundColor and ForegroundColor properties to variables. It then changes the foreground color to each color in the ConsoleColor enumeration except to the color that matches the current background, and it changes the background color to each color in the ConsoleColor enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the ResetColor method to restore the original console colors.
    /// @include ConsoleColor4.cpp
    static bool background_color(console_color color) noexcept {return __os_background_color(color);}
    
    static void beep() noexcept {beep(800, 200);}
    
    static bool beep(unsigned int frequency, unsigned int duration) noexcept {return __os_beep(frequency, duration);}
    
    static int buffer_height() noexcept {return __os_buffer_height();}
    
    static int buffer_width() noexcept {return __os_buffer_width();}
    
    static bool caps_lock() noexcept {return __os_caps_lock();}
    
    static bool clrscr() noexcept {return __os_clrscr();}
    
    static int cursor_left() noexcept {return __os_cursor_left();}
    
    static bool cursor_left(int left) noexcept {return set_cursor_position(left, cursor_top());}
    
    static int cursor_size() noexcept {return __os_cursor_size();}
    
    static void cursor_size(int size) noexcept {__os_cursor_size(size);}
    
    static int cursor_top() noexcept {return __os_cursor_top();}
    
    static bool cursor_top(int top) noexcept {return set_cursor_position(cursor_left(), top);}
    
    static bool cursor_visible() noexcept {return __os_cursor_visible();}
    
    static void cursor_visible(bool visible) noexcept {__os_cursor_visible(visible);}
    
    static console_color foreground_color() noexcept {return __os_foreground_color();}
    
    static bool foreground_color(console_color color) noexcept {return __os_foreground_color(color);}
    
    template<typename ... Args>
    static std::basic_string<Char> format(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {return __format(fmt.c_str(), std::forward<Args>(args) ...);}
    
    static int input_code_page() noexcept {return __os_input_code_page();}
    
    static bool input_code_page(int code_page) noexcept {return __os_input_code_page(code_page);}
    
    static bool is_error_redireted() noexcept {return error.rdbuf() != __get_err_rdbuf<Char>();}
    
    static bool is_in_redireted() noexcept {return in.rdbuf() != __get_in_rdbuf<Char>();}
    
    static bool is_out_redireted() noexcept {return out.rdbuf() != __get_out_rdbuf<Char>();}
    
    static std::basic_ostream<Char> open_standard_error() noexcept {return std::basic_ostream<Char>(__get_err_rdbuf<Char>());}
    
    static std::basic_istream<Char> open_standard_input() noexcept {return std::basic_istream<Char>(__get_in_rdbuf<Char>());}
    
    static std::basic_ostream<Char> open_standard_output() noexcept {return std::basic_ostream<Char>(__get_out_rdbuf<Char>());}
    
    static int output_code_page() noexcept {return __os_output_code_page();}
    
    static bool output_code_page(int code_page) noexcept {return __os_output_code_page(code_page);}
    
    static std::basic_string<Char> read_line() noexcept {
      std::basic_string<Char> result;
      in >> result;
      return result;
    }
    
    static bool reset_color() noexcept {return __os_reset_color();}
    
    static bool set_cursor_position(int left, int top) noexcept {return __os_set_cursor_position(left, top);}
    
    static void set_error(const std::ostream& os) noexcept {error.rdbuf(os.rdbuf());}
    
    static void set_in(const std::istream& is) noexcept  {in.rdbuf(is.rdbuf());}
    
    static void set_out(const std::ostream& os) noexcept  {out.rdbuf(os.rdbuf());}
    
    static std::map<int, console_special_key> signal_keys() noexcept {return __os_signal_keys();}
    
    static int window_height() noexcept {return __os_window_height();}
    
    static int window_left() noexcept {return __os_window_left();}
    
    static int window_top() noexcept {return __os_window_top();}
    
    static int window_width() noexcept {return __os_window_width();}
    
    template<typename Arg>
    static void write(Arg&& arg) noexcept {out << arg;}
    
    static void write_line() noexcept {out << std::endl;}
    
    template<typename Arg>
    static void write_line(Arg&& arg) noexcept {out << arg << std::endl;}
    
    template<typename ... Args>
    static void write(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {out << format(fmt, std::forward<Args>(args) ...);}
    
    template<typename ... Args>
    static void write_line(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {out << format(fmt, std::forward<Args>(args) ...) << std::endl;}
  };
  
  template<class Char>
  std::basic_ostream<Char> basic_console<Char>::error {__get_err_rdbuf<Char>()};
  template<class Char>
  std::basic_istream<Char> basic_console<Char>::in {__get_in_rdbuf<Char>()};
  template<class Char>
  std::basic_ostream<Char> basic_console<Char>::out {__get_out_rdbuf<Char>()};
  
  using console = basic_console<char>;
  
  using wconsole = basic_console<wchar_t>;
}

#include "background_color.hpp"
#include "beep.hpp"
#include "foreground_color.hpp"
#include "format.hpp"
#include "reset_color.hpp"
