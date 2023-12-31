/// @file
/// @brief Contains xtd::io::file_access enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Defines constants for read, write, or read/write access to a file. This enumeration has a flags attribute that allows a bitwise combination of its member values.
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
  }
}


/// @cond
flags_attribute_(xtd::io, file_access);

template<> struct xtd::enum_register<xtd::io::file_access> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::io::file_access> {{xtd::io::file_access::read, L"read"}, {xtd::io::file_access::write, L"write"}, {xtd::io::file_access::read_write, L"read_write"}};}
};
/// @endcond
