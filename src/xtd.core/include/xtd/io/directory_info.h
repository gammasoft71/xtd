/// @file
/// @brief Contains xtd::io::directory_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <iterator>
#include <memory>
#include "file_system_info.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    class directory;
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
    /// @code
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
    /// @endcode
    /// @par Example
    /// The following example demonstrates how to copy a directory and its contents.
    /// @code
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
    /// @endcode
    /// @remarks Use the xtd::io::directory_info class for typical operations such as copying, moving, renaming, creating, and deleting directories.
    /// @remarks If you are going to reuse an object several times, consider using the instance method of xtd::io::directory_info instead of the corresponding static methods of the xtd::io::directory class, because a security check will not always be necessary.
    /// @note In members that accept a path as an input string, that path must be well-formed or an exception is raised. For example, if a path is fully qualified but begins with a space, the path is not trimmed in methods of the class. Therefore, the path is malformed and an exception is raised. Similarly, a path or a combination of paths cannot be fully qualified twice. For example, "c:\temp c:\windows" also raises an exception in most cases. Ensure that your paths are well-formed when using methods that accept a path string.
    /// @remarks In members that accept a path, the path can refer to a file or just a directory. The specified path can also refer to a relative path or a Universal Naming Convention (UNC) path for a server and share name. For example, all the following are acceptable paths:
    /// * "c:\\MyDir\\MyFile.txt".
    /// * "c:\\MyDir".
    /// * "MyDir\\MySubdir".
    /// * "\\\\MyServer\\MyShare".
    /// @remarks By default, full read/write access to new directories is granted to all users.
    /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
    class core_export_ directory_info final : public xtd::io::file_system_info {
    public:
      /// @brief Represent directory iterator used by xtd::io::directory_info.
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
        friend xtd::io::directory;
        friend xtd::io::directory_info;
        struct data;
        std::shared_ptr<data> data_;
      };

      /// @brief Represent file iterator used by xtd::io::directory_info.
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
        friend xtd::io::directory;
        friend xtd::io::directory_info;
        struct data;
        std::shared_ptr<data> data_;
      };

      /// @brief Represent file system iterator used by xtd::io::directory_info.
      class file_system_info_iterator : public std::iterator<std::input_iterator_tag, std::shared_ptr<xtd::io::file_system_info>> {
        explicit file_system_info_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        file_system_info_iterator();
        file_system_info_iterator(const file_system_info_iterator&) = default;
        file_system_info_iterator(file_system_info_iterator&&) = default;
        
        file_system_info_iterator& operator++();
        file_system_info_iterator operator++(int);
        bool operator==(file_system_info_iterator other) const;
        bool operator!=(file_system_info_iterator other) const {return !operator==(other);}
        value_type operator*() const;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        friend xtd::io::directory_info;
        struct data;
        std::shared_ptr<data> data_;
      };

      /// @brief Represents the uninitialized xtd::io::directory_info object. This field is constant.
      static const directory_info empty;
      
      /// @brief Initializes a new instance of the xtd::io::directory_info class on the specified path.
      /// @param path A string specifying the path on which to create the xtd::io::directory_info.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::argument_exception path contains invalid characters such as ", <, >, or |.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @parr Example
      /// The following example uses this constructor to create the specified directory and subdirectory, and demonstrates that a directory that contains subdirectories cannot be deleted.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
      ///     // Specify the directories you want to manipulate.
      ///     directory_info di1(R"(c:\MyDir)");
      ///     directory_info di2(R"(c:\MyDir\temp)");
      ///
      ///     try {
      ///       // Create the directories.
      ///       di1.create();
      ///       di2.create();
      ///
      ///       // This operation will not be allowed because there are subdirectories.
      ///       console::write_line("I am about to attempt to delete {0}.", di1.name());
      ///       di1.remove();
      ///       console::write_line("The delete operation was successful, which was unexpected.");
      ///     } catch (const system_exception&) {
      ///       console::write_line("The delete operation failed as expected.");
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program);
      /// @endcode
      /// @remarks This constructor does not check if a directory exists. This constructor is a placeholder for a string that is used to access the disk in subsequent operations.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      directory_info(const xtd::ustring& path);
      
      /// @brief Gets a value indicating whether the directory exists.
      /// @return true if the directory exists; otherwise, false.
      /// @par rExample
      ///
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   // Copy a source directory to a target directory.
      ///   static void copy_directory(const ustring& source_directory, const ustring& target_directory) {
      ///     directory_info  source(source_directory);
      ///     directory_info  target(target_directory);
      ///
      ///     //Determine whether the source directory exists.
      ///     if(!source.exists())
      ///       return;
      ///     if(!target.exists())
      ///       target.create();
      ///
      ///     //Copy files.
      ///     vector<file_info> source_files = source.get_files();
      ///     for(size_t i = 0; i < source_files.size(); ++i)
      ///       file::copy(source_files[i].full_name(), target.full_name() +"\\" + source_files[i].name(), true);
      ///
      ///     //Copy directories.
      ///     vector<directory_info> source_directories = source.get_directories();
      ///     for(size_t j = 0; j < source_directories.size(); ++j)
      ///       copy_directory(source_directories[j].full_name(), target.full_name() + "\\" + source_directories[j].name());
      ///   }
      ///
      ///   static void main() {
      ///     // Specify the directories you want to manipulate.
      ///     copy_directory("D:\\Tools","D:\\NewTools");
      ///   }
      /// };
      ///
      /// startup_(program);
      /// @endcode
      /// @remarks The xtd::io::directory_info::exists property returns false if any error occurs while trying to determine if the specified file exists. This can occur in situations that raise exceptions such as passing a file name with invalid characters or too many characters, a failing or missing disk, or if the caller does not have permission to read the file.
      bool exists() const override;

      /// @brief Gets the name of this xtd::io::directory_info instance.
      /// @return The directory name.
      /// @par Example
      /// The following example displays the name of the current xtd::io::directory_info instance only.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
      ///     directory_info dir(".");
      ///     ustring dir_name = dir.name();
      ///     console::write_line("directory_info name is {0}.", dir_name);
      ///   }
      /// };
      ///
      /// startup_(program);
      /// @endcode
      /// @remarks This xtd::io::directory_info::name property returns only the name of the directory, such as "Bin". To get the full path, such as "c:\public\Bin", use the xtd::io::directory_info::full_name property.
      /// @remarks The xtd::io::directory_info::name property of a xtd::io::directory_info requires no permission (beyond the read permission to the directory necessary to construct the Exists) but can give out the directory name. If it is necessary to hand out a xtd::io::directory_info to a protected directory with a cryptographically secure name, create a dummy directory for the untrusted code's use.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      xtd::ustring name() const override;
      
      /// @brief Gets the parent directory of a specified subdirectory.
      /// @return The parent directory, or null if the path is null or if the file path denotes a root (such as \, C:\, or \\server\share).
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @par Example
      /// The following example refers to the parent directory of a specified directory.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
      ///     // Make a reference to a directory.
      ///     directory_info di("TempDir");
      ///
      ///     // Create the directory only if it does not already exist.
      ///     if (di.exists() == false)
      ///       di.create();
      ///
      ///     // Create a subdirectory in the directory just created.
      ///     directory_info dis = di.create_subdirectory("SubDir");
      ///
      ///     // Get a reference to the parent directory of the subdirectory you just made.
      ///     directory_info parent_dir = dis.parent();
      ///     console::write_line("The parent directory of '{0}' is '{1}'", dis.name(), parent_dir.name());
      ///
      ///     // Delete the parent directory.
      ///     di.remove(true);
      ///   }
      /// };
      /// ///
      /// startup_(program);
      /// @endcode
      /// @remarks To ensure consistent behavior across versions and to make your intent explicit, retrieve the value of one of the following properties on the xtd::io::directory_info instance returned by xtd::io::directory_info::parent.
      /// * xtd::io::directory_info::name, which returns the simple name of the directory (such as bin).
      /// * xtd::io::directory_info::full_name, which returns the absolute path of the directory.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      xtd::io::directory_info parent() const;
      
      /// @brief Gets the root portion of the directory.
      /// @return  An object that represents the root of the directory.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @par Example
      /// The following example displays root locations for specified directories.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
      ///     directory_info di1(R"(\\tempshare\tempdir)");
      ///     directory_info di2("tempdir");
      ///     directory_info di3(R"(x:\tempdir)");
      ///     directory_info di4(R"(c:\)");
      ///
      ///     console::write_line("The root path of '{0}' is '{1}'", di1.full_name(), di1.root());
      ///     console::write_line("The root path of '{0}' is '{1}'", di2.full_name(), di2.root());
      ///     console::write_line("The root path of '{0}' is '{1}'", di3.full_name(), di3.root());
      ///     console::write_line("The root path of '{0}' is '{1}'", di4.full_name(), di4.root());
      ///   }
      /// };
      ///
      /// startup_(program);
      ///
      /// /*
      ///  This code produces output similar to the following:
      ///
      ///  The root path of '\\tempshare\tempdir' is '\\tempshare\tempdir'
      ///  The root path of 'c:\Projects\ConsoleApplication1\ConsoleApplication1\bin\Debug\tempdir' is 'c:\'
      ///  The root path of 'x:\tempdir' is 'x:\'
      ///  The root path of 'c:\' is 'c:\'
      ///  */
      /// @endcode
      xtd::io::directory_info root() const;
      
      /// @brief Creates a directory.
      /// @exception xtd::io::io_exception The directory cannot be created.
      /// @par Example
      /// The following example checks whether a specified directory exists, creates the directory if it does not exist, and deletes the directory.
      /// @code
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
      /// @endcode
      /// @remarks If the directory already exists, this method does nothing.
      /// @remarks If the directory did not exist before calling this method, then any cached attribute information about the directory will be flushed if the creation is successful.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      void create();
      
      /// @brief Creates a subdirectory or subdirectories on the specified path. The specified path can be relative to this instance of the xtd::io::directory_info class.
      /// @param path The specified path. This cannot be a different disk volume or Universal Naming Convention (UNC) name.
      /// @return The last directory specified in path.
      /// @exception xtd::argument_exception path does not specify a valid file path or contains invalid xtd::io::directory_info characters.
      /// @exception xtd::io::directtory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::io::io_excepttion The subdirectory cannot be created. -or- A file or directory already has the name specified by path.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Example
      /// The following example demonstrates creating a subdirectory. In this example, the created directories are removed once created. Therefore, to test this sample, comment out the delete lines in the code.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
      ///     // Create a reference to a directory.
      ///     directory_info di("TempDir");
      ///
      ///     // Create the directory only if it does not already exist.
      ///     if (di.exists() == false)
      ///       di.create();
      ///
      ///     // Create a subdirectory in the directory just created.
      ///     directory_info dis = di.create_subdirectory("SubDir");
      ///
      ///     // Process that directory as required.
      ///     // ...
      ///
      ///     // Delete the subdirectory.
      ///     dis.remove(true);
      ///
      ///     // Delete the directory.
      ///     di.remove(true);
      ///   }
      /// };
      ///
      /// startup_(program);
      /// @endcode
      /// @remarks Any and all directories specified in path are created, unless some part of path is invalid. The path parameter specifies a directory path, not a file path. If the subdirectory already exists, this method does nothing.
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      xtd::io::directory_info create_subdirectory(const xtd::ustring& path) const;
      
      xtd::io::directory_info::directory_iterator enumerate_directories() const;
      xtd::io::directory_info::directory_iterator enumerate_directories(const xtd::ustring& pattern) const;
      
      xtd::io::directory_info::file_iterator enumerate_files() const;
      xtd::io::directory_info::file_iterator enumerate_files(const xtd::ustring& pattern) const;
      
      xtd::io::directory_info::file_system_info_iterator enumerate_file_system_infos() const;
      xtd::io::directory_info::file_system_info_iterator enumerate_file_system_infos(const xtd::ustring& pattern) const;

      std::vector<xtd::io::directory_info> get_directories() const;
      std::vector<xtd::io::directory_info> get_directories(const xtd::ustring& pattern) const;
      
      std::vector<xtd::io::file_info> get_files() const;
      std::vector<xtd::io::file_info> get_files(const xtd::ustring& pattern) const;
      
      std::vector<std::shared_ptr<xtd::io::file_system_info>> get_file_system_infos() const;
      std::vector<std::shared_ptr<xtd::io::file_system_info>> get_file_system_infos(const xtd::ustring& pattern) const;
      
      void move_to(const xtd::ustring& dest_dir_name);
      
      /// @brief Deletes this xtd::io::directory_info if it is empty.
      /// @exception xtd::unauthorized_access_exception The directory contains a read-only file.
      /// @exception xtd::io::directory_not_fond_exception The directory described by this xtd::io::directory_info object does not exist or could not be found.
      /// @exception xtd::io::io_excpetion The directory is not empty. -or- The directory is the application's current working directory. -or- There is an open handle on the directory.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @par Example
      /// The following example throws an exception if you attempt to delete a directory that is not empty.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static void main() {
      ///     // Specify the directories you want to manipulate.
      ///     directory_info di1(R"(c:\MyDir)");
      ///
      ///     try {
      ///       // Create the directories.
      ///       di1.create();
      ///       di1.create_subdirectory("temp");
      ///
      ///       //This operation will not be allowed because there are subdirectories.
      ///       console::write_line("I am about to attempt to delete {0}", di1.name());
      ///       di1.remove();
      ///       console::write_line("The Delete operation was successful, which was unexpected.");
      ///     } catch (const system_exception&) {
      ///       console::write_line("The Delete operation failed as expected.");
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program);
      /// @endcode
      /// @remarks For a list of common I/O tasks, see <a href="https://github.com/gammasoft71/xtd/blob/master/docs/tutorial_common_io_tasks.md">Common I/O Tasks</a>.
      void remove() const override;
      
      void remove(bool recursive) const;
      
    private:
      directory_info() = default;
    };
  }
}

/// @cond
namespace std {
  inline xtd::io::directory_info::directory_iterator begin(xtd::io::directory_info::directory_iterator it) {return it;}
  inline xtd::io::directory_info::directory_iterator end(xtd::io::directory_info::directory_iterator it) {return xtd::io::directory_info::directory_iterator();}
  inline xtd::io::directory_info::file_iterator begin(xtd::io::directory_info::file_iterator it) {return it;}
  inline xtd::io::directory_info::file_iterator end(xtd::io::directory_info::file_iterator it) {return xtd::io::directory_info::file_iterator();}
  inline xtd::io::directory_info::file_system_info_iterator begin(xtd::io::directory_info::file_system_info_iterator it) {return it;}
  inline xtd::io::directory_info::file_system_info_iterator end(xtd::io::directory_info::file_system_info_iterator it) {return xtd::io::directory_info::file_system_info_iterator();}
}
/// @endcond
