/// @file
/// @brief Contains xtd::io::directory_info class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "file_system_info.h"
#include "../iequatable.h"
#include <iterator>
#include <memory>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @cond
    class directory;
    class file_info;
    /// @endcond
    
    /// @brief Exposes instance methods for creating, moving, and enumerating through directories and subdirectories. This class cannot be inherited.
    /// @code
    /// class core_export_ directory_info final : public xtd::io::file_system_info
    /// @endcode
    /// @par Inheritance
    /// xtd::io::file_system_info → xtd::io::directory_info
    /// @par Header
    /// @code #include <xtd/io/directory_info> @endcode
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @par Examples
    /// The following example demonstrates some of the main members of the xtd::io::directory_info class.
    /// @code #include <xtd/xtd>
    ///
    /// using namespace xtd;
    /// using namespace xtd::io;
    ///
    /// class program {
    /// public:
    ///   static auto main() {
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
    /// startup_(program::main);
    /// @endcode
    /// @par Examples
    /// The following example demonstrates how to copy a directory and its contents.
    /// @code #include <xtd/xtd>
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
    ///   static auto main() {
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
    /// startup_(copy_dir::main);
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
    /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
    class core_export_ directory_info final : public xtd::io::file_system_info {
    public:
      /// @brief Represent directory iterator used by xtd::io::directory_info.
      class directory_iterator : public xtd::iequatable<directory_iterator> {
        struct data;
        
        explicit directory_iterator(const xtd::ustring& path, const xtd::ustring& pattern);
      public:
        /// @cond
        using iterator_category = std::input_iterator_tag;
        using value_type = xtd::io::directory_info;
        using difference_type = xtd::io::directory_info;
        using pointer = xtd::io::directory_info*;
        using reference = xtd::io::directory_info&;
        
        directory_iterator();
        directory_iterator(const directory_iterator&) = default;
        directory_iterator(directory_iterator&&) = default;
        
        directory_iterator& operator ++();
        directory_iterator operator ++(int32);
        value_type operator *() const;
        xtd::io::directory_info::directory_iterator begin() const;
        xtd::io::directory_info::directory_iterator end() const;
        bool equals(const directory_iterator& other) const noexcept override;
        
        xtd::ustring path() const;
        xtd::ustring pattern() const;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        friend xtd::io::directory_info;
        
        std::shared_ptr<data> data_;
      };
      
      /// @brief Represent file iterator used by xtd::io::directory_info.
      class file_iterator : public xtd::iequatable<file_iterator> {
        struct data;
        
        explicit file_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        using iterator_category = std::input_iterator_tag;
        using value_type = xtd::io::file_info;
        using difference_type = xtd::io::file_info;
        using pointer = xtd::io::file_info*;
        using reference = xtd::io::file_info&;
        
        file_iterator();
        file_iterator(const file_iterator&) = default;
        file_iterator(file_iterator&&) = default;
        
        file_iterator& operator ++();
        file_iterator operator ++(int32);
        value_type operator *() const;
        xtd::io::directory_info::file_iterator begin() const;
        xtd::io::directory_info::file_iterator end() const;
        bool equals(const file_iterator& other) const noexcept override;
        
        xtd::ustring path() const;
        xtd::ustring pattern() const;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        friend xtd::io::directory_info;
        
        std::shared_ptr<data> data_;
      };
      
      /// @brief Represent file system iterator used by xtd::io::directory_info.
      class file_system_info_iterator : public xtd::iequatable<file_system_info_iterator> {
        struct data;
        
        explicit file_system_info_iterator(const std::string& path, const std::string& pattern);
      public:
        /// @cond
        using iterator_category = std::input_iterator_tag;
        using value_type = std::shared_ptr<xtd::io::file_system_info>;
        using difference_type = std::shared_ptr<xtd::io::file_system_info>;
        using pointer = std::shared_ptr<xtd::io::file_system_info>* ;
        using reference = std::shared_ptr<xtd::io::file_system_info>& ;
        
        file_system_info_iterator();
        file_system_info_iterator(const file_system_info_iterator&) = default;
        file_system_info_iterator(file_system_info_iterator&&) = default;
        
        file_system_info_iterator& operator ++();
        file_system_info_iterator operator ++(int32);
        value_type operator *() const;
        xtd::io::directory_info::file_system_info_iterator begin() const;
        xtd::io::directory_info::file_system_info_iterator end() const;
        bool equals(const file_system_info_iterator& other) const noexcept override;
        
        xtd::ustring path() const;
        xtd::ustring pattern() const;
        /// @endcond
        
      private:
        friend xtd::io::directory;
        friend xtd::io::directory_info;
        
        std::shared_ptr<data> data_;
      };
      
      /// @name Public Fields
      
      /// @{
      /// @brief Represents the uninitialized xtd::io::directory_info object. This field is constant.
      static const directory_info empty;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::io::directory_info class on the specified path.
      /// @param path A string specifying the path on which to create the xtd::io::directory_info.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @exception xtd::argument_exception path contains invalid characters such as ", <, >, or |.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @par Examples
      /// The following example uses this constructor to create the specified directory and subdirectory, and demonstrates that a directory that contains subdirectories cannot be deleted.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
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
      /// startup_(program::main);
      /// @endcode
      /// @remarks This constructor does not check if a directory exists. This constructor is a placeholder for a string that is used to access the disk in subsequent operations.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      explicit directory_info(const xtd::ustring& path);
      /// @}
      
      /// @name Properrties
      
      /// @{
      /// @brief Gets a value indicating whether the directory exists.
      /// @return true if the directory exists; otherwise, false.
      /// @par Examples
      /// The following example demonstrates a use of the Exists property in the context of copying a source directory to a target directory.
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
      ///   static auto main() {
      ///     // Specify the directories you want to manipulate.
      ///     copy_directory("D:\\Tools","D:\\NewTools");
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @remarks The xtd::io::directory_info::exists property returns false if any error occurs while trying to determine if the specified file exists. This can occur in situations that raise exceptions such as passing a file name with invalid characters or too many characters, a failing or missing disk, or if the caller does not have permission to read the file.
      bool exists() const override;
      
      /// @brief Gets the name of this xtd::io::directory_info instance.
      /// @return The directory name.
      /// @par Examples
      /// The following example displays the name of the current xtd::io::directory_info instance only.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     directory_info dir(".");
      ///     ustring dir_name = dir.name();
      ///     console::write_line("directory_info name is {0}.", dir_name);
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @remarks This xtd::io::directory_info::name property returns only the name of the directory, such as "Bin". To get the full path, such as "c:\public\Bin", use the xtd::io::directory_info::full_name property.
      /// @remarks The xtd::io::directory_info::name property of a xtd::io::directory_info requires no permission (beyond the read permission to the directory necessary to construct the Exists) but can give out the directory name. If it is necessary to hand out a xtd::io::directory_info to a protected directory with a cryptographically secure name, create a dummy directory for the untrusted code's use.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      xtd::ustring name() const override;
      
      /// @brief Gets the parent directory of a specified subdirectory.
      /// @return The parent directory, or null if the path is null or if the file path denotes a root (such as \, C:\, or \\server\share).
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @par Examples
      /// The following example refers to the parent directory of a specified directory.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
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
      /// startup_(program::main);
      /// @endcode
      /// @remarks To ensure consistent behavior across versions and to make your intent explicit, retrieve the value of one of the following properties on the xtd::io::directory_info instance returned by xtd::io::directory_info::parent.
      /// * xtd::io::directory_info::name, which returns the simple name of the directory (such as bin).
      /// * xtd::io::directory_info::full_name, which returns the absolute path of the directory.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      xtd::io::directory_info parent() const;
      
      /// @brief Gets the root portion of the directory.
      /// @return  An object that represents the root of the directory.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @par Examples
      /// The following example displays root locations for specified directories.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
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
      /// startup_(program::main);
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
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Creates a directory.
      /// @exception xtd::io::io_exception The directory cannot be created.
      /// @par Examples
      /// The following example checks whether a specified directory exists, creates the directory if it does not exist, and deletes the directory.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
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
      /// startup_(program::main);
      /// @endcode
      /// @remarks If the directory already exists, this method does nothing.
      /// @remarks If the directory did not exist before calling this method, then any cached attribute information about the directory will be flushed if the creation is successful.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      void create();
      
      /// @brief Creates a subdirectory or subdirectories on the specified path. The specified path can be relative to this instance of the xtd::io::directory_info class.
      /// @param path The specified path. This cannot be a different disk volume or Universal Naming Convention (UNC) name.
      /// @return The last directory specified in path.
      /// @exception xtd::argument_exception path does not specify a valid file path or contains invalid xtd::io::directory_info characters.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::io::io_exception The subdirectory cannot be created.<br>-or-<br>A file or directory already has the name specified by path.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @exception xtd::not_supported_exception path contains a colon character (:) that is not part of a drive label ("C:\").
      /// @par Examples
      /// The following example demonstrates creating a subdirectory. In this example, the created directories are removed once created. Therefore, to test this sample, comment out the delete lines in the code.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
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
      /// startup_(program::main);
      /// @endcode
      /// @remarks Any and all directories specified in path are created, unless some part of path is invalid. The path parameter specifies a directory path, not a file path. If the subdirectory already exists, this method does nothing.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      xtd::io::directory_info create_subdirectory(const xtd::ustring& path) const;
      
      /// @brief Returns an enumerable collection of directory information in the current directory.
      /// @return An xtd::io::directory_info::directory_iterator of directories in the current directory.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// The following example enumerates the subdirectories under the "My Documents" directory.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Set a variable to the Documents path.
      ///     ustring doc_path = environment::get_folder_path(environment::special_folder::my_documents);
      ///
      ///     directory_info dirs(doc_path);
      ///
      ///     for (auto di : dirs.enumerate_directories()) {
      ///       console::write_line("{}", di.name());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @remarks The xtd::io::directory_info::enumerate_directories and xtd::io::directory_info::get_directories methods differ as follows:
      /// @remarks * When you use xtd::io::directory_info::enumerate_directories, you can start enumerating the collection of xtd::io::directory_info objects before the whole collection is returned.
      /// @remarks * When you use xtd::io::directory_info::get_directories, you must wait for the whole array of xtd::io::directory_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_directories can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      xtd::io::directory_info::directory_iterator enumerate_directories() const;
      /// @brief Returns an enumerable collection of directory information that matches a specified search pattern.
      /// @param search_pattern The search string to match against the names of directories. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An xtd::io::directory_info::directory_iterator of directories that matches search_pattern.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @remarks searchPattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in searchPattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the string "*t" searches for all names in ending with the letter "t". ". The searchPattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks The xtd::io::directory_info::enumerate_directories and xtd::io::directory_info::get_directories methods differ as follows:
      /// @remarks * When you use xtd::io::directory_info::enumerate_directories, you can start enumerating the collection of xtd::io::directory_info objects before the whole collection is returned.
      /// @remarks * When you use xtd::io::directory_info::get_directories, you must wait for the whole array of xtd::io::directory_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_directories can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      xtd::io::directory_info::directory_iterator enumerate_directories(const xtd::ustring& search_pattern) const;
      
      /// @brief Returns an enumerable collection of file information in the current directory.
      /// @return An xtd::io::directory_info::file_iterator of the files in the current directory.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// The following example enumerates the files under a specified directory.
      ///
      /// If you only need the names of the files, use the static xtd::io::directory class for better performance. For an example, see the xtd::io::directory::enumerate_files method.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Create a directory_info of the directory of the files to enumerate.
      ///     directory_info dir_info(R"(\\archives1\library\)");
      ///
      ///     // Get the files iteror.
      ///     auto files = dir_info.enumerate_files();
      ///
      ///     // Show results.
      ///     for (auto f : files) {
      ///       console::write_line("{0}", f.name());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @par Examples
      /// The following example shows how to enumerate files in a directory by using different search options. The example assumes a directory that has files named log1.txt, log2.txt, test1.txt, test2.txt, test3.txt.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     directory_info di(R"(C:\ExampleDir)");
      ///     console::write_line("No search pattern returns:");
      ///     for (auto fi : di.enumerate_files()) {
      ///       console::write_line(fi.name());
      ///     }
      ///
      ///     console::write_line();
      ///
      ///     console::write_line("Search pattern *2* returns:");
      ///     for (auto fi : di.enumerate_files("*2*")) {
      ///       console::write_line(fi.name());
      ///     }
      ///
      ///     console::write_line();
      ///
      ///     console::write_line("Search pattern test?.txt returns:");
      ///     for (auto fi : di.enumerate_files("test?.txt")) {
      ///       console::write_line(fi.name());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// /*
      ///  This code produces output similar to the following:
      ///
      ///  No search pattern returns:
      ///  log1.txt
      ///  log2.txt
      ///  test1.txt
      ///  test2.txt
      ///  test3.txt
      ///
      ///  Search pattern *2* returns:
      ///  log2.txt
      ///  test2.txt
      ///
      ///  Search pattern test?.txt returns:
      ///  test1.txt
      ///  test2.txt
      ///  test3.txt
      ///  */
      /// @endcode
      /// @remarks The xtd::io::directory_info::enumerate_files and xtd::io::directory_info::get_files methods differ as follows:
      /// * When you use xtd::io::directory_info::enumerate_files, you can start enumerating the collection of xtd::io::directory_info objects before the whole collection is returned.
      /// * When you use xtd::io::directory_info::get_files, you must wait for the whole array of xtd::io::directory_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_files can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      xtd::io::directory_info::file_iterator enumerate_files() const;
      /// @brief Returns an enumerable collection of file information that matches a search pattern.
      /// @param search_pattern The search string to match against the names of files. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An xtd::io::directory_info::file_iterator of files that matches search_pattern.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// The following example shows how to enumerate files in a directory by using different search options. The example assumes a directory that has files named log1.txt, log2.txt, test1.txt, test2.txt, test3.txt.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     directory_info di(R"(C:\ExampleDir)");
      ///     console::write_line("No search pattern returns:");
      ///     for (auto fi : di.enumerate_files()) {
      ///       console::write_line(fi.name());
      ///     }
      ///
      ///     console::write_line();
      ///
      ///     console::write_line("Search pattern *2* returns:");
      ///     for (auto fi : di.enumerate_files("*2*")) {
      ///       console::write_line(fi.name());
      ///     }
      ///
      ///     console::write_line();
      ///
      ///     console::write_line("Search pattern test?.txt returns:");
      ///     for (auto fi : di.enumerate_files("test?.txt")) {
      ///       console::write_line(fi.name());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// /*
      ///  This code produces output similar to the following:
      ///
      ///  No search pattern returns:
      ///  log1.txt
      ///  log2.txt
      ///  test1.txt
      ///  test2.txt
      ///  test3.txt
      ///
      ///  Search pattern *2* returns:
      ///  log2.txt
      ///  test2.txt
      ///
      ///  Search pattern test?.txt returns:
      ///  test1.txt
      ///  test2.txt
      ///  test3.txt
      ///  */
      /// @endcode
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the string "*t" searches for all names in ending with the letter "t". ". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks The xtd::io::directory_info::enumerate_files and xtd::io::directory_info::get_files methods differ as follows:
      /// * When you use xtd::io::directory_info::enumerate_files, you can start enumerating the collection of xtd::io::directory_info objects before the whole collection is returned.
      /// * When you use xtd::io::directory_info::get_files, you must wait for the whole array of xtd::io::directory_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_files can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      xtd::io::directory_info::file_iterator enumerate_files(const xtd::ustring& search_pattern) const;
      
      /// @brief Returns an enumerable collection of file system information in the current directory.
      /// @return An xtd::io::directory_info::file_system_info_iterator of file system information in the current directory.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @remarks The xtd::io::directory_info::enumerate_file_system_infos and xtd::io::directory_info::get_file_system_infos methods differ as follows:
      /// * When you use xtd::io::directory_info::enumerate_file_system_infos, you can start enumerating the collection of xtd::io::directory_info objects before the whole collection is returned.
      /// * When you use xtd::io::directory_info::get_file_system_infos, you must wait for the whole array of xtd::io::directory_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_file_system_infos can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      xtd::io::directory_info::file_system_info_iterator enumerate_file_system_infos() const;
      /// @brief Returns an enumerable collection of file system information that matches a specified search pattern.
      /// @param search_pattern The search string to match against the names of directories. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An xtd::io::directory_info::file_system_info_iterator of file system information objects that matches search_pattern.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the string "*t" searches for all names in ending with the letter "t". ". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks The xtd::io::directory_info::enumerate_file_system_infos and xtd::io::directory_info::get_file_system_infos methods differ as follows:
      /// * When you use xtd::io::directory_info::enumerate_file_system_infos, you can start enumerating the collection of xtd::io::directory_info objects before the whole collection is returned.
      /// * When you use xtd::io::directory_info::get_file_system_infos, you must wait for the whole array of xtd::io::directory_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_file_system_infos can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      xtd::io::directory_info::file_system_info_iterator enumerate_file_system_infos(const xtd::ustring& search_pattern) const;
      
      /// @brief Returns the subdirectories of the current directory.
      /// @return An array of xtd::io::directory_info objects.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// The following example retrieves all the directories in the root directory and displays the directory names.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     // Make a reference to a directory.
      ///     directory_info di("c:\\");
      ///
      ///     // Get a reference to each directory in that directory.
      ///     vector<directory_info> di_arr = di.get_directories();
      ///
      ///     // Display the names of the directories.
      ///     for (directory_info dri : di_arr)
      ///       console::write_line(dri.name());
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @remarks If there are no subdirectories, this method returns an empty array. This method is not recursive.
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      std::vector<xtd::io::directory_info> get_directories() const;
      /// @brief Returns an array of directories in the current DirectoryInfo matching the given search criteria.
      /// @param search_pattern The search string to match against the names of directories. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An array of type xtd::io::directory_info matching search_pattern.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// TThe following example counts the directories in a path that contain the specified letter.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace std;
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       directory_info di(R"(c:\)");
      ///
      ///       // Get only subdirectories that contain the letter "p."
      ///       vector<directory_info> dirs = di.get_directories("*p*");
      ///       console::write_line("The number of directories containing the letter p is {0}.", dirs.size());
      ///
      ///       for (directory_info di_next : dirs) {
      ///         console::write_line("The number of files in {0} is {1}", di_next, di_next.get_files().size());
      ///       }
      ///     } catch (const system_exception& e) {
      ///       console::write_line("The process failed: {0}", e.to_string());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///@endcode
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the string "*t" searches for all names in ending with the letter "t". ". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      std::vector<xtd::io::directory_info> get_directories(const xtd::ustring& search_pattern) const;
      
      /// @brief Returns a file list from the current directory.
      /// @return An array of type xtd::io::file_info.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// The following example shows how to get a list of files from a directory by using different search options. The example assumes a directory that has files named log1.txt, log2.txt, test1.txt, test2.txt, test3.tx
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     directory_info di(R"(C:\ExampleDir)");
      ///     console::write_line("No search pattern returns:");
      ///     for (auto fi : di.get_files()) {
      ///       console::write_line(fi.name());
      ///     }
      ///
      ///     console::write_line();
      ///
      ///     console::write_line("Search pattern *2* returns:");
      ///     for (auto fi : di.get_files("*2*")) {
      ///       console::write_line(fi.name());
      ///     }
      ///
      ///     console::write_line();
      ///
      ///     console::write_line("Search pattern test?.txt returns:");
      ///     for (auto fi : di.get_files("test?.txt")) {
      ///       console::write_line(fi.name());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// /*
      ///  This code produces output similar to the following:
      ///
      ///  No search pattern returns:
      ///  log1.txt
      ///  log2.txt
      ///  test1.txt
      ///  test2.txt
      ///  test3.txt
      ///
      ///  Search pattern *2* returns:
      ///  log2.txt
      ///  test2.txt
      ///
      ///  Search pattern test?.txt returns:
      ///  test1.txt
      ///  test2.txt
      ///  test3.txt
      ///  */
      /// @endcode
      /// @remarks The xtd::io::directory_info::enumerate_files and xtd::io::directory_info::get_files methods differ as follows:
      /// * When you use xtd::io::directory_info::enumerate_files, you can start enumerating the collection of xtd::io::directory_info objects before the whole collection is returned.
      /// * When you use xtd::io::directory_info::get_files, you must wait for the whole array of xtd::io::directory_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_files can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      std::vector<xtd::io::file_info> get_files() const;
      /// @brief Returns a file list from the current directory matching the given search pattern.
      /// @param search_pattern The search string to match against the names of files. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An array of type xtd::io::file_info.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// The following example shows how to get a list of files from a directory by using different search options. The example assumes a directory that has files named log1.txt, log2.txt, test1.txt, test2.txt, test3.tx
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     directory_info di(R"(C:\ExampleDir)");
      ///     console::write_line("No search pattern returns:");
      ///     for (auto fi : di.get_files()) {
      ///       console::write_line(fi.name());
      ///     }
      ///
      ///     console::write_line();
      ///
      ///     console::write_line("Search pattern *2* returns:");
      ///     for (auto fi : di.get_files("*2*")) {
      ///       console::write_line(fi.name());
      ///     }
      ///
      ///     console::write_line();
      ///
      ///     console::write_line("Search pattern test?.txt returns:");
      ///     for (auto fi : di.get_files("test?.txt")) {
      ///       console::write_line(fi.name());
      ///     }
      ///   }
      /// };
      ///
      /// startup_(program::main);
      ///
      /// /*
      ///  This code produces output similar to the following:
      ///
      ///  No search pattern returns:
      ///  log1.txt
      ///  log2.txt
      ///  test1.txt
      ///  test2.txt
      ///  test3.txt
      ///
      ///  Search pattern *2* returns:
      ///  log2.txt
      ///  test2.txt
      ///
      ///  Search pattern test?.txt returns:
      ///  test1.txt
      ///  test2.txt
      ///  test3.txt
      ///  */
      /// @endcode
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the string "*t" searches for all names in ending with the letter "t". ". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks The xtd::io::directory_info::enumerate_files and xtd::io::directory_info::get_files methods differ as follows:
      /// * When you use xtd::io::directory_info::enumerate_files, you can start enumerating the collection of xtd::io::directory_info objects before the whole collection is returned.
      /// * When you use xtd::io::directory_info::get_files, you must wait for the whole array of xtd::io::directory_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_files can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::directory_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      std::vector<xtd::io::file_info> get_files(const xtd::ustring& search_pattern) const;
      
      /// @brief Returns an array of strongly typed xtd::io::file_system_info entries representing all the files and subdirectories in a directory.
      /// @return An array of strongly typed xtd::io::file_system_info entries.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// The following example counts the files and directories under the specified directory.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       console::write_line("Enter the path to a directory:");
      ///
      ///       ustring directory = console::read_line();
      ///
      ///       // Create a new directory_info object.
      ///       directory_info dir(directory);
      ///
      ///       if (!dir.exists()) {
      ///         throw directory_not_found_exception("The directory does not exist.", csf_);
      ///       }
      ///
      ///       // Call the GetFileSystemInfos method.
      ///       std::vector<std::shared_ptr<file_system_info>> infos = dir.get_file_system_infos();
      ///
      ///       console::write_line("Working...");
      ///
      ///       // Pass the result to the list_directories_and_files
      ///       // method defined below.
      ///       list_directories_and_files(infos);
      ///
      ///       // Display the results to the console.
      ///       console::write_line("Directories: {0}", directories);
      ///       console::write_line("Files: {0}", files);
      ///     } catch (const system_exception& e) {
      ///       console::write_line(e.message());
      ///     }
      ///   }
      ///
      /// private:
      ///   static void list_directories_and_files(std::vector<std::shared_ptr<file_system_info>> fs_info) {
      ///     // Iterate through each item.
      ///     for (std::shared_ptr<file_system_info> i : fs_info) {
      ///       // Check to see if this is a directory_info object.
      ///       if (is<directory_info>(i)) {
      ///         // Add one to the directory count.
      ///         directories++;
      ///
      ///         // Cast the object to a directory_info object.
      ///         std::shared_ptr<directory_info> d_info = as<directory_info>(i);
      ///
      ///         // Iterate through all sub-directories.
      ///         list_directories_and_files(d_info->get_file_system_infos());
      ///       }
      ///       // Check to see if this is a FileInfo object.
      ///       else if (is<file_info>(i)) {
      ///         // Add one to the file count.
      ///         files++;
      ///       }
      ///     }
      ///   }
      ///
      ///   inline static long files = 0;
      ///   inline static long directories = 0;
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @remarks The xtd::io::directory_info::enumerate_file_system_infos and xtd::io::directory_info::get_file_system_infos methods differ as follows:
      /// * When you use xtd::io::directory_info::enumerate_file_system_infos, you can start enumerating the collection of xtd::io::file_system_info objects before the whole collection is returned.
      /// * When you use xtd::io::directory_info::get_file_system_infos, you must wait for the whole array of xtd::io::file_system_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_file_system_infos can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::file_system_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      std::vector<std::shared_ptr<xtd::io::file_system_info>> get_file_system_infos() const;
      /// @brief Retrieves an array of strongly typed FileSystemInfo objects representing the files and subdirectories that match the specified search criteria.
      /// @param search_pattern The search string to match against the names of directories and files. This parameter can contain a combination of valid literal path and wildcard (* and ?) characters, but it doesn't support regular expressions.
      /// @return An array of strongly typed xtd::io::file_system_info entries.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// The following example counts the files and directories that match the specified search pattern.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
      ///     try {
      ///       console::write_line("Enter the path to a directory:");
      ///
      ///       ustring directory = console::read_line();
      ///
      ///       console::write_line("Enter a search string (for example *p*):");
      ///
      ///       ustring search_string = console::read_line();
      ///
      ///       // Create a new directory_info object.
      ///       directory_info dir(directory);
      ///
      ///       if (!dir.exists()) {
      ///         throw directory_not_found_exception("The directory does not exist.", csf_);
      ///       }
      ///
      ///       // Call the GetFileSystemInfos method.
      ///       std::vector<std::shared_ptr<file_system_info>> infos = dir.get_file_system_infos(search_string);
      ///
      ///       console::write_line("Working...");
      ///
      ///       // Pass the result to the list_directories_and_files
      ///       // method defined below.
      ///       list_directories_and_files(infos, search_string);
      ///
      ///       // Display the results to the console.
      ///       console::write_line("Directories: {0}", directories);
      ///       console::write_line("Files: {0}", files);
      ///     } catch (const system_exception& e) {
      ///       console::write_line(e.message());
      ///     }
      ///   }
      ///
      /// private:
      ///   static void list_directories_and_files(std::vector<std::shared_ptr<file_system_info>> fs_info, const ustring& search_string) {
      ///     // Iterate through each item.
      ///     for (std::shared_ptr<file_system_info> i : fs_info) {
      ///       // Check to see if this is a directory_info object.
      ///       if (is<directory_info>(i)) {
      ///         // Add one to the directory count.
      ///         directories++;
      ///
      ///         // Cast the object to a directory_info object.
      ///         std::shared_ptr<directory_info> d_info = as<directory_info>(i);
      ///
      ///         // Iterate through all sub-directories.
      ///         list_directories_and_files(d_info->get_file_system_infos(search_string), search_string);
      ///       }
      ///       // Check to see if this is a FileInfo object.
      ///       else if (is<file_info>(i)) {
      ///         // Add one to the file count.
      ///         files++;
      ///       }
      ///     }
      ///   }
      ///
      ///   inline static long files = 0;
      ///   inline static long directories = 0;
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @remarks search_pattern can be a combination of literal and wildcard characters, but it doesn't support regular expressions. The following wildcard specifiers are permitted in search_pattern.
      /// | Wildcard specifier | Matches                                   |
      /// | ------------------ | ----------------------------------------- |
      /// | * (asterisk)       | Zero or more characters in that position. |
      /// | ? (question mark)  | Zero or one character in that position.   |
      /// @remarks Characters other than the wildcard are literal characters. For example, the string "*t" searches for all names in ending with the letter "t". ". The search_pattern string "s*" searches for all names in path beginning with the letter "s".
      /// @remarks The xtd::io::directory_info::enumerate_file_system_infos and xtd::io::directory_info::get_file_system_infos methods differ as follows:
      /// * When you use xtd::io::directory_info::enumerate_file_system_infos, you can start enumerating the collection of xtd::io::file_system_info objects before the whole collection is returned.
      /// * When you use xtd::io::directory_info::get_file_system_infos, you must wait for the whole array of xtd::io::file_system_info objects to be returned before you can access the array.
      /// @remarks Therefore, when you are working with many files and directories, xtd::io::directory_info::enumerate_file_system_infos can be more efficient.
      /// @remarks This method pre-populates the values of the following xtd::io::file_system_info properties:
      /// * xtd::io::file_system_info::attributes
      /// * xtd::io::file_system_info::creation_time
      /// * xtd::io::file_system_info::last_access_time
      /// * xtd::io::file_system_info::last_write_time
      /// * xtd::io::file_system_info::size
      std::vector<std::shared_ptr<xtd::io::file_system_info>> get_file_system_infos(const xtd::ustring& search_pattern) const;
      
      /// @brief Moves a DirectoryInfo instance and its contents to a new path.
      /// @param dest_dir_name The name and path to which to move this directory. The destination cannot be another disk volume or a directory with the identical name. It can be an existing directory to which you want to add this directory as a subdirectory.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid, such as being on an unmapped drive.
      /// @exception xtd::io::io_exception The directory is not empty.<br>-or-<br>The directory is the application's current working directory.<br>-or-<br>There is an open handle on the directory.
      /// @exception xtd::security::security_exception The caller does not have code access permission to create the directory.
      /// @par Examples
      /// The following example demonstrates moving a directory.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
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
      ///     // Move the main directory. Note that the contents move with the directory.
      ///     if (directory::exists("NewTempDir") == false)
      ///       di.move_to("NewTempDir");
      ///
      ///     try {
      ///       // Attempt to delete the subdirectory. Note that because it has been
      ///       // moved, an exception is thrown.
      ///       dis.remove(true);
      ///     } catch (const system_exception&) {
      ///       // Handle this exception in some way, such as with the following code:
      ///       // console::write_line("That directory does not exist.");
      ///     }
      ///
      ///     // Point the directory_info reference to the new directory.
      ///     //di = directory_info("NewTempDir");
      ///
      ///     // Delete the directory.
      ///     //di.remove(true);
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @remarks This method throws an IOException if, for example, you try to move c:\mydir to c:\public, and c:\public already exists. You must specify "c:\\public\\mydir" as the destDirName parameter, or specify a new directory name such as "c:\\newdir".
      /// @remarks This method permits moving a directory to a read-only directory. The read/write attribute of neither directory is affected.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      void move_to(const xtd::ustring& dest_dir_name);
      
      /// @brief Deletes this xtd::io::directory_info if it is empty.
      /// @exception xtd::unauthorized_access_exception The directory contains a read-only file.
      /// @exception xtd::io::directory_not_found_exception The directory described by this xtd::io::directory_info object does not exist or could not be found.
      /// @exception xtd::io::io_exception The directory is not empty.<br>-or-<br>The directory is the application's current working directory.<br>-or-<br>There is an open handle on the directory.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @par Examples
      /// The following example throws an exception if you attempt to delete a directory that is not empty.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
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
      /// startup_(program::main);
      /// @endcode
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      void remove() const override;
      
      /// @brief Deletes this instance of a DirectoryInfo, specifying whether to delete subdirectories and files.
      /// @param recursive true to delete this directory, its subdirectories, and all files; otherwise, false.
      /// @exception xtd::unauthorized_access_exception The directory contains a read-only file.
      /// @exception xtd::io::directory_not_found_exception The directory described by this xtd::io::directory_info object does not exist or could not be found.
      /// @exception xtd::io::io_exception The directory is not empty.<br>-or-<br>The directory is the application's current working directory.<br>-or-<br>There is an open handle on the directory.
      /// @exception xtd::security::security_exception The caller does not have the required permission.
      /// @par Examples
      /// The following example demonstrates deleting a directory. Because the directory is removed, first comment out the Delete line to test that the directory exists. Then uncomment the same line of code to test that the directory was removed successfully.
      /// @code
      /// #include <xtd/xtd>
      ///
      /// using namespace xtd;
      /// using namespace xtd::io;
      ///
      /// class program {
      /// public:
      ///   static auto main() {
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
      ///     // Process that directory as required.
      ///     // ...
      ///
      ///     // Delete the subdirectory. The true indicates that if subdirectories
      ///     // or files are in this directory, they are to be deleted as well.
      ///     dis.remove(true);
      ///
      ///     // Delete the directory.
      ///     di.remove(true);
      ///   }
      /// };
      ///
      /// startup_(program::main);
      /// @endcode
      /// @remarks If the xtd::io::directory_info has no files or subdirectories, this method deletes the xtd::io::directory_info even if recursive is false. Attempting to delete a xtd::io::directory_info that is not empty when recursive is false throws an xtd::io::io_exception.
      /// @remarks For a list of common I/O tasks, see <a href="https://gammasoft71.github.io/xtd/docs/documentation/Guides/xtd.core/Common%20I%3AO%20tasks">Common I/O Tasks</a>.
      void remove(bool recursive) const;
      /// @}
      
    private:
      directory_info() = default;
    };
  }
}
