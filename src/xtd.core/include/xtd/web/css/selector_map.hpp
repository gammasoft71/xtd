/// @file
/// @brief Contains xtd::web::css::selector_map alias.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "selector.hpp"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      /// @brief Represents the map of a selector name - selector pair.
      using selector_map = std::map<xtd::string, xtd::web::css::selector>;
    }
  }
}
