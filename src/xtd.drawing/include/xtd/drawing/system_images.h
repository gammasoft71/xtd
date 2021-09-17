/// @file
/// @brief Contains xtd::drawing::system_images factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include <xtd/static.h>
#include "../drawing_export.h"
#include "bitmap.h"
#include "size.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class system_icons;
    /// @endcond

    /// @brief Each property of the system_images class is an image object for Windows system-wide images. This class cannot be inherited.
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks Each property of the system_fonts class returns a Font used to display text in a particular Windows display element, such as the title bar of a window. These fonts reflect the current settings in Control Panel.
    class drawing_export_ system_images final static_ {
    public:
      static xtd::drawing::size default_size() {return {32, 32};}
      static xtd::drawing::image image_loading() {return image_loading(default_size());}
      static xtd::drawing::image image_loading(const xtd::drawing::size& size) {return system_images::from_name("image-loading", size);}
      static xtd::drawing::image image_missing() {return image_missing(default_size());}
      static xtd::drawing::image image_missing(const xtd::drawing::size& size) {return from_name("image-missing", size);}

      static xtd::drawing::image from_name(const xtd::ustring& name) {return from_name(default_theme(), name, default_size());}
      static xtd::drawing::image from_name(const xtd::ustring& name, const xtd::drawing::size& size) {return from_name(default_theme(), name, size);}
      static xtd::drawing::image from_name(const xtd::ustring& theme, const xtd::ustring& name) {return from_name(theme, name, default_size());}
      static xtd::drawing::image from_name(const xtd::ustring& theme, const xtd::ustring& name, const xtd::drawing::size& size);

      static std::vector<xtd::ustring> contexts();
      static std::map<xtd::ustring, std::vector<xtd::ustring>> context_names();
      static std::vector<xtd::ustring> names();
      static std::vector<xtd::ustring> names(const xtd::ustring& context) {return context_names()[context];}
      static std::vector<xtd::drawing::size> sizes();
      
    private:
      friend class system_icons;
      static xtd::ustring default_theme();
      static xtd::ustring fallback_theme();
      static std::vector<xtd::ustring> themes();
    };
  }
}
  
