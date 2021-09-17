#include "../../../include/xtd/diagnostics/process_start_info.h"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::security;

process_start_info::process_start_info(const ustring& file_name) : file_name_(file_name ) {
}

process_start_info::process_start_info(const ustring& file_name, const ustring& arguments) : file_name_(file_name), arguments_(arguments) {
}

const ustring& process_start_info::arguments() const {
  return arguments_;
}

process_start_info& process_start_info::arguments(const ustring& value) {
  arguments_ = value;
  return *this;
}

bool process_start_info::create_no_window() const {
  return create_no_window_;
}

process_start_info& process_start_info::create_no_window(bool value) {
  create_no_window_ = value;
  return *this;
}

const ustring& process_start_info::domain() const {
  return domain_;
}

process_start_info& process_start_info::domain(const ustring& value) {
  domain_ = value;
  return *this;
}

const std::map<ustring, ustring>& process_start_info::environment() const {
  return environment_variables_;
}

std::map<ustring, ustring>& process_start_info::environment() {
  return environment_variables_;
}

const std::map<ustring, ustring>& process_start_info::environment_variables() const {
  return environment_variables_;
}

std::map<ustring, ustring>& process_start_info::environment_variables() {
  return environment_variables_;
}

bool process_start_info::error_dialog() const {
  return error_dialog_;
}

process_start_info& process_start_info::error_dialog(bool value) {
  error_dialog_ = value;
  return *this;
}

intptr_t process_start_info::error_dialog_parent_handle() const {
  return error_dialog_parent_handle_;
}

process_start_info& process_start_info::error_dialog_parent_handle(intptr_t value) {
  error_dialog_parent_handle_ = value;
  return *this;
}

const ustring& process_start_info::file_name() const {
  return file_name_;
}

process_start_info& process_start_info::file_name(const ustring& value) {
  file_name_ = value;
  return *this;
}

process_start_info& process_start_info::file_name(const std::filesystem::path& value) {
  file_name_ = value.string();
  return *this;
}

process_start_info& process_start_info::file_name(const char* value) {
  file_name_ = value;
  return *this;
}

bool process_start_info::load_user_profile() const {
  return load_user_profile_;
}

process_start_info& process_start_info::load_user_profile(bool value) {
  load_user_profile_ = value;
  return *this;
}

const xtd::security::secure_string& process_start_info::password() const {
  return password_;
}

process_start_info& process_start_info::password(const xtd::security::secure_string& value) {
  password_ = value;
  return *this;
}

ustring process_start_info::password_in_clear_text() const {
   return password_.to_unsecure_string();
}

process_start_info& process_start_info::password_in_clear_text(const ustring& value) {
  password_ = secure_string(value.c_str(), value.size());
  return *this;
}

bool process_start_info::redirect_standard_error() const {
  return redirect_standard_error_;
}

process_start_info& process_start_info::redirect_standard_error(bool value) {
  redirect_standard_error_ = value;
  return *this;
}

bool process_start_info::redirect_standard_input() const {
  return redirect_standard_input_;
}

process_start_info& process_start_info::redirect_standard_input(bool value) {
  redirect_standard_input_ = value;
  return *this;
}

bool process_start_info::redirect_standard_output() const {
  return redirect_standard_output_;
}

process_start_info& process_start_info::redirect_standard_output(bool value) {
  redirect_standard_output_ = value;
  return *this;
}

const ustring& process_start_info::user_name() const {
  return user_name_;
}

process_start_info& process_start_info::user_name(const ustring& value) {
  user_name_ = value;
  return *this;
}

bool process_start_info::use_shell_execute() const {
  return use_shell_execute_;
}

process_start_info& process_start_info::use_shell_execute(bool value) {
  use_shell_execute_ = value;
  return *this;
}

ustring process_start_info::verb() const {
  return verb_;
}

process_start_info& process_start_info::verb(const ustring& value) {
  verb_ = value;
  return *this;
}

std::vector<ustring> process_start_info::verbs() const {
  if (file_name_ == "") return {};
  // return native::process:verbs(file_name_);
  return {};
}

process_window_style process_start_info::window_style() const {
  return window_style_;
}

process_start_info& process_start_info::window_style(process_window_style value) {
  window_style_ = value;
  return *this;
}

const ustring& process_start_info::working_directory() const {
  return working_directory_;
}

process_start_info& process_start_info::working_directory(const ustring& value) {
  working_directory_ = value;
  return *this;
}
