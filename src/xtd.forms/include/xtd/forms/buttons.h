/// @file
/// @brief Contains xtd::forms::buttons factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "button.h"
#include "system_texts.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides a collection of button objects for use by a Windows Forms application.
    /// @par Header
    /// @code #include <xtd/forms/buttons> @endcode
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
      /// @name Methods
      
      /// @{
      /// Create a system-defined button that represent abort button
      /// @return The created button.
      static button abort();
      /// Create a system-defined button that represent abort button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button abort(const drawing::point& location);
      /// Create a system-defined button that represent abort button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button abort(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent abort button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button abort(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent abort button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button abort(const control& parent);
      /// Create a system-defined button that represent abort button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button abort(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent abort button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button abort(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent abort button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button abort(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent about button
      /// @return The created button.
      static button about();
      /// Create a system-defined button that represent about button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button about(const drawing::point& location);
      /// Create a system-defined button that represent about button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button about(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent about button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button about(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent about button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button about(const control& parent);
      /// Create a system-defined button that represent about button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button about(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent about button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button about(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent about button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button about(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent actual_size button
      /// @return The created button.
      static button actual_size();
      /// Create a system-defined button that represent actual_size button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button actual_size(const drawing::point& location);
      /// Create a system-defined button that represent actual_size button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button actual_size(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent actual_size button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button actual_size(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent actual_size button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button actual_size(const control& parent);
      /// Create a system-defined button that represent actual_size button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button actual_size(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent actual_size button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button actual_size(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent actual_size button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button actual_size(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent add button
      /// @return The created button.
      static button add();
      /// Create a system-defined button that represent add button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button add(const drawing::point& location);
      /// Create a system-defined button that represent add button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button add(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent add button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button add(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent add button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button add(const control& parent);
      /// Create a system-defined button that represent add button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button add(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent add button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button add(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent add button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button add(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent alignment button
      /// @return The created button.
      static button alignment();
      /// Create a system-defined button that represent alignment button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button alignment(const drawing::point& location);
      /// Create a system-defined button that represent alignment button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button alignment(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent alignment button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button alignment(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent alignment button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button alignment(const control& parent);
      /// Create a system-defined button that represent alignment button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button alignment(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent alignment button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button alignment(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent alignment button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button alignment(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent align_left button
      /// @return The created button.
      static button align_left();
      /// Create a system-defined button that represent align_left button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button align_left(const drawing::point& location);
      /// Create a system-defined button that represent align_left button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button align_left(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent align_left button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button align_left(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent align_left button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button align_left(const control& parent);
      /// Create a system-defined button that represent align_left button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button align_left(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent align_left button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button align_left(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent align_left button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button align_left(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent align_right button
      /// @return The created button.
      static button align_right();
      /// Create a system-defined button that represent align_right button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button align_right(const drawing::point& location);
      /// Create a system-defined button that represent align_right button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button align_right(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent align_right button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button align_right(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent align_right button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button align_right(const control& parent);
      /// Create a system-defined button that represent align_right button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button align_right(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent align_right button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button align_right(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent align_right button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button align_right(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent apply button
      /// @return The created button.
      static button apply();
      /// Create a system-defined button that represent apply button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button apply(const drawing::point& location);
      /// Create a system-defined button that represent apply button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button apply(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent apply button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button apply(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent apply button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button apply(const control& parent);
      /// Create a system-defined button that represent apply button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button apply(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent apply button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button apply(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent apply button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button apply(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent ascending button
      /// @return The created button.
      static button ascending();
      /// Create a system-defined button that represent ascending button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button ascending(const drawing::point& location);
      /// Create a system-defined button that represent ascending button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button ascending(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent ascending button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ascending(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent ascending button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button ascending(const control& parent);
      /// Create a system-defined button that represent ascending button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button ascending(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent ascending button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button ascending(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent ascending button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ascending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent back button
      /// @return The created button.
      static button back();
      /// Create a system-defined button that represent back button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button back(const drawing::point& location);
      /// Create a system-defined button that represent back button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button back(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent back button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button back(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent back button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button back(const control& parent);
      /// Create a system-defined button that represent back button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button back(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent back button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button back(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent back button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button back(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent bold button
      /// @return The created button.
      static button bold();
      /// Create a system-defined button that represent bold button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button bold(const drawing::point& location);
      /// Create a system-defined button that represent bold button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button bold(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent bold button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button bold(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent bold button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button bold(const control& parent);
      /// Create a system-defined button that represent bold button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button bold(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent bold button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button bold(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent bold button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button bold(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent bottom button
      /// @return The created button.
      static button bottom();
      /// Create a system-defined button that represent bottom button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button bottom(const drawing::point& location);
      /// Create a system-defined button that represent bottom button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button bottom(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent bottom button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button bottom(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent bottom button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button bottom(const control& parent);
      /// Create a system-defined button that represent bottom button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button bottom(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent bottom button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button bottom(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent bottom button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button bottom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent cancel button
      /// @return The created button.
      static button cancel();
      /// Create a system-defined button that represent cancel button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button cancel(const drawing::point& location);
      /// Create a system-defined button that represent cancel button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button cancel(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent cancel button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cancel(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent cancel button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button cancel(const control& parent);
      /// Create a system-defined button that represent cancel button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button cancel(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent cancel button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button cancel(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent cancel button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cancel(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent cdrom button
      /// @return The created button.
      static button cdrom();
      /// Create a system-defined button that represent cdrom button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button cdrom(const drawing::point& location);
      /// Create a system-defined button that represent cdrom button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button cdrom(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent cdrom button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cdrom(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent cdrom button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button cdrom(const control& parent);
      /// Create a system-defined button that represent cdrom button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button cdrom(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent cdrom button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button cdrom(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent cdrom button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cdrom(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent centered button
      /// @return The created button.
      static button centered();
      /// Create a system-defined button that represent centered button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button centered(const drawing::point& location);
      /// Create a system-defined button that represent centered button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button centered(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent centered button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button centered(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent centered button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button centered(const control& parent);
      /// Create a system-defined button that represent centered button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button centered(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent centered button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button centered(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent centered button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button centered(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent clear button
      /// @return The created button.
      static button clear();
      /// Create a system-defined button that represent clear button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button clear(const drawing::point& location);
      /// Create a system-defined button that represent clear button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button clear(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent clear button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button clear(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent clear button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button clear(const control& parent);
      /// Create a system-defined button that represent clear button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button clear(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent clear button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button clear(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent clear button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button clear(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent close button
      /// @return The created button.
      static button close();
      /// Create a system-defined button that represent close button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button close(const drawing::point& location);
      /// Create a system-defined button that represent close button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button close(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent close button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button close(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent close button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button close(const control& parent);
      /// Create a system-defined button that represent close button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button close(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent close button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button close(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent close button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button close(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent color button
      /// @return The created button.
      static button color();
      /// Create a system-defined button that represent color button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button color(const drawing::point& location);
      /// Create a system-defined button that represent color button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button color(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent color button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button color(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent color button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button color(const control& parent);
      /// Create a system-defined button that represent color button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button color(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent color button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button color(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent color button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button color(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent contents button
      /// @return The created button.
      static button contents();
      /// Create a system-defined button that represent contents button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button contents(const drawing::point& location);
      /// Create a system-defined button that represent contents button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button contents(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent contents button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button contents(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent contents button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button contents(const control& parent);
      /// Create a system-defined button that represent contents button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button contents(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent contents button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button contents(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent contents button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button contents(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent convert button
      /// @return The created button.
      static button convert();
      /// Create a system-defined button that represent convert button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button convert(const drawing::point& location);
      /// Create a system-defined button that represent convert button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button convert(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent convert button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button convert(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent convert button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button convert(const control& parent);
      /// Create a system-defined button that represent convert button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button convert(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent convert button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button convert(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent convert button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button convert(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent copy button
      /// @return The created button.
      static button copy();
      /// Create a system-defined button that represent copy button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button copy(const drawing::point& location);
      /// Create a system-defined button that represent copy button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button copy(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent copy button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button copy(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent copy button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button copy(const control& parent);
      /// Create a system-defined button that represent copy button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button copy(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent copy button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button copy(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent copy button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button copy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent customize button
      /// @return The created button.
      static button customize();
      /// Create a system-defined button that represent customize button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button customize(const drawing::point& location);
      /// Create a system-defined button that represent customize button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button customize(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent customize button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button customize(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent customize button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button customize(const control& parent);
      /// Create a system-defined button that represent customize button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button customize(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent customize button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button customize(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent customize button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button customize(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent cut button
      /// @return The created button.
      static button cut();
      /// Create a system-defined button that represent cut button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button cut(const drawing::point& location);
      /// Create a system-defined button that represent cut button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button cut(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent cut button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cut(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent cut button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button cut(const control& parent);
      /// Create a system-defined button that represent cut button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button cut(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent cut button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button cut(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent cut button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button cut(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent del button
      /// @return The created button.
      static button del();
      /// Create a system-defined button that represent del button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button del(const drawing::point& location);
      /// Create a system-defined button that represent del button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button del(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent del button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button del(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent del button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button del(const control& parent);
      /// Create a system-defined button that represent del button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button del(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent del button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button del(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent del button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button del(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent descending button
      /// @return The created button.
      static button descending();
      /// Create a system-defined button that represent descending button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button descending(const drawing::point& location);
      /// Create a system-defined button that represent descending button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button descending(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent descending button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button descending(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent descending button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button descending(const control& parent);
      /// Create a system-defined button that represent descending button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button descending(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent descending button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button descending(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent descending button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button descending(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent down button
      /// @return The created button.
      static button down();
      /// Create a system-defined button that represent down button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button down(const drawing::point& location);
      /// Create a system-defined button that represent down button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button down(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent down button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button down(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent down button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button down(const control& parent);
      /// Create a system-defined button that represent down button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button down(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent down button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button down(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent down button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button down(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent edit button
      /// @return The created button.
      static button edit();
      /// Create a system-defined button that represent edit button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button edit(const drawing::point& location);
      /// Create a system-defined button that represent edit button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button edit(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent edit button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button edit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent edit button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button edit(const control& parent);
      /// Create a system-defined button that represent edit button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button edit(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent edit button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button edit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent edit button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button edit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent execute button
      /// @return The created button.
      static button execute();
      /// Create a system-defined button that represent execute button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button execute(const drawing::point& location);
      /// Create a system-defined button that represent execute button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button execute(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent execute button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button execute(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent execute button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button execute(const control& parent);
      /// Create a system-defined button that represent execute button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button execute(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent execute button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button execute(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent execute button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button execute(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent exit button
      /// @return The created button.
      static button exit();
      /// Create a system-defined button that represent exit button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button exit(const drawing::point& location);
      /// Create a system-defined button that represent exit button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button exit(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent exit button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button exit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent exit button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button exit(const control& parent);
      /// Create a system-defined button that represent exit button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button exit(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent exit button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button exit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent exit button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button exit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent file button
      /// @return The created button.
      static button file();
      /// Create a system-defined button that represent file button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button file(const drawing::point& location);
      /// Create a system-defined button that represent file button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button file(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent file button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button file(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent file button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button file(const control& parent);
      /// Create a system-defined button that represent file button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button file(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent file button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button file(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent file button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button file(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent find button
      /// @return The created button.
      static button find();
      /// Create a system-defined button that represent find button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button find(const drawing::point& location);
      /// Create a system-defined button that represent find button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button find(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent find button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button find(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent find button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button find(const control& parent);
      /// Create a system-defined button that represent find button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button find(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent find button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button find(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent find button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button find(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent first button
      /// @return The created button.
      static button first();
      /// Create a system-defined button that represent first button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button first(const drawing::point& location);
      /// Create a system-defined button that represent first button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button first(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent first button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button first(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent first button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button first(const control& parent);
      /// Create a system-defined button that represent first button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button first(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent first button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button first(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent first button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button first(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent floppy button
      /// @return The created button.
      static button floppy();
      /// Create a system-defined button that represent floppy button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button floppy(const drawing::point& location);
      /// Create a system-defined button that represent floppy button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button floppy(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent floppy button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button floppy(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent floppy button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button floppy(const control& parent);
      /// Create a system-defined button that represent floppy button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button floppy(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent floppy button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button floppy(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent floppy button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button floppy(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent font button
      /// @return The created button.
      static button font();
      /// Create a system-defined button that represent font button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button font(const drawing::point& location);
      /// Create a system-defined button that represent font button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button font(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent font button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button font(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent font button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button font(const control& parent);
      /// Create a system-defined button that represent font button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button font(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent font button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button font(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent font button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button font(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent forward button
      /// @return The created button.
      static button forward();
      /// Create a system-defined button that represent forward button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button forward(const drawing::point& location);
      /// Create a system-defined button that represent forward button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button forward(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent forward button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button forward(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent forward button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button forward(const control& parent);
      /// Create a system-defined button that represent forward button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button forward(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent forward button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button forward(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent forward button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button forward(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent harddisk button
      /// @return The created button.
      static button harddisk();
      /// Create a system-defined button that represent harddisk button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button harddisk(const drawing::point& location);
      /// Create a system-defined button that represent harddisk button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button harddisk(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent harddisk button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button harddisk(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent harddisk button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button harddisk(const control& parent);
      /// Create a system-defined button that represent harddisk button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button harddisk(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent harddisk button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button harddisk(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent harddisk button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button harddisk(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent help button
      /// @return The created button.
      static button help();
      /// Create a system-defined button that represent help button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button help(const drawing::point& location);
      /// Create a system-defined button that represent help button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button help(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent help button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button help(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent help button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button help(const control& parent);
      /// Create a system-defined button that represent help button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button help(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent help button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button help(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent help button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button help(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent home button
      /// @return The created button.
      static button home();
      /// Create a system-defined button that represent home button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button home(const drawing::point& location);
      /// Create a system-defined button that represent home button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button home(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent home button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button home(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent home button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button home(const control& parent);
      /// Create a system-defined button that represent home button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button home(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent home button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button home(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent home button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button home(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent ignore button
      /// @return The created button.
      static button ignore();
      /// Create a system-defined button that represent ignore button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button ignore(const drawing::point& location);
      /// Create a system-defined button that represent ignore button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button ignore(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent ignore button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ignore(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent ignore button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button ignore(const control& parent);
      /// Create a system-defined button that represent ignore button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button ignore(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent ignore button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button ignore(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent ignore button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ignore(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent indent button
      /// @return The created button.
      static button indent();
      /// Create a system-defined button that represent indent button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button indent(const drawing::point& location);
      /// Create a system-defined button that represent indent button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button indent(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent indent button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button indent(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent indent button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button indent(const control& parent);
      /// Create a system-defined button that represent indent button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button indent(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent indent button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button indent(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent indent button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button indent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent index button
      /// @return The created button.
      static button index();
      /// Create a system-defined button that represent index button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button index(const drawing::point& location);
      /// Create a system-defined button that represent index button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button index(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent index button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button index(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent index button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button index(const control& parent);
      /// Create a system-defined button that represent index button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button index(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent index button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button index(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent index button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button index(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent info button
      /// @return The created button.
      static button info();
      /// Create a system-defined button that represent info button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button info(const drawing::point& location);
      /// Create a system-defined button that represent info button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button info(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent info button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button info(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent info button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button info(const control& parent);
      /// Create a system-defined button that represent info button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button info(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent info button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button info(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent info button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button info(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent italic button
      /// @return The created button.
      static button italic();
      /// Create a system-defined button that represent italic button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button italic(const drawing::point& location);
      /// Create a system-defined button that represent italic button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button italic(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent italic button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button italic(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent italic button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button italic(const control& parent);
      /// Create a system-defined button that represent italic button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button italic(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent italic button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button italic(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent italic button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button italic(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent justified button
      /// @return The created button.
      static button justified();
      /// Create a system-defined button that represent justified button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button justified(const drawing::point& location);
      /// Create a system-defined button that represent justified button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button justified(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent justified button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button justified(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent justified button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button justified(const control& parent);
      /// Create a system-defined button that represent justified button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button justified(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent justified button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button justified(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent justified button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button justified(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent jump_to button
      /// @return The created button.
      static button jump_to();
      /// Create a system-defined button that represent jump_to button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button jump_to(const drawing::point& location);
      /// Create a system-defined button that represent jump_to button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button jump_to(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent jump_to button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button jump_to(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent jump_to button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button jump_to(const control& parent);
      /// Create a system-defined button that represent jump_to button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button jump_to(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent jump_to button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button jump_to(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent jump_to button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button jump_to(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent last button
      /// @return The created button.
      static button last();
      /// Create a system-defined button that represent last button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button last(const drawing::point& location);
      /// Create a system-defined button that represent last button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button last(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent last button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button last(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent last button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button last(const control& parent);
      /// Create a system-defined button that represent last button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button last(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent last button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button last(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent last button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button last(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent network button
      /// @return The created button.
      static button network();
      /// Create a system-defined button that represent network button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button network(const drawing::point& location);
      /// Create a system-defined button that represent network button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button network(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent network button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button network(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent network button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button network(const control& parent);
      /// Create a system-defined button that represent network button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button network(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent network button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button network(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent network button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button network(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent new_ button
      /// @return The created button.
      static button new_();
      /// Create a system-defined button that represent new_ button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button new_(const drawing::point& location);
      /// Create a system-defined button that represent new_ button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button new_(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent new_ button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button new_(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent new_ button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button new_(const control& parent);
      /// Create a system-defined button that represent new_ button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button new_(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent new_ button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button new_(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent new_ button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button new_(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent next button
      /// @return The created button.
      static button next();
      /// Create a system-defined button that represent next button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button next(const drawing::point& location);
      /// Create a system-defined button that represent next button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button next(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent next button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button next(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent next button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button next(const control& parent);
      /// Create a system-defined button that represent next button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button next(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent next button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button next(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent next button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button next(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent no button
      /// @return The created button.
      static button no();
      /// Create a system-defined button that represent no button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button no(const drawing::point& location);
      /// Create a system-defined button that represent no button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button no(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent no button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button no(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent no button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button no(const control& parent);
      /// Create a system-defined button that represent no button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button no(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent no button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button no(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent no button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button no(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent ok button
      /// @return The created button.
      static button ok();
      /// Create a system-defined button that represent ok button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button ok(const drawing::point& location);
      /// Create a system-defined button that represent ok button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button ok(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent ok button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ok(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent ok button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button ok(const control& parent);
      /// Create a system-defined button that represent ok button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button ok(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent ok button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button ok(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent ok button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button ok(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent open button
      /// @return The created button.
      static button open();
      /// Create a system-defined button that represent open button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button open(const drawing::point& location);
      /// Create a system-defined button that represent open button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button open(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent open button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button open(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent open button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button open(const control& parent);
      /// Create a system-defined button that represent open button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button open(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent open button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button open(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent open button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button open(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent options button
      /// @return The created button.
      static button options();
      /// Create a system-defined button that represent options button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button options(const drawing::point& location);
      /// Create a system-defined button that represent options button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button options(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent options button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button options(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent options button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button options(const control& parent);
      /// Create a system-defined button that represent options button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button options(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent options button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button options(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent options button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button options(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent paste button
      /// @return The created button.
      static button paste();
      /// Create a system-defined button that represent paste button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button paste(const drawing::point& location);
      /// Create a system-defined button that represent paste button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button paste(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent paste button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button paste(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent paste button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button paste(const control& parent);
      /// Create a system-defined button that represent paste button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button paste(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent paste button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button paste(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent paste button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button paste(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent preferences button
      /// @return The created button.
      static button preferences();
      /// Create a system-defined button that represent preferences button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button preferences(const drawing::point& location);
      /// Create a system-defined button that represent preferences button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button preferences(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent preferences button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button preferences(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent preferences button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button preferences(const control& parent);
      /// Create a system-defined button that represent preferences button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button preferences(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent preferences button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button preferences(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent preferences button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button preferences(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent previous button
      /// @return The created button.
      static button previous();
      /// Create a system-defined button that represent previous button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button previous(const drawing::point& location);
      /// Create a system-defined button that represent previous button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button previous(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent previous button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button previous(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent previous button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button previous(const control& parent);
      /// Create a system-defined button that represent previous button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button previous(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent previous button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button previous(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent previous button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button previous(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent print button
      /// @return The created button.
      static button print();
      /// Create a system-defined button that represent print button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button print(const drawing::point& location);
      /// Create a system-defined button that represent print button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button print(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent print button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button print(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent print button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button print(const control& parent);
      /// Create a system-defined button that represent print button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button print(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent print button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button print(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent print button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button print(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent print_preview button
      /// @return The created button.
      static button print_preview();
      /// Create a system-defined button that represent print_preview button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button print_preview(const drawing::point& location);
      /// Create a system-defined button that represent print_preview button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button print_preview(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent print_preview button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button print_preview(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent print_preview button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button print_preview(const control& parent);
      /// Create a system-defined button that represent print_preview button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button print_preview(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent print_preview button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button print_preview(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent print_preview button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button print_preview(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent properties button
      /// @return The created button.
      static button properties();
      /// Create a system-defined button that represent properties button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button properties(const drawing::point& location);
      /// Create a system-defined button that represent properties button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button properties(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent properties button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button properties(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent properties button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button properties(const control& parent);
      /// Create a system-defined button that represent properties button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button properties(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent properties button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button properties(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent properties button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button properties(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent quit button
      /// @return The created button.
      static button quit();
      /// Create a system-defined button that represent quit button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button quit(const drawing::point& location);
      /// Create a system-defined button that represent quit button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button quit(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent quit button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button quit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent quit button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button quit(const control& parent);
      /// Create a system-defined button that represent quit button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button quit(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent quit button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button quit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent quit button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button quit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent redo button
      /// @return The created button.
      static button redo();
      /// Create a system-defined button that represent redo button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button redo(const drawing::point& location);
      /// Create a system-defined button that represent redo button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button redo(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent redo button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button redo(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent redo button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button redo(const control& parent);
      /// Create a system-defined button that represent redo button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button redo(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent redo button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button redo(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent redo button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button redo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent refresh button
      /// @return The created button.
      static button refresh();
      /// Create a system-defined button that represent refresh button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button refresh(const drawing::point& location);
      /// Create a system-defined button that represent refresh button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button refresh(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent refresh button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button refresh(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent refresh button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button refresh(const control& parent);
      /// Create a system-defined button that represent refresh button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button refresh(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent refresh button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button refresh(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent refresh button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button refresh(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent remove button
      /// @return The created button.
      static button remove();
      /// Create a system-defined button that represent remove button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button remove(const drawing::point& location);
      /// Create a system-defined button that represent remove button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button remove(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent remove button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button remove(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent remove button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button remove(const control& parent);
      /// Create a system-defined button that represent remove button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button remove(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent remove button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button remove(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent remove button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button remove(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent replace button
      /// @return The created button.
      static button replace();
      /// Create a system-defined button that represent replace button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button replace(const drawing::point& location);
      /// Create a system-defined button that represent replace button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button replace(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent replace button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button replace(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent replace button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button replace(const control& parent);
      /// Create a system-defined button that represent replace button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button replace(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent replace button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button replace(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent replace button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button replace(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent retry button
      /// @return The created button.
      static button retry();
      /// Create a system-defined button that represent retry button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button retry(const drawing::point& location);
      /// Create a system-defined button that represent retry button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button retry(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent retry button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button retry(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent retry button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button retry(const control& parent);
      /// Create a system-defined button that represent retry button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button retry(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent retry button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button retry(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent retry button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button retry(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent revert_to_saved button
      /// @return The created button.
      static button revert_to_saved();
      /// Create a system-defined button that represent revert_to_saved button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button revert_to_saved(const drawing::point& location);
      /// Create a system-defined button that represent revert_to_saved button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button revert_to_saved(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent revert_to_saved button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button revert_to_saved(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent revert_to_saved button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button revert_to_saved(const control& parent);
      /// Create a system-defined button that represent revert_to_saved button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button revert_to_saved(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent revert_to_saved button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent revert_to_saved button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button revert_to_saved(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent save button
      /// @return The created button.
      static button save();
      /// Create a system-defined button that represent save button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button save(const drawing::point& location);
      /// Create a system-defined button that represent save button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button save(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent save button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button save(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent save button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button save(const control& parent);
      /// Create a system-defined button that represent save button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button save(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent save button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button save(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent save button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button save(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent save_as button
      /// @return The created button.
      static button save_as();
      /// Create a system-defined button that represent save_as button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button save_as(const drawing::point& location);
      /// Create a system-defined button that represent save_as button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button save_as(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent save_as button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button save_as(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent save_as button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button save_as(const control& parent);
      /// Create a system-defined button that represent save_as button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button save_as(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent save_as button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button save_as(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent save_as button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button save_as(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent search button
      /// @return The created button.
      static button search();
      /// Create a system-defined button that represent search button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button search(const drawing::point& location);
      /// Create a system-defined button that represent search button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button search(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent search button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button search(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent search button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button search(const control& parent);
      /// Create a system-defined button that represent search button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button search(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent search button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button search(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent search button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button search(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent select_all button
      /// @return The created button.
      static button select_all();
      /// Create a system-defined button that represent select_all button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button select_all(const drawing::point& location);
      /// Create a system-defined button that represent select_all button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button select_all(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent select_all button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button select_all(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent select_all button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button select_all(const control& parent);
      /// Create a system-defined button that represent select_all button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button select_all(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent select_all button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button select_all(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent select_all button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button select_all(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent settings button
      /// @return The created button.
      static button settings();
      /// Create a system-defined button that represent settings button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button settings(const drawing::point& location);
      /// Create a system-defined button that represent settings button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button settings(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent settings button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button settings(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent settings button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button settings(const control& parent);
      /// Create a system-defined button that represent settings button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button settings(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent settings button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button settings(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent settings button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button settings(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent spell_check button
      /// @return The created button.
      static button spell_check();
      /// Create a system-defined button that represent spell_check button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button spell_check(const drawing::point& location);
      /// Create a system-defined button that represent spell_check button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button spell_check(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent spell_check button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button spell_check(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent spell_check button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button spell_check(const control& parent);
      /// Create a system-defined button that represent spell_check button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button spell_check(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent spell_check button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button spell_check(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent spell_check button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button spell_check(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent stop button
      /// @return The created button.
      static button stop();
      /// Create a system-defined button that represent stop button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button stop(const drawing::point& location);
      /// Create a system-defined button that represent stop button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button stop(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent stop button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button stop(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent stop button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button stop(const control& parent);
      /// Create a system-defined button that represent stop button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button stop(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent stop button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button stop(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent stop button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button stop(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent strikeout button
      /// @return The created button.
      static button strikeout();
      /// Create a system-defined button that represent strikeout button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button strikeout(const drawing::point& location);
      /// Create a system-defined button that represent strikeout button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button strikeout(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent strikeout button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button strikeout(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent strikeout button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button strikeout(const control& parent);
      /// Create a system-defined button that represent strikeout button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button strikeout(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent strikeout button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button strikeout(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent strikeout button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button strikeout(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent tools button
      /// @return The created button.
      static button tools();
      /// Create a system-defined button that represent tools button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button tools(const drawing::point& location);
      /// Create a system-defined button that represent tools button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button tools(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent tools button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button tools(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent tools button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button tools(const control& parent);
      /// Create a system-defined button that represent tools button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button tools(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent tools button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button tools(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent tools button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button tools(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent top button
      /// @return The created button.
      static button top();
      /// Create a system-defined button that represent top button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button top(const drawing::point& location);
      /// Create a system-defined button that represent top button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button top(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent top button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button top(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent top button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button top(const control& parent);
      /// Create a system-defined button that represent top button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button top(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent top button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button top(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent top button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button top(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent undelete button
      /// @return The created button.
      static button undelete();
      /// Create a system-defined button that represent undelete button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button undelete(const drawing::point& location);
      /// Create a system-defined button that represent undelete button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button undelete(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent undelete button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button undelete(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent undelete button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button undelete(const control& parent);
      /// Create a system-defined button that represent undelete button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button undelete(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent undelete button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button undelete(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent undelete button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button undelete(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent underline button
      /// @return The created button.
      static button underline();
      /// Create a system-defined button that represent underline button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button underline(const drawing::point& location);
      /// Create a system-defined button that represent underline button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button underline(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent underline button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button underline(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent underline button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button underline(const control& parent);
      /// Create a system-defined button that represent underline button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button underline(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent underline button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button underline(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent underline button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button underline(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent undo button
      /// @return The created button.
      static button undo();
      /// Create a system-defined button that represent undo button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button undo(const drawing::point& location);
      /// Create a system-defined button that represent undo button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button undo(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent undo button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button undo(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent undo button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button undo(const control& parent);
      /// Create a system-defined button that represent undo button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button undo(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent undo button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button undo(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent undo button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button undo(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent unindent button
      /// @return The created button.
      static button unindent();
      /// Create a system-defined button that represent unindent button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button unindent(const drawing::point& location);
      /// Create a system-defined button that represent unindent button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button unindent(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent unindent button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button unindent(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent unindent button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button unindent(const control& parent);
      /// Create a system-defined button that represent unindent button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button unindent(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent unindent button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button unindent(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent unindent button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button unindent(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent up button
      /// @return The created button.
      static button up();
      /// Create a system-defined button that represent up button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button up(const drawing::point& location);
      /// Create a system-defined button that represent up button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button up(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent up button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button up(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent up button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button up(const control& parent);
      /// Create a system-defined button that represent up button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button up(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent up button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button up(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent up button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button up(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent view button
      /// @return The created button.
      static button view();
      /// Create a system-defined button that represent view button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button view(const drawing::point& location);
      /// Create a system-defined button that represent view button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button view(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent view button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button view(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent view button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button view(const control& parent);
      /// Create a system-defined button that represent view button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button view(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent view button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button view(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent view button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button view(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent window button
      /// @return The created button.
      static button window();
      /// Create a system-defined button that represent window button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button window(const drawing::point& location);
      /// Create a system-defined button that represent window button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button window(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent window button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button window(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent window button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button window(const control& parent);
      /// Create a system-defined button that represent window button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button window(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent window button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button window(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent window button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button window(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent yes button
      /// @return The created button.
      static button yes();
      /// Create a system-defined button that represent yes button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button yes(const drawing::point& location);
      /// Create a system-defined button that represent yes button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button yes(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent yes button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button yes(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent yes button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button yes(const control& parent);
      /// Create a system-defined button that represent yes button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button yes(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent yes button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button yes(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent yes button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button yes(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent zoom_in button
      /// @return The created button.
      static button zoom_in();
      /// Create a system-defined button that represent zoom_in button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button zoom_in(const drawing::point& location);
      /// Create a system-defined button that represent zoom_in button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button zoom_in(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent zoom_in button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_in(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent zoom_in button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button zoom_in(const control& parent);
      /// Create a system-defined button that represent zoom_in button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button zoom_in(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent zoom_in button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button zoom_in(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent zoom_in button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_in(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent zoom_out button
      /// @return The created button.
      static button zoom_out();
      /// Create a system-defined button that represent zoom_out button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button zoom_out(const drawing::point& location);
      /// Create a system-defined button that represent zoom_out button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button zoom_out(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent zoom_out button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_out(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent zoom_out button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button zoom_out(const control& parent);
      /// Create a system-defined button that represent zoom_out button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button zoom_out(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent zoom_out button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button zoom_out(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent zoom_out button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_out(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      
      /// Create a system-defined button that represent zoom_to_fit button
      /// @return The created button.
      static button zoom_to_fit();
      /// Create a system-defined button that represent zoom_to_fit button with specified location.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button zoom_to_fit(const drawing::point& location);
      /// Create a system-defined button that represent zoom_to_fit button with specified location, and size.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button zoom_to_fit(const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent zoom_to_fit button with specified location, size, and name.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_to_fit(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// Create a system-defined button that represent zoom_to_fit button with specified parent.
      /// @param parent The control that contains the button.
      /// @return The created button.
      static button zoom_to_fit(const control& parent);
      /// Create a system-defined button that represent zoom_to_fit button with specified parent, and location.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @return The created button.
      static button zoom_to_fit(const control& parent, const drawing::point& location);
      /// Create a system-defined button that represent zoom_to_fit button with specified parent, location, and size.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @return The created button.
      static button zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size);
      /// Create a system-defined button that represent zoom_to_fit button with specified parent, location, size, and name.
      /// @param parent The control that contains the button.
      /// @param location The button location in pixels.
      /// @param size The button size in pixels.
      /// @param name The name of the button.
      /// @return The created button.
      static button zoom_to_fit(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
    };
  }
}
