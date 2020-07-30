#pragma once
#include <cstdint>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a display device or multiple display devices on a single system.
    class padding {
    public:
      padding() = default;
      
      padding(int all) : all_(true), left_(all), top_(all), right_(all), bottom_(all) {}
      
      padding(int left, int top, int right, int bottom) : all_(left == top && left == right && left == bottom), left_(left), top_(top), right_(right), bottom_(bottom) {}
      
      /// @cond
      padding(const padding&) = default;
      padding& operator=(const padding&) = default;
      /// @endcond
      
      int all() const {return all_ ? top_ : -1;}
      void all(int all) {
        if (!all_ || left_ != all) {
          all_ = true;
          left_ = top_ = right_ = bottom_ = all;
        }
      }
      
      int bottom() const {return bottom_;}
      void bottom(int bottom) {
        if (all_ || bottom_ != bottom) {
          all_ = false;
          bottom_ = bottom;
        }
      }
      
      int left() const {return left_;}
      void left(int left) {
        if (all_ || left_ != left) {
          all_ = false;
          left_ = left;
        }
      }

      int right() const {return right_;}
      void right(int right) {
        if (all_ || right_ != right) {
          all_ = false;
          right_ = right;
        }
      }

      int top() const {return top_;}
      void top(int top) {
        if (all_ || top_ != top) {
          all_ = false;
          top_ = top;
        }
      }

      static const padding empty;
                                        
    private:
      bool all_ = true;
      int left_ = 0;
      int top_ = 0;
      int right_ = 0;
      int bottom_ = 0;
    };
  }
}
