/// @file
/// @brief Contains xtd::collections::vector_list typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <any>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace collections {
    /// @brief Represents a collection of std::any.
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core collections
    /// @par Examples
    /// The following example shows hows to use xtd::collections::vector_list.
    /// @include vector_list.cpp
    using vector_list = std::vector<std::any>;
  }
}
