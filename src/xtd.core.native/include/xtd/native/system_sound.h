/// @file
/// @brief Contains system_sound API.
/// @copyright Copyright (c) 2021 Gammasoft. All rights reserved.
#pragma once
/// @cond
#ifndef __XTD_CORE_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/core_native_export.h>
#include <cstddef>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @cond
  namespace media {
    class system_sound;
  }
  /// @endcond

  /// @brief The xtd::native namespace contains internal native API definitions to access underlying operating system components used by xtd.core library.
  /// @warning Internal use only
  namespace native {
    /// @brief Contains system_sound native API.
    /// @par Namespace
    /// xtd::native
    /// @par Library
    /// xtd.core.native
    /// @ingroup xtd_core_native native
    /// @warning Internal use only
    class core_native_export_ system_sound final {
      system_sound() = delete;
      friend xtd::media::system_sound;
    protected:
      /// @brief Play system sound.
      /// @param sound The sound to play (see souund.h).
      /// @warning Internal use only
      static void play(uint32_t sound);
    };
  }
}
