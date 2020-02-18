#pragma once
#include <cstdint>
#include <memory>
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    class icon {
    public:
      explicit icon(const std::string& filename) {}

      explicit icon(std::istream& stream) {}

      explicit icon(const char* const* bits) {}
      
      icon(const icon& icon, int32_t width, int32_t height) {}

      /// @cond
      icon(const icon& icon) = default;
      icon& operator=(const icon& icon) = default;
      /// @endcond
      
    private:
      struct data {
        intptr_t icon_;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
