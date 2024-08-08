#include <xtd/collections/array_list>
#include <xtd/console>
#include <xtd/platform_id>
#include <xtd/time_span>

using namespace xtd;
using namespace xtd::collections;

auto main() -> int {
  auto items = array_list {true, 42, "This is a string", platform_id::win32s, u8"Another string", 4.2f, 2_h + 25_min + 43_s};
  
  console::write_line("items = [{}]", ustring::join(", ", items));
  console::write_line("items = {}", items);
  console::write_line();
  
  for (auto item : items) {
    if (is<ustring>(item)) console::write_line("{}", as<ustring>(item).to_upper().quoted());
    else if (is<platform_id>(item)) console::write_line("{}::{}", typeof_(as<platform_id>(item)).name(), item);
    else console::write_line("{}", item);
  }
}

// This code produces the following output :
//
// items = [true, 42, This is a string, win32s, Another string, 4.2, 02:25:43]
// items = [true, 42, This is a string, win32s, Another string, 4.2, 02:25:43]
//
// true
// 42
// "THIS IS A STRING"
// platform_id::win32s
// "ANOTHER STRING"
// 4.2
// 02:25:43
