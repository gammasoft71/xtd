/// @file
/// @brief Contains xtd::forms::form_button_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "images.hpp"
#include <xtd/drawing/system_images>
#include <xtd/environment>
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a form button images factories for use by a form control.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/form_button_images>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    class form_button_images final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Close image object.
      /// @return A xtd::drawing::image that represent "window-close".
      [[nodiscard]] static auto close() -> xtd::drawing::image;
      /// @brief Close image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-close".
      [[nodiscard]] static auto close(bool maximized_form) -> xtd::drawing::image;
      /// @brief Close image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-close".
      [[nodiscard]] static auto close(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Close image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-close".
      [[nodiscard]] static auto close(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Close image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      [[nodiscard]] static auto close(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Close image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      [[nodiscard]] static auto close(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Close hovered image object.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      [[nodiscard]] static auto close_hovered() -> xtd::drawing::image;
      /// @brief Close hovered image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-close".
      [[nodiscard]] static auto close_hovered(bool maximized_form) -> xtd::drawing::image;
      /// @brief Close hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      [[nodiscard]] static auto close_hovered(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Close hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      [[nodiscard]] static auto close_hovered(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Close hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      [[nodiscard]] static auto close_hovered(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Close hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      [[nodiscard]] static auto close_hovered(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Fullscreen image object.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      [[nodiscard]] static auto fullscreen() -> xtd::drawing::image;
      /// @brief Fullscreen image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      [[nodiscard]] static auto fullscreen(bool maximized_form) -> xtd::drawing::image;
      /// @brief Fullscreen image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      [[nodiscard]] static auto fullscreen(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Fullscreen image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      [[nodiscard]] static auto fullscreen(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Fullscreen image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      [[nodiscard]] static auto fullscreen(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Fullscreen image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      [[nodiscard]] static auto fullscreen(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Close image object.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      [[nodiscard]] static auto fullscreen_hovered() -> xtd::drawing::image;
      /// @brief Fullscreen hovered image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent  "window-fullscreen-hovered".
      [[nodiscard]] static auto fullscreen_hovered(bool maximized_form) -> xtd::drawing::image;
      /// @brief Fullscreen hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      [[nodiscard]] static auto fullscreen_hovered(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Fullscreen hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      [[nodiscard]] static auto fullscreen_hovered(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Fullscreen hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      [[nodiscard]] static auto fullscreen_hovered(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Fullscreen hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      [[nodiscard]] static auto fullscreen_hovered(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Maximize image object.
      /// @return A xtd::drawing::image that represent "window-maximize".
      [[nodiscard]] static auto maximize() -> xtd::drawing::image;
      /// @brief Maximize image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-maximize".
      [[nodiscard]] static auto maximize(bool maximized_form) -> xtd::drawing::image;
      /// @brief Maximize image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      [[nodiscard]] static auto maximize(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Maximize image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-maximize".
      [[nodiscard]] static auto maximize(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Maximize image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      [[nodiscard]] static auto maximize(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Maximize image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      [[nodiscard]] static auto maximize(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Maximize hovered image object.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      [[nodiscard]] static auto maximize_hovered() -> xtd::drawing::image;
      /// @brief Maximize hovered image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      [[nodiscard]] static auto maximize_hovered(bool maximized_form) -> xtd::drawing::image;
      /// @brief Maximize hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      [[nodiscard]] static auto maximize_hovered(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Maximize hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      [[nodiscard]] static auto maximize_hovered(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Maximize hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      [[nodiscard]] static auto maximize_hovered(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Maximize hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      [[nodiscard]] static auto maximize_hovered(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Minimize image object.
      /// @return A xtd::drawing::image that represent "window-minimize".
      [[nodiscard]] static auto minimize() -> xtd::drawing::image;
      /// @brief Minimize image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-minimize".
      [[nodiscard]] static auto minimize(bool maximized_form) -> xtd::drawing::image;
      /// @brief Minimize image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      [[nodiscard]] static auto minimize(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Minimize image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-minimize".
      [[nodiscard]] static auto minimize(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Minimize image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      [[nodiscard]] static auto minimize(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Minimize image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      [[nodiscard]] static auto minimize(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Minimize hovered image object.
      /// @return A xtd::drawing::image that represent "window-close".
      [[nodiscard]] static auto minimize_hovered() -> xtd::drawing::image;
      /// @brief Minimize hovered image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      [[nodiscard]] static auto minimize_hovered(bool maximized_form) -> xtd::drawing::image;
      /// @brief Minimize hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      [[nodiscard]] static auto minimize_hovered(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Minimize hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      [[nodiscard]] static auto minimize_hovered(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Minimize hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      [[nodiscard]] static auto minimize_hovered(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Minimize hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      [[nodiscard]] static auto minimize_hovered(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Restore image object.
      /// @return A xtd::drawing::image that represent "window-restore".
      [[nodiscard]] static auto restore() -> xtd::drawing::image;
      /// @brief Restore image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-restore".
      [[nodiscard]] static auto restore(bool maximized_form) -> xtd::drawing::image;
      /// @brief Restore image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-restore".
      [[nodiscard]] static auto restore(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Restore image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-restore".
      [[nodiscard]] static auto restore(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Restore image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore".
      [[nodiscard]] static auto restore(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Restore image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore".
      [[nodiscard]] static auto restore(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Restore hovered image object.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      [[nodiscard]] static auto restore_hovered() -> xtd::drawing::image;
      /// @brief Restore hovered image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      [[nodiscard]] static auto restore_hovered(bool maximized_form) -> xtd::drawing::image;
      /// @brief Restore hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      [[nodiscard]] static auto restore_hovered(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Restore hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      [[nodiscard]] static auto restore_hovered(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief Restore hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      [[nodiscard]] static auto restore_hovered(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Restore hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered""window-restore-hovered".
      [[nodiscard]] static auto restore_hovered(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief System menu image object.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      [[nodiscard]] static auto system_menu() -> xtd::drawing::image;
      /// @brief System menu image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      [[nodiscard]] static auto system_menu(bool maximized_form) -> xtd::drawing::image;
      /// @brief System menu image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      [[nodiscard]] static auto system_menu(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief System menu image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      [[nodiscard]] static auto system_menu(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief System menu image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      [[nodiscard]] static auto system_menu(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief System menu image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      [[nodiscard]] static auto system_menu(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief System menu hovered image object.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      [[nodiscard]] static auto system_menu_hovered() -> xtd::drawing::image;
      /// @brief System menu hovered image object with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      [[nodiscard]] static auto system_menu_hovered(bool maximized_form) -> xtd::drawing::image;
      /// @brief System menu hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      [[nodiscard]] static auto system_menu_hovered(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief System menu hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      [[nodiscard]] static auto system_menu_hovered(const xtd::string& theme, bool maximized_form) -> xtd::drawing::image;
      /// @brief System menu hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      [[nodiscard]] static auto system_menu_hovered(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief System menu hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      [[nodiscard]] static auto system_menu_hovered(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Gets the height and width of the button images.
      /// @return The size that represents the height and width of the button images in pixels.
      /// @remarks The following table show size by operating system :
      /// | Windows  | macOS    | linux    |
      /// | -------- | -------- | -------- |
      /// | {90, 58} | {24, 24} | {64, 64} |
      [[nodiscard]] static auto size() -> xtd::drawing::size;
      /// @brief Gets the height and width of the button images with specified maximized form.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return The size that represents the height and width of the button images in pixels.
      /// @remarks The following table show size by operating system :
      /// | maximized form | Windows  | macOS    | linux    |
      /// | -------------- | -------- | -------- | -------- |
      /// | `false`        | {90, 58} | {24, 24} | {64, 64} |
      /// | `true`         | {90, 42} | {24, 24} | {64, 64} |
      [[nodiscard]] static auto size(bool maximized_form) -> xtd::drawing::size;
      
      /// @brief Gets image object with specified name.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::context_names to get names by context.
      [[nodiscard]] static auto from_name(const xtd::string& name) -> xtd::drawing::image;
      /// @brief Gets image object with specified theme and name.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      [[nodiscard]] static auto from_name(const xtd::string& theme, const xtd::string& name) -> xtd::drawing::image;
      /// @brief Gets image object with specified name and size.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      [[nodiscard]] static auto from_name(const xtd::string& name, const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Gets image object with specified theme, name and size.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      [[nodiscard]] static auto from_name(const xtd::string& theme, const xtd::string& name, const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Gets image object with specified name and maximized form.
      /// @param name the image name to get.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      [[nodiscard]] static auto from_name(const xtd::string& name, bool maximized_form) -> xtd::drawing::image;
      /// @brief Gets image object with specified theme,  name and maximized form.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @param maximized_form `true` if form is maximized; otherwise `false`.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      [[nodiscard]] static auto from_name(const xtd::string& theme, const xtd::string& name, bool maximized_form) -> xtd::drawing::image;
      /// @}
    };
  }
}
