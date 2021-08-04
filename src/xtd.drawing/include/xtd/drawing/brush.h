/// @file
/// @brief Contains xtd::drawing::brush class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <memory>
#include <ostream>
#include <xtd/object.h>
#include <xtd/ustring.h>
#include "../drawing_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond

    /// @brief Defines objects used to fill the interiors of graphical shapes such as rectangles, ellipses, pies, polygons, and paths.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    /// @remarks This is an abstract base class and cannot be instantiated. To create a brush object, use classes derived from xtd::drawing::brush, such as xtd::drawing::solid_brush, xtd::drawing::texture_brush, and xtd::drawing::drawing2d::linear_gradient_brush.
    class drawing_export_ brush : public object {
    public:
      //static const brush null;
      
      /// @cond
      brush(const brush& value);
      brush& operator=(const brush& value);
      ~brush();
      bool operator==(const brush& value) const {return data_->handle_ == value.data_->handle_;}
      bool operator!=(const brush& value) const {return !operator==(value);}
      /// @endcond
      
      /// @brief Converts this brush object to a human-readable string.
      /// @return A string that represents this brush object.
      xtd::ustring to_string() const noexcept override {return ustring::full_class_name(*this);}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::brush& brush) noexcept {
        return os << brush.to_string();
      }
      /// @endcond
      
    protected:
      friend class graphics;

      /// @brief Initialize a new instance of brush class.
      brush();
      
      /// @brief In a derived class, sets a reference to a GDI+ brush object.
      /// @param brush A pointer to the GDI+ brush object.
      void set_native_brush(intptr_t brush);
      
      /// @cond
      struct data {
        intptr_t handle_ = 0;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
      /// @endcond
    };
  }
}
