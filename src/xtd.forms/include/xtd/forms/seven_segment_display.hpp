/// @file
/// @brief Contains xtd::forms::seven_segment_display control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "application.hpp"
#include "control.hpp"
#include "segments.hpp"
#include "segment_style.hpp"
#include <xtd/argument_out_of_range_exception>
#include <xtd/drawing/system_colors>

namespace xtd {
  namespace forms {
    /// @brief Represents a seven segment display class.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/seven_segment_display>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                            | macOS                                              | Gnome                                              |
    /// | ----- | -------------------------------------------------- | -------------------------------------------------- | -------------------------------------------------- |
    /// | Light |  @image html control_seven_segment_display_w.png   |  @image html control_seven_segment_display_m.png   |  @image html control_seven_segment_display_g.png   |
    /// | Dark  |  @image html control_seven_segment_display_wd.png  |  @image html control_seven_segment_display_md.png  |  @image html control_seven_segment_display_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of seven segment display control.
    /// @include seven_segment_display.cpp
    class seven_segment_display : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new instance of seven_segment_display class.
      seven_segment_display();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets background segment color.
      /// @return A xtd::drawing color that represent the background segment color.
      /// @remarks Do not confuse back_segment_color and back_color. Background segment color is the color when segment is off.
      virtual auto back_segment_color() const noexcept -> xtd::drawing::color;
      /// @brief Sets background segment color.
      /// @param value A xtd::drawing color that represent the background segment color.
      /// @return Current seven_segment_display.
      /// @remarks Do not confuse back_segment_color and back_color. Background segment color is the color when segment is off.
      virtual auto back_segment_color(const xtd::drawing::color& value) -> seven_segment_display&;
      
      /// @brief Gets the background segment opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the background segment opacity.
      virtual auto back_segment_opacity() const noexcept -> double;
      /// @brief Sets the background segment opacity.
      /// @param value A double-precision value between 0.0 and 1.0 that represent the background segment opacity.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.0 or greater than 1.0.
      /// @return Current seven_segment_display.
      virtual auto back_segment_opacity(double value) -> seven_segment_display&;
      
      /// @brief Gets a value indicate if background segments are shown.
      /// @return `true` if background segments are shown; otherwise `false`
      virtual auto show_back_segment() const noexcept -> bool;
      /// @brief Sets a value indicate if background segments are shown.
      /// @param value `true` if background segments are shown; otherwise `false`
      /// @return Current seven_segment_display.
      virtual auto show_back_segment(bool value) -> seven_segment_display&;
      
      /// @brief Gets segment style.
      /// @return One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      virtual auto segment_style() const noexcept -> xtd::forms::segment_style;
      /// @brief Sets segment style.
      /// @param value One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      /// @return Current seven_segment_display.
      virtual auto segment_style(xtd::forms::segment_style value) -> seven_segment_display&;
      
      /// @brief Gets thickness of segment.
      /// @return A int32 that represent the segment thickness.
      virtual auto thickness() const noexcept -> xtd::int32;
      /// @brief Sets thickness of segment.
      /// @param value A int32 that represent the segment thickness.
      /// @return Current seven_segment_display.
      virtual auto thickness(xtd::int32 value) -> seven_segment_display&;
      
