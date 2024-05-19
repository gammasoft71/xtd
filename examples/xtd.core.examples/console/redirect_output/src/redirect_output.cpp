#include <xtd/io/path>
#include <xtd/io/file>
#include <xtd/console>
#include <xtd/environment>

using namespace xtd;
using namespace xtd::io;

auto main() -> int {
  auto output_file_path = path::combine(path::get_temp_path(), "xtd_example_write.txt");
  
  auto output_stream = file::open_write(output_file_path);
  console::set_out(output_stream);
  
  console::write_line("Item1");
  console::write_line("Item2");
  console::write_line("Item3");
  
  output_stream.close();
  console::set_out(console::open_standard_output());
  
  console::write_line(ustring::join(environment::new_line(), file::read_all_lines(output_file_path)));
  
  file::remove(output_file_path);
}

// This code can produce the following output:
//
// Item1
// Item2
// Item3
