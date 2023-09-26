#include "../../../include/xtd/forms/folder_browser_box"
#include "../../../include/xtd/forms/folder_browser_dialog"

using namespace xtd;
using namespace xtd::forms;

dialog_result folder_browser_box::show(ustring& selected_path, const iwin32_window& owner) {
  return show_folder_browser_box(selected_path, "", environment::special_folder::desktop, true, true, &owner);
}

dialog_result folder_browser_box::show(ustring& selected_path, const iwin32_window& owner, const ustring& description) {
  return show_folder_browser_box(selected_path, description, environment::special_folder::desktop, true, true, &owner);
}

dialog_result folder_browser_box::show(ustring& selected_path, const iwin32_window& owner, const ustring& description, environment::special_folder root_folder) {
  return show_folder_browser_box(selected_path, description, root_folder, true, true, &owner);
}

dialog_result folder_browser_box::show(ustring& selected_path, const iwin32_window& owner, const ustring& description, environment::special_folder root_folder, bool show_new_folder_button) {
  return show_folder_browser_box(selected_path, description, root_folder, show_new_folder_button, true, &owner);
}

dialog_result folder_browser_box::show(ustring& selected_path, const iwin32_window& owner, const ustring& description, environment::special_folder root_folder, bool show_new_folder_button, bool auto_upgrade_enable) {
  return show_folder_browser_box(selected_path, description, root_folder, show_new_folder_button, auto_upgrade_enable, &owner);
}

dialog_result folder_browser_box::show(ustring& selected_path) {
  return show_folder_browser_box(selected_path);
}

dialog_result folder_browser_box::show(ustring& selected_path, const ustring& description) {
  return show_folder_browser_box(selected_path, description);
}

dialog_result folder_browser_box::show(ustring& selected_path, const ustring& description, environment::special_folder root_folder) {
  return show_folder_browser_box(selected_path, description, root_folder);
}

dialog_result folder_browser_box::show(ustring& selected_path, const ustring& description, environment::special_folder root_folder, bool show_new_folder_button) {
  return show_folder_browser_box(selected_path, description, root_folder, show_new_folder_button);
}

dialog_result folder_browser_box::show(ustring& selected_path, const ustring& description, environment::special_folder root_folder, bool show_new_folder_button, bool auto_upgrade_enable) {
  return show_folder_browser_box(selected_path, description, root_folder, show_new_folder_button, auto_upgrade_enable);
}

dialog_result folder_browser_box::show_folder_browser_box(ustring& selected_path, const ustring& description, environment::special_folder root_folder, bool show_new_folder_button, bool auto_upgrade_enable, const iwin32_window* owner) {
  auto dialog = folder_browser_dialog {};
  dialog.description(description).root_folder(root_folder).show_new_folder_button(show_new_folder_button).auto_upgrade_enable(auto_upgrade_enable).selected_path(selected_path);
  const auto result = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
  if (result == dialog_result::ok) selected_path = dialog.selected_path();
  return result;
}
