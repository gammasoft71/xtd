#include "../include/console.hpp"

using namespace gammasoft;
using namespace std;

istream& console::in = cin;
ostream& console::err = cerr;
ostream& console::out = cout;

void console::beep() noexcept {
  beep(800, 200);
}

bool console::cursor_left(int left) noexcept {
  return set_cursor_position(left, cursor_top());
}

bool console::cursor_top(int top) noexcept {
  return set_cursor_position(cursor_left(), top);
}

std::string console::read_line() noexcept {
  string result;
  in >> result;
  return result;
}

void console::write_line() noexcept {
  out << std::endl;
}

