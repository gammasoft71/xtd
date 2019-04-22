/// @file
/// @brief Contains xtd::environment class.
#pragma once
#include "guid.hpp"
//#include "platform_id.hpp"
#include "version.hpp"

/// @cond
class __opaque_environment final {
public:
  static std::string new_line();
  static std::string get_know_folder_path(int id);
  //static xtd::platform_id get_os_platform_id();
  static int get_os_version(int& major, int& minor, int& build, int& revision);
  static bool is_os_64_bit();
  static std::string get_machine_name();
  static unsigned int get_processor_count();
  static int get_system_page_size();
  static int get_tick_count();
  static std::string get_user_domain_name();
  static std::string get_user_name();
  static xtd::version get_version();
  static long long get_working_set();
  static int set_env(const std::string& name, const std::string& value);
  static int unset_env(const std::string& name);
  static xtd::guid new_guid();
};
/// @endcond
