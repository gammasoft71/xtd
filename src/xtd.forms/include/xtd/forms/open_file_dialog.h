#pragma once
#include <xtd/io/file.h>
#include "file_dialog.h"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::forms namespace contains classes for creating Windows-based applications that take full advantage of the rich user interface features available in the Microsoft Windows operating system, Apple macOS and Linux like Ubuntu operating system.
  namespace forms {
    class forms_export_ open_file_dialog : public file_dialog {
    public:
      /// @brief Initializes a new instance of the common_dialog class.
      open_file_dialog() = default;
      
      std::ifstream open_file() const {return io::file::open_read(file_name_);}
      
    private:
      bool run_file_dialog(intptr_t hwnd_owner) override;
      void run_file_sheet(intptr_t owner) override;
    };
  }
}
