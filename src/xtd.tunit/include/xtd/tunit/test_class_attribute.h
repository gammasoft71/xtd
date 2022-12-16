/// @file
/// @brief Contains xtd::tunit::test_class_attribute class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "unit_test.h"
#include <memory>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represents a test class attribute.
    template <typename test_class_t>
    class test_class_attribute final {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Creates a new instance of test_class_attribute with specified name.
      /// @param name The name of the test class attribute.
      explicit test_class_attribute(const std::string& name) noexcept {xtd::tunit::unit_test::add({name, std::make_shared<test_class_t>()});}
      /// @}
    };
  }
}
