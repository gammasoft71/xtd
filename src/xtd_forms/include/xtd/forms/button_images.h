#pragma once
#include <xtd/static.h>
#include <xtd/drawing/system_images.h>
#include "theme.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class button_images static_ {
    public:
      static xtd::drawing::image add() {return add(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image add(const std::string& theme) {return add(theme, size());}
      static xtd::drawing::image add(const xtd::drawing::size& size) {return add(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image add(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "list-add", size);}
      
      static xtd::drawing::image apply() {return apply(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image apply(const std::string& theme) {return apply(theme, size());}
      static xtd::drawing::image apply(const xtd::drawing::size& size) {return apply(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image apply(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-ok-apply", size);}
      
      static xtd::drawing::image ok() {return ok(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image ok(const std::string& theme) {return ok(theme, size());}
      static xtd::drawing::image ok(const xtd::drawing::size& size) {return ok(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image ok(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-ok", size);}
      
      static xtd::drawing::image cancel() {return cancel(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image cancel(const std::string& theme) {return cancel(theme, size());}
      static xtd::drawing::image cancel(const xtd::drawing::size& size) {return cancel(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image cancel(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-cancel", size);}
      
      static xtd::drawing::image next() {return next(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image next(const std::string& theme) {return next(theme, size());}
      static xtd::drawing::image next(const xtd::drawing::size& size) {return next(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image next(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "go-next", size);}
      
      static xtd::drawing::image no() {return no(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image no(const std::string& theme) {return no(theme, size());}
      static xtd::drawing::image no(const xtd::drawing::size& size) {return no(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image no(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-cancel", size);}

      static xtd::drawing::image previous() {return previous(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image previous(const std::string& theme) {return previous(theme, size());}
      static xtd::drawing::image previous(const xtd::drawing::size& size) {return previous(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image previous(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "go-previous", size);}

      static xtd::drawing::image remove() {return remove(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image remove(const std::string& theme) {return remove(theme, size());}
      static xtd::drawing::image remove(const xtd::drawing::size& size) {return remove(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image remove(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "list-remove", size);}
      
      static xtd::drawing::image yes() {return yes(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image yes(const std::string& theme) {return yes(theme, size());}
      static xtd::drawing::image yes(const xtd::drawing::size& size) {return yes(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image yes(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-ok", size);}

      static xtd::drawing::size size() {return {16, 16};}
      static xtd::drawing::image from_name(const std::string& name) {return from_name(name, size());}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name) {return from_name(theme, name, size());}
      static xtd::drawing::image from_name(const std::string& name, const xtd::drawing::size& size) {return from_name(xtd::forms::theme::default_theme_name(), name, size);}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name, const xtd::drawing::size& size) {return xtd::drawing::system_images::from_name(theme, name, size);}
    };
  }
}
