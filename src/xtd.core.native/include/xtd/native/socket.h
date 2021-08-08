/// @file
/// @brief Contains socket API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <string>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace net {
    class socket_address;
  }
  // @endcond

  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains translator native API.
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ socket final {
      friend xtd::net::socket_address;
    protected:
      /// @brief Gets the native address family value corresponding to xtd address family.
      /// @return The native address family value corresponding to xtd address family (see address_families.h).
      /// @warning Internal use only
      static int32_t address_family_to_native(int32_t address_family);
      /// @brief Gets the xtd address family value corresponding to native address family.
      /// @return The xtd address family value corresponding to native address family (see address_families.h).
      /// @warning Internal use only
      static int32_t native_to_address_family(int32_t address_family);
    };
  }
}
