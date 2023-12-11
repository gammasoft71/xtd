#define __XTD_CORE_NATIVE_LIBRARY__
#include <xtd/native/environment>
#include "../../../../include/xtd/native/posix/strings.h"
#undef __XTD_CORE_NATIVE_LIBRARY__
#include <cstdio>
#include <cstdlib>
#include <map>
#include <numeric>
#include <thread>
#include <sys/sysinfo.h>
#include <sys/param.h>
#include <unistd.h>

using namespace std;
using namespace std::literals;
using namespace xtd::native;

extern char** environ;
int_least32_t __environment_argc;
char** __environment_argv;

namespace {
  static string create_process(const string& command) {
    auto fs = popen(command.c_str(), "r");
    auto result = string {};
    while (!feof(fs)) {
      char buf[513];
      size_t l = fread(buf, 1, 512, fs);
      buf[l] = 0;
      result += buf;
    }
    pclose(fs);
    return result;
  }
  
  __attribute__((constructor)) void startup_program(int_least32_t argc, char** argv) {
    __environment_argc = argc;
    __environment_argv = argv;
  }
  
  using distribution_dictionary = map<string, string>;
  
  const distribution_dictionary& get_distribution_key_values() {
    static auto distribution_key_values = distribution_dictionary {};
    if (!distribution_key_values.empty()) return distribution_key_values;
    auto distribution_string = create_process("cat /etc/os-release");
    auto distribution_lines = xtd::native::posix::strings::split(distribution_string, {'\n'});
    for (auto distribution_line : distribution_lines) {
      auto key_value = xtd::native::posix::strings::split(distribution_line, {'='});
      if (key_value.size() != 2) continue;
      distribution_key_values.insert({key_value[0], xtd::native::posix::strings::replace(key_value[1], "\"", "")});
    }
    
    return distribution_key_values;
  }
}

int_least32_t environment::at_quick_exit(void (*on_quick_exit)(void)) {
  return std::at_quick_exit(on_quick_exit);
}

vector<string> environment::get_command_line_args() {
  return {__environment_argv, __environment_argv + __environment_argc};
}

string environment::get_desktop_environment() {
  auto current_desktop = get_environment_variable("XDG_CURRENT_DESKTOP", ENVIRONMENT_VARIABLE_TARGET_PROCESS);
  if (current_desktop == "") current_desktop = get_environment_variable("XDG_DATA_DIRS", ENVIRONMENT_VARIABLE_TARGET_PROCESS);
  for (auto environment_desktop : {"budgie", "cinnamon", "deepin", "Enlightenment", "étoilé", "gnome", "kde", "lxqt", "mate", "pantheon", "razor", "unity", "xfce"}) {
    if (posix::strings::contains(posix::strings::to_lower(current_desktop), environment_desktop)) return environment_desktop;
  }
  return "";
}

string environment::get_desktop_theme() {
  auto desktop = get_desktop_environment();
  if (desktop != "gnome") return desktop;
  auto current_theme = create_process("gsettings get org.gnome.desktop.interface gtk-theme");
  if (current_theme.size() >= 4)
    current_theme = posix::strings::substring(current_theme, 1, current_theme.size() - 3);
  return current_theme;
}

string environment::get_distribution_bug_report() {
  auto name_it = get_distribution_key_values().find("BUG_REPORT_URL");
  if (name_it == get_distribution_key_values().end()) return "";
  return name_it->second;
}

string environment::get_distribution_code_name() {
  auto iterator = get_distribution_key_values().find("VERSION_CODENAME");
  if (iterator == get_distribution_key_values().end()) return "";
  return iterator->second;
}

string environment::get_distribution_description() {
  auto iterator = get_distribution_key_values().find("PRETTY_NAME");
  if (iterator == get_distribution_key_values().end()) return "";
  return iterator->second;
}

string environment::get_distribution_home() {
  auto name_it = get_distribution_key_values().find("HOME_URL");
  if (name_it == get_distribution_key_values().end()) return "";
  return name_it->second;
}

string environment::get_distribution_id() {
  auto iterator = get_distribution_key_values().find("ID");
  if (iterator == get_distribution_key_values().end()) return "";
  return iterator->second;
}

vector<string> environment::get_distribution_like_ids() {
  auto iterator = get_distribution_key_values().find("ID_LIKE");
  if (iterator == get_distribution_key_values().end()) return {};
  return posix::strings::split(iterator->second, {' '});
}

string environment::get_distribution_name() {
  auto name_it = get_distribution_key_values().find("NAME");
  if (name_it == get_distribution_key_values().end()) return "Unknown";
  return name_it->second;
}

void environment::get_distribution_version(int_least32_t& major, int_least32_t& minor, int_least32_t& build, int_least32_t& revision) {
  auto name_it = get_distribution_key_values().find("VERSION_ID");
  if (name_it == get_distribution_key_values().end()) return;
  auto versions = xtd::native::posix::strings::split(name_it->second, {'.'});
  if (versions.size() >= 1) major = stoi(versions[0]);
  if (versions.size() >= 2) minor = stoi(versions[1]);
}

