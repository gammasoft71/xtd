#include <cstring>
#include <iostream>
#include <mutex>
#include "../../include/xtd/console.h"
#include "../../include/xtd/io/stream_reader.h"
#define __XTD_CORE_INTERNAL__
#include "../../include/xtd/internal/__generic_stream_output.h"
#include "../../include/xtd/internal/__opaque_console.h"
#undef __XTD_CORE_INTERNAL__

using namespace std;
using namespace xtd;
using namespace xtd::io;

bool __xtd_internal_cancel_key_press__(bool cancel, int_least32_t special_key) {
  auto e = console_cancel_event_args(cancel, static_cast<console_special_key>(special_key));
  console::__internal_cancel_key_press__(e);
  return e.cancel();
}

namespace {
  std::mutex console_mutex;
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

int32 console::buffer_height() {
  return __opaque_console::buffer_height();
}

void console::buffer_height(int32 height) {
  __opaque_console::buffer_height(height);
}

int32 console::buffer_width() {
  return __opaque_console::buffer_width();
}

void console::buffer_width(int32 width) {
  __opaque_console::buffer_width(width);
}

bool console::caps_lock() {
  return __opaque_console::caps_lock();
}

int32 console::cursor_left() {
  return __opaque_console::cursor_left();
}

void console::cursor_left(int32 left) {
  set_cursor_position(left, cursor_top());
}

int32 console::cursor_size() {
  return __opaque_console::cursor_size();
}

void console::cursor_size(int32 size) {
  __opaque_console::cursor_size(size);
}

int32 console::cursor_top() {
  return __opaque_console::cursor_top();
}

void console::cursor_top(int32 top) {
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

int32 console::input_code_page() {
  return __opaque_console::input_code_page();
}

bool console::input_code_page(int32 code_page) {
  return __opaque_console::input_code_page(code_page);
}

bool console::is_error_redirected() {
  return error.rdbuf() != __get_err_rdbuf();
}

bool console::is_input_redirected() {
  return in.rdbuf() != __get_in_rdbuf();
}

bool console::is_output_redirected() {
  return out.rdbuf() != __get_out_rdbuf();
}

bool console::key_available() {
  return __opaque_console::key_available();
}

int32 console::largest_window_height() {
  return __opaque_console::largest_window_height();
}

int32 console::largest_window_width() {
  return __opaque_console::largest_window_width();
}

bool console::number_lock() {
  return __opaque_console::number_lock();
}

int32 console::output_code_page() {
  return __opaque_console::output_code_page();
}

bool console::output_code_page(int32 code_page) {
  return __opaque_console::output_code_page(code_page);
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

int32 console::window_height() {
  return __opaque_console::window_height();
}

void console::window_height(int32 height) {
  __opaque_console::window_height(height);
}

int32 console::window_left() {
  return __opaque_console::window_left();
}

void console::window_left(int32 left) {
  __opaque_console::window_left(left);
}

int32 console::window_top() {
  return __opaque_console::window_top();
}

void console::window_top(int32 top) {
  __opaque_console::window_top(top);
}

int32 console::window_width() {
  return __opaque_console::window_width();
}

void console::window_width(int32 width) {
  __opaque_console::window_width(width);
}

void console::beep() {
  beep(800, 200);
}

void console::beep(uint32 frequency, uint32 duration) {
  __opaque_console::beep(frequency, duration);
}

void console::clear() {
  __opaque_console::clear();
}

std::pair<int32, int32> console::get_cursor_position() {
  return {cursor_left(), cursor_top()};
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

ustring console::read_line() {
  out.flush();
  return stream_reader {in}.read_line();
}

console_key_info console::read_key() {
  return read_key(false);
}

console_key_info console::read_key(bool intercept) {
  out.flush();

  auto key_char = U'0', key_code = U'0';
  auto alt = false, shift = false, ctrl = false;
  __opaque_console::read_key(key_char, key_code, alt, shift, ctrl);
  auto key_info = console_key_info(key_char, static_cast<console_key>(key_code), shift, alt, ctrl);
  
  if (intercept == false)
    write(key_info.key_char());
  return key_info;
}

bool console::reset_color() {
  return __opaque_console::reset_color();
}

void console::set_cursor_position(int32 left, int32 top) {
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

void console::set_window_position(int32 left, int32 top) {
  window_left(left);
  window_top(top);
}

void console::set_window_size(int32 width, int32 height) {
  window_width(width);
  window_height(height);
}

void console::write_line() {
  write_line_("");
}

void console::__internal_cancel_key_press__(console_cancel_event_args& e) {
  cancel_key_press(e);
}

void console::write_(const ustring& value) {
  lock_guard<mutex> lock(console_mutex);
  out << value;
}

void console::write_line_(const ustring& value) {
  lock_guard<mutex> lock(console_mutex);
  out << value << std::endl;
}
