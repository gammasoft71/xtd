#pragma once
#include <xtd/strings.h>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Specifies the style of dashed lines drawn with a xtd::drawing::pen object.
    /// @remarks To define a custom dash_style, set the dash_pattern property of the xtd::drawing::pen.
    enum class dash_style {
      /// @brief Specifies a solid line.
      solid = 0,
      /// @brief Specifies a line consisting of dashes.
      dash,
      /// @brief Specifies a line consisting of dots.
      dot,
      /// @brief Specifies a line consisting of a repeating pattern of dash-dot.
      dash_dot,
      /// @brief Specifies a line consisting of a repeating pattern of dash-dot-dot.
      dash_dot_dot,
      /// @brief Specifies a user-defined custom dash style.
      custom
    };
    
    /// @cond
    inline std::ostream& operator<<(std::ostream& os, dash_style value) {return os << xtd::to_string(value, {{dash_style::solid, "solid"}, {dash_style::dash, "dash"}, {dash_style::dot, "dot"}, {dash_style::dash_dot, "dash_dot"}, {dash_style::dash_dot_dot, "dash_dot_dot"}});}
    inline std::wostream& operator<<(std::wostream& os, dash_style value) {return os << xtd::to_string(value, {{dash_style::solid, L"solid"}, {dash_style::dash, L"dash"}, {dash_style::dot, L"dot"}, {dash_style::dash_dot, L"dash_dot"}, {dash_style::dash_dot_dot, L"dash_dot_dot"}});}
    /// @endcond
  }
}
