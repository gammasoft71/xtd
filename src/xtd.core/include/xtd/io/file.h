/// @file
/// @brief Contains xtd::io::file class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "file_attributes.h"
#include "file_permissions.h"
#include "stream_reader.h"
#include "stream_writer.h"
#include "../chrono.h"
#include "../core_export.h"
#include "../date_time.h"
#include "../static.h"
#include "../ustring.h"
#include <cstdint>
#include <cstdio>
#include <fstream>
#include <tuple>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::fstream objects.
    /// @code
    /// class core_export_ file static_
    /// @endcode
    /// @par Inheritance
    /// xtd::static_object → xtd::io::file
    /// @par Header
    /// @code #include <xtd/io/file> @endcode
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ file static_ {
    public:
      /// @name Static methods
      
      /// @{
      /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static void append_all_lines(const xtd::ustring& path, type_t contents) {
        xtd::io::stream_writer sw(path, true);
        for (const auto& line : contents)
          sw.write_line(line);
      }
      
      /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static void append_all_lines(const xtd::ustring& path, const std::initializer_list<type_t>& contents) {
        xtd::io::stream_writer sw(path, true);
        for (const auto& line : contents)
          sw.write_line(line);
      }
      
      /// @brief Appends text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      template<typename type_t>
      static void append_all_text(const xtd::ustring& path, type_t text) {
        xtd::io::stream_writer sw(path, true);
        sw.write(text);
      }
      
      /// @brief Creates a std::ofstream that appends text to an existing file.
      /// @param path The path to the file to append to.
      /// @return A std::ofstream that appends text to an existing file.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      static std::ofstream append_text(const xtd::ustring& path);
      
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is not allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory or an existing file.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::file_not_found_exception if file src does not exists.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      static void copy(const xtd::ustring& src, const xtd::ustring& dest);
      
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory.
      /// @param overwrite true if the destination file can be overwritten; otherwise, false.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path<br>-or-<br>file dest exists.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      static void copy(const xtd::ustring& src, const xtd::ustring& dest, bool overwrite);
      
      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::ofstream that provides read/write access to the file specified in path.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path<br>-or-<br>file dest exists.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be created.
      static std::ofstream create(const xtd::ustring& path);
      
      /// @brief Creates or opens a file for writing text.
      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::ofstream that provides read/write access to the file specified in path.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path<br>-or-<br>file dest exists.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be created.
      static std::ofstream create_text(const xtd::ustring& path);
      
      /// @brief Determines whether the specified file exists.
      /// @param path The file to check.
      /// @return true if the caller has the required permissions and path contains the name of an existing file; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns false regardless of the existence of path.
      static bool exists(const xtd::ustring& path) noexcept;
      
      /// @brief Gets the xtd::io::file_attributes of the file on the path.
      /// @param path The path to the file.
      /// @return The xtd::io::file_attributes of the file on the path.
      /// @exception xtd::io::file_not_found_exception if file src does not exists.
      static xtd::io::file_attributes get_attributes(const xtd::ustring& path);
      
      /// @brief Returns the creation date and time of the specified file or directory.
      /// @param path The file or directory for which to obtain creation date and time information.
      /// @return A xtd::date_time class set to the creation date and time for the specified file or directory. This value is expressed in local time.
      /// @exception xtd::unauthorized_access_exception The caller does not have the required permission.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::not_supported_excpttion path is in an invalid format.
      static xtd::date_time get_creation_time(const xtd::ustring& path);
      
      /// @brief Returns the date and time the specified file or directory was last accessed.
      /// @param path The file or directory for which to obtain access date and time information.
      /// @return A xtd::date_time structure set to the date and time that the specified file or directory was last accessed. This value is expressed in local time.
      /// @exception xtd::unauthorized_access_exception The caller does not have the required permission.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::not_supported_excpttion path is in an invalid format.
      static xtd::date_time get_last_access_time(const xtd::ustring& path);
      
      /// @brief Returns the date and time the specified file or directory was last written to.
      /// @param path The file or directory for which to obtain write date and time information.
      /// @return A xtd::date_time structure set to the date and time that the specified file or directory was last written to. This value is expressed in local time.
      /// @exception xtd::unauthorized_access_exception The caller does not have the required permission.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::not_supported_excpttion path is in an invalid format.
      static xtd::date_time get_last_write_time(const xtd::ustring& path);
      
      /// @brief Gets the xtd::io::file_permissions of the file on the path.
      /// @param path The path to the file.
      /// @return The xtd::io::file_permissions of the file on the path.
      /// @exception xtd::io::file_not_found_exception if file src does not exists.
      static xtd::io::file_permissions get_permissions(const xtd::ustring& path);
      
      /// @brief Moves a specified file to a new location, providing the option to specify a new file name.
      /// @param src The name of the file to move.
      /// @param dest The new path for the file.
      /// @return true if the file moved; otherwise, false.
      /// @exception xtd::argument_exception if dest already exist.
      /// @exception xtd::io::io_exception if path is empty or an invalid path.
      /// @exception xtd::io::io_exception if the caller has not the required permissions.
      static void move(const xtd::ustring& src, const xtd::ustring& dest);
      
      /// @brief Moves a specified file to a new location, providing the options to specify a new file name and to overwrite the destination file if it already exists.
      /// @param src The name of the file to move.
      /// @param dest The new path for the file.
      /// @param overwrite true to overwrite the destination file if it already exists; false otherwise.
      /// @return true if the file moved; otherwise, false.
      /// @exception xtd::argument_exception if dest already exist.
      /// @exception xtd::io::io_exception if path is empty or an invalid path.
      /// @exception xtd::io::io_exception if the caller has not the required permissions.
      static void move(const xtd::ustring& src, const xtd::ustring& dest, bool overwrite);
      
      /// @brief Opens a FileStream on the specified path.
      /// @param path The file to open.
      /// @param mode A std::ios::openmode value that specifies whether a file is created if one does not exist, and determines whether the contents of existing files are retained or overwritten.
      /// @return A std::fstream on the specified path.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      static std::fstream open(const xtd::ustring& path, std::ios::openmode mode);
      
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::ifstream on the specified path.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      static std::ifstream open_read(const xtd::ustring& path);
      
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::ifstream on the specified path.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      static std::ifstream open_text(const xtd::ustring& path);
      
      /// @brief Opens an existing file for writing.
      /// @param path The file to be opened for writing.
      /// @return A std::ofstream on the specified path.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      static std::ofstream open_write(const xtd::ustring& path);
      
      /// @brief Opens a binary file, reads the contents of the file into a byte array, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A byte array containing the contents of the file.
      /// @exception xtd::io::file_not_found_exception if path does not exists.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      static std::vector<xtd::byte> read_all_bytes(const xtd::ustring& path);
      
      /// @brief Opens a binary file, reads the contents of the file into a byte array, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A byte array containing the contents of the file.
      /// @exception xtd::io::file_not_found_exception if path does not exists.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      template<typename char_t>
      static std::vector<xtd::byte> read_all_bytes(const char_t* path) {return read_all_bytes(xtd::ustring(path));}
      
      /// @brief Opens a text file, reads all lines of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A String array containing all lines of the file.
      /// @remarks This method also returns an empty array if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns an empty array regardless of the existence of path.
      static std::vector<xtd::ustring> read_all_lines(const xtd::ustring& path);
      
      /// @brief Opens a text file, reads all text of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A string containing all text of the file.
      /// @remarks This method also returns empty string if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns empty string regardless of the existence of file.
      static xtd::ustring read_all_text(const xtd::ustring& path);
      
      /// @brief Deletes the specified file.
      /// @param path The name of the file to be deleted.
      /// @return std::ofstream An unshared std::ofstream that provides access to the specified file, with the specified mode and access.
      /// @return true if the file is deleted; otherwise, false.
      static void remove(const xtd::ustring& path);
      
      /// @brief Replaces the contents of a specified file with the contents of another file, deleting the original file, and creating a backup of the replaced file and optionally ignores merge errors.
      /// @param source_file_name The name of a file that replaces the file specified by destination_file_name.
      /// @param destination_file_name The name of the file being replaced.
      /// @param destination_backup_file_name The name of the backup file.
      /// @param ignore_metadata_errors true to ignore merge errors (such as attributes and access control lists (ACLs)) from the replaced file to the replacement file; otherwise, false.
      /// @return false source_file_name does not exist or bad format, or destination_file_name does not exist or bad format, or if ignore_metadata_errors equal false and destination_backup_file_name bad format or on ani io error; otherwise true.
      static void replace(const xtd::ustring& source_file_name, const xtd::ustring& destination_file_name, const xtd::ustring& destination_backup_file_name);
      
      /// @brief Sets the specified xtd::io::file_attributes of the file on the specified path.
      /// @param path The path to the file.
      /// @param attributes A bitwise combination of the enumeration values.
      /// @exception xtd::io::io_exception The file specified by path is a directory.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::file_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks Certain file attributes, such as xtd::io::file_attributes::hidden and xtd::io::file_attributes::read_only, can be combined. Other attributes, such as xtd::io::file_attributes::normal, must be used alone.
      /// @remarks It is not possible to change the compression status of a xtd::io::file object using the xtd::io::file::set_attributes method.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      static void set_attributes(const xtd::ustring& path, xtd::io::file_attributes attributes);
      
      /// @brief Sets the date and time the file was created.
      /// @param path The file for which to set the creation date and time information.
      /// @param creation_time A xtd::date_time containing the value to set for the creation date and time of path. This value is expressed in local time.
      /// @exception xtd::io::io_exception The file specified by path is a directory.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::file_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks NTFS-formatted drives may cache file meta-info, such as file creation time, for a short period of time. As a result, it may be necessary to explicitly set the creation time of a file if you are overwriting or replacing an existing file.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      static void set_creation_time(const xtd::ustring& path, const xtd::date_time& creation_time);
      
      /// @brief Sets the date and time the specified file was last accessed.
      /// @param path The file for which to set the access date and time information.
      /// @param last_access_time A xtd::date_time containing the value to set for the last access date and time of path. This value is expressed in local
      /// @exception xtd::io::io_exception The file specified by path is a directory.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::file_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      static void set_last_access_time(const xtd::ustring& path, const xtd::date_time& last_access_time);
      
      /// @brief Sets the date and time that the specified file was last written to.
      /// @param path The file for which to set the date and time information.
      /// @param last_write_time A xtd::date_time containing the value to set for the last write date and time of path. This value is expressed in local time.
      /// @exception xtd::io::io_exception The file specified by path is a directory.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::file_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      static void set_last_write_time(const xtd::ustring& path, const xtd::date_time& last_write_time);
      
      /// @brief Sets the specified xtd::io::file_permissions of the file on the specified path.
      /// @param path The path to the file.
      /// @param attributes A bitwise combination of the enumeration values.
      /// @exception xtd::io::io_exception The file specified by path is a directory.
      /// @exception xtd::argument_exception path is a zero-length string, contains only white space, or contains one or more invalid characters. You can query for invalid characters by using the xtd::io::path::get_invalid_path_chars method.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::file_not_found_exception The specified path is invalid (for example, it is on an unmapped drive).
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @remarks The path parameter is permitted to specify relative or absolute path information. Relative path information is interpreted as relative to the current working directory. To obtain the current working directory, see xtd::io::directory::get_current_directory.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      static void set_permissions(const xtd::ustring& path, xtd::io::file_permissions permissions);
      
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static void write_all_lines(const xtd::ustring& path, type_t contents) {
        xtd::io::stream_writer sw(path);
        for (const auto& line : contents)
          sw.write_line(line);
      }
      
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static void write_all_lines(const xtd::ustring& path, const std::initializer_list<type_t>& contents) {
        xtd::io::stream_writer sw(path);
        for (const auto& line : contents)
          sw.write_line(line);
      }
      
      /// @brief Writes text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      template<typename type_t>
      static void write_all_text(const xtd::ustring& path, type_t text) {
        xtd::io::stream_writer sw(path);
        sw.write(text);
      }
      
      /// @brief Creates a std::ofstream that appends text to an existing file.
      /// @param path The path to the file to write to.
      /// @return A std::ofstream that writes text to an existing file.
      /// @exception xtd::argument_exception path contains one or more of the invalid characters<br>-or-<br>The system could not retrieve the absolute path.
      /// @exception xtd::io::io_exception the handle of the specified file cannot be opened.
      static std::ofstream write_text(const xtd::ustring& path);
      /// @}
    private:
      static std::tuple<time_t, time_t, time_t> get_file_times(const ustring& path);
    };
  }
}
