/// @file
/// @brief Contains xtd::tunit::constraints::and_operator_value class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "that_value.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The constraints namespace contains the constraint-based assert model.
    namespace constraints {
      /// @cond
      template<class actual_t> class operator_value;
      /// @endcond
      
      template<class actual_t>
      class and_operator_value : public that_value<actual_t> {
      protected:
        /// @name Protected Construtors
        
        /// @{
        and_operator_value() = default;
        and_operator_value(that_value<actual_t>&& v) : that_value<actual_t> {std::move(v)} {}
        and_operator_value(const that_value<actual_t>& v) : that_value<actual_t> {v} {}
        /// @}
        
      private:
        template<class value_t> friend class operator_value;
      };
    }
  }
}
