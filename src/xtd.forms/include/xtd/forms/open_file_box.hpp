/// @file
/// @brief Contains xtd::forms::open_file_box control.
/// @copyright Copyright (c) 2025 Gammasoft. All rights reserved.
#pragma once
#include "open_file_box_options.hpp"
#include "open_file_dialog.hpp"
#include <xtd/static>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a file selection dialog. This class cannot be inherited.
    /// @par Header
    /// ```cpp
    /// #include <xtd/forms/open_file_box>
    /// ```
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                      | macOS                                        | Gnome                                        |
    /// | ----- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
    /// | Light |  @image html dialog_open_file_dialog_w.png   |  @image html dialog_open_file_dialog_m.png   |  @image html dialog_open_file_dialog_g.png   |
    /// | Dark  |  @image html dialog_open_file_dialog_wd.png  |  @image html dialog_open_file_dialog_md.png  |  @image html dialog_open_file_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::open_file_box dialog.
    /// @include open_file_box.cpp
    class forms_export_ open_file_box final static_ {
    public:
      /// @name Public Static Methods
      
      /// @{
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::forms::iwin32_window& owner);
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title);
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const open_file_box_options options);
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory);
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory, const open_file_box_options options);
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter);
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter, const open_file_box_options options);
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name);
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::string& title);
      
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::string& title, const open_file_box_options options);
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::string& title, const xtd::string& initial_directory);
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::string& title, const xtd::string& initial_directory, const open_file_box_options options);
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter);
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::string& file_name, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter, const open_file_box_options options);
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title);
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const open_file_box_options options);
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory);
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory, const open_file_box_options options);
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter);
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter, const open_file_box_options options);
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::string& title);
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::string& title, const open_file_box_options options);
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::string& title, const xtd::string& initial_directory);
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::string& title, const xtd::string& initial_directory, const open_file_box_options options);
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::string& title, const xtd::string& initial_directory, const xtd::string& filter);
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output std::vector <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      static xtd::forms::dialog_result show(std::vector<xtd::string>& file_names, const xtd::string& title, const xtd::string& initial_directory, const xtd::string& filter, const open_file_box_options options);
      /// @}
      
    private:
      template<const bool multiselect, typename output_t>
      static xtd::forms::dialog_result show_open_file_box(output_t& output, const xtd::string& title, const xtd::string& initial_directory = xtd::string::empty_string, const xtd::string& filter = xtd::string::empty_string, const open_file_box_options options = open_file_box_options::none, const xtd::forms::iwin32_window* owner = nullptr) {
        auto dialog = xtd::forms::open_file_dialog {};
        dialog.multiselect(multiselect)
        .title(title)
        .initial_directory(initial_directory)
        .filter(filter)
        .check_file_exists((options & open_file_box_options::check_file_exists) == open_file_box_options::check_file_exists)
        .dereference_link((options & open_file_box_options::dereference_link) == open_file_box_options::dereference_link)
        .validate_names((options & open_file_box_options::validate_names) == open_file_box_options::validate_names)
        .restore_directory((options & open_file_box_options::restore_directory) == open_file_box_options::restore_directory)
        .auto_upgrade_enabled((options & open_file_box_options::enable_auto_upgrade) == open_file_box_options::enable_auto_upgrade)
        .show_hidden_files((options & open_file_box_options::show_hidden_files) == open_file_box_options::show_hidden_files)
        .show_help((options & open_file_box_options::show_help) == open_file_box_options::show_help)
        .show_preview((options & open_file_box_options::show_preview) == open_file_box_options::show_preview)
        .support_multi_dotted_extensions((options & open_file_box_options::support_multi_dotted_extensions) == open_file_box_options::support_multi_dotted_extensions);
        if constexpr(!multiselect) dialog.file_name(output);
        const auto res = owner ? dialog.show_sheet_dialog(*owner) : dialog.show_dialog();
        if (res != dialog_result::ok) return res;
        if constexpr(multiselect) output = dialog.file_names();
        else output = dialog.file_name();
        return res;
      }
    };
  }
}
