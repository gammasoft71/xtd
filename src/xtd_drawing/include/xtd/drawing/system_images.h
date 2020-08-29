#pragma once
#include "bitmap.h"
#include "size.h"
#include "theme.h"
#include <map>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the system_images class is an image object for Windows system-wide images. This class cannot be inherited.
    /// @remarks Each property of the system_fonts class returns a Font used to display text in a particular Windows display element, such as the title bar of a window. These fonts reflect the current settings in Control Panel.
    class system_images : public theme_image {
    public:
      static xtd::drawing::size default_size() {return {32, 32};}
      static xtd::drawing::image image_loading() {return image_loading(default_size());}
      static xtd::drawing::image image_loading(const xtd::drawing::size& size) {return system_images::from_name("image-loading", size);}
      static xtd::drawing::image image_missing() {return image_missing(default_size());}
      static xtd::drawing::image image_missing(const xtd::drawing::size& size) {return from_name("image-missing", size);}

      static xtd::drawing::image from_name(const std::string& name) {return from_name(default_theme(), name, default_size());}
      static xtd::drawing::image from_name(const std::string& name, const xtd::drawing::size& size) {return from_name(default_theme(), name, size);}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name) {return from_name(theme, name, default_size());}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name, const xtd::drawing::size& size);

      static std::vector<std::string> contexts();
      static std::map<std::string, std::vector<std::string>> context_names();
      static std::vector<std::string> names();
      static std::vector<std::string> names(const std::string& context) {return context_names()[context];}
      static std::vector<xtd::drawing::size> sizes();
    };
  }
}
  
