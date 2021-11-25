/// @file
/// @brief Contains xtd::io::file_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "file_system_info.h"
#include <fstream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    class directory_info;
    /// @endcond
    
    /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::fstream objects.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @par Example
    /// The following example demonstrates some of the main members of the xtd::io::file_info class.
    /// When the properties are first retrieved, xtd::io::file_info calls the xtd::io::file_info::refresh method and caches information about the file. On subsequent calls, you must call xtd::io::file_info::refresh to get the latest copy of the information.
    /// @include file_info.cpp
    /// @remarks Use the xtd::io::file_info class for typical operations such as copying, moving, renaming, creating, opening, deleting, and appending to files.
    /// @remarks If you are performing multiple operations on the same file, it can be more efficient to use td::io::file_info instance methods instead of the corresponding static methods of thetd::io::file class, because a security check will not always be necessary.
    /// @remarks Many of the xtd::io::file_info methods return other I/O types when you create or open files. You can use these other types to further manipulate a file. For more information, see specific td::io::file_info members such as td::io::file_info::open, td::io::file_info::open_read, td::io::file_info::open_text, td::io::file_info::create_text, or td::io::file_info::create.
    /// @remarks By default, full read/write access to new files is granted to all users.
    class core_export_ file_info : public xtd::io::file_system_info {
    public:
      /// @brief Represents the uninitialized xtd::io::file_info object. This field is constant.
      static const file_info empty;
      
      /// @brief Initializes a new instance of the xtd::io::file_info class, which acts as a wrapper for a file path.
      /// @param file_name The fully qualified name of the new file, or the relative file name. Do not end the path with the directory separator character.
      /// @exception xtd:argument_exception The file name is empty, contains only white spaces, or contains invalid characters.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::unauthorized_access_exception Access to fileName is denied.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::not_supported_exception fileName contains a colon (:) in the middle of the string.
      /// @par Example
      /// The following example demonstrates some of the main members of the xtd::io::file_info class.
      /// When the properties are first retrieved, xtd::io::file_info calls the xtd::io::file_info::refresh method and caches information about the file. On subsequent calls, you must call xtd::io::file_info::refresh to get the latest copy of the information.
      /// @include file_info.cpp
      /// @remarks You can specify either the fully qualified or the relative file name, but the security check gets the fully qualified name.
      file_info(const xtd::ustring& file_name);
      
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
      /// @par Example
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
      /// @exception xtd::io::file_not_found_exception The file described by the current FileInfo object could not be found.
      /// @exception xtd::io::io_exception An I/O error occurred while opening the file.
      /// @exception xtd::unauthorized_access_exception This operation is not supported on the current platform. -or- The caller does not have the required permission.
      /// @exception xtd::argument_exception The user does not have write permission, but attempted to set this property to false.
      /// @par Example
      /// The following example uses the xtd::io::file_info::is_read_only property to mark a file as read only and then mark it as read-write.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
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
      ///     // Create a new FileInfo object.
      ///     file_info f_info(file_name);
      ///
      ///     // Set the IsReadOnly property.
      ///     f_info.is_read_only(set_read_only);
      ///   }
      ///
      ///   // Returns wether a file is read-only.
      ///   static bool is_file_read_only(const ustring& file_name) {
      ///     // Create a new FileInfo object.
      ///     file_info f_info(file_name);
      ///
      ///     // Return the IsReadOnly property value.
      ///     return f_info.is_read_only();
      ///   }
      /// };
      ///
      /// startup_(program);
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
      /// @exception xtd::io::file_not_found_exception The file described by the current FileInfo object could not be found.
      /// @exception xtd::io::io_exception An I/O error occurred while opening the file.
      /// @exception xtd::unauthorized_access_exception This operation is not supported on the current platform. -or- The caller does not have the required permission.
      /// @exception xtd::argument_exception The user does not have write permission, but attempted to set this property to false.
      /// @par Example
      /// The following example uses the xtd::io::file_info::is_read_only property to mark a file as read only and then mark it as read-write.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
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
      ///     // Create a new FileInfo object.
      ///     file_info f_info(file_name);
      ///
      ///     // Set the IsReadOnly property.
      ///     f_info.is_read_only(set_read_only);
      ///   }
      ///
      ///   // Returns wether a file is read-only.
      ///   static bool is_file_read_only(const ustring& file_name) {
      ///     // Create a new FileInfo object.
      ///     file_info f_info(file_name);
      ///
      ///     // Return the IsReadOnly property value.
      ///     return f_info.is_read_only();
      ///   }
      /// };
      ///
      /// startup_(program);
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
      /// @exception xtd::io::file_not_found_exception The file does not exist. -or- The xtd::io::file_info::size property is called for a directory.
      /// @par Example
      ///
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// int main() {
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
      /// //@endcode
      /// @remarks
      /// The value of the Length property is pre-cached if the current instance of the FileInfo object was returned from any of the following DirectoryInfo methods:
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
      /// @par Example
      ///
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// int main() {
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

      /// @brief Creates a std::ofstream that appends text to the file represented by this instance of the xtd::io::file_info.
      /// @return a new A new std::ofstream.
      /// @epar Examplle
      ///
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
      ///     file_info fi(R"(c:\MyTest.txt)");
      ///
      ///     // This text is added only once to the file.
      ///     if (!fi.exists())  {
      ///       //Create a file to write to.
      ///       using_ (ofstream s(fi.create_text())) {
      ///         stream_writer ws(s);
      ///         stream_writer sw(s);
      ///         sw.write_line("Hello");
      ///         sw.write_line("And");
      ///         sw.write_line("Welcome");
      ///       }
      ///     }
      ///
      ///     // This text will always be added, making the file longer over time
      ///     // if it is not deleted.
      ///     using_ (ofstream s = fi.append_text()) {
      ///       stream_writer sw(s);
      ///       sw.write_line("This");
      ///       sw.write_line("is Extra");
      ///       sw.write_line("Text");
      ///     }
      ///
      ///     //Open the file to read from.
      ///     using_ (ifstream s = fi.open_text()) {
      ///       stream_reader sr(s);
      ///       while (!sr.end_of_stream()) {
      ///         console::write_line(sr.read_line());
      ///       }
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program);
      ///
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// //
      /// // Hello
      /// // And
      /// /// // Welcome
      /// // This
      /// // is Extra
      /// // Text
      ///
      /// //When you run this application a second time, you will see the following output:
      /// //
      /// // Hello
      /// // And
      /// // Welcome
      /// // This
      /// // is Extra
      /// /// // Text
      /// // This
      /// // is Extra
      /// // Text
      /// @endcode
      /// @par Example
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
      ///   static void main() {
      ///     file_info fi("temp.txt");
      ///      // Create a writer, ready to add entries to the file.
      ///     ofstream ofs(fi.append_text());
      ///     stream_writer sw(ofs);
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
      /// startup_(program);
      ///
      /// // This code produces output similar to the following;
      /// // results may vary based on the computer/file structure/etc.:
      /// // Add as many lines as you like...
      /// // Add another line to the output...
      /// @encoode
      std::ofstream append_text() const;

      xtd::io::file_info copy_to(const xtd::ustring& dest_file_name) const;
      
      xtd::io::file_info copy_to(const xtd::ustring& dest_file_name, bool overwrite) const;
      
      std::ofstream create() const;
      
      std::ofstream create_text() const;
      
      void move_to(const xtd::ustring& dest_file_name);
      
      void move_to(const xtd::ustring& dest_file_name, bool overwrite);
      
      std::fstream open(std::ios::openmode mode) const;
      
      std::ifstream open_read() const;

      std::ifstream open_text() const;
      
      std::ofstream open_write() const;

      void remove() const override;
      
      void replace(const xtd::ustring& destination_file_name, const xtd::ustring& destination_backup_file_name);

    private:
      file_info() = default;
    };
  }
}
