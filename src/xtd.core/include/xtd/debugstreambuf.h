/// @file
/// @brief Contains xtd::debugstreambuf class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <iostream>
#include "object.h"
#include "diagnostics/debug.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides an std::stringbuf for xtd::diagnostics::debug.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class debugstreambuf : public object, public std::stringbuf {
  public:
    int sync() override {
#if !defined(NDEBUG) || defined(DEBUG) || defined(TRACE)
      if (!str().empty()) {
        if (str() == "\n") xtd::diagnostics::debug::write_line();
        else if (xtd::ustring(str()).ends_with('\n')) xtd::diagnostics::debug::write_line(xtd::ustring(str()).trim_end('\n'));
        else xtd::diagnostics::debug::write(str());
        str("");
      }
#endif
      return 0;
    }
  };
}
