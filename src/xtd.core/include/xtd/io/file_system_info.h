/// @file
/// @brief Contains xtd::io::file_system_info class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <chrono>
#include <memory>
#include "../abstract.h"
#include "../core_export.h"
#include "../ustring.h"
#include "file_attributes.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides the base class for both xtd::io::file_info and xtd::io::directory_info objects.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    /// @remarks The xtd::io::file_system_info class contains methods that are common to file and directory manipulation. A xtd::io::file_system_info object can represent either a file or a directory, thus serving as the basis for xtd::io::file_info or xtd::io::directory_info objects. Use this base class when parsing a lot of files and directories.
    /// @remarks In members that accept a path, the path can refer to a file or just a directory. The specified path can also refer to a relative path or a Universal Naming Convention (UNC) path for a server and share name. For example, all the following are acceptable paths:
    /// * "c:\\MyDir\\MyFile.txt"
    /// * "c:\\MyDir"
    /// * "MyDir\\MySubdir"
    /// * "\\\\MyServer\\MyShare"
    class core_export_ file_system_info abstract_ {
    protected:
      /// @brief Initializes a new instance of the xtd::io::file_system_info class.
      file_system_info() = default;
      
    public:
      /// @brief Gets the attributes for the current file or directory.
      /// @return xtd::io::file_attributes of the current xtd::io::file_system_info.
      /// @exception xtd::io::file_not_found_exception The specified file doesn't exist. Only thrown when setting the property value.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid. For example, it's on an unmapped drive. Only thrown when setting the property value.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::argument_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::io_exception xtd::io::file_system_info::refresh() cannot initialize the data.
      /// @remarks The value of the xtd::io::file_system_info::attributes property is pre-cached if the current instance of the xtd::io::file_system_info object was returned from any of the following xtd::io::directory_info methods:
      /// * xtd::io::directory_info::Gget_directories
      /// * xtd::io::directory_info::get_files
      /// * xtd::io::directory_info::get_file_system_infos
      /// * xtd::io::directory_info::enumerate_directories
      /// * xtd::io::directory_info::enumerate_files
      /// * xtd::io::directory_info::enumerate_file_system_infos
      /// @remarks The value may be cached when either the value itself or other xtd::io::file_system_info properties are accessed. To get the latest value, call the xtd::io::file_system_info::refresh method.
      /// @remarks If the path doesn't exist as of the last cached state, the return value is static_cast<xtd::io::file_attributes>(-1). xtd::io::file_not_found_exception or xtd::io::directory_not_found_exception can only be thrown when setting the value.
      /// @remarks The value of this property is a combination of the archive, compressed, directory, hidden, offline, read-only, system, and temporary file attribute flags.
      /// @remarks When you set this value, use the bitwise OR operator (|) to apply more than one value. To retain any existing values in the xtd::io::file_system_info::attributes property, include the value of the xtd::io::file_system_info::attributes property in your assignment. For example:
      /// @verbatim example_file.attributes(example_file.attributes() | file_attributes::read_only; @endverbatim
       xtd::io::file_attributes attributes() const;
      /// @brief Sets the attributes for the current file or directory.
      /// @param value xtd::io::file_attributes of the current xtd::io::file_system_info.
      /// @exception xtd::io::file_not_found_exception The specified file doesn't exist. Only thrown when setting the property value.
      /// @exception xtd::io::directory_not_found_exception The specified path is invalid. For example, it's on an unmapped drive. Only thrown when setting the property value.
      /// @exception xtd::io::path_too_long_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::argument_exception The specified path, file name, or both exceed the system-defined maximum length.
      /// @exception xtd::io::io_exception xtd::io::file_system_info::refresh() cannot initialize the data.
      /// @remarks The value of the xtd::io::file_system_info::attributes property is pre-cached if the current instance of the xtd::io::file_system_info object was returned from any of the following xtd::io::directory_info methods:
      /// * xtd::io::directory_info::Gget_directories
      /// * xtd::io::directory_info::get_files
      /// * xtd::io::directory_info::get_file_system_infos
      /// * xtd::io::directory_info::enumerate_directories
      /// * xtd::io::directory_info::enumerate_files
      /// * xtd::io::directory_info::enumerate_file_system_infos
      /// @remarks The value may be cached when either the value itself or other xtd::io::file_system_info properties are accessed. To get the latest value, call the xtd::io::file_system_info::refresh method.
      /// @remarks If the path doesn't exist as of the last cached state, the return value is static_cast<xtd::io::file_attributes>(-1). xtd::io::file_not_found_exception or xtd::io::directory_not_found_exception can only be thrown when setting the value.
      /// @remarks The value of this property is a combination of the archive, compressed, directory, hidden, offline, read-only, system, and temporary file attribute flags.
      /// @remarks When you set this value, use the bitwise OR operator (|) to apply more than one value. To retain any existing values in the xtd::io::file_system_info::attributes property, include the value of the xtd::io::file_system_info::attributes property in your assignment. For example:
      /// @verbatim example_file.attributes(example_file.attributes() | file_attributes::read_only; @endverbatim
      xtd::io::file_system_info& attributes(xtd::io::file_attributes value);

      /// @brief Gets the creation time
      /// @return The creation date and time
      /// @exception xtd::io::io_exception system error when retrieving the file information
      std::chrono::system_clock::time_point creation_time() const;
      
      /// @brief Gets a value indicating whether the file or directory exists.
      /// @return true if the file or directory exists; otherwise, false.
      virtual bool exists() const = 0;
      
      /// @brief Gets the string representing the extension part of the file.
      /// @return A string containing the System::IO::FileSystemInfo extension.
      virtual xtd::ustring extension() const;
      
      xtd::ustring full_name() const;
      
      std::chrono::system_clock::time_point last_access_time() const;
      
      std::chrono::system_clock::time_point last_write_time() const;
      
      virtual xtd::ustring name() const = 0;
      
      static bool is_empty(const file_system_info& file_system_info);
      
      void refresh();
      
      virtual void remove() = 0;
      
      /// @cond
      file_system_info(const file_system_info&) = default;
      file_system_info& operator=(const file_system_info&) = default;
      /// @endcond
    
    protected:
      xtd::ustring full_path_;
      xtd::ustring original_path_;
      xtd::io::file_attributes attributes_ = static_cast<xtd::io::file_attributes>(0);
      std::chrono::system_clock::time_point creation_time_;
      std::chrono::system_clock::time_point last_access_time_;
      std::chrono::system_clock::time_point last_write_time_;
      bool exists_ = false;
    };
  }
}
