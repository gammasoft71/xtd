#include <xtd/compiler_id>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(compiler_id_tests) {
    void test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(compiler_id::unknown), csf_);
      assert::are_equal("unknown", enum_object<>::to_string(compiler_id::unknown), csf_);
      assert::are_equal(compiler_id::unknown, enum_object<>::parse<compiler_id>("unknown"), csf_);
    }
    
    void test_method_(visual_studio) {
      assert::are_equal(0, enum_object<>::to_int32(compiler_id::visual_studio), csf_);
      assert::are_equal("visual_studio", enum_object<>::to_string(compiler_id::visual_studio), csf_);
      assert::are_equal(compiler_id::visual_studio, enum_object<>::parse<compiler_id>("visual_studio"), csf_);
    }
    
    void test_method_(clang) {
      assert::are_equal(1, enum_object<>::to_int32(compiler_id::clang), csf_);
      assert::are_equal("clang", enum_object<>::to_string(compiler_id::clang), csf_);
      assert::are_equal(compiler_id::clang, enum_object<>::parse<compiler_id>("clang"), csf_);
    }
    
    void test_method_(gcc) {
      assert::are_equal(2, enum_object<>::to_int32(compiler_id::gcc), csf_);
      assert::are_equal("gcc", enum_object<>::to_string(compiler_id::gcc), csf_);
      assert::are_equal(compiler_id::gcc, enum_object<>::parse<compiler_id>("gcc"), csf_);
    }
  };
}
