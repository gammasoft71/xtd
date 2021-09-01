/// @file
/// @brief Contains #typeof_ keyword.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "ustring.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace __s__ {
    template<typename type_t>
    std::string __typeof_() {
      return xtd::ustring::full_class_name<type_t>();
    }

    template<typename type_t>
    std::string __typeof_(const type_t& value) {
      return xtd::ustring::full_class_name(value);
    }
  }
  /// @endcond

  /// @brief Used to obtain the type string for a type. A typeof_ expression takes the following form:
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core keywords
  /// @par Examples
  /// @code
  /// std::string type1 = typeof_<int32_t>();
  ///
  /// int32_t i = 42;
  /// std::string type2 = typeof_(i);
  /// @endcode
  /// @remarks The typeof_ operator cannot be overloaded.
  #define typeof_ \
    xtd::__s__::__typeof_
}
