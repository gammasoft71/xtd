#pragma once
#include <xtd/delegate.h>
#include <xtd/drawing/image.h>
#include <xtd/drawing/size.h>
#include "theme_base.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class theme_images final : public theme_base {
    public:
      using image_getter = xtd::delegate<xtd::drawing::image(const std::string& name, const xtd::drawing::size& size)>;

      theme_images() = default;
      explicit theme_images(const std::string& name) : theme_base(name) {}
      theme_images(const std::string& name, xtd::forms::theme_style theme_style, const image_getter& image_getter) : theme_base(name, theme_style), image_getter_(image_getter) {}
      /// @cond
      theme_images(const theme_images&) = default;
      theme_images& operator=(const theme_images&) = default;
      bool operator==(const theme_images& value) const {return theme_base::operator==(value);}
      bool operator!=(const theme_images& value) const {return !operator==(value);}
      /// @endcond

      static const theme_images empty;

      static xtd::drawing::size default_size() {return {32, 32};}

      xtd::drawing::image from_name(const std::string& name) const {return from_name(name, default_size());}
      xtd::drawing::image from_name(const std::string& name, const xtd::drawing::size& size) const {return image_getter_(name, size);}
      
      static theme_images current_theme() {
        if (current_theme_ == theme_images::empty) current_theme_ = default_theme();
        return current_theme_;
      }
      static void current_theme(const theme_images& theme) {
        current_theme_ = theme;
      }
      static void current_theme(const std::string& name) {current_theme(theme_from_name(name));}

      static theme_images default_theme() {return theme_from_name(default_theme_name());}

      static theme_images theme_from_name(const std::string& theme_name);
      
    private:
      theme_images(const std::string& name, xtd::forms::theme_style theme_style, const image_getter& image_getter, bool is_default) : theme_base(name, theme_style, is_default), image_getter_(image_getter) {}
      image_getter image_getter_;
      static theme_images current_theme_;
    };
  }
}
