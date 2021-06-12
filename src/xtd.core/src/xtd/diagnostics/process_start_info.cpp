#include "../../../include/xtd/diagnostics/process_start_info.h"

using namespace std;
using namespace xtd::diagnostics;

process_start_info::process_start_info(const std::string& file_name) : file_name_(file_name ) {
}

process_start_info::process_start_info(const std::string& file_name, const std::string& arguments) : file_name_(file_name), arguments_(arguments) {
}

const std::string& process_start_info::arguments() const {
  return arguments_;
}

process_start_info& process_start_info::arguments(const std::string& value) {
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

const std::string& process_start_info::domain() const {
  return domain_;
}

process_start_info& process_start_info::domain(const std::string& value) {
  domain_ = value;
  return *this;
}

const std::map<std::string, std::string>& process_start_info::environment() const {
  return environment_variables_;
}

std::map<std::string, std::string>& process_start_info::environment() {
  return environment_variables_;
}

const std::map<std::string, std::string>& process_start_info::environment_variables() const {
  return environment_variables_;
}

std::map<std::string, std::string>& process_start_info::environment_variables() {
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

const std::string& process_start_info::file_name() const {
  return file_name_;
}

process_start_info& process_start_info::file_name(const std::string& value) {
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

const xtd::security::secure_string& process_start_info::pasword() const {
  return password_;
}

process_start_info& process_start_info::pasword(const xtd::security::secure_string& value) {
  password_ = value;
  return *this;
}

std::string process_start_info::password_in_clear_text() const {
  //return native::security::to_unsecure_string(password_);
  return password_;
}

process_start_info& process_start_info::password_in_clear_text(const std::string& value) {
  //password_ = native::security_api::to_secure_secure_string(value);
  return *this;
}

vector<string> process_start_info::get_verbs(const string& file_name) const {
  return {};
}
