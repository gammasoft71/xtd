/// @file
/// @brief Contains xtd::debugstreambuf class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "diagnostics/debug.hpp"
#include "object.hpp"
#include <iostream>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides an std::stringbuf for xtd::diagnostics::debug.
  /// @par Header
  /// ```cpp
  /// #include <xtd/debugstreambuf>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class debugstreambuf : public object, public std::stringbuf {
  protected:
    /// @name Protected Methods
    
    /// @{
    /// @brief Synchronizes the buffers with the associated character sequence
    int32 sync() override {
      #if DEBUG
      if (!str().empty()) {
        if (str() == "\n") xtd::diagnostics::debug::write_line();
        else if (xtd::string(str()).ends_with('\n')) xtd::diagnostics::debug::write_line(xtd::string(str()).trim_end('\n'));
        else xtd::diagnostics::debug::write(str());
        str("");
      }
      #endif
      return 0;
    }
    /// @}
  };
}
