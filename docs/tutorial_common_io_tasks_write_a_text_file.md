| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# How to: Write a Text File

The following code example demonstrates how to create a text file and write text to it using the xtd::io::stream_writer class, which is defined in the xtd.io namespace. The xtd::io::stream_writer constructor takes the name of the file to be created. If the file exists, it is overwritten (unless you pass *true* as the second xtd::io::stream_writer constructor argument).
The file is then filed using the Write and WriteLine functions.
 
```c++
#include <chrono>
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static void main() {
    ustring file_name = "textfile.txt";
    
    stream_writer sw(file_name);
    sw.write_line("A text file is born!");
    sw.write("You can use write_line");
    sw.write_line("...or just write");
    sw.write_line("and do {0} output too.", "formatted");
    sw.write_line("You can also send non-text objects:");
    sw.write_line(std::chrono::system_clock::now());
    sw.close();
    console::write_line("a new file ('{0}') has been written", file_name);
  }
};

startup_(program);
```
 
## See also

* [Common I/O Tasks](tutorial_common_io_tasks.md)
* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.

