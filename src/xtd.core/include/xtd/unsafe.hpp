/// @file
/// @brief Contains xtd::unsafe static class.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "is_value_type.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief Contains unsafe cast as operators.
  /// @par Header
  /// ```cpp
  /// #include <xtd/unsafe>
  /// ```
  /// @par Namespace
  /// xtd
  /// @par Library
  /// xtd.core
  /// @ingroup xtd_core
  class unsafe static_ {
  public:
    template<typename to_type, typename from_type>
    requires (!xtd::is_value_type_v<to_type>)
    [[nodiscard]] static constexpr auto as(from_type&& value) -> to_type {return static_cast<to_type>(std::forward<from_type>(value));}
    
    template<typename to_type, typename from_type>
    requires xtd::is_value_type_v<to_type>
    [[nodiscard]] static constexpr auto as(from_type&& value) -> to_type {
      using underlying = typename to_type::native_type;
      return to_type{static_cast<underlying>(value)};
    }
    
    template<typename to_type, typename from_type>
    [[nodiscard]] static constexpr auto as(const from_type* value) -> to_type* {return reinterpret_cast<to_type*>(value);}
    
    template<typename to_type, typename from_type>
    [[nodiscard]] static constexpr auto as(from_type* value) -> const to_type* {return reinterpret_cast<const to_type*>(value);}
  };
}
