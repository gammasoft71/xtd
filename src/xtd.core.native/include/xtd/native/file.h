/// @file
/// @brief Contains file API.
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
#include "file_attribute.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace io {
    class file_info;
  }
  /// @endcond

  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains file native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ file final {
      file() = delete;
      friend xtd::io::file_info;
    protected:
      /// @brief Copy a specified source file to a target file.
      /// @param source_file The source file to copy.
      /// @param target_file The target file where copy.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t copy(const std::string& source_file, const std::string& target_file);
      /// @brief Get file size of specified path.
      /// @param path The relative or absolute path to the directory to get size.
      /// @return The file size.
      /// @warning Internal use only
      static size_t get_size(const std::string& path);
      /// @brief Moves a file or a directory and its contents to a new location.
      /// @param old_path The path of the file or directory to move.
      /// @param new_path The path to the new location for old_path. If old_path is a file, then new_path must also be a file name.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t move(const std::string& old_path, const std::string& new_path);
      /// @brief Permanently deletes a speccified file.
      /// @param file The file name to delete.
      /// @return 0 if success; otherwise failed.
      /// @warning Internal use only
      static int32_t remove(const std::string& file);
    };
  }
}
