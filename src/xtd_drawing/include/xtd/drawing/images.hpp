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
      /// @brief Gets a system-defined image that represent back image. This field is constant.
      static const image back_256x256;
      /// @brief Gets a system-defined image that represent burn disk image. This field is constant.
      static const image burn_disk_256x256;
      /// @brief Gets a system-defined image that represent calendar image. This field is constant.
      static const image calendar_256x256;
      /// @brief Gets a system-defined image that represent cancel image. This field is constant.
      static const image cancel_256x256;
      /// @brief Gets a system-defined image that represent cancel 2image. This field is constant.
      static const image cancel2_256x256;
      /// @brief Gets a system-defined image that represent cdrom image. This field is constant.
      static const image cdrom_256x256;
      /// @brief Gets a system-defined image that represent copy image. This field is constant.
      static const image copy_256x256;
      /// @brief Gets a system-defined image that represent copy2 image. This field is constant.
      static const image copy2_256x256;
      /// @brief Gets a system-defined image that represent cut image. This field is constant.
      static const image cut_256x256;
      /// @brief Gets a system-defined image that represent gammasoft image. This field is constant.
      static const image gammasoft_256x256;
      /// @brief Gets a system-defined image that represent left image. This field is constant.
      static const image left_256x256;
    };
  }
}
