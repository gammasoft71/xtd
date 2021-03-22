/// @file
/// @brief Contains xtd::drawing::brush class.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
#include <cstdint>
#include <memory>
#include <ostream>
#include <xtd/strings.h>
#include "../drawing_export.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond

    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing
    class drawing_export_ brush {
    public:
      //static const brush null;
      
      /// @cond
      brush(const brush& value);
      brush& operator=(const brush& value);
      virtual ~brush();
      bool operator==(const brush& value) const {return data_->handle_ == value.data_->handle_;}
      bool operator!=(const brush& value) const {return !operator==(value);}
      /// @endcond
      
      std::string to_string() const {return strings::full_class_name(*this);}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::brush& brush) noexcept {
        return os << brush.to_string();
      }
      /// @endcond
      
    protected:
      /// @cond
      friend class graphics;
      /// @endcond
      brush();
      
      void set_native_brush(intptr_t brush);
      
      struct data {
        intptr_t handle_ = 0;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
