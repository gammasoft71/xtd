/// @file
/// @brief Contains xtd::tunit::test_class class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.h"
#include "class_initialize_attribute.h"
#include "class_cleanup_attribute.h"
#include "settings.h"
#include "test_initialize_attribute.h"
#include "test_cleanup_attribute.h"
#include "test_method_attribute.h"
#include <chrono>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    class registered_test_class;
    class test;
    class unit_test;
    /// @endcond
    
    class tunit_export_ test_class {
    public:
      /// @cond
      test_class() = default;
      test_class(const test_class&) = default;
      test_class& operator=(const test_class&) = default;
      virtual ~test_class() = default;
      /// @endcond

      std::chrono::milliseconds elapsed_time() const noexcept {
        using namespace std::chrono_literals;
        if (start_time_point.time_since_epoch() == 0ms && end_time_point.time_since_epoch() == 0ms) return 0ms;
        if (end_time_point.time_since_epoch() == 0ms) return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time_point);
        return std::chrono::duration_cast<std::chrono::milliseconds>(end_time_point - start_time_point);
      }
      
      std::string name() const noexcept {return name_;}
      
      size_t test_count() const noexcept {
        size_t count = 0;
        for (auto method : tests_)
          if (settings::default_settings().is_match_test_name(name(), method.name())) count++;
        return count;
      }
      
      size_t aborted_test_count() const noexcept {
        size_t count = 0;
        for (auto method : tests_)
          if (settings::default_settings().is_match_test_name(name(), method.name()) && method.aborted()) count++;
        return count;
      }
      
      size_t failed_test_count() const noexcept {
        size_t count = 0;
        for (auto method : tests_)
          if (settings::default_settings().is_match_test_name(name(), method.name()) && method.failed()) count++;
        return count;
      }

      size_t ignored_test_count() const noexcept {
        size_t count = 0;
        for (auto method : tests_)
          if (settings::default_settings().is_match_test_name(name(), method.name()) && method.ignored()) count++;
        return count;
      }
      
      size_t succeed_test_count() const noexcept {
        size_t count = 0;
        for (auto method : tests_)
          if (settings::default_settings().is_match_test_name(name(), method.name()) && method.succeed()) count++;
        return count;
      }

      const std::vector<xtd::tunit::test>& tests() const noexcept {return tests_;}

    protected:
      void add_class_cleanup(const xtd::tunit::test& class_cleanup) noexcept {class_cleanup_ = class_cleanup;}
      
      void add_class_initialize(const xtd::tunit::test& class_initialize) noexcept {class_initialize_ = class_initialize;}
      
      void add_test_cleanup(const xtd::tunit::test& test_cleanup) noexcept {test_cleanup_ = test_cleanup;}
      
      void add_test_initialize(const xtd::tunit::test& test_initialize) noexcept {test_initialize_ = test_initialize;}
      
      void add_test_method(const xtd::tunit::test& test) noexcept {tests_.push_back(test);}
      
    private:
      friend class xtd::tunit::test;
      friend class xtd::tunit::unit_test;
      friend class xtd::tunit::class_initialize_attribute;
      friend class xtd::tunit::class_cleanup_attribute;
      friend class xtd::tunit::registered_test_class;
      friend class xtd::tunit::test_initialize_attribute;
      friend class xtd::tunit::test_cleanup_attribute;
      friend class xtd::tunit::test_method_attribute;
      
      const xtd::tunit::test& class_cleanup() const noexcept {return class_cleanup_;}
      const xtd::tunit::test& class_initialize() const noexcept {return class_initialize_;}
      const xtd::tunit::test& test_cleanup() const noexcept {return test_cleanup_;}
      const xtd::tunit::test& test_initialize() const noexcept {return test_initialize_;}
      const std::vector<xtd::tunit::test>& test_methods() const noexcept {return tests_;}

      void run(const xtd::tunit::unit_test& unit_test);
      
      xtd::tunit::test class_cleanup_;
      xtd::tunit::test class_initialize_;
      std::chrono::high_resolution_clock::time_point end_time_point;
      std::string name_;
      std::chrono::high_resolution_clock::time_point start_time_point;
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

