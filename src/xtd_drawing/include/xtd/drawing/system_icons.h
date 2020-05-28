#pragma once
#include "icon.h"
#include "system_images.h"
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
      static xtd::drawing::icon application() {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("application-x-executable")));}
      static xtd::drawing::icon error() {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-error")));}
      static xtd::drawing::icon exclamation() {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-warning")));}
      static xtd::drawing::icon information() {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-information")));}
      static xtd::drawing::icon question() {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-question")));}
      static xtd::drawing::icon shield() {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-password")));}
      static xtd::drawing::icon win_logo() {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("windows", "start-here")));}
      
      static xtd::drawing::icon macos_logo() {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("macos", "start-here")));}
      static xtd::drawing::icon gnome_logo() {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("gnome", "start-here")));}
    };
  }
}
  
