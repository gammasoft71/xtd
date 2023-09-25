#include "../../../include/xtd/diagnostics/process_start_info"

using namespace xtd;
using namespace xtd::diagnostics;
using namespace xtd::security;

process_start_info::process_start_info(const ustring& file_name) : file_name_(file_name) {
}

process_start_info::process_start_info(const ustring& file_name, const ustring& arguments) : file_name_(file_name), arguments_(arguments) {
}

const ustring& process_start_info::arguments() const noexcept {
  return arguments_;
}

process_start_info& process_start_info::arguments(const ustring& value) noexcept {
  arguments_ = value;
  return *this;
}

bool process_start_info::create_no_window() const noexcept {
  return create_no_window_;
}

process_start_info& process_start_info::create_no_window(bool value) noexcept {
  create_no_window_ = value;
  return *this;
}

const ustring& process_start_info::domain() const noexcept {
  return domain_;
}

process_start_info& process_start_info::domain(const ustring& value) noexcept {
  domain_ = value;
  return *this;
}

const std::map<ustring, ustring>& process_start_info::environment() const noexcept {
  return environment_variables_;
}

std::map<ustring, ustring>& process_start_info::environment() noexcept {
  return environment_variables_;
}

const std::map<ustring, ustring>& process_start_info::environment_variables() const noexcept {
  return environment_variables_;
}

std::map<ustring, ustring>& process_start_info::environment_variables() noexcept {
  return environment_variables_;
}

bool process_start_info::error_dialog() const noexcept {
  return error_dialog_;
}

process_start_info& process_start_info::error_dialog(bool value) noexcept {
  error_dialog_ = value;
  return *this;
}

intptr process_start_info::error_dialog_parent_handle() const noexcept {
  return error_dialog_parent_handle_;
}

process_start_info& process_start_info::error_dialog_parent_handle(intptr value) noexcept {
  error_dialog_parent_handle_ = value;
  return *this;
}

const ustring& process_start_info::file_name() const noexcept {
  return file_name_;
}

process_start_info& process_start_info::file_name(const ustring& value) noexcept {
  file_name_ = value;
  return *this;
}

process_start_info& process_start_info::file_name(const char* value) noexcept {
  file_name_ = value;
  return *this;
}

bool process_start_info::load_user_profile() const noexcept {
  return load_user_profile_;
}

process_start_info& process_start_info::load_user_profile(bool value) noexcept {
  load_user_profile_ = value;
  return *this;
}

const xtd::security::secure_string& process_start_info::password() const noexcept {
  return password_;
}

process_start_info& process_start_info::password(const xtd::security::secure_string& value) noexcept {
  password_ = value;
  return *this;
}

ustring process_start_info::password_in_clear_text() const noexcept {
  return password_.to_unsecure_string();
}

process_start_info& process_start_info::password_in_clear_text(const ustring& value) noexcept {
  password_ = secure_string(value.c_str(), value.size());
  return *this;
}

bool process_start_info::redirect_standard_error() const noexcept {
  return redirect_standard_error_;
}

process_start_info& process_start_info::redirect_standard_error(bool value) noexcept {
  redirect_standard_error_ = value;
  return *this;
}

bool process_start_info::redirect_standard_input() const noexcept {
  return redirect_standard_input_;
}

process_start_info& process_start_info::redirect_standard_input(bool value) noexcept {
  redirect_standard_input_ = value;
  return *this;
}

bool process_start_info::redirect_standard_output() const noexcept {
  return redirect_standard_output_;
}

process_start_info& process_start_info::redirect_standard_output(bool value) noexcept {
  redirect_standard_output_ = value;
  return *this;
}

const ustring& process_start_info::user_name() const noexcept {
  return user_name_;
}

process_start_info& process_start_info::user_name(const ustring& value) noexcept {
  user_name_ = value;
  return *this;
}

bool process_start_info::use_shell_execute() const noexcept {
  return use_shell_execute_;
}

process_start_info& process_start_info::use_shell_execute(bool value) noexcept {
  use_shell_execute_ = value;
  return *this;
}

ustring process_start_info::verb() const noexcept {
  return verb_;
}

process_start_info& process_start_info::verb(const ustring& value) noexcept {
  verb_ = value;
  return *this;
}

std::vector<ustring> process_start_info::verbs() const {
  if (file_name_ == "") return {};
  // return native::process:verbs(file_name_);
  return {};
}

process_window_style process_start_info::window_style() const noexcept {
  return window_style_;
}

process_start_info& process_start_info::window_style(process_window_style value) noexcept {
  window_style_ = value;
  return *this;
}

const ustring& process_start_info::working_directory() const noexcept {
  return working_directory_;
}

process_start_info& process_start_info::working_directory(const ustring& value) noexcept {
  working_directory_ = value;
  return *this;
}
