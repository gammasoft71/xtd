/// @file
/// @brief Contains xtd::forms::run_worker_completed_event_args event args.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <xtd/any>
#include <xtd/event_args>
#include <xtd/optional>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::background_worker::run_worker_completed event handler.
    /// @par Header
    /// @code #include <xtd/forms/run_wrker_completed_event_args> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class run_worker_completed_event_args : public event_args {
    public:
      /// @cond
      run_worker_completed_event_args(const run_worker_completed_event_args& do_work_event_args) = default;
      run_worker_completed_event_args& operator =(const run_worker_completed_event_args& do_work_event_args) = default;
      /// @endcond
      
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the DoWorkEventArgs class.
      /// @param argument Specifies an argument for an asynchronous operation.
      run_worker_completed_event_args(const std::any& result, std::optional<std::reference_wrapper<std::exception>> exception, bool cancel) : cancel_(cancel), exception_(exception), result_(result) {}
      /// @}
      
      /// @name Properties
      
      /// @{
      bool cancel() const noexcept {return cancel_;}
      void cancel(bool value) {cancel_ = value;}
      
      /// @brief Gets a value that represents the argument of an asynchronous operation.
      /// @return An object representing the argument of an asynchronous operation.
      std::any user_state() const noexcept {return user_state_;}
      
      std::any result() const noexcept {return result_;}
      /// @}
      
    private:
      bool cancel_ = false;
      std::optional<std::reference_wrapper<std::exception>> exception_;
      std::any result_;
      std::any user_state_;
    };
  }
}
