/// @file
/// @brief Contains xtd::abstract_object class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "object.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Represent an abstract class.
  /// @par Header
  /// @code #include <xtd/abstract_object> @endcode
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
  public:
    /// @cond
    ~abstract_object() override = 0;
    /// @endcond
    
  protected:
    /// @name Protected Constructors
    
    /// @{
    /// @brief Initializes a new instance of the xtd::abstract_object class.
    abstract_object() = default;
    /// @}
  };
  
  /// @brief This keyword is used to represents an abstract class.
  /// @par Header
  /// @code #include <xtd/abstract_object> @endcode
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
