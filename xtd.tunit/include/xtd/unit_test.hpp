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
      
      explicit unit_test(const char* argv, int argc);
      
      int run() ;
      
    private:
      template <typename TestClass>
      friend struct xtd::tunit::test_class_attribute;
      
      static void add(const xtd::tunit::registered_test_class& test_class);
      
      static std::vector<xtd::tunit::registered_test_class>& test_classs();
      
      bool also_run_ignored_tests = false;
    };
  }
}
