/// @file
/// @brief Contains #call_once_ keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <utility>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::call_once struct can be used to execute a routine exactly once. This can be used to initialise data in a thread-safe way.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks See also #call_once_ keyword helper.
  ///
  /// @code
  /// #include <xtd/xtd>
  ///
  /// using namespace xtd;
  /// using namespace xtd::threading;
  ///
  /// auto main() -> int {
  ///   console::write_line("(main) begin");
  ///
  ///   auto mre = manual_reset_event {};
  ///
  ///   auto thread_proc = [&] {
  ///     static auto cpt = 0;
  ///     [[maybe_unused]] auto __call_once__ = call_once {} + [&] {
  ///       console::write_line("  (thread_proc) call once {} times", cpt + 1);
  ///     };
  ///     console::write_line("  (thread_proc) running {} times", ++cpt);
  ///     if (cpt == 3) mre.set();
  ///   };
  ///
  ///   thread_pool::register_wait_for_single_object(mre, thread_proc, {}, 100, false);
  ///
  ///   mre.wait_one();
  ///
  ///   thread::join_all();
  ///   console::write_line("(main) end");
  /// }
  ///
  /// // This code produces the following output:
  /// //
  /// // (main) begin
  /// //   (thread_proc) call once 1 times
  /// //   (thread_proc) running 1 times
  /// //   (thread_proc) running 2 times
  /// //   (thread_proc) running 3 times
  /// // (main) end
  /// @endcode
  struct call_once {
  };
  
  /// @cond
  template<typename function_t>
  struct __xtd_call_once_object__ {
    __xtd_call_once_object__(function_t function) { function(); }
  };
  
  template<typename function_t>
  auto operator +(call_once, function_t&& function) {
    return __xtd_call_once_object__<function_t>{std::forward<function_t>(function)};
  }
  /// @endcond
}

/// @cond
#define __xtd_call_once_cat__(name, line) name##line
#define __xtd_call_once_id__(name, line) __xtd_call_once_cat__(name, line)
/// @endcond

/// @brief The xtd keyword #call_once_ can be used to execute a routine exactly once. This can be used to initialise data in a thread-safe way.
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
/// @remarks See also xtd::call_once struct.
///
/// @code
/// #include <xtd/xtd>
///
/// using namespace xtd;
/// using namespace xtd::threading;
///
/// auto main() -> int {
///   console::write_line("(main) begin");
///
///   auto mre = manual_reset_event {};
///
///   auto thread_proc = [&] {
///     static auto cpt = 0;
///     call_once_ {
///       console::write_line("  (thread_proc) call once {} times", cpt + 1);
///     };
///     console::write_line("  (thread_proc) running {} times", ++cpt);
///     if (cpt == 3) mre.set();
///   };
///
///   thread_pool::register_wait_for_single_object(mre, thread_proc, {}, 100, false);
///
///   mre.wait_one();
///
///   thread::join_all();
///   console::write_line("(main) end");
/// }
///
/// // This code produces the following output:
/// //
/// // (main) begin
/// //   (thread_proc) call once 1 times
/// //   (thread_proc) running 1 times
/// //   (thread_proc) running 2 times
/// //   (thread_proc) running 3 times
/// // (main) end
/// @endcode
#define call_once_ [[maybe_unused]] static auto __xtd_call_once_id__(__xtd__call_once__, __LINE__) = xtd::call_once {} + [&]
