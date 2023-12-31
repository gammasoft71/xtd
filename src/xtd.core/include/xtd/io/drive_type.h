/// @file
/// @brief Contains xtd::io::drive_type enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Defines constants for drive types, including CDRom, Fixed, Network, NoRootDirectory, Ram, Removable, and Unknown.
    /// @code
    /// enum class drive_type
    /// @endcode
    /// @par Inheritance
    /// xtd::io::io_exception → xtd::io::drive_not_found_exception
    /// @par Header
    /// @code #include <xtd/io/drive_type> @endcode
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
  }
}

/// @cond
template<> struct xtd::enum_register<xtd::io::drive_type> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::io::drive_type> {{xtd::io::drive_type::unknown, "unknown"}, {xtd::io::drive_type::no_root_directory, "no_root_directory"}, {xtd::io::drive_type::removable, "removable"}, {xtd::io::drive_type::fixed, "fixed"}, {xtd::io::drive_type::network, "network"}, {xtd::io::drive_type::cd_rom, "cd_rom"}, {xtd::io::drive_type::ram, "ram"}};}
};
/// @endcond
