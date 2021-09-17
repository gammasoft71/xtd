/// @file
/// @brief Contains xtd::web::css::selector_map typedef.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "selector.h"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      using selector_map = std::map<xtd::ustring, xtd::web::css::selector>;
    }
  }
}
