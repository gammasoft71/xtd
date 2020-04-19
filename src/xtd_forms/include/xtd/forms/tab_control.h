#pragma once
#include "control.h"
#include "tab_alignment.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @cond
    class tab_page;
    /// @endcond
  
    class tab_control : public control {
    public:
      tab_control();

      virtual control_collection& pages() {return this->controls();}
      virtual const control_collection& pages() const {return this->controls();}

      virtual tab_alignment alignment() const {return this->alignment_;}
      virtual tab_control& alignment(tab_alignment alignment);
      
      drawing::size default_size() const override {return{200, 100};}
      
      virtual size_t selected_index() const {return this->selected_index_;}
      virtual tab_control& selected_index(size_t selected_index_);

      event<tab_control, event_handler<control&>> selected_index_changed;

      
    protected:
      forms::create_params create_params() const override;

      drawing::size measure_control() const override;

      virtual void on_selected_index_changed(const event_args& e) {selected_index_changed(*this, e);}
      
      void recreate_handle() override;

      void wnd_proc(message& message) override;
      
      virtual void wm_reflect_command(message& message);
      
      /// @cond
      friend class tab_page;
      tab_alignment alignment_ = tab_alignment::top;
      size_t selected_index_ = -1;
      /// @endcond
    };
  }
}
