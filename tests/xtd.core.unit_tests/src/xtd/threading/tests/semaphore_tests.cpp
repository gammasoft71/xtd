#include <xtd/threading/semaphore>
#include <xtd/threading/thread>
#include <xtd/collections/generic/list>
#include <xtd/environment>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>
#include <xtd/io/io_exception>
#include <utility>

using namespace xtd::collections::generic;
using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::threading::tests {
  class test_class_(semaphore_tests) {
    // unnamed
    
    auto test_method_(constructor) {
      auto s1 = semaphore {};
      auto s2 = semaphore {};
      assert::are_not_equal(semaphore::invalid_handle, s1.handle());
      assert::are_not_equal(semaphore::invalid_handle, s2.handle());
      assert::are_not_equal(s2, s1);
    }
    
    auto test_method_(copy_constructor) {
      auto s1 = semaphore {};
      auto s2 = s1;
      assert::are_equal(s2, s1);
    }
    
    auto test_method_(copy_operator) {
      auto s1 = semaphore {};
      auto s2 = semaphore {};
      s2 = s1;
      assert::are_equal(s2, s1);
    }
    
    auto test_method_(constructor_with_initial_count_to_0) {
      auto s = semaphore {0};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_initial_count_to_1) {
      auto s = semaphore {1};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_true(s.wait_one(0));
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_initial_count_to_5) {
      auto s = semaphore {5};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_initial_count_to_0_and_maximum_count_to_1) {
      auto s = semaphore {0, 1};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_false(s.wait_one(0));
          assert::are_equal(0, s.release());
          assert::throws<semaphore_full_exception>([&]{s.release();});
          assert::is_true(s.wait_one(0));
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_initial_count_to_1_and_maximum_count_to_1) {
      auto s = semaphore {1, 1};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::throws<semaphore_full_exception>([&]{s.release();});
          assert::is_true(s.wait_one(0));
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_initial_count_to_1_and_maximum_count_to_5) {
      auto s = semaphore {1, 5};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      assert::is_true(s.wait_one(0));
      assert::are_equal(0, s.release());
      assert::are_equal(1, s.release());
      assert::are_equal(2, s.release());
      assert::are_equal(3, s.release());
      assert::are_equal(4, s.release());
      assert::throws<semaphore_full_exception>([&] {s.release();});
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    // named
    
    auto test_method_(constructor_with_name) {
      auto s1 = semaphore {"xtd_semaphore_test"};
      auto s2 = semaphore {"xtd_semaphore_test_2"};
      assert::are_not_equal(semaphore::invalid_handle, s1.handle());
      assert::are_not_equal(semaphore::invalid_handle, s2.handle());
      assert::are_not_equal(s2, s1);
    }
    
    auto test_method_(copy_constructor_with_name) {
      auto s1 = semaphore {"xtd_semaphore_test"};
      auto s2 = s1;
      assert::are_equal(s2, s1);
    }
    auto test_method_(constructor_with_name_and_initial_count_to_0) {
      auto s = semaphore {0, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_name_and_initial_count_to_1) {
      auto s = semaphore {1, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_true(s.wait_one(0));
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_name_and_initial_count_to_5) {
      auto s = semaphore {5, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_true(s.wait_one(0));
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_name_and_initial_count_to_0_and_maximum_count_to_1) {
      auto s = semaphore {0, 1, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::is_false(s.wait_one(0));
          assert::are_equal(0, s.release());
          assert::throws<semaphore_full_exception>([&]{s.release();});
          assert::is_true(s.wait_one(0));
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_name_and_initial_count_to_1_and_maximum_count_to_1) {
      auto s = semaphore {1, 1, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::throws<semaphore_full_exception>([&]{s.release();});
          assert::is_true(s.wait_one(0));
          assert::is_false(s.wait_one(0));
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(constructor_with_name_and_initial_count_to_1_and_maximum_count_to_5) {
      auto s = semaphore {1, 5, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle());
      assert::is_true(s.wait_one(0));
      assert::are_equal(0, s.release());
      assert::are_equal(1, s.release());
      assert::are_equal(2, s.release());
      assert::are_equal(3, s.release());
      assert::are_equal(4, s.release());
      assert::throws<semaphore_full_exception>([&] {s.release();});
      auto thread_ran = 0;
      auto threads = list<thread> {};
      for (auto index = 0; index < 5; ++index) {
        threads.add(thread {[&] {
            assert::is_true(s.wait_one(0));
            ++thread_ran;
          }});
        threads[threads.count() - 1].start();
      }
      thread::join_all(threads);
      assert::are_equal(5, thread_ran);
    }
    
    auto test_method_(create_semaphore_and_close) {
      auto s = semaphore {};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto s2 = semaphore {};
          s.close();
          assert::are_equal(wait_handle::invalid_handle, s.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
      assert::are_equal(wait_handle::invalid_handle, s.handle());
    }
    
    auto test_method_(create_semaphore_with_name_and_close) {
      auto s = semaphore {"xtd_semaphore_test"};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto s2 = semaphore {};
          s.close();
          assert::are_equal(wait_handle::invalid_handle, s.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
      assert::are_equal(wait_handle::invalid_handle, s.handle());
    }
    
    auto test_method_(open_existing_with_same_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto s2 = semaphore::open_existing("xtd_semaphore_test");
          assert::are_not_equal(wait_handle::invalid_handle, s2.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(open_existing_with_different_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::throws<io::io_exception>([] {auto s2 = semaphore::open_existing("xtd_semaphore_test_2");});
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(open_existing_with_empty_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          assert::throws<argument_exception>([] {auto s2 = semaphore::open_existing("");});
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(try_open_existing_with_same_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto s2 = semaphore {};
          auto result = semaphore::try_open_existing("xtd_semaphore_test", s2);
          assert::is_true(result);
          assert::are_not_equal(wait_handle::invalid_handle, s2.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(try_open_existing_with_different_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto s2 = semaphore {};
          auto result = semaphore::try_open_existing("xtd_semaphore_test_2", s2);
          assert::is_false(result);
          assert::are_equal(wait_handle::invalid_handle, s2.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
    
    auto test_method_(try_open_existing_with_empty_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle());
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
          auto s2 = semaphore {};
          auto result = semaphore::try_open_existing("", s2);
          assert::is_false(result);
          assert::are_equal(wait_handle::invalid_handle, s2.handle());
          thread_ran = true;
        }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran);
    }
  };
}
