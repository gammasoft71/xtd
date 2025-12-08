#include <xtd/diagnostics/trace_level>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace xtd::diagnostics::tests {
  class test_class_(trace_level_tests) {
    auto test_method_(off) {
      assert::are_equal(0, enum_object<>::to_int32(trace_level::off));
      assert::are_equal("off", enum_object<>::to_string(trace_level::off));
      assert::are_equal(trace_level::off, enum_object<>::parse<trace_level>("off"));
    }
    
    auto test_method_(error) {
      assert::are_equal(1, enum_object<>::to_int32(trace_level::error));
      assert::are_equal("error", enum_object<>::to_string(trace_level::error));
      assert::are_equal(trace_level::error, enum_object<>::parse<trace_level>("error"));
    }
    
    auto test_method_(warning) {
      assert::are_equal(2, enum_object<>::to_int32(trace_level::warning));
      assert::are_equal("warning", enum_object<>::to_string(trace_level::warning));
      assert::are_equal(trace_level::warning, enum_object<>::parse<trace_level>("warning"));
    }
    
    auto test_method_(info) {
      assert::are_equal(3, enum_object<>::to_int32(trace_level::info));
      assert::are_equal("info", enum_object<>::to_string(trace_level::info));
      assert::are_equal(trace_level::info, enum_object<>::parse<trace_level>("info"));
    }
    
    auto test_method_(verbose) {
      assert::are_equal(4, enum_object<>::to_int32(trace_level::verbose));
      assert::are_equal("verbose", enum_object<>::to_string(trace_level::verbose));
      assert::are_equal(trace_level::verbose, enum_object<>::parse<trace_level>("verbose"));
    }
  };
}
