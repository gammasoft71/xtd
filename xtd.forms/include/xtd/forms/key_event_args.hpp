#pragma once

#include <xtd/event_args.hpp>
#include "keys.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class key_event_args : public xtd::event_args {
    public:
      key_event_args() = default;

      key_event_args(keys key_data) : key_data_(key_data) {}
      //key_event_args(keys key_data, int key_value) : key_data_(key_data), key_value_(key_value) {}

      /// @cond
      key_event_args(const xtd::forms::key_event_args& key_event_args) = default;
      key_event_args& operator=(const xtd::forms::key_event_args& key_event_args) = default;
      /// @endcond

      bool alt() const {return (this->key_data_ & keys::alt) == keys::alt;}
      
      bool command() const {return (this->key_data_ & keys::command) == keys::command;}
      
      bool control() const {return (this->key_data_ & keys::control) == keys::control;}
      
      bool handled() const {return this->handled_;}
      void handled(bool handled) {this->handled_ = handled;}
      
      keys key_code() const {return this->key_data_ & keys::key_code;}
 
      keys key_data() const {return this->key_data_;}
      
      int key_value() const {return static_cast<int>(this->key_data_) & 0xFFFF;}
      //int key_value() const {return this->key_value_;}

      keys modifiers() const {return this->key_data_ & keys::modifiers;}
      
      bool shift() const {return (this->key_data_ & keys::shift) == keys::shift;}
      
      bool suppress_key_press() const {return this->suppress_key_press_;}
      void suppress_key_press(bool suppress_key_press) {this->suppress_key_press_ = suppress_key_press;}
      

    private:
      keys key_data_;
      //int key_value_;
      bool handled_ = false;
      bool suppress_key_press_ = false;
    };
  }
}
