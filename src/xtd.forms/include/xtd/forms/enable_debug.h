/// @file
/// @brief Contains xtd::forms::enable_debug class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <xtd/object.h>
#include <xtd/static.h>
#include <xtd/diagnostics/trace_switch.h>
#include "../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent enable debug class.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms debug
    /// @remarks You can activate or deactivate one, some or all debug trace categories.
    /// @par Examples
    /// The following code example demonstrate the use of enable_debug class.
    /// @include enable_debug.cpp
    class forms_export_ enable_debug : public object {
    public:
      /// @cond
      enable_debug() = default;
      enable_debug(const enable_debug&) = default;
      enable_debug& operator=(const enable_debug&) = default;

      bool operator==(const enable_debug& value) const {return value_ == value.value_;}
      bool operator!=(const enable_debug& value) const  {return !operator==(value);}
      enable_debug operator|(const enable_debug& value) const {return enable_debug(value_ | value.value_);}
      enable_debug operator+(const enable_debug& value) const {return enable_debug(value_ + value.value_);}
      /// @endcond

      /// @brief Represent none debug.
      static const enable_debug none;
      /// @brief Represent creation debug.
      static const enable_debug creation;
      /// @brief Represent events debug.
      static const enable_debug events;
      /// @brief Represent key events debug.
      static const enable_debug key_events;
      /// @brief Represent mouse events debug.
      static const enable_debug mouse_events;
      /// @brief Represent layout debug.
      static const enable_debug layout;
      /// @brief Represent workaround debug.
      static const enable_debug workaround;
      /// @brief Represent all debug.
      static const enable_debug all;

      /// @brief Gets enable_debug flags status.
      /// @return true if enable_debug flags is on; otherwise false.
      static bool get(const enable_debug& flags) {return (values_.value_ & flags.value_) == flags.value_;}
      /// @brief Sets enable_debug flags status.
      /// @param on true if enable_debug flags is on; otherwise false.
      static void set(const enable_debug& flags, bool on) {values_.value_ = on ? (values_.value_ | flags.value_) : (values_.value_ & ~flags.value_);}
      
      /// @brief Gets a trace switch to configure debug traces.
      /// @return a xtd::diagnostics::trace_switch to configure debug traces.
      static xtd::diagnostics::trace_switch& trace_switch() {return trace_switch_;}

    private:
      explicit enable_debug(uint64_t value) : value_(value) {}
      
      uint64_t value_ = 0;
      static xtd::diagnostics::trace_switch trace_switch_;
      static enable_debug values_;
    };
  }
}
