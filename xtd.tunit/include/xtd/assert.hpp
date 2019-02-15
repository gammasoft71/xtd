/// @file
/// @brief Contains xtd::tunit::assert class.
#pragma once
#include "assert_error.hpp"
#include "line_info.hpp"
#include <string>

#define assert_ assert
#undef assert

/// @brief The xtd namespace contains all fundamental classes to access console.
namespace xtd {
  /// @brief The tunit namespace contains a unit test framework.
  namespace tunit {
    class assert final {
    public:
      /// @cond
      assert() = delete;
      /// @endcond
      
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual) {are_equal(expected, actual, "", line_info_);}
      
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const xtd::tunit::line_info& line_info) {are_equal(expected, actual, "", line_info);}
      
      template<typename TExpected, typename TActual>
      static void are_equal(const TExpected& expected, const TActual& actual, const std::string& message, const xtd::tunit::line_info& line_info) {
        if (actual == expected)
          succeed();
        else
          failed(message);
      }
      
    private:
      static void succeed() {        
      }
      
      static void failed(const std::string& message) {
        throw assert_error(message);
      }
    };
  }
}

#define are_equal_(expected, actual) are_equel(expected, actual, {__func__, __FILE__, __LINE__})
