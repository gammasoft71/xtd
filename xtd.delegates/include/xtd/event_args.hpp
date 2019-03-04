#pragma once

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  class event_args {
  public:
    event_args() = default;
    static event_args empty() { return event_args(); }
  };
}
