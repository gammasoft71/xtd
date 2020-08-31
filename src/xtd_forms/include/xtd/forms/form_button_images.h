#pragma once
#include <xtd/environment.h>
#include <xtd/static.h>
#include <xtd/drawing/system_images.h>
#include "theme.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class form_button_images static_ {
    public:
      static xtd::drawing::image close() {return close(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image close(bool maximized) {return close(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image close(const std::string& theme) {return close(theme, size());}
      static xtd::drawing::image close(bool maximized, const std::string& theme) {return close(theme, size(maximized));}
      static xtd::drawing::image close(const xtd::drawing::size& size) {return close(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image close(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-close", size);}
      
      static xtd::drawing::image close_hovered() {return close_hovered(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image close_hovered(bool maximized) {return close_hovered(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image close_hovered(const std::string& theme) {return close_hovered(theme, size());}
      static xtd::drawing::image close_hovered(bool maximized, const std::string& theme) {return close_hovered(theme, size(maximized));}
      static xtd::drawing::image close_hovered(const xtd::drawing::size& size) {return close_hovered(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image close_hovered(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-close-hovered", size);}
      
      static xtd::drawing::image fullscreen() {return fullscreen(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image fullscreen(bool maximized) {return fullscreen(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image fullscreen(const std::string& theme) {return fullscreen(theme, size());}
      static xtd::drawing::image fullscreen(bool maximized, const std::string& theme) {return fullscreen(theme, size(maximized));}
      static xtd::drawing::image fullscreen(const xtd::drawing::size& size) {return fullscreen(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image fullscreen(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-fullscreen", size);}
      
      static xtd::drawing::image fullscreen_hovered() {return fullscreen_hovered(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image fullscreen_hovered(bool maximized) {return fullscreen_hovered(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image fullscreen_hovered(const std::string& theme) {return fullscreen_hovered(theme, size());}
      static xtd::drawing::image fullscreen_hovered(bool maximized, const std::string& theme) {return fullscreen_hovered(theme, size(maximized));}
      static xtd::drawing::image fullscreen_hovered(const xtd::drawing::size& size) {return fullscreen_hovered(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image fullscreen_hovered(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-fullscreen-hovered", size);}
      
      static xtd::drawing::image maximize() {return maximize(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image maximize(bool maximized) {return maximize(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image maximize(const std::string& theme) {return maximize(theme, size());}
      static xtd::drawing::image maximize(bool maximized, const std::string& theme) {return maximize(theme, size(maximized));}
      static xtd::drawing::image maximize(const xtd::drawing::size& size) {return maximize(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image maximize(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-maximize", size);}
      
      static xtd::drawing::image maximize_hovered() {return maximize_hovered(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image maximize_hovered(bool maximized) {return maximize_hovered(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image maximize_hovered(const std::string& theme) {return maximize_hovered(theme, size());}
      static xtd::drawing::image maximize_hovered(bool maximized, const std::string& theme) {return maximize_hovered(theme, size(maximized));}
      static xtd::drawing::image maximize_hovered(const xtd::drawing::size& size) {return maximize_hovered(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image maximize_hovered(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-maximize-hovered", size);}
      
      static xtd::drawing::image minimize() {return minimize(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image minimize(bool maximized) {return minimize(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image minimize(const std::string& theme) {return minimize(theme, size());}
      static xtd::drawing::image minimize(bool maximized, const std::string& theme) {return minimize(theme, size(maximized));}
      static xtd::drawing::image minimize(const xtd::drawing::size& size) {return minimize(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image minimize(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-minimize", size);}
      
      static xtd::drawing::image minimize_hovered() {return minimize_hovered(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image minimize_hovered(bool maximized) {return minimize_hovered(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image minimize_hovered(const std::string& theme) {return minimize_hovered(theme, size());}
      static xtd::drawing::image minimize_hovered(bool maximized, const std::string& theme) {return minimize_hovered(theme, size(maximized));}
      static xtd::drawing::image minimize_hovered(const xtd::drawing::size& size) {return minimize_hovered(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image minimize_hovered(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-minimize-hovered", size);}
      
      static xtd::drawing::image restore() {return restore(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image restore(bool maximized) {return restore(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image restore(const std::string& theme) {return restore(theme, size());}
      static xtd::drawing::image restore(bool maximized, const std::string& theme) {return restore(theme, size(maximized));}
      static xtd::drawing::image restore(const xtd::drawing::size& size) {return restore(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image restore(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-restore", size);}
      
      static xtd::drawing::image restore_hovered() {return restore_hovered(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image restore_hovered(bool maximized) {return restore_hovered(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image restore_hovered(const std::string& theme) {return restore_hovered(theme, size());}
      static xtd::drawing::image restore_hovered(bool maximized, const std::string& theme) {return restore_hovered(theme, size(maximized));}
      static xtd::drawing::image restore_hovered(const xtd::drawing::size& size) {return restore_hovered(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image restore_hovered(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-restore-hovered", size);}
      
      static xtd::drawing::image system_menu() {return system_menu(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image system_menu(bool maximized) {return system_menu(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image system_menu(const std::string& theme) {return system_menu(theme, size());}
      static xtd::drawing::image system_menu(bool maximized, const std::string& theme) {return system_menu(theme, size(maximized));}
      static xtd::drawing::image system_menu(const xtd::drawing::size& size) {return system_menu(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image system_menu(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-system-menu", size);}
      
      static xtd::drawing::image system_menu_hovered() {return system_menu_hovered(xtd::forms::theme::default_theme_name(), size());}
      static xtd::drawing::image system_menu_hovered(bool maximized) {return system_menu_hovered(xtd::forms::theme::default_theme_name(), size(maximized));}
      static xtd::drawing::image system_menu_hovered(const std::string& theme) {return system_menu_hovered(theme, size());}
      static xtd::drawing::image system_menu_hovered(bool maximized, const std::string& theme) {return system_menu_hovered(theme, size(maximized));}
      static xtd::drawing::image system_menu_hovered(const xtd::drawing::size& size) {return system_menu_hovered(xtd::forms::theme::default_theme_name(), size);}
      static xtd::drawing::image system_menu_hovered(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "window-system-menu-hovered", size);}

      static xtd::drawing::size size() {return size(false);}
      static xtd::drawing::size size(bool maximized) {
        if (environment::os_version().is_windows_platform()) return {90, maximized ? 42 : 58};
        if (environment::os_version().is_macos_platform()) return {24, 24};
        if (environment::os_version().is_linux_platform()) return {64, 64};
        return {32, 32};
      }
      static xtd::drawing::image from_name(const std::string& name) {return from_name(name, size());}
      static xtd::drawing::image from_name(bool maximized, const std::string& name) {return from_name(name, size(maximized));}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name) {return from_name(theme, name, size());}
      static xtd::drawing::image from_name(bool maximized, const std::string& theme, const std::string& name) {return from_name(theme, name, size(maximized));}
      static xtd::drawing::image from_name(const std::string& name, const xtd::drawing::size& size) {return from_name(xtd::forms::theme::default_theme_name(), name, size);}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name, const xtd::drawing::size& size) {return xtd::drawing::system_images::from_name(theme, name, size);}
    };
  }
}
