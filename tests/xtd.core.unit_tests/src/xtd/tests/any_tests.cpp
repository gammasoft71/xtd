#include <xtd/any.h>
#include <xtd/xtd.tunit>

using namespace std;
using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(any_tests) {
  public:
    void test_method_(format_any_empty) {
      any a;
      assert::are_equal("{}", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_any_byte) {
      any a = byte(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_any_double) {
      any a = double(.42);
      assert::are_equal("0.42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_any_int16) {
      any a = int16(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }

    void test_method_(format_any_int32) {
      any a = int32(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_any_int64) {
      any a = int32(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_any_sbyte) {
      any a = sbyte(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }

    void test_method_(format_any_single) {
      any a = .42f;
      assert::are_equal("0.42", ustring::format("{}", a), csf_);
    }

    void test_method_(format_any_uint16) {
      any a = uint16(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_any_uint32) {
      any a = uint32(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
    
    void test_method_(format_any_uint64) {
      any a = uint64(42);
      assert::are_equal("42", ustring::format("{}", a), csf_);
    }
  };
}
