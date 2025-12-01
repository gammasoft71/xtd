#include "../../../include/xtd/security/secure_string.hpp"
#include "../../../include/xtd/collections/generic/list.hpp"
#include "../../../include/xtd/guid.hpp"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/cryptography>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace xtd;
using namespace xtd::collections::generic;
using namespace xtd::security;

namespace {
  list<byte> encrypt(const xtd::guid& guid, const char value[], size_t length) {
    // https://www.programmingalgorithms.com/algorithm/xor-encryption/
    auto key = guid.to_string("D");
    auto result = list<xtd::byte> {};
    for (auto index = 0_z; index < length; ++index)
      result.add(value[index] != key[index % key.length()] ? value[index] ^ key[index % key.length()] : value[index]);
    return result;
  }
  
  string decrypt(const xtd::guid& guid, const xtd::byte value[], size_t length) {
    // https://www.programmingalgorithms.com/algorithm/xor-encryption/
    return string {reinterpret_cast<const char*>(encrypt(guid, reinterpret_cast<const char*>(value), length).data()), length};
  }
}

secure_string::secure_string(const char value[], size_t length) {
  if (value == nullptr) return;
  data_ = encrypt(guid(native::cryptography::machine_guid()), value, length).to_array();
}

bool secure_string::empty() const noexcept {
  return data_.length() == 0;
}

intptr secure_string::data() const noexcept {
  return reinterpret_cast<intptr>(data_.data());
}

size_t secure_string::length() const noexcept {
  return data_.length();
}

size_t secure_string::size() const noexcept {
  return length();
}

std::string secure_string::to_unsecure_string() const noexcept {
  if (empty()) return "";
  return decrypt(guid(native::cryptography::machine_guid()), data_.data(), data_.length());
}
