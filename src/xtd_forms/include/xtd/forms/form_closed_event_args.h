#pragma once

#include <xtd/event_args.h>
#include "close_reason.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class form_closed_event_args : public event_args {
    public:
      form_closed_event_args() = default;
      form_closed_event_args(forms::close_reason close_reason) : close_reason_(close_reason) {};

      /// @cond
      form_closed_event_args(const form_closed_event_args& form_closed_event_args) = default;
      form_closed_event_args& operator=(const form_closed_event_args& form_closed_event_args) = default;
      /// @endcond

      forms::close_reason close_reason() const {return this->close_reason_;}

    private:
      forms::close_reason close_reason_ = forms::close_reason::none;
    };
  }
}
