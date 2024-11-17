/// @file
/// @brief Contains #nameof_ keyword.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Used to obtain the simple (unqualified) string name of a variable, type, or member.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// When reporting errors in code, hooking up model-view-controller (MVC) links, firing property changed events, etc., you often want to capture the string name of a method. Using nameof helps keep your code valid when renaming definitions. Before, you had to use string literals to refer to definitions, which is brittle when renaming code elements because tools do not know to check these string literals.
  ///
  /// A nameof expression has this form:
  /// ```cpp
  /// if (x == null) throw  std::argument_error(nameof_(x));
  /// write_line(nameof_(person.address().zip_code())); // prints "person.address().zip_code()"
  /// ```
  /// @par Examples
  /// Some C++ examples:
  /// @include nameof.cpp
  /// @remarks The argument to nameof must be a simple name, qualified name, member access, base access with a specified member, or this access with a specified member. The argument expression identifies a code definition, but it is never evaluated.
  /// @remarks Because the argument needs to be an expression syntactically, there are many things disallowed that are not useful to list. The following are worth mentioning that produce errors: predefined types (for example, int or void), nullable types (Point?), array types (Customer[,]), pointer types (Buffer*), qualified alias (A::B), and unbound generic types (Dictionary<,>), preprocessing symbols (DEBUG), and labels (loop:).
  /// @remarks If you need to get the fully-qualified name, you can use the typeof_ expression along with nameof. For example:
  /// ```cpp
  /// class c {
  /// public: 
  ///   void f(int i) {
  ///     log(xtd::string::format("{0}::{1}", typeof_<c>(), nameof_(f)), "method entry");
  ///   }
  /// }
  /// ```
#define nameof_(...) \
  std::string(#__VA_ARGS__)
}
