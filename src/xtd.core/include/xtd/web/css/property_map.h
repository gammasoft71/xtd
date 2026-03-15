/// @file
/// @brief Contains xtd::web::css::property_map typedef.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#if defined(_MSC_VER) && __cplusplus < 202302L
#  pragma message("Deprecated : Replaced by #include <xtd/web/css/property_map.hpp> - Will be removed in version 0.4.0.")
#else
#  warning "Deprecated : Replaced by #include <xtd/web/css/property_map.hpp> - Will be removed in version 0.4.0."
#endif
#include "property_dictionary.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      /// @brief Represents the map of a property name - property pair.
      /// @deprecated Replaced by xtd::web::css::property_dictionary - Will be removed in version 0.4.0.
      using property_map [[deprecated("Replaced by xtd::web::css::property_dictionary - Will be removed in version 0.4.0.")]] = xtd::web::css::property_dictionary;
    }
  }
}
