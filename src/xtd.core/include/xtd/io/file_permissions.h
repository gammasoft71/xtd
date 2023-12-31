/// @file
/// @brief Contains xtd::io::file_permissions enum class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../enum.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides permissions for files and directories.
    /// @code
    /// enum class file_permissions
    /// @endcode
    /// @par Header
    /// @code #include <xtd/io/file_permissions> @endcode
    /// @par Namespace
    /// xtd::io
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    enum class file_permissions {
      /// @brief No permission bits are set.
      none = 0,
      /// @brief File owner has read permission.
      owner_read = 0400,
      /// @brief File owner has write permission.
      owner_write = 0200,
      /// @brief File owner has execute/search permission.
      owner_execute = 0100,
      /// @brief File owner has read, write and execute/search permission. Equivalent to xtd::io::file_permissions::owner_read | xtd::io::file_permissions::owner_write | xtd::io::file_permissions::owner_execute.
      owner_all = owner_read | owner_write | owner_execute,
      /// @brief The file's ueer group has read permission.
      group_read = 040,
      /// @brief The file's ueer group has write permission.
      group_write = 020,
      /// @brief The file's ueer group has execute/search permission.
      group_execute = 010,
      /// @brief The file's ueer group has read, write and execute/search permission. Equivalent to xtd::io::file_permissions::group_read | xtd::io::file_permissions::group_write | xtd::io::file_permissions::group_execute.
      group_all = group_read | group_write | group_execute,
      /// @brief Other ueers has read permission.
      others_read = 04,
      /// @brief Other ueers has write permission.
      others_write = 02,
      /// @brief Other ueers has execute/search permission.
      others_execute = 01,
      /// @brief Other ueers has read, write and execute/search permission. Equivalent to xtd::io::file_permissions::others_read| xtd::io::file_permissions::others_write | xtd::io::file_permissions::others_execute.
      others_all = others_read | others_write | others_execute,
      /// @brief All users have read, write, and execute/search permissions. Equivalent to xtd::io::file_permissions::owner_all | xtd::io::file_permissions::group_all | xtd::io::file_permissions::others_all.
      all = owner_all | group_all | others_all,
      /// @brief Set user ID to file owner user ID on execution.
      set_uid = 04000,
      /// @brief Set group ID to file's user group ID on execution.
      set_gid = 02000,
      /// @brief Implementation-defined meaning, but POSIX XSI specifies that when set on a directory, only file owners may delete files even if the directory is writeable to others (used with /tmp).
      sticky_bit = 01000,
      /// @brief All valid permission bits. Equivalent to xtd::io::file_permissions::all | xtd::io::file_permissions::set_uid | xtd::io::file_permissions::set_gid | xtd::io::file_permissions::sticky_bit
      mask = all | set_uid | set_gid | sticky_bit,
      /// @brief Unknown permissions (e.g. when file or directory is created without permissions).
      unknown = 0xFFF,
    };
  }
}

/// @cond
flags_attribute_(xtd::io, file_permissions);

template<> struct xtd::enum_register<xtd::io::file_permissions> {
  explicit operator auto() const noexcept {return xtd::enum_collection<xtd::io::file_permissions> {{xtd::io::file_permissions::none, "none"}, {xtd::io::file_permissions::owner_read, "owner_read"}, {xtd::io::file_permissions::owner_write, "owner_write"}, {xtd::io::file_permissions::owner_execute, "owner_execute"}, {xtd::io::file_permissions::group_read, "group_read"}, {xtd::io::file_permissions::group_write, "group_write"}, {xtd::io::file_permissions::group_execute, "group_execute"}, {xtd::io::file_permissions::others_read, "others_read"}, {xtd::io::file_permissions::others_write, "others_write"}, {xtd::io::file_permissions::others_execute, "others_execute"}, {xtd::io::file_permissions::set_uid, "set_uid"}, {xtd::io::file_permissions::set_gid, "set_gid"}, {xtd::io::file_permissions::sticky_bit, "sticky_bit"}, {xtd::io::file_permissions::unknown, "unknown"}};}
};
/// @endcond
