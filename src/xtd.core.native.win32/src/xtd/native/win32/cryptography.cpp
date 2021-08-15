#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/cryptography.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <Windows.h>

using namespace std;
using namespace xtd::native;

namespace {
  string get_machine_guid_str() {
    char value[255];
    DWORD value_size = sizeof(value);
    return RegGetValueA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Cryptography", "MachineGuid", RRF_RT_REG_SZ, nullptr, value, &value_size) == 0 ? value : "";
  }
}

vector<uint8_t> cryptography::machine_guid() {
  string guid_str = get_machine_guid_str();

  static const string guid_fallback = "30395f0ed6aa4a5eb4af6f90a608c605";
  static const string hex_chars = "0123456789ABCDDEF";
  for(auto index = 0U; guid_str[index] != 0; ++index)
    if (hex_chars.find(toupper(guid_str[index])) == hex_chars.npos)  guid_str.erase(index--, 1);
  if (guid_str.size() != 32) guid_str = guid_fallback;

  vector<uint8_t> bytes;
  for (auto index = 0U; index < guid_str.size(); index += 2)
    bytes.push_back(static_cast<uint8_t>(stoi(guid_str.substr(index, 2), 0, 16)));
  return bytes;
}
