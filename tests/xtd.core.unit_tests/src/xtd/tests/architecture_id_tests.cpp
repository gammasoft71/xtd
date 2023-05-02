#include <xtd/architecture_id.h>
#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(architecture_id_tests) {
  public:
    void test_method_(unknown) {
      assert::are_equal(-1, enum_object<>::to_int32(architecture_id::unknown), csf_);
      assert::are_equal("unknown", enum_object<>::to_string(architecture_id::unknown), csf_);
    }

    void test_method_(x86) {
      assert::are_equal(0, enum_object<>::to_int32(architecture_id::x86), csf_);
      assert::are_equal("x86", enum_object<>::to_string(architecture_id::x86), csf_);
    }

    void test_method_(arm) {
      assert::are_equal(1, enum_object<>::to_int32(architecture_id::arm), csf_);
      assert::are_equal("arm", enum_object<>::to_string(architecture_id::arm), csf_);
    }
  };
}
