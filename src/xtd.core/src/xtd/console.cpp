#include "../../include/xtd/argument_out_of_range_exception.h"
#include "../../include/xtd/as.h"
#include "../../include/xtd/console.h"
#include "../../include/xtd/int16_object.h"
#include "../../include/xtd/lock.h"
#include "../../include/xtd/io/stream_reader.h"
#define __XTD_CORE_INTERNAL__
#include "../../include/xtd/internal/__generic_stream_output.h"
#undef __XTD_CORE_INTERNAL__
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/console>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstring>
#include <iostream>
#include <mutex>

using namespace std;
using namespace xtd;
using namespace xtd::io;

namespace {
  std::streambuf* __get_err_rdbuf() {
    static auto rdbuf = std::cerr.rdbuf();
    return rdbuf;
  }
  
  std::streambuf* __get_in_rdbuf() {
    static auto rdbuf = std::cin.rdbuf();
    return rdbuf;
  }
  
  std::streambuf* __get_out_rdbuf() {
    static auto rdbuf = std::cout.rdbuf();
    return rdbuf;
  }
  
  auto __auto_flush_out = true;
  auto __console_mutex__ = std::recursive_mutex {};
}

std::ostream console::error {__get_err_rdbuf()};
std::istream console::in {__get_in_rdbuf()};
std::ostream console::out {__get_out_rdbuf()};
event<console, console_cancel_event_handler> console::cancel_key_press;

bool console::auto_flush_out() {
  return __auto_flush_out;
}

void console::auto_flush_out(bool value) {
  __auto_flush_out = value;
}

console_color console::background_color() {
  register_cancel_key_press(); // Must be first...
  return as<console_color>(native::console::background_color());
}

void console::background_color(console_color color) {
  if (!enum_object<>::is_defined(color)) throw argument_exception {csf_};
  register_cancel_key_press(); // Must be first...
  native::console::background_color(as<int32>(color));
}

int32 console::buffer_height() {
  register_cancel_key_press(); // Must be first...
  return native::console::buffer_height();
}

void console::buffer_height(int32 height) {
  register_cancel_key_press(); // Must be first...
  if (height <= 0 || height >= int16_object::max_value) throw argument_out_of_range_exception {csf_};
  native::console::buffer_height(height);
}

int32 console::buffer_width() {
  register_cancel_key_press(); // Must be first...
  return native::console::buffer_width();
}

void console::buffer_width(int32 width) {
  register_cancel_key_press(); // Must be first...
  if (width <= 0 || width >= int16_object::max_value) throw argument_out_of_range_exception {csf_};
  native::console::buffer_width(width);
}

bool console::caps_lock() {
  register_cancel_key_press(); // Must be first...
  return native::console::caps_lock();
}

int32 console::cursor_left() {
  register_cancel_key_press(); // Must be first...
  return native::console::cursor_left();
}

void console::cursor_left(int32 left) {
  register_cancel_key_press(); // Must be first...
  set_cursor_position(left, cursor_top());
}

int32 console::cursor_size() {
  register_cancel_key_press(); // Must be first...
  return native::console::cursor_size();
}

void console::cursor_size(int32 size) {
  register_cancel_key_press(); // Must be first...
  if (size < 1 || size > 100) throw argument_out_of_range_exception {csf_};
  native::console::cursor_size(size);
}

int32 console::cursor_top() {
  register_cancel_key_press(); // Must be first...
  return native::console::cursor_top();
}

void console::cursor_top(int32 top) {
  register_cancel_key_press(); // Must be first...
  set_cursor_position(cursor_left(), top);
}

bool console::cursor_visible() {
  register_cancel_key_press(); // Must be first...
  return native::console::cursor_visible();
}

void console::cursor_visible(bool visible) {
  register_cancel_key_press(); // Must be first...
  native::console::cursor_visible(visible);
}

console_color console::foreground_color() {
  register_cancel_key_press(); // Must be first...
  return as<console_color>(native::console::foreground_color());
}

