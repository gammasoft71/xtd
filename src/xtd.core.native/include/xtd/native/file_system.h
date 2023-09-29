/// @file
/// @brief Contains file_system API.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "file_attribute.h"
#include <xtd/core_native_export>
#include <cstdint>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace io {
    class directory;
    class directory_info;
    class file;
    class file_info;
    class file_system_info;
    class path;
    
  }
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @cond
    class directory;
    class drive;
    class file;
    class speech_synthesizer;
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
      friend xtd::io::directory;
      friend xtd::io::directory_info;
      friend xtd::io::file;
      friend xtd::io::file_info;
      friend xtd::io::file_system_info;
      friend xtd::io::path;
      friend xtd::native::directory;
      friend xtd::native::drive;
      friend xtd::native::file;
      friend xtd::native::speech_synthesizer;
    protected:
      /// @brief Gets the attributes for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param attribute The file or path attribute. (see file_attribute.h)
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int_least32_t get_attributes(const std::string& path, int_least32_t& attributes);
      /// @brief Gets file creeation time, last access time and lastt write time of specified path.
      /// @param path The relative or absolute path to the directory to get times.
      /// @param creation_time That contains the creation time.
      /// @param last_access_time That contains the last access time.
      /// @param last_write_time That contains the last write time.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int_least32_t get_file_times(const std::string& path, time_t& creation_time, time_t& last_access_time, time_t& last_write_time);
      /// @brief Gets full path of specified path.
      /// @param relative_path The relative path to the directory to search.
      /// @return The fulll path.
      /// @warning Internal use only
      static std::string get_full_path(const std::string& relative_path);
      /// @brief Check if specified path is too long for the OS.
      /// @param path The path to cjheck the size.
      /// @return true if path too long; otherwiser false.
      /// @warning Internal use only
      static bool is_path_too_long(const std::string& path);
      /// @brief Sets the attributes for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param attribute The file or path attribute. (see file_attribute.h)
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int_least32_t set_attributes(const std::string& path, int_least32_t attributes);
      /// @brief Sets the creation time for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param creation_time The file or path creation time.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int_least32_t set_creation_time(const std::string& path, time_t creation_time);
      /// @brief Sets the last access time for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param last_access_time The file or path last access time.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int_least32_t set_last_access_time(const std::string& path, time_t last_access_time);
      /// @brief Sets the last write time for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param last_write_time The file or path last write time.
      /// @return 0 if success; -1 operation is not supported; otherwise failed.
      /// @warning Internal use only
      static int_least32_t set_last_write_time(const std::string& path, time_t last_write_time);
      /// @brief Gets the permissions for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param attribute The file or path permissions. (see file_permission.h)
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int_least32_t get_permissions(const std::string& path, int_least32_t& permissions);
      /// @brief Sets the permissions for the specified file or directory path.
      /// @param path The relative or absolute path to the directory to get attribute.
      /// @param attribute The file or path permissions. (see file_permission.h)
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int_least32_t set_permissions(const std::string& path, int_least32_t permissions);
    };
  }
}
