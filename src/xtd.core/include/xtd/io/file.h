/// @file
/// @brief Contains xtd::io::file class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <cstdio>
#include <fstream>
#include <string>
#include <vector>
#include <filesystem>
#include "../core_export.h"
#include "file_attributes.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of files, and aids in the creation of std::basic_ftream objects.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    class core_export_ file {
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
      template<typename char_t, typename type_t>
      static bool append_all_lines(const std::basic_string<char_t>& path, type_t contents) noexcept {
        try {
          std::basic_ofstream<char_t> file(path, std::ios::app);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
      
#if defined(__cpp_lib_filesystem)
      /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static bool append_all_lines(const std::filesystem::path& path, type_t contents) noexcept {
        try {
        std::ofstream file(path, std::ios::app);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
#endif
      
      /// @cond
      template<typename char_t, typename type_t>
      static bool append_all_lines(const char_t* path, type_t contents) noexcept {return append_all_lines(std::basic_string<char_t>(path), contents);}
      /// @endcond
      
      /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename char_t, typename type_t>
      static bool append_all_lines(const std::basic_string<char_t>& path, const std::initializer_list<type_t>& contents) noexcept {
        try {
          std::basic_ofstream<char_t> file(path, std::ios::app);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Appends lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static bool append_all_lines(const std::filesystem::path& path, const std::initializer_list<type_t>& contents) noexcept {
        try {
          std::ofstream file(path, std::ios::app);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
#endif
      
      /// @cond
      template<typename char_t, typename type_t>
      static bool append_all_lines(const char_t* path, const std::initializer_list<type_t>& contents) noexcept {return append_all_lines(std::basic_string<char_t>(path), contents);}
      /// @endcond
      
      
      /// @brief Appends text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename char_t, typename type_t>
      static bool append_all_text(const std::basic_string<char_t>& path, type_t text) noexcept {
        try {
          std::basic_ofstream<char_t> file(path, std::ios::app);
          file << text;
          return true;
        } catch(...) {
          return false;
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Appends text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to append to the file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename type_t>
      static bool append_all_text(const std::filesystem::path& path, type_t text) noexcept {
        try {
          std::ofstream file(path, std::ios::app);
          file << text;
          return true;
        } catch(...) {
          return false;
        }
      }
#endif
      
      /// @cond
      template<typename char_t, typename type_t>
      static bool append_all_text(const char_t* path, type_t text) noexcept {return append_all_text(std::basic_string<char_t>(path), text);}
      /// @endcond
      
      /// @brief Creates a std::basic_ofstream that appends text to an existing file.
      /// @param path The path to the file to append to.
      /// @return A std::basic_ofstream that appends text to an existing file.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename char_t>
      static std::basic_ofstream<char_t> append_text(const std::basic_string<char_t>& path) noexcept {
        try {
          return std::basic_ofstream<char_t>(path, std::ios::app);
        } catch(...) {
          return std::basic_ofstream<char_t>();
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Creates a std::basic_ofstream that appends text to an existing file.
      /// @param path The path to the file to append to.
      /// @return A std::basic_ofstream that appends text to an existing file.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      static std::ofstream append_text(const std::filesystem::path& path) noexcept {
        try {
          return std::ofstream(path, std::ios::app);
        } catch(...) {
          return std::ofstream();
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static std::basic_ofstream<char_t> append_text(const char_t* path) noexcept {return append_text(std::basic_string<char_t>(path));}
      /// @endcond
      
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is not allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory or an existing file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename char_t>
      static bool copy(const std::basic_string<char_t>& src, const std::basic_string<char_t>& dest) {return copy(src, dest, true);}
  
#if defined(__cpp_lib_filesystem)
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is not allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory or an existing file.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      static bool copy(const std::filesystem::path& src, const std::filesystem::path& dest) {return copy(src, dest, true);}
#endif
      
      /// @cond
      template<typename char_t>
      static bool copy(const char_t* src, const char_t* dest) {return copy(std::basic_string<char_t>(src), std::basic_string<char_t>(dest));}
      template<typename char_t>
      static bool copy(const std::basic_string<char_t>& src, const char_t* dest) {return copy(src, std::basic_string<char_t>(dest));}
      template<typename char_t>
      static bool copy(const char_t* src, const std::basic_string<char_t> dest) {return copy(src, std::basic_string<char_t>(dest));}
      /// @endcond
      
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory.
      /// @param overwrite true if the destination file can be overwritten; otherwise, false.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename char_t>
      static bool copy(const std::basic_string<char_t>& src, const std::basic_string<char_t>& dest, bool overwrite) {
        try {
          if (exists(dest) && overwrite == false) return false;
#if defined(__cpp_lib_filesystem)
          std::filesystem::copy(src, dest, std::filesystem::copy_options::overwrite_existing);
          return true;
#else
          std::basic_ifstream<char_t> file_src(src, std::ios::binary);
          std::basic_ofstream<char_t> file_dest(dest, std::ios::binary);
          file_dest << file_src.rdbuf();
          return true;
#endif
        }
        catch (...) {
          return false;
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Copies an existing file to a new file. Overwriting a file of the same name is allowed.
      /// @param src The file to be opened for reading.
      /// @param dest The name of the destination file. This cannot be a directory.
      /// @param overwrite true if the destination file can be overwritten; otherwise, false.
      /// @return true if the text appended; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
       static bool copy(const std::filesystem::path& src, const std::filesystem::path& dest, bool overwrite) {
        try {
          if (std::filesystem::exists(dest) && overwrite == false) return false;
          std::ifstream file_src(src, std::ios::binary);
          std::ofstream file_dest(dest, std::ios::binary);
          file_dest << file_src.rdbuf();
          return true;
        } catch(...) {
          return false;
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static bool copy(const char_t* src, const char_t* dest, bool overwrite) {return copy(std::basic_string<char_t>(src), std::basic_string<char_t>(dest), overwrite);}
      template<typename char_t>
      static bool copy(const std::basic_string<char_t>& src, const char_t* dest, bool overwrite) {return copy(src, std::basic_string<char_t>(dest), overwrite);}
      template<typename char_t>
      static bool copy(const char_t* src, const std::basic_string<char_t> dest, bool overwrite) {return copy(src, std::basic_string<char_t>(dest), overwrite);}
      /// @endcond

      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::basic_ofstream that provides read/write access to the file specified in path.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename char_t>
      static std::basic_ofstream<char_t> create(const std::basic_string<char_t>& path) noexcept {
        try {
          return std::basic_ofstream<char_t>(path, std::ios::binary | std::ios::out);
        } catch(...) {
          return std::basic_ofstream<char_t>();
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::basic_ofstream that provides read/write access to the file specified in path.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      static std::ofstream create(const std::filesystem::path& path) noexcept {
        try {
          return std::ofstream(path, std::ios::binary | std::ios::out);
        } catch(...) {
          return std::ofstream();
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static std::basic_ofstream<char_t> create(const char_t* path) noexcept {return create(std::basic_string<char_t>(path));}
      /// @endcond
      
      /// @brief Creates or opens a file for writing text.
      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::basic_ofstream that provides read/write access to the file specified in path.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename char_t>
      static std::basic_ofstream<char_t> create_text(const std::basic_string<char_t>& path) noexcept {
        try {
          return std::basic_ofstream<char_t>(path);
        } catch(...) {
          return std::basic_ofstream<char_t>();
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Creates or opens a file for writing text.
      /// @brief Creates or overwrites a file in the specified path.
      /// @param The path and name of the file to create.
      /// @return A std::basic_ofstream that provides read/write access to the file specified in path.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      static std::ofstream create_text(const std::filesystem::path& path) noexcept {
        try {
          return std::ofstream(path);
        } catch(...) {
          return std::ofstream();
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static std::basic_ofstream<char_t> create_text(const char_t* path) noexcept {return create_text(std::basic_string<char_t>(path));}
      /// @endcond
      
      /// @brief Determines whether the specified file exists.
      /// @param path The file to check.
      /// @return true if the caller has the required permissions and path contains the name of an existing file; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns false regardless of the existence of path.
      template<typename char_t>
      static bool exists(const std::basic_string<char_t>& path) noexcept {
        try {
          return std::basic_ifstream<char_t> {path}.good();
        } catch(...) {
          return false;
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Determines whether the specified file exists.
      /// @param path The file to check.
      /// @return true if the caller has the required permissions and path contains the name of an existing file; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns false regardless of the existence of path.
      static bool exists(const std::filesystem::path& path) noexcept {
        try {
          return std::ifstream {path}.good();
        } catch(...) {
          return false;
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static bool exists(const char_t* path) noexcept {return exists(std::basic_string<char_t>(path));}
      /// @endcond
      
      /// @brief Gets the xtd::io::file_attributes of the file on the path.
      /// @param src The path to the file.
      /// @return The xtd::io::file_attributes of the file on the path.
      /// @remarks Return (xtd::io::file_attributes)-1, if src is string empty or src contains one or more of the invalid characters or the system could not retrieve the absolute path.
      template<typename char_t>
      static xtd::io::file_attributes get_attributes(const std::basic_string<char_t>& src) noexcept {
        return get_attributes(src.c_str());
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Gets the xtd::io::file_attributes of the file on the path.
      /// @param src The path to the file.
      /// @return The xtd::io::file_attributes of the file on the path.
      /// @remarks Return (xtd::io::file_attributes)-1, if src is string empty or src contains one or more of the invalid characters or the system could not retrieve the absolute path.
      static xtd::io::file_attributes get_attributes(const std::filesystem::path& src) noexcept {
        return get_attributes(src.string().c_str());
      }
#endif

      /// @cond
      template<typename char_t>
      static xtd::io::file_attributes get_attributes(const char_t* path) noexcept {
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
      template<typename char_t>
      static bool move(const std::basic_string<char_t>& src, const std::basic_string<char_t>& dest) noexcept {return move(src.c_str(), dest.c_str());}
    
#if defined(__cpp_lib_filesystem)
      /// @brief Moves a specified file to a new location, providing the option to specify a new file name.
      /// @param src The name of the file to move.
      /// @param dest The new path for the file.
      /// @return true if the file moved; otherwise, false.
      /// @remarks This method also returns false if dest already exist.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      static bool move(const std::filesystem::path& src, const std::filesystem::path& dest) noexcept {return move(src.string(), dest.string());}
#endif
      
      /// @cond
      template<typename char_t>
      static bool move(const char_t* src, const char_t* dest) noexcept {
        try {
          if (exists(dest)) return false;
#if defined(__cpp_lib_filesystem)
          std::filesystem::rename(src, dest);
          return true;
#else
          return rename(src, dest) == 0;
#endif
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
      template<typename char_t>
      static std::basic_fstream<char_t> open(const std::basic_string<char_t>& path, std::ios::openmode mode) noexcept {
        try {
          return std::basic_fstream<char_t>(path, mode);
        } catch(...) {
          return std::basic_fstream<char_t>();
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Opens a FileStream on the specified path.
      /// @param path The file to open.
      /// @param mode A std::ios::openmode value that specifies whether a file is created if one does not exist, and determines whether the contents of existing files are retained or overwritten.
      /// @return A std::basic_fstream on the specified path.
      /// @remarks This method also returns an empty std::basic_fstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_fstream if the caller has not the required permissions.
      static std::fstream open(const std::filesystem::path& path, std::ios::openmode mode) noexcept {
        try {
          return std::fstream(path, mode);
        } catch(...) {
          return std::fstream();
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static std::basic_fstream<char_t> open(const char_t* path, std::ios::openmode mode) noexcept {return open(std::basic_string<char_t>(path), mode);}
      /// @endcond
      
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::basic_ifstream on the specified path.
      /// @remarks This method also returns an empty std::basic_ifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ifstream if the caller has not the required permissions.
      template<typename char_t>
      static std::basic_ifstream<char_t> open_read(const std::basic_string<char_t>& path) noexcept {
        try {
          return std::basic_ifstream<char_t>(path, std::ios::binary | std::ios::in);
        } catch(...) {
          return std::basic_ifstream<char_t>();
        }
      }
      
#if defined(__cpp_lib_filesystem)
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::basic_ifstream on the specified path.
      /// @remarks This method also returns an empty std::basic_ifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ifstream if the caller has not the required permissions.
      static std::ifstream open_read(const std::filesystem::path& path) noexcept {
        try {
          return std::ifstream(path, std::ios::binary | std::ios::in);
        } catch(...) {
          return std::ifstream();
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static std::basic_ifstream<char_t> open_read(const char_t* path) noexcept {return open_read(std::basic_string<char_t>(path));}
      /// @endcond
      
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::basic_ifstream on the specified path.
      /// @remarks This method also returns an empty std::basic_ifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ifstream if the caller has not the required permissions.
      template<typename char_t>
      static std::basic_ifstream<char_t> open_text(const std::basic_string<char_t>& path) noexcept {
        try {
          return std::basic_ifstream<char_t>(path);
        } catch(...) {
          return std::basic_ifstream<char_t>();
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Opens an existing file for reading.
      /// @param path The file to be opened for reading.
      /// @return A std::basic_ifstream on the specified path.
      /// @remarks This method also returns an empty std::basic_ifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ifstream if the caller has not the required permissions.
      static std::ifstream open_text(const std::filesystem::path& path) noexcept {
        try {
          return std::ifstream(path);
        } catch(...) {
          return std::ifstream();
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static std::basic_ifstream<char_t> open_text(const char_t* path) noexcept {return open_text(std::basic_string<char_t>(path));}
      /// @endcond
      
      /// @brief Opens an existing file for writing.
      /// @param path The file to be opened for writing.
      /// @return A std::basic_ofstream on the specified path.
      /// @remarks This method also returns an empty std::basic_oifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename char_t>
      static std::basic_ofstream<char_t> open_write(const std::basic_string<char_t>& path) noexcept {
        try {
          return std::basic_ofstream<char_t>(path, std::ios::binary | std::ios::out);
        } catch(...) {
          return std::basic_ofstream<char_t>();
        }
      }
    
#if defined(__cpp_lib_filesystem)
      /// @brief Opens an existing file for writing.
      /// @param path The file to be opened for writing.
      /// @return A std::basic_ofstream on the specified path.
      /// @remarks This method also returns an empty std::basic_oifstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      static std::ofstream open_write(const std::filesystem::path& path) noexcept {
        try {
          return std::ofstream(path, std::ios::binary | std::ios::out);
        } catch(...) {
          return std::ofstream();
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static std::basic_ofstream<char_t> open_write(const char_t* path) noexcept {return open_write(std::basic_string<char_t>(path));}
      /// @endcond
      
      template<typename char_t>
      static std::vector<unsigned char> read_all_bytes(const std::basic_string<char_t>& path) noexcept {
        try {
          std::ifstream file(path, std::ios::binary);
          return std::vector<unsigned char> {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
        } catch(...) {
          return {};
        }
      }

#if defined(__cpp_lib_filesystem)
      static std::vector<unsigned char> read_all_bytes(const std::filesystem::path& path) noexcept {
        try {
          std::ifstream file(path, std::ios::binary);
          return std::vector<unsigned char> {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
        } catch(...) {
          return {};
        }
      }
#endif
      
      template<typename char_t>
      static std::vector<unsigned char> read_all_bytes(const char_t* path) noexcept {return read_all_bytes(std::basic_string<char_t>(path));}
      
      /// @brief Opens a text file, reads all lines of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A String array containing all lines of the file.
      /// @remarks This method also returns an empty array if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns an empty array regardless of the existence of path.
      template<typename char_t>
      static std::vector<std::basic_string<char_t>> read_all_lines(const std::basic_string<char_t>& path) noexcept {
        try {
          std::vector<std::basic_string<char_t>> contents;
          std::basic_ifstream<char_t> file(path);
          std::basic_string<char_t> line;
          while(std::getline(file, line))
            contents.push_back(line);
          return contents;
        } catch(...) {
          return {};
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Opens a text file, reads all lines of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A String array containing all lines of the file.
      /// @remarks This method also returns an empty array if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns an empty array regardless of the existence of path.
      static std::vector<std::string> read_all_lines(const std::filesystem::path& path) noexcept {
        try {
          std::vector<std::string> contents;
          std::ifstream file(path);
          std::string line;
          while(std::getline(file, line))
            contents.push_back(line);
          return contents;
        } catch(...) {
          return {};
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static std::vector<std::basic_string<char_t>> read_all_lines(const char_t* path) noexcept {return read_all_lines(std::basic_string<char_t>(path));}
      /// @endcond
      
      /// @brief Opens a text file, reads all text of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A dstring containing all text of the file.
      /// @remarks This method also returns empty string if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns empty string regardless of the existence of file.
      template<typename char_t>
      static std::basic_string<char_t> read_all_text(const std::basic_string<char_t>& path) noexcept {
        try {
          std::basic_ifstream<char_t> file(path);
          return std::basic_string<char_t> {std::istreambuf_iterator<char_t>(file), std::istreambuf_iterator<char_t>()};
        } catch(...) {
          return {};
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Opens a text file, reads all text of the file, and then closes the file.
      /// @param path The file to open for reading.
      /// @return A dstring containing all text of the file.
      /// @remarks This method also returns empty string if path is empty or an invalid path.
      /// @remarks If the caller does not have sufficient permissions to read the specified file, no exception is thrown and the method returns empty string regardless of the existence of file.
      static std::string read_all_text(const std::filesystem::path& path) noexcept {
        try {
          std::ifstream file(path);
          return std::string {std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()};
        } catch(...) {
          return {};
        }
      }
#endif

      /// @cond
      template<typename char_t>
      static std::basic_string<char_t> read_all_text(const char_t* path) noexcept {return read_all_text(std::basic_string<char_t>(path));}
      /// @endcond
      
      /// @brief Deletes the specified file.
      /// @param path The name of the file to be deleted.
      /// @return std::basic_ofstream An unshared std::basic_ofstream that provides access to the specified file, with the specified mode and access.
      /// @return true if the file is deleted; otherwise, false.
      template<typename char_t>
      static bool remove(const std::basic_string<char_t>& path) noexcept {return remove(path.c_str());}
      
#if defined(__cpp_lib_filesystem)
      /// @brief Deletes the specified file.
      /// @param path The name of the file to be deleted.
      /// @return std::basic_ofstream An unshared std::basic_ofstream that provides access to the specified file, with the specified mode and access.
      /// @return true if the file is deleted; otherwise, false.
      static bool remove(const std::filesystem::path& path) noexcept {return remove(path.string());}
#endif

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
      template<typename char_t>
      static bool replace(const std::basic_string<char_t>& source_file_name, const std::basic_string<char_t>& destination_file_name, const std::basic_string<char_t>& destination_backup_file_name) noexcept {
        if (!exists(source_file_name) || !exists(destination_file_name)) return false;
        if (!copy(destination_file_name, destination_backup_file_name)) return false;
        if (!remove(destination_file_name)) return false;
        return move(source_file_name, destination_file_name);
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Replaces the contents of a specified file with the contents of another file, deleting the original file, and creating a backup of the replaced file and optionally ignores merge errors.
      /// @param source_file_name The name of a file that replaces the file specified by destination_file_name.
      /// @param destination_file_name The name of the file being replaced.
      /// @param destination_backup_file_name The name of the backup file.
      /// @param ignore_metadata_errors true to ignore merge errors (such as attributes and access control lists (ACLs)) from the replaced file to the replacement file; otherwise, false.
      /// @return false source_file_name does not exist or bad format, or destination_file_name does not exist or bad format, or if ignore_metadata_errors equal false and destination_backup_file_name bad format or on ani io error; otherwise true.
      static bool replace(const std::filesystem::path& source_file_name, const std::filesystem::path destination_file_name, const std::filesystem::path& destination_backup_file_name) noexcept {
        if (!std::filesystem::exists(source_file_name) || !std::filesystem::exists(destination_file_name)) return false;
        if (!copy(destination_file_name, destination_backup_file_name)) return false;
        if (!remove(destination_file_name)) return false;
        return move(source_file_name, destination_file_name);
      }
#endif

      /// @cond
      template<typename char_t>
      static bool replace(const char_t* source_file_name, const char_t* destination_file_name, const char_t* destination_backup_file_name) noexcept {return replace(std::basic_string<char_t>(source_file_name), std::basic_string<char_t>(destination_file_name), std::basic_string<char_t>(destination_backup_file_name));}
      template<typename char_t>
      static bool replace(const std::basic_string<char_t>& source_file_name, const char_t* destination_file_name, const char_t* destination_backup_file_name) noexcept {return replace(source_file_name, std::basic_string<char_t>(destination_file_name), std::basic_string<char_t>(destination_backup_file_name));}
      template<typename char_t>
      static bool replace(const char_t* source_file_name, const std::basic_string<char_t>& destination_file_name, const char_t* destination_backup_file_name) noexcept {return replace(std::basic_string<char_t>(source_file_name), destination_file_name, std::basic_string<char_t>(destination_backup_file_name));}
      template<typename char_t>
      static bool replace(const char_t* source_file_name, const char_t* destination_file_name, const std::basic_string<char_t>& destination_backup_file_name) noexcept {return replace(std::basic_string<char_t>(source_file_name), std::basic_string<char_t>(destination_file_name), destination_backup_file_name);}
      template<typename char_t>
      static bool replace(const std::basic_string<char_t>& source_file_name, const std::basic_string<char_t>& destination_file_name, const char_t* destination_backup_file_name) noexcept {return replace(source_file_name, destination_file_name, std::basic_string<char_t>(destination_backup_file_name));}
      template<typename char_t>
      static bool replace(const std::basic_string<char_t>& source_file_name, const char_t* destination_file_name, const std::basic_string<char_t>&destination_backup_file_name) noexcept {return replace(source_file_name, std::basic_string<char_t>(destination_file_name), destination_backup_file_name);}
      template<typename char_t>
      static bool replace(const char_t* source_file_name, const std::basic_string<char_t>& destination_file_name, const std::basic_string<char_t>& destination_backup_file_name) noexcept {return replace(std::basic_string<char_t>(source_file_name), destination_file_name, destination_backup_file_name);}
      /// @endcond
      
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename char_t, typename type_t>
      static bool write_all_lines(const std::basic_string<char_t>& path, type_t contents) noexcept {
        try {
          std::basic_ofstream<char_t> file(path);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
 
#if defined(__cpp_lib_filesystem)
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static bool write_all_lines(const std::filesystem::path& path, type_t contents) noexcept {
        try {
          std::ofstream file(path);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
#endif

      /// @cond
      template<typename char_t, typename type_t>
      static bool write_all_lines(const char_t* path, type_t contents) noexcept {return write_all_lines(std::basic_string<char_t>(path), contents);}
      /// @endcond
      
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename char_t, typename type_t>
      static bool write_all_lines(const std::basic_string<char_t>& path, const std::initializer_list<type_t>& contents) noexcept {
        try {
          std::basic_ofstream<char_t> file(path);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Writes lines to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The lines to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      /// @remarks If the target file already exists, it is overwritten.
      template<typename type_t>
      static bool write_all_lines(const std::filesystem::path& path, const std::initializer_list<type_t>& contents) noexcept {
        try {
          std::ofstream file(path);
          for (const auto& line : contents)
            file << line << std::endl;
          return true;
        } catch(...) {
          return false;
        }
      }
#endif

      /// @cond
      template<typename char_t, typename type_t>
      static bool write_all_lines(const char_t* path, const std::initializer_list<type_t>& contents) noexcept {return write_all_lines(std::basic_string<char_t>(path), contents);}
      /// @endcond
      
      /// @brief Writes text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename char_t, typename type_t>
      static bool write_all_text(const std::basic_string<char_t>& path, type_t text) noexcept {
        try {
          std::basic_ofstream<char_t> file(path);
          file << text;
          return true;
        } catch(...) {
          return false;
        }
      }
   
#if defined(__cpp_lib_filesystem)
      /// @brief Writes text to a file, and then closes the file. If the specified file does not exist, this method creates a file, writes the specified lines to the file, and then closes the file.
      /// @param path The file to write to.
      /// @param contents The text to write to the file.
      /// @return true if the text written; otherwise, false.
      /// @remarks This method also returns false if path is empty or an invalid path.
      /// @remarks This method also returns false if the caller has not the required permissions.
      template<typename type_t>
      static bool write_all_text(const std::filesystem::path& path, type_t text) noexcept {
        try {
          std::ofstream file(path);
          file << text;
          return true;
        } catch(...) {
          return false;
        }
      }
#endif
      
      /// @cond
      template<typename char_t, typename type_t>
      static bool write_all_text(const char_t* path, type_t text) noexcept {return write_all_text(std::basic_string<char_t>(path), text);}
      /// @endcond
      
      /// @brief Creates a std::basic_ofstream that appends text to an existing file.
      /// @param path The path to the file to write to.
      /// @return A std::basic_ofstream that writes text to an existing file.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      template<typename char_t>
      static std::basic_ofstream<char_t> write_text(const std::basic_string<char_t>& path) noexcept {
        try {
          return std::basic_ofstream<char_t>(path);
        } catch(...) {
          return std::basic_ofstream<char_t>();
        }
      }

#if defined(__cpp_lib_filesystem)
      /// @brief Creates a std::basic_ofstream that appends text to an existing file.
      /// @param path The path to the file to write to.
      /// @return A std::basic_ofstream that writes text to an existing file.
      /// @remarks This method also returns an empty std::basic_ofstream if path is empty or an invalid path.
      /// @remarks This method also returns an empty std::basic_ofstream if the caller has not the required permissions.
      static std::ofstream write_text(const std::filesystem::path& path) noexcept {
        try {
          return std::ofstream(path);
        } catch(...) {
          return std::ofstream();
        }
      }
#endif
      
      /// @cond
      template<typename char_t>
      static std::basic_ofstream<char_t> write_text(const char_t* path) noexcept {return write_text(std::basic_string<char_t>(path));}
      /// @endcond
      
    private:
      static int __get_file_attributes(const char*path);
    };
  }
}
