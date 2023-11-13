/// @file
/// @brief Contains #finally_ keyword.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  struct __xtd_finally_helper__ { };
  
  template<typename function_t>
  struct __xtd_finally_object__ {
    ~__xtd_finally_object__() { function(); }
    function_t function;
  };
  
  template<typename function_t>
  auto operator +(__xtd_finally_helper__, function_t&& function) {
    return __xtd_finally_object__<function_t>{std::forward<function_t>(function)};
  }
  /// @endcond
}

/// @cond
#define __xtd_finally_cat__(name, line) name##line
#define __xtd_finally_id__(name, line) __xtd_finally_cat__(name, line)
/// @endcond

/// @brief In addition to try and catch clauses, xtd supports a #finally_ clause. A #finally_ block can follow a try or catch block.
/// @remarks The purpose of the #finally_ block is to clean up any resources left after the exception occurred. Note that the finally block is always executed, even if no exception was thrown. The catch block is only executed if a managed exception is thrown within the associated try block.
/// @warning Generally in C++ the #finally_ is NOT required because of <a href="https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization">RAII</a>.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @code
/// #include <xtd/console>
///
/// using namespace xtd;
///
/// auto main()->int {
///   console::write_line("start");
///   try {
///     console::write_line("try");
///     throw system_exception("invalid operation exception");
///   } catch (const system_exception& e) {
///     console::write_line("catch");
///   } finally_ {
///     console::write_line("finally");
///   };
///   console::write_line("stop");
/// }
///
/// // This code produces the following output:
/// //
/// // start
/// // try
/// // catch
/// // stop
/// // finally
/// @endcode
#define finally_ auto __xtd_finally_id__(__xtd__finally__, __LINE__) = xtd::__xtd_finally_helper__{} + [&]
