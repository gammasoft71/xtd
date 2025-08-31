/// @file
/// @brief Contains directory API.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "file_attribute.hpp"
#include <xtd/core_native_export>
#include <cstdint>
#include <iterator>
#include <memory>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace io {
    class directory;
    class directory_info;
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @cond
    class drive;
    class file_system;
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
      friend drive;
      friend file_system;
      friend xtd::io::directory;
      friend xtd::io::directory_info;
      
    public:
      /// @brief Represent directory iterator used by xtd::native::directory::enumerate_directories.
      /// @warning Internal use only
      class core_native_export_ directory_iterator {
        struct data;
        
        explicit directory_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        using iterator_category = std::input_iterator_tag;
        using value_type = std::string;
        using difference_type = std::string;
        using pointer = std::string*;
        using reference = std::string&;
        
        directory_iterator();
        directory_iterator(const directory_iterator&) = default;
        directory_iterator(directory_iterator&&) = default;
        ~directory_iterator();
        
        directory_iterator& operator ++();
        directory_iterator operator ++(int32_t);
        bool operator ==(directory_iterator other) const;
        bool operator !=(directory_iterator other) const {return !operator ==(other);}
        value_type operator *() const;
        
        xtd::native::directory::directory_iterator begin() const;
        xtd::native::directory::directory_iterator end() const;
        
        const std::string& path() const;
        const std::string& pattern() const;
        /// @endcond
        
      private:
        friend xtd::io::directory_info;
        friend xtd::native::directory;
        
        std::shared_ptr<data> data_;
      };
      
      /// @brief Represent file iterator used by xtd::native::directory::enumerate_files.
      /// @warning Internal use only
      class core_native_export_ file_iterator {
        struct data;
        
        explicit file_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        using iterator_category = std::input_iterator_tag;
        using value_type = std::string;
        using difference_type = std::string;
        using pointer = std::string*;
        using reference = std::string&;
        
        file_iterator();
        file_iterator(const file_iterator&) = default;
        file_iterator(file_iterator&&) = default;
        ~file_iterator();
        
        file_iterator& operator ++();
        file_iterator operator ++(int32_t);
        bool operator ==(file_iterator other) const;
        bool operator !=(file_iterator other) const {return !operator ==(other);}
        value_type operator *() const;
        xtd::native::directory::file_iterator begin() const;
        xtd::native::directory::file_iterator end() const;
        
        const std::string& path() const;
        const std::string& pattern() const;
        /// @endcond
        
      private:
        friend xtd::io::directory_info;
        friend xtd::native::directory;
        
        std::shared_ptr<data> data_;
      };
      
      /// @brief Represent file iterator used by xtd::native::directory::enumerate_files.
      /// @warning Internal use only
      class core_native_export_ file_and_directory_iterator {
        struct data;
        
        explicit file_and_directory_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        using iterator_category = std::input_iterator_tag;
        using value_type = std::string;
        using difference_type = std::string;
        using pointer = std::string*;
        using reference = std::string&;
        
        file_and_directory_iterator();
        file_and_directory_iterator(const file_and_directory_iterator&) = default;
        file_and_directory_iterator(file_and_directory_iterator&&) = default;
        ~file_and_directory_iterator();
        
        file_and_directory_iterator& operator ++();
        file_and_directory_iterator operator ++(int32_t);
        bool operator ==(file_and_directory_iterator other) const;
        bool operator !=(file_and_directory_iterator other) const {return !operator ==(other);}
        value_type operator *() const;
        xtd::native::directory::file_and_directory_iterator begin() const;
        xtd::native::directory::file_and_directory_iterator end() const;
        
        const std::string& path() const;
        const std::string& pattern() const;
        /// @endcond
        
      private:
        friend xtd::io::directory_info;
        friend xtd::native::directory;
        
        std::shared_ptr<data> data_;
      };
      
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Creates all directories and subdirectories in the specified path unless they already exist.
      /// @param directory_name The directory to create.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static std::int32_t create(const std::string& directory_name);
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
      /// @brief Check if specified directory exist.
      /// @param path The diretory path to check.
      /// @return `true` is file exist; otherwise `false`.
      /// @warning Internal use only
      static bool exists(const std::string& path);
      /// @brief Gets the current directory.
      /// @return The currrent directory.
      /// @remarks On error the return value is an empty string ("").
      /// @warning Internal use only
      static std::string get_current_directory();
      /// @brief Deletes an empty directory from a specified path.
      /// @param directory_name The name of the empty directory to remove. This directory must be writable and empty.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static std::int32_t remove(const std::string& directory_name);
      /// @brief Sets the current directory.
      /// @param dirrectory_name The currrent directory.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static std::int32_t set_current_directory(const std::string& directory_name);
      /// @}
    };
  }
}
