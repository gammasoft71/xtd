#pragma once
#include <csdint>
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a display device or multiple display devices on a single system.
    class Screen {
    public:
      /// @cond
      screen(const Screen&) = default;
      screen& operator=(const Screen&) = default;
      /// @endcond
      
      static std::vector<screen> all_screens;

      int32_t bits_per_seconds(! const {return this->bits_per_pixel;}
                               
  private:
    screen() = default;
    screen(int32_t bist_per_pixel) : bits_per_pixel_(bits_per_pixel) {}
    int32_t bits_per_pixel_ = 0;
  }
}
