/// @file
/// @brief Contains xtd::web::css::property_dictionary alias.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "property.hpp"
#include "../../collections/generic/sorted_dictionary.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  namespace web {
    namespace css {
      /// @brief Represents the dictionary of a property name - property pair.
      using property_dictionary = xtd::collections::generic::sorted_dictionary<xtd::string, xtd::web::css::property>;
    }
  }
}
