#pragma once
#include <xtd/static.h>
#include <xtd/drawing/system_images.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class menu_images static_ {
    public:
      static xtd::drawing::image file_new() {return file_new(size());}
      static xtd::drawing::image file_new(const xtd::drawing::size& size) {return from_name("document-new", size);}
      static xtd::drawing::image file_open() {return file_open(size());}
      static xtd::drawing::image file_open(const xtd::drawing::size& size) {return from_name("document-open", size);}
      static xtd::drawing::image file_save() {return file_save(size());}
      static xtd::drawing::image file_save(const xtd::drawing::size& size) {return from_name("document-save", size);}
      static xtd::drawing::image file_print() {return file_print(size());}
      static xtd::drawing::image file_print(const xtd::drawing::size& size) {return from_name("document-print", size);}
      static xtd::drawing::image file_print_preview() {return file_print_preview(size());}
      static xtd::drawing::image file_print_preview(const xtd::drawing::size& size) {return from_name("document-print-preview", size);}
      static xtd::drawing::image file_exit() {return file_exit(size());}
      static xtd::drawing::image file_exit(const xtd::drawing::size& size) {return from_name("application-exit", size);}
      static xtd::drawing::image edit_undo() {return edit_undo(size());}
      static xtd::drawing::image edit_undo(const xtd::drawing::size& size) {return from_name("edit-undo", size);}
      static xtd::drawing::image edit_redo() {return edit_redo(size());}
      static xtd::drawing::image edit_redo(const xtd::drawing::size& size) {return from_name("edit-redo", size);}
      static xtd::drawing::image edit_cut() {return edit_cut(size());}
      static xtd::drawing::image edit_cut(const xtd::drawing::size& size) {return from_name("edit-cut", size);}
      static xtd::drawing::image edit_copy() {return edit_copy(size());}
      static xtd::drawing::image edit_copy(const xtd::drawing::size& size) {return from_name("edit-copy", size);}
      static xtd::drawing::image edit_paste() {return edit_paste(size());}
      static xtd::drawing::image edit_paste(const xtd::drawing::size& size) {return from_name("edit-paste", size);}
      static xtd::drawing::image view_back() {return view_back(size());}
      static xtd::drawing::image view_back(const xtd::drawing::size& size) {return from_name("go-previous", size);}
      static xtd::drawing::image view_forward() {return view_forward(size());}
      static xtd::drawing::image view_forward(const xtd::drawing::size& size) {return from_name("go-next", size);}
      static xtd::drawing::image help_about() {return help_about(size());}
      static xtd::drawing::image help_about(const xtd::drawing::size& size) {return from_name("help-about", size);}

      static xtd::drawing::size size() {return {16, 16};}
      static xtd::drawing::image from_name(const std::string& name) {return from_name(name, size());}
      static xtd::drawing::image from_name(const std::string& name, const xtd::drawing::size& size) {return xtd::drawing::system_images::from_name(name, size);}
    };
  }
}
