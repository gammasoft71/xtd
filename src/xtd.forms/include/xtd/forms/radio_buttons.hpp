/// @file
/// @brief Contains xtd::forms::radio_buttons factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "radio_button.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of radio_button objects for use by a Windows Forms application.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/radio_buttons>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Examples
    /// The following code example demonstrates the use of radio_button control factory.
    /// @include radio_buttons.cpp
    class forms_export_ radio_buttons final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Create a system-defined radio_button that represent abort radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto abort(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent about radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto about() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto about(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent actual_size radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto actual_size(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent add radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto add() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto add(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent alignment radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto alignment(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent align_left radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_left(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent align_right radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto align_right(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent apply radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto apply(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent ascending radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ascending(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent back radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto back() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto back(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent bold radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bold(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent bottom radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto bottom(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent cancel radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cancel(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent cdrom radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cdrom(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent centered radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto centered(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent clear radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto clear(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent close radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto close() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto close(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent color radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto color() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto color(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent contents radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto contents(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent convert radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto convert(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent copy radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto copy(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent customize radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto customize(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent cut radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto cut(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent del radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto del() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto del(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent descending radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto descending(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent down radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto down() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto down(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent edit radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto edit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent execute radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto execute(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent exit radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto exit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent file radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto file() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto file(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent find radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto find() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto find(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent first radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto first() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto first(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent floppy radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto floppy(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent font radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto font() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto font(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent forward radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto forward(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent harddisk radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto harddisk(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent help radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto help() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto help(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent home radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto home() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto home(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent ignore radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ignore(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent indent radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto indent(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent index radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto index() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto index(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent info radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto info() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto info(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent italic radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto italic(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent justified radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto justified(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent jump_to radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto jump_to(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent last radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto last() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto last(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent network radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto network() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto network(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent new_ radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto new_(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent next radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto next() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto next(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent no radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto no() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto no(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent ok radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto ok(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent open radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto open() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto open(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent options radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto options() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto options(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent paste radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto paste(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent preferences radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto preferences(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent previous radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto previous(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent print radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent print_preview radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto print_preview(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent properties radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto properties(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent quit radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto quit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent redo radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto redo(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent refresh radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto refresh(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent remove radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto remove(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent replace radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto replace(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent retry radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto retry(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto revert_to_saved(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent save radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent save_as radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto save_as(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent search radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto search() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto search(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent select_all radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto select_all(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent settings radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto settings(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent spell_check radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto spell_check(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent stop radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto stop(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent strikeout radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto strikeout(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent tools radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto tools(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent top radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto top() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto top(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent undelete radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undelete(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent underline radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto underline(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent undo radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto undo(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent unindent radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto unindent(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent up radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto up() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto up(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent view radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto view() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto view(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent window radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto window() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto window(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent yes radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto yes(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_in(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_out(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit() -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, bool checked) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size) -> xtd::forms::radio_button;
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      [[nodiscard]] static auto zoom_to_fit(const xtd::forms::control& parent, bool checked, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> xtd::forms::radio_button;
      /// @}
    };
  }
}
