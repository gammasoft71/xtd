#include "../include/console.hpp"

using namespace gammasoft;
using namespace std;

std::streambuf* __cerr_rdbuf {std::cerr.rdbuf()};
std::streambuf* __cin_rdbuf {std::cin.rdbuf()};
std::streambuf* __cout_rdbuf {std::cout.rdbuf()};

ostream console::error {__cerr_rdbuf};
istream console::in {__cin_rdbuf};
ostream console::out {__cout_rdbuf};

void console::beep() noexcept {
  beep(800, 200);
}

bool console::cursor_left(int left) noexcept {
  return set_cursor_position(left, cursor_top());
}

bool console::cursor_top(int top) noexcept {
  return set_cursor_position(cursor_left(), top);
}

bool console::is_error_redireted() noexcept {
  return error.rdbuf() != __cerr_rdbuf;
}

bool console::is_in_redireted() noexcept {
  return in.rdbuf() != __cin_rdbuf;
}

bool console::is_out_redireted() noexcept {
  return out.rdbuf() != __cout_rdbuf;
}

std::ostream console::open_standard_error() noexcept {
  return std::ostream(__cerr_rdbuf);
}

std::istream console::open_standard_input() noexcept {
  return std::istream(__cin_rdbuf);
}

std::ostream console::open_standard_output() noexcept {
  return std::ostream(__cout_rdbuf);
}

std::string console::read_line() noexcept {
  string result;
  in >> result;
  return result;
}

void console::set_error(const std::ostream& error) noexcept {
  console::error.rdbuf(error.rdbuf());
}

void console::set_in(const std::istream& in) noexcept {
  console::in.rdbuf(in.rdbuf());
}

void console::set_out(const std::ostream& out) noexcept {
  console::out.rdbuf(out.rdbuf());
}

void console::write_line() noexcept {
  out << std::endl;
}

