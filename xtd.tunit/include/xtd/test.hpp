/// @file
/// @brief Contains xtd::tunit::registered_method class.
#pragma once
#include "line_info.hpp"
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
    
    struct test final {
    public:
      test() = default;
      test(const std::string& name, xtd::delegate<void()> method, const xtd::tunit::line_info& caller) noexcept : test(name, method, false, caller) {}
      test(const std::string& name, xtd::delegate<void()> method, bool ignore, const xtd::tunit::line_info& info) noexcept :  ignore_(ignore), info_(info), method_(method), name_(name) {}
      
      bool ignore() const noexcept {return this->ignore_;}
      
      const xtd::tunit::line_info line_info() const noexcept {return this->info_;}
      
      xtd::delegate<void()> method() const noexcept {return this->method_;}
      
      const std::string& name() const noexcept {return this->name_;}

      std::chrono::milliseconds elapsed_time() const noexcept {
        using namespace std::chrono_literals;
        if (this->start_time_point.time_since_epoch() == 0ms && this->end_time_point.time_since_epoch() == 0ms) return 0ms;
        if (this->end_time_point.time_since_epoch() == 0ms) return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->start_time_point);
        return std::chrono::duration_cast<std::chrono::milliseconds>(this->end_time_point - this->start_time_point);
      }

      int run(const xtd::tunit::unit_test& unit_test, const xtd::tunit::test_class& test_class);

    private:
      friend struct xtd::tunit::test_class;
      std::chrono::high_resolution_clock::time_point end_time_point;
      bool ignore_ = true;
      xtd::tunit::line_info info_;
      xtd::delegate<void()> method_;
      std::string name_;
      std::chrono::high_resolution_clock::time_point start_time_point;
    };
  }
}