string environment::get_distribution_version_string() {
  auto iterator = get_distribution_key_values().find("VERSION");
  if (iterator == get_distribution_key_values().end()) return "";
  return iterator->second;
}

string environment::get_environment_variable(const string& variable, int_least32_t target) {
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

map<string, string>& environment::get_environment_variables(int_least32_t target) {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS) {
    static auto envs = map<string, string> {};
    if (envs.size() == 0) {
      for (auto index = size_t {0}; environ[index] != nullptr; index++) {
        vector<string> key_value = posix::strings::split(environ[index], {'='});
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
  
  static map<string, string> envs;
  return envs;
}

string environment::get_know_folder_path(int_least32_t csidl) {
  static auto special_folders = map<int_least32_t, string> {{CSIDL_DESKTOP, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Desktop"}, {CSIDL_PERSONAL, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS)}, {CSIDL_MYMUSIC, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Music"}, {CSIDL_MYVIDEO, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Videos"}, {CSIDL_DESKTOPDIRECTORY, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Desktop"}, {CSIDL_FONTS, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/.fonts"}, {CSIDL_TEMPLATES, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Templates"}, {CSIDL_APPDATA, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/.config"}, {CSIDL_LOCAL_APPDATA, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/.local/share"}, {CSIDL_COMMON_APPDATA, "/usr/share"}, {CSIDL_MYPICTURES, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS) + "/Pictures"}, {CSIDL_PROFILE, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS)}, {CSIDL_COMMON_TEMPLATES, "/usr/share/templates"}, {CSIDL_HOME, get_environment_variable("HOME", ENVIRONMENT_VARIABLE_TARGET_PROCESS)}};
  auto it = special_folders.find(csidl);
  if (it == special_folders.end()) return "";
  return it->second;
}

string environment::get_machine_name() {
  return posix::strings::replace(create_process("uname -n"), "\n", "");
}

int_least32_t environment::get_os_platform_id() {
  if (create_process("uname -a").find("MSYS_NT") != string::npos) return PLATFORM_MSYS2;
  return PLATFORM_UNIX;
}

void environment::get_os_version(int_least32_t& major, int_least32_t& minor, int_least32_t& build, int_least32_t& revision) {
  auto numbers = posix::strings::split(create_process("uname -r"), {'.', '-', '\n'});
  if (numbers.size() < 1 || !posix::strings::try_parse(numbers[0], major)) major = 0;
  if (numbers.size() < 2 || !posix::strings::try_parse(numbers[1], minor)) minor = 0;
  if (numbers.size() < 3 || !posix::strings::try_parse(numbers[2], build)) build = 0;
  if (numbers.size() < 4 || !posix::strings::try_parse(numbers[3], revision)) revision = 0;
}

string environment::get_service_pack() {
  return "";
}

uint_least32_t environment::get_processor_count() {
  return thread::hardware_concurrency();
}

size_t environment::get_system_page_size() {
  return sysconf(_SC_PAGESIZE);
}

uint_least32_t environment::get_tick_count() {
  // https://stackoverflow.com/questions/1540627/what-api-do-i-call-to-get-the-system-uptime
  struct sysinfo info {};
  sysinfo(&info);
  return info.uptime * 1000;
}

bool environment::get_user_administrator() {
  // https://stackoverflow.com/questions/3214297/how-can-my-c-c-application-determine-if-the-root-user-is-executing-the-command
  //return getuid() != geteuid();
  return !getuid();
}

string environment::get_user_domain_name() {
  return posix::strings::trim_end(create_process("uname -n"), {'\n'});
}

string environment::get_user_name() {
  auto user_name = getenv("USER");
  return user_name ? user_name : "";
}

bool environment::has_shutdown_started() {
  // return always false on linux and macos.
  return false;
}

bool environment::is_processor_arm() {
  auto uname_result = create_process("uname -m");
  return posix::strings::contains(uname_result, "arm") || posix::strings::contains(uname_result, "aarch64");
}

bool environment::is_os_64_bit() {
  return posix::strings::contains(create_process("uname -m"), "64");
}

string environment::new_line() {
  return "\n";
}

void environment::quick_exit(int_least32_t exit_code) noexcept {
  std::quick_exit(exit_code);
}

void environment::set_environment_variable(const string& name, const string& value, int_least32_t target) {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS)
    setenv(name.c_str(), value.c_str(), 1);
  else if (target == ENVIRONMENT_VARIABLE_TARGET_USER) {
    /// @todo Snset registry value when implmented ???
  } if (target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    /// @todo Set registry value when implmented ???
  }
}

void environment::unset_environment_variable(const string& name, int_least32_t target) {
  if (target == ENVIRONMENT_VARIABLE_TARGET_PROCESS)
    unsetenv(name.c_str());
  else if (target == ENVIRONMENT_VARIABLE_TARGET_USER) {
    /// @todo Unset registry value when implmented ???
  } if (target == ENVIRONMENT_VARIABLE_TARGET_MACHINE) {
    /// @todo Unset registry value when implmented ???
  }
}

int_least64_t environment::working_set() {
  return 0;
}
