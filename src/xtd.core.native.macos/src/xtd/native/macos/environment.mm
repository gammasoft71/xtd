#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment>
#include "../../../../include/xtd/native/macos/strings.hpp"
#include "../../../../include/xtd/native/macos/shell_execute.hpp"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstdio>
#include <cstdlib>
#include <map>
#include <numeric>
#include <thread>
#include <TargetConditionals.h>
#include <time.h>
#include <crt_externs.h>
#include <mach-o/dyld.h>
#include <sys/sysctl.h>
#include <sys/param.h>
#include <unistd.h>

// Macros defined in mach-o/loader.h included by mach-o/dyld.h.
#undef PLATFORM_UNKNOWN
#undef PLATFORM_MACOS
#undef PLATFORM_IOS
#undef PLATFORM_TVOS
#undef PLATFORM_WATCHOS
#undef PLATFORM_BRIDGEOS
#undef PLATFORM_VISIONOS

using namespace std;
using namespace xtd::native;

namespace {
  auto macos_information() -> tuple<string, string, string> {
    // https://en.wikipedia.org/wiki/MacOS_version_history
    static auto build_version = string {};
    static auto codename = string {};
    static auto major = -1;
    static auto minor = -1;
    static auto name = string {"macOS"};
    static auto version = string {};
    
    if (version.empty()) {
      try {
        codename = xtd::native::macos::strings::replace(macos::shell_execute::run("awk", "'/SOFTWARE LICENSE AGREEMENT FOR macOS/' '/System/Library/CoreServices/Setup Assistant.app/Contents/Resources/en.lproj/OSXSoftwareLicense.rtf' | awk -F 'macOS ' '{print $NF}' | awk '{print substr($0, 0, length($0)-1)}'"), "\n", "");
        auto distribution_string = macos::shell_execute::run("sw_vers");
        auto distribution_lines = xtd::native::macos::strings::split(distribution_string, {'\n'});
        for (auto distribution_line : distribution_lines) {
          auto key_value = xtd::native::macos::strings::split(distribution_line, {'\t'});
          if (key_value[0] == "BuildVersion:") build_version = key_value[key_value.size() - 1];
          if (key_value[0] == "ProductVersion:") version = key_value[key_value.size() - 1];
        }
        auto versions = xtd::native::macos::strings::split(version, {'.'});
        if (versions.size() == 2) {
          major = stoi(versions[0]);
          minor = stoi(versions[1]);
        }
      } catch (...) {
      }
    }
    
    if (major == 26) return make_tuple("macOS", "Tahoe", version);
    if (major == 15) return make_tuple("macOS", "Sequoia", version);
    if (major == 14) return make_tuple("macOS", "Sonoma", version);
    if (major == 13) return make_tuple("macOS", "Ventura", version);
    if (major == 12) return make_tuple("macOS", "Monterey", version);
    if (major == 11) return make_tuple("macOS", "Big Sur", version);
    if (major == 10 && minor == 15) return make_tuple("macOS", "Catalina", version);
    if (major == 10 && minor == 14) return make_tuple("macOS", "Mojave", version);
    if (major == 10 && minor == 13) return make_tuple("macOS", "High Sierra", version);
    if (major == 10 && minor == 12) return make_tuple("macOS", "Sierra", version);
    if (major == 10 && minor == 11) return make_tuple("OS X", "El Capitan", version);
    if (major == 10 && minor == 10) return make_tuple("OS X", "Yosemite", version);
    if (major == 10 && minor == 9) return make_tuple("OS X", "Mavericks", version);
    if (major == 10 && minor == 8) return make_tuple("OS X", "Montain Lion", version);
    if (major == 10 && minor == 7) return make_tuple("OS X", "Lion", version);
    if (major == 10 && minor == 6) return make_tuple("OS X", "Snow Leopard", version);
    if (major == 10 && minor == 5) return make_tuple("OS X", "Leopard", version);
    if (major == 10 && minor == 4) return make_tuple("OS X", "Tiger", version);
    if (major == 10 && minor == 3) return make_tuple("OS X", "Panther", version);
    if (major == 10 && minor == 2) return make_tuple("OS X", "Jaguar", version);
    if (major == 10 && minor == 1) return make_tuple("OS X", "Puma", version);
    if (major == 10 && minor == 0) return make_tuple("OS X", "Cheetah", version);
    return make_tuple(name, codename, version);
  }
  
