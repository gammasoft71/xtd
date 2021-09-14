#include <any>
#include <chrono>
#include <locale>
#include <ostream>
#include <string>

#include <xtd/xtd>

using namespace std;
using namespace std::chrono;
using namespace std::literals;
using namespace xtd;
using namespace xtd::collections;

int main() {
  register_any_stringer<platform_id>([](platform_id value) {return ustring::format("{}", value);});
  register_any_stringer<seconds>([](seconds value) {return ustring::format("{}", value);});

  // Creates and initializes a new vector_list.
  vector_list vector_list = {true, 42, "This is a string"_s, platform_id::win32s, u8"Another string"_s, 4.2f, hours(2) + minutes(25) + seconds(43)};
  
  console::write_line("vector_list = {{{}}}", ustring::join(", ", vector_list));
  console::write_line();
  
  for (const any& item : vector_list) {
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
