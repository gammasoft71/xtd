#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

int main() {
  directory_info di(".");
  console::write_line("full_name = {}", di.full_name());
  console::write_line("  attributes = {}", di.attributes());
  console::write_line("  creation_time = {}", di.creation_time());
  console::write_line("  exists = {}", di.exists());
  console::write_line("  extension = {}", di.extension());
  console::write_line("  last_access_time = {}", di.last_access_time());
  console::write_line("  last_write_time = {}", di.last_write_time());
  console::write_line("  name = {}", di.name());
  console::write_line("  to_string = {}", di.to_string());
}

// This code produces the following output :
//
// full_name = /|---OMITTED---|/xtd.examples/xtd.core.examples/io/directory_info/Debug
//   attributes = directory
//   creation_time = Fri Oct 22 19:21:52 2021
//   exists = true
//   extension =
//   last_access_time = Fri Oct 22 19:22:14 2021
//   last_write_time = Fri Oct 22 19:22:14 2021
//   name = Debug
//   to_string = .
