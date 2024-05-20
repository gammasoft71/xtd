/// @file
/// @brief Contains #scope_exit_ keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Nowadays, every C++ developer is familiar with the Resource Acquisition Is Initialization ([RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization)) technique. It binds resource acquisition and release to initialization and destruction of a variable that holds the resource. There are times when writing a special class for such a variable is not worth the effort. This is when xtd xtd::scope_exit comes into play.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks See also #scope_exit_ keyword helper.
  /// @warning Prefer use [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) then xtd::scope_exit.
  ///
  /// @code
  /// #include <xtd/xtd>
  ///
  /// using namespace xtd;
  ///
  /// auto main() -> int {
  ///   static auto __scope_exit__ = scope_exit {} + [&] {
  ///     console::write_line("scope_exit");
  ///   };
  ///   console::write_line("begin");
  ///   //...
  ///   console::write_line();
  ///   console::write_line("do something...");
  ///   console::write_line();
  ///   //...
  ///   console::write_line("end");
  /// }
  ///
  /// // This code produces the following output:
  /// //
  /// // begin
  /// //
  /// // do something...
  /// //
  /// // end
  /// // scope_exit
  /// @endcode
  struct scope_exit {
  };
  
  /// @cond
  template<typename function_t>
  struct __xtd_scope_exit_object__ {
    ~__xtd_scope_exit_object__() { function(); }
    function_t function;
  };
  
  template<typename function_t>
  auto operator +(scope_exit, function_t&& function) {
    return __xtd_scope_exit_object__<function_t>{std::forward<function_t>(function)};
  }
  /// @endcond
}

/// @cond
#define __xtd_scope_exit_cat__(name, line) name##line
#define __xtd_scope_exit_id__(name, line) __xtd_scope_exit_cat__(name, line)
/// @endcond

/// @brief Nowadays, every C++ developer is familiar with the Resource Acquisition Is Initialization ([RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization)) technique. It binds resource acquisition and release to initialization and destruction of a variable that holds the resource. There are times when writing a special class for such a variable is not worth the effort. This is when xtd #scope_exit_ comes into play.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks See also xtd::scope_exit struct.
/// @warning Prefer use [RAII](https://en.wikipedia.org/wiki/Resource_acquisition_is_initialization) then #scope_exit_.
///
/// @code
/// #include <xtd/xtd>
///
/// using namespace xtd;
///
/// auto main() -> int {
///   scope_exit_ {
///     console::write_line("scope_exit");
///   };
///   console::write_line("begin");
///   //...
///   console::write_line();
///   console::write_line("do something...");
///   console::write_line();
///   //...
///   console::write_line("end");
/// }
///
/// // This code produces the following output:
/// //
/// // begin
/// //
/// // do something...
/// //
/// // end
/// // scope_exit
/// @endcode
#define scope_exit_ [[maybe_unused]] auto __xtd_scope_exit_id__(__xtd__scope_exit__, __LINE__) = xtd::scope_exit {} + [&]
