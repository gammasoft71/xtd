#include "../include/xtd/diagnostics/process_start_info.h"

using namespace std;
using namespace xtd::diagnostics;

string process_start_info::get_password_in_clear_text() const {
  //return native::security::to_unsecure_string(password_);
  return password_;
}

void process_start_info::set_password_in_clear_text(const string& password) {
  //password_ = native::security_api::to_secure_secure_String(password);
  password_ = password;
}

vector<string> process_start_info::get_verbs(const string& file_name) const {
  return {};
}
