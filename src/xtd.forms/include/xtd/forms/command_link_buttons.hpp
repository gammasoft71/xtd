/// @file
/// @brief Contains xtd::forms::command_link_buttons factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "command_link_button.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of command_link_button objects for use by a Windows Forms application.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/command_link_buttons>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of command_link_buttons control factory.
    /// @include command_link_buttons.cpp
    class command_link_buttons final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Create a system-defined command_link_button that represent abort command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto abort() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent abort command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto abort(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent abort command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto abort(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent abort command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto abort(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent abort command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto abort(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent abort command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto abort(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent abort command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto abort(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent abort command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto abort(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent about command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto about() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent about command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto about(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent about command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto about(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent about command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto about(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent about command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto about(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent about command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto about(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent about command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto about(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent about command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto about(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent actual_size command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto actual_size() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent actual_size command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto actual_size(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent actual_size command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto actual_size(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent actual_size command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto actual_size(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent actual_size command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto actual_size(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent actual_size command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto actual_size(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent actual_size command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto actual_size(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent actual_size command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto actual_size(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent add command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto add() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent add command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto add(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent add command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto add(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent add command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto add(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent add command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto add(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent add command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto add(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent add command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto add(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent add command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto add(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto alignment() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto alignment(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto alignment(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto alignment(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto alignment(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto alignment(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto alignment(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent alignment command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto alignment(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent align_left command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_left() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_left command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_left(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_left command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_left(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_left command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_left(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_left command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_left(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_left command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_left(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_left command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_left(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_left command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_left(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent align_right command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_right() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_right command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_right(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_right command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_right(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_right command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_right(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_right command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_right(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_right command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_right(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_right command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_right(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent align_right command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto align_right(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent apply command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto apply() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent apply command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto apply(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent apply command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto apply(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent apply command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto apply(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent apply command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto apply(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent apply command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto apply(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent apply command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto apply(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent apply command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto apply(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto ascending() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ascending(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ascending(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ascending(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ascending(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ascending(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ascending(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ascending command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ascending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent back command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto back() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent back command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto back(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent back command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto back(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent back command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto back(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent back command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto back(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent back command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto back(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent back command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto back(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent back command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto back(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent bold command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto bold() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bold command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bold(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bold command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bold(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bold command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bold(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bold command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bold(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bold command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bold(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bold command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bold(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bold command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bold(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto bottom() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bottom(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bottom(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bottom(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bottom(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bottom(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bottom(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent bottom command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto bottom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto cancel() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cancel(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cancel(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cancel(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cancel(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cancel(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cancel(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cancel command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cancel(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent cdrom command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto cdrom() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cdrom command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cdrom(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cdrom command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cdrom(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cdrom command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cdrom(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cdrom command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cdrom(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cdrom command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cdrom(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cdrom command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cdrom(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cdrom command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cdrom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent centered command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto centered() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent centered command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto centered(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent centered command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto centered(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent centered command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto centered(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent centered command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto centered(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent centered command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto centered(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent centered command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto centered(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent centered command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto centered(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent clear command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto clear() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent clear command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto clear(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent clear command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto clear(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent clear command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto clear(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent clear command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto clear(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent clear command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto clear(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent clear command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto clear(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent clear command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto clear(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent close command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto close() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent close command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto close(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent close command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto close(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent close command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto close(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent close command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto close(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent close command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto close(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent close command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto close(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent close command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto close(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent color command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto color() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent color command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto color(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent color command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto color(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent color command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto color(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent color command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto color(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent color command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto color(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent color command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto color(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent color command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto color(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent contents command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto contents() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent contents command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto contents(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent contents command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto contents(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent contents command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto contents(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent contents command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto contents(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent contents command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto contents(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent contents command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto contents(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent contents command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto contents(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent convert command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto convert() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent convert command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto convert(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent convert command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto convert(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent convert command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto convert(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent convert command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto convert(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent convert command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto convert(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent convert command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto convert(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent convert command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto convert(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent copy command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto copy() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent copy command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto copy(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent copy command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto copy(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent copy command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto copy(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent copy command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto copy(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent copy command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto copy(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent copy command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto copy(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent copy command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto copy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent customize command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto customize() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent customize command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto customize(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent customize command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto customize(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent customize command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto customize(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent customize command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto customize(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent customize command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto customize(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent customize command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto customize(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent customize command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto customize(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent cut command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto cut() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cut command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cut(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cut command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cut(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cut command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cut(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cut command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cut(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cut command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cut(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cut command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cut(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent cut command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto cut(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent del command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto del() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent del command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto del(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent del command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto del(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent del command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto del(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent del command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto del(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent del command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto del(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent del command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto del(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent del command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto del(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent descending command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto descending() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent descending command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto descending(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent descending command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto descending(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent descending command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto descending(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent descending command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto descending(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent descending command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto descending(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent descending command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto descending(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent descending command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto descending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent down command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto down() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent down command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto down(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent down command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto down(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent down command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto down(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent down command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto down(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent down command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto down(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent down command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto down(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent down command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto down(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent edit command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto edit() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent edit command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto edit(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent edit command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto edit(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent edit command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto edit(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent edit command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto edit(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent edit command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto edit(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent edit command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto edit(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent edit command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto edit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent execute command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto execute() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent execute command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto execute(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent execute command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto execute(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent execute command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto execute(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent execute command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto execute(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent execute command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto execute(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent execute command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto execute(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent execute command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto execute(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent exit command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto exit() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent exit command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto exit(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent exit command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto exit(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent exit command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto exit(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent exit command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto exit(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent exit command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto exit(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent exit command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto exit(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent exit command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto exit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent file command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto file() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent file command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto file(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent file command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto file(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent file command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto file(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent file command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto file(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent file command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto file(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent file command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto file(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent file command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto file(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent find command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto find() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent find command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto find(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent find command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto find(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent find command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto find(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent find command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto find(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent find command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto find(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent find command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto find(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent find command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto find(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent first command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto first() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent first command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto first(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent first command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto first(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent first command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto first(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent first command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto first(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent first command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto first(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent first command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto first(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent first command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto first(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto floppy() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto floppy(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto floppy(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto floppy(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto floppy(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto floppy(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto floppy(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent floppy command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto floppy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent font command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto font() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent font command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto font(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent font command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto font(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent font command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto font(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent font command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto font(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent font command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto font(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent font command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto font(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent font command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto font(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent forward command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto forward() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent forward command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto forward(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent forward command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto forward(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent forward command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto forward(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent forward command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto forward(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent forward command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto forward(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent forward command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto forward(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent forward command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto forward(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent harddisk command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto harddisk() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent harddisk command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto harddisk(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent harddisk command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto harddisk(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent harddisk command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto harddisk(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent harddisk command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto harddisk(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent harddisk command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto harddisk(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent harddisk command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto harddisk(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent harddisk command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto harddisk(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent help command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto help() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent help command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto help(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent help command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto help(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent help command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto help(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent help command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto help(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent help command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto help(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent help command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto help(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent help command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto help(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent home command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto home() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent home command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto home(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent home command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto home(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent home command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto home(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent home command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto home(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent home command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto home(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent home command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto home(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent home command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto home(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto ignore() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ignore(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ignore(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ignore(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ignore(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ignore(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ignore(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ignore command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ignore(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent indent command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto indent() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent indent command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto indent(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent indent command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto indent(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent indent command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto indent(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent indent command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto indent(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent indent command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto indent(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent indent command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto indent(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent indent command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto indent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent index command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto index() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent index command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto index(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent index command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto index(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent index command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto index(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent index command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto index(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent index command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto index(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent index command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto index(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent index command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto index(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent info command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto info() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent info command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto info(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent info command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto info(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent info command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto info(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent info command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto info(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent info command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto info(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent info command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto info(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent info command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto info(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent italic command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto italic() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent italic command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto italic(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent italic command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto italic(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent italic command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto italic(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent italic command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto italic(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent italic command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto italic(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent italic command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto italic(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent italic command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto italic(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent justified command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto justified() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent justified command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto justified(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent justified command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto justified(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent justified command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto justified(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent justified command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto justified(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent justified command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto justified(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent justified command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto justified(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent justified command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto justified(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent jump_to command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto jump_to() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent jump_to command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto jump_to(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent jump_to command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto jump_to(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent jump_to command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto jump_to(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent jump_to command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto jump_to(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent jump_to command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto jump_to(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent jump_to command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto jump_to(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent jump_to command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto jump_to(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent last command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto last() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent last command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto last(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent last command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto last(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent last command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto last(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent last command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto last(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent last command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto last(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent last command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto last(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent last command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto last(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent network command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto network() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent network command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto network(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent network command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto network(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent network command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto network(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent network command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto network(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent network command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto network(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent network command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto network(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent network command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto network(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent new_ command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto new_() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent new_ command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto new_(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent new_ command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto new_(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent new_ command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto new_(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent new_ command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto new_(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent new_ command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto new_(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent new_ command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto new_(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent new_ command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto new_(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent next command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto next() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent next command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto next(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent next command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto next(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent next command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto next(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent next command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto next(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent next command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto next(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent next command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto next(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent next command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto next(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent no command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto no() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent no command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto no(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent no command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto no(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent no command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto no(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent no command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto no(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent no command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto no(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent no command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto no(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent no command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto no(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent ok command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto ok() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ok command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ok(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ok command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ok(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ok command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ok(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ok command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ok(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ok command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ok(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ok command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ok(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent ok command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto ok(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent open command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto open() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent open command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto open(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent open command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto open(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent open command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto open(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent open command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto open(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent open command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto open(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent open command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto open(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent open command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto open(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent options command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto options() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent options command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto options(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent options command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto options(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent options command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto options(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent options command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto options(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent options command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto options(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent options command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto options(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent options command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto options(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent paste command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto paste() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent paste command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto paste(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent paste command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto paste(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent paste command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto paste(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent paste command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto paste(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent paste command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto paste(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent paste command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto paste(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent paste command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto paste(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto preferences() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto preferences(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto preferences(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto preferences(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto preferences(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto preferences(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto preferences(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent preferences command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto preferences(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent previous command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto previous() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent previous command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto previous(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent previous command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto previous(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent previous command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto previous(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent previous command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto previous(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent previous command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto previous(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent previous command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto previous(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent previous command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto previous(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent print command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto print() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent print_preview command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto print_preview() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print_preview command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print_preview(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print_preview command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print_preview(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print_preview command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print_preview(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print_preview command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print_preview(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print_preview command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print_preview(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print_preview command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print_preview(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent print_preview command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto print_preview(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent properties command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto properties() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent properties command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto properties(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent properties command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto properties(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent properties command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto properties(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent properties command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto properties(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent properties command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto properties(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent properties command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto properties(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent properties command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto properties(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent quit command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto quit() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent quit command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto quit(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent quit command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto quit(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent quit command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto quit(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent quit command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto quit(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent quit command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto quit(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent quit command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto quit(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent quit command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto quit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent redo command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto redo() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent redo command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto redo(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent redo command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto redo(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent redo command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto redo(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent redo command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto redo(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent redo command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto redo(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent redo command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto redo(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent redo command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto redo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto refresh() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto refresh(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto refresh(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto refresh(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto refresh(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto refresh(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto refresh(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent refresh command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto refresh(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent remove command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto remove() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent remove command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto remove(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent remove command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto remove(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent remove command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto remove(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent remove command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto remove(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent remove command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto remove(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent remove command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto remove(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent remove command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto remove(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent replace command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto replace() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent replace command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto replace(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent replace command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto replace(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent replace command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto replace(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent replace command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto replace(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent replace command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto replace(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent replace command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto replace(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent replace command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto replace(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent retry command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto retry() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent retry command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto retry(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent retry command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto retry(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent retry command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto retry(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent retry command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto retry(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent retry command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto retry(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent retry command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto retry(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent retry command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto retry(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent revert_to_saved command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto revert_to_saved() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto revert_to_saved(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto revert_to_saved(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto revert_to_saved(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto revert_to_saved(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto revert_to_saved(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent save command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto save() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent save_as command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto save_as() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save_as command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save_as(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save_as command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save_as(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save_as command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save_as(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save_as command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save_as(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save_as command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save_as(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save_as command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save_as(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent save_as command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto save_as(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent search command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto search() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent search command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto search(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent search command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto search(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent search command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto search(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent search command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto search(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent search command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto search(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent search command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto search(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent search command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto search(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent select_all command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto select_all() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent select_all command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto select_all(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent select_all command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto select_all(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent select_all command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto select_all(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent select_all command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto select_all(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent select_all command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto select_all(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent select_all command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto select_all(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent select_all command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto select_all(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent settings command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto settings() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent settings command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto settings(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent settings command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto settings(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent settings command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto settings(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent settings command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto settings(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent settings command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto settings(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent settings command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto settings(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent settings command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto settings(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent spell_check command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto spell_check() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent spell_check command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto spell_check(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent spell_check command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto spell_check(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent spell_check command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto spell_check(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent spell_check command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto spell_check(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent spell_check command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto spell_check(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent spell_check command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto spell_check(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent spell_check command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto spell_check(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent stop command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto stop() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent stop command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto stop(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent stop command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto stop(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent stop command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto stop(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent stop command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto stop(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent stop command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto stop(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent stop command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto stop(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent stop command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto stop(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto strikeout() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto strikeout(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto strikeout(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto strikeout(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto strikeout(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto strikeout(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto strikeout(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent strikeout command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto strikeout(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent tools command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto tools() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent tools command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto tools(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent tools command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto tools(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent tools command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto tools(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent tools command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto tools(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent tools command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto tools(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent tools command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto tools(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent tools command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto tools(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent top command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto top() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent top command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto top(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent top command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto top(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent top command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto top(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent top command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto top(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent top command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto top(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent top command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto top(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent top command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto top(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto undelete() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undelete(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undelete(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undelete(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undelete(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undelete(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undelete(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undelete command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undelete(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent underline command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto underline() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent underline command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto underline(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent underline command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto underline(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent underline command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto underline(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent underline command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto underline(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent underline command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto underline(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent underline command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto underline(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent underline command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto underline(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent undo command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto undo() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undo command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undo(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undo command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undo(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undo command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undo(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undo command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undo(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undo command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undo(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undo command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undo(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent undo command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto undo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent unindent command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto unindent() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent unindent command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto unindent(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent unindent command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto unindent(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent unindent command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto unindent(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent unindent command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto unindent(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent unindent command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto unindent(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent unindent command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto unindent(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent unindent command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto unindent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent up command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto up() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent up command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto up(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent up command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto up(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent up command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto up(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent up command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto up(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent up command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto up(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent up command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto up(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent up command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto up(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent view command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto view() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent view command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto view(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent view command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto view(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent view command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto view(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent view command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto view(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent view command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto view(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent view command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto view(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent view command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto view(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent window command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto window() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent window command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto window(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent window command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto window(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent window command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto window(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent window command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto window(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent window command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto window(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent window command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto window(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent window command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto window(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent yes command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto yes() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent yes command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto yes(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent yes command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto yes(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent yes command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto yes(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent yes command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto yes(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent yes command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto yes(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent yes command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto yes(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent yes command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto yes(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent zoom_in command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_in() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_in command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_in(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_in command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_in(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_in command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_in(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_in command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_in(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_in command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_in(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_in command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_in(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_in command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_in(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent zoom_out command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_out() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_out command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_out(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_out command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_out(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_out command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_out(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_out command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_out(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_out command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_out(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_out command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_out(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_out command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_out(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      
      /// @brief Create a system-defined command_link_button that represent zoom_to_fit command_link_button
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_to_fit() -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_to_fit(const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_to_fit(const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_to_fit(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_to_fit(const control& parent) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_to_fit(const control& parent, const drawing::point& location) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size) -> command_link_button;
      /// @brief Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      [[nodiscard]] static auto zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> command_link_button;
      /// @}
    };
  }
}
