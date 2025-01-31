/// @file
/// @brief Contains xtd::io::directory class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "directory_info.hpp"
#include "../core_export.hpp"
#include "../date_time.hpp"
#include "../iequatable.hpp"
#include "../static.hpp"
#include <tuple>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Exposes static methods for creating, moving, and enumerating through directories and subdirectories. This class cannot be inherited.
    /// ```cpp
    /// class core_export_ directory static_
    /// ```
    /// @par Inheritance
    /// xtd::static_object → xtd::io::directory
    /// @par Header
    /// ```cpp
    /// #include <xtd/io/directory>
    /// ```
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @par Examples
    /// The following example shows how to retrieve all the text files from a directory and move them to a new directory. After the files are moved, they no longer exist in the original directory.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// using namespace xtd;
    /// using namespace xtd::io;
    ///
    /// class program {
    /// public:
    ///   static auto main() {
    ///     string source_directory = R"(C:\current)";
    ///     string archive_directory = R"(C:\archive)";
    ///
    ///     try {
    ///       auto txt_files = directory::enumerate_files(source_directory, "*.txt");
    ///
    ///       for (string current_file : txt_files) {
    ///         string file_name = current_file.substring(source_directory.size() + 1);
    ///         directory::move(current_file, path::combine(archive_directory, file_name));
    ///       }
    ///     } catch (exception& e) {
    ///       console::write_line(e.message());
    ///     }
    ///   }
    /// };
    ///
    /// startup_(program::main);
    /// ```
    /// @par Examples
    /// The following example demonstrates how to move a directory and all its files to a new directory. The original directory no longer exists after it has been moved.
    /// ```cpp
    /// #include <xtd/xtd>
    ///
    /// using namespace xtd;
    /// using namespace xtd::io;
    ///
    /// class program {
    /// public:
    ///   static auto main() {
    ///     string source_directory = R"(C:\source)";
    ///     string destination_directory = R"(C:\destination)";
    ///
    ///     try {
    ///       directory::move(source_directory, destination_directory);
    ///     } catch (const exception& e) {
    ///       console::write_line(e.message());
    ///     }
    ///   }
    /// };
    ///
    /// startup_(program::main);
    /// ```
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
    /// @remarks By default, full read/write access to new directories is granted to all users. However, the app must have the correct security to access existing directories.
    /// @remarks To demand permissions for a directory and all its subdirectories, end the path string with the directory separator character. (For example, "C:\Temp\" grants access to C:\Temp\ and all its subdirectories.) To demand permissions only for a specific directory, end the path string with a period. (For example, "C:\Temp\." grants access only to C:\Temp\, not to its subdirectories.)
    /// @remarks In members that accept a search_pattern parameter, the search string can be any combination of literal characters and two wildcard characters; * and ?. This parameter does not recognize regular expressions. For more information, see the xtd::io::directory::enumerate_directories(string, string) method or any other method that uses the search_pattern parameter.
    /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
    /// @remarks xtd::io::directory and xtd::io::directory_info are not supported for use in Windows Store apps. For information about how to access files and folders in Windows Store apps, see [Accessing data and files (Windows Store apps)](https://msdn.microsoft.com/library/windows/apps/hh758319.aspx).
    class core_export_ directory static_ {
    public:
      /// @brief Represent directory iterator used by xtd::io::directory.
      class directory_iterator : public xtd::iequatable<directory_iterator> {
        struct data;
        
        explicit directory_iterator(const xtd::string& path, const xtd::string& pattern);
      public:
        /// @cond
        using iterator_category = std::input_iterator_tag;
        using value_type = xtd::string;
        using difference_type = xtd::string;
        using pointer = xtd::string*;
        using reference = xtd::string&;
        
        directory_iterator();
        directory_iterator(const directory_iterator&) = default;
        directory_iterator(directory_iterator&&) = default;
        
        directory_iterator& operator ++();
        directory_iterator operator ++(int32);
        value_type operator *() const;
        xtd::io::directory::directory_iterator begin() const;
        xtd::io::directory::directory_iterator end() const;
        bool equals(const directory_iterator& other) const noexcept override;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        
        xtd::sptr<data> data_;
      };
      
      /// @brief Represent file iterator used by xtd::io::directory.
      class file_iterator : public xtd::iequatable<file_iterator> {
        struct data;
        
        explicit file_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        using iterator_category = std::input_iterator_tag;
        using value_type = xtd::string;
        using difference_type = xtd::string;
        using pointer = xtd::string*;
        using reference = xtd::string&;
        
        file_iterator();
        file_iterator(const file_iterator&) = default;
        file_iterator(file_iterator&&) = default;
        
        file_iterator& operator ++();
        file_iterator operator ++(int);
        value_type operator *() const;
        xtd::io::directory::file_iterator begin() const;
        xtd::io::directory::file_iterator end() const;
        bool equals(const file_iterator& other) const noexcept override;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        
        xtd::sptr<data> data_;
      };
      
      /// @brief Represent file system iterator used by xtd::io::directory.
      class file_system_entry_iterator : public xtd::iequatable<file_system_entry_iterator> {
        struct data;
        
        explicit file_system_entry_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        using iterator_category = std::input_iterator_tag;
        using value_type = xtd::string;
        using difference_type = xtd::string;
        using pointer = xtd::string*;
        using reference = xtd::string&;
        
        file_system_entry_iterator();
        file_system_entry_iterator(const file_system_entry_iterator&) = default;
        file_system_entry_iterator(file_system_entry_iterator&&) = default;
        
        file_system_entry_iterator& operator ++();
        file_system_entry_iterator operator ++(int32);
        value_type operator *() const;
        xtd::io::directory::file_system_entry_iterator begin() const;
        xtd::io::directory::file_system_entry_iterator end() const;
        bool equals(const file_system_entry_iterator& other) const noexcept override;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        
        xtd::sptr<data> data_;
      };
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Creates all directories and subdirectories in the specified path unless they already exist.
      /// @param path The directory to create.
      /// @return An object that represents the directory at the specified path. This object is returned regardless of whether a directory at the specified path already exists.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example creates and deletes the specified directory:
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
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
      ///     catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @par Examples
      /// To create the directory C:\Users\User1\Public\Html when the current directory is C:\Users\User1, use any of the following calls to ensure that the backslash is interpreted properly:
      /// ```cpp
      /// directory::create_directory("Public\\Html");
      /// directory::create_directory("\\Users\\User1\\Public\\Html");
      /// directory::create_directory("c:\\Users\\User1\\Public\\Html");
      /// ```
      /// @remarks Any and all directories specified in path are created, unless they already exist or unless some part of path is invalid. If the directory already exists, this method does not create a new directory, but it returns a DirectoryInfo object for the existing directory.
      /// @remarks The path parameter specifies a directory path, not a file path.
      /// @remarks Trailing spaces are removed from the end of the path parameter before creating the directory.
      /// @remarks Creating a directory with only the colon character (:) is not supported, and will cause a not_supported_exception to be thrown.
      /// @remarks On Unix systems, use a forward slash (/) as path separator.
      static xtd::io::directory_info create_directory(const xtd::string& path);
      
      /// @brief Returns an enumerable collection of directory full names in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @return An xtd::io::directory::directory_iterator of the full names (including paths) for the directories in the directory specified by path.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par rExample
      /// The following example enumerates the top-level directories in a specified path.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       // Set a variable to the My Documents path.
      ///       string doc_path = environment::get_folder_path(environment::special_folder::my_documents);
      ///
      ///       list<string> dirs(begin(directory::enumerate_directories(doc_path)), end(directory::enumerate_directories(doc_path)));
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
      /// startup_(program::main);
      /// ```
      /// @remarks You can specify relative or absolute path information in the path parameter. Relative path information is interpreted as relative to the current working directory, which you can determine by using the xtd::io::directory::get_current_directory method. The returned directory names are prefixed with the value you provided in the path parameter. For example, if you provide a relative path in the path parameter, the returned directory names will contain a relative path.
      /// @remarks The xtd::io::directory::enumerate_directories and xtd::io::directory::get_directories methods differ as follows: When you use xtd::io::directory::enumerate_directories, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_directories, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_directories can be more efficient.
      static xtd::io::directory::directory_iterator enumerate_directories(const xtd::string& path);
      /// @brief Returns an enumerable collection of directory full names that match a search pattern in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @param search_pattern The search string to match against the names of directories in path. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An xtd::io::directory::directory_iterator of the full names (including paths) for the directories in the directory specified by path and that match the specified search pattern.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par rExample
      /// The following example enumerates the top-level directories in a specified path that match a specified search pattern.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       string dir_path = R"(\\archives\2009\reports)";
      ///
      ///       // Create a List collection.
      ///       auto dirs = list<string>(begin(directory::enumerate_directories(dir_path, "dv_*")), end(directory::enumerate_directories(dir_path, "dv_*")));
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
      /// startup_(program::main);
      /// ```
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the search_pattern string "*t" searches for all names in path ending with the letter "t". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks search_pattern cannot end in two periods ("..") or contain two periods ("..") followed by xtd::io::path::directory_separator_char or xtd::io::path::alt_directory_separator_char, nor can it contain any invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @remarks You can specify relative or absolute path information in the path parameter. Relative path information is interpreted as relative to the current working directory, which you can determine by using the xtd::io::directory::get_current_directory method. The returned directory names are prefixed with the value you provided in the path parameter. For example, if you provide a relative path in the path parameter, the returned directory names will contain a relative path.
      /// @remarks The xtd::io::directory::enumerate_directories and xtd::io::directory::get_directories methods differ as follows: When you use xtd::io::directory::xtd::io::directory::enumerate_directories, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_directories, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_directories can be more efficient.
      static xtd::io::directory::directory_iterator enumerate_directories(const xtd::string& path, const xtd::string& search_pattern);
      
      /// @brief Returns an enumerable collection of full file names in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @return An xtd::io::directory::directory_iterator of the full names (including paths) for the files in the directory specified by path.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example shows how to retrieve all the text files from a directory and move them to a new directory. After the files are moved, they no longer exist in the original directory.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     string source_directory = R"(C:\current)";
      ///     string archive_directory = R"(C:\archive)";
      ///
      ///     try {
      ///       auto txt_files = directory::enumerate_files(source_directory);
      ///
      ///       for (string current_file : txt_files) {
      ///         string file_name = current_file.substring(source_directory.size() + 1);
      ///         directory::move(current_file, path::combine(archive_directory, file_name));
      ///       }
      ///     } catch (exception& e) {
      ///       console::write_line(e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks You can specify relative path information with the path parameter. Relative path information is interpreted as relative to the current working directory, which you can determine by using the xtd::io::directory::get_current_directory method.
      /// @remarks The xtd::io::directory::enumerate_files and xtd::io::directory::get_files methods differ as follows: When you use xtd::io::directory::enumerate_files, you can start enumerating the collection of names before the whole collection is returned. When you use xtd::io::directory::get_files, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_files can be more efficient.
      static xtd::io::directory::file_iterator enumerate_files(const xtd::string& path);
      /// @brief Returns an enumerable collection of full file names that match a search pattern in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @param search_pattern The search string to match against the names of files in path. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An xtd::io::directory::directory_iterator of the full names (including paths) for the files in the directory specified by path and that match the specified search pattern.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example shows how to retrieve all the text files from a directory and move them to a new directory. After the files are moved, they no longer exist in the original directory.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     string source_directory = R"(C:\current)";
      ///     string archive_directory = R"(C:\archive)";
      ///
      ///     try {
      ///       auto txt_files = directory::enumerate_files(source_directory, "*.txt");
      ///
      ///       for (string current_file : txt_files) {
      ///         string file_name = current_file.substring(source_directory.size() + 1);
      ///         directory::move(current_file, path::combine(archive_directory, file_name));
      ///       }
      ///     } catch (exception& e) {
      ///       console::write_line(e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in searchPattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// Characters other than the wildcard are literal characters. For example, the search_pattern string "*t" searches for all names in path ending with the letter "t". The search_attern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks search_pattern cannot end in two periods ("..") or contain two periods ("..") followed by xtd::io::path::directory_separator_char or xtd::ioo::path::alt_directory_separator_char, nor can it contain any invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @remarks You can specify relative path information with the path parameter. Relative path information is interpreted as relative to the current working directory, which you can determine by using the xtd::io::directory::get_current_directory method.
      /// @remarks The xtd::io::directory::enumerate_files and xtd::io::directory::get_files methods differ as follows: When you use xtd::io::directory::enumerate_files, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_files, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_files can be more efficient.
      static xtd::io::directory::file_iterator enumerate_files(const xtd::string& path, const xtd::string& search_pattern);
      
      /// @brief Returns an enumerable collection of file names and directory names in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @return An xtd::io::directory::file_system_entry_iterator of file-system entries in the directory specified by path.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @remarks You can specify relative path information with the path parameter. Relative path information is interpreted as relative to the current working directory, which you can determine by using the xtd::io::directory::get_current_directory method.
      /// @remarks The xtd::io::directory::enumerate_file_system_entries and xtd::io::directory::get_file_system_entries methods differ as follows: When you use xtd::io::directory::enumerate_file_system_entries, you can start enumerating the collection of entries before the whole collection is returned; when you use xtd::io::directory::get_file_system_entries, you must wait for the whole array of entries to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_files_system_entires can be more efficient.
      static xtd::io::directory::file_system_entry_iterator enumerate_file_system_entries(const xtd::string& path);
      /// @brief Returns an enumerable collection of file names and directory names that match a search pattern in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @param serach_pattern The search string to match against the names of file-system entries in path. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An xtd::io::directory::file_system_entry_iterator of file-system entries in the directory specified by path and that match the specified search pattern.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in searchPattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// Characters other than the wildcard are literal characters. For example, the search_pattern string "*t" searches for all names in path ending with the letter "t". The search_attern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks search_pattern cannot end in two periods ("..") or contain two periods ("..") followed by xtd::io::path::directory_separator_char or xtd::ioo::path::alt_directory_separator_char, nor can it contain any invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @remarks You can specify relative path information with the path parameter. Relative path information is interpreted as relative to the current working directory, which you can determine by using the xtd::io::directory::get_current_directory method.
      /// @remarks The xtd::io::directory::enumerate_file_system_entries and xtd::io::directory::get_file_system_entries methods differ as follows: When you use xtd::io::directory::enumerate_file_system_entries, you can start enumerating the collection of entries before the whole collection is returned; when you use xtd::io::directory::get_file_system_entries, you must wait for the whole array of entries to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_file_system_entries can be more efficient.
      static xtd::io::directory::file_system_entry_iterator enumerate_file_system_entries(const xtd::string& path, const xtd::string& search_pattern);
      
      /// @brief Determines whether the given path refers to an existing directory on disk.
      /// @param path The path to test.
      /// @return `true` if path refers to an existing directory; `false` if the directory does not exist or an error occurs when trying to determine if the specified directory exists.
      /// @par rExample
      /// The following example takes an array of file or directory names on the command line, determines what kind of name it is, and processes it appropriately.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main(const list<string>& args) {
      ///     for (string path : args) {
      ///       if (file::exists(path)) {
      ///         // This path is a file
      ///         process_file(path);
      ///       } else if(directory::exists(path)) {
      ///         // This path is a directory
      ///         process_directory(path);
      ///       } else {
      ///         console::write_line("{0} is not a valid file or directory.", path);
      ///       }
      ///     }
      ///   }
      ///
      ///   // Process all files in the directory passed in, recurse on any directories
      ///   // that are found, and process the files they contain.
      ///   static void process_directory(const string& target_directory) {
      ///     // Process the list of files found in the directory.
      ///     list<string> file_entries = directory::get_files(target_directory);
      ///     for (string file_name : file_entries)
      ///       process_file(file_name);
      ///
      ///     // Recurse into subdirectories of this directory.
      ///     list<string> subdirectory_entries = directory::get_directories(target_directory);
      ///     for (string subdirectory : subdirectory_entries)
      ///       process_directory(subdirectory);
      ///   }
      ///
      ///   // Insert logic for processing found files here.
      ///   static void process_file(const string& path) {
      ///     console::write_line("Processed file '{0}'.", path);
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory.
      /// @remarks Trailing spaces are removed from the end of the path parameter before checking whether the directory exists.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks If you do not have at a minimum read-only permission to the directory, the Exists method will return `false`.
      /// @remarks The xtd::io::directory::exists method returns `false` if any error occurs while trying to determine if the specified file exists. This can occur in situations that raise exceptions such as passing a file name with invalid characters or too many characters, a failing or missing disk, or if the caller does not have permission to read the file.
      static bool exists(const xtd::string& path);
      
      /// @brief Gets the creation date and time of a directory.
      /// @param path The path of the directory.
      /// @return A xtd::date::time class that is set to the creation date and time for the specified directory. This value is expressed in local time.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      ///
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      /// The following example gets the creation time of the specified directory.
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       // Get the creation time of a well-known directory.
      ///       date_time dt = directory::get_creation_time(environment::current_directory());
      ///       ///
      ///       // Give feedback to the user.
      ///       if (date_time::now().subtract(dt).total_days() > 364) {
      ///         console::write_line("This directory is over a year old.");
      ///       } else if (date_time::now().subtract(dt).total_days() > 30) {
      ///         console::write_line("This directory is over a month old.");
      ///       } else if (date_time::now().subtract(dt).total_days() <= 1) {
      ///         console::write_line("This directory is less than a day old.");
      ///       } else {
      ///         console::write_line("This directory was created on {0}", dt);
      ///       }
      ///     } catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      static xtd::date_time get_creation_time(const xtd::string& path);
      
      /// @brief Gets the current working directory of the application.
      /// @return A string that contains the absolute path of the current working directory, and does not end with a backslash (\).
      /// @exception xtd::unauthorized_access_exception The caller does not have the required permission.
      /// @exception xtd::not_supported_exception The operating system does not have current directory functionality.
      /// @par Examples
      /// The following example demonstrates how to use the xtd::io::directory::get_current_directory method.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       // Get the current directory.
      ///       string path = directory::get_current_directory();
      ///       string target = R"(c:\temp)";
      ///       console::write_line("The current directory is {0}", path);
      ///       if (!directory::exists(target)) {
      ///         directory::create_directory(target);
      ///       }
      ///
      ///       // Change the current directory.
      ///       environment::current_directory(target);
      ///       if (path.equals(directory::get_current_directory())) {
      ///         console::write_line("You are in the temp directory.");
      ///       } else {
      ///         console::write_line("You are not in the temp directory.");
      ///       }
      ///     } catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The current directory is distinct from the original directory, which is the one from which the process was started.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static xtd::string get_current_directory();
      
      /// @brief Returns the names of subdirectories (including their paths) in the specified directory.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @return An array of the full names (including paths) of subdirectories in the specified path, or an empty array if no directories are found.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example takes an array of file or directory names on the command line, determines what kind of name it is, and processes it appropriately.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main(const list<string>& args) {
      ///     for (string path : args) {
      ///       if (file::exists(path)) {
      ///         // This path is a file
      ///         process_file(path);
      ///       } else if(directory::exists(path)) {
      ///         // This path is a directory
      ///         process_directory(path);
      ///       } else {
      ///         console::write_line("{0} is not a valid file or directory.", path);
      ///       }
      ///     }
      ///   }
      ///
      ///   // Process all files in the directory passed in, recurse on any directories
      ///   // that are found, and process the files they contain.
      ///   static void process_directory(const string& target_directory) {
      ///     // Process the list of files found in the directory.
      ///     std::vector<string> file_entries = directory::get_files(target_directory);
      ///     for (string file_name : file_entries)
      ///       process_file(file_name);
      ///
      ///     // Recurse into subdirectories of this directory.
      ///     std::vector<string> subdirectory_entries = directory::get_directories(target_directory);
      ///     for (string subdirectory : subdirectory_entries)
      ///       process_directory(subdirectory);
      ///   }
      ///
      ///   // Insert logic for processing found files here.
      ///   static void process_file(const string& path) {
      ///     console::write_line("Processed file '{0}'.", path);
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks This method is identical to xtd::io::directory::get_directories(string, string) with the asterisk (*) specified as the search pattern, so it returns all subdirectories.
      /// @remarks The xtd::io::directory::enumerate_directories and xtd::io::directory::get_directories methods differ as follows: When you use xtd::io::directory::enumerate_directories, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_directories, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_directories can be more efficient.
      /// @remarks The path parameter can specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The names returned by this method are prefixed with the directory information provided in path.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static std::vector<xtd::string> get_directories(const xtd::string& path);
      /// @brief Returns the names of subdirectories (including their paths) that match the specified search pattern in the specified directory.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @param search_pattern The search string to match against the names of subdirectories in path. This parameter can contain a combination of valid literal and wildcard characters, but it doesn't support regular expressions.
      /// @return An array of the full names (including paths) of the subdirectories that match the search pattern in the specified directory, or an empty array if no directories are found.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      ///
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       // Only get subdirectories that begin with the letter "p."
      ///       list<string> dirs = directory::get_directories(R"(c:\)", "p*");
      ///       console::write_line("The number of directories starting with p is {0}.", dirs.size());
      ///       for (string dir : dirs) {
      ///         console::write_line(dir);
      ///       }
      ///     } catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks This method returns all subdirectories directly under the specified directory that match the specified search pattern. If the specified directory has no subdirectories, or no subdirectories match the search_pattern parameter, this method returns an empty array. Only the top directory is searched.
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the search_attern string "*t" searches for all names in path ending with the letter "t". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks search_pattern cannot end in two periods ("..") or contain two periods ("..") followed by xtd::io::path::directory_separator_char or xtd::io::path::alt_directory_separator_char, nor can it contain any invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @remarks The path parameter can specify relative or absolute path information, and is not case-sensitive. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The xtd::io::directory::enumerate_directories and xtd::io::directory::get_directories methods differ as follows: When you use xtd::io::directory::enumerate_directories, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_directories, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_directories can be more efficient.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static std::vector<xtd::string> get_directories(const xtd::string& path, const xtd::string& search_pattern);
      
      /// @brief Returns the volume information, root information, or both for the specified path.
      /// @param path The path of a file or directory.
      /// @return A string that contains the volume information, root information, or both for the specified path.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example illustrates how to set the current directory and display the directory root.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Create string for a directory. This value should be an existing directory
      ///     // or the sample will throw a DirectoryNotFoundException.
      ///     string dir = R"(C:\test)";
      ///     try {
      ///       //Set the current directory.
      ///       directory::set_current_directory(dir);
      ///     } catch (const directory_not_found_exception& e) {
      ///       console::write_line("The specified directory does not exist. {0}", e);
      ///     }
      ///     // Print to console the results.
      ///     console::write_line("Root directory: {0}", directory::get_directory_root(dir));
      ///     console::write_line("Current directory: {0}", directory::get_current_directory());
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks This method obtains the fully qualified path name of path, as returned by xtd::io::path::get_full_path, and returns root directory information. The specified path is not required to exist.
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static xtd::string get_directory_root(const xtd::string& path);
      
      /// @brief Returns the names of files (including their paths) in the specified directory.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @return An array of the full names (including paths) for the files in the specified directory, or an empty array if no files are found.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example demonstrates how to use the GetFiles method to return file names from a user-specified location. The example is configured to catch all errors common to this method.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main(const std::vector<list>& args) {
      ///     for (string path : args) {
      ///       if (file::exists(path)) {
      ///         // This path is a file
      ///         process_file(path);
      ///       } else if(directory::exists(path)) {
      ///         // This path is a directory
      ///         process_directory(path);
      ///       } else {
      ///         console::write_line("{0} is not a valid file or directory.", path);
      ///       }
      ///     }
      ///   }
      ///
      ///   // Process all files in the directory passed in, recurse on any directories
      ///   // that are found, and process the files they contain.
      ///   static void process_directory(const string& target_directory) {
      ///     // Process the list of files found in the directory.
      ///     std::vector<string> file_entries = directory::get_files(target_directory);
      ///     for (string file_name : file_entries)
      ///       process_file(file_name);
      ///
      ///     // Recurse into subdirectories of this directory.
      ///     std::vector<string> subdirectory_entries = directory::get_directories(target_directory);
      ///     for (string subdirectory : subdirectory_entries)
      ///       process_directory(subdirectory);
      ///   }
      ///
      ///   // Insert logic for processing found files here.
      ///   static void process_file(const string& path) {
      ///     console::write_line("Processed file '{0}'.", path);
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The xtd::io::directory::enumerate_files and xtd::io::directory::get_files methods differ as follows: When you use xtd::io::directory::enumerate_files, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_files, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_files can be more efficient.
      /// @remarks The returned file names are appended to the supplied path parameter.
      /// @remarks This method is identical to xtd::io::directory::get_files(string, string) with the asterisk (*) specified as the search pattern.
      /// @remarks The path parameter can specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The order of the returned file names is not guaranteed; use the std:::sort method if a specific sort order is required.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static std::vector<xtd::string> get_files(const xtd::string& path);
      /// @brief Returns the names of files (including their paths) that match the specified search pattern in the specified directory.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @param search_pattern The search string to match against the names of files in path. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An array of the full names (including paths) for the files in the specified directory that match the specified search pattern, or an empty array if no files are found.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example counts the number of files that begin with the specified letter.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       // Only get files that begin with the letter "c".
      ///       list<string> dirs = directory::get_files(R"(c:\", "c*)");
      ///       console::write_line("The number of files starting with c is {0}.", dirs.size());
      ///       for (string dir : dirs) {
      ///         console::write_line(dir);
      ///       }
      ///     } catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The returned file names are appended to the supplied path parameter and the order of the returned file names is not guaranteed; use the std::sort method if a specific sort order is required.
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the search_pattern string "*t" searches for all names in path ending with the letter "t". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks search_pattern cannot end in two periods ("..") or contain two periods ("..") followed by xtd::io::path::directory_separator_char or xtd::io::path::alt_directory_separator_char, nor can it contain any invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @note When you use the asterisk wildcard character in a search_pattern such as "*.txt", the number of characters in the specified extension affects the search as follows:
      /// * If the specified extension is exactly three characters long, the method returns files with extensions that begin with the specified extension. For example, "*.xls" returns both "book.xls" and "book.xlsx".
      /// * In all other cases, the method returns files that exactly match the specified extension. For example, "*.ai" returns "file.ai" but not "file.aif".
      /// <br>When you use the question mark wildcard character, this method returns only files that match the specified file extension. For example, given two files, "file1.txt" and "file1.txtother", in a directory, a search pattern of "file?.txt" returns just the first file, whereas a search pattern of "file*.txt" returns both files.
      /// @note Because this method checks against file names with both the 8.3 file name format and the long file name format, a search pattern similar to "*1*.txt" may return unexpected file names. For example, using a search pattern of "*1*.txt" returns "longfilename.txt" because the equivalent 8.3 file name format is "LONGFI~1.TXT".
      /// @remarks The xtd::io::directory::enumerate_files and xtd::io::directory::get_files methods differ as follows: When you use xtd::io::directory::enumerate_files, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_files, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_files can be more efficient.
      /// @remarks The path parameter can specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static std::vector<xtd::string> get_files(const xtd::string& path, const xtd::string& search_pattern);
      
      /// @brief Returns the names of all files and subdirectories in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @return An array of the names of files and subdirectories in the specified directory, or an empty array if no files or subdirectories are found.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example uses the xtd::io::directory::get_file_system_entries method to fill an array of strings with the names of all files and subdirectories in a user-specified location and prints each string in the array to the console. The example is configured to catch all errors common to this method.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     program snippets;
      ///
      ///     string path = io::directory::get_current_directory();
      ///     string filter = "*.exe";
      ///
      ///     snippets.print_file_system_entries(path);
      ///     snippets.print_file_system_entries(path, filter);
      ///     snippets.get_logical_drives();
      ///     snippets.get_parent(path);
      ///     snippets.move("C:\\proof", "C:\\Temp");
      ///   }
      ///
      ///   void print_file_system_entries(const string& path) {
      ///     try {
      ///       // Obtain the file system entries in the directory path.
      ///       list<string> directory_entries = io::directory::get_file_system_entries(path);
      ///
      ///    for (xtd::string str : directory_entries) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::directory_not_found_exception&) {
      ///       console::write_line("The path encapsulated in the directory object does not exist.");
      ///     }
      ///   }
      ///
      ///   void print_file_system_entries(string path, string pattern) {
      ///     try {
      ///       // Obtain the file system entries in the directory path that match the pattern.
      ///       list<string> directory_entries = io::directory::get_file_system_entries(path, pattern);
      ///
      ///       for (string str : directory_entries) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::directory_not_found_exception&) {
      ///       console::write_line("The path encapsulated in the directory object does not exist.");
      ///     }
      ///   }
      ///
      ///   // Print out all logical drives on the system.
      ///   void get_logical_drives() {
      ///     try {
      ///       list<string> drives = io::directory::get_logical_drives();
      ///
      ///       for (string str : drives) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const io::io_exception&) {
      ///       console::write_line("An I/O error occurs.");
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     }
      ///   }
      ///
      ///   void get_parent(const string& path) {
      ///     try {
      ///       io::directory_info directory_info = io::directory::get_parent(path);
      ///
      ///       console::write_line(directory_info.full_name());
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     }
      ///   }
      ///
      ///   void move(const string& source_path, const string& destination_path) {
      ///     try {
      ///       io::directory::move(source_path, destination_path);
      ///       console::write_line("The directory move is complete.");
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::io_exception&) {
      ///       console::write_line("An attempt was made to move a directory to a different volume, or dest_dir_name already exists.");
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The order of the returned file and directory names is not guaranteed; use the std::sort method if a specific sort order is required.
      /// @remarks The xtd::io::directory::enumerate_fileSystem_entries and xtd::io::directory::get_file_system_entries methods differ as follows: When you use xtd::io::directory::enumerate_file_system_entries, you can start enumerating the collection of entries before the whole collection is returned; when you use xtd::io::directory::get_file_system_entries, you must wait for the whole array of entries to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_file_system_enties can be more efficient.
      /// @remarks This method is identical to xtd::io::directory::get_file_system_entries with the asterisk (*) specified as the search pattern.
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static std::vector<xtd::string> get_file_system_entries(const xtd::string& path);
      /// @brief Returns an array of file names and directory names that match a search pattern in a specified path.
      /// @param path The relative or absolute path to the directory to search. This string is not case-sensitive.
      /// @param serach_pattern The search string to match against the names of file and directories in path. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An array of file names and directory names that match the specified search criteria, or an empty array if no files or directories are found.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example uses the xtd::io::directory::get_file_system_entries method to fill an array of strings with the names of all files matching a user-specified filter in a specific location and prints each string in the array to the console. The example is configured to catch all errors common to this method.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     program snippets;
      ///
      ///     string path = io::directory::get_current_directory();
      ///     string filter = "*.exe";
      ///
      ///     snippets.print_file_system_entries(path);
      ///     snippets.print_file_system_entries(path, filter);
      ///     snippets.get_logical_drives();
      ///     snippets.get_parent(path);
      ///     snippets.move("C:\\proof", "C:\\Temp");
      ///   }
      ///
      ///   void print_file_system_entries(const string& path) {
      ///     try {
      ///       // Obtain the file system entries in the directory path.
      ///       list<string> directory_entries = io::directory::get_file_system_entries(path);
      ///
      ///    for (xtd::string str : directory_entries) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::directory_not_found_exception&) {
      ///       console::write_line("The path encapsulated in the directory object does not exist.");
      ///     }
      ///   }
      ///
      ///   void print_file_system_entries(string path, string pattern) {
      ///     try {
      ///       // Obtain the file system entries in the directory path that match the pattern.
      ///       list<string> directory_entries = io::directory::get_file_system_entries(path, pattern);
      ///
      ///       for (string str : directory_entries) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::directory_not_found_exception&) {
      ///       console::write_line("The path encapsulated in the directory object does not exist.");
      ///     }
      ///   }
      ///
      ///   // Print out all logical drives on the system.
      ///   void get_logical_drives() {
      ///     try {
      ///       list<string> drives = io::directory::get_logical_drives();
      ///
      ///       for (string str : drives) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const io::io_exception&) {
      ///       console::write_line("An I/O error occurs.");
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     }
      ///   }
      ///
      ///   void get_parent(const string& path) {
      ///     try {
      ///       io::directory_info directory_info = io::directory::get_parent(path);
      ///
      ///       console::write_line(directory_info.full_name());
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     }
      ///   }
      ///
      ///   void move(const string& source_path, const string& destination_path) {
      ///     try {
      ///       io::directory::move(source_path, destination_path);
      ///       console::write_line("The directory move is complete.");
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::io_exception&) {
      ///       console::write_line("An attempt was made to move a directory to a different volume, or dest_dir_name already exists.");
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The returned file names are appended to the supplied path parameter and the order of the returned file names is not guaranteed; use the std::sort method if a specific sort order is required.
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the search_pattern string "*t" searches for all names in path ending with the letter "t". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks search_pattern cannot end in two periods ("..") or contain two periods ("..") followed by xtd::io::path::directory_separator_char or xtd::io::path::alt_directory_separator_char, nor can it contain any invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @note When you use the asterisk wildcard character in a search_pattern such as "*.txt", the number of characters in the specified extension affects the search as follows:
      /// * If the specified extension is exactly three characters long, the method returns files with extensions that begin with the specified extension. For example, "*.xls" returns both "book.xls" and "book.xlsx".
      /// * In all other cases, the method returns files that exactly match the specified extension. For example, "*.ai" returns "file.ai" but not "file.aif".
      /// <br>When you use the question mark wildcard character, this method returns only files that match the specified file extension. For example, given two files, "file1.txt" and "file1.txtother", in a directory, a search pattern of "file?.txt" returns just the first file, whereas a search pattern of "file*.txt" returns both files.
      /// @note Because this method checks against file names with both the 8.3 file name format and the long file name format, a search pattern similar to "*1*.txt" may return unexpected file names. For example, using a search pattern of "*1*.txt" returns "longfilename.txt" because the equivalent 8.3 file name format is "LONGFI~1.TXT".
      /// @remarks The xtd::io::directory::enumerate_files and xtd::io::directory::get_files methods differ as follows: When you use xtd::io::directory::enumerate_files, you can start enumerating the collection of names before the whole collection is returned; when you use xtd::io::directory::get_files, you must wait for the whole array of names to be returned before you can access the array. Therefore, when you are working with many files and directories, xtd::io::directory::enumerate_files can be more efficient.
      /// @remarks The path parameter can specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static std::vector<xtd::string> get_file_system_entries(const xtd::string& path, const xtd::string& search_pattern);
      
      /// @brief Returns the date and time the specified file or directory was last accessed.
      /// @param path The file or directory for which to obtain access date and time information.
      /// @return A xtd::date_time class that is set to the date and time the specified file or directory was last accessed. This value is expressed in local time.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example demonstrates how to use GetLastAccessTime.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       string path = R"(c:\MyDir)";
      ///       if (!directory::exists(path)) {
      ///         directory::create_directory(path);
      ///       }
      ///       directory::set_last_access_time(path, {1985, 5, 4});
      ///
      ///       // Get the creation time of a well-known directory.
      ///       date_time dt = directory::get_last_access_time(path);
      ///       console::write_line("The last access time for this directory was {0}", dt);
      ///
      ///       // Update the last access time.
      ///       directory::set_last_access_time(path, date_time::now());
      ///       dt = directory::get_last_access_time(path);
      ///       console::write_line("The last access time for this directory was {0}", dt);
      ///     }
      ///
      ///     catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @note This method may return an inaccurate value, because it uses native functions whose values may not be continuously updated by the operating system.
      /// @remarks This method is identical to xtd::io::file::get_last_access_time.
      /// @remarks If the directory described in the path parameter does not exist, this method returns 12:00 midnight, January 1, 1601 A.D. (C.E.) Coordinated Universal Time (UTC), adjusted to local time.
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static xtd::date_time get_last_access_time(const xtd::string& path);
      
      /// @brief Returns the date and time the specified file or directory was last written to.
      /// @param path The file or directory for which to obtain modification date and time information.
      /// @return A xtd::date_time class that is set to the date and time the specified file or directory was last written to. This value is expressed in local time.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example demonstrates how to use xtd::io::directory::get_last_write_time.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       string path = R"(c:\MyDir)";
      ///       if (!directory::exists(path)) {
      ///         directory::create_directory(path);
      ///       }
      ///       directory::set_last_write_time(path, {1985, 5, 4});
      ///
      ///       // Get the creation time of a well-known directory.
      ///       date_time dt = directory::get_last_write_time(path);
      ///       console::write_line("The last write time for this directory was {0}", dt);
      ///
      ///       // Update the last write time.
      ///       directory::set_last_write_time(path, date_time::now());
      ///       dt = directory::get_last_write_time(path);
      ///       console::write_line("The last write time for this directory was {0}", dt);
      ///     }
      ///
      ///     catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @note This method may return an inaccurate value, because it uses native functions whose values may not be continuously updated by the operating system.
      /// @remarks If the directory described in the path parameter does not exist, this method returns 12:00 midnight, January 1, 1601 A.D. (C.E.) Coordinated Universal Time (UTC), adjusted to local time.
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static xtd::date_time get_last_write_time(const xtd::string& path);
      
      /// @brief Retrieves the names of the logical drives on this computer in the form "<drive letter>:\".
      /// @return The logical drives on this computer.
      /// @exception xtd::io::io_exception An I/O error occurred (for example, a disk error).
      /// @exception xtd::unauthorized_access_exception The caller does not have the required permission.
      /// @par Examples
      /// The following example uses the xtd::io::directory::get_logical_drives method to assign the name of each drive on the calling computer to an array of strings. Each member of this string array is then printed to the console. The example is configured to catch all errors common to this method.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     program snippets;
      ///
      ///     string path = io::directory::get_current_directory();
      ///     string filter = "*.exe";
      ///
      ///     snippets.print_file_system_entries(path);
      ///     snippets.print_file_system_entries(path, filter);
      ///     snippets.get_logical_drives();
      ///     snippets.get_parent(path);
      ///     snippets.move("C:\\proof", "C:\\Temp");
      ///   }
      ///
      ///   void print_file_system_entries(const string& path) {
      ///     try {
      ///       // Obtain the file system entries in the directory path.
      ///       list<string> directory_entries = io::directory::get_file_system_entries(path);
      ///
      ///    for (xtd::string str : directory_entries) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::directory_not_found_exception&) {
      ///       console::write_line("The path encapsulated in the directory object does not exist.");
      ///     }
      ///   }
      ///
      ///   void print_file_system_entries(string path, string pattern) {
      ///     try {
      ///       // Obtain the file system entries in the directory path that match the pattern.
      ///       list<string> directory_entries = io::directory::get_file_system_entries(path, pattern);
      ///
      ///       for (string str : directory_entries) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::directory_not_found_exception&) {
      ///       console::write_line("The path encapsulated in the directory object does not exist.");
      ///     }
      ///   }
      ///
      ///   // Print out all logical drives on the system.
      ///   void get_logical_drives() {
      ///     try {
      ///       list<string> drives = io::directory::get_logical_drives();
      ///
      ///       for (string str : drives) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const io::io_exception&) {
      ///       console::write_line("An I/O error occurs.");
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     }
      ///   }
      ///
      ///   void get_parent(const string& path) {
      ///     try {
      ///       io::directory_info directory_info = io::directory::get_parent(path);
      ///
      ///       console::write_line(directory_info.full_name());
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     }
      ///   }
      ///
      ///   void move(const string& source_path, const string& destination_path) {
      ///     try {
      ///       io::directory::move(source_path, destination_path);
      ///       console::write_line("The directory move is complete.");
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::io_exception&) {
      ///       console::write_line("An attempt was made to move a directory to a different volume, or dest_dir_name already exists.");
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks xtd::io::directory::get_logical_drives returns all of the accessible drives on a particular machine, including the floppy drive and any optical drives.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static std::vector<xtd::string> get_logical_drives();
      
      /// @brief Retrieves the parent directory of the specified path, including both absolute and relative paths.
      /// @param path The path for which to retrieve the parent directory.
      /// @return The parent directory, or xtd::io::directory_info::empty if path is the root directory, including the root of a UNC server or share name.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example demonstrates how to use the xtd::io::directory::get_parent method to retrieve the parent directory of a user-specified location, "path". The value returned by the xtd::io::directory::get_parent method is then printed to the console. The example is configured to catch all errors common to this method.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::collections::generic;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     program snippets;
      ///
      ///     string path = io::directory::get_current_directory();
      ///     string filter = "*.exe";
      ///
      ///     snippets.print_file_system_entries(path);
      ///     snippets.print_file_system_entries(path, filter);
      ///     snippets.get_logical_drives();
      ///     snippets.get_parent(path);
      ///     snippets.move("C:\\proof", "C:\\Temp");
      ///   }
      ///
      ///   void print_file_system_entries(const string& path) {
      ///     try {
      ///       // Obtain the file system entries in the directory path.
      ///       list<string> directory_entries = io::directory::get_file_system_entries(path);
      ///
      ///    for (xtd::string str : directory_entries) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::directory_not_found_exception&) {
      ///       console::write_line("The path encapsulated in the directory object does not exist.");
      ///     }
      ///   }
      ///
      ///   void print_file_system_entries(string path, string pattern) {
      ///     try {
      ///       // Obtain the file system entries in the directory path that match the pattern.
      ///       list<string> directory_entries = io::directory::get_file_system_entries(path, pattern);
      ///
      ///       for (string str : directory_entries) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::directory_not_found_exception&) {
      ///       console::write_line("The path encapsulated in the directory object does not exist.");
      ///     }
      ///   }
      ///
      ///   // Print out all logical drives on the system.
      ///   void get_logical_drives() {
      ///     try {
      ///       list<string> drives = io::directory::get_logical_drives();
      ///
      ///       for (string str : drives) {
      ///         console::write_line(str);
      ///       }
      ///     } catch (const io::io_exception&) {
      ///       console::write_line("An I/O error occurs.");
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     }
      ///   }
      ///
      ///   void get_parent(const string& path) {
      ///     try {
      ///       io::directory_info directory_info = io::directory::get_parent(path);
      ///
      ///       console::write_line(directory_info.full_name());
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     }
      ///   }
      ///
      ///   void move(const string& source_path, const string& destination_path) {
      ///     try {
      ///       io::directory::move(source_path, destination_path);
      ///       console::write_line("The directory move is complete.");
      ///     } catch (const security::security_exception&) {
      ///       console::write_line("The caller does not have the required permission.");
      ///     } catch (const argument_exception&) {
      ///       console::write_line("path is an empty string, contains only white spaces, or contains invalid characters.");
      ///     } catch (const io::io_exception&) {
      ///       console::write_line("An attempt was made to move a directory to a different volume, or dest_dir_name already exists.");
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The path parameter can specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks Trailing spaces are removed from the end of the path parameter before getting the directory.
      /// @remarks The string returned by this method consists of all characters in the path up to, but not including, the last xtd::io::path::directory_separator_char or alt_directory_separator_char. For example, passing the path "C:\Directory\SubDirectory\test.txt" to xtd::io::directory::get_parent returns "C:\Directory\SubDirectory". Passing "C:\Directory\SubDirectory" returns "C:\Directory". However, passing "C:\Directory\SubDirectory\" returns "C:\Directory\SubDirectory", because the ending directory separator is after "SubDirectory".
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static xtd::io::directory_info get_parent(const xtd::string& path);
      
      /// @brief Gets the xtd::io::file_permissions of the directory on the path.
      /// @param path The path to the directory.
      /// @return The xtd::io::file_permissions of the directory on the path.
      /// @exception xtd::io::directory_not_found_exception if directory src does not exists.
      static xtd::io::file_permissions get_permissions(const xtd::string& path);
      
      /// @brief Moves a file or a directory and its contents to a new location.
      /// @param source_dir_name The path of the file or directory to move.
      /// @param dest_dir_name The path to the new location for source_dir_name. If source_dir_name is a file, then dest_dir_name must also be a file name.
      /// @exception xtd::io::io_exception An attempt was made to move a directory to a different volume.<br>-or-<br>dest_dir_name already exists. See the Note in the Remarks section.<br>-or-<br>The source_dir_name and dest_dir_name parameters refer to the same file or directory.<br>-or-<br>The directory or a file within it is being used by another process.
      /// @exception xtd::argument_exception source_dir_name or dest_dir_name is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters with the xtd::path::io::get_invalid_path_chars() method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The path specified by sourceDirName is invalid (for example, it is on an unmapped drive).
      /// @par Examples
      /// The following example demonstrates how to move a directory and all its files to a new directory. The original directory no longer exists after it has been moved.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     string source_directory = R"(C:\source)";
      ///     string destination_directory = R"(C:\destination)";
      ///
      ///     try {
      ///       directory::move(source_directory, destination_directory);
      ///     } catch (const exception& e) {
      ///       console::write_line(e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks This method creates a new directory with the name specified by destDirName and moves the contents of sourceDirName to the newly created destination directory. If you try to move a directory to a directory that already exists, an IOException will occur. For example, an exception will occur if you try to move c:\mydir to c:\public, and c:\public already exists. Alternatively, you could specify "c:\\public\\mydir" as the destDirName parameter, provided that "mydir" does not exist under "c:\\public", or specify a new directory name such as "c:\\newdir".
      /// @remarks The sourceDirName and destDirName arguments are permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see GetCurrentDirectory.
      /// @remarks Trailing spaces are removed from the end of the path parameters before moving the directory.
      /// @note xtd::io::directory::move method throws an xtd::io::io_exception in all platforms when the dest_dir_name already exists.
      static void move(const xtd::string& source_dir_name, const xtd::string& dest_dir_name);
      
      /// @brief Deletes an empty directory from a specified path.
      /// @param path The name of the empty directory to remove. This directory must be writable and empty.
      /// @exception xtd::io::io_exception A file with the same name and location specified by path exists.<br>-or-<br>The directory is the application's current working directory.<br>-or-<br>The directory specified by path is not empty.<br>-or-<br>The directory is read-only or contains a read-only file.<br>-or-<br>The directory is being used by another process.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Exaample
      /// The following example shows how to create a new directory and subdirectory, and then delete only the subdirectory.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     string sub_path = R"(C:\NewDirectory\NewSubDirectory)";
      ///
      ///     try {
      ///       directory::create_directory(sub_path);
      ///       directory::remove(sub_path);
      ///
      ///       bool directory_exists = directory::exists(R"(C:\NewDirectory)");
      ///       bool sub_directory_exists = directory::exists(sub_path);
      ///
      ///       console::write_line("top-level directory exists: {0}", directory_exists);
      ///       console::write_line("sub-directory exists: {0}", sub_directory_exists);
      ///     } catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks This method behaves identically to xtd::io::dirctory::remove(const xtd::string&, bool) with `false` specified for the second parameter.
      /// @remarks The path parameter may specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see GetCurrentDirectory.
      /// @remarks Trailing spaces are removed from the end of the path parameter before deleting the directory.
      /// @remarks This method throws an IOException if the directory specified in the path parameter contains files or subdirectories.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks In some cases, if you have the specified directory open in File Explorer, the Delete method may not be able to delete it.
      static void remove(const xtd::string& path);
      
      /// @brief Deletes the specified directory and, if indicated, any subdirectories and files in the directory.
      /// @param path The name of the directory to remove.
      /// @param recursive `true` to remove directories, subdirectories, and files in path; otherwise, `false`.
      /// @exception xtd::io::io_exception A file with the same name and location specified by path exists.<br>-or-<br>The directory is the application's current working directory.<br>-or-<br>The directory specified by path is not empty.<br>-or-<br>The directory is read-only or contains a read-only file.<br>-or-<br>The directory is being used by another process.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example shows how to create a new directory, subdirectory, and file in the subdirectory, and then recursively delete all the new items.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     string top_path = R"(C:\NewDirectory)";
      ///     string sub_path = R"(C:\NewDirectory\NewSubDirectory)";
      ///
      ///     try {
      ///       directory::create_directory(sub_path);
      ///
      ///       block_scope_(stream_writer writer(sub_path + R"(\example.txt)")) {
      ///         writer.write_line("content added");
      ///       }
      ///
      ///       directory::remove(top_path, true);
      ///
      ///       bool directory_exists = directory::exists(top_path);
      ///
      ///       console::write_line("top-level directory exists: {0}", directory_exists);
      ///     } catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.message());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The path parameter may specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks Trailing spaces are removed from the end of the path parameter before deleting the directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks If the recursive parameter is `true`, the user must have write permission for the current directory as well as for all subdirectories.
      /// @remarks The behavior of this method differs slightly when deleting a directory that contains a reparse point, such as a symbolic link or a mount point. If the reparse point is a directory, such as a mount point, it is unmounted and the mount point is deleted. This method does not recurse through the reparse point. If the reparse point is a symbolic link to a file, the reparse point is deleted and not the target of the symbolic link.
      /// @remarks In some cases, if you have the specified directory open in File Explorer, the xtd::io::directory::remove method may not be able to delete it.
      static void remove(const xtd::string& path, bool recursive);
      
      /// @brief Sets the creation date and time for the specified file or directory.
      /// @param path The file or directory for which to set the creation date and time information.
      /// @param creation_time The date and time the file or directory was last written to. This value is expressed in local time.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      ///
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Set the directory.
      ///     string n = R"(C:\test\newdir)";
      ///
      ///     //Create the directory.
      ///     try {
      ///       directory::create_directory(n);
      ///     } catch (const io_exception& e) {
      ///       console::write_line(e);
      ///     }
      ///
      ///     //Set the creation and last access times to a variable DateTime value.
      ///     directory::set_creation_time(n, {2002, 1, 3});
      ///     directory::set_last_access_time(n, {2002, 1, 3});
      ///
      ///     // Print to console the results.
      ///     console::write_line("Creation Date: {0}", directory::get_creation_time(n));
      ///     console::write_line("Last write time: {0}", directory::get_last_write_time(n));
      ///     console::write_line("Last access time: {0}", directory::get_last_access_time(n));
      ///
      ///     //Set the last write time to a different value.
      ///     directory::set_last_write_time(n, {1999, 1, 1});
      ///     console::write_line("Changed last write time: {0}", directory::get_last_write_time(n));
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// // Obviously, since this sample deals with dates and times, the output will vary
      /// // depending on when you run the executable. Here is one example of the output:
      /// //Creation Date: 1/3/2002 12:00:00 AM
      /// //Last write time: 12/31/1998 4:00:00 PM
      /// //Last access time: 1/2/2002 4:00:00 PM
      /// //Changed last write time: 1/1/1999 12:00:00 AM
      /// ```
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      static void set_creation_time(const xtd::string& path, const xtd::date_time& creation_time);
      /// @brief Sets the creation date and time for the specified file or directory.
      /// @param path The file or directory for which to set the creation date and time information.
      /// @param creation_time The date and time the file or directory was last written to. This value is expressed in local time.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      ///
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Set the directory.
      ///     string n = R"(C:\test\newdir)";
      ///
      ///     //Create the directory.
      ///     try {
      ///       directory::create_directory(n);
      ///     } catch (const io_exception& e) {
      ///       console::write_line(e);
      ///     }
      ///
      ///     //Set the creation and last access times to a variable DateTime value.
      ///     directory::set_creation_time(n, {2002, 1, 3});
      ///     directory::set_last_access_time(n, {2002, 1, 3});
      ///
      ///     // Print to console the results.
      ///     console::write_line("Creation Date: {0}", directory::get_creation_time(n));
      ///     console::write_line("Last write time: {0}", directory::get_last_write_time(n));
      ///     console::write_line("Last access time: {0}", directory::get_last_access_time(n));
      ///
      ///     //Set the last write time to a different value.
      ///     directory::set_last_write_time(n, {1999, 1, 1});
      ///     console::write_line("Changed last write time: {0}", directory::get_last_write_time(n));
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// // Obviously, since this sample deals with dates and times, the output will vary
      /// // depending on when you run the executable. Here is one example of the output:
      /// //Creation Date: 1/3/2002 12:00:00 AM
      /// //Last write time: 12/31/1998 4:00:00 PM
      /// //Last access time: 1/2/2002 4:00:00 PM
      /// //Changed last write time: 1/1/1999 12:00:00 AM
      /// ```
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      static void set_creation_time(const xtd::string& path, time_t creation_time);
      
      /// @brief Sets the application's current working directory to the specified directory.
      /// @param path The path to which the current working directory is set.
      /// @exception xtd::argument_exception Attempted to set to an empty string ("").
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @exception xtd::io::directory_not_found_exception Attempted to set a local path that cannot be found.
      /// @exception xtd::security::security_exception The caller does not have the appropriate permission.
      /// @par Examples
      /// The following example illustrates how to set the current directory and display the directory root.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Create string for a directory. This value should be an existing directory
      ///     // or the sample will throw a DirectoryNotFoundException.
      ///     string dir = R"(C:\test)";
      ///     try {
      ///       //Set the current directory.
      ///       directory::set_current_directory(dir);
      ///     } catch (const directory_not_found_exception& e) {
      ///       console::write_line("The specified directory does not exist. {0}", e);
      ///     }
      ///     // Print to console the results.
      ///     console::write_line("Root directory: {0}", directory::get_directory_root(dir));
      ///     console::write_line("Current directory: {0}", directory::get_current_directory());
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks When the application terminates, the working directory is restored to its original location (the directory where the process was started).
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks Trailing spaces are removed from the end of the path parameter before setting the directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks If you are setting the directory to a drive with removable media (for example, "E:" for a USB flash drive), you can determine whether the drive is ready by using the IsReady property.When the application terminates, the working directory is restored to its original location (the directory where the process was started).
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see GetCurrentDirectory.
      /// @remarks Trailing spaces are removed from the end of the path parameter before setting the directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks If you are setting the directory to a drive with removable media (for example, "E:" for a USB flash drive), you can determine whether the drive is ready by using the xtd::io::drive::is_ready property.
      static void set_current_directory(const xtd::string& path);
      
      /// @brief Sets the date and time the specified file or directory was last accessed.
      /// @param path The file or directory for which to set the access date and time information.
      /// @param last_access_time An object that contains the value to set for the access date and time of path. This value is expressed in local time.
      /// @exception xtd::argument_exception Attempted to set to an empty string ("").
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @exception xtd::io::directory_not_found_exception Attempted to set a local path that cannot be found.
      /// @exception xtd::security::security_exception The caller does not have the appropriate permission.
      /// @par Examples
      /// The following example demonstrates how to use xtd::directory::set_last_access_time.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       string path = R"(c:\MyDir)";
      ///       if (!directory::exists(path)) {
      ///         directory::create_directory(path);
      ///       }
      ///       directory::set_last_access_time(path, {1985, 5, 4});
      ///
      ///       // Get the creation time of a well-known directory.
      ///       sdate_time dt = directory::get_last_access_time(path);
      ///       console::write_line("The last access time for this directory was {0}", dt);
      ///
      ///       // Update the last access time.
      ///       directory::set_last_access_time(path, date_time::now());
      ///       dt = directory::get_last_access_time(path);
      ///       console::write_line("The last access time for this directory was {0}", dt);
      ///     }
      ///
      ///     catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static void set_last_access_time(const xtd::string& path, const xtd::date_time& last_access_time);
      
      /// @brief Sets the date and time a directory was last written to.
      /// @param path The path of the directory.
      /// @param last_write_time The date and time the directory was last written to. This value is expressed in local time.
      /// @exception xtd::argument_exception Attempted to set to an empty string ("").
      /// @exception xtd::io::io_exception An I/O error occurred.
      /// @exception xtd::io::directory_not_found_exception Attempted to set a local path that cannot be found.
      /// @exception xtd::security::security_exception The caller does not have the appropriate permission.
      /// @par Examples
      /// The following example demonstrates how to use xtd::io::set_last_write_time.
      /// ```cpp
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       string path = R"(c:\MyDir)";
      ///       if (!directory::exists(path)) {
      ///         directory::create_directory(path);
      ///       }
      ///       directory::set_last_write_time(path, {1985, 5, 4});
      ///
      ///       // Get the creation time of a well-known directory.
      ///       date_time dt = directory::get_last_write_time(path);
      ///       console::write_line("The last write time for this directory was {0}", dt);
      ///
      ///       // Update the last write time.
      ///       directory::set_last_write_time(path, date_time::now());
      ///       tp = directory::get_last_write_time(path);
      ///       console::write_line("The last write time for this directory was {0}", dt);
      ///     }
      ///
      ///     catch (const exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// ```
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks The path parameter is not case-sensitive.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static void set_last_write_time(const xtd::string& path, const xtd::date_time& last_write_time);
      
      /// @brief Sets the specified xtd::io::file_permissions of the directory on the specified path.
      /// @param path The path to the directory.
      /// @param attributes A bitwise combination of the enumeration values.
      /// @exception xtd::io::io_exception The directory specified by path is a file.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, directory name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks For a list of common I/O tasks, see [Common I/O Tasks](https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks).
      static void set_permissions(const xtd::string& path, xtd::io::file_permissions permissions);
      /// @}

    private:
      static std::tuple<time_t, time_t, time_t> get_file_times(const string& path);
    };
  }
}
