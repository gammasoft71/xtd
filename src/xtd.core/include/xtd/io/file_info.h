/// @file
/// @brief Contains xtd::io::file_info class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "file_system_info.h"
#include "stream_reader.h"
#include "stream_writer.h"
#include <fstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    class directory_info;
    /// @endcond
    
    /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::fstream objects.
    /// @code
    /// class core_export_ file_info : public xtd::io::file_system_info
    /// @endcode
    /// @par Inheritance
    /// xtd::io::file_system_info → xtd::io::file_info
    /// @par Header
    /// @code #include <xtd/io/file_info> @endcode
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @par Examples
    /// The following example demonstrates some of the main members of the xtd::io::file_info class.
    /// When the properties are first retrieved, xtd::io::file_info calls the xtd::io::file_info::refresh method and caches information about the file. On subsequent calls, you must call xtd::io::file_info::refresh to get the latest copy of the information.
    /// @include file_info.cpp
    /// @remarks Use the xtd::io::file_info class for typical operations such as copying, moving, renaming, creating, opening, deleting, and appending to files.
    /// @remarks If you are performing multiple operations on the same file, it can be more efficient to use td::io::file_info instance methods instead of the corresponding static methods of thetd::io::file class, because a security check will not always be necessary.
    /// @remarks Many of the xtd::io::file_info methods return other I/O types when you create or open files. You can use these other types to further manipulate a file. For more information, see specific td::io::file_info members such as td::io::file_info::open, td::io::file_info::open_read, td::io::file_info::open_text, td::io::file_info::create_text, or td::io::file_info::create.
    /// @remarks By default, full read/write access to new files is granted to all users.
    class core_export_ file_info : public xtd::io::file_system_info {
    public:
      /// @name Public Fields
      
      /// @{
      /// @brief Represents the uninitialized xtd::io::file_info object. This field is constant.
      static const file_info empty;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::io::file_info class, which acts as a wrapper for a file path.
      /// @param file_name The fully qualified name of the new file, or the relative file name. Do not end the path with the directory separator character.
      /// @exception xtd:argument_exception The file name is empty, contains only white spaces, or contains invalid characters.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::unauthorized_access_exception Access to fileName is denied.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::not_supported_exception fileName contains a colon (:) in the middle of the string.
      /// @par Examples
      /// The following example demonstrates some of the main members of the xtd::io::file_info class.
      /// When the properties are first retrieved, xtd::io::file_info calls the xtd::io::file_info::refresh method and caches information about the file. On subsequent calls, you must call xtd::io::file_info::refresh to get the latest copy of the information.
      /// @include file_info.cpp
      /// @remarks You can specify either the fully qualified or the relative file name, but the security check gets the fully qualified name.
      explicit file_info(const xtd::ustring& file_name);
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets an instance of the parent directory.
      /// @return A xtd::io::directory_info object representing the parent directory of this file.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      xtd::io::directory_info directory() const;
      
      /// @brief Gets a string representing the directory's full path.
      /// @return A string representing the directory's full path.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @par Exemple
      /// The following example retrieves the full path of the specified file.
      /// @code
      /// ustring file_name = R"(C:\TMP\log.txt)";
      /// file_info file_info(file_name);
      /// if (!file_info.exists())
      ///   return;
      ///
      /// console::write_line("{0} has a directoryName of {1}", file_name, file_info.directory_name());
      /// /* This code produces output similar to the following,
      ///  * though actual results may vary by machine:
      ///  *
      ///  * C:\TMP\log.txt has a directory name of C:\TMP
      ///  */
      /// @endcode
      /// @remarks To get the parent directory as a xtd::io::directory_info object, use the xtd::io::file_info::directory property.
      /// @remarks When first called, xtd::io::file_info calls xtd::io::file_info::refresh and caches information about the file. On subsequent calls, you must call xtd::io::file_info::refresh to get the latest copy of the information.
      xtd::ustring directory_name() const;
      
      /// @brief Gets a value indicating whether a file exists.
      /// @return true if the file exists; false if the file does not exist or if the file is a directory.
      /// @par Examples
      /// The following code example uses the xtd::io::file_info::exists property ensure a file exists before opening it. You can use this technique to throw a custom exception when the file is not found.
      /// @code
      /// std::vector<char> open_data_file(const ustring& file_name) {
      ///   // Check the FileName argument.
      ///   if (file_name.size() == 0)
      ///     throw argument_exception("file_name", csf_);
      ///
      ///   // Check to see if the file exists.
      ///   file_info f_info(file_name);
      ///
      ///   // You can throw a personalized exception if
      ///   // the file does not exist.
      ///   if (!f_info.exists())
      ///     throw file_not_found_exception("The file was not found.", csf_);
      ///
      ///   // Open the file.
      ///   std::ifstream f_stream(file_name, std::ios::binary);
      ///
      ///   // Create a buffer.
      ///   std::vector<char> buffer(f_info.size());
      ///
      ///   // Read the file contents to the buffer.
      ///   f_stream.read(&buffer[0], f_info.size());
      ///
      ///   // return the buffer.
      ///   return buffer;
      /// }
      /// @endcode
      /// @remarks When first called, xtd::io::file_info calls xtd::io::file_info::refresh and caches information about the file. On subsequent calls, you must call xtd::io::file_info::refresh to get the latest copy of the information.
      /// @remarks The xtd::io::file_info::exists property returns false if any error occurs while trying to determine if the specified file exists. This can occur in situations that raise exceptions such as passing a file name with invalid characters or too many characters, a failing or missing disk, or if the caller does not have permission to read the file.
      bool exists() const override;
      
      /// @brief Gets a value that determines if the current file is read only.
      /// @return true if the current file is read only; otherwise, false.
      /// @exception xtd::io::file_not_found_exception The file described by the current xtd::io::file_info object could not be found.
      /// @exception xtd::io::io_exception An I/O error occurred while opening the file.
      /// @exception xtd::unauthorized_access_exception This operation is not supported on the current platform.<br>-or-<br>The caller does not have the required permission.
      /// @exception xtd::argument_exception The user does not have write permission, but attempted to set this property to false.
      /// @par Examples
      /// The following example uses the xtd::io::file_info::is_read_only property to mark a file as read only and then mark it as read-write.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     ustring file_name = R"(c:\test.xml)";
      ///
      ///     // Get the read-only value for a file.
      ///     bool is_read_only = is_file_read_only(file_name);
      ///
      ///     // Display wether the file is read-only.
      ///     console::write_line("The file read-only value for " + file_name + " is: " + is_read_only);
      ///
      ///     console::write_line("Changing the read-only value for " + file_name + " to true.");
      ///
      ///     // Set the file to read-only.
      ///     set_file_read_access(file_name, true);
      ///
      ///     // Get the read-only value for a file.
      ///     is_read_only = is_file_read_only(file_name);
      ///
      ///     // Display that the file is read-only.
      ///     console::write_line("The file read-only value for " + file_name + " is: " + is_read_only);
      ///   }
      ///
      ///   // Sets the read-only value of a file.
      ///   static void set_file_read_access(const ustring& file_name, bool set_read_only) {
      ///     // Create a new xtd::io::file_info object.
      ///     file_info f_info(file_name);
      ///
      ///     // Set the IsReadOnly property.
      ///     f_info.is_read_only(set_read_only);
      ///   }
      ///
      ///   // Returns wether a file is read-only.
      ///   static bool is_file_read_only(const ustring& file_name) {
      ///     // Create a new xtd::io::file_info object.
      ///     file_info f_info(file_name);
      ///
      ///     // Return the IsReadOnly property value.
      ///     return f_info.is_read_only();
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      ///
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// //
      /// // The file read-only value for c:\test.xml is: True
      /// // Changing the read-only value for c:\test.xml to true.
      /// // The file read-only value for c:\test.xml is: True
      /// @endcode
      /// @remarks Use the xtd::io::file_info::is_read_only property to quickly determine or change whether the current file is read only.
      /// @remarks When first called, file_info calls xtd::io::file_info::refresh and caches information about the file. On subsequent calls, you must call xtd::io::file_info::refresh to get the latest copy of the information.
      bool is_read_only() const;
      /// @brief Sets a value that determines if the current file is read only.
      /// @param value true if the current file is read only; otherwise, false.
      /// @exception xtd::io::file_not_found_exception The file described by the current xtd::io::file_info object could not be found.
      /// @exception xtd::io::io_exception An I/O error occurred while opening the file.
      /// @exception xtd::unauthorized_access_exception This operation is not supported on the current platform.<br>-or-<br>The caller does not have the required permission.
      /// @exception xtd::argument_exception The user does not have write permission, but attempted to set this property to false.
      /// @par Examples
      /// The following example uses the xtd::io::file_info::is_read_only property to mark a file as read only and then mark it as read-write.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     ustring file_name = R"(c:\test.xml)";
      ///
      ///     // Get the read-only value for a file.
      ///     bool is_read_only = is_file_read_only(file_name);
      ///
      ///     // Display wether the file is read-only.
      ///     console::write_line("The file read-only value for " + file_name + " is: " + is_read_only);
      ///
      ///     console::write_line("Changing the read-only value for " + file_name + " to true.");
      ///
      ///     // Set the file to read-only.
      ///     set_file_read_access(file_name, true);
      ///
      ///     // Get the read-only value for a file.
      ///     is_read_only = is_file_read_only(file_name);
      ///
      ///     // Display that the file is read-only.
      ///     console::write_line("The file read-only value for " + file_name + " is: " + is_read_only);
      ///   }
      ///
      ///   // Sets the read-only value of a file.
      ///   static void set_file_read_access(const ustring& file_name, bool set_read_only) {
      ///     // Create a new xtd::io::file_info object.
      ///     file_info f_info(file_name);
      ///
      ///     // Set the IsReadOnly property.
      ///     f_info.is_read_only(set_read_only);
      ///   }
      ///
      ///   // Returns wether a file is read-only.
      ///   static bool is_file_read_only(const ustring& file_name) {
      ///     // Create a new xtd::io::file_info object.
      ///     file_info f_info(file_name);
      ///
      ///     // Return the IsReadOnly property value.
      ///     return f_info.is_read_only();
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      ///
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// //
      /// // The file read-only value for c:\test.xml is: True
      /// // Changing the read-only value for c:\test.xml to true.
      /// // The file read-only value for c:\test.xml is: True
      /// @endcode
      /// @remarks Use the xtd::io::file_info::is_read_only property to quickly determine or change whether the current file is read only.
      /// @remarks When first called, file_info calls xtd::io::file_info::refresh and caches information about the file. On subsequent calls, you must call xtd::io::file_info::refresh to get the latest copy of the information.
      void is_read_only(bool value);
      
      /// @brief Gets the size, in bytes, of the current file.
      /// @return The size of the current file in bytes.
      /// @exception xtd::io::io_exception xtd::io::file_info::refresh cannot update the state of the file or directory.
      /// @exception xtd::io::file_not_found_exception The file does not exist.<br>-or-<br>The xtd::io::file_info::size property is called for a directory.
      /// @par Examples
      ///
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// auto main()->int {
      ///   // Make a reference to a directory.
      ///   directory_info di("c:\\");
      ///   // Get a reference to each file in that directory.
      ///   vector<file_info> fi_arr = di.get_files();
      ///   // Display the names and sizes of the files.
      ///   console::write_line("The directory {0} contains the following files:", di.name());
      ///   for (file_info f : fi_arr)
      ///     console::write_line("The size of {0} is {1} bytes.", f.name(), f.length());
      /// }
      ///
      /// // This code produces the following to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// //
      /// // The directory c:\ contains the following files:
      /// // The size of MyComputer.log is 274 bytes.
      /// // The size of AUTOEXEC.BAT is 0 bytes.
      /// // The size of boot.ini is 211 bytes.
      /// // The size of CONFIG.SYS is 0 bytes.
      /// // The size of hiberfil.sys is 1072775168 bytes.
      /// // The size of IO.SYS is 0 bytes.
      /// // The size of MASK.txt is 2700 bytes.
      /// // The size of mfc80.dll is 1093632 bytes.
      /// // The size of mfc80u.dll is 1079808 bytes.
      /// // The size of MSDOS.SYS is 0 bytes.
      /// // The size of NTDETECT.COM is 47564 bytes.
      /// // The size of ntldr is 250032 bytes.
      /// // The size of pagefile.sys is 1610612736 bytes.
      /// // The size of UpdatePatch.log is 22778 bytes.
      /// // The size of UpdatePatch.txt is 30 bytes.
      /// // The size of wt3d.ini is 234 bytes.
      /// @endcode
      /// @remarks
      /// The value of the Length property is pre-cached if the current instance of the xtd::io::file_info object was returned from any of the following DirectoryInfo methods:
      /// * xtd::io::file_info::get_directories
      /// * xtd::io::file_info::_det_files
      /// * xtd::io::file_info::get_file_system_infos
      /// * xtd::io::file_info::enumerate_directories
      /// * xtd::io::file_info::enumerate_files
      /// * xtd::io::file_info::enumerate_file_system_infos
      /// * To get the latest value, call the xtd::io::file_info::refresh method.
      size_t length() const;
      
      /// @brief Gets the name of the file.
      /// @return The name of the file.
      ///
      /// @par Examples
      ///
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// auto main()->int {
      ///   // Create a reference to the current directory.
      ///   directory_info di(environment::current_directory());
      ///   // Create an array representing the files in the current directory.
      ///   vector<file_info> fi = di.get_files();
      ///   console::write_line("The following files exist in the current directory:");
      ///   // Print out the names of the files in the current directory.
      ///   for (file_info fi_temp : fi)
      ///     console::write_line(fi_temp.name());
      /// }
      ///
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// //
      /// // The following files exist in the current directory:
      /// // fileinfoname.exe
      /// // fileinfoname.pdb
      /// // newTemp.txt
      /// @endcode
      /// @remarks When first called, xtd::io::file_info calls Refresh and caches information about the file. On subsequent calls, you must call Refresh to get the latest copy of the information.
      /// @remarks The name of the file includes the file extension.
      xtd::ustring name() const override;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Creates a xtd::io::stream_writer that appends text to the file represented by this instance of the xtd::io::file_info.
      /// @return a new A new std::ofstream.
      /// @par Examplle
      /// The following example appends text to a file and reads from the file.
      /// @include file_info_append_text.cpp
      /// @par Examples
      /// The following example demonstrates appending text to the end of a file and also displays the result of the append operation to the console. The first time this routine is called, the file is created if it does not exist. After that, the specified text is appended to the file.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// /// public:
      ///   static auto main() {
      ///     file_info fi("temp.txt");
      ///      // Create a writer, ready to add entries to the file.
      ///     stream_writer sw = fi.append_text();
      ///     sw.write_line("Add as many lines as you like...");
      ///     sw.write_line("Add another line to the output...");
      ///     sw.flush();
      ///     sw.close();
      ///     // Get the information out of the file and display it.
      ///     // Remember that the file might have other lines if it already existed.
      ///     ifstream ifs(fi.open_read());
      ///     stream_reader sr(ifs);
      ///     while (sr.peek() != -1)
      ///       console::write_line(sr.read_line());
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      /// @endcode
      xtd::io::stream_writer append_text() const;
      
      /// @brief Copies an existing file to a new file, disallowing the overwriting of an existing file.
      /// @param desy_file_name The name of the new file to copy to.
      /// @return A new file with a fully qualified path.
      /// @exception xtd::argument_exception dest_file_name is empty, contains only white spaces, or contains invalid characters.
      /// @exception xtd::io_io_exception An error occurs, or the destination file already exists and overwrite is false.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::io::directory_not_found_exception The directory specified in dest_file_name does not exist.
      /// @exception xtd::unauthorized_access_exceptionA directory path is passed in, or the file is being moved to a different drive.
      /// @exception xtd::ioo::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::not_supported_exception dest_file_name contains a colon (:) in the middle of the string.
      /// @par Examples
      /// The following example demonstrates both overloads of the td::io::file_info::copy_to method.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     ustring path = R"(c:\SoureFile.txt)";
      ///     ustring path2 = R"(c:\NewFile.txt)";
      ///     file_info fi1(path);
      ///     file_info fi2(path2);
      ///
      ///     try {
      ///       // Create the source file.
      ///       using_(ofstream s(fi1.create())) {
      ///       }
      ///
      ///       //Ensure that the target file does not exist.
      ///       if (file::exists(path2)) {
      ///         fi2.remove();
      ///       }
      ///
      ///       //Copy the file.f
      ///    fi1.copy_to(path2);
      ///       console::write_line("{0} was copied to {1}.", path, path2);
      ///     } catch (const io_exception& ioex) {
      ///       console::write_line(ioex.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      /// @endcode
      /// @par Examples
      /// The following example demonstrates copying one file to another file, throwing an exception if the destination file already exists.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       // Create a reference to a file, which might or might not exist.
      ///       // If it does not exist, it is not yet created.
      ///       file_info fi("temp.txt");
      ///       // Create a writer, ready to add entries to the file.
      ///       ofstream ofs(fi.append_text());
      ///       stream_writer sw(ofs);
      ///       sw.write_line("Add as many lines as you like...");
      ///       sw.write_line("Add another line to the output...");
      ///       sw.flush();
      ///       sw.close();
      ///       // Get the information out of the file and display it.
      ///       ifstream ifs(fi.open_read());
      ///       stream_reader sr(ifs);
      ///       console::write_line("This is the information in the first file:");
      ///       while (sr.peek() != -1)
      ///         console::write_line(sr.read_line());
      ///       // Copy this file to another file. The file will not be overwritten if it already exists.
      ///       file_info newfi = fi.copy_to("newTemp.txt");
      ///       // Get the information out of the new file and display it.
      ///       ifs = newfi.open_read();
      ///       sr = stream_reader(ifs);
      ///       console::write_line("{0}This is the information in the second file:", environment::new_line());
      ///       while (sr.peek() != -1)
      ///         console::write_line(sr.read_line());
      ///     } catch(const system_exception& e) {
      ///       console::write_line(e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// //
      /// // This is the information in the first file:
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      ///
      /// // This is the information in the second file:
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      /// @endcode
      /// @remarks Use the xtd::io::file_info::copy_to(ustring, bool) method to allow overwriting of an existing file.
      /// @warning Whenever possible, avoid using short file names (such as XXXXXX~1.XXX) with this method. If two files have equivalent short file names then this method may fail and raise an exception and/or result in undesirable behavior
      xtd::io::file_info copy_to(const xtd::ustring& dest_file_name) const;
      /// @brief Copies an existing file to a new file, allowing the overwriting of an existing file.
      /// @param dest_file_name The name of the new file to copy to.
      /// @param overwrite true to allow an existing file to be overwritten; otherwise, false.
      /// @return A new file, or an overwrite of an existing file if overwrite is true. If the file exists and overwrite is false, an xtd::io::ioo_exception is thrown.
      /// @exception xtd::argument_exception dest_file_name is empty, contains only white spaces, or contains invalid characters.
      /// @exception xtd::io_io_exception An error occurs, or the destination file already exists and overwrite is false.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::io::directory_not_found_exception The directory specified in dest_file_name does not exist.
      /// @exception xtd::unauthorized_access_exceptionA directory path is passed in, or the file is being moved to a different drive.
      /// @exception xtd::ioo::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::not_supported_exception dest_file_name contains a colon (:) in the middle of the string.
      /// @par Examples
      /// The following example demonstrates both overloads of the td::io::file_info::copy_to method.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     ustring path = R"(c:\SoureFile.txt)";
      ///     ustring path2 = R"(c:\NewFile.txt)";
      ///     file_info fi1(path);
      ///     file_info fi2(path2);
      ///
      ///     try {
      ///       // Create the source file.
      ///       using_(ofstream s(fi1.create())) {
      ///       }
      ///
      ///       //Ensure that the target file does not exist.
      ///       if (file::exists(path2)) {
      ///         fi2.remove();
      ///       }
      ///
      ///       //Copy the file.f
      ///    fi1.copy_to(path2);
      ///       console::write_line("{0} was copied to {1}.", path, path2);
      ///     } catch (const io_exception& ioex) {
      ///       console::write_line(ioex.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      /// @endcode
      /// @par Examples
      /// The following example demonstrates copying one file to another file, throwing an exception if the destination file already exists.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Create a reference to a file, which might or might not exist.
      ///     // If it does not exist, it is not yet created.
      ///     file_info fi("temp.txt");
      ///     // Create a writer, ready to add entries to the file.
      ///     ofstream ofs(fi.append_text());
      ///     stream_writer sw(ofs);
      ///     sw.write_line("Add as many lines as you like...");
      ///     sw.write_line("Add another line to the output...");
      ///     sw.flush();
      ///     sw.close();
      ///     // Get the information out of the file and display it.
      ///     ifstream ifs(fi.open_read());
      ///     stream_reader sr(ifs);
      ///     console::write_line("This is the information in the first file:");
      ///     while (sr.peek() != -1)
      ///       console::write_line(sr.read_line());
      ///     // Copy this file to another file. The true parameter specifies that the file will be overwritten if it already exists.
      ///     file_info newfi = fi.copy_to("newTemp.txt", true);
      ///     // Get the information out of the new file and display it.
      ///     ifs = newfi.open_read();
      ///     sr = stream_reader(ifs);
      ///     console::write_line("{0}This is the information in the second file:", environment::new_line());
      ///     while (sr.peek() != -1)
      ///       console::write_line(sr.read_line());
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// //
      /// // This is the information in the first file:
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      ///
      /// // This is the information in the second file:
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      /// @endcode
      /// @remarks Use this method to allow or prevent overwriting of an existing file. Use the xtd::io::file_info::copy_to(ustring) method to prevent overwriting of an existing file by default.
      /// @warning Whenever possible, avoid using short file names (such as XXXXXX~1.XXX) with this method. If two files have equivalent short file names then this method may fail and raise an exception and/or result in undesirable behavior
      xtd::io::file_info copy_to(const xtd::ustring& dest_file_name, bool overwrite) const;
      
      /// @brief Creates a file.
      /// @return A new file.
      /// @par Examples
      /// The following example creates a reference to a file, and then creates the file on disk using xtd::io::file_info.create().
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Create a reference to a file.
      ///     file_info fi("temp.txt");
      ///     // Actually create the file.
      ///     ofstream ofs( fi.create());
      ///     // Modify the file as required, and then close the file.
      ///     ofs.close();
      ///     // Delete the file.
      ///     fi.remove();
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @par Examples
      /// The following example creates a file, adds some text to it, and reads from the file.
      /// @include file_info_open.cpp
      /// @remarks By default, full read/write access to new files is granted to all users.
      /// @remarks This method is a wrapper for the functionality provided by xtd::io::file::create.
      std::ofstream create() const;
      
      /// @brief Creates a std::ofstream that writes a new text file.
      /// @return A new std::ofstream.
      /// @exception xtd::unauthorized_access_exception The file name is a directory.
      /// @exception xtd::io::io_exception The disk is read-only.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @par Examples
      /// The following example demonstrates the xtd::io::file_info::create_text method.
      /// @include file_info_open_text.cpp
      /// @remarks By default, full read/write access to new files is granted to all users.
      xtd::io::stream_writer create_text() const;
      
      /// @brief Moves a specified file to a new location, providing the option to specify a new file name.
      /// @param dest_file_name The path to move the file to, which can specify a different file name.
      /// @exception xtd::io::io_exception An I/O error occurs, such as the destination file already exists or the destination device is not ready.
      /// @exception xtd::argument_exception dest_file_name is empty, contains only white spaces, or contains invalid characters.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::unauthorized_access_exception dest_file_name is read-only or is a directory.
      /// @exception xtd::io::file_not_found_exception The file is not found.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::not_supported_exception dest_file_name contains a colon (:) in the middle of the string.
      /// @par Examples
      /// The following example demonstrates moving a file to a different location and renaming the file.
      /// @include file_info_move_to.cpp
      /// @remarks This method works across disk volumes. For example, the file c:\MyFile.txt can be moved to d:\public and renamed NewFile.txt.
      /// @remarks This method does not overwrite the destination file if it already exists. For that purpose, call xtd::ioo::file_info::move_to(ustring, bool) instead.
      void move_to(const xtd::ustring& dest_file_name);
      
      /// @brief Moves a specified file to a new location, providing the options to specify a new file name and to overwrite the destination file if it already exists.
      /// @param dest_file_name The path to move the file to, which can specify a different file name.
      /// @param overwrite true to overwrite the destination file if it already exists; false otherwise.
      /// @exception xtd::io::io_exception An I/O error occurred, such as the destination device is not ready.
      /// @exception xtd::argument_exception dest_file_name is empty, contains only white spaces, or contains invalid characters.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::unauthorized_access_exception dest_file_name is read-only or is a directory.
      /// @exception xtd::io::file_not_found_exception The file is not found.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::not_supported_exception dest_file_name contains a colon (:) in the middle of the string.
      /// @par Examples
      /// The following example demonstrates moving a file to a different location and renaming the file.
      /// @include file_info_move_to.cpp
      /// @remarks This method works across disk volumes. For example, the file c:\MyFile.txt can be moved to d:\public and renamed NewFile.txt.
      void move_to(const xtd::ustring& dest_file_name, bool overwrite);
      
      /// @brief
      /// @param mode A std::ios::openmode constant specifying the mode (for example, std::ios::openmode::in or std::ios::openmode::app) in which to open the file.
      /// @return A file opened in the specified mode, with read/write access and unshared.
      /// @exception xtd::io::file_not_found_exception The file is not found.
      /// @exception xtd::unauthorized_access_exception The file is read-only or is a directory.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::io::io_exception The file is already open.
      /// @par Examples
      /// The following example opens a file, adds some information to the file, and reads the file.
      /// @include file_info_open.cpp
      std::fstream open(std::ios::openmode mode) const;
      
      /// @brief Creates a read-only std::ifstream.
      /// @return A new read-only std::ifstream.
      /// @exception xtd::unauthorized_access_exception name is read-only or is a directory.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::io::io_exception The file is already open.
      /// @par Examples
      /// The following example opens a file as read-only and reads from it.
      /// @include file_info_open_read.cpp
      /// @remarks This method returns a read-only std::ifstream object.
      std::ifstream open_read() const;
      
      /// @brief Creates a xtd::io::stream_reader that reads from an existing text file.
      /// @return A new xtd::io::stream_reader.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::io::file_not_found_exception The file is not found.
      /// @exception xtd::unauthorized_access_exception name is read-only or is a directory.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @par Examples
      /// The following example demonstrates the xtd::io::file_info::create_text method.
      /// @include file_info_open_text.cpp
      xtd::io::stream_reader open_text() const;
      
      /// @brief Creates a write-only std::ofstream.
      /// @return A write-only unshared std::ofstream object for a new or existing file.
      /// @exception xtd::unauthorized_access_exception The path specified when creating an instance of the xtd::io::file_info object is read-only or is a directory.
      /// @exception xtd::io::directory_not_found_exception The path specified when creating an instance of the xtd::io::file_info object is invalid, such as being on an unmapped drive.
      /// @par Examples
      /// The following example opens a file for writing and then reads from the file.
      /// @include file_info_open.cpp
      /// @return The xtd::io::file_info::open_write method opens a file if one already exists for the file path, or creates a new file if one does not exist. For an existing file, it does not append the new text to the existing text. Instead, it overwrites the existing characters with the new characters. If you overwrite a longer string (such as "This is a test of the open_write method") with a shorter string (like "Second run"), the file will contain a mix of the strings ("Second runtest of the open_write method").
      std::ofstream open_write() const;
      
      /// @brief Permanently deletes a file.
      /// @exception xtd::io::io_exception The target file is open or memory-mapped on a computer running Microsoft Windows NT.<br>-or-<br>There is an open handle on the file, and the operating system is Windows XP or earlier. This open handle can result from enumerating directories and files. For more information, see How to: Enumerate Directories and Files.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::unauthorized_access_exception The path is a directory.
      /// @par Examples
      /// The following example demonstrates the xtd::io::file_info::remove method.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     ustring path = R"(c:\MyTest.txt)";
      ///     file_info fi1(path);
      ///
      ///     try {
      ///       using_ (ofstream ofs = fi1.create_text()) {}
      ///       ustring path2 = path + "temp";
      ///       file_info fi2(path2);
      ///
      ///       //Ensure that the target does not exist.
      ///       fi2.remove();
      ///
      ///       //Copy the file.
      ///       fi1.copy_to(path2);
      ///       console::write_line("{0} was copied to {1}.", path, path2);
      ///
      ///       //Delete the newly created file.
      ///       fi2.remove();
      ///       console::write_line("{0} was successfully deleted.", path2);
      ///     } catch (const system_exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// //
      /// //c:\MyTest.txt was copied to c:\MyTest.txttemp.
      /// //c:\MyTest.txttemp was successfully deleted.
      /// @endcode
      /// @par Examples
      /// The following example creates, closes, and deletes a file.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Create a reference to a file.
      ///     file_info fi("temp.txt");
      ///     // Actually create the file.
      ///     ofstream ofs = fi.create();
      ///     // Modify the file as required, and then close the file.
      ///     ofs.close();
      ///     // Delete the file.
      ///     fi.remove();
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @remarks If the file does not exist, this method does nothing.
      void remove() const override;
      
      /// @brief Replaces the contents of a specified file with the file described by the current xtd::io::file_info object, deleting the original file, and creating a backup of the replaced file.
      /// @param destination_file_name The name of a file to replace with the current file.
      /// @param destination_backup_file_name The name of a file with which to create a backup of the file described by the destFileName parameter.
      /// @return A xtd::io::file_info object that encapsulates information about the file described by the destFileName parameter.
      /// @exception xtd::argument_exception The path described by the destFileName parameter was not of a legal form.<br>-or-<br>The path described by the destBackupFileName parameter was not of a legal form.
      /// @exception xtd::io::file_not_found_exception The file described by the current xtd::io::file_info object could not be found.<br>-or-<br>The file described by the destinationFileName parameter could not be found.
      /// @exception xtd::platform_not_supported_exception The current operating system is not Microsoft Windows NT or later.
      /// @par Examples
      /// The following example uses the xtd::io::file_info::replace method to replace a file with another file and create a backup of the replaced file.
      /// @include file_info_replace.cpp
      /// @remarks The Replace method replaces the contents of a specified file with the contents of the file described by the current xtd::io::file_info object. It also creates a backup of the file that was replaced. Finally, it returns a new xtd::io::file_info object that describes the overwritten file.
      /// @remarks Pass an empty string ("") to the dest_backup_file_name parameter if you do not want to create a backup of the file being replaced.
      file_info replace(const xtd::ustring& destination_file_name, const xtd::ustring& destination_backup_file_name);
      /// @}
      
    private:
      file_info() = default;
    };
  }
}
