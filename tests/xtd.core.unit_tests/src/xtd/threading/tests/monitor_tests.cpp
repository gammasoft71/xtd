#include <xtd/threading/monitor>
#include <xtd/threading/synchronization_lock_exception>
#include <xtd/threading/thread>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(monitor_tests) {
    void test_method_(enter) {
      object lock_object;
      assert::is_false(monitor::is_entered(lock_object));
      monitor::enter(lock_object);
      assert::is_true(monitor::is_entered(lock_object));
      monitor::exit(lock_object);
      assert::is_false(monitor::is_entered(lock_object));
    }
    
    void test_method_(double_enter) {
      object lock_object;
      assert::is_false(monitor::is_entered(lock_object));
      monitor::enter(lock_object);
      assert::is_true(monitor::is_entered(lock_object));
      monitor::enter(lock_object);
      assert::is_true(monitor::is_entered(lock_object));
      monitor::exit(lock_object);
      assert::is_true(monitor::is_entered(lock_object));
      monitor::exit(lock_object);
      assert::is_false(monitor::is_entered(lock_object));
    }
    
    void test_method_(double_exit_without_double_enter) {
      object lock_object;
      assert::is_false(monitor::is_entered(lock_object));
      monitor::enter(lock_object);
      assert::is_true(monitor::is_entered(lock_object));
      monitor::exit(lock_object);
      assert::is_false(monitor::is_entered(lock_object));
      assert::throws<synchronization_lock_exception>([&] {monitor::exit(lock_object);});
    }

    void test_method_(lock_object) {
      object lock_object;
      assert::is_false(monitor::is_entered(lock_object));
      monitor::enter(lock_object);
      assert::is_true(monitor::is_entered(lock_object));
      monitor::exit(lock_object);
      assert::is_false(monitor::is_entered(lock_object));
    }

    void test_method_(lock_int) {
      auto lock_int = 0;
      assert::is_false(monitor::is_entered(lock_int));
      monitor::enter(lock_int);
      assert::is_true(monitor::is_entered(lock_int));
      monitor::exit(lock_int);
      assert::is_false(monitor::is_entered(lock_int));
    }

    void test_method_(lock_string) {
      assert::is_false(monitor::is_entered("lock_string"));
      monitor::enter("lock_string");
      assert::is_true(monitor::is_entered("lock_string"));
      monitor::exit("lock_string");
      assert::is_false(monitor::is_entered("lock_string"));
    }

    void test_method_(enter_lock_string_exit_other_string) {
      monitor::enter("lock_string");
      assert::throws<synchronization_lock_exception>([&] {monitor::exit("other_string");});
      monitor::exit("lock_string");
    }
    
    void test_method_(try_enter_lock_string) {
      assert::is_true(monitor::try_enter("lock_string"));
      assert::is_true(monitor::try_enter("lock_string"));
      monitor::exit("lock_string");
      monitor::exit("lock_string");
    }
    
    void test_method_(try_enter_lock_string_already_locked) {
      assert::is_true(monitor::try_enter("lock_string"));
      bool thread_ran = false;
      auto thread = threading::thread::start_new([&] {
        assert::is_false(monitor::try_enter("lock_string", 0));
        thread_ran = true;
      });
      thread.join();
      assert::is_true(thread_ran);
      monitor::exit("lock_string");
    }
  };
}
