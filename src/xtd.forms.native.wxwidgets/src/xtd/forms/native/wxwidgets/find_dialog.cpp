#include <xtd/literals.h>
#include <xtd/convert_string.h>
#include <xtd/drawing/system_colors.h>
#define __XTD_FORMS_NATIVE_LIBRARY__
#include <xtd/forms/native/find_dialog.h>
#include "../../../../../include/xtd/forms/native/wxwidgets/control_handler.h"
#include "../../../../../include/xtd/forms/native/wxwidgets/dark_mode.h"
#undef __XTD_FORMS_NATIVE_LIBRARY__
#include <wx/fdrepdlg.h>

using namespace xtd;
using namespace xtd::forms::native;

#if defined(__WXMSW__)
namespace {
  HHOOK handle_hook;
  LRESULT CALLBACK callbackProc(INT ncode, WPARAM wparam, LPARAM lparam) {
    if (ncode == HCBT_ACTIVATE) {
      allow_dark_mode_for_window(static_cast<intptr_t>(wparam));
      refresh_title_bar_theme_color(static_cast<intptr_t>(wparam));
      UnhookWindowsHookEx(handle_hook);
    } else
      CallNextHookEx(handle_hook, ncode, wparam, lparam);
    return 0;
  }
}
#endif

intptr_t find_dialog::create(intptr_t hwnd, const std::optional<xtd::drawing::point>& location, const xtd::ustring& title, const xtd::ustring& find_string, bool show_up_down, bool show_whole_word, bool show_match_case, bool downwards, bool whole_word, bool match_case, callback_t find_next, callback_t dialog_closed) {
  if (!wxTheApp) return 0;

  int32_t find_replace_flags = 0;
  if (downwards) find_replace_flags |= wxFindReplaceFlags::wxFR_DOWN;
  if (whole_word) find_replace_flags |= wxFindReplaceFlags::wxFR_WHOLEWORD;
  if (match_case) find_replace_flags |= wxFindReplaceFlags::wxFR_MATCHCASE;
  wxFindReplaceData* find_replace_data = new wxFindReplaceData();
  find_replace_data->SetFlags(find_replace_flags);
  find_replace_data->SetFindString(convert_string::to_wstring(find_string));
  
#if defined(__WXMSW__)
  handle_hook = SetWindowsHookExW(WH_CBT, &callbackProc, 0, GetCurrentThreadId());
#endif

  int32_t dialog_style = 0;
  if (!show_up_down) dialog_style |= wxFR_NOUPDOWN;
  if (!show_whole_word) dialog_style |= wxFR_NOWHOLEWORD;
  if (!show_match_case) dialog_style |= wxFR_NOMATCHCASE;
  wxFindReplaceDialog* find_replace_dialog = new wxFindReplaceDialog(reinterpret_cast<control_handler*>(hwnd)->control(), find_replace_data, convert_string::to_wstring(title), dialog_style);
#if !defined(__WXMSW__)
  find_replace_dialog->SetMinSize(find_replace_dialog->GetSize());
  find_replace_dialog->SetMaxSize(find_replace_dialog->GetSize());
#endif

  find_replace_dialog->Bind(wxEVT_FIND_CLOSE, [find_replace_dialog, dialog_closed](wxFindDialogEvent& event) {
    auto downwards = (event.GetFlags() & wxFindReplaceFlags::wxFR_DOWN) == wxFindReplaceFlags::wxFR_DOWN;
    auto whole_word = (event.GetFlags() & wxFindReplaceFlags::wxFR_WHOLEWORD) == wxFindReplaceFlags::wxFR_WHOLEWORD;
    auto match_case = (event.GetFlags() & wxFindReplaceFlags::wxFR_MATCHCASE) == wxFindReplaceFlags::wxFR_MATCHCASE;
    auto find_string = event.GetFindString();
    find_replace_dialog->Hide();
    dialog_closed(xtd::drawing::point(find_replace_dialog->GetPosition().x, find_replace_dialog->GetPosition().y), xtd::convert_string::to_string(find_string.c_str().AsWChar()), downwards, whole_word, match_case);
  });
  find_replace_dialog->Bind(wxEVT_FIND, [find_replace_dialog, find_next](wxFindDialogEvent& event) {
    auto downwards = (event.GetFlags() & wxFindReplaceFlags::wxFR_DOWN) == wxFindReplaceFlags::wxFR_DOWN;
    auto whole_word = (event.GetFlags() & wxFindReplaceFlags::wxFR_WHOLEWORD) == wxFindReplaceFlags::wxFR_WHOLEWORD;
    auto match_case = (event.GetFlags() & wxFindReplaceFlags::wxFR_MATCHCASE) == wxFindReplaceFlags::wxFR_MATCHCASE;
    auto find_string = event.GetFindString();
    find_next(xtd::drawing::point(find_replace_dialog->GetPosition().x, find_replace_dialog->GetPosition().y), xtd::convert_string::to_string(find_string.c_str().AsWChar()), downwards, whole_word, match_case);
  });
  find_replace_dialog->Bind(wxEVT_FIND_NEXT, [find_replace_dialog, find_next](wxFindDialogEvent& event) {
    auto downwards = (event.GetFlags() & wxFindReplaceFlags::wxFR_DOWN) == wxFindReplaceFlags::wxFR_DOWN;
    auto whole_word = (event.GetFlags() & wxFindReplaceFlags::wxFR_WHOLEWORD) == wxFindReplaceFlags::wxFR_WHOLEWORD;
    auto match_case = (event.GetFlags() & wxFindReplaceFlags::wxFR_MATCHCASE) == wxFindReplaceFlags::wxFR_MATCHCASE;
    auto find_string = event.GetFindString();
    find_next(xtd::drawing::point(find_replace_dialog->GetPosition().x, find_replace_dialog->GetPosition().y), xtd::convert_string::to_string(find_string.c_str().AsWChar()), downwards, whole_word, match_case);
  });
  
  if (location.has_value())
    find_replace_dialog->SetPosition({location.value().x(), location.value().y()});

  return reinterpret_cast<intptr_t>(find_replace_dialog);
}

void find_dialog::close(intptr_t dialog) {
  if (!dialog || !wxTheApp) return;
  
  reinterpret_cast<wxFindReplaceDialog*>(dialog)->Hide();
}

void find_dialog::destroy(intptr_t dialog) {
  if (!dialog || !wxTheApp) return;
  
  auto data = reinterpret_cast<wxFindReplaceDialog*>(dialog)->GetData();
  reinterpret_cast<wxFindReplaceDialog*>(dialog)->Destroy();
  delete data;
}

void find_dialog::show(intptr_t dialog) {
  if (!dialog || !wxTheApp) return;

  reinterpret_cast<wxFindReplaceDialog*>(dialog)->Show();
}
