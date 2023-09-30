#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include <xtd/forms/native/find_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_colors>
#include <xtd/convert_string>
#include <xtd/literals>
#include <wx/fdrepdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
namespace {
  HHOOK handle_hook;
  LRESULT CALLBACK callbackProc(INT ncode, WPARAM wparam, LPARAM lparam) {
    if (ncode == HCBT_ACTIVATE) {
      allow_dark_mode_for_window(static_cast<intptr>(wparam));
      refresh_title_bar_theme_color(static_cast<intptr>(wparam));
      UnhookWindowsHookEx(handle_hook);
    } else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
}
#endif

class wxFindDialog : public wxFindReplaceDialog {
public:
  wxFindDialog(intptr hwnd, wxFindReplaceData* data, const wxString& title, int32 style, xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, bool, bool, bool)> find_next, xtd::delegate<void()> dialog_closed) : wxFindReplaceDialog(reinterpret_cast<control_handler*>(hwnd)->control(), data, title, style), style(style), find_next(find_next), dialog_closed(dialog_closed), hwnd(hwnd) {}
  
  int32 style = 0;
  bool downwards = true;
  bool whole_word = false;
  bool match_case = false;
  wxString find_string;
  xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, bool, bool, bool)> find_next;
  xtd::delegate<void()> dialog_closed;
  intptr hwnd = 0;
};

intptr find_dialog::create(intptr hwnd, const std::optional<xtd::drawing::point>& location, const xtd::ustring& title, const xtd::ustring& find_string, bool show_up_down, bool show_whole_word, bool show_match_case, bool downwards, bool whole_word, bool match_case, xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, bool, bool, bool)> find_next, xtd::delegate<void()> dialog_closed) {
  if (!wxTheApp) return 0;
  
  int32 find_replace_flags = 0;
  if (downwards) find_replace_flags |= wxFindReplaceFlags::wxFR_DOWN;
  if (whole_word) find_replace_flags |= wxFindReplaceFlags::wxFR_WHOLEWORD;
  if (match_case) find_replace_flags |= wxFindReplaceFlags::wxFR_MATCHCASE;
  wxFindReplaceData* find_replace_data = new wxFindReplaceData();
  find_replace_data->SetFlags(find_replace_flags);
  find_replace_data->SetFindString(convert_string::to_wstring(find_string));
  
  #if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
  #endif
  
  int32 style = 0;
  if (!show_up_down) style |= wxFR_NOUPDOWN;
  if (!show_whole_word) style |= wxFR_NOWHOLEWORD;
  if (!show_match_case) style |= wxFR_NOMATCHCASE;
  wxFindDialog* find_dialog = new wxFindDialog(hwnd, find_replace_data, convert_string::to_wstring(title), style, find_next, dialog_closed);
  #if !defined(__WXMSW__)
  find_dialog->SetMinSize(find_dialog->GetSize());
  find_dialog->SetMaxSize(find_dialog->GetSize());
  #endif
  
  find_dialog->downwards = downwards;
  find_dialog->whole_word = whole_word;
  find_dialog->match_case = match_case;
  find_dialog->find_string = convert_string::to_wstring(find_string);
  
  find_dialog->Bind(wxEVT_FIND_CLOSE, [find_dialog, dialog_closed](wxFindDialogEvent & event) {
    find_dialog->Hide();
    dialog_closed();
  });
  
  find_dialog->Bind(wxEVT_FIND, [find_dialog, find_next](wxFindDialogEvent & event) {
    find_dialog->downwards = (event.GetFlags() & wxFindReplaceFlags::wxFR_DOWN) == wxFindReplaceFlags::wxFR_DOWN;
    find_dialog->whole_word = (event.GetFlags() & wxFindReplaceFlags::wxFR_WHOLEWORD) == wxFindReplaceFlags::wxFR_WHOLEWORD;
    find_dialog->match_case = (event.GetFlags() & wxFindReplaceFlags::wxFR_MATCHCASE) == wxFindReplaceFlags::wxFR_MATCHCASE;
    find_dialog->find_string = event.GetFindString();
    find_next(xtd::drawing::point(find_dialog->GetPosition().x, find_dialog->GetPosition().y), xtd::convert_string::to_string(find_dialog->find_string.c_str().AsWChar()), find_dialog->downwards, find_dialog->whole_word, find_dialog->match_case);
  });
  
  find_dialog->Bind(wxEVT_FIND_NEXT, [find_dialog, find_next](wxFindDialogEvent & event) {
    find_dialog->downwards = (event.GetFlags() & wxFindReplaceFlags::wxFR_DOWN) == wxFindReplaceFlags::wxFR_DOWN;
    find_dialog->whole_word = (event.GetFlags() & wxFindReplaceFlags::wxFR_WHOLEWORD) == wxFindReplaceFlags::wxFR_WHOLEWORD;
    find_dialog->match_case = (event.GetFlags() & wxFindReplaceFlags::wxFR_MATCHCASE) == wxFindReplaceFlags::wxFR_MATCHCASE;
    find_dialog->find_string = event.GetFindString();
    find_next(xtd::drawing::point(find_dialog->GetPosition().x, find_dialog->GetPosition().y), xtd::convert_string::to_string(find_dialog->find_string.c_str().AsWChar()), find_dialog->downwards, find_dialog->whole_word, find_dialog->match_case);
  });
  
  if (location.has_value())
    find_dialog->SetPosition({location.value().x(), location.value().y()});
    
  return reinterpret_cast<intptr>(find_dialog);
}

void find_dialog::close(intptr dialog) {
  if (!dialog || !wxTheApp) return;
  
  reinterpret_cast<wxFindDialog*>(dialog)->Hide();
}

void find_dialog::destroy(intptr dialog) {
  if (!dialog || !wxTheApp) return;
  
  auto data = reinterpret_cast<wxFindDialog*>(dialog)->GetData();
  reinterpret_cast<wxFindDialog*>(dialog)->Destroy();
  delete data;
}

void find_dialog::show(intptr& dialog) {
  if (!dialog || !wxTheApp) return;
  
  auto& old_dialog = *reinterpret_cast<wxFindDialog*>(dialog);
  dialog = create(old_dialog.hwnd, xtd::drawing::point(old_dialog.GetPosition().x, old_dialog.GetPosition().y), xtd::convert_string::to_string(old_dialog.GetTitle().c_str().AsWChar()), xtd::convert_string::to_string(old_dialog.find_string.c_str().AsWChar()), (old_dialog.style & wxFR_NOUPDOWN) != wxFR_NOUPDOWN, (old_dialog.style & wxFR_NOWHOLEWORD) != wxFR_NOWHOLEWORD, (old_dialog.style & wxFR_NOMATCHCASE) != wxFR_NOMATCHCASE, old_dialog.downwards, old_dialog.whole_word, old_dialog.match_case, old_dialog.find_next, old_dialog.dialog_closed);
  old_dialog.Destroy();
  
  reinterpret_cast<wxFindDialog*>(dialog)->Show();
}
