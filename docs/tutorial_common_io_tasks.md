| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# Common I/O Tasks

The xtd.io namespace provides several classes that allow for various actions, such as reading and writing, to be performed on files, directories, and streams. For more information, see [File and Stream I/O](tutorial_file_and_stream_io.md).


## Common File Tasks

| To do this...                                    | See the example in this topic... |
|--------------------------------------------------|----------------------------------|
| Create a text file                               | file::create_text method<br>file_info::create_text method<br>file::create method<br>file_info::create method |
| Write to a text file                             | [ow to: Write Text to a File]()<br>[How to: Write a Text File]() |
| Read from a text file                            | [How to: Read Text from a File]() |
| Append text to a file                            | [How to: Open and Append to a Log File]()<br>file::append_text method<br>file_info.append_text method |
| Rename or move a file                            | file::move method<br>file_info::move_ro method |
| Delete a file                                    | file::remove method<br>file_info::remove method |
| Copy a file                                      | file::copy method<brd>file_info::copy_to method |
| Get the size of a file                           | file_info::length property |
| Get the attributes of a file                     | file::get_attributes method |
| Set the attributes of a file                     | file::set_attributes method |
| Determine whether a file exists                  | file::exists method |
| Read from a binary file                          | [How to: Read and Write to a Newly Created Data File]() |
| Write to a binary file                           | [How to: Read and Write to a Newly Created Data File]() |
| Retrieve a file name extension                   | path::get_extension method |
| Retrieve the fully qualified path of a file      | path::get_full_path method |
| Retrieve the file name and extension from a path | path::get_file_name method |
| Change the extension of a file                   | path::change_extension method |

## Common Directory Tasks

| To do this...                                          | See the example in this topic... |
|--------------------------------------------------------|----------------------------------|
| Access a file in a special folder such as My Documents | [How to: Write Text to a File]() |
| Create a directory                                     | directory::create_directory method<br>file_info::directory property |
| Create a subdirectory                                  | directory_info.create_subdirectory method |
| Rename or move a directory                             | directory::move method<br>directory_inf::move_to method |
| Copy a directory                                       | [How to: Copy Directories]() |
| Delete a directory                                     | directory::remove method<br>directory_info::remove method |
| See the files and subdirectories in a directory        | [How to: Enumerate Directories and Files]() |
| Find the size of a directory                           | xtd::io::directory class |
| Determine whether a directory exists                   | directory::exists method |
 
______________________________________________________________________________________________

© 2021 Gammasoft.

