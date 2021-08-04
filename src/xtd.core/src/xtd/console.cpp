#include <cstring>
#include <iostream>
#include "../../include/xtd/console.h"
#define __XTD_CORE_INTERNAL__
#include "../../include/xtd/internal/__generic_stream_output.h"
#include "../../include/xtd/internal/__opaque_console.h"
#undef __XTD_CORE_INTERNAL__

using namespace std;
using namespace xtd;

namespace {
  std::streambuf* __get_err_rdbuf() {
    static std::streambuf* rdbuf = std::cerr.rdbuf();
    return rdbuf;
  }

  std::streambuf* __get_in_rdbuf() {
    static std::streambuf* rdbuf = std::cin.rdbuf();
    return rdbuf;
  }

  std::streambuf* __get_out_rdbuf() {
    static std::streambuf* rdbuf = std::cout.rdbuf();
    return rdbuf;
  }
}

std::ostream console::error {__get_err_rdbuf()};
std::istream console::in {__get_in_rdbuf()};
std::ostream console::out {__get_out_rdbuf()};
event<console, console_cancel_event_handler> console::cancel_key_press;

console_color console::background_color() {
  return  __opaque_console::background_color();
}

void console::background_color(console_color color) {
  __opaque_console::background_color(color);
}

void console::beep() {
  beep(800, 200);
}

void console::beep(uint32_t frequency, uint32_t duration) {
  __opaque_console::beep(frequency, duration);
}

int32_t console::buffer_height() {
  return __opaque_console::buffer_height();
}

void console::buffer_height(int32_t height) {
  __opaque_console::buffer_height(height);
}

int32_t console::buffer_width() {
  return __opaque_console::buffer_width();
}

void console::buffer_width(int32_t width) {
  __opaque_console::buffer_width(width);
}

bool console::caps_lock() {
  return __opaque_console::caps_lock();
}

void console::clear() {
  __opaque_console::clear();
}

int32_t console::cursor_left() {
  return __opaque_console::cursor_left();
}

void console::cursor_left(int32_t left) {
  set_cursor_position(left, cursor_top());
}

int32_t console::cursor_size() {
  return __opaque_console::cursor_size();
}

void console::cursor_size(int32_t size) {
  __opaque_console::cursor_size(size);
}

int32_t console::cursor_top() {
  return __opaque_console::cursor_top();
}

void console::cursor_top(int32_t top) {
  set_cursor_position(cursor_left(), top);
}

bool console::cursor_visible() {
  return __opaque_console::cursor_visible();
}

void console::cursor_visible(bool visible) {
  __opaque_console::cursor_visible(visible);
}

console_color console::foreground_color() {
  return __opaque_console::foreground_color();
}

bool console::foreground_color(console_color color) {
  return __opaque_console::foreground_color(color);
}

int32_t console::input_code_page() {
  return __opaque_console::input_code_page();
}

bool console::input_code_page(int32_t code_page) {
  return __opaque_console::input_code_page(code_page);
}

bool console::is_error_redireted() {
  return error.rdbuf() != __get_err_rdbuf();
}

bool console::is_in_redireted() {
  return in.rdbuf() != __get_in_rdbuf();
}

bool console::is_out_redireted() {
  return out.rdbuf() != __get_out_rdbuf();
}

bool console::key_available() {
  return __opaque_console::key_available();
}

int32_t console::largest_window_height() {
  return __opaque_console::largest_window_height();
}

int32_t console::largest_window_width() {
  return __opaque_console::largest_window_width();
}

bool console::number_lock() {
  return __opaque_console::number_lock();
}

std::ostream console::open_standard_error() {
  return std::ostream(__get_err_rdbuf());
}

std::istream console::open_standard_input() {
  return std::istream(__get_in_rdbuf());
}

std::ostream console::open_standard_output() {
  return std::ostream(__get_out_rdbuf());
}

int32_t console::output_code_page() {
  return __opaque_console::output_code_page();
}

bool console::output_code_page(int32_t code_page) {
  return __opaque_console::output_code_page(code_page);
}

ustring console::read_line() {
  ustring result;
  in >> result;
  return result;
}

console_key_info console::read_key() {
  return read_key(false);
}

console_key_info console::read_key(bool intercept) {
  int key_char = 0;
  int key_code = 0;
  bool alt = false;
  bool shift = false;
  bool ctrl = false;
  
  out.flush();
  __opaque_console::read_key(key_char, key_code, alt, shift, ctrl);
  console_key_info key_info = console_key_info(key_char, static_cast<console_key>(key_code), shift, alt, ctrl);
  
  if (intercept == false)
    write(key_info.key_char());
  return key_info;
}

bool console::reset_color() {
  return __opaque_console::reset_color();
}

void console::set_cursor_position(int32_t left, int32_t top) {
  __opaque_console::set_cursor_position(left, top);
}

void console::set_error(const std::ostream& os) {
  error.rdbuf(os.rdbuf());
}

void console::set_in(const std::istream& is) {
  in.rdbuf(is.rdbuf());
}

void console::set_out(const std::ostream& os)  {
  out.rdbuf(os.rdbuf());
}

ustring console::title() {
  return __opaque_console::title();
}

void console::title(const ustring& title) {
  __opaque_console::title(title);
}

bool console::treat_control_c_as_input() {
  return __opaque_console::treat_control_c_as_input();
}

void console::treat_control_c_as_input(bool treat_control_c_as_input) {
  return __opaque_console::treat_control_c_as_input(treat_control_c_as_input);
}

int32_t console::window_height() {
  return __opaque_console::window_height();
}

void console::window_height(int32_t height) {
  __opaque_console::window_height(height);
}

int32_t console::window_left() {
  return __opaque_console::window_left();
}

void console::window_left(int32_t left) {
  __opaque_console::window_left(left);
}

int32_t console::window_top() {
  return __opaque_console::window_top();
}

void console::window_top(int32_t top) {
  __opaque_console::window_top(top);
}

int32_t console::window_width() {
  return __opaque_console::window_width();
}

void console::window_width(int32 width) {
  __opaque_console::window_width(width);
}

void console::write_line() {
  out << std::endl << std::flush;
}

void console::__internal_cancel_key_press__(console_cancel_event_args& e) {
  cancel_key_press(e);
}
