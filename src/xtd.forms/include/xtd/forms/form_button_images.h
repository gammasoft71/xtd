/// @file
/// @brief Contains xtd::forms::form_button_images factory.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/environment.h>
#include <xtd/static.h>
#include <xtd/drawing/system_images.h>
#include "theme_images.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a form button images factories for use by a form control.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    class form_button_images final static_ {
    public:
      /// @brief Close image object.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close() {return close(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Close image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(bool maximized_form) {return close(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Close image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(const std::string& theme) {return close(theme, size());}
      /// @brief Close image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(const std::string& theme, bool maximized_form) {return close(theme, size(maximized_form));}
      /// @brief Close image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(const xtd::drawing::size& size) {return close(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Close image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(const std::string& theme, const xtd::drawing::size& size) {return close(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Close image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-close", size);}

      /// @brief Close hovered image object.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered() {return close_hovered(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Close hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image close_hovered(bool maximized_form) {return close_hovered(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Close hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered(const std::string& theme) {return close_hovered(theme, size());}
      /// @brief Close hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered(const std::string& theme, bool maximized_form) {return close_hovered(theme, size(maximized_form));}
      /// @brief Close hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered(const xtd::drawing::size& size) {return close_hovered(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Close hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered(const std::string& theme, const xtd::drawing::size& size) {return close_hovered(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Close hovered image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close-hovered".
      static xtd::drawing::image close_hovered(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-close-hovered", size);}

      /// @brief Fullscreen image object.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen() {return fullscreen(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Fullscreen image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen(bool maximized_form) {return fullscreen(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Fullscreen image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen(const std::string& theme) {return fullscreen(theme, size());}
      /// @brief Fullscreen image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen(const std::string& theme, bool maximized_form) {return fullscreen(theme, size(maximized_form));}
      /// @brief Fullscreen image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen(const xtd::drawing::size& size) {return fullscreen(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Fullscreen image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image fullscreen(const std::string& theme, const xtd::drawing::size& size) {return fullscreen(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Fullscreen image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen".
      static xtd::drawing::image fullscreen(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-fullscreen", size);}

      /// @brief Close image object.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered() {return fullscreen_hovered(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Fullscreen hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent  "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(bool maximized_form) {return fullscreen_hovered(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Fullscreen hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(const std::string& theme) {return fullscreen_hovered(theme, size());}
      /// @brief Fullscreen hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(const std::string& theme, bool maximized_form) {return fullscreen_hovered(theme, size(maximized_form));}
      /// @brief Fullscreen hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(const xtd::drawing::size& size) {return fullscreen_hovered(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Fullscreen hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(const std::string& theme, const xtd::drawing::size& size) {return fullscreen_hovered(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Fullscreen hovered image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-fullscreen-hovered".
      static xtd::drawing::image fullscreen_hovered(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-fullscreen-hovered", size);}

      /// @brief Maximize image object.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize() {return maximize(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Maximize image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(bool maximized_form) {return maximize(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Maximize image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(const std::string& theme) {return maximize(theme, size());}
      /// @brief Maximize image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(const std::string& theme, bool maximized_form) {return maximize(theme, size(maximized_form));}
      /// @brief Maximize image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(const xtd::drawing::size& size) {return maximize(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Maximize image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(const std::string& theme, const xtd::drawing::size& size) {return maximize(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Maximize image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize".
      static xtd::drawing::image maximize(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-maximize", size);}

      /// @brief Maximize hovered image object.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered() {return maximize_hovered(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Maximize hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(bool maximized_form) {return maximize_hovered(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Maximize hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(const std::string& theme) {return maximize_hovered(theme, size());}
      /// @brief Maximize hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(const std::string& theme, bool maximized_form) {return maximize_hovered(theme, size(maximized_form));}
      /// @brief Maximize hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(const xtd::drawing::size& size) {return maximize_hovered(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Maximize hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(const std::string& theme, const xtd::drawing::size& size) {return maximize_hovered(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Maximize hovered image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-maximize-hovered".
      static xtd::drawing::image maximize_hovered(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-maximize-hovered", size);}

      /// @brief Minimize image object.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize() {return minimize(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Minimize image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(bool maximized_form) {return minimize(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Minimize image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(const std::string& theme) {return minimize(theme, size());}
      /// @brief Minimize image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(const std::string& theme, bool maximized_form) {return minimize(theme, size(maximized_form));}
      /// @brief Minimize image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(const xtd::drawing::size& size) {return minimize(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Minimize image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(const std::string& theme, const xtd::drawing::size& size) {return minimize(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Minimize image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize".
      static xtd::drawing::image minimize(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-minimize", size);}

      /// @brief Minimize hovered image object.
      /// @return A xtd::drawing::image that represent "window-close".
      static xtd::drawing::image minimize_hovered() {return minimize_hovered(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Minimize hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(bool maximized_form) {return minimize_hovered(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Minimize hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(const std::string& theme) {return minimize_hovered(theme, size());}
      /// @brief Minimize hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(const std::string& theme, bool maximized_form) {return minimize_hovered(theme, size(maximized_form));}
      /// @brief Minimize hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(const xtd::drawing::size& size) {return minimize_hovered(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Minimize hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(const std::string& theme, const xtd::drawing::size& size) {return minimize_hovered(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Minimize hovered image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-minimize-hovered".
      static xtd::drawing::image minimize_hovered(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-minimize-hovered", size);}

      /// @brief Restore image object.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore() {return restore(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Restore image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(bool maximized_form) {return restore(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Restore image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(const std::string& theme) {return restore(theme, size());}
      /// @brief Restore image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(const std::string& theme, bool maximized_form) {return restore(theme, size(maximized_form));}
      /// @brief Restore image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(const xtd::drawing::size& size) {return restore(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Restore image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(const std::string& theme, const xtd::drawing::size& size) {return restore(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Restore image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore".
      static xtd::drawing::image restore(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-restore", size);}

      /// @brief Restore hovered image object.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered() {return restore_hovered(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Restore hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered(bool maximized_form) {return restore_hovered(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief Restore hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered(const std::string& theme) {return restore_hovered(theme, size());}
      /// @brief Restore hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered(const std::string& theme, bool maximized_form) {return restore_hovered(theme, size(maximized_form));}
      /// @brief Restore hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered(const xtd::drawing::size& size) {return restore_hovered(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Restore hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered""window-restore-hovered".
      static xtd::drawing::image restore_hovered(const std::string& theme, const xtd::drawing::size& size) {return restore_hovered(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Restore hovered image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-restore-hovered".
      static xtd::drawing::image restore_hovered(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-restore-hovered", size);}

      /// @brief System menu image object.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu() {return system_menu(xtd::forms::theme_images::current_theme(), size());}
      /// @brief System menu image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(bool maximized_form) {return system_menu(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief System menu image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(const std::string& theme) {return system_menu(theme, size());}
      /// @brief System menu image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(const std::string& theme, bool maximized_form) {return system_menu(theme, size(maximized_form));}
      /// @brief System menu image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(const xtd::drawing::size& size) {return system_menu(xtd::forms::theme_images::current_theme(), size);}
      /// @brief System menu image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(const std::string& theme, const xtd::drawing::size& size) {return system_menu(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief System menu image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu".
      static xtd::drawing::image system_menu(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-system-menu", size);}

      /// @brief System menu hovered image object.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered() {return system_menu_hovered(xtd::forms::theme_images::current_theme(), size());}
      /// @brief System menu hovered image object with specified maximized form.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(bool maximized_form) {return system_menu_hovered(xtd::forms::theme_images::current_theme(), size(maximized_form));}
      /// @brief System menu hovered image object with specified theme.
      /// @param theme a string that represent theme of image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(const std::string& theme) {return system_menu_hovered(theme, size());}
      /// @brief System menu hovered image object with specified theme and maximized form.
      /// @param theme a string that represent theme of image.
      /// @param maximized_form true if form is maximized; otherwise false.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(const std::string& theme, bool maximized_form) {return system_menu_hovered(theme, size(maximized_form));}
      /// @brief System menu hovered image object with specified size.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(const xtd::drawing::size& size) {return system_menu_hovered(xtd::forms::theme_images::current_theme(), size);}
      /// @brief System menu hovered image object with specified theme and size.
      /// @param theme a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(const std::string& theme, const xtd::drawing::size& size) {return system_menu_hovered(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief System menu hovered image object with specified theme and size.
      /// @param xtd::forms::theme_images a string that represent theme of image.
      /// @param size a xtd::drawing::size represent the sie of the image.
      /// @return A xtd::drawing::image that represent "window-system-menu-hovered".
      static xtd::drawing::image system_menu_hovered(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "window-system-menu-hovered", size);}

      static xtd::drawing::size size() {return size(false);}
      static xtd::drawing::size size(bool maximized_form) {
        if (environment::os_version().is_windows_platform()) return {90, maximized_form ? 42 : 58};
        if (environment::os_version().is_macos_platform()) return {24, 24};
        if (environment::os_version().is_linux_platform()) return {64, 64};
        return {32, 32};
      }
      static xtd::drawing::image from_name(const std::string& name) {return from_name(name, size());}
      static xtd::drawing::image from_name(bool maximized_form, const std::string& name) {return from_name(name, size(maximized_form));}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name) {return from_name(theme, name, size());}
      static xtd::drawing::image from_name(const std::string& theme, bool maximized_form, const std::string& name) {return from_name(theme, name, size(maximized_form));}
      static xtd::drawing::image from_name(const std::string& name, const xtd::drawing::size& size) {return from_name(xtd::forms::theme_images::current_theme(), name, size);}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name, const xtd::drawing::size& size) {return from_name(xtd::forms::theme_images::theme_from_name(theme), name, size);}
      static xtd::drawing::image from_name(const xtd::forms::theme_images& theme, const std::string& name, const xtd::drawing::size& size) {return theme.from_name(name, size);}
    };
  }
}
