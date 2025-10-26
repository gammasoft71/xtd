#include "../../include/xtd/operating_system.hpp"

using namespace xtd;

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version) : platform_(platform), version_(version) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::string& service_pack) : platform_(platform), version_(version), service_pack_(service_pack) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::string& service_pack, const xtd::string& desktop_environment) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::string& service_pack, const xtd::string& desktop_environment, const xtd::string& desktop_theme) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment), desktop_theme_(desktop_theme) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::string& service_pack, const xtd::string& desktop_environment, const xtd::string& desktop_theme, bool is_64_bit) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment), desktop_theme_(desktop_theme), is_64_bit_(is_64_bit) {
}

operating_system::operating_system(xtd::platform_id platform, const xtd::version& version, const xtd::string& service_pack, const xtd::string& desktop_environment, const xtd::string& desktop_theme, bool is_64_bit, const xtd::distribution& distribution) : platform_(platform), version_(version), service_pack_(service_pack), desktop_environment_(desktop_environment), desktop_theme_(desktop_theme), is_64_bit_(is_64_bit), distribution_(distribution) {
}

string operating_system::desktop_environment() const noexcept {
  return desktop_environment_;
}

string operating_system::desktop_theme() const noexcept {
  return desktop_theme_;
}

distribution operating_system::distribution() const noexcept {
  return distribution_;
}

string operating_system::name() const noexcept {
  static auto operating_system_names = std::map<platform_id, string> {{platform_id::win32s, "Microsoft Win32S"}, {platform_id::win32_windows, "Microsoft Windows 95"}, {platform_id::win32_nt, "Microsoft Windows"}, {platform_id::win_ce, "Microsoft Windows CE"}, {platform_id::unix, "Unix"}, {platform_id::xbox, "Xbox"}, {platform_id::macos, "macOS"}, {platform_id::ios, "iOS"}, {platform_id::android, "Android"}, {platform_id::linux, "Linux"}, {platform_id::tvos, "tvOS"}, {platform_id::watchos, "watchOS"}, {platform_id::free_bsd, "FreeBSD"}, {platform_id::haiku, "Haiku"}, {platform_id::serenityos, "SerenityOS"}, {platform_id::aix, "AIX"}, {platform_id::mingw, "MINGW"}, {platform_id::msys, "MSYS"}, {platform_id::other, "Other"}, {platform_id::unknown, "<Unknown>"}};
  if (platform_ == xtd::platform_id::win32_windows && (version_.major() > 4 || (version_.major() == 4 && version_.minor() > 0))) return "Microsoft Windows 98";
  auto it = operating_system_names.find(platform_);
  return it != operating_system_names.end() ? it->second : "<Unknown>";
}

platform_id operating_system::platform() const noexcept {
  return platform_;
}

string operating_system::service_pack() const noexcept {
  return service_pack_;
}

const xtd::version& operating_system::version() const noexcept {
  return version_;
}

string operating_system::version_string() const noexcept {
  if (!xtd::string::is_empty(version_string_)) return version_string_;
  version_string_ = string::format("{} {}", name(), version_.to_string(version_.build() >= 0 ? 3 : 2));
  if (!xtd::string::is_empty(service_pack_)) version_string_ += string::format(" {}", service_pack());
  return version_string_;
}

bool operating_system::is_64_bit() const noexcept {
  return is_64_bit_;
}

bool operating_system::is_aix() const noexcept {
  return platform_ == xtd::platform_id::aix;
}

bool operating_system::is_android() const noexcept {
  return platform_ == xtd::platform_id::android;
}

bool operating_system::is_apple_platform() const noexcept {
  return is_darwin();
}

bool operating_system::is_bsd_platform() const noexcept {
  return is_free_bsd() || is_darwin();
}

bool operating_system::is_darwin() const noexcept {
  return is_macos() || is_ios() || is_tvos() || is_watchos();
}

bool operating_system::is_free_bsd() const noexcept {
  return platform_ == xtd::platform_id::free_bsd;
}

bool operating_system::is_haiku() const noexcept {
  return platform_ == xtd::platform_id::haiku;
}

bool operating_system::is_serenityos() const noexcept {
  return platform_ == xtd::platform_id::serenityos;
}

bool operating_system::is_ios() const noexcept {
  return platform_ == xtd::platform_id::ios;
}

bool operating_system::is_linux() const noexcept {
  return platform_ == xtd::platform_id::linux;
}

bool operating_system::is_macos() const noexcept {
  return platform_ == xtd::platform_id::macos;
}

bool operating_system::is_macos_platform() const noexcept {
  return is_apple_platform();
}

bool operating_system::is_mingw() const noexcept {
  return platform_ == xtd::platform_id::mingw;
}

bool operating_system::is_msys() const noexcept {
  return platform_ == xtd::platform_id::msys;
}

bool operating_system::is_posix() const noexcept {
  return platform_ == xtd::platform_id::posix;
}

bool operating_system::is_posix_platform() const noexcept {
  return platform_ == xtd::platform_id::posix || is_unix_platform();
}

bool operating_system::is_unix_platform() const noexcept {
  return platform_ == xtd::platform_id::unix || is_aix() || is_android() || is_free_bsd() || is_haiku() || is_serenityos() || is_linux() || is_darwin();
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
  return is_windows() || is_windows_ce() || is_mingw() || is_msys() || is_xbox();
}

bool operating_system::is_xbox() const noexcept {
  return platform_ == xtd::platform_id::xbox;
}

size operating_system::get_hash_code() const noexcept {
  return hash_code::combine(platform_, version_, service_pack_, desktop_environment_, desktop_theme_, is_64_bit_, distribution_);
}

string operating_system::to_string() const noexcept {
  return version_string();
}
