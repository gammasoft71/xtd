/// @file
/// @brief Contains xtd::forms::selection_range control.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <xtd/date_time.h>
#include <xtd/object.h>
#include "../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class forms_export_ selection_range : public object {
    public:
      /// @Name Constructors
      
      /// @{
      selection_range() = default;
      selection_range(date_time start, date_time end);
      /// @}
      
      /// @cond
      selection_range(const selection_range&) = default;
      selection_range(selection_range&&) = default;
      selection_range& operator =(const selection_range&) = default;
      /// @endcond
      
      
      /// @Name Properties
      
      /// @{
      virtual date_time end() const;
      virtual void end(date_time value);
      
      
      virtual date_time start() const;
      virtual void start(date_time value);
      /// @}
      
    private:
      date_time start_;
      date_time end_;
    };
  }
}
