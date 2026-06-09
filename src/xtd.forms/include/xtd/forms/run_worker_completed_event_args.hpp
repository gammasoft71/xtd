/// @file
/// @brief Contains xtd::forms::run_worker_completed_event_args event args.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
    /// ```cpp
    /// #include <xtd/forms/run_wrker_completed_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class run_worker_completed_event_args : public xtd::event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the xtd::forms::run_worker_completed_event_args class.
      /// @param argument Specifies an argument for an asynchronous operation.
      run_worker_completed_event_args(const xtd::any_object& result, std::optional<xtd::ref<std::exception>> exception, bool cancel) : cancel_(cancel), exception_(exception), result_(result) {}
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value indicates the asynchronus operation is canceled.
      /// @return `true`if asynchronus operation is canceled; otherwise `false`.
      [[nodiscard]] bool cancel() const noexcept {return cancel_;}
      /// @brief Sets a value indicates the asynchronus operation is canceled.
      /// @param value `true`if asynchronus operation is canceled; otherwise `false`.
      run_worker_completed_event_args& cancel(bool value) {
        cancel_ = value;
        return *this;
      }
      
      /// @brief Gets a value that represents the argument of an asynchronous operation.
      /// @return An object representing the argument of an asynchronous operation.
      [[nodiscard]] xtd::any_object user_state() const noexcept {return user_state_;}
      
      /// @biref Gets a value that represents the result of an asynchronous operation.
      /// @return An xtd::any_object representing the result of an asynchronous operation.
      [[nodiscard]] xtd::any_object result() const noexcept {return result_;}
      /// @}
      
    private:
      bool cancel_ = false;
      std::optional<xtd::ref<std::exception>> exception_;
      xtd::any_object result_;
      xtd::any_object user_state_;
    };
  }
}
