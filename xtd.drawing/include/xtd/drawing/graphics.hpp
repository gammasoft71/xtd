#pragma once
#include <cstdint>
#include <ostream>
#include <xtd/xtd.strings>
#include "color.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace forms {
    class paint_event_args;
  }
  /// @endcond
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    struct graphics {
    public:
      ~graphics();
      
      void clear(const color& color);
      
      std::string to_string() const {return strings::full_class_name(*this);}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::graphics& graphics) noexcept {
        return os << graphics.to_string();
      }
      /// @endcond
      
    private:
      graphics(intptr_t hdc) : hdc_(hdc) {}
      
      intptr_t hdc_ = 0;
    };
  }
}
