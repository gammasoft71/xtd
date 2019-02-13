/// @file
/// @brief Contains xtd::registered_method class.
#pragma once
#include "caller.hpp"
#include <xtd/delegates>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace TUnit {
    /// @cond
    struct test_class;
    class unit_test;
    /// @endcond
    
    struct registered_method {
    public:
      registered_method() = default;
      registered_method(const std::string& name, delegate<void()> method, const caller& caller) : registered_method(name, method, false, caller) {}
      registered_method(const std::string& name, delegate<void()> method, bool ignore, const caller& caller) : name_(name), method_(method), ignore_(ignore), caller_(caller) {}
      
    private:
      // friend struct xtd::tunit::test_class;
      friend class unit_test;
      std::string name_;
      delegate<void()> method_;
      bool ignore_ = true;
      caller caller_;
    };
  }
}
