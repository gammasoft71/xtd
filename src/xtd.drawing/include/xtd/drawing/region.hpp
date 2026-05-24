/// @file
/// @brief Contains xtd::drawing::region class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "../drawing_export.hpp"
#include "drawing_2d/graphics_path.hpp"
#include <xtd/iequatable>
#include <xtd/object>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond
    
    /// @brief Describes the interior of a graphics shape composed of rectangles and paths. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ region final : public xtd::object
    /// ```
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
    class drawing_export_ region final : public xtd::object, public xtd::iequatable<region> {
      struct data;
      
    public:
      /// @name Public Constructors
      
      /// @{
      /// @brief Initializes a new xtd::drawing::region.
      /// @remarks This constructor initializes a new xtd::drawing::region with an infinite interior.
      region();
      /// @brief Initializes a new xtd::drawing::region with the specified xtd::drawing::graphics_path.
      /// @param path A xtd::drawing::graphics_path that defines the new xtd::drawing::region.
      /// @remarks This method creates a new xtd::drawing::region with a xtd::drawing::graphics_path. The new region is defined as the interior of the xtd::drawing::graphics_path specified by the path parameter.
      explicit region(const xtd::drawing::drawing_2d::graphics_path& path);
      /// @brief Initializes a new xtd::drawing::region from the specified xtd::drawing::rectangle structure.
      /// @param rect A xtd::drawing::rectangle structure that defines the interior of the new xtd::drawing::region.
      /// @remarks This method creates a new xtd::drawing::region with a rectangular interior. The interior is defined by the rect parameter.
      explicit region(const xtd::drawing::rectangle& rect);
      /// @brief Initializes a new xtd::drawing::region from the specified xtd::drawing::rectangle_f structure.
      /// @param rect A xtd::drawing::rectangle_f structure that defines the interior of the new xtd::drawing::region.
      /// @remarks This method creates a new xtd::drawing::region with a rectangular interior. The interior is defined by the rect parameter.
      explicit region(const xtd::drawing::rectangle_f& rect);
      /// @}
      
      /// @cond
      ~region();
      /// @endcond
      
      /// @name Public Properties
      
      /// @{
      /// @brief Gets the handle of the region.
      /// @return An xtd::intptr that contains the handle of the region.
      [[nodiscard]] auto handle() const noexcept -> xtd::intptr;
      /// @}
      
      /// @name Public Methods
      
      /// @{
      /// @brief Updates this xtd::drawing::region to contain the portion of the specified xtd::drawing::graphics_path that does not intersect with this xtd::drawing::region.
      /// @param path The xtd::drawing::graphics_path to complement this xtd::drawing::region.
      auto complement(const xtd::drawing::drawing_2d::graphics_path& path) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to contain the portion of the specified xtd::drawing::rectangle structure that does not intersect with this xtd::drawing::region.
      /// @param rect The xtd::drawing::rectangle structure to complement this xtd::drawing::region.
      auto complement(const xtd::drawing::rectangle& rect) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to contain the portion of the specified xtd::drawing::rectangle_f structure that does not intersect with this xtd::drawing::region.
      /// @param rect The xtd::drawing::rectangle_f structure to complement this xtd::drawing::region.
      auto complement(const xtd::drawing::rectangle_f& rect) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to contain the portion of the specified xtd::drawing::region that does not intersect with this xtd::drawing::region.
      /// @param region The xtd::drawing::region object to complement this xtd::drawing::region object.
      auto complement(const xtd::drawing::region& region) noexcept -> void;
      
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param obj The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const xtd::object& obj) const noexcept -> bool override;
      /// @brief Determines whether the specified object is equal to the current object.
      /// @param other The object to compare with the current object.
      /// @return `true` if the specified object is equal to the current object. otherwise, `false`.
      [[nodiscard]] auto equals(const region& other) const noexcept -> bool override;
      
      /// @brief Serves as a hash function for a particular type.
      /// @return A hash code for the current object.
      [[nodiscard]] auto get_hash_code() const noexcept -> xtd::usize override;
      
      /// @brief Updates this xtd::drawing::region to contain only the portion of its interior that does not intersect with the specified xtd::drawing::graphics_path.
      /// @param path The xtd::drawing::graphics_path to exclude from this xtd::drawing::region.
      auto exclude(const xtd::drawing::drawing_2d::graphics_path& path) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to contain only the portion of its interior that does not intersect with the specified xtd::drawing::rectangle structure.
      /// @param rect The xtd::drawing::rectangle structure to exclude from this xtd::drawing::region.
      auto exclude(const xtd::drawing::rectangle& rect) noexcept -> void;
      /// @brief The xtd::drawing::rectangle_f structure to exclude from this xtd::drawing::region.
      auto exclude(const xtd::drawing::rectangle_f& rect) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to contain only the portion of its interior that does not intersect with the specified xtd::drawing::region.
      /// @param region The xtd::drawing::region to exclude from this xtd::drawing::region.
      auto exclude(const xtd::drawing::region& region) noexcept -> void;
      
      /// @brief Gets a xtd::drawing::rectangle_f structure that represents a rectangle that bounds this xtd::drawing::region on the drawing surface of a xtd::drawing::graphics object.
      /// @param g The xtd::drawing::graphics on which this xtd::drawing::region is drawn.
      /// @return A xtd::drawing::rectangle_f structure that represents the bounding rectangle for this xtd::drawing::region in pixels.
      /// @remarks The current transformation of the graphics context is used to compute the region interior on the drawing surface. The bounding rectangle is not always the smallest possible bounding rectangle depending on the current transformation.
      [[nodiscard]] auto get_bounds() const noexcept -> xtd::drawing::rectangle_f;
      /// @brief Gets a xtd::drawing::rectangle_f structure that represents a rectangle that bounds this xtd::drawing::region on the drawing surface of a xtd::drawing::graphics object.
      /// @param g The xtd::drawing::graphics on which this xtd::drawing::region is drawn.
      /// @return A xtd::drawing::rectangle_f structure that represents the bounding rectangle for this xtd::drawing::region on the specified drawing surface.
      /// @remarks The current transformation of the graphics context is used to compute the region interior on the drawing surface. The bounding rectangle is not always the smallest possible bounding rectangle depending on the current transformation.
      [[nodiscard]] auto get_bounds(const xtd::drawing::graphics& g) const noexcept -> xtd::drawing::rectangle_f;
      
      /// @brief Returns a Windows handle to this xtd::drawing::region in the specified graphics context.
      /// @param g The xtd::drawing::graphics on which this xtd::drawing::region is drawn.
      /// @return A Windows handle to this xtd::drawing::region.
      /// @remarks You are responsible for calling the xtd::region::release_hrgn method to free the memory used by the GDI region object.
      [[nodiscard]] auto get_hrgn(const xtd::drawing::graphics& g) const noexcept -> xtd::intptr;
      
      /// @brief Updates this xtd::drawing::region to the intersection of itself with the specified xtd::drawing::graphics_path.
      /// @param path The xtd::drawing::graphics_path to intersect with this xtd::drawing::region.
      auto intersect(const xtd::drawing::drawing_2d::graphics_path& path) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to the intersection of itself with the specified xtd::drawing::rectangle structure.
      /// @param The xtd::drawing::rectangle structure to intersect with this xtd::drawing::region.
      auto intersect(const xtd::drawing::rectangle& rect) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to the intersection of itself with the specified xtd::drawing::rectangle_f structure.
      /// @param rect The xtd::drawing::rectangle_f structure to intersect with this xtd::drawing::region.
      auto intersect(const xtd::drawing::rectangle_f& rect) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to the intersection of itself with the specified xtd::drawing::region.
      /// @param region The xtd::drawing::region to intersect with this xtd::drawing::region.
      auto intersect(const xtd::drawing::region& region) noexcept -> void;
      
      /// @brief Tests whether this xtd::drawing::region has an empty interior.
      /// @return `true` if the interior of this xtd::drawing::region is empty; otherwise, `false`.
      /// @remarks The current transformation of the graphics context g is used to compute the region interior on the drawing surface.
      [[nodiscard]] auto is_empty() const noexcept -> bool;
      /// @brief Tests whether this xtd::drawing::region has an empty interior on the specified drawing surface.
      /// @param g A xtd::drawing::graphics that represents a drawing surface.
      /// @return `true` if the interior of this xtd::drawing::region is empty when the transformation associated with g is applied; otherwise, `false`.
      /// @remarks The current transformation of the graphics context g is used to compute the region interior on the drawing surface.
      [[nodiscard]] auto is_empty(const xtd::drawing::graphics& g) const noexcept -> bool;
      
      /// @brief Tests whether this xtd::drawing::region has an infinite interior.
      /// @return `true` if the interior of this xtd::drawing::region is infinite; otherwise, `false`.
      /// @remarks The current transformation of the graphics context g is used to compute the region interior on the drawing surface.
      [[nodiscard]] auto is_infinite() const noexcept -> bool;
      /// @brief Tests whether this xtd::drawing::region has an infinite interior on the specified drawing surface.
      /// @param g A xtd::drawing::graphics that represents a drawing surface.
      /// @return `true` if the interior of this xtd::drawing::region is infinite when the transformation associated with g is applied; otherwise, `false`.
      /// @remarks The current transformation of the graphics context g is used to compute the region interior on the drawing surface.
      [[nodiscard]] auto is_infinite(const xtd::drawing::graphics& g) const noexcept -> bool;
      
      /// @brief Tests whether any portion of the specified xtd::drawing::rectangle_f structure is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param rect The xtd::drawing::rectangle_f structure to test.
      /// @param g A xtd::drawing::graphics that represents a graphics context.
      /// @return `true` when any portion of the rect is contained within this xtd::drawing::region; otherwise, `false`.
      /// @remarks The current transformation of the graphics context is used to compute the region interior and the rectangle coordinates on the drawing surface.
      [[nodiscard]] auto is_visible(const xtd::drawing::rectangle_f& rect, const xtd::drawing::graphics& g) const noexcept -> bool;
      /// @brief Tests whether any portion of the specified rectangle is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to test.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to test.
      /// @param width The width of the rectangle to test.
      /// @param height The height of the rectangle to test.
      /// @param g A xtd::drawing::graphics that represents a graphics context.
      /// @return `true` when any portion of the specified rectangle is contained within this xtd::drawing::region; otherwise, `false`.
      /// @remarks The current transformation of the graphics context is used to compute the region interior and the rectangle coordinates on the drawing surface.
      [[nodiscard]] auto is_visible(float x, float y, float width, float height, const xtd::drawing::graphics& g) const noexcept -> bool;
      /// @brief Tests whether any portion of the specified xtd::drawing::rectangle structure is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param rect The xtd::drawing::rectangle structure to test.
      /// @param g A xtd::drawing::graphics that represents a graphics context.
      /// @return `true` when any portion of the rect is contained within this xtd::drawing::region; otherwise, `false`.
      /// @remarks The current transformation of the graphics context is used to compute the region interior and the rectangle coordinates on the drawing surface.
      [[nodiscard]] auto is_visible(const xtd::drawing::rectangle& rect, const xtd::drawing::graphics& g) const noexcept -> bool;
      /// @brief Tests whether any portion of the specified rectangle is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to test.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to test.
      /// @param width The width of the rectangle to test.
      /// @param height The height of the rectangle to test.
      /// @param g A xtd::drawing::graphics that represents a graphics context.
      /// @return `true` when any portion of the specified rectangle is contained within this xtd::drawing::region; otherwise, `false`.
      /// @remarks The current transformation of the graphics context is used to compute the region interior and the rectangle coordinates on the drawing surface.
      [[nodiscard]] auto is_visible(xtd::int32 x, xtd::int32 y, xtd::int32 width, xtd::int32 height, const xtd::drawing::graphics& g) const noexcept -> bool;
      /// @brief Tests whether any portion of the specified xtd::drawing::rectangle_f structure is contained within this xtd::drawing::region.
      /// @param rect The xtd::drawing::rectangle_f structure to test.
      /// @return `true` when any portion of rect is contained within this xtd::drawing::region; otherwise, `false`.
      [[nodiscard]] auto is_visible(const xtd::drawing::rectangle_f& rect) const noexcept -> bool;
      /// @brief Tests whether any portion of the specified rectangle is contained within this xtd::drawing::region.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to test.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to test.
      /// @param width The width of the rectangle to test.
      /// @param height The height of the rectangle to test.
      /// @return `true` when any portion of the specified rectangle is contained within this xtd::drawing::region; otherwise, `false`.
      [[nodiscard]] auto is_visible(float x, float y, float width, float height) const noexcept -> bool;
      /// @brief Tests whether any portion of the specified xtd::drawing::rectangle structure is contained within this xtd::drawing::region.
      /// @param rect The xtd::drawing::rectangle structure to test.
      /// @return `true` when any portion of rect is contained within this xtd::drawing::region; otherwise, `false`.
      [[nodiscard]] auto is_visible(const xtd::drawing::rectangle& rect) const noexcept -> bool;
      /// @brief Tests whether any portion of the specified rectangle is contained within this xtd::drawing::region.
      /// @param x The x-coordinate of the upper-left corner of the rectangle to test.
      /// @param y The y-coordinate of the upper-left corner of the rectangle to test.
      /// @param width The width of the rectangle to test.
      /// @param height The height of the rectangle to test.
      /// @return `true` when any portion of the specified rectangle is contained within this xtd::drawing::region; otherwise, `false`.
      [[nodiscard]] auto is_visible(xtd::int32 x, xtd::int32 y, xtd::int32 width, xtd::int32 height) const noexcept -> bool;
      /// @brief Tests whether the specified PointF structure is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param pt The PointF structure to test.
      /// @param g A xtd::drawing::graphics that represents a graphics context.
      /// @return `true` when point is contained within this xtd::drawing::region; otherwise, `false`.
      /// @remarks The current transformation of the graphics context is used to compute the region interior and the rectangle coordinates on the drawing surface.
      [[nodiscard]] auto is_visible(xtd::drawing::point_f pt, const xtd::drawing::graphics& g) const noexcept -> bool;
      /// @brief Tests whether the specified point is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param x The x-coordinate of the point to test.
      /// @param y The y-coordinate of the point to test.
      /// @param g A xtd::drawing::graphics that represents a graphics context.
      /// @return `true` when the specified point is contained within this xtd::drawing::region; otherwise, `false`.
      /// @remarks The current transformation of the graphics context is used to compute the region interior and the rectangle coordinates on the drawing surface.
      [[nodiscard]] auto is_visible(float x, float y, const xtd::drawing::graphics& g) const noexcept -> bool;
      /// @brief Tests whether the specified Point structure is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param pt The Point structure to test.
      /// @param g A xtd::drawing::graphics that represents a graphics context.
      /// @return `true` when point is contained within this xtd::drawing::region; otherwise, `false`.
      /// @remarks The current transformation of the graphics context is used to compute the region interior and the rectangle coordinates on the drawing surface.
      [[nodiscard]] auto is_visible(xtd::drawing::point pt, const xtd::drawing::graphics& g) const noexcept -> bool;
      /// @brief Tests whether the specified point is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param x The x-coordinate of the point to test.
      /// @param y The y-coordinate of the point to test.
      /// @param g A xtd::drawing::graphics that represents a graphics context.
      /// @return `true` when the specified point is contained within this xtd::drawing::region; otherwise, `false`.
      /// @remarks The current transformation of the graphics context is used to compute the region interior and the rectangle coordinates on the drawing surface.
      [[nodiscard]] auto is_visible(xtd::int32 x, xtd::int32 y, const xtd::drawing::graphics& g) const noexcept -> bool;
      /// @brief Tests whether the specified PointF structure is contained within this xtd::drawing::region.
      /// @param pt The PointF structure to test.
      /// @return `true` when point is contained within this xtd::drawing::region; otherwise, `false`.
      [[nodiscard]] auto is_visible(xtd::drawing::point_f pt) const noexcept -> bool;
      /// @brief Tests whether the specified point is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param x The x-coordinate of the point to test.
      /// @param y The y-coordinate of the point to test.
      /// @return `true` when the specified point is contained within this xtd::drawing::region; otherwise, `false`.
      [[nodiscard]] auto is_visible(float x, float y) const noexcept -> bool;
      /// @brief Tests whether the specified Point structure is contained within this xtd::drawing::region.
      /// @param pt The Point structure to test.
      /// @return `true` when point is contained within this xtd::drawing::region; otherwise, `false`.
      [[nodiscard]] auto is_visible(xtd::drawing::point pt) const noexcept -> bool;
      /// @brief Tests whether the specified point is contained within this xtd::drawing::region when drawn using the specified xtd::drawing::graphics.
      /// @param x The x-coordinate of the point to test.
      /// @param y The y-coordinate of the point to test.
      /// @return `true` when the specified point is contained within this xtd::drawing::region; otherwise, `false`.
      [[nodiscard]] auto is_visible(xtd::int32 x, xtd::int32 y) const noexcept -> bool;
      
      /// @brief Initializes this xtd::drawing::region to an empty interior.
      auto make_empty() -> void;
      
      /// @brief Initializes this xtd::drawing::region object to an infinite interior.
      auto make_infinite() noexcept -> void;
      
      /// @brief Updates this xtd::drawing::region to the union of itself and the specified xtd::drawing::graphics_path.
      /// @param path The xtd::drawing::graphics_path to unite with this xtd::drawing::region.
      auto make_union(const xtd::drawing::drawing_2d::graphics_path& path) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to the union of itself and the specified xtd::drawing::rectangle structure.
      /// @param rect The xtd::drawing::rectangle structure to unite with this xtd::drawing::region.
      auto make_union(const xtd::drawing::rectangle& rect) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to the union of itself and the specified xtd::drawing::rectangle_f structure.
      /// @param rect The xtd::drawing::rectangle_f structure to unite with this xtd::drawing::region.
      auto make_union(const xtd::drawing::rectangle_f& rect) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to the union of itself and the specified xtd::drawing::region.
      /// @param region The xtd::drawing::region to unite with this xtd::drawing::region.
      auto make_union(const xtd::drawing::region& region) noexcept -> void;
      
      /// @brief Updates this xtd::drawing::region to the union minus the intersection of itself with the specified xtd::drawing::graphics_path.
      /// @param path The xtd::drawing::graphics_path to Xor with this xtd::drawing::region.
      auto make_xor(const xtd::drawing::drawing_2d::graphics_path& path) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to the union minus the intersection of itself with the specified xtd::drawing::rectangle structure.
      /// @param path The xtd::drawing::rectangle structure to Xor with this xtd::drawing::region.
      auto make_xor(const xtd::drawing::rectangle& rect) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to the union minus the intersection of itself with the specified xtd::drawing::rectangle_f structure.
      /// @param path The xtd::drawing::rectangle_f structure to Xor with this xtd::drawing::region.
      auto make_xor(const xtd::drawing::rectangle_f& rect) noexcept -> void;
      /// @brief Updates this xtd::drawing::region to the union minus the intersection of itself with the specified xtd::drawing::region.
      /// @param path The xtd::drawing::region to Xor with this xtd::drawing::region.
      auto make_xor(const xtd::drawing::region& region) noexcept -> void;
      
      /// @brief Releases the handle of the xtd::drawing::region.
      /// @param region_handle The handle to the xtd::drawing::region.
      auto release_hrgn(xtd::intptr region_handle) -> void;
      
      /// @brief Offsets the coordinates of this xtd::drawing::region by the specified amount.
      /// @param dx The amount to offset this xtd::drawing::region horizontally.
      /// @param dy The amount to offset this xtd::drawing::region vertically.
      auto translate(xtd::int32 dx, xtd::int32 dy) noexcept -> void;
      /// @brief Offsets the coordinates of this xtd::drawing::region by the specified amount.
      /// @param dx The amount to offset this xtd::drawing::region horizontally.
      /// @param dy The amount to offset this xtd::drawing::region vertically.
      auto translate(float dx, float dy) noexcept -> void;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Tests whether the specified Region is identical to this xtd::drawing::region on the specified drawing surface.
      /// @param region The Region to test.
      /// @param g A xtd::drawing::graphics that represents a drawing surface.
      /// @return `true` if the interior of region is identical to the interior of this region when the transformation associated with the `g` parameter is applied; otherwise, `false`.
      /// @remarks The current transformation of the graphics context `g` is used to compute the region interiors on the drawing surface.
      [[nodiscard]] static auto equals(const region& region, const xtd::drawing::graphics& g) noexcept -> bool;
      
      /// @brief Initializes a new xtd::drawing::region from a handle to the specified existing GDI region.
      /// @param hrgn A handle to an existing xtd::drawing::region.
      /// @return The new xtd::drawing::region.
      /// @remarks This method creates a new xtd::drawing::region with an interior defined by the existing xtd::drawing::region referred to by the handle in the hrgn parameter.
      [[nodiscard]] static auto from_hrgn(xtd::intptr hrgn) -> xtd::drawing::region;
      /// @}
      
    private:
      xtd::sptr<data> data_;
    };
  }
}
