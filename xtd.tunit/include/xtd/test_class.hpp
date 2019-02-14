/// @file
/// @brief Contains xtd::tunit::test_class class.
#pragma once
#include "class_initialize_attribute.hpp"
#include "class_cleanup_attribute.hpp"
#include "test_initialize_attribute.hpp"
#include "test_cleanup_attribute.hpp"
#include "test_method_attribute.hpp"
#include <chrono>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    /// @cond
    struct registered_test_class;
    /// @endcond
    
    struct test_class {
    public:
      /// @cond
      test_class() = default;
      virtual ~test_class() = default;
      /// @endcond

      std::chrono::high_resolution_clock::duration elapsed_time() const noexcept {return std::chrono::high_resolution_clock::now() - this->start_time_point;}
      
      std::string name() const noexcept {return this->name_;}
      
      size_t test_count() const noexcept {
        size_t count = 0;
        for (auto method : this->tests_)
          if (!method.ignore() || this->also_run_ignored_tests_) count++;
        return count;
      }
      
      size_t ignore_test_count() const noexcept {
        size_t count = 0;
        for (auto method : this->tests_)
          if (method.ignore()) count++;
        return count;
      }
      
      const std::vector<xtd::tunit::test>& tests() const noexcept {return this->tests_;}
      
      void run(const xtd::tunit::unit_test& unit_test);

    protected:
      void add_class_cleanup(const xtd::tunit::test& class_cleanup) noexcept {this->class_cleanup_ = class_cleanup;}
      
      void add_class_initialize(const xtd::tunit::test& class_initialize) noexcept {this->class_initialize_ = class_initialize;}
      
      void add_test_cleanup(const xtd::tunit::test& test_cleanup) noexcept {this->test_cleanup_ = test_cleanup;}
      
      void add_test_initialize(const xtd::tunit::test& test_initialize) noexcept {this->test_initialize_ = test_initialize;}
      
      void add_test_method(const xtd::tunit::test& test) noexcept {this->tests_.push_back(test);}
      
    private:
      friend class xtd::tunit::unit_test;
      friend struct xtd::tunit::class_initialize_attribute;
      friend struct xtd::tunit::class_cleanup_attribute;
      friend struct xtd::tunit::registered_test_class;
      friend struct xtd::tunit::test_initialize_attribute;
      friend struct xtd::tunit::test_cleanup_attribute;
      friend struct xtd::tunit::test_method_attribute;
      
      const xtd::tunit::test& class_cleanup() const noexcept {return this->class_cleanup_;}
      const xtd::tunit::test& class_initialize() const noexcept {return this->class_initialize_;}
      const xtd::tunit::test& test_cleanup() const noexcept {return this->test_cleanup_;}
      const xtd::tunit::test& test_initialize() const noexcept {return this->test_initialize_;}
      const std::vector<xtd::tunit::test>& test_methods() const noexcept {return this->tests_;}

      bool also_run_ignored_tests_ = false;
      xtd::tunit::test class_cleanup_;
      xtd::tunit::test class_initialize_;
      std::chrono::high_resolution_clock::time_point start_time_point = std::chrono::high_resolution_clock::now();
      std::string name_;
      xtd::tunit::test test_cleanup_;
      xtd::tunit::test test_initialize_;
      std::vector<xtd::tunit::test> tests_;
    };
  }
}

#define test_class_(class_name) \
  class_name;\
  xtd::tunit::test_class_attribute<class_name> __##class_name##_attribute {#class_name}; \
  class class_name : public xtd::tunit::test_class

#define test_class_from_(class_name, from_class_name) \
  class_name;\
  xtd::tunit::test_class_attribute<class_name> __##class_name##_attribute {#class_name}; \
  class class_name : public from_class_name

