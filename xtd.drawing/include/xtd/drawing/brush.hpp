#pragma once
#include <cstdint>
#include <memory>
#include <ostream>
#include <xtd/xtd.strings>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @cond
    class graphics;
    /// @endcond
    /// @brief Defines an object used to draw lines and curves. This class cannot be inherited.
    struct brush {
    public:
      //static const brush null;
      
      /// @cond
      brush(const brush&) = default;
      virtual ~brush();
      brush& operator=(const brush&) = default;
      bool operator==(const brush& value) const {return this->data_->handle_ == value.data_->handle_;}
      bool operator!=(const brush& value) const {return !this->operator==(value);}
      /// @endcond
      
      std::string to_string() const {return strings::full_class_name(*this);}
      
      /// @cond
      friend std::ostream& operator<<(std::ostream& os, const xtd::drawing::brush& brush) noexcept {
        return os << brush.to_string();
      }
      /// @endcond
      
    protected:
      friend class graphics;
      brush();
      
      void set_native_brush(intptr_t brush);
      
      struct data {
        intptr_t handle_ = 0;
      };
      
      std::shared_ptr<data> data_ = std::make_shared<data>();
    };
  }
}
