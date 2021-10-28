/// @file
/// @brief Contains xtd::io::directory class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include "../core_export.h"
#include "../static.h"
#include "directory_info.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Exposes static methods for creating, moving, and enumerating through directories and subdirectories. This class cannot be inherited.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @par Example
    /// The following example shows how to retrieve all the text files from a directory and move them to a new directory. After the files are moved, they no longer exist in the original directory.
    /// @code
    /// #include <xtd/xtd>
    ///
    /// using namespace xtd;
    /// using namespace xtd::io;
    ///
    /// class program {
    /// public:
    ///   static void main() {
    ///     ustring source_directory = R"(C:\current)";
    ///     ustring archive_directory = R"(C:\archive)";
    ///
    ///     try {
    ///       auto txt_files = directory::enumerate_files(source_directory, "*.txt");
    ///
    ///       for (ustring current_file : txt_files) {
    ///         ustring file_name = current_file.substring(source_directory.size() + 1);
    ///         directory::move(current_file, path::combine(archive_directory, file_name));
    ///       }
    ///     } catch (system_exception& e) {
    ///       console::write_line(e.message());
    ///     }
    ///   }
    /// };
    ///
    /// startup_(program);
    /// @endcode
    /// @par Example
    /// The following example demonstrates how to move a directory and all its files to a new directory. The original directory no longer exists after it has been moved.
    /// @code
    /// #include <xtd/xtd>
    ///
    /// using namespace xtd;
    /// using namespace xtd::io;
    ///
    /// class program {
    /// public:
    ///   static void main() {
    ///     ustring source_directory = R"(C:\source)";
    ///     ustring destination_directory = R"(C:\destination)";
    ///
    ///     try {
    ///       directory::move(source_directory, destination_directory);
    ///     } catch (const system_exception& e) {
    ///       console::write_line(e.message());
    ///     }
    ///   }
    /// };
    ///
    /// startup_(program);
    /// @endcode
    /// @remarks Use the xtd::io::directory class for typical operations such as copying, moving, renaming, creating, and deleting directories.
    /// * To create a directory, use one of the xtd::io::directory::create_directory methods.
    /// * To delete a directory, use one of the xtd::io::directory::remove methods.
    /// * To get or set the current directory for an app, use the xtd::io::directory::get_current_directory or xtd::io::directory::set_current_directory method.
    /// * To manipulate date/time information related to the creation, access, and writing of a directory, use methods such as xtd::io::directory::set_last_access_time and xtd::io::directory::set_creation_time.
    /// @remarks The static methods of the xtd::io::directory class perform security checks on all methods. If you are going to reuse an object several times, consider using the corresponding instance method of xtd::io::directory_info instead, because the security check will not always be necessary.
    /// @remarks If you are performing only one directory-related action, it might be more efficient to use a static xtd::io::directory method rather than a corresponding xtd::io::directory_info instance method. Most xtd::io::directory methods require the path to the directory that you are manipulating.
    /// @note In members that accept a string path parameter, that path must be well-formed or an exception is raised. For example, if a path is fully qualified but begins with a space (" c:\temp"), the path string isn't trimmed, so the path is considered malformed and an exception is raised. In addition, a path or a combination of paths cannot be fully qualified twice. For example, "c:\temp c:\windows" also raises an exception. Ensure that your paths are well-formed when using methods that accept a path string. For more information see xtd::io::path.
    /// @remarks In members that accept a path, the path can refer to a file or a directory. You can use a full path, a relative path, or a Universal Naming Convention (UNC) path for a server and share name. For example, all the following are acceptable paths:
    /// * "c:\\MyDir".
    /// * "MyDir\\MySubdir".
    /// * "\\\\MyServer\\MyShare".
    /// To demand permissions for a directory and all its subdirectories, end the path string with the directory separator character. (For example, "C:\Temp\" grants access to C:\Temp\ and all its subdirectories.) To demand permissions only for a specific directory, end the path string with a period. (For example, "C:\Temp\." grants access only to C:\Temp\, not to its subdirectories.)
    /// In members that accept a search_pattern parameter, the search string can be any combination of literal characters and two wildcard characters; * and ?. This parameter does not recognize regular expressions. For more information, see the xtd::io::directory::enumerate_directories(ustring, ustring) method or any other method that uses the search_pattern parameter.
    /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
    /// @remarks xtd::io::directory and xtd::io::directory_info are not supported for use in Windows Store apps. For information about how to access files and folders in Windows Store apps, see <a href=https://msdn.microsoft.com/library/windows/apps/hh758319.aspx>Accessing data and files (Windows Store apps)</a>.
    class core_export_ directory static_ {
    public:
      /// @brief Represent directory iterator used by xtd::io::directory.
      class directory_iterator : public std::iterator<std::input_iterator_tag, xtd::ustring> {
        explicit directory_iterator(const xtd::ustring& path, const xtd::ustring& pattern);
      public:
        /// @cond
        directory_iterator();
        directory_iterator(const directory_iterator&) = default;
        directory_iterator(directory_iterator&&) = default;
        
        directory_iterator& operator++();
        directory_iterator operator++(int);
        bool operator==(directory_iterator other) const;
        bool operator!=(directory_iterator other) const {return !operator==(other);}
        value_type operator*() const;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        struct data;
        std::shared_ptr<data> data_;
      };
      
      /// @brief Represent file iterator used by xtd::io::directory.
      class file_iterator : public std::iterator<std::input_iterator_tag, xtd::ustring> {
        explicit file_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        file_iterator();
        file_iterator(const file_iterator&) = default;
        file_iterator(file_iterator&&) = default;
        
        file_iterator& operator++();
        file_iterator operator++(int);
        bool operator==(file_iterator other) const;
        bool operator!=(file_iterator other) const {return !operator==(other);}
        value_type operator*() const;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        struct data;
        std::shared_ptr<data> data_;
      };
      
      /// @brief Represent file system iterator used by xtd::io::directory.
      class file_system_entry_iterator : public std::iterator<std::input_iterator_tag, xtd::ustring> {
        explicit file_system_entry_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        file_system_entry_iterator();
        file_system_entry_iterator(const file_system_entry_iterator&) = default;
        file_system_entry_iterator(file_system_entry_iterator&&) = default;
        
        file_system_entry_iterator& operator++();
        file_system_entry_iterator operator++(int);
        bool operator==(file_system_entry_iterator other) const;
        bool operator!=(file_system_entry_iterator other) const {return !operator==(other);}
        value_type operator*() const;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        struct data;
        std::shared_ptr<data> data_;
      };

      /// @brief Creates all directories and subdirectories in the specified path unless they already exist.
      /// @param path The directory to create.
      /// @return An object that represents the directory at the specified path. This object is returned regardless of whether a directory at the specified path already exists.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xttd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_excpetion The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Example
      /// The following example creates and deletes the specified directory:
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
      ///     // Specify the directories you want to manipulate.
      ///     directory_info di("c:\\MyDir");
      ///     try {
      ///       // Determine whether the directory exists.
      ///       if (di.exists()) {
      ///         // Indicate that the directory already exists.
      ///         console::write_line("That path exists already.");
      ///         return;
      ///       }
      ///
      ///       // Try to create the directory.
      ///       di.create();
      ///       console::write_line("The directory was created successfully.");
      ///
      ///       // Delete the directory.
      ///       di.remove();
      ///       console::write_line("The directory was deleted successfully.");
      ///     }
      ///     catch (const system_exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program);
      /// @endcode
      /// @par Example
      /// To create the directory C:\Users\User1\Public\Html when the current directory is C:\Users\User1, use any of the following calls to ensure that the backslash is interpreted properly:
      /// @code
      /// directory::create_directory("Public\\Html");
      /// directory::create_directory("\\Users\\User1\\Public\\Html");
      /// directory::create_directory("c:\\Users\\User1\\Public\\Html");
      /// @endcode
      /// @remarks Any and all directories specified in path are created, unless they already exist or unless some part of path is invalid. If the directory already exists, this method does not create a new directory, but it returns a DirectoryInfo object for the existing directory.
      /// @remarks The path parameter specifies a directory path, not a file path.
      /// @remarks Trailing spaces are removed from the end of the path parameter before creating the directory.
      /// @remarks Creating a directory with only the colon character (:) is not supported, and will cause a not_supported_exception to be thrown.
      /// @remarks On Unix systems, use a forward slash (/) as path separator.
      static xtd::io::directory_info create_directory(const xtd::ustring& path);
      
      /// @brief Returns an enumerable collection of directory full names in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @return An xtd::io::directory::directory_iterator of the full names (including paths) for the directories in the directory specified by path.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xttd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_excpetion The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par rExample
      /// The following example enumerates the top-level directories in a specified path.
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
      ///     try {
      ///       // Set a variable to the My Documents path.
      ///       ustring doc_path = environment::get_folder_path(environment::special_folder::my_documents);
      ///
      ///       vector<ustring> dirs(begin(directory::enumerate_directories(doc_path)), end(directory::enumerate_directories(doc_path)));
      ///
      ///       for (auto dir : dirs) {
      ///         console::write_line("{}", dir.substring(dir.last_index_of(path::directory_separator_char()) + 1));
      ///       }
      ///       console::write_line("{} directories found.", dirs.size());
      ///     } catch (const unauthorized_access_exception& ex) {
      ///       console::write_line(ex.message());
      ///     } catch (const path_too_long_exception& ex) {
      ///       console::write_line(ex.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program);
      /// @endcode
      /// @remarks You can specify relative or absolute path information in the path parameter. Relative path information is interpreted as relative to the current working directory, which you can determine by using the xtd::io::directory::get_current_directory method. The returned directory names are prefixed with the value you provided in the path parameter. For example, if you provide a relative path in the path parameter, the returned directory names will contain a relative path.
      /// @remarks The xtd::io::directory::enumerate_directories and xtd::io::directory::get_directories methods differ as follows: When you use xtd::io::directory::enumerate_directories, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_directories, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_directories can be more efficient.
      /// @remarks The returned collection is not cached; each call to the xtd::io::directory::get_enumerator on the collection will start a new enumeration.
      static xtd::io::directory::directory_iterator enumerate_directories(const xtd::ustring& path);
      /// @brief Returns an enumerable collection of directory full names that match a search pattern in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @param search_pattern The search string to match against the names of directories in path. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An xtd::io::directory::directory_iterator of the full names (including paths) for the directories in the directory specified by path and that match the specified search pattern.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xttd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_excpetion The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par rExample
      /// The following example enumerates the top-level directories in a specified path that match a specified search pattern.
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
      ///     try {
      ///       ustring dir_path = R"(\\archives\2009\reports)";
      ///
      ///       // Create a List collection.
      ///       auto dirs = vector<ustring>(begin(directory::enumerate_directories(dir_path, "dv_*")), end(directory::enumerate_directories(dir_path, "dv_*")));
      ///
      ///       // Show results.
      ///       for (auto dir : dirs) {
      ///         // Remove path information from string.
      ///         console::write_line("{0}", dir.substring(dir.last_index_of("\\") + 1));
      ///       }
      ///       console::write_line("{0} directories found.", dirs.size());
      ///     } catch (const unauthorized_access_exception& ex) {
      ///       console::write_line(ex.message());
      ///     } catch (const path_too_long_exception& ex) {
      ///       console::write_line(ex.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program);
      /// @endcode
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// |--------------------|-------------------------------------------|
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the search_pattern string "*t" searches for all names in path ending with the letter "t". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks search_pattern cannot end in two periods ("..") or contain two periods ("..") followed by xtd::io::path::directory_separator_char or xtd::io::path::alt_directory_separator_char, nor can it contain any invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @remarks You can specify relative or absolute path information in the path parameter. Relative path information is interpreted as relative to the current working directory, which you can determine by using the xtd::io::directory::get_current_directory method. The returned directory names are prefixed with the value you provided in the path parameter. For example, if you provide a relative path in the path parameter, the returned directory names will contain a relative path.
      /// @remarks The xtd::io::directory::enumerate_directories and xtd::io::directory::get_directories methods differ as follows: When you use xtd::io::directory::xtd::io::directory::enumerate_directories, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_directories, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_directories can be more efficient.
      /// @remarks The returned collection is not cached; each call to the xtd::io::directory::get_enumerator on the collection will start a new enumeration.
      static xtd::io::directory::directory_iterator enumerate_directories(const xtd::ustring& path, const xtd::ustring& search_pattern);
      
      /// @brief Returns an enumerable collection of full file names in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      static xtd::io::directory::file_iterator enumerate_files(const xtd::ustring& path);
      static xtd::io::directory::file_iterator enumerate_files(const xtd::ustring& path, const xtd::ustring& search_pattern);
      
      static xtd::io::directory::file_system_entry_iterator enumerate_file_system_entries(const xtd::ustring& path);
      static xtd::io::directory::file_system_entry_iterator enumerate_file_system_entries(const xtd::ustring& path, const xtd::ustring& search_pattern);
      
      static bool exists(const xtd::ustring& path);
      
      static std::chrono::system_clock::time_point get_creation_time(const xtd::ustring& path);
      
      static xtd::ustring get_current_directory();

      static std::vector<xtd::ustring> get_directories(const xtd::ustring& path);
      static std::vector<xtd::ustring> get_directories(const xtd::ustring& path, const xtd::ustring& search_pattern);

      static xtd::ustring get_directory_root(const xtd::ustring& path);

      static std::vector<xtd::ustring> get_files(const xtd::ustring& path);
      static std::vector<xtd::ustring> get_files(const xtd::ustring& path, const xtd::ustring& search_pattern);
      
      static std::vector<xtd::ustring> get_file_system_entries(const xtd::ustring& path);
      static std::vector<xtd::ustring> get_file_system_entries(const xtd::ustring& path, const xtd::ustring& search_pattern);
      
      static std::chrono::system_clock::time_point get_last_access_time(const xtd::ustring& path);
      
      static std::chrono::system_clock::time_point get_last_write_time(const xtd::ustring& path);
      
      static std::vector<xtd::ustring> get_logical_drives();

      static xtd::io::directory_info get_parent(const xtd::ustring& path);

      static void move(const xtd::ustring& src, const xtd::ustring& dst);
      
      /// @brief Deletes an empty directory from a specified path.
      /// @param path The name of the empty directory to remove. This directory must be writable and empty.
      /// @exception xtd::io::io_exception A file with the same name and location specified by path exists. -or- The directory is the application's current working directory. -or- The directory specified by path is not empty. -or- The directory is read-only or contains a read-only file. -or- The directory is being used by another process.
      static void remove(const xtd::ustring& path);

      static void remove(const xtd::ustring& path, bool recursive);
    };
  }
}

/// @cond
namespace std {
  inline xtd::io::directory::directory_iterator begin(xtd::io::directory::directory_iterator it) {return it;}
  inline xtd::io::directory::directory_iterator end(xtd::io::directory::directory_iterator it) {return xtd::io::directory::directory_iterator();}
  inline xtd::io::directory::file_iterator begin(xtd::io::directory::file_iterator it) {return it;}
  inline xtd::io::directory::file_iterator end(xtd::io::directory::file_iterator it) {return xtd::io::directory::file_iterator();}
  inline xtd::io::directory::file_system_entry_iterator begin(xtd::io::directory::file_system_entry_iterator it) {return it;}
  inline xtd::io::directory::file_system_entry_iterator end(xtd::io::directory::file_system_entry_iterator it) {return xtd::io::directory::file_system_entry_iterator();}
}
/// @endcond
