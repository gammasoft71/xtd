#include <xtd/console>
#include <xtd/environment>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << ustring::format("[{,10}]", 42) << environment::new_line;
  console::out << ustring::format("[{,-10}]", 42) << environment::new_line;
  console::out << ustring::format("[{:D10}]", 42) << environment::new_line;
}

// This code produces the following output :
//
// [        42]
// [42        ]
// [0000000042]
