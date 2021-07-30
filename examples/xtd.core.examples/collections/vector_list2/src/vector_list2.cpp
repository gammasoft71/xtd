#include "any_to_ostream.h"
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
  // Creates and initializes a new vector_list.
  vector_list vector_list = {true, 42, "This is a string"s, platform_id::win32s, "Another string"s, 4.2f, hours(2) + minutes(25) + seconds(43)};
  register_any_to_ostream<platform_id>([](std::ostream& os, platform_id value)->std::ostream& {return os << value;});
  register_any_to_ostream<seconds>([](std::ostream& os, seconds value)->std::ostream& {return os << value;});

  //console::write_line("vector_list = {{{}}}", ustring::join(", ", vector_list));
  //console::write_line();
  
  for (const any& item : vector_list) {
    if (is<ustring>(item)) console::write_line("{}", std::quoted(as<ustring>(item).to_upper()));
    else console::write_line("{}", item);
  }
}

// This code can produces the following output :
//
// 42
// "THIS IS A STRING"
// "ANOTHER STRING"
// 4.2
// 02:25:43
