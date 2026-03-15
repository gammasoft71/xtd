/// @file
/// @brief Contains xtd::web::css::selector_map alias.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/web/css/selector_map.hpp> - Will be removed in version 0.4.0.")
#else
#  warning "Deprecated : Replaced by #include <xtd/web/css/selector_map.hpp> - Will be removed in version 0.4.0."
#endif
#include "selector_dictionary.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      /// @brief Represents the map of a selector name - selector pair.
      /// @deprecated Replaced by xtd::web::css::selector_dictionary - Will be removed in version 0.4.0.
      using selector_map [[deprecated("Replaced by xtd::web::css::selector_dictionary - Will be removed in version 0.4.0.")]] = xtd::web::css::selector_dictionary;
    }
  }
}
