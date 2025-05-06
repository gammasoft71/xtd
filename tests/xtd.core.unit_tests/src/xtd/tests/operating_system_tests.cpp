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
  };
}
