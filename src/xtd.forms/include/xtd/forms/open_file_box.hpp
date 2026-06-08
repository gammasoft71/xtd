/// @file
/// @brief Contains xtd::forms::open_file_box control.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
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
    /// | Light |  @image html dialog_open_file_dialog_w.png   |  @image html dialog_open_file_dialog_m.png   |  @image html dialog_open_file_dialog_g.png   |
    /// | Dark  |  @image html dialog_open_file_dialog_wd.png  |  @image html dialog_open_file_dialog_md.png  |  @image html dialog_open_file_dialog_gd.png  |
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
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::forms::iwin32_window& owner) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box in front of a specified window.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::string& title) -> xtd::forms::dialog_result;
      
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::string& title, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::string& title, const xtd::string& initial_directory) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::string& title, const xtd::string& initial_directory, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter) -> xtd::forms::dialog_result;
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::string that will store the selected file name.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::string& file_name, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box in front of a specified window.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param owner An xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::forms::iwin32_window& owner, const xtd::string& title, const xtd::string& initial_directory,  const xtd::string& filter, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::string& title) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::string& title, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::string& title, const xtd::string& initial_directory) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::string& title, const xtd::string& initial_directory, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::string& title, const xtd::string& initial_directory, const xtd::string& filter) -> xtd::forms::dialog_result;
      /// @brief Displays a multiple file select dialog box.
      /// @param file_names An output xtd::array <xtd::string> that will store the selected file names.
      /// @param title An xtd::string that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::string that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::string that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::open_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is xtd::forms::dialog_result::ok, the output file_names parameter will contain the selected file paths, otherwise it will be ignored.
      [[nodiscard]] static auto show(xtd::array<xtd::string>& file_names, const xtd::string& title, const xtd::string& initial_directory, const xtd::string& filter, const xtd::forms::open_file_box_options options) -> xtd::forms::dialog_result;
      /// @}
      
    private:
      template<const bool multiselect, typename output_t>
      [[nodiscard]] static auto show_open_file_box(output_t& output, const xtd::string& title, const xtd::string& initial_directory = xtd::string::empty_string, const xtd::string& filter = xtd::string::empty_string, const xtd::forms::open_file_box_options options = xtd::forms::open_file_box_options::none, const xtd::forms::iwin32_window* owner = nullptr) -> xtd::forms::dialog_result {
        auto dialog = xtd::forms::open_file_dialog {};
        dialog.multiselect(multiselect)
          .title(title)
          .initial_directory(initial_directory)
          .filter(filter)
          .check_file_exists((options & xtd::forms::open_file_box_options::check_file_exists) == xtd::forms::open_file_box_options::check_file_exists)
          .dereference_link((options & xtd::forms::open_file_box_options::dereference_link) == xtd::forms::open_file_box_options::dereference_link)
          .validate_names((options & xtd::forms::open_file_box_options::validate_names) == xtd::forms::open_file_box_options::validate_names)
          .restore_directory((options & xtd::forms::open_file_box_options::restore_directory) == xtd::forms::open_file_box_options::restore_directory)
          .auto_upgrade_enabled((options & xtd::forms::open_file_box_options::enable_auto_upgrade) == xtd::forms::open_file_box_options::enable_auto_upgrade)
          .show_hidden_files((options & xtd::forms::open_file_box_options::show_hidden_files) == xtd::forms::open_file_box_options::show_hidden_files)
          .show_help((options & xtd::forms::open_file_box_options::show_help) == xtd::forms::open_file_box_options::show_help)
          .show_preview((options & xtd::forms::open_file_box_options::show_preview) == xtd::forms::open_file_box_options::show_preview)
          .support_multi_dotted_extensions((options & xtd::forms::open_file_box_options::support_multi_dotted_extensions) == xtd::forms::open_file_box_options::support_multi_dotted_extensions);
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
