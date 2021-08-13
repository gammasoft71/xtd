#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/cryptography.h>
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <iostream>
#include <unistd.h>

using namespace std;
using namespace xtd::native;

namespace {
  static std::string create_process(const std::string& command) {
    auto fs = popen(command.c_str(), "r");
    std::string result;
    while (!feof(fs)) {
      char buf[513];
      size_t l = fread(buf, 1, 512, fs);
      buf[l] = 0;
      result += buf;
    }
    pclose(fs);
    return result;
  }
}

vector<uint8_t> cryptography::machine_guid() {
  vector<uint8_t> bytes;
  string guid_str;
#if defined(__APPLE__)
  guid_str = create_process("ioreg -rd1 -c IOPlatformExpertDevice | grep -E '(UUID)'");
  guid_str = guid_str.erase(guid_str.find("\n")).substr(guid_str.find("=") + 2);
#else
  guid_str = create_process("{ uname -n ; cat /proc/meminfo | head -n1 ; cat /proc/cpuinfo ; } | md5sum");
  guid_str = guid_str.erase(guid_str.find("\n"), 2);
#endif
  if (guid_str.empty())
    guid_str = "30395f0e-d6aa-4a5e-b4af-6f90a608c605"; // fallback
  for(auto index = 0U; guid_str[index] != 0; ++index)
    if (guid_str[index] == '-' || guid_str[index] == ' ' || guid_str[index] == '"') guid_str.erase(index, 1);
  cout << "[" << guid_str << "]" << endl;
  for(auto index = 0U; index < guid_str.size(); index += 2)
    bytes.push_back(static_cast<uint8_t>(stoi(guid_str.substr(index, 2), 0, 16)));
  return bytes;
}
