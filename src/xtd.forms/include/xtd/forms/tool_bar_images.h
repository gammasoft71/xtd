/// @file
/// @brief Contains xtd::forms::tool_bar_images factory.
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
    /// @brief Provides a tool bar images factories for use by a tool_bar control.
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms
    class tool_bar_images final static_ {
    public:
      /// @brief File new image object.
      /// @return A xtd::drawing::image that represent "document-new".
      static xtd::drawing::image file_new() {return file_new(xtd::forms::theme_images::current_theme(), size());}
      /// @brief File new image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-new".
      static xtd::drawing::image file_new(const xtd::ustring& theme) {return file_new(theme, size());}
      /// @brief File new image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-new".
      static xtd::drawing::image file_new(const xtd::drawing::size& size) {return file_new(xtd::forms::theme_images::current_theme(), size);}
      /// @brief File new image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-new".
      static xtd::drawing::image file_new(const xtd::ustring& theme, const xtd::drawing::size& size) {return file_new(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief File new image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-new".
      static xtd::drawing::image file_new(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "document-new", size);}
      
      /// @brief File open image object.
      /// @return A xtd::drawing::image that represent "document-open".
      static xtd::drawing::image file_open() {return file_open(xtd::forms::theme_images::current_theme(), size());}
      /// @brief File open image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-open".
      static xtd::drawing::image file_open(const xtd::ustring& theme) {return file_open(theme, size());}
      /// @brief File open image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-open".
      static xtd::drawing::image file_open(const xtd::drawing::size& size) {return file_open(xtd::forms::theme_images::current_theme(), size);}
      /// @brief File open image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-open".
      static xtd::drawing::image file_open(const xtd::ustring& theme, const xtd::drawing::size& size) {return file_open(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief File open image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-open".
      static xtd::drawing::image file_open(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "document-open", size);}
      
      /// @brief File save image object.
      /// @return A xtd::drawing::image that represent "document-save".
      static xtd::drawing::image file_save() {return file_save(xtd::forms::theme_images::current_theme(), size());}
      /// @brief File save image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-save".
      static xtd::drawing::image file_save(const xtd::ustring& theme) {return file_save(theme, size());}
      /// @brief File save image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save".
      static xtd::drawing::image file_save(const xtd::drawing::size& size) {return file_save(xtd::forms::theme_images::current_theme(), size);}
      /// @brief File save image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save".
      static xtd::drawing::image file_save(const xtd::ustring& theme, const xtd::drawing::size& size) {return file_save(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief File save image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save".
      static xtd::drawing::image file_save(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "document-save", size);}

      /// @brief File save as image object.
      /// @return A xtd::drawing::image that represent "document-save-as".
      static xtd::drawing::image file_save_as() {return file_save_as(xtd::forms::theme_images::current_theme(), size());}
      /// @brief File save as image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-save-as".
      static xtd::drawing::image file_save_as(const xtd::ustring& theme) {return file_save_as(theme, size());}
      /// @brief File save as image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save-as".
      static xtd::drawing::image file_save_as(const xtd::drawing::size& size) {return file_save_as(xtd::forms::theme_images::current_theme(), size);}
      /// @brief File save as image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save-as".
      static xtd::drawing::image file_save_as(const xtd::ustring& theme, const xtd::drawing::size& size) {return file_save_as(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief File save as image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-save-as".
      static xtd::drawing::image file_save_as(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "document-save-as", size);}

      /// @brief File print image object.
      /// @return A xtd::drawing::image that represent "document-print".
      static xtd::drawing::image file_print() {return file_print(xtd::forms::theme_images::current_theme(), size());}
      /// @brief File print image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-print".
      static xtd::drawing::image file_print(const xtd::ustring& theme) {return file_print(theme, size());}
      /// @brief File print image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print".
      static xtd::drawing::image file_print(const xtd::drawing::size& size) {return file_print(xtd::forms::theme_images::current_theme(), size);}
      /// @brief File print image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print".
      static xtd::drawing::image file_print(const xtd::ustring& theme, const xtd::drawing::size& size) {return file_print(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief File print image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print".
      static xtd::drawing::image file_print(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "document-print", size);}
      
      /// @brief File print preview image object.
      /// @return A xtd::drawing::image that represent "document-print-preview".
      static xtd::drawing::image file_print_preview() {return file_print_preview(xtd::forms::theme_images::current_theme(), size());}
      /// @brief File print preview image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-print-preview".
      static xtd::drawing::image file_print_preview(const xtd::ustring& theme) {return file_print_preview(theme, size());}
      /// @brief File print preview image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print-preview".
      static xtd::drawing::image file_print_preview(const xtd::drawing::size& size) {return file_print_preview(xtd::forms::theme_images::current_theme(), size);}
      /// @brief File print preview image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print-preview".
      static xtd::drawing::image file_print_preview(const xtd::ustring& theme, const xtd::drawing::size& size) {return file_print_preview(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief File print preview image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-print-preview".
      static xtd::drawing::image file_print_preview(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "document-print-preview", size);}

      /// @brief File page setup image object.
      /// @return A xtd::drawing::image that represent "document-page-setup".
      static xtd::drawing::image file_page_setup() {return file_page_setup(xtd::forms::theme_images::current_theme(), size());}
      /// @brief File page setup image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "document-page-setup".
      static xtd::drawing::image file_page_setup(const xtd::ustring& theme) {return file_page_setup(theme, size());}
      /// @brief File page setup image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-page-setup".
      static xtd::drawing::image file_page_setup(const xtd::drawing::size& size) {return file_page_setup(xtd::forms::theme_images::current_theme(), size);}
      /// @brief File page setup image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-page-setup".
      static xtd::drawing::image file_page_setup(const xtd::ustring& theme, const xtd::drawing::size& size) {return file_page_setup(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief File page setup image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "document-page-setup".
      static xtd::drawing::image file_page_setup(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "document-page-setup", size);}

      /// @brief File exit image object.
      /// @return A xtd::drawing::image that represent  "application-exit".
      static xtd::drawing::image file_exit() {return file_exit(xtd::forms::theme_images::current_theme(), size());}
      /// @brief File exit image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "application-exit".
      static xtd::drawing::image file_exit(const xtd::ustring& theme) {return file_exit(theme, size());}
      /// @brief File exit image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "application-exit".
      static xtd::drawing::image file_exit(const xtd::drawing::size& size) {return file_exit(xtd::forms::theme_images::current_theme(), size);}
      /// @brief File exit image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "application-exit".
      static xtd::drawing::image file_exit(const xtd::ustring& theme, const xtd::drawing::size& size) {return file_exit(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief File exit image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "application-exit".
      static xtd::drawing::image file_exit(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "application-exit", size);}
      
      /// @brief Edit undo image object.
      /// @return A xtd::drawing::image that represent "edit-undo".
      static xtd::drawing::image edit_undo() {return edit_undo(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Edit undo image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-undo".
      static xtd::drawing::image edit_undo(const xtd::ustring& theme) {return edit_undo(theme, size());}
      /// @brief Edit undoEdit undo image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-undo".
      static xtd::drawing::image edit_undo(const xtd::drawing::size& size) {return edit_undo(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-undo".
      static xtd::drawing::image edit_undo(const xtd::ustring& theme, const xtd::drawing::size& size) {return edit_undo(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-undo".
      static xtd::drawing::image edit_undo(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-undo", size);}
      
      /// @brief Edit undo image object.
      /// @return A xtd::drawing::image that represent  "edit-redo".
      static xtd::drawing::image edit_redo() {return edit_redo(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Edit undo image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-redo".
      static xtd::drawing::image edit_redo(const xtd::ustring& theme) {return edit_redo(theme, size());}
      /// @brief Edit undo image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-redo".
      static xtd::drawing::image edit_redo(const xtd::drawing::size& size) {return edit_redo(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "edit-redo" "edit-redo".
      static xtd::drawing::image edit_redo(const xtd::ustring& theme, const xtd::drawing::size& size) {return edit_redo(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Edit undo image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-redo".
      static xtd::drawing::image edit_redo(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-redo", size);}
      
      /// @brief Edit cut image object.
      /// @return A xtd::drawing::image that represent "edit-cut".
      static xtd::drawing::image edit_cut() {return edit_cut(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Edit cut image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-cut".
      static xtd::drawing::image edit_cut(const xtd::ustring& theme) {return edit_cut(theme, size());}
      /// @brief Edit cut image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-cut".
      static xtd::drawing::image edit_cut(const xtd::drawing::size& size) {return edit_cut(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Edit cut image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-cut".
      static xtd::drawing::image edit_cut(const xtd::ustring& theme, const xtd::drawing::size& size) {return edit_cut(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Edit cut image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-cut".
      static xtd::drawing::image edit_cut(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-cut", size);}
      
      /// @brief Edit copy image object.
      /// @return A xtd::drawing::image that represent "edit-copy".
      static xtd::drawing::image edit_copy() {return edit_copy(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Edit copy image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "edit-copy".
      static xtd::drawing::image edit_copy(const xtd::ustring& theme) {return edit_copy(theme, size());}
      /// @brief Edit copy image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-copy".
      static xtd::drawing::image edit_copy(const xtd::drawing::size& size) {return edit_copy(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Edit copy image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-copy".
      static xtd::drawing::image edit_copy(const xtd::ustring& theme, const xtd::drawing::size& size) {return edit_copy(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Edit copy image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-copy".
      static xtd::drawing::image edit_copy(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-copy", size);}
      
      /// @brief Edit paste image object.
      /// @return A xtd::drawing::image that represent "edit-paste".
      static xtd::drawing::image edit_paste() {return edit_paste(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Edit paste image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent  "edit-paste".
      static xtd::drawing::image edit_paste(const xtd::ustring& theme) {return edit_paste(theme, size());}
      /// @brief Edit paste image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "edit-paste".
      static xtd::drawing::image edit_paste(const xtd::drawing::size& size) {return edit_paste(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Edit paste image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-paste".
      static xtd::drawing::image edit_paste(const xtd::ustring& theme, const xtd::drawing::size& size) {return edit_paste(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Edit paste image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "edit-paste".
      static xtd::drawing::image edit_paste(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-paste", size);}
      
      /// @brief View back image object.
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image view_back() {return view_back(xtd::forms::theme_images::current_theme(), size());}
      /// @brief View back image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image view_back(const xtd::ustring& theme) {return view_back(theme, size());}
      /// @brief View back image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image view_back(const xtd::drawing::size& size) {return view_back(xtd::forms::theme_images::current_theme(), size);}
      /// @brief View back image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image view_back(const xtd::ustring& theme, const xtd::drawing::size& size) {return view_back(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief View back image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "go-previous".
      static xtd::drawing::image view_back(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "go-previous", size);}

      /// @brief View forward image object.
      /// @return A xtd::drawing::image that represent  "go-next".
      static xtd::drawing::image view_forward() {return view_forward(xtd::forms::theme_images::current_theme(), size());}
      /// @brief View forward image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent  "go-next".
      static xtd::drawing::image view_forward(const xtd::ustring& theme) {return view_forward(theme, size());}
      /// @brief View forward image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "go-next".
      static xtd::drawing::image view_forward(const xtd::drawing::size& size) {return view_forward(xtd::forms::theme_images::current_theme(), size);}
      /// @brief View forward image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "go-next".
      static xtd::drawing::image view_forward(const xtd::ustring& theme, const xtd::drawing::size& size) {return view_forward(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief View forward image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent  "go-next".
      static xtd::drawing::image view_forward(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "go-next", size);}

      /// @brief Help about image object.
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help_about() {return help_about(xtd::forms::theme_images::current_theme(), size());}
      /// @brief Help about image object with specified theme.
      /// @param theme A string that represent a theme
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help_about(const xtd::ustring& theme) {return help_about(theme, size());}
      /// @brief Help about image object with specified size.
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help_about(const xtd::drawing::size& size) {return help_about(xtd::forms::theme_images::current_theme(), size);}
      /// @brief Help about image object with specified theme and size.
      /// @param theme A string that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help_about(const xtd::ustring& theme, const xtd::drawing::size& size) {return help_about(xtd::forms::theme_images::theme_from_name(theme), size);}
      /// @brief Help about image object with specified theme and size.
      /// @param theme A xtd::forms::theme_images that represent a theme
      /// @param size A xtd::drawing::size size for the image
      /// @return A xtd::drawing::image that represent "help-about".
      static xtd::drawing::image help_about(const xtd::forms::theme_images& theme, const xtd::drawing::size& size) {return from_name(theme, "help-about", size);}

      /// @brief Gets the height and width of the menu images.
      /// @return The size that represents the height and width of the menu images in pixels (16 x 16).
      static xtd::drawing::size size() {return xtd::environment::os_version().is_windows_platform() ? xtd::drawing::size {16, 16} : xtd::drawing::size {24, 24};}
      
      /// @brief Gets image object with specified name.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::context_names to get names by context.
      static xtd::drawing::image from_name(const xtd::ustring& name) {return from_name(name, size());}
      /// @brief Gets image object with specified theme and name.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::ustring& theme, const xtd::ustring& name) {return from_name(theme, name, size());}
      /// @brief Gets image object with specified name and size.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::ustring& name, const xtd::drawing::size& size) {return from_name(xtd::forms::theme_images::current_theme(), name, size);}
      /// @brief Gets image object with specified theme, name and size.
      /// @param theme the theme name that contains the image to get.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::ustring& theme, const xtd::ustring& name, const xtd::drawing::size& size) {return from_name(xtd::forms::theme_images::theme_from_name(theme), name, size);}
      /// @brief Gets image object with specified theme, name and size.
      /// @param theme the theme that contains the image to get.
      /// @param name the image name to get.
      /// @param size The size that represents the height and width of the button images in pixels.
      /// @return A xtd::drawing::image that represent the specified name.
      /// @remarks Use xtd::drawing::system_images::themes to get valid themes.
      /// @remarks Use xtd::drawing::system_images::context_names to get valid names by context.
      static xtd::drawing::image from_name(const xtd::forms::theme_images& theme, const xtd::ustring& name, const xtd::drawing::size& size) {return theme.from_name(name, size);}
    };
  }
}
