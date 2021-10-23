| [Home](home.md) | [News](news.md) | [Gallery](gallery.md) | [Examples](examples.md) | [Downloads](downloads.md) | [Documentation](documentation.md) | [Sources](https://github.com/gammasoft71/xtd) | [Project](https://sourceforge.net/projects/xtdpro/) | [Gammasoft](gammasoft.md)  | [Contact](contact.md) | [Website](https://gammasoft71.wixsite.com/xtdpro) |

# File and stream I/O

File and stream I/O (input/output) refers to the transfer of data either to or from a storage medium. In xtd, the xtd::io namespaces contain types that enable reading and writing, both synchronously and asynchronously, on data streams and files. These namespaces also contain types that perform compression and decompression on files, and types that enable communication through pipes and serial ports.

A file is an ordered and named collection of bytes that has persistent storage. When you work with files, you work with directory paths, disk storage, and file and directory names. In contrast, a stream is a sequence of bytes that you can use to read from and write to a backing store, which can be one of several storage mediums (for example, disks or memory). Just as there are several backing stores other than disks, there are several kinds of streams other than file streams, such as network, memory, and pipe streams.

## Files and directories

You can use the types in the [xtd::io](https://codedocs.xyz/gammasoft71/xtd/group__io.html) namespace to interact with files and directories. For example, you can get and set properties for files and directories, and retrieve collections of files and directories based on search criteria.

For path naming conventions and the ways to express a file path for Windows, macOS and Linux systems.

Here are some commonly used file and directory classes:

* [xtd::io::file](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1file.html) - provides static methods for creating, copying, deleting, moving, and opening files, and helps create a FileStream object.
* [xtd::io::file_info](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1file__info.html) - provides instance methods for creating, copying, deleting, moving, and opening files, and helps create a FileStream object.
* [xtd::io::directory](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1directory.html) - provides static methods for creating, moving, and enumerating through directories and subdirectories.
* [xtd::io::directory_info](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1directory__info.html) - provides instance methods for creating, moving, and enumerating through directories and subdirectories.
* [xtd::io::path](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1path.html) - provides methods and properties for processing directory strings in a cross-platform manner.

You should always provide robust exception handling when calling filesystem methods. 

## Streams

The std classes [std::ostream](https://en.cppreference.com/w/cpp/io/basic_iostream) and [std::istream](https://en.cppreference.com/w/cpp/io/basic_ostream) and [std::iostream](https://en.cppreference.com/w/cpp/io/basic_istream) support reading and writing bytes.

## Readers and writers

The [xtd::io](https://codedocs.xyz/gammasoft71/xtd/group__io.html) namespace also provides types for reading characters from streams and writing them to streams. Typically, streams are designed for byte input and output. The reader and writer types handle the conversion of the characters to and from bytes so the stream can complete the operation. Each reader and writer class is associated with a stream.

Here are some commonly used reader and writer classes:

* [xtd::io::binary_reader](xtd::io](https://codedocs.xyz/gammasoft71/xtd/group__io.html) and [xtd::io::binary_writer](xtd::io](https://codedocs.xyz/gammasoft71/xtd/group__io.html) – for reading and writing primitive data types as binary values.
* [xtd::io::stream_reader](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1stream__reader.html) and [xtd::io::stream_writer](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1stream__writer.html) – for reading and writing characters by using a value to convert the characters to and from bytes.
* [xtd::io::string_reader](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1string__reader.html) and [xtd::io::string_writer](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1string__writer.html) – for reading and writing characters to and from strings.
* [xtd::io::text_reader](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1text__reader.html) and [xtd::io::text_writer](https://codedocs.xyz/gammasoft71/xtd/classxtd_1_1io_1_1text__writer.html) – serve as the abstract base classes for other readers and writers that read and write characters and strings, but not binary data.

## Compression

Coming soon...

## See also

* [Common I/O Tasks](tutorial_common_io_tasks.md)
* [Tutorials](tutorials.md)
* [Documentation](documentation.md)

______________________________________________________________________________________________

© 2021 Gammasoft.

<!--
https://docs.microsoft.com/en-us/dotnet/standard/io/
--->