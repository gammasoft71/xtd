#pragma once
#include <xtd/drawing/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class panel {
      public:
        enum class styles {
          none = 0b0,
          border_fixed_single = 0b1,
          border_fixed_3d = 0b10
        };

        panel() = delete;
        static intptr_t create(intptr_t parent, const drawing::size& size, styles styles);
      };

      inline panel::styles& operator +=(panel::styles& lhs, panel::styles rhs) {lhs = static_cast<panel::styles>(static_cast<int64_t>(lhs) + static_cast<int64_t>(rhs)); return lhs;}
      inline panel::styles& operator -=(panel::styles& lhs, panel::styles rhs) {lhs = static_cast<panel::styles>(static_cast<int64_t>(lhs) - static_cast<int64_t>(rhs)); return lhs;}
      inline panel::styles& operator &=(panel::styles& lhs, panel::styles rhs) {lhs = static_cast<panel::styles>(static_cast<int64_t>(lhs) & static_cast<int64_t>(rhs)); return lhs;}
      inline panel::styles& operator |=(panel::styles& lhs, panel::styles rhs) {lhs = static_cast<panel::styles>(static_cast<int64_t>(lhs) | static_cast<int64_t>(rhs)); return lhs;}
      inline panel::styles& operator ^=(panel::styles& lhs, panel::styles rhs) {lhs = static_cast<panel::styles>(static_cast<int64_t>(lhs) ^ static_cast<int64_t>(rhs)); return lhs;}
      inline panel::styles operator +(panel::styles lhs, panel::styles rhs) {return static_cast<panel::styles>(static_cast<int64_t>(lhs) + static_cast<int64_t>(rhs));}
      inline panel::styles operator -(panel::styles lhs, panel::styles rhs) {return static_cast<panel::styles>(static_cast<int64_t>(lhs) - static_cast<int64_t>(rhs));}
      inline panel::styles operator ~(panel::styles rhs) {return static_cast<panel::styles>(~static_cast<int64_t>(rhs));}
      inline panel::styles operator &(panel::styles lhs, panel::styles rhs) {return static_cast<panel::styles>(static_cast<int64_t>(lhs) & static_cast<int64_t>(rhs));}
      inline panel::styles operator |(panel::styles lhs, panel::styles rhs) {return static_cast<panel::styles>(static_cast<int64_t>(lhs) | static_cast<int64_t>(rhs));}
      inline panel::styles operator ^(panel::styles lhs, panel::styles rhs) {return static_cast<panel::styles>(static_cast<int64_t>(lhs) ^ static_cast<int64_t>(rhs));}
    }
  }
}
