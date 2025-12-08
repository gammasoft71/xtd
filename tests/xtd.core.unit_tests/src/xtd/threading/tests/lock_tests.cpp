#include <xtd/threading/lock>
#include <xtd/threading/thread>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::threading::tests {
  class test_class_(lock_tests) {
    auto test_method_(lock_object) {
      object lock_object;
      assert::is_false(monitor::is_entered(lock_object));
      block_scope_(lock lock {lock_object}) {
        assert::is_true(monitor::is_entered(lock_object));
      }
      assert::is_false(monitor::is_entered(lock_object));
    }
    
    auto test_method_(lock_string) {
      assert::is_false(monitor::is_entered("lock_string"));
      block_scope_(lock lock {"lock_string"}) {
        assert::is_true(monitor::is_entered("lock_string"));
      }
      assert::is_false(monitor::is_entered("lock_string"));
    }
    
    auto test_method_(lock_int) {
      int lock_int = 0;
      assert::is_false(monitor::is_entered(lock_int));
      block_scope_(lock lock {lock_int}) {
        assert::is_true(monitor::is_entered(lock_int));
      }
      assert::is_false(monitor::is_entered(lock_int));
    }
    
    auto test_method_(double_lock) {
      object lock_object;
      assert::is_false(monitor::is_entered(lock_object));
      block_scope_(lock lock1 {lock_object}) {
        assert::is_true(monitor::is_entered(lock_object));
        block_scope_(lock lock2 {lock_object}) {
          assert::is_true(monitor::is_entered(lock_object));
        }
      }
      assert::is_false(monitor::is_entered(lock_object));
    }
  };
}
