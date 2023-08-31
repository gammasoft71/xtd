#include <xtd/io/file_info>
#include <xtd/io/path>
#include <xtd/console>
#include <xtd/startup>
#include <xtd/using>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    auto path = path::combine(path::get_temp_path(), "MyTest.txt");
    auto fi = file_info {path};
    
    if (!fi.exists()) {
      //Create a file to write to.
      using_(auto sw = fi.create_text()) {
        sw.write_line("Hello");
        sw.write_line("And");
        sw.write_line("Welcome");
      }
    }
    
    //Open the file to read from.
    using_(auto sr = fi.open_text()) {
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
