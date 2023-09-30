/// @file
/// @brief Contains xtd::drawing::buffered_graphics_context class.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "buffered_graphics.h"
#include "graphics.h"
#include "point.h"
#include "size.h"
#include <xtd/optional>
#include <xtd/object>
#include <xtd/types>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Provides methods for creating graphics buffers that can be used for double buffering.
    /// @code
    /// class drawing_export_ buffered_graphics_context : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::buffered_graphics_context
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks The xtd::drawing::buffered_graphics_context class allows you to implement custom double buffering for your graphics. Graphics that use double buffering can reduce or eliminate flicker that is caused by redrawing a display surface.
    /// @note The simplest way to use double buffering is to set the xtd::forms::control_styles::optimized_double_buffer control style flag on a control using the xtd::forms::control::set_style method. Setting the xtd::forms::control_styles::optimized_double_buffer control styles flag for a control redirects all painting for the control through a default graphics buffer, without requiring any additional code. This flag is set to true by default.
    /// @remarks The xtd::drawing::buffered_graphics_context class provides methods for creating and configuring a graphics buffer. The xtd::drawing::buffered_graphics_context::allocate method creates a xtd::drawing::buffered_graphics, which is a wrapper for a graphics buffer that also provides methods you can use to write to the buffer and render its contents to an output device.
    /// @remarks You can retrieve the xtd::drawing::buffered_graphics_context for the current application domain from the static xtd::drawing::buffered_graphics_manager::current property. For graphically intensive applications such as animation, you can create a dedicated xtd::drawing::buffered_graphics_context using the constructor, but for most applications the xtd::drawing::buffered_graphics_manager::current property will be sufficient.
    class drawing_export_ buffered_graphics_context : public xtd::object {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new instance of the BufferedGraphicsContext class.
      /// @remarks For graphically intensive applications such as animation, you can sometimes improve performance by using a dedicated xtd::drawing::buffered_graphics_context instead of the default instance provided by the xtd::drawing::buffered_graphics_manager. This allows you to create and manage graphics buffers individually.
      buffered_graphics_context() = default;
      /// @}
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the maximum size of the buffer to use.
      /// @return A xtd::drawing::size indicating the maximum size of the buffer dimensions.
      /// @remarks This property allows you to get or set the maximum dimensions for a buffer that should be retained in memory. You can allocate a buffer of any size, however any buffer with dimensions greater than the xtd::drawing::buffered_graphics_context::MaximumBuffer size will be used temporarily and then discarded when the xtd::drawing::buffered_graphics object is released.
      const xtd::drawing::size& maximum_buffer() const noexcept;
      /// @brief Sets the maximum size of the buffer to use.
      /// @param value A xtd::drawing::size indicating the maximum size of the buffer dimensions.
      /// @exception xtd::argument_exception The height or width of the size is less than or equal to zero.
      /// @remarks This property allows you to get or set the maximum dimensions for a buffer that should be retained in memory. You can allocate a buffer of any size, however any buffer with dimensions greater than the xtd::drawing::buffered_graphics_context::MaximumBuffer size will be used temporarily and then discarded when the xtd::drawing::buffered_graphics object is released.
      buffered_graphics_context& maximum_buffer(const xtd::drawing::size& value);
      /// @}
      
      /// @name Methods
      
      /// @{
      void allocate(const xtd::drawing::graphics& target_graphics, const xtd::drawing::rectangle& targat_rectangle);
      void allocate(intptr target_dc, const xtd::drawing::rectangle& targat_rectangle);
      
      /// @brief Destroy of the current graphics buffer, if a buffer has been allocated and has not yet been destroyed.
      /// @remarks If the graphics buffer is in use, it will be marked for destroying as soon as it is free; otherwise, it will be destoyed immediately.
      void invalidate();
      /// @}
      
    private:
      //xtd::drawing::buffered_graphics alloc_buffer_in_temp_manager(const xtd::drawing::graphics* target_graphics, intptr target_dc, const xtd::drawing::rectangle& target_rectangle);
      //xtd::drawing::buffered_graphics allocate_buffer(const xtd::drawing::graphics* target_graphics, intptr target_dc, const xtd::drawing::rectangle& target_rectangle);
      void destroy();
      
      inline static const int BUFFER_FREE = 0; //the graphics buffer is free to use
      inline static const int BUFFER_BUSY_PAINTING = 1; //graphics buffer is busy being created/painting
      inline static const int BUFFER_BUSY_DESTROYING = 2; //graphics buffer is busy destroying
      
      xtd::drawing::buffered_graphics buffer_;
      xtd::drawing::size buffered_size_;
      int busy_ = BUFFER_FREE;
      xtd::drawing::graphics compat_graphics_;
      bool invalidate_when_free_ = false;
      xtd::drawing::size maximum_buffer_ {75 * 3, 32 * 3}; //by defualt, the size of our maxbuffer will be 3 x standard button size.
      xtd::drawing::point target_location_;
      xtd::drawing::size virtual_size_;
    };
  }
}
