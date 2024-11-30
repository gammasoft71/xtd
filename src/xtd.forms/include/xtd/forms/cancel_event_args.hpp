/// @file
/// @brief Contains xtd::forms::cancel_event_args event args.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/event_args>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for a cancelable event.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/cancel_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    /// @remarks A cancelable event is raised by a component when it is about to perform an action that can be canceled, such as the closing event of a form.
    class cancel_event_args : public event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the cancel_event_args class with the cancel property set to false.
      cancel_event_args() = default;
      
      /// @brief Initializes a new instance of the cancel_event_args class with the cancel property set to the given value.
      /// @param cancel true to cancel the event; otherwise, false.
      explicit cancel_event_args(bool cancel) : cancel_(cancel) {};
      /// @}
      
      /// @cond
      cancel_event_args(const cancel_event_args& cancel_event_args) = default;
      cancel_event_args& operator =(const cancel_event_args& cancel_event_args) = default;
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicating whether the event should be canceled.
      /// @return true if the event should be canceled; otherwise, false.
      virtual bool cancel() const noexcept {return cancel_;}
      /// @brief Sets a value indicating whether the event should be canceled.
      /// @param cancel true if the event should be canceled; otherwise, false.
      virtual void cancel(bool cancel) {cancel_ = cancel;}
      /// @}
      
    protected:
      bool cancel_ = false;
    };
  }
}