  using distribution_dictionary = map<string, string>;
  
  auto get_distribution_key_values() -> const distribution_dictionary& {
    static auto distribution_key_values = distribution_dictionary {};
    if (!distribution_key_values.empty()) return distribution_key_values;
    auto [name, codename, version] = macos_information();
    distribution_key_values.insert({"BUG_REPORT_URL", "https://support.apple.com/macos"});
    distribution_key_values.insert({"HOME_URL", "https://www.apple.com/macos"});
    distribution_key_values.insert({"ID", xtd::native::macos::strings::replace(xtd::native::macos::strings::to_lower(name), " ", "")});
    distribution_key_values.insert({"ID_LIKE", "macos osx"});
    distribution_key_values.insert({"NAME", name});
    distribution_key_values.insert({"PRETTY_NAME", "Apple " + name + " " + version + " (" + codename + ")"});
    distribution_key_values.insert({"VERSION", version + " (" + codename + ")"});
    distribution_key_values.insert({"VERSION_ID", version});
    distribution_key_values.insert({"VERSION_CODENAME", codename});
    
    return distribution_key_values;
  }
  
  void (*__on_quick_exit__)(void) = nullptr;
}

auto environment::at_quick_exit(void (*on_quick_exit)(void)) -> int32_t {
  /// Workaround quick_exit and at_quick_exit are not implemented on macOS !
  /// See https://github.com/runtimeverification/k/issues/1580 for more informtion
  //return at_quick_exit(on_quick_exit);
  __on_quick_exit__ = on_quick_exit;
  return 0;
}

auto environment::get_command_line_args() -> vector<string> {
  auto argc = *_NSGetArgc();
  auto argv = *_NSGetArgv();
  if (argv == nullptr || argc < 1) return {"a.out"};
  return {argv, argv + argc};
}

auto environment::get_desktop_environment() -> string {
  return "macos";
}

auto environment::get_desktop_theme() -> string {
  return macos::strings::contains(macos::shell_execute::run("defaults", "read -g AppleInterfaceStyle"), "Dark") ? "macos dark" : "macos";
}

auto environment::get_distribution_bug_report() -> string {
  auto name_it = get_distribution_key_values().find("BUG_REPORT_URL");
  if (name_it == get_distribution_key_values().end()) return "";
  return name_it->second;
}

auto environment::get_distribution_code_name() -> string {
  auto iterator = get_distribution_key_values().find("VERSION_CODENAME");
  if (iterator == get_distribution_key_values().end()) return "";
  return iterator->second;
}

auto environment::get_distribution_description() -> string {
  auto iterator = get_distribution_key_values().find("PRETTY_NAME");
  if (iterator == get_distribution_key_values().end()) return "";
  return iterator->second;
}

auto environment::get_distribution_home() -> string {
  auto name_it = get_distribution_key_values().find("HOME_URL");
  if (name_it == get_distribution_key_values().end()) return "";
  return name_it->second;
}

auto environment::get_distribution_id() -> string {
  auto iterator = get_distribution_key_values().find("ID");
  if (iterator == get_distribution_key_values().end()) return "";
  return iterator->second;
}

auto environment::get_distribution_like_ids() -> vector<string> {
  auto iterator = get_distribution_key_values().find("ID_LIKE");
  if (iterator == get_distribution_key_values().end()) return {};
  return macos::strings::split(iterator->second, {' '});
}

auto environment::get_distribution_name() -> string {
  auto name_it = get_distribution_key_values().find("NAME");
  if (name_it == get_distribution_key_values().end()) return "Unknown";
  return name_it->second;
}

