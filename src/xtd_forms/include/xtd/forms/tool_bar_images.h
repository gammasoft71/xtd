#pragma once
#include <xtd/environment.h>
#include <xtd/static.h>
#include <xtd/drawing/system_images.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class tool_bar_images static_ {
    public:
      static xtd::drawing::image file_new() {return file_new(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image file_new(const std::string& theme) {return file_new(theme, size());}
      static xtd::drawing::image file_new(const xtd::drawing::size& size) {return file_new(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image file_new(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "document-new", size);}
      static xtd::drawing::image file_open() {return file_open(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image file_open(const std::string& theme) {return file_open(theme, size());}
      static xtd::drawing::image file_open(const xtd::drawing::size& size) {return file_open(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image file_open(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "document-open", size);}
      static xtd::drawing::image file_save() {return file_save(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image file_save(const std::string& theme) {return file_save(theme, size());}
      static xtd::drawing::image file_save(const xtd::drawing::size& size) {return file_save(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image file_save(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "document-save", size);}
      static xtd::drawing::image file_save_as() {return file_save_as(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image file_save_as(const std::string& theme) {return file_save_as(theme, size());}
      static xtd::drawing::image file_save_as(const xtd::drawing::size& size) {return file_save_as(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image file_save_as(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "document-save-as", size);}
      static xtd::drawing::image file_print() {return file_print(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image file_print(const std::string& theme) {return file_print(theme, size());}
      static xtd::drawing::image file_print(const xtd::drawing::size& size) {return file_print(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image file_print(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "document-print", size);}
      static xtd::drawing::image file_print_preview() {return file_print_preview(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image file_print_preview(const std::string& theme) {return file_print_preview(theme, size());}
      static xtd::drawing::image file_print_preview(const xtd::drawing::size& size) {return file_print_preview(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image file_print_preview(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "document-print-preview", size);}
      static xtd::drawing::image file_page_setup() {return file_page_setup(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image file_page_setup(const std::string& theme) {return file_page_setup(theme, size());}
      static xtd::drawing::image file_page_setup(const xtd::drawing::size& size) {return file_page_setup(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image file_page_setup(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "document-page-setup", size);}
      static xtd::drawing::image file_exit() {return file_exit(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image file_exit(const std::string& theme) {return file_exit(theme, size());}
      static xtd::drawing::image file_exit(const xtd::drawing::size& size) {return file_exit(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image file_exit(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "application-exit", size);}
      static xtd::drawing::image edit_undo() {return edit_undo(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image edit_undo(const std::string& theme) {return edit_undo(theme, size());}
      static xtd::drawing::image edit_undo(const xtd::drawing::size& size) {return edit_undo(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image edit_undo(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-undo", size);}
      static xtd::drawing::image edit_redo() {return edit_redo(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image edit_redo(const std::string& theme) {return edit_redo(theme, size());}
      static xtd::drawing::image edit_redo(const xtd::drawing::size& size) {return edit_redo(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image edit_redo(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-redo", size);}
      static xtd::drawing::image edit_cut() {return edit_cut(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image edit_cut(const std::string& theme) {return edit_cut(theme, size());}
      static xtd::drawing::image edit_cut(const xtd::drawing::size& size) {return edit_cut(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image edit_cut(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-cut", size);}
      static xtd::drawing::image edit_copy() {return edit_copy(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image edit_copy(const std::string& theme) {return edit_copy(theme, size());}
      static xtd::drawing::image edit_copy(const xtd::drawing::size& size) {return edit_copy(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image edit_copy(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-copy", size);}
      static xtd::drawing::image edit_paste() {return edit_paste(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image edit_paste(const std::string& theme) {return edit_paste(theme, size());}
      static xtd::drawing::image edit_paste(const xtd::drawing::size& size) {return edit_paste(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image edit_paste(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "edit-paste", size);}
      static xtd::drawing::image view_back() {return view_back(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image view_back(const std::string& theme) {return view_back(theme, size());}
      static xtd::drawing::image view_back(const xtd::drawing::size& size) {return view_back(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image view_back(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "go-previous", size);}
      static xtd::drawing::image view_forward() {return view_forward(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image view_forward(const std::string& theme) {return view_forward(theme, size());}
      static xtd::drawing::image view_forward(const xtd::drawing::size& size) {return view_forward(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image view_forward(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "go-next", size);}
      static xtd::drawing::image help_about() {return help_about(xtd::drawing::system_images::default_theme(), size());}
      static xtd::drawing::image help_about(const std::string& theme) {return help_about(theme, size());}
      static xtd::drawing::image help_about(const xtd::drawing::size& size) {return help_about(xtd::drawing::system_images::default_theme(), size);}
      static xtd::drawing::image help_about(const std::string& theme, const xtd::drawing::size& size) {return from_name(theme, "help-about", size);}

      static xtd::drawing::size size() {return xtd::environment::os_version().is_osx_platform() ? xtd::drawing::size {24, 24} : xtd::drawing::size {16, 16};}
      static xtd::drawing::image from_name(const std::string& name) {return from_name(name, size());}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name) {return from_name(theme, name, size());}
      static xtd::drawing::image from_name(const std::string& name, const xtd::drawing::size& size) {return from_name(xtd::drawing::system_images::default_theme(), name, size);}
      static xtd::drawing::image from_name(const std::string& theme, const std::string& name, const xtd::drawing::size& size) {return xtd::drawing::system_images::from_name(theme, name, size);}
    };
  }
}
