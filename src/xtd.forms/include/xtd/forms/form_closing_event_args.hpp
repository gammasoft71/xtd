/// @file
/// @brief Contains xtd::forms::form_closing_event_args event args.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "cancel_event_args.hpp"
#include "close_reason.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the form_closing event.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/form_closing_event_args>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class form_closing_event_args : public xtd::forms::cancel_event_args {
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the form_closing_event_args class.
      form_closing_event_args() = default;
      /// @brief Initializes a new instance of the form_closing_event_args class.
      /// @param value A xtd::forms::close_reason value that represents the reason why the form is being closed.
      /// @remarks The close_reason and cancel parameters are used to initialize the close_reason and cancel properties, respectively.
      explicit form_closing_event_args(xtd::forms::close_reason value) : close_reason_(value) {};
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets a value that indicates why the form is being closed.
      /// @return One of the xtd::forms::close_reason enumerated values.
      [[nodiscard]] auto close_reason() const noexcept -> xtd::forms::close_reason {return close_reason_;}
      /// @}
      
    private:
      xtd::forms::close_reason close_reason_ = xtd::forms::close_reason::none;
    };
  }
}
