/// @file
/// @brief Contains xtd::drawing::actions_system_images factory.
/// @copyright Copyright (c) 2026 Gammasoft. All rights reserved.
#pragma once
#include "system_images_base.hpp"

/// @brief The xtd namespace contains all fundamental classes to access Hardware, Os, System, and more.
namespace xtd {
  /// @brief The xtd::drawing namespace provides access to GDI+ basic graphics functionality. More advanced functionality is provided in the xtd::drawing::drawing_2d, xtd::drawing::imaging, and xtd::drawing::text namespaces.
  namespace drawing {
    /// @brief Each property of the xtd::drawing::actions_system_images class is an xtd::drawing::image object for Windows system-wide images. This class cannot be inherited.
    /// ```cpp
    /// class drawing_export_ actions_system_images final : private system_images_base
    /// ```
    /// @par Inheritance
    /// xtd::drawing::system_images_base → xtd::drawing::actions_system_images
    /// @par Header
    /// ```cpp
    /// #include <xtd/drawing/actions_system_images>
    /// ```
    /// @par Namespace
    /// xtd::drawing
    /// @par Library
    /// xtd.drawing
    /// @ingroup xtd_drawing images
    /// @remarks Each property of the images class returns a xtd::drawing::image used to display a Windows system-wide images.
    class drawing_export_ actions_system_images final : private system_images_base {
    public:
      /// @name Public Static Properties
      
      /// @{
      /// @brief Gets system image from specified name.
      /// @return The default size in pixels (32 x 32).
      [[nodiscard]] static auto default_size() noexcept -> xtd::drawing::size;
      
