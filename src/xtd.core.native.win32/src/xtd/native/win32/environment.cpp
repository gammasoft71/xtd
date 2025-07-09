#define NOMINMAX
#define UNICODE
#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment>
#include <xtd/native/constant_special_item_id_list>
#include "../../../../include/xtd/native/win32/strings.hpp"
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

using namespace std;
using namespace xtd::native;

auto __machine_envs__ = map<string, string> {};
auto __none_envs__ = map<string, string> {};
auto __process_envs__ = map<string, string> {};
auto __user_envs__ = map<string, string> {};

namespace {
  void get_windows_version(int32_t& major, int32_t& minor, int32_t& build, int32_t& revision) {
    // GetVersionEx (https://docs.microsoft.com/en-us/windows/win32/api/sysinfoapi/nf-sysinfoapi-getversionexa) allows you to get the version for a Windows 8 at most. For Windows 10 and more see :
    // https://stackoverflow.com/questions/32115255/c-how-to-detect-windows-10
    NTSTATUS(WINAPI * RtlGetVersion)(LPOSVERSIONINFOEXW);
    auto os_info = OSVERSIONINFOEXW {};
    
    *reinterpret_cast<FARPROC*>(&RtlGetVersion) = GetProcAddress(GetModuleHandleA("ntdll"), "RtlGetVersion");
    if (RtlGetVersion != nullptr) {
      os_info.dwOSVersionInfoSize = sizeof(os_info);
      RtlGetVersion(&os_info);
      major = os_info.dwMajorVersion;
      minor = os_info.dwMinorVersion;
      build = os_info.dwBuildNumber;
      revision = (os_info.wServicePackMajor << 10) | os_info.wServicePackMinor;
    } else {
#pragma warning(push)
#pragma warning(disable : 4996)
      auto version_info = OSVERSIONINFOEX {};
      version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
      if (GetVersionEx((LPOSVERSIONINFO)&version_info)) {
        major = version_info.dwMajorVersion;
        minor = version_info.dwMinorVersion;
        build = version_info.dwBuildNumber;
        revision = (version_info.wServicePackMajor << 16) | version_info.wServicePackMinor;
      }
#pragma warning(pop)
    }
  }
  
