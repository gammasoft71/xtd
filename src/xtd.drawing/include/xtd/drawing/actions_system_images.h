/// @file
/// @brief Contains xtd::drawing::actions_system_images factory.
/// @copyright Copyright (c) 2024 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.h"
#include <vector>

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::actions_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// @code
    /// class drawing_export_ actions_system_images final : private system_images_base
    /// @endcode
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::actions_system_images
    /// @par Header
    /// @code #include <xtd/drawing/actions_system_images> @endcode
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing drawing
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ actions_system_images final : private system_images_base {
    public:
      /// @name Properties

      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      static xtd::drawing::size default_size() noexcept;

      /// @brief Gets the actions system image "address-book-new".
      /// @return The xtd::drawing::image "address-book-new".
      static xtd::drawing::image address_book_new() noexcept;
      /// @brief Gets the actions system image "address-book-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "address-book-new".
      static xtd::drawing::image address_book_new(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "application-exit".
      /// @return The xtd::drawing::image "application-exit".
      static xtd::drawing::image application_exit() noexcept;
      /// @brief Gets the actions system image "application-exit" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "application-exit".
      static xtd::drawing::image application_exit(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "appointment-new".
      /// @return The xtd::drawing::image "appointment-new".
      static xtd::drawing::image appointment_new() noexcept;
      /// @brief Gets the actions system image "appointment-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "appointment-new".
      static xtd::drawing::image appointment_new(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "call-start".
      /// @return The xtd::drawing::image "call-start".
      static xtd::drawing::image call_start() noexcept;
      /// @brief Gets the actions system image "call-start" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "call-start".
      static xtd::drawing::image call_start(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "call-stop".
      /// @return The xtd::drawing::image "call-stop".
      static xtd::drawing::image call_stop() noexcept;
      /// @brief Gets the actions system image "call-stop" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "call-stop".
      static xtd::drawing::image call_stop(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "contact-new".
      /// @return The xtd::drawing::image "contact-new".
      static xtd::drawing::image contact_new() noexcept;
      /// @brief Gets the actions system image "contact-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "contact-new".
      static xtd::drawing::image contact_new(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "dialog-cancel".
      /// @return The xtd::drawing::image "dialog-cancel".
      static xtd::drawing::image dialog_cancel() noexcept;
      /// @brief Gets the actions system image "dialog-cancel" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "dialog-cancel".
      static xtd::drawing::image dialog_cancel(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "dialog-ok".
      /// @return The xtd::drawing::image "dialog-ok".
      static xtd::drawing::image dialog_ok() noexcept;
      /// @brief Gets the actions system image "dialog-ok" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "dialog-ok".
      static xtd::drawing::image dialog_ok(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "dialog-ok-apply".
      /// @return The xtd::drawing::image "dialog-ok-apply".
      static xtd::drawing::image dialog_ok_apply() noexcept;
      /// @brief Gets the actions system image "dialog-ok-apply" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "dialog-ok-apply".
      static xtd::drawing::image dialog_ok_apply(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-edit".
      /// @return The xtd::drawing::image "document-edit".
      static xtd::drawing::image document_edit() noexcept;
      /// @brief Gets the actions system image "document-edit" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-edit".
      static xtd::drawing::image document_edit(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-new".
      /// @return The xtd::drawing::image "document-new".
      static xtd::drawing::image document_new() noexcept;
      /// @brief Gets the actions system image "document-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-new".
      static xtd::drawing::image document_new(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-open".
      /// @return The xtd::drawing::image "document-open".
      static xtd::drawing::image document_open() noexcept;
      /// @brief Gets the actions system image "document-open" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-open".
      static xtd::drawing::image document_open(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-open-recent".
      /// @return The xtd::drawing::image "document-open-recent".
      static xtd::drawing::image document_open_recent() noexcept;
      /// @brief Gets the actions system image "document-open-recent" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-open-recent".
      static xtd::drawing::image document_open_recent(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-page-setup".
      /// @return The xtd::drawing::image "document-page-setup".
      static xtd::drawing::image document_page_setup() noexcept;
      /// @brief Gets the actions system image "document-page-setup" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-page-setup".
      static xtd::drawing::image document_page_setup(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-print".
      /// @return The xtd::drawing::image "document-print".
      static xtd::drawing::image document_print() noexcept;
      /// @brief Gets the actions system image "document-print" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-print".
      static xtd::drawing::image document_print(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-print-preview".
      /// @return The xtd::drawing::image "document-print-preview".
      static xtd::drawing::image document_print_preview() noexcept;
      /// @brief Gets the actions system image "document-print-preview" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-print-preview".
      static xtd::drawing::image document_print_preview(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-properties".
      /// @return The xtd::drawing::image "document-properties".
      static xtd::drawing::image document_properties() noexcept;
      /// @brief Gets the actions system image "document-properties" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-properties".
      static xtd::drawing::image document_properties(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-revert".
      /// @return The xtd::drawing::image "document-revert".
      static xtd::drawing::image document_revert() noexcept;
      /// @brief Gets the actions system image "document-revert" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-revert".
      static xtd::drawing::image document_revert(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-save".
      /// @return The xtd::drawing::image "document-save".
      static xtd::drawing::image document_save() noexcept;
      /// @brief Gets the actions system image "document-save" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-save".
      static xtd::drawing::image document_save(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-save-as".
      /// @return The xtd::drawing::image "document-save-as".
      static xtd::drawing::image document_save_as() noexcept;
      /// @brief Gets the actions system image "document-save-as" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-save-as".
      static xtd::drawing::image document_save_as(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "document-send".
      /// @return The xtd::drawing::image "document-send".
      static xtd::drawing::image document_send() noexcept;
      /// @brief Gets the actions system image "document-send" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-send".
      static xtd::drawing::image document_send(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-clear".
      /// @return The xtd::drawing::image "edit-clear".
      static xtd::drawing::image edit_clear() noexcept;
      /// @brief Gets the actions system image "edit-clear" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-clear".
      static xtd::drawing::image edit_clear(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-copy".
      /// @return The xtd::drawing::image "edit-copy".
      static xtd::drawing::image edit_copy() noexcept;
      /// @brief Gets the actions system image "edit-copy" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-copy".
      static xtd::drawing::image edit_copy(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-cut".
      /// @return The xtd::drawing::image "edit-cut".
      static xtd::drawing::image edit_cut() noexcept;
      /// @brief Gets the actions system image "edit-cut" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-cut".
      static xtd::drawing::image edit_cut(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-delete".
      /// @return The xtd::drawing::image "edit-delete".
      static xtd::drawing::image edit_delete() noexcept;
      /// @brief Gets the actions system image "edit-delete" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-delete".
      static xtd::drawing::image edit_delete(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-find".
      /// @return The xtd::drawing::image "edit-find".
      static xtd::drawing::image edit_find() noexcept;
      /// @brief Gets the actions system image "edit-find" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-find".
      static xtd::drawing::image edit_find(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-find-replace".
      /// @return The xtd::drawing::image "edit-find-replace".
      static xtd::drawing::image edit_find_replace() noexcept;
      /// @brief Gets the actions system image "edit-find-replace" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-find-replace".
      static xtd::drawing::image edit_find_replace(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-paste".
      /// @return The xtd::drawing::image "edit-paste".
      static xtd::drawing::image edit_paste() noexcept;
      /// @brief Gets the actions system image "edit-paste" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-paste".
      static xtd::drawing::image edit_paste(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-redo".
      /// @return The xtd::drawing::image "edit-redo".
      static xtd::drawing::image edit_redo() noexcept;
      /// @brief Gets the actions system image "edit-redo" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-redo".
      static xtd::drawing::image edit_redo(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-rename".
      /// @return The xtd::drawing::image "edit-rename".
      static xtd::drawing::image edit_rename() noexcept;
      /// @brief Gets the actions system image "edit-rename" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-rename".
      static xtd::drawing::image edit_rename(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-select-all".
      /// @return The xtd::drawing::image "edit-select-all".
      static xtd::drawing::image edit_select_all() noexcept;
      /// @brief Gets the actions system image "edit-select-all" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-select-all".
      static xtd::drawing::image edit_select_all(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "edit-undo".
      /// @return The xtd::drawing::image "edit-undo".
      static xtd::drawing::image edit_undo() noexcept;
      /// @brief Gets the actions system image "edit-undo" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-undo".
      static xtd::drawing::image edit_undo(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "folder-new".
      /// @return The xtd::drawing::image "folder-new".
      static xtd::drawing::image folder_new() noexcept;
      /// @brief Gets the actions system image "folder-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "folder-new".
      static xtd::drawing::image folder_new(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-indent-less".
      /// @return The xtd::drawing::image "format-indent-less".
      static xtd::drawing::image format_indent_less() noexcept;
      /// @brief Gets the actions system image "format-indent-less" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-indent-less".
      static xtd::drawing::image format_indent_less(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-indent-more".
      /// @return The xtd::drawing::image "format-indent-more".
      static xtd::drawing::image format_indent_more() noexcept;
      /// @brief Gets the actions system image "format-indent-more" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-indent-more".
      static xtd::drawing::image format_indent_more(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-justify-center".
      /// @return The xtd::drawing::image "format-justify-center".
      static xtd::drawing::image format_justify_center() noexcept;
      /// @brief Gets the actions system image "format-justify-center" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-justify-center".
      static xtd::drawing::image format_justify_center(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-justify-fill".
      /// @return The xtd::drawing::image "format-justify-fill".
      static xtd::drawing::image format_justify_fill() noexcept;
      /// @brief Gets the actions system image "format-justify-fill" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-justify-fill".
      static xtd::drawing::image format_justify_fill(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-justify-left".
      /// @return The xtd::drawing::image "format-justify-left".
      static xtd::drawing::image format_justify_left() noexcept;
      /// @brief Gets the actions system image "format-justify-left" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-justify-left".
      static xtd::drawing::image format_justify_left(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-justify-right".
      /// @return The xtd::drawing::image "format-justify-right".
      static xtd::drawing::image format_justify_right() noexcept;
      /// @brief Gets the actions system image "format-justify-right" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-justify-right".
      static xtd::drawing::image format_justify_right(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-text-direction-ltr".
      /// @return The xtd::drawing::image "format-text-direction-ltr".
      static xtd::drawing::image format_text_direction_ltr() noexcept;
      /// @brief Gets the actions system image "format-text-direction-ltr" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-direction-ltr".
      static xtd::drawing::image format_text_direction_ltr(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-text-direction-rtl".
      /// @return The xtd::drawing::image "format-text-direction-rtl".
      static xtd::drawing::image format_text_direction_rtl() noexcept;
      /// @brief Gets the actions system image "format-text-direction-rtl" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-direction-rtl".
      static xtd::drawing::image format_text_direction_rtl(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-text-bold".
      /// @return The xtd::drawing::image "format-text-bold".
      static xtd::drawing::image format_text_bold() noexcept;
      /// @brief Gets the actions system image "format-text-bold" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-bold".
      static xtd::drawing::image format_text_bold(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-text-italic".
      /// @return The xtd::drawing::image "format-text-italic".
      static xtd::drawing::image format_text_italic() noexcept;
      /// @brief Gets the actions system image "format-text-italic" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-italic".
      static xtd::drawing::image format_text_italic(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-text-underline".
      /// @return The xtd::drawing::image "format-text-underline".
      static xtd::drawing::image format_text_underline() noexcept;
      /// @brief Gets the actions system image "format-text-underline" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-underline".
      static xtd::drawing::image format_text_underline(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "format-text-strikethrough".
      /// @return The xtd::drawing::image "format-text-strikethrough".
      static xtd::drawing::image format_text_strikethrough() noexcept;
      /// @brief Gets the actions system image "format-text-strikethrough" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-strikethrough".
      static xtd::drawing::image format_text_strikethrough(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-bottom".
      /// @return The xtd::drawing::image "go-bottom".
      static xtd::drawing::image go_bottom() noexcept;
      /// @brief Gets the actions system image "go-bottom" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-bottom".
      static xtd::drawing::image go_bottom(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-down".
      /// @return The xtd::drawing::image "go-down".
      static xtd::drawing::image go_down() noexcept;
      /// @brief Gets the actions system image "go-down" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-down".
      static xtd::drawing::image go_down(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-first".
      /// @return The xtd::drawing::image "go-first".
      static xtd::drawing::image go_first() noexcept;
      /// @brief Gets the actions system image "go-first" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-first".
      static xtd::drawing::image go_first(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-home".
      /// @return The xtd::drawing::image "go-home".
      static xtd::drawing::image go_home() noexcept;
      /// @brief Gets the actions system image "go-home" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-home".
      static xtd::drawing::image go_home(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-jump".
      /// @return The xtd::drawing::image "go-jump".
      static xtd::drawing::image go_jump() noexcept;
      /// @brief Gets the actions system image "go-jump" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-jump".
      static xtd::drawing::image go_jump(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-last".
      /// @return The xtd::drawing::image "go-last".
      static xtd::drawing::image go_last() noexcept;
      /// @brief Gets the actions system image "go-last" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-last".
      static xtd::drawing::image go_last(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-next".
      /// @return The xtd::drawing::image "go-next".
      static xtd::drawing::image go_next() noexcept;
      /// @brief Gets the actions system image "go-next" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-next".
      static xtd::drawing::image go_next(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-previous".
      /// @return The xtd::drawing::image "go-previous".
      static xtd::drawing::image go_previous() noexcept;
      /// @brief Gets the actions system image "go-previous" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-previous".
      static xtd::drawing::image go_previous(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-top".
      /// @return The xtd::drawing::image "go-top".
      static xtd::drawing::image go_top() noexcept;
      /// @brief Gets the actions system image "go-top" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-top".
      static xtd::drawing::image go_top(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "go-up".
      /// @return The xtd::drawing::image "go-up".
      static xtd::drawing::image go_up() noexcept;
      /// @brief Gets the actions system image "go-up" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-up".
      static xtd::drawing::image go_up(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "help-about".
      /// @return The xtd::drawing::image "help-about".
      static xtd::drawing::image help_about() noexcept;
      /// @brief Gets the actions system image "help-about" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "help-about".
      static xtd::drawing::image help_about(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "help-contents".
      /// @return The xtd::drawing::image "help-contents".
      static xtd::drawing::image help_contents() noexcept;
      /// @brief Gets the actions system image "help-contents" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "help-contents".
      static xtd::drawing::image help_contents(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "help-faq".
      /// @return The xtd::drawing::image "help-faq".
      static xtd::drawing::image help_faq() noexcept;
      /// @brief Gets the actions system image "help-faq" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "help-faq".
      static xtd::drawing::image help_faq(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "insert-image".
      /// @return The xtd::drawing::image "insert-image".
      static xtd::drawing::image insert_image() noexcept;
      /// @brief Gets the actions system image "insert-image" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-image".
      static xtd::drawing::image insert_image(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "insert-link".
      /// @return The xtd::drawing::image "insert-link".
      static xtd::drawing::image insert_link() noexcept;
      /// @brief Gets the actions system image "insert-link" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-link".
      static xtd::drawing::image insert_link(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "insert-object".
      /// @return The xtd::drawing::image "insert-object".
      static xtd::drawing::image insert_object() noexcept;
      /// @brief Gets the actions system image "insert-object" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-object".
      static xtd::drawing::image insert_object(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "insert-table".
      /// @return The xtd::drawing::image "insert-table".
      static xtd::drawing::image insert_table() noexcept;
      /// @brief Gets the actions system image "insert-table" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-table".
      static xtd::drawing::image insert_table(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "insert-text".
      /// @return The xtd::drawing::image "insert-text".
      static xtd::drawing::image insert_text() noexcept;
      /// @brief Gets the actions system image "insert-text" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-text".
      static xtd::drawing::image insert_text(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "list-add".
      /// @return The xtd::drawing::image "list-add".
      static xtd::drawing::image list_add() noexcept;
      /// @brief Gets the actions system image "list-add" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "list-add".
      static xtd::drawing::image list_add(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "list-remove".
      /// @return The xtd::drawing::image "list-remove".
      static xtd::drawing::image list_remove() noexcept;
      /// @brief Gets the actions system image "list-remove" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "list-remove".
      static xtd::drawing::image list_remove(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-forward".
      /// @return The xtd::drawing::image "mail-forward".
      static xtd::drawing::image mail_forward() noexcept;
      /// @brief Gets the actions system image "mail-forward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-forward".
      static xtd::drawing::image mail_forward(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-mark-important".
      /// @return The xtd::drawing::image "mail-mark-important".
      static xtd::drawing::image mail_mark_important() noexcept;
      /// @brief Gets the actions system image "mail-mark-important" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-important".
      static xtd::drawing::image mail_mark_important(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-mark-junk".
      /// @return The xtd::drawing::image "mail-mark-junk".
      static xtd::drawing::image mail_mark_junk() noexcept;
      /// @brief Gets the actions system image "mail-mark-junk" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-junk".
      static xtd::drawing::image mail_mark_junk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-mark-notjunk".
      /// @return The xtd::drawing::image "mail-mark-notjunk".
      static xtd::drawing::image mail_mark_notjunk() noexcept;
      /// @brief Gets the actions system image "mail-mark-notjunk" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-notjunk".
      static xtd::drawing::image mail_mark_notjunk(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-mark-read".
      /// @return The xtd::drawing::image "mail-mark-read".
      static xtd::drawing::image mail_mark_read() noexcept;
      /// @brief Gets the actions system image "mail-mark-read" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-read".
      static xtd::drawing::image mail_mark_read(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-mark-unread".
      /// @return The xtd::drawing::image "mail-mark-unread".
      static xtd::drawing::image mail_mark_unread() noexcept;
      /// @brief Gets the actions system image "mail-mark-unread" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-unread".
      static xtd::drawing::image mail_mark_unread(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-message-new".
      /// @return The xtd::drawing::image "mail-message-new".
      static xtd::drawing::image mail_message_new() noexcept;
      /// @brief Gets the actions system image "mail-message-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-message-new".
      static xtd::drawing::image mail_message_new(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-reply-all".
      /// @return The xtd::drawing::image "mail-reply-all".
      static xtd::drawing::image mail_reply_all() noexcept;
      /// @brief Gets the actions system image "mail-reply-all" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-reply-all".
      static xtd::drawing::image mail_reply_all(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-reply-sender".
      /// @return The xtd::drawing::image "mail-reply-sender".
      static xtd::drawing::image mail_reply_sender() noexcept;
      /// @brief Gets the actions system image "mail-reply-sender" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-reply-sender".
      static xtd::drawing::image mail_reply_sender(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-send".
      /// @return The xtd::drawing::image "mail-send".
      static xtd::drawing::image mail_send() noexcept;
      /// @brief Gets the actions system image "mail-send" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-send".
      static xtd::drawing::image mail_send(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "mail-send-receive".
      /// @return The xtd::drawing::image "mail-send-receive".
      static xtd::drawing::image mail_send_receive() noexcept;
      /// @brief Gets the actions system image "mail-send-receive" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-send-receive".
      static xtd::drawing::image mail_send_receive(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-eject".
      /// @return The xtd::drawing::image "media-eject".
      static xtd::drawing::image media_eject() noexcept;
      /// @brief Gets the actions system image "media-eject" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-eject".
      static xtd::drawing::image media_eject(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-optical-burn".
      /// @return The xtd::drawing::image "media-optical-burn".
      static xtd::drawing::image media_optical_burn() noexcept;
      /// @brief Gets the actions system image "media-optical-burn" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-burn".
      static xtd::drawing::image media_optical_burn(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-playback-pause".
      /// @return The xtd::drawing::image "media-playback-pause".
      static xtd::drawing::image media_playback_pause() noexcept;
      /// @brief Gets the actions system image "media-playback-pause" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-playback-pause".
      static xtd::drawing::image media_playback_pause(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-playback-start".
      /// @return The xtd::drawing::image "media-playback-start".
      static xtd::drawing::image media_playback_start() noexcept;
      /// @brief Gets the actions system image "media-playback-start" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-playback-start".
      static xtd::drawing::image media_playback_start(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-playback-stop".
      /// @return The xtd::drawing::image "media-playback-stop".
      static xtd::drawing::image media_playback_stop() noexcept;
      /// @brief Gets the actions system image "media-playback-stop" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-playback-stop".
      static xtd::drawing::image media_playback_stop(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-record".
      /// @return The xtd::drawing::image "media-record".
      static xtd::drawing::image media_record() noexcept;
      /// @brief Gets the actions system image "media-record" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-record".
      static xtd::drawing::image media_record(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-seek-backward".
      /// @return The xtd::drawing::image "media-seek-backward".
      static xtd::drawing::image media_seek_backward() noexcept;
      /// @brief Gets the actions system image "media-seek-backward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-seek-backward".
      static xtd::drawing::image media_seek_backward(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-seek-forward".
      /// @return The xtd::drawing::image "media-seek-forward".
      static xtd::drawing::image media_seek_forward() noexcept;
      /// @brief Gets the actions system image "media-seek-forward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-seek-forward".
      static xtd::drawing::image media_seek_forward(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-skip-backward".
      /// @return The xtd::drawing::image "media-skip-backward".
      static xtd::drawing::image media_skip_backward() noexcept;
      /// @brief Gets the actions system image "media-skip-backward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-skip-backward".
      static xtd::drawing::image media_skip_backward(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "media-skip-forward".
      /// @return The xtd::drawing::image "media-skip-forward".
      static xtd::drawing::image media_skip_forward() noexcept;
      /// @brief Gets the actions system image "media-skip-forward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-skip-forward".
      static xtd::drawing::image media_skip_forward(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "object-flip-horizontal".
      /// @return The xtd::drawing::image "object-flip-horizontal".
      static xtd::drawing::image object_flip_horizontal() noexcept;
      /// @brief Gets the actions system image "object-flip-horizontal" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "object-flip-horizontal".
      static xtd::drawing::image object_flip_horizontal(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "object-flip-vertical".
      /// @return The xtd::drawing::image "object-flip-vertical".
      static xtd::drawing::image object_flip_vertical() noexcept;
      /// @brief Gets the actions system image "object-flip-vertical" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "object-flip-vertical".
      static xtd::drawing::image object_flip_vertical(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "object-rotate-left".
      /// @return The xtd::drawing::image "object-rotate-left".
      static xtd::drawing::image object_rotate_left() noexcept;
      /// @brief Gets the actions system image "object-rotate-left" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "object-rotate-left".
      static xtd::drawing::image object_rotate_left(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "object-rotate-right".
      /// @return The xtd::drawing::image "object-rotate-right".
      static xtd::drawing::image object_rotate_right() noexcept;
      /// @brief Gets the actions system image "object-rotate-right" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "object-rotate-right".
      static xtd::drawing::image object_rotate_right(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "process-stop".
      /// @return The xtd::drawing::image "process-stop".
      static xtd::drawing::image process_stop() noexcept;
      /// @brief Gets the actions system image "process-stop" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "process-stop".
      static xtd::drawing::image process_stop(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "system-lock-screen".
      /// @return The xtd::drawing::image "system-lock-screen".
      static xtd::drawing::image system_lock_screen() noexcept;
      /// @brief Gets the actions system image "system-lock-screen" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-lock-screen".
      static xtd::drawing::image system_lock_screen(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "system-log-out".
      /// @return The xtd::drawing::image "system-log-out".
      static xtd::drawing::image system_log_out() noexcept;
      /// @brief Gets the actions system image "system-log-out" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-log-out".
      static xtd::drawing::image system_log_out(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "system-run".
      /// @return The xtd::drawing::image "system-run".
      static xtd::drawing::image system_run() noexcept;
      /// @brief Gets the actions system image "system-run" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-run".
      static xtd::drawing::image system_run(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "system-search".
      /// @return The xtd::drawing::image "system-search".
      static xtd::drawing::image system_search() noexcept;
      /// @brief Gets the actions system image "system-search" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-search".
      static xtd::drawing::image system_search(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "system-reboot".
      /// @return The xtd::drawing::image "system-reboot".
      static xtd::drawing::image system_reboot() noexcept;
      /// @brief Gets the actions system image "system-reboot" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-reboot".
      static xtd::drawing::image system_reboot(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "system-shutdown".
      /// @return The xtd::drawing::image "system-shutdown".
      static xtd::drawing::image system_shutdown() noexcept;
      /// @brief Gets the actions system image "system-shutdown" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-shutdown".
      static xtd::drawing::image system_shutdown(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "tools-check-spelling".
      /// @return The xtd::drawing::image "tools-check-spelling".
      static xtd::drawing::image tools_check_spelling() noexcept;
      /// @brief Gets the actions system image "tools-check-spelling" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "tools-check-spelling".
      static xtd::drawing::image tools_check_spelling(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "view-fullscreen".
      /// @return The xtd::drawing::image "view-fullscreen".
      static xtd::drawing::image view_fullscreen() noexcept;
      /// @brief Gets the actions system image "view-fullscreen" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-fullscreen".
      static xtd::drawing::image view_fullscreen(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "view-media-equalizer".
      /// @return The xtd::drawing::image "view-media-equalizer".
      static xtd::drawing::image view_media_equalizer() noexcept;
      /// @brief Gets the actions system image "view-media-equalizer" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-media-equalizer".
      static xtd::drawing::image view_media_equalizer(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "view-media-lyrics".
      /// @return The xtd::drawing::image "view-media-lyrics".
      static xtd::drawing::image view_media_lyrics() noexcept;
      /// @brief Gets the actions system image "view-media-lyrics" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-media-lyrics".
      static xtd::drawing::image view_media_lyrics(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "view-refresh".
      /// @return The xtd::drawing::image "view-refresh".
      static xtd::drawing::image view_refresh() noexcept;
      /// @brief Gets the actions system image "view-refresh" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-refresh".
      static xtd::drawing::image view_refresh(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "view-restore".
      /// @return The xtd::drawing::image "view-restore".
      static xtd::drawing::image view_restore() noexcept;
      /// @brief Gets the actions system image "view-restore" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-restore".
      static xtd::drawing::image view_restore(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "view-sort-ascending".
      /// @return The xtd::drawing::image "view-sort-ascending".
      static xtd::drawing::image view_sort_ascending() noexcept;
      /// @brief Gets the actions system image "view-sort-ascending" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-sort-ascending".
      static xtd::drawing::image view_sort_ascending(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "view-sort-descending".
      /// @return The xtd::drawing::image "view-sort-descending".
      static xtd::drawing::image view_sort_descending() noexcept;
      /// @brief Gets the actions system image "view-sort-descending" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-sort-descending".
      static xtd::drawing::image view_sort_descending(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-close".
      /// @return The xtd::drawing::image "window-close".
      static xtd::drawing::image window_close() noexcept;
      /// @brief Gets the actions system image "window-close" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-close".
      static xtd::drawing::image window_close(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-close-hovered".
      /// @return The xtd::drawing::image "window-close-hovered".
      static xtd::drawing::image window_close_hovered() noexcept;
      /// @brief Gets the actions system image "window-close-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-close-hovered".
      static xtd::drawing::image window_close_hovered(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-fullscreen".
      /// @return The xtd::drawing::image "window-fullscreen".
      static xtd::drawing::image window_fullscreen() noexcept;
      /// @brief Gets the actions system image "window-fullscreen" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-fullscreen".
      static xtd::drawing::image window_fullscreen(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-fullscreen-hovered".
      /// @return The xtd::drawing::image "window-fullscreen-hovered".
      static xtd::drawing::image window_fullscreen_hovered() noexcept;
      /// @brief Gets the actions system image "window-fullscreen-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-fullscreen-hovered".
      static xtd::drawing::image window_fullscreen_hovered(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-maximize".
      /// @return The xtd::drawing::image "window-maximize".
      static xtd::drawing::image window_maximize() noexcept;
      /// @brief Gets the actions system image "window-maximize" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-maximize".
      static xtd::drawing::image window_maximize(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-maximize-hovered".
      /// @return The xtd::drawing::image "window-maximize-hovered".
      static xtd::drawing::image window_maximize_hovered() noexcept;
      /// @brief Gets the actions system image "window-maximize-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-maximize-hovered".
      static xtd::drawing::image window_maximize_hovered(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-minimize".
      /// @return The xtd::drawing::image "window-minimize".
      static xtd::drawing::image window_minimize() noexcept;
      /// @brief Gets the actions system image "window-minimize" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-minimize".
      static xtd::drawing::image window_minimize(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-minimize-hovered".
      /// @return The xtd::drawing::image "window-minimize-hovered".
      static xtd::drawing::image window_minimize_hovered() noexcept;
      /// @brief Gets the actions system image "window-minimize-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-minimize-hovered".
      static xtd::drawing::image window_minimize_hovered(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-new".
      /// @return The xtd::drawing::image "window-new".
      static xtd::drawing::image window_new() noexcept;
      /// @brief Gets the actions system image "window-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-new".
      static xtd::drawing::image window_new(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-restore".
      /// @return The xtd::drawing::image "window-restore".
      static xtd::drawing::image window_restore() noexcept;
      /// @brief Gets the actions system image "window-restore" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-restore".
      static xtd::drawing::image window_restore(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "window-restore-hovered".
      /// @return The xtd::drawing::image "window-restore-hovered".
      static xtd::drawing::image window_restore_hovered() noexcept;
      /// @brief Gets the actions system image "window-restore-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-restore-hovered".
      static xtd::drawing::image window_restore_hovered(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "zoom-fit-best".
      /// @return The xtd::drawing::image "zoom-fit-best".
      static xtd::drawing::image zoom_fit_best() noexcept;
      /// @brief Gets the actions system image "zoom-fit-best" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "zoom-fit-best".
      static xtd::drawing::image zoom_fit_best(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "zoom-in".
      /// @return The xtd::drawing::image "zoom-in".
      static xtd::drawing::image zoom_in() noexcept;
      /// @brief Gets the actions system image "zoom-in" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "zoom-in".
      static xtd::drawing::image zoom_in(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "zoom-original".
      /// @return The xtd::drawing::image "zoom-original".
      static xtd::drawing::image zoom_original() noexcept;
      /// @brief Gets the actions system image "zoom-original" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "zoom-original".
      static xtd::drawing::image zoom_original(const xtd::drawing::size& size) noexcept;

      /// @brief Gets the actions system image "zoom-out".
      /// @return The xtd::drawing::image "zoom-out".
      static xtd::drawing::image zoom_out() noexcept;
      /// @brief Gets the actions system image "zoom-out" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "zoom-out".
      static xtd::drawing::image zoom_out(const xtd::drawing::size& size) noexcept;

      /// @}

      /// @name Methods

      /// @{
      /// @brief Gets an array of images.
      /// @return The array of images.
      static const std::vector<xtd::drawing::image>& get_images() noexcept;
      /// @brief Gets an array of images with specified size.
      /// @param size The images size in pixels.
      /// @return The array of images.
      static std::vector<xtd::drawing::image> get_images(const xtd::drawing::size& size) noexcept;

      /// @brief Gets an array of image names.
      /// @return The array of image names.
      static const std::vector<xtd::ustring>& get_image_names() noexcept;
      /// @}
    };
  }
}
