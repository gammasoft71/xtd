/// @file
/// @brief Contains xtd::io::file class.
#pragma once

#include "file_attributes.hpp"
#include <cstdio>
#include <fstream>
#include <string>
#include <vector>

/// @cond
int __get_file_attributes(const char*path);
/// @endcond

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::IO namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::basic_ftream objects.
    class file {
    public:
      /// @cond
      file() = delete;
      /// @endcond
      
      /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename Char, typename T>
      static bool append_all_lines(const std::basic_string<Char>& path, T contents) noexcept {
        try {
          std::basic_ofstream<Char> file(path, std::ios::app);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename Char, typename T>
      static bool append_all_lines(const Char* path, T contents) noexcept {return append_all_lines(std::basic_string<Char>(path), contents);}
      /// @endcond
      
      /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename Char, typename T>
      static bool append_all_lines(const std::basic_string<Char>& path, const std::initializer_list<T>& contents) noexcept {
        try {
          std::basic_ofstream<Char> file(path, std::ios::app);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename Char, typename T>
      static bool append_all_lines(const Char* path, const std::initializer_list<T>& contents) noexcept {return append_all_lines(std::basic_string<Char>(path), contents);}
      /// @endcond
      
      
      /// @brief Appends text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename Char, typename T>
      static bool append_all_text(const std::basic_string<Char>& path, T text) noexcept {
        try {
          std::basic_ofstream<Char> file(path, std::ios::app);
          file << text;
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename Char, typename T>
      static bool append_all_text(const Char* path, T text) noexcept {return append_all_text(std::basic_string<Char>(path), text);}
      /// @endcond
      
      /// @brief Creates a std::basic_ofstream that appends text to an existing file.
      /// @param path The path to the file to append to.
      /// @return A std::basic_ofstream that appends text to an existing file.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename Char>
      static std::basic_ofstream<Char> append_text(const std::basic_string<Char>& path) noexcept {
        try {
          return std::basic_ofstream<Char>(path, std::ios::app);
        } catch(...) {
          return std::basic_ofstream<Char>();
        }
      }
      
      /// @cond
      template<typename Char>
      static std::basic_ofstream<Char> append_text(const Char* path) noexcept {return append_text(std::basic_string<Char>(path));}
      /// @endcond
      
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is not allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory or an existing file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename Char>
      static bool copy(const std::basic_string<Char>& src, const std::basic_string<Char>& dest) {return copy(src, dest, true);}
      
      /// @cond
      template<typename Char>
      static bool copy(const Char* src, const Char* dest) {return copy(std::basic_string<Char>(src), std::basic_string<Char>(dest));}
      template<typename Char>
      static bool copy(const std::basic_string<Char>& src, const Char* dest) {return copy(src, std::basic_string<Char>(dest));}
      template<typename Char>
      static bool copy(const Char* src, const std::basic_string<Char> dest) {return copy(src, std::basic_string<Char>(dest));}
      /// @endcond
      
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory.
      /// @param overwrite true if the destination file can be overwritten; otherwise, false.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename Char>
      static bool copy(const std::basic_string<Char>& src, const std::basic_string<Char>& dest, bool overwrite) {
        try {
          if (exists(dest) && overwrite == false) return false;
          std::basic_ifstream<Char> file_src(src, std::ios::binary);
          std::basic_ofstream<Char> file_dest(dest, std::ios::binary);
          file_dest << file_src.rdbuf();
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename Char>
      static bool copy(const Char* src, const Char* dest, bool overwrite) {return copy(std::basic_string<Char>(src), std::basic_string<Char>(dest), overwrite);}
      template<typename Char>
      static bool copy(const std::basic_string<Char>& src, const Char* dest, bool overwrite) {return copy(src, std::basic_string<Char>(dest), overwrite);}
      template<typename Char>
      static bool copy(const Char* src, const std::basic_string<Char> dest, bool overwrite) {return copy(src, std::basic_string<Char>(dest), overwrite);}
      /// @endcond

      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::basic_ofstream that provides read/write access to the file specified in path.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename Char>
      static std::basic_ofstream<Char> create(const std::basic_string<Char>& path) noexcept {
        try {
          return std::basic_ofstream<Char>(path, std::ios::binary | std::ios::out);
        } catch(...) {
          return std::basic_ofstream<Char>();
        }
      }
      
      /// @cond
      template<typename Char>
      static std::basic_ofstream<Char> create(const Char* path) noexcept {return create(std::basic_string<Char>(path));}
      /// @endcond
      
      /// @brief Creates or opens a file for writing text.
      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::basic_ofstream that provides read/write access to the file specified in path.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename Char>
      static std::basic_ofstream<Char> create_text(const std::basic_string<Char>& path) noexcept {
        try {
          return std::basic_ofstream<Char>(path);
        } catch(...) {
          return std::basic_ofstream<Char>();
        }
      }
      
      /// @cond
      template<typename Char>
      static std::basic_ofstream<Char> create_text(const Char* path) noexcept {return create_text(std::basic_string<Char>(path));}
      /// @endcond
      
      /// @brief Determines whether the specified file exists.
      /// @param path The file to check.
      /// @return true if the caller has the required permissions and path contains the name of an existing file; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns false regardless of the existence of path.
      template<typename Char>
      static bool exists(const std::basic_string<Char>& path) noexcept {
        try {
          return std::basic_ifstream<Char> {path}.good();
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename Char>
      static bool exists(const Char* path) noexcept {return exists(std::basic_string<Char>(path));}
      /// @endcond
      
      /// @brief Gets the xtd::io::file_attributes of the file on the path.
      /// @param src The path to the file.
      /// @return The xtd::io::file_attributes of the file on the path.
      /// @remarks Return (xtd::io::file_attributes)-1, if src is string empty or src contains one or more of the invalid characters or the system could not retrieve the absolute path.
      template<typename Char>
      static xtd::io::file_attributes get_attributes(const std::basic_string<Char>& src) noexcept {
        return get_attributes(src.c_str());
      }
      
      /// @cond
      template<typename Char>
      static xtd::io::file_attributes get_attributes(const Char* path) noexcept {
        return (xtd::io::file_attributes)__get_file_attributes(path);
      }
      /// @endcond
      
      /// @brief Moves a specified file to a new location, providing the option to specify a new file name.
      /// @param src The name of the file to move.
      /// @param dest The new path for the file.
      /// @return true if the file moved; otherwise, false.
      /// @remarks This method also returns false if dest already exist.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename Char>
      static bool move(const std::basic_string<Char>& src, const std::basic_string<Char>& dest) noexcept {return move(src.c_str(), dest.c_str());}
      
      /// @cond
      template<typename Char>
      static bool move(const Char* src, const Char* dest) noexcept {
        try {
          if (exists(dest)) return false;
          return rename(src, dest) == 0;
        } catch(...) {
          return false;
        }
      }
      /// @endcond
      
      /// @brief Opens a FileStream on the specified path.
      /// @param path The file to open.
      /// @param mode A std::ios::openmode value that specifies whether a file is created if one does not exist, and determines whether the contents of existing files are retained or overwritten.
      /// @return A std::basic_fstream on the specified path.
      /// @remarks This method also returns an empty std::basic_fstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_fstream if the caller has not the required permissions.
      template<typename Char>
      static std::basic_fstream<Char> open(const std::basic_string<Char>& path, std::ios::openmode mode) noexcept {
        try {
          return std::basic_fstream<Char>(path, mode);
        } catch(...) {
          return std::basic_fstream<Char>();
        }
      }
      
      /// @cond
      template<typename Char>
      static std::basic_fstream<Char> open(const Char* path, std::ios::openmode mode) noexcept {return open(std::basic_string<Char>(path), mode);}
      /// @endcond
      
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::basic_ifstream on the specified path.
      /// @remarks This method also returns an empty std::basic_ifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ifstream if the caller has not the required permissions.
      template<typename Char>
      static std::basic_ifstream<Char> open_read(const std::basic_string<Char>& path) noexcept {
        try {
          return std::basic_ifstream<Char>(path, std::ios::binary | std::ios::in);
        } catch(...) {
          return std::basic_ifstream<Char>();
        }
      }
      
      /// @cond
      template<typename Char>
      static std::basic_ifstream<Char> open_read(const Char* path) noexcept {return open_read(std::basic_string<Char>(path));}
      /// @endcond
      
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::basic_ifstream on the specified path.
      /// @remarks This method also returns an empty std::basic_ifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ifstream if the caller has not the required permissions.
      template<typename Char>
      static std::basic_ifstream<Char> open_text(const std::basic_string<Char>& path) noexcept {
        try {
          return std::basic_ifstream<Char>(path);
        } catch(...) {
          return std::basic_ifstream<Char>();
        }
      }
      
      /// @cond
      template<typename Char>
      static std::basic_ifstream<Char> open_text(const Char* path) noexcept {return open_text(std::basic_string<Char>(path));}
      /// @endcond
      
      /// @brief Opens an existing file for writing.
      /// @param path The file to be opened for writing.
      /// @return A std::basic_ofstream on the specified path.
      /// @remarks This method also returns an empty std::basic_oifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename Char>
      static std::basic_ofstream<Char> open_write(const std::basic_string<Char>& path) noexcept {
        try {
          return std::basic_ofstream<Char>(path, std::ios::binary | std::ios::out);
        } catch(...) {
          return std::basic_ofstream<Char>();
        }
      }
      
      /// @cond
      template<typename Char>
      static std::basic_ofstream<Char> open_write(const Char* path) noexcept {return open_write(std::basic_string<Char>(path));}
      /// @endcond
      
      template<typename Char>
      static std::vector<unsigned char> read_all_bytes(const std::basic_string<Char>& path) noexcept {
        try {
          std::ifstream file(path, std::ios::binary);
          return std::vector<unsigned char> {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
        } catch(...) {
          return {};
        }
      }
      
      template<typename Char>
      static std::vector<unsigned char> read_all_bytes(const Char* path) noexcept {return read_all_bytes(std::basic_string<Char>(path));}
      
      /// @brief Opens a text file, reads all lines of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A String array containing all lines of the file.
      /// @remarks This method also returns an empty array if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns an empty array regardless of the existence of path.
      template<typename Char>
      static std::vector<std::basic_string<Char>> read_all_lines(const std::basic_string<Char>& path) noexcept {
        try {
          std::vector<std::basic_string<Char>> contents;
          std::ifstream file(path);
          std::string line;
          while(std::getline(file, line))
            contents.push_back(line);
          return contents;
        } catch(...) {
          return {};
        }
      }
      
      /// @cond
      template<typename Char>
      static std::vector<std::basic_string<Char>> read_all_lines(const Char* path) noexcept {return read_all_lines(std::basic_string<Char>(path));}
      /// @endcond
      
      /// @brief Opens a text file, reads all text of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A dstring containing all text of the file.
      /// @remarks This method also returns empty string if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns empty string regardless of the existence of file.
      template<typename Char>
      static std::basic_string<Char> read_all_text(const std::basic_string<Char>& path) noexcept {
        try {
          std::ifstream file(path);
          return std::basic_string<Char> {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
        } catch(...) {
          return {};
        }
      }
      
      /// @cond
      template<typename Char>
      static std::basic_string<Char> read_all_text(const Char* path) noexcept {return read_all_text(std::basic_string<Char>(path));}
      /// @endcond
      
      /// @brief Deletes the specified file.
      /// @param path The name of the file to be deleted.
      /// @return std::basic_ofstream An unshared std::basic_ofstream that provides access to the specified file, with the specified mode and access.
      /// @return true if the file is deleted; otherwise, false.
      template<typename Char>
      static bool remove(const std::basic_string<Char>& path) noexcept {return remove(path.c_str());}
      
      /// @cond
      template<typename Char>
      static bool remove(const Char* path) noexcept {return ::remove(path) == 0;}
      /// @endcond
      
      /// @brief Replaces the contents of a specified file with the contents of another file, deleting the original file, and creating a backup of the replaced file and optionally ignores merge errors.
      /// @param source_file_name The name of a file that replaces the file specified by destination_file_name.
      /// @param destination_file_name The name of the file being replaced.
      /// @param destination_backup_file_name The name of the backup file.
      /// @param ignore_metadata_errors true to ignore merge errors (such as attributes and access control lists (ACLs)) from the replaced file to the replacement file; otherwise, false.
      /// @return false source_file_name does not exist or bad format, or destination_file_name does not exist or bad format, or if ignore_metadata_errors equal false and destination_backup_file_name bad format or on ani io error; otherwise true.
      template<typename Char>
      static bool replace(const std::basic_string<Char>& source_file_name, const std::basic_string<Char>& destination_file_name, const std::basic_string<Char>& destination_backup_file_name, bool ignore_metadata_errors) noexcept {
        if (!exists(source_file_name) || !exists(destination_file_name)) return false;
        if (!copy(destination_file_name, destination_backup_file_name) && ignore_metadata_errors == false) return false;
        if (!file::remove(destination_file_name) && ignore_metadata_errors == false) return false;
        return move(source_file_name, destination_file_name);
      }
      
      /// @cond
      template<typename Char>
      static bool replace(const Char* source_file_name, const Char* destination_file_name, const Char* destination_backup_file_name, bool ignore_metadata_errors) noexcept {return replace(std::basic_string<Char>(source_file_name), std::basic_string<Char>(destination_file_name), std::basic_string<Char>(destination_backup_file_name), ignore_metadata_errors);}
      template<typename Char>
      static bool replace(const std::basic_string<Char>& source_file_name, const Char* destination_file_name, const Char* destination_backup_file_name, bool ignore_metadata_errors) noexcept {return replace(source_file_name, std::basic_string<Char>(destination_file_name), std::basic_string<Char>(destination_backup_file_name), ignore_metadata_errors);}
      template<typename Char>
      static bool replace(const Char* source_file_name, const std::basic_string<Char>& destination_file_name, const Char* destination_backup_file_name, bool ignore_metadata_errors) noexcept {return replace(std::basic_string<Char>(source_file_name), destination_file_name, std::basic_string<Char>(destination_backup_file_name), ignore_metadata_errors);}
      template<typename Char>
      static bool replace(const Char* source_file_name, const Char* destination_file_name, const std::basic_string<Char>& destination_backup_file_name, bool ignore_metadata_errors) noexcept {return replace(std::basic_string<Char>(source_file_name), std::basic_string<Char>(destination_file_name), destination_backup_file_name, ignore_metadata_errors);}
      template<typename Char>
      static bool replace(const std::basic_string<Char>& source_file_name, const std::basic_string<Char>& destination_file_name, const Char* destination_backup_file_name, bool ignore_metadata_errors) noexcept {return replace(source_file_name, destination_file_name, std::basic_string<Char>(destination_backup_file_name), ignore_metadata_errors);}
      template<typename Char>
      static bool replace(const std::basic_string<Char>& source_file_name, const Char* destination_file_name, const std::basic_string<Char>&destination_backup_file_name, bool ignore_metadata_errors) noexcept {return replace(source_file_name, std::basic_string<Char>(destination_file_name), destination_backup_file_name, ignore_metadata_errors);}
      template<typename Char>
      static bool replace(const Char* source_file_name, const std::basic_string<Char>& destination_file_name, const std::basic_string<Char>& destination_backup_file_name, bool ignore_metadata_errors) noexcept {return replace(std::basic_string<Char>(source_file_name), destination_file_name, destination_backup_file_name, ignore_metadata_errors);}
      /// @endcond
      
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename Char, typename T>
      static bool write_all_lines(const std::basic_string<Char>& path, T contents) noexcept {
        try {
          std::basic_ofstream<Char> file(path);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename Char, typename T>
      static bool write_all_lines(const Char* path, T contents) noexcept {return write_all_lines(std::basic_string<Char>(path), contents);}
      /// @endcond
      
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename Char, typename T>
      static bool write_all_lines(const std::basic_string<Char>& path, const std::initializer_list<T>& contents) noexcept {
        try {
          std::basic_ofstream<Char> file(path);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename Char, typename T>
      static bool write_all_lines(const Char* path, const std::initializer_list<T>& contents) noexcept {return write_all_lines(std::basic_string<Char>(path), contents);}
      /// @endcond
      
      
      /// @brief Writes text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename Char, typename T>
      static bool write_all_text(const std::basic_string<Char>& path, T text) noexcept {
        try {
          std::basic_ofstream<Char> file(path);
          file << text;
          return true;
        } catch(...) {
          return false;
        }
      }
      
      /// @cond
      template<typename Char, typename T>
      static bool write_all_text(const Char* path, T text) noexcept {return write_all_lines(std::basic_string<Char>(path), text);}
      /// @endcond
      
      /// @brief Creates a std::basic_ofstream that appends text to an existing file.
      /// @param path The path to the file to write to.
      /// @return A std::basic_ofstream that writes text to an existing file.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename Char>
      static std::basic_ofstream<Char> write_text(const std::basic_string<Char>& path) noexcept {
        try {
          return std::basic_ofstream<Char>(path);
        } catch(...) {
          return std::basic_ofstream<Char>();
        }
      }
      
      /// @cond
      template<typename Char>
      static std::basic_ofstream<Char> write_text(const Char* path) noexcept {return write_text(std::basic_string<Char>(path));}
      /// @endcond
    };
  }
}