bool console::foreground_color(console_color color) {
  register_cancel_key_press(); // Must be first...
  if (!enum_object<>::is_defined(color)) throw argument_exception {csf_};
  return native::console::foreground_color(as<int32>(color));
}

int32 console::input_code_page() {
  register_cancel_key_press(); // Must be first...
  return native::console::input_code_page();
}

bool console::input_code_page(int32 code_page) {
  register_cancel_key_press(); // Must be first...
  return native::console::input_code_page(code_page);
}

bool console::is_error_redirected() {
  register_cancel_key_press(); // Must be first...
  return error.rdbuf() != __get_err_rdbuf();
}

bool console::is_input_redirected() {
  register_cancel_key_press(); // Must be first...
  return in.rdbuf() != __get_in_rdbuf();
}

bool console::is_output_redirected() {
  register_cancel_key_press(); // Must be first...
  return out.rdbuf() != __get_out_rdbuf();
}

bool console::key_available() {
  register_cancel_key_press(); // Must be first...
  return native::console::key_available();
}

int32 console::largest_window_height() {
  register_cancel_key_press(); // Must be first...
  return native::console::largest_window_height();
}

int32 console::largest_window_width() {
  register_cancel_key_press(); // Must be first...
  return native::console::largest_window_width();
}

bool console::number_lock() {
  register_cancel_key_press(); // Must be first...
  return native::console::number_lock();
}

int32 console::output_code_page() {
  register_cancel_key_press(); // Must be first...
  return native::console::output_code_page();
}

bool console::output_code_page(int32 code_page) {
  register_cancel_key_press(); // Must be first...
  return native::console::output_code_page(code_page);
}

ustring console::title() {
  register_cancel_key_press(); // Must be first...
  return native::console::title();
}

void console::title(const ustring& title) {
  register_cancel_key_press(); // Must be first...
  native::console::title(title);
}

bool console::treat_control_c_as_input() {
  register_cancel_key_press(); // Must be first...
  return native::console::treat_control_c_as_input();
}

void console::treat_control_c_as_input(bool treat_control_c_as_input) {
  register_cancel_key_press(); // Must be first...
  native::console::treat_control_c_as_input(treat_control_c_as_input);
}

int32 console::window_height() {
  register_cancel_key_press(); // Must be first...
  return native::console::window_height();
}

void console::window_height(int32 height) {
  register_cancel_key_press(); // Must be first...
  if (height <= 0 || height >= int16_object::max_value) throw argument_out_of_range_exception {csf_};
  native::console::window_height(height);
}

int32 console::window_left() {
  register_cancel_key_press(); // Must be first...
  return native::console::window_left();
}

void console::window_left(int32 left) {
  register_cancel_key_press(); // Must be first...
  if (left < 0 || left >= buffer_width()) throw argument_out_of_range_exception {csf_};
  native::console::window_left(left);
}

int32 console::window_top() {
  register_cancel_key_press(); // Must be first...
  return native::console::window_top();
}

void console::window_top(int32 top) {
  register_cancel_key_press(); // Must be first...
  if (top < 0 || top >= buffer_height()) throw argument_out_of_range_exception {csf_};
  native::console::window_top(top);
}

int32 console::window_width() {
  register_cancel_key_press(); // Must be first...
  return native::console::window_width();
}

void console::window_width(int32 width) {
  register_cancel_key_press(); // Must be first...
  if (width <= 0 || width >= int16_object::max_value) throw argument_out_of_range_exception {csf_};
  native::console::window_width(width);
}

void console::beep() {
  register_cancel_key_press(); // Must be first...
  beep(800, 200);
}

void console::beep(uint32 frequency, uint32 duration) {
  register_cancel_key_press(); // Must be first...
  native::console::beep(frequency, duration);
}

void console::clear() {
  register_cancel_key_press(); // Must be first...
  native::console::clear();
}

