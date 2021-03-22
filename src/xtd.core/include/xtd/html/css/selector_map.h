/// @file
/// @brief Contains xtd::html::css::selector_map typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "selector.h"
#include <map>

namespace xtd {
  namespace html {
    namespace css {
      using selector_map = std::map<std::string, xtd::html::css::selector>;
    }
  }
}
