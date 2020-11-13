#pragma once
#include <cstdint>
#include <memory>
#include <xtd/event.h>
#include <xtd/event_handler.h>
#include "component.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class timer final : public component {
    public:
      timer() = default;

      /// @cond
      timer(const timer&) = delete;
      ~timer() {this->stop();}
      /// @endcond
      
      event<timer, event_handler<timer&>> tick;

      bool enabled() const {return enabled_;}
      void enabled(bool enabled);
      
      int32_t interval() const {return interval_;}
      void interval(int32_t interval);

      void start() {enabled(true);}

      void stop() {enabled(false);}

    protected:
      void on_tick(const event_args& e);
      
    private:
      bool enabled_ = false;
      int32_t interval_ = 100;
      intptr_t handle_ = 0;
    };
  }
}
