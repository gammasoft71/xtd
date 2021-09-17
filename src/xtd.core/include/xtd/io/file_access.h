/// @file
/// @brief Contains xtd::io::file_access enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Defines constants for read, write, or read/write access to a file. This enumeration has a fllags attribute that allows a bitwise combination of its member values.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    enum class file_access {
      /// @brief Read access to the file. Data can be read from the file. Combine with Write for read/write access.
      read = 0b1,
      /// @brief Write access to the file. Data can be written to the file. Combine with Read for read/write access.
      write = 0b10,
      /// @brief The file is a read_write file. The file is part of the operating read_write or is used exclusively by the operating read_write.
      read_write = 0b11,
    };

    /// @cond
    inline file_access& operator^=(file_access& lhs, file_access rhs) {lhs = static_cast<file_access>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
    inline file_access& operator&=(file_access& lhs, file_access rhs) {lhs = static_cast<file_access>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
    inline file_access& operator|=(file_access& lhs, file_access rhs) {lhs = static_cast<file_access>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
    inline file_access& operator+=(file_access& lhs, file_access rhs) {lhs = static_cast<file_access>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
    inline file_access& operator-=(file_access& lhs, file_access rhs) {lhs = static_cast<file_access>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
    inline file_access operator^(file_access lhs, file_access rhs) {return static_cast<file_access>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}
    inline file_access operator&(file_access lhs, file_access rhs) {return static_cast<file_access>(static_cast<int>(lhs) & static_cast<int>(rhs));}
    inline file_access operator|(file_access lhs, file_access rhs) {return static_cast<file_access>(static_cast<int>(lhs) | static_cast<int>(rhs));}
    inline file_access operator+(file_access lhs, file_access rhs) {return static_cast<file_access>(static_cast<int>(lhs) + static_cast<int>(rhs));}
    inline file_access operator-(file_access lhs, file_access rhs) {return static_cast<file_access>(static_cast<int>(lhs) - static_cast<int>(rhs));}
    inline file_access operator~(file_access lhs) {return static_cast<file_access>(~static_cast<int>(lhs));}
    inline std::ostream& operator<<(std::ostream& os, file_access value) {return os << to_string(value, {{file_access::read, "read"}, {file_access::write, "write"}, {file_access::read_write, "read_write"}});}
    inline std::wostream& operator<<(std::wostream& os, file_access value) {return os << to_string(value, {{file_access::read, L"read"}, {file_access::write, L"write"}, {file_access::read_write, L"read_write"}});}
    /// @endcond
  }
}
