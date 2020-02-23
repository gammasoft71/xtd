#pragma once
#include <filesystem>
#include "../control.hpp"

#if !defined(__XTD_FORMS_RESOURCES_PATH__)
#  define __XTD_FORMS_RESOURCES_PATH__ ""
#endif

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms::properties {
    /// @brief A strongly-typed resource class, for looking up localized strings, etc.
    class resources static_ {
    public:
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& gammasoft() {
        if (!std::filesystem::exists(std::filesystem::path(__XTD_FORMS_RESOURCES_PATH__)/"pictures"/"gammasoft.png")) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(__XTD_FORMS_RESOURCES_PATH__, "pictures", "gammasoft.png"));
        return bitmap;
      }
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& xtd() {
        if (!std::filesystem::exists(std::filesystem::path(__XTD_FORMS_RESOURCES_PATH__)/"pictures"/"xtd.png")) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(__XTD_FORMS_RESOURCES_PATH__, "pictures", "xtd.png"));
        return bitmap;
      }
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& xtd_console() {
        if (!std::filesystem::exists(std::filesystem::path(__XTD_FORMS_RESOURCES_PATH__)/"pictures"/"xtd_console.png")) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(__XTD_FORMS_RESOURCES_PATH__, "pictures", "xtd_console.png"));
        return bitmap;
      }
      
      /// @brief Looks up a localized resource of type xtd::drawing::bitmap.
      static const xtd::drawing::bitmap& xtd_forms() {
        if (!std::filesystem::exists(std::filesystem::path(__XTD_FORMS_RESOURCES_PATH__)/"pictures"/"xtd_forms.png")) return xtd::drawing::bitmap::empty;
        static xtd::drawing::bitmap bitmap(xtd::io::path::combine(__XTD_FORMS_RESOURCES_PATH__, "pictures", "xtd_forms.png"));
        return bitmap;
      }

    };
  }
}
