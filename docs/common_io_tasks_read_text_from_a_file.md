| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# How to: Read Text from a File

The following example shows how to read text from a text file using xtd for desktop apps. In example, when you create the instance of the [xtd::io::stream_reader](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1stream__reader.html) class, you provide the relative or absolute path to the file.

## Example: Read in a console app

The following example shows a read operation within a console app. This example opens the text file using a stream reader, copies the contents to a string, and outputs the string to the console.

### Important

The example assume that a file named test_file.txt already exists in the same folder as the app.

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    try {
      // Open the text file using a stream reader.
      block_scope_(stream_reader sr("test_file.txt")) {
        // Read the stream as a string, and write the string to the console.
        console::write_line(sr.read_to_end());
      }
    } catch (const io_exception& e) {
      console::write_line("The file could not be read:");
      console::write_line(e.message());
    }
  }
};

startup_(program::main);
```
 
## See also

* [Common I/O Tasks](common_io_tasks.md)
* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2025 Gammasoft.

