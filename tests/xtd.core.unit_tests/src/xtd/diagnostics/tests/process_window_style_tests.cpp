#include <xtd/diagnostics/process_window_style>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(process_window_style_tests) {
  public:
    void test_method_(normal) {
      assert::are_equal(0, enum_object<>::to_int32(process_window_style::normal), csf_);
      assert::are_equal("normal", enum_object<>::to_string(process_window_style::normal), csf_);
      assert::are_equal(process_window_style::normal, enum_object<>::parse<process_window_style>("normal"), csf_);
    }
    
    void test_method_(hidden) {
      assert::are_equal(1, enum_object<>::to_int32(process_window_style::hidden), csf_);
      assert::are_equal("hidden", enum_object<>::to_string(process_window_style::hidden), csf_);
      assert::are_equal(process_window_style::hidden, enum_object<>::parse<process_window_style>("hidden"), csf_);
    }
    
    void test_method_(minimized) {
      assert::are_equal(2, enum_object<>::to_int32(process_window_style::minimized), csf_);
      assert::are_equal("minimized", enum_object<>::to_string(process_window_style::minimized), csf_);
      assert::are_equal(process_window_style::minimized, enum_object<>::parse<process_window_style>("minimized"), csf_);
    }
    
    void test_method_(maximized) {
      assert::are_equal(3, enum_object<>::to_int32(process_window_style::maximized), csf_);
      assert::are_equal("maximized", enum_object<>::to_string(process_window_style::maximized), csf_);
      assert::are_equal(process_window_style::maximized, enum_object<>::parse<process_window_style>("maximized"), csf_);
    }
  };
}
