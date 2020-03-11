#pragma once
#include <cstdint>
#include <memory>
#include <ostream>
#include <xtd/xtd.strings>
#include "drawing2d/pen_alignment.h"
#include "drawing2d/pen_type.h"
#include "brush.h"
#include "color.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond
    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    class pen final {
    public:
      /// @brief Initializes a new instance of the xtd::drawing::pen class with the specified xtd::drawing::brush.
      /// @param brush A xtd::drawing::brush that determines the fill properties of this xtd::drawing::pen.
      /// @remarks The brush property determines how the xtd::drawing::pen draws lines. Lines are drawn as if they are filled rectangles, with the characteristics of the specified brush.
      /// @remarks The width property of the new xtd::drawing::pen  is set to 1 (the default).
      pen(const drawing::brush& brush);
      
      pen(const drawing::brush& brush, float width);
      
      /// @brief Initializes a new instance of the xtd::drawing::pen class with the specified xtd::drawing::color.
      /// @param color A xtd::drawing::color structure that indicates the color of this xtd::drawing::pen.
      /// @remarks The color property is set to the color specified by the color parameter. The width property is set to 1 (the default).
      pen(const drawing::color& color);
      
      pen(const drawing::color& color, float width);
      
      /// @cond
      pen();
      pen(const pen& value);
      pen& operator=(const pen& value);
      virtual ~pen();
      bool operator==(const pen& value) const {return this->data_->alignment_ == value.data_->alignment_ && this->data_->type_ == value.data_->type_;}
      bool operator!=(const pen& value) const {return !this->operator==(value);}
      /// @endcond
      
      /// @brief Gets the alignment for this xtd::drawing::pen.
      /// @return A xtd::drawing2d::pen_alignment that represents the alignment for this xtd::drawing::pen.
      /// @remarks This property determines how the xtd::drawing::pen draws closed curves and polygons. The td::drawing2d::pen_alignment enumeration specifies five values; however, only two values - td::drawing2d::pen_alignment::center and td::drawing2d::pen_alignment::inset - will change the appearance of a drawn line. td::drawing2d::pen_alignment::center is the default value for this property and specifies that the width of the pen is centered on the outline of the curve or polygon. A value of td::drawing2d::pen_alignment::inset for this property specifies that the width of the pen is inside the outline of the curve or polygon. The other three values, td::drawing2d::pen_alignment::right, td::drawing2d::pen_alignment::left, and td::drawing2d::pen_alignment::outset, will result in a pen that is centered.
      drawing2d::pen_alignment alignment() const {return this->data_->alignment_;}

      /// @brief Sets the alignment for this xtd::drawing::pen.
      /// @param alignment A xtd::drawing2d::pen_alignment that represents the alignment for this xtd::drawing::pen.
      /// @remarks This property determines how the xtd::drawing::pen draws closed curves and polygons. The td::drawing2d::pen_alignment enumeration specifies five values; however, only two values - td::drawing2d::pen_alignment::center and td::drawing2d::pen_alignment::inset - will change the appearance of a drawn line. td::drawing2d::pen_alignment::center is the default value for this property and specifies that the width of the pen is centered on the outline of the curve or polygon. A value of td::drawing2d::pen_alignment::inset for this property specifies that the width of the pen is inside the outline of the curve or polygon. The other three values, td::drawing2d::pen_alignment::right, td::drawing2d::pen_alignment::left, and td::drawing2d::pen_alignment::outset, will result in a pen that is centered.
      pen& alignment(drawing2d::pen_alignment alignment);
      
      std::unique_ptr<drawing::brush> brush() const;
      pen& brush(const drawing::brush& brush);
      
      const drawing::color& color() const {return this->data_->color_;}
      pen& color(const drawing::color& color);

      drawing2d::pen_type type() const {return this->data_->type_;}
      pen& type(drawing2d::pen_type type);
      
      float width() const {return this->data_->width_;}
      pen& width(float width);
      
      std::string to_string() const {return strings::full_class_name(*this);}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::pen& pen) noexcept {
        return os << pen.to_string();
      }

    private:
      friend class graphics;
      struct data {
        intptr_t handle_ = 0;
        drawing2d::pen_alignment alignment_ = drawing2d::pen_alignment::center;
        drawing::color color_;
        drawing2d::pen_type type_ = drawing2d::pen_type::solid_color;
        float width_ = 1.0f;
      };
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
