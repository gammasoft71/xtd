/// @file
/// @brief Contains xtd::signal_cancel_event_args event args.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "event_args.h"
#include "signal.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides data for the environment signal event. This class cannot be inherited.
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  /// @remarks A user can interrupt a console application process by simultaneously pressing the Control modifier key and the C console key (Ctrl+C), or the Control modifier key and the Break console key (Ctrl+Break). The console consequently provides a signal_cancel_event_args object to the event handler for the console::cancel_key_press event to specify whether the process should be cancelled.
  /// @remarks If the cancel property is set to true in the event handler, the process is resumed; otherwise, the process is terminated. By default, the value of the signal_cancel_event_args property is false, and the process terminates.
  class signal_cancel_event_args final : public xtd::event_args {
  public:
    /// @name Constructors
    
    /// @{
    /// @brief Initializes a new instance of the signal_cancel_event_args class.
    signal_cancel_event_args() = default;
    
    /// @brief Initializes a new instance of the signal_cancel_event_args class.
    /// @param signal One of the enumeration values that specifies the key combination that interrupted the current process. There is no default value..
    explicit signal_cancel_event_args(xtd::signal signal);
    /// @}
    
    /// @cond
    signal_cancel_event_args(const signal_cancel_event_args&) = default;
    signal_cancel_event_args& operator =(const signal_cancel_event_args&) = default;
    /// @endcond
    
    /// @name Properties
    
    /// @{
    /// @brief Gets a value that indicates whether a signal has interrupted the current process. The default is false, which terminates the current process.
    /// @return true if the current process should resume when the event handler concludes; false if the current process should terminate. The default value is false; the current process terminates when the event handler returns. If true, the current process continues.
    bool cancel() const noexcept;
    
    /// @brief Sets a value that indicates whether a signal has interrupted the current process. The default is false, which terminates the current process.
    /// @param true if the current process should resume when the event handler concludes; false if the current process should terminate. The default value is false; the current process terminates when the event handler returns. If true, the current process continues.
    void cancel(bool cancel);
    
    /// @brief Gets the signal that interrupted the current process.
    /// @return One of the enumeration values that specifies the signal that interrupted the current process. There is no default value.
    xtd::signal signal() const noexcept;
    /// @}
    
  private:
    bool cancel_ = false;
    xtd::signal signal_ = static_cast<xtd::signal>(0);
  };
}
