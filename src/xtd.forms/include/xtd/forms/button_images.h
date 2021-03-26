/// @file
/// @brief Contains xtd::forms::button_images factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/static.h>
#include <xtd/drawing/system_images.h>
#include "theme_images.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a button images factories for use by a button control.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class button_images final static_ {
    public:
      /// @brief Add image object.
      static xtd::drawing::image add() {return add(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Add image object with specified theme.
      /// @param theme A string that represent a theme
      static xtd::drawing::image add(const std::string& theme) {return add(theme, size());}
      /// @brief Add image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image add(const xtd::drawing::size& size) {return add(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Add image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image add(const std::string& theme, const xtd::drawing::size& size) {return add(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Add image object with specified theme images and size.
      /// @param theme A xtd::forms::theme_images that represent a theme images
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image add(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "list-add", size);}

      /// @brief Apply image object.
      static xtd::drawing::image apply() {return apply(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Apply image object with specified theme.
      /// @param theme A string that represent a theme
      static xtd::drawing::image apply(const std::string& theme) {return apply(theme, size());}
      /// @brief Apply image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image apply(const xtd::drawing::size& size) {return apply(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Apply image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image apply(const std::string& theme, const xtd::drawing::size& size) {return apply(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Apply image object with specified theme images and size.
      /// @param theme A xtd::forms::theme_images that represent a theme images
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image apply(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-ok-apply", size);}

      /// @brief Ok image object.
      static xtd::drawing::image ok() {return ok(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Ok image object with specified theme.
      /// @param theme A string that represent a theme
      static xtd::drawing::image ok(const std::string& theme) {return ok(theme, size());}
      /// @brief Ok image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image ok(const xtd::drawing::size& size) {return ok(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Ok image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image ok(const std::string& theme, const xtd::drawing::size& size) {return ok(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Ok image object with specified theme images and size.
      /// @param theme A xtd::forms::theme_images that represent a theme images
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image ok(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-ok", size);}

      /// @brief Cancel image object.
      static xtd::drawing::image cancel() {return cancel(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Cancel image object with specified theme.
      /// @param theme A string that represent a theme
      static xtd::drawing::image cancel(const std::string& theme) {return cancel(theme, size());}
      /// @brief Cancel image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image cancel(const xtd::drawing::size& size) {return cancel(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Cancel image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image cancel(const std::string& theme, const xtd::drawing::size& size) {return cancel(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Cancel image object with specified theme images and size.
      /// @param theme A xtd::forms::theme_images that represent a theme images
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image cancel(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-cancel", size);}

      /// @brief Next image object.
      static xtd::drawing::image next() {return next(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Next image object with specified theme.
      /// @param theme A string that represent a theme
      static xtd::drawing::image next(const std::string& theme) {return next(theme, size());}
      /// @brief Next image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image next(const xtd::drawing::size& size) {return next(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Next image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image next(const std::string& theme, const xtd::drawing::size& size) {return next(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Next image object with specified theme images and size.
      /// @param theme A xtd::forms::theme_images that represent a theme images
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image next(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "go-next", size);}

      /// @brief No image object.
      static xtd::drawing::image no() {return no(xtd::forms::theme_images::current_theme(), size());}
      /// @brief No image object with specified theme.
      /// @param theme A string that represent a theme
      static xtd::drawing::image no(const std::string& theme) {return no(theme, size());}
      /// @brief No image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image no(const xtd::drawing::size& size) {return no(xtd::forms::theme_images::current_theme(), size);}
      /// @brief No image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image no(const std::string& theme, const xtd::drawing::size& size) {return no(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief No image object with specified theme images and size.
      /// @param theme A xtd::forms::theme_images that represent a theme images
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image no(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-cancel", size);}

      /// @brief Previous image object.
      static xtd::drawing::image previous() {return previous(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Previous image object with specified theme.
      /// @param theme A string that represent a theme
      static xtd::drawing::image previous(const std::string& theme) {return previous(theme, size());}
      /// @brief Previous image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image previous(const xtd::drawing::size& size) {return previous(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Previous image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image previous(const std::string& theme, const xtd::drawing::size& size) {return previous(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Previous image object with specified theme images and size.
      /// @param theme A xtd::forms::theme_images that represent a theme images
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image previous(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "go-previous", size);}

      /// @brief Remove image object.
      static xtd::drawing::image remove() {return remove(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Remove image object with specified theme.
      /// @param theme A string that represent a theme
      static xtd::drawing::image remove(const std::string& theme) {return remove(theme, size());}
      /// @brief Remove image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image remove(const xtd::drawing::size& size) {return remove(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Remove image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image remove(const std::string& theme, const xtd::drawing::size& size) {return remove(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Remove image object with specified theme images and size.
      /// @param theme A xtd::forms::theme_images that represent a theme images
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image remove(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "list-remove", size);}

      /// @brief Yes image object.
      static xtd::drawing::image yes() {return yes(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Yes image object with specified theme.
      /// @param theme A string that represent a theme
      static xtd::drawing::image yes(const std::string& theme) {return yes(theme, size());}
      /// @brief Yes image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image yes(const xtd::drawing::size& size) {return yes(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Yes image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image yes(const std::string& theme, const xtd::drawing::size& size) {return yes(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Yes image object with specified theme images and size.
      /// @param theme A xtd::forms::theme_images that represent a theme images
      /// @param size A xtd::drawing::size size for the image
      static xtd::drawing::image yes(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-ok", size);}

      static xtd::drawing::size size() {return {16, 16};}
      static xtd::drawing::image from_name(const std::string& name) {return from_name(name, size());}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name) {return from_name(theme, name, size());}
      static xtd::drawing::image from_name(const std::string& name, const xtd::drawing::size& size) {return from_name(xtd::forms::theme_images::current_theme(), name, size);}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name, const xtd::drawing::size& size) {return from_name(xtd::forms::theme_images::theme_from_name(theme), name, size);}
      static xtd::drawing::image from_name(const xtd::forms::theme_images& theme, const std::string& name, const xtd::drawing::size& size) {return theme.from_name(name, size);}
    };
  }
}
