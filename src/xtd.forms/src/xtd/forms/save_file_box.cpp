#include "../../../include/xtd/forms/save_file_box"
#include "../../../include/xtd/forms/save_file_dialog"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner) {
  return show_save_file_box(file_name, "", "", "", save_file_box_options::none, &owner);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title) {
  return show_save_file_box(file_name, title, "", "", save_file_box_options::none, &owner);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const save_file_box_options options) {
  return show_save_file_box(file_name, title, "", "", options, &owner);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory) {
  return show_save_file_box(file_name, title, initial_directory, "", save_file_box_options::none, &owner);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory, const save_file_box_options options) {
  return show_save_file_box(file_name, title, initial_directory, "", options, &owner);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter) {
  return show_save_file_box(file_name, title, initial_directory, filter, save_file_box_options::none, &owner);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter, const save_file_box_options options) {
  return show_save_file_box(file_name, title, initial_directory, filter, options, &owner);
}

dialog_result save_file_box::show(xtd::ustring& file_name) {
  return show_save_file_box(file_name, "", "", "", save_file_box_options::none, nullptr);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::ustring& title) {
  return show_save_file_box(file_name, title, "", "", save_file_box_options::none, nullptr);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::ustring& title, const save_file_box_options options) {
  return show_save_file_box(file_name, title, "", "", options, nullptr);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory) {
  return show_save_file_box(file_name, title, initial_directory, "", save_file_box_options::none, nullptr);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory, const save_file_box_options options) {
  return show_save_file_box(file_name, title, initial_directory, "", options, nullptr);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter) {
  return show_save_file_box(file_name, title, initial_directory, filter, save_file_box_options::none, nullptr);
}

dialog_result save_file_box::show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter, const save_file_box_options options) {
  return show_save_file_box(file_name, title, initial_directory, filter, options, nullptr);
}

dialog_result save_file_box::show_save_file_box(xtd::ustring& output, const xtd::ustring& title, const xtd::ustring& initial_directory, const xtd::ustring& filter, const save_file_box_options options, const iwin32_window* owner) {
  auto dialog = xtd::forms::save_file_dialog {};
  dialog.title(title)
  .initial_directory(initial_directory)
  .file_name(output)
  .filter(filter)
  .check_file_exists((options & save_file_box_options::check_file_exists) == save_file_box_options::check_file_exists)
  .dereference_link((options & save_file_box_options::dereference_link) == save_file_box_options::dereference_link)
  .validate_names((options & save_file_box_options::validate_names) == save_file_box_options::validate_names)
  .restore_directory((options & save_file_box_options::restore_directory) == save_file_box_options::restore_directory)
  .auto_upgrade_enabled((options & save_file_box_options::enable_auto_upgrade) == save_file_box_options::enable_auto_upgrade)
  .show_hidden_files((options & save_file_box_options::show_hidden_files) == save_file_box_options::show_hidden_files)
  .show_help((options & save_file_box_options::show_help) == save_file_box_options::show_help)
  .show_preview((options & save_file_box_options::show_preview) == save_file_box_options::show_preview)
  .support_multi_dotted_extensions((options & save_file_box_options::support_multi_dotted_extensions) == save_file_box_options::support_multi_dotted_extensions);
  const auto res = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
  if (res == dialog_result::ok)
    output = dialog.file_name();
  return res;
}
