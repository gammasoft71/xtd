#pragma once
#include <xtd/interface.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class icontrol_trace interface_ {
    public:
      virtual void write(const std::string& message) = 0;
      virtual void flush() = 0;
    };
  }
}
