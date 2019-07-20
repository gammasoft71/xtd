#pragma once
#include "control.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class form : public control {
    public:
      form();

      drawing::size default_size() const override {return{300, 300};}

      using control::parent;
      void parent(const control& parent) override;

      void create_handle() override;
    };
  }
}
