| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# How to: Write Text to a File

This topic shows different ways to write text to a file for a xtd app.

The following classes and methods are typically used to write text to a file:

* [xtd::io::stream_writer](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1stream__writer.html) contains methods to write to a file ([write and write_line).
* [xtd::io::file](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1file.html) provides static methods to write text to a file, such as write_all_lines and write_all_text, or to append text to a file, such as append_all_jines, append_all_text, and append_text.
* [xtd::io::path](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1path.html) is for strings that have file or directory path information. It contains the combine method and, the join and try_join methods, which allow concatenation of strings to build a file or directory path.

## Notes

The following examples show only the minimum amount of code needed. A real-world app usually provides more robust error checking and exception handling.

## Example: Write text with stream_writer

The following example shows how to use the xtd::io::stream_writer class to write text to a new file one line at a time. Because the xtd::io::stream_writer object is declared and instantiated in a using statement, the destructor automatically flushes and closes the stream.

```c++
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static void main() {
    // Create a string array with the lines of text
    std::vector<ustring> lines = { "First line", "Second line", "Third line" };
    
    // Set a variable to the Documents path.
    ustring doc_path = environment::get_folder_path(environment::special_folder::my_documents);
    
    // Write the string array to a new file named "WriteLines.txt".
    using_ (stream_writer output_file(path::combine(doc_path, "write_lines.txt"))) {
      for (const ustring& line : lines)
      output_file.write_line(line);
    }
  }
};

startup_(program);

// The example creates a file named "write_lines.txt" with the following contents:
// First line
// Second line
// Third line
```
 
 ## Example: Append text with stream_writer
 
 The following example shows how to use the xtd::io::stream_writer class to append text to the text file created in the first example.
 
 ```c++
 #include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static void main() {
    // Set a variable to the Documents path.
    ustring doc_path = environment::get_folder_path(environment::special_folder::my_documents);
    
    // Append text to an existing file named "write_lines.txt".
    using_ (stream_writer output_file(path::combine(doc_path, "write_lines.txt"), true)) {
      output_file.write_line("Fourth Line");
    }
  }
};

startup_(program);

// The example adds the following line to the contents of "write_lines.txt":
// Fourth Line
 ```

## Example: Write and append text with the file class

The following example shows how to write text to a new file and append new lines of text to the same file using the xtd::io::file class. The xtd::io::file::write_all_text and xtd::io::file::append_all_lines methods open and close the file automatically. If the path you provide to the xtd::io::file::write_all_text method already exists, the file is overwritten.

```c+++
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::io;

class program {
public:
  static void main() {
    // Create a string with a line of text.
    ustring text = "First line" + environment::new_line();
    
    // Set a variable to the Documents path.
    ustring doc_path = environment::get_folder_path(environment::special_folder::my_documents);
    
    // Write the text to a new file named "write_file.txt".
    file::write_all_text(path::combine(doc_path, "write_file.txt"), text);
    
    // Create a string array with the additional lines of text
    std::vector<ustring> lines = { "New line 1", "New line 2" };
    
    // Append new lines of text to the file
    file::append_all_lines(path::combine(doc_path, "write_file.txt"), lines);
  }
};

startup_(program);

// The example creates a file named "write_file.txt" with the contents:
// First line
// And then appends the following contents:
// New line 1
// New line 2
```
 
## See also

* [Common I/O Tasks](tutorial_common_io_tasks.md)
* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.

