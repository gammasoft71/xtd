/// @file
/// @brief Contains xtd::forms::loading_indicators factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
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
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator.
      /// @return The created loading indicator.
      static loading_indicator bar() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator bar(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator bar(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator bar(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator bar(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator bar(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator bar(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator bar(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator bar(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator bar(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator bar(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator bar(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator bar(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator bar(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator bar(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent bar loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator bar(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_bars() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_bars loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_bars(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent circle_blinks loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator circle_blinks(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_center loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_center(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_chronological loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_chronological(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_pulse loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_pulse(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines_wave loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines_wave(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent five_lines loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator five_lines(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator pulse(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator pulse(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent pulse_outline loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator pulse_outline(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator.
      /// @return The created loading indicator.
      static loading_indicator standard() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator standard(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator standard(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator standard(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator standard(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator standard(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator standard(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator standard(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator standard(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator standard(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator standard(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator standard(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator standard(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator standard(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator standard(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent standard loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator standard(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator.
      /// @return The created loading indicator.
      static loading_indicator system() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator system(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator system(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator system(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator system(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator system(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator system(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator system(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator system(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator system(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator system(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator system(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator system(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator system(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator system(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent system loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator system(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator three_balls(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_bouncing loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_bouncing(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation() noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified location.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified location, and size.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified location, size, and name.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified and running state.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified running state, and location.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified running state, location, and size.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified running state, location, size, and name.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent.
      /// @param parent The control that contains the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const control& parent) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const control& parent, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, and running state.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const control& parent, bool running) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, running state, and location.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const control& parent, bool running, const xtd::drawing::point& location) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, running state, location, and size.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size) noexcept;
      /// @brief Create a system-defined xtd::forms::loading_indicator that represent three_balls_rotation loading indicator with specified parent, running state, location, size, and name.
      /// @param parent The control that contains the loading indicator.
      /// @param running true if the loading indicator is running; otherwise false.
      /// @param location The loading indicator location in pixels.
      /// @param size The loading indicator size in pixels.
      /// @param name The name of the loading indicator.
      /// @return The created loading indicator.
      static loading_indicator three_balls_rotation(const control& parent, bool running, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::ustring& name) noexcept;
      /// @}
    };
  }
}
