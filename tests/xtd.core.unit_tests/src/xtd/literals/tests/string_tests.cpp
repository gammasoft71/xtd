#include <xtd/literals/string>
#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(string_tests) {
        auto test_method_(_s_operator_on_char_ptr) {
          auto v = "string"_s;
          assert::is_instance_of<string>(v);
          assert::are_equal("string", v);
        }
        
        auto test_method_(_s_operator_on_char8_ptr) {
          auto v = u8"string"_s;
          assert::is_instance_of<string>(v);
          assert::are_equal("string", v);
        }
        
        auto test_method_(_s_operator_on_char16_ptr) {
          auto v = u"string"_s;
          assert::is_instance_of<string>(v);
          assert::are_equal("string", v);
        }
        
        auto test_method_(_s_operator_on_char32_ptr) {
          auto v = U"string"_s;
          assert::is_instance_of<string>(v);
          assert::are_equal("string", v);
        }
        
        auto test_method_(_s_operator_on_wchar_ptr) {
          auto v = L"string"_s;
          assert::is_instance_of<string>(v);
          assert::are_equal("string", v);
        }
        
        auto test_method_(_sb_operator_on_long_double) {
          auto v = 42.0_sb;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
        }
        
        auto test_method_(_sb_operator_on_unsigned_long_long) {
          auto v = 42_sb;
          assert::is_instance_of<string>(v);
          assert::are_equal("101010", v);
        }
        
        auto test_method_(_sb2_operator_on_long_double) {
          auto v = 42.0_sb2;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
        }
        
        auto test_method_(_sb2_operator_on_unsigned_long_long) {
          auto v = 42_sb2;
          assert::is_instance_of<string>(v);
          assert::are_equal("101010", v);
        }
        
        auto test_method_(_sb4_operator_on_long_double) {
          auto v = 42.0_sb4;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
        }
        
        auto test_method_(_sb4_operator_on_unsigned_long_long) {
          auto v = 42_sb4;
          assert::is_instance_of<string>(v);
          assert::are_equal("101010", v);
        }
        
        auto test_method_(_sb8_operator_on_long_double) {
          auto v = 42.0_sb8;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
        }
        
        auto test_method_(_sb8_operator_on_unsigned_long_long) {
          auto v = 42_sb8;
          assert::is_instance_of<string>(v);
          assert::are_equal("00101010", v);
        }
        
        auto test_method_(_sb16_operator_on_long_double) {
          auto v = 42.0_sb16;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
        }
        
        auto test_method_(_sb16_operator_on_unsigned_long_long) {
          auto v = 42_sb16;
          assert::is_instance_of<string>(v);
          assert::are_equal("0000000000101010", v);
        }
        
        auto test_method_(_sb32_operator_on_long_double) {
          auto v = 42.0_sb32;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("100000001000101000000000000000000000000000000000000000000000000", v);
        }
        
        auto test_method_(_sb32_operator_on_unsigned_long_long) {
          auto v = 42_sb32;
          assert::is_instance_of<string>(v);
          assert::are_equal("00000000000000000000000000101010", v);
        }
        
        auto test_method_(_sb64_operator_on_long_double) {
          auto v = 42.0_sb64;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("0100000001000101000000000000000000000000000000000000000000000000", v);
        }
        
        auto test_method_(_sb64_operator_on_unsigned_long_long) {
          auto v = 42_sb64;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("0000000000000000000000000000000000000000000000000000000000101010", v);
        }
        
        auto test_method_(_sd_operator_on_long_double) {
          auto v = 42.0_sd;
          assert::is_instance_of<string>(v);
          assert::are_equal("42", v);
        }
        
        auto test_method_(_sd_operator_on_unsigned_long_long) {
          auto v = 42_sd;
          assert::is_instance_of<string>(v);
          assert::are_equal("42", v);
        }
        
        auto test_method_(_sx_operator_on_long_double) {
          auto v = 42.0_sx;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("0x1.5p+5", v);
        }
        
        auto test_method_(_sx_operator_on_unsigned_long_long) {
          auto v = 42_sx;
          assert::is_instance_of<string>(v);
          assert::are_equal("2a", v);
        }
        
        auto test_method_(_sx2_operator_on_unsigned_long_long) {
          auto v = 42_sx2;
          assert::is_instance_of<string>(v);
          assert::are_equal("2a", v);
        }
        
        auto test_method_(_sx4_operator_on_unsigned_long_long) {
          auto v = 42_sx4;
          assert::is_instance_of<string>(v);
          assert::are_equal("002a", v);
        }
        
        auto test_method_(_sx8_operator_on_unsigned_long_long) {
          auto v = 42_sx8;
          assert::is_instance_of<string>(v);
          assert::are_equal("0000002a", v);
        }
        
        auto test_method_(_sx16_operator_on_unsigned_long_long) {
          auto v = 42_sx16;
          assert::is_instance_of<string>(v);
          assert::are_equal("000000000000002a", v);
        }
        
        auto test_method_(_sX_operator_on_long_double) {
          auto v = 42.0_sX;
          assert::is_instance_of<string>(v);
          if (environment::os_version().is_macos()) assert::are_equal("0x1.5p+5", v);
        }
        
        auto test_method_(_sX_operator_on_unsigned_long_long) {
          auto v = 42_sX;
          assert::is_instance_of<string>(v);
          assert::are_equal("2A", v);
        }
        
        auto test_method_(_sX2_operator_on_unsigned_long_long) {
          auto v = 42_sX2;
          assert::is_instance_of<string>(v);
          assert::are_equal("2A", v);
        }
        
        auto test_method_(_sX4_operator_on_unsigned_long_long) {
          auto v = 42_sX4;
          assert::is_instance_of<string>(v);
          assert::are_equal("002A", v);
        }
        
        auto test_method_(_sX8_operator_on_unsigned_long_long) {
          auto v = 42_sX8;
          assert::is_instance_of<string>(v);
          assert::are_equal("0000002A", v);
        }
        
        auto test_method_(_sX16_operator_on_unsigned_long_long) {
          auto v = 42_sX16;
          assert::is_instance_of<string>(v);
          assert::are_equal("000000000000002A", v);
        }
      };
    }
  }
}
