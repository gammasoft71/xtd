/// @file
/// @brief Contains #async_ keyword.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "threading/tasks/task.hpp"

/// @brief Use the #async_ modifier to specify that a method, lambda expression, or anonymous method is asynchronous. If you use this modifier on a method or expression, you create an async method. The following example defines an async method named `example_method_async`:
/// ```cpp
/// * Method :
/// auto example_method_async() async_ {
///  // ...
/// }
/// ```
/// The previous example corresponds to the following example, without the #async_ keyword:
/// ```cpp
/// auto example_method_async() -> xtd::threading::tasks::task<> {
///  // ...
/// }
/// ```
///
/// * Lambda :
/// auto example_method_async = [] async_ {
///  // ...
/// }
/// ```
/// The previous example corresponds to the following example, without the #async_ keyword:
/// ```cpp
/// auto example_method_async = [] -> xtd::threading::tasks::task<> {
///  // ...
/// }
/// ```
///
/// @par Namespace
/// xtd
/// @par Library
/// xtd.core
/// @ingroup xtd_core keywords
#define async_ \
  -> xtd::threading::tasks::task<>
