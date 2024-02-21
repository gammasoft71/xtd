/// @file
/// @brief Contains xtd::forms::command_link_buttons factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "command_link_button.h"
#include "system_texts.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of command_link_button objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/command_link_buttons> @endcode
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
      /// @name Methods
      
      /// @{
      /// Create a system-defined command_link_button that represent abort command_link_button
      /// @return The created command_link_button.
      static command_link_button abort();
      /// Create a system-defined command_link_button that represent abort command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button abort(const drawing::point& location);
      /// Create a system-defined command_link_button that represent abort command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button abort(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent abort command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button abort(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent abort command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button abort(const control& parent);
      /// Create a system-defined command_link_button that represent abort command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button abort(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent abort command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button abort(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent abort command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button abort(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent about command_link_button
      /// @return The created command_link_button.
      static command_link_button about();
      /// Create a system-defined command_link_button that represent about command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button about(const drawing::point& location);
      /// Create a system-defined command_link_button that represent about command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button about(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent about command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button about(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent about command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button about(const control& parent);
      /// Create a system-defined command_link_button that represent about command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button about(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent about command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button about(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent about command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button about(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent actual_size command_link_button
      /// @return The created command_link_button.
      static command_link_button actual_size();
      /// Create a system-defined command_link_button that represent actual_size command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button actual_size(const drawing::point& location);
      /// Create a system-defined command_link_button that represent actual_size command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button actual_size(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent actual_size command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button actual_size(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent actual_size command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button actual_size(const control& parent);
      /// Create a system-defined command_link_button that represent actual_size command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button actual_size(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent actual_size command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button actual_size(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent actual_size command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button actual_size(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent add command_link_button
      /// @return The created command_link_button.
      static command_link_button add();
      /// Create a system-defined command_link_button that represent add command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button add(const drawing::point& location);
      /// Create a system-defined command_link_button that represent add command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button add(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent add command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button add(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent add command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button add(const control& parent);
      /// Create a system-defined command_link_button that represent add command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button add(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent add command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button add(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent add command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button add(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent alignment command_link_button
      /// @return The created command_link_button.
      static command_link_button alignment();
      /// Create a system-defined command_link_button that represent alignment command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button alignment(const drawing::point& location);
      /// Create a system-defined command_link_button that represent alignment command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button alignment(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent alignment command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button alignment(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent alignment command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button alignment(const control& parent);
      /// Create a system-defined command_link_button that represent alignment command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button alignment(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent alignment command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button alignment(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent alignment command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button alignment(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent align_left command_link_button
      /// @return The created command_link_button.
      static command_link_button align_left();
      /// Create a system-defined command_link_button that represent align_left command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button align_left(const drawing::point& location);
      /// Create a system-defined command_link_button that represent align_left command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button align_left(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent align_left command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button align_left(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent align_left command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button align_left(const control& parent);
      /// Create a system-defined command_link_button that represent align_left command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button align_left(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent align_left command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button align_left(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent align_left command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button align_left(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent align_right command_link_button
      /// @return The created command_link_button.
      static command_link_button align_right();
      /// Create a system-defined command_link_button that represent align_right command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button align_right(const drawing::point& location);
      /// Create a system-defined command_link_button that represent align_right command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button align_right(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent align_right command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button align_right(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent align_right command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button align_right(const control& parent);
      /// Create a system-defined command_link_button that represent align_right command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button align_right(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent align_right command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button align_right(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent align_right command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button align_right(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent apply command_link_button
      /// @return The created command_link_button.
      static command_link_button apply();
      /// Create a system-defined command_link_button that represent apply command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button apply(const drawing::point& location);
      /// Create a system-defined command_link_button that represent apply command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button apply(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent apply command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button apply(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent apply command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button apply(const control& parent);
      /// Create a system-defined command_link_button that represent apply command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button apply(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent apply command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button apply(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent apply command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button apply(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent ascending command_link_button
      /// @return The created command_link_button.
      static command_link_button ascending();
      /// Create a system-defined command_link_button that represent ascending command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button ascending(const drawing::point& location);
      /// Create a system-defined command_link_button that represent ascending command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button ascending(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent ascending command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button ascending(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent ascending command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button ascending(const control& parent);
      /// Create a system-defined command_link_button that represent ascending command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button ascending(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent ascending command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button ascending(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent ascending command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button ascending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent back command_link_button
      /// @return The created command_link_button.
      static command_link_button back();
      /// Create a system-defined command_link_button that represent back command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button back(const drawing::point& location);
      /// Create a system-defined command_link_button that represent back command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button back(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent back command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button back(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent back command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button back(const control& parent);
      /// Create a system-defined command_link_button that represent back command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button back(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent back command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button back(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent back command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button back(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent bold command_link_button
      /// @return The created command_link_button.
      static command_link_button bold();
      /// Create a system-defined command_link_button that represent bold command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button bold(const drawing::point& location);
      /// Create a system-defined command_link_button that represent bold command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button bold(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent bold command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button bold(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent bold command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button bold(const control& parent);
      /// Create a system-defined command_link_button that represent bold command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button bold(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent bold command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button bold(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent bold command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button bold(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent bottom command_link_button
      /// @return The created command_link_button.
      static command_link_button bottom();
      /// Create a system-defined command_link_button that represent bottom command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button bottom(const drawing::point& location);
      /// Create a system-defined command_link_button that represent bottom command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button bottom(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent bottom command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button bottom(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent bottom command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button bottom(const control& parent);
      /// Create a system-defined command_link_button that represent bottom command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button bottom(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent bottom command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button bottom(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent bottom command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button bottom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent cancel command_link_button
      /// @return The created command_link_button.
      static command_link_button cancel();
      /// Create a system-defined command_link_button that represent cancel command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button cancel(const drawing::point& location);
      /// Create a system-defined command_link_button that represent cancel command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button cancel(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent cancel command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button cancel(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent cancel command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button cancel(const control& parent);
      /// Create a system-defined command_link_button that represent cancel command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button cancel(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent cancel command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button cancel(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent cancel command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button cancel(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent cdrom command_link_button
      /// @return The created command_link_button.
      static command_link_button cdrom();
      /// Create a system-defined command_link_button that represent cdrom command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button cdrom(const drawing::point& location);
      /// Create a system-defined command_link_button that represent cdrom command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button cdrom(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent cdrom command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button cdrom(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent cdrom command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button cdrom(const control& parent);
      /// Create a system-defined command_link_button that represent cdrom command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button cdrom(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent cdrom command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button cdrom(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent cdrom command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button cdrom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent centered command_link_button
      /// @return The created command_link_button.
      static command_link_button centered();
      /// Create a system-defined command_link_button that represent centered command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button centered(const drawing::point& location);
      /// Create a system-defined command_link_button that represent centered command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button centered(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent centered command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button centered(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent centered command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button centered(const control& parent);
      /// Create a system-defined command_link_button that represent centered command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button centered(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent centered command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button centered(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent centered command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button centered(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent clear command_link_button
      /// @return The created command_link_button.
      static command_link_button clear();
      /// Create a system-defined command_link_button that represent clear command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button clear(const drawing::point& location);
      /// Create a system-defined command_link_button that represent clear command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button clear(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent clear command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button clear(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent clear command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button clear(const control& parent);
      /// Create a system-defined command_link_button that represent clear command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button clear(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent clear command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button clear(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent clear command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button clear(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent close command_link_button
      /// @return The created command_link_button.
      static command_link_button close();
      /// Create a system-defined command_link_button that represent close command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button close(const drawing::point& location);
      /// Create a system-defined command_link_button that represent close command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button close(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent close command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button close(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent close command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button close(const control& parent);
      /// Create a system-defined command_link_button that represent close command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button close(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent close command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button close(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent close command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button close(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent color command_link_button
      /// @return The created command_link_button.
      static command_link_button color();
      /// Create a system-defined command_link_button that represent color command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button color(const drawing::point& location);
      /// Create a system-defined command_link_button that represent color command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button color(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent color command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button color(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent color command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button color(const control& parent);
      /// Create a system-defined command_link_button that represent color command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button color(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent color command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button color(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent color command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button color(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent contents command_link_button
      /// @return The created command_link_button.
      static command_link_button contents();
      /// Create a system-defined command_link_button that represent contents command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button contents(const drawing::point& location);
      /// Create a system-defined command_link_button that represent contents command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button contents(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent contents command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button contents(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent contents command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button contents(const control& parent);
      /// Create a system-defined command_link_button that represent contents command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button contents(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent contents command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button contents(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent contents command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button contents(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent convert command_link_button
      /// @return The created command_link_button.
      static command_link_button convert();
      /// Create a system-defined command_link_button that represent convert command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button convert(const drawing::point& location);
      /// Create a system-defined command_link_button that represent convert command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button convert(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent convert command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button convert(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent convert command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button convert(const control& parent);
      /// Create a system-defined command_link_button that represent convert command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button convert(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent convert command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button convert(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent convert command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button convert(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent copy command_link_button
      /// @return The created command_link_button.
      static command_link_button copy();
      /// Create a system-defined command_link_button that represent copy command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button copy(const drawing::point& location);
      /// Create a system-defined command_link_button that represent copy command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button copy(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent copy command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button copy(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent copy command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button copy(const control& parent);
      /// Create a system-defined command_link_button that represent copy command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button copy(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent copy command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button copy(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent copy command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button copy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent customize command_link_button
      /// @return The created command_link_button.
      static command_link_button customize();
      /// Create a system-defined command_link_button that represent customize command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button customize(const drawing::point& location);
      /// Create a system-defined command_link_button that represent customize command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button customize(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent customize command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button customize(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent customize command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button customize(const control& parent);
      /// Create a system-defined command_link_button that represent customize command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button customize(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent customize command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button customize(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent customize command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button customize(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent cut command_link_button
      /// @return The created command_link_button.
      static command_link_button cut();
      /// Create a system-defined command_link_button that represent cut command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button cut(const drawing::point& location);
      /// Create a system-defined command_link_button that represent cut command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button cut(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent cut command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button cut(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent cut command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button cut(const control& parent);
      /// Create a system-defined command_link_button that represent cut command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button cut(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent cut command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button cut(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent cut command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button cut(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent del command_link_button
      /// @return The created command_link_button.
      static command_link_button del();
      /// Create a system-defined command_link_button that represent del command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button del(const drawing::point& location);
      /// Create a system-defined command_link_button that represent del command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button del(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent del command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button del(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent del command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button del(const control& parent);
      /// Create a system-defined command_link_button that represent del command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button del(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent del command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button del(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent del command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button del(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent descending command_link_button
      /// @return The created command_link_button.
      static command_link_button descending();
      /// Create a system-defined command_link_button that represent descending command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button descending(const drawing::point& location);
      /// Create a system-defined command_link_button that represent descending command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button descending(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent descending command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button descending(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent descending command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button descending(const control& parent);
      /// Create a system-defined command_link_button that represent descending command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button descending(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent descending command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button descending(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent descending command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button descending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent down command_link_button
      /// @return The created command_link_button.
      static command_link_button down();
      /// Create a system-defined command_link_button that represent down command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button down(const drawing::point& location);
      /// Create a system-defined command_link_button that represent down command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button down(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent down command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button down(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent down command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button down(const control& parent);
      /// Create a system-defined command_link_button that represent down command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button down(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent down command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button down(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent down command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button down(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent edit command_link_button
      /// @return The created command_link_button.
      static command_link_button edit();
      /// Create a system-defined command_link_button that represent edit command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button edit(const drawing::point& location);
      /// Create a system-defined command_link_button that represent edit command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button edit(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent edit command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button edit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent edit command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button edit(const control& parent);
      /// Create a system-defined command_link_button that represent edit command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button edit(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent edit command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button edit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent edit command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button edit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent execute command_link_button
      /// @return The created command_link_button.
      static command_link_button execute();
      /// Create a system-defined command_link_button that represent execute command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button execute(const drawing::point& location);
      /// Create a system-defined command_link_button that represent execute command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button execute(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent execute command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button execute(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent execute command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button execute(const control& parent);
      /// Create a system-defined command_link_button that represent execute command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button execute(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent execute command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button execute(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent execute command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button execute(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent exit command_link_button
      /// @return The created command_link_button.
      static command_link_button exit();
      /// Create a system-defined command_link_button that represent exit command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button exit(const drawing::point& location);
      /// Create a system-defined command_link_button that represent exit command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button exit(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent exit command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button exit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent exit command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button exit(const control& parent);
      /// Create a system-defined command_link_button that represent exit command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button exit(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent exit command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button exit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent exit command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button exit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent file command_link_button
      /// @return The created command_link_button.
      static command_link_button file();
      /// Create a system-defined command_link_button that represent file command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button file(const drawing::point& location);
      /// Create a system-defined command_link_button that represent file command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button file(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent file command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button file(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent file command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button file(const control& parent);
      /// Create a system-defined command_link_button that represent file command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button file(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent file command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button file(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent file command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button file(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent find command_link_button
      /// @return The created command_link_button.
      static command_link_button find();
      /// Create a system-defined command_link_button that represent find command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button find(const drawing::point& location);
      /// Create a system-defined command_link_button that represent find command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button find(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent find command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button find(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent find command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button find(const control& parent);
      /// Create a system-defined command_link_button that represent find command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button find(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent find command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button find(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent find command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button find(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent first command_link_button
      /// @return The created command_link_button.
      static command_link_button first();
      /// Create a system-defined command_link_button that represent first command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button first(const drawing::point& location);
      /// Create a system-defined command_link_button that represent first command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button first(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent first command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button first(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent first command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button first(const control& parent);
      /// Create a system-defined command_link_button that represent first command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button first(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent first command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button first(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent first command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button first(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent floppy command_link_button
      /// @return The created command_link_button.
      static command_link_button floppy();
      /// Create a system-defined command_link_button that represent floppy command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button floppy(const drawing::point& location);
      /// Create a system-defined command_link_button that represent floppy command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button floppy(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent floppy command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button floppy(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent floppy command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button floppy(const control& parent);
      /// Create a system-defined command_link_button that represent floppy command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button floppy(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent floppy command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button floppy(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent floppy command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button floppy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent font command_link_button
      /// @return The created command_link_button.
      static command_link_button font();
      /// Create a system-defined command_link_button that represent font command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button font(const drawing::point& location);
      /// Create a system-defined command_link_button that represent font command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button font(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent font command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button font(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent font command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button font(const control& parent);
      /// Create a system-defined command_link_button that represent font command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button font(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent font command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button font(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent font command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button font(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent forward command_link_button
      /// @return The created command_link_button.
      static command_link_button forward();
      /// Create a system-defined command_link_button that represent forward command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button forward(const drawing::point& location);
      /// Create a system-defined command_link_button that represent forward command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button forward(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent forward command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button forward(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent forward command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button forward(const control& parent);
      /// Create a system-defined command_link_button that represent forward command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button forward(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent forward command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button forward(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent forward command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button forward(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent harddisk command_link_button
      /// @return The created command_link_button.
      static command_link_button harddisk();
      /// Create a system-defined command_link_button that represent harddisk command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button harddisk(const drawing::point& location);
      /// Create a system-defined command_link_button that represent harddisk command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button harddisk(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent harddisk command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button harddisk(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent harddisk command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button harddisk(const control& parent);
      /// Create a system-defined command_link_button that represent harddisk command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button harddisk(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent harddisk command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button harddisk(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent harddisk command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button harddisk(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent help command_link_button
      /// @return The created command_link_button.
      static command_link_button help();
      /// Create a system-defined command_link_button that represent help command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button help(const drawing::point& location);
      /// Create a system-defined command_link_button that represent help command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button help(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent help command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button help(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent help command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button help(const control& parent);
      /// Create a system-defined command_link_button that represent help command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button help(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent help command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button help(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent help command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button help(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent home command_link_button
      /// @return The created command_link_button.
      static command_link_button home();
      /// Create a system-defined command_link_button that represent home command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button home(const drawing::point& location);
      /// Create a system-defined command_link_button that represent home command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button home(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent home command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button home(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent home command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button home(const control& parent);
      /// Create a system-defined command_link_button that represent home command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button home(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent home command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button home(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent home command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button home(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent ignore command_link_button
      /// @return The created command_link_button.
      static command_link_button ignore();
      /// Create a system-defined command_link_button that represent ignore command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button ignore(const drawing::point& location);
      /// Create a system-defined command_link_button that represent ignore command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button ignore(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent ignore command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button ignore(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent ignore command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button ignore(const control& parent);
      /// Create a system-defined command_link_button that represent ignore command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button ignore(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent ignore command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button ignore(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent ignore command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button ignore(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent indent command_link_button
      /// @return The created command_link_button.
      static command_link_button indent();
      /// Create a system-defined command_link_button that represent indent command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button indent(const drawing::point& location);
      /// Create a system-defined command_link_button that represent indent command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button indent(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent indent command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button indent(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent indent command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button indent(const control& parent);
      /// Create a system-defined command_link_button that represent indent command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button indent(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent indent command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button indent(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent indent command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button indent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent index command_link_button
      /// @return The created command_link_button.
      static command_link_button index();
      /// Create a system-defined command_link_button that represent index command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button index(const drawing::point& location);
      /// Create a system-defined command_link_button that represent index command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button index(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent index command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button index(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent index command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button index(const control& parent);
      /// Create a system-defined command_link_button that represent index command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button index(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent index command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button index(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent index command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button index(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent info command_link_button
      /// @return The created command_link_button.
      static command_link_button info();
      /// Create a system-defined command_link_button that represent info command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button info(const drawing::point& location);
      /// Create a system-defined command_link_button that represent info command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button info(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent info command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button info(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent info command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button info(const control& parent);
      /// Create a system-defined command_link_button that represent info command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button info(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent info command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button info(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent info command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button info(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent italic command_link_button
      /// @return The created command_link_button.
      static command_link_button italic();
      /// Create a system-defined command_link_button that represent italic command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button italic(const drawing::point& location);
      /// Create a system-defined command_link_button that represent italic command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button italic(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent italic command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button italic(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent italic command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button italic(const control& parent);
      /// Create a system-defined command_link_button that represent italic command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button italic(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent italic command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button italic(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent italic command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button italic(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent justified command_link_button
      /// @return The created command_link_button.
      static command_link_button justified();
      /// Create a system-defined command_link_button that represent justified command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button justified(const drawing::point& location);
      /// Create a system-defined command_link_button that represent justified command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button justified(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent justified command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button justified(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent justified command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button justified(const control& parent);
      /// Create a system-defined command_link_button that represent justified command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button justified(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent justified command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button justified(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent justified command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button justified(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent jump_to command_link_button
      /// @return The created command_link_button.
      static command_link_button jump_to();
      /// Create a system-defined command_link_button that represent jump_to command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button jump_to(const drawing::point& location);
      /// Create a system-defined command_link_button that represent jump_to command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button jump_to(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent jump_to command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button jump_to(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent jump_to command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button jump_to(const control& parent);
      /// Create a system-defined command_link_button that represent jump_to command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button jump_to(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent jump_to command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button jump_to(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent jump_to command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button jump_to(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent last command_link_button
      /// @return The created command_link_button.
      static command_link_button last();
      /// Create a system-defined command_link_button that represent last command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button last(const drawing::point& location);
      /// Create a system-defined command_link_button that represent last command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button last(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent last command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button last(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent last command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button last(const control& parent);
      /// Create a system-defined command_link_button that represent last command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button last(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent last command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button last(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent last command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button last(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent network command_link_button
      /// @return The created command_link_button.
      static command_link_button network();
      /// Create a system-defined command_link_button that represent network command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button network(const drawing::point& location);
      /// Create a system-defined command_link_button that represent network command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button network(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent network command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button network(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent network command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button network(const control& parent);
      /// Create a system-defined command_link_button that represent network command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button network(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent network command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button network(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent network command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button network(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent new_ command_link_button
      /// @return The created command_link_button.
      static command_link_button new_();
      /// Create a system-defined command_link_button that represent new_ command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button new_(const drawing::point& location);
      /// Create a system-defined command_link_button that represent new_ command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button new_(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent new_ command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button new_(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent new_ command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button new_(const control& parent);
      /// Create a system-defined command_link_button that represent new_ command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button new_(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent new_ command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button new_(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent new_ command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button new_(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent next command_link_button
      /// @return The created command_link_button.
      static command_link_button next();
      /// Create a system-defined command_link_button that represent next command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button next(const drawing::point& location);
      /// Create a system-defined command_link_button that represent next command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button next(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent next command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button next(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent next command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button next(const control& parent);
      /// Create a system-defined command_link_button that represent next command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button next(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent next command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button next(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent next command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button next(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent no command_link_button
      /// @return The created command_link_button.
      static command_link_button no();
      /// Create a system-defined command_link_button that represent no command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button no(const drawing::point& location);
      /// Create a system-defined command_link_button that represent no command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button no(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent no command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button no(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent no command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button no(const control& parent);
      /// Create a system-defined command_link_button that represent no command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button no(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent no command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button no(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent no command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button no(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent ok command_link_button
      /// @return The created command_link_button.
      static command_link_button ok();
      /// Create a system-defined command_link_button that represent ok command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button ok(const drawing::point& location);
      /// Create a system-defined command_link_button that represent ok command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button ok(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent ok command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button ok(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent ok command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button ok(const control& parent);
      /// Create a system-defined command_link_button that represent ok command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button ok(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent ok command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button ok(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent ok command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button ok(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent open command_link_button
      /// @return The created command_link_button.
      static command_link_button open();
      /// Create a system-defined command_link_button that represent open command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button open(const drawing::point& location);
      /// Create a system-defined command_link_button that represent open command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button open(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent open command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button open(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent open command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button open(const control& parent);
      /// Create a system-defined command_link_button that represent open command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button open(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent open command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button open(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent open command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button open(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent options command_link_button
      /// @return The created command_link_button.
      static command_link_button options();
      /// Create a system-defined command_link_button that represent options command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button options(const drawing::point& location);
      /// Create a system-defined command_link_button that represent options command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button options(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent options command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button options(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent options command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button options(const control& parent);
      /// Create a system-defined command_link_button that represent options command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button options(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent options command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button options(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent options command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button options(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent paste command_link_button
      /// @return The created command_link_button.
      static command_link_button paste();
      /// Create a system-defined command_link_button that represent paste command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button paste(const drawing::point& location);
      /// Create a system-defined command_link_button that represent paste command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button paste(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent paste command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button paste(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent paste command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button paste(const control& parent);
      /// Create a system-defined command_link_button that represent paste command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button paste(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent paste command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button paste(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent paste command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button paste(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent preferences command_link_button
      /// @return The created command_link_button.
      static command_link_button preferences();
      /// Create a system-defined command_link_button that represent preferences command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button preferences(const drawing::point& location);
      /// Create a system-defined command_link_button that represent preferences command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button preferences(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent preferences command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button preferences(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent preferences command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button preferences(const control& parent);
      /// Create a system-defined command_link_button that represent preferences command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button preferences(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent preferences command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button preferences(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent preferences command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button preferences(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent previous command_link_button
      /// @return The created command_link_button.
      static command_link_button previous();
      /// Create a system-defined command_link_button that represent previous command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button previous(const drawing::point& location);
      /// Create a system-defined command_link_button that represent previous command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button previous(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent previous command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button previous(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent previous command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button previous(const control& parent);
      /// Create a system-defined command_link_button that represent previous command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button previous(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent previous command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button previous(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent previous command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button previous(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent print command_link_button
      /// @return The created command_link_button.
      static command_link_button print();
      /// Create a system-defined command_link_button that represent print command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button print(const drawing::point& location);
      /// Create a system-defined command_link_button that represent print command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button print(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent print command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button print(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent print command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button print(const control& parent);
      /// Create a system-defined command_link_button that represent print command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button print(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent print command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button print(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent print command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button print(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent print_preview command_link_button
      /// @return The created command_link_button.
      static command_link_button print_preview();
      /// Create a system-defined command_link_button that represent print_preview command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button print_preview(const drawing::point& location);
      /// Create a system-defined command_link_button that represent print_preview command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button print_preview(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent print_preview command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button print_preview(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent print_preview command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button print_preview(const control& parent);
      /// Create a system-defined command_link_button that represent print_preview command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button print_preview(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent print_preview command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button print_preview(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent print_preview command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button print_preview(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent properties command_link_button
      /// @return The created command_link_button.
      static command_link_button properties();
      /// Create a system-defined command_link_button that represent properties command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button properties(const drawing::point& location);
      /// Create a system-defined command_link_button that represent properties command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button properties(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent properties command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button properties(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent properties command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button properties(const control& parent);
      /// Create a system-defined command_link_button that represent properties command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button properties(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent properties command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button properties(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent properties command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button properties(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent quit command_link_button
      /// @return The created command_link_button.
      static command_link_button quit();
      /// Create a system-defined command_link_button that represent quit command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button quit(const drawing::point& location);
      /// Create a system-defined command_link_button that represent quit command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button quit(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent quit command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button quit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent quit command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button quit(const control& parent);
      /// Create a system-defined command_link_button that represent quit command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button quit(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent quit command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button quit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent quit command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button quit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent redo command_link_button
      /// @return The created command_link_button.
      static command_link_button redo();
      /// Create a system-defined command_link_button that represent redo command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button redo(const drawing::point& location);
      /// Create a system-defined command_link_button that represent redo command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button redo(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent redo command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button redo(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent redo command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button redo(const control& parent);
      /// Create a system-defined command_link_button that represent redo command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button redo(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent redo command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button redo(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent redo command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button redo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent refresh command_link_button
      /// @return The created command_link_button.
      static command_link_button refresh();
      /// Create a system-defined command_link_button that represent refresh command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button refresh(const drawing::point& location);
      /// Create a system-defined command_link_button that represent refresh command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button refresh(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent refresh command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button refresh(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent refresh command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button refresh(const control& parent);
      /// Create a system-defined command_link_button that represent refresh command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button refresh(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent refresh command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button refresh(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent refresh command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button refresh(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent remove command_link_button
      /// @return The created command_link_button.
      static command_link_button remove();
      /// Create a system-defined command_link_button that represent remove command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button remove(const drawing::point& location);
      /// Create a system-defined command_link_button that represent remove command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button remove(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent remove command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button remove(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent remove command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button remove(const control& parent);
      /// Create a system-defined command_link_button that represent remove command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button remove(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent remove command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button remove(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent remove command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button remove(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent replace command_link_button
      /// @return The created command_link_button.
      static command_link_button replace();
      /// Create a system-defined command_link_button that represent replace command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button replace(const drawing::point& location);
      /// Create a system-defined command_link_button that represent replace command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button replace(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent replace command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button replace(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent replace command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button replace(const control& parent);
      /// Create a system-defined command_link_button that represent replace command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button replace(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent replace command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button replace(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent replace command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button replace(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent retry command_link_button
      /// @return The created command_link_button.
      static command_link_button retry();
      /// Create a system-defined command_link_button that represent retry command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button retry(const drawing::point& location);
      /// Create a system-defined command_link_button that represent retry command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button retry(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent retry command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button retry(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent retry command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button retry(const control& parent);
      /// Create a system-defined command_link_button that represent retry command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button retry(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent retry command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button retry(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent retry command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button retry(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent revert_to_saved command_link_button
      /// @return The created command_link_button.
      static command_link_button revert_to_saved();
      /// Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button revert_to_saved(const drawing::point& location);
      /// Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button revert_to_saved(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button revert_to_saved(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button revert_to_saved(const control& parent);
      /// Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button revert_to_saved(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent revert_to_saved command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent save command_link_button
      /// @return The created command_link_button.
      static command_link_button save();
      /// Create a system-defined command_link_button that represent save command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button save(const drawing::point& location);
      /// Create a system-defined command_link_button that represent save command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button save(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent save command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button save(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent save command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button save(const control& parent);
      /// Create a system-defined command_link_button that represent save command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button save(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent save command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button save(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent save command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button save(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent save_as command_link_button
      /// @return The created command_link_button.
      static command_link_button save_as();
      /// Create a system-defined command_link_button that represent save_as command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button save_as(const drawing::point& location);
      /// Create a system-defined command_link_button that represent save_as command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button save_as(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent save_as command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button save_as(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent save_as command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button save_as(const control& parent);
      /// Create a system-defined command_link_button that represent save_as command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button save_as(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent save_as command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button save_as(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent save_as command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button save_as(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent search command_link_button
      /// @return The created command_link_button.
      static command_link_button search();
      /// Create a system-defined command_link_button that represent search command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button search(const drawing::point& location);
      /// Create a system-defined command_link_button that represent search command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button search(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent search command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button search(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent search command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button search(const control& parent);
      /// Create a system-defined command_link_button that represent search command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button search(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent search command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button search(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent search command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button search(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent select_all command_link_button
      /// @return The created command_link_button.
      static command_link_button select_all();
      /// Create a system-defined command_link_button that represent select_all command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button select_all(const drawing::point& location);
      /// Create a system-defined command_link_button that represent select_all command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button select_all(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent select_all command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button select_all(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent select_all command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button select_all(const control& parent);
      /// Create a system-defined command_link_button that represent select_all command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button select_all(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent select_all command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button select_all(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent select_all command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button select_all(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent settings command_link_button
      /// @return The created command_link_button.
      static command_link_button settings();
      /// Create a system-defined command_link_button that represent settings command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button settings(const drawing::point& location);
      /// Create a system-defined command_link_button that represent settings command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button settings(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent settings command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button settings(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent settings command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button settings(const control& parent);
      /// Create a system-defined command_link_button that represent settings command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button settings(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent settings command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button settings(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent settings command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button settings(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent spell_check command_link_button
      /// @return The created command_link_button.
      static command_link_button spell_check();
      /// Create a system-defined command_link_button that represent spell_check command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button spell_check(const drawing::point& location);
      /// Create a system-defined command_link_button that represent spell_check command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button spell_check(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent spell_check command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button spell_check(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent spell_check command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button spell_check(const control& parent);
      /// Create a system-defined command_link_button that represent spell_check command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button spell_check(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent spell_check command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button spell_check(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent spell_check command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button spell_check(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent stop command_link_button
      /// @return The created command_link_button.
      static command_link_button stop();
      /// Create a system-defined command_link_button that represent stop command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button stop(const drawing::point& location);
      /// Create a system-defined command_link_button that represent stop command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button stop(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent stop command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button stop(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent stop command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button stop(const control& parent);
      /// Create a system-defined command_link_button that represent stop command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button stop(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent stop command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button stop(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent stop command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button stop(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent strikeout command_link_button
      /// @return The created command_link_button.
      static command_link_button strikeout();
      /// Create a system-defined command_link_button that represent strikeout command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button strikeout(const drawing::point& location);
      /// Create a system-defined command_link_button that represent strikeout command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button strikeout(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent strikeout command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button strikeout(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent strikeout command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button strikeout(const control& parent);
      /// Create a system-defined command_link_button that represent strikeout command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button strikeout(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent strikeout command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button strikeout(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent strikeout command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button strikeout(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent tools command_link_button
      /// @return The created command_link_button.
      static command_link_button tools();
      /// Create a system-defined command_link_button that represent tools command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button tools(const drawing::point& location);
      /// Create a system-defined command_link_button that represent tools command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button tools(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent tools command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button tools(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent tools command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button tools(const control& parent);
      /// Create a system-defined command_link_button that represent tools command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button tools(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent tools command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button tools(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent tools command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button tools(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent top command_link_button
      /// @return The created command_link_button.
      static command_link_button top();
      /// Create a system-defined command_link_button that represent top command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button top(const drawing::point& location);
      /// Create a system-defined command_link_button that represent top command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button top(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent top command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button top(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent top command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button top(const control& parent);
      /// Create a system-defined command_link_button that represent top command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button top(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent top command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button top(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent top command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button top(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent undelete command_link_button
      /// @return The created command_link_button.
      static command_link_button undelete();
      /// Create a system-defined command_link_button that represent undelete command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button undelete(const drawing::point& location);
      /// Create a system-defined command_link_button that represent undelete command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button undelete(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent undelete command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button undelete(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent undelete command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button undelete(const control& parent);
      /// Create a system-defined command_link_button that represent undelete command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button undelete(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent undelete command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button undelete(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent undelete command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button undelete(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent underline command_link_button
      /// @return The created command_link_button.
      static command_link_button underline();
      /// Create a system-defined command_link_button that represent underline command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button underline(const drawing::point& location);
      /// Create a system-defined command_link_button that represent underline command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button underline(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent underline command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button underline(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent underline command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button underline(const control& parent);
      /// Create a system-defined command_link_button that represent underline command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button underline(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent underline command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button underline(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent underline command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button underline(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent undo command_link_button
      /// @return The created command_link_button.
      static command_link_button undo();
      /// Create a system-defined command_link_button that represent undo command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button undo(const drawing::point& location);
      /// Create a system-defined command_link_button that represent undo command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button undo(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent undo command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button undo(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent undo command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button undo(const control& parent);
      /// Create a system-defined command_link_button that represent undo command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button undo(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent undo command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button undo(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent undo command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button undo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent unindent command_link_button
      /// @return The created command_link_button.
      static command_link_button unindent();
      /// Create a system-defined command_link_button that represent unindent command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button unindent(const drawing::point& location);
      /// Create a system-defined command_link_button that represent unindent command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button unindent(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent unindent command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button unindent(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent unindent command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button unindent(const control& parent);
      /// Create a system-defined command_link_button that represent unindent command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button unindent(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent unindent command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button unindent(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent unindent command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button unindent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent up command_link_button
      /// @return The created command_link_button.
      static command_link_button up();
      /// Create a system-defined command_link_button that represent up command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button up(const drawing::point& location);
      /// Create a system-defined command_link_button that represent up command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button up(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent up command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button up(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent up command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button up(const control& parent);
      /// Create a system-defined command_link_button that represent up command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button up(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent up command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button up(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent up command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button up(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent view command_link_button
      /// @return The created command_link_button.
      static command_link_button view();
      /// Create a system-defined command_link_button that represent view command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button view(const drawing::point& location);
      /// Create a system-defined command_link_button that represent view command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button view(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent view command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button view(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent view command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button view(const control& parent);
      /// Create a system-defined command_link_button that represent view command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button view(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent view command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button view(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent view command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button view(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent window command_link_button
      /// @return The created command_link_button.
      static command_link_button window();
      /// Create a system-defined command_link_button that represent window command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button window(const drawing::point& location);
      /// Create a system-defined command_link_button that represent window command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button window(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent window command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button window(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent window command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button window(const control& parent);
      /// Create a system-defined command_link_button that represent window command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button window(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent window command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button window(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent window command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button window(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent yes command_link_button
      /// @return The created command_link_button.
      static command_link_button yes();
      /// Create a system-defined command_link_button that represent yes command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button yes(const drawing::point& location);
      /// Create a system-defined command_link_button that represent yes command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button yes(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent yes command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button yes(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent yes command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button yes(const control& parent);
      /// Create a system-defined command_link_button that represent yes command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button yes(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent yes command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button yes(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent yes command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button yes(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent zoom_in command_link_button
      /// @return The created command_link_button.
      static command_link_button zoom_in();
      /// Create a system-defined command_link_button that represent zoom_in command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_in(const drawing::point& location);
      /// Create a system-defined command_link_button that represent zoom_in command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_in(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent zoom_in command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button zoom_in(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent zoom_in command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button zoom_in(const control& parent);
      /// Create a system-defined command_link_button that represent zoom_in command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_in(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent zoom_in command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_in(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent zoom_in command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button zoom_in(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent zoom_out command_link_button
      /// @return The created command_link_button.
      static command_link_button zoom_out();
      /// Create a system-defined command_link_button that represent zoom_out command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_out(const drawing::point& location);
      /// Create a system-defined command_link_button that represent zoom_out command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_out(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent zoom_out command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button zoom_out(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent zoom_out command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button zoom_out(const control& parent);
      /// Create a system-defined command_link_button that represent zoom_out command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_out(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent zoom_out command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_out(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent zoom_out command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button zoom_out(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined command_link_button that represent zoom_to_fit command_link_button
      /// @return The created command_link_button.
      static command_link_button zoom_to_fit();
      /// Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified location.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_to_fit(const drawing::point& location);
      /// Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified location, and size.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_to_fit(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified location, size, and name.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button zoom_to_fit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified parent.
      /// @param parent The control that contains the command_link_button.
      /// @return The created command_link_button.
      static command_link_button zoom_to_fit(const control& parent);
      /// Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified parent, and location.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_to_fit(const control& parent, const drawing::point& location);
      /// Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified parent, location, and size.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @return The created command_link_button.
      static command_link_button zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined command_link_button that represent zoom_to_fit command_link_button with specified parent, location, size, and name.
      /// @param parent The control that contains the command_link_button.
      /// @param location The command_link_button location in pixels.
      /// @param size The command_link_button size in pixels.
      /// @param name The name of the command_link_button.
      /// @return The created command_link_button.
      static command_link_button zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
    };
  }
}
