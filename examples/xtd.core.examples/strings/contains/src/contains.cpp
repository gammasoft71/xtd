#include <xtd/xtd.core>
#include <iostream>

using namespace std;
using namespace string_literals;
using namespace xtd;

int main() {
  auto s = "This is a literal string";
  cout << "The string: \"" << s << "\"" << (strings::contains(s, "is") ? " contains " : " does not contain ") << "\"is\" substring." << endl;
  cout << "The string: \"" << s << "\"" << (strings::contains(s, "z") ? " contains " : " does not contain ") << "\"z\" character." << endl;
}

// This code produces the following output:
//
// The string: "This is a literal string" contains "is" substring.
// The string: "This is a literal string" does not contain "z" character.
