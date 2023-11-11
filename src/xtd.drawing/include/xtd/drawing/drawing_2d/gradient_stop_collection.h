/// @file
/// @brief Contains xtd::drawing::drawing_2d::gradient_stop alias.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "drawing2d.h"
#include "gradient_stop.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Represents a collection of xtd::drawing::drawing_2d::gradient_stop objects that can be individually accessed by index.
      /// @par Namespace
      /// xtd::drawing::drawing_2d/
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      using gradient_stop_collection = std::vector<xtd::drawing::drawing_2d::gradient_stop>;
    }
  }
}

