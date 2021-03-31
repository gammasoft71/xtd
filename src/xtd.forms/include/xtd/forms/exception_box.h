/// @file
/// @brief Contains xtd::forms::exception_box dialog.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include "exception_dialog.h"
#include "iwin32_window.h"
#include <xtd/static.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class control;
    /// @endcond

    class exception_box final static_ {
    public:
      static dialog_result show(const iwin32_window& owner) {return show_exception_dialog(&owner);}
      static dialog_result show(const iwin32_window& owner, const std::string& caption) {return show_exception_dialog(&owner, nullptr, caption);}
      static dialog_result show(const iwin32_window& owner, const std::exception& exception) {return show_exception_dialog(&owner, &exception);}
      static dialog_result show(const iwin32_window& owner, const std::exception& exception, const std::string& caption) {return show_exception_dialog(&owner, &exception, caption);}
      
      static dialog_result show() {return show_exception_dialog(nullptr);}
      static dialog_result show(const std::string& caption) {return show_exception_dialog(nullptr, nullptr, caption);}
      static dialog_result show(const std::exception& exception) {return show_exception_dialog(nullptr, &exception);}
      static dialog_result show(const std::exception& exception, const std::string& caption) {return show_exception_dialog(nullptr, &exception, caption);}
      
    private:
      static dialog_result show_exception_dialog(const iwin32_window* owner, const std::exception* exception = nullptr, const std::string& caption = "") {
        exception_dialog dialog;
        if (exception) dialog.exception(*exception);
        dialog.text(caption);
        return owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
      }
    };
  }
}
