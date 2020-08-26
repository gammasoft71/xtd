#include <xtd/forms/native/file_dialog.h>
#include <xtd/forms/file_dialog_flags.h>
#include <wx/filedlg.h>

using namespace std::literals;
using namespace xtd;
using namespace xtd::forms::native;

bool file_dialog::run_open_dialog(intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title) {
  long wx_style = wxFD_OPEN;
  if ((options & OFN_NODEREFERENCELINKS) == OFN_NODEREFERENCELINKS) wx_style |= wxFD_NO_FOLLOW;
  if ((options & OFN_FILEMUSTEXIST) == OFN_FILEMUSTEXIST) wx_style |= wxFD_FILE_MUST_EXIST;
  if ((options & OFN_NOCHANGEDIR) != OFN_NOCHANGEDIR) wx_style |= wxFD_CHANGE_DIR;
  if ((options & OFN_SHOWPREVIEW) == OFN_SHOWPREVIEW) wx_style |= wxFD_PREVIEW;
  if ((options & OFN_ALLOWMULTISELECT) == OFN_ALLOWMULTISELECT) wx_style |= wxFD_MULTIPLE;
  if ((options & OFN_FORCESHOWHIDDEN) == OFN_FORCESHOWHIDDEN) wx_style |= wxFD_SHOW_HIDDEN;
  wxFileDialog dialog(reinterpret_cast<wxWindow*>(hwnd), {title.c_str(), wxMBConvUTF8()}, {initial_directory.c_str(), wxMBConvUTF8()}, {file_name.c_str(), wxMBConvUTF8()}, {filter.c_str(), wxMBConvUTF8()}, wx_style);
  dialog.SetFilterIndex(static_cast<int32_t>(filter_index - 1));
  if (dialog.ShowModal() != wxID_OK) return false;
  if ((options & OFN_ALLOWMULTISELECT) != OFN_ALLOWMULTISELECT) {
    file_name = dialog.GetPath().utf8_str().data();
  } else {
    wxArrayString files;
    dialog.GetFilenames(files);
#if defined(__APPLE__)
    file_name = dialog.GetPath() + files[0].utf8_str().data();
    for (wxString file : files)
      file_names.push_back(dialog.GetDirectory().utf8_str().data() + "/"s + file.utf8_str().data());
#else
    file_name = files[0].utf8_str().data();
    for (wxString file : files)
      file_names.push_back(file.utf8_str().data());
#endif
  }
  return true;
}

bool file_dialog::run_save_dialog(intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title) {
  long wx_style = wxFD_SAVE;
  if ((options & OFN_OVERWRITEPROMPT) == OFN_OVERWRITEPROMPT) wx_style |= wxFD_OVERWRITE_PROMPT;
  if ((options & OFN_NODEREFERENCELINKS) == OFN_NODEREFERENCELINKS) wx_style |= wxFD_NO_FOLLOW;
  if ((options & OFN_NOCHANGEDIR) != OFN_NOCHANGEDIR) wx_style |= wxFD_CHANGE_DIR;
  if ((options & OFN_SHOWPREVIEW) == OFN_SHOWPREVIEW) wx_style |= wxFD_PREVIEW;
  if ((options & OFN_FORCESHOWHIDDEN) == OFN_FORCESHOWHIDDEN) wx_style |= wxFD_SHOW_HIDDEN;
  wxFileDialog dialog(reinterpret_cast<wxWindow*>(hwnd), {title.c_str(), wxMBConvUTF8()}, {initial_directory.c_str(), wxMBConvUTF8()}, {file_name.c_str(), wxMBConvUTF8()}, {filter.c_str(), wxMBConvUTF8()}, wx_style);
  dialog.SetFilterIndex(static_cast<int32_t>(filter_index - 1));
  if (dialog.ShowModal() != wxID_OK) return false;
  file_name = dialog.GetPath();
  return true;
}
