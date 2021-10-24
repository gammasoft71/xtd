/// @file
/// @brief Contains xtd::io::path class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <cstdlib>
#include <random>
#include <regex>
#include <sstream>
#include "../core_export.h"
#include "../static.h"
#include "../ustring.h"
/// @todo remove comment when drive_into.h will be create
//#include "drive_into.h"
#include "file.h"

//#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Performs operations on std::basic_string instances that contain file or directory path information. These operations are performed in a cross-platform manner.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ path static_ {
    public:
      /// @brief Provides a platform-specific alternate character used to separate directory levels in a path string that reflects a hierarchical file system organization.
      /// @return char_t character used to separate directory levels.
      /// @remarks This method can have the same value as directory_separator_char. alt_directory_separator_char and directory_separator_char are both valid for separating directory levels in a path string.
      /// @remarks The value of this field is a slash ('/') on both Windows and Unix-based operating systems.
      /// @par Examples
      /// The following code example demonstrates the use of the alt_directory_separator_char() property.
      /// @include directory_separator_char.cpp
      template<typename char_t>
      static char_t alt_directory_separator_char() noexcept {return static_cast<char_t>(alt_directory_separator_char());}
      
      /// @brief Provides a platform-specific alternate character used to separate directory levels in a path string that reflects a hierarchical file system organization.
      /// @return char character used to separate directory levels.
      /// @remarks This method can have the same value as directory_separator_char. alt_directory_separator_char and directory_separator_char are both valid for separating directory levels in a path string.
      /// @remarks The value of this field is a slash ('/') on both Windows and Unix-based operating systems.
      /// @par Examples
      /// The following code example demonstrates the use of the alt_directory_separator_char() property.
      /// @include directory_separator_char.cpp
      static char alt_directory_separator_char() noexcept;
      
      /// @brief Changes the extension of a path string.
      /// @param path The path information to modify. The path cannot contain any of the characters defined in GetInvalidPathchar_ts.
      /// @param extension The new extension (with or without a leading period). Specify null to remove an existing extension from path.
      /// @return string The modified path information.
      /// @note On Windows-based desktop platforms, if path is an empty string (""), the path information is returned unmodified. If extension is empty string (""), the returned string contains the specified path with its extension removed. If path has no extension, and extension is not empty, the returned path string contains extension appended to the end of path.
      /// @remarks If neither path nor extension contains a period (.), change_extension adds the period.
      /// @remarks The extension parameter can contain multiple periods and any valid path characters, and can be any length. If extension is empty (""), the returned string contains the contents of path with the last period and all characters following it removed.
      /// @remarks If extension is an empty string, the returned path string contains the contents of path with any characters following the last period removed.
      /// @remarks If extension does not contain a leading period, the period is added.
      /// @remarks If path contains a multiple extension separated by multiple periods, the returned string contains the contents of path with the last period and all characters following it replaced by extension. For example, if path is "\Dir1\examples\pathtests.csx.txt" and extension is "cs", the modified path is "\Dir1\examples\pathtests.csx.cs".
      /// @remarks It is not possible to verify that the returned results are valid in all scenarios. For example, if path is empty, extension is appended.
      static xtd::ustring change_extension(const xtd::ustring& path, const xtd::ustring& extension);
      
      /// @brief Combines two path strings.
      /// @param path1 The first path.
      /// @param path2 The second path.
      /// @return A string containing the combined paths. If one of the specified paths is a zero-length string, this method returns the other path. If path2 contains an absolute path, this method returns path2.
      /// @remarks an empty string if path contains one or more of the invalid characters.
      static xtd::ustring combine(const xtd::ustring& path1, const xtd::ustring& path2);
      
      /// @brief Combines three path strings.
      /// @param path1 The first path.
      /// @param path2 The second path.
      /// @param path3 The third path.
      /// @return A string containing the combined paths. If one of the specified paths is a zero-length string, this method returns the other path. If path2 contains an absolute path, this method returns path2.
      /// @remarks an empty string if path contains one or more of the invalid characters.
      template<typename type1_t, typename type2_t, typename type3_t>
      static auto combine(type1_t path1, type2_t path2, type3_t path3) noexcept {
        return combine(combine(path1, path2), path3);
      }
      
      /// @brief Combines four path strings.
      /// @param path1 The first path.
      /// @param path2 The second path.
      /// @param path3 The third path.
      /// @param path4 The fourth path.
      /// @return A string containing the combined paths. If one of the specified paths is a zero-length string, this method returns the other path. If path2 contains an absolute path, this method returns path2.
      /// @remarks an empty string if path contains one or more of the invalid characters.
      template<typename type1_t, typename type2_t, typename type3_t, typename type4_t>
      static auto combine(type1_t path1, type2_t path2, type3_t path3, type4_t path4) noexcept {
        return combine(combine(combine(path1, path2), path3), path4);
      }
      
      /// @brief Combines path strings array.
      /// @param paths The path array.
      /// @return A string containing the combined paths. If one of the specified paths is a zero-length string, this method returns the other path. If path2 contains an absolute path, this method returns path2.
      /// @remarks an empty string if path contains one or more of the invalid characters.
      template<typename path_t>
      static xtd::ustring combine(path_t paths) noexcept {
        xtd::ustring result;
        for (auto path : paths)
          result = combine(result, path);
        return result;
      }
      
      /// @brief Combines path strings array.
      /// @param paths The path array.
      /// @return A string containing the combined paths. If one of the specified paths is a zero-length string, this method returns the other path. If path2 contains an absolute path, this method returns path2.
      /// @remarks an empty string if path contains one or more of the invalid characters.
      static xtd::ustring combine(const std::initializer_list<xtd::ustring>& paths) noexcept;
      
      /// @brief Provides a platform-specific character used to separate directory levels in a path string that reflects a hierarchical file system organization.
      /// @return char_t Platform-specific character used to separate directory levels.
      /// @remarks alt_directory_separator_char and directory_separator_char are both valid for separating directory levels in a path string.
      /// @par Examples
      /// The following code example demonstrates the use of the directory_separator_char() property.
      /// @include directory_separator_char.cpp
      template<typename char_t>
      static char_t directory_separator_char() noexcept {
        return static_cast<char_t>(directory_separator_char());
      }
      
      /// @brief Provides a platform-specific character used to separate directory levels in a path string that reflects a hierarchical file system organization.
      /// @return char Platform-specific character used to separate directory levels.
      /// @remarks alt_directory_separator_char and directory_separator_char are both valid for separating directory levels in a path string.
      /// @par Examples
      /// The following code example demonstrates the use of the directory_separator_char() property.
      /// @include directory_separator_char.cpp
      static char directory_separator_char() noexcept;
      
      /// @brief Returns the directory information for the specified path string.
      /// @param path the path of a file or directory.
      /// @return A string containing directory information for path, or null if path denotes a root directory, is the empty string ("").
      /// @remarks Returns string empty if path does not contain directory information.
      static xtd::ustring get_directory_name(const xtd::ustring& path);
      
      /// @brief Returns the extension of the specified path string.
      /// @param path The path string from which to get the extension.
      /// @return A std::string containing the extension of the specified path (including the ".") or std::string::empty.
      /// @remarks If path is empty, GetExtension returns string empty. If path does not have extension information, GetExtension returns string empty ("").
      static xtd::ustring get_extension(const xtd::ustring& path);
      
      /// @brief Returns the file name and extension of the specified path string.
      /// @param path The path string from which to obtain the file name and extension.
      /// @return The characters after the last directory separator character in path. If the last character of path is a directory or volume separator character, this method returns string empty ("").
      /// @remarks The separator characters used to determine the start of the file name are directory_separator_char and alt_directory_separator_char.
      static xtd::ustring get_file_name(const xtd::ustring& path);
      
      static xtd::ustring get_file_name_without_extension(const xtd::ustring& path);
      
      /// @brief Returns the absolute path for the specified path string.
      /// @param path The file or directory for which to obtain absolute path information.
      /// @return A string containing the fully qualified location of path, such as "C:\\MyFile.txt".
      static xtd::ustring get_full_path(const xtd::ustring& path);
      
      /// @brief Gets an array containing the characters that are not allowed in path names.
      /// @return An array containing the characters that are not allowed in path names.
      /// @remarks The array returned from this method is not guaranteed to contain the complete set of characters that are invalid in file and directory names. The full set of invalid characters can vary by file system. For example, on Windows-based desktop platforms, invalid path characters might include ASCII/Unicode characters 1 through 31, as well as quote ("), less than (<), greater than (>), pipe (|), backspace (\b), null (\0) and tab (\t).
      template<typename char_t>
      static std::vector<char_t> get_invalid_path_chars() noexcept {return {34, 60, 62, 124, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 0};}
      
      /// @brief Gets an array containing the characters that are not allowed in path names.
      /// @return An array containing the characters that are not allowed in path names.
      /// @remarks The array returned from this method is not guaranteed to contain the complete set of characters that are invalid in file and directory names. The full set of invalid characters can vary by file system. For example, on Windows-based desktop platforms, invalid path characters might include ASCII/Unicode characters 1 through 31, as well as quote ("), less than (<), greater than (>), pipe (|), backspace (\b), null (\0) and tab (\t).
      static std::vector<char> get_invalid_path_chars() noexcept;
      
      /// @brief Gets the root directory information of the specified path.
      /// @param path The path from which to obtain root directory information.
      /// @return A string containing the root directory of path, such as "C:\", or null if
      /// @return path is null, or an empty string if path does not contain root directory
      /// @return information.
      static xtd::ustring get_path_root(const xtd::ustring& path);
      
      /// @brief Returns a random folder name or file name.
      /// @return A random folder name or file name.
      /// @remarks The get_random_file_name method returns a cryptographically strong, random string that can be used as either a folder name or a file name. Unlike GetTempFileName, get_random_file_name does not create a file. When the security of your file system is paramount, this method should be used instead of GetTempFileName.
      static xtd::ustring get_random_file_name();
            
      /// @brief Creates a uniquely named, zero-byte temporary file on disk and returns the full path of that file.
      /// @return The full path of the temporary file.
      /// @remarks This method creates a temporary file with a .TMP file extension. The temporary file is created within the user’s temporary folder, which is the path returned by the GetTempPath method.
      /// @remarks The GetTempFileName method will raise an IOException if it is used to create more than 65535 files without deleting previous temporary files.
      /// @remarks The GetTempFileName method will raise an IOException if no unique temporary file name is available. To resolve this error, delete all unneeded temporary files.
      static xtd::ustring get_temp_file_name();
      
      /// @brief Returns the path of the current user's temporary folder.
      /// @return string The path to the temporary folder, ending with a backslash.
      /// @remarks This method checks for the existence of environment variables in the following order and uses the first path found:
      /// * The path specified by the TMP environment variable.
      /// * The path specified by the TEMP environment variable.
      /// * The path specified by the USERPROFILE environment variable.
      /// * The Windows directory.
      static xtd::ustring get_temp_path() noexcept;
      
      /// @brief Determines whether a path includes a file name extension.
      /// @param path The path to search for an extension.
      /// @return true if the characters that follow the last directory separator (\\ or /)
      /// @return or volume separator (:) in the path include a period (.) followed by one
      /// @return or more characters; otherwise, false.
      static bool has_extension(const xtd::ustring& path);
      
      /// @brief Gets a value indicating whether the specified path string contains absolute or relative path information.
      /// @param path The path to test.
      /// @return true if path contains an absolute path; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns false regardless of the existence of path.
      static bool is_path_rooted(const xtd::ustring& path);
      
      /// @brief A platform-specific separator character used to separate path strings in environment variables.
      /// @par Examples
      /// The following code example demonstrates the use of the PathSeparator() property.
      /// @include directory_separator_char.cpp
      template<typename char_t>
      static char_t path_separator() noexcept {return static_cast<char_t>(path_separator());}
      
      /// @brief A platform-specific separator character used to separate path strings in environment variables.
      /// @par Examples
      /// The following code example demonstrates the use of the PathSeparator() property.
      /// @include directory_separator_char.cpp
      static char path_separator() noexcept;
      
      /// @brief Provides a platform-specific volume separator character.
      /// @par Examples
      /// The following code example demonstrates the use of the volume_separator_char() property.
      /// @include directory_separator_char.cpp
      template<typename char_t>
      static char_t volume_separator_char() noexcept {return  static_cast<char_t>(volume_separator_char());}
      
      /// @brief Provides a platform-specific volume separator character.
      /// @par Examples
      /// The following code example demonstrates the use of the volume_separator_char() property.
      /// @include directory_separator_char.cpp
      static char volume_separator_char() noexcept;
      
    private:
      static int __get_index_path_rooted(const xtd::ustring& path);
      static bool __is_drive(const xtd::ustring& path) noexcept;      
    };
  }
}
