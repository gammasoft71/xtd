/// @file
/// @brief Contains __opaque_environment class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "core_export.h"
#include "guid.h"
#include "platform_id.h"
#include "version.h"

/// @cond
namespace xtd {
  class environment;
  class guid;
}

class core_export_ __opaque_environment final {
  friend class xtd::environment;
  friend class xtd::guid;
  
  static std::string get_current_directory() noexcept;
  static std::string get_desktop_environment() noexcept;
  static std::string get_environment_variable(const std::string& variable) noexcept;
  static std::string get_know_folder_path(int id) noexcept;
  static std::string get_machine_name() noexcept;
  static xtd::platform_id get_os_platform_id() noexcept;
  static void get_os_version(int& major, int& minor, int& build, int& revision) noexcept;
  static std::string get_service_pack() noexcept;
  static unsigned int get_processor_count() noexcept;
  static size_t get_system_page_size() noexcept;
  static unsigned int get_tick_count() noexcept;
  static std::string get_user_domain_name() noexcept;
  static std::string get_user_name() noexcept;
  static xtd::version get_version() noexcept;
  static bool is_processor_arm() noexcept;
  static bool is_os_64_bit() noexcept;
  static xtd::guid new_guid() noexcept;
  static std::string new_line() noexcept;
  static int set_current_directory(const std::string& directory_name) noexcept;
  static int set_env(const std::string& name, const std::string& value) noexcept;
  static int unset_env(const std::string& name) noexcept;
};
/// @endcond
