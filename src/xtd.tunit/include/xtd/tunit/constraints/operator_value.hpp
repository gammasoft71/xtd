/// @file
/// @brief Contains xtd::tunit::constraints::operator_value class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "actual_value.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @cond
    template<typename actual_t> class does_not_value;
    template<typename actual_t> class does_value;
    template<typename actual_t> class is_not_value;
    template<typename actual_t> class is_value;
    /// @endcond
    
    /// @brief The constraints namespace contains the constraint-based assert model.
    namespace constraints {
      template<typename actual_t>
      class operator_value : public actual_value<actual_t> {
      public:
        /// @name Public Methods
        
        /// @{
        auto and_();
        /// @}
        
      protected:
        /// @name Protected Construtors
        
        /// @{
        operator_value() = default;
        operator_value(actual_value<actual_t>&& v) : actual_value<actual_t> {std::move(v)} {}
        operator_value(const actual_value<actual_t>& v) : actual_value<actual_t> {v} {}
        /// @}
        
      private:
        template<typename value_t> friend class does_not_value;
        template<typename value_t> friend class does_value;
        template<typename value_t> friend class is_not_value;
        template<typename value_t> friend class is_value;
      };
    }
  }
}
