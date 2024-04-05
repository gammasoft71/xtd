/// @file
/// @brief Contains environment API.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @cond
#if !defined(__XTD_CORE_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include "constant_special_item_id_list.h"
#include "environment_variable_target.h"
#include "platform_ids.h"
#include <xtd/core_native_export>
#include <cstdint>
#include <map>
#include <string>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  class environment;
  /// @endcond
  
  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @cond
    class translator;
    /// @endcond
    
    /// @brief Contains environment native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ environment final {
      environment() = delete;
      friend xtd::environment;
      friend xtd::native::translator;
    protected:
      /// @name Protected Static Methods
      
      /// @{
      /// @brief Registers the function pointed to by func to be called on quick program termination (via xtd::native::environment::quick_exit).
      /// @param on_quick_exit pointer to a function to be called on quick program termination.
      /// @return 0​ if the registration succeeds, nonzero value otherwise.
      /// @warning Internal use only
      static int_least32_t at_quick_exit(void (*on_quick_exit)(void));

      /// @brief Returns a string array containing the command-line arguments for the current process.
      /// @return An array of string where each element contains a command-line argument. The first element is the executable file name, and the following zero or more elements contain the remaining command-line arguments.
      /// @warning Internal use only
      static std::vector<std::string> get_command_line_args();
      /// @brief Gets the desktop environment name.
      /// @return std::string A string containing desktop environment name.
      /// @remarks Returns "windows" on Windows, "macos" on macOS, "budgie" or "cinnamon" or "deepin" or "Enlightenment", "étoilé" or "gnome" or "kde" or "lxqt" or "mate" or "pantheon" or "razor" or "unity" or "xfce" on linux.
      /// @remarks Return "" if not found or defined.
      /// @warning Internal use only
      static std::string get_desktop_environment();
      /// @brief Gets the desktop theme name.
      /// @return std::string A string containing desktop theme name.
      /// @remarks Returns a string, such as "Adwaita", "Breeze", "windows dark", "macos dark", ...
      /// @remarks Return "" if not found or defined.
      /// @warning Internal use only
      static std::string get_desktop_theme();
      /// @brief Gets the distribution bug report url.
      /// @return std::string A string containing distribution bug report url.
      /// @remarks Return "" if not found or defined.
      /// @warning Internal use only
      static std::string get_distribution_bug_report();
      /// @brief Gets the distribution code name.
      /// @return std::string A string containing distribution code name.
      /// @remarks Return "" if not found or defined.
      /// @warning Internal use only
      static std::string get_distribution_code_name();
      /// @brief Gets the distribution description.
      /// @return std::string A string containing distribution description.
      /// @remarks Return "" if not found or defined.
      /// @warning Internal use only
      static std::string get_distribution_description();
      /// @brief Gets the distribution home url.
      /// @return std::string A string containing distribution home url.
      /// @remarks Returns "Windows" on Windows, "macOS" on macOS, "Ubuntu", "Rocky Linux", ...
      /// @remarks Return "" if not found or defined.
      /// @warning Internal use only
      static std::string get_distribution_home();
      /// @brief Gets the distribution identifier.
      /// @return std::string A string containing distribution identifier.
      /// @remarks Return "" if not found or defined.
      /// @warning Internal use only
      static std::string get_distribution_id();
      /// @brief Gets the distribution like identifiers array.
      /// @return std::string A string containing distribution like identifiers array.
      /// @remarks Return {} if not found or defined.
      /// @warning Internal use only
      static std::vector<std::string> get_distribution_like_ids();
      /// @brief Gets the distribution name.
      /// @return std::string A string containing distribution name.
      /// @remarks Returns "Windows" on Windows, "macOS" on macOS, "Ubuntu", "Rocky Linux", ...
      /// @remarks Return "" if not found or defined.
      /// @warning Internal use only
      static std::string get_distribution_name();
      /// @brief Gets a xtd::version object that identifies the distribution.
      /// @param major return the major version.
      /// @param minor return the minor version, build, and revision numbers for the distribution.
      /// @param build return the build.
      /// @param revision return the revision numbers for the distribution.
      /// @warning Internal use only
      static void get_distribution_version(int_least32_t& major, int_least32_t& minor, int_least32_t& build, int_least32_t& revision);
      /// @brief Gets the distribution version string.
      /// @return std::string A string containing distribution version string.
      /// @remarks Return "" if not found or defined.
      /// @warning Internal use only
      static std::string get_distribution_version_string();
      /// @brief Retrieves all environment variable names and their values from the current process, or from the Windows operating system registry key for the current user or local machine.
      /// @param target The environment variable target (see environment_variable_target.h file).
      /// @return std::map A dictionary that contains all environment variable names and their values from the source specified by the target parameter; otherwise, an empty dictionary if no environment variables are found.
      /// @warning Internal use only
      static std::map<std::string, std::string>& get_environment_variables(int_least32_t target);
      /// @brief Retrieves the value of an environment variable from the current process.
      /// @param variable The name of the environment variable.
      /// @return std::string The value of the environment variable specified by variable, or empty "" if the environment variable is not found.
      /// @warning Internal use only
      static std::string get_environment_variable(const std::string& variable, int_least32_t target);
      /// @brief Gets the path to the system special folder that is identified by the specified enumeration.
      /// @param csidl System special folder identifier (see constant_special_item_id_list.h file).
      /// @return The path to the specified system special folder, if that folder physically exists on your computer; otherwise, an empty string ("").
      /// @warning Internal use only
      static std::string get_know_folder_path(int_least32_t csidl);
      /// @brief Gets the NetBIOS name of this local computer.
      /// @return A string containing the name of this computer.
      /// @warning Internal use only
      static std::string get_machine_name();
      /// @brief Gets a platform id that identifies the operating system platform.
      /// @return Operating system platform identifier (see platform_ids.h file).
      /// @warning Internal use only
      static int_least32_t get_os_platform_id();
      /// @brief Gets a xtd::version object that identifies the operating system.
      /// @param major return the major version.
      /// @param minor return the minor version, build, and revision numbers for the operating system.
      /// @param build return the build.
      /// @param revision return the revision numbers for the operating system.
      /// @warning Internal use only
      static void get_os_version(int_least32_t& major, int_least32_t& minor, int_least32_t& build, int_least32_t& revision);
      /// @brief Gets the number of processors on the current machine.
      /// @return The 32-bit unsigned integer that specifies the number of processors on the current machine. There is no default. If the current machine contains multiple processor groups, this property returns the number of logical processors that are available for use.
      /// @warning Internal use only
      static uint_least32_t get_processor_count();
      /// @brief Gets the service pack version represented by this operating_system object.
      /// @return string The service pack version, if service packs are supported and at least one is installed; otherwise, an empty string ("").
      /// @warning Internal use only
      static std::string get_service_pack();
      /// @brief Gets the number of bytes in the operating system's memory page.
      /// @return The number of bytes in the system memory page.
      /// @warning Internal use only
      static size_t get_system_page_size();
      /// @brief Gets the number of milliseconds elapsed since the system started.
      /// @return A 32-bit unsigned integer containing the amount of time in milliseconds that has passed since the last time the computer was started.
      /// @warning Internal use only
      static uint_least32_t get_tick_count();
      /// @brief Gets a value indicating whether the current user is an administrator.
      /// @return bool true if the current user is an administrator; otherwise, false.
      /// @warning Internal use only
      static bool get_user_administrator();
      /// @brief Gets the network domain name associated with the current user.
      /// @return The network domain name associated with the current user.
      /// @warning Internal use only
      static std::string get_user_domain_name();
      /// @brief Gets the user name of the person who is currently logged on to the operating system.
      /// @return The user name of the person who is logged on to the operating system.
      /// @warning Internal use only
      static std::string get_user_name();
      /// @brief Gets a value that indicates whether the current application domain is shutting down.
      /// @return bool true if the current application domain is shutting down; otherwise, false.
      /// @warning Internal use only
      static bool has_shutdown_started();
      /// @brief Determines whether the current processor is arm.
      /// @return true if the processor is is arm; otherwise, false.
      /// @warning Internal use only
      static bool is_processor_arm();
      /// @brief Determines whether the current operating system is a 64-bit operating system.
      /// @return true if the operating system is 64-bit; otherwise, false.
      /// @warning Internal use only
      static bool is_os_64_bit();
      /// @brief Gets the newline string defined for this environment.
      /// @return A string containing "\r\n" for non-Unix platforms, or a string containing "\n" for Unix platforms.
      /// @warning Internal use only
      static std::string new_line();
      /// @brief Terminates this process and returns an exit code to the operating system without completely cleaning the resources..
      /// @param exit_code The exit code to return to the operating system. Use 0 (zero) to indicate that the process completed successfully.
      /// @warning Internal use only
      [[noreturn]] static void quick_exit(int_least32_t exit_code) noexcept;
      /// @brief Creates or modifies an environment variable stored in the current process.
      /// @param variable The name of an environment variable.
      /// @param value A value to assign to variable.
      /// @warning Internal use only
      static void set_environment_variable(const std::string& name, const std::string& value, int_least32_t target);
      /// @brief Deletes an environment variable stored in the current process.
      /// @param variable The name of an environment variable.
      /// @warning Internal use only
      static void unset_environment_variable(const std::string& name, int_least32_t target);
      /// @brief Gets the amount of physical memory mapped to the process context.
      /// @return Int64 A 64-bit signed integer containing the number of bytes of physical memory mapped to the process context.
      /// @warning Internal use only
      static int_least64_t working_set();
      /// @}
    };
  }
}
