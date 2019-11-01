#include <xtd/forms/native/file_dialog.hpp>
#include <xtd/forms/window_file_dialog.hpp>
#include <wx/filedlg.h>

using namespace xtd;
using namespace xtd::forms::native;

#if !defined(__APPLE__)
bool file_dialog::run_open_dialog(intptr_t hwnd, const ustring& default_ext, ustring& file_name, std::vector<ustring>& file_names, const ustring& filter, size_t filter_index, const ustring& initial_directory, size_t options, bool support_multi_dotted_extensions, const ustring& title) {
  long wx_style = wxFD_OPEN;
  if ((options & OFN_OVERWRITEPROMPT) == OFN_OVERWRITEPROMPT) wx_style |= wxFD_OVERWRITE_PROMPT;
  if ((options & OFN_NODEREFERENCELINKS) == OFN_NODEREFERENCELINKS) wx_style |= wxFD_NO_FOLLOW;
  if ((options & OFN_FILEMUSTEXIST) == OFN_FILEMUSTEXIST) wx_style |= wxFD_FILE_MUST_EXIST;
  if ((options & OFN_NOCHANGEDIR) != OFN_NOCHANGEDIR) wx_style |= wxFD_CHANGE_DIR;
  if ((options & OFN_SHOWPREVIEW) == OFN_SHOWPREVIEW) wx_style |= wxFD_PREVIEW;
  if ((options & OFN_ALLOWMULTISELECT) == OFN_ALLOWMULTISELECT) wx_style |= wxFD_MULTIPLE;
  //if ((options & OFN_FORCESHOWHIDDEN) == OFN_FORCESHOWHIDDEN) wx_style |= wxFD_SHOW_HIDDEN;
  wxFileDialog dialog(reinterpret_cast<wxWindow*>(hwnd), title.wstr(), initial_directory.wstr(), file_name.wstr(), filter, wx_style);
  if (dialog.ShowModal() != wxID_OK) return false;
  if ((options & OFN_ALLOWMULTISELECT) != OFN_ALLOWMULTISELECT) {
    file_name = dialog.GetPath();
  } else {
    wxArrayString files;
    dialog.GetFilenames(files);
    file_name = files[0].ToStdString();
    for (wxString file : files)
      file_names.push_back(file.ToStdString());
  }
  return true;
}

bool file_dialog::run_save_dialog(intptr_t hwnd, const ustring& default_ext, ustring& file_name, std::vector<ustring>& file_names, const ustring& filter, size_t filter_index, const ustring& initial_directory, size_t options, bool support_multi_dotted_extensions, const ustring& title) {
  long wx_style = wxFD_SAVE;
  wxFileDialog dialog(reinterpret_cast<wxWindow*>(hwnd), title.wstr(), initial_directory.wstr(), file_name.wstr(), filter, wx_style);
  if (dialog.ShowModal() != wxID_OK) return false;
  return true;
}
#endif
