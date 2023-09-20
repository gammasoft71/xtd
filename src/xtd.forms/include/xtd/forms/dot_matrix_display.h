/// @file
/// @brief Contains xtd::forms::dot_matrix_display control.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include <array>
#include <xtd/argument_out_of_range_exception.h>
#include <xtd/drawing/solid_brush.h>
#include "control.h"
#include "segments.h"
#include "dot_matrix_style.h"

namespace xtd {
  namespace forms {
    /// @brief Represents a dot matrix display class.
    /// @par Header
    /// @code #include <xtd/forms/dot_matrix_display> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                         | macOS                                           | Gnome                                           |
    /// | ----- | ----------------------------------------------- | ----------------------------------------------- | ----------------------------------------------- |
    /// | Light |  @image html control_dot_matrix_display_w.png   |  @image html control_dot_matrix_display_m.png   |  @image html control_dot_matrix_display_g.png   |
    /// | Dark  |  @image html control_dot_matrix_display_wd.png  |  @image html control_dot_matrix_display_md.png  |  @image html control_dot_matrix_display_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of dot matrix display control.
    /// @include dot_matrix_display.cpp
    class dot_matrix_display : public control {
      struct data;
      
    public:
      /// @name Alias
      
      /// @{
      /// @brief Represents a dots collection.
      using dots_collection =  std::vector<std::vector<bool>>;
      
      /// @brief Represents a point collection.
      using points_collection =  std::vector<xtd::drawing::point>;
      /// @}
      
      /// @name Constructors
      
      /// @{
      /// @brief Initialize a new instance of dot_matrix_display class.
      dot_matrix_display();
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets background dot color.
      /// @return A xtd::drawing color that represent the background dot color.
      /// @remarks Do not confuse back_dot_color and back_color. Background dot color is the color when dot is off.
      virtual drawing::color back_dot_color() const noexcept;
      /// @brief Sets background dot color.
      /// @param value A xtd::drawing color that represent the background dot color.
      /// @return Current dot_matrix_display.
      /// @remarks Do not confuse back_dot_color and back_color. Background dot color is the color when dot is off.
      virtual dot_matrix_display& back_dot_color(const drawing::color& value);
      
      /// @brief Gets the background dot opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the background dot opacity.
      virtual double back_dot_opacity() const noexcept;
      /// @brief Sets the background dot opacity.
      /// @param value A double-precision value between 0.0 and 1.0 that represent the background dot opacity.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.0 or greater than 1.0.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& back_dot_opacity(double value);
      
      /// @brief Gets dot matrix style.
      /// @return One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      virtual forms::dot_matrix_style dot_matrix_style() const noexcept;
      /// @brief Sets dot matrix style.
      /// @param value One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& dot_matrix_style(forms::dot_matrix_style value);
      
      /// @brief Gets all dots status.
      /// @return A dots_collection that represent all dots status.
      virtual const dots_collection& dots() const noexcept;
      /// @brief Sets all dots status.
      /// @param dots A dots_collection that represent all dots status.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& dots(const dots_collection& dots);
      
      /// @brief Gets the matrix size. Number of height dots.
      /// @return A int32 represent the height dots of the matrix. The default is 7.
      virtual int32 matrix_height() const noexcept;
      /// @brief Sets the matrix size. Number of height dots.
      /// @param value A int32 represent the height dots of the matrix. The default is 7.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& matrix_height(int32 value);
      
      /// @brief Gets the matrix size. Number height dots.
      /// @return A int32 that represent the width dots of the matrix. The default is 7.
      virtual int32 matrix_width() const noexcept;
      /// @brief Sets the matrix size. Number height dots.
      /// @param value A int32 that represent the width dots of the matrix. The default is 7.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& matrix_width(int32 value);
      
      /// @brief Gets the matrix size. Number of width and height dots.
      /// @return A xtd::drawing::point that represent the width and height dots of the matrix. The default is {7, 7}.
      virtual const drawing::size& matrix_size() const noexcept;
      /// @brief Gets the matrix size. Number of width and height dots.
      /// @param value A xtd::drawing::point that represent the width and height dots of the matrix. The default is {7, 7}. The default is {7, 7}.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& matrix_size(const drawing::size& value);
      
      /// @brief Gets a value indicate if background dots are shown.
      /// @return true if background dots are shown; otherwise false.
      virtual bool show_back_dot() const noexcept;
      /// @brief Sets a value indicate if background dots are shown.
      /// @param value true if background dots are shown; otherwise false.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& show_back_dot(bool value);
      
      /// @brief Gets thickness of dot.
      /// @return A int32 that represent the dot thickness.
      virtual int32 thickness() const noexcept;
      /// @brief Sets thickness of dot.
      /// @param value A int32 that represent the dot thickness.
      /// @return Current dot_matrix_display.
      virtual dot_matrix_display& thickness(int32 value);
      /// @}
      
      /// @name Methods
      
      /// @{
      using control::create;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified color, location, size, and name.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot true if background dots are shown; otherwise false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @param name The name of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      static dot_matrix_display create(const dots_collection& dots, bool show_back_dot = true, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, color, location ,size, and name.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot true if background dots are shown; otherwise false.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @param name The name of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      static dot_matrix_display create(const control& parent, const dots_collection& dots, bool show_back_dot = true, const drawing::point& location = {-1, -1}, const drawing::size& size = {-1, -1}, const xtd::ustring& name = xtd::ustring::empty_string);
      
      /// @brief Gets specified dot point status.
      /// @param point dot point location in the matrix.
      /// @return true if specified dot point is on; otherwise false.
      virtual bool get_dot(const drawing::point& point) const noexcept;
      
      /// @brief Sets all dots with specified boolean.
      /// @param on true to set all dots to on; otherwise false.
      virtual void set_all_dots(bool on);
      
      /// @brief Sets specified dot point status.
      /// @param point dot point location in the matrix.
      /// @param on true if specified dot point is on; otherwise false.
      virtual void set_dot(const drawing::point& point, bool on);
      
      /// @brief Sets specified dots to on.
      /// @param points Dot points collection tha contains locations in the matrix.
      virtual void set_dots(const points_collection& points);
      /// @brief Sets specified dots with specified boolean.
      /// @param points Dot points collection tha contains locations in the matrix.
      /// @param on true to set specified dots points to on; otherwise false.
      virtual void set_dots(const points_collection& points, bool on);
      /// @}
      
    protected:
      /// @name Protected properties
      
      /// @{
      xtd::drawing::size default_size() const noexcept override;
      /// @}
      
      /// @name Protected methods
      
      /// @{
      void on_back_color_changed(const event_args& e) override;
      
      void on_fore_color_changed(const event_args& e) override;
      
      void on_paint(paint_event_args& e) override;
      
      drawing::size measure_control() const noexcept override;
      
      /// @brief Draw specified dot point with specified color on specified graphics.
      /// @param graphics Define the control graphics where draw the specified dot point.
      /// @param color The dot color to draw.
      /// @param point The dot point location in the matrix.
      virtual void draw_dot(drawing::graphics& graphics, const drawing::color& color, const drawing::point& point);
      /// @}
      
    private:
      std::shared_ptr<data> data_;
    };
  }
}
