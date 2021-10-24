/// @file
/// @brief Contains xtd::io::directory_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <iterator>
#include "file_system_info.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    class file_info;
    /// @endcond

    /// @brief Exposes instance methods for creating, moving, and enumerating through directories and subdirectories. This class cannot be inherited.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @par Example
    /// The following example demonstrates some of the main members of the xtd::io::directory_info class.
    /// @cond
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
    /// @endcond
    /// @par Example
    /// The following example demonstrates how to copy a directory and its contents.
    /// @cond
    /// #include <xtd/xtd>
    ///
    /// using namespace xtd;
    /// using namespace xtd::io;
    ///
    /// class copy_dir {
    /// public:
    ///   static void copy_all(const directory_info& source, const directory_info& target) {
    ///     if (source.full_name().to_lower() == target.full_name().to_lower()) {
    ///       return;
    ///     }
    ///
    ///     // Check if the target directory exists, if not, create it.
    ///     if (directory::exists(target.full_name()) == false) {
    ///       directory::create_directory(target.full_name());
    ///     }
    ///
    ///     // Copy each file into it's new directory.
    ///     for (file_info fi : source.get_files()) {
    ///       console::write_line("Copying {0}\\{1}", target.full_name(), fi.name());
    ///       fi.copy_to(path::combine(target.to_string(), fi.name()), true);
    ///     }
    ///
    ///     // Copy each subdirectory using recursion.
    ///     for (directory_info di_source_sub_dir : source.get_directories()) {
    ///       directory_info next_target_sub_dir = target.create_subdirectory(di_source_sub_dir.name());
    ///       copy_all(di_source_sub_dir, next_target_sub_dir);
    ///     }
    ///   }
    ///
    ///   static void main() {
    ///     ustring source_directory = "c:\\source_directory";
    ///     ustring target_directory = "c:\\target_directory";
    ///
    ///     directory_info di_source(source_directory);
    ///     directory_info di_target(target_directory);
    ///
    ///     copy_all(di_source, di_target);
    ///   }
    /// };
    ///
    /// startup_(copy_dir);
    ///
    /// // Output will vary based on the contents of the source directory.
    /// @endcond
    /// @remarks Use the xtd::io::directory_info class for typical operations such as copying, moving, renaming, creating, and deleting directories.
    /// @remarks If you are going to reuse an object several times, consider using the instance method of xtd::io::directory_info instead of the corresponding static methods of the xtd::io::directory class, because a security check will not always be necessary.
    /// @note In members that accept a path as an input string, that path must be well-formed or an exception is raised. For example, if a path is fully qualified but begins with a space, the path is not trimmed in methods of the class. Therefore, the path is malformed and an exception is raised. Similarly, a path or a combination of paths cannot be fully qualified twice. For example, "c:\temp c:\windows" also raises an exception in most cases. Ensure that your paths are well-formed when using methods that accept a path string.
    /// @remarks In members that accept a path, the path can refer to a file or just a directory. The specified path can also refer to a relative path or a Universal Naming Convention (UNC) path for a server and share name. For example, all the following are acceptable paths:
    /// * "c:\\MyDir\\MyFile.txt" in C#, or "c:\MyDir\MyFile.txt" in Visual Basic.
    /// * "c:\\MyDir" in C#, or "c:\MyDir" in Visual Basic.
    /// * "MyDir\\MySubdir" in C#, or "MyDir\MySubDir" in Visual Basic.
    /// * "\\\\MyServer\\MyShare" in C#, or "\\MyServer\MyShare" in Visual Basic.
    /// @remarks By default, full read/write access to new directories is granted to all users.
    /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
    class core_export_ directory_info final : public xtd::io::file_system_info {
    public:
      /// @brief Represent directory iterator used by xtd::io::directtory_info.
      class directory_iterator : public std::iterator<std::input_iterator_tag, xtd::io::directory_info> {
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
        friend xtd::io::directory_info;
        struct data;
        std::shared_ptr<data> data_;
      };

      /// @brief Represent file iterator used by xtd::io::directtory_info.
      class file_iterator : public std::iterator<std::input_iterator_tag, xtd::io::file_info> {
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
        friend xtd::io::directory_info;
        struct data;
        std::shared_ptr<data> data_;
      };

      /// @brief Represent file iterator used by xtd::io::directtory_info.
      class file_system_iterator : public std::iterator<std::input_iterator_tag, xtd::io::file_info> {
        explicit file_system_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        file_system_iterator();
        file_system_iterator(const file_system_iterator&) = default;
        file_system_iterator(file_system_iterator&&) = default;
        
        file_system_iterator& operator++();
        file_system_iterator operator++(int);
        bool operator==(file_system_iterator other) const;
        bool operator!=(file_system_iterator other) const {return !operator==(other);}
        value_type operator*() const;
        /// @endcond
        
      private:
        friend xtd::io::directory_info;
        struct data;
        std::shared_ptr<data> data_;
      };

      static const directory_info empty;
      
      /// @brief Initializes a new instance of the xtd::io::directory_info class on the specified path.
      /// @param path A string specifying the path on which to create the xtd::io::directory_info.
      ///
      directory_info(const xtd::ustring& path);
      
      bool exists() const override;

      size_t length() const;

      xtd::ustring name() const override;
      
      xtd::io::directory_info parent() const;
      
      xtd::io::directory_info root() const;
      
      void create();
      
      xtd::io::directory_info create_subdirectory(const xtd::ustring& path);
      
      xtd::io::directory_info::directory_iterator enumerate_directories() const;
      xtd::io::directory_info::directory_iterator enumerate_directories(const xtd::ustring& pattern) const;
      
      xtd::io::directory_info::file_iterator enumerate_files() const;
      xtd::io::directory_info::file_iterator enumerate_files(const xtd::ustring& pattern) const;
      
      xtd::io::directory_info::file_system_iterator enumerate_File_system_infos() const;
      xtd::io::directory_info::file_system_iterator enumerate_File_system_infos(const xtd::ustring& pattern) const;

      void remove() override;
      
      void remove(bool recursive);
      
    private:
      directory_info() = default;
    };
  }
}

namespace std {
  inline xtd::io::directory_info::directory_iterator begin(xtd::io::directory_info::directory_iterator it) {return it;}
  inline xtd::io::directory_info::directory_iterator end(xtd::io::directory_info::directory_iterator it) {return xtd::io::directory_info::directory_iterator();}
  inline xtd::io::directory_info::file_iterator begin(xtd::io::directory_info::file_iterator it) {return it;}
  inline xtd::io::directory_info::file_iterator end(xtd::io::directory_info::file_iterator it) {return xtd::io::directory_info::file_iterator();}
  inline xtd::io::directory_info::file_system_iterator begin(xtd::io::directory_info::file_system_iterator it) {return it;}
  inline xtd::io::directory_info::file_system_iterator end(xtd::io::directory_info::file_system_iterator it) {return xtd::io::directory_info::file_system_iterator();}
}
