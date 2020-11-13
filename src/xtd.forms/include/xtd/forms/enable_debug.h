#pragma once
#include <cstdint>
#include <xtd/static.h>
#include <xtd/diagnostics/trace_switch.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class enable_debug {
    public:
      enable_debug() = default;
      enable_debug(const enable_debug&) = default;
      enable_debug& operator=(const enable_debug&) = default;

      static const enable_debug none;
      static const enable_debug events;
      static const enable_debug key_events;
      static const enable_debug mouse_events;
      static const enable_debug layout;
      static const enable_debug workaround;
      static const enable_debug all;

      static bool get(const enable_debug& flag) {return (values_.value_ & flag.value_) == flag.value_;}
      static void set(const enable_debug& flag, bool value) {values_.value_ = value ? (values_.value_ | flag.value_) : (values_.value_ & ~flag.value_);}
      
      static xtd::diagnostics::trace_switch& trace_switch() {return trace_switch_;}

      bool operator==(const enable_debug& value) const {return value_ == value.value_;}
      bool operator!=(const enable_debug& value) const  {return !operator==(value);}

      enable_debug operator|(const enable_debug& value) const {return enable_debug(value_ | value.value_);}
      enable_debug operator+(const enable_debug& value) const {return enable_debug(value_ + value.value_);}

    private:
      explicit enable_debug(uint64_t value) : value_(value) {}
      
      uint64_t value_ = 0;
      static xtd::diagnostics::trace_switch trace_switch_;
      static enable_debug values_;
    };
  }
}
