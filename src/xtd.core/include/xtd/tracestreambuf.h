/// @file
/// @brief Contains xtd::tracestreambuf class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "diagnostics/trace.h"
#include "object.h"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides an std::stringbuf for xtd::diagnostics::trace.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class tracestreambuf : public object, public std::stringbuf {
  protected:
    /// @name Protected methods
    
    /// @{
    /// @brief Synchronizes the buffers with the associated character sequence
    int32 sync() override {
      #if defined(TRACE)
      if (!str().empty()) {
        if (str() == "\n") xtd::diagnostics::trace::write_line();
        else if (ustring(str()).ends_with('\n')) xtd::diagnostics::trace::write_line(ustring(str()).trim_end('\n'));
        else xtd::diagnostics::trace::write(str());
        str("");
      }
      #endif
      return 0;
    }
  };
}
