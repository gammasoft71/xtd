/// @file
/// @brief Contains xtd::drawing::imaging::effects::effect  class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static>
#include "effects/effect.hpp"
#include "../image.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @brief The xtd::drawing::imaging::image_effector allows effects defined in the xtd::drawing::imaging::effects namespace to be applied to both xtd::drawing::image and xtd::drawing::graphics via overloaded xtd::drawing::imaging::image_effector::set_effect methods. This class cannot be inherited.
      /// @par Namespace
      /// xtd::drawing::imaging
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing effects
      class image_effector static_ {
      public:
        /// @name Public Static Methods
        
        /// @{
        /// @brief Sets the specified effects to the specifid image.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param effect The effect to apply.
        /// @return The resulting image.
        static xtd::drawing::image set_effect(const xtd::drawing::image& image, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param rectangle The xtd::drawing::rectangle to with apply effect.
        /// @param effect The effect to apply.
        /// @return The resulting image.
        static xtd::drawing::image set_effect(const xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param effect The effect to apply.
        static void set_effect(xtd::drawing::image& image, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid image with rectangle.
        /// @param image The xtd::drawing::image to which to apply the effect.
        /// @param rectangle The xtd::drawing::rectangle to with apply effect.
        /// @param effect The effect to apply.
        static void set_effect(xtd::drawing::image& image, const xtd::drawing::rectangle& rectangle, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid graphics.
        /// @param image The xtd::drawing::graphics to which to apply the effect.
        /// @param effect The effect to apply.
        static void set_effect(xtd::drawing::graphics& graphics, const xtd::drawing::imaging::effects::effect& effect);
        /// @brief Sets the specified effects to the specifid graphics with rectangle.
        /// @param image The xtd::drawing::graphics to which to apply the effect.
        /// @param rectangle The xtd::drawing::rectangle to with apply effect.
        /// @param effect The effect to apply.
        static void set_effect(xtd::drawing::graphics& graphics, const xtd::drawing::rectangle& rectangle, const xtd::drawing::imaging::effects::effect& effect);
        /// @}
      };
    }
  }
}
