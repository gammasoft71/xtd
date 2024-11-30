/// @file
/// @brief Contains xtd::forms::button_images factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "images.hpp"
#include <xtd/static>
#include <xtd/drawing/system_images>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a button images factories for use by a button control.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/button_images>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    class button_images final static_ {
    public:
      /// @name Static porperties
      
      /// @{
      /// @brief Add image object.
      /// @return A xtd::drawing::image that represent "list-add".
      static xtd::drawing::image add() {return add(xtd::forms::application::style_sheet().theme().name(), size());}
      /// @brief Add image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "list-add".
      static xtd::drawing::image add(const xtd::string& theme) {return add(theme, size());}
      /// @brief Add image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "list-add".
      static xtd::drawing::image add(const xtd::drawing::size& size) {return add(xtd::forms::application::style_sheet().theme().name(), size);}
      /// @brief Add image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "list-add".
      static xtd::drawing::image add(const xtd::string& theme, const xtd::drawing::size& size) {return from_name(theme, "list-add", size);}
      
      /// @brief Apply image object.
      /// @return A xtd::drawing::image that represent "dialog-ok-apply".
      static xtd::drawing::image apply() {return apply(xtd::forms::application::style_sheet().theme().name(), size());}
      /// @brief Apply image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "dialog-ok-apply".
      static xtd::drawing::image apply(const xtd::string& theme) {return apply(theme, size());}
      /// @brief Apply image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-ok-apply".
      static xtd::drawing::image apply(const xtd::drawing::size& size) {return apply(xtd::forms::application::style_sheet().theme().name(), size);}
      /// @brief Apply image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-ok-apply".
      static xtd::drawing::image apply(const xtd::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-ok-apply", size);}
      
      /// @brief Ok image object.
      /// @return A xtd::drawing::image that represent "dialog-ok".
      static xtd::drawing::image ok() {return ok(xtd::forms::application::style_sheet().theme().name(), size());}
      /// @brief Ok image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "dialog-ok".
      static xtd::drawing::image ok(const xtd::string& theme) {return ok(theme, size());}
      /// @brief Ok image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-ok".
      static xtd::drawing::image ok(const xtd::drawing::size& size) {return ok(xtd::forms::application::style_sheet().theme().name(), size);}
      /// @brief Ok image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-ok".
      static xtd::drawing::image ok(const xtd::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-ok", size);}
      
      /// @brief Cancel image object.
      /// @return A xtd::drawing::image that represent "dialog-cancel".
      static xtd::drawing::image cancel() {return cancel(xtd::forms::application::style_sheet().theme().name(), size());}
      /// @brief Cancel image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "dialog-cancel".
      static xtd::drawing::image cancel(const xtd::string& theme) {return cancel(theme, size());}
      /// @brief Cancel image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-cancel".
      static xtd::drawing::image cancel(const xtd::drawing::size& size) {return cancel(xtd::forms::application::style_sheet().theme().name(), size);}
      /// @brief Cancel image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-cancel".
      static xtd::drawing::image cancel(const xtd::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-cancel", size);}
      
      /// @brief Next image object.
      /// @return A xtd::drawing::image that represent "go-next".
      static xtd::drawing::image next() {return next(xtd::forms::application::style_sheet().theme().name(), size());}
      /// @brief Next image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "go-next".
      static xtd::drawing::image next(const xtd::string& theme) {return next(theme, size());}
      /// @brief Next image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-next".
      static xtd::drawing::image next(const xtd::drawing::size& size) {return next(xtd::forms::application::style_sheet().theme().name(), size);}
      /// @brief Next image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-next".
      static xtd::drawing::image next(const xtd::string& theme, const xtd::drawing::size& size) {return from_name(theme, "go-next", size);}
      
      /// @brief No image object.
      /// @return A xtd::drawing::image that represent "dialog-cancel".
      static xtd::drawing::image no() {return no(xtd::forms::application::style_sheet().theme().name(), size());}
      /// @brief No image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "dialog-cancel".
      static xtd::drawing::image no(const xtd::string& theme) {return no(theme, size());}
      /// @brief No image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-cancel".
      static xtd::drawing::image no(const xtd::drawing::size& size) {return no(xtd::forms::application::style_sheet().theme().name(), size);}
      /// @brief No image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-cancel".
      static xtd::drawing::image no(const xtd::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-cancel", size);}
      
      /// @brief Previous image object.
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image previous() {return previous(xtd::forms::application::style_sheet().theme().name(), size());}
      /// @brief Previous image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image previous(const xtd::string& theme) {return previous(theme, size());}
      /// @brief Previous image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image previous(const xtd::drawing::size& size) {return previous(xtd::forms::application::style_sheet().theme().name(), size);}
      /// @brief Previous image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image previous(const xtd::string& theme, const xtd::drawing::size& size) {return from_name(theme, "go-previous", size);}
      
      /// @brief Remove image object.
      /// @return A xtd::drawing::image that represent "list-remove".
      static xtd::drawing::image remove() {return remove(xtd::forms::application::style_sheet().theme().name(), size());}
      /// @brief Remove image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "list-remove".
      static xtd::drawing::image remove(const xtd::string& theme) {return remove(theme, size());}
      /// @brief Remove image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "list-remove".
      static xtd::drawing::image remove(const xtd::drawing::size& size) {return remove(xtd::forms::application::style_sheet().theme().name(), size);}
      /// @brief Remove image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "list-remove".
      static xtd::drawing::image remove(const xtd::string& theme, const xtd::drawing::size& size) {return from_name(theme, "list-remove", size);}
      
      /// @brief Yes image object.
      /// @return A xtd::drawing::image that represent add.
      static xtd::drawing::image yes() {return yes(xtd::forms::application::style_sheet().theme().name(), size());}
      /// @brief Yes image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "dialog-ok".
      static xtd::drawing::image yes(const xtd::string& theme) {return yes(theme, size());}
      /// @brief Yes image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-ok".
      static xtd::drawing::image yes(const xtd::drawing::size& size) {return yes(xtd::forms::application::style_sheet().theme().name(), size);}
      /// @brief Yes image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "dialog-ok".
      static xtd::drawing::image yes(const xtd::string& theme, const xtd::drawing::size& size) {return from_name(theme, "dialog-ok", size);}
      
      /// @brief Gets the height and width of the button images.
      /// @return The size that represents the height and width of the button images in pixels (16 x 16).
      static xtd::drawing::size size() {return {16, 16};}
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets image object with specified name.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::context_names to get names by context.
      static xtd::drawing::image from_name(const xtd::string& name) {return from_name(name, size());}
      /// @brief Gets image object with specified theme and name.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::string& theme, const xtd::string& name) {return from_name(theme, name, size());}
      /// @brief Gets image object with specified name and size.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::string& name, const xtd::drawing::size& size) {return from_name(xtd::forms::application::style_sheet().theme().name(), name, size);}
      /// @brief Gets image object with specified theme, name and size.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::string& theme, const xtd::string& name, const xtd::drawing::size& size) {return images::from_name(theme, name, size);}
      /// @}
    };
  }
}
