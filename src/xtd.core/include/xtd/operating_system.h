/// @file
/// @brief Contains xtd::operating_system class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <map>
#include <vector>
#include "object.h"
#include "platform_id.h"
#include "strings.h"
#include "version.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about an operating system, such as the version and platform identifier. This class cannot be inherited.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The operating_system class contains information about an operating system.
  /// @remarks For information about the current runtime operating system, retrieve the operating_system object returned by the xtd::environment::os_version method.
  /// @remarks By design, the operating_system class is not a general purpose means of describing an operating system, and you cannot derive a more inclusive type from the operating_system class. If you need a type to contain other information about an operating system, create your own type, then include a field of type operating_system and any additional fields or methods that you require.
  class operating_system final : public object {
  public:
    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version) : platform_(platform), version_(version) {}

    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @param service_pack A string, such as "Service Pack 3", that represent the sercie pack. If no Service Pack has been installed, the string must be empty.
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version, const std::string& service_pack) : platform_(platform), version_(version), service_pack_(service_pack) {}
    
    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @param service_pack A string, such as "Service Pack 3", that represent the sercie pack. If no Service Pack has been installed, the string must be empty.
    /// @param desktop_environment A string, such as "gnome", "kde", "windows", "macos".
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version, const std::string& service_pack, const std::string& desktop_environment) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment) {}
    
    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @param service_pack A string, such as "Service Pack 3", that represent the sercie pack. If no Service Pack has been installed, the string must be empty.
    /// @param desktop_environment A string, such as "gnome", "kde", "windows", "macos".
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version, const std::string& service_pack, const std::string& desktop_environment, bool is_64_bit) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment), is_64_bit_(is_64_bit) {}

    /// @cond
    operating_system() = default;
    operating_system(const operating_system&) = default;
    operating_system& operator=(const operating_system&) = default;
    friend std::ostream& operator <<(std::ostream& os, const operating_system& operating_system) noexcept {return os << operating_system.to_string();}
    /// @endcond
    
    /// @brief Gets the desktop environment .
    /// @return string The desktop environment for the operating system, if not found empty string ("").
    /// @remarks On Windows is always "windows".
    /// @remarks On macOS is always "macos".
    /// @remarks On linux it can be "budgie", "cinamon",  "deepin", "Enlightenment", "étoilé", "gnome", "kde", "lxqt", "mate", "pantheon", "razor-qt", "unity", "xfce".
    std::string desktop_environment() const {return desktop_environment_;}
    
    /// @brief Determines whether the current operating system is a 64-bit operating system.
    /// @return true if the operating system is 64-bit; otherwise, false.
    bool is_64_bit() const noexcept {return is_64_bit_;}

    /// @brief Determines whether the current platform is macOS family.
    /// @return true if the current platform is macOS family; otherwise, false.
    bool is_macos_platform() const noexcept {return platform_ == xtd::platform_id::macos || platform_ == xtd::platform_id::ios;}
    
    /// @brief Determines whether the current platform is Unix family.
    /// @return true if the current platform is Unix family; otherwise, false.
    bool is_linux_platform() const noexcept {return platform_ == xtd::platform_id::unix || platform_ == xtd::platform_id::android;}
    
    /// @brief Determines whether the current platform is Windows family.
    /// @return true if the current platform is Windows family; otherwise, false.
    bool is_windows_platform() const noexcept {return platform_ == xtd::platform_id::win32_nt || platform_ == xtd::platform_id::win32s || platform_ == xtd::platform_id::win32_windows || platform_ == xtd::platform_id::win_ce || platform_ == xtd::platform_id::xbox;}
    
    /// @brief Gets the concatenated string representation of the platform identifier.
    /// @return The string representation of the values returned by the platform.
    std::string name() const noexcept {
      static std::map<xtd::platform_id, std::string> operating_system_names {{platform_id::win32s, "Microsoft Win32S"}, {platform_id::win32_windows, "Microsoft Windows 95"}, {platform_id::win32_nt, "Microsoft Windows NT"}, {platform_id::win_ce, "Microsoft Windows CE"}, {platform_id::unix, "Unix"}, {platform_id::xbox, "Xbox"}, {platform_id::macos, "macOS"}, {platform_id::ios, "iOS"}, {platform_id::android, "Android"}, {platform_id::unknown, "<Unknown>"}};
      if (platform_ == xtd::platform_id::win32_windows && (version_.major() > 4 || (version_.major() == 4 && version_.minor() > 0))) return "Microsoft Windows 98";
      return operating_system_names[platform_];
    }

    /// @brief Gets a xtd::platform_id enumeration value that identifies the operating system platform.
    /// @return xtd::platform_id One of the xtd::platform_id values.
    xtd::platform_id platform() const noexcept {return platform_;}
    
    /// @brief Gets the service pack version represented by this operating_system object.
    /// @return string The service pack version, if service packs are supported and at least one is installed; otherwise, an empty string ("").
    /// @remarks A service pack is used to distribute software updates for the operating system on which it is installed. However, not every operating system uses service packs.
    /// @remarks The service pack version, if available, is already correctly formatted for display.
    std::string service_pack() const noexcept {return service_pack_;}
    
    /// @brief Gets a xtd::version object that identifies the operating system.
    /// @return Version A Version object that describes the major version, minor version, build, and revision numbers for the operating system.
    /// @remarks For Window system only: See http://msdn.microsoft.com/library/windows/desktop/ms724832.aspx on the Windows Dev Center for a list of Windows operating system versions and their corresponding version numbers.
    const xtd::version& version() const noexcept {return version_;}
    
    /// @brief Gets the concatenated string representation of the platform identifier, version, and service pack that are currently installed on the operating system.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    /// @remarks By default, the value returned by version_string is the same as the value returned by the to_string method.
    std::string version_string() const noexcept {
      if (!version_string_.empty()) return version_string_;
      version_string_ = name() + " " + version_.to_string(3);
      if (!service_pack_.empty()) version_string_ += " " + service_pack();
      return version_string_;
    }
    
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    std::string to_string() const noexcept {return version_string();}
    
  private:
    xtd::platform_id platform_ = xtd::platform_id::unknown;
    xtd::version version_;
    std::string service_pack_;
    std::string desktop_environment_;
    bool is_64_bit_ = false;
    mutable std::string version_string_;
  };
}
