#pragma once
#include <cstdint>
#include <memory>
#include <xtd/xtd.strings>
#include "bitmap.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    class icon {
    public:
      icon() = default;
      ~icon();

      explicit icon(const std::string& filename);

      explicit icon(std::istream& stream);

      explicit icon(const char* const* bits);
      
      icon(const icon& icon, int32_t width, int32_t height);

      /// @cond
      icon(const icon& icon) = default;
      icon& operator=(const icon& icon) = default;
      bool operator==(const icon& icon) const {return data_->handle_ == icon.data_->handle_;}
      bool operator!=(const icon& icon) const {return !operator==(icon);}
      /// @endcond
      
      /// @brief Get the handle of this image.
      /// @return The handle of this image.
      intptr_t handle() const {return this->data_->handle_;}

      static icon empty;

      void save(const std::string& filename) const;
      void save(std::ostream& stream) const;
      
      static icon from_bitmap(const bitmap& bitmap);
      
      bitmap to_bitmap() const;

    private:
      explicit icon(const bitmap& bitmap);
      struct data {
        intptr_t handle_ = 0;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
