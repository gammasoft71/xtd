#if defined(__linux__) || defined(__APPLE__)

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <numeric>
#include <random>
#include <thread>
#include <vector>

#include <time.h>
#if !defined(__ANDROID__)
#include <uuid/uuid.h>
#endif
#include <sys/time.h>

#if defined(__APPLE__)
#include "TargetConditionals.h"
#include <time.h>
#include <sys/sysctl.h>
#else
#include <sys/sysinfo.h>
#endif
#include <sys/param.h>
#include <unistd.h>

#include "../include/xtd/__opaque_environment.h"
#include "../include/xtd/environment.h"
#include <xtd/xtd.strings>

int __environment_argc;
char** __environment_argv;

namespace {
  static std::string create_process(const std::string& command) {
    FILE* fs = popen(command.c_str(), "r");
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
  
  __attribute__((constructor)) void startup_program(int argc, char **argv) {
    __environment_argc = argc;
    __environment_argv = argv;
  }
}

std::string __opaque_environment::get_current_directory() noexcept {
  char path[MAXPATHLEN + 1];
  return getcwd(path, MAXPATHLEN) ? path : "";
}

std::string __opaque_environment::get_desktop_environment() noexcept {
#if defined(__APPLE__)
  return "macos";
#else
  auto current_desktop = get_environment_variable("XDG_CURRENT_DESKTOP");
  if (current_desktop == "") current_desktop = get_environment_variable("XDG_DATA_DIRS");
  for (auto environment_desktop : {"budgie", "cinamon",  "deepin", "Enlightenment", "étoilé", "gnome", "kde", "lxqt", "mate", "pantheon", "razor", "unity", "xfce"}) {
    if (xtd::strings::contains(xtd::strings::to_lower(current_desktop), environment_desktop)) return environment_desktop;
  }
  return "";
#endif
}

std::string __opaque_environment::get_environment_variable(const std::string& variable) noexcept {
  char* value = getenv(variable.c_str());
  return value == nullptr ? "" : value;
}

std::string __opaque_environment::get_know_folder_path(int id) noexcept {
#if defined(__APPLE__)
  static std::map<xtd::environment::special_folder, std::string> special_folders = {{xtd::environment::special_folder::desktop, xtd::environment::expand_environment_variables("%HOME%/Desktop")}, {xtd::environment::special_folder::personal, xtd::environment::expand_environment_variables("%HOME%")}, {xtd::environment::special_folder::favorites, xtd::environment::expand_environment_variables("%HOME%/Library/Favorites")},  {xtd::environment::special_folder::my_music, xtd::environment::expand_environment_variables("%HOME%/Music")}, {xtd::environment::special_folder::my_videos, xtd::environment::expand_environment_variables("%HOME%/Videos")}, {xtd::environment::special_folder::desktop_directory, xtd::environment::expand_environment_variables("%HOME%/Desktop")}, {xtd::environment::special_folder::fonts, xtd::environment::expand_environment_variables("%HOME%/Library/Fonts")}, {xtd::environment::special_folder::templates, xtd::environment::expand_environment_variables("%HOME%/Templates")}, {xtd::environment::special_folder::application_data, xtd::environment::expand_environment_variables("%HOME%/.config")}, {xtd::environment::special_folder::local_application_data, xtd::environment::expand_environment_variables("%HOME%/.local/share")}, {xtd::environment::special_folder::internet_cache, xtd::environment::expand_environment_variables("%HOME%/Library/Caches")}, {xtd::environment::special_folder::common_application_data, "/usr/share"}, {xtd::environment::special_folder::system, "/System"}, {xtd::environment::special_folder::program_files, "/Applications"}, {xtd::environment::special_folder::my_pictures, xtd::environment::expand_environment_variables("%HOME%/Pictures")}, {xtd::environment::special_folder::user_profile, xtd::environment::expand_environment_variables("%HOME%")}, {xtd::environment::special_folder::common_templates, "/usr/share/templates"}};
#else
  static std::map<xtd::environment::special_folder, std::string> special_folders = {{xtd::environment::special_folder::desktop, xtd::environment::expand_environment_variables("%HOME%/Desktop")}, {xtd::environment::special_folder::my_documents, xtd::environment::expand_environment_variables("%HOME%")}, {xtd::environment::special_folder::my_music, xtd::environment::expand_environment_variables("%HOME%/Music")}, {xtd::environment::special_folder::my_videos, xtd::environment::expand_environment_variables("%HOME%/Videos")}, {xtd::environment::special_folder::desktop_directory, xtd::environment::expand_environment_variables("%HOME%/Desktop")}, {xtd::environment::special_folder::fonts, xtd::environment::expand_environment_variables("%HOME%/.fonts")}, {xtd::environment::special_folder::templates, xtd::environment::expand_environment_variables("%HOME%/Templates")}, {xtd::environment::special_folder::application_data, xtd::environment::expand_environment_variables("%HOME%/.config")}, {xtd::environment::special_folder::local_application_data, xtd::environment::expand_environment_variables("%HOME%/.local/share")}, {xtd::environment::special_folder::common_application_data, "/usr/share"}, {xtd::environment::special_folder::my_pictures, xtd::environment::expand_environment_variables("%HOME%/Pictures")}, {xtd::environment::special_folder::user_profile, xtd::environment::expand_environment_variables("%HOME%")}, {xtd::environment::special_folder::common_templates, "/usr/share/templates"}};
#endif
  if (special_folders.find(static_cast<xtd::environment::special_folder>(id)) == special_folders.end()) return "";
  return special_folders[static_cast<xtd::environment::special_folder>(id)];
}

std::string __opaque_environment::get_machine_name() noexcept {
  return xtd::strings::replace(create_process("uname -n"), "\n", "") ;
}

xtd::platform_id __opaque_environment::get_os_platform_id() noexcept {
#if defined(__APPLE__)
  #if TARGET_OS_SIMULATOR == 1 || TARGET_OS_IPHONE == 1
    return xtd::platform_id::ios;
  #else
    return xtd::platform_id::macos;
  #endif
#else
  #if defined(__ANDROID__)
    return xtd::platform_id::android;
  #else
    return xtd::platform_id::unix;
  #endif
#endif
}

int __opaque_environment::get_os_version(int& major, int& minor, int& build, int& revision) noexcept {
#if defined(__APPLE__)
  std::vector<std::string> numbers = xtd::strings::split(create_process("sw_vers -productVersion"), {'.', '\n'});
#else
  std::vector<std::string> numbers = xtd::strings::split(create_process("uname -r"), {'.', '-', '\n'});
#endif
  if (numbers.size() < 1 || !xtd::strings::try_parse(numbers[0], major))
    major = 0;
  if (numbers.size() < 2 || !xtd::strings::try_parse(numbers[1], minor))
    minor = 0;
  if (numbers.size() < 3 || !xtd::strings::try_parse(numbers[2], build))
    build = 0;
  if (numbers.size() < 4 || !xtd::strings::try_parse(numbers[3], revision))
    revision = 0;
  return 0;
}

std::string __opaque_environment::get_service_pack() noexcept {
  return "";
}

unsigned int __opaque_environment::get_processor_count() noexcept {
  return std::thread::hardware_concurrency();
}

size_t __opaque_environment::get_system_page_size() noexcept {
  return sysconf(_SC_PAGESIZE);
}

unsigned int __opaque_environment::get_tick_count() noexcept {
#if defined (__APPLE__)
  // https://stackoverflow.com/questions/3269321/osx-programmatically-get-uptime
  struct timeval boottime, nowtime;
  size_t len = sizeof(boottime);
  int mib[2] = { CTL_KERN, KERN_BOOTTIME };
  sysctl(mib, 2, &boottime, &len, NULL, 0);
  gettimeofday(&nowtime, NULL);
  return (int)((nowtime.tv_sec - boottime.tv_sec) * 1000) + ((nowtime.tv_usec - boottime.tv_usec) / 1000);
#else
  // https://stackoverflow.com/questions/1540627/what-api-do-i-call-to-get-the-system-uptime
  struct sysinfo info;
  sysinfo(&info);
  return info.uptime * 1000;
#endif
}

std::string __opaque_environment::get_user_domain_name() noexcept {
  return xtd::strings::trim_end(create_process("uname -n"), '\n');
}

std::string __opaque_environment::get_user_name() noexcept {
  char name[512];
  strcpy(name, getenv("USER"));
  return name;
}

bool __opaque_environment::is_os_64_bit() noexcept {
  return  xtd::strings::ends_with(create_process("uname -m"), "64");
}

xtd::guid __opaque_environment::new_guid() noexcept {
  std::vector<unsigned char> guid(16);
#if !defined(__ANDROID__)
  uuid_generate(guid.data());
#else
  // http://tools.ietf.org/html/rfc4122
  //
  // 0                   1                   2                   3
  // 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |                          time_low                             |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |       time_mid                |         time_hi_and_version   |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |clk_seq_hi_res |  clk_seq_low  |         node (0-1)            |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  // |                         node (2-5)                            |
  // +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
  //
  // 4.4 Algorithms for Creating a UUID from Truly Random or
  // Pseudo-Random Numbers
  //
  // The version 4 UUID is meant for generating UUIDs from truly-random or pseudo-random numbers.
  //
  // The algorithm is as follows:
  //  o  Set the two most significant bits (bits 6 and 7) of the clock_seq_hi_and_reserved to zero and one, respectively.
  //  o  Set the four most significant bits (bits 12 through 15) of the time_hi_and_version field to the 4-bit version number from Section 4.1.3.
  //  o  Set all the other bits to randomly (or pseudo-randomly) chosen values.
  static std::random_device rand;
  std::uniform_int_distribution<int> rand_byte_distribution(0, std::numeric_limits<uint8_t>::max());
  std::for_each(guid.begin(), guid.end(), [&](uint8_t& value) {value = static_cast<int8_t>(rand_byte_distribution(rand));});
  guid[8] &= 0xDF;
  guid[8] |= 0x40;
  guid[7] &= 0x0F;
  guid[7] |= 0x40;
#endif
  return xtd::guid(guid);
}

std::string __opaque_environment::new_line() noexcept {
  return "\n";
}

int __opaque_environment::set_current_directory(const std::string& directory_name) noexcept {
  return chdir(directory_name.c_str());
}

int __opaque_environment::set_env(const std::string& name, const std::string& value) noexcept {
  return setenv(name.c_str(), value.c_str(), 1);
}

int __opaque_environment::unset_env(const std::string& name) noexcept {
  return unsetenv(name.c_str());
}

#endif
