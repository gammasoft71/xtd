#include "../../../include/xtd/net/network_credential.hpp"

using namespace xtd;
using namespace xtd::net;
using namespace xtd::security;

network_credential::network_credential(const string& user_name, const secure_string& password) : user_name_ {user_name}, password_ {password} {
}

network_credential::network_credential(const string& user_name, const string& password) : user_name_ {user_name}, password_ {password.chars().c_str(), password.length()} {
}

network_credential::network_credential(const string& user_name, const secure_string& password, const string& domain) : user_name_ {user_name}, password_ {password}, domain_ {domain} {
}

network_credential::network_credential(const string& user_name, const string& password, const string& domain) : user_name_ {user_name}, password_ {password.chars().c_str(), password.length()}, domain_ {domain} {
}

auto network_credential::domain() const noexcept -> const string& {
  return domain_;
}

auto network_credential::domain(const string& value) noexcept -> network_credential& {
  domain_ = value;
  return self_;
}

auto network_credential::password() const noexcept -> string {
  return password_.to_unsecure_string();
}

auto network_credential::password(const string& value) noexcept -> network_credential& {
  password_ = secure_string {value.chars().c_str(), value.length()};
  return self_;
}

auto network_credential::secure_password() const noexcept -> const secure_string& {
  return password_;
}

auto network_credential::secure_password(const secure_string& value) noexcept -> network_credential& {
  password_ = value;
  return self_;
}

auto network_credential::user_name() const noexcept -> const string& {
  return user_name_;
}

auto network_credential::user_name(const string& value) noexcept -> network_credential& {
  user_name_ = value;
  return self_;
}
