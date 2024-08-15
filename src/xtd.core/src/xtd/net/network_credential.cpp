#include "../../../include/xtd/net/network_credential.h"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::security;

network_credential::network_credential(const xtd::string& user_name, const xtd::security::secure_string& password) : user_name_(user_name), password_(password) {
}

network_credential::network_credential(const xtd::string& user_name, const xtd::string& password) : user_name_(user_name), password_(password.c_str(), password.size()) {
}

network_credential::network_credential(const xtd::string& user_name, const xtd::security::secure_string& password, const xtd::string& domain) : user_name_(user_name), password_(password), domain_(domain) {
}

network_credential::network_credential(const xtd::string& user_name, const xtd::string& password, const xtd::string& domain) : user_name_(user_name), password_(password.c_str(), password.size()), domain_(domain) {
}

const xtd::string& network_credential::domain() const noexcept {
  return domain_;
}

network_credential& network_credential::domain(const xtd::string& value) noexcept {
  domain_ = value;
  return *this;
}

xtd::string network_credential::password() const noexcept {
  return password_.to_unsecure_string();
}

network_credential& network_credential::password(const xtd::string& value) noexcept {
  password_ = secure_string(value.c_str(), value.size());
  return *this;
}

const xtd::security::secure_string& network_credential::secure_password() const noexcept {
  return password_;
}

network_credential& network_credential::secure_password(const xtd::security::secure_string& value) noexcept {
  password_ = value;
  return *this;
}

const xtd::string& network_credential::user_name() const noexcept {
  return user_name_;
}

network_credential& network_credential::user_name(const xtd::string& value) noexcept {
  user_name_ = value;
  return *this;
}
