/// @file
/// @brief Contains xtd::io::file_system_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <chrono>
#include <memory>
#include "../abstract.h"
#include "../core_export.h"
#include "../ustring.h"
#include "file_attributes.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides the base class for both xtd::io::file_info and xtd::io::directory_info objects.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @remarks The xtd::io::file_system_info class contains methods that are common to file and directory manipulation. A xtd::io::file_system_info object can represent either a file or a directory, thus serving as the basis for xtd::io::file_info or xtd::io::directory_info objects. Use this base class when parsing a lot of files and directories.
    /// @remarks In members that accept a path, the path can refer to a file or just a directory. The specified path can also refer to a relative path or a Universal Naming Convention (UNC) path for a server and share name. For example, all the following are acceptable paths:
    /// * "c:\\MyDir\\MyFile.txt"
    /// * "c:\\MyDir"
    /// * "MyDir\\MySubdir"
    /// * "\\\\MyServer\\MyShare"
    /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
    /// @par Example
    /// The following example shows how to loop through all the files and directories, querying some information about each entry.
    /// @code
    /// #include <xtd/xtd>
    ///
    /// using namespace xtd;
    /// using namespace xtd::io;
    ///
    /// class program {
    /// public:
    ///   static void main() {
    ///     //  Loop through all the immediate subdirectories of C.
    ///     for (ustring entry : directory::get_directories("C:\\")) {
    ///       display_file_system_info_attributes(directory_info(entry));
    ///     }
    ///     //  Loop through all the files in C.
    ///     for (ustring entry : directory::get_files("C:\\")) {
    ///       display_file_system_info_attributes(file_info(entry));
    ///     }
    ///   }
    ///
    ///   static void display_file_system_info_attributes(const file_system_info& fsi) {
    ///     //  Assume that this entry is a file.
    ///     ustring entry_type = "File";
    ///
    ///     // Determine if entry is really a directory
    ///     if ((fsi.attributes() & file_attributes::directory) == file_attributes::directory) {
    ///       entry_type = "Directory";
    ///     }
    ///     //  Show this entry's type, name, and creation date.
    ///     console::write_line("{0} entry {1} was created on {2:D}", entry_type, fsi.full_name(), fsi.creation_time());
    ///   }
    /// };
    ///
    /// startup_(program);
    ///
    /// // Output will vary based on contents of drive C.
    ///
    /// // Directory entry C:\Documents and Settings was created on Tuesday, November 25, 2003
    /// // Directory entry C:\Inetpub was created on Monday, January 12, 2004
    /// // Directory entry C:\Program Files was created on Tuesday, November 25, 2003
    /// // Directory entry C:\RECYCLER was created on Tuesday, November 25, 2003
    /// // Directory entry C:\System Volume Information was created on Tuesday, November 2, 2003
    /// // Directory entry C:\WINDOWS was created on Tuesday, November 25, 2003
    /// // File entry C:\IO.SYS was created on Tuesday, November 25, 2003
    /// // File entry C:\MSDOS.SYS was created on Tuesday, November 25, 2003
    /// // File entry C:\pagefile.sys was created on Saturday, December 27, 2003
    /// @endcode
    class core_export_ file_system_info abstract_ {
    protected:
      /// @brief Initializes a new instance of the xtd::io::file_system_info class.
      file_system_info() = default;
      
    public:
      /// @cond
      file_system_info(const file_system_info&) = default;
      file_system_info& operator=(const file_system_info&) = default;
      /// @endcond
      
      /// @brief Gets the attributes for the current file or directory.
      /// @return xtd::io::file_attributes of the current xtd::io::file_system_info.
      /// @exception xtd::io::file_not_found_exception The specified file doesn't exist. Only thrown when setting the property value.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid. For example, it's on an unmapped drive. Only thrown when setting the property value.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::argument_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::io_exception xtd::io::file_system_info::refresh() cannot initialize the data.
      /// @remarks The value of the xtd::io::file_system_info::attributes property is pre-cached if the current instance of the xtd::io::file_system_info object was returned from any of the following xtd::io::directory_info methods:
      /// * xtd::io::directory_info::get_directories
      /// * xtd::io::directory_info::get_files
      /// * xtd::io::directory_info::get_file_system_infos
      /// * xtd::io::directory_info::enumerate_directories
      /// * xtd::io::directory_info::enumerate_files
      /// * xtd::io::directory_info::enumerate_file_system_infos
      /// @remarks The value may be cached when either the value itself or other xtd::io::file_system_info properties are accessed. To get the latest value, call the xtd::io::file_system_info::refresh method.
      /// @remarks If the path doesn't exist as of the last cached state, the return value is static_cast<xtd::io::file_attributes>(-1). xtd::io::file_not_found_exception or xtd::io::directory_not_found_exception can only be thrown when setting the value.
      /// @remarks The value of this property is a combination of the archive, compressed, directory, hidden, offline, read-only, system, and temporary file attribute flags.
      /// @remarks When you set this value, use the bitwise OR operator (|) to apply more than one value. To retain any existing values in the xtd::io::file_system_info::attributes property, include the value of the xtd::io::file_system_info::attributes property in your assignment. For example:
      /// @verbatim example_file.attributes(example_file.attributes() | file_attributes::read_only; @endverbatim
      /// @par Example
      /// The following example demonstrates the xtd::io::file_system_info::attribute property. This code example is part of a larger example provided for the xtd::io::file_system_info class.
      /// @code
      ///   static void display_file_system_info_attributes(const file_system_info& fsi) {
      ///     //  Assume that this entry is a file.
      ///     ustring entry_type = "File";
      ///
      ///     // Determine if entry is really a directory
      ///     if ((fsi.attributes() & file_attributes::directory) == file_attributes::directory) {
      ///       entry_type = "Directory";
      ///     }
      ///     //  Show this entry's type, name, and creation date.
      ///     console::write_line("{0} entry {1} was created on {2:D}", entry_type, fsi.full_name(), fsi.creation_time());
      ///   }
      /// @endcode
       xtd::io::file_attributes attributes() const;
      /// @brief Sets the attributes for the current file or directory.
      /// @param value xtd::io::file_attributes of the current xtd::io::file_system_info.
      /// @exception xtd::io::file_not_found_exception The specified file doesn't exist. Only thrown when setting the property value.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid. For example, it's on an unmapped drive. Only thrown when setting the property value.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::argument_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::io_exception xtd::io::file_system_info::refresh() cannot initialize the data.
      /// @exception xtd::platform_not_supported_exception The opration is not supported on the current operating system.
      /// @remarks The value of the xtd::io::file_system_info::attributes property is pre-cached if the current instance of the xtd::io::file_system_info object was returned from any of the following xtd::io::directory_info methods:
      /// * xtd::io::directory_info::get_directories
      /// * xtd::io::directory_info::get_files
      /// * xtd::io::directory_info::get_file_system_infos
      /// * xtd::io::directory_info::enumerate_directories
      /// * xtd::io::directory_info::enumerate_files
      /// * xtd::io::directory_info::enumerate_file_system_infos
      /// @remarks The value may be cached when either the value itself or other xtd::io::file_system_info properties are accessed. To get the latest value, call the xtd::io::file_system_info::refresh method.
      /// @remarks If the path doesn't exist as of the last cached state, the return value is static_cast<xtd::io::file_attributes>(-1). xtd::io::file_not_found_exception or xtd::io::directory_not_found_exception can only be thrown when setting the value.
      /// @remarks The value of this property is a combination of the archive, compressed, directory, hidden, offline, read-only, system, and temporary file attribute flags.
      /// @remarks When you set this value, use the bitwise OR operator (|) to apply more than one value. To retain any existing values in the xtd::io::file_system_info::attributes property, include the value of the xtd::io::file_system_info::attributes property in your assignment. For example:
      /// @verbatim example_file.attributes(example_file.attributes() | file_attributes::read_only; @endverbatim
      /// @par Example
      /// The following example demonstrates the xtd::io::file_system_info::attribute property. This code example is part of a larger example provided for the xtd::io::file_system_info class.
      /// @code
      ///   static void display_file_system_info_attributes(const file_system_info& fsi) {
      ///     //  Assume that this entry is a file.
      ///     ustring entry_type = "File";
      ///
      ///     // Determine if entry is really a directory
      ///     if ((fsi.attributes() & file_attributes::directory) == file_attributes::directory) {
      ///       entry_type = "Directory";
      ///     }
      ///     //  Show this entry's type, name, and creation date.
      ///     console::write_line("{0} entry {1} was created on {2:D}", entry_type, fsi.full_name(), fsi.creation_time());
      ///   }
      /// @endcode
      xtd::io::file_system_info& attributes(xtd::io::file_attributes value);

      /// @brief Gets the creation time of the current file or directory.
      /// @return The creation date and time of the current xtd::io::file_system_info object.
      /// @exception xtd::io::io_exception system error when retrieving the file information.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid; for example, it is on an unmapped drive.
      /// @exception xtd::platform_not_supported_exception The opration is not supported on the current operating system.
      /// @par Example
      /// The following example demonstrates the xtd::io::file_system_info::creation_time property. This code example is part of a larger example provided for the xtd::io::file_system_info class.
      /// @code
      ///   static void display_file_system_info_attributes(const file_system_info& fsi) {
      ///     //  Assume that this entry is a file.
      ///     ustring entry_type = "File";
      ///
      ///     // Determine if entry is really a directory
      ///     if ((fsi.attributes() & file_attributes::directory) == file_attributes::directory) {
      ///       entry_type = "Directory";
      ///     }
      ///     //  Show this entry's type, name, and creation date.
      ///     console::write_line("{0} entry {1} was created on {2:D}", entry_type, fsi.full_name(), fsi.creation_time());
      ///   }
      /// @endcode
      std::chrono::system_clock::time_point creation_time() const;
      /// @brief Gets the creation time of the current file or directory.
      /// @param value The creation date and time of the current xtd::io::file_system_info object.
      /// @exception xtd::io::io_exception system error when retrieving the file information.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid; for example, it is on an unmapped drive.
      /// @exception xtd::platform_not_supported_exception The opration is not supported on the current operating system.
      /// @par Example
      /// The following example demonstrates the xtd::io::file_system_info::creation_time property. This code example is part of a larger example provided for the xtd::io::file_system_info class.
      /// @code
      ///   static void display_file_system_info_attributes(const file_system_info& fsi) {
      ///     //  Assume that this entry is a file.
      ///     ustring entry_type = "File";
      ///
      ///     // Determine if entry is really a directory
      ///     if ((fsi.attributes() & file_attributes::directory) == file_attributes::directory) {
      ///       entry_type = "Directory";
      ///     }
      ///     //  Show this entry's type, name, and creation date.
      ///     console::write_line("{0} entry {1} was created on {2:D}", entry_type, fsi.full_name(), fsi.creation_time());
      ///   }
      /// @endcode
      xtd::io::file_system_info& creation_time(std::chrono::system_clock::time_point value);

      /// @brief Gets a value indicating whether the file or directory exists.
      /// @return true if the file or directory exists; otherwise, false.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      virtual bool exists() const = 0;
      
      /// @brief Gets the extension part of the file name, including the leading dot . even if it is the entire file name, or an empty string if no extension is present.
      /// @return A string containing the xtd::io::file_system_info extension.
      /// @remarks The Extension property returns the FileSystemInfo extension, which starts at, and includes, the last dot (.) in the file's full name. For example:
      /// * For a file c:\NewFile.txt, this property returns ".txt".
      /// * For a file c:\.gitignore, this property returns ".gitignore".
      /// * For a file c:\noextension, this property returns an empty string "".
      /// * For a file c:\a.b.c, this property returns ".c".
      /// * When the xtd::io::file_system_info is constructed from a file path with a trailing dot, then that trailing dot is trimmed, so new xtd::io::file_system_info("foo.bar.").extension returns ".bar".
      /// @remarks
      /// | To do this...                                 | See the example in this topic...                                                                                                               |
      /// |-----------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------|
      /// | Create a text file.                           | <a ref="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks_write_text_to_a_file.md">How to: Write Text to a File</a> |
      /// | Write to a text file.                         | <a ref="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks_write_text_to_a_file.md">How to: Write Text to a File</a> |
      /// | Read from a text file.                        | <a ref="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks_read_text_from_a_file.md">How to: Read Text to a File</a> |
      /// | Retrieve the fully qualified path of a file.  | xtd::io::path::get_full_path                                                                                                                   |
      /// | Retrieve only the file name a path.           | xtd::io::path::get_file_name_without_extension                                                                                                 |
      /// | Retrieve only the directory name from a path. | xtd::io::path::get_directory_name                                                                                                              |
      /// | Change the extension of a file.               | xtd::io::path::change_extrnsion                                                                                                                |
      virtual xtd::ustring extension() const;
      
      /// @brief Gets the full path of the directory or file.
      /// @return A string containing the full path.
      /// @par Example
      /// The following example demonstrates the xtd::io::file_system_info::full_name property. This code example is part of a larger example provided for the xtd::io::file_system_info class.
      /// @code
      ///   static void display_file_system_info_attributes(const file_system_info& fsi) {
      ///     //  Assume that this entry is a file.
      ///     ustring entry_type = "File";
      ///
      ///     // Determine if entry is really a directory
      ///     if ((fsi.attributes() & file_attributes::directory) == file_attributes::directory) {
      ///       entry_type = "Directory";
      ///     }
      ///     //  Show this entry's type, name, and creation date.
      ///     console::write_line("{0} entry {1} was created on {2:D}", entry_type, fsi.full_name(), fsi.creation_time());
      ///   }
      /// @endcode
      /// @remarks For example, for a file c:\new_file.txt, this property returns "c:\new_file.txt".
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      xtd::ustring full_name() const;
      
      /// @brief Gets the time the current file or directory was last accessed.
      /// @return The time that the current file or directory was last accessed.
      /// @exception xtd::io::io_exception system error when retrieving the file information.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid; for example, it is on an unmapped drive.
      /// @exception xtd::platform_not_supported_exception The opration is not supported on the current operating system.
      /// @par Example
      /// The following code example demonstrates the updating of the xtd::io::file_system_info::last_access_time property through a "touch" operation. In this example, the file is "touched", updating the xtd::io::file_system_info::creation_time, xtd::io::file_system_info::last_access_time and xtd::io::file_system_info::last_write_time properties to the current date and time.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class touch {
      /// public:
      ///   static void main(const std::vector<ustring>& args) {
      ///     // Make sure a filename was provided.
      ///     if (args.size() > 0) {
      ///       // Verify that the provided filename exists.
      ///       if (file::exists(args[0])) {
      ///         file_info fi(args[0]);
      ///         touch_file(fi);
      ///       } else {
      ///         console::write_line("Could not find the file: {0}.", args[0]);
      ///       }
      ///     } else {
      ///       console::write_line("No file was specified.");
      ///     }
      ///   }
      ///
      ///   static void touch_file(file_system_info& fsi) {
      ///     console::write_line("Touching: {0}", fsi.full_name());
      ///
      ///     // Update the CreationTime, LastWriteTime and LastAccessTime.
      ///     try {
      ///       auto now = std::chrono::system_clock::now();
      ///       fsi.creation_time(now).last_write_time(now).last_access_time(now);
      ///     } catch (const system_exception& e) {
      ///       console::write_line("Error: {0}", e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(touch);
      /// @endcode
      /// @note This method may return an inaccurate value because it uses native functions whose values may not be continuously updated by the operating system.
      /// @remarks The value of the xtd::io::file_system_info::last_access_time property is pre-cached if the current instance of the xtd::io::file_system_info object was returned from any of the following xtd::io::directory_info methods:
      /// * xtd::io::directory_info::get_directories
      /// * xtd::io::directory_info::get_files
      /// * xtd::io::directory_info::get_file_system_infos
      /// * xtd::io::directory_info::enumerate_directories
      /// * xtd::io::directory_info::enumerate_files
      /// * xtd::io::directory_info::enumerate_file_system_infos
      /// * To get the latest value, call the xtd::io::file_system_info::refresh method.
      std::chrono::system_clock::time_point last_access_time() const;
      /// @brief Sets the time the current file or directory was last accessed.
      /// @param value The time that the current file or directory was last accessed.
      /// @exception xtd::io::io_exception system error when retrieving the file information.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid; for example, it is on an unmapped drive.
      /// @exception xtd::platform_not_supported_exception The opration is not supported on the current operating system.
      /// @par Example
      /// The following code example demonstrates the updating of the xtd::io::file_system_info::last_access_time property through a "touch" operation. In this example, the file is "touched", updating the xtd::io::file_system_info::creation_time, xtd::io::file_system_info::last_access_time and xtd::io::file_system_info::last_write_time properties to the current date and time.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class touch {
      /// public:
      ///   static void main(const std::vector<ustring>& args) {
      ///     // Make sure a filename was provided.
      ///     if (args.size() > 0) {
      ///       // Verify that the provided filename exists.
      ///       if (file::exists(args[0])) {
      ///         file_info fi(args[0]);
      ///         touch_file(fi);
      ///       } else {
      ///         console::write_line("Could not find the file: {0}.", args[0]);
      ///       }
      ///     } else {
      ///       console::write_line("No file was specified.");
      ///     }
      ///   }
      ///
      ///   static void touch_file(file_system_info& fsi) {
      ///     console::write_line("Touching: {0}", fsi.full_name());
      ///
      ///     // Update the CreationTime, LastWriteTime and LastAccessTime.
      ///     try {
      ///       auto now = std::chrono::system_clock::now();
      ///       fsi.creation_time(now).last_write_time(now).last_access_time(now);
      ///     } catch (const system_exception& e) {
      ///       console::write_line("Error: {0}", e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(touch);
      /// @endcode
      /// @note This method may return an inaccurate value because it uses native functions whose values may not be continuously updated by the operating system.
      /// @remarks The value of the xtd::io::file_system_info::last_access_time property is pre-cached if the current instance of the xtd::io::file_system_info object was returned from any of the following xtd::io::directory_info methods:
      /// * xtd::io::directory_info::get_directories
      /// * xtd::io::directory_info::get_files
      /// * xtd::io::directory_info::get_file_system_infos
      /// * xtd::io::directory_info::enumerate_directories
      /// * xtd::io::directory_info::enumerate_files
      /// * xtd::io::directory_info::enumerate_file_system_infos
      /// * To get the latest value, call the xtd::io::file_system_info::refresh method.
      xtd::io::file_system_info& last_access_time(std::chrono::system_clock::time_point value);
      
      /// @brief Gets the time when the current file or directory was last written to.
      /// @return The time the current file was last written.
      /// @exception xtd::io::io_exception system error when retrieving the file information.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid; for example, it is on an unmapped drive.
      /// @exception xtd::platform_not_supported_exception The opration is not supported on the current operating system.
      /// @par Example
      /// The following code example demonstrates the updating of the xtd::io::file_system_info::last_write_time property through a "touch" operation. In this example, the file is "touched", updating the xtd::io::file_system_info::creation_time, xtd::io::file_system_info::last_access_time and xtd::io::file_system_info::last_write_time properties to the current date and time.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class touch {
      /// public:
      ///   static void main(const std::vector<ustring>& args) {
      ///     // Make sure a filename was provided.
      ///     if (args.size() > 0) {
      ///       // Verify that the provided filename exists.
      ///       if (file::exists(args[0])) {
      ///         file_info fi(args[0]);
      ///         touch_file(fi);
      ///       } else {
      ///         console::write_line("Could not find the file: {0}.", args[0]);
      ///       }
      ///     } else {
      ///       console::write_line("No file was specified.");
      ///     }
      ///   }
      ///
      ///   static void touch_file(file_system_info& fsi) {
      ///     console::write_line("Touching: {0}", fsi.full_name());
      ///
      ///     // Update the CreationTime, LastWriteTime and LastAccessTime.
      ///     try {
      ///       auto now = std::chrono::system_clock::now();
      ///       fsi.creation_time(now).last_write_time(now).last_access_time(now);
      ///     } catch (const system_exception& e) {
      ///       console::write_line("Error: {0}", e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(touch);
      /// @endcode
      /// @note This method may return an inaccurate value because it uses native functions whose values may not be continuously updated by the operating system.
      /// @remarks The value of the xtd::io::file_system_info::last_write_time property is pre-cached if the current instance of the xtd::io::file_system_info object was returned from any of the following xtd::io::directory_info methods:
      /// * xtd::io::directory_info::get_directories
      /// * xtd::io::directory_info::get_files
      /// * xtd::io::directory_info::get_file_system_infos
      /// * xtd::io::directory_info::enumerate_directories
      /// * xtd::io::directory_info::enumerate_files
      /// * xtd::io::directory_info::enumerate_file_system_infos
      /// * To get the latest value, call the xtd::io::file_system_info::refresh method.
      std::chrono::system_clock::time_point last_write_time() const;
      /// @brief Sets the time when the current file or directory was last written to.
      /// @param value The time the current file was last written.
      /// @exception xtd::io::io_exception system error when retrieving the file information.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid; for example, it is on an unmapped drive.
      /// @exception xtd::platform_not_supported_exception The opration is not supported on the current operating system.
      /// @par Example
      /// The following code example demonstrates the updating of the xtd::io::file_system_info::last_write_time property through a "touch" operation. In this example, the file is "touched", updating the xtd::io::file_system_info::creation_time, xtd::io::file_system_info::last_access_time and xtd::io::file_system_info::last_write_time properties to the current date and time.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class touch {
      /// public:
      ///   static void main(const std::vector<ustring>& args) {
      ///     // Make sure a filename was provided.
      ///     if (args.size() > 0) {
      ///       // Verify that the provided filename exists.
      ///       if (file::exists(args[0])) {
      ///         file_info fi(args[0]);
      ///         touch_file(fi);
      ///       } else {
      ///         console::write_line("Could not find the file: {0}.", args[0]);
      ///       }
      ///     } else {
      ///       console::write_line("No file was specified.");
      ///     }
      ///   }
      ///
      ///   static void touch_file(file_system_info& fsi) {
      ///     console::write_line("Touching: {0}", fsi.full_name());
      ///
      ///     // Update the CreationTime, LastWriteTime and LastAccessTime.
      ///     try {
      ///       auto now = std::chrono::system_clock::now();
      ///       fsi.creation_time(now).last_write_time(now).last_access_time(now);
      ///     } catch (const system_exception& e) {
      ///       console::write_line("Error: {0}", e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(touch);
      /// @endcode
      /// @note This method may return an inaccurate value because it uses native functions whose values may not be continuously updated by the operating system.
      /// @remarks The value of the xtd::io::file_system_info::last_write_time property is pre-cached if the current instance of the xtd::io::file_system_info object was returned from any of the following xtd::io::directory_info methods:
      /// * xtd::io::directory_info::get_directories
      /// * xtd::io::directory_info::get_files
      /// * xtd::io::directory_info::get_file_system_infos
      /// * xtd::io::directory_info::enumerate_directories
      /// * xtd::io::directory_info::enumerate_files
      /// * xtd::io::directory_info::enumerate_file_system_infos
      /// * To get the latest value, call the xtd::io::file_system_info::refresh method.
      xtd::io::file_system_info& last_write_time(std::chrono::system_clock::time_point value);

      /// @brief For files, gets the name of the file. For directories, gets the name of the last directory in the hierarchy if a hierarchy exists. Otherwise, the Name property gets the name of the directory.
      /// @return A xtd::ustring that is the name of the parent directory, the name of the last directory in the hierarchy, or the name of a file, including the file name extension.
      /// @remarks For a directory, xtd::io::file_system_info::name returns only the name of the parent directory, such as dir, not c:\dir. For a subdirectory, xtd::io::file_system_info::name returns only the name of the subdirectory, such as sub1, not c:\dir\sub1.
      /// @remarks For a file, xtd::io::file_system_info::name returns only the file name and file name extension, such as my_file.txt, not c:\dir\my_file.txt.
      virtual xtd::ustring name() const = 0;
      
      /// @brief Refreshes the state of the object.
      /// @exception xtd::io::io_exception A device such as a disk drive is not ready.
      /// @remarks xtd::io::file_system_info::refresh takes a snapshot of the file from the current file system.
      /// @remarks Call xtd::io::file_system_info::refresh before attempting to get the attribute information, or the information will be outdated.
      void refresh();
      
      /// @brief Deletes a file or directory.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid; for example, it is on an unmapped drive.
      /// @exception xtd::io::io_exception There is an open handle on the file or directory, and the operating system is Windows XP or earlier. This open handle can result from enumerating directories and files. For more information, see <a ref="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks_enumerate_directories_and_files.mdd">How to: Enumerate Directories and Files</a>.
      virtual void remove() const = 0;
      
      /// @brief Returns the original path. Use the xtd::io::file_system_info::full_name or xtd::io::file_system_info::name properties for the full path or file/directory name.
      /// @return A string with the original path.
      /// @note The string returned by the xtd::io::file_system_info::tto_string method represents the path that was passed to the constructor of the class implementing xtd::io::file_system_info. Instead of calling the xtd::io::file_system_info::to_string method, you should retrieve the value of either of the following properties, depending on your intent:
      /// * xtd::io::file_system_info::name, to get the name of the file or directory, without any parent path information.
      /// * xtd::io::file_system_info::full_name, to get the fully qualified path of the file or directory.
      xtd::ustring to_string() const noexcept override;
      
    protected:
      /// @brief Represents the fully qualified path of the directory or file.
      xtd::ustring full_path_;
      /// @brief The path originally specified by the user, whether relative or absolute.
      xtd::ustring original_path_;
      
    private:
      xtd::io::file_attributes attributes_ = static_cast<xtd::io::file_attributes>(0);
      std::chrono::system_clock::time_point creation_time_;
      std::chrono::system_clock::time_point last_access_time_;
      std::chrono::system_clock::time_point last_write_time_;
    };
  }
}
