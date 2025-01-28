/// @file
/// @brief Contains xtd::console_cancel_event_args event args.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "console_special_key.hpp"
#include "event_args.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Provides data for the console::cancel_key_press event. This class cannot be inherited.
  /// @par Header
  /// ```cpp
  /// #include <xtd/console_cancel_event_args>
  /// ```
    /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core events
  /// @remarks A user can interrupt a console application process by simultaneously pressing the Control modifier key and the C console key (Ctrl+C), or the Control modifier key and the Break console key (Ctrl+Break). The console consequently provides a console_cancel_event_args object to the event handler for the console::cancel_key_press event to specify whether the process should be cancelled.
  /// @remarks If the cancel property is set to true in the event handler, the process is resumed; otherwise, the process is terminated. By default, the value of the console_cancel_event_args property is false, and the process terminates.
  class console_cancel_event_args final : public xtd::event_args {
  public:
    /// @name Public Constructors
    
    /// @{
    /// @brief Initializes a new instance of the console_cancel_event_args class.
    console_cancel_event_args() = default;
    
    /// @brief Initializes a new instance of the console_cancel_event_args class.
    /// @param special_key One of the enumeration values that specifies the key combination that interrupted the current process. There is no default value..
    explicit console_cancel_event_args(console_special_key special_key);
    /// @}
    
    /// @cond
    console_cancel_event_args(const console_cancel_event_args&) = default;
    console_cancel_event_args& operator =(const console_cancel_event_args&) = default;
    /// @endcond
    
    /// @name Public Properties
    
    /// @{
    /// @brief Gets a value that indicates whether simultaneously pressing the Control modifier key and the C console key (Ctrl+C) or the Ctrl+Break keys terminates the current process. The default is false, which terminates the current process.
    /// @return `true` if the current process should resume when the event handler concludes; false if the current process should terminate. The default value is false; the current process terminates when the event handler returns. If true, the current process continues.
    bool cancel() const noexcept;
    
    /// @brief Sets a value that indicates whether simultaneously pressing the Control modifier key and the C console key (Ctrl+C) or the Ctrl+Break keys terminates the current process. The default is false, which terminates the current process.
    /// @param true if the current process should resume when the event handler concludes; false if the current process should terminate. The default value is false; the current process terminates when the event handler returns. If true, the current process continues.
    void cancel(bool cancel);
    
    /// @brief Gets the combination of modifier and console keys that interrupted the current process.
    /// @return One of the enumeration values that specifies the key combination that interrupted the current process. There is no default value.
    console_special_key special_key() const noexcept;
    /// @}
    
  private:
    bool cancel_ = false;
    console_special_key special_key_ = static_cast<console_special_key>(0);
  };
}
