/// @file
/// @brief Contains xtd::io::file_attributes enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides attributes for files and directories.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    enum class file_attributes {
      /// @brief The file is read-only.
      read_only = 0x0001,
      /// @brief The file is hidden, and thus is not included in an ordinary directory listing.
      hidden = 0x0002,
      /// @brief The file is a system file. The file is part of the operating system or is used exclusively by the operating system.
      system = 0x0004,
      /// @brief The file is a directory.
      directory = 0x0010,
      /// @brief The file's archive status. Applications use this attribute to mark files for backup or removal.
      archive = 0x0020,
      /// @brief Reserved for future use.
      device = 0x0040,
      /// @brief The file is normal and has no other attributes set. This attribute is valid only if used alone.
      normal = 0x0080,
      /// @brief The file is temporary. File systems attempt to keep all of the data in memory for quicker access rather than flushing the data back to mass storage. A temporary file should be deleted by the application as soon as it is no longer needed.
      temporary = 0x0100,
      /// @brief The file is a sparse file. Sparse files are typically large files whose data are mostly zeros.
      sparse_file = 0x0200,
      /// @brief The file contains a reparse point, which is a block of user-defined data associated with a file or a directory.
      reparse_point = 0x0400,
      /// @brief The file is compressed.
      compressed = 0x0800,
      /// @brief The file is offline. The data of the file is not immediately available.
      offline = 0x1000,
      /// @brief The file will not be indexed by the operating system's content indexing service.
      not_content_indexed = 0x2000,
      /// @brief The file or directory is encrypted. For a file, this means that all data in the file is encrypted. For a directory, this means that encryption is the default for newly created files and directories.
      encrypted = 0x4000
    };

    /// @cond
    inline file_attributes& operator^=(file_attributes& lhs, file_attributes rhs) {lhs = static_cast<file_attributes>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
    inline file_attributes& operator&=(file_attributes& lhs, file_attributes rhs) {lhs = static_cast<file_attributes>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
    inline file_attributes& operator|=(file_attributes& lhs, file_attributes rhs) {lhs = static_cast<file_attributes>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
    inline file_attributes& operator+=(file_attributes& lhs, file_attributes rhs) {lhs = static_cast<file_attributes>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
    inline file_attributes& operator-=(file_attributes& lhs, file_attributes rhs) {lhs = static_cast<file_attributes>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
    inline file_attributes operator^(file_attributes lhs, file_attributes rhs) {return static_cast<file_attributes>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}
    inline file_attributes operator&(file_attributes lhs, file_attributes rhs) {return static_cast<file_attributes>(static_cast<int>(lhs) & static_cast<int>(rhs));}
    inline file_attributes operator|(file_attributes lhs, file_attributes rhs) {return static_cast<file_attributes>(static_cast<int>(lhs) | static_cast<int>(rhs));}
    inline file_attributes operator+(file_attributes lhs, file_attributes rhs) {return static_cast<file_attributes>(static_cast<int>(lhs) + static_cast<int>(rhs));}
    inline file_attributes operator-(file_attributes lhs, file_attributes rhs) {return static_cast<file_attributes>(static_cast<int>(lhs) - static_cast<int>(rhs));}
    inline file_attributes operator~(file_attributes lhs) {return static_cast<file_attributes>(~static_cast<int>(lhs));}
    inline std::ostream& operator<<(std::ostream& os, file_attributes value) {return os << to_string(value, {{file_attributes::read_only, "read_only"}, {file_attributes::hidden, "hidden"}, {file_attributes::system, "system"}, {file_attributes::directory, "directory"}, {file_attributes::device, "device"}, {file_attributes::normal, "normal"}, {file_attributes::temporary, "temporary"}, {file_attributes::sparse_file, "sparse_file"}, {file_attributes::reparse_point, "reparse_point"}, {file_attributes::compressed, "compressed"}, {file_attributes::offline, "offline"}, {file_attributes::not_content_indexed, "not_content_indexed"}, {file_attributes::encrypted, "encrypted"}});}
    inline std::wostream& operator<<(std::wostream& os, file_attributes value) {return os << to_string(value, {{file_attributes::read_only, L"read_only"}, {file_attributes::hidden, L"hidden"}, {file_attributes::system, L"system"}, {file_attributes::directory, L"directory"}, {file_attributes::device, L"device"}, {file_attributes::normal, L"normal"}, {file_attributes::temporary, L"temporary"}, {file_attributes::sparse_file, L"sparse_file"}, {file_attributes::reparse_point, L"reparse_point"}, {file_attributes::compressed, L"compressed"}, {file_attributes::offline, L"offline"}, {file_attributes::not_content_indexed, L"not_content_indexed"}, {file_attributes::encrypted, L"encrypted"}});}
    /// @endcond
  }
}
