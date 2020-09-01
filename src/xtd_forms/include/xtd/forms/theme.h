#pragma once
#include "theme_base.h"
#include "theme_colors.h"
#include "theme_images.h"
#include "theme_renderers.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class theme final : public theme_base {
    public:
      theme() = default;
      explicit theme(const std::string& name) : theme_base(name) {}
      theme(const std::string& name, xtd::forms::theme_style theme_style) : theme_base(name, theme_style), theme_colors_(theme_colors::theme_from_name(name)), theme_images_(theme_images::theme_from_name(name)), theme_renderers_(theme_renderers::theme_from_name(name)) {}
      theme(const std::string& name, xtd::forms::theme_style theme_style, const theme_colors& theme_colors) : theme_base(name, theme_style), theme_colors_(theme_colors) {}
      theme(const std::string& name, xtd::forms::theme_style theme_style, const theme_images& theme_images) : theme_base(name, theme_style), theme_images_(theme_images) {}
      theme(const std::string& name, xtd::forms::theme_style theme_style, const theme_renderers& theme_renderers) : theme_base(name, theme_style), theme_renderers_(theme_renderers) {}
      theme(const std::string& name, xtd::forms::theme_style theme_style, const theme_colors& theme_colors, const theme_images& theme_images) : theme_base(name, theme_style), theme_colors_(theme_colors), theme_images_(theme_images) {}
      theme(const std::string& name, xtd::forms::theme_style theme_style, const theme_colors& theme_colors, const theme_images& theme_images, const theme_renderers& theme_renderers) : theme_base(name, theme_style), theme_colors_(theme_colors), theme_images_(theme_images), theme_renderers_(theme_renderers) {}
      /// @cond
      theme(const theme&) = default;
      theme& operator=(const theme&) = default;
      bool operator==(const theme& value) const {return theme_base::operator==(value);}
      bool operator!=(const theme& value) const {return !operator==(value);}
      /// @endcond

      static const theme empty;

      static const theme& current_theme() {
        if (current_theme_ == theme::empty) current_theme_ = default_theme();
        return current_theme_;
      }
      static void current_theme(const theme& theme) {
        current_theme_ = theme;
        theme_colors::current_theme(current_theme_.theme_colors_);
        theme_images::current_theme(current_theme_.theme_images_);
        theme_renderers::current_theme(current_theme_.theme_renderers_);
      }
      static void current_theme(const std::string& name) {current_theme(theme_from_name(name));}

      static theme default_theme() {return theme_from_name(default_theme_name());}

      static theme theme_from_name(const std::string& theme_name);
      
    private:
      theme(const std::string& name, xtd::forms::theme_style theme_style, bool is_default) : theme_base(name, theme_style, is_default) {}
      theme_colors theme_colors_ = theme_colors::current_theme();
      theme_images theme_images_ = theme_images::current_theme();
      theme_renderers theme_renderers_ = theme_renderers::current_theme();
      static theme current_theme_;
    };
  }
}
