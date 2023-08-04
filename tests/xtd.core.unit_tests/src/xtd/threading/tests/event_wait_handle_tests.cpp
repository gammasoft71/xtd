#include <xtd/threading/event_wait_handle.h>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(event_wait_handle_tests) {
  public:
    static void class_initialize_(class_initialize) {
      auto e = event_wait_handle {"xtd_event_wait_handle_test"};
      auto e2 = event_wait_handle {"xtd_event_wait_handle_test_2"};
    }

    void test_method_(constructor) {
      auto e1 = event_wait_handle {};
      auto e2 = event_wait_handle {};
      assert::are_not_equal(event_wait_handle::invalid_handle, e1.handle(), csf_);
      assert::are_not_equal(event_wait_handle::invalid_handle, e2.handle(), csf_);
      assert::are_not_equal(e2, e1, csf_);
    }
  };
}
