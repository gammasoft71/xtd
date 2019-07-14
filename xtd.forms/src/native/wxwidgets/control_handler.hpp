#pragma once

#include <memory>
#include <thread>
#include <xtd/xtd.delegates>
#include "../../../include/xtd/forms/message.hpp"
#include "../../../include/xtd/forms/message.hpp"
#include "../../../include/xtd/forms/window_messages.hpp"
#include "../../../include/xtd/forms/window_message_keys.hpp"
#include <wx/frame.h>

class control_handler;

template<typename TControl>
class control_wrapper : public TControl {
public:
  control_wrapper(control_handler* event_handler, wxWindow *parent, wxWindowID id, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : TControl(parent, id, pos, size, style), event_handler_(event_handler) {}
  control_wrapper(control_handler* event_handler, wxWindow *parent, wxWindowID id, const wxString& label, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = 0) : TControl(parent, id, label, pos, size, style), event_handler_(event_handler) {}
  
  bool Destroy() override;
  
  bool ProcessEvent(wxEvent &event) override;
  void ProcessMouseEvent(wxEvent &event, intptr_t hwnd);

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
  void clear_control() {this->control_ = nullptr;}

private:
  xtd::delegate<void(xtd::forms::message&)> wnd_proc_;
  wxWindow* control_;
};

template<typename TControl>
inline bool control_wrapper<TControl>::Destroy() {
  for (wxWindow* children : this->GetChildren())
    children->Destroy();
  this->event_handler_->clear_control();
  return this->TControl::Destroy();
}

template<typename TControl>
inline bool control_wrapper<TControl>::ProcessEvent(wxEvent& event) {
  wxWindow* window = reinterpret_cast<wxWindow*>(event.GetEventObject());
  if (!window) return this->TControl::ProcessEvent(event);
  intptr_t hwnd = reinterpret_cast<intptr_t>(window->GetHandle());

  // mouse events
  if (event.GetEventType() == wxEVT_LEFT_DOWN || event.GetEventType() == wxEVT_MIDDLE_DOWN || event.GetEventType() == wxEVT_RIGHT_DOWN || event.GetEventType() == wxEVT_LEFT_UP || event.GetEventType() == wxEVT_MIDDLE_UP || event.GetEventType() == wxEVT_RIGHT_UP || event.GetEventType() == wxEVT_MOTION || event.GetEventType() == wxEVT_ENTER_WINDOW || event.GetEventType() == wxEVT_LEAVE_WINDOW || event.GetEventType() == wxEVT_LEFT_DCLICK || event.GetEventType() == wxEVT_MIDDLE_DCLICK || event.GetEventType() == wxEVT_RIGHT_DCLICK || event.GetEventType() == wxEVT_SET_FOCUS || event.GetEventType() == wxEVT_KILL_FOCUS || event.GetEventType() == wxEVT_CHILD_FOCUS || event.GetEventType() == wxEVT_MOUSEWHEEL || event.GetEventType() == wxEVT_AUX1_DOWN || event.GetEventType() == wxEVT_AUX2_DOWN || event.GetEventType() == wxEVT_AUX1_UP || event.GetEventType() == wxEVT_AUX2_UP || event.GetEventType() == wxEVT_AUX1_DCLICK || event.GetEventType() == wxEVT_AUX2_DCLICK /*|| event.GetEventType() == wxEVT_MAGNIFY*/)
    this->ProcessMouseEvent(event, hwnd);

  else if (event.GetEventType() == wxEVT_CLOSE_WINDOW)
    this->event_handler_->send_message(hwnd, WM_CLOSE, 0, 0, reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_DESTROY)
    this->event_handler_->send_message(hwnd, WM_DESTROY, 0, 0, reinterpret_cast<intptr_t>(&event));
  //else if (event.GetEventType() == wxEVT_ENABLE)
  //  this->event_handler_->send_message(hwnd, WM_ENABLE, 0, 0, reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_COMMAND_ENTER)
    this->event_handler_->send_message(hwnd, WM_COMMAND, 0, 0, reinterpret_cast<intptr_t>(&event));
  //else if (event.GetEventType() == wxEVT_ENTER_SIZEMOVE)
  //  this->event_handler_->send_message(hwnd, WM_ENTERSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
  //else if (event.GetEventType() == wxEVT_EXIT_SIZEMOVE)
  //  this->event_handler_->send_message(hwnd, WM_EXITSIZEMOVE, 0, 0, reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_MOVE)
    this->event_handler_->send_message(hwnd, WM_MOVE, 0, window->GetPosition().x + (window->GetPosition().y << 16), reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_NULL)
    this->event_handler_->send_message(hwnd, WM_NULL, 0, 0, reinterpret_cast<intptr_t>(&event));
  //else if (event.GetEventType() == wxEVT_QUIT)
  //  this->event_handler_->send_message(hwnd, WM_QUIT, 0, 0, reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_SHOW) {
    wxShowEvent& show_event = static_cast<wxShowEvent&>(event);
    this->event_handler_->send_message(hwnd, WM_SHOWWINDOW, show_event.IsShown(), 0, reinterpret_cast<intptr_t>(&event));
  } else if (event.GetEventType() == wxEVT_SIZE)
    this->event_handler_->send_message(hwnd, WM_SIZE, 0, window->GetSize().GetWidth() + (window->GetSize().GetHeight() << 16), reinterpret_cast<intptr_t>(&event));
  else if (event.GetEventType() == wxEVT_TEXT) {
    wxCStrData str_data = static_cast<wxCommandEvent&>(event).GetString().c_str();
    const char* str = str_data.AsChar();
    this->event_handler_->send_message(hwnd, WM_SETTEXT, 0, reinterpret_cast<intptr_t>(str), reinterpret_cast<intptr_t>(&event));
  }
  
