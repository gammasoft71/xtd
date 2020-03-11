#pragma once
#include "panel.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class tab_page : public panel {
    public:
      tab_page();

      using panel::text;
      control& text(const std::string& text) override;

      void destroy_handle() override;

    protected:
      forms::create_params create_params() const override;
    };
  }
}
