#include "../../../include/xtd/security/secure_string.hpp"
#include "../../../include/xtd/guid.hpp"
#include "../../../include/xtd/literals.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/cryptography>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::security;

namespace {
  std::vector<xtd::byte> encrypt(const xtd::guid& guid, const char value[], size_t length) {
    // https://www.programmingalgorithms.com/algorithm/xor-encryption/
    auto key = guid.to_string("D");
    auto result = std::vector<xtd::byte> {};
    for (auto index = 0_z; index < length; ++index)
      result.push_back(value[index] != key[index % key.size()] ? value[index] ^ key[index % key.size()] : value[index]);
    return result;
  }
  
  string decrypt(const xtd::guid& guid, const xtd::byte value[], size_t length) {
    // https://www.programmingalgorithms.com/algorithm/xor-encryption/
    return string {reinterpret_cast<const char*>(encrypt(guid, reinterpret_cast<const char*>(value), length).data()), length};
  }
}

secure_string::secure_string(const char value[], size_t length) {
  if (value == nullptr) return;
  data_ = encrypt(guid(native::cryptography::machine_guid()), value, length);
}

bool secure_string::empty() const noexcept {
  return data_.size() == 0;
}

intptr secure_string::data() const noexcept {
  return reinterpret_cast<intptr>(data_.data());
}

size_t secure_string::size() const noexcept {
  return data_.size();
}

std::string secure_string::to_unsecure_string() const noexcept {
  if (empty()) return "";
  return decrypt(guid(native::cryptography::machine_guid()), data_.data(), data_.size());
}
