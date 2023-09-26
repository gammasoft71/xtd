/// @file
/// @brief Contains xtd::forms::save_file_box control.
/// @copyright Copyright (c) 2023 Gammasoft. All rights reserved.
#pragma once
#include "../forms_export"
#include "dialog_result"
#include "iwin32_window"
#include "save_file_box_options"
#include <xtd/static>
#include <xtd/ustring>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    /// @brief Represents a common dialog box that displays a file save dialog to the user to select a location for saving a file.
    /// @par Header
    /// @code #include <xtd/forms/save_file_box> @endcode
    /// @par Namespace
    /// xtd::forms
    /// @par Library
    /// xtd.forms
    /// @ingroup xtd_forms dialogs
    /// @par Appearance
    /// |       | Windows                                      | macOS                                        | Gnome                                        |
    /// | ----- | -------------------------------------------- | -------------------------------------------- | -------------------------------------------- |
    /// | Light |  @image html dialog_save_file_dialog_w.png   |  @image html dialog_save_file_dialog_m.png   |  @image html dialog_save_file_dialog_g.png   |
    /// | Dark  |  @image html dialog_save_file_dialog_wd.png  |  @image html dialog_save_file_dialog_md.png  |  @image html dialog_save_file_dialog_gd.png  |
    /// @par Examples
    /// The following code example demonstrates the use of xtd::forms::save_file_box dialog.
    /// @include save_file_box.cpp
    class forms_export_ save_file_box final static_ {
    public:
      /// @name Methods
      
      /// @{
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner);
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title);
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const save_file_box_options options);
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory);
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory, const save_file_box_options options);
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::ustring that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter);
      
      /// @brief Displays a save file dialog box in front of a specified window.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param owner An If xtd::forms::iwin32_window that represents the owner window of the file dialog box.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::ustring that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::forms::iwin32_window& owner, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter, const save_file_box_options options);
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name);
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title);
      
      /// @brief Displays a select file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const save_file_box_options options);
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory);
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory, const save_file_box_options options);
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::ustring that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter);
      
      /// @brief Displays a save file dialog box.
      /// @param file_name An output xtd::ustring that will store the selected file name.
      /// @param title An xtd::ustring that specifies the caption title of the file dialog box.
      /// @param initial_directory An xtd::ustring that specifies the initial directory displayed by the file dialog box
      /// @param filter An xtd::ustring that specifies the file name filter string, which determines the choices that appear in the "Save as file type" or "Files of type" box in the dialog box, separated by vertical bar | for example: @verbatim (*.txt)|*.txt|All files (*.*)|*.* @endverbatim
      /// @param options A bitwise combination of enum xtd::forms::save_file_box_options to specify additional options to the file dialog box
      /// @return xtd::forms::dialog_result::ok if the user clicks OK in the dialog box; otherwise, xtd::forms::dialog_result::cancel.
      /// @remarks If xtd::forms::dialog_result is ok, the output file_name parameter will contain the selected file path, otherwise it will be ignored.
      static xtd::forms::dialog_result show(xtd::ustring& file_name, const xtd::ustring& title, const xtd::ustring& initial_directory,  const xtd::ustring& filter, const save_file_box_options options);
      /// @}
      
    private:
      static xtd::forms::dialog_result show_save_file_box(xtd::ustring& output, const xtd::ustring& title, const xtd::ustring& initial_directory = "", const xtd::ustring& filter = "", const save_file_box_options options = save_file_box_options::none, const iwin32_window* owner = nullptr);
    };
  }
}
