#include "../../../include/xtd/forms/file_dialog"
#include "file_dialog_data.h"

using namespace xtd;
using namespace xtd::forms;

file_dialog::file_dialog() : data_(std::make_shared<data>()) {
}

bool file_dialog::add_extension() const noexcept {
  return get_option(OFN_ADDEXTENSION);
}

file_dialog& file_dialog::add_extension(bool value) {
  set_option(OFN_ADDEXTENSION, value);
  return *this;
}

bool file_dialog::auto_upgrade_enabled() const noexcept {
  return data_->auto_upgrade_enabled;
}

file_dialog& file_dialog::auto_upgrade_enabled(bool value) {
  data_->auto_upgrade_enabled = value;
  return *this;
}

bool file_dialog::check_file_exists() const noexcept {
  return get_option(OFN_FILEMUSTEXIST);
}

file_dialog& file_dialog::check_file_exists(bool value) {
  set_option(OFN_FILEMUSTEXIST, value);
  return *this;
}


bool file_dialog::check_path_exists() const noexcept {
  return get_option(OFN_PATHMUSTEXIST);
}

file_dialog& file_dialog::check_path_exists(bool value) {
  set_option(OFN_PATHMUSTEXIST, value);
  return *this;
}

const xtd::ustring& file_dialog::default_ext() const noexcept {
  return data_->default_ext;
}

file_dialog& file_dialog::default_ext(const xtd::ustring& value) {
  data_->default_ext = value;
  return *this;
}

bool file_dialog::dereference_link() const noexcept {
  return !get_option(OFN_NODEREFERENCELINKS);
}

file_dialog& file_dialog::dereference_link(bool value) {
  set_option(OFN_NODEREFERENCELINKS, !value);
  return *this;
}

const xtd::ustring& file_dialog::file_name() const noexcept {
  return data_->file_name;
}

file_dialog& file_dialog::file_name(const xtd::ustring& value) {
  data_->file_name = value;
  return *this;
}

const std::vector<xtd::ustring> file_dialog::file_names() const noexcept {
  return data_->file_names;
}

const xtd::ustring& file_dialog::filter() const noexcept {
  return data_->filter;
}

file_dialog& file_dialog::filter(const xtd::ustring& value) {
  data_->filter = value;
  return *this;
}

size_t file_dialog::filter_index() const noexcept {
  return data_->filter_index;
}

file_dialog& file_dialog::filter_index(size_t value) {
  data_->filter_index = value;
  return *this;
}

const xtd::ustring& file_dialog::initial_directory() const noexcept {
  return data_->initial_directory;
}

file_dialog& file_dialog::initial_directory(const xtd::ustring& value) {
  data_->initial_directory = value;
  return *this;
}

size_t file_dialog::options() const noexcept {
  return data_->options;
}

bool file_dialog::restore_directory() const noexcept {
  return get_option(OFN_NOCHANGEDIR);
}

file_dialog& file_dialog::restore_directory(bool value) {
  set_option(OFN_NOCHANGEDIR, value);
  return *this;
}

bool file_dialog::show_help() const noexcept {
  return !get_option(OFN_SHOWHELP);
}

file_dialog& file_dialog::show_help(bool value) {
  set_option(OFN_SHOWHELP, value);
  return *this;
}

bool file_dialog::show_hidden_files() const noexcept {
  return !get_option(OFN_FORCESHOWHIDDEN);
}

file_dialog& file_dialog::show_hidden_files(bool value) {
  set_option(OFN_FORCESHOWHIDDEN, value);
  return *this;
}

bool file_dialog::show_preview() const noexcept {
  return !get_option(OFN_SHOWPREVIEW);
}

file_dialog& file_dialog::show_preview(bool value) {
  set_option(OFN_SHOWPREVIEW, value);
  return *this;
}

bool file_dialog::support_multi_dotted_extensions() const noexcept {
  return data_->support_multi_dotted_extensions;
}

file_dialog& file_dialog::support_multi_dotted_extensions(bool value) {
  data_->support_multi_dotted_extensions = value;
  return *this;
}

const xtd::ustring& file_dialog::title() const noexcept {
  return data_->title;
}

file_dialog& file_dialog::title(const xtd::ustring& value) {
  data_->title = value;
  return *this;
}

bool file_dialog::validate_names() const noexcept {
  return !get_option(OFN_NOVALIDATE);
}

file_dialog& file_dialog::validate_names(bool value) {
  set_option(OFN_NOVALIDATE, !value);
  return *this;
}

void file_dialog::reset() noexcept {
  set_dialog_result(xtd::forms::dialog_result::none);
  data_->auto_upgrade_enabled = true;
  data_->default_ext = "";
  data_->file_name = "";
  data_->file_names.clear();
  data_->filter = "";
  data_->filter_index = 1;
  data_->initial_directory = "";
  data_->options = OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_ADDEXTENSION;
  data_->support_multi_dotted_extensions = true;
  data_->title = "";
}

xtd::ustring file_dialog::to_string() const noexcept {
  return ustring::format("{}: title: {}, filename: {}", get_type().full_name(), data_->title, data_->file_name);
}

bool file_dialog::run_dialog(intptr hwnd_owner) {
  return run_file_dialog(hwnd_owner);
}

void file_dialog::run_sheet(intptr hwnd_owner) {
  return run_file_sheet(hwnd_owner);
}

bool file_dialog::get_option(size_t flag) const noexcept {
  return (data_->options & flag) == flag;
}

void file_dialog::set_option(size_t flag, bool value) {
  data_->options = value ? data_->options | flag : data_->options & ~flag;
}
