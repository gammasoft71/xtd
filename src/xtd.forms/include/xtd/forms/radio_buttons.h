/// @file
/// @brief Contains xtd::forms::radio_buttons factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "radio_button.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of radio_button objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/radio_buttons> @endcode
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
      /// @name Methods
      
      /// @{
      /// @brief Create a system-defined radio_button that represent abort radio_button.
      /// @return The created radio_button.
      static radio_button abort();
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button abort(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button abort(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button abort(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button abort(bool checked);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button abort(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button abort(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button abort(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button abort(const control& parent);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button abort(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button abort(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button abort(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button abort(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button abort(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button abort(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent abort radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button abort(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent about radio_button.
      /// @return The created radio_button.
      static radio_button about();
      /// @brief Create a system-defined radio_button that represent about radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button about(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button about(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button about(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button about(bool checked);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button about(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button about(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button about(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button about(const control& parent);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button about(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button about(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button about(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button about(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button about(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button about(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent about radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button about(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent actual_size radio_button.
      /// @return The created radio_button.
      static radio_button actual_size();
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button actual_size(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button actual_size(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button actual_size(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button actual_size(bool checked);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button actual_size(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button actual_size(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button actual_size(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button actual_size(const control& parent);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button actual_size(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button actual_size(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button actual_size(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button actual_size(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button actual_size(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button actual_size(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent actual_size radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button actual_size(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent add radio_button.
      /// @return The created radio_button.
      static radio_button add();
      /// @brief Create a system-defined radio_button that represent add radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button add(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button add(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button add(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button add(bool checked);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button add(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button add(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button add(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button add(const control& parent);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button add(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button add(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button add(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button add(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button add(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button add(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent add radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button add(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent alignment radio_button.
      /// @return The created radio_button.
      static radio_button alignment();
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button alignment(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button alignment(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button alignment(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button alignment(bool checked);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button alignment(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button alignment(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button alignment(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button alignment(const control& parent);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button alignment(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button alignment(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button alignment(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button alignment(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button alignment(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button alignment(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent alignment radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button alignment(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent align_left radio_button.
      /// @return The created radio_button.
      static radio_button align_left();
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button align_left(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button align_left(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_left(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button align_left(bool checked);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button align_left(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button align_left(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_left(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button align_left(const control& parent);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button align_left(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button align_left(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_left(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button align_left(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button align_left(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button align_left(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent align_left radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_left(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent align_right radio_button.
      /// @return The created radio_button.
      static radio_button align_right();
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button align_right(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button align_right(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_right(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button align_right(bool checked);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button align_right(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button align_right(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_right(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button align_right(const control& parent);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button align_right(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button align_right(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_right(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button align_right(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button align_right(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button align_right(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent align_right radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button align_right(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent apply radio_button.
      /// @return The created radio_button.
      static radio_button apply();
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button apply(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button apply(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button apply(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button apply(bool checked);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button apply(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button apply(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button apply(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button apply(const control& parent);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button apply(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button apply(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button apply(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button apply(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button apply(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button apply(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent apply radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button apply(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent ascending radio_button.
      /// @return The created radio_button.
      static radio_button ascending();
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ascending(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ascending(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ascending(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button ascending(bool checked);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ascending(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ascending(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ascending(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button ascending(const control& parent);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ascending(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ascending(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ascending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button ascending(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ascending(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ascending(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ascending radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ascending(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent back radio_button.
      /// @return The created radio_button.
      static radio_button back();
      /// @brief Create a system-defined radio_button that represent back radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button back(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button back(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button back(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button back(bool checked);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button back(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button back(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button back(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button back(const control& parent);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button back(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button back(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button back(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button back(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button back(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button back(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent back radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button back(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent bold radio_button.
      /// @return The created radio_button.
      static radio_button bold();
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button bold(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button bold(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bold(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button bold(bool checked);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button bold(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button bold(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bold(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button bold(const control& parent);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button bold(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button bold(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bold(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button bold(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button bold(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button bold(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent bold radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bold(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent bottom radio_button.
      /// @return The created radio_button.
      static radio_button bottom();
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button bottom(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button bottom(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bottom(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button bottom(bool checked);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button bottom(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button bottom(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bottom(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button bottom(const control& parent);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button bottom(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button bottom(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bottom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button bottom(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button bottom(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button bottom(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent bottom radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button bottom(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent cancel radio_button.
      /// @return The created radio_button.
      static radio_button cancel();
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cancel(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cancel(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cancel(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button cancel(bool checked);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cancel(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cancel(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cancel(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button cancel(const control& parent);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cancel(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cancel(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cancel(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button cancel(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cancel(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cancel(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cancel radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cancel(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent cdrom radio_button.
      /// @return The created radio_button.
      static radio_button cdrom();
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cdrom(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cdrom(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cdrom(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button cdrom(bool checked);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cdrom(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cdrom(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cdrom(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button cdrom(const control& parent);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cdrom(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cdrom(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cdrom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button cdrom(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cdrom(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cdrom(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cdrom radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cdrom(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent centered radio_button.
      /// @return The created radio_button.
      static radio_button centered();
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button centered(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button centered(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button centered(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button centered(bool checked);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button centered(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button centered(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button centered(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button centered(const control& parent);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button centered(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button centered(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button centered(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button centered(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button centered(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button centered(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent centered radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button centered(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent clear radio_button.
      /// @return The created radio_button.
      static radio_button clear();
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button clear(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button clear(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button clear(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button clear(bool checked);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button clear(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button clear(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button clear(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button clear(const control& parent);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button clear(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button clear(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button clear(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button clear(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button clear(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button clear(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent clear radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button clear(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent close radio_button.
      /// @return The created radio_button.
      static radio_button close();
      /// @brief Create a system-defined radio_button that represent close radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button close(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button close(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button close(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button close(bool checked);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button close(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button close(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button close(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button close(const control& parent);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button close(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button close(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button close(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button close(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button close(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button close(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent close radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button close(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent color radio_button.
      /// @return The created radio_button.
      static radio_button color();
      /// @brief Create a system-defined radio_button that represent color radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button color(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button color(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button color(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button color(bool checked);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button color(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button color(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button color(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button color(const control& parent);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button color(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button color(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button color(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button color(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button color(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button color(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent color radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button color(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent contents radio_button.
      /// @return The created radio_button.
      static radio_button contents();
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button contents(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button contents(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button contents(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button contents(bool checked);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button contents(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button contents(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button contents(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button contents(const control& parent);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button contents(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button contents(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button contents(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button contents(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button contents(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button contents(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent contents radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button contents(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent convert radio_button.
      /// @return The created radio_button.
      static radio_button convert();
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button convert(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button convert(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button convert(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button convert(bool checked);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button convert(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button convert(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button convert(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button convert(const control& parent);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button convert(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button convert(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button convert(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button convert(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button convert(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button convert(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent convert radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button convert(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent copy radio_button.
      /// @return The created radio_button.
      static radio_button copy();
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button copy(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button copy(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button copy(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button copy(bool checked);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button copy(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button copy(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button copy(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button copy(const control& parent);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button copy(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button copy(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button copy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button copy(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button copy(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button copy(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent copy radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button copy(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent customize radio_button.
      /// @return The created radio_button.
      static radio_button customize();
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button customize(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button customize(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button customize(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button customize(bool checked);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button customize(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button customize(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button customize(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button customize(const control& parent);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button customize(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button customize(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button customize(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button customize(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button customize(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button customize(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent customize radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button customize(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent cut radio_button.
      /// @return The created radio_button.
      static radio_button cut();
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cut(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cut(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cut(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button cut(bool checked);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cut(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cut(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cut(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button cut(const control& parent);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cut(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cut(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cut(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button cut(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button cut(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button cut(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent cut radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button cut(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent del radio_button.
      /// @return The created radio_button.
      static radio_button del();
      /// @brief Create a system-defined radio_button that represent del radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button del(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button del(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button del(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button del(bool checked);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button del(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button del(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button del(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button del(const control& parent);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button del(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button del(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button del(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button del(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button del(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button del(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent del radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button del(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent descending radio_button.
      /// @return The created radio_button.
      static radio_button descending();
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button descending(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button descending(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button descending(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button descending(bool checked);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button descending(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button descending(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button descending(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button descending(const control& parent);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button descending(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button descending(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button descending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button descending(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button descending(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button descending(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent descending radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button descending(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent down radio_button.
      /// @return The created radio_button.
      static radio_button down();
      /// @brief Create a system-defined radio_button that represent down radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button down(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button down(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button down(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button down(bool checked);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button down(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button down(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button down(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button down(const control& parent);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button down(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button down(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button down(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button down(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button down(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button down(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent down radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button down(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent edit radio_button.
      /// @return The created radio_button.
      static radio_button edit();
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button edit(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button edit(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button edit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button edit(bool checked);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button edit(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button edit(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button edit(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button edit(const control& parent);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button edit(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button edit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button edit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button edit(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button edit(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button edit(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent edit radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button edit(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent execute radio_button.
      /// @return The created radio_button.
      static radio_button execute();
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button execute(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button execute(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button execute(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button execute(bool checked);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button execute(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button execute(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button execute(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button execute(const control& parent);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button execute(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button execute(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button execute(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button execute(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button execute(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button execute(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent execute radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button execute(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent exit radio_button.
      /// @return The created radio_button.
      static radio_button exit();
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button exit(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button exit(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button exit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button exit(bool checked);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button exit(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button exit(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button exit(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button exit(const control& parent);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button exit(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button exit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button exit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button exit(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button exit(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button exit(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent exit radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button exit(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent file radio_button.
      /// @return The created radio_button.
      static radio_button file();
      /// @brief Create a system-defined radio_button that represent file radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button file(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button file(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button file(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button file(bool checked);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button file(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button file(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button file(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button file(const control& parent);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button file(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button file(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button file(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button file(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button file(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button file(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent file radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button file(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent find radio_button.
      /// @return The created radio_button.
      static radio_button find();
      /// @brief Create a system-defined radio_button that represent find radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button find(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button find(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button find(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button find(bool checked);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button find(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button find(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button find(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button find(const control& parent);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button find(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button find(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button find(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button find(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button find(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button find(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent find radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button find(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent first radio_button.
      /// @return The created radio_button.
      static radio_button first();
      /// @brief Create a system-defined radio_button that represent first radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button first(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button first(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button first(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button first(bool checked);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button first(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button first(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button first(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button first(const control& parent);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button first(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button first(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button first(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button first(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button first(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button first(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent first radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button first(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent floppy radio_button.
      /// @return The created radio_button.
      static radio_button floppy();
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button floppy(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button floppy(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button floppy(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button floppy(bool checked);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button floppy(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button floppy(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button floppy(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button floppy(const control& parent);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button floppy(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button floppy(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button floppy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button floppy(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button floppy(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button floppy(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent floppy radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button floppy(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent font radio_button.
      /// @return The created radio_button.
      static radio_button font();
      /// @brief Create a system-defined radio_button that represent font radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button font(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button font(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button font(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button font(bool checked);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button font(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button font(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button font(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button font(const control& parent);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button font(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button font(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button font(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button font(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button font(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button font(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent font radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button font(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent forward radio_button.
      /// @return The created radio_button.
      static radio_button forward();
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button forward(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button forward(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button forward(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button forward(bool checked);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button forward(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button forward(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button forward(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button forward(const control& parent);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button forward(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button forward(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button forward(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button forward(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button forward(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button forward(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent forward radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button forward(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent harddisk radio_button.
      /// @return The created radio_button.
      static radio_button harddisk();
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button harddisk(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button harddisk(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button harddisk(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button harddisk(bool checked);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button harddisk(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button harddisk(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button harddisk(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button harddisk(const control& parent);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button harddisk(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button harddisk(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button harddisk(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button harddisk(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button harddisk(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button harddisk(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent harddisk radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button harddisk(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent help radio_button.
      /// @return The created radio_button.
      static radio_button help();
      /// @brief Create a system-defined radio_button that represent help radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button help(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button help(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button help(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button help(bool checked);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button help(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button help(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button help(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button help(const control& parent);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button help(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button help(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button help(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button help(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button help(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button help(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent help radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button help(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent home radio_button.
      /// @return The created radio_button.
      static radio_button home();
      /// @brief Create a system-defined radio_button that represent home radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button home(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button home(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button home(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button home(bool checked);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button home(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button home(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button home(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button home(const control& parent);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button home(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button home(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button home(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button home(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button home(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button home(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent home radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button home(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent ignore radio_button.
      /// @return The created radio_button.
      static radio_button ignore();
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ignore(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ignore(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ignore(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button ignore(bool checked);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ignore(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ignore(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ignore(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button ignore(const control& parent);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ignore(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ignore(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ignore(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button ignore(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ignore(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ignore(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ignore radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ignore(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent indent radio_button.
      /// @return The created radio_button.
      static radio_button indent();
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button indent(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button indent(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button indent(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button indent(bool checked);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button indent(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button indent(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button indent(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button indent(const control& parent);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button indent(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button indent(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button indent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button indent(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button indent(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button indent(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent indent radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button indent(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent index radio_button.
      /// @return The created radio_button.
      static radio_button index();
      /// @brief Create a system-defined radio_button that represent index radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button index(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button index(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button index(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button index(bool checked);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button index(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button index(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button index(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button index(const control& parent);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button index(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button index(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button index(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button index(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button index(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button index(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent index radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button index(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent info radio_button.
      /// @return The created radio_button.
      static radio_button info();
      /// @brief Create a system-defined radio_button that represent info radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button info(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button info(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button info(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button info(bool checked);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button info(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button info(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button info(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button info(const control& parent);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button info(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button info(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button info(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button info(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button info(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button info(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent info radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button info(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent italic radio_button.
      /// @return The created radio_button.
      static radio_button italic();
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button italic(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button italic(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button italic(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button italic(bool checked);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button italic(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button italic(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button italic(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button italic(const control& parent);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button italic(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button italic(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button italic(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button italic(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button italic(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button italic(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent italic radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button italic(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent justified radio_button.
      /// @return The created radio_button.
      static radio_button justified();
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button justified(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button justified(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button justified(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button justified(bool checked);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button justified(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button justified(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button justified(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button justified(const control& parent);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button justified(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button justified(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button justified(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button justified(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button justified(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button justified(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent justified radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button justified(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent jump_to radio_button.
      /// @return The created radio_button.
      static radio_button jump_to();
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button jump_to(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button jump_to(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button jump_to(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button jump_to(bool checked);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button jump_to(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button jump_to(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button jump_to(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button jump_to(const control& parent);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button jump_to(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button jump_to(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button jump_to(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button jump_to(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button jump_to(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button jump_to(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent jump_to radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button jump_to(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent last radio_button.
      /// @return The created radio_button.
      static radio_button last();
      /// @brief Create a system-defined radio_button that represent last radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button last(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button last(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button last(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button last(bool checked);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button last(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button last(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button last(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button last(const control& parent);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button last(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button last(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button last(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button last(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button last(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button last(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent last radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button last(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent network radio_button.
      /// @return The created radio_button.
      static radio_button network();
      /// @brief Create a system-defined radio_button that represent network radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button network(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button network(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button network(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button network(bool checked);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button network(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button network(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button network(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button network(const control& parent);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button network(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button network(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button network(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button network(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button network(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button network(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent network radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button network(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent new_ radio_button.
      /// @return The created radio_button.
      static radio_button new_();
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button new_(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button new_(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button new_(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button new_(bool checked);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button new_(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button new_(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button new_(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button new_(const control& parent);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button new_(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button new_(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button new_(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button new_(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button new_(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button new_(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent new_ radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button new_(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent next radio_button.
      /// @return The created radio_button.
      static radio_button next();
      /// @brief Create a system-defined radio_button that represent next radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button next(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button next(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button next(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button next(bool checked);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button next(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button next(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button next(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button next(const control& parent);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button next(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button next(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button next(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button next(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button next(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button next(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent next radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button next(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent no radio_button.
      /// @return The created radio_button.
      static radio_button no();
      /// @brief Create a system-defined radio_button that represent no radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button no(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button no(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button no(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button no(bool checked);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button no(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button no(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button no(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button no(const control& parent);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button no(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button no(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button no(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button no(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button no(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button no(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent no radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button no(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent ok radio_button.
      /// @return The created radio_button.
      static radio_button ok();
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ok(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ok(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ok(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button ok(bool checked);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ok(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ok(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ok(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button ok(const control& parent);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ok(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ok(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ok(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button ok(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button ok(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button ok(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent ok radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button ok(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent open radio_button.
      /// @return The created radio_button.
      static radio_button open();
      /// @brief Create a system-defined radio_button that represent open radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button open(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button open(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button open(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button open(bool checked);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button open(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button open(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button open(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button open(const control& parent);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button open(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button open(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button open(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button open(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button open(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button open(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent open radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button open(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent options radio_button.
      /// @return The created radio_button.
      static radio_button options();
      /// @brief Create a system-defined radio_button that represent options radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button options(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button options(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button options(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button options(bool checked);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button options(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button options(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button options(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button options(const control& parent);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button options(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button options(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button options(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button options(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button options(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button options(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent options radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button options(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent paste radio_button.
      /// @return The created radio_button.
      static radio_button paste();
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button paste(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button paste(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button paste(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button paste(bool checked);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button paste(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button paste(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button paste(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button paste(const control& parent);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button paste(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button paste(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button paste(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button paste(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button paste(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button paste(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent paste radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button paste(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent preferences radio_button.
      /// @return The created radio_button.
      static radio_button preferences();
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button preferences(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button preferences(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button preferences(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button preferences(bool checked);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button preferences(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button preferences(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button preferences(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button preferences(const control& parent);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button preferences(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button preferences(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button preferences(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button preferences(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button preferences(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button preferences(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent preferences radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button preferences(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent previous radio_button.
      /// @return The created radio_button.
      static radio_button previous();
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button previous(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button previous(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button previous(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button previous(bool checked);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button previous(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button previous(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button previous(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button previous(const control& parent);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button previous(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button previous(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button previous(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button previous(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button previous(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button previous(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent previous radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button previous(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent print radio_button.
      /// @return The created radio_button.
      static radio_button print();
      /// @brief Create a system-defined radio_button that represent print radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button print(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button print(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button print(bool checked);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button print(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button print(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button print(const control& parent);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button print(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button print(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button print(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button print(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button print(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent print radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent print_preview radio_button.
      /// @return The created radio_button.
      static radio_button print_preview();
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button print_preview(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button print_preview(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print_preview(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button print_preview(bool checked);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button print_preview(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button print_preview(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print_preview(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button print_preview(const control& parent);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button print_preview(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button print_preview(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print_preview(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button print_preview(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button print_preview(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button print_preview(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent print_preview radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button print_preview(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent properties radio_button.
      /// @return The created radio_button.
      static radio_button properties();
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button properties(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button properties(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button properties(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button properties(bool checked);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button properties(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button properties(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button properties(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button properties(const control& parent);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button properties(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button properties(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button properties(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button properties(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button properties(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button properties(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent properties radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button properties(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent quit radio_button.
      /// @return The created radio_button.
      static radio_button quit();
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button quit(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button quit(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button quit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button quit(bool checked);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button quit(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button quit(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button quit(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button quit(const control& parent);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button quit(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button quit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button quit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button quit(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button quit(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button quit(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent quit radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button quit(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent redo radio_button.
      /// @return The created radio_button.
      static radio_button redo();
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button redo(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button redo(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button redo(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button redo(bool checked);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button redo(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button redo(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button redo(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button redo(const control& parent);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button redo(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button redo(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button redo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button redo(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button redo(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button redo(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent redo radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button redo(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent refresh radio_button.
      /// @return The created radio_button.
      static radio_button refresh();
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button refresh(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button refresh(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button refresh(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button refresh(bool checked);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button refresh(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button refresh(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button refresh(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button refresh(const control& parent);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button refresh(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button refresh(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button refresh(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button refresh(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button refresh(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button refresh(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent refresh radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button refresh(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent remove radio_button.
      /// @return The created radio_button.
      static radio_button remove();
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button remove(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button remove(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button remove(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button remove(bool checked);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button remove(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button remove(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button remove(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button remove(const control& parent);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button remove(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button remove(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button remove(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button remove(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button remove(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button remove(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent remove radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button remove(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent replace radio_button.
      /// @return The created radio_button.
      static radio_button replace();
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button replace(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button replace(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button replace(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button replace(bool checked);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button replace(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button replace(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button replace(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button replace(const control& parent);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button replace(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button replace(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button replace(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button replace(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button replace(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button replace(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent replace radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button replace(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent retry radio_button.
      /// @return The created radio_button.
      static radio_button retry();
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button retry(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button retry(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button retry(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button retry(bool checked);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button retry(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button retry(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button retry(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button retry(const control& parent);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button retry(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button retry(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button retry(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button retry(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button retry(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button retry(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent retry radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button retry(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button.
      /// @return The created radio_button.
      static radio_button revert_to_saved();
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button revert_to_saved(bool checked);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button revert_to_saved(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button revert_to_saved(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button revert_to_saved(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const control& parent);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent revert_to_saved radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button revert_to_saved(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent save radio_button.
      /// @return The created radio_button.
      static radio_button save();
      /// @brief Create a system-defined radio_button that represent save radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button save(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button save(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button save(bool checked);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button save(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button save(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button save(const control& parent);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button save(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button save(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button save(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button save(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button save(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent save radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent save_as radio_button.
      /// @return The created radio_button.
      static radio_button save_as();
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button save_as(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button save_as(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save_as(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button save_as(bool checked);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button save_as(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button save_as(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save_as(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button save_as(const control& parent);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button save_as(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button save_as(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save_as(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button save_as(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button save_as(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button save_as(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent save_as radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button save_as(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent search radio_button.
      /// @return The created radio_button.
      static radio_button search();
      /// @brief Create a system-defined radio_button that represent search radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button search(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button search(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button search(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button search(bool checked);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button search(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button search(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button search(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button search(const control& parent);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button search(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button search(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button search(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button search(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button search(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button search(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent search radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button search(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent select_all radio_button.
      /// @return The created radio_button.
      static radio_button select_all();
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button select_all(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button select_all(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button select_all(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button select_all(bool checked);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button select_all(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button select_all(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button select_all(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button select_all(const control& parent);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button select_all(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button select_all(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button select_all(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button select_all(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button select_all(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button select_all(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent select_all radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button select_all(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent settings radio_button.
      /// @return The created radio_button.
      static radio_button settings();
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button settings(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button settings(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button settings(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button settings(bool checked);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button settings(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button settings(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button settings(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button settings(const control& parent);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button settings(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button settings(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button settings(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button settings(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button settings(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button settings(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent settings radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button settings(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent spell_check radio_button.
      /// @return The created radio_button.
      static radio_button spell_check();
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button spell_check(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button spell_check(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button spell_check(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button spell_check(bool checked);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button spell_check(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button spell_check(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button spell_check(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button spell_check(const control& parent);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button spell_check(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button spell_check(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button spell_check(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button spell_check(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button spell_check(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button spell_check(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent spell_check radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button spell_check(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent stop radio_button.
      /// @return The created radio_button.
      static radio_button stop();
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button stop(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button stop(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button stop(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button stop(bool checked);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button stop(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button stop(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button stop(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button stop(const control& parent);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button stop(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button stop(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button stop(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button stop(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button stop(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button stop(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent stop radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button stop(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent strikeout radio_button.
      /// @return The created radio_button.
      static radio_button strikeout();
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button strikeout(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button strikeout(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button strikeout(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button strikeout(bool checked);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button strikeout(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button strikeout(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button strikeout(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button strikeout(const control& parent);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button strikeout(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button strikeout(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button strikeout(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button strikeout(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button strikeout(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button strikeout(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent strikeout radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button strikeout(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent tools radio_button.
      /// @return The created radio_button.
      static radio_button tools();
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button tools(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button tools(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button tools(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button tools(bool checked);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button tools(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button tools(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button tools(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button tools(const control& parent);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button tools(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button tools(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button tools(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button tools(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button tools(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button tools(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent tools radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button tools(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent top radio_button.
      /// @return The created radio_button.
      static radio_button top();
      /// @brief Create a system-defined radio_button that represent top radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button top(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button top(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button top(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button top(bool checked);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button top(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button top(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button top(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button top(const control& parent);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button top(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button top(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button top(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button top(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button top(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button top(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent top radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button top(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent undelete radio_button.
      /// @return The created radio_button.
      static radio_button undelete();
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button undelete(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button undelete(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undelete(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button undelete(bool checked);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button undelete(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button undelete(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undelete(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button undelete(const control& parent);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button undelete(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button undelete(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undelete(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button undelete(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button undelete(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button undelete(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent undelete radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undelete(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent underline radio_button.
      /// @return The created radio_button.
      static radio_button underline();
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button underline(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button underline(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button underline(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button underline(bool checked);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button underline(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button underline(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button underline(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button underline(const control& parent);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button underline(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button underline(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button underline(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button underline(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button underline(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button underline(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent underline radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button underline(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent undo radio_button.
      /// @return The created radio_button.
      static radio_button undo();
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button undo(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button undo(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undo(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button undo(bool checked);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button undo(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button undo(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undo(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button undo(const control& parent);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button undo(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button undo(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button undo(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button undo(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button undo(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent undo radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button undo(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent unindent radio_button.
      /// @return The created radio_button.
      static radio_button unindent();
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button unindent(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button unindent(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button unindent(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button unindent(bool checked);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button unindent(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button unindent(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button unindent(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button unindent(const control& parent);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button unindent(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button unindent(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button unindent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button unindent(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button unindent(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button unindent(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent unindent radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button unindent(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent up radio_button.
      /// @return The created radio_button.
      static radio_button up();
      /// @brief Create a system-defined radio_button that represent up radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button up(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button up(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button up(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button up(bool checked);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button up(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button up(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button up(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button up(const control& parent);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button up(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button up(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button up(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button up(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button up(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button up(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent up radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button up(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent view radio_button.
      /// @return The created radio_button.
      static radio_button view();
      /// @brief Create a system-defined radio_button that represent view radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button view(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button view(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button view(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button view(bool checked);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button view(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button view(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button view(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button view(const control& parent);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button view(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button view(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button view(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button view(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button view(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button view(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent view radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button view(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent window radio_button.
      /// @return The created radio_button.
      static radio_button window();
      /// @brief Create a system-defined radio_button that represent window radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button window(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button window(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button window(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button window(bool checked);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button window(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button window(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button window(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button window(const control& parent);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button window(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button window(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button window(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button window(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button window(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button window(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent window radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button window(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent yes radio_button.
      /// @return The created radio_button.
      static radio_button yes();
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button yes(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button yes(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button yes(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button yes(bool checked);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button yes(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button yes(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button yes(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button yes(const control& parent);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button yes(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button yes(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button yes(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button yes(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button yes(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button yes(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent yes radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button yes(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent zoom_in radio_button.
      /// @return The created radio_button.
      static radio_button zoom_in();
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_in(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_in(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_in(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button zoom_in(bool checked);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_in(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_in(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_in(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_in(const control& parent);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_in(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_in(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_in(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button zoom_in(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_in(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_in(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_in radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_in(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent zoom_out radio_button.
      /// @return The created radio_button.
      static radio_button zoom_out();
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_out(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_out(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_out(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button zoom_out(bool checked);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_out(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_out(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_out(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_out(const control& parent);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_out(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_out(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_out(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button zoom_out(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_out(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_out(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_out radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_out(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);

      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button.
      /// @return The created radio_button.
      static radio_button zoom_to_fit();
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified location.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified location, and size.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified location, size, and name.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified and check_state.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(bool checked);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified check_state, and location.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified check_state, location, and size.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified check_state, location, size, and name.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent.
      /// @param parent The control that contains the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const control& parent);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, and location.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const control& parent, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent,  location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, and check_state.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const control& parent, bool checked);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, check_state, and location.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const control& parent, bool checked, const drawing::point& location);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, check_state, location, and size.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const control& parent, bool checked, const drawing::point& location, const drawing::size& size);
      /// @brief Create a system-defined radio_button that represent zoom_to_fit radio_button with specified parent, check_state, location, size, and name.
      /// @param parent The control that contains the radio_button.
      /// @param check_state One of the xtd::forms::check_state enumeration values.
      /// @param location The radio_button location in pixels.
      /// @param size The radio_button size in pixels.
      /// @param name The name of the radio_button.
      /// @return The created radio_button.
      static radio_button zoom_to_fit(const control& parent, bool checked, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
    };
  }
}
