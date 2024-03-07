/// @file
/// @brief Contains xtd::forms::group_box container.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "border_style.h"
#include "control.h"
#include "flat_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a Windows control that displays a frame around a group of controls with an optional caption.
    /// @par Header
    /// @code #include <xtd/forms/group_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms containers
    /// @par Appearance
    /// |       | Windows                                   | macOS                                     | Gnome                                     |
    /// | ----- | ----------------------------------------- | ----------------------------------------- | ----------------------------------------- |
    /// | Light |  @image html containers_group_box_w.png   |  @image html containers_group_box_m.png   |  @image html containers_group_box_g.png   |
    /// | Dark  |  @image html containers_group_box_wd.png  |  @image html containers_group_box_md.png  |  @image html containers_group_box_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of group_box container.
    /// @include group_box.cpp
    /// @par Examples
    /// The following code example demonstrates the use of group_box container and check_box controls.
    /// @include group_box_and_check_box.cpp
    /// @par Examples
    /// The following code example demonstrates the use of group_box container and radio_group_box controls.
    /// @include group_box_and_radio_group_box.cpp
    class forms_export_ group_box : public control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new instance of the group_box class.
      group_box();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets how the group_box behaves when its auto_size property is enabled
      /// @return One of the xtd::forms::auto_size_mode values. The default is xtd::forms::auto_size_mode::grow_only.
      virtual forms::auto_size_mode auto_size_mode() const noexcept;
      /// @brief Sets how the group_box behaves when its auto_size property is enabled
      /// @param value One of the xtd::forms::auto_size_mode values. The default is xtd::forms::auto_size_mode::grow_only.
      /// @return Current group_box.
      virtual group_box& auto_size_mode(forms::auto_size_mode value);
      
      using control::control_appearance;
      control& control_appearance(forms::control_appearance value) override;
      
      /// @brief Gets the flat style appearance of the xtd::forms::group_box control.
      /// @return One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      virtual xtd::forms::flat_style flat_style() const noexcept;
      /// @brief Sets the flat style appearance of the xtd::forms::group_box control.
      /// @param flat_style One of the xtd::forms::flat_style values. The default value is xtd::forms::flat_style::standard.
      virtual xtd::forms::group_box& flat_style(xtd::forms::flat_style flat_style);
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create();
      /// @brief A factory to create an xtd::forms::group_box with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::group_box with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::group_box with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::group_box.
      /// @param name The name of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::group_box with specified text.
      /// @param text A string that represent text of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const xtd::ustring& text);
      /// @brief A factory to create an xtd::forms::group_box with specified text, and location.
      /// @param text A string that represent text of the xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const xtd::ustring& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::group_box with specified text, location, and size.
      /// @param text A string that represent text of the xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::group_box with specified text, location, size, and name.
      /// @param text A string that represent text of the xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::group_box.
      /// @param name The name of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::group_box with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const control& parent);
      /// @brief A factory to create an xtd::forms::group_box with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::group_box with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::group_box with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::group_box.
      /// @param name The name of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::group_box with specified parent, and text.
      /// @param parent The parent that contains the new created xtd::forms::group_box.
      /// @param text A string that represent text of the xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const control& parent, const xtd::ustring& text);
      /// @brief A factory to create an xtd::forms::group_box with specified parent, text, and location.
      /// @param parent The parent that contains the new created xtd::forms::group_box.
      /// @param text A string that represent text of the xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const control& parent, const xtd::ustring& text, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::group_box with specified parent, text, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::group_box.
      /// @param text A string that represent text of the xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::group_box with specified parent, text, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::group_box.
      /// @param text A string that represent text of the xtd::forms::group_box.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::group_box.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::group_box.
      /// @param name The name of the xtd::forms::group_box.
      /// @return New xtd::forms::group_box created.
      static group_box create(const control& parent, const xtd::ustring& text, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protectd properties
      
      /// @{
      forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protectd methods
      
      /// @{
      drawing::size measure_control() const noexcept override;
      void on_font_changed(const xtd::event_args& e) override;
      void on_resize(const xtd::event_args& e) override;
      void on_text_changed(const xtd::event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
