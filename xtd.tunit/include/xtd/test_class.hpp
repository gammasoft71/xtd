/// @file
/// @brief Contains xtd::tunit::test_class class.
#pragma once
#include "class_initialize_attribute.hpp"
#include "class_cleanup_attribute.hpp"
#include "test_initialize_attribute.hpp"
#include "test_cleanup_attribute.hpp"
#include "test_method_attribute.hpp"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    struct test_class {
    public:
      /// @cond
      test_class() = default;
      virtual ~test_class() = default;
      /// @endcond

    protected:
      void add_class_cleanup(const xtd::tunit::registered_method& class_cleanup) {this->class_cleanup_ = class_cleanup;}
      
      void add_class_initialize(const xtd::tunit::registered_method& class_initialize) {this->class_initialize_ = class_initialize;}
      
      void add_test_cleanup(const xtd::tunit::registered_method& test_cleanup) {this->test_cleanup_ = test_cleanup;}
      
      void add_test_initialize(const xtd::tunit::registered_method& test_initialize) {this->test_initialize_ = test_initialize;}
      
      void add_test_method(const xtd::tunit::registered_method& test_method) {this->test_methods_.push_back(test_method);}
      
    private:
      friend class xtd::tunit::unit_test;
      friend struct xtd::tunit::class_initialize_attribute;
      friend struct xtd::tunit::class_cleanup_attribute;
      friend struct xtd::tunit::test_initialize_attribute;
      friend struct xtd::tunit::test_cleanup_attribute;
      friend struct xtd::tunit::test_method_attribute;
      
      xtd::tunit::registered_method class_cleanup_;
      xtd::tunit::registered_method class_initialize_;
      xtd::tunit::registered_method test_cleanup_;
      xtd::tunit::registered_method test_initialize_;
      std::vector<xtd::tunit::registered_method> test_methods_;
    };
  }
}
