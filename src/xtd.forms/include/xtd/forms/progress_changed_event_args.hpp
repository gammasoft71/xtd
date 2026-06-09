/// @file
/// @brief Contains xtd::forms::progress_changed_event_args event args.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
    /// ```cpp
    /// #include <xtd/forms/progress_changed_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class progress_changed_event_args : public xtd::event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the DoWorkEventArgs class.
      /// @param argument Specifies an argument for an asynchronous operation.
      progress_changed_event_args(xtd::int32 progress_percentage, const xtd::any_object& user_state) : progress_percentage_(progress_percentage), user_state_(user_state) {}
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value representing the progress percentage of an asynchronous operation.
      /// @return The progress percentage of an asynchronous operation.
      [[nodiscard]] auto progress_percentage() const noexcept -> xtd::int32 {return progress_percentage_;}
      
      /// @brief Gets a value that represents the argument of an asynchronous operation.
      /// @return An object representing the argument of an asynchronous operation.
      [[nodiscard]] auto user_state() const noexcept -> xtd::any_object {return user_state_;}
      /// @}
      
    private:
      xtd::int32 progress_percentage_ = 0;
      xtd::any_object user_state_;
    };
  }
}
