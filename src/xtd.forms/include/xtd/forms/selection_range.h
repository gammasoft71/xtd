/// @file
/// @brief Contains xtd::forms::selection_range control.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <chrono>
#include <xtd/object.h>
#include "../forms_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class forms_export_ selection_range : public object {
    public:
      using time_point = std::chrono::system_clock::time_point;

      /// @Name Constructors

      /// @{
      selection_range() = default;
      selection_range(time_point start, time_point end);
      /// @}

      /// @cond
      selection_range(const selection_range&) = default;
      selection_range(selection_range&&) = default;
      selection_range& operator=(const selection_range&) = default;
      /// @endcond


      /// @Name Properties

      /// @{
      virtual time_point end() const;
      virtual void end(time_point value);
      virtual void end(time_t value);
      virtual void end(const std::tm& value);
      virtual void end(int32_t year, int32_t month, int32_t day);
      virtual void end(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second);


      virtual time_point start() const;
      virtual void start(time_point value);
      virtual void start(time_t value);
      virtual void start(const std::tm& value);
      virtual void start(int32_t year, int32_t month, int32_t day);
      virtual void start(int32_t year, int32_t month, int32_t day, int32_t hour, int32_t minute, int32_t second);
      /// @}

    private:
      time_point start_;
      time_point end_;
    };
  }
}
