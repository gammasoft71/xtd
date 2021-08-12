#include "../../../include/xtd/security/secure_string.h"
#include "../../../include/xtd/guid.h"
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/cryptography.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

using namespace std;
using namespace xtd;
using namespace xtd::security;

namespace {
  vector<byte_t> encript(const xtd::guid& guid, const char value[], size_t length) {
    // https://kylewbanks.com/blog/Simple-XOR-Encryption-Decryption-in-Cpp
    auto key = guid.to_string("D");
    vector<byte_t> result;
    for (auto index = 0U; index < length; ++index)
      result.push_back(value[index] != key[index % key.size()] ? value[index] ^ key[index % key.size()] : value[index]);
    return result;
  }

  ustring decript(const xtd::guid& guid, const byte_t value[], size_t length) {
    // https://kylewbanks.com/blog/Simple-XOR-Encryption-Decryption-in-Cpp
    return ustring(reinterpret_cast<const char*>(encript(guid, reinterpret_cast<const char*>(value), length).data()));
  }
}

secure_string::secure_string(const char value[], size_t length) {
  if (value == nullptr) return;
  guid machine_guid(native::cryptography::machine_guid());
  data_ = encript(guid(native::cryptography::machine_guid()), value, length);
}

bool secure_string::empty() const noexcept {
  return data_.size() == 0;
}

intptr_t secure_string::data() const noexcept {
  return reinterpret_cast<intptr_t>(data_.data());
}

size_t secure_string::size() const noexcept {
  return data_.size();
}

std::string secure_string::to_unsecure_string() const noexcept {
  if (empty()) return "";
  return decript(guid(native::cryptography::machine_guid()), data_.data(), data_.size());
}
