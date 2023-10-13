/// @file
/// @brief Contains xtd::forms::loading_indicators factory.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "loading_indicator.h"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of loading indicator objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/loading_indicators> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of loading_indicators control factory.
    /// @include loading_indicators.cpp
    class forms_export_ loading_indicators static_ {
      struct data;
      
    public:
      /// @name Properties
      
      /// @{
      /// @brief Create a system-defined loading_indicator that represent circle blinks loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator circle_blinks(const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      /// @brief Create a system-defined loading_indicator that represent circle blinks loading indicator.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator circle_blinks(const control& parent, const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      
      /// @brief Create a system-defined loading_indicator that represent five lines chronological loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator five_lines_chronological(const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      /// @brief Create a system-defined loading_indicator that represent five lines chronological loading indicator.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator five_lines_chronological(const control& parent, const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      
      /// @brief Create a system-defined loading_indicator that represent five lines loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator five_lines(const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      /// @brief Create a system-defined loading_indicator that represent five lines loading indicator.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator five_lines(const control& parent, const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;

      /// @brief Create a system-defined loading_indicator that represent standard loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator standard(const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      /// @brief Create a system-defined loading_indicator that represent standard loading indicator.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator standard(const control& parent, const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;

      /// @brief Create a system-defined loading_indicator that represent system loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator system(const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      /// @brief Create a system-defined loading_indicator that represent system loading indicator.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator system(const control& parent, const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;

      /// @brief Create a system-defined loading_indicator that represent three_balls loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator three_balls(const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      /// @brief Create a system-defined loading_indicator that represent three_balls loading indicator.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator three_balls(const control& parent, const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;

      /// @brief Create a system-defined loading_indicator that represent three_balls_bouncing loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator three_balls_bouncing(const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      /// @brief Create a system-defined loading_indicator that represent three_balls_bouncing loading indicator.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator three_balls_bouncing(const control& parent, const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;

      /// @brief Create a system-defined loading_indicator that represent three_balls_rotation loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator three_balls_rotation(const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      /// @brief Create a system-defined loading_indicator that represent three_balls_rotation loading indicator.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading_indicator location in pixels.
      /// @param size The loading_indicator size in pixels.
      /// @return The created loading_indicator.
      static loading_indicator three_balls_rotation(const control& parent, const xtd::drawing::point& location = {-1, -1}, const xtd::drawing::size& size = {-1, -1}, bool running = true) noexcept;
      /// @}
      
    };
  }
}
