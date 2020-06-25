#if defined(_WIN32)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <direct.h>
#include <shlobj.h>
#include <windows.h>
#include <Lmcons.h>

#include "../include/xtd/__opaque_environment.h"
#include <xtd/xtd.strings>

std::string __opaque_environment::get_current_directory() noexcept {
  char path[MAX_PATH + 1];
  return _getcwd(path, MAX_PATH) ? path : "";
}

std::string __opaque_environment::get_desktop_environment() noexcept {
  return "windows";
}

std::string __opaque_environment::get_environment_variable(const std::string& variable) noexcept {
  size_t size = 0;
  getenv_s(&size, NULL, 0, variable.c_str());
  std::string value(size-1, 0);
  getenv_s(&size, value.data(), size, variable.c_str());
  return value;
}

std::string __opaque_environment::get_know_folder_path(int id) noexcept {
  char path[MAX_PATH + 1];
  return SHGetFolderPath(nullptr, id, nullptr, SHGFP_TYPE_CURRENT, path) == S_OK ? path : "";
}

std::string __opaque_environment::get_machine_name() noexcept {
  char machine_name[MAX_COMPUTERNAME_LENGTH + 1];
  DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
  if (!GetComputerName(machine_name, &size))
    return "";
  return machine_name;
}

xtd::platform_id __opaque_environment::get_os_platform_id() noexcept {
  return xtd::platform_id::win32_nt;
}

int __opaque_environment::get_os_version(int& major, int& minor, int& build, int& revision) noexcept {
#pragma warning(push)
#pragma warning(disable : 4996)
  OSVERSIONINFOEX version_info;
  ZeroMemory(&version_info, sizeof(OSVERSIONINFOEX));
  version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  if (GetVersionEx((LPOSVERSIONINFO)&version_info)) {
    major = version_info.dwMajorVersion;
    minor = version_info.dwMinorVersion;
    build = version_info.dwBuildNumber;
    revision = (version_info.wServicePackMajor << 16) | version_info.wServicePackMinor;
  }
#pragma warning(pop)
  return 0;
}

std::string __opaque_environment::get_service_pack() noexcept {
#pragma warning(push)
#pragma warning(disable : 4996)
  OSVERSIONINFOEX version_info;
  ZeroMemory(&version_info, sizeof(OSVERSIONINFOEX));
  version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  if (GetVersionEx((LPOSVERSIONINFO)&version_info))
    return version_info.szCSDVersion;
#pragma warning(pop)
  return "";
}

unsigned int __opaque_environment::get_processor_count() noexcept {
  SYSTEM_INFO system_info;
  GetNativeSystemInfo(&system_info);
  return system_info.dwNumberOfProcessors;
}

size_t __opaque_environment::get_system_page_size() noexcept {
  SYSTEM_INFO system_info;
  GetNativeSystemInfo(&system_info);
  return system_info.dwPageSize;
}

unsigned int __opaque_environment::get_tick_count() noexcept {
  return GetTickCount();
}

std::string __opaque_environment::get_user_domain_name() noexcept {
  char name[512];
  size_t count = 512;
  _dupenv_s((char**)&name, &count, "USERDOMAIN");
  //strcpy_s(name, 512, getenv("USERDOMAIN"));
  return name;
}

std::string __opaque_environment::get_user_name() noexcept {
  char user_name[UNLEN + 1];
  DWORD size = UNLEN + 1;
  if (!GetUserName(user_name, &size))
    return "";
  return user_name;
}

bool __opaque_environment::is_os_64_bit() noexcept {
  SYSTEM_INFO system_info;
  GetNativeSystemInfo(&system_info);
  return (system_info.wProcessorArchitecture & (PROCESSOR_ARCHITECTURE_AMD64 | PROCESSOR_ARCHITECTURE_ARM64 | PROCESSOR_ARCHITECTURE_IA64)) != 0;
}

xtd::guid __opaque_environment::new_guid() noexcept {
  UUID guid;
  UuidCreate(&guid);
  return xtd::guid(guid.Data1, guid.Data2, guid.Data3, std::vector<unsigned char>(guid.Data4, guid.Data4 + 8));
}

std::string __opaque_environment::new_line() noexcept {
  return "\n";
}

int __opaque_environment::set_current_directory(const std::string& directory_name) noexcept {
  return _chdir(directory_name.c_str());
}

int __opaque_environment::set_env(const std::string& name, const std::string& value) noexcept {
  return _putenv(xtd::strings::format("{}={}", name, value).c_str());
}

int __opaque_environment::unset_env(const std::string& name) noexcept {
  return _putenv(xtd::strings::format("{0}=", name).c_str());
}

#endif
