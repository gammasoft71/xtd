/// @file
/// @brief Contains xtd::io::file class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <cstdint>
#include <cstdio>
#include <fstream>
#include <vector>
#include <filesystem>
#include "../core_export.h"
#include "../static.h"
#include "../ustring.h"
#include "file_attributes.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::ftream objects.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ file static_ {
    public:
      /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static bool append_all_lines(const xtd::ustring& path, type_t contents) noexcept {
        try {
          std::ofstream file(path, std::ios::app);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static bool append_all_lines(const xtd::ustring& path, const std::initializer_list<type_t>& contents) noexcept {
        try {
          std::ofstream file(path, std::ios::app);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename char_t, typename type_t>
      static bool append_all_lines(const char_t* path, const std::initializer_list<type_t>& contents) noexcept {return append_all_lines(xtd::ustring(path), contents);}
      /// @endcond
      
      
      /// @brief Appends text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename type_t>
      static bool append_all_text(const xtd::ustring& path, type_t text) noexcept {
        try {
          std::ofstream file(path, std::ios::app);
          file << text;
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename char_t, typename type_t>
      static bool append_all_text(const char_t* path, type_t text) noexcept {return append_all_text(xtd::ustring(path), text);}
      /// @endcond
      
      /// @brief Creates a std::ofstream that appends text to an existing file.
      /// @param path The path to the file to append to.
      /// @return A std::ofstream that appends text to an existing file.
      /// @remarks This method also returns an empty std::ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::ofstream if the caller has not the required permissions.
      static std::ofstream append_text(const xtd::ustring& path) noexcept;
      
      /// @cond
      template<typename char_t>
      static std::ofstream append_text(const char_t* path) noexcept {return append_text(xtd::ustring(path));}
      /// @endcond
      
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is not allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory or an existing file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      static bool copy(const xtd::ustring& src, const xtd::ustring& dest);
  
      /// @cond
      template<typename char_t>
      static bool copy(const char_t* src, const char_t* dest) {return copy(xtd::ustring(src), xtd::ustring(dest));}
      template<typename char_t>
      static bool copy(const xtd::ustring& src, const char_t* dest) {return copy(src, xtd::ustring(dest));}
      template<typename char_t>
      static bool copy(const char_t* src, const xtd::ustring& dest) {return copy(xtd::ustring(src), dest);}
      /// @endcond
      
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory.
      /// @param overwrite true if the destination file can be overwritten; otherwise, false.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      static bool copy(const xtd::ustring& src, const xtd::ustring& dest, bool overwrite);
      
      /// @cond
      template<typename char_t>
      static bool copy(const char_t* src, const char_t* dest, bool overwrite) {return copy(xtd::ustring(src), xtd::ustring(dest), overwrite);}
      template<typename char_t>
      static bool copy(const xtd::ustring& src, const char_t* dest, bool overwrite) {return copy(src, xtd::ustring(dest), overwrite);}
      template<typename char_t>
      static bool copy(const char_t* src, const xtd::ustring& dest, bool overwrite) {return copy(xtd::ustring(src), dest, overwrite);}
      /// @endcond

      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::ofstream that provides read/write access to the file specified in path.
      /// @remarks This method also returns an empty std::ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::ofstream if the caller has not the required permissions.
      static std::ofstream create(const xtd::ustring& path) noexcept;

      /// @cond
      template<typename char_t>
      static std::ofstream create(const char_t* path) noexcept {return create(xtd::ustring(path));}
      /// @endcond
      
      /// @brief Creates or opens a file for writing text.
      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::ofstream that provides read/write access to the file specified in path.
      /// @remarks This method also returns an empty std::ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::ofstream if the caller has not the required permissions.
      static std::ofstream create_text(const xtd::ustring& path) noexcept;

      /// @cond
      template<typename char_t>
      static std::ofstream create_text(const char_t* path) noexcept {return create_text(xtd::ustring(path));}
      /// @endcond
      
      /// @brief Determines whether the specified file exists.
      /// @param path The file to check.
      /// @return true if the caller has the required permissions and path contains the name of an existing file; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns false regardless of the existence of path.
      static bool exists(const xtd::ustring& path) noexcept;

      /// @cond
      template<typename char_t>
      static bool exists(const char_t* path) noexcept {return exists(xtd::ustring(path));}
      /// @endcond
      
      /// @brief Gets the xtd::io::file_attributes of the file on the path.
      /// @param src The path to the file.
      /// @return The xtd::io::file_attributes of the file on the path.
      /// @remarks Return (xtd::io::file_attributes)-1, if src is string empty or src contains one or more of the invalid characters or the system could not retrieve the absolute path.
      static xtd::io::file_attributes get_attributes(const xtd::ustring& src) noexcept;

      /// @cond
      template<typename char_t>
      static xtd::io::file_attributes get_attributes(const char_t* path) noexcept {
        return get_attributes(xtd::ustring(path));
      }
      /// @endcond
      
      /// @brief Moves a specified file to a new location, providing the option to specify a new file name.
      /// @param src The name of the file to move.
      /// @param dest The new path for the file.
      /// @return true if the file moved; otherwise, false.
      /// @remarks This method also returns false if dest already exist.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      static bool move(const xtd::ustring& src, const xtd::ustring& dest) noexcept;
    
      /// @cond
      template<typename char_t>
      static bool move(const char_t* src, const char_t* dest) noexcept {
        try {
          if (exists(dest)) return false;
#if defined(__cpp_lib_filesystem)
          std::filesystem::rename(src, dest);
          return true;
#else
          return ::rename(src, dest) == 0;
#endif
        } catch(...) {
          return false;
        }
      }
      /// @endcond
      
      /// @brief Opens a FileStream on the specified path.
      /// @param path The file to open.
      /// @param mode A std::ios::openmode value that specifies whether a file is created if one does not exist, and determines whether the contents of existing files are retained or overwritten.
      /// @return A std::fstream on the specified path.
      /// @remarks This method also returns an empty std::fstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::fstream if the caller has not the required permissions.
      static std::fstream open(const xtd::ustring& path, std::ios::openmode mode) noexcept;

      /// @cond
      template<typename char_t>
      static std::fstream open(const char_t* path, std::ios::openmode mode) noexcept {return open(xtd::ustring(path), mode);}
      /// @endcond
      
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::ifstream on the specified path.
      /// @remarks This method also returns an empty std::ifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::ifstream if the caller has not the required permissions.
      static std::ifstream open_read(const xtd::ustring& path) noexcept;
      
      /// @cond
      template<typename char_t>
      static std::ifstream open_read(const char_t* path) noexcept {return open_read(xtd::ustring(path));}
      /// @endcond
      
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::ifstream on the specified path.
      /// @remarks This method also returns an empty std::ifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::ifstream if the caller has not the required permissions.
      static std::ifstream open_text(const xtd::ustring& path) noexcept;

      /// @cond
      template<typename char_t>
      static std::ifstream open_text(const char_t* path) noexcept {return open_text(xtd::ustring(path));}
      /// @endcond
      
      /// @brief Opens an existing file for writing.
      /// @param path The file to be opened for writing.
      /// @return A std::ofstream on the specified path.
      /// @remarks This method also returns an empty std::oifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::ofstream if the caller has not the required permissions.
      static std::ofstream open_write(const xtd::ustring& path) noexcept;
    
      /// @cond
      template<typename char_t>
      static std::ofstream open_write(const char_t* path) noexcept {return open_write(xtd::ustring(path));}
      /// @endcond
      
      static std::vector<uint8_t> read_all_bytes(const xtd::ustring& path) noexcept;

      template<typename char_t>
      static std::vector<uint8_t> read_all_bytes(const char_t* path) noexcept {return read_all_bytes(xtd::ustring(path));}
      
      /// @brief Opens a text file, reads all lines of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A String array containing all lines of the file.
      /// @remarks This method also returns an empty array if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns an empty array regardless of the existence of path.
      static std::vector<xtd::ustring> read_all_lines(const xtd::ustring& path) noexcept;

      /// @cond
      template<typename char_t>
      static std::vector<xtd::ustring> read_all_lines(const char_t* path) noexcept {return read_all_lines(xtd::ustring(path));}
      /// @endcond
      
      /// @brief Opens a text file, reads all text of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A dstring containing all text of the file.
      /// @remarks This method also returns empty string if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns empty string regardless of the existence of file.
      static xtd::ustring read_all_text(const xtd::ustring& path) noexcept;

      /// @cond
      template<typename char_t>
      static xtd::ustring read_all_text(const char_t* path) noexcept {return read_all_text(xtd::ustring(path));}
      /// @endcond
      
      /// @brief Deletes the specified file.
      /// @param path The name of the file to be deleted.
      /// @return std::ofstream An unshared std::ofstream that provides access to the specified file, with the specified mode and access.
      /// @return true if the file is deleted; otherwise, false.
      static bool remove(const xtd::ustring& path) noexcept;
      
      /// @cond
      template<typename char_t>
      static bool remove(const char_t* path) noexcept {
        return ::remove(path) == 0;
      }
      /// @endcond
      
      /// @brief Replaces the contents of a specified file with the contents of another file, deleting the original file, and creating a backup of the replaced file and optionally ignores merge errors.
      /// @param source_file_name The name of a file that replaces the file specified by destination_file_name.
      /// @param destination_file_name The name of the file being replaced.
      /// @param destination_backup_file_name The name of the backup file.
      /// @param ignore_metadata_errors true to ignore merge errors (such as attributes and access control lists (ACLs)) from the replaced file to the replacement file; otherwise, false.
      /// @return false source_file_name does not exist or bad format, or destination_file_name does not exist or bad format, or if ignore_metadata_errors equal false and destination_backup_file_name bad format or on ani io error; otherwise true.
      static bool replace(const xtd::ustring& source_file_name, const xtd::ustring& destination_file_name, const xtd::ustring& destination_backup_file_name) noexcept;

      /// @cond
      template<typename char_t>
      static bool replace(const char_t* source_file_name, const char_t* destination_file_name, const char_t* destination_backup_file_name) noexcept {return replace(xtd::ustring(source_file_name), xtd::ustring(destination_file_name), xtd::ustring(destination_backup_file_name));}
      template<typename char_t>
      static bool replace(const xtd::ustring& source_file_name, const char_t* destination_file_name, const char_t* destination_backup_file_name) noexcept {return replace(source_file_name, xtd::ustring(destination_file_name), xtd::ustring(destination_backup_file_name));}
      template<typename char_t>
      static bool replace(const char_t* source_file_name, const xtd::ustring& destination_file_name, const char_t* destination_backup_file_name) noexcept {return replace(xtd::ustring(source_file_name), destination_file_name, xtd::ustring(destination_backup_file_name));}
      template<typename char_t>
      static bool replace(const char_t* source_file_name, const char_t* destination_file_name, const xtd::ustring& destination_backup_file_name) noexcept {return replace(xtd::ustring(source_file_name), xtd::ustring(destination_file_name), destination_backup_file_name);}
      template<typename char_t>
      static bool replace(const xtd::ustring& source_file_name, const xtd::ustring& destination_file_name, const char_t* destination_backup_file_name) noexcept {return replace(source_file_name, destination_file_name, xtd::ustring(destination_backup_file_name));}
      template<typename char_t>
      static bool replace(const xtd::ustring& source_file_name, const char_t* destination_file_name, const xtd::ustring& destination_backup_file_name) noexcept {return replace(source_file_name, xtd::ustring(destination_file_name), destination_backup_file_name);}
      template<typename char_t>
      static bool replace(const char_t* source_file_name, const xtd::ustring& destination_file_name, const xtd::ustring& destination_backup_file_name) noexcept {return replace(xtd::ustring(source_file_name), destination_file_name, destination_backup_file_name);}
      /// @endcond
      
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static bool write_all_lines(const xtd::ustring& path, type_t contents) noexcept {
        try {
          std::ofstream file(path);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
 
      /// @cond
      template<typename char_t, typename type_t>
      static bool write_all_lines(const char_t* path, type_t contents) noexcept {return write_all_lines(xtd::ustring(path), contents);}
      /// @endcond
      
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static bool write_all_lines(const xtd::ustring& path, const std::initializer_list<type_t>& contents) noexcept {
        try {
          std::ofstream file(path);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }

      /// @cond
      template<typename char_t, typename type_t>
      static bool write_all_lines(const char_t* path, const std::initializer_list<type_t>& contents) noexcept {return write_all_lines(xtd::ustring(path), contents);}
      /// @endcond
      
      /// @brief Writes text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename type_t>
      static bool write_all_text(const xtd::ustring& path, type_t text) noexcept {
        try {
          std::ofstream file(path);
          file << text;
          return true;
        } catch(...) {
          return false;
        }
      }
   
      /// @cond
      template<typename char_t, typename type_t>
      static bool write_all_text(const char_t* path, type_t text) noexcept {return write_all_text(xtd::ustring(path), text);}
      /// @endcond
      
      /// @brief Creates a std::ofstream that appends text to an existing file.
      /// @param path The path to the file to write to.
      /// @return A std::ofstream that writes text to an existing file.
      /// @remarks This method also returns an empty std::ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::ofstream if the caller has not the required permissions.
      static std::ofstream write_text(const xtd::ustring& path) noexcept;

      /// @cond
      template<typename char_t>
      static std::ofstream write_text(const char_t* path) noexcept {return write_text(xtd::ustring(path));}
      /// @endcond
    };
  }
}
