/// @file
/// @brief Contains [xtd::any](https://en.cppreference.com/w/cpp/utility/any) type and [std::bad_any_cast](https://en.cppreference.com/w/cpp/utility/any/bad_any_cast) exception.
#pragma once
/// @cond
#define __XTD_STD_INTERNAL__
#include "internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
/// @endcond

#include <any>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represents the any alias on [std::any](https://www.cppreference.com/w/cpp/utility/any.html).
  /// @par Header
  /// ```cpp
  /// #include <xtd/<any>>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core types
  using any = std::any;
}

#include "any_cast.hpp"
#include "make_any.hpp"
