#pragma once
#include <cstdint>
#include <vector>
#include <xtd/ustring.hpp>

namespace xtd {
  namespace forms {
    namespace native {
      class file_dialog {
      public:
        file_dialog() = delete;
        static bool run_open_dialog(intptr_t hwnd, const ustring& default_ext, ustring& file_name, std::vector<ustring>& file_names, const ustring& filter, size_t filter_index, const ustring& initial_directory, size_t options, bool support_multi_dotted_extensions, const ustring& title);
        static bool run_save_dialog(intptr_t hwnd, const ustring& default_ext, ustring& file_name, std::vector<ustring>& file_names, const ustring& filter, size_t filter_index, const ustring& initial_directory, size_t options, bool support_multi_dotted_extensions, const ustring& title);
      };
    }
  }
}
