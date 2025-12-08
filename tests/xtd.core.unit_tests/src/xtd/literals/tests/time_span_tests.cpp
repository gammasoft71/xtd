#include <xtd/literals/time_span>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd {
  inline namespace literals {
    namespace tests {
      class test_class_(time_span_tests) {
        auto test_method_(_h_operator_on_on_unsigned_long_long) {
          auto v = 42_h;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {1, 18, 0, 0}, v);
        }
        
        auto test_method_(_m_operator_on_on_unsigned_long_long) {
          auto v = 42_m;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {0, 42, 0}, v);
        }
        
        auto test_method_(_min_operator_on_on_unsigned_long_long) {
          auto v = 42_min;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {0, 42, 0}, v);
        }
        
        auto test_method_(_ms_operator_on_on_unsigned_long_long) {
          auto v = 42_ms;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {0, 0, 0, 0, 42}, v);
        }
        
        auto test_method_(_ns_operator_on_on_unsigned_long_long) {
          auto v = 42_ns;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {0, 0, 0, 0, 0, 0, 42}, v);
        }
        
        auto test_method_(_s_operator_on_on_unsigned_long_long) {
          auto v = 42_s;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {0, 0, 42}, v);
        }
        
        auto test_method_(_t_operator_on_on_unsigned_long_long) {
          auto v = 42_t;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {42}, v);
        }
        
        auto test_method_(_ts_operator_on_on_char_ptr) {
          auto v = "6:12:14"_ts;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {6, 12, 14}, v);
        }
        
        auto test_method_(_ts_operator_on_on_char8_ptr) {
          auto v = u8"6:12:14"_ts;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {6, 12, 14}, v);
        }
        
        auto test_method_(_ts_operator_on_on_char16_ptr) {
          auto v = u"6:12:14"_ts;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {6, 12, 14}, v);
        }
        
        auto test_method_(_ts_operator_on_on_char32_ptr) {
          auto v = U"6:12:14"_ts;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {6, 12, 14}, v);
        }
        
        auto test_method_(_ts_operator_on_on_wchar_ptr) {
          auto v = L"6:12:14"_ts;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {6, 12, 14}, v);
        }
        
        auto test_method_(_us_operator_on_on_unsigned_long_long) {
          auto v = 42_us;
          assert::is_instance_of<time_span>(v);
          assert::are_equal(time_span {0, 0, 0, 0, 0, 42}, v);
        }
        
        auto test_method_(many_time_span_suffixes) {
          assert::are_equal(xtd::time_span {0, 12, 24, 1, 500}, 12_h + 24_m +  1_s + 500_ms);
        }
      };
    }
  }
}
