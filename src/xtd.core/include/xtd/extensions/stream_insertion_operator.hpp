/// @file
/// @brief Contains xtd::extensions::stream_insertion_operator class.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#define __XTD_STD_INTERNAL__
#include "../internal/__xtd_std_version.hpp"
#undef __XTD_STD_INTERNAL__
#include <compare>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::extensions namespace contains interface extensions.
  namespace extensions {
    /// @brief Internal comparable operators definition.
    /// @par Definition
    /// ```cpp
    /// template<class type_t, class stringable_t>
    /// class stream_insertion_operator
    /// ```
    /// @par Header
    /// ```cpp
    /// #include <xtd/extensions/stream_insertion_operator
    /// ```
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core extensions
    /// @warning Internal use only for xtd::istringable interfece.
    template<class type_t, class stringable_t>
    class stream_insertion_operator {
    public:
      /// @name Public Operators
      
      /// @{
      /// @brief Stream insertable operator with specidied value.
      /// @param os The output stream where insert value.
      /// @param value The value to insert in output stream.
      /// @return the output stream with value inserted.
      friend auto operator <<(std::ostream& os, const type_t& value) -> std::ostream& {return os << value.to_string();}
      /// @}
      
    private:
      friend stringable_t;
      stream_insertion_operator() = default;
    };
  }
}
