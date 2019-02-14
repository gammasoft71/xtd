/// @file
/// @brief Contains xtd::registered_method class.
#pragma once
#include "test_class.hpp"
#include <memory>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    struct registered_test_class final {
    public:
      registered_test_class(const std::string& name, std::unique_ptr<xtd::tunit::test_class>&& test_class) : name_(name), test_class_(std::move(test_class)) {}
      
    private:
      friend class xtd::tunit::unit_test;
      std::string name_;
      std::unique_ptr<xtd::tunit::test_class> test_class_;
    };
  }
}
