#define __XTD_FORMS_NATIVE_LIBRARY__
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#include <xtd/forms/native/replace_dialog>
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/drawing/system_colors>
#include <xtd/convert_string>
#include <xtd/literals>
#include <wx/fdrepdlg.h>
#include <wx/radiobox.h>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
namespace {
  auto handle_hook = HHOOK{};
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

class wxReplaceDialog : public wxFindReplaceDialog {
public:
  wxReplaceDialog(intptr hwnd, wxFindReplaceData* data, const wxString& title, int32 style, xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, const xtd::ustring&, bool, bool)> find_next, xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, const xtd::ustring&, bool, bool, bool)> replace, xtd::delegate<void()> dialog_closed) : wxFindReplaceDialog(reinterpret_cast<control_handler*>(hwnd)->control(), data, title, style), style(style), find_next(find_next), replace(replace), dialog_closed(dialog_closed), hwnd(hwnd) {
    #if !defined(__WXMSW__)
    m_radioDir->Hide();
    #endif
  }
  
  int32 style = 0;
  bool whole_word = false;
  bool match_case = false;
  wxString find_string;
  wxString replace_string;
  xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, const xtd::ustring&, bool, bool)> find_next;
  xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, const xtd::ustring&, bool, bool, bool)> replace;
  xtd::delegate<void()> dialog_closed;
  intptr hwnd = 0;
};

intptr replace_dialog::create(intptr hwnd, const std::optional<xtd::drawing::point>& location, const xtd::ustring& title, const xtd::ustring& find_string, const xtd::ustring& replace_string, bool show_whole_word, bool show_match_case, bool whole_word, bool match_case, xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, const xtd::ustring&, bool, bool)> find_next, xtd::delegate<void(const xtd::drawing::point&, const xtd::ustring&, const xtd::ustring&, bool, bool, bool)> replace, xtd::delegate<void()> dialog_closed) {
  if (!wxTheApp) return 0;
  
  int32 find_replace_flags = 0;
  if (whole_word) find_replace_flags |= wxFindReplaceFlags::wxFR_WHOLEWORD;
  if (match_case) find_replace_flags |= wxFindReplaceFlags::wxFR_MATCHCASE;
  wxFindReplaceData* find_replace_data = new wxFindReplaceData();
  find_replace_data->SetFlags(find_replace_flags);
  find_replace_data->SetFindString(convert_string::to_wstring(find_string));
  find_replace_data->SetReplaceString(convert_string::to_wstring(replace_string));
  
  #if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
  #endif
  
  int32 style = wxFR_REPLACEDIALOG | wxFR_NOUPDOWN;
  if (!show_whole_word) style |= wxFR_NOWHOLEWORD;
  if (!show_match_case) style |= wxFR_NOMATCHCASE;
  wxReplaceDialog* replace_dialog = new wxReplaceDialog(hwnd, find_replace_data, convert_string::to_wstring(title), style, find_next, replace, dialog_closed);
  #if !defined(__WXMSW__)
  replace_dialog->SetMinSize(replace_dialog->GetSize());
  replace_dialog->SetMaxSize(replace_dialog->GetSize());
  #endif
  
  replace_dialog->whole_word = whole_word;
  replace_dialog->match_case = match_case;
  replace_dialog->find_string = convert_string::to_wstring(find_string);
  replace_dialog->replace_string = convert_string::to_wstring(replace_string);
  
  replace_dialog->Bind(wxEVT_FIND_CLOSE, [replace_dialog, dialog_closed](wxFindDialogEvent & event) {
    replace_dialog->Hide();
    dialog_closed();
  });
  
  replace_dialog->Bind(wxEVT_FIND, [replace_dialog, find_next](wxFindDialogEvent & event) {
    replace_dialog->whole_word = (event.GetFlags() & wxFindReplaceFlags::wxFR_WHOLEWORD) == wxFindReplaceFlags::wxFR_WHOLEWORD;
    replace_dialog->match_case = (event.GetFlags() & wxFindReplaceFlags::wxFR_MATCHCASE) == wxFindReplaceFlags::wxFR_MATCHCASE;
    replace_dialog->find_string = event.GetFindString();
    replace_dialog->replace_string = event.GetReplaceString();
    find_next(xtd::drawing::point(replace_dialog->GetPosition().x, replace_dialog->GetPosition().y), xtd::convert_string::to_string(replace_dialog->find_string.c_str().AsWChar()), xtd::convert_string::to_string(replace_dialog->replace_string.c_str().AsWChar()), replace_dialog->whole_word, replace_dialog->match_case);
  });
  
  replace_dialog->Bind(wxEVT_FIND_NEXT, [replace_dialog, find_next](wxFindDialogEvent & event) {
    replace_dialog->whole_word = (event.GetFlags() & wxFindReplaceFlags::wxFR_WHOLEWORD) == wxFindReplaceFlags::wxFR_WHOLEWORD;
    replace_dialog->match_case = (event.GetFlags() & wxFindReplaceFlags::wxFR_MATCHCASE) == wxFindReplaceFlags::wxFR_MATCHCASE;
    replace_dialog->find_string = event.GetFindString();
    replace_dialog->replace_string = event.GetReplaceString();
    find_next(xtd::drawing::point(replace_dialog->GetPosition().x, replace_dialog->GetPosition().y), xtd::convert_string::to_string(replace_dialog->find_string.c_str().AsWChar()), xtd::convert_string::to_string(replace_dialog->replace_string.c_str().AsWChar()), replace_dialog->whole_word, replace_dialog->match_case);
  });
  
  replace_dialog->Bind(wxEVT_FIND_REPLACE, [replace_dialog, replace](wxFindDialogEvent & event) {
    replace_dialog->whole_word = (event.GetFlags() & wxFindReplaceFlags::wxFR_WHOLEWORD) == wxFindReplaceFlags::wxFR_WHOLEWORD;
    replace_dialog->match_case = (event.GetFlags() & wxFindReplaceFlags::wxFR_MATCHCASE) == wxFindReplaceFlags::wxFR_MATCHCASE;
    replace_dialog->find_string = event.GetFindString();
    replace_dialog->replace_string = event.GetReplaceString();
    replace(xtd::drawing::point(replace_dialog->GetPosition().x, replace_dialog->GetPosition().y), xtd::convert_string::to_string(replace_dialog->find_string.c_str().AsWChar()), xtd::convert_string::to_string(replace_dialog->replace_string.c_str().AsWChar()), false, replace_dialog->whole_word, replace_dialog->match_case);
  });
  
  replace_dialog->Bind(wxEVT_FIND_REPLACE_ALL, [replace_dialog, replace](wxFindDialogEvent & event) {
    replace_dialog->whole_word = (event.GetFlags() & wxFindReplaceFlags::wxFR_WHOLEWORD) == wxFindReplaceFlags::wxFR_WHOLEWORD;
    replace_dialog->match_case = (event.GetFlags() & wxFindReplaceFlags::wxFR_MATCHCASE) == wxFindReplaceFlags::wxFR_MATCHCASE;
    replace_dialog->find_string = event.GetFindString();
    replace_dialog->replace_string = event.GetReplaceString();
    replace(xtd::drawing::point(replace_dialog->GetPosition().x, replace_dialog->GetPosition().y), xtd::convert_string::to_string(replace_dialog->find_string.c_str().AsWChar()), xtd::convert_string::to_string(replace_dialog->replace_string.c_str().AsWChar()), true, replace_dialog->whole_word, replace_dialog->match_case);
  });
  
  if (location.has_value())
    replace_dialog->SetPosition({location.value().x(), location.value().y()});
    
  return reinterpret_cast<intptr>(replace_dialog);
}

