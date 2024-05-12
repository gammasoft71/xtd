#include "../../../include/xtd/forms/open_file_box.h"

using namespace std;
using namespace xtd;
using namespace xtd::forms;

dialog_result open_file_box::show(ustring& file_name, const iwin32_window& owner) {
  return show_open_file_box<false>(file_name, ustring::empty_string, ustring::empty_string, ustring::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(ustring& file_name, const iwin32_window& owner, const ustring& title) {
  return show_open_file_box<false>(file_name, title, ustring::empty_string, ustring::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(ustring& file_name, const iwin32_window& owner, const ustring& title, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, ustring::empty_string, ustring::empty_string, options, &owner);
}

dialog_result open_file_box::show(ustring& file_name, const iwin32_window& owner, const ustring& title, const ustring& initial_directory) {
  return show_open_file_box<false>(file_name, title, initial_directory, ustring::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(ustring& file_name, const iwin32_window& owner, const ustring& title, const ustring& initial_directory, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, initial_directory, ustring::empty_string, options, &owner);
}

dialog_result open_file_box::show(ustring& file_name, const iwin32_window& owner, const ustring& title, const ustring& initial_directory,  const ustring& filter) {
  return show_open_file_box<false>(file_name, title, initial_directory, filter, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(ustring& file_name, const iwin32_window& owner, const ustring& title, const ustring& initial_directory,  const ustring& filter, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, initial_directory, filter, options, &owner);
}

dialog_result open_file_box::show(ustring& file_name) {
  return show_open_file_box<false>(file_name, ustring::empty_string, ustring::empty_string, ustring::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(ustring& file_name, const ustring& title) {
  return show_open_file_box<false>(file_name, title, ustring::empty_string, ustring::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(ustring& file_name, const ustring& title, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, ustring::empty_string, ustring::empty_string, options, nullptr);
}

dialog_result open_file_box::show(ustring& file_name, const ustring& title, const ustring& initial_directory) {
  return show_open_file_box<false>(file_name, title, initial_directory, ustring::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(ustring& file_name, const ustring& title, const ustring& initial_directory, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, initial_directory, ustring::empty_string, options, nullptr);
}

dialog_result open_file_box::show(ustring& file_name, const ustring& title, const ustring& initial_directory,  const ustring& filter) {
  return show_open_file_box<false>(file_name, title, initial_directory, filter, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(ustring& file_name, const ustring& title, const ustring& initial_directory,  const ustring& filter, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, initial_directory, filter, options, nullptr);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const iwin32_window& owner, const ustring& title) {
  return show_open_file_box<true>(file_names, title, ustring::empty_string, ustring::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const iwin32_window& owner, const ustring& title, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, ustring::empty_string, ustring::empty_string, options, &owner);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const iwin32_window& owner, const ustring& title, const ustring& initial_directory) {
  return show_open_file_box<true>(file_names, title, initial_directory, ustring::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const iwin32_window& owner, const ustring& title, const ustring& initial_directory, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, initial_directory, ustring::empty_string, options, &owner);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const iwin32_window& owner, const ustring& title, const ustring& initial_directory,  const ustring& filter) {
  return show_open_file_box<true>(file_names, title, initial_directory, filter, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const iwin32_window& owner, const ustring& title, const ustring& initial_directory,  const ustring& filter, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, initial_directory, filter, options, &owner);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const ustring& title) {
  return show_open_file_box<true>(file_names, title, ustring::empty_string, ustring::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const ustring& title, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, ustring::empty_string, ustring::empty_string, options, nullptr);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const ustring& title, const ustring& initial_directory) {
  return show_open_file_box<true>(file_names, title, initial_directory, ustring::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const ustring& title, const ustring& initial_directory, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, initial_directory, ustring::empty_string, options, nullptr);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const ustring& title, const ustring& initial_directory, const ustring& filter) {
  return show_open_file_box<true>(file_names, title, initial_directory, filter, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(vector<ustring>& file_names, const ustring& title, const ustring& initial_directory, const ustring& filter, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, initial_directory, filter, options, nullptr);
}
