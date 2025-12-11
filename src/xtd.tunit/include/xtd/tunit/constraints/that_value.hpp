/// @file
/// @brief Contains xtd::tunit::constraints::that_value class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "actual_value.hpp"
#include "does_value.hpp"
#include "is_value.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    namespace constraints {
      template<class actual_t>
      class that_value : public actual_value<actual_t> {
      public:
        that_value() = default;
        that_value(actual_value<actual_t>&& v) : actual_value<actual_t> {std::move (v)} {}
        that_value(const actual_value<actual_t>& v) : actual_value<actual_t> {v} {}
        
        inline auto does() {return does_value<actual_t>(self_);}
        inline auto is() {return is_value<actual_t>(self_);}
      };
    }
  }
}
