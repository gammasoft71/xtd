#pragma once
#include <xtd/static.hpp>
#include "image.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
  /// @brief Provides a collection of image objects for use by a Windows Forms application.
    class images static_ {
    public:
      /// @brief Gets a system-defined image that represent about image. This field is constant.
      static const image about_256x256;
      /// @brief Gets a system-defined image that represent add image. This field is constant.
      static const image add_256x256;
      /// @brief Gets a system-defined image that represent apply image. This field is constant.
      static const image apply_256x256;
      /// @brief Gets a system-defined image that represent archive image. This field is constant.
      static const image archive_256x256;
      /// @brief Gets a system-defined image that represent audio disk image. This field is constant.
      static const image audio_disk_256x256;
      /// @brief Gets a system-defined image that represent gammasoft image. This field is constant.
      static const image gammasoft_256x256;
    };
  }
}
