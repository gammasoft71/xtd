#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment.h>
#undef __XTD_CORE_NATIVE_LIBRARY__

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <direct.h>
#include <shlobj.h>
#include <windows.h>
#include <Lmcons.h>

using namespace xtd::native;

#undef min
#undef max

__declspec(dllimport) extern char** environ;
__declspec(dllimport) extern int __argc;
__declspec(dllimport) extern char** __argv;
int __environment_argc = __argc;
char** __environment_argv = __argv;

std::vector<std::string> environment::get_command_line_args() {
  return {__environment_argv, __environment_argv + __environment_argc};
}

std::string environment::get_desktop_environment() {
  return "windows";
}

std::string environment::get_environment_variable(const std::string& variable) {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS) {
    static std::map<std::string, std::string> envs;
    if (envs.size() == 0) {
      for (size_t index = 0; environ[index] != nullptr; index++) {
        std::vector<std::string> key_value = unix::strings::split(environ[index], {'='});
        if (key_value.size() == 2)
          envs[key_value[0]] = key_value[1];
      }
    }
    return envs;
  }
  
  if(target == ENVIRONMENT_VARIABLE_TARGET_USER || target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    static std::map<std::string, std::string> envs;
    envs.clear();
    //microsoft::win32::registry_key key = target == environment_variable_target::user ? microsoft::win32::registry::current_user().create_sub_key("Environment") : microsoft::win32::registry::local_machine().create_sub_key("System").create_sub_key("CurrentControlSet").create_sub_key("Control").create_sub_key("Session Manager").create_sub_key("Environment");
    //for (auto name : key.get_value_names())
    //  envs[name] = key.get_value(name).to_string();
    return envs;
  }
  
  static std::map<std::string, std::string> envs;
  return envs;
}

std::string environment::get_know_folder_path(int32_t id) {
  char path[MAX_PATH + 1];
  return SHGetFolderPath(nullptr, id, nullptr, SHGFP_TYPE_CURRENT, path) == S_OK ? path : "";
}

std::string environment::get_machine_name() {
  char machine_name[MAX_COMPUTERNAME_LENGTH + 1];
  DWORD size = MAX_COMPUTERNAME_LENGTH + 1;
  if (!GetComputerName(machine_name, &size))
    return "";
  return machine_name;
}

int32_t environment::get_os_platform_id() {
  return PLATFORM_WIN32_NT;
}

void environment::get_os_version(int32_t& major, int32_t& minor, int32_t& build, int32_t& revision) {
#pragma warning(push)
#pragma warning(disable : 4996)
  OSVERSIONINFOEX version_info {};
  version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  if (GetVersionEx((LPOSVERSIONINFO)&version_info)) {
    major = version_info.dwMajorVersion;
    minor = version_info.dwMinorVersion;
    build = version_info.dwBuildNumber;
    revision = (version_info.wServicePackMajor << 16) | version_info.wServicePackMinor;
  }
#pragma warning(pop)
}

std::string environment::get_service_pack() {
#pragma warning(push)
#pragma warning(disable : 4996)
  OSVERSIONINFOEX version_info {};
  version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  if (GetVersionEx((LPOSVERSIONINFO)&version_info))
    return version_info.szCSDVersion;
#pragma warning(pop)
  return "";
}

uint32_t environment::get_processor_count() {
  SYSTEM_INFO system_info {};
  GetNativeSystemInfo(&system_info);
  return system_info.dwNumberOfProcessors;
}

size_t environment::get_system_page_size() {
  SYSTEM_INFO system_info {};
  GetNativeSystemInfo(&system_info);
  return system_info.dwPageSize;
}

uint32_t environment::get_tick_count() {
  return GetTickCount();
}

std::string environment::get_user_domain_name() {
  auto name = getenv("USERDOMAIN");
  return name ? name : "";
}

std::string environment::get_user_name() {
  char user_name[UNLEN + 1];
  DWORD size = UNLEN + 1;
  if (!GetUserName(user_name, &size))
    return "";
  return user_name;
}

bool environment::is_processor_arm() {
  SYSTEM_INFO system_info {};
  GetNativeSystemInfo(&system_info);
  return (system_info.wProcessorArchitecture & (PROCESSOR_ARCHITECTURE_ARM | PROCESSOR_ARCHITECTURE_ARM64)) != 0;
}

bool environment::is_os_64_bit() {
  SYSTEM_INFO system_info {};
  GetNativeSystemInfo(&system_info);
  return (system_info.wProcessorArchitecture & (PROCESSOR_ARCHITECTURE_AMD64 | PROCESSOR_ARCHITECTURE_ARM64 | PROCESSOR_ARCHITECTURE_IA64)) != 0;
}

std::string environment::new_line() {
  return "\n";
}

void environment::set_environment_variable(const std::string& name, const std::string& value) {
  _putenv((name + "=" + value).c_str());
}

void environment::unset_environment_variable(const std::string& name) {
  _putenv((name+ "=").c_str());
}
