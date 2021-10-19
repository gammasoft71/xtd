/// @file
/// @brief Contains xtd::io::drive_type enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Defines constants for drive types, including CDRom, Fixed, Network, NoRootDirectory, Ram, Removable, and Unknown.
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core io
    enum class drive_type {
      /// @brief The type of drive is unknown.
      unknown,
      /// @brief The drive does not have a root directory.
      no_root_directory,
      /// @brief The drive is a removable storage device, such as a floppy disk drive or a USB flash drive.
      removable,
      /// @brief The drive is a fixed disk.
      fixed,
      /// @brief The drive is a network drive.
      network,
      /// @brief The drive is an optical disc device, such as a CD or DVD-ROM.
      cd_rom,
      /// @brief The drive is a RAM disk.
      ram
    };

    inline std::ostream& operator<<(std::ostream& os, drive_type value) {return os << to_string(value, {{drive_type::unknown, "unknown"}, {drive_type::no_root_directory, "no_root_directory"}, {drive_type::removable, "removable"}, {drive_type::fixed, "fixed"}, {drive_type::network, "network"}, {drive_type::cd_rom, "cd_rom"}, {drive_type::ram, "ram"}});}
    inline std::wostream& operator<<(std::wostream& os, drive_type value) {return os << to_string(value, {{drive_type::unknown, L"unknown"}, {drive_type::no_root_directory, L"no_root_directory"}, {drive_type::removable, L"removable"}, {drive_type::fixed, L"fixed"}, {drive_type::network, L"network"}, {drive_type::cd_rom, L"cd_rom"}, {drive_type::ram, L"ram"}});}
  }
}
