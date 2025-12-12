/// @file
/// @brief Contains xtd::tunit::constraints::actual_value class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "assert_type.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The tunit namespace contains a unit test library.
  namespace tunit {
    /// @brief The contraints namespace contains the constraint-based assert model.
    namespace constraints {
      /// @cond
      class assert_value;
      /// @endcond
      
      template<class actual_t>
      class actual_value {
      protected:
        /// @name Protected Construtors
        
        /// @{
        actual_value() {}
        actual_value(actual_value&&) = default;
        actual_value(const actual_value&) = default;
        /// @}
        
        /// @name Protected Properties
        
        /// @{
        xtd::tunit::constraints::assert_type assert_type() const noexcept {return assert_type_;};
        actual_value& type(xtd::tunit::constraints::assert_type assert_type) noexcept {
          assert_type_ = assert_type;
          return self_;
        };
        
        auto is_assert() const noexcept {return assert_type() == xtd::tunit::constraints::assert_type::assert;}
        auto is_valid() const noexcept {return assert_type() == xtd::tunit::constraints::assert_type::valid;}
        auto is_assume() const noexcept {return assert_type() == xtd::tunit::constraints::assert_type::assume;}
        
        const actual_t& actual() const noexcept {return *actual_;}
        actual_value& actual(const actual_t& actual) noexcept {
          actual_ = &actual;
          return self_;
        }
        /// @}
        
      private:
        friend class assert_value;
        xtd::tunit::constraints::assert_type assert_type_;
        const actual_t* actual_ = null;
      };
    }
  }
}
