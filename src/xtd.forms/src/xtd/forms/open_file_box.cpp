#include "../../../include/xtd/forms/open_file_box.hpp"

using namespace xtd;
using namespace xtd::forms;

dialog_result open_file_box::show(string& file_name, const iwin32_window& owner) {
  return show_open_file_box<false>(file_name, string::empty_string, string::empty_string, string::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(string& file_name, const iwin32_window& owner, const string& title) {
  return show_open_file_box<false>(file_name, title, string::empty_string, string::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(string& file_name, const iwin32_window& owner, const string& title, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, string::empty_string, string::empty_string, options, &owner);
}

dialog_result open_file_box::show(string& file_name, const iwin32_window& owner, const string& title, const string& initial_directory) {
  return show_open_file_box<false>(file_name, title, initial_directory, string::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(string& file_name, const iwin32_window& owner, const string& title, const string& initial_directory, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, initial_directory, string::empty_string, options, &owner);
}

dialog_result open_file_box::show(string& file_name, const iwin32_window& owner, const string& title, const string& initial_directory,  const string& filter) {
  return show_open_file_box<false>(file_name, title, initial_directory, filter, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(string& file_name, const iwin32_window& owner, const string& title, const string& initial_directory,  const string& filter, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, initial_directory, filter, options, &owner);
}

dialog_result open_file_box::show(string& file_name) {
  return show_open_file_box<false>(file_name, string::empty_string, string::empty_string, string::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(string& file_name, const string& title) {
  return show_open_file_box<false>(file_name, title, string::empty_string, string::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(string& file_name, const string& title, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, string::empty_string, string::empty_string, options, nullptr);
}

dialog_result open_file_box::show(string& file_name, const string& title, const string& initial_directory) {
  return show_open_file_box<false>(file_name, title, initial_directory, string::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(string& file_name, const string& title, const string& initial_directory, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, initial_directory, string::empty_string, options, nullptr);
}

dialog_result open_file_box::show(string& file_name, const string& title, const string& initial_directory,  const string& filter) {
  return show_open_file_box<false>(file_name, title, initial_directory, filter, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(string& file_name, const string& title, const string& initial_directory,  const string& filter, const open_file_box_options options) {
  return show_open_file_box<false>(file_name, title, initial_directory, filter, options, nullptr);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const iwin32_window& owner, const string& title) {
  return show_open_file_box<true>(file_names, title, string::empty_string, string::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const iwin32_window& owner, const string& title, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, string::empty_string, string::empty_string, options, &owner);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const iwin32_window& owner, const string& title, const string& initial_directory) {
  return show_open_file_box<true>(file_names, title, initial_directory, string::empty_string, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const iwin32_window& owner, const string& title, const string& initial_directory, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, initial_directory, string::empty_string, options, &owner);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const iwin32_window& owner, const string& title, const string& initial_directory,  const string& filter) {
  return show_open_file_box<true>(file_names, title, initial_directory, filter, open_file_box_options::none, &owner);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const iwin32_window& owner, const string& title, const string& initial_directory,  const string& filter, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, initial_directory, filter, options, &owner);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const string& title) {
  return show_open_file_box<true>(file_names, title, string::empty_string, string::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const string& title, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, string::empty_string, string::empty_string, options, nullptr);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const string& title, const string& initial_directory) {
  return show_open_file_box<true>(file_names, title, initial_directory, string::empty_string, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const string& title, const string& initial_directory, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, initial_directory, string::empty_string, options, nullptr);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const string& title, const string& initial_directory, const string& filter) {
  return show_open_file_box<true>(file_names, title, initial_directory, filter, open_file_box_options::none, nullptr);
}

dialog_result open_file_box::show(std::vector<string>& file_names, const string& title, const string& initial_directory, const string& filter, const open_file_box_options options) {
  return show_open_file_box<true>(file_names, title, initial_directory, filter, options, nullptr);
}
