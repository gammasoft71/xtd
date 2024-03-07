/// @file
/// @brief Contains xtd::forms::progress_changed_event_args event args.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include <xtd/any>
#include <xtd/event_args>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::background_worker::progress_changed event handler.
    /// @par Header
    /// @code #include <xtd/forms/progress_changed_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class progress_changed_event_args : public event_args {
    public:
      /// @cond
      progress_changed_event_args(const progress_changed_event_args&) = default;
      progress_changed_event_args& operator =(const progress_changed_event_args&) = default;
      /// @endcond
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the DoWorkEventArgs class.
      /// @param argument Specifies an argument for an asynchronous operation.
      progress_changed_event_args(int32 progress_percentage, const std::any& user_state) : progress_percentage_(progress_percentage), user_state_(user_state) {}
      /// @}
      
      /// @name Public Properties
      
      /// @{
      int32 progress_percentage() const noexcept {return progress_percentage_;}
      
      /// @brief Gets a value that represents the argument of an asynchronous operation.
      /// @return An object representing the argument of an asynchronous operation.
      std::any user_state() const noexcept {return user_state_;}
      /// @}
      
    private:
      int32 progress_percentage_ = 0;
      std::any user_state_;
    };
  }
}
