#pragma once

#include <memory>
#include <thread>
#include <xtd/delegates>
#include "../../../include/xtd/forms/message.hpp"
#include "../../../include/xtd/forms/message.hpp"
#include "../../../include/xtd/forms/window_messages.hpp"
#include <wx/frame.h>

class control_handler;

template<typename TControl>
class control_wrapper : public TControl {
public:
  control_wrapper(control_handler* event_handler, wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : TControl(parent, id, pos, size, style), event_handler_(event_handler) {}
  control_wrapper(control_handler* event_handler, wxWindow *parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : TControl(parent, id, label, pos, size, style), event_handler_(event_handler) {}
  
  bool ProcessEvent(wxEvent &event) override;

private:
  control_handler* event_handler_;
};

class control_handler {
public:
  control_handler() = default;

  template<typename control>
  void create(wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
    this->control_ = new control_wrapper<control>(this, parent, id, pos, size, style);
  }
  
  template<typename control>
  void create(wxWindow *parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) {
    this->control_ = new control_wrapper<control>(this, parent, id, label, pos, size, style);
  }

  void register_wnd_proc(xtd::delegate<void(xtd::forms::message&)> wnd_proc) {
    this->wnd_proc_ = wnd_proc;
  }
  
  void unregister_wnd_proc() {
    //this->wnd_proc_ = xtd::delegate<void(xtd::forms::message&)>();
  }
  
  intptr_t send_message(intptr_t hwnd, int msg, intptr_t wparam, intptr_t lparam, intptr_t handle) {
    if (this->wnd_proc_ == nullptr) return -1;
    xtd::forms::message message = xtd::forms::message::create(hwnd, msg, wparam, lparam, 0, handle);
    this->wnd_proc_(message);
    return message.result();
  }

  wxWindow* control() const {return this->control_;}

private:
  xtd::delegate<void(xtd::forms::message&)> wnd_proc_;
  wxWindow* control_;
};

template<typename TControl>
inline bool control_wrapper<TControl>::ProcessEvent(wxEvent &event) {
  wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
  intptr_t hwnd = reinterpret_cast<intptr_t>(window->GetHandle());

  std::thread::id cti = std::this_thread::get_id();
  if (event.GetEventType() == wxEVT_ACTIVATE_APP) event_handler_->send_message(hwnd, WM_ACTIVATEAPP, true, reinterpret_cast<intptr_t>(&cti), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_CLOSE_WINDOW) event_handler_->send_message(hwnd, WM_CLOSE, 0, 0, reinterpret_cast<intptr_t>(&event));
  //if (event.GetEventType() == wxEVT_CREATE) event_handler_->send_message(hwnd, WM_CREATE, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_DESTROY) event_handler_->send_message(hwnd, WM_DESTROY, 0, 0, reinterpret_cast<intptr_t>(&event));
  //if (event.GetEventType() == wxEVT_ENABLE) event_handler_->send_message(hwnd, WM_ENABLE, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_COMMAND_ENTER) event_handler_->send_message(hwnd, WM_COMMAND, 0, 0, reinterpret_cast<intptr_t>(&event));
  //if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE) event_handler_->send_message(hwnd, WM_ENTERSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
  //if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE) event_handler_->send_message(hwnd, WM_EXITSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MOVE) event_handler_->send_message(hwnd, WM_MOVE, 0, window->GetPosition().x + (window->GetPosition().y << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_NULL) event_handler_->send_message(hwnd, WM_NULL, 0, 0, reinterpret_cast<intptr_t>(&event));
  //if (event.GetEventType() == wxEVT_QUIT) event_handler_->send_message(hwnd, WM_QUIT, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_TEXT) event_handler_->send_message(hwnd, WM_SETTEXT, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_SHOW) event_handler_->send_message(hwnd, WM_COMMAND, window->IsShown(), 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_SIZE) event_handler_->send_message(hwnd, WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
  
  return this->TControl::ProcessEvent(event);
}
