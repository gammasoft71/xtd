#include <xtd/operating_system>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(operating_system_tests) {
    void test_method_(create_with_default_ctor) {
      auto os = operating_system {};
      assert::is_empty(os.desktop_environment());
      assert::is_empty(os.desktop_theme());
      assert::is_empty(os.distribution().name());
      assert::are_equal("<Unknown>", os.name());
      assert::are_equal(platform_id::unknown, os.platform());
      assert::is_empty(os.service_pack());
      assert::are_equal(xtd::version {}, os.version());
      assert::are_equal("<Unknown> 0.0", os.version_string());
      assert::is_false(os.is_64_bit());
    }
    
    void test_method_(create_with_platform_id_and_version) {
      auto os = operating_system {platform_id::free_bsd, xtd::version {14, 2}};
      assert::is_empty(os.desktop_environment());
      assert::is_empty(os.desktop_theme());
      assert::is_empty(os.distribution().name());
      assert::are_equal("FreeBSD", os.name());
      assert::are_equal(platform_id::free_bsd, os.platform());
      assert::is_empty(os.service_pack());
      assert::are_equal(xtd::version {14, 2}, os.version());
      assert::are_equal("FreeBSD 14.2", os.version_string());
      assert::is_false(os.is_64_bit());
    }
    
    void test_method_(create_with_platform_id_version_and_service_pack) {
      auto os = operating_system {platform_id::free_bsd, xtd::version {14, 2}, "SP 28"};
      assert::is_empty(os.desktop_environment());
      assert::is_empty(os.desktop_theme());
      assert::is_empty(os.distribution().name());
      assert::are_equal("FreeBSD", os.name());
      assert::are_equal(platform_id::free_bsd, os.platform());
      assert::are_equal("SP 28", os.service_pack());
      assert::are_equal(xtd::version {14, 2}, os.version());
      assert::are_equal("FreeBSD 14.2 SP 28", os.version_string());
      assert::is_false(os.is_64_bit());
    }
    
    void test_method_(create_with_platform_id_version_service_pack_and_desktop_environment) {
      auto os = operating_system {platform_id::free_bsd, xtd::version {14, 2}, "SP 28", "gnome"};
      assert::are_equal("gnome", os.desktop_environment());
      assert::is_empty(os.desktop_theme());
      assert::is_empty(os.distribution().name());
      assert::are_equal("FreeBSD", os.name());
      assert::are_equal(platform_id::free_bsd, os.platform());
      assert::are_equal("SP 28", os.service_pack());
      assert::are_equal(xtd::version {14, 2}, os.version());
      assert::are_equal("FreeBSD 14.2 SP 28", os.version_string());
      assert::is_false(os.is_64_bit());
    }
    
    void test_method_(create_with_platform_id_version_service_pack_desktop_environment_and_desktop_theme) {
      auto os = operating_system {platform_id::free_bsd, xtd::version {14, 2}, "SP 28", "gnome", "Adwaita-dark"};
      assert::are_equal("gnome", os.desktop_environment());
      assert::are_equal("Adwaita-dark", os.desktop_theme());
      assert::is_empty(os.distribution().name());
      assert::are_equal("FreeBSD", os.name());
      assert::are_equal(platform_id::free_bsd, os.platform());
      assert::are_equal("SP 28", os.service_pack());
      assert::are_equal(xtd::version {14, 2}, os.version());
      assert::are_equal("FreeBSD 14.2 SP 28", os.version_string());
      assert::is_false(os.is_64_bit());
    }
    
    void test_method_(create_with_platform_id_version_service_pack_desktop_environment_desktop_theme_and_is_64_bit_to_false) {
      auto os = operating_system {platform_id::free_bsd, xtd::version {14, 2}, "SP 28", "gnome", "Adwaita-dark", false};
      assert::are_equal("gnome", os.desktop_environment());
      assert::are_equal("Adwaita-dark", os.desktop_theme());
      assert::is_empty(os.distribution().name());
      assert::are_equal("FreeBSD", os.name());
      assert::are_equal(platform_id::free_bsd, os.platform());
      assert::are_equal("SP 28", os.service_pack());
      assert::are_equal(xtd::version {14, 2}, os.version());
      assert::are_equal("FreeBSD 14.2 SP 28", os.version_string());
      assert::is_false(os.is_64_bit());
    }
    
    void test_method_(create_with_platform_id_version_service_pack_desktop_environment_desktop_theme_and_is_64_bit_to_true) {
      auto os = operating_system {platform_id::free_bsd, xtd::version {14, 2}, "SP 28", "gnome", "Adwaita-dark", true};
      assert::are_equal("gnome", os.desktop_environment());
      assert::are_equal("Adwaita-dark", os.desktop_theme());
      assert::is_empty(os.distribution().name());
      assert::are_equal("FreeBSD", os.name());
      assert::are_equal(platform_id::free_bsd, os.platform());
      assert::are_equal("SP 28", os.service_pack());
      assert::are_equal(xtd::version {14, 2}, os.version());
      assert::are_equal("FreeBSD 14.2 SP 28", os.version_string());
      assert::is_true(os.is_64_bit());
    }
    
    void test_method_(create_with_platform_id_version_service_pack_desktop_environment_desktop_theme_is_64_bit_and_distribution) {
      auto os = operating_system {platform_id::free_bsd, xtd::version {14, 2}, "SP 28", "gnome", "Adwaita-dark", true, xtd::distribution {"FreeBSD", xtd::version {14, 2}, "", "The Power To Serve", "freebsd", {"freebsd", "bsd", "unix"}, "FreeBSD 14.2", uri {"https://www.freebsd.org"}, uri {"https://www.freebsd.org/support/"}}};
      assert::are_equal("gnome", os.desktop_environment());
      assert::are_equal("Adwaita-dark", os.desktop_theme());
      assert::are_equal("FreeBSD", os.distribution().name());
      assert::are_equal("FreeBSD", os.name());
      assert::are_equal(platform_id::free_bsd, os.platform());
      assert::are_equal("SP 28", os.service_pack());
      assert::are_equal(xtd::version {14, 2}, os.version());
      assert::are_equal("FreeBSD 14.2 SP 28", os.version_string());
      assert::is_true(os.is_64_bit());
    }
    
    void test_method_(desktop_environment) {
      assert::are_equal("", operating_system {platform_id::unknown, xtd::version {}, "", ""}.desktop_environment());
      assert::are_equal("macOS", operating_system {platform_id::unknown, xtd::version {}, "", "macOS"}.desktop_environment());
      assert::are_equal("AIX", operating_system {platform_id::unknown, xtd::version {}, "", "AIX"}.desktop_environment());
    }
    
    void test_method_(desktop_theme) {
      assert::are_equal("", operating_system {platform_id::unknown, xtd::version {}, "", "", ""}.desktop_theme());
      assert::are_equal("windows", operating_system {platform_id::unknown, xtd::version {}, "", "", "windows"}.desktop_theme());
      assert::are_equal("macos dark", operating_system {platform_id::unknown, xtd::version {}, "", "", "macos dark"}.desktop_theme());
    }
    
    void test_method_(distribution) {
      assert::is_empty(operating_system {platform_id::unknown, xtd::version {}, "", "", "", false, xtd::distribution {}}.distribution().name());
      assert::are_equal("macOS", operating_system {platform_id::unknown, xtd::version {}, "", "", "", false, xtd::distribution {"macOS", xtd::version {15, 4}, "Sequoia", "", "macos", {"macos"}, "macOS 15.4", uri {"https://www.apple.com/macos"}, uri {"https://support.apple.com/macos"}}}.distribution().name());
      assert::are_equal("AIX", operating_system {platform_id::unknown, xtd::version {}, "", "", "", false, xtd::distribution {"AIX", xtd::version {7, 3}, "", "", "aix", {"aix", "unix"}, "AIX 7.3", uri {"https://www.ibm.com/products/aix"}, uri {"https://www.ibm.com/support/fixcentral?lnk=flatitem"}}}.distribution().name());
    }
    
    void test_method_(name) {
      assert::are_equal("<Unknown>", operating_system {platform_id::unknown, xtd::version {}}.name());
      assert::are_equal("macOS", operating_system {platform_id::macos, xtd::version {}}.name());
      assert::are_equal("AIX", operating_system {platform_id::aix, xtd::version {}}.name());
    }
    
    void test_method_(platform) {
      assert::are_equal(platform_id::unknown, operating_system {platform_id::unknown, xtd::version {}}.platform());
      assert::are_equal(platform_id::macos, operating_system {platform_id::macos, xtd::version {}}.platform());
      assert::are_equal(platform_id::aix, operating_system {platform_id::aix, xtd::version {}}.platform());
    }
    
    void test_method_(service_pack) {
      assert::are_equal("Service Pack 1", operating_system {platform_id::unknown, xtd::version {}, "Service Pack 1"}.service_pack());
      assert::are_equal("SP 2", operating_system {platform_id::macos, xtd::version {}, "SP 2"}.service_pack());
      assert::is_empty(operating_system {platform_id::aix, xtd::version {}, ""}.service_pack());
    }
    
    void test_method_(version) {
      assert::are_equal(xtd::version {}, operating_system {platform_id::unknown, xtd::version {}}.version());
      assert::are_equal(xtd::version {1, 2}, operating_system {platform_id::macos, xtd::version {1, 2}}.version());
      assert::are_equal(xtd::version {1, 2, 3}, operating_system {platform_id::aix, xtd::version {1, 2, 3}}.version());
    }
    
    void test_method_(version_string) {
      assert::are_equal("<Unknown> 0.0", operating_system {platform_id::unknown, xtd::version {}}.version_string());
      assert::are_equal("macOS 1.2", operating_system {platform_id::macos, xtd::version {1, 2}}.version_string());
      assert::are_equal("AIX 1.2.3", operating_system {platform_id::aix, xtd::version {1, 2, 3}}.version_string());
      assert::are_equal("Microsoft Windows 1.2.3", operating_system {platform_id::win32_nt, xtd::version {1, 2, 3, 4}}.version_string());
    }
    
    void test_method_(is_64_bit) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_64_bit());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}, "Service pack", "environment", "theme", false}.is_64_bit());
      assert::is_true(operating_system {platform_id::aix, xtd::version {}, "Service pack", "environment", "theme", true}.is_64_bit());
    }
    
    void test_method_(is_aix) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_aix());
      assert::is_true(operating_system {platform_id::aix, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_aix());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_aix());
    }
    
    void test_method_(is_android) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_android());
      assert::is_true(operating_system {platform_id::android, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_android());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_android());
    }
    
    void test_method_(is_apple_platform) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_apple_platform());
      assert::is_true(operating_system {platform_id::macos, xtd::version {}}.is_apple_platform());
      assert::is_true(operating_system {platform_id::ios, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_apple_platform());
      assert::is_true(operating_system {platform_id::tvos, xtd::version {}}.is_apple_platform());
      assert::is_true(operating_system {platform_id::watchos, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_apple_platform());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_apple_platform());
    }
    
    void test_method_(is_bsd_platform) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_bsd_platform());
      assert::is_true(operating_system {platform_id::macos, xtd::version {}}.is_bsd_platform());
      assert::is_true(operating_system {platform_id::ios, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_bsd_platform());
      assert::is_true(operating_system {platform_id::tvos, xtd::version {}}.is_bsd_platform());
      assert::is_true(operating_system {platform_id::watchos, xtd::version {}}.is_bsd_platform());
      assert::is_true(operating_system {platform_id::free_bsd, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_bsd_platform());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_bsd_platform());
    }
    
    void test_method_(is_darwin) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_darwin());
      assert::is_true(operating_system {platform_id::macos, xtd::version {}}.is_darwin());
      assert::is_true(operating_system {platform_id::ios, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_darwin());
      assert::is_true(operating_system {platform_id::tvos, xtd::version {}}.is_darwin());
      assert::is_true(operating_system {platform_id::watchos, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_darwin());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_darwin());
    }
    
    void test_method_(is_free_bsd) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_free_bsd());
      assert::is_true(operating_system {platform_id::free_bsd, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_free_bsd());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_free_bsd());
    }
    
    void test_method_(is_haiku) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_haiku());
      assert::is_true(operating_system {platform_id::haiku, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_haiku());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_haiku());
    }
    
    void test_method_(is_serenityos){
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_serenityos());
      assert::is_true(operating_system {platform_id::serenityos, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_serenityos());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_serenityos());
    }
    
    void test_method_(is_ios) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_ios());
      assert::is_true(operating_system {platform_id::ios, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_ios());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_ios());
    }
    
    void test_method_(is_linux) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_linux());
      assert::is_true(operating_system {platform_id::linux, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_linux());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_linux());
    }
    
    void test_method_(is_macos) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_macos());
      assert::is_true(operating_system {platform_id::macos, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_macos());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_macos());
    }
    
    void test_method_(is_macos_platform) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_macos_platform());
      assert::is_true(operating_system {platform_id::macos, xtd::version {}}.is_macos_platform());
      assert::is_true(operating_system {platform_id::ios, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_macos_platform());
      assert::is_true(operating_system {platform_id::tvos, xtd::version {}}.is_macos_platform());
      assert::is_true(operating_system {platform_id::watchos, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_macos_platform());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_macos_platform());
    }
    
    void test_method_(is_mingw) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_mingw());
      assert::is_true(operating_system {platform_id::mingw, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_mingw());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_mingw());
    }
    
    void test_method_(is_msys) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_msys());
      assert::is_true(operating_system {platform_id::msys, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_msys());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_msys());
    }
    
    void test_method_(is_posix) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_posix());
      assert::is_true(operating_system {platform_id::posix, xtd::version {}}.is_posix());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_posix());
    }
    
    void test_method_(is_posix_platform) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_posix_platform());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_posix_platform());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_posix_platform());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_posix_platform());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::unix, xtd::version {}}.is_posix_platform());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::macos, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::ios, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::android, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::linux, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::tvos, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::watchos, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::free_bsd, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::haiku, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::serenityos, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::aix, xtd::version {}}.is_posix_platform());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_posix_platform());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_posix_platform());
      assert::is_true(operating_system {platform_id::posix, xtd::version {}}.is_posix_platform());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_posix_platform());
    }
    
    void test_method_(is_unix_platform) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_unix_platform());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_unix_platform());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_unix_platform());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_unix_platform());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::unix, xtd::version {}}.is_unix_platform());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::macos, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::ios, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::android, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::linux, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::tvos, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::watchos, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::free_bsd, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::haiku, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::serenityos, xtd::version {}}.is_unix_platform());
      assert::is_true(operating_system {platform_id::aix, xtd::version {}}.is_unix_platform());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_unix_platform());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_unix_platform());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_unix_platform());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_unix_platform());
    }
    
    void test_method_(is_tvos) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_tvos());
      assert::is_true(operating_system {platform_id::tvos, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_tvos());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_tvos());
    }
    
    void test_method_(is_watchos) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_watchos());
      assert::is_true(operating_system {platform_id::watchos, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_watchos());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_watchos());
    }
    
    void test_method_(is_windows) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_windows());
      assert::is_true(operating_system {platform_id::win32s, xtd::version {}}.is_windows());
      assert::is_true(operating_system {platform_id::win32_windows, xtd::version {}}.is_windows());
      assert::is_true(operating_system {platform_id::win32_nt, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_windows());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_windows());
    }
    
    void test_method_(is_windows_ce) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_windows_ce());
      assert::is_true(operating_system {platform_id::win_ce, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::xbox, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_windows_ce());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_windows_ce());
    }
    
    void test_method_(is_windows_platform) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_windows_platform());
      assert::is_true(operating_system {platform_id::win32s, xtd::version {}}.is_windows_platform());
      assert::is_true(operating_system {platform_id::win32_windows, xtd::version {}}.is_windows_platform());
      assert::is_true(operating_system {platform_id::win32_nt, xtd::version {}}.is_windows_platform());
      assert::is_true(operating_system {platform_id::win_ce, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_windows_platform());
      assert::is_true(operating_system {platform_id::xbox, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_windows_platform());
      assert::is_true(operating_system {platform_id::mingw, xtd::version {}}.is_windows_platform());
      assert::is_true(operating_system {platform_id::msys, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_windows_platform());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_windows_platform());
    }
    
    void test_method_(is_xbox) {
      assert::is_false(operating_system {platform_id::unknown, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::win32s, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::win32_windows, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::win32_nt, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::win_ce, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::unix, xtd::version {}}.is_xbox());
      assert::is_true(operating_system {platform_id::xbox, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::macos, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::ios, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::android, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::linux, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::tvos, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::watchos, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::free_bsd, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::haiku, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::serenityos, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::aix, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::mingw, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::msys, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::posix, xtd::version {}}.is_xbox());
      assert::is_false(operating_system {platform_id::other, xtd::version {}}.is_xbox());
    }
    
    void test_method_(to_string) {
      assert::are_equal("<Unknown> 0.0", operating_system {platform_id::unknown, xtd::version {}}.to_string());
      assert::are_equal("macOS 1.2", operating_system {platform_id::macos, xtd::version {1, 2}}.to_string());
      assert::are_equal("AIX 1.2.3", operating_system {platform_id::aix, xtd::version {1, 2, 3}}.to_string());
      assert::are_equal("Microsoft Windows 1.2.3", operating_system {platform_id::win32_nt, xtd::version {1, 2, 3, 4}}.to_string());
    }
  };
}