auto environment::get_distribution_version(int32_t& major, int32_t& minor, int32_t& build, int32_t& revision) -> void {
  auto name_it = get_distribution_key_values().find("VERSION_ID");
  if (name_it == get_distribution_key_values().end()) return;
  auto versions = xtd::native::macos::strings::split(name_it->second, {'.'});
  if (versions.size() >= 1) major = stoi(versions[0]);
  if (versions.size() >= 2) minor = stoi(versions[1]);
}

auto environment::get_distribution_version_string() -> string {
  auto iterator = get_distribution_key_values().find("VERSION");
  if (iterator == get_distribution_key_values().end()) return "";
  return iterator->second;
}

auto environment::get_environment_variable(const string& variable, int32_t target) -> string {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS) {
    auto value = getenv(variable.c_str());
    return value ? value : "";
  }  else if (target == ENVIRONMENT_VARIABLE_TARGET_USER) {
    /// @todo Get registry value when implmented ???
    return "";
  } if (target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    /// @todo Get registry value when implmented ???
    return "";
  }
  return "";
}

extern char** environ;

auto environment::get_environment_variables(int32_t target) -> map<string, string>& {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS) {
    static auto envs = map<string, string> {};
    if (envs.size() == 0) {
      for (auto index = size_t {0}; environ[index] != nullptr; index++) {
        auto key_value = macos::strings::split(environ[index], {'='});
        if (key_value.size() == 2)
          envs[key_value[0]] = key_value[1];
      }
    }
    return envs;
  }
  
  if (target == ENVIRONMENT_VARIABLE_TARGET_USER || target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    static auto envs = map<string, string> {};
    envs.clear();
    //microsoft::win32::registry_key key = target == environment_variable_target::user ? microsoft::win32::registry::current_user().create_sub_key("Environment") : microsoft::win32::registry::local_machine().create_sub_key("System").create_sub_key("CurrentControlSet").create_sub_key("Control").create_sub_key("Session Manager").create_sub_key("Environment");
    //for (auto name : key.get_value_names())
    //  envs[name] = key.get_value(name).to_string();
    return envs;
  }
  
  static auto envs = map<string, string> {};
  return envs;
}

auto environment::get_executable_path() -> string {
  char executable_path[PATH_MAX];
  auto size = uint32_t {PATH_MAX};
  if (_NSGetExecutablePath(executable_path, &size) != 0) return get_command_line_args()[0];
  return executable_path;
}

