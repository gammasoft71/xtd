#include <xtd/threading/lock_guard.h>
#include <xtd/threading/thread>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(lock_guard_tests) {
  public:
    void test_method_(lock_object) {
      object lock_object;
      assert::is_false(monitor::is_entered(lock_object), csf_);
      using_(lock_guard lock {lock_object}) {
        assert::is_true(monitor::is_entered(lock_object), csf_);
      }
      assert::is_false(monitor::is_entered(lock_object), csf_);
    }
    
    void test_method_(lock_string) {
      assert::is_false(monitor::is_entered("lock_string"), csf_);
      using_(lock_guard lock {"lock_string"}) {
        assert::is_true(monitor::is_entered("lock_string"), csf_);
      }
      assert::is_false(monitor::is_entered("lock_string"), csf_);
    }

    void test_method_(lock_int) {
      int lock_int = 0;
      assert::is_false(monitor::is_entered(lock_int), csf_);
      using_(lock_guard lock {lock_int}) {
        assert::is_true(monitor::is_entered(lock_int), csf_);
      }
      assert::is_false(monitor::is_entered(lock_int), csf_);
    }
    
    void test_method_(double_lock_guard) {
      object lock_object;
      assert::is_false(monitor::is_entered(lock_object), csf_);
      using_(lock_guard lock1 {lock_object}) {
        assert::is_true(monitor::is_entered(lock_object), csf_);
        using_(lock_guard lock2 {lock_object}) {
          assert::is_true(monitor::is_entered(lock_object), csf_);
        }
      }
      assert::is_false(monitor::is_entered(lock_object), csf_);
    }
  };
}
