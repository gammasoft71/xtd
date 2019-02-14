/// @file
/// @brief Contains xtd::unit_test class.
#pragma once

#include "registered_test_class.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The TUnit namespace contains a unit test framework.
  namespace tunit {
    /// @cond
    template <typename TestClass>
    struct test_class_attribute;
    /// @endcond

    /// @brief The template class.
    class unit_test final {
    public:
      unit_test() = default;
      
      unit_test(char* argv[], int argc) {}
      
      int run() {
        for (auto test_class : test_classes()) {
          test_class.test_->class_initialize_.method()();
          for (auto test_method : test_class.test_->test_methods_) {
            if (!test_method.ignore_ || this->also_run_ignored_tests) {
              test_class.test_->test_initialize_.method()();
              test_method.method()();
              test_class.test_->test_cleanup_.method()();
            }
          }
          test_class.test_->class_cleanup_.method()();
        }
        return 0;
      }
      
    private:
      template <typename TestClass>
      friend struct xtd::tunit::test_class_attribute;
      
      static void add(const xtd::tunit::registered_test_class& test_class) {test_classes().push_back(test_class);}
      
      static std::vector<xtd::tunit::registered_test_class>& test_classes() {
        static std::vector<xtd::tunit::registered_test_class> test_classes;
        return test_classes;
      }
      
      bool also_run_ignored_tests = false;
    };
  }
}
