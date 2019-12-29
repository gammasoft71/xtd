#pragma once
#include "environment.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The specified expression is cleared automaticaly when the scope is ended.
  /// @par Library
  /// xtd.core
  /// @par Examples
  /// @code
  /// // mo is released automatically after the end cosure }.
  /// using_(std::shared_ptr<base_objects> mo = std::make_shared<my_object>()) {
  ///   std::cout << sr->read_data() << std::endl;
  /// }
  /// @endcode
  /// @ingroup keywords
  #define using_(expression) \
    for (bool __xtd_using__ = true; __xtd_using__; __xtd_using__ = false)\
      for (expression; __xtd_using__; __xtd_using__ = false)
}
