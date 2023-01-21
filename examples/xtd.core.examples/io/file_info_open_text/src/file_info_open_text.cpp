#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    ustring path = xtd::io::path::combine(xtd::io::path::get_temp_path(), "MyTest.txt");
    file_info fi(path);
    
    if (!fi.exists()) {
      //Create a file to write to.
      using_(stream_writer sw = fi.create_text()) {
        sw.write_line("Hello");
        sw.write_line("And");
        sw.write_line("Welcome");
      }
    }
    
    //Open the file to read from.
    using_(stream_reader sr = fi.open_text()) {
      while (!sr.end_of_stream())
        console::write_line(sr.read_line());
    }
  }
};

startup_(program);

// This code produces output similar to the following;
// results may vary based on the computer/file structure/etc.:
//
// Hello
// And
// Welcome
