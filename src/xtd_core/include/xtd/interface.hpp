#pragma once
#include "environment.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent an interface class.
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
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
  /// @endcode
  struct core_export_ interface {
    /// @cond
  public:
    virtual ~interface() = default;
    /// @endcond
  };

  /// @brief This keyword is use to represent an interface.
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// class istringable interface_ {
  /// public:
  ///   virtual std::string to_string() const = 0;
  /// };
  ///
  /// class foo : public istringable {
  /// public:
  ///   Foo() = default;
  ///
  ///   std::string to_string() const override {return "foo";}
  /// };
  /// @endcode
  /// @ingroup keywords
  #define interface_ \
    : public Interface
}
