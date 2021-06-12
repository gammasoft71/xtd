/// @file
/// @brief Contains xtd::security::secure_string class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides the underlying structure of the common language runtime security system, including base classes for permissions.
  namespace security {
    /// @brief Represents text that should be kept confidential, such as by deleting it from computer memory when no longer needed. This class cannot be inherited.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core security
    using secure_string = std::string;
  }
}
