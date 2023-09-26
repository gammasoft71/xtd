#include "../../../include/xtd/forms/tool_bar_images"

using namespace xtd;
using namespace xtd::forms;

xtd::drawing::image tool_bar_images::file_new() {
  return file_new(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::file_new(const xtd::ustring& theme) {
  return file_new(theme, size());
}

xtd::drawing::image tool_bar_images::file_new(const xtd::drawing::size& size) {
  return file_new(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::file_new(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "document-new", size);
}

xtd::drawing::image tool_bar_images::file_open() {
  return file_open(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::file_open(const xtd::ustring& theme) {
  return file_open(theme, size());
}

xtd::drawing::image tool_bar_images::file_open(const xtd::drawing::size& size) {
  return file_open(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::file_open(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "document-open", size);
}

xtd::drawing::image tool_bar_images::file_save() {
  return file_save(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::file_save(const xtd::ustring& theme) {
  return file_save(theme, size());
}

xtd::drawing::image tool_bar_images::file_save(const xtd::drawing::size& size) {
  return file_save(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::file_save(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "document-save", size);
}

xtd::drawing::image tool_bar_images::file_save_as() {
  return file_save_as(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::file_save_as(const xtd::ustring& theme) {
  return file_save_as(theme, size());
}

xtd::drawing::image tool_bar_images::file_save_as(const xtd::drawing::size& size) {
  return file_save_as(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::file_save_as(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "document-save-as", size);
}

xtd::drawing::image tool_bar_images::file_print() {
  return file_print(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::file_print(const xtd::ustring& theme) {
  return file_print(theme, size());
}

xtd::drawing::image tool_bar_images::file_print(const xtd::drawing::size& size) {
  return file_print(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::file_print(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "document-print", size);
}

xtd::drawing::image tool_bar_images::file_print_preview() {
  return file_print_preview(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::file_print_preview(const xtd::ustring& theme) {
  return file_print_preview(theme, size());
}

xtd::drawing::image tool_bar_images::file_print_preview(const xtd::drawing::size& size) {
  return file_print_preview(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::file_print_preview(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "document-print-preview", size);
}

xtd::drawing::image tool_bar_images::file_page_setup() {
  return file_page_setup(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::file_page_setup(const xtd::ustring& theme) {
  return file_page_setup(theme, size());
}

xtd::drawing::image tool_bar_images::file_page_setup(const xtd::drawing::size& size) {
  return file_page_setup(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::file_page_setup(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "document-page-setup", size);
}

xtd::drawing::image tool_bar_images::file_exit() {
  return file_exit(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::file_exit(const xtd::ustring& theme) {
  return file_exit(theme, size());
}

xtd::drawing::image tool_bar_images::file_exit(const xtd::drawing::size& size) {
  return file_exit(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::file_exit(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "application-exit", size);
}

xtd::drawing::image tool_bar_images::edit_undo() {
  return edit_undo(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::edit_undo(const xtd::ustring& theme) {
  return edit_undo(theme, size());
}

xtd::drawing::image tool_bar_images::edit_undo(const xtd::drawing::size& size) {
  return edit_undo(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::edit_undo(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "edit-undo", size);
}

xtd::drawing::image tool_bar_images::edit_redo() {
  return edit_redo(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::edit_redo(const xtd::ustring& theme) {
  return edit_redo(theme, size());
}

xtd::drawing::image tool_bar_images::edit_redo(const xtd::drawing::size& size) {
  return edit_redo(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::edit_redo(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "edit-redo", size);
}

xtd::drawing::image tool_bar_images::edit_cut() {
  return edit_cut(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::edit_cut(const xtd::ustring& theme) {
  return edit_cut(theme, size());
}

xtd::drawing::image tool_bar_images::edit_cut(const xtd::drawing::size& size) {
  return edit_cut(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::edit_cut(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "edit-cut", size);
}

xtd::drawing::image tool_bar_images::edit_copy() {
  return edit_copy(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::edit_copy(const xtd::ustring& theme) {
  return edit_copy(theme, size());
}

xtd::drawing::image tool_bar_images::edit_copy(const xtd::drawing::size& size) {
  return edit_copy(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::edit_copy(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "edit-copy", size);
}

xtd::drawing::image tool_bar_images::edit_paste() {
  return edit_paste(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::edit_paste(const xtd::ustring& theme) {
  return edit_paste(theme, size());
}

xtd::drawing::image tool_bar_images::edit_paste(const xtd::drawing::size& size) {
  return edit_paste(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::edit_paste(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "edit-paste", size);
}

xtd::drawing::image tool_bar_images::view_back() {
  return view_back(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::view_back(const xtd::ustring& theme) {
  return view_back(theme, size());
}

xtd::drawing::image tool_bar_images::view_back(const xtd::drawing::size& size) {
  return view_back(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::view_back(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "go-previous", size);
}

xtd::drawing::image tool_bar_images::view_forward() {
  return view_forward(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::view_forward(const xtd::ustring& theme) {
  return view_forward(theme, size());
}

xtd::drawing::image tool_bar_images::view_forward(const xtd::drawing::size& size) {
  return view_forward(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::view_forward(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "go-next", size);
}

xtd::drawing::image tool_bar_images::help() {
  return help(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::help(const xtd::ustring& theme) {
  return help(theme, size());
}

xtd::drawing::image tool_bar_images::help(const xtd::drawing::size& size) {
  return help(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::help(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "help", size);
}

xtd::drawing::image tool_bar_images::help_about() {
  return help_about(application::style_sheet().theme().name(), size());
}

xtd::drawing::image tool_bar_images::help_about(const xtd::ustring& theme) {
  return help_about(theme, size());
}

xtd::drawing::image tool_bar_images::help_about(const xtd::drawing::size& size) {
  return help_about(application::style_sheet().theme().name(), size);
}

xtd::drawing::image tool_bar_images::help_about(const xtd::ustring& theme, const xtd::drawing::size& size) {
  return from_name(theme, "help-about", size);
}

xtd::drawing::size tool_bar_images::size() {
  return xtd::environment::os_version().is_windows_platform() ? xtd::drawing::size {16, 16} : xtd::drawing::size {64, 64};
}

xtd::drawing::image tool_bar_images::from_name(const xtd::ustring& name) {
  return from_name(name, size());
}

xtd::drawing::image tool_bar_images::from_name(const xtd::ustring& theme, const xtd::ustring& name) {
  return from_name(theme, name, size());
}

xtd::drawing::image tool_bar_images::from_name(const xtd::ustring& name, const xtd::drawing::size& size) {
  return from_name(application::style_sheet().theme().name(), name, size);
}

xtd::drawing::image tool_bar_images::from_name(const xtd::ustring& theme, const xtd::ustring& name, const xtd::drawing::size& size) {
  return images::from_name(theme, name, size);
}
