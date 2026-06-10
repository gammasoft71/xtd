/// @file
/// @brief Contains xtd::forms::tool_bar_images factory.
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
    /// @brief Provides a tool bar images factories for use by a tool_bar control.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/tool_bar_images>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    class tool_bar_images final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief File new image object.
      /// @return A xtd::drawing::image that represent "document-new".
      [[nodiscard]] static auto file_new() -> xtd::drawing::image;
      /// @brief File new image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-new".
      [[nodiscard]] static auto file_new(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief File new image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-new".
      [[nodiscard]] static auto file_new(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief File new image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-new".
      [[nodiscard]] static auto file_new(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief File open image object.
      /// @return A xtd::drawing::image that represent "document-open".
      [[nodiscard]] static auto file_open() -> xtd::drawing::image;
      /// @brief File open image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-open".
      [[nodiscard]] static auto file_open(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief File open image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-open".
      [[nodiscard]] static auto file_open(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief File open image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-open".
      [[nodiscard]] static auto file_open(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief File save image object.
      /// @return A xtd::drawing::image that represent "document-save".
      [[nodiscard]] static auto file_save() -> xtd::drawing::image;
      /// @brief File save image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-save".
      [[nodiscard]] static auto file_save(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief File save image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save".
      [[nodiscard]] static auto file_save(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief File save image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save".
      [[nodiscard]] static auto file_save(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief File save as image object.
      /// @return A xtd::drawing::image that represent "document-save-as".
      [[nodiscard]] static auto file_save_as() -> xtd::drawing::image;
      /// @brief File save as image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-save-as".
      [[nodiscard]] static auto file_save_as(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief File save as image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save-as".
      [[nodiscard]] static auto file_save_as(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief File save as image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save-as".
      [[nodiscard]] static auto file_save_as(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief File print image object.
      /// @return A xtd::drawing::image that represent "document-print".
      [[nodiscard]] static auto file_print() -> xtd::drawing::image;
      /// @brief File print image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-print".
      [[nodiscard]] static auto file_print(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief File print image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print".
      [[nodiscard]] static auto file_print(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief File print image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print".
      [[nodiscard]] static auto file_print(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief File print preview image object.
      /// @return A xtd::drawing::image that represent "document-print-preview".
      [[nodiscard]] static auto file_print_preview() -> xtd::drawing::image;
      /// @brief File print preview image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-print-preview".
      [[nodiscard]] static auto file_print_preview(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief File print preview image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print-preview".
      [[nodiscard]] static auto file_print_preview(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief File print preview image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print-preview".
      [[nodiscard]] static auto file_print_preview(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief File page setup image object.
      /// @return A xtd::drawing::image that represent "document-page-setup".
      [[nodiscard]] static auto file_page_setup() -> xtd::drawing::image;
      /// @brief File page setup image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-page-setup".
      [[nodiscard]] static auto file_page_setup(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief File page setup image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-page-setup".
      [[nodiscard]] static auto file_page_setup(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief File page setup image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-page-setup".
      [[nodiscard]] static auto file_page_setup(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief File exit image object.
      /// @return A xtd::drawing::image that represent  "application-exit".
      [[nodiscard]] static auto file_exit() -> xtd::drawing::image;
      /// @brief File exit image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "application-exit".
      [[nodiscard]] static auto file_exit(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief File exit image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "application-exit".
      [[nodiscard]] static auto file_exit(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief File exit image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "application-exit".
      [[nodiscard]] static auto file_exit(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Edit undo image object.
      /// @return A xtd::drawing::image that represent "edit-undo".
      [[nodiscard]] static auto edit_undo() -> xtd::drawing::image;
      /// @brief Edit undo image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-undo".
      [[nodiscard]] static auto edit_undo(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Edit undoEdit undo image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-undo".
      [[nodiscard]] static auto edit_undo(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-undo".
      [[nodiscard]] static auto edit_undo(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Edit undo image object.
      /// @return A xtd::drawing::image that represent  "edit-redo".
      [[nodiscard]] static auto edit_redo() -> xtd::drawing::image;
      /// @brief Edit undo image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-redo".
      [[nodiscard]] static auto edit_redo(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Edit undo image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-redo".
      [[nodiscard]] static auto edit_redo(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "edit-redo" "edit-redo".
      [[nodiscard]] static auto edit_redo(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Edit cut image object.
      /// @return A xtd::drawing::image that represent "edit-cut".
      [[nodiscard]] static auto edit_cut() -> xtd::drawing::image;
      /// @brief Edit cut image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-cut".
      [[nodiscard]] static auto edit_cut(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Edit cut image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-cut".
      [[nodiscard]] static auto edit_cut(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Edit cut image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-cut".
      [[nodiscard]] static auto edit_cut(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Edit copy image object.
      /// @return A xtd::drawing::image that represent "edit-copy".
      [[nodiscard]] static auto edit_copy() -> xtd::drawing::image;
      /// @brief Edit copy image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-copy".
      [[nodiscard]] static auto edit_copy(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Edit copy image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-copy".
      [[nodiscard]] static auto edit_copy(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Edit copy image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-copy".
      [[nodiscard]] static auto edit_copy(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Edit paste image object.
      /// @return A xtd::drawing::image that represent "edit-paste".
      [[nodiscard]] static auto edit_paste() -> xtd::drawing::image;
      /// @brief Edit paste image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent  "edit-paste".
      [[nodiscard]] static auto edit_paste(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Edit paste image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "edit-paste".
      [[nodiscard]] static auto edit_paste(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Edit paste image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-paste".
      [[nodiscard]] static auto edit_paste(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief View back image object.
      /// @return A xtd::drawing::image that represent "go-previous".
      [[nodiscard]] static auto view_back() -> xtd::drawing::image;
      /// @brief View back image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "go-previous".
      [[nodiscard]] static auto view_back(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief View back image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      [[nodiscard]] static auto view_back(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief View back image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      [[nodiscard]] static auto view_back(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief View forward image object.
      /// @return A xtd::drawing::image that represent  "go-next".
      [[nodiscard]] static auto view_forward() -> xtd::drawing::image;
      /// @brief View forward image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent  "go-next".
      [[nodiscard]] static auto view_forward(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief View forward image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "go-next".
      [[nodiscard]] static auto view_forward(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief View forward image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "go-next".
      [[nodiscard]] static auto view_forward(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Help about image object.
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help() -> xtd::drawing::image;
      /// @brief Help about image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Help about image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Help about image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Help about image object.
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help_about() -> xtd::drawing::image;
      /// @brief Help about image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help_about(const xtd::string& theme) -> xtd::drawing::image;
      /// @brief Help about image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help_about(const xtd::drawing::size& size) -> xtd::drawing::image;
      /// @brief Help about image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      [[nodiscard]] static auto help_about(const xtd::string& theme, const xtd::drawing::size& size) -> xtd::drawing::image;
      
      /// @brief Gets the height and width of the menu images.
      /// @return The size that represents the height and width of the menu images in pixels (16 x 16).
      [[nodiscard]] static auto size() -> xtd::drawing::size;
      
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
      /// @}
    };
  }
}
