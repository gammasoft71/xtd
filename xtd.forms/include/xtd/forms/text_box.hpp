#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class text_box : public control {
    public:
      text_box();

      drawing::size default_size() const override {return{100, 23};}

      using control::text;
      void text(const std::string& text) override;

      void create_handle() override;
    };
  }
}
