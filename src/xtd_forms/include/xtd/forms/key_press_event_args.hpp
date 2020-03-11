#pragma once

#include <xtd/event_args.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class key_press_event_args : public event_args {
    public:
      key_press_event_args() = default;

      key_press_event_args(char32_t key_char) : key_char_(key_char) {}

      /// @cond
      key_press_event_args(const key_press_event_args& key_press_event_args) = default;
      key_press_event_args& operator=(const key_press_event_args& key_press_event_args) = default;
      /// @endcond

      bool handled() const {return this->handled_;}
      void handled(bool handled) {this->handled_ = handled;}
      
      char32_t key_char() const {return this->key_char_;}

    private:
      char32_t key_char_;
      bool handled_ = false;
    };
  }
}
