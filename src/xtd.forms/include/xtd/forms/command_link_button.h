#pragma once
#include "button_base.h"
#include "dialog_result.h"
#include "ibutton_control.h"
#include "timer.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class command_link_button : public button_base {
    public:
      /// @brief Initializes a new instance of the button class.
      /// @remarks By default the button displays no caption. To specify the caption text, set the text property.
      command_link_button();
      
      /// @brief Gets the mode by which the button automatically resizes itself.
      /// @return One of the AutoSizeMode values. The default value is grow_only.
      virtual forms::auto_size_mode auto_size_mode() const {return this->auto_size_mode_;}
      /// @brief Sets the mode by which the button automatically resizes itself.
      /// @param value One of the AutoSizeMode values. The default value is growonly.
      virtual command_link_button& auto_size_mode(forms::auto_size_mode value);

      /// @brief Gets the default size of the control.
      /// @return The default size.
      drawing::size default_size() const override {return {200, 60};}
      
      /// @brief Measure this control.
      /// @return The drawing::size size of this control.
      /// @remarks This method is used when auto_size is true.
      drawing::size measure_control() const override;
      
    protected:
      /// @brief Gets a create_params on the base class when creating a window.
      /// @return A create_params object on the base class when creating a window.
      /// @remarks Inheriting classes can override this property to add extra functionality, but must first call the create_params constructor on the base class to verify that the control continues to work correctly.
      forms::create_params create_params() const override;
      
      void on_handle_created(const event_args& e) override;
      
      /// @brief Processes Windows messages.
      /// @param m The Windows Message to process.
      /// @remarks All messages are sent to the wnd_proc method after getting filtered through the pre_process_message method.
      //void wnd_proc(message& message) override;

      /// @cond
      forms::dialog_result dialog_result_ = forms::dialog_result::none;
      /// @endcond

    private:
      //void wm_click(message& message);
      //void wm_mouse_up(message& message);
   };
  }
}
