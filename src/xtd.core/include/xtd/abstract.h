/// @file
/// @brief Contains xtd::abstract_object class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "abstract_object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief This keyword is used to represents an abstract class.
  /// @par Header
  /// ```cpp
  /// #include <xtd/abstract>
  /// ```
    /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @remarks This keyword has no other use than to tag a class to abstract.
  /// @par Examples
  /// ```cpp
  /// class foo abstract_ {
  /// public:
  ///   virtual std::string to_string() = 0;
  /// };
  /// ```
  #define abstract_ \
    : public xtd::abstract_object
}
