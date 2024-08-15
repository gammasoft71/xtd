#include <xtd/xtd.tunit>

using namespace xtd;
using namespace xtd::tunit;

// Simulate gtest event listener test output
class gtest_event_listener final : public event_listener {
private:
  void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_start(e);
    console::out << "[==========] Running " << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test case." << environment::new_line;
  }
  
  //void on_unit_test_initialize_start(const xtd::tunit::tunit_event_args& e) const override {
  //  event_listener::on_unit_test_initialize_start(e);
  //}
  
  void on_unit_test_initialize_end(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_initialize_end(e);
    console::out << "[----------] Global test environment set-up." << environment::new_line;
  }
  
  void on_class_start(const xtd::tunit::class_event_args& e) const override {
    event_listener::on_class_start(e);
    console::out << "[----------] " << e.test_class().test_count() << " tests from " << e.test_class().name() << environment::new_line;
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
    console::out << "[ RUN      ] " << e.test_class().name() << "." << e.test().name() << environment::new_line;
  }
  
  void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
    event_listener::on_test_succeed(e);
    console::out << "[       OK ] " << e.test_class().name() << "." << e.test().name() << " (" << as<int>(e.test().elapsed_time().total_microseconds()) << " ms)" << environment::new_line;
  }
  
  //void on_test_aborted(const xtd::tunit::test_event_args& e) const override {
  //  event_listener::on_test_aborted(e);
  //}
  
  void on_test_failed(const xtd::tunit::test_event_args& e) const override {
    event_listener::on_test_failed(e);
    console::out << e.test().stack_frame().get_file_name() << ":" << e.test().stack_frame().get_file_line_number() << ": Failure" << environment::new_line;
    if (e.test().actual() != "") console::out << "  Actual: " << e.test().actual() << environment::new_line;
    if (e.test().expect() != "") console::out << "Expected: " << e.test().expect() << environment::new_line;
    if (e.test().message() != "") console::out << e.test().message() << environment::new_line;
    console::out << "[  FAILED  ] " << e.test_class().name() << "." << e.test().name() << " (" << as<int>(e.test().elapsed_time().total_milliseconds()) << " ms)" << environment::new_line;
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
    console::out << "[----------] " << e.test_class().test_count() << " tests from " << e.test_class().name() << " (" << as<int>(e.test_class().elapsed_time().total_milliseconds()) << " ms)" << environment::new_line;
  }
  
  //void on_unit_test_cleanup_start(const xtd::tunit::tunit_event_args& e) const override {
  //  event_listener::on_unit_test_cleanup_start(e);
  //}
  
  void on_unit_test_cleanup_end(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_cleanup_end(e);
    console::out << environment::new_line << "[----------] Global test environment tear-down" << environment::new_line;
  }
  
  void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_end(e);
    console::out << "[==========] " << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test case ran. (" << as<int>(e.unit_test().elapsed_time().total_milliseconds()) << " ms total)" << environment::new_line;
    console::out << "[  PASSED  ] " << e.unit_test().succeed_test_count() << " tests." << environment::new_line;
    if (e.unit_test().failed_test_count()) {
      console::out << "[  FAILED  ] " << e.unit_test().failed_test_count() << " test, listed below:" << environment::new_line;
      for (ustring name : e.unit_test().failed_test_names())
        console::out << "[  FAILED  ] " << name << environment::new_line;
      console::out << environment::new_line;
      console::out << " " << e.unit_test().failed_test_count() << " FAILED TEST" << environment::new_line;
    }
    if (!e.unit_test().failed_test_count() && e.unit_test().ignored_test_count()) console::out << environment::new_line;
    if (e.unit_test().ignored_test_count()) console::out << "  YOU HAVE " << e.unit_test().ignored_test_count() << " DISABLED TESTS" << environment::new_line << environment::new_line;
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
