#include "../../../include/xtd/diagnostics/process_start_info.hpp"

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::diagnostics;
using namespace xtd::security;

process_start_info::process_start_info(const string& file_name) : file_name_(file_name) {
}

process_start_info::process_start_info(const string& file_name, const string& arguments) : file_name_(file_name), arguments_(arguments) {
}

auto process_start_info::arguments() const noexcept -> const string& {
  return arguments_;
}

auto process_start_info::arguments(const string& value) noexcept -> process_start_info& {
  arguments_ = value;
  return *this;
}

auto process_start_info::create_no_window() const noexcept -> bool {
  return create_no_window_;
}

auto process_start_info::create_no_window(bool value) noexcept -> process_start_info& {
  create_no_window_ = value;
  return *this;
}

auto process_start_info::domain() const noexcept -> const string& {
  return domain_;
}

auto process_start_info::domain(const string& value) noexcept -> process_start_info& {
  domain_ = value;
  return *this;
}

auto process_start_info::environment() const noexcept -> const idictionary<string, string>& {
  return environment_variables_;
}

auto process_start_info::environment() noexcept -> idictionary<string, string>& {
  return environment_variables_;
}

auto process_start_info::environment_variables() const noexcept -> const idictionary<string, string>& {
  return environment_variables_;
}

auto process_start_info::environment_variables() noexcept -> idictionary<string, string>& {
  return environment_variables_;
}

auto process_start_info::error_dialog() const noexcept -> bool {
  return error_dialog_;
}

auto process_start_info::error_dialog(bool value) noexcept -> process_start_info& {
  error_dialog_ = value;
  return *this;
}

auto process_start_info::error_dialog_parent_handle() const noexcept -> intptr {
  return error_dialog_parent_handle_;
}

auto process_start_info::error_dialog_parent_handle(intptr value) noexcept -> process_start_info& {
  error_dialog_parent_handle_ = value;
  return *this;
}

auto process_start_info::file_name() const noexcept -> const string& {
  return file_name_;
}

auto process_start_info::file_name(const string& value) noexcept -> process_start_info& {
  file_name_ = value;
  return *this;
}

auto process_start_info::file_name(const char* value) noexcept -> process_start_info& {
  file_name_ = value;
  return *this;
}

auto process_start_info::load_user_profile() const noexcept -> bool {
  return load_user_profile_;
}

auto process_start_info::load_user_profile(bool value) noexcept -> process_start_info& {
  load_user_profile_ = value;
  return *this;
}

auto process_start_info::password() const noexcept -> const secure_string& {
  return password_;
}

auto process_start_info::password(const secure_string& value) noexcept -> process_start_info& {
  password_ = value;
  return *this;
}

auto process_start_info::password_in_clear_text() const noexcept -> string {
  return password_.to_unsecure_string();
}

auto process_start_info::password_in_clear_text(const string& value) noexcept -> process_start_info& {
  password_ = secure_string(value.chars().c_str(), value.length());
  return *this;
}

auto process_start_info::redirect_standard_error() const noexcept -> bool {
  return redirect_standard_error_;
}

auto process_start_info::redirect_standard_error(bool value) noexcept -> process_start_info& {
  redirect_standard_error_ = value;
  return *this;
}

auto process_start_info::redirect_standard_input() const noexcept -> bool {
  return redirect_standard_input_;
}

auto process_start_info::redirect_standard_input(bool value) noexcept -> process_start_info& {
  redirect_standard_input_ = value;
  return *this;
}

auto process_start_info::redirect_standard_output() const noexcept -> bool {
  return redirect_standard_output_;
}

auto process_start_info::redirect_standard_output(bool value) noexcept -> process_start_info& {
  redirect_standard_output_ = value;
  return *this;
}

auto process_start_info::user_name() const noexcept -> const string& {
  return user_name_;
}

auto process_start_info::user_name(const string& value) noexcept -> process_start_info& {
  user_name_ = value;
  return *this;
}

auto process_start_info::use_shell_execute() const noexcept -> bool {
  return use_shell_execute_;
}

auto process_start_info::use_shell_execute(bool value) noexcept -> process_start_info& {
  use_shell_execute_ = value;
  return *this;
}

auto process_start_info::verb() const noexcept -> string {
  return verb_;
}

auto process_start_info::verb(const string& value) noexcept -> process_start_info& {
  verb_ = value;
  return *this;
}

auto process_start_info::verbs() const -> list<string> {
  if (file_name_ == "") return {};
  // return native::process:verbs(file_name_);
  return {};
}

auto process_start_info::window_style() const noexcept -> process_window_style {
  return window_style_;
}

auto process_start_info::window_style(process_window_style value) noexcept -> process_start_info& {
  window_style_ = value;
  return *this;
}

auto process_start_info::working_directory() const noexcept -> const string& {
  return working_directory_;
}

auto process_start_info::working_directory(const string& value) noexcept -> process_start_info& {
  working_directory_ = value;
  return *this;
}
