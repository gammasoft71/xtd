/// @file
/// @brief Contains xtd::forms::properties::resources class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/environment.h>
#include "../control.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms::properties {
    /// @brief A strongly-typed resource class, for looking up localized strings, etc.
    /// @par Namespace
    /// xtd::forms::properties
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class resources final static_ {
    public:
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& cursor_arrow() {
        if (!xtd::io::file::exists(xtd::io::path::combine(forms_resource_path_, "cursors", xtd::ustring::format("arrow{}.png", get_os_potfix())))) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(forms_resource_path_, "cursors", xtd::ustring::format("arrow{}.png", get_os_potfix())));
        return bitmap;
      }
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& cursor_no_move_2d() {
        if (!xtd::io::file::exists(xtd::io::path::combine(forms_resource_path_, "cursors", xtd::ustring::format("cursor_no_move_2d{}.png", get_os_potfix())))) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(forms_resource_path_, "cursors", xtd::ustring::format("cursor_no_move_2d{}.png", get_os_potfix())));
        return bitmap;
      }
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& gammasoft() {
        if (!xtd::io::file::exists(xtd::io::path::combine(forms_resource_path_, "pictures", "gammasoft.png"))) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(forms_resource_path_, "pictures", "gammasoft.png"));
        return bitmap;
      }
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& xtd() {
        if (!xtd::io::file::exists(xtd::io::path::combine(forms_resource_path_, "pictures", "xtd.png"))) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(forms_resource_path_, "pictures", "xtd.png"));
        return bitmap;
      }
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& xtd_console() {
        if (!xtd::io::file::exists(xtd::io::path::combine(forms_resource_path_, "pictures", "xtd_console.png"))) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(forms_resource_path_, "pictures", "xtd_console.png"));
        return bitmap;
      }
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& xtd_forms() {
        if (!xtd::io::file::exists(xtd::io::path::combine(forms_resource_path_, "pictures", "xtd_forms.png"))) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(forms_resource_path_, "pictures", "xtd_forms.png"));
        return bitmap;
      }

    private:
      static std::string get_os_potfix() noexcept {return xtd::environment::os_version().is_windows_platform() ? "_w" : xtd::environment::os_version().is_linux_platform() ? "_g" : xtd::environment::os_version().is_macos_platform() ? "_m" : "";}
#if defined(__XTD_RESOURCES_PATH__)
      static constexpr const char* forms_resource_path_ = __XTD_RESOURCES_PATH__;
#else
      static constexpr const char* forms_resource_path_ = "";
#endif
    };
  }
}