auto environment::get_know_folder_path(int32_t csidl) -> string {
  static auto special_folders = map<int32_t, string> {{CSIDL_DESKTOP, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Desktop"}, {CSIDL_PERSONAL, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS)}, {CSIDL_FAVORITES, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Library/Favorites"}, {CSIDL_MYMUSIC, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Music"}, {CSIDL_MYVIDEO, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Movies"}, {CSIDL_DESKTOPDIRECTORY, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Desktop"}, {CSIDL_FONTS, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Library/Fonts"}, {CSIDL_TEMPLATES, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Templates"}, {CSIDL_APPDATA, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Library/Preferences"}, {CSIDL_LOCAL_APPDATA, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/.local/share"}, {CSIDL_INTERNET_CACHE, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Library/Caches"}, {CSIDL_COMMON_APPDATA, "/usr/share"}, {CSIDL_SYSTEM, "/System"}, {CSIDL_PROGRAM_FILES, "/Applications"}, {CSIDL_MYPICTURES, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Pictures"}, {CSIDL_PROFILE, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS)}, {CSIDL_COMMON_TEMPLATES, "/usr/share/templates"}, {CSIDL_HOME, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS)}};
  auto it = special_folders.find(csidl);
  if (it == special_folders.end()) return "";
  return it->second;
}

auto environment::get_machine_name() -> string {
  return macos::strings::replace(macos::shell_execute::run("uname", "-n"), "\n", "");
}

auto environment::get_os_platform_id() -> int32_t {
  #if TARGET_OS_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
  return PLATFORM_IOS;
  #else
  return PLATFORM_MACOS;
  #endif
}

auto environment::get_os_version(int32_t& major, int32_t& minor, int32_t& build, int32_t& revision) -> void {
  auto numbers = macos::strings::split(macos::shell_execute::run("sw_vers", "-productVersion"), {'.', '\n'});
  if (numbers.size() < 1 || !macos::strings::try_parse(numbers[0], major)) major = 0;
  if (numbers.size() < 2 || !macos::strings::try_parse(numbers[1], minor)) minor = 0;
  if (numbers.size() < 3 || !macos::strings::try_parse(numbers[2], build)) build = 0;
  if (numbers.size() < 4 || !macos::strings::try_parse(numbers[3], revision)) revision = 0;
}

auto environment::get_processor_count() -> uint32_t {
  return thread::hardware_concurrency();
}

auto environment::get_resources_path(bool gui_app) -> string {
  auto app_path = get_executable_path();
  auto pos = app_path.rfind('/');
  return (pos == app_path.npos ? "" : app_path.substr(0, pos) + '/') + (gui_app ? "../Resources" : "resources");
}

auto environment::get_service_pack() -> string {
  return "";
}

auto environment::get_system_page_size() -> size_t {
  return sysconf(_SC_PAGESIZE);
}

auto environment::get_tick_count() -> uint32_t {
  // https://stackoverflow.com/questions/3269321/osx-programmatically-get-uptime
  auto boottime = timeval {};
  auto nowtime = timeval {};
  auto len = sizeof(boottime);
  int32_t mib[2] = {CTL_KERN, KERN_BOOTTIME};
  sysctl(mib, 2, &boottime, &len, nullptr, 0);
  gettimeofday(&nowtime, nullptr);
  return static_cast<uint32_t>((nowtime.tv_sec - boottime.tv_sec) * 1000) + static_cast<uint32_t>((nowtime.tv_usec - boottime.tv_usec) / 1000);
}

auto environment::get_user_administrator() -> bool {
  // https://stackoverflow.com/questions/3214297/how-can-my-c-c-application-determine-if-the-root-user-is-executing-the-command
  //return getuid() != geteuid();
  return !getuid();
}

auto environment::get_user_domain_name() -> string {
  return macos::strings::trim_end(macos::shell_execute::run("uname", "-n"), {'\n'});
}

auto environment::get_user_name() -> string {
  auto user_name = getenv("USER");
  return user_name ? user_name : "";
}

auto environment::has_shutdown_started() -> bool {
  // return always `false` on macos.
  return false;
}

auto environment::is_processor_arm() -> bool {
  auto uname_result = macos::shell_execute::run("uname", "-m");
  return macos::strings::contains(uname_result, "arm") || macos::strings::contains(uname_result, "aarch64");
}

auto environment::is_os_64_bit() -> bool {
  return macos::strings::contains(macos::shell_execute::run("uname", "-m"), "64");
}

auto environment::new_line() -> string {
  return "\n";
}

auto environment::quick_exit(int32_t exit_code) noexcept -> void {
  /// Workaround quick_exit and at_quick_exit are not implemented on macOS !
  /// See https://github.com/runtimeverification/k/issues/1580 for more informtion
  //quick_exit(exit_code)
  if (__on_quick_exit__) __on_quick_exit__();
  _Exit(exit_code);
}

auto environment::set_environment_variable(const string& name, const string& value, int32_t target) -> void {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS)
    setenv(name.c_str(), value.c_str(), 1);
  else if (target == ENVIRONMENT_VARIABLE_TARGET_USER) {
    /// @todo Set registry value when implmented ???
  } if (target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    /// @todo Set registry value when implmented ???
  }
}

auto environment::unset_environment_variable(const string& name, int32_t target) -> void {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS)
    unsetenv(name.c_str());
  else if (target == ENVIRONMENT_VARIABLE_TARGET_USER) {
    /// @todo Unset registry value when implmented ???
  } if (target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    /// @todo Unset registry value when implmented ???
  }
}

auto environment::working_set() -> int64_t {
  return 0;
}
