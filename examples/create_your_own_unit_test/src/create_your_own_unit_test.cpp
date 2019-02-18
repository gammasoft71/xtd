#include <xtd/tunit>
#include <sstream>

using namespace std;
using namespace xtd::tunit;

// Simulate google test output
class google_unit_test : public unit_test {
public:
  google_unit_test() = default;
  
  google_unit_test(char* argv[], int argc) : unit_test(argv, argc) {}
  
private:
  void on_unit_test_start(const xtd::tunit::tunit_event_args& e) const override {
    this->unit_test::on_unit_test_start(e);
    cout << "[==========] Running " << this->test_count() << " tests from " << this->test_cases_count() << " test case." << endl;
  }
  
  void on_unit_test_initialize_start(const xtd::tunit::tunit_event_args& e) const override {
    this->unit_test::on_unit_test_initialize_start(e);
  }
  
  void on_unit_test_initialize_end(const xtd::tunit::tunit_event_args& e) const override {
    this->unit_test::on_unit_test_initialize_end(e);
    cout << "[----------] Global test environment set-up." << endl;
  }
  
  void on_class_start(const xtd::tunit::class_event_args& e) const override {
    this->unit_test::on_class_start(e);
    cout << "[----------] " << e.test_class().test_count() << " tests from " << e.test_class().name() << endl;
  }
  
  void on_class_initialize_start(const xtd::tunit::class_event_args& e) const override {
    this->unit_test::on_class_initialize_start(e);
  }
  
  void on_class_initialize_end(const xtd::tunit::class_event_args& e) const override {
    this->unit_test::on_class_initialize_end(e);
  }
  
  void on_test_initialize_start(const xtd::tunit::test_event_args& e) const override {
    this->unit_test::on_test_initialize_start(e);
  }
  
  void on_test_initialize_end(const xtd::tunit::test_event_args& e) const override {
    this->unit_test::on_test_initialize_end(e);
  }
  
  void on_test_start(const xtd::tunit::test_event_args& e) const override {
    this->unit_test::on_test_start(e);
    cout << "[ RUN      ] " << e.test_class().name() << "." << e.test().name() << endl;
  }
  
  void on_test_succeed(const xtd::tunit::test_event_args& e) const override {
    this->unit_test::on_test_succeed(e);
    cout << "[       OK ] " << e.test_class().name() << "." << e.test().name() << " (" << e.test().elapsed_time().count() << " ms)" << endl;
  }
  
  void on_test_failed(const xtd::tunit::test_event_args& e) const override {
    this->unit_test::on_test_failed(e);
    cout << e.test().line_info().file_path() << ":" << e.test().line_info().line_number() << endl;
    cout << e.test().message() << endl;
    if (e.test().user_message() != "") cout << e.test().user_message() << endl;
    cout << "[  FAILED  ] ManualTest.TestCase3 (" << e.test().elapsed_time().count() << " ms)" << endl;
  }
  
  void on_test_end(const xtd::tunit::test_event_args& e) const override {
    this->unit_test::on_test_end(e);
  }

  void on_test_cleanup_start(const xtd::tunit::test_event_args& e) const override {
    this->unit_test::on_test_cleanup_start(e);
  }
  
  void on_test_cleanup_end(const xtd::tunit::test_event_args& e) const override {
    this->unit_test::on_test_cleanup_end(e);
  }
 
  void on_class_cleanup_start(const xtd::tunit::class_event_args& e) const override {
    this->unit_test::on_class_cleanup_start(e);
  }
  
  void on_class_cleanup_end(const xtd::tunit::class_event_args& e) const override {
    this->unit_test::on_class_cleanup_end(e);
  }
  
  void on_class_end(const xtd::tunit::class_event_args& e) const override {
    this->unit_test::on_class_end(e);
    cout << "[----------] " << e.test_class().test_count() << " tests from " << e.test_class().name() << " (" << e.test_class().elapsed_time().count() << " ms)" << endl;
  }

  void on_unit_test_cleanup_start(const xtd::tunit::tunit_event_args& e) const override {
    this->unit_test::on_unit_test_cleanup_start(e);
  }
  
  void on_unit_test_cleanup_end(const xtd::tunit::tunit_event_args& e) const override {
    this->unit_test::on_unit_test_cleanup_end(e);
    cout << endl << "[----------] Global test environment tear-down" << endl;
  }

  void on_unit_test_end(const xtd::tunit::tunit_event_args& e) const override {
    this->unit_test::on_unit_test_end(e);
    cout << "[==========] " << this->test_count() << " tests from " << this->test_cases_count() << " test case ran. (" << this->elapsed_time().count() << " ms total)" << endl;
    cout << "[  PASSED  ] " << this->passed_test_count() << " tests." << endl;
    if (this->failed_test_count()) {
      cout << "[  FAILED  ] " << this->failed_test_count() << " test, listed below:" << endl;
      for(string name : this->failed_test_names()) {
        cout << "[  FAILED  ] " << name << endl;
      }
    }
    cout << endl;
    if (this->failed_test_count()) cout << " " << this->failed_test_count() << " FAILED TEST" << endl;
    if (this->ignore_test_count()) cout << "  YOU HAVE " << this->ignore_test_count() << " DISABLED TESTS" << endl;
    cout <<endl;
  }
};

namespace unit_tests {
  class test_class_(test) {
  public:
    void test_method_(test_case1) {
    }

    void test_method_(test_case2) {
    }

    void test_method_(test_case3) {
      assert::fail("Your message...");
    }

    void ignore_test_method_(test_case4) {
    }
  };
}

// The main entry point for the application.
int main(int argc, char* argv[]) {
  return google_unit_test(argv, argc).run();
}

// This code can produce the following output:
//
// Start 1 tests from 1 test case
//   Start 1 tests from test
//     PASSED test_case1 (0 ms total)
//   End 1 tests from test (0 ms total)
//
//   Summary :
//     PASSED 1 tests.
// End 1 tests from 1 test case ran. (0 ms total)
