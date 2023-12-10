/// @file
/// @brief Contains xtd::operating_system class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "optional.h"
#include "distribution.h"
#include "object.h"
#include "platform_id.h"
#include "ustring.h"
#include "version.h"
#include <map>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents information about an operating system, such as the version and platform identifier. This class cannot be inherited.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks The operating_system class contains information about an operating system.
  /// @remarks For information about the current runtime operating system, retrieve the operating_system object returned by the xtd::environment::os_version method.
  /// @remarks By design, the operating_system class is not a general purpose means of describing an operating system, and you cannot derive a more inclusive type from the operating_system class. If you need a type to contain other information about an operating system, create your own type, then include a field of type operating_system and any additional fields or methods that you require.
  class operating_system final : public object {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version);
    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @param service_pack A string, such as "Service Pack 3", that represent the service pack. If no Service Pack has been installed, the string must be empty.
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack);
    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @param service_pack A string, such as "Service Pack 3", that represent the service pack. If no Service Pack has been installed, the string must be empty.
    /// @param desktop_environment A string, such as "gnome", "kde", "windows", "macos".
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack, const xtd::ustring& desktop_environment);
    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @param service_pack A string, such as "Service Pack 3", that represent the service pack. If no Service Pack has been installed, the string must be empty.
    /// @param desktop_environment A string, such as "gnome", "kde", "windows", "macos".
    /// @param desktop_theme A string, such as "Adwaita", "Breeze", "windows dark", "macos dark", ...
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack, const xtd::ustring& desktop_environment, const xtd::ustring& desktop_theme);
    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @param service_pack A string, such as "Service Pack 3", that represent the service pack. If no Service Pack has been installed, the string must be empty.
    /// @param desktop_environment A string, such as "gnome", "kde", "windows", "macos".
    /// @param desktop_theme A string, such as "Adwaita", "Breeze", "windows dark", "macos dark", ...
    /// @param is_64_bit True if Operating System is 64 bits; otherwise false.
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack, const xtd::ustring& desktop_environment, const xtd::ustring& desktop_theme, bool is_64_bit);
    /// @brief Initializes a new instance of the operating_system class, using the specified platform identifier value and version object.
    /// @param platform One of the xtd::platform_id values that indicates the operating system platform.
    /// @param version A Version object that indicates the version of the operating system.
    /// @param service_pack A string, such as "Service Pack 3", that represent the service pack. If no Service Pack has been installed, the string must be empty.
    /// @param desktop_environment A string, such as "gnome", "kde", "windows", "macos".
    /// @param desktop_theme A string, such as "Adwaita", "Breeze", "windows dark", "macos dark", ...
    /// @param is_64_bit True if Operating System is 64 bits; otherwise false.
    /// @param distribution An xtd::distribution that contains the operating system distribution informations.
    /// @exception ArgumentNullException version is null.
    /// @exception ArgumentException platform is not a xtd::platform_id enumeration value.
    operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack, const xtd::ustring& desktop_environment, const xtd::ustring& desktop_theme, bool is_64_bit, const xtd::distribution& distribution);
    /// @}
    
    /// @cond
    operating_system() = default;
    operating_system(const operating_system&) = default;
    operating_system& operator =(const operating_system&) = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets the desktop environment.
    /// @return string The desktop environment for the operating system, if not found empty string ("").
    /// @remarks On Windows is always "windows".
    /// @remarks On macOS is always "macos".
    /// @remarks On linux it can be "budgie", "cinnamon",  "deepin", "Enlightenment", "étoilé", "gnome", "kde", "lxqt", "mate", "pantheon", "razor-qt", "unity", "xfce".
    xtd::ustring desktop_environment() const noexcept;
    
    /// @brief Gets the desktop theme.
    /// @return string The desktop theme for the operating system, if not found empty string ("").
    /// @remarks On Windows is "windows" or "windows dark".
    /// @remarks On macOS is "macos" or 'macos dark'.
    /// @remarks On linux it can be "Adwaita", "Adwaita-dark",  "Breeze", "Breeze-Dark", "Yaru", "Yaru-dark", "Yaru-light", ...
    xtd::ustring desktop_theme() const noexcept;
    
    /// @brief Gets the distribution.
    /// @return An xtd::distribution that contains the operating system distribution informations.
    xtd::distribution distribution() const noexcept;
    
    /// @brief Gets the concatenated string representation of the platform identifier.
    /// @return The string representation of the values returned by the platform.
    xtd::ustring name() const noexcept;
    
    /// @brief Gets a xtd::platform_id enumeration value that identifies the operating system platform.
    /// @return xtd::platform_id One of the xtd::platform_id values.
    xtd::platform_id platform() const noexcept;
    
    /// @brief Gets the service pack version represented by this operating_system object.
    /// @return string The service pack version, if service packs are supported and at least one is installed; otherwise, an empty string ("").
    /// @remarks A service pack is used to distribute software updates for the operating system on which it is installed. However, not every operating system uses service packs.
    /// @remarks The service pack version, if available, is already correctly formatted for display.
    xtd::ustring service_pack() const noexcept;
    
    /// @brief Gets a xtd::version object that identifies the operating system.
    /// @return Version A Version object that describes the major version, minor version, build, and revision numbers for the operating system.
    /// @remarks For Window system only: See http://msdn.microsoft.com/library/windows/desktop/ms724832.aspx on the Windows Dev Center for a list of Windows operating system versions and their corresponding version numbers.
    const xtd::version& version() const noexcept;
    
    /// @brief Gets the concatenated string representation of the platform identifier, version, and service pack that are currently installed on the operating system.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    /// @remarks By default, the value returned by version_string is the same as the value returned by the to_string method.
    xtd::ustring version_string() const noexcept;
    /// @}
    
    /// @name Methods
    
    /// @{
    /// @brief Determines whether the current operating system is a 64-bit operating system.
    /// @return true if the operating system is 64-bit; otherwise, false.
    bool is_64_bit() const noexcept;
    
    /// @brief Determines whether the current platform is Android.
    /// @return true if the current platform is Android; otherwise, false.
    bool is_android() const noexcept;
    
    /// @brief Determines whether the current platform is FreeBSD.
    /// @return true if the current platform is Android; otherwise, false.
    bool is_free_bsd() const noexcept;
    
    /// @brief Determines whether the current platform is iOS.
    /// @return true if the current platform is iOS; otherwise, false.
    bool is_ios() const noexcept;
    
    /// @brief Determines whether the current platform is macOS.
    /// @return true if the current platform is macOS; otherwise, false.
    bool is_macos() const noexcept;
    
    /// @brief Determines whether the current platform is macOS family.
    /// @return true if the current platform is macOS family; otherwise, false.
    bool is_macos_platform() const noexcept;
    
    /// @brief Determines whether the current platform is Linux.
    /// @return true if the current platform is Linux; otherwise, false.
    bool is_linux() const noexcept;
    
    /// @brief Determines whether the current platform is Unix family.
    /// @return true if the current platform is Unix family; otherwise, false.
    bool is_unix_platform() const noexcept;
    
    /// @brief Determines whether the current platform is tvOS family.
    /// @return true if the current platform is macOS family; otherwise, false.
    bool is_tvos() const noexcept;
    
    /// @brief Determines whether the current platform is watchOS.
    /// @return true if the current platform is watchOS; otherwise, false.
    bool is_watchos() const noexcept;
    
    /// @brief Determines whether the current platform is Windows.
    /// @return true if the current platform is Windows; otherwise, false.
    bool is_windows() const noexcept;
    
    /// @brief Determines whether the current platform is Windows CE.
    /// @return true if the current platform is Windows CE; otherwise, false.
    bool is_windows_ce() const noexcept;
    
    /// @brief Determines whether the current platform is Windows family.
    /// @return true if the current platform is Windows family; otherwise, false.
    bool is_windows_platform() const noexcept;
    
    /// @brief Determines whether the current platform is xbox.
    /// @return true if the current platform is xbox; otherwise, false.
    bool is_xbox() const noexcept;
    
    /// @brief Converts the value of this operating_system object to its equivalent string representation.
    /// @return The string representation of the values returned by the platform, version, and service_pack methods.
    xtd::ustring to_string() const noexcept override;
    /// @}
    
  private:
    xtd::platform_id platform_ = xtd::platform_id::unknown;
    xtd::version version_;
    xtd::ustring service_pack_;
    xtd::ustring desktop_environment_;
    xtd::ustring desktop_theme_;
    bool is_64_bit_ = false;
    xtd::distribution distribution_;
    mutable xtd::ustring version_string_;
  };
}