  tuple<string, string, string> get_windows_information() {
    // https://en.wikipedia.org/wiki/List_of_Microsoft_Windows_versions
    auto major = -1, minor = -1, build = -1, revision = -1;
    get_windows_version(major, minor, build, revision);
    if (build >= 26100) return make_tuple("Windows 11", "Germanium", "24H2");
    if (build >= 22631) return make_tuple("Windows 11", "Sun Valley 2", "23H2");
    if (build >= 22621) return make_tuple("Windows 11", "Sun Valley 2", "22H2");
    if (build >= 22000) return make_tuple("Windows 11", "Sun Valley", "21H2");
    if (build >= 19045) return make_tuple("Windows 10", "Vibranium", "22H2");
    if (build >= 19044) return make_tuple("Windows 10", "Vibranium", "21H2");
    if (build >= 19043) return make_tuple("Windows 10", "Vibranium", "21H1");
    if (build >= 19042) return make_tuple("Windows 10", "Vibranium", "20H2");
    if (build >= 19041) return make_tuple("Windows 10", "Vibranium", "2004");
    if (build >= 18363) return make_tuple("Windows 10", "Vanadium", "1909");
    if (build >= 18362) return make_tuple("Windows 10", "19H1", "1903");
    if (build >= 17763) return make_tuple("Windows 10", "Redstone 5", "1809");
    if (build >= 17134) return make_tuple("Windows 10", "Redstone 4", "1803");
    if (build >= 16299) return make_tuple("Windows 10", "Redstone 3", "1709");
    if (build >= 15063) return make_tuple("Windows 10", "Redstone 2", "1703");
    if (build >= 14393) return make_tuple("Windows 10", "Redstone 1", "1607");
    if (build >= 10586) return make_tuple("Windows 10", "Threshold 2", "1511");
    if (build >= 10240) return make_tuple("Windows 10", "Threshold", "1507");
    if (build >= 9600) return make_tuple("Windows 8.1", "Blue", "");
    if (build >= 9200) return make_tuple("Windows 8", "Windows 8", "");
    if (build >= 7601) return make_tuple("Windows 7", "Windows 7", "");
    if (build >= 6002) return make_tuple("Windows Vista", "Longhorn", "");
    if (build >= 3790) return make_tuple("Windows XP", "Anvil", "");
    if (build >= 3000) return make_tuple("Windows Me", "Millennium", "");
    if (build >= 2710) return make_tuple("Windows XP", "Emerald", "");
    if (build >= 2700) return make_tuple("Windows XP", "Symphony", "");
    if (build >= 2600) return make_tuple("Windows XP", "Whistler", "");
    if (build >= 2222) return make_tuple("Windows Windows 98 Second Edition", "", "");
    if (build >= 2195) return make_tuple("Windows 2000", "Windows NT 5.0", "");
    if (build >= 1998) return make_tuple("Windows Windows 98", "Memphis", "");
    if (build >= 1381) return make_tuple("Windows NT 4.0", "Shell Update Release", "");
    if (build >= 1057) return make_tuple("Windows NT 3.51", "Daytona", "");
    if (build >= 950) return make_tuple("Windows 95", "Chicago", "");
    if (build >= 807) return make_tuple("Windows NT 3.5", "Daytona", "");
    if (build >= 528) return make_tuple("Windows NT 3.1", "Razzle", "");
    if (build >= 300) return make_tuple("Windows 3.11", "Snowball", "");
    if (build >= 153) return make_tuple("Windows 3.2", "", "");
    if (build >= 103) return make_tuple("Windows 3.1", "", "");
    if (build >= 102) return make_tuple("Windows 3.1", "Sparta", "");
    return {"Windows", "", ""};
  }
}

int32_t environment::at_quick_exit(void (*on_quick_exit)(void)) {
  return std::at_quick_exit(on_quick_exit);
}

vector<string> environment::get_command_line_args() {
  auto argc = 0;
  auto argv = CommandLineToArgvW(GetCommandLine(), &argc);
  if (argv == nullptr || argc == 0) return {"a.exe"};
  auto args = vector<string> {};
  for (auto index = 0; index < argc; ++index)
    args.push_back(win32::strings::to_string(argv[index]));
  LocalFree(argv);
  return args;
}

string environment::get_desktop_environment() {
  return "windows";
}

