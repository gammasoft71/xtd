/// @file
/// @brief Contains file_system API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstdint>
#include <string>
#include <chrono>
#include "file_attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace io {
    class directory_info;
    class file;
    class file_info;
    class file_system_info;
  }
  /// @endcond

  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @cond
    class directory;
    class drive;
    class file;
    /// @endcond
  
    /// @brief Contains file_system native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ file_system final {
      file_system() = delete;
      friend xtd::io::directory_info;
      friend xtd::io::file;
      friend xtd::io::file_info;
      friend xtd::io::file_system_info;
      friend xtd::native::directory;
      friend xtd::native::drive;
      friend xtd::native::file;
    protected:
      /// @brief Gets the attributes for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param attribute The file or path attribute. (see file_attribute.h)
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t get_attributes(const std::string& path, int32_t& attributes);
      /// @brief Get file creeation time, last access time and lastt write time of specified path.
      /// @param path The relative or absolute path to the directory to get times.
      /// @param creation_time That contains the creation time.
      /// @param last_access_time That contains the last access time.
      /// @param last_write_time That contains the last write time.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t get_file_times(const std::string& path, std::chrono::system_clock::time_point& creation_time, std::chrono::system_clock::time_point& last_access_time, std::chrono::system_clock::time_point& last_write_time);
      /// @brief Get full path of specified path.
      /// @param relative_path The relative path to the directory to search.
      /// @return The fulll path.
      /// @warning Internal use only
      static std::string get_full_path(const std::string& relative_path);
      /// @brief Check if specified path is too long for the OS.
      /// @param path The path to cjheck the size.
      /// @return true if path too long; otherwiser false.
      /// @warning Internal use only
      static bool is_path_too_long(const std::string& path);
      /// @brief Sets the creation time for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param creation_time The file or path creation time.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int32_t set_creation_time(const std::string& path, std::chrono::system_clock::time_point& creation_time);
      /// @brief Sets the attributes for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param attribute The file or path attribute. (see file_attribute.h)
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int32_t set_file_attributes(const std::string& path, int32_t attributes);
      /// @brief Sets the last access time for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param last_access_time The file or path last access time.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int32_t set_last_access_time(const std::string& path, std::chrono::system_clock::time_point& last_access_time);
      /// @brief Sets the last write time for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param last_write_time The file or path last write time.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int32_t set_last_write_time(const std::string& path, std::chrono::system_clock::time_point& last_write_time);
    };
  }
}
