#include <xtd/io/file_info>
#include <xtd/io/stream_reader>
#include <xtd/io/stream_writer>
#include <xtd/block_scope>
#include <xtd/console>
#include <xtd/startup>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    auto path = "MyTest.txt";
    auto fi = file_info {path};
    
    // Delete the file if it exists.
    if (fi.exists())
      fi.remove();
      
    //Create the file.
    block_scope_(auto fs = fi.create()) {
      auto sw = stream_writer {fs};
      sw.write_line("This is some text in the file.");
    }
    
    //Open the stream and read it back.
    block_scope_(auto fs = fi.open(std::ios::in)) {
      auto sr = stream_reader {fs};
      while (!sr.end_of_stream())
        console::write_line(sr.read_line());
    }
  }
};

startup_(program::main);

// This code produces the following output :
//
// This is some text in the file.
