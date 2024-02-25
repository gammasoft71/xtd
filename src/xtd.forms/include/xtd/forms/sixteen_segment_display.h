/// @file
/// @brief Contains xtd::forms::sixteen_segment_display control.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "fourteen_segment_display.h"

namespace xtd {
  namespace forms {
    /// @brief Represents a sixteen segment display class.
    /// @par Header
    /// @code #include <xtd/forms/sixtenn_segment_display> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                              | macOS                                                | Gnome                                                |
    /// | ----- | ---------------------------------------------------- | ---------------------------------------------------- | ---------------------------------------------------- |
    /// | Light |  @image html control_sixteen_segment_display_w.png   |  @image html control_sixteen_segment_display_m.png   |  @image html control_sixteen_segment_display_g.png   |
    /// | Dark  |  @image html control_sixteen_segment_display_wd.png  |  @image html control_sixteen_segment_display_md.png  |  @image html control_sixteen_segment_display_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of sixteen segment display control.
    /// @include sixteen_segment_display.cpp
    class sixteen_segment_display : public fourteen_segment_display {
      struct data;
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of sixteen_segment_display class.
      sixteen_segment_display();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Sets thickness of segment.
      /// @param value A int32 that represent the segment thickness.
      /// @return Current seven_segment_display.
      int32 thickness() const noexcept override;
      /// @brief Sets thickness of segment.
      /// @param value A int32 that represent the segment thickness.
      /// @return Current seven_segment_display.
      seven_segment_display& thickness(int32 value) override;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create();
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const drawing::point& location);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @param name The name of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified segments.
      /// @param segments A dots_collection that represent all dots status.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(xtd::forms::segments segments);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified segments, and location.
      /// @param segments A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(xtd::forms::segments segments, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified segments, location, and size.
      /// @param segments A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified segments, location, size, and name.
      /// @param segments A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @param name The name of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified segments, and back_segment visibility.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(xtd::forms::segments segments, bool show_back_segment);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified segments, back_segment visibility, and location.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified segments, back_segment visibility, location, and size.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified segments, back_segment visibility, location, size, and name.
      /// @param segments A dots_collection that represent all dots status.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @param name The name of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @param name The name of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, segments.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param segments A xtd::forms::segments combination that represent sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, xtd::forms::segments segments);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, segments, and location.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param segments A xtd::forms::segments combination that represent sixteen_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, xtd::forms::segments segments, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, segments, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param segments A xtd::forms::segments combination that represent sixteen_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, segments, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param segments A xtd::forms::segments combination that represent sixteen_segment_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @param name The name of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, xtd::forms::segments segments, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, segments, and back_segment visibility.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param segments A xtd::forms::segments combination that represent sixteen_segment_display.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, xtd::forms::segments segments, bool show_back_segment);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, segments, back_segment visibility, and location.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param segments A xtd::forms::segments combination that represent sixteen_segment_display.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, segments, back_segment visibility, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param segments A xtd::forms::segments combination that represent sixteen_segment_display.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size);
      /// @brief A factory to create an xtd::forms::sixteen_segment_display with specified parent, segments, back_segment visibility, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::sixteen_segment_display.
      /// @param segments A xtd::forms::segments combination that represent sixteen_segment_display.
      /// @param show_back_segment true if background segments are shown; otherwise false
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::sixteen_segment_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::sixteen_segment_display.
      /// @param name The name of the xtd::forms::sixteen_segment_display.
      /// @return New xtd::forms::sixteen_segment_display created.
      static sixteen_segment_display create(const control& parent, xtd::forms::segments segments, bool show_back_segment, const drawing::point& location, const drawing::size& size, const xtd::ustring& name);
      /// @}
      
    protected:
      /// @name Protected methods
      
      /// @{
      void draw_back_digit(drawing::graphics& graphics) override;
      
      void draw_segment_a(drawing::graphics& graphics, const drawing::color& color) override;
      
      /// @brief Draw segment a1 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_a1(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment a2 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_a2(drawing::graphics& graphics, const drawing::color& color);
      
      void draw_segment_d(drawing::graphics& graphics, const drawing::color& color) override;
      
      /// @brief Draw segment d1 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_d1(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment d2 on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      virtual void draw_segment_d2(drawing::graphics& graphics, const drawing::color& color);
      
      /// @brief Draw segment i on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      void draw_segment_i(drawing::graphics& graphics, const drawing::color& color) override;
      
      /// @brief Draw segment l on specified graphics with specified color.
      /// @param graphics A xtd::drawing::graphics from on_paint method.
      /// @param color A xtd::drawing::color used to draw segment.
      void draw_segment_l(drawing::graphics& graphics, const drawing::color& color) override;
      
      void on_paint(paint_event_args& e) override;
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