std::pair<int32, int32> console::get_cursor_position() {
  register_cancel_key_press(); // Must be first...
  return {cursor_left(), cursor_top()};
}

std::ostream console::open_standard_error() {
  register_cancel_key_press(); // Must be first...
  return std::ostream {__get_err_rdbuf()};
}

std::istream console::open_standard_input() {
  register_cancel_key_press(); // Must be first...
  return std::istream {__get_in_rdbuf()};
}

std::ostream console::open_standard_output() {
  register_cancel_key_press(); // Must be first...
  return std::ostream {__get_out_rdbuf()};
}

int32 console::read() {
  return in.get();
}

ustring console::read_line() {
  register_cancel_key_press(); // Must be first...
  out.flush();
  if (!is_input_redirected()) native::console::echo(true);
  auto result = stream_reader {in}.read_line();
  if (!is_input_redirected()) native::console::echo(false);
  return result;
}

console_key_info console::read_key() {
  register_cancel_key_press(); // Must be first...
  return read_key(false);
}

console_key_info console::read_key(bool intercept) {
  register_cancel_key_press(); // Must be first...
  out.flush();
  
  auto key_char = U'0', key_code = U'0';
  auto alt = false, shift = false, ctrl = false;
  native::console::read_key(key_char, key_code, alt, shift, ctrl);
  auto key_info = console_key_info(key_char, as<console_key>(key_code), shift, alt, ctrl);
  
  if (intercept == false)
    write(key_info.key_char());
  return key_info;
}

bool console::reset_color() {
  register_cancel_key_press(); // Must be first...
  return native::console::reset_color();
}

void console::set_cursor_position(int32 left, int32 top) {
  register_cancel_key_press(); // Must be first...
  if (left < 0 || left >= buffer_width()) throw argument_out_of_range_exception {csf_};
  if (top < 0 || top >= buffer_height()) throw argument_out_of_range_exception {csf_};
  native::console::set_cursor_position(left, top);
}

void console::set_error(const std::ostream& os) {
  register_cancel_key_press(); // Must be first...
  error.rdbuf(os.rdbuf());
}

void console::set_in(const std::istream& is) {
  register_cancel_key_press(); // Must be first...
  in.rdbuf(is.rdbuf());
}

void console::set_out(const std::ostream& os)  {
  register_cancel_key_press(); // Must be first...
  out.rdbuf(os.rdbuf());
}

void console::set_window_position(int32 left, int32 top) {
  register_cancel_key_press(); // Must be first...
  if (left < 0 || left + window_width() >= buffer_width()) throw argument_out_of_range_exception{csf_};
  if (top < 0 || top + window_height() >= buffer_height()) throw argument_out_of_range_exception{csf_};
  window_left(left);
  window_top(top);
}

void console::set_window_size(int32 width, int32 height) {
  register_cancel_key_press(); // Must be first...
  if (height <= 0 || height >= int16_object::max_value) throw argument_out_of_range_exception {csf_};
  if (width <= 0 || width >= int16_object::max_value) throw argument_out_of_range_exception {csf_};
  window_width(width);
  window_height(height);
}

void console::write_line() {
  register_cancel_key_press(); // Must be first...
  write_line_("");
}

bool console::on_cancel_key_press(int32 special_key) {
  auto e = console_cancel_event_args(as<console_special_key>(special_key));
  cancel_key_press(e);
  return e.cancel();
}

void console::register_cancel_key_press() {
  static auto initialized = false;
  if (!initialized) native::console::register_user_cancel_callback(console::on_cancel_key_press);
  initialized = true;
}

void console::write_(const ustring& value) {
  auto lock = std::lock_guard<std::recursive_mutex> {__console_mutex__};
  out << value;
  if (auto_flush_out()) out.flush();
}

void console::write_line_(const ustring& value) {
  auto lock = std::lock_guard<std::recursive_mutex> {__console_mutex__};
  out << value << std::endl;
  if (auto_flush_out()) out.flush();
}
