/// @file
/// @brief Contains xtd::forms::tool_bar_images factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "images.h"
#include <xtd/drawing/system_images>
#include <xtd/environment>
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a tool bar images factories for use by a tool_bar control.
    /// @par Header
    /// @code #include <xtd/forms/tool_bar_images> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms components
    class tool_bar_images final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief File new image object.
      /// @return A xtd::drawing::image that represent "document-new".
      static xtd::drawing::image file_new();
      /// @brief File new image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-new".
      static xtd::drawing::image file_new(const xtd::ustring& theme);
      /// @brief File new image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-new".
      static xtd::drawing::image file_new(const xtd::drawing::size& size);
      /// @brief File new image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-new".
      static xtd::drawing::image file_new(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief File open image object.
      /// @return A xtd::drawing::image that represent "document-open".
      static xtd::drawing::image file_open();
      /// @brief File open image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-open".
      static xtd::drawing::image file_open(const xtd::ustring& theme);
      /// @brief File open image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-open".
      static xtd::drawing::image file_open(const xtd::drawing::size& size);
      /// @brief File open image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-open".
      static xtd::drawing::image file_open(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief File save image object.
      /// @return A xtd::drawing::image that represent "document-save".
      static xtd::drawing::image file_save();
      /// @brief File save image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-save".
      static xtd::drawing::image file_save(const xtd::ustring& theme);
      /// @brief File save image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save".
      static xtd::drawing::image file_save(const xtd::drawing::size& size);
      /// @brief File save image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save".
      static xtd::drawing::image file_save(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief File save as image object.
      /// @return A xtd::drawing::image that represent "document-save-as".
      static xtd::drawing::image file_save_as();
      /// @brief File save as image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-save-as".
      static xtd::drawing::image file_save_as(const xtd::ustring& theme);
      /// @brief File save as image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save-as".
      static xtd::drawing::image file_save_as(const xtd::drawing::size& size);
      /// @brief File save as image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save-as".
      static xtd::drawing::image file_save_as(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief File print image object.
      /// @return A xtd::drawing::image that represent "document-print".
      static xtd::drawing::image file_print();
      /// @brief File print image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-print".
      static xtd::drawing::image file_print(const xtd::ustring& theme);
      /// @brief File print image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print".
      static xtd::drawing::image file_print(const xtd::drawing::size& size);
      /// @brief File print image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print".
      static xtd::drawing::image file_print(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief File print preview image object.
      /// @return A xtd::drawing::image that represent "document-print-preview".
      static xtd::drawing::image file_print_preview();
      /// @brief File print preview image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-print-preview".
      static xtd::drawing::image file_print_preview(const xtd::ustring& theme);
      /// @brief File print preview image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print-preview".
      static xtd::drawing::image file_print_preview(const xtd::drawing::size& size);
      /// @brief File print preview image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print-preview".
      static xtd::drawing::image file_print_preview(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief File page setup image object.
      /// @return A xtd::drawing::image that represent "document-page-setup".
      static xtd::drawing::image file_page_setup();
      /// @brief File page setup image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-page-setup".
      static xtd::drawing::image file_page_setup(const xtd::ustring& theme);
      /// @brief File page setup image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-page-setup".
      static xtd::drawing::image file_page_setup(const xtd::drawing::size& size);
      /// @brief File page setup image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-page-setup".
      static xtd::drawing::image file_page_setup(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief File exit image object.
      /// @return A xtd::drawing::image that represent  "application-exit".
      static xtd::drawing::image file_exit();
      /// @brief File exit image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "application-exit".
      static xtd::drawing::image file_exit(const xtd::ustring& theme);
      /// @brief File exit image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "application-exit".
      static xtd::drawing::image file_exit(const xtd::drawing::size& size);
      /// @brief File exit image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "application-exit".
      static xtd::drawing::image file_exit(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Edit undo image object.
      /// @return A xtd::drawing::image that represent "edit-undo".
      static xtd::drawing::image edit_undo();
      /// @brief Edit undo image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-undo".
      static xtd::drawing::image edit_undo(const xtd::ustring& theme);
      /// @brief Edit undoEdit undo image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-undo".
      static xtd::drawing::image edit_undo(const xtd::drawing::size& size);
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-undo".
      static xtd::drawing::image edit_undo(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Edit undo image object.
      /// @return A xtd::drawing::image that represent  "edit-redo".
      static xtd::drawing::image edit_redo();
      /// @brief Edit undo image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-redo".
      static xtd::drawing::image edit_redo(const xtd::ustring& theme);
      /// @brief Edit undo image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-redo".
      static xtd::drawing::image edit_redo(const xtd::drawing::size& size);
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "edit-redo" "edit-redo".
      static xtd::drawing::image edit_redo(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Edit cut image object.
      /// @return A xtd::drawing::image that represent "edit-cut".
      static xtd::drawing::image edit_cut();
      /// @brief Edit cut image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-cut".
      static xtd::drawing::image edit_cut(const xtd::ustring& theme);
      /// @brief Edit cut image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-cut".
      static xtd::drawing::image edit_cut(const xtd::drawing::size& size);
      /// @brief Edit cut image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-cut".
      static xtd::drawing::image edit_cut(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Edit copy image object.
      /// @return A xtd::drawing::image that represent "edit-copy".
      static xtd::drawing::image edit_copy();
      /// @brief Edit copy image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-copy".
      static xtd::drawing::image edit_copy(const xtd::ustring& theme);
      /// @brief Edit copy image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-copy".
      static xtd::drawing::image edit_copy(const xtd::drawing::size& size);
      /// @brief Edit copy image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-copy".
      static xtd::drawing::image edit_copy(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Edit paste image object.
      /// @return A xtd::drawing::image that represent "edit-paste".
      static xtd::drawing::image edit_paste();
      /// @brief Edit paste image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent  "edit-paste".
      static xtd::drawing::image edit_paste(const xtd::ustring& theme);
      /// @brief Edit paste image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "edit-paste".
      static xtd::drawing::image edit_paste(const xtd::drawing::size& size);
      /// @brief Edit paste image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-paste".
      static xtd::drawing::image edit_paste(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief View back image object.
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image view_back();
      /// @brief View back image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image view_back(const xtd::ustring& theme);
      /// @brief View back image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image view_back(const xtd::drawing::size& size);
      /// @brief View back image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image view_back(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief View forward image object.
      /// @return A xtd::drawing::image that represent  "go-next".
      static xtd::drawing::image view_forward();
      /// @brief View forward image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent  "go-next".
      static xtd::drawing::image view_forward(const xtd::ustring& theme);
      /// @brief View forward image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "go-next".
      static xtd::drawing::image view_forward(const xtd::drawing::size& size);
      /// @brief View forward image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "go-next".
      static xtd::drawing::image view_forward(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Help about image object.
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help();
      /// @brief Help about image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help(const xtd::ustring& theme);
      /// @brief Help about image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help(const xtd::drawing::size& size);
      /// @brief Help about image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Help about image object.
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help_about();
      /// @brief Help about image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help_about(const xtd::ustring& theme);
      /// @brief Help about image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help_about(const xtd::drawing::size& size);
      /// @brief Help about image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help_about(const xtd::ustring& theme, const xtd::drawing::size& size);
      
      /// @brief Gets the height and width of the menu images.
      /// @return The size that represents the height and width of the menu images in pixels (16 x 16).
      static xtd::drawing::size size();
      
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
      /// @}
    };
  }
}
