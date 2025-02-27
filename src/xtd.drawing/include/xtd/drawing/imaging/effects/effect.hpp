/// @file
/// @brief Contains xtd::drawing::imaging::effects::effect struct.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include <xtd/abstract>
#include "../../graphics.hpp"
#include "../../rectangle.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::drawing::imaging namespace provides advanced GDI+ imaging functionality. Basic graphics functionality is provided by the xtd.drawing namespace.
    /// @remarks The metafile class provides methods for recording and saving metafiles. The encoder class enables users to extend GDI+ to support any image format. The property_item class provides methods for storing and retrieving metadata in image files.
    namespace imaging {
      /// @cond
      class image_effector;
      /// @endcond
      
      /// @brief The xtd::drawing::imaging::effects namespace provides functionality for adding effects to images.
      namespace effects {
        /// @brief Represents the base class for all effects.
        /// @par Namespace
        /// xtd::drawing::imaging::effects
        /// @par Library
        /// xtd.drawing
        /// @ingroup xtd_drawing effects
        /// @par Examples
        /// The following code shows how to use xtd::drawing::imaging::image_effector, and all effect inherited from xtd::drawing::imaging::effects::effect.
        /// [image_converter](https://github.com/gammasoft71/xtd/blob/master/examples/xtd.forms.examples/drawing/image_converter/README.md)
        struct effect abstract_ {
          friend class xtd::drawing::imaging::image_effector;
        protected:
          /// @name Protected Methods
          
          /// @{
          /// @brief Apply the effect.
          /// @param graphics The graphics to apply effect.
          /// @param image The image where the effect is applied.
          virtual void apply(xtd::drawing::image& image) const = 0;
          /// @}
        };
      }
    }
  }
}
