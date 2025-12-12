/// @file
/// @brief Contains xtd::tunit::constraints::assert_value class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "that_value.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The contraints namespace contains the constraint-based assert model.
    namespace constraints {
      class assert_value {
      public:
        assert_value(const assert_type& type) : type_ {type} {}
        
        template<class actual_t>
        inline auto that(const actual_t& actual) {return that_value<actual_t> {actual_value<actual_t> {}.type(type_).actual(actual)};}
        
      private:
        const assert_type& type_;
      };
    }
  }
}
