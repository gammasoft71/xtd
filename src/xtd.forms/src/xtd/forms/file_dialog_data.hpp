#include "../../../include/xtd/forms/file_dialog.hpp"
#include <xtd/forms/open_file_name_flags>

/// @cond
struct xtd::forms::file_dialog::data {
  bool auto_upgrade_enabled = true;
  xtd::string default_ext = "";
  xtd::string file_name = "";
  xtd::collections::generic::list<xtd::string> file_names;
  xtd::string filter = "";
  size_t filter_index = 1;
  xtd::string initial_directory = "";
  size_t options = OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_ADDEXTENSION;
  bool support_multi_dotted_extensions = true;
  xtd::string title = "";
};
/// @endcond
