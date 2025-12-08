#include <xtd/month_of_year>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(month_of_year_tests) {
    auto test_method_(january) {
      assert::are_equal(1, enum_object<>::to_int32(month_of_year::january));
      assert::are_equal("january", enum_object<>::to_string(month_of_year::january));
      assert::are_equal(month_of_year::january, enum_object<>::parse<month_of_year>("january"));
    }
    
    auto test_method_(february) {
      assert::are_equal(2, enum_object<>::to_int32(month_of_year::february));
      assert::are_equal("february", enum_object<>::to_string(month_of_year::february));
      assert::are_equal(month_of_year::february, enum_object<>::parse<month_of_year>("february"));
    }
    
    auto test_method_(march) {
      assert::are_equal(3, enum_object<>::to_int32(month_of_year::march));
      assert::are_equal("march", enum_object<>::to_string(month_of_year::march));
      assert::are_equal(month_of_year::march, enum_object<>::parse<month_of_year>("march"));
    }
    
    auto test_method_(april) {
      assert::are_equal(4, enum_object<>::to_int32(month_of_year::april));
      assert::are_equal("april", enum_object<>::to_string(month_of_year::april));
      assert::are_equal(month_of_year::april, enum_object<>::parse<month_of_year>("april"));
    }
    
    auto test_method_(may) {
      assert::are_equal(5, enum_object<>::to_int32(month_of_year::may));
      assert::are_equal("may", enum_object<>::to_string(month_of_year::may));
      assert::are_equal(month_of_year::may, enum_object<>::parse<month_of_year>("may"));
    }
    
    auto test_method_(june) {
      assert::are_equal(6, enum_object<>::to_int32(month_of_year::june));
      assert::are_equal("june", enum_object<>::to_string(month_of_year::june));
      assert::are_equal(month_of_year::june, enum_object<>::parse<month_of_year>("june"));
    }
    
    auto test_method_(july) {
      assert::are_equal(7, enum_object<>::to_int32(month_of_year::july));
      assert::are_equal("july", enum_object<>::to_string(month_of_year::july));
      assert::are_equal(month_of_year::july, enum_object<>::parse<month_of_year>("july"));
    }
    
    auto test_method_(august) {
      assert::are_equal(8, enum_object<>::to_int32(month_of_year::august));
      assert::are_equal("august", enum_object<>::to_string(month_of_year::august));
      assert::are_equal(month_of_year::august, enum_object<>::parse<month_of_year>("august"));
    }
    
    auto test_method_(september) {
      assert::are_equal(9, enum_object<>::to_int32(month_of_year::september));
      assert::are_equal("september", enum_object<>::to_string(month_of_year::september));
      assert::are_equal(month_of_year::september, enum_object<>::parse<month_of_year>("september"));
    }
    
    auto test_method_(october) {
      assert::are_equal(10, enum_object<>::to_int32(month_of_year::october));
      assert::are_equal("october", enum_object<>::to_string(month_of_year::october));
      assert::are_equal(month_of_year::october, enum_object<>::parse<month_of_year>("october"));
    }
    
    auto test_method_(november) {
      assert::are_equal(11, enum_object<>::to_int32(month_of_year::november));
      assert::are_equal("november", enum_object<>::to_string(month_of_year::november));
      assert::are_equal(month_of_year::november, enum_object<>::parse<month_of_year>("november"));
    }
    
    auto test_method_(december) {
      assert::are_equal(12, enum_object<>::to_int32(month_of_year::december));
      assert::are_equal("december", enum_object<>::to_string(month_of_year::december));
      assert::are_equal(month_of_year::december, enum_object<>::parse<month_of_year>("december"));
    }
  };
}

