#pragma once
#include "icon.h"
#include "size.h"
#include <map>
#include <string>
#include <vector>
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the system_icons class is an icon object for Windows system-wide icons. This class cannot be inherited.
    /// @remarks Each property of the system_fonts class returns a Font used to display text in a particular Windows display element, such as the title bar of a window. These fonts reflect the current settings in Control Panel.
    class system_icons static_ {
    public:
      static xtd::drawing::icon application() {return from_name("application-x-executable");}
      static xtd::drawing::icon error() {return from_name("dialog-error");}
      static xtd::drawing::icon exclamation() {return from_name("dialog-warning");}
      static xtd::drawing::icon information() {return from_name("dialog-information");}
      static xtd::drawing::icon question() {return from_name("dialog-question");}
      static xtd::drawing::icon shield() {return from_name("dialog-password");}
      static xtd::drawing::icon win_logo() {return from_name("windows", "start-here");}
      
      static xtd::drawing::icon macos_logo() {return from_name("macos", "start-here");}
      static xtd::drawing::icon gnome_logo() {return from_name("gnome", "start-here");}

      static xtd::drawing::icon from_name(const std::string& name) {return from_name(default_theme(), name, size(32, 32));}
      static xtd::drawing::icon from_name(const std::string& name, const xtd::drawing::size& size) {return from_name(default_theme(), name, size);}
      static xtd::drawing::icon from_name(const std::string& theme, const std::string& name) {return from_name(theme, name, size(32, 32));}
      static xtd::drawing::icon from_name(const std::string& theme, const std::string& name, const xtd::drawing::size& size);

      static std::vector<std::string> contexts();
      static std::map<std::string, std::vector<std::string>> context_names();
      static std::string default_theme();
      static std::vector<std::string> names();
      static std::vector<std::string> names(const std::string& context) {return context_names()[context];}
      static std::vector<xtd::drawing::size> sizes();
      static std::vector<std::string> themes();
    };
  }
}
  
