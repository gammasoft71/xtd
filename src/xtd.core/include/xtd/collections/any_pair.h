/// @file
/// @brief Contains xtd::collections::any_pair typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace collections {
    /// @brief Implements a std::pair with the key and the value strongly typed to be std::any.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    using any_pair = std::pair<std::any, std::any>;
  }
}
