| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# How to: Copy Directories

This article demonstrates how to use I/O classes to synchronously copy the contents of a directory to another location.
For an example of asynchronous file copy, see Asynchronous file I/O.
This example copies subdirectories by setting the recursive parameter of the copy_directory method to `true`. The copy_directory method recursively copies subdirectories by calling itself on each subdirectory until there are no more to copy.

## Examples

```cpp
#include <xtd/xtd>

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::io;

class program {
public:
  static void copy_directory(const string& source_dir, const string& destination_dir, bool recursive) {
    // Get information about the source directory
    auto dir = directory_info(source_dir);
    
    // Check if the source directory exists
    if (!dir.exists())
      throw directory_not_found_exception(string::format("Source directory not found: {}", dir.full_name()));
    
    // Cache directories before we start copying
    list<directory_info> dirs = dir.get_directories();
    
    // Create the destination directory
    directory::create_directory(destination_dir);
    
    // Get the files in the source directory and copy to the destination directory
    for (const file_info& file : dir.get_files()) {
      string target_file_path = path::combine(destination_dir, file.name());
      file.copy_to(target_file_path);
    }
    
    // If recursive and copying subdirectories, recursively call this method
    if (recursive) {
      for (const directory_info& sub_dir : dirs) {
        string new_destination_dir = path::combine(destination_dir, sub_dir.name());
        copy_directory(sub_dir.full_name(), new_destination_dir, true);
      }
    }
  }
  
  static auto main() {
    copy_directory(".",  path::combine(".", "copytest"), true);
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

<!---
https://docs.microsoft.com/en-us/dotnet/standard/io/how-to-copy-directories
--->
