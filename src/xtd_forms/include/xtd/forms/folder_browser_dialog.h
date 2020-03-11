#pragma once
#include <xtd/environment.h>
#include <xtd/forms/folder_browser_dialog_flags.h>
#include "common_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class folder_browser_dialog : public common_dialog {
    public:
      folder_browser_dialog() = default;
      
      bool auto_upgrade_enable() const {return this->get_option(BIF_USENEWUI);}
      folder_browser_dialog& auto_upgrade_enable(bool value) {
        this->set_option(BIF_USENEWUI, value);
        return *this;
      }
      
      const std::string& description() const {return description_;}
      folder_browser_dialog& description(const std::string& value) {
        description_ = value;
        return *this;
      }

      environment::special_folder root_folder() const {return root_folder_;}
      folder_browser_dialog& root_folder(environment::special_folder value) {
        root_folder_ = value;
        return *this;
      }

      const std::string& selected_path() const {return selected_path_;}
      folder_browser_dialog& selected_path(const std::string& value) {
        selected_path_ = value;
        return *this;
      }

      /// @brief Resets all options to their default values, the last selected color to black, and the custom colors to their default values.
      void reset() override;
      
    protected:
      /// @brief When overridden in a derived class, specifies a common dialog box.
      /// @param owner A value that represents the window handle of the owner window for the common dialog box.
      /// @return true if the dialog box was successfully run; otherwise, false.
      bool run_dialog(intptr_t owner) override;

    private:
      bool get_option(size_t flag) const {return (this->options_ & flag) == flag;}
      void set_option(size_t flag, bool value) {this->options_ = value ? this->options_ | flag : this->options_ & ~flag;}

      std::string description_;
      environment::special_folder root_folder_ = environment::special_folder::desktop;
      std::string selected_path_;
      size_t options_ =  BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE;
    };
  }
}
