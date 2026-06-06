/// @file
/// @brief Contains xtd::forms::dot_matrix_display control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "control.hpp"
#include "segments.hpp"
#include "dot_matrix_style.hpp"
#include <xtd/drawing/solid_brush>
#include <xtd/argument_out_of_range_exception>
#include <array>

namespace xtd {
  namespace forms {
    /// @brief Represents a dot matrix display class.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/dot_matrix_display>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms controls
    /// @par Appearance
    /// |       | Windows                                         | macOS                                           | Gnome                                           |
    /// | ----- | ----------------------------------------------- | ----------------------------------------------- | ----------------------------------------------- |
    /// | Light |  @image html control_dot_matrix_display_w.png   |  @image html control_dot_matrix_display_m.png   |  @image html control_dot_matrix_display_g.png   |
    /// | Dark  |  @image html control_dot_matrix_display_wd.png  |  @image html control_dot_matrix_display_md.png  |  @image html control_dot_matrix_display_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of dot matrix display control.
    /// @include dot_matrix_display.cpp
    class dot_matrix_display : public xtd::forms::control {
      struct data;
      
    public:
      /// @name Public Aliases
      
      /// @{
      /// @brief Represents a dots collection.
      using dots_collection = xtd::array<xtd::array<bool>>;
      
      /// @brief Represents a point collection.
      using points_collection = xtd::array<xtd::drawing::point>;
      /// @}
      
      /// @name Public Constructors
      
      /// @{
      /// @brief Initialize a new instance of dot_matrix_display class.
      dot_matrix_display();
      /// @}
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets background dot color.
      /// @return A xtd::drawing color that represent the background dot color.
      /// @remarks Do not confuse back_dot_color and back_color. Background dot color is the color when dot is off.
      [[nodiscard]] virtual auto back_dot_color() const noexcept -> xtd::drawing::color;
      /// @brief Sets background dot color.
      /// @param value A xtd::drawing color that represent the background dot color.
      /// @return Current dot_matrix_display.
      /// @remarks Do not confuse back_dot_color and back_color. Background dot color is the color when dot is off.
      virtual auto back_dot_color(const xtd::drawing::color& value) -> dot_matrix_display&;
      
      /// @brief Gets the background dot opacity.
      /// @return A double-precision value between 0.0 and 1.0 that represent the background dot opacity.
      [[nodiscard]] virtual auto back_dot_opacity() const noexcept -> double;
      /// @brief Sets the background dot opacity.
      /// @param value A double-precision value between 0.0 and 1.0 that represent the background dot opacity.
      /// @exception xtd::argument_out_of_range_exception if value less than 0.0 or greater than 1.0.
      /// @return Current dot_matrix_display.
      virtual auto back_dot_opacity(double value) -> dot_matrix_display&;
      
      /// @brief Gets dot matrix style.
      /// @return One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      [[nodiscard]] virtual auto dot_matrix_style() const noexcept -> xtd::forms::dot_matrix_style;
      /// @brief Sets dot matrix style.
      /// @param value One of xtd::forms::dot_matrix_style values. The default is xtd::forms::dot_matrix_style::standard.
      /// @return Current dot_matrix_display.
      virtual auto dot_matrix_style(xtd::forms::dot_matrix_style value) -> dot_matrix_display&;
      
      /// @brief Gets all dots status.
      /// @return A dots_collection that represent all dots status.
      [[nodiscard]] virtual auto dots() const noexcept -> const dots_collection&;
      /// @brief Sets all dots status.
      /// @param value A dots_collection that represent all dots status.
      /// @return Current dot_matrix_display.
      virtual auto dots(const dots_collection& value) -> dot_matrix_display&;
      
      /// @brief Gets the matrix size. Number of height dots.
      /// @return A int32 represent the height dots of the matrix. The default is 7.
      [[nodiscard]] virtual auto matrix_height() const noexcept -> xtd::int32;
      /// @brief Sets the matrix size. Number of height dots.
      /// @param value A int32 represent the height dots of the matrix. The default is 7.
      /// @return Current dot_matrix_display.
      virtual auto matrix_height(xtd::int32 value) -> dot_matrix_display&;
      
      /// @brief Gets the matrix size. Number height dots.
      /// @return A int32 that represent the width dots of the matrix. The default is 7.
      [[nodiscard]] virtual auto matrix_width() const noexcept -> xtd::int32;
      /// @brief Sets the matrix size. Number height dots.
      /// @param value A int32 that represent the width dots of the matrix. The default is 7.
      /// @return Current dot_matrix_display.
      virtual auto matrix_width(xtd::int32 value) -> dot_matrix_display&;
      
      /// @brief Gets the matrix size. Number of width and height dots.
      /// @return A xtd::drawing::point that represent the width and height dots of the matrix. The default is {7, 7}.
      [[nodiscard]] virtual auto matrix_size() const noexcept -> const xtd::drawing::size&;
      /// @brief Gets the matrix size. Number of width and height dots.
      /// @param value A xtd::drawing::point that represent the width and height dots of the matrix. The default is {7, 7}. The default is {7, 7}.
      /// @return Current dot_matrix_display.
      virtual auto matrix_size(const xtd::drawing::size& value) -> dot_matrix_display&;
      
      /// @brief Gets a value indicate if background dots are shown.
      /// @return `true` if background dots are shown; otherwise `false`.
      [[nodiscard]] virtual auto show_back_dot() const noexcept -> bool;
      /// @brief Sets a value indicate if background dots are shown.
      /// @param value `true` if background dots are shown; otherwise `false`.
      /// @return Current dot_matrix_display.
      virtual auto show_back_dot(bool value) -> dot_matrix_display&;
      
