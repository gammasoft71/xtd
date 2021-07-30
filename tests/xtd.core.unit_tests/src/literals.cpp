#include <xtd/literals.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace unit_tests {  
  class test_class_(test_lietarls) {
  public:
    void test_method_(operator_s_on_char_ptr) {
      auto s = "string"_s;
      assert::is_instance_of<ustring>(s);
      assert::are_equal_("string", s);
    }

    void test_method_(operator_s_on_char8_t_ptr) {
      auto s = u8"string"_s;
      assert::is_instance_of<ustring>(s);
      assert::are_equal_("string", s);
    }
    
    void test_method_(operator_s_on_unsigned_long_long) {
      auto s = 42_s;
      assert::is_instance_of<std::string>(s);
      assert::are_equal_("42", s);
    }
  };
}
