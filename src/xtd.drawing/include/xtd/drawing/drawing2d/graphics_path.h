/// @file
/// @brief Contains xtd::drawing::graphics_path class.
/// @copyright Copyright (c) 2022 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <memory>
#include <ostream>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../../drawing_export.h"
#include "fill_mode.h"
#include "../rectangle.h"
#include "../rectangle_f.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief The xtd::.drawing::drawing2d namespace provides advanced two-dimensional and vector graphics functionality.
    namespace drawing2d {
      /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
      /// @code
      /// class drawing_export_ graphics_path final : public object
      /// @endcode
      /// @par Inheritance
      /// xtd::object → xtd::drawing::drawing2d::graphics_path
      /// @par Namespace
      /// xtd::drawing::drawing2d
      /// @par Library
      /// xtd.drawing
      /// @ingroup xtd_drawing drawing
      class drawing_export_ graphics_path final : public object {
      public:
        /// @name Constructors
        
        /// @brief Initializes a new instance of the xtd::drawing::drawing2d::graphics_path class with a xtd::drawing::drawing2d::graphics_path::fill_mode value of xtd::drawing::drawing2d::fill_mode::alternate.
        graphics_path();
        /// @brief Initializes a new instance of the xtd::drawing::drawing2d::graphics_path class with the specified xtd::drawing::drawing2d::fil_mode enumeration.
        /// @param mode The xtd::drawing::drawing2d::fill_mode enumeration that determines how the interior of this xtd::drawing::drawing2d::graphics_path is filled.
        explicit graphics_path(xtd::drawing::drawing2d::fill_mode mode);
        /// @}
        
        /// @cond
        graphics_path(const xtd::drawing::drawing2d::graphics_path& value);
        graphics_path& operator=(const xtd::drawing::drawing2d::graphics_path& value);
        ~graphics_path();
        bool operator==(const xtd::drawing::drawing2d::graphics_path& value) const;
        bool operator!=(const xtd::drawing::drawing2d::graphics_path& value) const;
        /// @endcond
        
        /// @name Properties
        
        /// @{
        /// @brief Gets the handle of the graphics path.
        /// @return An intptr_t that contains the handle of the graphics path.
        intptr_t handle() const noexcept;
        
        
        /// @brief Gets a xtd::drawing::drawing2d::fill_mode enumeration that determines how the interiors of shapes in this xtd::drawing::drawing2d::graphics_path are filled.
        /// @return A xtd::drawing::drawing2d::fill_mode enumeration that specifies how the interiors of shapes in this xtd::drawing::drawing2d::graphics_path are filled.
        xtd::drawing::drawing2d::fill_mode fill_mode() const noexcept;
        /// @brief Sets a xtd::drawing::drawing2d::fill_mode enumeration that determines how the interiors of shapes in this xtd::drawing::drawing2d::graphics_path are filled.
        /// @param value A xtd::drawing::drawing2d::fill_mode enumeration that specifies how the interiors of shapes in this xtd::drawing::drawing2d::graphics_path are filled.
        graphics_path& fill_mode(xtd::drawing::drawing2d::fill_mode value) noexcept;
        /// @}
   
        /// @name Methods
        
        /// @{
        void add_arc(const xtd::drawing::rectangle& rect, float start_angle, float sweep_angle);
        void add_arc(const xtd::drawing::rectangle_f& rect, float start_angle, float sweep_angle);
        void add_arc(int32_t x, int32_t y, int32_t width, int32_t height, float start_angle, float sweep_angle);
        void add_arc(float x, float y, float width, float height, float start_angle, float sweep_angle);

        void add_ellipse(int32_t x, int32_t y, int32_t width, int32_t height);
        void add_ellipse(float x, float y, float width, float height);
        void add_ellipse(const xtd::drawing::rectangle& rect);
        void add_ellipse(const xtd::drawing::rectangle_f& rect);
        
        void add_rectangle(int32_t x, int32_t y, int32_t width, int32_t height);
        void add_rectangle(float x, float y, float width, float height);
        void add_rectangle(const xtd::drawing::rectangle& rect);
        void add_rectangle(const xtd::drawing::rectangle_f& rect);

        xtd::drawing::rectangle_f get_bounds() const;
        
        xtd::ustring to_string() const noexcept override;
        /// @}
        
        /// @cond
        friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::drawing2d::graphics_path& graphics_path) noexcept {return os << graphics_path.to_string();}
        /// @endcond
        
      private:
        struct data {
          intptr_t handle = 0;
          xtd::drawing::drawing2d::fill_mode fill_mode = xtd::drawing::drawing2d::fill_mode::alternate;
        };
        std::shared_ptr<data> data_ = std::make_shared<data>();
      };
    }
  }
}
