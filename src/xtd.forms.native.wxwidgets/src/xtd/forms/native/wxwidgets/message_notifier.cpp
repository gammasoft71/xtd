#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include <xtd/forms/native/message_notifier>
#include <xtd/forms/native/message_notifier_styles>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/convert_string>
#include <wx/app.h>
#include <wx/notifmsg.h>
#include <wx/icon.h>

using namespace xtd;
using namespace xtd::forms::native;

//int32 convert_to_buttons(uint32 style){
//    switch(style)
//    {
//
//    }
//}

int32 convert_to_icon(uint32 style) {
  if ((style & NIIF_INFO) == NIIF_INFO) return wxICON_INFORMATION;
  if ((style & NIIF_WARNING) == NIIF_WARNING) return wxICON_WARNING;
  if ((style & NIIF_ERROR) == NIIF_ERROR) return wxICON_ERROR;
  return wxICON_NONE;
}


void message_notifier::show(intptr hwnd, const xtd::ustring& title,
  const xtd::ustring& message,
  const xtd::drawing::icon& icon,
  uint32 style,
  bool close_timeout_enabled_,
  std::chrono::system_clock::duration close_timeout_interval,
  xtd::delegate<void()> on_notifier_closed) {
  
  if (!wxTheApp) throw argument_exception {csf_};
  auto notifmsg = std::make_unique<wxNotificationMessage>();
  notifmsg->SetParent(hwnd == 0 ? nullptr : reinterpret_cast<control_handler*>(hwnd)->control());
  notifmsg->SetTitle(convert_string::to_wstring(title));
  notifmsg->SetMessage(convert_string::to_wstring(message));
  if (icon != xtd::drawing::icon::empty)
    notifmsg->SetIcon(reinterpret_cast<wxIconBundle*>(icon.handle())->GetIcon());
  else
    notifmsg->SetFlags(convert_to_icon(style));
    
  // Events
  notifmsg->Bind(wxEVT_NOTIFICATION_MESSAGE_DISMISSED, [on_notifier_closed](wxCommandEvent & event) {
    on_notifier_closed();
    event.Skip();
  });
  //   notifmsg->Bind(wxEVT_NOTIFICATION_MESSAGE_CLICK, [on_notifier_closed](wxCommandEvent& event) {
  //       on_notifier_closed();
  //       event.Skip();
  //    });
  //   notifmsg->Bind(wxEVT_NOTIFICATION_MESSAGE_ACTION, [on_notifier_closed](wxCommandEvent& event) {
  //       on_notifier_closed(/*event.GetId()*/);
  //       event.Skip();
  //    });
  
  notifmsg->Show(close_timeout_enabled_ ? static_cast<int32>(std::chrono::duration_cast<std::chrono::seconds>(close_timeout_interval).count()) : static_cast<int32>(wxNotificationMessage::Timeout_Never));
}


