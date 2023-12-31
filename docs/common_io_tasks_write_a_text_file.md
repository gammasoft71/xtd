| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# How to: Write a Text File

The following code example demonstrates how to create a text file and write text to it using the xtd::io::stream_writer class, which is defined in the [xtd::io](https://gammasoft71.github.io/xtd/reference_guides/latest/namespacextd_1_1io.html) namespace. The [xtd::io::stream_writer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1stream__writer.html) constructor takes the name of the file to be created. If the file exists, it is overwritten (unless you pass *true* as the second [xtd::io::stream_writer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1stream__writer.html) constructor argument).
The file is then filed using the [xtd::io::stream_writer::write](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1text__writer.html#a8d13fc012efd84779130b80a0d6ddb1c) and [xtd::io::stream_writer::write_line](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1text__writer.html#a4c3a56d538a98adb83dc4b9f32aeacd8) functions.
 
```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    ustring file_name = "textfile.txt";
    
    stream_writer sw(file_name);
    sw.write_line("A text file is born!");
    sw.write("You can use write_line");
    sw.write_line("...or just write");
    sw.write_line("and do {0} output too.", "formatted");
    sw.write_line("You can also send non-text objects:");
    sw.write_line(date_time::now());
    sw.close();
    console::write_line("a new file ('{0}') has been written", file_name);
  }
};

startup_(program);
```
 
## See also

* [Common I/O Tasks](common_io_tasks.md)
* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.

