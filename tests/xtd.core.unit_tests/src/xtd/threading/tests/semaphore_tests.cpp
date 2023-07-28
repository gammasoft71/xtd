#include <xtd/threading/semaphore.h>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(semaphore_tests) {
  public:
    void test_method_(constructor) {
      auto m = semaphore {};
      assert::are_not_equal(semaphore::invalid_handle, m.handle(), csf_);
    }
  };
}
