/// @file
/// @brief Contains directory API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <chrono>
#include <cstdint>
#include <iterator>
#include <memory>
#include <string>
#include <vector>
#include "file_attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace io {
    class directory;
    class directory_info;
    class file_info;
    class file_system_info;
  }
  /// @endcond
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @cond
    class drive;
    /// @endcond
    
    /// @brief Contains directory native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ directory final {
      directory() = delete;
    public:
      /// @brief Represent directory iterator used by xtd::native::directtory::enumerate_directories.
      /// @warning Internal use only
      class directory_iterator : public std::iterator<std::input_iterator_tag, std::string> {
        explicit directory_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        directory_iterator();
        directory_iterator(const directory_iterator&) = default;
        directory_iterator(directory_iterator&&) = default;
        ~directory_iterator();

        directory_iterator& operator++();
        directory_iterator operator++(int);
        bool operator==(directory_iterator other) const;
        bool operator!=(directory_iterator other) const {return !operator==(other);}
        value_type operator*() const;
        /// @endcond
        
      private:
        friend xtd::io::directory_info;
        friend xtd::native::directory;
        struct data;
        std::shared_ptr<data> data_;
      };
      
      /// @brief Represent file iterator used by xtd::native::directtory::enumerate_files.
      /// @warning Internal use only
      class file_iterator : public std::iterator<std::input_iterator_tag, std::string> {
        explicit file_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        file_iterator();
        file_iterator(const file_iterator&) = default;
        file_iterator(file_iterator&&) = default;
        ~file_iterator();
        
        file_iterator& operator++();
        file_iterator operator++(int);
        bool operator==(file_iterator other) const;
        bool operator!=(file_iterator other) const {return !operator==(other);}
        value_type operator*() const;
        /// @endcond
        
      private:
        friend xtd::io::directory_info;
        friend xtd::native::directory;
        struct data;
        std::shared_ptr<data> data_;
      };
      
      /// @brief Represent file iterator used by xtd::native::directtory::enumerate_files.
      /// @warning Internal use only
      class file_and_directory_iterator : public std::iterator<std::input_iterator_tag, std::string> {
        explicit file_and_directory_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        file_and_directory_iterator();
        file_and_directory_iterator(const file_and_directory_iterator&) = default;
        file_and_directory_iterator(file_and_directory_iterator&&) = default;
        ~file_and_directory_iterator();
        
        file_and_directory_iterator& operator++();
        file_and_directory_iterator operator++(int);
        bool operator==(file_and_directory_iterator other) const;
        bool operator!=(file_and_directory_iterator other) const {return !operator==(other);}
        value_type operator*() const;
        /// @endcond
        
      private:
        friend xtd::io::directory_info;
        friend xtd::native::directory;
        struct data;
        std::shared_ptr<data> data_;
      };

    protected:
      friend directory_iterator;
      friend drive;
      friend file_iterator;
      friend xtd::io::directory;
      friend xtd::io::directory_info;
      friend xtd::io::file_info;
      friend xtd::io::file_system_info;

      /// @brief Copy a specified source file to a target file.
      /// @param source_file The source file to copy.
      /// @param target_file The target file where copy.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t copy_file(const std::string& source_file, const std::string& target_file);
      /// @brief Creates all directories and subdirectories in the specified path unless they already exist.
      /// @param directory_name The directory to create.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t create_directory(const std::string& directory_name);
      /// @brief Returns an enumerable collection of directory full names that match a search pattern in a specified path.
      /// @param path The relative or absolute path to the directory to search.
      /// @param pattern The search string to match against the names of directories in path. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An iterator of the full names (including paths) for the directories in the directory specified by path and that match the specified search pattern.
      /// @warning Internal use only
      static directory_iterator enumerate_directories(const std::string& path, const std::string& pattern);
      /// @brief Returns an iterator of full file names that match a search pattern in a specified path.
      /// @param path The relative or absolute path to the directory to search.
      /// @param pattern The search string to match against the names of files in path. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An iterator of the full names (including paths) for the files in the directory specified by path and that match the specified search pattern.
      /// @warning Internal use only
      static file_iterator enumerate_files(const std::string& path, const std::string& pattern);
      /// @brief Returns an iterator of full file names and full direcctory names that match a search pattern in a specified path.
      /// @param path The relative or absolute path to the directory to search.
      /// @param pattern The search string to match against the names of files in path. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An iterator of the full names (including paths) for the files in the directory specified by path and that match the specified search pattern.
      /// @warning Internal use only
      static file_and_directory_iterator enumerate_files_and_directories(const std::string& path, const std::string& pattern);
      /// @brief Get the current directory.
      /// @return The currrent directory.
      /// @warning Internal use only
      static std::string get_current_directory();
      /// @brief Gets the attributes for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param attribute The file or path attribute. (see file_attribute.h)
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t get_file_attributes(const std::string& path, int32_t& attributes);
      /// @brief Get file size of specified path.
      /// @param path The relative or absolute path to the directory to get size.
      /// @return The file size.
      /// @warning Internal use only
      static size_t get_file_size(const std::string& path);
      /// @brief Get file creeation time, last access time and lastt write time of specified path.
      /// @param path The relative or absolute path to the directory to get times.
      /// @param creation_time That contains the creation time.
      /// @param last_access_time That contains the last access time.
      /// @param last_write_time That contains the last write time.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t get_file_times(const std::string& path, std::chrono::system_clock::time_point& creation_time, std::chrono::system_clock::time_point& last_access_time, std::chrono::system_clock::time_point& last_write_time);
      /// @brief Get full path of specified path.
      /// @param relative_path The relative path to the directory to search.
      /// @return The fulll path.
      /// @warning Internal use only
      static std::string get_full_path(const std::string& relative_path);
      /// @brief Moves a file or a directory and its contents to a new location.
      /// @param old_path The path of the file or directory to move.
      /// @param new_path The path to the new location for old_path. If old_path is a file, then new_path must also be a file name.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t move_file(const std::string& old_path, const std::string& new_path);
      /// @brief Deletes an empty directory from a specified path.
      /// @param directory_name The name of the empty directory to remove. This directory must be writable and empty.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t remove_directory(const std::string& directory_name);
      /// @brief Permanently deletes a speccified file.
      /// @param file The file name to delete.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t remove_file(const std::string& file);
      /// @brief Set the current directory.
      /// @param dirrectory_name The currrent directory.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int32_t set_current_directory(const std::string& directory_name);
      /// @brief Sets the creation time for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param creation_time The file or path creation time.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int32_t set_creation_time(const std::string& path, std::chrono::system_clock::time_point& creation_time);
      /// @brief Sets the attributes for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param attribute The file or path attribute. (see file_attribute.h)
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int32_t set_file_attributes(const std::string& path, int32_t attributes);
      /// @brief Sets the last access time for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param last_access_time The file or path last access time.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int32_t set_last_access_time(const std::string& path, std::chrono::system_clock::time_point& last_access_time);
      /// @brief Sets the last write time for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param last_write_time The file or path last write time.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int32_t set_last_write_time(const std::string& path, std::chrono::system_clock::time_point& last_write_time);
    };
  }
}

namespace std {
  inline xtd::native::directory::directory_iterator begin(xtd::native::directory::directory_iterator it) {return it;}
  inline xtd::native::directory::directory_iterator end(xtd::native::directory::directory_iterator it) {return xtd::native::directory::directory_iterator();}
  inline xtd::native::directory::file_iterator begin(xtd::native::directory::file_iterator it) {return it;}
  inline xtd::native::directory::file_iterator end(xtd::native::directory::file_iterator it) {return xtd::native::directory::file_iterator();}
  inline xtd::native::directory::file_and_directory_iterator begin(xtd::native::directory::file_and_directory_iterator it) {return it;}
  inline xtd::native::directory::file_and_directory_iterator end(xtd::native::directory::file_and_directory_iterator it) {return xtd::native::directory::file_and_directory_iterator();}
}
