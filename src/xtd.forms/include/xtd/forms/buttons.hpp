/// @file
/// @brief Contains xtd::forms::buttons factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "button.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of button objects for use by a Windows Forms application.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/buttons>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of buttons control factory.
    /// @include buttons.cpp
    class buttons final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Create a system-defined button that represent abort button
      /// @return The created button.
      [[nodiscard]] static auto abort() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent abort button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto abort(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent abort button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto abort(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent abort button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto abort(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent abort button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent abort button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent abort button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent abort button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent about button
      /// @return The created button.
      [[nodiscard]] static auto about() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent about button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto about(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent about button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto about(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent about button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto about(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent about button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent about button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent about button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent about button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent actual_size button
      /// @return The created button.
      [[nodiscard]] static auto actual_size() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent actual_size button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto actual_size(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent actual_size button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto actual_size(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent actual_size button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto actual_size(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent actual_size button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent actual_size button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent actual_size button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent actual_size button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent add button
      /// @return The created button.
      [[nodiscard]] static auto add() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent add button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto add(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent add button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto add(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent add button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto add(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent add button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent add button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent add button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent add button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent alignment button
      /// @return The created button.
      [[nodiscard]] static auto alignment() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent alignment button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto alignment(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent alignment button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto alignment(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent alignment button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto alignment(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent alignment button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent alignment button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent alignment button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent alignment button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent align_left button
      /// @return The created button.
      [[nodiscard]] static auto align_left() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_left button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto align_left(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_left button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto align_left(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_left button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto align_left(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_left button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_left button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_left button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_left button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent align_right button
      /// @return The created button.
      [[nodiscard]] static auto align_right() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_right button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto align_right(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_right button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto align_right(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_right button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto align_right(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_right button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_right button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_right button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent align_right button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent apply button
      /// @return The created button.
      [[nodiscard]] static auto apply() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent apply button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto apply(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent apply button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto apply(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent apply button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto apply(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent apply button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent apply button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent apply button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent apply button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent ascending button
      /// @return The created button.
      [[nodiscard]] static auto ascending() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ascending button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ascending(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ascending button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ascending(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ascending button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto ascending(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ascending button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ascending button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ascending button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ascending button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent back button
      /// @return The created button.
      [[nodiscard]] static auto back() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent back button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto back(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent back button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto back(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent back button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto back(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent back button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent back button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent back button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent back button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent bold button
      /// @return The created button.
      [[nodiscard]] static auto bold() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bold button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto bold(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bold button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto bold(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bold button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto bold(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bold button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bold button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bold button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bold button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent bottom button
      /// @return The created button.
      [[nodiscard]] static auto bottom() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bottom button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto bottom(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bottom button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto bottom(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bottom button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto bottom(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bottom button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bottom button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bottom button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent bottom button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent cancel button
      /// @return The created button.
      [[nodiscard]] static auto cancel() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cancel button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cancel(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cancel button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cancel(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cancel button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto cancel(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cancel button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cancel button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cancel button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cancel button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent cdrom button
      /// @return The created button.
      [[nodiscard]] static auto cdrom() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cdrom button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cdrom(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cdrom button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cdrom(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cdrom button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto cdrom(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cdrom button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cdrom button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cdrom button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cdrom button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent centered button
      /// @return The created button.
      [[nodiscard]] static auto centered() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent centered button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto centered(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent centered button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto centered(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent centered button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto centered(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent centered button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent centered button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent centered button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent centered button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent clear button
      /// @return The created button.
      [[nodiscard]] static auto clear() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent clear button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto clear(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent clear button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto clear(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent clear button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto clear(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent clear button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent clear button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent clear button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent clear button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent close button
      /// @return The created button.
      [[nodiscard]] static auto close() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent close button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto close(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent close button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto close(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent close button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto close(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent close button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent close button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent close button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent close button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent color button
      /// @return The created button.
      [[nodiscard]] static auto color() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent color button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto color(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent color button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto color(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent color button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto color(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent color button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent color button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent color button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent color button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent contents button
      /// @return The created button.
      [[nodiscard]] static auto contents() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent contents button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto contents(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent contents button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto contents(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent contents button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto contents(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent contents button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent contents button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent contents button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent contents button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent convert button
      /// @return The created button.
      [[nodiscard]] static auto convert() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent convert button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto convert(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent convert button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto convert(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent convert button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto convert(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent convert button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent convert button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent convert button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent convert button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent copy button
      /// @return The created button.
      [[nodiscard]] static auto copy() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent copy button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto copy(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent copy button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto copy(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent copy button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto copy(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent copy button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent copy button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent copy button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent copy button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent customize button
      /// @return The created button.
      [[nodiscard]] static auto customize() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent customize button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto customize(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent customize button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto customize(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent customize button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto customize(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent customize button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent customize button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent customize button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent customize button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent cut button
      /// @return The created button.
      [[nodiscard]] static auto cut() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cut button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cut(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cut button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cut(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cut button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto cut(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cut button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cut button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cut button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent cut button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent del button
      /// @return The created button.
      [[nodiscard]] static auto del() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent del button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto del(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent del button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto del(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent del button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto del(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent del button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent del button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent del button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent del button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent descending button
      /// @return The created button.
      [[nodiscard]] static auto descending() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent descending button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto descending(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent descending button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto descending(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent descending button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto descending(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent descending button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent descending button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent descending button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent descending button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent down button
      /// @return The created button.
      [[nodiscard]] static auto down() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent down button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto down(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent down button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto down(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent down button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto down(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent down button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent down button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent down button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent down button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent edit button
      /// @return The created button.
      [[nodiscard]] static auto edit() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent edit button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto edit(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent edit button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto edit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent edit button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto edit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent edit button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent edit button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent edit button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent edit button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent execute button
      /// @return The created button.
      [[nodiscard]] static auto execute() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent execute button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto execute(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent execute button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto execute(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent execute button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto execute(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent execute button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent execute button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent execute button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent execute button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent exit button
      /// @return The created button.
      [[nodiscard]] static auto exit() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent exit button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto exit(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent exit button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto exit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent exit button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto exit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent exit button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent exit button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent exit button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent exit button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent file button
      /// @return The created button.
      [[nodiscard]] static auto file() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent file button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto file(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent file button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto file(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent file button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto file(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent file button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent file button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent file button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent file button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent find button
      /// @return The created button.
      [[nodiscard]] static auto find() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent find button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto find(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent find button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto find(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent find button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto find(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent find button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent find button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent find button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent find button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent first button
      /// @return The created button.
      [[nodiscard]] static auto first() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent first button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto first(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent first button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto first(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent first button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto first(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent first button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent first button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent first button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent first button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent floppy button
      /// @return The created button.
      [[nodiscard]] static auto floppy() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent floppy button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto floppy(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent floppy button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto floppy(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent floppy button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto floppy(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent floppy button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent floppy button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent floppy button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent floppy button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent font button
      /// @return The created button.
      [[nodiscard]] static auto font() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent font button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto font(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent font button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto font(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent font button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto font(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent font button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent font button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent font button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent font button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent forward button
      /// @return The created button.
      [[nodiscard]] static auto forward() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent forward button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto forward(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent forward button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto forward(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent forward button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto forward(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent forward button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent forward button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent forward button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent forward button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent harddisk button
      /// @return The created button.
      [[nodiscard]] static auto harddisk() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent harddisk button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto harddisk(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent harddisk button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto harddisk(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent harddisk button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto harddisk(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent harddisk button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent harddisk button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent harddisk button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent harddisk button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent help button
      /// @return The created button.
      [[nodiscard]] static auto help() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent help button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto help(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent help button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto help(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent help button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto help(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent help button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent help button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent help button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent help button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent home button
      /// @return The created button.
      [[nodiscard]] static auto home() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent home button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto home(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent home button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto home(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent home button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto home(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent home button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent home button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent home button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent home button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent ignore button
      /// @return The created button.
      [[nodiscard]] static auto ignore() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ignore button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ignore(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ignore button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ignore(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ignore button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto ignore(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ignore button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ignore button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ignore button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ignore button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent indent button
      /// @return The created button.
      [[nodiscard]] static auto indent() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent indent button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto indent(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent indent button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto indent(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent indent button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto indent(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent indent button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent indent button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent indent button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent indent button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent index button
      /// @return The created button.
      [[nodiscard]] static auto index() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent index button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto index(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent index button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto index(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent index button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto index(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent index button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent index button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent index button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent index button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent info button
      /// @return The created button.
      [[nodiscard]] static auto info() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent info button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto info(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent info button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto info(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent info button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto info(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent info button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent info button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent info button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent info button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent italic button
      /// @return The created button.
      [[nodiscard]] static auto italic() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent italic button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto italic(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent italic button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto italic(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent italic button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto italic(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent italic button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent italic button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent italic button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent italic button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent justified button
      /// @return The created button.
      [[nodiscard]] static auto justified() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent justified button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto justified(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent justified button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto justified(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent justified button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto justified(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent justified button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent justified button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent justified button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent justified button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent jump_to button
      /// @return The created button.
      [[nodiscard]] static auto jump_to() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent jump_to button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto jump_to(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent jump_to button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto jump_to(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent jump_to button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto jump_to(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent jump_to button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent jump_to button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent jump_to button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent jump_to button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent last button
      /// @return The created button.
      [[nodiscard]] static auto last() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent last button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto last(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent last button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto last(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent last button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto last(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent last button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent last button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent last button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent last button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent network button
      /// @return The created button.
      [[nodiscard]] static auto network() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent network button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto network(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent network button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto network(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent network button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto network(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent network button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent network button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent network button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent network button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent new_ button
      /// @return The created button.
      [[nodiscard]] static auto new_() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent new_ button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto new_(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent new_ button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto new_(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent new_ button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto new_(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent new_ button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent new_ button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent new_ button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent new_ button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent next button
      /// @return The created button.
      [[nodiscard]] static auto next() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent next button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto next(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent next button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto next(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent next button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto next(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent next button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent next button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent next button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent next button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent no button
      /// @return The created button.
      [[nodiscard]] static auto no() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent no button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto no(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent no button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto no(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent no button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto no(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent no button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent no button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent no button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent no button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent ok button
      /// @return The created button.
      [[nodiscard]] static auto ok() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ok button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ok(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ok button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ok(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ok button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto ok(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ok button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ok button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ok button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent ok button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent open button
      /// @return The created button.
      [[nodiscard]] static auto open() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent open button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto open(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent open button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto open(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent open button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto open(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent open button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent open button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent open button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent open button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent options button
      /// @return The created button.
      [[nodiscard]] static auto options() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent options button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto options(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent options button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto options(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent options button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto options(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent options button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent options button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent options button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent options button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent paste button
      /// @return The created button.
      [[nodiscard]] static auto paste() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent paste button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto paste(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent paste button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto paste(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent paste button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto paste(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent paste button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent paste button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent paste button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent paste button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent preferences button
      /// @return The created button.
      [[nodiscard]] static auto preferences() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent preferences button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto preferences(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent preferences button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto preferences(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent preferences button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto preferences(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent preferences button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent preferences button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent preferences button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent preferences button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent previous button
      /// @return The created button.
      [[nodiscard]] static auto previous() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent previous button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto previous(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent previous button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto previous(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent previous button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto previous(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent previous button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent previous button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent previous button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent previous button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent print button
      /// @return The created button.
      [[nodiscard]] static auto print() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto print(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto print(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto print(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent print_preview button
      /// @return The created button.
      [[nodiscard]] static auto print_preview() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print_preview button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto print_preview(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print_preview button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto print_preview(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print_preview button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto print_preview(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print_preview button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print_preview button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print_preview button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent print_preview button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent properties button
      /// @return The created button.
      [[nodiscard]] static auto properties() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent properties button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto properties(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent properties button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto properties(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent properties button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto properties(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent properties button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent properties button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent properties button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent properties button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent quit button
      /// @return The created button.
      [[nodiscard]] static auto quit() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent quit button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto quit(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent quit button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto quit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent quit button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto quit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent quit button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent quit button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent quit button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent quit button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent redo button
      /// @return The created button.
      [[nodiscard]] static auto redo() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent redo button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto redo(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent redo button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto redo(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent redo button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto redo(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent redo button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent redo button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent redo button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent redo button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent refresh button
      /// @return The created button.
      [[nodiscard]] static auto refresh() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent refresh button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto refresh(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent refresh button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto refresh(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent refresh button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto refresh(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent refresh button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent refresh button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent refresh button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent refresh button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent remove button
      /// @return The created button.
      [[nodiscard]] static auto remove() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent remove button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto remove(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent remove button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto remove(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent remove button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto remove(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent remove button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent remove button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent remove button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent remove button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent replace button
      /// @return The created button.
      [[nodiscard]] static auto replace() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent replace button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto replace(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent replace button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto replace(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent replace button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto replace(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent replace button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent replace button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent replace button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent replace button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent retry button
      /// @return The created button.
      [[nodiscard]] static auto retry() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent retry button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto retry(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent retry button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto retry(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent retry button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto retry(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent retry button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent retry button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent retry button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent retry button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent revert_to_saved button
      /// @return The created button.
      [[nodiscard]] static auto revert_to_saved() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent revert_to_saved button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto revert_to_saved(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent revert_to_saved button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto revert_to_saved(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent revert_to_saved button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto revert_to_saved(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent revert_to_saved button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent revert_to_saved button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent revert_to_saved button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent revert_to_saved button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent save button
      /// @return The created button.
      [[nodiscard]] static auto save() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto save(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto save(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto save(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent save_as button
      /// @return The created button.
      [[nodiscard]] static auto save_as() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save_as button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto save_as(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save_as button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto save_as(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save_as button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto save_as(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save_as button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save_as button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save_as button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent save_as button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent search button
      /// @return The created button.
      [[nodiscard]] static auto search() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent search button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto search(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent search button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto search(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent search button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto search(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent search button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent search button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent search button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent search button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent select_all button
      /// @return The created button.
      [[nodiscard]] static auto select_all() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent select_all button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto select_all(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent select_all button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto select_all(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent select_all button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto select_all(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent select_all button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent select_all button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent select_all button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent select_all button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent settings button
      /// @return The created button.
      [[nodiscard]] static auto settings() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent settings button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto settings(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent settings button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto settings(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent settings button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto settings(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent settings button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent settings button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent settings button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent settings button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent spell_check button
      /// @return The created button.
      [[nodiscard]] static auto spell_check() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent spell_check button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto spell_check(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent spell_check button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto spell_check(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent spell_check button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto spell_check(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent spell_check button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent spell_check button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent spell_check button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent spell_check button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent stop button
      /// @return The created button.
      [[nodiscard]] static auto stop() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent stop button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto stop(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent stop button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto stop(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent stop button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto stop(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent stop button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent stop button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent stop button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent stop button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent strikeout button
      /// @return The created button.
      [[nodiscard]] static auto strikeout() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent strikeout button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto strikeout(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent strikeout button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto strikeout(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent strikeout button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto strikeout(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent strikeout button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent strikeout button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent strikeout button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent strikeout button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent tools button
      /// @return The created button.
      [[nodiscard]] static auto tools() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent tools button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto tools(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent tools button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto tools(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent tools button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto tools(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent tools button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent tools button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent tools button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent tools button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent top button
      /// @return The created button.
      [[nodiscard]] static auto top() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent top button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto top(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent top button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto top(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent top button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto top(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent top button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent top button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent top button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent top button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent undelete button
      /// @return The created button.
      [[nodiscard]] static auto undelete() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undelete button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto undelete(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undelete button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto undelete(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undelete button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto undelete(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undelete button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undelete button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undelete button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undelete button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent underline button
      /// @return The created button.
      [[nodiscard]] static auto underline() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent underline button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto underline(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent underline button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto underline(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent underline button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto underline(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent underline button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent underline button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent underline button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent underline button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent undo button
      /// @return The created button.
      [[nodiscard]] static auto undo() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undo button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto undo(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undo button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto undo(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undo button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto undo(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undo button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undo button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undo button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent undo button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent unindent button
      /// @return The created button.
      [[nodiscard]] static auto unindent() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent unindent button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto unindent(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent unindent button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto unindent(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent unindent button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto unindent(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent unindent button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent unindent button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent unindent button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent unindent button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent up button
      /// @return The created button.
      [[nodiscard]] static auto up() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent up button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto up(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent up button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto up(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent up button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto up(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent up button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent up button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent up button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent up button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent view button
      /// @return The created button.
      [[nodiscard]] static auto view() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent view button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto view(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent view button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto view(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent view button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto view(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent view button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent view button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent view button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent view button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent window button
      /// @return The created button.
      [[nodiscard]] static auto window() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent window button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto window(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent window button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto window(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent window button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto window(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent window button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent window button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent window button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent window button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent yes button
      /// @return The created button.
      [[nodiscard]] static auto yes() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent yes button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto yes(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent yes button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto yes(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent yes button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto yes(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent yes button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent yes button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent yes button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent yes button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent zoom_in button
      /// @return The created button.
      [[nodiscard]] static auto zoom_in() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_in button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_in(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_in button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_in(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_in button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto zoom_in(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_in button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_in button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_in button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_in button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent zoom_out button
      /// @return The created button.
      [[nodiscard]] static auto zoom_out() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_out button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_out(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_out button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_out(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_out button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto zoom_out(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_out button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_out button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_out button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_out button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      
      /// @brief Create a system-defined button that represent zoom_to_fit button
      /// @return The created button.
      [[nodiscard]] static auto zoom_to_fit() -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_to_fit button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_to_fit button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_to_fit button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_to_fit button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_to_fit button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_to_fit button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::button;
      /// @brief Create a system-defined button that represent zoom_to_fit button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::button;
      /// @}
    };
  }
}
