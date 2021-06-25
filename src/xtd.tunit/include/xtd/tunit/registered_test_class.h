/// @file
/// @brief Contains xtd::tunit::registered_test_class class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "test_class.h"
#include <memory>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief Represents the registered test class.
    /// @par Library
    /// xtd.tunit
    /// @ingroup xtd_tunit
    class registered_test_class final {
    public:
      registered_test_class(const std::string& name, std::shared_ptr<xtd::tunit::test_class> test_class) noexcept : tc_(test_class) {tc_->name_ = name;}
      
    private:
      friend class xtd::tunit::unit_test;

      const std::shared_ptr<xtd::tunit::test_class>& test() const noexcept {return tc_;}

      std::shared_ptr<xtd::tunit::test_class> tc_;
    };
  }
}
