#include "../../../include/xtd/forms/file_dialog"

/// @cond
struct xtd::forms::file_dialog::data {
  bool auto_upgrade_enabled = true;
  xtd::ustring default_ext = "";
  xtd::ustring file_name = "";
  std::vector<xtd::ustring> file_names;
  xtd::ustring filter = "";
  size_t filter_index = 1;
  xtd::ustring initial_directory = "";
  size_t options = OFN_HIDEREADONLY | OFN_PATHMUSTEXIST | OFN_ADDEXTENSION;
  bool support_multi_dotted_extensions = true;
  xtd::ustring title = "";
};
/// @endcond
