#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

int main(int argc, char* argv[]) {
  ustring file_name = path::combine(path::get_temp_path(), "file.txt");
  
  file::write_all_text(file_name, "Hello, World!");
  console::write_line(file::read_all_text(file_name));
  
  file::remove(file_name);
}

// This code produces the following output:
//
// Hello, World!
