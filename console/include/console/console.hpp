/// @file
/// @brief Contains xtd::console class.
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
  /// @include Console.cpp
  /// @include ConsoleOut.cpp
  template<class Char>
  class basic_console final {
  public:
    /// @brief Gets the standard input stream.
    /// @param A std::basic_istream<Char> that represents the standard input stream.
    /// @par Example
    /// The following sample illustrates the use of the in property.
    /// @include console_in_out.cpp
    static std::basic_istream<Char> in;
    
    /// @brief Gets the error output stream.
    /// @param A std::basic_ostream<Char> that represents the error output stream.
    static std::basic_ostream<Char> error;
    
    /// @brief Gets the standard output stream.
    /// @param A std::basic_ostream<Char> that represents the standard output stream.
    /// @par Example
    /// The following sample illustrates the use of the out property.
    /// @include console_in_out.cpp
    static std::basic_ostream<Char> out;
    
    /// @cond
    basic_console() = delete;
    /// @endcond
    
    /// @brief Gets the background color of the console.
    /// @return the background console_color.
    /// @include
    /// A get operation for a Windows-based application, in which a console does not exist, returns console_color.Black.
    /// @par Example
    /// The following example saves the values of the console_color enumeration to an array and stores the current values of the background_color and foreground_color properties to variables. It then changes the foreground color to each color in the console_color enumeration except to the color that matches the current background, and it changes the background color to each color in the console_color enumeration except to the color that matches the current foreground. (If the foreground color is the same as the background color, the text isn't visible.) Finally, it calls the reset_color method to restore the original console colors.
    /// @include console_color4.cpp
    static console_color background_color() noexcept {return  __opaque_console::background_color();}
    
    /// @brief Sets the background color of the console.
    /// @param A ConsoleColor that specifies the background color of the console; that is, the color that appears behind each character.
    /// @return false if the color specified in a set operation is not a valid member of console_color or I/O error occurred; otherise true.
    /// @remarks A change to the background_color method affects only output that is written to individual character cells after the background color is changed. To change the background color of the console window as a whole, set the BackgroundColor property and call the Clear method. The following example provides an illustration.
    /// @include
    /// A get operation for a Windows-based application, in which a console does not exist, returns console_color.Black.
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
    /// @param The current height, in rows, of the buffer area.
    /// @return true if buffer heigh changed; otherwise false.
    /// @par Example
    /// This example demonstrates the buffer_height and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static bool buffer_height(int height) noexcept {return __opaque_console::buffer_height(height);}
    
    /// @brief Gets the width of the buffer area.
    /// @param The current width, in columns, of the buffer area.
    /// @par Example
    /// This example demonstrates the BufferHeight and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static int buffer_width() noexcept {return __opaque_console::buffer_width();}
    
    /// @brief Sets the width of the buffer area.
    /// @param The current width, in columns, of the buffer area.
    /// @par Example
    /// This example demonstrates the BufferHeight and buffer_width properties. The example reports the dimensions of an operating system window set to a buffer size of 300 rows and 85 columns.
    /// @include console_buffer.cpp
    static bool buffer_width(int width) noexcept {return __opaque_console::buffer_width(width);}
    
    static bool caps_lock() noexcept {return __opaque_console::caps_lock();}
    
    static bool clrscr() noexcept {return __opaque_console::clrscr();}
    
    static int cursor_left() noexcept {return __opaque_console::cursor_left();}
    
    static bool cursor_left(int left) noexcept {return set_cursor_position(left, cursor_top());}
    
    static int cursor_size() noexcept {return __opaque_console::cursor_size();}
    
    static void cursor_size(int size) noexcept {__opaque_console::cursor_size(size);}
    
    static int cursor_top() noexcept {return __opaque_console::cursor_top();}
    
    static bool cursor_top(int top) noexcept {return set_cursor_position(cursor_left(), top);}
    
    static bool cursor_visible() noexcept {return __opaque_console::cursor_visible();}
    
    static void cursor_visible(bool visible) noexcept {__opaque_console::cursor_visible(visible);}
    
    static console_color foreground_color() noexcept {return __opaque_console::foreground_color();}
    
    static bool foreground_color(console_color color) noexcept {return __opaque_console::foreground_color(color);}
    
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
    
    static void write_line() noexcept {out << std::endl;}
    
    template<typename Arg>
    static void write_line(Arg&& arg) noexcept {out << arg << std::endl;}
    
    template<typename ... Args>
    static void write(const std::basic_string<Char>& fmt, Args&& ... args) noexcept {out << format(fmt, args...);}
    
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