string environment::get_desktop_theme() {
  auto value = DWORD {};
  auto value_size = static_cast<DWORD>(sizeof(value));
  if (RegGetValue(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize", L"AppsUseLightTheme", RRF_RT_REG_DWORD, nullptr, &value, &value_size) != ERROR_SUCCESS)
    value = 0;
  return value == 0 ? "windows" : "windows dark";
}

string environment::get_distribution_bug_report() {
  return "https://support.microsoft.com/windows";
}

string environment::get_distribution_code_name() {
  auto [name, code_name, version] = get_windows_information();
  return code_name;
}

string environment::get_distribution_description() {
  auto [name, code_name, version] = get_windows_information();
  auto major = -1, minor = -1, build = -1, revision = -1;
  get_os_version(major, minor, build, revision);
  return name + " " + version + (version.empty() ? "" : " ") + to_string(major) + "." + to_string(minor) + "." + to_string(build);
}

string environment::get_distribution_home() {
  return "https://www.microsoft.com/windows";
}

string environment::get_distribution_id() {
  return "windows";
}

vector<string> environment::get_distribution_like_ids() {
  return {"windows"};
}

string environment::get_distribution_name() {
  auto [name, code_name, version] = get_windows_information();
  return name;
}

void environment::get_distribution_version(int32_t& major, int32_t& minor, int32_t& build, int32_t& revision) {
  auto dummy = -1;
  get_os_version(major, minor, build, dummy);
}

string environment::get_distribution_version_string() {
  auto [name, code_name, version] = get_windows_information();
  auto version_string = string("");
  auto major = -1, minor = -1, build = -1, revision = -1;
  get_distribution_version(major, minor, build, revision);
  
  return version + (version.empty() ? "" : " ") + to_string(major) + "." + to_string(minor) + "." + to_string(build) + (code_name.empty() ? "" : " (" + code_name + ")");
}

string environment::get_environment_variable(const string& variable, int32_t target) {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS) {
    auto environent_variable_size = DWORD {65535};
    auto environment_variable = wstring(environent_variable_size, '\0');
    environent_variable_size = GetEnvironmentVariable(win32::strings::to_wstring(variable).data(), environment_variable.data(), environent_variable_size);
    if (!environent_variable_size) return "";
    return win32::strings::to_string(environment_variable);
  }  else if (target == ENVIRONMENT_VARIABLE_TARGET_USER) {
    /// @todo Get registry value
    return "";
  } if (target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    /// @todo Get registry value
    return "";
  }
  return "";
}

map<string, string>& environment::get_environment_variables(int32_t target) {
  auto& envs = __none_envs__;
  
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS) {
    auto environments = std::vector<std::string> {};
    for (auto line = GetEnvironmentStrings(); line[0] != 0; line += wcslen(line) + 1)
      environments.push_back(win32::strings::to_string(line));
      
    envs = __process_envs__;
    envs.clear();
    
    for (auto environment : environments) {
      auto key_value = win32::strings::split(environment, { '=' });
      if (key_value.size() == 2) envs.insert({ key_value[0], key_value[1] });
    }
    return envs;
  }
  
  if (target == ENVIRONMENT_VARIABLE_TARGET_USER || target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    envs = target == ENVIRONMENT_VARIABLE_TARGET_USER ? __user_envs__ : __machine_envs__;
    envs.clear();
    
    auto root_key = target == ENVIRONMENT_VARIABLE_TARGET_USER ? HKEY_CURRENT_USER : HKEY_LOCAL_MACHINE;
    auto sub_key = wstring {target == ENVIRONMENT_VARIABLE_TARGET_USER ? L"Environment" : L"System\\CurrentControlSet\\Control\\Session Manager\\Environment"};
    auto environment_key = HKEY {};
    auto result = RegOpenKeyEx(root_key, sub_key.data(), 0, KEY_READ, &environment_key);
    if (result != ERROR_SUCCESS || environment_key == 0) return envs;
    
    for (DWORD index = 0; result != ERROR_NO_MORE_ITEMS; ++index) {
      auto value_size = DWORD {32767};
      auto value = wstring(value_size, '\0');
      auto data_type = DWORD {REG_EXPAND_SZ};
      auto data_size = DWORD {65535};
      auto data = wstring(data_size, 0);
      result = RegEnumValue(environment_key, index, value.data(), &value_size, nullptr, &data_type, reinterpret_cast<LPBYTE>(data.data()), &data_size);
      if (value[0] != 0) envs.insert({ win32::strings::to_string(value), win32::strings::to_string(data)});
    }
    
    RegCloseKey(environment_key);
    return envs;
  }
  return envs;
}

