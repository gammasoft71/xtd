#pragma once
#include <xtd/drawing/size.hpp>
#include <cstdint>

namespace xtd {
  namespace forms {
    namespace native {
      class label {
      public:
        enum class styles {
          none = 0b0,
          auto_size = 0b1,
          border_fixed_single = 0b10,
          border_fixed_3d = 0b100
        };

        label() = delete;
        static intptr_t create(intptr_t parent, const drawing::size& size, styles styles);
      };

      inline label::label::styles& operator +=(label::styles& lhs, label::styles rhs) {lhs = static_cast<label::styles>(static_cast<int64_t>(lhs) + static_cast<int64_t>(rhs)); return lhs;}
      inline label::styles& operator -=(label::styles& lhs, label::styles rhs) {lhs = static_cast<label::styles>(static_cast<int64_t>(lhs) - static_cast<int64_t>(rhs)); return lhs;}
      inline label::styles& operator &=(label::styles& lhs, label::styles rhs) {lhs = static_cast<label::styles>(static_cast<int64_t>(lhs) & static_cast<int64_t>(rhs)); return lhs;}
      inline label::styles& operator |=(label::styles& lhs, label::styles rhs) {lhs = static_cast<label::styles>(static_cast<int64_t>(lhs) | static_cast<int64_t>(rhs)); return lhs;}
      inline label::styles& operator ^=(label::styles& lhs, label::styles rhs) {lhs = static_cast<label::styles>(static_cast<int64_t>(lhs) ^ static_cast<int64_t>(rhs)); return lhs;}
      inline label::styles operator +(label::styles lhs, label::styles rhs) {return static_cast<label::styles>(static_cast<int64_t>(lhs) + static_cast<int64_t>(rhs));}
      inline label::styles operator -(label::styles lhs, label::styles rhs) {return static_cast<label::styles>(static_cast<int64_t>(lhs) - static_cast<int64_t>(rhs));}
      inline label::styles operator ~(label::styles rhs) {return static_cast<label::styles>(~static_cast<int64_t>(rhs));}
      inline label::styles operator &(label::styles lhs, label::styles rhs) {return static_cast<label::styles>(static_cast<int64_t>(lhs) & static_cast<int64_t>(rhs));}
      inline label::styles operator |(label::styles lhs, label::styles rhs) {return static_cast<label::styles>(static_cast<int64_t>(lhs) | static_cast<int64_t>(rhs));}
      inline label::styles operator ^(label::styles lhs, label::styles rhs) {return static_cast<label::styles>(static_cast<int64_t>(lhs) ^ static_cast<int64_t>(rhs));}
    }
  }
}
