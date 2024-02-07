#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/cryptography>
#include "../../../../include/xtd/native/win32/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace std;
using namespace xtd::native;

namespace {
  wstring get_machine_guid_str() {
    auto value = wstring(255, '\0');
    auto value_size = static_cast<DWORD>(value.size());
    return RegGetValue(HKEY_LOCAL_MACHINE, L"SOFTWARE\\Microsoft\\Cryptography", L"MachineGuid", RRF_RT_REG_SZ, nullptr, value.data(), &value_size) == 0 ? value : L"";
  }
}

vector<uint_least8_t> cryptography::machine_guid() {
  auto guid_str = win32::strings::to_string(get_machine_guid_str());
  
  static const auto guid_fallback = string {"30395f0ed6aa4a5eb4af6f90a608c605"};
  static const auto hex_chars = string {"0123456789ABCDEF"};
  for (auto index = 0U; guid_str[index] != 0; ++index)
    if (hex_chars.find(static_cast<char>(toupper(guid_str[index]))) == hex_chars.npos)  guid_str.erase(index--, 1);
  if (guid_str.size() != 32) guid_str = guid_fallback;
  
  auto bytes = vector<uint_least8_t> {};
  for (auto index = 0U; index < guid_str.size(); index += 2)
    bytes.push_back(static_cast<uint_least8_t>(stoi(guid_str.substr(index, 2), 0, 16)));
  return bytes;
}
