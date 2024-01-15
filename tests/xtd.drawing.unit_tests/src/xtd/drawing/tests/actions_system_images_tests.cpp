#include <xtd/drawing/actions_system_images>
#include <xtd/drawing/system_images>
#include <xtd/tunit/assert>
#include <xtd/tunit/test_class_attribute>
#include <xtd/tunit/test_method_attribute>

using namespace xtd::drawing;
using namespace xtd::tunit;

namespace xtd::drawing::tests {
  class test_class_(actions_system_images_tests) {
    void test_method_(default_size) {
      auto s = actions_system_images::default_size();
      assert::are_equal(size {32, 32}, s, csf_);
    }

    void test_method_(address_book_new) {
      auto i = actions_system_images::address_book_new();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("address-book-new"), i, csf_);
    }

    void test_method_(address_book_new_with_specified_size) {
      auto i = actions_system_images::address_book_new({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("address-book-new", size {64, 64}), i, csf_);
    }

    void test_method_(application_exit) {
      auto i = actions_system_images::application_exit();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("application-exit"), i, csf_);
    }

    void test_method_(application_exit_with_specified_size) {
      auto i = actions_system_images::application_exit({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("application-exit", size {64, 64}), i, csf_);
    }

    void test_method_(appointment_new) {
      auto i = actions_system_images::appointment_new();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("appointment-new"), i, csf_);
    }

    void test_method_(appointment_new_with_specified_size) {
      auto i = actions_system_images::appointment_new({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("appointment-new", size {64, 64}), i, csf_);
    }

    void test_method_(call_start) {
      auto i = actions_system_images::call_start();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("call-start"), i, csf_);
    }

    void test_method_(call_start_with_specified_size) {
      auto i = actions_system_images::call_start({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("call-start", size {64, 64}), i, csf_);
    }

    void test_method_(call_stop) {
      auto i = actions_system_images::call_stop();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("call-stop"), i, csf_);
    }

    void test_method_(call_stop_with_specified_size) {
      auto i = actions_system_images::call_stop({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("call-stop", size {64, 64}), i, csf_);
    }

    void test_method_(contact_new) {
      auto i = actions_system_images::contact_new();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("contact-new"), i, csf_);
    }

