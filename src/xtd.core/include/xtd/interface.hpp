/// @file
/// @brief Contains xtd::interface interface.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#undef interface

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent an interface class.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @par Examples
  /// ```cpp
  /// @include <xtd/interface>
  ///
  /// class istringable : public interface {
  /// public:
  ///   virtual std::string to_string() const = 0;
  /// };
  ///
  /// class foo : public istringable {
  /// public:
  ///   foo() = default;
  ///
  ///   std:string to_string() const override {return "foo";}
  /// };
  /// ```
  class interface {
    /// @cond
  public:
    virtual ~interface() = default;
    /// @endcond
  };
  
  /// @brief This keyword is use to represent an interface.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// ```cpp
  /// @include <xtd/interface>
  ///
  /// class istringable interface_ {
  /// public:
  ///   virtual std::string to_string() const = 0;
  /// };
  ///
  /// class foo : public istringable {
  /// public:
  ///   Foo() = default;
  ///
  ///   std:::string to_string() const override {return "foo";}
  /// };
  /// ```
#define interface_ \
: public xtd::interface
}
