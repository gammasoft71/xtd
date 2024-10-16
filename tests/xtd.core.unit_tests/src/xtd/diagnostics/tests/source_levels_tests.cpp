#include <xtd/diagnostics/source_levels>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::diagnostics;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(source_levels_tests) {
    void test_method_(off) {
      assert::are_equal(0, enum_object<>::to_int32(source_levels::off));
      assert::are_equal("off", enum_object<>::to_string(source_levels::off));
      assert::are_equal(source_levels::off, enum_object<>::parse<source_levels>("off"));
    }
    
    void test_method_(critical) {
      assert::are_equal(1, enum_object<>::to_int32(source_levels::critical));
      assert::are_equal("critical", enum_object<>::to_string(source_levels::critical));
      assert::are_equal(source_levels::critical, enum_object<>::parse<source_levels>("critical"));
    }
    
    void test_method_(error) {
      assert::are_equal(3, enum_object<>::to_int32(source_levels::error));
      assert::are_equal("error", enum_object<>::to_string(source_levels::error));
      assert::are_equal(source_levels::error, enum_object<>::parse<source_levels>("error"));
    }
    
    void test_method_(warning) {
      assert::are_equal(7, enum_object<>::to_int32(source_levels::warning));
      assert::are_equal("warning", enum_object<>::to_string(source_levels::warning));
      assert::are_equal(source_levels::warning, enum_object<>::parse<source_levels>("warning"));
    }
    
    void test_method_(information) {
      assert::are_equal(15, enum_object<>::to_int32(source_levels::information));
      assert::are_equal("information", enum_object<>::to_string(source_levels::information));
      assert::are_equal(source_levels::information, enum_object<>::parse<source_levels>("information"));
    }
    
    void test_method_(verbose) {
      assert::are_equal(31, enum_object<>::to_int32(source_levels::verbose));
      assert::are_equal("verbose", enum_object<>::to_string(source_levels::verbose));
      assert::are_equal(source_levels::verbose, enum_object<>::parse<source_levels>("verbose"));
    }
    
    void test_method_(activity_tracing) {
      assert::are_equal(65280, enum_object<>::to_int32(source_levels::activity_tracing));
      assert::are_equal("activity_tracing", enum_object<>::to_string(source_levels::activity_tracing));
      assert::are_equal(source_levels::activity_tracing, enum_object<>::parse<source_levels>("activity_tracing"));
    }
    void test_method_(all) {
      assert::are_equal(65535, enum_object<>::to_int32(source_levels::all));
      assert::are_equal("all", enum_object<>::to_string(source_levels::all));
      assert::are_equal(source_levels::all, enum_object<>::parse<source_levels>("all"));
    }
  };
}
