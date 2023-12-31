| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Support](support.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md) | [Website](https://gammasoft71.github.io/xtd) |

# How to: Enumerate Directories and Files

Enumerable collections provide better performance than arrays when you work with large collections of directories and files. 
To enumerate directories and files, use methods that return an enumerable collection of directory or file names, or their [directory_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory__info.html), [file_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__info.html), or [file_system_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__system__info.html) objects.

If you want to search and return only the names of directories or files, use the enumeration methods of the [directory](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory.html) class. 
If you want to search and return other properties of directories or files, use the [directory_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory__info.html) and [file_system_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__system__info.html) classes.

The following table summarizes the methods that return enumerable collections of files and directories:

| To search and return                                                                                                               | Use method                                                                                                                                                   |
| ---------------------------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Directory names                                                                                                                    | [directory::enumerate_directories](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory.html#a18b4ef2bf2e42182dfd412ffacba57b1)                  |
| Directory information ([directory_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory__info.html))              | [directory_info::enumerate_directories](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory__info.html#ad0818557e5fbc58db748458c7e907c4b)       |
| File names                                                                                                                         | [directory::enumerate_files](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory.html#aecc4a0b18118e7e15e2fa43be4fcf237)                        |
| File information ([file_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__info.html))                             | [directory_info::enumerate_files](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory__info.html#aae6b6e624c5ac50f1f7bb5ec8088114a)             |
| File system entry names                                                                                                            | [directory::enumerate_file_system_entries](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory.html#a7e708ed279ee55d2412433a1cd842a08)          |
| File system entry information ([file_system_info](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__system__info.html)) | [directory_info::enumerate_file_system_infos](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory__info.html#a5603178c1e7c506db62092308ce6f66d) |
| Directory and file names                                                                                                           | [directory::enumerate_file_system_entries](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory.html#a7e708ed279ee55d2412433a1cd842a08)          |

## Examples: Use the directory class

The following example uses the [directory::enumerate_directories(const ustring&)](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory.html#a18b4ef2bf2e42182dfd412ffacba57b1) method to get a list of the top-level directory names in a specified path.

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    try {
      // Set a variable to the My Documents path.
      ustring doc_path = environment::get_folder_path(environment::special_folder::my_documents);
      
      auto dirs_iterator = directory::enumerate_directories(doc_path);
      vector<ustring> dirs(dirs_iterator.begin(), dirs_iterator.end());
      
      for (auto dir : dirs) {
        console::write_line("{}", dir.substring(dir.last_index_of(path::directory_separator_char()) + 1));
      }
      console::write_line("{} directories found.", dirs.size());
    } catch (const unauthorized_access_exception& ex) {
      console::write_line(ex.message());
    } catch (const path_too_long_exception& ex) {
      console::write_line(ex.message());
    }
  }
};

startup_(program);
```
 
## Examples: Use the directory_info class

The following example uses the [directory_info::enumerate_directories](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory__info.html#ad0818557e5fbc58db748458c7e907c4b) method to list a collection of top-level directories whose [creation_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__system__info.html#a970dfefd830a4edfdc36f72153c9d811) is not earlier than a certain [date_time](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1date__time.html) value.
 
 ```cpp
 #include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    // Set a variable to the Documents path.
    ustring doc_path = environment::get_folder_path(environment::special_folder::my_documents);
    
    directory_info dir_programs(doc_path);
    date_time start_of_2021(2021, 1, 1);
    vector<directory_info> dirs;
    
    for (auto dir : dir_programs.enumerate_directories()) {
      if (dir.creation_time() >= start_of_2021)
        dirs.push_back(dir);
    };
    
    for (auto di : dirs) {
      console::write_line("{}", di.name());
    }
  }
};

startup_(program);
```

The following example uses the [directory_info::enumerate_files](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1directory__info.html#aae6b6e624c5ac50f1f7bb5ec8088114a) method to list all files whose [length](https://gammasoft71.github.io/xtd/reference_guides/latest/classxtd_1_1io_1_1file__info.html#a7bbc1abbd603c19f70d687770961d195) exceeds 10MB. 
This example first enumerates the top-level directories, to catch possible unauthorized access exceptions, and then enumerates the files. 

```cpp
#include <xtd/xtd>

using namespace std;
using namespace xtd;
using namespace xtd::io;

class program {
public:
  static auto main() {
    // Set a variable to the Documents path.
    ustring doc_path = environment::get_folder_path(environment::special_folder::my_documents);
    
    directory_info di_top(doc_path);
    
    try {
      for (auto fi : di_top.enumerate_files()) {
        try {
          // Display each file over 10 MB;
          if (fi.length() > 10000000) {
            console::write_line("{}\t\t{:N0}", fi.full_name(), fi.length());
          }
        } catch (const unauthorized_access_exception& un_auth_top) {
          console::write_line(un_auth_top.message());
        }
      }
      
      for (auto di : di_top.enumerate_directories("*")) {
        try {
          for (auto fi : di.enumerate_files("*")) {
            try {
              // Display each file over 10 MB;
              if (fi.length() > 10000000) {
                console::write_line("{}\t\t{:N0}", fi.full_name(), fi.length());
              }
            } catch (const unauthorized_access_exception& un_auth_file) {
              console::write_line(un_auth_file.message());
            }
          }
        } catch (const unauthorized_access_exception& un_auth_sub_dir) {
          console::write_line(un_auth_sub_dir.message());
        }
      }
    } catch (const directory_not_found_exception& dir_not_found) {
      console::write_line("{}", dir_not_found.message());
    } catch (const unauthorized_access_exception& un_auth_dir) {
      console::write_line("un_auth_dir: {}", un_auth_dir.message());
    } catch (const path_too_long_exception& long_path) {
      console::write_line("{}", long_path.message());
    }
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

<!---
https://docs.microsoft.com/en-us/dotnet/standard/io/how-to-enumerate-directories-and-files
--->
