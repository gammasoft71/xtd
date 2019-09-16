#pragma once

#include <xtd/event_args.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class cancel_event_args : public event_args {
    public:
      cancel_event_args() = default;

      /// @cond
      cancel_event_args(const cancel_event_args& cancel_event_args) = default;
      cancel_event_args& operator=(const cancel_event_args& cancel_event_args) = default;
      /// @endcond

      virtual bool cancel() const {return this->cancel_;}
      virtual void cancel(bool cancel) {this->cancel_ = cancel;}

    protected:
      bool cancel_ = false;
    };
  }
}
