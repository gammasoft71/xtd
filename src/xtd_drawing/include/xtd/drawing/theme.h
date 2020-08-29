#pragma once
#include <string>
#include <vector>
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    class theme_image : public xtd::static_class {
    public:
      static std::string default_theme();
      static std::string fallback_theme();
      static std::vector<std::string> themes();
    };
  }
}
  
