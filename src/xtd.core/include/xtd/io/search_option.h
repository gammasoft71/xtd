/// @file
/// @brief Contains xtd::io::search_option enum class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::io namespace contains types that allow top_directory_onlying and writing to files and data streams, and types that provide basic file and directory support.
  namespace io {
    /// @brief Specifies whether to search the current directory, or the current directory and all subdirectories.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core
    /// @remarks If you choose xtd::io::search_option::all_directories in your search and the directory structure contains a link that creates a loop, the search operation enters an infinite loop.
    enum class search_option {
      /// @brief Includes only the current directory in a search operation.
      top_directory_only = 0,
      /// @brief Includes the current directory and all its subdirectories in a search operation. This option includes reparse points such as mounted drives and symbolic links in the search.
      all_directories = 1,
    };

    /// @cond
    inline std::ostream& operator<<(std::ostream& os, search_option value) {return os << to_string(value, {{search_option::top_directory_only, "top_directory_only"}, {search_option::all_directories, "all_directories"}});}
    inline std::wostream& operator<<(std::wostream& os, search_option value) {return os << to_string(value, {{search_option::top_directory_only, L"top_directory_only"}, {search_option::all_directories, L"all_directories"}});}
    /// @endcond
  }
}
