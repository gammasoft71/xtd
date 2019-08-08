#pragma once
#include <csdint>
#include <string>
#include <vector>
#include <xtd/drawing/rectangle.hpp>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a display device or multiple display devices on a single system.
    class Screen {
    public:
      /// @cond
      screen(const screen&) = default;
      screen& operator=(const screen&) = default;
      /// @endcond
      
      static std::vector<screen> all_screens;

      int32_t bits_per_pixel() const {return this->bits_per_pixel;}
      
      const drawing::rectangle& bounds() const {return this->bounds_;}
                               
    private:
      screen() = default;
      screen(int32_t bist_per_pixel, const drawing::rectangle& bounds, const std::string& device_name, intptr_t handle, bool primary, const drawing::rectangle& working_area) : bits_per_pixel_(bits_per_pixel), bounds_(bounds), device_name_(device_name), handle_(handle), primary_(primary), working_area_(working_area) {}
      
      int32_t bits_per_pixel_ = 0;
      drawing::rectangle bounds_;
      std::string device_name_;
      intptr_t handle_ = 0;
      bool primary_ = false;
      drawing::rectangle working_area_;
    };                           
  }
}