      /// @brief Gets thickness of dot.
      /// @return A int32 that represent the dot thickness.
      [[nodiscard]] virtual auto thickness() const noexcept -> xtd::int32;
      /// @brief Sets thickness of dot.
      /// @param value A int32 that represent the dot thickness.
      /// @return Current dot_matrix_display.
      virtual auto thickness(xtd::int32 value) -> dot_matrix_display&;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Gets specified dot point status.
      /// @param point dot point location in the matrix.
      /// @return `true` if specified dot point is on; otherwise `false`.
      [[nodiscard]] virtual auto get_dot(const xtd::drawing::point& point) const noexcept -> bool;
      
      /// @brief Sets all dots with specified boolean.
      /// @param on `true` to set all dots to on; otherwise `false`.
      virtual auto set_all_dots(bool on) -> void;
      
      /// @brief Sets specified dot point status.
      /// @param point dot point location in the matrix.
      /// @param on `true` if specified dot point is on; otherwise `false`.
      virtual auto set_dot(const xtd::drawing::point& point, bool on) -> void;
      
      /// @brief Sets specified dots to on.
      /// @param points Dot points collection tha contains locations in the matrix.
      virtual auto set_dots(const points_collection& points) -> void;
      /// @brief Sets specified dots with specified boolean.
      /// @param points Dot points collection tha contains locations in the matrix.
      /// @param on `true` to set specified dots points to on; otherwise `false`.
      virtual auto set_dots(const points_collection& points, bool on) -> void;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief A factory to create an xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create() -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified location.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified location, and size.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified location, size, and name.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @param name The name of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified dots.
      /// @param dots A dots_collection that represent all dots status.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const dots_collection& dots) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified dots, and location.
      /// @param dots A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const dots_collection& dots, const xtd::drawing::point& location) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified dots, location, and size.
      /// @param dots A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const dots_collection& dots, const xtd::drawing::point& location, const xtd::drawing::size& size) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified dots, location, size, and name.
      /// @param dots A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @param name The name of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const dots_collection& dots, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified dots, and back_dot visibility.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot `true` if background dots are shown; otherwise `false`.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const dots_collection& dots, bool show_back_dot) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified dots, back_dot visibility, and location.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot `true` if background dots are shown; otherwise `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const dots_collection& dots, bool show_back_dot, const xtd::drawing::point& location) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified dots, back_dot visibility, location, and size.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot `true` if background dots are shown; otherwise `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const dots_collection& dots, bool show_back_dot, const xtd::drawing::point& location, const xtd::drawing::size& size) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified dots, back_dot visibility, location, size, and name.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot `true` if background dots are shown; otherwise `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @param name The name of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const dots_collection& dots, bool show_back_dot, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, and location.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const xtd::drawing::point& location) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @param name The name of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, and dots.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param dots A dots_collection that represent all dots status.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const dots_collection& dots) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, dots, and location.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param dots A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const dots_collection& dots, const xtd::drawing::point& location) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, dots, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param dots A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const dots_collection& dots, const xtd::drawing::point& location, const xtd::drawing::size& size) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, dots, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param dots A dots_collection that represent all dots status.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @param name The name of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const dots_collection& dots, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, dots, and back_dot visibility.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot `true` if background dots are shown; otherwise `false`.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const dots_collection& dots, bool show_back_dot) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, dots, back_dot visibility, and location.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot `true` if background dots are shown; otherwise `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const dots_collection& dots, bool show_back_dot, const xtd::drawing::point& location) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, dots, back_dot visibility, location, and size.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot `true` if background dots are shown; otherwise `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const dots_collection& dots, bool show_back_dot, const xtd::drawing::point& location, const xtd::drawing::size& size) -> dot_matrix_display;
      /// @brief A factory to create an xtd::forms::dot_matrix_display with specified parent, dots, back_dot visibility, location, size, and name.
      /// @param parent The parent that contains the new created xtd::forms::dot_matrix_display.
      /// @param dots A dots_collection that represent all dots status.
      /// @param show_back_dot `true` if background dots are shown; otherwise `false`.
      /// @param location A xtd::drawing::point that represent location of the xtd::forms::dot_matrix_display.
      /// @param size A xtd::drawing::size that represent size of the xtd::forms::dot_matrix_display.
      /// @param name The name of the xtd::forms::dot_matrix_display.
      /// @return New xtd::forms::dot_matrix_display created.
      [[nodiscard]] static auto create(const control& parent, const dots_collection& dots, bool show_back_dot, const xtd::drawing::point& location, const xtd::drawing::size& size, const xtd::string& name) -> dot_matrix_display;
      /// @}
      
    protected:
      /// @name Protected Properties
      
      /// @{
      [[nodiscard]] auto default_size() const noexcept -> xtd::drawing::size override;
      /// @}
      
      /// @name Protected Methods
      
      /// @{      
      auto on_back_color_changed(const event_args& e) -> void override;
      
      auto on_fore_color_changed(const event_args& e) -> void override;
      
      auto on_paint(paint_event_args& e) -> void override;
      
      [[nodiscard]] auto measure_control() const noexcept -> xtd::drawing::size override;
      
      /// @brief Draw specified dot point with specified color on specified graphics.
      /// @param graphics Define the control graphics where draw the specified dot point.
      /// @param color The dot color to draw.
      /// @param point The dot point location in the matrix.
      virtual auto draw_dot(drawing::graphics& graphics, const xtd::drawing::color& color, const xtd::drawing::point& point) -> void;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
