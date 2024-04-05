#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <xtd/static.h>
#include <xtd/types.h>
#include <xtd/drawing_native_export.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class region;
    /// @endcond
    
    /// @brief The xtd::drawing::native namespace contains internal native API definitions to access underlying toolkits used by xtd.drawing library.
    /// @warning Internal use only
    namespace native {
      /// @brief Contains region native API.
      /// @par Namespace
      /// xtd::drawing::native
      /// @par Library
      /// xtd.drawing.native
      /// @ingroup xtd_drawing_native native
      /// @warning Internal use only
      class drawing_native_export_ region final static_ {
        friend xtd::drawing::region;
      protected:
        /// @name Protected Static Methods
        
        /// @{
        /// @brief Creates a region with an infinite interior.
        /// @return The created region handle.
        /// @warning Internal use only
        static intptr create();
        
        /// @brief Creates a region from the specified rectangle.
        /// @param x A x-coordinate of rectangle that defines the interior of the region.
        /// @param y A y-coordinate of rectangle that defines the interior of the region.
        /// @param width A width of rectangle that defines the interior of the region.
        /// @param height A height of rectangle that defines the interior of the region.
        /// @return The created region handle.
        /// @warning Internal use only
        static intptr create_from_rect(float x, float y, float width, float height);
        
        /// @brief Creates a region with the specified graphics path.
        /// @param path A graphics path handle that defines the region.
        /// @return The created region handle.
        /// @warning Internal use only
        static intptr create_from_graphics_path(intptr path);
        
        /// @brief Destroys the region.
        /// @param handle The region handle to destroy.
        /// @warning Internal use only
        static void destroy(intptr handle);
        
        /// @brief Updates thie region to contain the portion of the specified region that does not intersect with the region.
        /// @param handle The region handle.
        /// @param region The region handle to complement the region.
        /// @warning Internal use only
        static void complement(intptr handle, intptr region);
        
        /// @brief Updates the region to contain only the portion of its interior that does not intersect with the specified region.
        /// @param handle The region handle.
        /// @param region The region handle to exclude from the region.
        /// @warning Internal use only
        static void exclude(intptr handle, intptr region);
        
        /// @brief Creates a region from a handle to the specified existing GDI region.
        /// @param hrgn A handle to an existing region.
        /// @return The created region handle.
        /// @warning Internal use only
        static intptr from_hrgn(intptr hrgn);
        
        /// @brief Gets a rectangle that represents a rectangle that bounds in pixels the region.
        /// @param handle The region handle.
        /// @param x The x-coordinate of rectangle that represents the bounding rectangle in pixels for the region.
        /// @param y The y-coordinate of rectangle that represents the bounding rectangle in pixels for the region.
        /// @param width The width of rectangle that represents the bounding rectangle in pixels for the region.
        /// @param height The height of rectangle that represents the bounding rectangle in pixels for the region.
        /// @warning Internal use only
        static void get_bounds(intptr handle, float& x, float& y, float& width, float& height);
        
        /// @brief Returns a Windows handle to the region in the specified graphics context.
        /// @param handle The region handle.
        /// @param graphics The graphics handle on which the region is drawn.
        /// @return A Windows handle to the region.
        /// @warning Internal use only
        static intptr get_hrgn(intptr handle, intptr grpahics);
        
        /// @brief Updates the region to the intersection of itself with the specified region.
        /// @param handle The region handle.
        /// @param region The region handle to intersect with the region.
        /// @warning Internal use only
        static void intersect(intptr handle, intptr region);
        
        /// @brief Tests whether the region has an empty interior.
        /// @param handle The region handle.
        /// @return true if the interior of the region is empty; otherwise, false.
        /// @warning Internal use only
        static bool is_empty(intptr handle);
        /// @brief Tests whether the region has an empty interior on the specified drawing surface.
        /// @param handle The region handle.
        /// @param graphics A graphics handle that represents a drawing surface.
        /// @return true if the interior of the region is empty when the transformation associated with graphics is applied; otherwise, false.
        /// @warning Internal use only
        static bool is_empty(intptr handle, intptr grpahics);
        
        /// @brief Tests whether the region has an infinite interior.
        /// @param handle The region handle.
        /// @return true if the interior of the region is infinite; otherwise, false.
        /// @warning Internal use only
        static bool is_infinite(intptr handle);
        /// @brief Tests whether the region has an infinite interior on the specified drawing surface.
        /// @param handle The region handle.
        /// @param graphics A graphics handle that represents a drawing surface.
        /// @return true if the interior of the region is infinite when the transformation associated with graphics is applied; otherwise, false.
        /// @warning Internal use only
        static bool is_infinite(intptr handle, intptr grpahics);
        
        /// @brief Tests whether the specified point is contained within the region when drawn using the specified graphics.
        /// @param handle The region handle.
        /// @param x The x-coordinate of the point to test.
        /// @param y The y-coordinate of the point to test.
        /// @return true when the specified point is contained within the region; otherwise, false.
        /// @warning Internal use only
        static bool is_visible(intptr handle, float x, float y);
        /// @brief Tests whether the specified point is contained within the region when drawn using the specified graphics.
        /// @param handle The region handle.
        /// @param x The x-coordinate of the point to test.
        /// @param y The y-coordinate of the point to test.
        /// @param graphics The graphics handle that represents a draing surface.
        /// @return true when the specified point is contained within the region; otherwise, false.
        /// @warning Internal use only
        static bool is_visible(intptr handle, float x, float y, intptr grpahics);
        /// @brief Tests whether any portion of the specified rectangle is contained within the region.
        /// @param handle The region handle.
        /// @param x The x-coordinate of the upper-left corner of the rectangle to test.
        /// @param y The y-coordinate of the upper-left corner of the rectangle to test.
        /// @param width The width of the rectangle to test.
        /// @param height The height of the rectangle to test.
        /// @return true when any portion of the specified rectangle is contained within the region; otherwise, false.
        /// @warning Internal use only
        static bool is_visible(intptr handle, float x, float y, float width, float height);
        /// @brief Tests whether any portion of the specified rectangle is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
        /// @param handle The region handle.
        /// @param x The x-coordinate of the upper-left corner of the rectangle to test.
        /// @param y The y-coordinate of the upper-left corner of the rectangle to test.
        /// @param width The width of the rectangle to test.
        /// @param height The height of the rectangle to test.
        /// @param graphics A graphics handle that represents a graphics context.
        /// @return true when any portion of the specified rectangle is contained within the region; otherwise, false.
        /// @warning Internal use only
        static bool is_visible(intptr handle, float x, float y, float width, float height, intptr grpahics);
        
        /// @brief Initializes the region to an empty interior.
        /// @param handle The region handle.
        /// @warning Internal use only
        static void make_empty(intptr handle);
        
        /// @brief Updates the region to the union of itself and the specified region.
        /// @param handle The region handle.
        /// @param region The region handle to unite with the region.
        /// @warning Internal use only
        static void make_union(intptr handle, intptr region);
        
        /// @brief Updates the region to the union minus the intersection of itself with the specified region.
        /// @param handle The region handle.
        /// @param path The region handle to Xor with this xtd::drawing::region.
        /// @warning Internal use only
        static void make_xor(intptr handle, intptr region);
        
        /// @brief Releases the handle of the region.
        /// @param region_handle The handle to the region.
        /// @warning Internal use only
        static void release_hrgn(intptr region_handle);
        
        /// @brief Offsets the coordinates of the region by the specified amount.
        /// @param handle The region handle.
        /// @param dx The amount to offset the region horizontally.
        /// @param dy The amount to offset the region vertically.
        /// @warning Internal use only
        static void translate(intptr handle, float dx, float dy);
        /// @}
      };
    }
  }
}
