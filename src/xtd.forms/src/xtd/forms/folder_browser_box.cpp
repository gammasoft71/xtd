#include "../../../include/xtd/forms/folder_browser_box.h"

using namespace xtd;
using namespace xtd::forms;

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner) {
  return show_folder_browser_box(selected_path, "", xtd::environment::special_folder::desktop, true, true, &owner);
}

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner, const xtd::ustring& description) {
  return show_folder_browser_box(selected_path, description, xtd::environment::special_folder::desktop, true, true, &owner);
}

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner, const xtd::ustring& description, xtd::environment::special_folder root_folder) {
  return show_folder_browser_box(selected_path, description, root_folder, true, true, &owner);
}

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner, const xtd::ustring& description, xtd::environment::special_folder root_folder, bool show_new_folder_button) {
  return show_folder_browser_box(selected_path, description, root_folder, show_new_folder_button, true, &owner);
}

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path, const xtd::forms::iwin32_window& owner, const xtd::ustring& description, xtd::environment::special_folder root_folder, bool show_new_folder_button, bool auto_upgrade_enable) {
  return show_folder_browser_box(selected_path, description, root_folder, show_new_folder_button, auto_upgrade_enable, &owner);
}

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path) {
  return show_folder_browser_box(selected_path);
}

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path, const xtd::ustring& description) {
  return show_folder_browser_box(selected_path, description);
}

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path, const xtd::ustring& description, xtd::environment::special_folder root_folder) {
  return show_folder_browser_box(selected_path, description, root_folder);
}

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path, const xtd::ustring& description, xtd::environment::special_folder root_folder, bool show_new_folder_button) {
  return show_folder_browser_box(selected_path, description, root_folder, show_new_folder_button);
}

xtd::forms::dialog_result folder_browser_box::show(xtd::ustring& selected_path, const xtd::ustring& description, xtd::environment::special_folder root_folder, bool show_new_folder_button, bool auto_upgrade_enable) {
  return show_folder_browser_box(selected_path, description, root_folder, show_new_folder_button, auto_upgrade_enable);
}

xtd::forms::dialog_result folder_browser_box::show_folder_browser_box(xtd::ustring& selected_path, const xtd::ustring& description, xtd::environment::special_folder root_folder, bool show_new_folder_button, bool auto_upgrade_enable, const iwin32_window* owner) {
  xtd::forms::folder_browser_dialog dialog;
  dialog.description(description).root_folder(root_folder).show_new_folder_button(show_new_folder_button).auto_upgrade_enable(auto_upgrade_enable).selected_path(selected_path);
  const auto result = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
  if (result == dialog_result::ok) selected_path = dialog.selected_path();
  return result;
}
