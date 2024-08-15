#include <xtd/console>
#include <xtd/environment>
#include <xtd/system_exception>
#include <xtd/argument_out_of_range_exception>
#include <xtd/string>

using namespace xtd;

auto main() -> int {
  console::out << ustring::format("{}", std::exception()) << environment::new_line;
  console::out << ustring::format("{}", std::invalid_argument("Invalid argument")) << environment::new_line;
  console::out << ustring::format("{}", system_exception("System exception")) << environment::new_line;
  console::out << ustring::format("{}", argument_out_of_range_exception("Argument out of range exception")) << environment::new_line;
}

// This code produces the following output :
//
// exception: std::exception
// exception: Invalid argument
// xtd::system_exception : System exception
//    at main [0x00005620] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/format/format_exception/Debug/format_exception:line 0
// xtd::argument_out_of_range_exception : Argument out of range exception
//    at main [0x00005620] in /Users/gammasoft71/Projects/xtd/build/xtd.examples/xtd.core.examples/format/format_exception/Debug/format_exception:line 0
