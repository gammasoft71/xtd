/// @file
/// @brief Contains xtd::forms::seven_segment_display control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "application.h"
#include "control.h"
#include "segments.h"
#include "segment_style.h"
#include <xtd/argument_out_of_range_exception>
#include <xtd/drawing/system_colors>

namespace xtd {
  namespace forms {
    /// @brief Represents a seven segment display class.
    /// @par Header
    /// @code #include <xtd/forms/seven_segment_display> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                            | macOS                                              | Gnome                                              |
    /// | ----- | -------------------------------------------------- | -------------------------------------------------- | -------------------------------------------------- |
    /// | Light |  @image html control_seven_segment_display_w.png   |  @image html control_seven_segment_display_m.png   |  @image html control_seven_segment_display_g.png   |
    /// | Dark  |  @image html control_seven_segment_display_wd.png  |  @image html control_seven_segment_display_md.png  |  @image html control_seven_segment_display_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of seven segment display control.
    /// @include seven_segment_display.cpp
    class seven_segment_display : public control {
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
      virtual drawing::color back_segment_color() const noexcept;
      /// @brief Sets background segment color.
      /// @param value A xtd::drawing color that represent the background segment color.
      /// @return Current seven_segment_display.
      /// @remarks Do not confuse back_segment_color and back_color. Background segment color is the color when segment is off.
      virtual seven_segment_display& back_segment_color(const drawing::color& value);
      
      /// @brief Gets the background segment opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the background segment opacity.
      virtual double back_segment_opacity() const noexcept;
      /// @brief Sets the background segment opacity.
      /// @param value A double-precision value between 0.0 and 1.0 that represent the background segment opacity.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.0 or greater than 1.0.
      /// @return Current seven_segment_display.
      virtual seven_segment_display& back_segment_opacity(double value);
      
      /// @brief Gets a value indicate if background segments are shown.
      /// @return true if background segments are shown; otherwise false
      virtual bool show_back_segment() const noexcept;
      /// @brief Sets a value indicate if background segments are shown.
      /// @param value true if background segments are shown; otherwise false
      /// @return Current seven_segment_display.
      virtual seven_segment_display& show_back_segment(bool value);
      
      /// @brief Gets segment style.
      /// @return One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      virtual forms::segment_style segment_style() const noexcept;
      /// @brief Sets segment style.
      /// @param value One of xtd::forms::segment_style values. The default is xtd::forms::segment_style::standard.
      /// @return Current seven_segment_display.
      virtual seven_segment_display& segment_style(forms::segment_style value);
      
      /// @brief Gets thickness of segment.
      /// @return A int32 that represent the segment thickness.
      virtual int32 thickness() const noexcept;
      /// @brief Sets thickness of segment.
      /// @param value A int32 that represent the segment thickness.
      /// @return Current seven_segment_display.
      virtual seven_segment_display& thickness(int32 value);
      
      /// @brief Gets seven_segment_display value.
      /// @return A xtd::forms::segments combination that represent seven_segment_display.
      virtual forms::segments value() const noexcept;
      /// @brief Sets seven_segment_display value.
      /// @param value A xtd::forms::segments combination that represent seven_segment_display.
      /// @return Current seven_segment_display.
      virtual seven_segment_display& value(forms::segments value);
      /// @}

      /// @name Public Methods
      
      /// @{
      /// @brief Gets if specified xtd::forms::segments combination is on.
      /// @return true if xtd::forms::segments combination is on; otherwise false.
      virtual bool get_segments(forms::segments segment) const noexcept;
      /// @brief Sets specified xtd::forms::segments combination to on.
      /// @param segment A xtd::forms::segments combination to set.
      /// @param on true to set to on; otherwise false.
      virtual void set_segments(forms::segments segment, bool value);
      /// @}

      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create();
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments.
      /// @param segments A dots_collection that represent all dots status.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(xtd::forms::segments segments);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, and location.
      /// @param segments A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(xtd::forms::segments segments, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, location, and size.
      /// @param segments A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, location, size, and name.
      /// @param segments A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, and back_segment visibility.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(xtd::forms::segments segments, bool show_back_segment);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, back_segment visibility, and location.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, back_segment visibility, location, and size.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified segments, back_segment visibility, location, size, and name.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, xtd::forms::segments segments);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, and location.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, xtd::forms::segments segments, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, and back_segment visibility.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, xtd::forms::segments segments, bool show_back_segment);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, back_segment visibility, and location.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, back_segment visibility, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::seven_segment_display with specified parent, segments, back_segment visibility, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::seven_segment_display.
      /// @param segments A xtd::forms::segments combination that represent seven_segment_display.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::seven_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::seven_segment_display.
      /// @param name The name of the xtd::forms::seven_segment_display.
      /// @return New xtd::forms::seven_segment_display created.
      static seven_segment_display create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      drawing::size default_size() const noexcept override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{
      /// @brief Creates a new object that is a copy of the current instance.
      /// @return A new object that is a copy of this instance.
      /// @par Notes to Implementers
      /// All controls must be override the clone method.
      std::unique_ptr<xtd::object> clone() const override;
      
      /// @brief Draw all background digit on specified graphics.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      virtual void draw_back_digit(drawing::graphics& graphics);
      
      /// @brief Draw segment a on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_a(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment b on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_b(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment c on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_c(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment d on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_d(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment e on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_e(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment f on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_f(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment g on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_g(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment dot point on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_dp(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment punctuation colon on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_pc(drawing::graphics& graphics, const drawing::color& color);

      void on_back_color_changed(const event_args& e) override;
      
      void on_enabled_changed(const event_args& e) override;
      
      void on_fore_color_changed(const event_args& e) override;
      
      void on_paint(paint_event_args& e) override;
      
      void on_parent_enabled_changed(const event_args& e) override;
      
      drawing::size measure_control() const noexcept override;
      
      void set_bounds_core(int32 x, int32 y, int32 width, int32 height, bounds_specified specified) override;
      
      void set_client_size_core(int32 width, int32 height) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
