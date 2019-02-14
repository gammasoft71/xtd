/// @file
/// @brief Contains xtd::tunit::registered_method class.
#pragma once
#include "caller.hpp"
#include <xtd/delegates>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    /// @cond
    struct test_class;
    class unit_test;
    /// @endcond
    
    struct registered_method final {
    public:
      registered_method() = default;
      registered_method(const std::string& name, xtd::delegate<void()> method, const xtd::tunit::caller& caller) : registered_method(name, method, false, caller) {}
      registered_method(const std::string& name, xtd::delegate<void()> method, bool ignore, const xtd::tunit::caller& caller) : name_(name), method_(method), ignore_(ignore), caller__(caller) {}
      
      const std::string& name() const noexcept {return this->name_;}
      xtd::delegate<void()> method() const noexcept {return this->method_;}
      bool ignore() const noexcept {return this->ignore_;}
      const xtd::tunit::caller caller() const noexcept {return this->caller__;}

    private:
      // friend struct xtd::tunit::test_class;
      friend class xtd::tunit::unit_test;
      std::string name_;
      xtd::delegate<void()> method_;
      bool ignore_ = true;
      xtd::tunit::caller caller__;
    };
  }
}
