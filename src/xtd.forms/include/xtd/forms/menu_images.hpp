/// @file
/// @brief Contains xtd::forms::menu_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "application.hpp"
#include "images.hpp"
#include <xtd/drawing/system_images>
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a menu images factories for use by a menu control.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/menu_images>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    class menu_images final static_ {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief File new image object.
      /// @return A xtd::drawing::image that represent "document-new".
      [[nodiscard]] static auto file_new() -> xtd::drawing::image {return file_new(application::style_sheet().theme().name(), size());}
      /// @brief File new image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-new".
      [[nodiscard]] static auto file_new(const xtd::string& theme) -> xtd::drawing::image {return file_new(theme, size());}
      /// @brief File new image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-new".
      [[nodiscard]] static auto file_new(const xtd::drawing::size& size) -> xtd::drawing::image {return file_new(application::style_sheet().theme().name(), size);}
      /// @brief File new image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-new".
      [[nodiscard]] static auto file_new(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "document-new", size);}
      
      /// @brief File open image object.
      /// @return A xtd::drawing::image that represent "document-open".
      [[nodiscard]] static auto file_open() -> xtd::drawing::image {return file_open(application::style_sheet().theme().name(), size());}
      /// @brief File open image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-open".
      [[nodiscard]] static auto file_open(const xtd::string& theme) -> xtd::drawing::image {return file_open(theme, size());}
      /// @brief File open image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-open".
      [[nodiscard]] static auto file_open(const xtd::drawing::size& size) -> xtd::drawing::image {return file_open(application::style_sheet().theme().name(), size);}
      /// @brief File open image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-open".
      [[nodiscard]] static auto file_open(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "document-open", size);}
      
      /// @brief File save image object.
      /// @return A xtd::drawing::image that represent "document-save".
      [[nodiscard]] static auto file_save() -> xtd::drawing::image {return file_save(application::style_sheet().theme().name(), size());}
      /// @brief File save image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-save".
      [[nodiscard]] static auto file_save(const xtd::string& theme) -> xtd::drawing::image {return file_save(theme, size());}
      /// @brief File save image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save".
      [[nodiscard]] static auto file_save(const xtd::drawing::size& size) -> xtd::drawing::image {return file_save(application::style_sheet().theme().name(), size);}
      /// @brief File save image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save".
      [[nodiscard]] static auto file_save(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "document-save", size);}
      
      /// @brief File print image object.
      /// @return A xtd::drawing::image that represent "document-print".
      [[nodiscard]] static auto file_print() -> xtd::drawing::image {return file_print(application::style_sheet().theme().name(), size());}
      /// @brief File print image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-print".
      [[nodiscard]] static auto file_print(const xtd::string& theme) -> xtd::drawing::image {return file_print(theme, size());}
      /// @brief File print image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print".
      [[nodiscard]] static auto file_print(const xtd::drawing::size& size) -> xtd::drawing::image {return file_print(application::style_sheet().theme().name(), size);}
      /// @brief File print image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print".
      [[nodiscard]] static auto file_print(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "document-print", size);}
      
      /// @brief File print preview image object.
      /// @return A xtd::drawing::image that represent "document-print-preview".
      [[nodiscard]] static auto file_print_preview() -> xtd::drawing::image {return file_print_preview(application::style_sheet().theme().name(), size());}
      /// @brief File print preview image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-print-preview".
      [[nodiscard]] static auto file_print_preview(const xtd::string& theme) -> xtd::drawing::image {return file_print_preview(theme, size());}
      /// @brief File print preview image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print-preview".
      [[nodiscard]] static auto file_print_preview(const xtd::drawing::size& size) -> xtd::drawing::image {return file_print_preview(application::style_sheet().theme().name(), size);}
      /// @brief File print preview image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print-preview".
      [[nodiscard]] static auto file_print_preview(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "document-print-preview", size);}
      
      /// @brief File exit image object.
      /// @return A xtd::drawing::image that represent  "application-exit".
      [[nodiscard]] static auto file_exit() -> xtd::drawing::image {return file_exit(application::style_sheet().theme().name(), size());}
      /// @brief File exit image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "application-exit".
      [[nodiscard]] static auto file_exit(const xtd::string& theme) -> xtd::drawing::image {return file_exit(theme, size());}
      /// @brief File exit image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "application-exit".
      [[nodiscard]] static auto file_exit(const xtd::drawing::size& size) -> xtd::drawing::image {return file_exit(application::style_sheet().theme().name(), size);}
      /// @brief File exit image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "application-exit".
      [[nodiscard]] static auto file_exit(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "application-exit", size);}
      
      /// @brief Edit undo image object.
      /// @return A xtd::drawing::image that represent "edit-undo".
      [[nodiscard]] static auto edit_undo() -> xtd::drawing::image {return edit_undo(application::style_sheet().theme().name(), size());}
      /// @brief Edit undo image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-undo".
      [[nodiscard]] static auto edit_undo(const xtd::string& theme) -> xtd::drawing::image {return edit_undo(theme, size());}
      /// @brief Edit undoEdit undo image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-undo".
      [[nodiscard]] static auto edit_undo(const xtd::drawing::size& size) -> xtd::drawing::image {return edit_undo(application::style_sheet().theme().name(), size);}
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-undo".
      [[nodiscard]] static auto edit_undo(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "edit-undo", size);}
      
      /// @brief Edit undo image object.
      /// @return A xtd::drawing::image that represent  "edit-redo".
      [[nodiscard]] static auto edit_redo() -> xtd::drawing::image {return edit_redo(application::style_sheet().theme().name(), size());}
      /// @brief Edit undo image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-redo".
      [[nodiscard]] static auto edit_redo(const xtd::string& theme) -> xtd::drawing::image {return edit_redo(theme, size());}
      /// @brief Edit undo image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-redo".
      [[nodiscard]] static auto edit_redo(const xtd::drawing::size& size) -> xtd::drawing::image {return edit_redo(application::style_sheet().theme().name(), size);}
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "edit-redo" "edit-redo".
      [[nodiscard]] static auto edit_redo(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "edit-redo", size);}
      
      /// @brief Edit cut image object.
      /// @return A xtd::drawing::image that represent "edit-cut".
      [[nodiscard]] static auto edit_cut() -> xtd::drawing::image {return edit_cut(application::style_sheet().theme().name(), size());}
      /// @brief Edit cut image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-cut".
      [[nodiscard]] static auto edit_cut(const xtd::string& theme) -> xtd::drawing::image {return edit_cut(theme, size());}
      /// @brief Edit cut image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-cut".
      [[nodiscard]] static auto edit_cut(const xtd::drawing::size& size) -> xtd::drawing::image {return edit_cut(application::style_sheet().theme().name(), size);}
      /// @brief Edit cut image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-cut".
      [[nodiscard]] static auto edit_cut(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "edit-cut", size);}
      
      /// @brief Edit copy image object.
      /// @return A xtd::drawing::image that represent "edit-copy".
      [[nodiscard]] static auto edit_copy() -> xtd::drawing::image {return edit_copy(application::style_sheet().theme().name(), size());}
      /// @brief Edit copy image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-copy".
      [[nodiscard]] static auto edit_copy(const xtd::string& theme) -> xtd::drawing::image {return edit_copy(theme, size());}
      /// @brief Edit copy image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-copy".
      [[nodiscard]] static auto edit_copy(const xtd::drawing::size& size) -> xtd::drawing::image {return edit_copy(application::style_sheet().theme().name(), size);}
      /// @brief Edit copy image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-copy".
      [[nodiscard]] static auto edit_copy(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "edit-copy", size);}
      
      /// @brief Edit paste image object.
      /// @return A xtd::drawing::image that represent "edit-paste".
      [[nodiscard]] static auto edit_paste() -> xtd::drawing::image {return edit_paste(application::style_sheet().theme().name(), size());}
      /// @brief Edit paste image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent  "edit-paste".
      [[nodiscard]] static auto edit_paste(const xtd::string& theme) -> xtd::drawing::image {return edit_paste(theme, size());}
      /// @brief Edit paste image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "edit-paste".
      [[nodiscard]] static auto edit_paste(const xtd::drawing::size& size) -> xtd::drawing::image {return edit_paste(application::style_sheet().theme().name(), size);}
      /// @brief Edit paste image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-paste".
      [[nodiscard]] static auto edit_paste(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "edit-paste", size);}
      
      /// @brief View back image object.
      /// @return A xtd::drawing::image that represent "go-previous".
      [[nodiscard]] static auto view_back() -> xtd::drawing::image {return view_back(application::style_sheet().theme().name(), size());}
      /// @brief View back image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "go-previous".
      [[nodiscard]] static auto view_back(const xtd::string& theme) -> xtd::drawing::image {return view_back(theme, size());}
      /// @brief View back image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      [[nodiscard]] static auto view_back(const xtd::drawing::size& size) -> xtd::drawing::image {return view_back(application::style_sheet().theme().name(), size);}
      /// @brief View back image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      [[nodiscard]] static auto view_back(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "go-previous", size);}
      
      /// @brief View forward image object.
      /// @return A xtd::drawing::image that represent  "go-next".
      [[nodiscard]] static auto view_forward() -> xtd::drawing::image {return view_forward(application::style_sheet().theme().name(), size());}
      /// @brief View forward image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent  "go-next".
      [[nodiscard]] static auto view_forward(const xtd::string& theme) -> xtd::drawing::image {return view_forward(theme, size());}
      /// @brief View forward image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "go-next".
      [[nodiscard]] static auto view_forward(const xtd::drawing::size& size) -> xtd::drawing::image {return view_forward(application::style_sheet().theme().name(), size);}
      /// @brief View forward image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "go-next".
      [[nodiscard]] static auto view_forward(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "go-next", size);}
      
      /// @brief Help about image object.
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help_about() -> xtd::drawing::image {return help_about(application::style_sheet().theme().name(), size());}
      /// @brief Help about image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help_about(const xtd::string& theme) -> xtd::drawing::image {return help_about(theme, size());}
      /// @brief Help about image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help_about(const xtd::drawing::size& size) -> xtd::drawing::image {return help_about(application::style_sheet().theme().name(), size);}
      /// @brief Help about image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help_about(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(theme, "help-about", size);}
      
      /// @brief Gets the height and width of the menu images.
      /// @return The size that represents the height and width of the menu images in pixels (16 x 16).
      [[nodiscard]] static auto size() -> xtd::drawing::size {return {16, 16};}
      
      /// @brief Gets image object with specified name.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::context_names to get names by context.
      [[nodiscard]] static auto from_name(const xtd::string& name) -> xtd::drawing::image {return from_name(name, size());}
      /// @brief Gets image object with specified theme and name.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      [[nodiscard]] static auto from_name(const xtd::string& theme, const xtd::string& name) -> xtd::drawing::image {return from_name(theme, name, size());}
      /// @brief Gets image object with specified name and size.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      [[nodiscard]] static auto from_name(const xtd::string& name, const xtd::drawing::size& size) -> xtd::drawing::image {return from_name(application::style_sheet().theme().name(), name, size);}
      /// @brief Gets image object with specified theme, name and size.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      [[nodiscard]] static auto from_name(const xtd::string& theme, const xtd::string& name, const xtd::drawing::size& size) -> xtd::drawing::image {return images::from_name(theme, name, size);}
      /// @}
    };
  }
}
