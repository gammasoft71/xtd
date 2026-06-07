/// @file
/// @brief Contains xtd::forms::loading_indicators factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "loading_indicator.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of loading indicator objects for use by a Windows Forms application.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/loading_indicators>
    /// ```
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
      /// @name Public Static Properties
      
      /// @{
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto bar(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_bars(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto circle_blinks(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_center(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_chronological(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_pulse(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines_wave(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto five_lines(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto pulse_outline(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto standard(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto system(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_bouncing(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation() noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified and running state.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified running state, and location.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified running state, location, and size.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified running state, location, size, and name.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::forms::control& parent) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::forms::control& parent, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::forms::control& parent, bool running) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept -> xtd::forms::loading_indicator;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running `true` if the loading indicator is running; otherwise `false`.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      [[nodiscard]] static auto three_balls_rotation(const xtd::forms::control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) noexcept -> xtd::forms::loading_indicator;
      /// @}
    };
  }
}
