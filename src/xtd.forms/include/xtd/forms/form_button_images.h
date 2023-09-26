/// @file
/// @brief Contains xtd::forms::form_button_images factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "images"
#include <xtd/drawing/system_images>
#include <xtd/environment>
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a form button images factories for use by a form control.
    /// @par Header
    /// @code #include <xtd/forms/form_button_images> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    class form_button_images final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Close image object.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close();
      /// @brief Close image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(bool maximized_form);
      /// @brief Close image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(const xtd::ustring& theme);
      /// @brief Close image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(const xtd::ustring& theme, bool maximized_form);
      /// @brief Close image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(const xtd::drawing::size& size);
      /// @brief Close image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Close hovered image object.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered();
      /// @brief Close hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close_hovered(bool maximized_form);
      /// @brief Close hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered(const xtd::ustring& theme);
      /// @brief Close hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered(const xtd::ustring& theme, bool maximized_form);
      /// @brief Close hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered(const xtd::drawing::size& size);
      /// @brief Close hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Fullscreen image object.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen();
      /// @brief Fullscreen image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen(bool maximized_form);
      /// @brief Fullscreen image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen(const xtd::ustring& theme);
      /// @brief Fullscreen image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen(const xtd::ustring& theme, bool maximized_form);
      /// @brief Fullscreen image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen(const xtd::drawing::size& size);
      /// @brief Fullscreen image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image fullscreen(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Close image object.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered();
      /// @brief Fullscreen hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent  "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(bool maximized_form);
      /// @brief Fullscreen hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(const xtd::ustring& theme);
      /// @brief Fullscreen hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(const xtd::ustring& theme, bool maximized_form);
      /// @brief Fullscreen hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(const xtd::drawing::size& size);
      /// @brief Fullscreen hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Maximize image object.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize();
      /// @brief Maximize image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(bool maximized_form);
      /// @brief Maximize image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(const xtd::ustring& theme);
      /// @brief Maximize image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(const xtd::ustring& theme, bool maximized_form);
      /// @brief Maximize image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(const xtd::drawing::size& size);
      /// @brief Maximize image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Maximize hovered image object.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered();
      /// @brief Maximize hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(bool maximized_form);
      /// @brief Maximize hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(const xtd::ustring& theme);
      /// @brief Maximize hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(const xtd::ustring& theme, bool maximized_form);
      /// @brief Maximize hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(const xtd::drawing::size& size);
      /// @brief Maximize hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Minimize image object.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize();
      /// @brief Minimize image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(bool maximized_form);
      /// @brief Minimize image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(const xtd::ustring& theme);
      /// @brief Minimize image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(const xtd::ustring& theme, bool maximized_form);
      /// @brief Minimize image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(const xtd::drawing::size& size);
      /// @brief Minimize image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Minimize hovered image object.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image minimize_hovered();
      /// @brief Minimize hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(bool maximized_form);
      /// @brief Minimize hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(const xtd::ustring& theme);
      /// @brief Minimize hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(const xtd::ustring& theme, bool maximized_form);
      /// @brief Minimize hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(const xtd::drawing::size& size);
      /// @brief Minimize hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Restore image object.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore();
      /// @brief Restore image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(bool maximized_form);
      /// @brief Restore image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(const xtd::ustring& theme);
      /// @brief Restore image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(const xtd::ustring& theme, bool maximized_form);
      /// @brief Restore image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(const xtd::drawing::size& size);
      /// @brief Restore image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Restore hovered image object.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered();
      /// @brief Restore hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered(bool maximized_form);
      /// @brief Restore hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered(const xtd::ustring& theme);
      /// @brief Restore hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered(const xtd::ustring& theme, bool maximized_form);
      /// @brief Restore hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered(const xtd::drawing::size& size);
      /// @brief Restore hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered""window-restore-hovered".
      static xtd::drawing::image restore_hovered(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief System menu image object.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu();
      /// @brief System menu image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(bool maximized_form);
      /// @brief System menu image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(const xtd::ustring& theme);
      /// @brief System menu image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(const xtd::ustring& theme, bool maximized_form);
      /// @brief System menu image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(const xtd::drawing::size& size);
      /// @brief System menu image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief System menu hovered image object.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered();
      /// @brief System menu hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(bool maximized_form);
      /// @brief System menu hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(const xtd::ustring& theme);
      /// @brief System menu hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(const xtd::ustring& theme, bool maximized_form);
      /// @brief System menu hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(const xtd::drawing::size& size);
      /// @brief System menu hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Gets the height and width of the button images.
      /// @return The size that represents the height and width of the button images in pixels.
      /// @remarks The following table show size by operating system :
      /// | Windows  | macOS    | linux    |
      /// | -------- | -------- | -------- |
      /// | {90, 58} | {24, 24} | {64, 64} |
      static xtd::drawing::size size();
      /// @brief Gets the height and width of the button images with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return The size that represents the height and width of the button images in pixels.
      /// @remarks The following table show size by operating system :
      /// | maximized form | Windows  | macOS    | linux    |
      /// | -------------- | -------- | -------- | -------- |
      /// | false          | {90, 58} | {24, 24} | {64, 64} |
      /// | true           | {90, 42} | {24, 24} | {64, 64} |
      static xtd::drawing::size size(bool maximized_form);
      
      /// @brief Gets image object with specified name.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::context_names to get names by context.
      static xtd::drawing::image from_name(const xtd::ustring& name);
      /// @brief Gets image object with specified theme and name.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::ustring& theme, const xtd::ustring& name);
      /// @brief Gets image object with specified name and size.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::ustring& name, const xtd::drawing::size& size);
      /// @brief Gets image object with specified theme, name and size.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::ustring& theme, const xtd::ustring& name, const xtd::drawing::size& size);
      /// @brief Gets image object with specified name and maximized form.
      /// @param name the image name to get.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::ustring& name, bool maximized_form);
      /// @brief Gets image object with specified theme,  name and maximized form.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::ustring& theme, const xtd::ustring& name, bool maximized_form);
      /// @}
    };
  }
}
