#include <xtd/xtd.tunit>
#include <sstream>

using namespace std;
using namespace xtd::tunit;

// Simulate gtest event listener test output
class gtest_event_listener final : public event_listener {
private:
  void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_start(e);
    cout << "[==========] Running " << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test case." << endl;
  }
  
  //void on_unit_test_initialize_start(const xtd::tunit::tunit_event_args& e) const override {
  //  event_listener::on_unit_test_initialize_start(e);
  //}
  
  void on_unit_test_initialize_end(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_initialize_end(e);
    cout << "[----------] Global test environment set-up." << endl;
  }
  
  void on_class_start(const xtd::tunit::class_event_args& e) const override {
    event_listener::on_class_start(e);
    cout << "[----------] " << e.test_class().test_count() << " tests from " << e.test_class().name() << endl;
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
    cout << "[ RUN      ] " << e.test_class().name() << "." << e.test().name() << endl;
  }
  
  void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
    event_listener::on_test_succeed(e);
    cout << "[       OK ] " << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << endl;
  }
  
  //void on_test_aborted(const xtd::tunit::test_event_args& e) const override {
  //  event_listener::on_test_aborted(e);
  //}

  void on_test_failed(const xtd::tunit::test_event_args& e) const override {
    event_listener::on_test_failed(e);
    cout << e.test().line_info().file_path() << ":" << e.test().line_info().line_number() << ": Failure" << endl;
    if (e.test().actual() != "") cout << "  Actual: " << e.test().actual() << endl;
    if (e.test().expect() != "") cout << "Expected: " << e.test().expect() << endl;
    if (e.test().message() != "") cout << e.test().message() << endl;
    cout << "[  FAILED  ] " << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << endl;
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
    cout << "[----------] " << e.test_class().test_count() << " tests from " << e.test_class().name() << " (" << e.test_class().elapsed_time().count() << " ms)" << endl;
  }

  //void on_unit_test_cleanup_start(const xtd::tunit::tunit_event_args& e) const override {
  //  event_listener::on_unit_test_cleanup_start(e);
  //}
  
  void on_unit_test_cleanup_end(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_cleanup_end(e);
    cout << endl << "[----------] Global test environment tear-down" << endl;
  }

  void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
    event_listener::on_unit_test_end(e);
    cout << "[==========] " << e.unit_test().test_count() << " tests from " << e.unit_test().test_cases_count() << " test case ran. (" << e.unit_test().elapsed_time().count() << " ms total)" << endl;
    cout << "[  PASSED  ] " << e.unit_test().succeed_test_count() << " tests." << endl;
    if (e.unit_test().failed_test_count()) {
      cout << "[  FAILED  ] " << e.unit_test().failed_test_count() << " test, listed below:" << endl;
      for(string name : e.unit_test().failed_test_names()) {
        cout << "[  FAILED  ] " << name << endl;
      }
      cout << endl;
      cout << " " << e.unit_test().failed_test_count() << " FAILED TEST" << endl;
    }
    if (!e.unit_test().failed_test_count() && e.unit_test().ignored_test_count()) cout << endl;
    if (e.unit_test().ignored_test_count()) cout << "  YOU HAVE " << e.unit_test().ignored_test_count() << " DISABLED TESTS" << endl << endl;
  }
};

// Simulate gtest unit test test output
class gtest_unit_test final : public unit_test {
public:
  gtest_unit_test() : unit_test(make_unique<gtest_event_listener>()) {}
};

namespace unit_tests {
  class test_class_(test) {
  public:
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

int main() {
  return gtest_unit_test().run();
  // is same :
  // return unit_test(std::make_unique<gtest_event_listener>()).run();
}

// This code can produce the following output:
//
// [==========] Running 3 tests from 1 test case.
// [----------] Global test environment set-up.
// [----------] 3 tests from test
// [ RUN      ] test.test_case1
// [       OK ] test.test_case1 (0 ms)
// [ RUN      ] test.test_case2
// [       OK ] test.test_case2 (0 ms)
// [ RUN      ] test.test_case3
// !---OMITTED---!/xtd.tunit/examples/create_your_own_unit_test/src/create_your_own_unit_test.cpp:139: Failure
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