  return this->TControl::ProcessEvent(event);
}

template<typename TControl>
inline void control_wrapper<TControl>::ProcessMouseEvent(wxEvent& event, intptr_t hwnd) {
  wxMouseEvent& mouse_event = static_cast<wxMouseEvent&>(event);
  wxMouseState mouse_state = wxGetMouseState();
  int virtual_keys = 0;
  if (mouse_state.ControlDown()) virtual_keys += MK_CONTROL;
  if (mouse_state.ShiftDown()) virtual_keys += MK_SHIFT;
  if (mouse_state.LeftIsDown()) virtual_keys += MK_LBUTTON;
  if (mouse_state.MiddleIsDown()) virtual_keys += MK_MBUTTON;
  if (mouse_state.RightIsDown()) virtual_keys += MK_RBUTTON;
  if (mouse_state.Aux1IsDown()) virtual_keys += MK_XBUTTON1;
  if (mouse_state.Aux2IsDown()) virtual_keys += MK_XBUTTON2;

  if (event.GetEventType() == wxEVT_LEFT_DOWN)
    event_handler_->send_message(hwnd, WM_LBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MIDDLE_DOWN)
    event_handler_->send_message(hwnd, WM_MBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_RIGHT_DOWN)
    event_handler_->send_message(hwnd, WM_RBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_LEFT_UP)
    event_handler_->send_message(hwnd, WM_LBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MIDDLE_UP)
    event_handler_->send_message(hwnd, WM_MBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_RIGHT_UP)
    event_handler_->send_message(hwnd, WM_RBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MOTION)
    event_handler_->send_message(hwnd, WM_MOUSEMOVE, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_ENTER_WINDOW)
    event_handler_->send_message(hwnd, WM_MOUSEENTER, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_LEAVE_WINDOW)
    event_handler_->send_message(hwnd, WM_MOUSELEAVE, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_LEFT_DCLICK)
    event_handler_->send_message(hwnd, WM_LBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MIDDLE_DCLICK)
    event_handler_->send_message(hwnd, WM_MBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_RIGHT_DCLICK)
    event_handler_->send_message(hwnd, WM_RBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_SET_FOCUS)
    event_handler_->send_message(hwnd, WM_SETFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_KILL_FOCUS)
    event_handler_->send_message(hwnd, WM_KILLFOCUS, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_CHILD_FOCUS)
    event_handler_->send_message(hwnd, WM_CHILDACTIVATE, 0, 0, reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_MOUSEWHEEL)
    event_handler_->send_message(hwnd, WM_MOUSEWHEEL, virtual_keys + (mouse_event.GetWheelDelta() << 16), mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_AUX1_DOWN || event.GetEventType() == wxEVT_AUX2_DOWN)
    event_handler_->send_message(hwnd, WM_XBUTTONDOWN, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_AUX1_UP || event.GetEventType() == wxEVT_AUX2_UP)
    event_handler_->send_message(hwnd, WM_XBUTTONUP, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
  if (event.GetEventType() == wxEVT_AUX1_DCLICK || event.GetEventType() == wxEVT_AUX2_DCLICK)
    event_handler_->send_message(hwnd, WM_XBUTTONDBLCLK, virtual_keys, mouse_state.GetX() + (mouse_state.GetY() << 16), reinterpret_cast<intptr_t>(&event));
}
