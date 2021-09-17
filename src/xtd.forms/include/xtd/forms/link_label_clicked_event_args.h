/// @file
/// @brief Contains xtd::forms::link_label class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <xtd/event_args.h>
#include "mouse_buttons.h"
#include "link.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class link_label;
    /// @endcond

    /// @brief Represents a Windows label control that can display hyperlinks.
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms forms
    /// @remarks
    class link_label_clicked_event_args : public xtd::event_args {
    public:
      link_label_clicked_event_args(const xtd::forms::link& link, xtd::forms::mouse_buttons button);

      const xtd::forms::link& link() const;
      
      xtd::forms::mouse_buttons button() const;
      
      bool visited() const;
      void visited(bool value);
      
    private:
      xtd::forms::link link_;
      xtd::forms::mouse_buttons button_ = xtd::forms::mouse_buttons::left;
      bool visited_ = false;
    };
  }
}

