/// @file
/// @brief Contains xtd::static_object class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent a static object. A static class can't be instantiated (constructors are deleted).
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// class foo : public static_object {
  /// public:
  ///   static std::string to_string() {return "foo";}
  /// };
  /// ```
  class static_object {
    static_object() = delete;
  };
  
  /// @brief This keyword is use to represent a static object. A static object can't be instantiated (constructors are deleted).
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// ```cpp
  /// class foo static_ {
  /// public:
  ///   static std::string to_string() {return "foo";}
  /// };
  /// ```
#define static_ \
: xtd::static_object
  
  /// @brief This keyword is use to represent a static object. A static object can't be instantiated (constructors are deleted).
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// ```cpp
  /// class foo static_object_ {
  /// public:
  ///   static std::string to_string() {return "foo";}
  /// };
  /// ```
#define static_object_ \
: xtd::static_object
}
