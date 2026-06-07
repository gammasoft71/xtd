/// @file
/// @brief Contains xtd::forms::loading_indicator control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"
#include "content_alignment.hpp"
#include "loading_indicator_style.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a loading indicator control.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/loading_indicator>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                        | macOS                                          | Gnome                                          |
    /// | ----- | ---------------------------------------------- | ---------------------------------------------- | ---------------------------------------------- |
    /// | Light |  @image html control_loading_indicator_w.png   |  @image html control_loading_indicator_m.png   |  @image html control_loading_indicator_g.png   |
    /// | Dark  |  @image html control_loading_indicator_wd.png  |  @image html control_loading_indicator_md.png  |  @image html control_loading_indicator_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of loading indicator control.
    /// @include loading_indicator.cpp
    class forms_export_ loading_indicator : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new instance of loading_indicator class.
      loading_indicator();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      using xtd::forms::control::control_appearance;
      auto control_appearance(forms::control_appearance value) -> xtd::forms::control& override;
      
      /// @brief Gets the flat style appearance of the loading_indicator control.
      /// @return One of the xtd::forms::loading_indicator_style values. The default value is xtd::forms::loading_indicator_style::standard.
      /// @remarks When the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, the text in the loading_indicator control will be aligned to the top and center locations within the bounds of the control.
      [[nodiscard]] virtual auto loading_indicator_style() const noexcept -> xtd::forms::loading_indicator_style;
      /// @brief Sets the flat style appearance of the loading_indicator control.
      /// @param value One of the xtd::forms::loading_indicator_style values. The default value is xtd::forms::loading_indicator_style::standard.
      /// @return Current loading_indicator instance.
      /// @remarks When the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, any values assigned to the image_list, image, image_index, and image_align properties are ignored. In addition, the text_align property ignores any property values that are not vertical property settings. Horizontally aligned settings of the text_align property are aligned to the top of the control. For example, if you set the text_align property to content_alignment::top_center, content_alignment::middle_center, or content_alignment::bottom_center, when the loading_indicator_style property is set to xtd::forms::loading_indicator_style::system, the text in the loading_indicator control will be aligned to the top and center locations within the bounds of the control.
      virtual auto loading_indicator_style(xtd::forms::loading_indicator_style value) -> loading_indicator&;
      
      /// @brief Gets a valiue that indicates if the loading indicator is running.
      /// @return `true` if the loading indicator is running; otherwise `false`.
      [[nodiscard]] virtual auto running() const noexcept -> bool;
      
      /// @brief Gets a valiue that indicates if the loading indicator is running.
      /// @param value `true` if the loading indicator is running; otherwise `false`.
      virtual auto running(bool value) -> loading_indicator&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Starts animation of the loading indicator.
      auto start() -> void;
      /// @brief Stops animation of the loading indicator.
      auto stop() -> void;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      [[nodiscard]] static auto create() -> loading_indicator;
      /// @brief A factory to create an xtd::forms::loading_indicator with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> loading_indicator;
      /// @brief A factory to create an xtd::forms::loading_indicator with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> loading_indicator;
      /// @brief A factory to create an xtd::forms::loading_indicator with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::loading_indicator.
      /// @param name The name of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> loading_indicator;
      /// @brief A factory to create an xtd::forms::loading_indicator with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent) -> loading_indicator;
      /// @brief A factory to create an xtd::forms::loading_indicator with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::loading_indicator.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location) -> loading_indicator;
      /// @brief A factory to create an xtd::forms::loading_indicator with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::loading_indicator.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> loading_indicator;
      /// @brief A factory to create an xtd::forms::loading_indicator with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::loading_indicator.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::loading_indicator.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::loading_indicator.
      /// @param name The name of the xtd::forms::loading_indicator.
      /// @return New xtd::forms::loading_indicator created.
      [[nodiscard]] static auto create(const xtd::forms::control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> loading_indicator;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto create_params() const noexcept -> xtd::forms::create_params override;
      /// @}
      
      /// @name Protected method
      
      /// @{
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      auto on_handle_created(const event_args& e) -> void override;
      auto on_paint(xtd::forms::paint_event_args& e) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
