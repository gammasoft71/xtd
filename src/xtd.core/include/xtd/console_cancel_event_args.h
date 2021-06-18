/// @file
/// @brief Contains xtd::console_cancel_event_args event args.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "event_args.h"
#include "console_special_key.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides data for the console::cancel_key_press event. This class cannot be inherited.
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  /// @remarks A user can interrupt a console application process by simultaneously pressing the Control modifier key and the C console key (Ctrl+C), or the Control modifier key and the Break console key (Ctrl+Break). The console consequently provides a console_cancel_event_args object to the event handler for the console::cancel_key_press event to specify whether the process should be cancelled.
  /// @remarks If the cancel property is set to true in the event handler, the process is resumed; otherwise, the process is terminated. By default, the value of the console_cancel_event_args property is false, and the process terminates.
  class console_cancel_event_args final : public xtd::event_args {
  public:
    /// @brief Initializes a new instance of the console_cancel_event_args class.
    console_cancel_event_args() = default;

    /// @brief Initializes a new instance of the console_cancel_event_args class.
    /// @param cancel true if the current process should resume when the event handler concludes; false if the current process should terminate. The default value is false; the current process terminates when the event handler returns. If true, the current process continues..
    /// @param special_key One of the enumeration values that specifies the key combination that interrupted the current process. There is no default value..
    console_cancel_event_args(bool cancel, console_special_key special_key) : cancel_(cancel), special_key_(special_key) {}

    /// @cond
    console_cancel_event_args(const console_cancel_event_args&) = default;
    console_cancel_event_args& operator=(const console_cancel_event_args&) = default;
    /// @endcond
    
    /// @brief Gets a value that indicates whether simultaneously pressing the Control modifier key and the C console key (Ctrl+C) or the Ctrl+Break keys terminates the current process. The default is false, which terminates the current process.
    /// @return true if the current process should resume when the event handler concludes; false if the current process should terminate. The default value is false; the current process terminates when the event handler returns. If true, the current process continues.
    bool cancel() const {return cancel_;}
    
    /// @brief Sets a value that indicates whether simultaneously pressing the Control modifier key and the C console key (Ctrl+C) or the Ctrl+Break keys terminates the current process. The default is false, which terminates the current process.
    /// @param true if the current process should resume when the event handler concludes; false if the current process should terminate. The default value is false; the current process terminates when the event handler returns. If true, the current process continues.
    void cancel(bool cancel) {cancel_ = cancel;}
    
    /// @brief Gets the combination of modifier and console keys that interrupted the current process.
    /// @return One of the enumeration values that specifies the key combination that interrupted the current process. There is no default value.
    console_special_key special_key() const {return special_key_;}

  private:
    bool cancel_ = false;
    console_special_key special_key_ = static_cast<console_special_key>(0);
  };
}
