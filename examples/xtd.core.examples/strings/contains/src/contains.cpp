#include <xtd/console>
#include <xtd/ustring>

using namespace xtd;

auto main() -> int {
  auto s = "This is a literal string";
  console::write_line("The string: \""_s + s + "\""_s + (ustring {s}.contains("is") ? " contains " : " does not contain ") + "\"is\" substring."_s);
  console::write_line("The string: \""_s + s + "\""_s + (ustring {s}.contains("z") ? " contains " : " does not contain ") + "\"z\" character."_s);
}

// This code produces the following output:
//
// The string: "This is a literal string" contains "is" substring.
// The string: "This is a literal string" does not contain "z" character.
