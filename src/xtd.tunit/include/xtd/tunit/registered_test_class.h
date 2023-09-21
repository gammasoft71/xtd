/// @file
/// @brief Contains xtd::tunit::registered_test_class class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "test_class"
#include "../tunit_export"
#include <memory>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represents the registered test class.
    /// @par Namespace
    /// xtd::tunit
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit tunit
    class tunit_export_ registered_test_class final {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Creates a new registered_test_class instance.
      /// @param name The name associate to the test_class.
      /// @remarks The name is the name of the test class displayed when running the tests.
      registered_test_class(const std::string& name, std::shared_ptr<xtd::tunit::test_class> test_class) noexcept;
      /// @}
      
    private:
      friend class xtd::tunit::unit_test;
      
      const std::shared_ptr<xtd::tunit::test_class>& test() const noexcept;
      
      std::shared_ptr<xtd::tunit::test_class> tc_;
    };
  }
}
