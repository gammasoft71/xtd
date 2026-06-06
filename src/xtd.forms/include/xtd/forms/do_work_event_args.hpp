/// @file
/// @brief Contains xtd::forms::do_work_event_args event args.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "cancel_event_args.hpp"
#include <xtd/any>
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the xtd::forms::background_worker::do_work event handler.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/do_work_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class do_work_event_args : public xtd::forms::cancel_event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the DoWorkEventArgs class.
      /// @param argument Specifies an argument for an asynchronous operation.
      explicit do_work_event_args(const xtd::any_object& argument) : argument_(argument) {}
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value that represents the argument of an asynchronous operation.
      /// @return An object representing the argument of an asynchronous operation.
      [[nodiscard]] auto argument() const noexcept -> const xtd::any_object& {return argument_;}
      
      /// @brief Gets a value that represents the result of an asynchronous operation.
      /// @return A xtd::any_object representing the result of an asynchronous operation.
      [[nodiscard]] auto result() const noexcept -> const xtd::any_object& {return result_;}
      /// @brief Sets a value that represents the result of an asynchronous operation.
      /// @param value A xtd::any_object representing the result of an asynchronous operation.
      auto result(const xtd::any_object& value) -> do_work_event_args& {
        result_ = value;
        return *this;
      }
      /// @}
      
    private:
      xtd::any_object argument_;
      xtd::any_object result_;
    };
  }
}
