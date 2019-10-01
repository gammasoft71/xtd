#pragma once
#include "scrollable_control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class container_control : public scrollable_control {
    public:      
      
    /// @brief Gets the active control on the container control.
    /// @return The control that is currently active on the container_control.
    std::optional<control_ref> active_control() const {return this->active_control_;}
    /// @brief Sets the active control on the container control.
    /// @param active_control The control that is currently active on the container_control.
      void active_control(const control& active_control);
    /// @brief Resets the active control on the container control.
    /// @param nullptr.
    void active_control(std::nullptr_t) {this->active_control_.reset();}

    protected:
      container_control() = default;
      std::optional<control_ref> active_control_;
    };
  }
}
