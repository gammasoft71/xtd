/// @file
/// @brief Contains xtd::io::file_permissions enum class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow reading and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Provides permissions for files and directories.
    /// @code
    /// enum class file_permissions
    /// @endcode
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
      owner_all = owner_read|owner_write|owner_execute,
      /// @brief The file's ueer group has read permission.
      group_read = 010,
      /// @brief The file's ueer group has write permission.
      group_write = 020,
      /// @brief The file's ueer group has execute/search permission.
      group_execute = 010,
      /// @brief The file's ueer group has read, write and execute/search permission. Equivalent to xtd::io::file_permissions::group_read | xtd::io::file_permissions::group_write | xtd::io::file_permissions::group_execute.
      group_all = group_read|group_write|group_execute,
      /// @brief Other ueers has read permission.
      others_read = 04,
      /// @brief Other ueers has write permission.
      others_write = 02,
      /// @brief Other ueers has execute/search permission.
      others_execute = 01,
      /// @brief Other ueers has read, write and execute/search permission. Equivalent to xtd::io::file_permissions::others_read| xtd::io::file_permissions::others_write | xtd::io::file_permissions::others_execute.
      others_all = others_read|others_write|others_execute,
      /// @brief All users have read, write, and execute/search permissions. Equivalent to xtd::io::file_permissions::owner_all | xtd::io::file_permissions::group_all | xtd::io::file_permissions::others_all.
      all = owner_all|group_all|others_all,
      /// @brief Set user ID to file owner user ID on execution.
      set_uid = 04000,
      /// @brief Set group ID to file's user group ID on execution.
      set_gid = 02000,
      /// @brief Implementation-defined meaning, but POSIX XSI specifies that when set on a directory, only file owners may delete files even if the directory is writeable to others (used with /tmp).
      sticky_bit = 01000,
      /// @brief All valid permission bits. Equivalent to xtd::io::file_permissions::all | xtd::io::file_permissions::set_uid | xtd::io::file_permissions::set_gid | xtd::io::file_permissions::sticky_bit
      mask = all|set_uid|set_gid|sticky_bit,
      /// @brief Unknown permissions (e.g. when file or directory is created without permissions).
      unknown = 0xFFF,
    };
    
    /// @cond
    inline file_permissions& operator^=(file_permissions& lhs, file_permissions rhs) {lhs = static_cast<file_permissions>(static_cast<int>(lhs) ^ static_cast<int>(rhs)); return lhs;}
    inline file_permissions& operator&=(file_permissions& lhs, file_permissions rhs) {lhs = static_cast<file_permissions>(static_cast<int>(lhs) & static_cast<int>(rhs)); return lhs;}
    inline file_permissions& operator|=(file_permissions& lhs, file_permissions rhs) {lhs = static_cast<file_permissions>(static_cast<int>(lhs) | static_cast<int>(rhs)); return lhs;}
    inline file_permissions& operator+=(file_permissions& lhs, file_permissions rhs) {lhs = static_cast<file_permissions>(static_cast<int>(lhs) + static_cast<int>(rhs)); return lhs;}
    inline file_permissions& operator-=(file_permissions& lhs, file_permissions rhs) {lhs = static_cast<file_permissions>(static_cast<int>(lhs) - static_cast<int>(rhs)); return lhs;}
    inline file_permissions operator^(file_permissions lhs, file_permissions rhs) {return static_cast<file_permissions>(static_cast<int>(lhs) ^ static_cast<int>(rhs));}
    inline file_permissions operator&(file_permissions lhs, file_permissions rhs) {return static_cast<file_permissions>(static_cast<int>(lhs) & static_cast<int>(rhs));}
    inline file_permissions operator|(file_permissions lhs, file_permissions rhs) {return static_cast<file_permissions>(static_cast<int>(lhs) | static_cast<int>(rhs));}
    inline file_permissions operator+(file_permissions lhs, file_permissions rhs) {return static_cast<file_permissions>(static_cast<int>(lhs) + static_cast<int>(rhs));}
    inline file_permissions operator-(file_permissions lhs, file_permissions rhs) {return static_cast<file_permissions>(static_cast<int>(lhs) - static_cast<int>(rhs));}
    inline file_permissions operator~(file_permissions lhs) {return static_cast<file_permissions>(~static_cast<int>(lhs));}
    inline std::ostream& operator<<(std::ostream& os, file_permissions value) {return os << to_string(value, {{file_permissions::none, "none"}, {file_permissions::owner_read, "owner_read"}, {file_permissions::owner_write, "owner_write"}, {file_permissions::owner_execute, "owner_execute"}, {file_permissions::group_read, "group_read"}, {file_permissions::group_execute, "group_execute"}, {file_permissions::others_read, "others_read"}, {file_permissions::others_write, "others_write"}, {file_permissions::others_execute, "others_execute"}, {file_permissions::set_uid, "set_uid"}, {file_permissions::set_gid, "set_gid"}, {file_permissions::sticky_bit, "sticky_bit"}, {file_permissions::unknown, "unknown"}});}
    inline std::wostream& operator<<(std::wostream& os, file_permissions value) {return os << to_string(value, {{file_permissions::none, L"none"}, {file_permissions::owner_read, L"owner_read"}, {file_permissions::owner_write, L"owner_write"}, {file_permissions::owner_execute, L"owner_execute"}, {file_permissions::group_read, L"group_read"}, {file_permissions::group_execute, L"group_execute"}, {file_permissions::others_read, L"others_read"}, {file_permissions::others_write, L"others_write"}, {file_permissions::others_execute, L"others_execute"}, {file_permissions::set_uid, L"set_uid"}, {file_permissions::set_gid, L"set_gid"}, {file_permissions::sticky_bit, L"sticky_bit"}, {file_permissions::unknown, L"unknown"}});}
    /// @endcond
  }
}
