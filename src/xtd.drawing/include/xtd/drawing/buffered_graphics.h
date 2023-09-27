/// @file
/// @brief Contains xtd::drawing::buffered_graphics class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "graphics"
#include <xtd/optional>
#include <xtd/object>
#include <xtd/types>


/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Provides a graphics buffer for double buffering.
    /// @code
    /// class drawing_export_ buffered_graphics : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::buffered_graphics
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks The xtd::drawing::buffered_graphics class allows you to implement custom double buffering for your graphics. It provides a wrapper for a graphics buffer, along with methods that you can use to write to the buffer and render its contents to an output device.
    /// @remarks Graphics that use double buffering can reduce or eliminate flicker that is caused by redrawing a display surface. When you use double buffering, updated graphics are first drawn to a buffer in memory, and the contents of this buffer are then quickly written to some or all of the displayed surface. This relatively brief overwrite of the displayed graphics typically reduces or eliminates the flicker that sometimes occurs when graphics are updated.
    /// @note The simplest way to use double buffering is to set the xtd::forms::control_styles::optimized_double_buffer control style flag on a control using the xtd::control::set_style method. Setting the xtd::forms::control_styles::optimized_double_buffer flag for a control redirects all painting for the control through a default graphics buffer, without requiring any additional code. This flag is set to @verbatim true @endverbatim by default.
    /// @remarks The xtd::drawing::buffered_graphics class has no public constructor and must be created by the xtd::drawing::bffered_graphics_context for an application domain using its xtd::drawing::bffered_graphics_context::allocate method. You can retrieve the xtd::drawing::::buffered_graphics_context for the current application domain from the static xtd::drawing::buffered_graphics_manager::current property.
    /// @remarks The xtd::drawing::graphics property can be used for drawing to the graphics buffer. This property provides access to the xtd::drawing::graphics object that draws to the graphics buffer allocated for this xtd::drawing::buffered_graphics object.
    /// @remarks The xtd::drawing::buffered_graphics::render method with no arguments draws the contents of the graphics buffer to the surface specified when the buffer was allocated. Other overloads of the xtd::drawing::buffered_graphics::render method allow you to specify a xtd::drawing::graphics object or an xtd::intptr type that points to a device context to which to draw the contents of the graphics buffer.
    class drawing_export_ buffered_graphics : public xtd::object {
    public:
      /// @name Properties
      
      /// @{
      /// @brief Gets a xtd::drawing::graphics object that outputs to the graphics buffer.
      /// @return A xtd::drawing::graphics object that outputs to the graphics buffer.
      /// @remarks This property provides a xtd::drawing::graphics object that draws to the graphics buffer allocated for this xtd::drawing::buffered_graphics object.
      const xtd::drawing::graphics& graphics() const noexcept;
      xtd::drawing::graphics& graphics() noexcept;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Writes the contents of the graphics buffer to the default device.
      /// @remarks This method writes the contents of the graphics buffer to the device specified by calling the xtd::drawing::bffered_graphics_context::allocate method of the xtd::drawing::bffered_graphics_context used to create this xtd::drawing::bffered_graphics object.
      void render();
      /// @brief Writes the contents of the graphics buffer to the specified xtd::drawing::graphics object.
      /// @param target A xtd::drawing::graphics object to which to write the contents of the graphics buffer.
      /// @remarks This method writes the contents of the graphics buffer to the specified xtd::drawing::graphics object.
      void render(xtd::drawing::graphics& target);
      /// @brief Writes the contents of the graphics buffer to the device context associated with the specified intptr handle.
      /// @param target_dc An intptr that points to the device context to which to write the contents of the graphics buffer.
      /// @remarks This method writes the contents of the graphics buffer to the device context associated with the specified intptr handle.
      void render(intptr target_dc);
      /// @}
      
    protected:
      buffered_graphics(const xtd::drawing::graphics& buffered_graphics_surface, std::optional<xtd::drawing::graphics> target_graphics, intptr target_dc, const xtd::drawing::point& target_location, xtd::drawing::size virtual_size);
      
    private:
      xtd::drawing::graphics buffered_graphics_surface_;
      intptr target_dc_ = 0;
      std::optional<xtd::drawing::graphics> target_graphics_;
      xtd::drawing::point target_location_;
      xtd::drawing::size virtual_size_;
    };
  }
}
