#include <xtd/xtd>

class program {
public:
  static auto main() {
    auto path = "MyTest.txt";
    auto fi = file_info {path};
    
    //Create the file.
    block_scope_(auto fs = fi.create()) {
      auto sw = stream_writer {fs};
      sw.write_line("This is some text in the file.");
    }
    
    //Open the stream and read it back.
    block_scope_(auto fs = fi.open_read()) {
      auto sr = stream_reader {fs};
      while (!sr.end_of_stream())
        console::write_line(sr.read_line());
    }
  }
};

startup_(program::main);

// This code produces the following output :
// results may vary based on the computer/file structure/etc.:
//
// This is some text in the file.
