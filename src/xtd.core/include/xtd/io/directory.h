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
    /// @brief Provides static methods for the creation, copying, deletion, moving, and opening of Directories, and aids in the creation of xtd::io::directory_stream objects.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
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

      static xtd::io::directory_info create_directory(const xtd::ustring& path);
      
      static xtd::io::directory::directory_iterator enumerate_directories(const xtd::ustring& path);
      static xtd::io::directory::directory_iterator enumerate_directories(const xtd::ustring& path, const xtd::ustring& search_pattern);
      
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
