| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# How to: Read and Write to a Newly Created Data File

The [xtd::io::binary_writer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__writer.html) and [xtd::io::binary_reader](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__reader.html) classes are used for writing and reading data other than character strings. 
The following example shows how to create an empty file stream, write data to it, and read data from it.

The example creates a data file called *test.data* in the current directory, creates the associated [binary_writer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__writer.html) and [binary_reader](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__reader.html) objects, and uses the [binary_writer](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__writer.html) object to write the integers 0 through 10 to *test.data*, which leaves the file pointer at the end of the file. 
The [binary_reader](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1binary__reader.html) object then sets the file pointer back to the origin and reads out the specified content.

## Example

```cpp
#include <fstream>
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
private:
  inline static const ustring FILE_NAME = "test.data";
  
public:
  static auto main() {
    if (file::exists(FILE_NAME)) {
      console::write_line("{} already exists!", FILE_NAME);
      return;
    }
    
    using_ (ofstream fs(FILE_NAME, ios::binary | ios::out)) {
      using_ (binary_writer w(fs)) {
        for (int i = 0; i < 11; i++) {
          w.write(i);
        }
      }
    }
    
    using_ (ifstream fs(FILE_NAME, ios::binary | ios::in)) {
      using_ (binary_reader r(fs)) {
        for (int i = 0; i < 11; i++) {
          console::write_line(r.read_int32());
        }
      }
    }
  }
};

startup_(program);

// The example creates a file named "Test.data" and writes the integers 0 through 10 to it in binary format.
// It then writes the contents of Test.data to the console with each integer on a separate line.
```
 
## See also

* [Common I/O Tasks](common_io_tasks.md)
* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2024 Gammasoft.

<!---
https://docs.microsoft.com/en-us/dotnet/standard/io/how-to-read-and-write-to-a-newly-created-data-file
--->
