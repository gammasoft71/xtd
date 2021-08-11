#include "../../../include/xtd/net/network_credential.h"

using namespace std;
using namespace xtd;
using namespace xtd::net;

//network_credential::network_credential(const xtd::ustring& user_name, const xtd::security::secure_string& password) : user_name_(user_name), password_(password) {
//}

network_credential::network_credential(const xtd::ustring& user_name, const xtd::ustring& password) : user_name_(user_name), password_(password) {
}

//network_credential::network_credential(const xtd::ustring& user_name, const xtd::security::secure_string& password, const xtd::ustring& domain) : user_name_(user_name), password_(password), domain_(domain) {
//}

network_credential::network_credential(const xtd::ustring& user_name, const xtd::ustring& password, const xtd::ustring& domain) : user_name_(user_name), password_(password), domain_(domain) {
}

const xtd::ustring& network_credential::domain() const noexcept {
  return domain_;
}

network_credential& network_credential::domain(const xtd::ustring& value) noexcept {
  domain_ = value;
  return *this;
}

xtd::ustring network_credential::password() const noexcept {
  return password_;
}

network_credential& network_credential::password(const xtd::ustring& value) noexcept {
  password_ = value;
  return *this;
}

const xtd::security::secure_string& network_credential::secure_password() const noexcept {
  return password_;
}

network_credential& network_credential::secure_password(const xtd::security::secure_string& value) noexcept {
  password_ = value;
  return *this;
}

const xtd::ustring& network_credential::user_name() const noexcept {
  return user_name_;
}

network_credential& network_credential::user_name(const xtd::ustring& value) noexcept {
  user_name_ = value;
  return *this;
}
