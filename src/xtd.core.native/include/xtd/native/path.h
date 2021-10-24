/// @file
/// @brief Contains path API.
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
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace io {
    class path;
  }
  /// @endcond

  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @cond
    class directory;
    /// @endcond

    /// @brief Contains path native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ path final {
      path() = delete;
      friend xtd::io::path;
      friend xtd::native::directory;
    protected:
      /// @brief Provides a platform-specific alternate character used to separate directory levels in a path string that reflects a hierarchical file system organization.
      /// @return A platform-specific alternate character used to separate directory levels in a path string.
      /// @warning Internal use only
      static char alt_directory_separator_char();
      /// @brief Provides a platform-specific character used to separate directory levels in a path string that reflects a hierarchical file system organization.
      /// @return A platform-specific character used to separate directory levels in a path string.
      /// @warning Internal use only
      static char directory_separator_char();
      /// @brief Gets temp path.
      /// @return The temp path.
      /// @warning Internal use only
      static std::string get_temp_path();
      /// @brief Provides a platform-specific array of characters that cannot be specified in path string arguments passed to members of the Path class.
      /// @return A platform-specific array of characters that cannot be specified in path string.
      /// @warning Internal use only
      static std::vector<char> invalid_path_chars();
      /// @brief Provides a platform-specific separator character used to separate path strings in environment variables.A platform-specific separator character used to separate path strings in environment variables.
      /// @return A platform-specific separator character used to separate path strings.
      /// @warning Internal use only
      static char path_separator();
      /// @brief Provides a platform-specific volume separator character.
      /// @return A platform-specific volume separator character.
      /// @warning Internal use only
      static char volume_separator_char();
    };
  }
}
