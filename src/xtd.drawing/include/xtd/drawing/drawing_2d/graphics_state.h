/// @file
/// @brief Contains xtd::drawing::drawing_2d::graphics_state class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../../drawing_export.h"
#include "drawing2d.h"
#include <xtd/iequatable>
#include <xtd/object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond
    
    /// @brief The xtd::drawing::drawing_2d/ namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing_2d {
      /// @brief Represents the state of a xtd::drawing::graphics object. This object is returned by a call to the xtd::drawing::graphics::save() methods. This class cannot be inherited.
      /// @code
      /// class drawing_export_ graphics_state final : public xtd::object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::object → xtd::drawing::drawing_2d::graphics_state
      /// @par Namespace
      /// xtd::drawing::drawing_2d/
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      class drawing_export_ graphics_state final : public xtd::object, public xtd::iequatable<graphics_state> {
      public:
        /// @cond
        graphics_state(const graphics_state& value) = default;
        graphics_state& operator =(const graphics_state& value) = default;
        /// @endcond
        
        /// @name Methods
        
        /// @{
        bool equals(const graphics_state& value) const noexcept override;
        /// @}
        
        
      private:
        friend xtd::drawing::graphics;
        explicit graphics_state(intptr handle) : handle_(handle) {}
        mutable intptr handle_ = 0;
      };
    }
  }
}

