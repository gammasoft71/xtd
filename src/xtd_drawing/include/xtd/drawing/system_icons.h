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
      static xtd::drawing::icon application() {return application(default_size());}
      static xtd::drawing::icon application(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("application-x-executable", size)));}
      static xtd::drawing::icon error() {return error(default_size());}
      static xtd::drawing::icon error(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-error", size)));}
      static xtd::drawing::icon exclamation() {return exclamation(default_size());}
      static xtd::drawing::icon exclamation(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-warning", size)));}
      static xtd::drawing::icon information() {return information(default_size());}
      static xtd::drawing::icon information(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-information", size)));}
      static xtd::drawing::icon question() {return question(default_size());}
      static xtd::drawing::icon question(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-question", size)));}
      static xtd::drawing::icon shield() {return shield(default_size());}
      static xtd::drawing::icon shield(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("dialog-password", size)));}
      static xtd::drawing::icon win_logo() {return win_logo(default_size());}
      static xtd::drawing::icon win_logo(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("windows", "start-here", size)));}

      static xtd::drawing::size default_size() {return {32, 32};}
      static xtd::drawing::icon macos_logo() {return macos_logo(default_size());}
      static xtd::drawing::icon macos_logo(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("macos", "start-here", size)));}
      static xtd::drawing::icon gnome_logo() {return gnome_logo(default_size());}
      static xtd::drawing::icon gnome_logo(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("gnome", "start-here", size)));}
      static xtd::drawing::icon xtd_logo() {return xtd_logo(default_size());}
      static xtd::drawing::icon xtd_logo(const xtd::drawing::size& size) {return xtd::drawing::icon::from_bitmap(bitmap(system_images::from_name("xtd", "start-here", size)));}
    };
  }
}
  
