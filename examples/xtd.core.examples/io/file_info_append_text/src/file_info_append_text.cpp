#include <xtd/io/file_info>
#include <xtd/io/path>
#include <xtd/block_scope>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    auto fi = file_info {path::combine(path::get_temp_path(), "MyTest.txt")};
    
    // This text is added only once to the file.
    if (!fi.exists())  {
      //Create a file to write to.
      block_scope_(auto sw = fi.create_text()) {
        sw.write_line("Hello");
        sw.write_line("And");
        sw.write_line("Welcome");
      }
    }
    
    // This text will always be added, making the file longer over time
    // if it is not deleted.
    block_scope_(auto sw = fi.append_text()) {
      sw.write_line("This");
      sw.write_line("is Extra");
      sw.write_line("Text");
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
// This
// is Extra
// Text

//When you run this application a second time, you will see the following output :
//
// Hello
// And
// Welcome
// This
// is Extra
// Text
// This
// is Extra
// Text
