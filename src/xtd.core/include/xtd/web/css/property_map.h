/// @file
/// @brief Contains xtd::web::css::property_map typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "property.h"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      using property_map = std::map<xtd::ustring, xtd::web::css::property>;
    }
  }
}
