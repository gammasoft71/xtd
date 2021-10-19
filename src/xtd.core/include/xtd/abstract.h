/// @file
/// @brief Contains xtd::abstract_object class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent an abstract class.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  /// @remarks This class has no other use than to tag a class to abstract.
  /// @par Examples
  /// @code
  /// class foo abstract_object {
  /// public:
  ///   virtual std::string to_string() = 0;
  /// };
  /// @endcode
  class abstract_object : public xtd::object {
  protected:
    abstract_object() = default;
  public:
    ~abstract_object() override = 0;
  };

  /// @brief This keyword is used to represents an abstract class.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @remarks This keyword has no other use than to tag a class to abstract.
  /// @par Examples
  /// @code
  /// class foo abstract_ {
  /// public:
  ///   virtual std::string to_string() = 0;
  /// };
  /// @endcode
  #define abstract_ \
    : public abstract_object

  /// @brief This keyword is used to represents an abstract class.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @remarks This keyword has no other use than to tag a class to abstract.
  /// @par Examples
  /// @code
  /// class foo abstract_object_ {
  /// public:
  ///   virtual std::string to_string() = 0;
  /// };
  /// @endcode
  #define abstract_object_ \
    : xtd::abstract_object
}
