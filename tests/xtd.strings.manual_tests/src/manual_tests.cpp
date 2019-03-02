#include <xtd/strings>

#include <iostream>
#include <vector>

using namespace std;
using namespace string_literals;
using namespace xtd;

inline std::string const& to_string(std::string const& s) { return s; }

// The main entry point for the application.
int main() {
  cout << strings::format("%s, %s!", "Hello", "World"s) << endl;
  std::string s = "Hello, World!";
  cout << strings::starts_width(s, "HELLO", true) << endl;
  int i = 2;
  cout << strings::concat<char>("item1 ", i, " ", 3.5) << endl;
  cout << strings::contains("Hello, Wolrd !", "Helli") << endl;
  cout << strings::join(", ", {"black", "yellow", "red"}, 0, 22) << endl;
  cout << strings::pad_left("padded", 10) << endl;
  cout << strings::pad_right("padded", 10, '+') << endl;
  cout << strings::replace("abc defabc def", "abc", "1234") << endl;
  cout << strings::replace("abc defabc def", 'e', 'z') << endl;
}

// This code produces the following output with colors:
//
// Hello, World!
