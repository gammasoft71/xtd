#pragma once
#include <cstdint>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Provides an interface to expose Win32 HWND handles.
    /// @remarks This interface is implemented on objects that expose Win32 HWND handles. The resultant handle can be used with Windows API calls.
    class iwin32_window  {
    public:
      /// @brief Gets the handle to the window represented by the implementer.
      /// @return A handle to the window represented by the implementer.
      /// @remarks Depending on the implementer, the value of the Handle property could change during the life of the window.
      virtual intptr_t handle() const = 0;
      
      /// @cond
      virtual ~iwin32_window() = default;
      /// @endcond
    };
  }
}
