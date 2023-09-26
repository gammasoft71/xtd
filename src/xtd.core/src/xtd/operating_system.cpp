#include "../../include/xtd/operating_system"

using namespace xtd;

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version) : platform_(platform), version_(version) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack) : platform_(platform), version_(version), service_pack_(service_pack) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack, const xtd::ustring& desktop_environment) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack, const xtd::ustring& desktop_environment, const xtd::ustring& desktop_theme) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment), desktop_theme_(desktop_theme) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack, const xtd::ustring& desktop_environment, const xtd::ustring& desktop_theme, bool is_64_bit) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment), desktop_theme_(desktop_theme), is_64_bit_(is_64_bit) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::ustring& service_pack, const xtd::ustring& desktop_environment, const xtd::ustring& desktop_theme, bool is_64_bit, const xtd::distribution& distribution) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment), desktop_theme_(desktop_theme), is_64_bit_(is_64_bit), distribution_(distribution) {
}

ustring operating_system::desktop_environment() const noexcept {
  return desktop_environment_;
}

ustring operating_system::desktop_theme() const noexcept {
  return desktop_theme_;
}

distribution operating_system::distribution() const noexcept {
  return distribution_;
}

ustring operating_system::name() const noexcept {
  static auto operating_system_names = std::map<platform_id, ustring> {{platform_id::win32s, "Microsoft Win32S"}, {platform_id::win32_windows, "Microsoft Windows 95"}, {platform_id::win32_nt, "Microsoft Windows"}, {platform_id::win_ce, "Microsoft Windows CE"}, {platform_id::unix, "Unix"}, {platform_id::xbox, "Xbox"}, {platform_id::macos, "macOS"}, {platform_id::ios, "iOS"}, {platform_id::android, "Android"}, {platform_id::linux, "Linux"}, {platform_id::tvos, "tvOS"}, {platform_id::watchos, "watchOS"}, {platform_id::other, "Other"}, {platform_id::unknown, "<Unknown>"}};
  if (platform_ == xtd::platform_id::win32_windows && (version_.major() > 4 || (version_.major() == 4 && version_.minor() > 0))) return "Microsoft Windows 98";
  return operating_system_names[platform_];
}

platform_id operating_system::platform() const noexcept {
  return platform_;
}

ustring operating_system::service_pack() const noexcept {
  return service_pack_;
}

const xtd::version& operating_system::version() const noexcept {
  return version_;
}

ustring operating_system::version_string() const noexcept {
  if (!version_string_.empty()) return version_string_;
  version_string_ = ustring::format("{} {}", name(), version_.to_string(3));
  if (!service_pack_.empty()) version_string_ += ustring::format(" {}", service_pack());
  return version_string_;
}

bool operating_system::is_64_bit() const noexcept {
  return is_64_bit_;
}

bool operating_system::is_android() const noexcept {
  return platform_ == xtd::platform_id::android;
}

bool operating_system::is_ios() const noexcept {
  return platform_ == xtd::platform_id::ios;
}

bool operating_system::is_macos() const noexcept {
  return platform_ == xtd::platform_id::macos;
}

bool operating_system::is_macos_platform() const noexcept {
  return platform_ == xtd::platform_id::macos || platform_ == xtd::platform_id::ios || platform_ == xtd::platform_id::tvos || platform_ == xtd::platform_id::watchos;
}

bool operating_system::is_linux() const noexcept {
  return platform_ == xtd::platform_id::linux;
}

bool operating_system::is_unix_platform() const noexcept {
  return platform_ == xtd::platform_id::unix || platform_ == xtd::platform_id::linux || platform_ == xtd::platform_id::android;
}

bool operating_system::is_tvos() const noexcept {
  return platform_ == xtd::platform_id::tvos;
}

bool operating_system::is_watchos() const noexcept {
  return platform_ == xtd::platform_id::watchos;
}

bool operating_system::is_windows() const noexcept {
  return platform_ == xtd::platform_id::win32_nt || platform_ == xtd::platform_id::win32s || platform_ == xtd::platform_id::win32_windows;
}

bool operating_system::is_windows_ce() const noexcept {
  return platform_ == xtd::platform_id::win_ce;
}

bool operating_system::is_windows_platform() const noexcept {
  return platform_ == xtd::platform_id::win32_nt || platform_ == xtd::platform_id::win32s || platform_ == xtd::platform_id::win32_windows || platform_ == xtd::platform_id::win_ce || platform_ == xtd::platform_id::xbox;
}

bool operating_system::is_xbox() const noexcept {
  return platform_ == xtd::platform_id::xbox;
}

ustring operating_system::to_string() const noexcept {
  return version_string();
}
