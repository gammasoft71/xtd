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

string __opaque_environment::new_line() {
  return "\r\n";
}

int __opaque_environment::get_os_version(int& major, int& minor, int& build, int& revision) {
#pragma warning(push)
#pragma warning(disable : 4996)
  OSVERSIONINFOEX versionInfo;
  ZeroMemory(&versionInfo, sizeof(OSVERSIONINFOEX));
  versionInfo.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  if (GetVersionEx((LPOSVERSIONINFO)&versionInfo)) {
    major = versionInfo.dwMajorVersion;
    minor = versionInfo.dwMinorVersion;
    build = versionInfo.dwBuildNumber;
    revision = versionInfo.wServicePackMajor << 16;
  }
#pragma warning(pop)
  return 0;
}

bool __opaque_environment::is_os_64_bit() {
  SYSTEM_INFO systemInfo;
  GetNativeSystemInfo(&systemInfo);
  return (systemInfo.wProcessorArchitecture & (PROCESSOR_ARCHITECTURE_AMD64 | PROCESSOR_ARCHITECTURE_ARM64 | PROCESSOR_ARCHITECTURE_IA64)) != 0;
}

std::string __opaque_environment::get_machine_name() {
  wchar machineName[MAX_COMPUTERNAME_LENGTH + 1];
  DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
  if (!GetComputerName(machineName, &size))
    return "";
  return machineName;
}

int __opaque_environment::get_processor_count() {
  SYSTEM_INFO systemInfo;
  GetNativeSystemInfo(&systemInfo);
  return systemInfo.dwNumberOfProcessors;
}

int __opaque_environment::get_system_page_size() {
  SYSTEM_INFO systemInfo;
  GetNativeSystemInfo(&systemInfo);
  return systemInfo.dwPageSize;
}

int __opaque_environment::get_tick_count() {
  return GetTickCount();
}

std::string __opaque_environment::get_user_domain_name() {
  char name[512];
  strcpy_s(name, 512, getenv("USERDOMAIN"));
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