      /// @brief Gets the actions system image "address-book-new".
      /// @return The xtd::drawing::image "address-book-new".
      [[nodiscard]] static auto address_book_new() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "address-book-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "address-book-new".
      [[nodiscard]] static auto address_book_new(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "application-exit".
      /// @return The xtd::drawing::image "application-exit".
      [[nodiscard]] static auto application_exit() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "application-exit" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "application-exit".
      [[nodiscard]] static auto application_exit(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "appointment-new".
      /// @return The xtd::drawing::image "appointment-new".
      [[nodiscard]] static auto appointment_new() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "appointment-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "appointment-new".
      [[nodiscard]] static auto appointment_new(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "call-start".
      /// @return The xtd::drawing::image "call-start".
      [[nodiscard]] static auto call_start() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "call-start" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "call-start".
      [[nodiscard]] static auto call_start(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "call-stop".
      /// @return The xtd::drawing::image "call-stop".
      [[nodiscard]] static auto call_stop() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "call-stop" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "call-stop".
      [[nodiscard]] static auto call_stop(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "contact-new".
      /// @return The xtd::drawing::image "contact-new".
      [[nodiscard]] static auto contact_new() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "contact-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "contact-new".
      [[nodiscard]] static auto contact_new(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "dialog-cancel".
      /// @return The xtd::drawing::image "dialog-cancel".
      [[nodiscard]] static auto dialog_cancel() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "dialog-cancel" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "dialog-cancel".
      [[nodiscard]] static auto dialog_cancel(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "dialog-ok".
      /// @return The xtd::drawing::image "dialog-ok".
      [[nodiscard]] static auto dialog_ok() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "dialog-ok" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "dialog-ok".
      [[nodiscard]] static auto dialog_ok(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "dialog-ok-apply".
      /// @return The xtd::drawing::image "dialog-ok-apply".
      [[nodiscard]] static auto dialog_ok_apply() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "dialog-ok-apply" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "dialog-ok-apply".
      [[nodiscard]] static auto dialog_ok_apply(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-edit".
      /// @return The xtd::drawing::image "document-edit".
      [[nodiscard]] static auto document_edit() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-edit" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-edit".
      [[nodiscard]] static auto document_edit(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-new".
      /// @return The xtd::drawing::image "document-new".
      [[nodiscard]] static auto document_new() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-new".
      [[nodiscard]] static auto document_new(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-open".
      /// @return The xtd::drawing::image "document-open".
      [[nodiscard]] static auto document_open() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-open" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-open".
      [[nodiscard]] static auto document_open(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-open-recent".
      /// @return The xtd::drawing::image "document-open-recent".
      [[nodiscard]] static auto document_open_recent() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-open-recent" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-open-recent".
      [[nodiscard]] static auto document_open_recent(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-page-setup".
      /// @return The xtd::drawing::image "document-page-setup".
      [[nodiscard]] static auto document_page_setup() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-page-setup" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-page-setup".
      [[nodiscard]] static auto document_page_setup(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-print".
      /// @return The xtd::drawing::image "document-print".
      [[nodiscard]] static auto document_print() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-print" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-print".
      [[nodiscard]] static auto document_print(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-print-preview".
      /// @return The xtd::drawing::image "document-print-preview".
      [[nodiscard]] static auto document_print_preview() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-print-preview" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-print-preview".
      [[nodiscard]] static auto document_print_preview(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-properties".
      /// @return The xtd::drawing::image "document-properties".
      [[nodiscard]] static auto document_properties() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-properties" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-properties".
      [[nodiscard]] static auto document_properties(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-revert".
      /// @return The xtd::drawing::image "document-revert".
      [[nodiscard]] static auto document_revert() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-revert" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-revert".
      [[nodiscard]] static auto document_revert(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-save".
      /// @return The xtd::drawing::image "document-save".
      [[nodiscard]] static auto document_save() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-save" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-save".
      [[nodiscard]] static auto document_save(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-save-as".
      /// @return The xtd::drawing::image "document-save-as".
      [[nodiscard]] static auto document_save_as() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-save-as" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-save-as".
      [[nodiscard]] static auto document_save_as(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "document-send".
      /// @return The xtd::drawing::image "document-send".
      [[nodiscard]] static auto document_send() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "document-send" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "document-send".
      [[nodiscard]] static auto document_send(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-clear".
      /// @return The xtd::drawing::image "edit-clear".
      [[nodiscard]] static auto edit_clear() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-clear" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-clear".
      [[nodiscard]] static auto edit_clear(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-copy".
      /// @return The xtd::drawing::image "edit-copy".
      [[nodiscard]] static auto edit_copy() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-copy" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-copy".
      [[nodiscard]] static auto edit_copy(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-cut".
      /// @return The xtd::drawing::image "edit-cut".
      [[nodiscard]] static auto edit_cut() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-cut" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-cut".
      [[nodiscard]] static auto edit_cut(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-delete".
      /// @return The xtd::drawing::image "edit-delete".
      [[nodiscard]] static auto edit_delete() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-delete" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-delete".
      [[nodiscard]] static auto edit_delete(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-find".
      /// @return The xtd::drawing::image "edit-find".
      [[nodiscard]] static auto edit_find() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-find" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-find".
      [[nodiscard]] static auto edit_find(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-find-replace".
      /// @return The xtd::drawing::image "edit-find-replace".
      [[nodiscard]] static auto edit_find_replace() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-find-replace" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-find-replace".
      [[nodiscard]] static auto edit_find_replace(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-paste".
      /// @return The xtd::drawing::image "edit-paste".
      [[nodiscard]] static auto edit_paste() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-paste" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-paste".
      [[nodiscard]] static auto edit_paste(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-redo".
      /// @return The xtd::drawing::image "edit-redo".
      [[nodiscard]] static auto edit_redo() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-redo" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-redo".
      [[nodiscard]] static auto edit_redo(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-rename".
      /// @return The xtd::drawing::image "edit-rename".
      [[nodiscard]] static auto edit_rename() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-rename" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-rename".
      [[nodiscard]] static auto edit_rename(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-select-all".
      /// @return The xtd::drawing::image "edit-select-all".
      [[nodiscard]] static auto edit_select_all() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-select-all" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-select-all".
      [[nodiscard]] static auto edit_select_all(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "edit-undo".
      /// @return The xtd::drawing::image "edit-undo".
      [[nodiscard]] static auto edit_undo() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "edit-undo" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "edit-undo".
      [[nodiscard]] static auto edit_undo(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "folder-new".
      /// @return The xtd::drawing::image "folder-new".
      [[nodiscard]] static auto folder_new() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "folder-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "folder-new".
      [[nodiscard]] static auto folder_new(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-indent-less".
      /// @return The xtd::drawing::image "format-indent-less".
      [[nodiscard]] static auto format_indent_less() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-indent-less" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-indent-less".
      [[nodiscard]] static auto format_indent_less(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-indent-more".
      /// @return The xtd::drawing::image "format-indent-more".
      [[nodiscard]] static auto format_indent_more() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-indent-more" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-indent-more".
      [[nodiscard]] static auto format_indent_more(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-justify-center".
      /// @return The xtd::drawing::image "format-justify-center".
      [[nodiscard]] static auto format_justify_center() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-justify-center" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-justify-center".
      [[nodiscard]] static auto format_justify_center(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-justify-fill".
      /// @return The xtd::drawing::image "format-justify-fill".
      [[nodiscard]] static auto format_justify_fill() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-justify-fill" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-justify-fill".
      [[nodiscard]] static auto format_justify_fill(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-justify-left".
      /// @return The xtd::drawing::image "format-justify-left".
      [[nodiscard]] static auto format_justify_left() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-justify-left" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-justify-left".
      [[nodiscard]] static auto format_justify_left(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-justify-right".
      /// @return The xtd::drawing::image "format-justify-right".
      [[nodiscard]] static auto format_justify_right() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-justify-right" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-justify-right".
      [[nodiscard]] static auto format_justify_right(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-text-direction-ltr".
      /// @return The xtd::drawing::image "format-text-direction-ltr".
      [[nodiscard]] static auto format_text_direction_ltr() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-text-direction-ltr" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-direction-ltr".
      [[nodiscard]] static auto format_text_direction_ltr(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-text-direction-rtl".
      /// @return The xtd::drawing::image "format-text-direction-rtl".
      [[nodiscard]] static auto format_text_direction_rtl() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-text-direction-rtl" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-direction-rtl".
      [[nodiscard]] static auto format_text_direction_rtl(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-text-bold".
      /// @return The xtd::drawing::image "format-text-bold".
      [[nodiscard]] static auto format_text_bold() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-text-bold" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-bold".
      [[nodiscard]] static auto format_text_bold(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-text-italic".
      /// @return The xtd::drawing::image "format-text-italic".
      [[nodiscard]] static auto format_text_italic() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-text-italic" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-italic".
      [[nodiscard]] static auto format_text_italic(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-text-underline".
      /// @return The xtd::drawing::image "format-text-underline".
      [[nodiscard]] static auto format_text_underline() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-text-underline" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-underline".
      [[nodiscard]] static auto format_text_underline(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "format-text-strikethrough".
      /// @return The xtd::drawing::image "format-text-strikethrough".
      [[nodiscard]] static auto format_text_strikethrough() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "format-text-strikethrough" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "format-text-strikethrough".
      [[nodiscard]] static auto format_text_strikethrough(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-bottom".
      /// @return The xtd::drawing::image "go-bottom".
      [[nodiscard]] static auto go_bottom() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-bottom" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-bottom".
      [[nodiscard]] static auto go_bottom(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-down".
      /// @return The xtd::drawing::image "go-down".
      [[nodiscard]] static auto go_down() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-down" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-down".
      [[nodiscard]] static auto go_down(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-first".
      /// @return The xtd::drawing::image "go-first".
      [[nodiscard]] static auto go_first() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-first" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-first".
      [[nodiscard]] static auto go_first(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-home".
      /// @return The xtd::drawing::image "go-home".
      [[nodiscard]] static auto go_home() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-home" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-home".
      [[nodiscard]] static auto go_home(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-jump".
      /// @return The xtd::drawing::image "go-jump".
      [[nodiscard]] static auto go_jump() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-jump" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-jump".
      [[nodiscard]] static auto go_jump(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-last".
      /// @return The xtd::drawing::image "go-last".
      [[nodiscard]] static auto go_last() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-last" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-last".
      [[nodiscard]] static auto go_last(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-next".
      /// @return The xtd::drawing::image "go-next".
      [[nodiscard]] static auto go_next() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-next" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-next".
      [[nodiscard]] static auto go_next(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-previous".
      /// @return The xtd::drawing::image "go-previous".
      [[nodiscard]] static auto go_previous() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-previous" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-previous".
      [[nodiscard]] static auto go_previous(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-top".
      /// @return The xtd::drawing::image "go-top".
      [[nodiscard]] static auto go_top() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-top" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-top".
      [[nodiscard]] static auto go_top(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "go-up".
      /// @return The xtd::drawing::image "go-up".
      [[nodiscard]] static auto go_up() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "go-up" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "go-up".
      [[nodiscard]] static auto go_up(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "help-about".
      /// @return The xtd::drawing::image "help-about".
      [[nodiscard]] static auto help_about() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "help-about" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "help-about".
      [[nodiscard]] static auto help_about(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "help-contents".
      /// @return The xtd::drawing::image "help-contents".
      [[nodiscard]] static auto help_contents() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "help-contents" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "help-contents".
      [[nodiscard]] static auto help_contents(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "help-faq".
      /// @return The xtd::drawing::image "help-faq".
      [[nodiscard]] static auto help_faq() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "help-faq" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "help-faq".
      [[nodiscard]] static auto help_faq(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "insert-image".
      /// @return The xtd::drawing::image "insert-image".
      [[nodiscard]] static auto insert_image() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "insert-image" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-image".
      [[nodiscard]] static auto insert_image(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "insert-link".
      /// @return The xtd::drawing::image "insert-link".
      [[nodiscard]] static auto insert_link() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "insert-link" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-link".
      [[nodiscard]] static auto insert_link(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "insert-object".
      /// @return The xtd::drawing::image "insert-object".
      [[nodiscard]] static auto insert_object() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "insert-object" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-object".
      [[nodiscard]] static auto insert_object(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "insert-table".
      /// @return The xtd::drawing::image "insert-table".
      [[nodiscard]] static auto insert_table() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "insert-table" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-table".
      [[nodiscard]] static auto insert_table(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "insert-text".
      /// @return The xtd::drawing::image "insert-text".
      [[nodiscard]] static auto insert_text() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "insert-text" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "insert-text".
      [[nodiscard]] static auto insert_text(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "list-add".
      /// @return The xtd::drawing::image "list-add".
      [[nodiscard]] static auto list_add() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "list-add" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "list-add".
      [[nodiscard]] static auto list_add(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "list-remove".
      /// @return The xtd::drawing::image "list-remove".
      [[nodiscard]] static auto list_remove() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "list-remove" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "list-remove".
      [[nodiscard]] static auto list_remove(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-forward".
      /// @return The xtd::drawing::image "mail-forward".
      [[nodiscard]] static auto mail_forward() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-forward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-forward".
      [[nodiscard]] static auto mail_forward(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-mark-important".
      /// @return The xtd::drawing::image "mail-mark-important".
      [[nodiscard]] static auto mail_mark_important() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-mark-important" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-important".
      [[nodiscard]] static auto mail_mark_important(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-mark-junk".
      /// @return The xtd::drawing::image "mail-mark-junk".
      [[nodiscard]] static auto mail_mark_junk() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-mark-junk" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-junk".
      [[nodiscard]] static auto mail_mark_junk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-mark-notjunk".
      /// @return The xtd::drawing::image "mail-mark-notjunk".
      [[nodiscard]] static auto mail_mark_notjunk() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-mark-notjunk" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-notjunk".
      [[nodiscard]] static auto mail_mark_notjunk(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-mark-read".
      /// @return The xtd::drawing::image "mail-mark-read".
      [[nodiscard]] static auto mail_mark_read() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-mark-read" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-read".
      [[nodiscard]] static auto mail_mark_read(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-mark-unread".
      /// @return The xtd::drawing::image "mail-mark-unread".
      [[nodiscard]] static auto mail_mark_unread() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-mark-unread" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-mark-unread".
      [[nodiscard]] static auto mail_mark_unread(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-message-new".
      /// @return The xtd::drawing::image "mail-message-new".
      [[nodiscard]] static auto mail_message_new() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-message-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-message-new".
      [[nodiscard]] static auto mail_message_new(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-reply-all".
      /// @return The xtd::drawing::image "mail-reply-all".
      [[nodiscard]] static auto mail_reply_all() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-reply-all" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-reply-all".
      [[nodiscard]] static auto mail_reply_all(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-reply-sender".
      /// @return The xtd::drawing::image "mail-reply-sender".
      [[nodiscard]] static auto mail_reply_sender() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-reply-sender" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-reply-sender".
      [[nodiscard]] static auto mail_reply_sender(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-send".
      /// @return The xtd::drawing::image "mail-send".
      [[nodiscard]] static auto mail_send() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-send" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-send".
      [[nodiscard]] static auto mail_send(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "mail-send-receive".
      /// @return The xtd::drawing::image "mail-send-receive".
      [[nodiscard]] static auto mail_send_receive() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "mail-send-receive" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "mail-send-receive".
      [[nodiscard]] static auto mail_send_receive(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-eject".
      /// @return The xtd::drawing::image "media-eject".
      [[nodiscard]] static auto media_eject() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-eject" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-eject".
      [[nodiscard]] static auto media_eject(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-optical-burn".
      /// @return The xtd::drawing::image "media-optical-burn".
      [[nodiscard]] static auto media_optical_burn() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-optical-burn" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-optical-burn".
      [[nodiscard]] static auto media_optical_burn(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-playback-pause".
      /// @return The xtd::drawing::image "media-playback-pause".
      [[nodiscard]] static auto media_playback_pause() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-playback-pause" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-playback-pause".
      [[nodiscard]] static auto media_playback_pause(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-playback-start".
      /// @return The xtd::drawing::image "media-playback-start".
      [[nodiscard]] static auto media_playback_start() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-playback-start" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-playback-start".
      [[nodiscard]] static auto media_playback_start(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-playback-stop".
      /// @return The xtd::drawing::image "media-playback-stop".
      [[nodiscard]] static auto media_playback_stop() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-playback-stop" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-playback-stop".
      [[nodiscard]] static auto media_playback_stop(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-record".
      /// @return The xtd::drawing::image "media-record".
      [[nodiscard]] static auto media_record() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-record" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-record".
      [[nodiscard]] static auto media_record(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-seek-backward".
      /// @return The xtd::drawing::image "media-seek-backward".
      [[nodiscard]] static auto media_seek_backward() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-seek-backward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-seek-backward".
      [[nodiscard]] static auto media_seek_backward(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-seek-forward".
      /// @return The xtd::drawing::image "media-seek-forward".
      [[nodiscard]] static auto media_seek_forward() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-seek-forward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-seek-forward".
      [[nodiscard]] static auto media_seek_forward(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-skip-backward".
      /// @return The xtd::drawing::image "media-skip-backward".
      [[nodiscard]] static auto media_skip_backward() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-skip-backward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-skip-backward".
      [[nodiscard]] static auto media_skip_backward(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "media-skip-forward".
      /// @return The xtd::drawing::image "media-skip-forward".
      [[nodiscard]] static auto media_skip_forward() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "media-skip-forward" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "media-skip-forward".
      [[nodiscard]] static auto media_skip_forward(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "object-flip-horizontal".
      /// @return The xtd::drawing::image "object-flip-horizontal".
      [[nodiscard]] static auto object_flip_horizontal() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "object-flip-horizontal" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "object-flip-horizontal".
      [[nodiscard]] static auto object_flip_horizontal(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "object-flip-vertical".
      /// @return The xtd::drawing::image "object-flip-vertical".
      [[nodiscard]] static auto object_flip_vertical() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "object-flip-vertical" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "object-flip-vertical".
      [[nodiscard]] static auto object_flip_vertical(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "object-rotate-left".
      /// @return The xtd::drawing::image "object-rotate-left".
      [[nodiscard]] static auto object_rotate_left() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "object-rotate-left" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "object-rotate-left".
      [[nodiscard]] static auto object_rotate_left(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "object-rotate-right".
      /// @return The xtd::drawing::image "object-rotate-right".
      [[nodiscard]] static auto object_rotate_right() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "object-rotate-right" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "object-rotate-right".
      [[nodiscard]] static auto object_rotate_right(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "process-stop".
      /// @return The xtd::drawing::image "process-stop".
      [[nodiscard]] static auto process_stop() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "process-stop" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "process-stop".
      [[nodiscard]] static auto process_stop(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "system-lock-screen".
      /// @return The xtd::drawing::image "system-lock-screen".
      [[nodiscard]] static auto system_lock_screen() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "system-lock-screen" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-lock-screen".
      [[nodiscard]] static auto system_lock_screen(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "system-log-out".
      /// @return The xtd::drawing::image "system-log-out".
      [[nodiscard]] static auto system_log_out() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "system-log-out" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-log-out".
      [[nodiscard]] static auto system_log_out(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "system-run".
      /// @return The xtd::drawing::image "system-run".
      [[nodiscard]] static auto system_run() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "system-run" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-run".
      [[nodiscard]] static auto system_run(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "system-search".
      /// @return The xtd::drawing::image "system-search".
      [[nodiscard]] static auto system_search() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "system-search" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-search".
      [[nodiscard]] static auto system_search(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "system-reboot".
      /// @return The xtd::drawing::image "system-reboot".
      [[nodiscard]] static auto system_reboot() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "system-reboot" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-reboot".
      [[nodiscard]] static auto system_reboot(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "system-shutdown".
      /// @return The xtd::drawing::image "system-shutdown".
      [[nodiscard]] static auto system_shutdown() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "system-shutdown" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "system-shutdown".
      [[nodiscard]] static auto system_shutdown(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "tools-check-spelling".
      /// @return The xtd::drawing::image "tools-check-spelling".
      [[nodiscard]] static auto tools_check_spelling() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "tools-check-spelling" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "tools-check-spelling".
      [[nodiscard]] static auto tools_check_spelling(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "view-fullscreen".
      /// @return The xtd::drawing::image "view-fullscreen".
      [[nodiscard]] static auto view_fullscreen() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "view-fullscreen" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-fullscreen".
      [[nodiscard]] static auto view_fullscreen(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "view-media-equalizer".
      /// @return The xtd::drawing::image "view-media-equalizer".
      [[nodiscard]] static auto view_media_equalizer() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "view-media-equalizer" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-media-equalizer".
      [[nodiscard]] static auto view_media_equalizer(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "view-media-lyrics".
      /// @return The xtd::drawing::image "view-media-lyrics".
      [[nodiscard]] static auto view_media_lyrics() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "view-media-lyrics" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-media-lyrics".
      [[nodiscard]] static auto view_media_lyrics(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "view-refresh".
      /// @return The xtd::drawing::image "view-refresh".
      [[nodiscard]] static auto view_refresh() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "view-refresh" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-refresh".
      [[nodiscard]] static auto view_refresh(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "view-restore".
      /// @return The xtd::drawing::image "view-restore".
      [[nodiscard]] static auto view_restore() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "view-restore" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-restore".
      [[nodiscard]] static auto view_restore(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "view-sort-ascending".
      /// @return The xtd::drawing::image "view-sort-ascending".
      [[nodiscard]] static auto view_sort_ascending() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "view-sort-ascending" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-sort-ascending".
      [[nodiscard]] static auto view_sort_ascending(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "view-sort-descending".
      /// @return The xtd::drawing::image "view-sort-descending".
      [[nodiscard]] static auto view_sort_descending() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "view-sort-descending" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "view-sort-descending".
      [[nodiscard]] static auto view_sort_descending(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-close".
      /// @return The xtd::drawing::image "window-close".
      [[nodiscard]] static auto window_close() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-close" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-close".
      [[nodiscard]] static auto window_close(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-close-hovered".
      /// @return The xtd::drawing::image "window-close-hovered".
      [[nodiscard]] static auto window_close_hovered() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-close-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-close-hovered".
      [[nodiscard]] static auto window_close_hovered(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-fullscreen".
      /// @return The xtd::drawing::image "window-fullscreen".
      [[nodiscard]] static auto window_fullscreen() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-fullscreen" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-fullscreen".
      [[nodiscard]] static auto window_fullscreen(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-fullscreen-hovered".
      /// @return The xtd::drawing::image "window-fullscreen-hovered".
      [[nodiscard]] static auto window_fullscreen_hovered() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-fullscreen-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-fullscreen-hovered".
      [[nodiscard]] static auto window_fullscreen_hovered(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-maximize".
      /// @return The xtd::drawing::image "window-maximize".
      [[nodiscard]] static auto window_maximize() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-maximize" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-maximize".
      [[nodiscard]] static auto window_maximize(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-maximize-hovered".
      /// @return The xtd::drawing::image "window-maximize-hovered".
      [[nodiscard]] static auto window_maximize_hovered() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-maximize-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-maximize-hovered".
      [[nodiscard]] static auto window_maximize_hovered(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-minimize".
      /// @return The xtd::drawing::image "window-minimize".
      [[nodiscard]] static auto window_minimize() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-minimize" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-minimize".
      [[nodiscard]] static auto window_minimize(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-minimize-hovered".
      /// @return The xtd::drawing::image "window-minimize-hovered".
      [[nodiscard]] static auto window_minimize_hovered() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-minimize-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-minimize-hovered".
      [[nodiscard]] static auto window_minimize_hovered(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-new".
      /// @return The xtd::drawing::image "window-new".
      [[nodiscard]] static auto window_new() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-new" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-new".
      [[nodiscard]] static auto window_new(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-restore".
      /// @return The xtd::drawing::image "window-restore".
      [[nodiscard]] static auto window_restore() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-restore" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-restore".
      [[nodiscard]] static auto window_restore(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "window-restore-hovered".
      /// @return The xtd::drawing::image "window-restore-hovered".
      [[nodiscard]] static auto window_restore_hovered() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "window-restore-hovered" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "window-restore-hovered".
      [[nodiscard]] static auto window_restore_hovered(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "zoom-fit-best".
      /// @return The xtd::drawing::image "zoom-fit-best".
      [[nodiscard]] static auto zoom_fit_best() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "zoom-fit-best" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "zoom-fit-best".
      [[nodiscard]] static auto zoom_fit_best(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "zoom-in".
      /// @return The xtd::drawing::image "zoom-in".
      [[nodiscard]] static auto zoom_in() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "zoom-in" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "zoom-in".
      [[nodiscard]] static auto zoom_in(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "zoom-original".
      /// @return The xtd::drawing::image "zoom-original".
      [[nodiscard]] static auto zoom_original() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "zoom-original" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "zoom-original".
      [[nodiscard]] static auto zoom_original(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      
      /// @brief Gets the actions system image "zoom-out".
      /// @return The xtd::drawing::image "zoom-out".
      [[nodiscard]] static auto zoom_out() noexcept -> xtd::drawing::image;
      /// @brief Gets the actions system image "zoom-out" with specified size.
      /// @param size The actions system image size in pixels.
      /// @return The xtd::drawing::image "zoom-out".
      [[nodiscard]] static auto zoom_out(const xtd::drawing::size& size) noexcept -> xtd::drawing::image;
      /// @}
      
      /// @name Public Static Methods
      
      /// @{
      /// @brief Gets an array of images.
      /// @return The array of images.
      [[nodiscard]] static auto get_images() noexcept -> const xtd::array<xtd::drawing::image>&;
      /// @brief Gets an array of images with specified size.
      /// @param size The images size in pixels.
      /// @return The array of images.
      [[nodiscard]] static auto get_images(const xtd::drawing::size& size) noexcept -> xtd::array<xtd::drawing::image>;
      
      /// @brief Gets an array of image names.
      /// @return The array of image names.
      [[nodiscard]] static auto get_image_names() noexcept -> const xtd::array<xtd::string>&;
      /// @}
    };
  }
}
