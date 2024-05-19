#include <xtd/collections/vector_list>
#include <xtd/register_any_stringer>
#include <xtd/as>
#include <xtd/console>
#include <xtd/is>
#include <xtd/platform_id>
#include <any>
#include <chrono>
#include <locale>
#include <ostream>
#include <string>

using namespace std;
using namespace std::chrono;
using namespace xtd;
using namespace xtd::collections;

auto main() -> int {
  register_any_stringer<platform_id>([](auto value) {return ustring::format("{}", value);});
  register_any_stringer<seconds>([](auto value) {return ustring::format("{}", value);});
  
  // Creates and initializes a new vector_list.
  auto list = vector_list {true, 42, "This is a string"_s, platform_id::win32s, u8"Another string"_s, 4.2f, hours(2) + minutes(25) + seconds(43)};
  
  console::write_line("vector_list = {{{}}}", ustring::join(", ", list));
  console::write_line();
  
  for (const any& item : list) {
    if (is<ustring>(item)) console::write_line("{}", std::quoted(as<ustring>(item).to_upper()));
    else console::write_line("{}", item);
  }
}

// This code can produces the following output :
//
// vector_list = {true, 42, This is a string, win32s, Another string, 4.2, 02:25:43}
//
// true
// 42
// "THIS IS A STRING"
// "ANOTHER STRING"
// 4.2
// 02:25:43
