/// @file
/// @brief Contains xtd::drawing::region class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.h"
#include <xtd/object.h>
#include "drawing2d/graphics_path.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond
    
    /// @brief Describes the interior of a graphics shape composed of rectangles and paths. This class cannot be inherited.
    /// @code
    /// class drawing_export_ region final : public xtd::object
    /// @endcode
    /// @par Inheritance
    /// xtd::object → xtd::drawing::region
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks A region is scalable because its coordinates are specified in world coordinates. On a drawing surface, however, its interior is dependent on the size and shape of the pixels representing it. An application can use regions to clip the output of drawing operations. These regions are called clipping regions. For more information on using regions for clipping,
    /// @remarks An application can also use regions in hit-testing operations, such as checking whether a point or a rectangle intersects a region.
    /// @remarks An application can fill a region by using the xtd::drawing::graphics::fill_region method and a xtd::drawing::brush object.
    class drawing_export_ region final : public xtd::object {
    public:
      /// @name Constructors
      
      /// @{
      /// @brief Initializes a new Region.
      /// @remarks This constructor initializes a new xtd::drawing::region with an infinite interior.
      region();
      /// @brief Initializes a new xtd::drawing::region with the specified xtd::drawing::graphics_path.
      /// @param path A xtd::drawing::graphics_path that defines the new xtd::drawing::region.
      /// @remarks This method creates a new xtd::drawing::region with a xtd::drawing::graphics_path. The new region is defined as the interior of the xtd::drawing::graphics_path specified by the path parameter.
      region(const xtd::drawing::drawing2d::graphics_path& path);
      /// @brief Initializes a new xtd::drawing::region from the specified xtd::drawing::rectangle structure.
      /// @param rect A xtd::drawing::rectangle structure that defines the interior of the new xtd::drawing::region.
      /// @remarks This method creates a new xtd::drawing::region with a rectangular interior. The interior is defined by the rect parameter.
      region(const xtd::drawing::rectangle& rect);
      /// @brief Initializes a new xtd::drawing::region from the specified xtd::drawing::rectangle_f structure.
      /// @param rect A xtd::drawing::rectangle_f structure that defines the interior of the new xtd::drawing::region.
      /// @remarks This method creates a new xtd::drawing::region with a rectangular interior. The interior is defined by the rect parameter.
      region(const xtd::drawing::rectangle_f& rect);
      /// @}
      
      /// @cond
      region(const region& value) = default;
      region& operator=(const region& value) = default;
      ~region();
      bool operator==(const region& value) const;
      bool operator!=(const region& value) const;
      /// @endcond
      
      /// @name Properties
      
      /// @{
      /// @brief Gets the handle of the region.
      /// @return An intptr_t that contains the handle of the region.
      intptr_t handle() const;
      /// @}
      
      /// @name Methods
      
      /// @{
      /// @brief Updates this Region to contain the portion of the specified GraphicsPath that does not intersect with this Region.
      /// @param path The GraphicsPath to complement this Region.
      void complement(const xtd::drawing::drawing2d::graphics_path& path);
      /// @brief Updates this Region to contain the portion of the specified Rectangle structure that does not intersect with this Region.
      /// @param rect The Rectangle structure to complement this Region.
      void complement(const xtd::drawing::rectangle& rect);
      /// @brief Updates this Region to contain the portion of the specified RectangleF structure that does not intersect with this Region.
      /// @param rect The RectangleF structure to complement this Region.
      void complement(const xtd::drawing::rectangle_f& rect);
      /// @brief Updates this Region to contain the portion of the specified Region that does not intersect with this Region.
      /// @param region The Region object to complement this Region object.
      void complement(const xtd::drawing::region& region);
      
      /// @brief Updates this Region to contain only the portion of its interior that does not intersect with the specified GraphicsPath.
      /// @param path The GraphicsPath to exclude from this Region.
      void exclude(const xtd::drawing::drawing2d::graphics_path& path);
      /// @brief Updates this Region to contain only the portion of its interior that does not intersect with the specified Rectangle structure.
      /// @param rect The Rectangle structure to exclude from this Region.
      void exclude(const xtd::drawing::rectangle& rect);
      /// @brief The RectangleF structure to exclude from this Region.
      void exclude(const xtd::drawing::rectangle_f& rect);
      /// @brief Updates this Region to contain only the portion of its interior that does not intersect with the specified Region.
      /// @param region The Region to exclude from this Region.
      void exclude(const xtd::drawing::region& region);
      
      /// @brief Initializes a new Region from a handle to the specified existing GDI region.
      /// @param hrgn A handle to an existing Region.
      /// @return The new Region.
      /// @remarks This method creates a new Region with an interior defined by the existing Region referred to by the handle in the hrgn parameter.
      static xtd::drawing::region from_hrgn(intptr_t hrgn);
      
      /// @brief Gets a RectangleF structure that represents a rectangle that bounds this Region on the drawing surface of a Graphics object.
      /// @param g The Graphics on which this Region is drawn.
      /// @return A RectangleF structure that represents the bounding rectangle for this Region on the specified drawing surface.
      /// @remarks The current transformation of the graphics context is used to compute the region interior on the drawing surface. The bounding rectangle is not always the smallest possible bounding rectangle depending on the current transformation.
      xtd::drawing::rectangle_f get_bounds(const xtd::drawing::graphics& g) const;
      
      /// @brief Returns a Windows handle to this Region in the specified graphics context.
      /// @param The Graphics on which this Region is drawn.
      /// @return A Windows handle to this Region.
      /// @remarks You are responsible for calling the ReleaseHrgn method to free the memory used by the GDI region object.
      intptr_t get_hrgn(const xtd::drawing::graphics& g) const;

      void intersect(const xtd::drawing::drawing2d::graphics_path& path);
      void intersect(const xtd::drawing::rectangle& rect);
      void intersect(const xtd::drawing::rectangle_f& rect);
      void intersect(const xtd::drawing::region& region);

      void make_union(const xtd::drawing::drawing2d::graphics_path& path);
      void make_union(const xtd::drawing::rectangle& rect);
      void make_union(const xtd::drawing::rectangle_f& rect);
      void make_union(const xtd::drawing::region& region);

      void make_xor(const xtd::drawing::drawing2d::graphics_path& path);
      void make_xor(const xtd::drawing::rectangle& rect);
      void make_xor(const xtd::drawing::rectangle_f& rect);
      void make_xor(const xtd::drawing::region& region);
      /// @}
      
    private:
      struct data {
        intptr_t handle = 0;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