string environment::get_know_folder_path(int32_t id) {
  if (id == CSIDL_HOME)
    return get_environment_variable("HOMEDRIVE", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + get_environment_variable("HOMEPATH", ENVIRONMENT_VARIABLE_TARGET_PROCESS);
  auto path = wstring(65535, '\0');
  return SHGetFolderPath(nullptr, id, nullptr, SHGFP_TYPE_CURRENT, path.data()) == S_OK ? win32::strings::to_string(path) : "";
}

string environment::get_machine_name() {
  auto machine_name = wstring(MAX_COMPUTERNAME_LENGTH, '\0');
  auto size = DWORD {MAX_COMPUTERNAME_LENGTH};
  if (!GetComputerName(machine_name.data(), &size))
    return "";
  return win32::strings::to_string(machine_name);
}

int32_t environment::get_os_platform_id() {
  return PLATFORM_WIN32_NT;
}

void environment::get_os_version(int32_t& major, int32_t& minor, int32_t& build, int32_t& revision) {
  return get_windows_version(major, minor, build, revision);
}

uint32_t environment::get_processor_count() {
  auto system_info = SYSTEM_INFO {};
  GetNativeSystemInfo(&system_info);
  return system_info.dwNumberOfProcessors;
}

std::string environment::get_resources_path(bool gui_app) {
  auto app_path = get_command_line_args()[0];
  auto pos = app_path.rfind('\\');
  return (pos == app_path.npos ? "" : app_path.substr(0, pos) + '\\') + "resources";
}

string environment::get_service_pack() {
#pragma warning(push)
#pragma warning(disable : 4996)
  auto version_info = OSVERSIONINFOEX {};
  version_info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
  if (GetVersionEx((LPOSVERSIONINFO)&version_info))
    return win32::strings::to_string(version_info.szCSDVersion);
#pragma warning(pop)
  return "";
}

size_t environment::get_system_page_size() {
  auto system_info = SYSTEM_INFO {};
  GetNativeSystemInfo(&system_info);
  return system_info.dwPageSize;
}

uint32_t environment::get_tick_count() {
  return GetTickCount();
}

bool environment::get_user_administrator() {
  return IsUserAnAdmin();
}

string environment::get_user_domain_name() {
  auto name = getenv("USERDOMAIN");
  return name ? name : "";
}

string environment::get_user_name() {
  auto user_name = wstring(UNLEN, '\0');
  auto size = DWORD {UNLEN};
  if (!GetUserName(user_name.data(), &size))
    return "";
  return win32::strings::to_string(user_name);
}

bool environment::has_shutdown_started() {
  auto result = SendMessageTimeout(HWND_BROADCAST, WM_QUERYENDSESSION, 0, (LPARAM)ENDSESSION_LOGOFF, SMTO_ABORTIFHUNG, 5000, NULL);
  return result == FALSE;
}

bool environment::is_processor_arm() {

  auto system_info = SYSTEM_INFO {};
  GetNativeSystemInfo(&system_info);
  if ((system_info.wProcessorArchitecture & PROCESSOR_ARCHITECTURE_ARM) == PROCESSOR_ARCHITECTURE_ARM) return true;
  if ((system_info.wProcessorArchitecture & PROCESSOR_ARCHITECTURE_ARM64) == PROCESSOR_ARCHITECTURE_ARM64) return true;
  return false;
}

bool environment::is_os_64_bit() {
  auto system_info = SYSTEM_INFO {};
  GetNativeSystemInfo(&system_info);
  if ((system_info.wProcessorArchitecture & PROCESSOR_ARCHITECTURE_AMD64) == PROCESSOR_ARCHITECTURE_AMD64) return true;
  if ((system_info.wProcessorArchitecture & PROCESSOR_ARCHITECTURE_ARM64) == PROCESSOR_ARCHITECTURE_ARM64) return true;
  if ((system_info.wProcessorArchitecture & PROCESSOR_ARCHITECTURE_IA64) == PROCESSOR_ARCHITECTURE_IA64) return true;
  return false;
}

string environment::new_line() {
  return "\n";
}

void environment::quick_exit(int32_t exit_code) noexcept {
  std::quick_exit(exit_code);
}

void environment::set_environment_variable(const string& name, const string& value, int32_t target) {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS)
    SetEnvironmentVariable(win32::strings::to_wstring(name).c_str(), win32::strings::to_wstring(value).c_str());
  else if (target == ENVIRONMENT_VARIABLE_TARGET_USER) {
    /// @todo Set registry value when implmented ???
  } if (target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    /// @todo Set registry value when implmented ???
  }
}

void environment::unset_environment_variable(const string& name, int32_t target) {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS)
    SetEnvironmentVariable(win32::strings::to_wstring(name).c_str(), nullptr);
  else if (target == ENVIRONMENT_VARIABLE_TARGET_USER) {
    /// @todo Unset registry value
  } if (target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    /// @todo Unset registry value
  }
}

int64_t environment::working_set() {
  return 0;
}
