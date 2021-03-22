/// @file
/// @brief Contains xtd::html::css::property_map typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "property.h"
#include <map>

namespace xtd {
  namespace html {
    namespace css {
      using property_map = std::map<std::string, xtd::html::css::property>;
    }
  }
}
