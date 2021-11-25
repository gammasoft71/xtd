#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

int main() {
  auto test_file = path::combine(path::get_temp_path(), "test_file.txt");
  file::write_all_text(test_file, "Hello, World!");
  file_info fi(test_file);
  console::write_line("full_name = {}", fi.full_name());
  console::write_line("  attributes = {}", fi.attributes());
  console::write_line("  creation_time = {}", fi.creation_time());
  console::write_line("  exists = {}", fi.exists());
  console::write_line("  extension = {}", fi.extension());
  console::write_line("  last_access_time = {}", fi.last_access_time());
  console::write_line("  last_write_time = {}", fi.last_write_time());
  console::write_line("  length = {}", fi.length());
  console::write_line("  name = {}", fi.name());
  console::write_line("  to_string = {}", fi.to_string());
  file::remove(test_file);
}

// This code produces the following output :
//
// full_name = //var/folders/d5/k7mxnq214dxf3jbvvvhpbfqh0000gn/T/test_file.txt
//   attributes = normal
//   creation_time = Fri Oct 22 22:05:37 2021
//   exists = true
//   extension = .txt
//   last_access_time = Fri Oct 22 22:05:37 2021
//   last_write_time = Fri Oct 22 22:05:37 2021
//   length = 13
//   name = test_file.txt
//   to_string = /var/folders/d5/k7mxnq214dxf3jbvvvhpbfqh0000gn/T/test_file.txt
