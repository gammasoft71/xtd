#pragma once
#include <vector>
#include "platform_id.h"
#include "version.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about an operating system, such as the version and platform identifier. This class cannot be inherited.
  /// @remarks The operating_system class contains information about an operating system.
  /// @remarks For information about the current runtime operating system, retrieve the operating_system object returned by the xtd::environment::os_version method.
  /// @remarks By design, the operating_system class is not a general purpose means of describing an operating system, and you cannot derive a more inclusive type from the operating_system class. If you need a type to contain other information about an operating system, create your own type, then include a field of type operating_system and any additional fields or methods that you require.
  class operating_system final {
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

    /// @cond
    operating_system() = default;
    operating_system(const operating_system&) = default;
    operating_system& operator=(const operating_system&) = default;
    friend std::ostream& operator <<(std::ostream& os, const operating_system& operating_system) noexcept {return os << operating_system.to_string();}
    /// @endcond
    
    /// @brief Determines whether the current platform is OSX family.
    /// @return true if the current platform is OSX family; otherwise, false.
    bool is_osx_platform() const noexcept {return this->platform_ == xtd::platform_id::mac_os_x || this->platform_ == xtd::platform_id::ios;}
    
    /// @brief Determines whether the current platform is Unix family.
    /// @return true if the current platform is Unix family; otherwise, false.
    bool is_linux_platform() const noexcept {return this->platform_ == xtd::platform_id::unix || this->platform_ == xtd::platform_id::android;}
    
    /// @brief Determines whether the current platform is Windows family.
    /// @return true if the current platform is Windows family; otherwise, false.
    bool is_windows_platform() const noexcept {return this->platform_ == xtd::platform_id::win32_nt || this->platform_ == xtd::platform_id::win32s || this->platform_ == xtd::platform_id::win32_windows || this->platform_ == xtd::platform_id::win_ce || this->platform_ == xtd::platform_id::xbox;}
    
    /// @brief Gets a System::xtd::platform_id enumeration value that identifies the operating system platform.
    /// @return xtd::platform_id One of the xtd::platform_id values.
    xtd::platform_id platform() const noexcept {return this->platform_;}
    
    /// @brief Gets the service pack version represented by this operating_system object.
    /// @return string The service pack version, if service packs are supported and at least one is installed; otherwise, an empty string ("").
    /// @remarks A service pack is used to distribute software updates for the operating system on which it is installed. However, not every operating system uses service packs.
    /// @remarks The service pack version, if available, is already correctly formatted for display.
    std::string service_pack() const noexcept {return this->service_pack_;}
    
    /// @brief Gets a System::Version object that identifies the operating system.
    /// @return Version A Version object that describes the major version, minor version, build, and revision numbers for the operating system.
    /// @remarks For Window system only: See http://msdn.microsoft.com/library/windows/desktop/ms724832.aspx on the Windows Dev Center for a list of Windows operating system versions and their corresponding version numbers.
    const xtd::version& version() const noexcept {return this->version_;}
    
    /// @brief Gets the concatenated string representation of the platform identifier, version, and service pack that are currently installed on the operating system.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    /// @remarks By default, the value returned by version_string is the same as the value returned by the to_string method.
    std::string version_string() const noexcept {
      if (!this->version_string_.empty()) return this->version_string_;
      switch (this->platform_) {
        case xtd::platform_id::win32s: this->version_string_ = "Microsoft Win32S"; break;
        case xtd::platform_id::win32_windows: this->version_string_ = this->version_.major() > 4 || (this->version_.major() == 4 && this->version_.minor() > 0) ? "Microsoft Windows 98" : "Microsoft Windows 95"; break;
        case xtd::platform_id::win32_nt: this->version_string_ = "Microsoft Windows NT"; break;
        case xtd::platform_id::win_ce: this->version_string_ = "Microsoft Windows CE"; break;
        case xtd::platform_id::unix: this->version_string_ = "Unix"; break;
        case xtd::platform_id::xbox: this->version_string_ = "Xbox"; break;
        case xtd::platform_id::mac_os_x: this->version_string_ = "macOS"; break;
        case xtd::platform_id::ios: this->version_string_ = "IOs"; break;
        case xtd::platform_id::android: this->version_string_ = "Android"; break;
        case xtd::platform_id::unknown: this->version_string_ = "<Unknown>"; break;
      }
      this->version_string_ += " " + this->version_.to_string(3);
      if (!this->service_pack_.empty()) this->version_string_ += " " + this->service_pack();
      return this->version_string_;
    }
    
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    std::string to_string() const noexcept {return this->version_string();}
    
  private:
    xtd::platform_id platform_ = xtd::platform_id::unknown;
    xtd::version version_;
    std::string service_pack_;
    mutable std::string version_string_;
  };
}
