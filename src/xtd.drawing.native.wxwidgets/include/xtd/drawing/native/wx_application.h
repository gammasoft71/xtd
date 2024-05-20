#pragma once
/// @cond
#if !defined(__XTD_DRAWING_NATIVE_LIBRARY__)
#error "Do not include this file: Internal use only"
#endif
/// @endcond

#include <xtd/delegate>
#include <xtd/event>
#include <xtd/scope_exit>
#include <wx/aboutdlg.h>
#include <wx/app.h>
#include <wx/menu.h>
#include <wx/window.h>
#include <cstdint>
#include <stdexcept>

namespace xtd {
  namespace drawing {
    namespace native {
      class wx_application : public wxApp {
        #if !defined(WM_ACTIVATEAPP)
        static constexpr int32 WM_ACTIVATEAPP = 0x001C;
        #endif
        static constexpr int32 WM_APPIDLE = 0x0401;
        //static constexpr int32 WM_QUIT = 0x0012;
      public:
        wx_application() = default;
        
        bool OnExceptionInMainLoop() override {
          if (!thread_exception.is_empty())
            return thread_exception();
          exceptionStored = std::current_exception();
          return false;
        }
        
        int32 MainLoop() override {
          class PreProcessFilter : public wxEventFilter {
          public:
            PreProcessFilter() {wxEvtHandler::AddFilter(this);}
            ~PreProcessFilter() {wxEvtHandler::RemoveFilter(this);}
            
            // Workaround to remove Ctrl-Alt-middle click that shows information about wx version
            int FilterEvent(wxEvent& event) override {
              auto mouseEVent = dynamic_cast<wxMouseEvent*>(&event);
              return mouseEVent && mouseEVent->GetEventType() == wxEVT_MIDDLE_DOWN && mouseEVent->ControlDown() && mouseEVent->AltDown() ? Event_Ignore : Event_Skip;
            }
          };
          auto pre_process_filer = PreProcessFilter {};
          
          scope_exit_ {
            wxTheApp->OnExit();
          };
          
          auto result = wxApp::MainLoop();
          if (exceptionStored) std::rethrow_exception(exceptionStored);
          return result;
        }

        bool ProcessEvent(wxEvent& event) override {
          if (exceptionStored) return wxApp::ProcessEvent(event);
          if (event.GetEventType() == wxEVT_ACTIVATE_APP) {
            wxActivateEvent& activate_event = static_cast<wxActivateEvent&>(event);
            send_message(0, WM_ACTIVATEAPP, activate_event.GetActive(), 0, reinterpret_cast<intptr>(&event));
          } else if (event.GetEventType() == wxEVT_IDLE)
            send_message(0, WM_APPIDLE, 0, 0, reinterpret_cast<intptr>(&event));
          //else if (event.GetEventType() == wxEVT_END_SESSION)
          //  send_message(0, WM_QUIT, 0, 0, reinterpret_cast<intptr>(&event));
          return wxApp::ProcessEvent(event);
        }
        
        bool ProcessIdle() override {
          processIdle();
          return wxApp::wxAppBase::ProcessIdle();
        }
        
        intptr send_message(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr handle) {
          return wnd_proc(hwnd, msg, wparam, lparam, handle);
        }
        
        static bool message_filter(intptr hwnd, int32 msg, intptr wparam, intptr lparam, intptr handle) {
          return message_filter_proc(hwnd, msg, wparam, lparam, handle);
        }
        
        static xtd::event<wx_application, xtd::delegate<bool(intptr, int32, intptr, intptr, intptr)>> message_filter_proc;
        xtd::event<wx_application, xtd::delegate<intptr(intptr, int32, intptr, intptr, intptr)>> wnd_proc;
        xtd::event<wx_application, xtd::delegate<bool()>> thread_exception;
        
        std::exception_ptr exceptionStored;
        xtd::delegate<void()> processIdle;
      };
    }
  }
}

