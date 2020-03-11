#pragma once
#include <xtd/xtd.delegates>
#include <wx/aboutdlg.h>
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/window.h>

namespace xtd {
  namespace forms {
    namespace native {
      class wx_application : public wxApp {
      public:
        wx_application() = default;
        
        bool ProcessEvent(wxEvent &event) override {
          if (event.GetEventType() == wxEVT_ACTIVATE_APP) {
            wxActivateEvent& acitvate_event = static_cast<wxActivateEvent&>(event);
            send_message(0, WM_ACTIVATEAPP, acitvate_event.GetActive(), 0, reinterpret_cast<intptr_t>(&event));
          } else if (event.GetEventType() == wxEVT_IDLE)
            send_message(0, WM_ENTERIDLE, 0, 0, reinterpret_cast<intptr_t>(&event));
          //else if (event.GetEventType() == wxEVT_END_SESSION)
          //  send_message(0, WM_QUIT, 0, 0, reinterpret_cast<intptr_t>(&event));
          return this->wxApp::ProcessEvent(event);
        }
        
        intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
          return this->wnd_proc(hwnd, msg, wparam, lparam, handle);
        }
        
        static bool message_filter(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
          return message_filter_proc(hwnd, msg, wparam, lparam, handle);
        }
        
        static event<wx_application, delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> message_filter_proc;
        event<wx_application, delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> wnd_proc;
      };
    }
  }
}
