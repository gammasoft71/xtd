#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/cryptography>
#include "../../../../include/xtd/native/macos/shell_execute.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <unistd.h>
#include <cstdint>

using namespace std;
using namespace xtd::native;

vector<uint_least8_t> cryptography::machine_guid() {
  static auto first = true;
  static auto guid_str = macos::shell_execute::run("ioreg", "-rd1 -c IOPlatformExpertDevice | grep -E '(UUID)'");
  if (first) guid_str = guid_str.substr(guid_str.find("=") + 1);
  first = false;
  
  static const auto guid_fallback = string {"30395f0ed6aa4a5eb4af6f90a608c605"};
  static const auto hex_chars = string {"0123456789ABCDEF"};
  for (auto index = 0u; guid_str[index] != 0; ++index)
    if (hex_chars.find(static_cast<char>(toupper(guid_str[index]))) == hex_chars.npos)  guid_str.erase(index--, 1);
  if (guid_str.size() != 32) guid_str = guid_fallback;
  
  auto bytes = vector<uint_least8_t> {};
  for (auto index = 0u; index < guid_str.size(); index += 2)
    bytes.push_back(static_cast<uint_least8_t>(stoi(guid_str.substr(index, 2), 0, 16)));
  return bytes;
}
