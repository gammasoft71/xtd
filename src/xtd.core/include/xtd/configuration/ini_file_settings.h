/// @file
/// @brief Contains xtd::configuration::ini_file_settings alias
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "file_settings.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains the types that provide the programming model for handling configuration data.
  namespace configuration {
    /// @brief Represents an object for storing and retrieving configuration information using text files in [INI format](https://en.wikipedia.org/wiki/INI_file).
    /// @par Header
    /// @code
    /// #include <xtd/configuration/ini_file_settings>
    /// @endcode
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core configuration
    /// @remarks An [INI file](https://en.wikipedia.org/wiki/INI_file) is a configuration file that consists of a text-based content with a structure and syntax comprising key–value pairs for properties, and sections that organize the properties.
    using init_file_settings = file_settings;
  }
}
