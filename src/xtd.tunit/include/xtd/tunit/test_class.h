/// @file
/// @brief Contains xtd::tunit::test_class class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../tunit_export.h"
#define __XTD_TUNIT_INTERNAL__
#include "__google_test_markers.h"
#undef __XTD_TUNIT_INTERNAL__
#include "class_initialize_attribute.h"
#include "class_cleanup_attribute.h"
#include "settings.h"
#include "test_initialize_attribute.h"
#include "test_cleanup_attribute.h"
#include "test_method_attribute.h"
#include <xtd/date_time>
#include <xtd/ustring>
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
    
    /// @brief Represents a test class.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    /// @remarks The class test_class must be the base class for all test classes defined in a test unit.
    /// @par Examples
    /// The following example shows how to use xtd::tunit::test_class class.
    /// @include test_class_without_helpers.cpp
    class tunit_export_ test_class {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Creates a new test_class instance.
      test_class() {
        // The following variables are a hack to ensure that GoogleTestAdapter (Microsoft Visual Studio) will detect the tunit application as a google test application...
        // See https://github.com/csoltenborn/GoogleTestAdapter/blob/master/GoogleTestAdapter/Core/GoogleTestConstants.cs
        __unused_google_test_markers__();
      }
      /// @}
      
      /// @cond
      test_class(const test_class&) = default;
      test_class& operator =(const test_class&) = default;
      virtual ~test_class() = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the elapsed time of the test class.
      /// @return The elapsed time of the test class.
      std::chrono::milliseconds elapsed_time() const noexcept;
      
      /// @brief Gets the name of the test class.
      /// @return The nzme of the test class.
      xtd::ustring name() const noexcept;
      
      /// @brief Gets the test count.
      /// @return The test count.
      size_t test_count() const noexcept;
      
      /// @brief Gets the aborted test count.
      /// @return The aborted test count.
      size_t aborted_test_count() const noexcept;
      
      /// @brief Gets the failed test count.
      /// @return The failed test count.
      size_t failed_test_count() const noexcept;
      
      /// @brief Gets the ignored test count.
      /// @return The ignored test count.
      size_t ignored_test_count() const noexcept;
      
      /// @brief Gets the succeed test count.
      /// @return The succeed test count.
      size_t succeed_test_count() const noexcept;
      
      /// @brief Gets the start time of the test class.
      /// @return The start time of the test class.
      const xtd::date_time& start_time() const noexcept;
      
      /// @brief Gets the tests array of this test class.
      /// @return The tests array.
      const std::vector<xtd::tunit::test>& tests() const noexcept;
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      /// @brief Adds the class cleanup method.
      /// @param class_cleanup The class cleanup method.
      void add_class_cleanup(const xtd::tunit::test& class_cleanup) noexcept;
      
      /// @brief Adds the class initialize method.
      /// @param class_initialize The class initialize method.
      void add_class_initialize(const xtd::tunit::test& class_initialize) noexcept;
      
      /// @brief Adds the test cleanup method.
      /// @param test_cleanup The test cleanup method.
      void add_test_cleanup(const xtd::tunit::test& test_cleanup) noexcept;
      
      /// @brief Adds the test initialize method.
      /// @param test_initialize The test initialize method.
      void add_test_initialize(const xtd::tunit::test& test_initialize) noexcept;
      
      /// @brief Adds a test method.
      /// @param test The a test method.
      void add_test_method(const xtd::tunit::test& test) noexcept;
      /// @}
      
    private:
      friend class xtd::tunit::test;
      friend class xtd::tunit::unit_test;
      friend class xtd::tunit::class_initialize_attribute;
      friend class xtd::tunit::class_cleanup_attribute;
      friend class xtd::tunit::registered_test_class;
      friend class xtd::tunit::test_initialize_attribute;
      friend class xtd::tunit::test_cleanup_attribute;
      friend class xtd::tunit::test_method_attribute;
      
      const xtd::tunit::test& class_cleanup() const noexcept;
      const xtd::tunit::test& class_initialize() const noexcept;
      const xtd::tunit::test& test_cleanup() const noexcept;
      const xtd::tunit::test& test_initialize() const noexcept;
      const std::vector<xtd::tunit::test>& test_methods() const noexcept;
      
      void run(const xtd::tunit::unit_test& unit_test);
      
      xtd::tunit::test class_cleanup_;
      xtd::tunit::test class_initialize_;
      xtd::date_time end_time_point;
      xtd::ustring name_;
      xtd::date_time start_time_;
      xtd::tunit::test test_cleanup_;
      xtd::tunit::test test_initialize_;
      std::vector<xtd::tunit::test> tests_;
    };
  }
}
