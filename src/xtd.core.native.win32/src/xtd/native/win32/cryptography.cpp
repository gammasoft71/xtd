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
    return RegGetValueA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Cryptography", "MachineGuid", RRF_RT_REG_SZ, nulllptr, value, &value_size) == 0 ? value : "";
  }
}

vector<uint8_t> cryptography::machine_guid() {
  vector<uint8_t> bytes;
  string guid_str = get_machine_guid_str();
  if (guid_str.empty())
    guid_str = "30395f0e-d6aa-4a5e-b4af-6f90a608c605"; // fallback
  for(auto index = 0U; guid_str[index] != 0; ++index)
    if (guid_str[index] == '-') guid_str.erase(index, 1);
  for (auto index = 0U; index < guid_str.size(); index += 2)
    bytes.push_back(static_cast<uint8_t>(stoi(guid_str.substr(index, 2), 0, 16)));
  return bytes;
}
