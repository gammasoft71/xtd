#if defined(_WIN32)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <Lmcons.h>

#include "../include/xtd/__opaque_environment.hpp"
#include <xtd/strings>

/*
xtd::platform_id __opaque_environment::get_os_platform_id() {
  return System::PlatformID::Win32NT;
}
 */

std::string __opaque_environment::new_line() {
  return "\r\n";
}

std::string __opaque_environment::get_know_folder_path(int id) {
  char path[MAX_PATH + 1];
  return SHGetFolderPath(null, id, null, SHGFP_TYPE_CURRENT, path) == S_OK ? path : L"";
}

int __opaque_environment::get_os_version(int& major, int& minor, int& build, int& revision) {
#pragma warning(push)
#pragma warning(disable : 4996)
  OSVERSIONINFOEX version_info;
  ZeroMemory(&version_info, sizeof(OSVERSIONINFOEX));
  version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  if (GetVersionEx((LPOSVERSIONINFO)&version_info)) {
    major = version_info.dwMajorVersion;
    minor = version_info.dwMinorVersion;
    build = version_info.dwBuildNumber;
    revision = version_info.wServicePackMajor << 16;
  }
#pragma warning(pop)
  return 0;
}

bool __opaque_environment::is_os_64_bit() {
  SYSTEM_INFO system_info;
  GetNativeSystemInfo(&system_info);
  return (system_info.wProcessorArchitecture & (PROCESSOR_ARCHITECTURE_AMD64 | PROCESSOR_ARCHITECTURE_ARM64 | PROCESSOR_ARCHITECTURE_IA64)) != 0;
}

std::string __opaque_environment::get_machine_name() {
  char machine_name[MAX_COMPUTERNAME_LENGTH + 1];
  DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
  if (!GetComputerName(machine_name, &size))
    return "";
  return machine_name;
}

unsigned int __opaque_environment::get_processor_count() {
  SYSTEM_INFO system_info;
  GetNativeSystemInfo(&system_info);
  return system_info.dwNumberOfProcessors;
}

int __opaque_environment::get_system_page_size() {
  SYSTEM_INFO system_info;
  GetNativeSystemInfo(&system_info);
  return system_info.dwPageSize;
}

int __opaque_environment::get_tick_count() {
  return GetTickCount();
}

std::string __opaque_environment::get_user_domain_name() {
  char name[512];
  size_t count = 512;
  _dupenv_s((char**)&name, &count, "USERDOMAIN");
  //strcpy_s(name, 512, getenv("USERDOMAIN"));
  return name;
}

std::string __opaque_environment::get_user_name() {
  char user_name[UNLEN + 1];
  DWORD size = UNLEN + 1;
  if (!GetUserName(user_name, &size))
    return "";
  return user_name;
}

long long __opaque_environment::get_working_set() {
  return 0;
}

int __opaque_environment::set_env(const std::string& name, const std::string& value) {
  return _putenv(xtd::strings::format("{}={}", name, value).c_str());
}

int __opaque_environment::unset_env(const std::string& name) {
  return _putenv(xtd::strings::format("{0}=", name).c_str());
}

xtd::guid __opaque_environment::new_guid() {
  UUID guid;
  UuidCreate(&guid);
  return xtd::guid(guid.Data1, guid.Data2, guid.Data3, std::vector<unsigned char>(guid.Data4, guid.Data4 + 8));
}

#endif
