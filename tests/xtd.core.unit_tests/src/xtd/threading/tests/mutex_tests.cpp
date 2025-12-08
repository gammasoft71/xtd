#include <xtd/threading/mutex>
#include <xtd/threading/thread>
#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/io/io_exception>
#include <xtd/object_closed_exception>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::threading::tests {
  class test_class_(mutex_tests) {
    auto test_method_(constructor) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      assert::are_not_equal(mutex::invalid_handle, m1.handle());
      assert::are_not_equal(mutex::invalid_handle, m2.handle());
      assert::are_not_equal(m2, m1);
    }
    
    auto test_method_(copy_constructor) {
      auto m1 = mutex {};
      auto m2 = m1;
      assert::are_equal(m2, m1);
    }
    
    auto test_method_(copy_operator) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      m2 = m1;
      assert::are_equal(m2, m1);
    }
    
    auto test_method_(constructor_with_initially_owned_to_false) {
      auto m = mutex {false};
      assert::are_not_equal(mutex::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_true(m.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_initially_owned_to_true) {
      auto m = mutex {true};
      assert::are_not_equal(mutex::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_false(m.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_initially_owned_to_false_and_name) {
      auto m = mutex {false, "xtd_mutex_test"};
      assert::are_not_equal(mutex::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_true(m.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_initially_owned_to_true_and_name) {
      auto m = mutex {true, "xtd_mutex_test"};
      assert::are_not_equal(mutex::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_false(m.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(copy_constructor_with_initially_owned_to_false_and_name) {
      auto m1 = mutex {false, "xtd_mutex_test"};
      auto m2 = m1;
      assert::are_equal(m2.handle(), m1.handle());
    }
    
    auto test_method_(create_two_mutex_with_same_name) {
      auto m1 = mutex {true, "xtd_mutex_test"};
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto m2 = mutex {false, "xtd_mutex_test"};
          assert::is_false(m2.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(create_two_mutex_with_same_name_and_created_new) {
      auto created_new = false;
      auto m1 = mutex {true, "xtd_mutex_test", created_new};
      assert::is_true(created_new);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto m2 = mutex {false, "xtd_mutex_test", created_new};
          assert::is_false(created_new);
          assert::is_false(m2.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(create_two_mutex_with_different_name_and_created_new) {
      auto created_new = false;
      auto m1 = mutex {true, "xtd_mutex_test", created_new};
      assert::is_true(created_new);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto m2 = mutex {false, "xtd_mutex_test_2", created_new};
          assert::is_true(created_new);
          assert::is_true(m2.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(create_mutex_and_close) {
      auto m = mutex {};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto m2 = mutex {};
          m.close();
          assert::are_equal(wait_handle::invalid_handle, m.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
      assert::are_equal(wait_handle::invalid_handle, m.handle());
    }
    
    auto test_method_(create_mutex_with_name_and_close) {
      auto created_new = false;
      auto m = mutex {false, "xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          m.close();
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
      assert::are_equal(wait_handle::invalid_handle, m.handle());
    }
    
    auto test_method_(open_existing_with_same_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto m = mutex {"xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto m2 = mutex::open_existing("xtd_mutex_test");
          assert::are_not_equal(wait_handle::invalid_handle, m2.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(open_existing_with_different_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto m = mutex {"xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::throws<io::io_exception>([] {auto m2 = mutex::open_existing("xtd_mutex_test_2");});
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(open_existing_with_empty_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto m = mutex {"xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::throws<argument_exception>([] {auto m2 = mutex::open_existing("");});
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(try_open_existing_with_same_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto m = mutex {"xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto m2 = mutex {};
          auto result = mutex::try_open_existing("xtd_mutex_test", m2);
          assert::is_true(result);
          assert::are_not_equal(wait_handle::invalid_handle, m2.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(try_open_existing_with_different_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto m = mutex {"xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto m2 = mutex {};
          auto result = mutex::try_open_existing("xtd_mutex_test_2", m2);
          assert::is_false(result);
          assert::are_equal(wait_handle::invalid_handle, m2.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(try_open_existing_with_empty_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto m = mutex {"xtd_mutex_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, m.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto m2 = mutex {};
          auto result = mutex::try_open_existing("", m2);
          assert::is_false(result);
          assert::are_equal(wait_handle::invalid_handle, m2.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(wait_one) {
      auto m = mutex {};
      assert::is_true(m.wait_one());
    }
    
    auto test_method_(wait_one_and_release_mutex) {
      auto m = mutex {};
      assert::is_true(m.wait_one());
      assert::does_not_throw([&] {m.release_mutex();});
    }
    
    auto test_method_(wait_one_and_release_mutex_and_release_mutex) {
      auto m = mutex {};
      assert::is_true(m.wait_one());
      assert::does_not_throw([&] {m.release_mutex();});
      assert::does_not_throw([&] {m.release_mutex();});
    }
    
    auto test_method_(wait_one_and_wait_one_and_release_mutex) {
      auto m = mutex {false};
      assert::is_true(m.wait_one(0));
      assert::is_true(m.wait_one(0));
      assert::does_not_throw([&] {m.release_mutex();});
    }
    
    auto test_method_(close_and_wait_one) {
      auto m = mutex {};
      m.close();
      assert::throws<object_closed_exception>([&] {m.wait_one();});
    }
    
    auto test_method_(close_and_release_mutex) {
      auto m = mutex {};
      m.close();
      assert::are_equal(mutex::invalid_handle, m.handle());
      assert::throws<object_closed_exception>([&] {m.release_mutex();});
    }
    
    auto test_method_(signal_and_wait) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      m1.wait_one();
      mutex::signal_and_wait(m1, m2);
    }
    
    auto test_method_(wait_all) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      auto m3 = mutex {};
      assert::is_true(mutex::wait_all({m1, m2, m3}));
    }
    
    auto test_method_(wait_any) {
      auto m1 = mutex {};
      auto m2 = mutex {};
      auto m3 = mutex {};
      assert::are_equal(0ul, mutex::wait_any({m1, m2, m3}));
    }
    
    auto test_method_(wait_one_and_release_mutex_with_threads) {
      auto m = mutex {};
      auto count = 0;
      for (auto index = 0; index < 10; ++index)
        thread::start_new([&] {
        m.wait_one();
        m.release_mutex();
        ++count;
      });
      thread::sleep(10);
      assert::is_true(m.wait_one(0));
      assert::are_equal(10, count);
      thread::join_all();
    }
  };
}
