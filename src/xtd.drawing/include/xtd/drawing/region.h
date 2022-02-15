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
      intptr_t handle() const;
      /// @}
      
      /// @name Methods
      
      /// @{
      xtd::drawing::rectangle_f get_bounds() const;
      
      void complement(const xtd::drawing::drawing2d::graphics_path& path);
      void complement(const xtd::drawing::rectangle& rect);
      void complement(const xtd::drawing::rectangle_f& rect);
      void complement(const xtd::drawing::region& region);
      
      void exclude(const xtd::drawing::drawing2d::graphics_path& path);
      void exclude(const xtd::drawing::rectangle& rect);
      void exclude(const xtd::drawing::rectangle_f& rect);
      void exclude(const xtd::drawing::region& region);
      
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
        xtd::drawing::rectangle_f bounds;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