void replace_dialog::close(intptr dialog) {
  if (!dialog || !wxTheApp) return;
  
  reinterpret_cast<wxReplaceDialog*>(dialog)->Hide();
}

void replace_dialog::destroy(intptr dialog) {
  if (!dialog || !wxTheApp) return;
  
  auto data = reinterpret_cast<wxReplaceDialog*>(dialog)->GetData();
  reinterpret_cast<wxReplaceDialog*>(dialog)->Destroy();
  delete data;
}

void replace_dialog::show(intptr& dialog) {
  if (!dialog || !wxTheApp) return;
  
  auto& old_dialog = *reinterpret_cast<wxReplaceDialog*>(dialog);
  dialog = create(old_dialog.hwnd, xtd::drawing::point(old_dialog.GetPosition().x, old_dialog.GetPosition().y), xtd::convert_string::to_string(old_dialog.GetTitle().c_str().AsWChar()), xtd::convert_string::to_string(old_dialog.find_string.c_str().AsWChar()), xtd::convert_string::to_string(old_dialog.replace_string.c_str().AsWChar()), (old_dialog.style & wxFR_NOWHOLEWORD) != wxFR_NOWHOLEWORD, (old_dialog.style & wxFR_NOMATCHCASE) != wxFR_NOMATCHCASE, old_dialog.whole_word, old_dialog.match_case, old_dialog.find_next, old_dialog.replace, old_dialog.dialog_closed);
  old_dialog.Destroy();
  
  reinterpret_cast<wxReplaceDialog*>(dialog)->Show();
}
