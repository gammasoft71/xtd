#pragma once
#include "theme_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class theme final : public theme_base {
    public:
      theme() = default;
      explicit theme(const std::string& name) : theme_base(name) {}
      theme(const std::string& name, xtd::forms::theme_style theme_style) : theme_base(name, theme_style) {}
      /// @cond
      theme(const theme&) = default;
      theme& operator=(const theme&) = default;
      bool operator==(const theme& value) const {return theme_base::operator==(value);}
      bool operator!=(const theme& value) const {return !operator==(value);}
      /// @endcond

      static const theme empty;

      static theme current_theme() {
        if (current_theme_ == theme::empty) current_theme_ = default_theme();
        return current_theme_;
      }
      static void current_theme(const theme& theme) {current_theme_ = theme;}
      static void current_theme(const std::string& name) {current_theme_ = theme_from_name(name);}

      static theme default_theme() {return theme_from_name(default_theme_name());}

      static theme theme_from_name(const std::string& theme_name);
      
    private:
      theme(const std::string& name, xtd::forms::theme_style theme_style, bool is_default) : theme_base(name, theme_style, is_default) {}
      static theme current_theme_;
    };
  }
}
