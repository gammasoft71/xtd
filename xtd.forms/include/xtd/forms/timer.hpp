#pragma once
#include <cstdint>
#include <xtd/event.hpp>
#include <xtd/event_handler.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class timer {
    public:
      timer() = default;
      ~timer() {this->enabled(false);}
      
      event<timer, event_handler<timer>> tick;

      bool enabled() const {return this->enabled_;}
      void enabled(bool enabled);
      
      int32_t interval() const {return this->interval_;}
      void interval(int32_t interval);

      void Start() {this->enabled(true);}

      void Stop() {this->enabled(false);}

    protected:
      void on_tick(const event_args& e) {this->tick(*this, e);}
      
    private:
      bool enabled_ = false;
      int32_t interval_ = 100;
      intptr_t handle_ = 0;
    };
  }
}