    void test_method_(contact_new_with_specified_size) {
      auto i = actions_system_images::contact_new({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("contact-new", size {64, 64}), i, csf_);
    }

    void test_method_(dialog_cancel) {
      auto i = actions_system_images::dialog_cancel();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-cancel"), i, csf_);
    }

    void test_method_(dialog_cancel_with_specified_size) {
      auto i = actions_system_images::dialog_cancel({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-cancel", size {64, 64}), i, csf_);
    }

    void test_method_(dialog_ok) {
      auto i = actions_system_images::dialog_ok();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-ok"), i, csf_);
    }

    void test_method_(dialog_ok_with_specified_size) {
      auto i = actions_system_images::dialog_ok({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-ok", size {64, 64}), i, csf_);
    }

    void test_method_(dialog_ok_apply) {
      auto i = actions_system_images::dialog_ok_apply();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-ok-apply"), i, csf_);
    }

    void test_method_(dialog_ok_apply_with_specified_size) {
      auto i = actions_system_images::dialog_ok_apply({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("dialog-ok-apply", size {64, 64}), i, csf_);
    }

    void test_method_(document_edit) {
      auto i = actions_system_images::document_edit();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-edit"), i, csf_);
    }

    void test_method_(document_edit_with_specified_size) {
      auto i = actions_system_images::document_edit({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-edit", size {64, 64}), i, csf_);
    }

    void test_method_(document_new) {
      auto i = actions_system_images::document_new();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-new"), i, csf_);
    }

    void test_method_(document_new_with_specified_size) {
      auto i = actions_system_images::document_new({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-new", size {64, 64}), i, csf_);
    }

    void test_method_(document_open) {
      auto i = actions_system_images::document_open();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-open"), i, csf_);
    }

    void test_method_(document_open_with_specified_size) {
      auto i = actions_system_images::document_open({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-open", size {64, 64}), i, csf_);
    }

    void test_method_(document_open_recent) {
      auto i = actions_system_images::document_open_recent();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-open-recent"), i, csf_);
    }

    void test_method_(document_open_recent_with_specified_size) {
      auto i = actions_system_images::document_open_recent({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-open-recent", size {64, 64}), i, csf_);
    }

    void test_method_(document_page_setup) {
      auto i = actions_system_images::document_page_setup();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-page-setup"), i, csf_);
    }

    void test_method_(document_page_setup_with_specified_size) {
      auto i = actions_system_images::document_page_setup({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-page-setup", size {64, 64}), i, csf_);
    }

    void test_method_(document_print) {
      auto i = actions_system_images::document_print();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-print"), i, csf_);
    }

    void test_method_(document_print_with_specified_size) {
      auto i = actions_system_images::document_print({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-print", size {64, 64}), i, csf_);
    }

    void test_method_(document_print_preview) {
      auto i = actions_system_images::document_print_preview();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-print-preview"), i, csf_);
    }

    void test_method_(document_print_preview_with_specified_size) {
      auto i = actions_system_images::document_print_preview({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-print-preview", size {64, 64}), i, csf_);
    }

    void test_method_(document_properties) {
      auto i = actions_system_images::document_properties();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-properties"), i, csf_);
    }

    void test_method_(document_properties_with_specified_size) {
      auto i = actions_system_images::document_properties({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-properties", size {64, 64}), i, csf_);
    }

    void test_method_(document_revert) {
      auto i = actions_system_images::document_revert();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-revert"), i, csf_);
    }

    void test_method_(document_revert_with_specified_size) {
      auto i = actions_system_images::document_revert({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-revert", size {64, 64}), i, csf_);
    }

    void test_method_(document_save) {
      auto i = actions_system_images::document_save();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-save"), i, csf_);
    }

    void test_method_(document_save_with_specified_size) {
      auto i = actions_system_images::document_save({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-save", size {64, 64}), i, csf_);
    }

    void test_method_(document_save_as) {
      auto i = actions_system_images::document_save_as();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-save-as"), i, csf_);
    }

    void test_method_(document_save_as_with_specified_size) {
      auto i = actions_system_images::document_save_as({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-save-as", size {64, 64}), i, csf_);
    }

    void test_method_(document_send) {
      auto i = actions_system_images::document_send();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-send"), i, csf_);
    }

    void test_method_(document_send_with_specified_size) {
      auto i = actions_system_images::document_send({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("document-send", size {64, 64}), i, csf_);
    }

    void test_method_(edit_clear) {
      auto i = actions_system_images::edit_clear();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-clear"), i, csf_);
    }

    void test_method_(edit_clear_with_specified_size) {
      auto i = actions_system_images::edit_clear({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-clear", size {64, 64}), i, csf_);
    }

    void test_method_(edit_copy) {
      auto i = actions_system_images::edit_copy();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-copy"), i, csf_);
    }

    void test_method_(edit_copy_with_specified_size) {
      auto i = actions_system_images::edit_copy({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-copy", size {64, 64}), i, csf_);
    }

    void test_method_(edit_cut) {
      auto i = actions_system_images::edit_cut();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-cut"), i, csf_);
    }

    void test_method_(edit_cut_with_specified_size) {
      auto i = actions_system_images::edit_cut({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-cut", size {64, 64}), i, csf_);
    }

    void test_method_(edit_delete) {
      auto i = actions_system_images::edit_delete();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-delete"), i, csf_);
    }

    void test_method_(edit_delete_with_specified_size) {
      auto i = actions_system_images::edit_delete({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-delete", size {64, 64}), i, csf_);
    }

    void test_method_(edit_find) {
      auto i = actions_system_images::edit_find();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-find"), i, csf_);
    }

    void test_method_(edit_find_with_specified_size) {
      auto i = actions_system_images::edit_find({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-find", size {64, 64}), i, csf_);
    }

    void test_method_(edit_find_replace) {
      auto i = actions_system_images::edit_find_replace();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-find-replace"), i, csf_);
    }

    void test_method_(edit_find_replace_with_specified_size) {
      auto i = actions_system_images::edit_find_replace({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-find-replace", size {64, 64}), i, csf_);
    }

    void test_method_(edit_paste) {
      auto i = actions_system_images::edit_paste();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-paste"), i, csf_);
    }

    void test_method_(edit_paste_with_specified_size) {
      auto i = actions_system_images::edit_paste({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-paste", size {64, 64}), i, csf_);
    }

    void test_method_(edit_redo) {
      auto i = actions_system_images::edit_redo();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-redo"), i, csf_);
    }

    void test_method_(edit_redo_with_specified_size) {
      auto i = actions_system_images::edit_redo({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-redo", size {64, 64}), i, csf_);
    }

    void test_method_(edit_rename) {
      auto i = actions_system_images::edit_rename();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-rename"), i, csf_);
    }

    void test_method_(edit_rename_with_specified_size) {
      auto i = actions_system_images::edit_rename({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-rename", size {64, 64}), i, csf_);
    }

    void test_method_(edit_select_all) {
      auto i = actions_system_images::edit_select_all();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-select-all"), i, csf_);
    }

    void test_method_(edit_select_all_with_specified_size) {
      auto i = actions_system_images::edit_select_all({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-select-all", size {64, 64}), i, csf_);
    }

    void test_method_(edit_undo) {
      auto i = actions_system_images::edit_undo();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-undo"), i, csf_);
    }

    void test_method_(edit_undo_with_specified_size) {
      auto i = actions_system_images::edit_undo({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("edit-undo", size {64, 64}), i, csf_);
    }

    void test_method_(folder_new) {
      auto i = actions_system_images::folder_new();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-new"), i, csf_);
    }

    void test_method_(folder_new_with_specified_size) {
      auto i = actions_system_images::folder_new({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("folder-new", size {64, 64}), i, csf_);
    }

    void test_method_(format_indent_less) {
      auto i = actions_system_images::format_indent_less();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-indent-less"), i, csf_);
    }

    void test_method_(format_indent_less_with_specified_size) {
      auto i = actions_system_images::format_indent_less({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-indent-less", size {64, 64}), i, csf_);
    }

    void test_method_(format_indent_more) {
      auto i = actions_system_images::format_indent_more();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-indent-more"), i, csf_);
    }

    void test_method_(format_indent_more_with_specified_size) {
      auto i = actions_system_images::format_indent_more({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-indent-more", size {64, 64}), i, csf_);
    }

    void test_method_(format_justify_center) {
      auto i = actions_system_images::format_justify_center();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-justify-center"), i, csf_);
    }

    void test_method_(format_justify_center_with_specified_size) {
      auto i = actions_system_images::format_justify_center({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-justify-center", size {64, 64}), i, csf_);
    }

    void test_method_(format_justify_fill) {
      auto i = actions_system_images::format_justify_fill();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-justify-fill"), i, csf_);
    }

    void test_method_(format_justify_fill_with_specified_size) {
      auto i = actions_system_images::format_justify_fill({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-justify-fill", size {64, 64}), i, csf_);
    }

    void test_method_(format_justify_left) {
      auto i = actions_system_images::format_justify_left();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-justify-left"), i, csf_);
    }

    void test_method_(format_justify_left_with_specified_size) {
      auto i = actions_system_images::format_justify_left({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-justify-left", size {64, 64}), i, csf_);
    }

    void test_method_(format_justify_right) {
      auto i = actions_system_images::format_justify_right();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-justify-right"), i, csf_);
    }

    void test_method_(format_justify_right_with_specified_size) {
      auto i = actions_system_images::format_justify_right({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-justify-right", size {64, 64}), i, csf_);
    }

    void test_method_(format_text_direction_ltr) {
      auto i = actions_system_images::format_text_direction_ltr();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-direction-ltr"), i, csf_);
    }

    void test_method_(format_text_direction_ltr_with_specified_size) {
      auto i = actions_system_images::format_text_direction_ltr({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-direction-ltr", size {64, 64}), i, csf_);
    }

    void test_method_(format_text_direction_rtl) {
      auto i = actions_system_images::format_text_direction_rtl();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-direction-rtl"), i, csf_);
    }

    void test_method_(format_text_direction_rtl_with_specified_size) {
      auto i = actions_system_images::format_text_direction_rtl({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-direction-rtl", size {64, 64}), i, csf_);
    }

    void test_method_(format_text_bold) {
      auto i = actions_system_images::format_text_bold();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-bold"), i, csf_);
    }

    void test_method_(format_text_bold_with_specified_size) {
      auto i = actions_system_images::format_text_bold({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-bold", size {64, 64}), i, csf_);
    }

    void test_method_(format_text_italic) {
      auto i = actions_system_images::format_text_italic();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-italic"), i, csf_);
    }

    void test_method_(format_text_italic_with_specified_size) {
      auto i = actions_system_images::format_text_italic({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-italic", size {64, 64}), i, csf_);
    }

    void test_method_(format_text_underline) {
      auto i = actions_system_images::format_text_underline();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-underline"), i, csf_);
    }

    void test_method_(format_text_underline_with_specified_size) {
      auto i = actions_system_images::format_text_underline({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-underline", size {64, 64}), i, csf_);
    }

    void test_method_(format_text_strikethrough) {
      auto i = actions_system_images::format_text_strikethrough();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-strikethrough"), i, csf_);
    }

    void test_method_(format_text_strikethrough_with_specified_size) {
      auto i = actions_system_images::format_text_strikethrough({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("format-text-strikethrough", size {64, 64}), i, csf_);
    }

    void test_method_(go_bottom) {
      auto i = actions_system_images::go_bottom();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-bottom"), i, csf_);
    }

    void test_method_(go_bottom_with_specified_size) {
      auto i = actions_system_images::go_bottom({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-bottom", size {64, 64}), i, csf_);
    }

    void test_method_(go_down) {
      auto i = actions_system_images::go_down();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-down"), i, csf_);
    }

    void test_method_(go_down_with_specified_size) {
      auto i = actions_system_images::go_down({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-down", size {64, 64}), i, csf_);
    }

    void test_method_(go_first) {
      auto i = actions_system_images::go_first();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-first"), i, csf_);
    }

    void test_method_(go_first_with_specified_size) {
      auto i = actions_system_images::go_first({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-first", size {64, 64}), i, csf_);
    }

    void test_method_(go_home) {
      auto i = actions_system_images::go_home();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-home"), i, csf_);
    }

    void test_method_(go_home_with_specified_size) {
      auto i = actions_system_images::go_home({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-home", size {64, 64}), i, csf_);
    }

    void test_method_(go_jump) {
      auto i = actions_system_images::go_jump();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-jump"), i, csf_);
    }

    void test_method_(go_jump_with_specified_size) {
      auto i = actions_system_images::go_jump({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-jump", size {64, 64}), i, csf_);
    }

    void test_method_(go_last) {
      auto i = actions_system_images::go_last();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-last"), i, csf_);
    }

    void test_method_(go_last_with_specified_size) {
      auto i = actions_system_images::go_last({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-last", size {64, 64}), i, csf_);
    }

    void test_method_(go_next) {
      auto i = actions_system_images::go_next();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-next"), i, csf_);
    }

    void test_method_(go_next_with_specified_size) {
      auto i = actions_system_images::go_next({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-next", size {64, 64}), i, csf_);
    }

    void test_method_(go_previous) {
      auto i = actions_system_images::go_previous();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-previous"), i, csf_);
    }

    void test_method_(go_previous_with_specified_size) {
      auto i = actions_system_images::go_previous({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-previous", size {64, 64}), i, csf_);
    }

    void test_method_(go_top) {
      auto i = actions_system_images::go_top();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-top"), i, csf_);
    }

    void test_method_(go_top_with_specified_size) {
      auto i = actions_system_images::go_top({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-top", size {64, 64}), i, csf_);
    }

    void test_method_(go_up) {
      auto i = actions_system_images::go_up();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-up"), i, csf_);
    }

    void test_method_(go_up_with_specified_size) {
      auto i = actions_system_images::go_up({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("go-up", size {64, 64}), i, csf_);
    }

    void test_method_(help_about) {
      auto i = actions_system_images::help_about();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help-about"), i, csf_);
    }

    void test_method_(help_about_with_specified_size) {
      auto i = actions_system_images::help_about({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help-about", size {64, 64}), i, csf_);
    }

    void test_method_(help_contents) {
      auto i = actions_system_images::help_contents();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help-contents"), i, csf_);
    }

    void test_method_(help_contents_with_specified_size) {
      auto i = actions_system_images::help_contents({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help-contents", size {64, 64}), i, csf_);
    }

    void test_method_(help_faq) {
      auto i = actions_system_images::help_faq();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help-faq"), i, csf_);
    }

    void test_method_(help_faq_with_specified_size) {
      auto i = actions_system_images::help_faq({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("help-faq", size {64, 64}), i, csf_);
    }

    void test_method_(insert_image) {
      auto i = actions_system_images::insert_image();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-image"), i, csf_);
    }

    void test_method_(insert_image_with_specified_size) {
      auto i = actions_system_images::insert_image({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-image", size {64, 64}), i, csf_);
    }

    void test_method_(insert_link) {
      auto i = actions_system_images::insert_link();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-link"), i, csf_);
    }

    void test_method_(insert_link_with_specified_size) {
      auto i = actions_system_images::insert_link({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-link", size {64, 64}), i, csf_);
    }

    void test_method_(insert_object) {
      auto i = actions_system_images::insert_object();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-object"), i, csf_);
    }

    void test_method_(insert_object_with_specified_size) {
      auto i = actions_system_images::insert_object({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-object", size {64, 64}), i, csf_);
    }

    void test_method_(insert_table) {
      auto i = actions_system_images::insert_table();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-table"), i, csf_);
    }

    void test_method_(insert_table_with_specified_size) {
      auto i = actions_system_images::insert_table({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-table", size {64, 64}), i, csf_);
    }

    void test_method_(insert_text) {
      auto i = actions_system_images::insert_text();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-text"), i, csf_);
    }

    void test_method_(insert_text_with_specified_size) {
      auto i = actions_system_images::insert_text({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("insert-text", size {64, 64}), i, csf_);
    }

    void test_method_(list_add) {
      auto i = actions_system_images::list_add();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("list-add"), i, csf_);
    }

    void test_method_(list_add_with_specified_size) {
      auto i = actions_system_images::list_add({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("list-add", size {64, 64}), i, csf_);
    }

    void test_method_(list_remove) {
      auto i = actions_system_images::list_remove();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("list-remove"), i, csf_);
    }

    void test_method_(list_remove_with_specified_size) {
      auto i = actions_system_images::list_remove({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("list-remove", size {64, 64}), i, csf_);
    }

    void test_method_(mail_forward) {
      auto i = actions_system_images::mail_forward();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-forward"), i, csf_);
    }

    void test_method_(mail_forward_with_specified_size) {
      auto i = actions_system_images::mail_forward({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-forward", size {64, 64}), i, csf_);
    }

    void test_method_(mail_mark_important) {
      auto i = actions_system_images::mail_mark_important();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-important"), i, csf_);
    }

    void test_method_(mail_mark_important_with_specified_size) {
      auto i = actions_system_images::mail_mark_important({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-important", size {64, 64}), i, csf_);
    }

    void test_method_(mail_mark_junk) {
      auto i = actions_system_images::mail_mark_junk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-junk"), i, csf_);
    }

    void test_method_(mail_mark_junk_with_specified_size) {
      auto i = actions_system_images::mail_mark_junk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-junk", size {64, 64}), i, csf_);
    }

    void test_method_(mail_mark_notjunk) {
      auto i = actions_system_images::mail_mark_notjunk();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-notjunk"), i, csf_);
    }

    void test_method_(mail_mark_notjunk_with_specified_size) {
      auto i = actions_system_images::mail_mark_notjunk({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-notjunk", size {64, 64}), i, csf_);
    }

    void test_method_(mail_mark_read) {
      auto i = actions_system_images::mail_mark_read();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-read"), i, csf_);
    }

    void test_method_(mail_mark_read_with_specified_size) {
      auto i = actions_system_images::mail_mark_read({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-read", size {64, 64}), i, csf_);
    }

    void test_method_(mail_mark_unread) {
      auto i = actions_system_images::mail_mark_unread();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-unread"), i, csf_);
    }

    void test_method_(mail_mark_unread_with_specified_size) {
      auto i = actions_system_images::mail_mark_unread({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-mark-unread", size {64, 64}), i, csf_);
    }

    void test_method_(mail_message_new) {
      auto i = actions_system_images::mail_message_new();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-message-new"), i, csf_);
    }

    void test_method_(mail_message_new_with_specified_size) {
      auto i = actions_system_images::mail_message_new({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-message-new", size {64, 64}), i, csf_);
    }

    void test_method_(mail_reply_all) {
      auto i = actions_system_images::mail_reply_all();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-reply-all"), i, csf_);
    }

    void test_method_(mail_reply_all_with_specified_size) {
      auto i = actions_system_images::mail_reply_all({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-reply-all", size {64, 64}), i, csf_);
    }

    void test_method_(mail_reply_sender) {
      auto i = actions_system_images::mail_reply_sender();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-reply-sender"), i, csf_);
    }

    void test_method_(mail_reply_sender_with_specified_size) {
      auto i = actions_system_images::mail_reply_sender({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-reply-sender", size {64, 64}), i, csf_);
    }

    void test_method_(mail_send) {
      auto i = actions_system_images::mail_send();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-send"), i, csf_);
    }

    void test_method_(mail_send_with_specified_size) {
      auto i = actions_system_images::mail_send({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-send", size {64, 64}), i, csf_);
    }

    void test_method_(mail_send_receive) {
      auto i = actions_system_images::mail_send_receive();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-send-receive"), i, csf_);
    }

    void test_method_(mail_send_receive_with_specified_size) {
      auto i = actions_system_images::mail_send_receive({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("mail-send-receive", size {64, 64}), i, csf_);
    }

    void test_method_(media_eject) {
      auto i = actions_system_images::media_eject();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-eject"), i, csf_);
    }

    void test_method_(media_eject_with_specified_size) {
      auto i = actions_system_images::media_eject({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-eject", size {64, 64}), i, csf_);
    }

    void test_method_(media_optical_burn) {
      auto i = actions_system_images::media_optical_burn();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-burn"), i, csf_);
    }

    void test_method_(media_optical_burn_with_specified_size) {
      auto i = actions_system_images::media_optical_burn({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-optical-burn", size {64, 64}), i, csf_);
    }

    void test_method_(media_playback_pause) {
      auto i = actions_system_images::media_playback_pause();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playback-pause"), i, csf_);
    }

    void test_method_(media_playback_pause_with_specified_size) {
      auto i = actions_system_images::media_playback_pause({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playback-pause", size {64, 64}), i, csf_);
    }

    void test_method_(media_playback_start) {
      auto i = actions_system_images::media_playback_start();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playback-start"), i, csf_);
    }

    void test_method_(media_playback_start_with_specified_size) {
      auto i = actions_system_images::media_playback_start({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playback-start", size {64, 64}), i, csf_);
    }

    void test_method_(media_playback_stop) {
      auto i = actions_system_images::media_playback_stop();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playback-stop"), i, csf_);
    }

    void test_method_(media_playback_stop_with_specified_size) {
      auto i = actions_system_images::media_playback_stop({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-playback-stop", size {64, 64}), i, csf_);
    }

    void test_method_(media_record) {
      auto i = actions_system_images::media_record();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-record"), i, csf_);
    }

    void test_method_(media_record_with_specified_size) {
      auto i = actions_system_images::media_record({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-record", size {64, 64}), i, csf_);
    }

    void test_method_(media_seek_backward) {
      auto i = actions_system_images::media_seek_backward();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-seek-backward"), i, csf_);
    }

    void test_method_(media_seek_backward_with_specified_size) {
      auto i = actions_system_images::media_seek_backward({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-seek-backward", size {64, 64}), i, csf_);
    }

    void test_method_(media_seek_forward) {
      auto i = actions_system_images::media_seek_forward();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-seek-forward"), i, csf_);
    }

    void test_method_(media_seek_forward_with_specified_size) {
      auto i = actions_system_images::media_seek_forward({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-seek-forward", size {64, 64}), i, csf_);
    }

    void test_method_(media_skip_backward) {
      auto i = actions_system_images::media_skip_backward();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-skip-backward"), i, csf_);
    }

    void test_method_(media_skip_backward_with_specified_size) {
      auto i = actions_system_images::media_skip_backward({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-skip-backward", size {64, 64}), i, csf_);
    }

    void test_method_(media_skip_forward) {
      auto i = actions_system_images::media_skip_forward();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-skip-forward"), i, csf_);
    }

    void test_method_(media_skip_forward_with_specified_size) {
      auto i = actions_system_images::media_skip_forward({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("media-skip-forward", size {64, 64}), i, csf_);
    }

    void test_method_(object_flip_horizontal) {
      auto i = actions_system_images::object_flip_horizontal();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("object-flip-horizontal"), i, csf_);
    }

    void test_method_(object_flip_horizontal_with_specified_size) {
      auto i = actions_system_images::object_flip_horizontal({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("object-flip-horizontal", size {64, 64}), i, csf_);
    }

    void test_method_(object_flip_vertical) {
      auto i = actions_system_images::object_flip_vertical();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("object-flip-vertical"), i, csf_);
    }

    void test_method_(object_flip_vertical_with_specified_size) {
      auto i = actions_system_images::object_flip_vertical({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("object-flip-vertical", size {64, 64}), i, csf_);
    }

    void test_method_(object_rotate_left) {
      auto i = actions_system_images::object_rotate_left();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("object-rotate-left"), i, csf_);
    }

    void test_method_(object_rotate_left_with_specified_size) {
      auto i = actions_system_images::object_rotate_left({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("object-rotate-left", size {64, 64}), i, csf_);
    }

    void test_method_(object_rotate_right) {
      auto i = actions_system_images::object_rotate_right();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("object-rotate-right"), i, csf_);
    }

    void test_method_(object_rotate_right_with_specified_size) {
      auto i = actions_system_images::object_rotate_right({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("object-rotate-right", size {64, 64}), i, csf_);
    }

    void test_method_(process_stop) {
      auto i = actions_system_images::process_stop();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("process-stop"), i, csf_);
    }

    void test_method_(process_stop_with_specified_size) {
      auto i = actions_system_images::process_stop({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("process-stop", size {64, 64}), i, csf_);
    }

    void test_method_(system_lock_screen) {
      auto i = actions_system_images::system_lock_screen();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-lock-screen"), i, csf_);
    }

    void test_method_(system_lock_screen_with_specified_size) {
      auto i = actions_system_images::system_lock_screen({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-lock-screen", size {64, 64}), i, csf_);
    }

    void test_method_(system_log_out) {
      auto i = actions_system_images::system_log_out();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-log-out"), i, csf_);
    }

    void test_method_(system_log_out_with_specified_size) {
      auto i = actions_system_images::system_log_out({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-log-out", size {64, 64}), i, csf_);
    }

    void test_method_(system_run) {
      auto i = actions_system_images::system_run();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-run"), i, csf_);
    }

    void test_method_(system_run_with_specified_size) {
      auto i = actions_system_images::system_run({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-run", size {64, 64}), i, csf_);
    }

    void test_method_(system_search) {
      auto i = actions_system_images::system_search();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-search"), i, csf_);
    }

    void test_method_(system_search_with_specified_size) {
      auto i = actions_system_images::system_search({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-search", size {64, 64}), i, csf_);
    }

    void test_method_(system_reboot) {
      auto i = actions_system_images::system_reboot();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-reboot"), i, csf_);
    }

    void test_method_(system_reboot_with_specified_size) {
      auto i = actions_system_images::system_reboot({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-reboot", size {64, 64}), i, csf_);
    }

    void test_method_(system_shutdown) {
      auto i = actions_system_images::system_shutdown();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-shutdown"), i, csf_);
    }

    void test_method_(system_shutdown_with_specified_size) {
      auto i = actions_system_images::system_shutdown({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("system-shutdown", size {64, 64}), i, csf_);
    }

    void test_method_(tools_check_spelling) {
      auto i = actions_system_images::tools_check_spelling();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("tools-check-spelling"), i, csf_);
    }

    void test_method_(tools_check_spelling_with_specified_size) {
      auto i = actions_system_images::tools_check_spelling({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("tools-check-spelling", size {64, 64}), i, csf_);
    }

    void test_method_(view_fullscreen) {
      auto i = actions_system_images::view_fullscreen();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-fullscreen"), i, csf_);
    }

    void test_method_(view_fullscreen_with_specified_size) {
      auto i = actions_system_images::view_fullscreen({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-fullscreen", size {64, 64}), i, csf_);
    }

    void test_method_(view_media_equalizer) {
      auto i = actions_system_images::view_media_equalizer();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-media-equalizer"), i, csf_);
    }

    void test_method_(view_media_equalizer_with_specified_size) {
      auto i = actions_system_images::view_media_equalizer({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-media-equalizer", size {64, 64}), i, csf_);
    }

    void test_method_(view_media_lyrics) {
      auto i = actions_system_images::view_media_lyrics();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-media-lyrics"), i, csf_);
    }

    void test_method_(view_media_lyrics_with_specified_size) {
      auto i = actions_system_images::view_media_lyrics({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-media-lyrics", size {64, 64}), i, csf_);
    }

    void test_method_(view_refresh) {
      auto i = actions_system_images::view_refresh();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-refresh"), i, csf_);
    }

    void test_method_(view_refresh_with_specified_size) {
      auto i = actions_system_images::view_refresh({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-refresh", size {64, 64}), i, csf_);
    }

    void test_method_(view_restore) {
      auto i = actions_system_images::view_restore();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-restore"), i, csf_);
    }

    void test_method_(view_restore_with_specified_size) {
      auto i = actions_system_images::view_restore({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-restore", size {64, 64}), i, csf_);
    }

    void test_method_(view_sort_ascending) {
      auto i = actions_system_images::view_sort_ascending();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-sort-ascending"), i, csf_);
    }

    void test_method_(view_sort_ascending_with_specified_size) {
      auto i = actions_system_images::view_sort_ascending({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-sort-ascending", size {64, 64}), i, csf_);
    }

    void test_method_(view_sort_descending) {
      auto i = actions_system_images::view_sort_descending();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-sort-descending"), i, csf_);
    }

    void test_method_(view_sort_descending_with_specified_size) {
      auto i = actions_system_images::view_sort_descending({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("view-sort-descending", size {64, 64}), i, csf_);
    }

    void test_method_(window_close) {
      auto i = actions_system_images::window_close();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-close"), i, csf_);
    }

    void test_method_(window_close_with_specified_size) {
      auto i = actions_system_images::window_close({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-close", size {64, 64}), i, csf_);
    }

    void test_method_(window_close_hovered) {
      auto i = actions_system_images::window_close_hovered();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-close-hovered"), i, csf_);
    }

    void test_method_(window_close_hovered_with_specified_size) {
      auto i = actions_system_images::window_close_hovered({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-close-hovered", size {64, 64}), i, csf_);
    }

    void test_method_(window_fullscreen) {
      auto i = actions_system_images::window_fullscreen();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-fullscreen"), i, csf_);
    }

    void test_method_(window_fullscreen_with_specified_size) {
      auto i = actions_system_images::window_fullscreen({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-fullscreen", size {64, 64}), i, csf_);
    }

    void test_method_(window_fullscreen_hovered) {
      auto i = actions_system_images::window_fullscreen_hovered();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-fullscreen-hovered"), i, csf_);
    }

    void test_method_(window_fullscreen_hovered_with_specified_size) {
      auto i = actions_system_images::window_fullscreen_hovered({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-fullscreen-hovered", size {64, 64}), i, csf_);
    }

    void test_method_(window_maximize) {
      auto i = actions_system_images::window_maximize();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-maximize"), i, csf_);
    }

    void test_method_(window_maximize_with_specified_size) {
      auto i = actions_system_images::window_maximize({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-maximize", size {64, 64}), i, csf_);
    }

    void test_method_(window_maximize_hovered) {
      auto i = actions_system_images::window_maximize_hovered();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-maximize-hovered"), i, csf_);
    }

    void test_method_(window_maximize_hovered_with_specified_size) {
      auto i = actions_system_images::window_maximize_hovered({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-maximize-hovered", size {64, 64}), i, csf_);
    }

    void test_method_(window_minimize) {
      auto i = actions_system_images::window_minimize();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-minimize"), i, csf_);
    }

    void test_method_(window_minimize_with_specified_size) {
      auto i = actions_system_images::window_minimize({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-minimize", size {64, 64}), i, csf_);
    }

    void test_method_(window_minimize_hovered) {
      auto i = actions_system_images::window_minimize_hovered();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-minimize-hovered"), i, csf_);
    }

    void test_method_(window_minimize_hovered_with_specified_size) {
      auto i = actions_system_images::window_minimize_hovered({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-minimize-hovered", size {64, 64}), i, csf_);
    }

    void test_method_(window_new) {
      auto i = actions_system_images::window_new();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-new"), i, csf_);
    }

    void test_method_(window_new_with_specified_size) {
      auto i = actions_system_images::window_new({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-new", size {64, 64}), i, csf_);
    }

    void test_method_(window_restore) {
      auto i = actions_system_images::window_restore();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-restore"), i, csf_);
    }

    void test_method_(window_restore_with_specified_size) {
      auto i = actions_system_images::window_restore({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-restore", size {64, 64}), i, csf_);
    }

    void test_method_(window_restore_hovered) {
      auto i = actions_system_images::window_restore_hovered();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-restore-hovered"), i, csf_);
    }

    void test_method_(window_restore_hovered_with_specified_size) {
      auto i = actions_system_images::window_restore_hovered({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("window-restore-hovered", size {64, 64}), i, csf_);
    }

    void test_method_(zoom_fit_best) {
      auto i = actions_system_images::zoom_fit_best();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("zoom-fit-best"), i, csf_);
    }

    void test_method_(zoom_fit_best_with_specified_size) {
      auto i = actions_system_images::zoom_fit_best({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("zoom-fit-best", size {64, 64}), i, csf_);
    }

    void test_method_(zoom_in) {
      auto i = actions_system_images::zoom_in();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("zoom-in"), i, csf_);
    }

    void test_method_(zoom_in_with_specified_size) {
      auto i = actions_system_images::zoom_in({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("zoom-in", size {64, 64}), i, csf_);
    }

    void test_method_(zoom_original) {
      auto i = actions_system_images::zoom_original();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("zoom-original"), i, csf_);
    }

    void test_method_(zoom_original_with_specified_size) {
      auto i = actions_system_images::zoom_original({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("zoom-original", size {64, 64}), i, csf_);
    }

    void test_method_(zoom_out) {
      auto i = actions_system_images::zoom_out();
      assert::are_equal(size {32, 32}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("zoom-out"), i, csf_);
    }

    void test_method_(zoom_out_with_specified_size) {
      auto i = actions_system_images::zoom_out({64, 64});
      assert::are_equal(size {64, 64}, i.size(), csf_);
      assert::are_not_equal(image::empty, i, csf_);
      assert::are_equal(system_images::from_name("zoom-out", size {64, 64}), i, csf_);
    }
  };
}
