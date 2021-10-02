/// @file
/// @brief Contains xtd::forms::dialog_closed_event_args dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <xtd/event_args.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides data for a dialog closed event.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms events
    class dialog_closed_event_args final : public event_args {
    public:
      /// @brief Initializes a new instance of the dialog_closed_event_args class.
      dialog_closed_event_args() = default;
      /// @brief Initializes a new instance of the dialog_closed_event_args class.
      /// @param dialog_result The dialog_result contains the result when closing dialog.
      explicit dialog_closed_event_args(forms::dialog_result dialog_result) : dialog_result_(dialog_result) {};
      
      /// @brief Get the dialog_result contains the result when closing dialog.
      /// One of dialog_result enumerated values.
      virtual forms::dialog_result dialog_result() const {return dialog_result_;}
      
    private:
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
    };
  }
}