      /// @brief Gets seven_segment_display value.
      /// @return A xtd::forms::segments combination that represent seven_segment_display.
      virtual auto value() const noexcept -> xtd::forms::segments;
      /// @brief Sets seven_segment_display value.
      /// @param value A xtd::forms::segments combination that represent seven_segment_display.
      /// @return Current seven_segment_display.
      virtual auto value(xtd::forms::segments value) -> seven_segment_display&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Gets if specified xtd::forms::segments combination is on.
      /// @return `true` if xtd::forms::segments combination is on; otherwise `false`.
      virtual auto get_segments(xtd::forms::segments segment) const noexcept -> bool;
      /// @brief Sets specified xtd::forms::segments combination to on.
      /// @param segment A xtd::forms::segments combination to set.
      /// @param on `true` to set to on; otherwise `false`.
      virtual auto set_segments(xtd::forms::segments segment, bool value) -> void;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create() -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const drawing::point& location) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const drawing::point& location, const drawing::size& size) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const drawing::point& location, const drawing::size& size, const xtd::string& name) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments.
      /// @param segments A dots_collection that represent all dots status.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(xtd::forms::segments segments) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, and location.
      /// @param segments A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(xtd::forms::segments segments, const drawing::point& location) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, location, and size.
      /// @param segments A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, location, size, and name.
      /// @param segments A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, and back_segment visibility.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment `true` if background segments are shown; otherwise `false`
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(xtd::forms::segments segments, bool show_back_segment) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, back_segment visibility, and location.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment `true` if background segments are shown; otherwise `false`
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, back_segment visibility, location, and size.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment `true` if background segments are shown; otherwise `false`
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, back_segment visibility, location, size, and name.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment `true` if background segments are shown; otherwise `false`
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, const drawing::point& location) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, const drawing::point& location, const drawing::size& size) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, xtd::forms::segments segments) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, and location.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, xtd::forms::segments segments, const drawing::point& location) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, and back_segment visibility.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param show_back_segment `true` if background segments are shown; otherwise `false`
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, xtd::forms::segments segments, bool show_back_segment) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, back_segment visibility, and location.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param show_back_segment `true` if background segments are shown; otherwise `false`
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, back_segment visibility, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param show_back_segment `true` if background segments are shown; otherwise `false`
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size) -> seven_segment_display;
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, back_segment visibility, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param show_back_segment `true` if background segments are shown; otherwise `false`
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      [[nodiscard]] static auto create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::string& name) -> seven_segment_display;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto default_size() const noexcept -> xtd::drawing::size override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Draw all background digit on specified graphics.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      virtual auto draw_back_digit(xtd::drawing::graphics& graphics) -> void;
      
      /// @brief Draw segment a on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual auto draw_segment_a(xtd::drawing::graphics& graphics, const xtd::drawing::color& color) -> void;
      
      /// @brief Draw segment b on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual auto draw_segment_b(xtd::drawing::graphics& graphics, const xtd::drawing::color& color) -> void;
      
      /// @brief Draw segment c on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual auto draw_segment_c(xtd::drawing::graphics& graphics, const xtd::drawing::color& color) -> void;
      
      /// @brief Draw segment d on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual auto draw_segment_d(xtd::drawing::graphics& graphics, const xtd::drawing::color& color) -> void;
      
      /// @brief Draw segment e on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual auto draw_segment_e(xtd::drawing::graphics& graphics, const xtd::drawing::color& color) -> void;
      
      /// @brief Draw segment f on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual auto draw_segment_f(xtd::drawing::graphics& graphics, const xtd::drawing::color& color) -> void;
      
      /// @brief Draw segment g on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual auto draw_segment_g(xtd::drawing::graphics& graphics, const xtd::drawing::color& color) -> void;
      
      /// @brief Draw segment dot point on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual auto draw_dp(xtd::drawing::graphics& graphics, const xtd::drawing::color& color) -> void;
      
      /// @brief Draw segment punctuation colon on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual auto draw_pc(xtd::drawing::graphics& graphics, const xtd::drawing::color& color) -> void;
      
      auto on_back_color_changed(const xtd::event_args& e) -> void override;
      
      auto on_enabled_changed(const xtd::event_args& e) -> void override;
      
      auto on_fore_color_changed(const xtd::event_args& e) -> void override;
      
      auto on_paint(xtd::forms::paint_event_args& e) -> void override;
      
      auto on_parent_enabled_changed(const xtd::event_args& e) -> void override;
      
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      
      auto set_bounds_core(xtd::int32 x, xtd::int32 y, xtd::int32 width, xtd::int32 height, xtd::forms::bounds_specified specified) -> void override;
      
      auto set_client_size_core(xtd::int32 width, xtd::int32 height) -> void override;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
