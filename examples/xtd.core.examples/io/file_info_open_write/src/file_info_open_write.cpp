#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    ustring path = "MyTest.txt";
    file_info fi(path);
    
    // Delete the file if it exists.
    if (fi.exists())
      fi.remove();
      
    // Open the stream for writing.
    using_(ofstream fs = fi.open_write()) {
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
//
// This is some text in the file.
