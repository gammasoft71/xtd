#if defined(__linux__) || defined(__APPLE__)

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <random>
#include <thread>
#include <vector>

#include <time.h>
#if !defined(__ANDROID__)
#include <uuid/uuid.h>
#else
#include "../../include/Switch/System/Random.hpp"
#endif

#include <sys/time.h>

#if defined(__APPLE__)
#include <time.h>
#include <sys/sysctl.h>
#else
#include <sys/sysinfo.h>
#endif

#include "../include/xtd/__opaque_environment.hpp"
#include <xtd/strings>

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
}

std::string __opaque_environment::new_line() {
  return "\n";
}

/*
xtd::platform_id __opaque_environment::get_os_platform_id() {
#if defined(__APPLE__)
  return xtd::platform_id::mac_os_x;
#else
  return xtd::platform_id::unix;
#endif
}
 */

int __opaque_environment::get_os_version(int& major, int& minor, int& build, int& revision) {
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

bool __opaque_environment::is_os_64_bit() {
  return  xtd::strings::ends_with(create_process("uname -m"), "64");
}

std::string __opaque_environment::get_machine_name() {
  return create_process("uname -n");
}

unsigned int __opaque_environment::get_processor_count() {
  return std::thread::hardware_concurrency();
}

int __opaque_environment::get_system_page_size() {
  return 4096;
}

int __opaque_environment::get_tick_count() {
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

std::string __opaque_environment::get_user_domain_name() {
  return xtd::strings::trim_end(create_process("uname -n"), '\n');
}

std::string __opaque_environment::get_user_name() {
  char name[512];
  strcpy(name, getenv("USER"));
  return name;
}

long long __opaque_environment::get_working_set() {
  return 0;
}

int __opaque_environment::set_env(const std::string& name, const std::string& value) {
  return setenv(name.c_str(), value.c_str(), 1);
}

int __opaque_environment::unset_env(const std::string& name) {
  return unsetenv(name.c_str());
}

xtd::guid __opaque_environment::new_guid() {
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

#endif
