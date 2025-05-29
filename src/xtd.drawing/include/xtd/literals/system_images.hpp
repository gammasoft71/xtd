/// @file
/// @brief Contains xtd::drawing::image suffixex.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "../drawing/image.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::literals namespace contains all xtd's litterals operators.
  inline namespace literals {
    /// @name Color suffixes
    
    /// @{
    /// @brief Used to convert specified value into xtd::drawing::image.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::image i = "system-file-manager"_image;
    /// i.save("system_file_manager.png");
    /// ```
    xtd::drawing::image operator""_image(const char* s, xtd::size n);
    
#if defined(__xtd__cpp_lib_char8_t)
    /// @brief Used to convert specified value into xtd::drawing::image.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::image i = u8"system-file-manager"_image;
    /// i.save("system_file_manager.png");
    /// ```
    xtd::drawing::image operator""_image(const char8* s, xtd::size n);
#endif
    
    /// @brief Used to convert specified value into xtd::drawing::image.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::image i = u"system-file-manager"_image;
    /// i.save("system_file_manager.png");
    /// ```
    xtd::drawing::image operator""_image(const char16* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::drawing::image.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::image i = U"system-file-manager"_image;
    /// i.save("system_file_manager.png");
    /// ```
    xtd::drawing::image operator""_image(const char32* s, xtd::size n);
    
    /// @brief Used to convert specified value into xtd::drawing::image.
    /// @par Namespace
    /// xtd
    /// @par Library
    /// xtd.core
    /// @ingroup xtd_core literals
    /// @par Examples
    /// ```cpp
    /// xtd::drawing::image i = L"system-file-manager"_image;
    /// i.save("system_file_manager.png");
    /// ```
    xtd::drawing::image operator""_image(const wchar* s, xtd::size n);
    /// @}
  }
}
