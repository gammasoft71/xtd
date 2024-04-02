/// @file
/// @brief Contains xtd::forms::loading_indicator control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "control.h"
#include "content_alignment.h"
#include "loading_indicator_style.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a loading indicator control.
    /// @par Header
    /// @code #include <xtd/forms/loading_indicator> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                        | macOS                                          | Gnome                                          |
    /// | ----- | ---------------------------------------------- | ---------------------------------------------- | ---------------------------------------------- |
    /// | Light |  @image html control_loading_indicator_w.png   |  @image html control_loading_indicator_m.png   |  @image html control_loading_indicator_g.png   |
    /// | Dark  |  @image html control_loading_indicator_wd.png  |  @image html control_loading_indicator_md.png  |  @image html control_loading_indicator_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of loading indicator control.
    /// @include loading_indicator.cpp
    class forms_export_ loading_indicator : public control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new instance of loading_indicator class.
      loading_indicator();
      /// @}
      
      /// @cond
      loading_indicator(loading_indicator&& rhs);
      loading_indicator(const loading_indicator&) = default;
      loading_indicator& operator =(const loading_indicator&) = default;
      /// @endcond

      /// @name Public Properties
      
      /// @{
      using control::control_appearance;
      control& control_appearance(forms::control_appearance value) override;
      
      /// @brief Gets the flat style appearance of the loading_indicator control.
      /// @return One of the xtd::forms::loading_indicator_style values. The default value is xtd::forms::loading_indicator_style::standard.
      /// @remarks When the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, the text in the loading_indicator control will be aligned to the top and center locations within the bounds of the control.
      virtual xtd::forms::loading_indicator_style loading_indicator_style() const noexcept;
      /// @brief Sets the flat style appearance of the loading_indicator control.
      /// @param loading_indicator_style One of the xtd::forms::loading_indicator_style values. The default value is xtd::forms::loading_indicator_style::standard.
      /// @return Current loading_indicator instance.
      /// @remarks When the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, the text in the loading_indicator control will be aligned to the top and center locations within the bounds of the control.
      virtual xtd::forms::loading_indicator& loading_indicator_style(xtd::forms::loading_indicator_style loading_indicator_style);
      
      /// @brief Gets a valiue that indicates if the loading indicator is running.
      /// @return true if the loading indicator is running; otherwise false.
      virtual bool running() const noexcept;
      
      /// @brief Gets a valiue that indicates if the loading indicator is running.
      /// @param value true if the loading indicator is running; otherwise false.
      virtual loading_indicator& running(bool value);
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Starts animation of the loading indicator.
      void start();
      /// @brief Stops animation of the loading indicator.
      void stop();
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      static loading_indicator create();
      /// @brief A factory to create an xtd::forms::loading_indicator with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      static loading_indicator create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::loading_indicator with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      static loading_indicator create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::loading_indicator with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::loading_indicator.
      /// @param name The name of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      static loading_indicator create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::loading_indicator with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      static loading_indicator create(const control& parent);
      /// @brief A factory to create an xtd::forms::loading_indicator with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::loading_indicator.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      static loading_indicator create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::loading_indicator with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::loading_indicator.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      static loading_indicator create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::loading_indicator with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::loading_indicator.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::loading_indicator.
      /// @param name The name of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      static loading_indicator create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      xtd::forms::create_params create_params() const noexcept override;
      /// @}
      
      /// @name Protected method
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      std::unique_ptr<xtd::object> clone() const override;
      
      xtd::drawing::size measure_control() const noexcept override;
      void on_handle_created(const event_args& e) override;
      void on_paint(xtd::forms::paint_event_args& e) override;
      /// @}
      
    private:
      void on_timer_tick(object& timer, const xtd::event_args& e);
      
      std::shared_ptr<data> data_;
    };
  }
}
