#pragma once
#include "control.hpp"
#include "tab_alignment.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class tab_control : public control {
    public:
      tab_control();
      
      virtual tab_alignment alignment() const {return this->alignment_;}
      virtual tab_control& alignment(tab_alignment alignment);

      drawing::size default_size() const override {return{200, 100};}
      
    protected:
      forms::create_params create_params() const override;
      
      drawing::size measure_control() const override;
      
      /// @cond
      tab_alignment alignment_ = tab_alignment::top;
      /// @endcond
    };
  }
}
