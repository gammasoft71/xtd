/// @file
/// @brief Contains xtd::forms::theme class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "theme_base.h"
#include "theme_colors.h"
#include "theme_images.h"
#include "theme_renderers.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class forms_export_ theme final : public theme_base {
    public:
      theme() = default;
      explicit theme(const xtd::ustring& name) : theme(name, xtd::forms::theme_style::system_auto, false) {}
      theme(const xtd::ustring& name, xtd::forms::theme_style theme_style) : theme(name, theme_style, false) {}
      theme(const xtd::ustring& name, xtd::forms::theme_style theme_style, const xtd::forms::theme_colors& theme_colors) : theme_base(name, theme_style), theme_colors_(theme_colors) {}
      theme(const xtd::ustring& name, xtd::forms::theme_style theme_style, const xtd::forms::theme_images& theme_images) : theme_base(name, theme_style), theme_images_(theme_images) {}
      theme(const xtd::ustring& name, xtd::forms::theme_style theme_style, const xtd::forms::theme_renderers& theme_renderers) : theme_base(name, theme_style), theme_renderers_(theme_renderers) {}
      theme(const xtd::ustring& name, xtd::forms::theme_style theme_style, const xtd::forms::theme_colors& theme_colors, const xtd::forms::theme_images& theme_images) : theme_base(name, theme_style), theme_colors_(theme_colors), theme_images_(theme_images) {}
      theme(const xtd::ustring& name, xtd::forms::theme_style theme_style, const xtd::forms::theme_colors& theme_colors, const xtd::forms::theme_images& theme_images, const xtd::forms::theme_renderers& theme_renderers) : theme_base(name, theme_style), theme_colors_(theme_colors), theme_images_(theme_images), theme_renderers_(theme_renderers) {}
      /// @cond
      theme(const theme&) = default;
      theme& operator=(const theme&) = default;
      bool operator==(const theme& value) const {return theme_base::operator==(value);}
      bool operator!=(const theme& value) const {return !operator==(value);}
      /// @endcond

      const xtd::forms::theme_colors& theme_colors() const {return theme_colors_;}
      xtd::forms::theme_colors& theme_colors() {return theme_colors_;}
      theme& theme_colors(const xtd::forms::theme_colors& theme_colors) {
        if (theme_colors_ != theme_colors)
          theme_colors_ = theme_colors;
        return *this;
      }
      
      const xtd::forms::theme_images& theme_images() const {return theme_images_;}
      xtd::forms::theme_images& theme_images() {return theme_images_;}
      theme& theme_images(const xtd::forms::theme_images& theme_images) {
        if (theme_images_ != theme_images)
          theme_images_ = theme_images;
        return *this;
      }
      
      const xtd::forms::theme_renderers& theme_renderers() const {return theme_renderers_;}
      xtd::forms::theme_renderers& theme_renderers() {return theme_renderers_;}
      theme& theme_renderers(const xtd::forms::theme_renderers& theme_renderers) {
        if (theme_renderers_ != theme_renderers)
          theme_renderers_ = theme_renderers;
        return *this;
      }
      
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
      static void current_theme(const xtd::ustring& name) {current_theme(theme_from_name(name));}

      static theme default_theme() {return theme_from_name(default_theme_name());}

      static theme theme_from_name(const xtd::ustring& theme_name);
      
    private:
      theme(const xtd::ustring& name, xtd::forms::theme_style theme_style, bool is_default) : theme_base(name, theme_style, is_default), theme_colors_(theme_colors::theme_from_name(name)), theme_images_(theme_images::theme_from_name(name)), theme_renderers_(theme_renderers::theme_from_name(name)) {}
      xtd::forms::theme_colors theme_colors_ = xtd::forms::theme_colors::current_theme();
      xtd::forms::theme_images theme_images_ = xtd::forms::theme_images::current_theme();
      xtd::forms::theme_renderers theme_renderers_ = xtd::forms::theme_renderers::current_theme();
      static theme current_theme_;
    };
  }
}
