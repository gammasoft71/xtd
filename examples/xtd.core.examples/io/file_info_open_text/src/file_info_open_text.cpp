#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto path = path::combine(path::get_temp_path(), "MyTest.txt");
    auto fi = file_info {path};
    
    if (!fi.exists()) {
      //Create a file to write to.
      block_scope_(auto sw = fi.create_text()) {
        sw.write_line("Hello");
        sw.write_line("And");
        sw.write_line("Welcome");
      }
    }
    
    //Open the file to read from.
    block_scope_(auto sr = fi.open_text()) {
      while (!sr.end_of_stream())
        console::write_line(sr.read_line());
    }
  }
};

startup_(program::main);

// This code produces output similar to the following;
// results may vary based on the computer/file structure/etc.:
//
// Hello
// And
// Welcome
