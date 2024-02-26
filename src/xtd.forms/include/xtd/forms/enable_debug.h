/// @file
/// @brief Contains xtd::forms::enable_debug class.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export.h"
#include <xtd/diagnostics/trace_switch>
#include <xtd/iequatable>
#include <xtd/object>
#include <xtd/static>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represent enable debug class.
    /// @par Header
    /// @code #include <xtd/forms/enable_debug> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms debug
    /// @remarks You can activate or deactivate one, some or all debug trace categories.
    /// @par Examples
    /// The following code example demonstrates the use of enable_debug class.
    /// @include enable_debug.cpp
    class forms_export_ enable_debug : public object, public xtd::iequatable<enable_debug> {
    public:
      /// @cond
      enable_debug() = default;
      enable_debug(const enable_debug&) = default;
      enable_debug& operator =(const enable_debug&) = default;
      
      enable_debug operator |(const enable_debug& value) const noexcept;
      enable_debug operator +(const enable_debug& value) const  noexcept;
      /// @endcond
      
      /// @name Fields
      
      /// @{
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
      /// @brief Represent style debug.
      static const enable_debug style;
      /// @brief Represent all debug.
      static const enable_debug all;
      
      /// @name Properties
      
      /// @{
      /// @brief Gets a trace switch to configure debug traces.
      /// @return a xtd::diagnostics::trace_switch to configure debug traces.
      static xtd::diagnostics::trace_switch& trace_switch() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      bool equals(const enable_debug& value) const noexcept override;
      
      /// @brief Gets enable_debug flags status.
      /// @return true if enable_debug flags is on; otherwise false.
      static bool get(const enable_debug& flags);
      /// @brief Sets enable_debug flags status.
      /// @param on true if enable_debug flags is on; otherwise false.
      static void set(const enable_debug& flags, bool on);
      /// @}
      
      
    private:
      explicit enable_debug(uint64 value);
      
      uint64 value_ = 0;
      static xtd::diagnostics::trace_switch trace_switch_;
      static enable_debug values_;
    };
  }
}
