#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    ustring path = "MyTest.txt";
    file_info fi(path);
    
    //Create the file.
    using_(ofstream fs = fi.create()) {
      stream_writer sw(fs);
      sw.write_line("This is some text in the file.");
    }
    
    //Open the stream and read it back.
    using_(ifstream fs = fi.open_read()) {
      stream_reader sr(fs);
      while (!sr.end_of_stream())
        console::write_line(sr.read_line());
    }
  }
};

startup_(program);

// This code produces the following output :
// results may vary based on the computer/file structure/etc.:
//
// This is some text in the file.
