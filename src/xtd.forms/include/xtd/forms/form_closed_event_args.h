/// @file
/// @brief Contains xtd::forms::form_closed_event_args event args.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once

#include <xtd/event_args.h>
#include "close_reason.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for the form_closed event.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class form_closed_event_args : public event_args {
    public:
      /// @brief Initializes a new instance of the form_closed_event_args class.
      form_closed_event_args() = default;
      /// @brief Initializes a new instance of the form_closed_event_args class.
      /// @param close_raison A close_reason value that represents the reason why the form was closed.A close_reason value that represents the reason why the form was closed.
      explicit form_closed_event_args(forms::close_reason close_reason) : close_reason_(close_reason) {};

      /// @cond
      form_closed_event_args(const form_closed_event_args& form_closed_event_args) = default;
      form_closed_event_args& operator=(const form_closed_event_args& form_closed_event_args) = default;
      /// @endcond

      /// @brief Gets a value that indicates why the form was closed.
      /// @return One of the close_reason enumerated values.
      /// @remarks A Form can be closed because of a variety of reasons, both user-initiated and programmatic. The close_reason property indicates the reason for the closure.
      forms::close_reason close_reason() const {return close_reason_;}

    private:
      forms::close_reason close_reason_ = forms::close_reason::none;
    };
  }
}
