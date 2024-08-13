#include <xtd/xtd.tunit>
#include <sstream>

using namespace xtd;
using namespace xtd::tunit;

// Simulate gtest event listener test output
class gtest_event_listener final : public event_listener {
private:
  void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_start(e);
    std::cout << "[==========] Running " << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test case." << std::endl;
  }
  
  //void on_unit_test_initialize_start(const xtd::tunit::tunit_event_args& e) const override {
  //  event_listener::on_unit_test_initialize_start(e);
  //}
  
  void on_unit_test_initialize_end(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_initialize_end(e);
    std::cout << "[----------] Global test environment set-up." << std::endl;
  }
  
  void on_class_start(const xtd::tunit::class_event_args& e) const override {
    event_listener::on_class_start(e);
    std::cout << "[----------] " << e.test_class().test_count() << " tests from " << e.test_class().name() << std::endl;
  }
  
  //void on_class_initialize_start(const xtd::tunit::class_event_args& e) const override {
  //  event_listener::on_class_initialize_start(e);
  //}
  
  //void on_class_initialize_end(const xtd::tunit::class_event_args& e) const override {
  //  event_listener::on_class_initialize_end(e);
  //}
  
  //void on_test_initialize_start(const xtd::tunit::test_event_args& e) const override {
  //  event_listener::on_test_initialize_start(e);
  //}
  
  //void on_test_initialize_end(const xtd::tunit::test_event_args& e) const override {
  //  event_listener::on_test_initialize_end(e);
  //}
  
  void on_test_start(const xtd::tunit::test_event_args& e) const override {
    event_listener::on_test_start(e);
    std::cout << "[ RUN      ] " << e.test_class().name() << "." << e.test().name() << std::endl;
  }
  
  void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
    event_listener::on_test_succeed(e);
    std::cout << "[       OK ] " << e.test_class().name() << "." << e.test().name() << " (" << as<int>(e.test().elapsed_time().total_microseconds()) << " ms)" << std::endl;
  }
  
  //void on_test_aborted(const xtd::tunit::test_event_args& e) const override {
  //  event_listener::on_test_aborted(e);
  //}
  
  void on_test_failed(const xtd::tunit::test_event_args& e) const override {
    event_listener::on_test_failed(e);
    std::cout << e.test().stack_frame().get_file_name() << ":" << e.test().stack_frame().get_file_line_number() << ": Failure" << std::endl;
    if (e.test().actual() != "") std::cout << "  Actual: " << e.test().actual() << std::endl;
    if (e.test().expect() != "") std::cout << "Expected: " << e.test().expect() << std::endl;
    if (e.test().message() != "") std::cout << e.test().message() << std::endl;
    std::cout << "[  FAILED  ] " << e.test_class().name() << "." << e.test().name() << " (" << as<int>(e.test().elapsed_time().total_milliseconds()) << " ms)" << std::endl;
  }
  
  //void on_test_ignored(const xtd::tunit::test_event_args& e) const override {
  //  event_listener::on_test_ignored(e);
  //}
  
  //void on_test_end(const xtd::tunit::test_event_args& e) const override {
  //  event_listener::on_test_end(e);
  //}
  
  //void on_test_cleanup_start(const xtd::tunit::test_event_args& e) const override {
  //  event_listener::on_test_cleanup_start(e);
  //}
  
  //void on_test_cleanup_end(const xtd::tunit::test_event_args& e) const override {
  //  event_listener::on_test_cleanup_end(e);
  //}
  
  //void on_class_cleanup_start(const xtd::tunit::class_event_args& e) const override {
  //  event_listener::on_class_cleanup_start(e);
  //}
  
  //void on_class_cleanup_end(const xtd::tunit::class_event_args& e) const override {
  //  event_listener::on_class_cleanup_end(e);
  //}
  
  void on_class_end(const xtd::tunit::class_event_args& e) const override {
    event_listener::on_class_end(e);
    std::cout << "[----------] " << e.test_class().test_count() << " tests from " << e.test_class().name() << " (" << as<int>(e.test_class().elapsed_time().total_milliseconds()) << " ms)" << std::endl;
  }
  
  //void on_unit_test_cleanup_start(const xtd::tunit::tunit_event_args& e) const override {
  //  event_listener::on_unit_test_cleanup_start(e);
  //}
  
  void on_unit_test_cleanup_end(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_cleanup_end(e);
    std::cout << std::endl << "[----------] Global test environment tear-down" << std::endl;
  }
  
  void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_end(e);
    std::cout << "[==========] " << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test case ran. (" << as<int>(e.unit_test().elapsed_time().total_milliseconds()) << " ms total)" << std::endl;
    std::cout << "[  PASSED  ] " << e.unit_test().succeed_test_count() << " tests." << std::endl;
    if (e.unit_test().failed_test_count()) {
      std::cout << "[  FAILED  ] " << e.unit_test().failed_test_count() << " test, listed below:" << std::endl;
      for (ustring name : e.unit_test().failed_test_names())
        std::cout << "[  FAILED  ] " << name << std::endl;
      std::cout << std::endl;
      std::cout << " " << e.unit_test().failed_test_count() << " FAILED TEST" << std::endl;
    }
    if (!e.unit_test().failed_test_count() && e.unit_test().ignored_test_count()) std::cout << std::endl;
    if (e.unit_test().ignored_test_count()) std::cout << "  YOU HAVE " << e.unit_test().ignored_test_count() << " DISABLED TESTS" << std::endl << std::endl;
  }
};

// Simulate gtest unit test test output
class gtest_unit_test final : public unit_test {
public:
  gtest_unit_test() : unit_test(new_uptr<gtest_event_listener>()) {}
};

namespace unit_tests {
  class test_class_(test) {
    void test_method_(test_case1) {
    }
    
    void test_method_(test_case2) {
    }
    
    void test_method_(test_case3) {
      assert::is_true(false, "Your message...");
    }
    
    void ignore_test_method_(test_case4) {
    }
  };
}

auto main() -> int {
  return gtest_unit_test().run();
  // is same :
  // return unit_test(std::new_uptr<gtest_event_listener>()).run();
}

// This code can produce the following output :
//
// [==========] Running 3 tests from 1 test case.
// [----------] Global test environment set-up.
// [----------] 3 tests from test
// [ RUN      ] test.test_case1
// [       OK ] test.test_case1 (0 ms)
// [ RUN      ] test.test_case2
// [       OK ] test.test_case2 (0 ms)
// [ RUN      ] test.test_case3
// !---OMITTED---!/create_gtest_like_event_listener.cpp:139: Failure
//   Actual: false
// Expected: true
// Your message...
// [  FAILED  ] ManualTest.TestCase3 (0 ms)
// [----------] 3 tests from test (0 ms)
//
// [----------] Global test environment tear-down
// [==========] 3 tests from 1 test case ran. (0 ms total)
// [  PASSED  ] 2 tests.
// [  FAILED  ] 1 test, listed below:
// [  FAILED  ] test.test_case3
//
//  1 FAILED TEST
//   YOU HAVE 1 DISABLED TESTS
