#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <xtd/static.h>

namespace xtd {
  namespace forms {
    namespace native {
      class file_dialog static_ {
      public:
        static bool run_open_dialog(intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title);
        static bool run_save_dialog(intptr_t hwnd, const std::string& default_ext, std::string& file_name, std::vector<std::string>& file_names, const std::string& filter, size_t filter_index, const std::string& initial_directory, size_t options, bool support_multi_dotted_extensions, const std::string& title);
      };
    }
  }
}
