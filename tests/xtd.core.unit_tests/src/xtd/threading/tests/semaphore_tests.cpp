#include <xtd/threading/semaphore.h>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(semaphore_tests) {
  public:
    static void class_initialize_(class_initialize) {
      auto created_new = false;
      auto s = semaphore {"xtd_mutex_test", created_new};
    }
    
    void test_method_(constructor) {
      auto s = semaphore {};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
    }
  };
}
