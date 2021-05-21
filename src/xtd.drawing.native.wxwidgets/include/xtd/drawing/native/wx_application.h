#pragma once
/// @cond
#ifndef __XTD_DRAWING_NATIVE_LIBRARY__
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <cstdint>
#include <stdexcept>
#include <xtd/delegate.h>
#include <xtd/event.h>
#include <wx/aboutdlg.h>
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/window.h>

namespace xtd {
  namespace drawing {
    namespace native {
      class wx_application : public wxApp {
#ifndef WM_ACTIVATEAPP
        static constexpr int32_t WM_ACTIVATEAPP = 0x001C;
        static constexpr int32_t WM_ENTERIDLE = 0x0121;
#endif
      public:
        wx_application() = default;
        
        bool OnExceptionInMainLoop() override {
          if (!thread_exception.is_empty())
            return thread_exception();
          exceptionStored = std::current_exception();
          return false;
        }
        
        int MainLoop() override {
          struct CallOnExit {
            ~CallOnExit() {wxTheApp->OnExit();}
          } callOnExit;
          auto result = wxApp::MainLoop();
          if (exceptionStored) std::rethrow_exception(exceptionStored);
          return result;
        }
        
        bool ProcessEvent(wxEvent &event) override {
          if (exceptionStored) return wxApp::ProcessEvent(event);
          if (event.GetEventType() == wxEVT_ACTIVATE_APP) {
            wxActivateEvent& acitvate_event = static_cast<wxActivateEvent&>(event);
            send_message(0, WM_ACTIVATEAPP, acitvate_event.GetActive(), 0, reinterpret_cast<intptr_t>(&event));
          } else if (event.GetEventType() == wxEVT_IDLE)
            send_message(0, WM_ENTERIDLE, 0, 0, reinterpret_cast<intptr_t>(&event));
          //else if (event.GetEventType() == wxEVT_END_SESSION)
          //  send_message(0, WM_QUIT, 0, 0, reinterpret_cast<intptr_t>(&event));
          return wxApp::ProcessEvent(event);
        }
        
        intptr_t send_message(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
          return wnd_proc(hwnd, msg, wparam, lparam, handle);
        }
        
        static bool message_filter(intptr_t hwnd, int32_t msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
          return message_filter_proc(hwnd, msg, wparam, lparam, handle);
        }
        
        static xtd::event<wx_application, xtd::delegate<bool(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> message_filter_proc;
        xtd::event<wx_application, xtd::delegate<intptr_t(intptr_t, int32_t, intptr_t, intptr_t, intptr_t)>> wnd_proc;
        xtd::event<wx_application, xtd::delegate<bool()>> thread_exception;
        
        std::exception_ptr exceptionStored;
      };
    }
  }
}

