#include <xtd/threading/semaphore.h>
#include <xtd/threading/thread.h>
#include <xtd/xtd.tunit>
#include <utility>

using namespace xtd::threading;
using namespace xtd::tunit;

namespace xtd::tests {
  class test_class_(semaphore_tests) {
  public:
    // unnamed
    
    void test_method_(constructor) {
      auto s1 = semaphore {};
      auto s2 = semaphore {};
      assert::are_not_equal(semaphore::invalid_handle, s1.handle(), csf_);
      assert::are_not_equal(semaphore::invalid_handle, s2.handle(), csf_);
      assert::are_not_equal(s2, s1, csf_);
    }
    
    void test_method_(copy_constructor) {
      auto s1 = semaphore {};
      auto s2 = s1;
      assert::are_equal(s2, s1, csf_);
    }
    
    void test_method_(copy_operator) {
      auto s1 = semaphore {};
      auto s2 = semaphore {};
      s2 = s1;
      assert::are_equal(s2, s1, csf_);
    }

    void test_method_(constructor_with_initial_count_to_0) {
      auto s = semaphore {0};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(constructor_with_initial_count_to_1) {
      auto s = semaphore {1};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::is_true(s.wait_one(0), csf_);
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(constructor_with_initial_count_to_5) {
      auto s = semaphore {5};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(constructor_with_initial_count_to_0_and_maximum_count_to_1) {
      auto s = semaphore {0, 1};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::is_false(s.wait_one(0), csf_);
        assert::are_equal(0, s.release(), csf_);
        assert::throws<semaphore_full_exception>([&]{s.release();}, csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(constructor_with_initial_count_to_1_and_maximum_count_to_1) {
      auto s = semaphore {1, 1};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::throws<semaphore_full_exception>([&]{s.release();}, csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(constructor_with_initial_count_to_1_and_maximum_count_to_5) {
      auto s = semaphore {1, 5};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      assert::is_true(s.wait_one(0), csf_);
      assert::are_equal(0, s.release(), csf_);
      assert::are_equal(1, s.release(), csf_);
      assert::are_equal(2, s.release(), csf_);
      assert::are_equal(3, s.release(), csf_);
      assert::are_equal(4, s.release(), csf_);
      assert::throws<semaphore_full_exception>([&]{s.release();}, csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    // named
    
    void test_method_(constructor_with_name) {
      auto s1 = semaphore {"xtd_semaphore_test"};
      auto s2 = semaphore {"xtd_semaphore_test_2"};
      assert::are_not_equal(semaphore::invalid_handle, s1.handle(), csf_);
      assert::are_not_equal(semaphore::invalid_handle, s2.handle(), csf_);
      assert::are_not_equal(s2, s1, csf_);
    }
    
    void test_method_(copy_constructor_with_name) {
      auto s1 = semaphore {"xtd_semaphore_test"};
      auto s2 = s1;
      assert::are_equal(s2, s1, csf_);
    }
    void test_method_(constructor_with_name_and_initial_count_to_0) {
      auto s = semaphore {0, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(constructor_with_name_and_initial_count_to_1) {
      auto s = semaphore {1, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::is_true(s.wait_one(0), csf_);
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(constructor_with_name_and_initial_count_to_5) {
      auto s = semaphore {5, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(constructor_with_name_and_initial_count_to_0_and_maximum_count_to_1) {
      auto s = semaphore {0, 1, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::is_false(s.wait_one(0), csf_);
        assert::are_equal(0, s.release(), csf_);
        assert::throws<semaphore_full_exception>([&]{s.release();}, csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(constructor_with_name_and_initial_count_to_1_and_maximum_count_to_1) {
      auto s = semaphore {1, 1, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::throws<semaphore_full_exception>([&]{s.release();}, csf_);
        assert::is_true(s.wait_one(0), csf_);
        assert::is_false(s.wait_one(0), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(constructor_with_name_and_initial_count_to_1_and_maximum_count_to_5) {
      auto s = semaphore {1, 5, "xtd_semaphore_test"};
      assert::are_not_equal(semaphore::invalid_handle, s.handle(), csf_);
      assert::is_true(s.wait_one(0), csf_);
      assert::are_equal(0, s.release(), csf_);
      assert::are_equal(1, s.release(), csf_);
      assert::are_equal(2, s.release(), csf_);
      assert::are_equal(3, s.release(), csf_);
      assert::are_equal(4, s.release(), csf_);
      assert::throws<semaphore_full_exception>([&]{s.release();}, csf_);
      auto thread_ran = 0;
      auto threads = std::vector<thread> {};
      for (auto index = 0; index < 5; ++index) {
        threads.emplace_back([&] {
          assert::is_true(s.wait_one(0), csf_);
          ++thread_ran;
        });
        threads.back().start();
      }
      thread::join_all(threads);
      assert::are_equal(5, thread_ran, csf_);
    }

    void test_method_(create_semaphore_and_close) {
      auto s = semaphore {};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto s2 = semaphore {};
        s.close();
        assert::are_equal(wait_handle::invalid_handle, s.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
      assert::are_equal(wait_handle::invalid_handle, s.handle(), csf_);
    }

    void test_method_(create_semaphore_with_name_and_close) {
      auto s = semaphore {"xtd_semaphore_test"};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto s2 = semaphore {};
        s.close();
        assert::are_equal(wait_handle::invalid_handle, s.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
      assert::are_equal(wait_handle::invalid_handle, s.handle(), csf_);
    }

    void test_method_(open_existing_with_same_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto s2 = semaphore::open_existing("xtd_semaphore_test");
        assert::are_not_equal(wait_handle::invalid_handle, s2.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(open_existing_with_different_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::throws<io::io_exception>([] {auto s2 = semaphore::open_existing("xtd_semaphore_test_2");}, csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(open_existing_with_empty_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        assert::throws<argument_exception>([] {auto s2 = semaphore::open_existing("");}, csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }

    void test_method_(try_open_existing_with_same_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto s2 = semaphore {};
        auto result = semaphore::try_open_existing("xtd_semaphore_test", s2);
        assert::is_true(result, csf_);
        assert::are_not_equal(wait_handle::invalid_handle, s2.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(try_open_existing_with_different_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto s2 = semaphore {};
        auto result = semaphore::try_open_existing("xtd_semaphore_test_2", s2);
        assert::is_false(result, csf_);
        assert::are_equal(wait_handle::invalid_handle, s2.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
    
    void test_method_(try_open_existing_with_empty_name) {
      if (environment::os_version().is_windows() && !environment::is_64_bit_process()) assert::ignore();
      auto created_new = false;
      auto s = semaphore {"xtd_semaphore_test", created_new};
      assert::are_not_equal(wait_handle::invalid_handle, s.handle(), csf_);
      auto thread_ran = false;
      auto thread = threading::thread {[&] {
        auto s2 = semaphore {};
        auto result = semaphore::try_open_existing("", s2);
        assert::is_false(result, csf_);
        assert::are_equal(wait_handle::invalid_handle, s2.handle(), csf_);
        thread_ran = true;
      }};
      thread.start();
      thread.join();
      assert::is_true(thread_ran, csf_);
    }
  };
}
