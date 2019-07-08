#pragma once

#include "../../../include/xtd/forms/message.hpp"
#include "../../../include/xtd/forms/window_messages.hpp"

#include <thread>

#include <xtd/delegates>

#include <wx/frame.h>

template <typename Control>
class wxControlEvent : public Control {
public:
  wxControlEvent(wxWindow *parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : Control(parent, id, pos, size, style) {
    this->send_message((intptr_t)this, WM_CREATE, 0, 0);
  }
  
  wxControlEvent(wxWindow *parent, wxWindowID id, const wxString& label = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : Control(parent, id, label, pos, size, style) {
    this->send_message((intptr_t)this, WM_CREATE, 0, 0);
  }
  
  virtual ~wxControlEvent() {
      this->send_message((intptr_t)this, WM_DESTROY, 0, 0);
  }
  
  bool ProcessEvent (wxEvent &event) override {
    wxWindow* window = ((wxWindow*)event.GetEventObject());

    std::thread::id cti = std::this_thread::get_id();
    if (event.GetEventType() == wxEVT_ACTIVATE_APP) send_message((intptr_t)window, WM_ACTIVATEAPP, true, (intptr_t)&cti);
    if (event.GetEventType() == wxEVT_CLOSE_WINDOW) send_message((intptr_t)window, WM_CLOSE, 0, 0);
    //if (event.GetEventType() == wxEVT_CREATE) send_message((intptr_t)window, WM_CREATE, 0, 0);
    if (event.GetEventType() == wxEVT_DESTROY) send_message((intptr_t)window, WM_DESTROY, 0, 0);
    //if (event.GetEventType() == wxEVT_ENABLE) send_message((intptr_t)window, WM_ENABLE, 0, 0);
    if (event.GetEventType() == wxEVT_COMMAND_ENTER)send_message((intptr_t)window, WM_COMMAND, 0, 0);
    //if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) send_message((intptr_t)window, WM_ENTERSIZEMOVE, 0, 0);
    //if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) send_message((intptr_t)window, WM_EXITSIZEMOVE, 0, 0);
    if (event.GetEventType() == wxEVT_MOVE) send_message((intptr_t)window, WM_MOVE, 0,  window->GetPosition().x + (window->GetPosition().y << 16));
    if (event.GetEventType() == wxEVT_NULL) send_message((intptr_t)window, WM_NULL, 0, 0);
    //if (event.GetEventType() == wxEVT_QUIT) send_message((intptr_t)window, WM_QUIT, 0, 0);
    if (event.GetEventType() == wxEVT_TEXT) send_message((intptr_t)window, WM_SETTEXT, 0, 0);
    if (event.GetEventType() == wxEVT_SHOW) send_message((intptr_t)window, WM_COMMAND, window->IsShown(), 0);
    if (event.GetEventType() == wxEVT_SIZE) send_message((intptr_t)window, WM_SIZE, 0,   window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16));

    return this->Control::ProcessEvent(event);
  }
  
  void register_wnd_proc(std::function<void (xtd::forms::message&)> wnd_proc) {
    this->wnd_proc = wnd_proc;
  }
  
  void unregister_wnd_proc() {
    this->wnd_proc = nullptr;
  }

  void send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam) {
    if (this->wnd_proc != nullptr) {
      xtd::forms::message message = xtd::forms::message::create(hwnd, msg, wparam, lparam, 0);
      this->wnd_proc(message);
    }
  }
  
protected:
  std::function<void (xtd::forms::message&)> wnd_proc;
};
